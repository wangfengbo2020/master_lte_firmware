@echo off
setlocal EnableDelayedExpansion
set CURDIR=%~dp0
set target=%1
set /p compile_flag=<%CURDIR%\config\common\compile_flag.txt
echo %compile_flag%

set /P FLASH_SIZE=<..\..\ql-config\config\FLASH_SIZE.ini
set /P RAM_SIZE=<%CURDIR%\config\ram\RAM_SIZE.ini
set /P ExtFlashType=<..\..\ql-config\config\EXT_FLASH.ini
set /p func=<..\..\ql-config\config\func.txt

if "%target%" == "clean" (
	gnumake -f Makefile clean TOP_DIR=%CURDIR%
) else (
	echo %compile_flag%|findstr "twice" >nul
	if !errorlevel! neq 1 (
		gnumake -f Makefile TOP_DIR=%CURDIR%
		copy %CURDIR%\config\common\feedbackLinkOptLteonlyThin.txt %CURDIR%\config\common\feedbackLink_backup.txt
		gnumake -f Makefile TOP_DIR=%CURDIR%
		echo need_compile_once >%CURDIR%\config\common\compile_flag.txt
	) else (
		copy %CURDIR%\config\common\feedbackLinkOptLteonlyThin.txt %CURDIR%\config\common\feedbackLink_backup.txt
		gnumake -f Makefile TOP_DIR=%CURDIR%
	)
)	
exit /b 0