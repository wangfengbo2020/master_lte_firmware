::Note
::MUST excute build_all.bat in DS-5 env. 

::Turn off the echo from this line
@echo off

set DMCHAGE=disable
set LOGO_SUPPORT=enable
set SECBOOT_V2_SUPPORT=disable
set PL_TYPE=CRANE
set DM_FOTA=enable
set FOTA_NO_UPDATER=disable

if "%QUECTEL_COMPILE_TOOLS_V1%"=="" (
    set QUECTEL_COMPILE_TOOLS_V1=%compile_tools_dir%
)

set COMPILE_TOOLS_PATH=%QUECTEL_COMPILE_TOOLS_V1%;%QUECTEL_COMPILE_TOOLS_V1%\ARM_Compiler_5\bin;%QUECTEL_COMPILE_TOOLS_V1%\Perl\site\bin;%QUECTEL_COMPILE_TOOLS_V1%\Perl\bin;%QUECTEL_COMPILE_TOOLS_V1%\Gnumake;%PATH%;

if "%COMPILE_ENV_SET_FLAG%"==""  echo --------------set compile tools path------------------- && set PATH=%COMPILE_TOOLS_PATH% && set COMPILE_ENV_SET_FLAG=done

if "%QUECTEL_COMPILE_TOOLS_V1%"=="%compile_tools_dir%" (
	ipconfig.exe
	set /p lin=<recode.txt
	set %lin%
	del recode.txt
	@echo Using ARM Compiler Address is %lin%
) else (
	set ARMLMD_LICENSE_FILE=%QUECTEL_COMPILE_TOOLS_V1%\license.dat
)

::create release directory
if not exist release md release

del /s /q /f release\*
::open comment(goto START and goto SUCCESS) to control build specilize boot33*.bin
::goto START
make clean
make feedback
make 
copy /Y boot33*.* release\
::check file exist in release?
if not exist release\boot33.bin goto ERROR
goto SUCCESS

:ERROR
::make clean
echo ****************************************************************
echo ***********************  ERROR  ********************************
echo ****************************************************************
goto END

:SUCCESS
make clean
echo ****************************************************************
echo ***********************  SUCCESS  ******************************
echo ****************************************************************
:END
