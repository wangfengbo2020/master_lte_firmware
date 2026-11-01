::Note
::MUST excute build_all.bat in DS-5 env. 

::Turn off the echo from this line
@echo off
if "%1%"=="clean" (
	if exist release rd /s /q release
	goto SUCCESS
)
set DMCHAGE=disable
set LOGO_SUPPORT=enable
set SECBOOT_V2_SUPPORT=disable
set QUECTEL_PROJ=OCPU
set PL_TYPE=CRANEL
set DM_FOTA=enable
set FOTA_NO_UPDATER=disable

set compile_tools_dir=..\..\ql-cross-tool\win32\owtoolchain

if "%QUECTEL_COMPILE_TOOLS_V1%"=="" (
    set QUECTEL_COMPILE_TOOLS_V1=%compile_tools_dir%
)

set COMPILE_TOOLS_PATH=%QUECTEL_COMPILE_TOOLS_V1%;%QUECTEL_COMPILE_TOOLS_V1%\ARM_Compiler_5\bin;%QUECTEL_COMPILE_TOOLS_V1%\Perl\site\bin;%QUECTEL_COMPILE_TOOLS_V1%\Perl\bin;%QUECTEL_COMPILE_TOOLS_V1%\gnumake;%PATH%;

if "%COMPILE_ENV_SET_FLAG%"==""  echo --------------set compile tools path------------------- && set PATH=%COMPILE_TOOLS_PATH% && set COMPILE_ENV_SET_FLAG=done


set ARMLMD_LICENSE_FILE=%QUECTEL_COMPILE_TOOLS_V1%\license.dat

::create release directory
if not exist release md release

del /s /q /f release\*
::open comment(goto START and goto SUCCESS) to control build specilize boot33*.bin
::goto START
gnumake clean
gnumake feedback
gnumake
copy /Y boot33.bin release\boot33.bin
copy /Y boot33.axf release\boot33.axf
copy /Y boot33.map release\boot33.map
::check file exist in release?
if not exist release\boot33.bin goto ERROR
goto SUCCESS

:ERROR
::gnumake clean
echo ****************************************************************
echo ***********************  ERROR  ********************************
echo ****************************************************************
goto END

:SUCCESS
gnumake clean
echo ****************************************************************
echo ***********************  SUCCESS  ******************************
echo ****************************************************************
:END
