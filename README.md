# LoaderU

Minimal `winmm.dll` proxy loader based on the useful part of `loader3`.

This build keeps the safe architecture:

- local `winmm.dll` proxy entry;
- real `winmm.dll` is loaded from `C:\Windows\System32`;
- all 181 exports match the local system `winmm.dll`;
- plugin loading is delayed by 7 seconds;
- plugin contract is compatible with `GPluginInfo` SDK 3.x style;
- plugins are sorted by `priority`;
- plugins can filter target exe through `target_apps`.

This build intentionally does not include the old loader3 anti-debug, PEB hiding,
PE-header wiping, process filtering, DLL blocking, or thread-blocking hooks.

## Install for test

Build:

```powershell
.\build.ps1
```

Copy `build\winmm.dll` to:

```text
BNSR\Binaries\Win64\winmm.dll
```

Create plugin folder:

```text
BNSR\Binaries\Win64\LoaderU
```

Put plugin DLL files there.

Optional override:

```text
LOADERU_PLUGINS_DIR=C:\Some\Other\Folder
```

## Logs

`loaderU` writes a small UTF-16 log next to the game exe:

```text
BNSR\Binaries\Win64\loaderU.log
```

Expected successful lines:

```text
loaderU: plugin scan started.
loaderU: plugin scan finished.
```

## Plugin contract

Export a data symbol named `GPluginInfo`:

```cpp
extern "C" __declspec(dllexport) PluginInfo GPluginInfo = {
    {3, 1, 0, 0},
    false,
    false,
    init,
    oep_notify,
    100,
    L"BNSR.exe;Client.exe"
};
```

Supported fields:

- `sdk_version`: must be major `3` or newer;
- `init`: optional, return `false` to reject loading;
- `oep_notify`: optional, called after all accepted plugins are initialized;
- `priority`: bigger priority initializes earlier;
- `target_apps`: semicolon-separated wildcard list, default is `BNSR.exe;Client.exe`.

Ignored fields:

- `hide_from_peb`;
- `erase_pe_header`.
