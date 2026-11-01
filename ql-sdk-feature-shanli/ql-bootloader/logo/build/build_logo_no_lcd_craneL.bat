::Note: must excute build_logo.bat in DS-5 env. 
::devide by LCD_TYPE
::naming rule: [logo][suffix].bin
:: suffix including:
:: (1) _no_lcd
:: (2) lcd_type

@echo off

::设置DOC窗口的尺寸，COLS---列数； LINES--行数
MODE con: COLS=200 LINES=6000

::config parameters
::------------------------------------------------------------------------
::[PARAMETER1] -- directory info
set DIR_RELEASE=..\release
set DIR_README_LOGO=..

::[PARAMETER2] -- image prefix
set TARGET_PREFIX=logo

::[PARAMETER3] -- MODULE
set SMALL_CODE=LOGO
set LCD_TYPE=NO_LCD
set TARGET_SUFFIX=_no_dsp_adc
set CHIP_TYPE=CRANEL

::[PARAMETER4] -- FUNCTION SCRIPT
set COMPRESS_BAT_SCRIPT=asr_compressed_script.bat
::variable to control logo*.bin compressed or not
::TRUE or FALSE
set BUILD_COMPRESSED_LOGO=TRUE

::[PARAMETER5] -- release image name
set TARGET_BAT=%TARGET_PREFIX%%TARGET_SUFFIX%
::------------------------------------------------------------------------

:: enable/disable charge function
:: DMCHAGE=disable will disable charge function
:: DMCHAGE=enable will enable charge function
set DMCHAGE=disable

::create release directory in logo directory
if not exist %DIR_RELEASE% md %DIR_RELEASE%
::create subdirectory logo_axf_map in .\release directory
if not exist %DIR_RELEASE%\%TARGET_PREFIX%_axf_map md %DIR_RELEASE%\%TARGET_PREFIX%_axf_map


del /s /q /f %DIR_RELEASE%\*
::copy readme_logo.txt
copy /Y %DIR_README_LOGO%\readme_logo.txt %DIR_RELEASE%\

::goto START
::************************************* NO_LCD ***********************************************
::
::********************************************************************************************
::START
make clean
make
if not exist .\%TARGET_BAT%.bin goto ERROR

if "%BUILD_COMPRESSED_LOGO%"=="TRUE" (
	if exist %COMPRESS_BAT_SCRIPT% (
		echo %COMPRESS_BAT_SCRIPT% is exist, and compress %TARGET_PREFIX%.bin		
		call %COMPRESS_BAT_SCRIPT%
		make handle_after_compress
		rename *%TARGET_PREFIX%*.bin %TARGET_BAT%.bin
	) else (
		echo %COMPRESS_BAT_SCRIPT% is not exist, not compress logo.bin
	)
) else (
	echo build no compress logo*.bin
)


copy /Y %TARGET_PREFIX%*.bin %DIR_RELEASE%\
copy /Y %TARGET_PREFIX%*axf %DIR_RELEASE%\%TARGET_PREFIX%_axf_map
copy /Y %TARGET_PREFIX%*map %DIR_RELEASE%\%TARGET_PREFIX%_axf_map

::check file exist in release?
if not exist %DIR_RELEASE%\%TARGET_BAT%.bin goto ERROR
goto SUCCESS

:ERROR
::make clean
echo ****************************************************************
echo ***********************  BUILD ERROR  **************************
echo ****************************************************************
goto END

:SUCCESS
make clean
echo ****************************************************************
echo ***********************  BUILD SUCCESS  ************************
echo ****************************************************************

:END
