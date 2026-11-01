#!/bin/bash
CUR_DIR=$(pwd)
TOP_DIR=$CUR_DIR/../..
ARELEASE_BIN=$CUR_DIR/arelease
APP_DIR=${TOP_DIR%%/ql-cross-tool/Linux/x86_64/../..}/ql-application/threadx
IMAGE_DIR=${TOP_DIR%%/ql-cross-tool/Linux/x86_64/../..}/ql-config/quec-project/aboot
ROOT_DIR=${TOP_DIR%%/ql-cross-tool/Linux/x86_64/../..}

chmod +x $ARELEASE_BIN

VERSION="FIRMWARE_PACKAGE"
if [ -e $APP_DIR/config/profile/version ]; then
    VERSION=$(grep "VERSION:" $APP_DIR/config/profile/version | sed 's/VERSION://g' | xargs echo -n)
    BUILD_TIME=$(grep "BUILD_TIME:" $APP_DIR/config/profile/version | sed 's/BUILD_TIME://g' | xargs echo -n)
fi

project_name=$(cat $ROOT_DIR/ql-config/config/QuecCurPrj.txt)
FLASHTYPE=$(cat $ROOT_DIR/ql-config/config/QuecFLashType.ini)

board_Variant=QUEC_CRANEL_DS_08MB_OPEN
PACKAGE_PROJECT=CRANEL

soc_platform_path=$ROOT_DIR/ql-config/soc_platform
dsp_image=$soc_platform_path/$PACKAGE_PROJECT/images/DSP_Normal/dsp.bin
boot2_image=$ROOT_DIR/ql-config/quec-project/aboot/images/boot2.bin
preboot_image=$ROOT_DIR/ql-config/quec-project/aboot/images/preboot.bin
flasher_image=$ROOT_DIR/ql-config/quec-project/aboot/images/flasher.bin
rd_image=$ROOT_DIR/ql-config/config/$project_name/$rd_image_type/ReliableData.bin
rfbin_image=$ROOT_DIR/ql-config/config/$project_name/rf.bin
rfbin_1_image=$ROOT_DIR/ql-config/config/$project_name/rf_1.bin
rfbin_2_image=$ROOT_DIR/ql-config/config/$project_name/rf_2.bin
customer_fs_image=$ROOT_DIR/ql-config/config/$project_name/customer_fs.bin
customer_backup_fs_image=$ROOT_DIR/ql-config/config/$project_name/customer_backup_fs.bin
logo_image=$ROOT_DIR/ql-config/quec-project/aboot/images/logo.bin
cp_image=$ROOT_DIR/ql-config/quec-project/aboot/images/kernel.bin
boot_image=$ROOT_DIR/ql-config/quec-project/aboot/images/boot33.bin
customer_app_image=$ROOT_DIR/ql-config/quec-project/aboot/images/app.bin
gnss_boot_image=$ROOT_DIR/ql-config/config/$project_name/gnss_boot.pkg
gnss_firm_image=$ROOT_DIR/ql-config/config/$project_name/gnss_firm.pkg
jacana_fw_image=$ROOT_DIR/ql-config/quec-project/aboot/images/jacana_fw.bin
btbin_image=$ROOT_DIR/ql-config/quec-project/aboot/images/btbin.bin
btlst_image=$ROOT_DIR/ql-config/quec-project/aboot/images/btlst.bin


if [ -e $ROOT_DIR/ql-bootloader/boot33/release ]; then
    boot_image=$ROOT_DIR/ql-bootloader/boot33/release/boot33.bin
fi

if [ -e $ROOT_DIR/ql-application/threadx/build ]; then
    customer_app_image=$ROOT_DIR/ql-application/threadx/build/app.bin
fi

if [[ $FLASHTYPE = "HX_GPS" ]]; then
	board_Variant=QUEC_CRANEL_DS_08MB_HX_GNSS_OPEN
	standard_arelease_iamges=cp=$cp_image,dsp=$dsp_image,boot33=$boot_image,rfbin=$rfbin_image,rd=$rd_image,customer_app=$customer_app_image,logo=$logo_image,preboot_bin=$preboot_image,boot2_bin=$boot2_image,customer_fs=$customer_fs_image,customer_backup_fs=$customer_backup_fs_image,flasher_bin=$flasher_image,gnss_boot=$gnss_boot_image,gnss_firm=$gnss_firm_image
elif [[ $FLASHTYPE = "ASR_GPS" ]]; then
	board_Variant=CRANEL_QUEC_PRODUCT_8M_ASR_GPS_OPEN
	standard_arelease_iamges=cp=$cp_image,dsp=$dsp_image,boot33=$boot_image,rfbin=$rfbin_image,rd=$rd_image,customer_app=$customer_app_image,logo=$logo_image,preboot_bin=$preboot_image,boot2_bin=$boot2_image,customer_fs=$customer_fs_image,customer_backup_fs=$customer_backup_fs_image,flasher_bin=$flasher_image,jacana_fw=$jacana_fw_image
elif [[ $FLASHTYPE = "HX_GPS_BT" ]]; then
	board_Variant=QUEC_CRANEL_DS_08MB_HX_GNSS_BT_OPEN
	standard_arelease_iamges=cp=$cp_image,dsp=$dsp_image,boot33=$boot_image,rfbin=$rfbin_image,rd=$rd_image,customer_app=$customer_app_image,logo=$logo_image,preboot_bin=$preboot_image,boot2_bin=$boot2_image,customer_fs=$customer_fs_image,customer_backup_fs=$customer_backup_fs_image,flasher_bin=$flasher_image,gnss_boot=$gnss_boot_image,gnss_firm=$gnss_firm_image,btbin=$btbin_image,btlst=$btlst_image
else
	board_Variant=QUEC_CRANEL_DS_08MB_OPEN
	standard_arelease_iamges=cp=$cp_image,dsp=$dsp_image,boot33=$boot_image,rfbin=$rfbin_image,rd=$rd_image,customer_app=$customer_app_image,logo=$logo_image,preboot_bin=$preboot_image,boot2_bin=$boot2_image,customer_fs=$customer_fs_image,customer_backup_fs=$customer_backup_fs_image,flasher_bin=$flasher_image
fi

$ARELEASE_BIN -c ${IMAGE_DIR} -g -p CRANEL_QUEC_PRODUCT -v $board_Variant -i $standard_arelease_iamges ${VERSION}.zip


echo ${VERSION}
echo ${BUILD_TIME}
