#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdint>

struct Version
{
    union
    {
        struct
        {
            std::uint16_t major;
            std::uint16_t minor;
            std::uint16_t build;
            std::uint16_t revision;
        };
        std::uint64_t version;
    };
};

struct PluginInfo
{
    Version sdk_version;
    bool hide_from_peb;
    bool erase_pe_header;
    bool(__cdecl* init)(const Version version);
    void(__cdecl* oep_notify)(const Version version);
    int priority;
    const wchar_t* target_apps;
};

static HINSTANCE g_module = nullptr;

static void AppendPath(wchar_t* path, const wchar_t* name)
{
    const auto length = lstrlenW(path);
    if (length > 0 && path[length - 1] != L'\\' && path[length - 1] != L'/')
    {
        lstrcatW(path, L"\\");
    }
    lstrcatW(path, name);
}

static void LogLine(const wchar_t* text)
{
    wchar_t path[MAX_PATH]{};
    const auto length = GetModuleFileNameW(g_module, path, MAX_PATH);
    if (length == 0 || length >= MAX_PATH)
    {
        return;
    }

    for (DWORD i = length; i > 0; --i)
    {
        if (path[i - 1] == L'\\' || path[i - 1] == L'/')
        {
            path[i] = L'\0';
            break;
        }
    }

    AppendPath(path, L"loaderU_test_plugin.log");
    const auto file = CreateFileW(path, FILE_APPEND_DATA, FILE_SHARE_READ, nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE)
    {
        return;
    }

    wchar_t line[256]{};
    lstrcpynW(line, text, 220);
    lstrcatW(line, L"\r\n");
    DWORD written = 0;
    WriteFile(file, line, static_cast<DWORD>(lstrlenW(line) * sizeof(wchar_t)), &written, nullptr);
    CloseHandle(file);
}

static bool __cdecl Init(const Version)
{
    LogLine(L"TestPlugin: init");
    return true;
}

static void __cdecl OepNotify(const Version)
{
    LogLine(L"TestPlugin: oep_notify");
}

extern "C" __declspec(dllexport) PluginInfo GPluginInfo = {
    {3, 1, 0, 0},
    false,
    false,
    Init,
    OepNotify,
    100,
    L"BNSR.exe;Client.exe"
};

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        g_module = instance;
        DisableThreadLibraryCalls(instance);
    }
    return TRUE;
}
