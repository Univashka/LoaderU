#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdint>

namespace
{
    HINSTANCE g_module = nullptr;
    HMODULE g_original = nullptr;

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

    struct LoadedPlugin
    {
        HMODULE module;
        const PluginInfo* info;
        wchar_t path[MAX_PATH];
    };

    constexpr Version LoaderUSdkVersion{3, 1, 0, 0};
    LoadedPlugin g_plugins[128]{};
    int g_pluginCount = 0;

    extern "C" void MissingWinmmExport() {}

    extern "C" FARPROC g_Ordinal_2 = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciExecute = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_CloseDriver = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_DefDriverProc = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_DriverCallback = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_DrvGetModuleHandle = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_GetDriverModuleHandle = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_OpenDriver = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_PlaySound = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_PlaySoundA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_PlaySoundW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_SendDriverMessage = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_WOWAppExit = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_auxGetDevCapsA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_auxGetDevCapsW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_auxGetNumDevs = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_auxGetVolume = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_auxOutMessage = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_auxSetVolume = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_joyConfigChanged = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_joyGetDevCapsA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_joyGetDevCapsW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_joyGetNumDevs = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_joyGetPos = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_joyGetPosEx = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_joyGetThreshold = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_joyReleaseCapture = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_joySetCapture = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_joySetThreshold = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciDriverNotify = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciDriverYield = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciFreeCommandResource = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciGetCreatorTask = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciGetDeviceIDA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciGetDeviceIDFromElementIDA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciGetDeviceIDFromElementIDW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciGetDeviceIDW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciGetDriverData = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciGetErrorStringA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciGetErrorStringW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciGetYieldProc = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciLoadCommandResource = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciSendCommandA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciSendCommandW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciSendStringA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciSendStringW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciSetDriverData = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mciSetYieldProc = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiConnect = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiDisconnect = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiInAddBuffer = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiInClose = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiInGetDevCapsA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiInGetDevCapsW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiInGetErrorTextA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiInGetErrorTextW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiInGetID = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiInGetNumDevs = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiInMessage = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiInOpen = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiInPrepareHeader = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiInReset = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiInStart = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiInStop = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiInUnprepareHeader = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutCacheDrumPatches = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutCachePatches = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutClose = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutGetDevCapsA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutGetDevCapsW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutGetErrorTextA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutGetErrorTextW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutGetID = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutGetNumDevs = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutGetVolume = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutLongMsg = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutMessage = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutOpen = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutPrepareHeader = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutReset = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutSetVolume = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutShortMsg = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiOutUnprepareHeader = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiStreamClose = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiStreamOpen = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiStreamOut = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiStreamPause = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiStreamPosition = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiStreamProperty = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiStreamRestart = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_midiStreamStop = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mixerClose = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mixerGetControlDetailsA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mixerGetControlDetailsW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mixerGetDevCapsA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mixerGetDevCapsW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mixerGetID = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mixerGetLineControlsA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mixerGetLineControlsW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mixerGetLineInfoA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mixerGetLineInfoW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mixerGetNumDevs = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mixerMessage = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mixerOpen = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mixerSetControlDetails = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmDrvInstall = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmGetCurrentTask = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmTaskBlock = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmTaskCreate = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmTaskSignal = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmTaskYield = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioAdvance = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioAscend = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioClose = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioCreateChunk = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioDescend = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioFlush = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioGetInfo = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioInstallIOProcA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioInstallIOProcW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioOpenA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioOpenW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioRead = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioRenameA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioRenameW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioSeek = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioSendMessage = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioSetBuffer = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioSetInfo = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioStringToFOURCCA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioStringToFOURCCW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmioWrite = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_mmsystemGetVersion = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_sndPlaySoundA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_sndPlaySoundW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_timeBeginPeriod = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_timeEndPeriod = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_timeGetDevCaps = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_timeGetSystemTime = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_timeGetTime = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_timeKillEvent = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_timeSetEvent = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInAddBuffer = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInClose = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInGetDevCapsA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInGetDevCapsW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInGetErrorTextA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInGetErrorTextW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInGetID = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInGetNumDevs = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInGetPosition = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInMessage = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInOpen = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInPrepareHeader = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInReset = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInStart = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInStop = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveInUnprepareHeader = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutBreakLoop = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutClose = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutGetDevCapsA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutGetDevCapsW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutGetErrorTextA = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutGetErrorTextW = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutGetID = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutGetNumDevs = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutGetPitch = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutGetPlaybackRate = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutGetPosition = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutGetVolume = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutMessage = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutOpen = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutPause = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutPrepareHeader = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutReset = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutRestart = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutSetPitch = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutSetPlaybackRate = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutSetVolume = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutUnprepareHeader = reinterpret_cast<FARPROC>(&MissingWinmmExport);
    extern "C" FARPROC g_waveOutWrite = reinterpret_cast<FARPROC>(&MissingWinmmExport);

    void Bind(FARPROC& target, const char* name)
    {
        const auto found = g_original ? GetProcAddress(g_original, name) : nullptr;
        target = found ? found : reinterpret_cast<FARPROC>(&MissingWinmmExport);
    }

    void BindOrdinal(FARPROC& target, WORD ordinal)
    {
        const auto found = g_original ? GetProcAddress(g_original, reinterpret_cast<LPCSTR>(static_cast<ULONG_PTR>(ordinal))) : nullptr;
        target = found ? found : reinterpret_cast<FARPROC>(&MissingWinmmExport);
    }

    void AppendPath(wchar_t* path, const wchar_t* name)
    {
        const auto length = lstrlenW(path);
        if (length > 0 && path[length - 1] != L'\\' && path[length - 1] != L'/')
        {
            lstrcatW(path, L"\\");
        }
        lstrcatW(path, name);
    }

    bool GetBaseDir(wchar_t* out, DWORD outChars)
    {
        const auto length = GetModuleFileNameW(g_module, out, outChars);
        if (length == 0 || length >= outChars)
        {
            return false;
        }

        for (DWORD i = length; i > 0; --i)
        {
            if (out[i - 1] == L'\\' || out[i - 1] == L'/')
            {
                out[i] = L'\0';
                return true;
            }
        }

        out[0] = L'\0';
        return true;
    }

    void LogLine(const wchar_t* text)
    {
        wchar_t path[MAX_PATH]{};
        if (!GetBaseDir(path, MAX_PATH))
        {
            return;
        }

        AppendPath(path, L"loaderU.log");
        const auto file = CreateFileW(path, FILE_APPEND_DATA, FILE_SHARE_READ, nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
        if (file == INVALID_HANDLE_VALUE)
        {
            return;
        }

        wchar_t line[1024]{};
        lstrcpynW(line, text, 900);
        lstrcatW(line, L"\r\n");
        DWORD written = 0;
        WriteFile(file, line, static_cast<DWORD>(lstrlenW(line) * sizeof(wchar_t)), &written, nullptr);
        CloseHandle(file);
    }

    wchar_t LowerChar(wchar_t ch)
    {
        if (ch >= L'A' && ch <= L'Z')
        {
            return static_cast<wchar_t>(ch - L'A' + L'a');
        }
        return ch;
    }

    bool WildMatchAsciiI(const wchar_t* pattern, const wchar_t* text)
    {
        const wchar_t* star = nullptr;
        const wchar_t* retry = nullptr;

        while (*text)
        {
            if (*pattern == L'*')
            {
                star = pattern++;
                retry = text;
                continue;
            }

            if (*pattern == L'?' || LowerChar(*pattern) == LowerChar(*text))
            {
                ++pattern;
                ++text;
                continue;
            }

            if (star)
            {
                pattern = star + 1;
                text = ++retry;
                continue;
            }

            return false;
        }

        while (*pattern == L'*')
        {
            ++pattern;
        }

        return *pattern == L'\0';
    }

    bool GetProcessFileName(wchar_t* out, DWORD outChars)
    {
        const auto length = GetModuleFileNameW(nullptr, out, outChars);
        if (length == 0 || length >= outChars)
        {
            return false;
        }

        const wchar_t* name = out;
        for (DWORD i = 0; i < length; ++i)
        {
            if (out[i] == L'\\' || out[i] == L'/')
            {
                name = out + i + 1;
            }
        }

        if (name != out)
        {
            MoveMemory(out, name, (lstrlenW(name) + 1) * sizeof(wchar_t));
        }
        return true;
    }

    bool TargetMatches(const PluginInfo* info, const wchar_t* exeName)
    {
        const wchar_t* targets = info->target_apps && info->target_apps[0] ? info->target_apps : L"BNSR.exe;Client.exe";
        wchar_t buffer[512]{};
        lstrcpynW(buffer, targets, 512);

        wchar_t* context = nullptr;
        wchar_t* token = wcstok_s(buffer, L";", &context);
        while (token)
        {
            while (*token == L' ')
            {
                ++token;
            }

            if (WildMatchAsciiI(token, exeName))
            {
                return true;
            }

            token = wcstok_s(nullptr, L";", &context);
        }

        return false;
    }

    void SortPluginsByPriority()
    {
        for (int i = 0; i < g_pluginCount; ++i)
        {
            for (int j = i + 1; j < g_pluginCount; ++j)
            {
                if (g_plugins[j].info->priority > g_plugins[i].info->priority)
                {
                    const auto tmp = g_plugins[i];
                    g_plugins[i] = g_plugins[j];
                    g_plugins[j] = tmp;
                }
            }
        }
    }

    void AddPlugin(HMODULE module, const PluginInfo* info, const wchar_t* path)
    {
        if (g_pluginCount >= 128)
        {
            FreeLibrary(module);
            return;
        }

        g_plugins[g_pluginCount].module = module;
        g_plugins[g_pluginCount].info = info;
        lstrcpynW(g_plugins[g_pluginCount].path, path, MAX_PATH);
        ++g_pluginCount;
    }

    void LoadPluginsFromDirectory(const wchar_t* dir, const wchar_t* exeName)
    {
        wchar_t pattern[MAX_PATH]{};
        lstrcpynW(pattern, dir, MAX_PATH);
        AppendPath(pattern, L"*.dll");

        WIN32_FIND_DATAW data{};
        const auto find = FindFirstFileW(pattern, &data);
        if (find == INVALID_HANDLE_VALUE)
        {
            return;
        }

        do
        {
            if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
            {
                continue;
            }

            wchar_t pluginPath[MAX_PATH]{};
            lstrcpynW(pluginPath, dir, MAX_PATH);
            AppendPath(pluginPath, data.cFileName);

            const auto module = LoadLibraryExW(pluginPath, nullptr, LOAD_WITH_ALTERED_SEARCH_PATH);
            if (!module)
            {
                continue;
            }

            const auto info = reinterpret_cast<const PluginInfo*>(GetProcAddress(module, "GPluginInfo"));
            if (!info || info->sdk_version.major < 3 || !TargetMatches(info, exeName))
            {
                FreeLibrary(module);
                continue;
            }

            AddPlugin(module, info, pluginPath);
        } while (FindNextFileW(find, &data));

        FindClose(find);
    }

    void RunPluginInit()
    {
        wchar_t exeName[MAX_PATH]{};
        if (!GetProcessFileName(exeName, MAX_PATH))
        {
            return;
        }

        wchar_t dir[MAX_PATH]{};
        const auto envLength = GetEnvironmentVariableW(L"LOADERU_PLUGINS_DIR", dir, MAX_PATH);
        if (envLength == 0 || envLength >= MAX_PATH)
        {
            if (!GetBaseDir(dir, MAX_PATH))
            {
                return;
            }
            AppendPath(dir, L"loaderU");
        }

        LogLine(L"loaderU: plugin scan started.");
        LoadPluginsFromDirectory(dir, exeName);
        SortPluginsByPriority();

        Version gameVersion{};
        gameVersion = LoaderUSdkVersion;

        for (int i = 0; i < g_pluginCount;)
        {
            const auto info = g_plugins[i].info;
            if (info->init && !info->init(gameVersion))
            {
                FreeLibrary(g_plugins[i].module);
                for (int j = i; j < g_pluginCount - 1; ++j)
                {
                    g_plugins[j] = g_plugins[j + 1];
                }
                --g_pluginCount;
                continue;
            }
            ++i;
        }

        for (int i = 0; i < g_pluginCount; ++i)
        {
            if (g_plugins[i].info->oep_notify)
            {
                g_plugins[i].info->oep_notify(gameVersion);
            }
        }

        LogLine(L"loaderU: plugin scan finished.");
    }

    DWORD WINAPI LoaderUThread(LPVOID)
    {
        Sleep(7000);
        RunPluginInit();
        return 0;
    }

    void LoadSystemWinmm()
    {
        wchar_t systemDir[MAX_PATH]{};
        const auto length = GetSystemDirectoryW(systemDir, MAX_PATH);
        if (length == 0 || length >= MAX_PATH) return;
        lstrcatW(systemDir, L"\\winmm.dll");
        g_original = LoadLibraryW(systemDir);
        if (!g_original) return;

        BindOrdinal(g_Ordinal_2, 2);
        Bind(g_mciExecute, "mciExecute");
        Bind(g_CloseDriver, "CloseDriver");
        Bind(g_DefDriverProc, "DefDriverProc");
        Bind(g_DriverCallback, "DriverCallback");
        Bind(g_DrvGetModuleHandle, "DrvGetModuleHandle");
        Bind(g_GetDriverModuleHandle, "GetDriverModuleHandle");
        Bind(g_OpenDriver, "OpenDriver");
        Bind(g_PlaySound, "PlaySound");
        Bind(g_PlaySoundA, "PlaySoundA");
        Bind(g_PlaySoundW, "PlaySoundW");
        Bind(g_SendDriverMessage, "SendDriverMessage");
        Bind(g_WOWAppExit, "WOWAppExit");
        Bind(g_auxGetDevCapsA, "auxGetDevCapsA");
        Bind(g_auxGetDevCapsW, "auxGetDevCapsW");
        Bind(g_auxGetNumDevs, "auxGetNumDevs");
        Bind(g_auxGetVolume, "auxGetVolume");
        Bind(g_auxOutMessage, "auxOutMessage");
        Bind(g_auxSetVolume, "auxSetVolume");
        Bind(g_joyConfigChanged, "joyConfigChanged");
        Bind(g_joyGetDevCapsA, "joyGetDevCapsA");
        Bind(g_joyGetDevCapsW, "joyGetDevCapsW");
        Bind(g_joyGetNumDevs, "joyGetNumDevs");
        Bind(g_joyGetPos, "joyGetPos");
        Bind(g_joyGetPosEx, "joyGetPosEx");
        Bind(g_joyGetThreshold, "joyGetThreshold");
        Bind(g_joyReleaseCapture, "joyReleaseCapture");
        Bind(g_joySetCapture, "joySetCapture");
        Bind(g_joySetThreshold, "joySetThreshold");
        Bind(g_mciDriverNotify, "mciDriverNotify");
        Bind(g_mciDriverYield, "mciDriverYield");
        Bind(g_mciFreeCommandResource, "mciFreeCommandResource");
        Bind(g_mciGetCreatorTask, "mciGetCreatorTask");
        Bind(g_mciGetDeviceIDA, "mciGetDeviceIDA");
        Bind(g_mciGetDeviceIDFromElementIDA, "mciGetDeviceIDFromElementIDA");
        Bind(g_mciGetDeviceIDFromElementIDW, "mciGetDeviceIDFromElementIDW");
        Bind(g_mciGetDeviceIDW, "mciGetDeviceIDW");
        Bind(g_mciGetDriverData, "mciGetDriverData");
        Bind(g_mciGetErrorStringA, "mciGetErrorStringA");
        Bind(g_mciGetErrorStringW, "mciGetErrorStringW");
        Bind(g_mciGetYieldProc, "mciGetYieldProc");
        Bind(g_mciLoadCommandResource, "mciLoadCommandResource");
        Bind(g_mciSendCommandA, "mciSendCommandA");
        Bind(g_mciSendCommandW, "mciSendCommandW");
        Bind(g_mciSendStringA, "mciSendStringA");
        Bind(g_mciSendStringW, "mciSendStringW");
        Bind(g_mciSetDriverData, "mciSetDriverData");
        Bind(g_mciSetYieldProc, "mciSetYieldProc");
        Bind(g_midiConnect, "midiConnect");
        Bind(g_midiDisconnect, "midiDisconnect");
        Bind(g_midiInAddBuffer, "midiInAddBuffer");
        Bind(g_midiInClose, "midiInClose");
        Bind(g_midiInGetDevCapsA, "midiInGetDevCapsA");
        Bind(g_midiInGetDevCapsW, "midiInGetDevCapsW");
        Bind(g_midiInGetErrorTextA, "midiInGetErrorTextA");
        Bind(g_midiInGetErrorTextW, "midiInGetErrorTextW");
        Bind(g_midiInGetID, "midiInGetID");
        Bind(g_midiInGetNumDevs, "midiInGetNumDevs");
        Bind(g_midiInMessage, "midiInMessage");
        Bind(g_midiInOpen, "midiInOpen");
        Bind(g_midiInPrepareHeader, "midiInPrepareHeader");
        Bind(g_midiInReset, "midiInReset");
        Bind(g_midiInStart, "midiInStart");
        Bind(g_midiInStop, "midiInStop");
        Bind(g_midiInUnprepareHeader, "midiInUnprepareHeader");
        Bind(g_midiOutCacheDrumPatches, "midiOutCacheDrumPatches");
        Bind(g_midiOutCachePatches, "midiOutCachePatches");
        Bind(g_midiOutClose, "midiOutClose");
        Bind(g_midiOutGetDevCapsA, "midiOutGetDevCapsA");
        Bind(g_midiOutGetDevCapsW, "midiOutGetDevCapsW");
        Bind(g_midiOutGetErrorTextA, "midiOutGetErrorTextA");
        Bind(g_midiOutGetErrorTextW, "midiOutGetErrorTextW");
        Bind(g_midiOutGetID, "midiOutGetID");
        Bind(g_midiOutGetNumDevs, "midiOutGetNumDevs");
        Bind(g_midiOutGetVolume, "midiOutGetVolume");
        Bind(g_midiOutLongMsg, "midiOutLongMsg");
        Bind(g_midiOutMessage, "midiOutMessage");
        Bind(g_midiOutOpen, "midiOutOpen");
        Bind(g_midiOutPrepareHeader, "midiOutPrepareHeader");
        Bind(g_midiOutReset, "midiOutReset");
        Bind(g_midiOutSetVolume, "midiOutSetVolume");
        Bind(g_midiOutShortMsg, "midiOutShortMsg");
        Bind(g_midiOutUnprepareHeader, "midiOutUnprepareHeader");
        Bind(g_midiStreamClose, "midiStreamClose");
        Bind(g_midiStreamOpen, "midiStreamOpen");
        Bind(g_midiStreamOut, "midiStreamOut");
        Bind(g_midiStreamPause, "midiStreamPause");
        Bind(g_midiStreamPosition, "midiStreamPosition");
        Bind(g_midiStreamProperty, "midiStreamProperty");
        Bind(g_midiStreamRestart, "midiStreamRestart");
        Bind(g_midiStreamStop, "midiStreamStop");
        Bind(g_mixerClose, "mixerClose");
        Bind(g_mixerGetControlDetailsA, "mixerGetControlDetailsA");
        Bind(g_mixerGetControlDetailsW, "mixerGetControlDetailsW");
        Bind(g_mixerGetDevCapsA, "mixerGetDevCapsA");
        Bind(g_mixerGetDevCapsW, "mixerGetDevCapsW");
        Bind(g_mixerGetID, "mixerGetID");
        Bind(g_mixerGetLineControlsA, "mixerGetLineControlsA");
        Bind(g_mixerGetLineControlsW, "mixerGetLineControlsW");
        Bind(g_mixerGetLineInfoA, "mixerGetLineInfoA");
        Bind(g_mixerGetLineInfoW, "mixerGetLineInfoW");
        Bind(g_mixerGetNumDevs, "mixerGetNumDevs");
        Bind(g_mixerMessage, "mixerMessage");
        Bind(g_mixerOpen, "mixerOpen");
        Bind(g_mixerSetControlDetails, "mixerSetControlDetails");
        Bind(g_mmDrvInstall, "mmDrvInstall");
        Bind(g_mmGetCurrentTask, "mmGetCurrentTask");
        Bind(g_mmTaskBlock, "mmTaskBlock");
        Bind(g_mmTaskCreate, "mmTaskCreate");
        Bind(g_mmTaskSignal, "mmTaskSignal");
        Bind(g_mmTaskYield, "mmTaskYield");
        Bind(g_mmioAdvance, "mmioAdvance");
        Bind(g_mmioAscend, "mmioAscend");
        Bind(g_mmioClose, "mmioClose");
        Bind(g_mmioCreateChunk, "mmioCreateChunk");
        Bind(g_mmioDescend, "mmioDescend");
        Bind(g_mmioFlush, "mmioFlush");
        Bind(g_mmioGetInfo, "mmioGetInfo");
        Bind(g_mmioInstallIOProcA, "mmioInstallIOProcA");
        Bind(g_mmioInstallIOProcW, "mmioInstallIOProcW");
        Bind(g_mmioOpenA, "mmioOpenA");
        Bind(g_mmioOpenW, "mmioOpenW");
        Bind(g_mmioRead, "mmioRead");
        Bind(g_mmioRenameA, "mmioRenameA");
        Bind(g_mmioRenameW, "mmioRenameW");
        Bind(g_mmioSeek, "mmioSeek");
        Bind(g_mmioSendMessage, "mmioSendMessage");
        Bind(g_mmioSetBuffer, "mmioSetBuffer");
        Bind(g_mmioSetInfo, "mmioSetInfo");
        Bind(g_mmioStringToFOURCCA, "mmioStringToFOURCCA");
        Bind(g_mmioStringToFOURCCW, "mmioStringToFOURCCW");
        Bind(g_mmioWrite, "mmioWrite");
        Bind(g_mmsystemGetVersion, "mmsystemGetVersion");
        Bind(g_sndPlaySoundA, "sndPlaySoundA");
        Bind(g_sndPlaySoundW, "sndPlaySoundW");
        Bind(g_timeBeginPeriod, "timeBeginPeriod");
        Bind(g_timeEndPeriod, "timeEndPeriod");
        Bind(g_timeGetDevCaps, "timeGetDevCaps");
        Bind(g_timeGetSystemTime, "timeGetSystemTime");
        Bind(g_timeGetTime, "timeGetTime");
        Bind(g_timeKillEvent, "timeKillEvent");
        Bind(g_timeSetEvent, "timeSetEvent");
        Bind(g_waveInAddBuffer, "waveInAddBuffer");
        Bind(g_waveInClose, "waveInClose");
        Bind(g_waveInGetDevCapsA, "waveInGetDevCapsA");
        Bind(g_waveInGetDevCapsW, "waveInGetDevCapsW");
        Bind(g_waveInGetErrorTextA, "waveInGetErrorTextA");
        Bind(g_waveInGetErrorTextW, "waveInGetErrorTextW");
        Bind(g_waveInGetID, "waveInGetID");
        Bind(g_waveInGetNumDevs, "waveInGetNumDevs");
        Bind(g_waveInGetPosition, "waveInGetPosition");
        Bind(g_waveInMessage, "waveInMessage");
        Bind(g_waveInOpen, "waveInOpen");
        Bind(g_waveInPrepareHeader, "waveInPrepareHeader");
        Bind(g_waveInReset, "waveInReset");
        Bind(g_waveInStart, "waveInStart");
        Bind(g_waveInStop, "waveInStop");
        Bind(g_waveInUnprepareHeader, "waveInUnprepareHeader");
        Bind(g_waveOutBreakLoop, "waveOutBreakLoop");
        Bind(g_waveOutClose, "waveOutClose");
        Bind(g_waveOutGetDevCapsA, "waveOutGetDevCapsA");
        Bind(g_waveOutGetDevCapsW, "waveOutGetDevCapsW");
        Bind(g_waveOutGetErrorTextA, "waveOutGetErrorTextA");
        Bind(g_waveOutGetErrorTextW, "waveOutGetErrorTextW");
        Bind(g_waveOutGetID, "waveOutGetID");
        Bind(g_waveOutGetNumDevs, "waveOutGetNumDevs");
        Bind(g_waveOutGetPitch, "waveOutGetPitch");
        Bind(g_waveOutGetPlaybackRate, "waveOutGetPlaybackRate");
        Bind(g_waveOutGetPosition, "waveOutGetPosition");
        Bind(g_waveOutGetVolume, "waveOutGetVolume");
        Bind(g_waveOutMessage, "waveOutMessage");
        Bind(g_waveOutOpen, "waveOutOpen");
        Bind(g_waveOutPause, "waveOutPause");
        Bind(g_waveOutPrepareHeader, "waveOutPrepareHeader");
        Bind(g_waveOutReset, "waveOutReset");
        Bind(g_waveOutRestart, "waveOutRestart");
        Bind(g_waveOutSetPitch, "waveOutSetPitch");
        Bind(g_waveOutSetPlaybackRate, "waveOutSetPlaybackRate");
        Bind(g_waveOutSetVolume, "waveOutSetVolume");
        Bind(g_waveOutUnprepareHeader, "waveOutUnprepareHeader");
        Bind(g_waveOutWrite, "waveOutWrite");
    }
}

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        g_module = instance;
        DisableThreadLibraryCalls(g_module);
        LoadSystemWinmm();

        const auto thread = CreateThread(nullptr, 0, LoaderUThread, nullptr, 0, nullptr);
        if (thread)
        {
            CloseHandle(thread);
        }
    }
    return TRUE;
}
