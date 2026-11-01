@echo off
%1 start "" mshta vbscript:createobject("shell.application").shellexecute("""%~0""","::",,"runas",1)(window.close)&exit

set CURDIR=%~dp0
cd /d %CURDIR%
.\ARM_Compiler_5\patcher.exe --dir . -c
.\ARM_Compiler_5\patcher.exe --license=ARM_DS_5 . > nul
cd /d %CURDIR%

set ARMLMD_LICENSE_FILE=%CURDIR%\license.dat

@echo.
@echo --------------------armcc---------------------
ARM_Compiler_5\bin\armcc --vsn

SETLOCAL ENABLEDELAYEDEXPANSION
for /f "delims=" %%i in ('ARM_Compiler_5\bin\armcc --vsn') do (set ret=!ret!%%i;)
echo !ret! | findstr /C:"Software supplied by" >nul || ( ENDLOCAL & goto ERROR)
ENDLOCAL

@echo.
@echo --------------------perl---------------------
Perl\bin\perl -v

@echo.
@echo --------------------gnumake---------------------
Gnumake\gnumake -v

::setx QUECTEL_COMPILE_TOOLS_V1 %CURDIR%

@echo.
@echo Install compile tools successfuly![Do not to move this directory!]
@echo.
goto EXIT

:ERROR
@echo.
@echo Install compile tools unsuccessfuly!
@echo.

:EXIT
@echo Please press any key to exit...
pause > nul
exit