@echo off
cls
title ParturIH314
setlocal enabledelayedexpansion
for /f %%a in (params.txt) do set checkContent=%%a
if not !checkContent! gtr 0 (
set /p "np=Set your ndk path: "
set /p  "pp=Set your project path: "
) else (
for /f "delims=" %%x in (params.txt) do set pp=%%x
set /p np=<params.txt
echo ndk path: !np!
echo project path: !pp!
)
echo.
call ndk-build NDK_PROJECT_PATH=%pp%\x32 NDK_APPLICATION_MK=%pp%\x32\jni\Application.mk MAIN_LOCAL_PATH="%pp%\x32\jni"
if "%errorlevel%"=="0" (echo Build successful.) else (echo Build failed.)
xcopy /y "%pp%\x32\libs\armeabi-v7a" "%pp%\out\armeabi-v7a\"*
echo.