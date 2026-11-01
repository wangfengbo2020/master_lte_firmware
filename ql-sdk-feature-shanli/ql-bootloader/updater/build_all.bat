@echo off
set CURDIR=%~dp0

set ARMCC_PATH=
set PATH_TMP=
@for %%i in (armcc.exe) do (
	@if not "%%~$PATH:i"=="" ( 
		set PATH_TMP=%%~$PATH:i
		SETLOCAL ENABLEDELAYEDEXPANSION
		for /f "delims=" %%i in ('armcc --vsn') do (set ret=!ret!%%i;)
		(echo !ret! | findstr /C:"Software supplied by" >nul) && (echo !ret! | findstr /C:"ARM Compiler 5" >nul) && (ENDLOCAL & goto SITE1)
		ENDLOCAL
		goto SITE2
	) else (
		goto SITE2
	)
)
:SITE1
set PATH_TMP=%PATH_TMP:\armcc.exe=%
set ARMCC_PATH=%PATH_TMP%

:SITE2
set COMPILE_ENV_SET_FLAG=
set PATH=%SystemRoot%;%SystemRoot%\system32;

if "%QUECTEL_COMPILE_TOOLS_V1%"=="" (
    set QUECTEL_COMPILE_TOOLS_V1=%CURDIR%\..\..\ql-cross-tool\win32\owtoolchain
)
if "%ARMCC_PATH%"=="" (
    set ARMCC_PATH=%QUECTEL_COMPILE_TOOLS_V1%\ARM_Compiler_5\bin
    set ARMLMD_LICENSE_FILE=%QUECTEL_COMPILE_TOOLS_V1%\license.dat
)
set COMPILE_TOOLS_PATH=%PATH%;%ARMCC_PATH%;%QUECTEL_COMPILE_TOOLS_V1%;%QUECTEL_COMPILE_TOOLS_V1%\Perl\site\bin;%QUECTEL_COMPILE_TOOLS_V1%\Perl\bin;%QUECTEL_COMPILE_TOOLS_V1%\Gnumake;
if "%COMPILE_ENV_SET_FLAG%"==""  echo --------------set compile tools path------------------- && set PATH=%COMPILE_TOOLS_PATH% && set COMPILE_ENV_SET_FLAG=done
echo PATH:
echo %PATH%
echo -------------------------------------------------------
echo=
pushd build\
@call m_tee build.bat
popd
pause