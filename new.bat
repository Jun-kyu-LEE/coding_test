@echo off
setlocal
set "ROOT=%~dp0"

if "%~1"=="" (
    echo Usage: new ^<number^>            e.g.  new 11315
    echo        new ^<site^> ^<number^>   e.g.  new baekjoon 1000
    exit /b 1
)

if "%~2"=="" (
    set "DIR=swea"
    set "NUM=%~1"
) else (
    set "DIR=%~1"
    set "NUM=%~2"
)

set "TARGET=%ROOT%%DIR%\%NUM%.cpp"

if exist "%TARGET%" (
    echo [open ] %DIR%\%NUM%.cpp
) else (
    copy /y "%ROOT%templates\swea_base.cpp" "%TARGET%" >nul
    echo [new  ] %DIR%\%NUM%.cpp
)

start "" "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" /edit "%TARGET%"
