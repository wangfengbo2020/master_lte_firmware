/******************************************************************************
*(C) Copyright 2008 Marvell International Ltd.
* All Rights Reserved
******************************************************************************/
/*--------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  Filename: telprod.h
 *
 *  Description: Definition of propriatry AT Commands for production mode.
 *
 *  History:
 *   May 20, 2010 - Creation of file
 *
 *  Notes:
 *
 ******************************************************************************/
#ifndef TEL_PROD_H
#define TEL_PROD_H

#include "teldef.h"
#include "quec_cust_feature.h"
#define MAX_FILE_NAME_LEN	116
#define MAX_VERSION_LEN		4
#define MAX_DATE_LEN		9
#define MAX_SERIAL_LEN      32
#define MAX_PRE_PWD_LEN     32
#define MAX_IMEI_LEN      	16
#define MAX_MAC_LEN      12
#define MAX_SSID_LEN      	128
#define MAX_WIFI_PASSWORD_LEN      	128
#define MAX_WIFI_CIPHER_LEN      	16

#define MAX_PID_LEN      	4
#define MAX_VID_LEN      	4


#define MAX_SIMCOM_LEN		2
#define MAX_SIMVER_LEN		2
#define MAX_SIMENCRY_LEN      	160
#define MAX_USBMODE_LEN      	1
#define MAX_HWVER_LEN   32
#define MAX_SWVER_LEN   32
#define MAX_PROTYPE_LEN   32
#define MAX_MANUFACTURE_LEN 32
#define MAX_DEVICE_MODEL_LEN 32
#define MAX_RDFILENAME_LEN	128

#define USER_DATA "Marvell"
#define SERIAL_NUM_FILE_FULL_NAME "www\\temp\\serialNum"
#define SERIAL_NUM_FILE_NAME "serialNum"
#define SERIAL2_NUM_FILE_NAME "serialNum2"			//Fias.fan @20220617 //增加SN2的读写接口和AT

#define PRE_PWD_FILE_FULL_NAME "www\\temp\\prePassword"
#define PRE_PWD_FILE_NAME "prePassword"
#define IMEI_NUM_FILE_FULL_NAME "www\\temp\\imei"
#define IMEI_NUM_FILE_NAME "IMEI.bin"
#ifdef QUEC_ADD_IMEI2_CONFIG
#define IMEI2_NUM_FILE_NAME "IMEI2.bin"
#endif
#define MEP1_FILE_FULL_NAME "www\\temp\\mep"
#define MEP1_FILE_NAME "MEP.bin"
#define MAC_FILE_FULL_NAME "www\\temp\\mac"
#define MAC_FILE_NAME "MAC.bin"
#ifdef QUEC_WSETMAC_SUPPORT
#define QMAC_FILE_FULL_NAME "www\\temp\\qmac"
#define QMAC_FILE_NAME "QMAC.bin"
#endif
#define SSID_FILE_FULL_NAME "www\\temp\\ssid"
#define SSID_FILE_NAME "SSID.bin"
#define PASSWORD_FILE_FULL_NAME "www\\temp\\password"
#define PASSWORD_FILE_NAME "PASSWORD.bin"
#define AUTHMODE_FILE_FULL_NAME "www\\temp\\authmode"
#define AUTHMODE_FILE_NAME "authmode.bin"
#define CIPHER_FILE_FULL_NAME "www\\temp\\cipher"
#define CIPHER_FILE_NAME "cipher.bin"
#define PID_FILE_FULL_NAME "www\\temp\\pid"
#define PID_FILE_NAME "pid.bin"
#define VID_FILE_FULL_NAME "www\\temp\\vid"
#define VID_FILE_NAME "vid.bin"
#define SIMKEY_FILE_FULL_NAME "www\\temp\\simkey"
#define SIMKEY_FILE_NAME "simkey.bin"
#define CDF_FILE_FULL_NAME "www\\temp\\cdfnvmfile"
#define MAX_PASSWORD_LEN   16

#define USBMODE_FILE_FULL_NAME "www\\temp\\usbmode"
#define USBMODE_FILE_NAME "usbmode.bin"

#define HWVER_FILE_FULL_NAME "www\\temp\\hwver"
#define HWVER_FILE_NAME "hwversion.bin"

#define SWVER_FILE_FULL_NAME "www\\temp\\swver"
#define SWVER_FILE_NAME "swver.bin"

#define PTVER_FILE_FULL_NAME "www\\temp\\ptver"
#define PTVER_FILE_NAME "ptver.bin"

#define DIALMODE_FILE_FULL_NAME "www\\temp\\dialmode"
#define DIALMODE_FILE_NAME "dialmode.bin"

#define DIALAPN_FILE_FULL_NAME "www\\temp\\dialapn"
#define DIALAPN_FILE_NAME "dialapn.bin"

#define DIALIPTYPE_FILE_FULL_NAME "www\\temp\\dialiptype"
#define DIALIPTYPE_FILE_NAME "dialiptype.bin"

#ifdef 	QUEC_CAMMERA_DECODE_AUTHORIZATION
#define QR_FILE_NAME "QR.bin"
#define QLINCENSE_FILE_NAME "QLINCENSE_INFO.bin"
#endif

#ifdef QUEC_AUDIO_DENOISE
#define QLINCENSE_DENOISE_FILE_NAME "QLINCENSE_DENOISE_INFO.bin"
#endif
//#define UNUSEDPARAM(param) (void)param
#define NVM_FILE_PATH "NVM\\"
#define TEMP_FILE_PREFIX "www\\temp\\"

#define MANUFACTURE_FILE_FULL_NAME "www\\temp\\manufacture"
#define MANUFACTURE_FILE_NAME "manufacture.bin"

#define MODEL_FILE_FULL_NAME "www\\temp\\model"
#define MODEL_FILE_NAME "model.bin"

#define BOARDTYPE_FILE_FULL_NAME "www\\temp\\boardtype"
#define BOARDTYPE_FILE_NAME "boardtype.bin"
#define MASTERKEY_FILE_FULL_NAME "www\\temp\\masterkey"
#define MASTERKEY_FILE_NAME "MASTERKEY.bin"

/*WIFI Password , set from RD, added by shoujunl @140603 start*/
#define WIFI_PASWD_FILE_FULL_NAME	"www\\temp\\wifipassword"
#define WIFI_PASWD_FILE_NAME	"wifipassword.bin"
#define MAX_WIFIPASWD_LEN   32
/*WIFI Password , set from RD, added by shoujunl @140603 start*/

#define FAST_DORMANCY_FILE_FULL_NAME "www\\temp\\fastdormancy"
#define FAST_DORMANCY_FILE_NAME "fastdormancy.bin"


 RETURNCODE_T  SysSleep (const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
 RETURNCODE_T  AtMrdRfc (const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
 RETURNCODE_T  AtMrdAdf (const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
 RETURNCODE_T  AtMrdCdf (const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
 RETURNCODE_T  AtMrdSn  (const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
 RETURNCODE_T  AtMrdPrePassword  (const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
 RETURNCODE_T  AtMrdAuth(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
 RETURNCODE_T  AtMrdImei(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
 RETURNCODE_T  AtMrdMep (const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
 RETURNCODE_T  AtVbatCal (const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
 RETURNCODE_T  AtMrdVbatCal (const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
 RETURNCODE_T  AtRedirect(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
 #ifndef TR069_DISABLE
 RETURNCODE_T  AtTR069(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
 #endif
 RETURNCODE_T  AtMrdMac(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
 RETURNCODE_T  AtMrdSsid(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
 RETURNCODE_T  AtMrdPassword(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMrdPID(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMrdVID(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMrdSimKey(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMrdWIFI(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMifiUsbMode(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMifiVER(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMifiDialMode(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtPowerSave(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMIFIDMINFO(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMrdCipher(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMifiDialConf(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMIFISaveRD(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATRFC(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATPROD(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATWIFIIDRW(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATWIFICHANNEL(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATWIFITXDATARATE(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATWIFIBAND(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATWIFIBANDWIDTH(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATWIFIVERSION(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATWIFIWEPKEY(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATWIFIWPAKEY(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);

RETURNCODE_T  ATWIFIWPA2KEY(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);

RETURNCODE_T  ATWIFIMIXEDKEY(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);

RETURNCODE_T  AtGetSSGVer(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtGetSSGTime(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATWIFIMFGTEST(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATWIFITEST(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtBoardType(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMasterKey(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATWIFIDBG(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtGetSSGModelName(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtPMICReg(            const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t  num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtRegRW(            const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t  num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtGPIOVER(            const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t  num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtWIFILOG(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATMRDBACKUP(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATMRDRESTORE(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMrdMepPLMN(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtWIFIWake(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtSYSWake(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtCheckSMS(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMrdUpdateMEP(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMIFIUpdatePaswd(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
/*for WIFI PASSWORD added by shoujunl @ 140603 start*/
RETURNCODE_T  AtMRD_WIFIPASWD(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
/*for WIFI PASSWORD added by shoujunl @ 140603 end*/
RETURNCODE_T  ATWIFISTICKYTIMCONFIG(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATWIFISTICKYTIMSTAMAC(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATWIFISTA(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATMKSMSFULL(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATCLEARSMS(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  AtMifiFdy(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
#ifdef PLAT_NEZHAC
RETURNCODE_T  ATWL(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
#endif
RETURNCODE_T  IPSECTest(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);


typedef struct vbat_calib_S {
	int gain;
	int offset;
}vbat_calib_T;

RETURNCODE_T  AtCalInfo(            const utlAtParameterOp_T        op,
                                       const char                      *command_name_p,
                                       const utlAtParameterValue_P2c   parameter_values_p,
                                       const size_t                    num_parameters,
                                       const char                      *info_text_p,
                                       unsigned int                    *xid_p,
                                       void                            *arg_p);
RETURNCODE_T  ATAUDNVM(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ATMBIMCFG(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
#endif

