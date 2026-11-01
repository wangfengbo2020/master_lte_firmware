@echo off
set CURDIR=%~dp0

echo                              __           ___                                         
echo                             /\ \__       /\_ \                                        
echo    __   __  __     __    ___\ \ ,_\    __\//\ \         ___   _____      __    ___    
echo  /'__`\/\ \/\ \  /'__`\ /'___\ \ \/  /'__`\\ \ \       / __`\/\ '__`\  /'__`\/' _ `\  
echo /\ \L\ \ \ \_\ \/\  __//\ \__/\ \ \_/\  __/ \_\ \_    /\ \L\ \ \ \L\ \/\  __//\ \/\ \ 
echo \ \___, \ \____/\ \____\ \____\\ \__\ \____\/\____\   \ \____/\ \ ,__/\ \____\ \_\ \_\
echo  \/___/\ \/___/  \/____/\/____/ \/__/\/____/\/____/    \/___/  \ \ \/  \/____/\/_/\/_/
echo       \ \_\                                                     \ \_\                 
echo        \/_/                                                      \/_/                 

@echo off
echo **********************************************************************************************
echo                                    Choose language
echo 1 English
echo 2 Chinese
echo **********************************************************************************************
set /p lang_opt=Enter choice (1 or 2): 

if "%lang_opt%"=="1" (
    set lang=EN
) else (
    if "%lang_opt%"=="2" (
        set lang=CN
    ) else (
        echo Invalid choice, defaulting to Chinese.
        set lang=CN
    )
)


if "%lang%"=="EN" (
echo **********************************************************************************************                                                             
echo                                    OpenEntry User Guide!!!   
echo Since the SDK is compatible with many modules of Quectel ASR platform, in order to facilitate customer development, customers can choose the supported modules according to the product form,
echo This configuration only needs to be configured once. If you want to change the supported module, you need to reconfigure it.
echo 1 Customers can choose the corresponding module OC, SDK support can be consulted by Quectel AE/FAE
echo 2 Customers can choose to cut the corresponding function
echo 3 Customers can choose whether to plug in flash
echo 4 Customers can modify the name of the generated firmware package
echo ********************************************************************************************** 
) else (
echo **********************************************************************************************                                                             
echo                                    OpenEntry 使用指引!!!   
echo 由于SDK兼容移远 ASR平台诸多模组，为了方便客户开发，客户可以根据产品形态自行选择支持的模块,
echo 功能等一些参数配置。此配置仅需要配置一次即可,如要更换支持的模块,需要重新配置。
echo 1 客户可以选择对应模块OC,SDK 支持情况可咨询移远AE/FAE
echo 2 客户可以选择裁剪对应的功能
echo 3 客户可以选择是否外挂flash
echo 4 客户可以修改生成固件包的名字
echo **********************************************************************************************   
)

 
if "%lang%"=="EN" (
set /p start=Press Enter to start!!!!
) else (
set /p start=敲回车开始!!!!
)

:start

set ex_fshsize=NO_EXTFLASH
set APP_MODE=XIP
echo       
echo ****************************************************** 
if "%lang%"=="EN" (
echo Select the module you are currently using
) else (
echo 选择你当前使用的模块  
)                                                                                                                                                                                                   
echo 1.EC200MCN_LA
echo 2.EC600MCN_LA/LE
echo 3.EC600MEU_LA
echo 4.EC600MCN_LC
echo 5.EC800MCN_LC
echo 6.EC800MCN_LA/LE
echo 7.EG810MCN_LA
echo 8.EC800MCN_GA
echo 9.EG810MCN_GA
echo 10.EC800MCN_GD
echo 11.EC800MCN_GC
echo 12.EC800MCN_GM
echo 13.EC200MCN_LC
echo 14.EC600MCN_LF
echo 15.EC800MCN_LF
echo 16.EC600MCN_CC
echo 17.EC200MCN_GB
echo 18.EC800MCN_GB
echo 19.EC800MCN_GA_BT
echo 20.EC600MLA_LA
echo 21.EG810MCN_GB
echo 22.EG810MEU_LA
echo 23.EC200MCN_LE
echo 24.EC100MCN_LA
echo ******************************************************
echo     
if "%lang%"=="EN" (
set /p QUEC_PROJECT=Please enter the project number to compile...
) else (
set /p QUEC_PROJECT=请输入要编译的项目序号... 
)
if %QUEC_PROJECT%==1 (
set quec_prj=EC200MCN_LA
) else if %QUEC_PROJECT%==2 (
set quec_prj=EC600MCN_LE
) else if %QUEC_PROJECT%==3 (
set quec_prj=EC600MEU_LA
) else if %QUEC_PROJECT%==4 (
set quec_prj=EC600MCN_LC
) else if %QUEC_PROJECT%==5 (
set quec_prj=EC800MCN_LC
) else if %QUEC_PROJECT%==6 (
set quec_prj=EC800MCN_LE
) else if %QUEC_PROJECT%==7 (
set quec_prj=EG810MCN_LA
) else if %QUEC_PROJECT%==8 (
set quec_prj=EC800MCN_GA
) else if %QUEC_PROJECT%==9 (
set quec_prj=EG810MCN_GA
) else if %QUEC_PROJECT%==10 (
set quec_prj=EC800MCN_GD
) else if %QUEC_PROJECT%==11 (
set quec_prj=EC800MCN_GC
) else if %QUEC_PROJECT%==12 (
set quec_prj=EC800MCN_GM
) else if %QUEC_PROJECT%==13 (
set quec_prj=EC200MCN_LC
) else if %QUEC_PROJECT%==14 (
set quec_prj=EC600MCN_LF
) else if %QUEC_PROJECT%==15 (
set quec_prj=EC800MCN_LF
) else if %QUEC_PROJECT%==16 (
set quec_prj=EC600MCN_CC
) else if %QUEC_PROJECT%==17 (
set quec_prj=EC200MCN_GB
) else if %QUEC_PROJECT%==18 (
set quec_prj=EC800MCN_GB
) else if %QUEC_PROJECT%==19 (
set quec_prj=EC800MCN_GA_BT
) else if %QUEC_PROJECT%==20 (
set quec_prj=EC600MLA_LA
) else if %QUEC_PROJECT%==21 (
set quec_prj=EG810MCN_GB
) else if %QUEC_PROJECT%==22 (
set quec_prj=EG810MEU_LA
) else if %QUEC_PROJECT%==23 (
set quec_prj=EC200MCN_LE
) else if %QUEC_PROJECT%==24 (
set quec_prj=EC100MCN_LA
) else (
	goto ERR
)
if "%lang%"=="EN" (
echo The project you selected is %quec_prj%
) else (
echo 您选择的项目为%quec_prj%  
) 
                                                                                                                                                                                       
@rem TO SWE 当需要增加新功能时,则同步修改ql-kernel\threadx\config\common\makefile文件,实现宏的定义
echo             
echo ***********************************************************************   
if "%lang%"=="EN" (
echo Start cutting and selecting functions. For example, if you need to use LCD and TTS, enter 13. If you want to select all, enter 123456789A...
) else (
echo 开始裁剪选择功能，例如需要使用LCD和TTS，那么则输入13，全选则输入123456789A...   
)                                                                                                                                                                                                
echo 1.LCD
echo 2.AMR
echo 3.MP3
echo 4.TTS
echo 5.MBEDTLS
echo 6.WAV
echo 7.CAMERA
echo 8.NTP
echo 9.PING
if "%lang%"=="EN" (
echo A. MDSSS-SPS - (Single card protocol stack supports dual card single standby function ^)
echo B. USBNET -- (only applicable to versions that support USBNET ^)
echo C.NAND_YAFFS - (Enable support for NAND YAFFS file system function ^)
echo D.AUDIO_DENOISE - (Enable support for audio noise reduction function ^)
echo E.AUDIO_KWS - (Enable support for audio speech recognition function ^)
echo Note: The more functions you add, the more flash and ram space you need to reserve for the kernel firmware.
) else (
echo A.MDSSS_SPS--(单卡协议栈支持双卡单待功能^)
echo B.USBNET--(仅适用于支持USBNET的版本^)
echo C.NAND_YAFFS--(开启支持NAND YAFFS 文件系统功能^)
echo D.AUDIO_DENOISE--(开启支持音频降噪功能^)
echo E.AUDIO_KWS--(开启支持音频语音识别功能^)
echo 注意事项:增加功能越多需要预留给内核固件的flash和ram空间越大    
)   
echo ***********************************************************************  

set MLCD=
set MAMR=
set MMP3=
set MTTS=
set MMBEDTLS=
set MWAV=
set MCAMERA=
set MNTP=
set MPING=
set MDSSS_SPS=
set MUSBNET=
set NAND_YAFFS=
set AUDIO_DENOISE=
set AUDIO_KWS=
if "%lang%"=="EN" (
set /p QUEC_MODULE=Please enter the serial number of the function block to be added (you can enter multiple at the same time^), no function is required, enter 0...
) else (
set /p QUEC_MODULE=请输入要增加功能块的序号(可同时填多个^),不需要任何功能输入0...
)   

echo %QUEC_MODULE%|findstr "1" >nul 
if %errorlevel%==0 (
	set MLCD=LCD_
	if "%lang%"=="EN" (
  	echo LCD Function is turned on
	) else (
	echo LCD 功能已打开
	)   
)
echo %QUEC_MODULE%|findstr "2" >nul 
if %errorlevel%==0 (
	set MAMR=AMR_
		if "%lang%"=="EN" (
  	echo AMR Function is turned on
	) else (
	echo AMR 功能已打开
	) 
)
echo %QUEC_MODULE%|findstr "3" >nul 
if %errorlevel%==0 (
	set MMP3=MP3_
		if "%lang%"=="EN" (
  	echo MP3 Function is turned on
	) else (
	echo MP3 功能已打开
	) 
)
echo %QUEC_MODULE%|findstr "4" >nul 
if %errorlevel%==0 (
	set MTTS=TTS_
		if "%lang%"=="EN" (
  	echo TTS Function is turned on
	) else (
	echo TTS 功能已打开
	) 
)
echo %QUEC_MODULE%|findstr "5" >nul 
if %errorlevel%==0 (
	set MMBEDTLS=MBEDTLS_
		if "%lang%"=="EN" (
  	echo MBEDTLS Function is turned on
	) else (
	echo MBEDTLS 功能已打开
	) 
)
echo %QUEC_MODULE%|findstr "6" >nul 
if %errorlevel%==0 (
	set MWAV=WAV_
		if "%lang%"=="EN" (
  	echo WAV Function is turned on
	) else (
	echo WAV 功能已打开
	) 
)
echo %QUEC_MODULE%|findstr "7" >nul 
if %errorlevel%==0 (
	set MCAMERA=CAMERA_
		if "%lang%"=="EN" (
  	echo CAMERA Function is turned on
	) else (
	echo CAMERA 功能已打开
	) 
)
echo %QUEC_MODULE%|findstr "8" >nul 
if %errorlevel%==0 (
	set MNTP=NTP_
		if "%lang%"=="EN" (
  	echo NTP Function is turned on
	) else (
	echo NTP 功能已打开
	) 
)
echo %QUEC_MODULE%|findstr "9" >nul 
if %errorlevel%==0 (
	set MPING=PING_
		if "%lang%"=="EN" (
  	echo PING Function is turned on
	) else (
	echo PING 功能已打开
	) 
)
echo %QUEC_MODULE%|findstr "A" >nul 
if %errorlevel%==0 (
	set MDSSS_SPS=DSSS_SPS
		if "%lang%"=="EN" (
  		echo DSSS_SPS Single card protocol stack supports dual SIM single standby function is turned on
	) else (
	echo DSSS_SPS 单卡协议栈支持双卡单待功能已打开
	) 
)
echo %QUEC_MODULE%|findstr "B" >nul 
if %errorlevel%==0 (
	set MUSBNET=USBNET_
			if "%lang%"=="EN" (
  	echo USBNET Function is turned on
	) else (
	echo USBNET 功能已打开
	) 
)
echo %QUEC_MODULE%|findstr "C" >nul 
if %errorlevel%==0 (
	set NAND_YAFFS=QL_NAND_YAFFS
			if "%lang%"=="EN" (
  	echo NAND_YAFFS Function is turned on
	) else (
	echo NAND_YAFFS 功能已打开
	) 
)
echo %QUEC_MODULE%|findstr "D" >nul 
if %errorlevel%==0 (
	set AUDIO_DENOISE=QL_AUDIO_DENOISE
			if "%lang%"=="EN" (
  	echo AUDIO_DENOISE Function is turned on
	) else (
	echo AUDIO_DENOISE 功能已打开
	) 
)
echo %QUEC_MODULE%|findstr "E" >nul 
if %errorlevel%==0 (
	set AUDIO_KWS=QL_AUDIO_KWS
	if "%lang%"=="EN" (
	echo AUDIO_KWS Function is turned on
	) else (
	echo AUDIO_KWS 功能已打开
	) 
)
echo %QUEC_MODULE%|findstr "0" >nul 
if %errorlevel%==0 (
	set module=
	if "%lang%"=="EN" (
	echo All the above functions are cut
	) else (
	echo 上述功能全裁剪
	) 
)

set module=%MLCD%%MAMR%%MMP3%%MTTS%%MMBEDTLS%%MWAV%%MCAMERA%%MNTP%%MPING%%MDSSS_SPS%%MUSBNET%%NAND_YAFFS%%AUDIO_DENOISE%%AUDIO_KWS%
echo _%module% >%CURDIR%\ql-config\config\func.txt  

  
if "%quec_prj%"=="EC600MCN_CC" (
	goto ext
) else if "%quec_prj%"=="EC600MCN_LF" (
	goto ext
) else if "%quec_prj%"=="EC800MCN_CC" (
    goto ext
) else if "%quec_prj%"=="EC600MCN_LC" (
    goto ext
) else (
	set APP_MODE=XIP
  goto packname
)

:ext
echo      
echo ******************************************************
if "%lang%"=="EN" (
echo Whether to install external flash, if not, please press 0
) else (
echo 是否外挂flash，如果没有请按0
) 
echo 0.NO_EXT_FLASH
echo 1.1M_EXT_FLASH
echo 2.2M_EXT_FLASH
echo 3.4M_EXT_FLASH
echo 4.8M_EXT_FLASH
echo 5.16M_EXT_FLASH
echo ****************************************************** 
echo  
 if "%lang%"=="EN" (
	set /p ext_flash=Please enter the serial number corresponding to the external flash size...
) else ( 
	set /p ext_flash=请输入对应外挂flash大小的序号...
) 
	if %ext_flash%==0 (
		set APP_MODE=XIP
		set ex_fshsize=NO_EXTFLASH
		goto packname
	) else if %ext_flash%==1 (
		set ex_fshsize=EXT_FLASH_M01
	) else if %ext_flash%==2 (
		set ex_fshsize=EXT_FLASH_M02
	) else if %ext_flash%==3 (
		set ex_fshsize=EXT_FLASH_M04
	) else if %ext_flash%==4 (
		set ex_fshsize=EXT_FLASH_M08
	) else if %ext_flash%==5 (
	   set ex_fshsize=EXT_FLASH_M16
	) else (
		goto ERR
	)

if "%quec_prj%"=="EC600MCN_CC" (
	set APP_MODE=RAM
	goto packname
) else if "%quec_prj%"=="EC600MCN_LF" (
	goto appmode
) else if "%quec_prj%"=="EC800MCN_CC" (
	set APP_MODE=RAM
    goto packname
) else if "%quec_prj%"=="EC600MCN_LC" (
    goto appmode
) else (
  goto ERR
)
:appmode
echo     
 if "%lang%"=="EN" (
echo ****************************************************** 
echo Please check whether the customer_app.bin partition is on the external flash~~~
echo 0.APP_MODE_FUN=0 Default settings, no partition modification
echo 1.APP_MODE_FUN=1 Modify the partition and put customer_app.bin into the external flash
echo ****************************************************** 
) else ( 
echo ****************************************************** 
echo 请检查customer_app.bin 分区是否在外置flash上~~~
echo 0.app存在于内置flash
echo 1.app存在于外挂flash
echo ****************************************************** 
)  
  
echo  
 if "%lang%"=="EN" (
	set /p APP_MODE_FUN=Please Enter...
) else ( 
	set /p APP_MODE_FUN=请输入...
)      

	if %APP_MODE_FUN%==0 (
		set APP_MODE=XIP
	) else if %APP_MODE_FUN%==1 (
		set APP_MODE=RAM
	) else (
		goto ERR
	)	
:packname	
 if "%lang%"=="EN" (
set /p CUST_VER=Please enter the generated firmware package name. Enter 0 to use the default firmware name of Quectel...  
) else ( 
	set /p CUST_VER=请输入生成的固件包名称，输入0则使用移远默认固件名称  
)  

if "%lang%"=="EN" (
echo firmware package name%CUST_VER%  
) else ( 
	echo 固件名称为%CUST_VER%  
)  
set cust_ver=%CUST_VER%

if "%lang%"=="EN" (
set /p OEM_VER=Please enter the OEM name, if none please enter 0...
echo The firmware name is %OEM_VER%  
) else ( 
	set /p OEM_VER=请输入OEM名称，若无请输入0  
echo  OEM名称为%OEM_VER%  
) 

set oem_ver=%OEM_VER%


:build
call build.bat project_name -p %quec_prj% -b %ex_fshsize% -x %APP_MODE% -c %cust_ver% -o %oem_ver%
call build_all.bat
goto exit




:ERR
echo  _______   ________  ________  ________  ________     
echo |\  ___ \ |\   __  \|\   __  \|\   __  \|\   __  \    
echo \ \   __/|\ \  \|\  \ \  \|\  \ \  \|\  \ \  \|\  \   
echo  \ \  \_|/_\ \   _  _\ \   _  _\ \  \\\  \ \   _  _\  
echo   \ \  \_|\ \ \  \\  \\ \  \\  \\ \  \\\  \ \  \\  \| 
echo    \ \_______\ \__\\ _\\ \__\\ _\\ \_______\ \__\\ _\ 
echo     \|_______|\|__|\|__|\|__|\|__|\|_______|\|__|\|__|

:exit


                                                                            
                                                                                               
