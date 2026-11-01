set TOP_DIR=%1

set buildver=LTE01R06A16_C_SDK_A


set /P project_name=<%TOP_DIR%\ql-config\config\QuecCurPrj.txt
set soc_platform_path=%TOP_DIR%\ql-config\soc_platform
set /p OEM_PROJECT=<%TOP_DIR%\ql-config\config\QuecOemPrj.txt
set /P RAM_SIZE=<%TOP_DIR%\ql-kernel\threadx\config\ram\RAM_SIZE.ini
set /P FLASHTYPE=<%TOP_DIR%\ql-config\config\QuecFLashType.ini
set /P PACKAGE_PROJECT=<%TOP_DIR%\ql-config\config\QuecPlatformType.ini
set /P ExtFlashType=<%TOP_DIR%\ql-config\config\EXT_FLASH.ini
set /P FLASH_SIZE=<%TOP_DIR%\ql-config\config\FLASH_SIZE.ini
if "%PACKAGE_PROJECT%"=="CRANEM" (
	set QuecProduct=CRANEM_QUEC_PRODUCT
	set boot2_image=%soc_platform_path%/%PACKAGE_PROJECT%/images/2020.07.30/boot2.bin
	set preboot_image=%soc_platform_path%/%PACKAGE_PROJECT%/images/2020.07.30/preboot.bin
	set flasher_image=%soc_platform_path%/%PACKAGE_PROJECT%/images/2020.07.30/flasher.bin
	set rd_image=%TOP_DIR%\ql-config\config\%project_name%\ReliableData.bin
	set rfbin_image=%TOP_DIR%\ql-config\config\%project_name%\rf.bin
	set dsp_image=%soc_platform_path%/%PACKAGE_PROJECT%/images/CAT1GSM/dsp.bin
) else (
	set QuecProduct=CRANEL_QUEC_PRODUCT
	set boot2_image=%TOP_DIR%\ql-config\quec-project\aboot\images\boot2.bin
	set preboot_image=%TOP_DIR%\ql-config\quec-project\aboot\images\preboot.bin
	set flasher_image=%TOP_DIR%\ql-config\quec-project\aboot\images\flasher.bin
	set rd_image=%TOP_DIR%\ql-config\config\%project_name%\%rd_image_type%\ReliableData.bin
	set rfbin_image=%TOP_DIR%\ql-config\config\%project_name%\rf.bin
	set rfbin_1_image=%TOP_DIR%\ql-config\config\%project_name%\rf_1.bin
	set rfbin_2_image=%TOP_DIR%\ql-config\config\%project_name%\rf_2.bin
	set customer_backup_fs_image=%TOP_DIR%\ql-config\config\%project_name%\customer_backup_fs.bin
	set gnss_boot_image=%TOP_DIR%\ql-config\config\%project_name%\gnss_boot.pkg
	set gnss_firm_image=%TOP_DIR%\ql-config\config\%project_name%\gnss_firm.pkg
	set jacana_fw_image=%TOP_DIR%\ql-config\quec-project\aboot\images\jacana_fw.bin
	set btbin_image=%TOP_DIR%\ql-config\quec-project\aboot\images\btbin.bin
	set btlst_image=%TOP_DIR%\ql-config\quec-project\aboot\images\btlst.bin
	set dsp_image=%soc_platform_path%/%PACKAGE_PROJECT%/images/DSP_Normal/dsp.bin
)

set customer_fs_image=%TOP_DIR%\ql-config\config\%project_name%\customer_fs.bin
set logo_image=%TOP_DIR%\ql-config\quec-project\aboot\images\logo.bin
set cp_image=%TOP_DIR%\ql-config\quec-project\aboot\images\kernel.bin
set boot_image=%TOP_DIR%\ql-config\quec-project\aboot\images\boot33.bin
set customer_app_image=%TOP_DIR%\ql-config\quec-project\aboot\images\app.bin

if exist %TOP_DIR%\ql-bootloader\boot33\release (
	set boot_image=%TOP_DIR%\ql-bootloader\boot33\release\boot33.bin
)

if exist %TOP_DIR%\ql-application\threadx\build (
	set customer_app_image=%TOP_DIR%\ql-application\threadx\build\app.bin
	rem %TOP_DIR%\ql-cross-tool\win32\host\tools\lzma.exe ds 18 e %TOP_DIR%\ql-application\threadx\build\app.bin %TOP_DIR%\ql-application\threadx\build\app_lzma.bin
	rem set customer_app_image=%TOP_DIR%\ql-application\threadx\build\app_lzma.bin
)

if exist %TOP_DIR%\ql-kernel\threadx\build (
	set cp_image=%TOP_DIR%\ql-kernel\threadx\build\release_kernel.bin
)
if "%ExtFlashType%"=="2M" (
	SET OPEN_PACKAGE=+02M_OPEN 
) else if "%ExtFlashType%"=="16M" (
	SET OPEN_PACKAGE=+16M_OPEN
) else if "%ExtFlashType%"=="8M" (
	SET OPEN_PACKAGE=+08M_OPEN
) else (
	SET OPEN_PACKAGE=_OPEN
)
set aboot_dir=%TOP_DIR%\ql-cross-tool\win32\host\tools\aboot-tools-win-x86
set ImageInfoGet=%TOP_DIR%\ql-cross-tool\win32\host\tools\ImageInfoGet
set AddCheck=%TOP_DIR%\ql-cross-tool\win32\host\tools\AddCheck
set cmd_7z=%TOP_DIR%\ql-cross-tool\win32\host\tools\7z\7z

if not exist %TOP_DIR%\target mkdir %TOP_DIR%\target
rd /q/s %TOP_DIR%\target

if "%FLASHTYPE%"=="HX_GPS"  (
	set QuecProductName=QUEC_CRANEL_DS_08MB_HX_GNSS%OPEN_PACKAGE%
	set standard_arelease_iamges="cp=%cp_image%,dsp=%dsp_image%,boot33=%boot_image%,rfbin=%rfbin_image%,rd=%rd_image%,customer_app=%customer_app_image%,logo=%logo_image%,preboot_bin=%preboot_image%,boot2_bin=%boot2_image%,customer_fs=%customer_fs_image%,customer_backup_fs=%customer_backup_fs_image%,flasher_bin=%flasher_image%,gnss_boot=%gnss_boot_image%,gnss_firm=%gnss_firm_image%"
) else if "%FLASHTYPE%"=="ASR_GPS" (
	set QuecProductName=QUEC_CRANEL_DS_08MB_ASR_GNSS%OPEN_PACKAGE%
	set standard_arelease_iamges="cp=%cp_image%,dsp=%dsp_image%,boot33=%boot_image%,rfbin=%rfbin_image%,rd=%rd_image%,customer_app=%customer_app_image%,logo=%logo_image%,preboot_bin=%preboot_image%,boot2_bin=%boot2_image%,customer_fs=%customer_fs_image%,customer_backup_fs=%customer_backup_fs_image%,flasher_bin=%flasher_image%,jacana_fw=%jacana_fw_image%"
) else if "%FLASHTYPE%"=="HX_GPS_BT" (
	set QuecProductName=QUEC_CRANEL_DS_08MB_HX_GNSS_BT%OPEN_PACKAGE%
	set standard_arelease_iamges="cp=%cp_image%,dsp=%dsp_image%,boot33=%boot_image%,rfbin=%rfbin_image%,rd=%rd_image%,customer_app=%customer_app_image%,logo=%logo_image%,preboot_bin=%preboot_image%,boot2_bin=%boot2_image%,customer_fs=%customer_fs_image%,customer_backup_fs=%customer_backup_fs_image%,flasher_bin=%flasher_image%,gnss_boot=%gnss_boot_image%,gnss_firm=%gnss_firm_image%,btbin=%btbin_image%,btlst=%btlst_image%"
) else if "%FLASHTYPE%"=="DEFAULT_BT" (
	set QuecProductName=QUEC_CRANEL_DS_08MB_BT%OPEN_PACKAGE%
	set standard_arelease_iamges="cp=%cp_image%,dsp=%dsp_image%,boot33=%boot_image%,rfbin=%rfbin_image%,rd=%rd_image%,customer_app=%customer_app_image%,logo=%logo_image%,preboot_bin=%preboot_image%,boot2_bin=%boot2_image%,customer_fs=%customer_fs_image%,customer_backup_fs=%customer_backup_fs_image%,flasher_bin=%flasher_image%,btbin=%btbin_image%,btlst=%btlst_image%"
) else if "%FLASHTYPE%"=="ASR_GPS_BT" (
	set QuecProductName=QUEC_CRANEL_DS_08MB_ASR_GNSS_BT%OPEN_PACKAGE%
	set standard_arelease_iamges="cp=%cp_image%,dsp=%dsp_image%,boot33=%boot_image%,rfbin=%rfbin_image%,rd=%rd_image%,customer_app=%customer_app_image%,logo=%logo_image%,preboot_bin=%preboot_image%,boot2_bin=%boot2_image%,customer_fs=%customer_fs_image%,customer_backup_fs=%customer_backup_fs_image%,flasher_bin=%flasher_image%,jacana_fw=%jacana_fw_image%,btbin=%btbin_image%,btlst=%btlst_image%"
) else (
	if "%PACKAGE_PROJECT%"=="CRANEM" (
		set QuecProductName=QUEC_CRANEM_SS_08MB%OPEN_PACKAGE%
		set standard_arelease_iamges="cp=%cp_image%,dsp=%dsp_image%,boot33=%boot_image%,rfbin=%rfbin_image%,rd=%rd_image%,customer_app=%customer_app_image%,logo=%logo_image%,preboot_bin=%preboot_image%,boot2_bin=%boot2_image%,customer_fs=%customer_fs_image%,flasher_bin=%flasher_image%"
	) else (
		set QuecProductName=QUEC_CRANEL_DS_08MB%OPEN_PACKAGE%
		set standard_arelease_iamges="cp=%cp_image%,dsp=%dsp_image%,boot33=%boot_image%,rfbin=%rfbin_image%,rd=%rd_image%,customer_app=%customer_app_image%,logo=%logo_image%,preboot_bin=%preboot_image%,boot2_bin=%boot2_image%,customer_fs=%customer_fs_image%,customer_backup_fs=%customer_backup_fs_image%,flasher_bin=%flasher_image%"
	)
	
)
echo %QuecProductName% >%TOP_DIR%\ql-config\quec-project\aboot\config\product\QuecProductName.txt
set standard_package_path=%TOP_DIR%\target\%buildver%
set standard_package_file=%buildver%.zip
mkdir %standard_package_path%
%aboot_dir%\arelease -c %TOP_DIR%\ql-config\quec-project\aboot  -g -p %QuecProduct% -v %QuecProductName% -i %standard_arelease_iamges%  %standard_package_path%\%standard_package_file%
if not exist %standard_package_path%\%buildver%.zip (
	echo ¨€¨€¨€¨€¨€¨€¨€¨[¨€¨€¨€¨€¨€¨€¨[ ¨€¨€¨€¨€¨€¨€¨[  ¨€¨€¨€¨€¨€¨€¨[ ¨€¨€¨€¨€¨€¨€¨[ ¨€¨€¨[¨€¨€¨[¨€¨€¨[
	echo ¨€¨€¨X¨T¨T¨T¨T¨a¨€¨€¨X¨T¨T¨€¨€¨[¨€¨€¨X¨T¨T¨€¨€¨[¨€¨€¨X¨T¨T¨T¨€¨€¨[¨€¨€¨X¨T¨T¨€¨€¨[¨€¨€¨U¨€¨€¨U¨€¨€¨U
	echo ¨€¨€¨€¨€¨€¨[  ¨€¨€¨€¨€¨€¨€¨X¨a¨€¨€¨€¨€¨€¨€¨X¨a¨€¨€¨U   ¨€¨€¨U¨€¨€¨€¨€¨€¨€¨X¨a¨€¨€¨U¨€¨€¨U¨€¨€¨U
	echo ¨€¨€¨X¨T¨T¨a  ¨€¨€¨X¨T¨T¨€¨€¨[¨€¨€¨X¨T¨T¨€¨€¨[¨€¨€¨U   ¨€¨€¨U¨€¨€¨X¨T¨T¨€¨€¨[¨^¨T¨a¨^¨T¨a¨^¨T¨a
	echo ¨€¨€¨€¨€¨€¨€¨€¨[¨€¨€¨U  ¨€¨€¨U¨€¨€¨U  ¨€¨€¨U¨^¨€¨€¨€¨€¨€¨€¨X¨a¨€¨€¨U  ¨€¨€¨U¨€¨€¨[¨€¨€¨[¨€¨€¨[
	echo ¨^¨T¨T¨T¨T¨T¨T¨a¨^¨T¨a  ¨^¨T¨a¨^¨T¨a  ¨^¨T¨a ¨^¨T¨T¨T¨T¨T¨a ¨^¨T¨a  ¨^¨T¨a¨^¨T¨a¨^¨T¨a¨^¨T¨a                                       
	goto end
)

copy /y %TOP_DIR%\ql-config\quec-project\download\quec_download.json %standard_package_path%\%buildver%.json
%ImageInfoGet% 1 0 1 %cp_image% %standard_package_path%\imageinfo.bin
%ImageInfoGet% 2 0 1 %dsp_image% %standard_package_path%\imageinfo.bin
%ImageInfoGet% 3 0 1 %rfbin_image% %standard_package_path%\imageinfo.bin
%AddCheck% %standard_package_path%\imageinfo.bin


mkdir %standard_package_path%\DBG
if exist %TOP_DIR%\ql-kernel\threadx\build (
	copy /Y %TOP_DIR%\ql-kernel\threadx\build\kernel.axf %standard_package_path%\DBG
	copy /Y %TOP_DIR%\ql-kernel\threadx\build\kernel.map %standard_package_path%\DBG
	copy /Y %TOP_DIR%\ql-kernel\threadx\build\KERNEL_MDB.txt %standard_package_path%\DBG
) else (
	copy /Y %TOP_DIR%\ql-config\quec-project\aboot\images\kernel.axf %standard_package_path%\DBG
	copy /Y %TOP_DIR%\ql-config\quec-project\aboot\images\kernel.map %standard_package_path%\DBG
	copy /Y %TOP_DIR%\ql-config\quec-project\aboot\images\KERNEL_MDB.txt %standard_package_path%\DBG
)
::rename %standard_package_path%\DBG\kernel.axf CRANE_DS_XIP_DM_GENERIC.axf
::rename %standard_package_path%\DBG\kernel.map CRANE_DS_XIP_DM_GENERIC.map

if exist %TOP_DIR%\ql-application\threadx\build (
	copy /Y %TOP_DIR%\ql-application\threadx\build\app.elf %standard_package_path%\DBG
	copy /Y %TOP_DIR%\ql-application\threadx\build\app.map %standard_package_path%\DBG
) else (
	copy /Y %TOP_DIR%\ql-config\quec-project\aboot\images\app.elf %standard_package_path%\DBG
	copy /Y %TOP_DIR%\ql-config\quec-project\aboot\images\app.map %standard_package_path%\DBG
)

::ï¿½ï¿½Â¼Ã¿ï¿½ï¿½Ê¹ï¿½Ãµï¿½feedbackï¿½ï¿½DBGï¿½ï¿½
if exist %TOP_DIR%\ql-kernel\threadx\config\common\feedbackLink_backup.txt (
	copy /Y %TOP_DIR%\ql-kernel\threadx\config\common\feedbackLink_backup.txt %standard_package_path%\DBG
	del %TOP_DIR%\ql-kernel\threadx\config\common\feedbackLink_backup.txt
)

::rename %standard_package_path%\DBG\app.elf CRANE_DS_XIP_DM_GENERIC_APP.axf
::rename %standard_package_path%\DBG\app.map CRANE_DS_XIP_DM_GENERIC_APP.map

%cmd_7z% a -tzip  %TOP_DIR%\target\%standard_package_file% -r %standard_package_path%\*.*

echo ¨€¨€¨€¨€¨€¨€¨€¨[¨€¨€¨[   ¨€¨€¨[ ¨€¨€¨€¨€¨€¨€¨[ ¨€¨€¨€¨€¨€¨€¨[¨€¨€¨€¨€¨€¨€¨€¨[¨€¨€¨€¨€¨€¨€¨€¨[¨€¨€¨€¨€¨€¨€¨€¨[
echo ¨€¨€¨X¨T¨T¨T¨T¨a¨€¨€¨U   ¨€¨€¨U¨€¨€¨X¨T¨T¨T¨T¨a¨€¨€¨X¨T¨T¨T¨T¨a¨€¨€¨X¨T¨T¨T¨T¨a¨€¨€¨X¨T¨T¨T¨T¨a¨€¨€¨X¨T¨T¨T¨T¨a
echo ¨€¨€¨€¨€¨€¨€¨€¨[¨€¨€¨U   ¨€¨€¨U¨€¨€¨U     ¨€¨€¨U     ¨€¨€¨€¨€¨€¨[  ¨€¨€¨€¨€¨€¨€¨€¨[¨€¨€¨€¨€¨€¨€¨€¨[
echo ¨^¨T¨T¨T¨T¨€¨€¨U¨€¨€¨U   ¨€¨€¨U¨€¨€¨U     ¨€¨€¨U     ¨€¨€¨X¨T¨T¨a  ¨^¨T¨T¨T¨T¨€¨€¨U¨^¨T¨T¨T¨T¨€¨€¨U
echo ¨€¨€¨€¨€¨€¨€¨€¨U¨^¨€¨€¨€¨€¨€¨€¨X¨a¨^¨€¨€¨€¨€¨€¨€¨[¨^¨€¨€¨€¨€¨€¨€¨[¨€¨€¨€¨€¨€¨€¨€¨[¨€¨€¨€¨€¨€¨€¨€¨U¨€¨€¨€¨€¨€¨€¨€¨U
echo ¨^¨T¨T¨T¨T¨T¨T¨a ¨^¨T¨T¨T¨T¨T¨a  ¨^¨T¨T¨T¨T¨T¨a ¨^¨T¨T¨T¨T¨T¨a¨^¨T¨T¨T¨T¨T¨T¨a¨^¨T¨T¨T¨T¨T¨T¨a¨^¨T¨T¨T¨T¨T¨T¨a
                                                         
:end
