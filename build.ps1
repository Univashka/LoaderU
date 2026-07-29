$ErrorActionPreference = "Stop"
$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
$Out = Join-Path $Root "build"
$VcVars = "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
if (!(Test-Path -LiteralPath $VcVars)) { $VcVars = "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" }
if (!(Test-Path -LiteralPath $VcVars)) { throw "vcvars64.bat was not found." }
New-Item -ItemType Directory -Force -Path $Out | Out-Null
$Bat = Join-Path $Out "build-clean-winmm.cmd"
@(
    '@echo off',
    'setlocal',
    ('call "{0}"' -f $VcVars),
    ('cd /d "{0}"' -f $Root),
    ('ml64 /nologo /c /Fo"{0}\WinmmForwardStubs.obj" WinmmForwardStubs.asm' -f $Out),
    ('cl /nologo /std:c++20 /O1 /GS- /MT /LD LoaderU.cpp "{0}\WinmmForwardStubs.obj" /Fo"{0}\LoaderU.obj" /Fe"{0}\winmm.dll" /link /DEF:winmm.def /OUT:"{0}\winmm.dll" /IMPLIB:"{0}\winmm.lib" /PDB:"{0}\winmm.pdb" /OPT:REF /OPT:ICF' -f $Out),
    'exit /b %ERRORLEVEL%'
) | Set-Content -LiteralPath $Bat -Encoding ASCII
& cmd.exe /c "`"$Bat`""
if ($LASTEXITCODE -ne 0) { throw "Build failed with exit code $LASTEXITCODE" }
if (!(Test-Path -LiteralPath (Join-Path $Out "winmm.dll"))) { throw "Build completed, but winmm.dll was not produced." }
Write-Host "Built: $Out\winmm.dll"
