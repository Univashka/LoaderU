$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
$Out = Join-Path $Root "build"
$VcVars = "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
if (!(Test-Path -LiteralPath $VcVars)) {
    $VcVars = "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
}
if (!(Test-Path -LiteralPath $VcVars)) {
    throw "vcvars64.bat was not found."
}

New-Item -ItemType Directory -Force -Path $Out | Out-Null
$Bat = Join-Path $Out "build-loaderu-test-plugin.cmd"
@(
    '@echo off',
    'setlocal',
    ('call "{0}"' -f $VcVars),
    ('cd /d "{0}"' -f $Root),
    ('cl /nologo /std:c++20 /O1 /GS- /MT /LD TestPlugin.cpp /Fo"{0}\TestPlugin.obj" /Fe"{0}\loaderU_test_plugin.dll" /link /OUT:"{0}\loaderU_test_plugin.dll" /IMPLIB:"{0}\loaderU_test_plugin.lib" /PDB:"{0}\loaderU_test_plugin.pdb" /OPT:REF /OPT:ICF' -f $Out),
    'exit /b %ERRORLEVEL%'
) | Set-Content -LiteralPath $Bat -Encoding ASCII

& cmd.exe /c "`"$Bat`""
if ($LASTEXITCODE -ne 0) {
    throw "Build failed with exit code $LASTEXITCODE"
}
Write-Host "Built: $Out\loaderU_test_plugin.dll"
