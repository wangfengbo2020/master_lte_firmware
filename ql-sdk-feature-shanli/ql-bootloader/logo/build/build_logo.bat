::Note: must excute build_logo.bat in DS-5 env. 
::devide by LCD_TYPE
::naming rule: logo_[lcdtype].bin

@echo off

::define some variables
set DIR_RELEASE=..\release
set DIR_README_LOGO=..

::create release directory in logo directory
if not exist %DIR_RELEASE% md %DIR_RELEASE%
::create subdirectory logo_axf_map in .\release directory
if not exist %DIR_RELEASE%\logo_axf_map md %DIR_RELEASE%\logo_axf_map

set ADD_COMMON_DIR=TRUE

del /s /q /f %DIR_RELEASE%\*
::copy logo_readme.txt
copy /Y %DIR_README_LOGO%\readme_logo.txt %DIR_RELEASE%\

::*********************************************
set SMALL_CODE=LOGO
::*********************************************
::goto START

::*************************************1.1 LCD_ADAPT******************************************
::config: ST7789DKB:3line_2data
::        gc9306:   3line_2data
		  gc9304:   3line_2data
::**************************************************************************************************
::START
make clean
set LCD_TYPE=LCD_ADAPT
make 
copy /Y logo*.bin %DIR_RELEASE%\
copy /Y logo*axf %DIR_RELEASE%\logo_axf_map
copy /Y logo*map %DIR_RELEASE%\logo_axf_map

::check file exist in release?
if not exist %DIR_RELEASE%\logo_lcd_adapt.bin goto ERROR
goto SUCCESS

::*************************************1.2 ST7789VER2******************************************
::config: 4line  2data
::*********************************************************************************************
::START
make clean
set LCD_TYPE=ST7789VER2
make 
copy /Y logo*.bin %DIR_RELEASE%\
copy /Y logo*axf %DIR_RELEASE%\logo_axf_map
copy /Y logo*map %DIR_RELEASE%\logo_axf_map

::check file exist in release?
if not exist %DIR_RELEASE%\logo_st7789ver2.bin goto ERROR
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


