@echo off
set default_ds5_path=C:\Program Files\DS-5

if not exist "%default_ds5_path%" (
	echo=
	echo ****************************************************************
	echo ***********************  ERROR  ********************************
	echo ****************************************************************
	echo=
	echo The Path of DS-5 is not %default_ds5_path%
	echo You need uninstall and install it OR update your build script
	echo=
	goto exit
)

SET PATH=%default_ds5_path%\bin;%PATH%
SET PATH=%default_ds5_path%\sw\ARMCompiler5.05\bin;%PATH%
::设置DOC窗口的尺寸，COLS---列数； LINES--行数
MODE con: COLS=200 LINES=6000

::启动变量延迟
setlocal ENABLEDELAYEDEXPANSION

::NOTE
::logo_script_list.csv中，可以添加客户定制的编译脚本
set logo_lunch_file=logo_script_list.csv
echo LOGO BUILD SCRIPT TO CHOOSE
echo ----+-------------------------------------------------------------+---------------------------------------
echo NUM + SCRIPT                                                      + DESCRIPTION
echo ----+-------------------------------------------------------------+---------------------------------------

for %%i in (%logo_lunch_file%) do (
	for /f "tokens=1-3 delims=," %%a in (%%i) do (
		set "lunch_a= %%a "
		set "lunch_b=+ %%b                                                                                    "
		set "lunch_c=+ %%c"
		echo !lunch_a:~0,3! !lunch_b:~0,61! !lunch_c!
	)
)

echo ----------------------------------------------------------------------------------------------------------


::根据用户输入的数字或者参数，选择对应的脚本
set parammeter=%1
if "%parammeter%"=="" (
	set /p logo_lunch_choose_num="> input your target build script NUM: "
) else (
	echo user input parameter is %parammeter%
	set logo_lunch_choose_num=%parammeter%
)	


for %%j in (%logo_lunch_file%) do (
	for /f "tokens=1-3 delims=," %%a in (%%j) do (
		set "user_input_num=%logo_lunch_choose_num%"
		if "%%a" == "%logo_lunch_choose_num%" (
			set LOGO_LUNCH_TARGET_SCRIPT=%%b
			set LOGO_LUNCH_DESCRIPTION=%%c 
		)
	)
)

::打印用户使用的编译脚本详细信息
echo USER CHOOSE, please review!
::如果用户输入数字错误，提示如下信息
if "%LOGO_LUNCH_TARGET_SCRIPT%"=="" (
	echo ERROR: ** The input number: [%logo_lunch_choose_num%] not exist in %logo_lunch_file%.
	echo Please refer to the following table or %logo_lunch_file%
	goto EOF
)
echo TARGET_SCRIPT     :%LOGO_LUNCH_TARGET_SCRIPT%
echo DESCRIPTION       :%LOGO_LUNCH_DESCRIPTION%


::开始编译
echo GOING TO CALL TARGET SCRIPT
goto REMOVE_DELAY
for /L %%a in (2,-1,0) do (
	set /p a=..<nul
	@ping 127.0.0.1 > nul
)
:REMOVE_DELAY

::清除build目录下的文件的只读属性
attrib ..\build\*.* -r /s

call m_tee %LOGO_LUNCH_TARGET_SCRIPT%

:EOF
















