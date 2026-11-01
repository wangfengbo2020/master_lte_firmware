/******************************************************************************
*(C) Copyright 2008 Marvell International Ltd.
* All Rights Reserved
******************************************************************************/
/*--------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  Filename: dev_api.c 
 *
 *  Description: API interface implementation for dev service
 *
 *  History: 
 *   Oct 17, 2008 - Qiang Xu, Creation of file    
 *
 *  Notes:
 *
 ******************************************************************************/
#include "ci_api_types.h"
#include "ci_api_client.h"
#include "telatci.h"
#include "teldef.h"
#include "telatparamdef.h"
#include "telutl.h"
#include "ci_dev.h"
#include"utlMalloc.h"
#include "teldev.h"
#include "utlTrace.h"
#include "dev_api.h"
#include "pl_d_globs.h"
#include "utilities.h"

#include "quec_atcmd_general.h"
#include "quec_atcmd_network.h"
#include "quec_debug.h"
#include "quec_urc.h"
#include "utlTimer.h"
#include "quec_net.h"
#include "quec_cust_patch.h" //quectel add
#ifdef QUEC_USB_QWIFISCAN_SUPPORT
#include "quec_atcmd_tcpip.h"
#include "quec_atcmd_production.h"
#endif
#include "quec_msg_process.h"
#include "quec_power_manager.h"
#include "quec_paging_kalive_app.h"

#ifdef QUECTEL_OPEN_CPU
#include "ql_nw.h"
#endif


#ifdef QUECTEL_NETWORK_SUPPORT
#define Network_Info_Log(msg, ...)  custom_log("NETWORK_INFO", msg, ##__VA_ARGS__)
#if QUEC_DUAL_SIM_SUPPORT
extern CiPsNwRegInfo quec_cgreg_info[2];
extern CiPs4GNwRegInfo quec_cereg_info[2];
extern CiMmPrimRegResultInd quec_creg_info[2];
#else
extern CiPsNwRegInfo quec_cgreg_info;
extern CiPs4GNwRegInfo quec_cereg_info;
extern CiMmPrimRegResultInd quec_creg_info;
#endif
#endif
extern INT16 gIpTrace_IPV4CopyLen;
extern INT16 gIpTrace_IPV6CopyLen;
#ifdef QUECTEL_AT_QCFG_SUPPORT
//extern QuecFreqScanType quec_asr_freq_scan_config;
#endif

#if defined (__QUEC_OEM_VER_PAX__) || defined (QUEC_NETWORK_GET_ECNO)

#include "quec_atcmd_network.h"
extern int g_3g_ecno;
bool g_ecno_ci_send = FALSE;

#endif
#ifdef QUECTEL_AT_RFTEST_SUPPORT
extern uint8 quec_ftm_state_flag;
#endif

#ifdef QUEC_ENGINEER_OUTPUT
extern char * quec_QengineerResBuf;
extern UINT32 quec_QengineerResLen;
extern UINT32 quec_QengineerBufLen;
extern UINT32 quec_qengineer_atp;
#endif

#ifdef QUECTEL_AT_QCFG_SUPPORT

extern  UINT8 quec_match_nwmode_with_band(UINT8 nwmode);
extern int quec_get_current_net_regstatus(void);
extern bool quec_is_correct_imsi(char *pIMSI,char *pReportIMSI);
#if 0
extern bool quec_audio_get_call_status(void);
#else
extern bool quec_led_get_call_status(void);
#endif
extern  char * Quectel_SMONCPrintf(UINT8 bFirstItem,  char*res_buff_ptr, char *szPlmn, UINT16 u16Lac, UINT32 uiCid, UINT8 u8BSIC, UINT16 u16Freq, INT32 iRssi, INT32 iC1, INT32 iC2);
extern QuecOSStatus quec_siolib_transmit_to_atp(TelAtParserID atp_index, uint8 *buf, uint32 len, uint32 * pActualTransLen);
extern void quec_set_net_service(UINT8 net_serv);
extern void  quec_loac_set_wifi_band_state(int state);

/* 1601 Enhance engineer mode 时 L1不会上报当前的rssi 
信息，因此上报的CiDevPrimLteEngmodeScellInfoInd的rssi为0 
 * 因此从csq中上报的CiMmPrimExtendedSigQualityInfoInd获取rssi
 */
#include "mm_api.h"
#if QUEC_DUAL_SIM_SUPPORT
extern mmExtendedSignal_quec quec_netquality_info[2];
#else
extern mmExtendedSignal_quec quec_netquality_info;
#endif
extern char IMSI[];
#endif
#ifdef QUECTEL_NETWORK_SUPPORT
/*isaac-20200716 add rxlev check data vaild */
#define QENG_SERVINGCELL_RXLEV_MAX 63
#endif

#ifdef QUECTEL_CELL
#define NCELL_CELL_ID_MIN   (0)
#define NCELL_CELL_ID_MAX   (0XFFFFFFFF)
#define NCELL_BSIC_MAX      (0XFF)
#define NCELL_PSC_MAX       (0XFFFF)
#define NCELL_CELL_MCC_INVALID (0)
#define QUEC_REGSTATUS_NOT_REGED (0)
#define QUEC_NECLL_GSM_MAX_RSSI (-65)
#define QUEC_NECLL_GSM_MIN_RSSI (-128)
#define QUEC_CELL_RSSI_MIN  (0)
#define QUEC_CELL_RSSI_MAX  (63)
extern char quec_cellex_info_buf[QUEC_CELLEX_INFO_MAX_LEN+1];
#endif

#ifdef QUEC_QNWCFG_SUPPORT
quec_csi_info_s_t qnwcfg_csi_info={0};
#endif

#ifdef QUECTEL_NETWORK_REJECT_URC_SUPPORT
UINT8 report_type=255;
BOOL report_flag=FALSE;
UINT8 reject_cause=255;
const ceer_lookup_s_type  *result_ptr = NULL;
extern UINT8 netreject_mode;
#endif

#ifndef MIN_SYS
extern void quec_wifiscan_ping(UINT32 atHandle);
#endif
/************************************************************************************
 *
 * Dev related const and global variables
 *
 *************************************************************************************/
extern CiServiceHandle 	    gAtciSvgHandle[CI_SG_NUMIDS+1];

extern CiDevStatus         gDeviceStatus;
extern CiDevStatus gDeviceStatus_1;

#ifdef QUEC_3601_PMIC_PWRKEY_9374
extern BOOL gFuncReset;
extern BOOL gFuncReset_1;
#endif
extern EngModeInfo stEngModeInfo_1;
extern UINT8 g_UMTS_EM_IND_SEQ;
extern UINT8 g_UMTS_EM_IND_SEQ_1;
extern EngModeInfo stEngModeInfo;
extern CiDevEngModeReportOption gEngModeRepOpt;
extern CiDevEngModeReportOption gEngModeRepOpt_1;
extern CiDevEngModeReportOption gStoreEngModeRepOpt;
extern CiDevEngModeReportOption gStoreEngModeRepOpt_1;
extern int gStoreTimeVal;
extern int gStoreTimeVal_1;
extern int gCurrTimeVal;
extern int gCurrTimeVal_1;
extern BOOL g_suppress_sim_removed;
extern BOOL g_suppress_sim_removed_1;
extern BOOL g_suppress_sim_removed_saved;
extern BOOL g_suppress_sim_removed_saved_1;
extern int gSINR;
extern int gSINR_1;
extern BOOL gSINRUpdate;
extern BOOL gSINRUpdate_1;
extern int gRSSI;
extern int gRSSI_1;
extern BOOL gRSSIUpdate;
extern BOOL gRSSIUpdate_1;
extern UINT16 gcell_lac, gcell_mcc, gcell_mnc;
extern UINT32 gcell_ci;
#ifdef LWIP_IPNETBUF_SUPPORT
extern UINT8 g_medcr_value;
extern UINT8 g_medcr_value_1;
#endif
extern char internalRevisionId[MAX_INTERNALREVISION_ID_LENGTH + 1];
extern char buildTimeStr[MAX_BUILDTIME_STR_LENGTH + 1];
extern void initATCIContext(UINT32 atHandle);
extern char revisionId[128];
extern int CurrentCfunValue;
extern int enterCfunValue;
extern UINT32   lastNWMode;
extern UINT32   lastNWMode_1;
extern void libConvertNumToHex(char *inData, int inLen, char *outData);
extern int libConvertHexToNum(char *inData, int inLen, char *outData);
#ifdef AT_FOR_GW20180208SN
extern UINT8 current_bandInd;
extern UINT8 current_accessTechnology;
extern char curr_operIdLongStr[CIMM_MAX_OPER_ID_LEN + 1] ;
extern UINT16 m_lac_tac;
extern UINT32 m_cell_id;
extern UINT16 m_bsic_phycellid;
extern UINT16 m_channel;
extern INT16 m_rxdbm;
extern INT16 m_txdbm;



extern UINT8 m_rsrp;
extern UINT8 m_rsrq;
extern INT8 m_sinr;
#endif
#ifdef QUECTEL_CTWing_SUPPORT
INT16 quec_g_txpower = 0;
INT16 quec_g_rsrp = 0;
INT16 quec_g_sinr = 0;
#endif

/****************************************************************
 *  F@: sim_libConvertNumToHexString - Convert number in CCI msg to HEX data string displayed in MAT cmd
 *  Note:  the data is appended to *outData
 */
void sim_libConvertNumToHexString(char *inData, int inLen, char *outData)
{
	int index=0;

	if (inLen > 0)
	{
		char* ptr=NULL;
		int length=0;

		ptr = &outData[strlen(outData)];
		length = sprintf(ptr, "\"");
		ptr += length;

		for (index = 0; index < inLen; index ++)
		{
			length = sprintf(ptr, "%02X", inData[index]);
			ptr += length;
		}
		length = sprintf(ptr, "\"");
		ptr += length;
	}
}
RETURNCODE_T SysSleepProcessSetFunc(UINT32 reqHandle, BOOL succ)
{
	CiReturnCode ret = CIRC_FAIL;
	if(succ == FALSE)
	{
		ret = ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
		return ret;
	}

	ret = ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
	return ret;
}

/************************************************************************************
 *
 * Implementation of Dev related AT commands by sending Request to CCI. 
 *
 *************************************************************************************/
/************************************************************************************
 * F@: ConvertHsdpaMode2Ci - Convert HSDPA Mode from AT to CCI enum
 *
 */
static BOOL libConvertHsdpaMode2Ci(UINT8 mode, CiDevHspaConfig *hspaCnf )
{
	BOOL ret = TRUE;
	DBGMSG("%s mode = %d.\n", __FUNCTION__, mode);

	switch ( mode )
	{
		case ATCI_HSDPA_OFF_HSUPA_OFF:
			*hspaCnf = CI_DEV_HSDPA_OFF_HSUPA_OFF;
			break;
		case ATCI_HSDPA_ON_HSUPA_ON:
			*hspaCnf = CI_DEV_HSDPA_ON_HSUPA_ON;
			break;
		case ATCI_HSDPA_ON_HSUPA_OFF:
			*hspaCnf = CI_DEV_HSDPA_ON_HSUPA_OFF;
			break;
		case ATCI_HSDPA_ON_HSUPA_ON_DLDC:
			*hspaCnf = CI_DEV_HSDPA_ON_HSUPA_ON_DLDC;
			break;
		case ATCI_HSPA_REL6:
			*hspaCnf = CI_DEV_HSPA_REL6;
			break;
		default:
			ret = FALSE;
			break;
	}
	return ret;
}
/************************************************************************************
 * F@: ConvertHsdpaMode2At - Convert HSDPA Mode from CCI enum to AT
 *
 */
static BOOL libConvertHsdpaMode2At(CiDevHspaConfig hspaCnf, UINT8 *mode)
{
	BOOL ret = TRUE;
	DBGMSG("%s hspaCnf = %d.\n", __FUNCTION__, hspaCnf);

	switch ( hspaCnf )
	{
		case CI_DEV_HSDPA_OFF_HSUPA_OFF:
			*mode = ATCI_HSDPA_OFF_HSUPA_OFF;
			break;
		case CI_DEV_HSDPA_ON_HSUPA_OFF:
			*mode = ATCI_HSDPA_ON_HSUPA_OFF;
			break;
		case CI_DEV_HSDPA_ON_HSUPA_ON:
			*mode = ATCI_HSDPA_ON_HSUPA_ON;
			break;
		case CI_DEV_HSDPA_ON_HSUPA_ON_DLDC:
			*mode = ATCI_HSDPA_ON_HSUPA_ON_DLDC;
			break;
		case CI_DEV_HSPA_REL6:
			*mode = ATCI_HSPA_REL6;
			break;
		default:
			ret = FALSE;
			break;
	}
	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_GetCD
*
*  PARAMETERS:
*
*  DESCRIPTION: Caculate the CD value from 14 digital imel numbers
*
*  RETURNS: CHAR
*
****************************************************************************************/
CHAR DEV_GetCD(CHAR * imei)
{
	int num = 0;
	int sum = 0;
	int CD = 0;
	int digNum = 0;
	if(imei == NULL)
		return 0;

	while(*imei)
	{
		if( *imei >'9' || *imei <'0')
			return 0;
		digNum = *imei - '0';
		if(num % 2)
			digNum *= 2;
		if(digNum >= 10)
			digNum = digNum/10 + digNum%10;
		sum += digNum;
		num++;
		imei++;
	}
	if(sum % 10)
		CD = 10 - sum%10;
	else
		CD = 0;

	return '0'+CD;
}
#ifndef MORE_ATC_SPACE_OPT
/*These methods are for function value cache, other module can query without invoking CI interface*/
static UINT8 glb_current_func_conf;

UINT8 GlbGetFuncConf(void)
{
	return 	glb_current_func_conf;
}

void GlbSetFuncConf(UINT8 conf)
{
	//uart_printf("\r\n CFUN SET %d\r\n",conf);
	glb_current_func_conf = conf;
}
#endif
//*********************************************************************************************//
#ifdef QUEC_3601_PMIC_PWRKEY_9374
//Rui.xu@2021/08/23:STASR1601-4314,Prevent calling large system functions during FOTA upgrade

#else
int GetCfunValue(void)
{
    //uart_printf("%s:CurrentCfunValue=%d",__FUNCTION__,CurrentCfunValue);
    return  CurrentCfunValue;
}

void SetCfunValue(int value)
{
    //uart_printf("%s:set cfun %d",__FUNCTION__,value);
	DEV_SetFunc(IND_REQ_HANDLE, value, 0, FALSE, 0, 0);
}

void wait_cfun_done(void)
{
	int count = 45;// 45s
	while(count > 0)
	{
		if(enterCfunValue == 0xFFFFFFFF)
		{
			break;
		}
		OSATaskSleep(200);
		count--;
	}
	if(count <= 0)
	{
		//uart_printf("%s:[ERROR]set CFUN0 timeout",__FUNCTION__);
	}
}
#endif
//*********************************************************************************************//


/****************************************************************************************
 *  FUNCTION:  DEV_GetDevStatus
 *
 *  PARAMETERS:
 *
 *  DESCRIPTION: interface to get current activity status, implementation of AT+CPAS
 *
 *  RETURNS: CiReturnCode
 *
 ****************************************************************************************/
CiReturnCode DEV_GetDevStatus(UINT32 atHandle)
{
	CiReturnCode	ret = CIRC_SUCCESS;
	char AtReplyBuf[100];
	CiDevStatus *pDeviceStatus;

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
		pDeviceStatus = &gDeviceStatus;
	} else {
		pDeviceStatus = &gDeviceStatus_1;
	}
#else
	pDeviceStatus = &gDeviceStatus;
#endif


	memset(AtReplyBuf, 0, sizeof(AtReplyBuf));
	sprintf(AtReplyBuf, "+CPAS: %d", *pDeviceStatus);
	ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, AtReplyBuf);
    
        return ret;
}

#ifdef AT_CMD_UNUSED_ENABLE

/****************************************************************************************
 *  FUNCTION:  DEV_SetEngineModeReportOption
 *
 *  PARAMETERS:
 *
 *  DESCRIPTION: interface to set engine mode report option, implementation of AT+CGED=
 *
 *  RETURNS: CiReturnCode
 *
 ****************************************************************************************/
CiReturnCode DEV_SetEngineModeReportOption(UINT32 atHandle, int modeVal, int timeVal)
{
	CiReturnCode	ret = CIRC_FAIL;
	CiDevPrimSetEngmodeRepOptReq   *setEngmodeRepOptReq=NULL;
	CiDevEngModeReportOption *pEngModeRepOpt;

	if (!GET_SIM1_FLAG(atHandle)) {
		pEngModeRepOpt = &gEngModeRepOpt;
	} else {
		pEngModeRepOpt = &gEngModeRepOpt_1;
	}

	setEngmodeRepOptReq = utlCalloc(1, sizeof(CiDevPrimSetEngmodeRepOptReq));
	if (setEngmodeRepOptReq == NULL)
		return CIRC_FAIL;

        if (modeVal == 0) //export the engineering information once
	{
		setEngmodeRepOptReq->type = CI_DEV_EM_OPTION_REQUEST;
	}
	else if (modeVal == 2) // stop the reporting the engineering information
	{
		setEngmodeRepOptReq->type = CI_DEV_EM_OPTION_NONE;
	}
	else // export the engineering information periodically
	{
		setEngmodeRepOptReq->type = CI_DEV_EM_OPTION_PERIODIC;
		setEngmodeRepOptReq->interval = timeVal;
	}

	/* Send the request */	            
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_ENGMODE_REPORT_OPTION_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_DEV_PRIM_SET_ENGMODE_REPORT_OPTION_REQ), (void *)setEngmodeRepOptReq );

	*pEngModeRepOpt = setEngmodeRepOptReq->type;
	
        return ret;
}
#endif
/****************************************************************************************
 *  FUNCTION:  DEV_GetSerialNumId
 *
 *  PARAMETERS:
 *
 *  DESCRIPTION: interface to get serial number ID, implementation of AT+CGSN, +CGSN?
 *
 *  RETURNS: CiReturnCode
 *
 ****************************************************************************************/
CiReturnCode DEV_GetSerialNumId(UINT32 atHandle)
{
	CiReturnCode	ret = CIRC_FAIL;
	CiDevPrimGetSerialNumIdReq   *getCgsnReq=NULL;
	//uart_printf("Function:%s\r\n",__FUNCTION__);
	getCgsnReq = utlCalloc(1, sizeof(CiDevPrimGetSerialNumIdReq));
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_SERIALNUM_ID_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_DEV_PRIM_GET_SERIALNUM_ID_REQ), (void *)getCgsnReq);

        return ret;
}

#ifdef QUECTEL_NETWORK_SUPPORT  //connor.wu 2018/12/24 fix the cops and *band compatibility issue
CiReturnCode DEV_SetBandModeReqByReqHandler(UINT32 reqHandle, UINT8 networkMode, UINT8 preferredMode,  UINT32 gsmMode, UINT32 umtsMode, UINT32 eutranhMode, UINT32 eutranlMode, UINT8 roamingConfig, UINT8 srvDomain, UINT8 bandPriorityFlag, CiBoolean isLteDualLink, UINT32 EUTRANBandModeExt)
{
    CiReturnCode ret = CIRC_FAIL;
    CiDevPrimSetBandModeReq                         *setBandModeReq;

    setBandModeReq = (CiDevPrimSetBandModeReq *)utlCalloc(1, sizeof(CiDevPrimSetBandModeReq));
    if (setBandModeReq == NULL)
    return CIRC_FAIL;

    CPUartLogPrintf("%s:reqHandle=0x%x,%d,%d,%x,%x,%x,%x,%x", __func__, reqHandle,networkMode,preferredMode,gsmMode, umtsMode, eutranhMode, eutranlMode, EUTRANBandModeExt);


    setBandModeReq->networkMode = networkMode;
    setBandModeReq->preferredMode = preferredMode;
    setBandModeReq->GSMBandMode = gsmMode;
    setBandModeReq->UMTSBandMode = umtsMode;
    setBandModeReq->EUTRANBandModeH = eutranhMode;
    setBandModeReq->EUTRANBandModeL = eutranlMode;
    setBandModeReq->roamingConfig = roamingConfig;
    setBandModeReq->srvDomain = srvDomain;
    setBandModeReq->bandPriorityFlag = bandPriorityFlag;
    setBandModeReq->isLteDualLink = isLteDualLink;
    setBandModeReq->EUTRANBandModeExt=EUTRANBandModeExt;

    ret = ciRequestExt( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_BAND_MODE_REQ,
    reqHandle, (void*)setBandModeReq);

    return ret;
}
#endif

#ifdef QUEC_BLACK_CELL_SUPPORT	//#65185
CiDevMeasReportConfigData gMeasRepConfig ={0};
CiDevMeasReportConfigData gMeasRepConfig_1 ={0};
CiReturnCode DEV_SetMeasReportConfigData(UINT32 atHandle, int scell_offset, int ncell_offset)
{
	CiReturnCode	ret = CIRC_FAIL;
	CiDevPrimSetCommonFeatureReq   *setCommonFeatureReq = NULL;
	CiDevMeasReportConfigData *measReportConfig;

	if (!GET_SIM1_FLAG(atHandle)) {
		measReportConfig = &gMeasRepConfig;
	} else {
		measReportConfig = &gMeasRepConfig_1;
	}
	setCommonFeatureReq = utlCalloc(1, sizeof(CiDevPrimSetCommonFeatureReq));
	if (setCommonFeatureReq == NULL)
		return CIRC_FAIL;

	CPUartLogPrintf("%s scell:%d ncell:%d", __func__, scell_offset, ncell_offset);
	setCommonFeatureReq->cmdType                                        = 0;   //set
	setCommonFeatureReq->featureId                                      = CI_DEV_FT_MEAS_REPORT_CFG;
	setCommonFeatureReq->commonFtData.measReportConfig.offset_scell     = scell_offset;
	setCommonFeatureReq->commonFtData.measReportConfig.offset_ncell_lte = ncell_offset;
	measReportConfig->offset_scell     = scell_offset;
	measReportConfig->offset_ncell_lte = ncell_offset;

	/* Send the request */
	ret = ciRequestExt( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_COMMON_FEATURE_REQ,
			MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_SET_COMMON_FEATURE_REQ), (void *)setCommonFeatureReq);

        return ret;
}

CiReturnCode DEV_GetMeasReportConfigData(UINT32 atHandle)
{
	CiReturnCode	ret = CIRC_FAIL;
	CiDevPrimGetCommonFeatureReq   *reqGetCommonFeature = NULL;
	//CiDevMeasReportConfigData *measReportConfig;

	reqGetCommonFeature = utlCalloc(1, sizeof(CiDevPrimSetCommonFeatureReq));
	if (reqGetCommonFeature == NULL)
		return CIRC_FAIL;
	reqGetCommonFeature->index     = GET_ATP_INDEX(atHandle);
	reqGetCommonFeature->featureId = CI_DEV_FT_MEAS_REPORT_CFG;
	/* Send the request */
	ret = ciRequestExt( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_COMMON_FEATURE_REQ,
			MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_COMMON_FEATURE_REQ), (void *)reqGetCommonFeature);

        return ret;
}
#endif

/****************************************************************************************
*  FUNCTION:  DEV_GetWirelessModeReq
*
*  PARAMETERS:
*
*  DESCRIPTION: interface to get wireless mode, implementation of AT+WS46?
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_GetWirelessModeReq(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_BAND_MODE_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_WIRELESS_MODE_REQ), NULL);

	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_SetWirelessModeReq
*
*  PARAMETERS:
*
*  DESCRIPTION: interface to select wireless data service, implementation of AT+WS46=
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_SetWirelessModeReq(UINT32 atHandle, UINT8 networkMode, UINT8 preferredMode)
{
	CiReturnCode ret = CIRC_FAIL;
	/*0,0,0,0,2,4,0 are the respective value for GSMBandMode, UMTSBandMode, EUTRANBandModeH,
	  EUTRANBandModeL, roamingConfig, srvDomain, bandPriorityFlag, isLteDualLink.*/
	  
	ret = DEV_SetBandModeReq(atHandle, networkMode, preferredMode, 0, 0, 0, 0, 2, 4, 0, 0, 0);

	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_GetEngineModeInfo
*
*  PARAMETERS:
*
*  DESCRIPTION: interface to get engine mode info, implementation of AT+CGED=0  (mode type = CI_DEV_EM_OPTION_REQUEST)
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_GetEngineModeInfo(UINT32 atHandle)
{
	CiReturnCode	ret = CIRC_FAIL;
	CiDevPrimGetEngmodeInfoReq   *getEngmodeInfoReq=NULL;

	getEngmodeInfoReq = utlCalloc(1, sizeof(CiDevPrimGetEngmodeInfoReq));
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_ENGMODE_INFO_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_DEV_PRIM_GET_ENGMODE_INFO_REQ), (void *)getEngmodeInfoReq);
                        
    return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_SetEngModeIndicatorOption
*
*  PARAMETERS:
*
*  DESCRIPTION: interface to set engine mode report option, implementation of AT+EEMOPT=
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode
DEV_SetEngModeIndicatorOption(UINT32 atHandle, int modeVal, int timeVal)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimSetEngmodeRepOptReq   *setEngmodeRepOptReq=NULL;
	int *pCurrTimeVal, *pStoreTimeVal;
	CiDevEngModeReportOption *pEngModeRepOpt, *pStoreEngModeRepOpt;

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
		pCurrTimeVal = &gCurrTimeVal;
		pStoreTimeVal = &gStoreTimeVal;
		pEngModeRepOpt = &gEngModeRepOpt;
		pStoreEngModeRepOpt = &gStoreEngModeRepOpt;
	} else {
		pCurrTimeVal = &gCurrTimeVal_1;
		pStoreTimeVal = &gStoreTimeVal_1;
		pEngModeRepOpt = &gEngModeRepOpt_1;
		pStoreEngModeRepOpt = &gStoreEngModeRepOpt_1;
	}
#else
	pCurrTimeVal = &gCurrTimeVal;
	pStoreTimeVal = &gStoreTimeVal;
	pEngModeRepOpt = &gEngModeRepOpt;
	pStoreEngModeRepOpt = &gStoreEngModeRepOpt;
#endif


	setEngmodeRepOptReq = utlCalloc(1, sizeof(CiDevPrimSetEngmodeRepOptReq));
	if (setEngmodeRepOptReq == NULL)
		return CIRC_FAIL;

	switch (modeVal)
	{
		case 0: // turn off indicator
			setEngmodeRepOptReq->type = CI_DEV_EM_OPTION_NONE;
			break;
		case 1: // set to query mode
			setEngmodeRepOptReq->type = CI_DEV_EM_OPTION_REQUEST;
			break;
		case 2: // set to periodic mode
			setEngmodeRepOptReq->type = CI_DEV_EM_OPTION_PERIODIC;
			setEngmodeRepOptReq->interval = timeVal;
			*pCurrTimeVal = timeVal;
			break;
		case 3: // snapshot mode, old <timeVal> is stored as snapshot
			// current type and value.
			setEngmodeRepOptReq->type = *pEngModeRepOpt;
			setEngmodeRepOptReq->interval = *pCurrTimeVal;

			// store current type and value.
			*pStoreEngModeRepOpt = *pEngModeRepOpt;
			*pStoreTimeVal = *pCurrTimeVal;
			break;
		case 4: // restore to snapshot <timeVal>
			setEngmodeRepOptReq->type = *pStoreEngModeRepOpt;
			setEngmodeRepOptReq->interval = *pStoreTimeVal;
			*pCurrTimeVal = *pStoreTimeVal;
			break;
		
		default:
			break;
	}

	*pEngModeRepOpt = setEngmodeRepOptReq->type;

	/* Send the request */
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_ENGMODE_REPORT_OPTION_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_SET_ENGMODE_REPORT_OPTION_REQ), (void *)setEngmodeRepOptReq );

	return ret;
}
#ifdef AT_CMD_UNUSED_ENABLE

/****************************************************************************************
 *  FUNCTION:  DEV_SysConfig
 *
 *  PARAMETERS:
 *
 *  DESCRIPTION: interface to set phone functionality status, implementation of AT^SYSCONFIG
 *
 *  RETURNS: CiReturnCode
 *
 ****************************************************************************************/
CiReturnCode DEV_SysConfig(UINT32 atHandle, int modVal, int acqVal, int bandVal, int roamVal, int srvVal )
{
	CiReturnCode	ret = CIRC_FAIL;
	CiDevPrimSetBandModeReq   *setBandReq=NULL;
/*
       char mmIndBuf[300];
	sprintf(mmIndBuf, "^SYSCONFIG: %d, %d, %d, %d \r\n", modVal, acqVal, roamVal, srvVal); 
       ATRESP( IND_REQ_HANDLE,0,0,mmIndBuf);
*/       
	UINT32 *plastNWMode;

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
		plastNWMode = &lastNWMode;
	} else {
		plastNWMode = &lastNWMode_1;
	}
#else
	plastNWMode = &lastNWMode;
#endif

	   
	setBandReq = utlCalloc(1, sizeof(CiDevPrimSetBandModeReq));
	//[klockwork][issue id: 1047]
	if(setBandReq == NULL)
	{
		ASSERT(0);
		return CIRC_FAIL;
	}

	setBandReq->GSMBandMode = 0; //default - EGSM_DCS_MODE
	setBandReq->UMTSBandMode = 15; 

	if (modVal == 2) //Auto
		setBandReq->networkMode = CI_DEV_NW_GSM_UMTS;
	else if (modVal == 13) //GSM only
	{
		setBandReq->networkMode = CI_DEV_NW_GSM;
		if (0xffffffff !=(unsigned int) bandVal)
		{
			setBandReq->GSMBandMode = bandVal;
			setBandReq->UMTSBandMode = 0;
		}

	}
	else if (modVal == 15) //TD only
	{
		setBandReq->networkMode = CI_DEV_NW_UMTS;
		if (0xffffffff != (unsigned int)bandVal)
		{
			setBandReq->UMTSBandMode = bandVal;
	             setBandReq->GSMBandMode = 0;
	       }
		}
	else
	{
		utlFree(setBandReq);
		return ret;
	}

	setBandReq->roamingConfig = roamVal;
	setBandReq->srvDomain =  srvVal;   

	switch(acqVal)
	{
		case 0:                                                    //auto
			setBandReq->preferredMode = CI_DEV_NW_GSM_UMTS;
			*plastNWMode = CI_DEV_NW_GSM_UMTS;
			break;

		case 1:                                                   //GSM first
			setBandReq->preferredMode = CI_DEV_NW_GSM;
			*plastNWMode = CI_DEV_NW_GSM;
			break;

		case 2:                                                  //UTRAN first
			setBandReq->preferredMode = CI_DEV_NW_UMTS;
			*plastNWMode = CI_DEV_NW_UMTS;
			break;

		case 3:                                                  //no change
			setBandReq->preferredMode = *plastNWMode;
			break;

		default:
			setBandReq->preferredMode = CI_DEV_NW_GSM_UMTS;
			break;
	}
        
		
        /* Send the CI Request. */
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_BAND_MODE_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_DEV_PRIM_SET_BAND_MODE_REQ), (void *)setBandReq);
    
        /* init the ATCI context variables */
	initATCIContext(atHandle);
      
    return ret;
}

/****************************************************************************************
 *  FUNCTION:  DEV_GetSysConfig
 *
 *  PARAMETERS:
 *
 *  DESCRIPTION: interface to set phone functionality status, implementation of AT^SYSCONFIG?
 *
 *  RETURNS: CiReturnCode
 *
 ****************************************************************************************/
CiReturnCode DEV_GetSysConfig(UINT32 atHandle )
{
	CiReturnCode	ret = CIRC_FAIL;
	CiDevPrimGetBandModeReq   *getBandReq=NULL;

	getBandReq = utlCalloc(1, sizeof(CiDevPrimGetBandModeReq));   	
        /* Send the CI Request. */
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_BAND_MODE_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_DEV_PRIM_GET_BAND_MODE_REQ), (void *)getBandReq);

    
    return ret;
}
#endif

/****************************************************************************************
*  FUNCTION:  DEV_GetEngModeInfo
*
*  PARAMETERS:
*
*  DESCRIPTION: interface to get engine mode info, implementation of AT+EEMGINFO? 
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_GetEngModeInfo(UINT32 atHandle, CiDevEngmodeType type )
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimGetEngmodeInfoReq   *getEngmodeInfoReq=NULL;

	getEngmodeInfoReq = utlCalloc(1, sizeof(CiDevPrimGetEngmodeInfoReq));

	if (getEngmodeInfoReq == NULL)
		return CIRC_FAIL;

    getEngmodeInfoReq->engmodeEnhanceType = type;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_ENGMODE_INFO_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_ENGMODE_INFO_REQ), (void *)getEngmodeInfoReq);

	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_setLPNWUL
*
*  PARAMETERS:
*
*  DESCRIPTION: Delivers measurements and positioning reports and/or status from A-GPS
*               client to PS/NW
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_setLPNWUL(UINT32 atHandle, UINT8 *msg_data, UINT32 msg_data_len,
                  UINT8 count, UINT8 bearer_type, UINT8 isFinalRsp, UINT8 *add_info, UINT32 add_info_len)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimLpNwulMsgReq *setNwulMsgReq=NULL;
	int len=0;
	extern int libConvertHexToNum(char *inData, int inLen, char *outData);
	setNwulMsgReq = utlCalloc(1, sizeof(CiDevPrimLpNwulMsgReq));
	if (setNwulMsgReq == NULL)
		return CIRC_FAIL;

	/* msg_data_len is the total bytes, even if this segment is padding */
	if (msg_data_len >= ((count + 1U) * AT_CMD_MAX_AGPS_MSG_SIZE))
	{
		len = AT_CMD_MAX_AGPS_MSG_SIZE;
	}
	else
	{
		len = msg_data_len % AT_CMD_MAX_AGPS_MSG_SIZE;
	}
	libConvertHexToNum((char *)msg_data, len * 2, (char *)setNwulMsgReq->msg_data);
	setNwulMsgReq->msg_data_len = msg_data_len;
	setNwulMsgReq->count = count;
	setNwulMsgReq->bearer_type = bearer_type;
	setNwulMsgReq->isFinalResponse = isFinalRsp;
	if (add_info_len <= CI_DEV_MAX_ADD_INFO_LEN)
	{
		setNwulMsgReq->additional_info_len = add_info_len;
		libConvertHexToNum((char *)add_info, add_info_len * 2, (char *)setNwulMsgReq->additional_info);
	}
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_LP_NWUL_MSG_REQ,
                         MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_LP_NWUL_MSG_REQ), (void *)setNwulMsgReq);

	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_GetSoftwareVersionNumber
*
*  PARAMETERS:
*
*  DESCRIPTION: interface to get SV of IMEISV, implementation of AT*CGSN?
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_GetSoftwareVersionNumber(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimGetSvReq   *getSvReq=NULL;

	getSvReq = utlCalloc(1, sizeof(CiDevPrimGetSvReq));

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_SV_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_SV_REQ), (void *)getSvReq);

	return ret;
}
/****************************************************************************************
*  FUNCTION:  DEV_GetLteMeas
*
*  PARAMETERS:
*
*  DESCRIPTION: interface to get the lte measure value ,about rsrp,rsrq
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
#ifndef LTEONLY_THIN
CiReturnCode DEV_GetLteMeas(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimGetLteMeasReq   *getSvReq=NULL;

	getSvReq = utlCalloc(1, sizeof(CiDevPrimGetLteMeasReq));

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_LTE_MEAS_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_LTE_MEAS_REQ), (void *)getSvReq);

	return ret;
}
#endif
/****************************************************************************************
*  FUNCTION:  DEV_SetSoftwareVersionNumber
*
*  PARAMETERS:
*
*  DESCRIPTION: interface to set SV of IMEISV, implementation of AT*CGSN=
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_SetSoftwareVersionNumber(UINT32 atHandle, const char* sv)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimSetSvReq   *setSvReq=NULL;

	setSvReq = utlCalloc(1, sizeof(CiDevPrimSetSvReq));
	if (setSvReq == NULL)
		return CIRC_FAIL;

	setSvReq->SVDigits.len = strlen(sv);
	strcpy((char *)setSvReq->SVDigits.val, sv);

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_SV_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_SET_SV_REQ), (void *)setSvReq);

	return ret;
}
#ifndef LTEONLY_THIN
/****************************************************************************************
*  FUNCTION:  DEV_SetHsdpaModeReq
*
*  PARAMETERS:
*
*  DESCRIPTION: interface to enable hsdpa, implementation of AT*EHSDPA=
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_SetHsdpaModeReq(UINT32 atHandle, UINT8 mode, UINT8 dl_category,
	UINT8 ul_category, UINT8 cpc_state, UINT8 dpaCategoryExt, UINT8 edchCategoryExt, UINT8 fdpchState, UINT8 efdpchState)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimEnableHsdpaReq 	*enableHsdpaReq=NULL;
	CiDevHspaConfig hsdpaCnf=0;

	enableHsdpaReq = utlCalloc(1, sizeof(CiDevPrimEnableHsdpaReq));
	if (enableHsdpaReq == NULL)
		return CIRC_FAIL;

	if(libConvertHsdpaMode2Ci(mode, &hsdpaCnf))
	{
		enableHsdpaReq->hspaConfig = hsdpaCnf;
		enableHsdpaReq->dlCategory = dl_category;
		enableHsdpaReq->ulCategory = ul_category;
		enableHsdpaReq->cpcState = cpc_state;
		enableHsdpaReq->dpaCategoryExt = dpaCategoryExt;
		enableHsdpaReq->edchCategoryExt = edchCategoryExt;
		enableHsdpaReq->fdpchState = fdpchState;
		enableHsdpaReq->eFdpchState= efdpchState;
		ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_ENABLE_HSDPA_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_ENABLE_HSDPA_REQ), (void *)enableHsdpaReq);
	}
	else
	{
		utlFree(enableHsdpaReq);
	}
	
	return ret;
}
/****************************************************************************************
*  FUNCTION:  DEV_GetHsdpaModeReq
*
*  PARAMETERS:
*
*  DESCRIPTION: interface to get hsdpa mode, implementation of AT*EHSDPA?
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_GetHsdpaModeReq(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimGetHsdpaStatusReq 		*getHsdpaStatusReq = NULL;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_HSDPA_STATUS_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_HSDPA_STATUS_REQ), (void *)getHsdpaStatusReq);

	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_SetGsmModeTxRxReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to set Tx/Rx on GSM for radio tesing
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_SetGsmModeTxRxReq(UINT32 atHandle, CiDevGsmTxRxOption option, UINT8 gsmBandMode, UINT16 arfcn, UINT32 afcDac, UINT32 txRampScale, UINT32 rxGainCode)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimSetGsmModeTxRxReq                  *setGsmModeTxRxReq=NULL;

	setGsmModeTxRxReq = (CiDevPrimSetGsmModeTxRxReq *)utlCalloc(1, sizeof(CiDevPrimSetGsmModeTxRxReq));
	if (setGsmModeTxRxReq == NULL)
		return CIRC_FAIL;

	setGsmModeTxRxReq->option = option;
	setGsmModeTxRxReq->gsmBandMode = gsmBandMode;
	setGsmModeTxRxReq->arfcn = arfcn;
	setGsmModeTxRxReq->afcDac = afcDac;
	setGsmModeTxRxReq->txRampScale = txRampScale;
	setGsmModeTxRxReq->rxGainCode = rxGainCode;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_GSM_MODE_TX_RX_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_SET_GSM_MODE_TX_RX_REQ), (void*)setGsmModeTxRxReq);

	return ret;
}
#endif


/****************************************************************************************
*  FUNCTION:  DEV_Get_internal_revision_Req
*
*  PARAMETERS:
*
*  DESCRIPTION: CI_DEV_PRIM_GET_INTERNAL_REVISION_ID_REQ AT*CGMR
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_Get_internal_revision_Req(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimGetInternalRevisionIdReq          *getInternalRevisionidReq = NULL;
	getInternalRevisionidReq = utlCalloc(1, sizeof(CiDevPrimGetInternalRevisionIdReq));

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_INTERNAL_REVISION_ID_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_INTERNAL_REVISION_ID_REQ), (void*)getInternalRevisionidReq);

	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_GetLPECID
*
*  PARAMETERS:
*
*  DESCRIPTION: Request an ECID measurement
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_GetLPECID(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimLpEcidMeasReq *getECIDreq;

	getECIDreq = utlCalloc(1, sizeof(CiDevPrimLpEcidMeasReq));
	if (getECIDreq == NULL)
		return CIRC_FAIL;

	getECIDreq->ecidMeasRequested = 0x7;
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_LP_ECID_MEAS_REQ,
                         MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_LP_ECID_MEAS_REQ), (void *)getECIDreq);

	return ret;
}

static char otdoaAssistanceData[sizeof(CiDevPrimLpOtdoaMeasReq)];
/****************************************************************************************
*  FUNCTION:  DEV_GetLPOtdoaReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request an OTDOA measurement
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_GetLPOtdoaReq(UINT32 atHandle, UINT8 *msg_data, UINT32 msg_data_len,  UINT8 count)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimLpOtdoaMeasReq *getOTDOAreq;
	extern int libConvertHexToNum(char *inData, int inLen, char *outData);
	char * potdoaAssistanceData = otdoaAssistanceData;
	int len;
	BOOL send = FALSE;

	/* msg_data_len is the total bytes, even if this segment is padding */
	if (msg_data_len >= ((count + 1U) * AT_CMD_MAX_AGPS_MSG_SIZE))
	{
		len = AT_CMD_MAX_AGPS_MSG_SIZE;
	}
	else
	{
		send = TRUE;
		len = msg_data_len % AT_CMD_MAX_AGPS_MSG_SIZE;
	}
	libConvertHexToNum((char *)msg_data, len * 2, &potdoaAssistanceData[(count * AT_CMD_MAX_AGPS_MSG_SIZE)]);

	if(send == TRUE)
	{
		getOTDOAreq = utlCalloc(1, sizeof(CiDevPrimLpOtdoaMeasReq));
		if (getOTDOAreq == NULL)
			return CIRC_FAIL;
		memcpy(getOTDOAreq,potdoaAssistanceData,sizeof(CiDevPrimLpOtdoaMeasReq));
		ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_LP_OTDOA_MEAS_REQ,
							MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_LP_OTDOA_MEAS_REQ), (char *)getOTDOAreq);
	}
	else
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
		ret = CIRC_SUCCESS;
	}

	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_SetLPOtdoaAbort
*
*  PARAMETERS:
*
*  DESCRIPTION: Request an OTDOA Abort measurement
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_SetLPOtdoaAbort(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimLpOtdoaMeasAbortReq   *SetOtdoaAbort = NULL;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_LP_OTDOA_MEAS_ABORT_REQ,
                         MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_LP_OTDOA_MEAS_ABORT_REQ), (void *)SetOtdoaAbort);

	return ret;
}


/****************************************************************************************
*  FUNCTION:  DEV_SetPowerBackOffReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to enable/disable the power back off, implementation of AT*GRIP=
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_SetPowerBackOffReq(UINT32 atHandle, UINT8 option,UINT8 value, UINT8 nwMode, UINT8 band)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimSetPowerBackOffReq          *setPowerBackOffReq=NULL;

	setPowerBackOffReq = (CiDevPrimSetPowerBackOffReq *)utlCalloc(1, sizeof(CiDevPrimSetPowerBackOffReq));
	if (setPowerBackOffReq == NULL)
		return CIRC_FAIL;

	setPowerBackOffReq->PowerBackOffType = option;
	setPowerBackOffReq->value= value;
	setPowerBackOffReq->networkMode = nwMode;
	setPowerBackOffReq->band = band;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_POWER_BACK_OFF_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_SET_POWER_BACK_OFF_REQ), (void*)setPowerBackOffReq);

	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_GetComConfigReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to get com configuration, implementation of AT*COMCFG=0,XXX
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/

CiReturnCode DEV_GetComConfigReq(UINT32 atHandle, UINT32 tokens)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimGetComConfigReq          *getComConfigReq = NULL;

	getComConfigReq = (CiDevPrimGetComConfigReq *)utlCalloc(1, sizeof(CiDevPrimGetComConfigReq));
	if (getComConfigReq == NULL)
		return CIRC_FAIL;

	getComConfigReq->tokens = tokens;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_COM_CONFIG_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_COM_CONFIG_REQ), (void*)getComConfigReq);

	return ret;
}
/****************************************************************************************
*  FUNCTION:  DEV_SetComConfigReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to set com configuration, implementation of AT*COMCFG=1,XXX
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_SetComConfigReq(UINT32 atHandle, ComConfig* ComConfigData)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimSetComConfigReq          *setComConfigReq = NULL;
	UINT8 numTokens = 0;

	setComConfigReq = (CiDevPrimSetComConfigReq *)utlCalloc(1, sizeof(CiDevPrimSetComConfigReq));
	if (setComConfigReq == NULL)
		return CIRC_FAIL;

	if(ComConfigData->umtsWbAmr != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_UMTS_WB_AMR;
		setComConfigReq->Token[numTokens].value = ComConfigData->umtsWbAmr;
		numTokens++;
	}
    
	if(ComConfigData->gsmWbAmr != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_GSM_WB_AMR;
		setComConfigReq->Token[numTokens].value = ComConfigData->gsmWbAmr;
		numTokens++;
	}

	if(ComConfigData->vendor != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_VENDOR;
		setComConfigReq->Token[numTokens].value = ComConfigData->vendor;
		numTokens++;
	}
	if(ComConfigData->manufacture != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_MANUFACTURE;
		setComConfigReq->Token[numTokens].value = ComConfigData->manufacture;
		numTokens++;
	}
    
	if(ComConfigData->lteCategory != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_LTE_CATEGORY;
		setComConfigReq->Token[numTokens].value = ComConfigData->lteCategory;
		numTokens++;
	}
    
	if(ComConfigData->mutiSlotPowerProfile != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_MULTISLOT_POWERPROFILE;
		setComConfigReq->Token[numTokens].value = ComConfigData->mutiSlotPowerProfile;
		numTokens++;
	}
    
	if(ComConfigData->lteSMSOnly != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_LTE_SMS_ONLY;
		setComConfigReq->Token[numTokens].value = ComConfigData->lteSMSOnly;
		numTokens++;
	}
    
	if(ComConfigData->ecSupported != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_EC_SUPPORTED;
		setComConfigReq->Token[numTokens].value = ComConfigData->ecSupported;
		numTokens++;
	}
    
	if(ComConfigData->epcoSupported != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_EPCO_SUPPORTED;
		setComConfigReq->Token[numTokens].value = ComConfigData->epcoSupported;
		numTokens++;
	}
    
	if(ComConfigData->hccpSupported != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_HCCP_SUPPORTED;
		setComConfigReq->Token[numTokens].value = ComConfigData->hccpSupported;
		numTokens++;
	}
    
	if(ComConfigData->mdrbSupported != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_MDRB_SUPPORTED;
		setComConfigReq->Token[numTokens].value = ComConfigData->mdrbSupported;
		numTokens++;
	}
    
	if(ComConfigData->cpBackoff != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_CP_BACKOFF;
		setComConfigReq->Token[numTokens].value = ComConfigData->cpBackoff;
		numTokens++;
	}
    
	if(ComConfigData->nslp != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_NSLP;
		setComConfigReq->Token[numTokens].value = ComConfigData->nslp;
		numTokens++;
	}
    
	if(ComConfigData->eab != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_EAB;
		setComConfigReq->Token[numTokens].value = ComConfigData->eab;
		numTokens++;
	}
    
	if(ComConfigData->rohc != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_ROHC;
		setComConfigReq->Token[numTokens].value = ComConfigData->rohc;
		numTokens++;
	}

	setComConfigReq->numTokens= numTokens;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_COM_CONFIG_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_SET_COM_CONFIG_REQ), (void*)setComConfigReq);

	return ret;
}
/****************************************************************************************
*  FUNCTION:  DEV_SetLTEModeTxRxReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to set Tx/Rx on LTE for radio tesing
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_SetLTEModeTxRxReq(UINT32 atHandle, CiDevLteTxRxOption option, UINT16 frequency, INT16 power, UINT8 bandwidth)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimSetLteModeTxRxReq                  *SetLteModeTxRxReq=NULL;

	SetLteModeTxRxReq = (CiDevPrimSetLteModeTxRxReq *)utlCalloc(1, sizeof(CiDevPrimSetLteModeTxRxReq));
	if (SetLteModeTxRxReq == NULL)
		return CIRC_FAIL;

	SetLteModeTxRxReq->option = option;
	SetLteModeTxRxReq->freq = frequency;
	SetLteModeTxRxReq->txRxPower = power;
	SetLteModeTxRxReq->bandwidth= bandwidth;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_LTE_MODE_TX_RX_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_SET_LTE_MODE_TX_RX_REQ), (void*)SetLteModeTxRxReq);

	return ret;
}
/****************************************************************************************
*  FUNCTION:  DEV_SetMccMncCcReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to set MccMncCc for country code, operator code and customer code.
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_SetMccMncCcReq(UINT32 atHandle, 
										UINT16 countryCode, 
										UINT16 operCode, 
										UINT8 *customerCode)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimSetMccMncCcReq                  *SetMccMncCcReq = NULL;

	SetMccMncCcReq = (CiDevPrimSetMccMncCcReq *)utlCalloc(1, sizeof(CiDevPrimSetMccMncCcReq));
	
	if (SetMccMncCcReq == NULL)
		return CIRC_FAIL;

	SetMccMncCcReq->countryCode = countryCode;
	SetMccMncCcReq->operCode = operCode;
	SetMccMncCcReq->customerCode[0]= customerCode[0];
	SetMccMncCcReq->customerCode[1]= customerCode[1];
	SetMccMncCcReq->customerCode[2]= customerCode[2];

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_MCC_MNC_CC_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_SET_MCC_MNC_CC_REQ), (void*)SetMccMncCcReq);

	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_GetMccMncCcReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to get MccMncCc for country code, operator code and customer code.
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_GetMccMncCcReq(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
 	CiDevPrimGetMccMncCcReq                  *GetMccMncCcReq = NULL;

	GetMccMncCcReq = (CiDevPrimGetMccMncCcReq *)utlCalloc(1, sizeof(CiDevPrimGetMccMncCcReq));

	if (GetMccMncCcReq == NULL)
		return CIRC_FAIL;
	
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_MCC_MNC_CC_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_MCC_MNC_CC_REQ), (void*)GetMccMncCcReq);

	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_GetRsrpReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to get rsrp, implementation of AT+VZWRSRP?
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_GetRsrpReq(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimGetLteMeasReq          *getLteMeasReq = NULL;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_LTE_MEAS_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, PRI_DEV_PRIM_GET_RSRP_REQ), (void*)getLteMeasReq);

	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_GetRsrq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to get rsrq, implementation of AT+VZWRSRQ?
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_GetRsrqReq(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimGetLteMeasReq          *getLteMeasReq = NULL;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_LTE_MEAS_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, PRI_DEV_PRIM_GET_RSRQ_REQ), (void*)getLteMeasReq);

	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_ReadRFTemperatureReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to read RF temperature, implementation of AT*RFTEMP?
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_ReadRFTemperatureReq(UINT32 atHandle, UINT8 tempType)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimReadRfTemperatureReq *readRfTemperatureReq = NULL;

	readRfTemperatureReq = (CiDevPrimReadRfTemperatureReq *)utlCalloc(1, sizeof(CiDevPrimReadRfTemperatureReq));
	if (readRfTemperatureReq == NULL)
		return CIRC_FAIL;

	readRfTemperatureReq->type = tempType;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_READ_RF_TEMPERATURE_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, tempType), (void*)readRfTemperatureReq);

	return ret;
}
/****************************************************************************************
*  FUNCTION:  DEV_GetLteCoexInfoReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to get LTE Coex Info Req, implementation of AT*LTECOEX?
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_GetLteCoexInfoReq(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimGetLteCoexInfoReq *getLteCoexInfoReq = NULL;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_LTE_COEX_INFO_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_LTE_COEX_INFO_REQ), (void*)getLteCoexInfoReq);

	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_SetLteCoexReportOptionReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to Set LTE Coex Report option Req, implementation of AT*LTECOEX=
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_SetLteCoexReportOptionReq(UINT32 atHandle, UINT8 enable)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimSetLteCoexReportOptionReq *setLteCoexReportOptionReq = NULL;

	setLteCoexReportOptionReq  = (CiDevPrimSetLteCoexReportOptionReq *)utlCalloc(1, sizeof(CiDevPrimSetLteCoexReportOptionReq));
	if (setLteCoexReportOptionReq == NULL)
		return CIRC_FAIL;

	setLteCoexReportOptionReq->enableLteCoexReport = enable;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_LTE_COEX_REPORT_OPTION_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_SET_LTE_COEX_REPORT_OPTION_REQ), (void*)setLteCoexReportOptionReq);

	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_GetSinrReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to Get Sinr Req, implementation of AT*SINR
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_GetSinrReq(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;

	CiDevPrimGetEngmodeInfoReq   *getEngmodeInfoReq = NULL;
	BOOL *pSINRUpdate;

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
		pSINRUpdate = &gSINRUpdate;
	} else {
		pSINRUpdate = &gSINRUpdate_1;
	}
#else
	pSINRUpdate = &gSINRUpdate;
#endif

	*pSINRUpdate = FALSE;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_ENGMODE_INFO_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_SINR_REQ), (void *)getEngmodeInfoReq);

	return ret;
}

/****************************************************************************************
*  FUNCTION:  DEV_GetRssiReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to Get Rssi Req, implementation of AT*RSSI
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_GetRssiReq(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;

	CiDevPrimGetEngmodeInfoReq   *getEngmodeInfoReq = NULL;
	BOOL *pRSSIUpdate;

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
		pRSSIUpdate = &gRSSIUpdate;
	} else {
		pRSSIUpdate = &gRSSIUpdate_1;
	}
#else
	pRSSIUpdate = &gRSSIUpdate;
#endif

	*pRSSIUpdate = FALSE;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_ENGMODE_INFO_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_RSSI_REQ), (void *)getEngmodeInfoReq);

	return ret;
}
#ifndef LTEONLY_THIN

/****************************************************************************************
*  FUNCTION:  DEV_GetWbAmrReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to get WB AMR configuration, implementation of AT*WBAMR=0,XXX
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/

CiReturnCode DEV_GetWbAmrReq(UINT32 atHandle, UINT32 tokens)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimGetComConfigReq          *getComConfigReq = NULL;

	getComConfigReq = (CiDevPrimGetComConfigReq *)utlCalloc(1, sizeof(CiDevPrimGetComConfigReq));
	if (getComConfigReq == NULL)
		return CIRC_FAIL;

	getComConfigReq->tokens = tokens;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_COM_CONFIG_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_COM_CONFIG_REQ), (void*)getComConfigReq);

	return ret;
}
/****************************************************************************************
*  FUNCTION:  DEV_SetWbAmrReq
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to set com configuration, implementation of AT*WBAMR=1,XXX
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_SetWbAmrReq(UINT32 atHandle, UINT32 umtsWbAmr, UINT32 gsmWbAmr)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimSetComConfigReq          *setComConfigReq = NULL;
	UINT8 numTokens = 0;

	setComConfigReq = (CiDevPrimSetComConfigReq *)utlCalloc(1, sizeof(CiDevPrimSetComConfigReq));
	if (setComConfigReq == NULL)
		return CIRC_FAIL;

	if(umtsWbAmr != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_UMTS_WB_AMR;
		setComConfigReq->Token[numTokens].value = umtsWbAmr;
		numTokens++;
	}
	if(gsmWbAmr != 65535)
	{
		setComConfigReq->Token[numTokens].name = CI_DEV_COMCFG_TOKEN_GSM_WB_AMR;
		setComConfigReq->Token[numTokens].value = gsmWbAmr;
		numTokens++;
	}

	setComConfigReq->numTokens= numTokens;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_COM_CONFIG_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_SET_COM_CONFIG_REQ), (void*)setComConfigReq);

	return ret;
}

#endif

/****************************************************************************************
 *  FUNCTION:  DEV_SetIMLConfigReq
 *
 *  PARAMETERS:
 *
 *  DESCRIPTION: Request to set com configuration, implementation of AT*IMLCONFIG=X,XXX
 *
 *  RETURNS: CiReturnCode
 *
 ****************************************************************************************/
CiReturnCode DEV_SetIMLConfigReq(UINT32 atHandle, UINT8 IMLType, int dataLen, char* data)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimSetImlConfigReq *setImlConfigReq = NULL;

	setImlConfigReq = (CiDevPrimSetImlConfigReq *)utlCalloc(1, sizeof(CiDevPrimSetImlConfigReq));
	if (setImlConfigReq == NULL)
		return CIRC_FAIL;

	setImlConfigReq->imlLogType = IMLType;

	if(dataLen != 0)
	{
		setImlConfigReq->cfgDataLen = libConvertHexToNum(data, dataLen, (char *)setImlConfigReq->cfgData);
		DBGMSG("IMLLogType: %d, datalen: %d", setImlConfigReq->imlLogType, setImlConfigReq->cfgDataLen);
	}

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_IMLCONFIG_REQ,
			MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_SET_IMLCONFIG_REQ), (void*)setImlConfigReq);

	return ret;
}

/****************************************************************************************
 *  FUNCTION:  DEV_GetIMLConfigReq
 *
 *  PARAMETERS:
 *
 *  DESCRIPTION: Request to get com configuration, implementation of AT*IMLCONFIG?
 *
 *  RETURNS: CiReturnCode
 *
 ****************************************************************************************/

CiReturnCode DEV_GetIMLConfigReq(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimGetImlConfigReq *getImlConfigReq = NULL;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_IMLCONFIG_REQ,
			MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_IMLCONFIG_REQ), (void*)getImlConfigReq);

	return ret;
}





#ifdef PLATFORM_FOR_PS_LW
CiReturnCode DEV_SetLTEBand(UINT32 atHandle, UINT8 numOfLteBands, int*lteBands)
{


	CiReturnCode ret = CIRC_FAIL;
	UINT8 index=0;
	CiDevPrimSetLteBandOrderReq		  *SetLteBandOrderReq = NULL;
	SetLteBandOrderReq = (CiDevPrimSetLteBandOrderReq *)utlCalloc(1, sizeof(CiDevPrimSetLteBandOrderReq));
	if (SetLteBandOrderReq == NULL)
		return CIRC_FAIL;

	SetLteBandOrderReq->numOfLteBands=numOfLteBands;
	

	DIAG_FILTER(CI, TEL_DEV, DEV_SetLTEBand_1, DIAG_INFORMATION)
	diagPrintf("numOfLteBands: %d" ,SetLteBandOrderReq->numOfLteBands);

	for(index=0;index<numOfLteBands;index++)
	{

		SetLteBandOrderReq->lteBands[index]=lteBands[index];


	}
	
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_LTE_BAND_ORDER_REQ,
	 	MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_SET_LTE_BAND_ORDER_REQ), (void*)SetLteBandOrderReq);

	return ret;
}

CiReturnCode DEV_GetLTEBand(UINT32 atHandle)

{

	CiReturnCode ret = CIRC_FAIL;

	CiDevPrimGetLteBandOrderReq		  *GetLteBandOrderReq = NULL;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_LTE_BAND_ORDER_REQ,
		 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_LTE_BAND_ORDER_REQ), (void*)GetLteBandOrderReq);

	return ret;
}

CiReturnCode DEV_GetCsc_req(UINT32 atHandle)
{
	CiDevPrimGetSalesCodeReq		  *getCgsnReq = NULL;
	CiReturnCode ret = CIRC_FAIL;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_SALES_CODE_REQ,
		 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_SALES_CODE_REQ), (void*)getCgsnReq);

	return ret;

}
#endif

/****************************************************************************************
*  FUNCTION:  DEV_GetOperCfg_req
*
*  PARAMETERS:
*
*  DESCRIPTION: Request to get configure info from modem side
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_GetOperCfg_req(UINT32 atHandle, UINT8 mode, UINT32 val)
{
	CiDevPrimGetOperConfigReq		  *getOperCfgReq= NULL;
	CiReturnCode ret = CIRC_FAIL;
	UINT32 reqId;

	getOperCfgReq = utlCalloc(1, sizeof(CiDevPrimGetOperConfigReq));
	if (getOperCfgReq == NULL)
		return CIRC_FAIL;

	getOperCfgReq->type = mode;
	getOperCfgReq->featureIdOrIndex = val;
	if(getOperCfgReq->type == CI_DEV_GET_SPECIFIC_OPER_CFG)
	{
		/*Since for type CI_DEV_GET_ALL_OPER_CFG, the reqId must be the multiple of CI_DEV_MAX_NUM_FEATURES,
		can't be 1, so for distinguish, use 1 here.*/
		reqId = 1;
	}
	else
	{
		reqId = val;
	}

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_OPER_CONFIG_REQ,
		 MAKE_CI_REQ_HANDLE(atHandle, reqId), (void*)getOperCfgReq);

	return ret;

}


/****************************************************************************************
 *  FUNCTION:  DEV_SetOperCfg_req
 *
 *  PARAMETERS:
 *
 *  DESCRIPTION: Request to set configure info to modem side
 *
 *  RETURNS: CiReturnCode
 *
 ****************************************************************************************/
CiReturnCode DEV_SetOperCfg_req(UINT32 atHandle, CiDevPrimSetOperConfigReq *setOperCfgReq)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimSetOperConfigReq *pSetOperCfgReq;

	pSetOperCfgReq = utlCalloc(1, sizeof(CiDevPrimSetOperConfigReq));
	if (pSetOperCfgReq == NULL)
		return CIRC_FAIL;

	memcpy(pSetOperCfgReq, setOperCfgReq, sizeof(CiDevPrimSetOperConfigReq));

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_OPER_CONFIG_REQ,
			MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_SET_OPER_CONFIG_REQ), (void*)pSetOperCfgReq);

	return ret;

}

CiReturnCode DEV_GetCellInfo(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimGetEngmodeInfoReq   *getEngmodeInfoReq=NULL;

	getEngmodeInfoReq = utlCalloc(1, sizeof(CiDevPrimGetEngmodeInfoReq));

	if (getEngmodeInfoReq == NULL)
		return CIRC_FAIL;

	getEngmodeInfoReq->engmodeEnhanceType = CI_DEV_ENGINEER_MODE_ONESHOT_NCELL_REQUIRED;
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_ENGMODE_INFO_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_CELL_INFO), (void *)getEngmodeInfoReq);
	
	return ret;
}




/************************************************************************************
 * F@: Dev_parseReturnCode - parse return code and show on serial port
 *
 */
void Dev_parseReturnCode(UINT32 atHandle,CiDevRc rc)
{
    switch( rc )
	{
		case CIRC_DEV_SUCCESS:
			ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,NULL);
			break;
		case CIRC_DEV_FAILURE:
			ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_PHONE_FAILURE,NULL);
			break;
		case CIRC_DEV_NO_CONNECTION:
			ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_NO_CONNECTION,NULL);
			break;
		case CIRC_DEV_INVALID_PARAMETER:
			ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_INVALID_PARAM,NULL);
			break;
		case CIRC_DEV_UNKNOWN:
		default:
			ATRESP( atHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
			break;
	}

}

/************************************************************************************
 * F@: SendL1DebugData - send L1DEBUG REQ to SAC
 *
 */
CiReturnCode Dev_L1Debug(UINT32 atHandle, CHAR *data, UINT16 length)
{
	CiReturnCode                        ret = CIRC_FAIL;
    CiDevPrimSetL1DebugReq                 *L1DebugReq = NULL;
    int i=0,len=0;

    //CPUartLogPrintf("enter %s", __FUNCTION__);

	L1DebugReq = utlCalloc(1, sizeof(CiDevPrimSetL1DebugReq));
	if (L1DebugReq == NULL)
		return CIRC_FAIL;

	for(i=0; i<length; i++)
	{
	    if((data[i] >= '0')&&(data[i] <= '9'))
	       L1DebugReq->data[len++] = data[i]-'0';
	    else if((data[i] >= 'a')&&(data[i] <= 'f'))
	       L1DebugReq->data[len++] = data[i]-'a'+10;
	    else if((data[i] >= 'A')&&(data[i] <= 'F'))
	       L1DebugReq->data[len++] = data[i]-'A'+10;
	    else
	    {
            CPUartLogPrintf("%s: input is not support.%d %x %d", __FUNCTION__, i,data[i],data[i]);
	    }
		//CPUartLogPrintf("%s: i=0x%x,data=0x%x", __FUNCTION__, i,L1DebugReq->data[i]);
    }
	L1DebugReq->length= len;
	
	//command id=01 //at*l1debug="01" //TA ( at*l1debug="0001" recommended)
	//command id=03 //at*l1debug="0003XX" //Lte 32K threshold
	//command id=0X //at*l1debug="000XYY" //todo
	if(L1DebugReq->length >= 2)
	{
		for(i=0; i<L1DebugReq->length/2; i++)
		{
			L1DebugReq->data[i] =  (L1DebugReq->data[2*i] << 4) + L1DebugReq->data[2*i + 1];
		}
		L1DebugReq->length= L1DebugReq->length/2;
		
		if( L1DebugReq->length == 1 && L1DebugReq->data[0] == 0x01) //command id=01 //at*l1debug="01" //TA
		{
			L1DebugReq->data[0]=0x00;
			L1DebugReq->data[1]=0x01;
			L1DebugReq->length=2;
		}
		
		if(L1DebugReq->length < CI_DEV_MAX_L1_DEBUG_REQ_LEN)
			memset(&L1DebugReq->data[L1DebugReq->length],0,(CI_DEV_MAX_L1_DEBUG_REQ_LEN - L1DebugReq->length));
	}
	else
		return CIRC_FAIL;
	
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_L1DEBUG_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_DEV_PRIM_SET_L1DEBUG_REQ), (void *)L1DebugReq);

    //CPUartLogPrintf("leave %s", __FUNCTION__);

	return ret;
}

void processL1DebugCnf(UINT32 atHandle, const void *paras)
{
    CiDevPrimSetL1DebugCnf *L1DebugCnf = (CiDevPrimSetL1DebugCnf *)paras;
    Dev_parseReturnCode(atHandle, L1DebugCnf->rc);
}

/****************************************************************
 *  F@: processGetSerialNumIdConf - Process CI cnf msg of AT+CGSN?
 */
static void processGetSerialNumIdConf(UINT32 atHandle, const void *paras)
{
	CiDevPrimGetSerialNumIdCnf *getCgsnCnf = (CiDevPrimGetSerialNumIdCnf *)paras;
	int len=0;
	CHAR imei[18];          /* 15(IMEI) + 2(SV) + 1(\0) */
	CHAR resImei[50];       /* large enough for IMEI response */

	memset(imei, 0, sizeof(imei));
	memset(resImei, 0, sizeof(resImei));
	
	if (getCgsnCnf->rc == CIRC_DEV_SUCCESS)
	{

		if (getCgsnCnf->serialNumStr.len > 17)
			len = 17;
		else
			len = getCgsnCnf->serialNumStr.len;
		memcpy(imei, getCgsnCnf->serialNumStr.valStr, len);
		imei[len] = '\0';               /* in case IMEI not end with \0 */
		
		
		if(len > 14)
			sprintf((char *)resImei, "\"%s\"", imei);
		else
			sprintf((char *)resImei, "\"%s%c\"", imei, DEV_GetCD(imei));

		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)resImei);
	}
	else
	{
		checkDevRet(atHandle, getCgsnCnf->rc);
	}


	return;
}






/****************************************************************
 *	F@: processSetEngModeIndicatorOptionConf - Process CI cnf msg of AT+EEMOPT=
 */
static void processSetEngModeReportOptionConf(UINT32 atHandle, const void *paras)
{
	CiDevPrimSetEngmodeRepOptCnf* setEngmodeRepOptCnf = (CiDevPrimSetEngmodeRepOptCnf *)paras;

	
	if (setEngmodeRepOptCnf->rc == CIRC_DEV_SUCCESS)
	{
		#ifdef QUEC_ENGINEER_OUTPUT
		if(CHECK_BIT_SET(network_infor_bitmsk ,QENG_ALL_INFO))
		{
			
			CPUartLogPrintf("%s,%d,get sys info",__func__,__LINE__);
	    	MM_GetSysInfo(atHandle);
		}
		else
		{
			ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
		}

		#else
			ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
		#endif
	}
	else
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
	}
	return;
}
/****************************************************************
 *  F@: processSetSVConf - Process CI cnf msg of
 */
static void processSetSVConf(UINT32 atHandle, const void *paras)
{
	CiDevPrimSetSvCnf* setSVCnf = (CiDevPrimSetSvCnf *)paras;

	if (setSVCnf->rc == CIRC_DEV_SUCCESS)
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
	}
	else
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);

	return;
}

/****************************************************************
 *  F@: processGetSVConf - Process CI cnf msg of
 */
static void processGetSVConf(UINT32 atHandle, const void *paras)
{
	CHAR temp[4];
	CHAR resImei[50];       /* large enough for IMEI response */
	CiDevPrimGetSvCnf* getSVCnf = (CiDevPrimGetSvCnf *)paras;

	memset(temp, 0, sizeof(temp));
	memset(resImei, 0, sizeof(resImei));

	if (getSVCnf->rc == CIRC_DEV_SUCCESS)
	{
		resImei[0] = '\0';
		memset(temp, 0, sizeof(temp));
		if(getSVCnf->SVDigits.len > 2)
			memcpy(temp, getSVCnf->SVDigits.val, 2);
		else
			memcpy(temp, getSVCnf->SVDigits.val, getSVCnf->SVDigits.len);

		sprintf((char *)resImei, "*CGSN: \"%s\"", temp);

		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)resImei);
	}
	else
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);

	return;
}



 #ifdef QUECTEL_AT_QCFG_SUPPORT
 UINT8 quec_match_mode_srdomain(UINT8 *net_mode, UINT8 *pref_mode, UINT8 *srdomain)
 {
    
	UINT8 ret=1;
	Network_Info_Log("net_mode=%d,pref_mode=%d,srdomain=%d",*net_mode,*pref_mode,*srdomain);
    if( *srdomain == 0)//set cs only we need to blind LTE
    {
        switch (*net_mode)
    	{
    		case CI_DEV_NW_GSM_LTE:
    			*net_mode = CI_DEV_NW_GSM;
    			break;
    		case CI_DEV_NW_UMTS_LTE:
    			*net_mode = CI_DEV_NW_UMTS;
    			break;
    		case CI_DEV_NW_GSM_UMTS_LTE:
    			*net_mode = CI_DEV_NW_GSM_UMTS;
    			break;
    		case CI_DEV_NW_LTE:
    			Network_Info_Log("ERROR CS ONLY IN LTE ONLY MODE!!!!!!!!");
				ret=0;
    			break;
    		default:
    			//do nothing
    			break;
    	}
		//set cs only we need to blind pref mode LTE to net mode
		if(*pref_mode == CI_DEV_NW_LTE)
		{
			*pref_mode = *net_mode;
		}
    }
    else 
    {
       // *net_mode=QuecNetModePref.net_mode;
	   // *pref_mode=QuecNetModePref.pref_mode;
    }
	Network_Info_Log("net_mode=%d,pref_mode=%d,srdomain=%d",*net_mode,*pref_mode,*srdomain);
    return ret;       
}
    
    void quec_map_nwscanseq2netmode_modepref(QUEC_NWSCANSEQ nwscanseq, UINT8 *netmode, UINT8 *mode_pref)
    {
           
        switch (nwscanseq)
        {
            case QUEC_SEQ_AUTO:
#if QUEC_LTE_SUPPORT
                *netmode = CI_DEV_NW_GSM_UMTS_LTE;
                *mode_pref=CI_DEV_NW_GSM_UMTS_LTE;
#else
                *netmode = CI_DEV_NW_GSM_UMTS;
                *mode_pref=CI_DEV_NW_GSM_UMTS;
#endif
                break;
            case QUEC_SEQ_L_W_G:
                *netmode = CI_DEV_NW_GSM_UMTS_LTE;
                *mode_pref=CI_DEV_NW_LTE;
                break;
            case QUEC_SEQ_G:
                *netmode = CI_DEV_NW_GSM;
                *mode_pref=CI_DEV_NW_GSM;
                break;
            case QUEC_SEQ_W:
                *netmode = CI_DEV_NW_UMTS;
                *mode_pref=CI_DEV_NW_UMTS;
                break;
            case QUEC_SEQ_L:
                *netmode = CI_DEV_NW_LTE;
                *mode_pref=CI_DEV_NW_LTE;
                break;
           case QUEC_SEQ_W_G_L:
                *netmode = CI_DEV_NW_GSM_UMTS_LTE;
                *mode_pref=CI_DEV_NW_UMTS;
                break;   
           case QUEC_SEQ_G_W_L:
                *netmode = CI_DEV_NW_GSM_UMTS_LTE;
                *mode_pref=CI_DEV_NW_GSM;
                break;   
           case QUEC_SEQ_L_W:
                *netmode = CI_DEV_NW_UMTS_LTE;
                *mode_pref=CI_DEV_NW_LTE;
                break;   
           case QUEC_SEQ_L_G:
                *netmode = CI_DEV_NW_GSM_LTE;
                *mode_pref=CI_DEV_NW_LTE;
                break;   
           case QUEC_SEQ_W_G:
                *netmode = CI_DEV_NW_GSM_UMTS;
                *mode_pref=CI_DEV_NW_UMTS;
                break;   
           case QUEC_SEQ_W_L:
                *netmode = CI_DEV_NW_UMTS_LTE;
                *mode_pref=CI_DEV_NW_UMTS;
                break;
           case QUEC_SEQ_G_L:
                *netmode = CI_DEV_NW_GSM_LTE;
                *mode_pref=CI_DEV_NW_GSM;
                break;   
           case QUEC_SEQ_G_W:
                *netmode = CI_DEV_NW_GSM_UMTS;
                *mode_pref=CI_DEV_NW_GSM;
                break;
            default:
#if QUEC_LTE_SUPPORT
                *netmode = CI_DEV_NW_GSM_UMTS_LTE;
                *mode_pref=CI_DEV_NW_GSM_UMTS_LTE;
#else
                *netmode = CI_DEV_NW_GSM_UMTS;
                *mode_pref=CI_DEV_NW_GSM_UMTS;
#endif
                Network_Info_Log("quec_map_nwscanseq2netmode_modepref:ERROR!!!!!!!!");
                break;
        }

        Network_Info_Log("quec_map_nwscanseq2netmode_modepref:netmode=%d,mode_pref=%d",*netmode,*mode_pref);
        return;         
     }
     void quec_map_netmode_modepref2nwscanseq(UINT8* nwscanseq, UINT8 netmode, UINT8 mode_pref)
     {
         
       switch (netmode)
       {
           case CI_DEV_NW_GSM_UMTS_LTE:
                switch (mode_pref)
                {
                    case CI_DEV_NW_LTE:
                         *nwscanseq=QUEC_SEQ_L_W_G;
                         break;
                    case CI_DEV_NW_GSM:
                         *nwscanseq=QUEC_SEQ_G_W_L;
                         break;
                    case CI_DEV_NW_UMTS:
                         *nwscanseq=QUEC_SEQ_W_G_L;
                         break;
                    default:
                         *nwscanseq=QUEC_SEQ_AUTO;
                         break;
                }         
               break;
           case CI_DEV_NW_GSM_UMTS:
#if QUEC_LTE_SUPPORT
               if(mode_pref==CI_DEV_NW_GSM)
                    *nwscanseq=QUEC_SEQ_G_W;
               else
                    *nwscanseq=QUEC_SEQ_W_G; 
#else
               if(mode_pref==CI_DEV_NW_GSM)
                    *nwscanseq=QUEC_SEQ_G_W;
               else if(mode_pref==CI_DEV_NW_UMTS)
                    *nwscanseq=QUEC_SEQ_W_G; 
			   else
			   		*nwscanseq=QUEC_SEQ_AUTO;
#endif
               break;
           case CI_DEV_NW_GSM_LTE:
               if(mode_pref==CI_DEV_NW_GSM)
                    *nwscanseq=QUEC_SEQ_G_L;
               else
                    *nwscanseq=QUEC_SEQ_L_G; 
               break;
           case CI_DEV_NW_UMTS_LTE:
               if(mode_pref==CI_DEV_NW_UMTS)
                    *nwscanseq=QUEC_SEQ_W_L;
               else
                    *nwscanseq=QUEC_SEQ_L_W; 
               break;
           case CI_DEV_NW_LTE:
               *nwscanseq=QUEC_SEQ_L;
               break;
           case CI_DEV_NW_GSM:
               *nwscanseq=QUEC_SEQ_G;
               break;
           case CI_DEV_NW_UMTS:
               *nwscanseq=QUEC_SEQ_W;
               break;
           default:
              *nwscanseq=QUEC_SEQ_AUTO;
               Network_Info_Log("quec_map_netmode_modepref2nwscanseq:ERROR!!!!!!!!");
               break;
      }
      Network_Info_Log("quec_map_netmode_modepref2nwscanseq:netmode=%d,mode_pref=%d,nwscanseq=%d",netmode,mode_pref,*nwscanseq);
      return;         
   }
    
typedef struct
{
    UINT64               quec_band;
    UINT32               asr_band;
}quectel_band_type;

 quectel_band_type  quectel_band_tbl_gsm[] =
{
    {QUEC_BAND_GSM_900, ASR_BAND_EGSM_900},
    {QUEC_BAND_GSM_1800, ASR_BAND_GSM_1800},
    {QUEC_BAND_GSM_850, ASR_BAND_GSM_850},
    {QUEC_BAND_GSM_1900, ASR_BAND_GSM_1900}
   
};

quectel_band_type  quectel_band_tbl_umts[] =
{
     {QUEC_BAND_WCDMA_2100, ASR_BAND_UMTS_BAND1},
     {QUEC_BAND_WCDMA_1900, ASR_BAND_UMTS_BAND2},
     {QUEC_BAND_WCDMA_850, ASR_BAND_UMTS_BAND5},
     {QUEC_BAND_WCDMA_900, ASR_BAND_UMTS_BAND8},
     {QUEC_BAND_WCDMA_800, ASR_BAND_UMTS_BAND6},
     {QUEC_BAND_WCDMA_1700, ASR_BAND_UMTS_BAND4}
      
};

 quectel_band_type  quectel_band_tbl_lteh[] =
 {
 	  {QUEC_BAND_LTE_BAND33, ASR_BAND_LTE_BAND33},
 	  {QUEC_BAND_LTE_BAND34, ASR_BAND_LTE_BAND34},
      {QUEC_BAND_LTE_BAND38, ASR_BAND_LTE_BAND38},
      {QUEC_BAND_LTE_BAND39, ASR_BAND_LTE_BAND39},
      {QUEC_BAND_LTE_BAND40, ASR_BAND_LTE_BAND40},
      {QUEC_BAND_LTE_BAND41, ASR_BAND_LTE_BAND41}
         
 };

 quectel_band_type  quectel_band_tbl_lte_ext[] =
 {
 	  {QUEC_BAND_LTE_BAND65, ASR_BAND_LTE_BAND65},
 	  {QUEC_BAND_LTE_BAND66, ASR_BAND_LTE_BAND66},
 	  {QUEC_BAND_LTE_BAND72, ASR_BAND_LTE_BAND72}
         
 };

void quec_map_Quecband2Asrband(UINT64 quec_gw_band,UINT64 quec_lte_band,UINT64 quec_lte_band_ext,UINT32 *asr_gsm_band,UINT32 *asr_umts_band,UINT32 *asr_lte_band_h,UINT32 *asr_lte_band_l,UINT32 *asr_lte_band_ext)
{

    Network_Info_Log("quec_map_Quecband2Asrband:quec_gw_band=0x%llx,quec_lte_band=0x%llx,0x%llx",quec_gw_band,quec_lte_band, quec_lte_band_ext);
    UINT8 index=0;
    for(index = 0; index < QUEC_ARR_SIZE(quectel_band_tbl_gsm); index++)
    {
       if((quec_gw_band & quectel_band_tbl_gsm[index].quec_band) != 0)
       {
           *asr_gsm_band |= quectel_band_tbl_gsm[index].asr_band;
       }
    }
    
    for(index = 0; index < QUEC_ARR_SIZE(quectel_band_tbl_umts); index++)
    {
       if((quec_gw_band & quectel_band_tbl_umts[index].quec_band) != 0)
       {
           *asr_umts_band |= quectel_band_tbl_umts[index].asr_band;
       }
    }
    
    for(index = 0; index < QUEC_ARR_SIZE(quectel_band_tbl_lteh); index++)
    {
       if((quec_lte_band & quectel_band_tbl_lteh[index].quec_band) != 0)
       {
           *asr_lte_band_h |= quectel_band_tbl_lteh[index].asr_band;
       }
    }
    
    *asr_lte_band_l |= quec_lte_band&0xFFFFFFFF;//band1-28
    
    for(index = 0; index < QUEC_ARR_SIZE(quectel_band_tbl_lte_ext); index++)
    {
       if((quec_lte_band_ext & quectel_band_tbl_lte_ext[index].quec_band) != 0)
       {
           *asr_lte_band_ext |= quectel_band_tbl_lte_ext[index].asr_band;
       }
    }
    
    
    Network_Info_Log("quec_map_Quecband2Asrband:gsm_band=0x%x,umts_band=0x%x,lte_band_h=0x%x,lte_band_l=0x%x,lte_band_ext=0x%x",*asr_gsm_band,*asr_umts_band,*asr_lte_band_h,*asr_lte_band_l, asr_lte_band_ext);
    return;         
}  
 

void quec_map_AsrbandQuecband(UINT64 *quec_gw_band,UINT64 *quec_lte_band,UINT64 *quec_lte_band_ext,UINT32 asr_gsm_band,UINT32 asr_umts_band,UINT32 asr_lte_band_h,UINT32 asr_lte_band_l,UINT32 asr_lte_band_ext)
{

    UINT8 index=0;
    for(index = 0; index < QUEC_ARR_SIZE(quectel_band_tbl_gsm); index++)
    {
       if((asr_gsm_band & quectel_band_tbl_gsm[index].asr_band) != 0)
       {
           *quec_gw_band |= quectel_band_tbl_gsm[index].quec_band;
       }
    }
    
    for(index = 0; index < QUEC_ARR_SIZE(quectel_band_tbl_umts); index++)
    {
       if((asr_umts_band& quectel_band_tbl_umts[index].asr_band) != 0)
       {
           *quec_gw_band |= quectel_band_tbl_umts[index].quec_band;
       }
    }
    
    for(index = 0; index < QUEC_ARR_SIZE(quectel_band_tbl_lteh); index++)
    {
       if((asr_lte_band_h& quectel_band_tbl_lteh[index].asr_band) != 0)
       {
           *quec_lte_band |= quectel_band_tbl_lteh[index].quec_band;
       }
    }
    
    *quec_lte_band |=asr_lte_band_l;
    
    for(index = 0; index < QUEC_ARR_SIZE(quectel_band_tbl_lte_ext); index++)
    {
       if((asr_lte_band_ext& quectel_band_tbl_lte_ext[index].asr_band) != 0)
       {
           *quec_lte_band_ext |= quectel_band_tbl_lte_ext[index].quec_band;
       }
    }
    
    
    Network_Info_Log("quec_map_AsrbandQuecband:gw_band=0x%llx,lte_band=0x%llx,0x%llx", *quec_gw_band, *quec_lte_band, *quec_lte_band_ext);
    return;         
}  

UINT8 quec_mode_check(QuecNetModeCfgType *p_quec_net_cfg)
{
    UINT8 mode_chk = p_quec_net_cfg->net_mode;
    UINT8 prefer_mode_chk = p_quec_net_cfg->pref_mode;
    UINT8 srv_domain_chk = p_quec_net_cfg->service_domain;
    if (quec_match_mode_srdomain(&mode_chk, &prefer_mode_chk, &srv_domain_chk) == 0)
    {
        Network_Info_Log("ERROR invalid mode or servicedomain!!!!!!!!");
        return -1;
    }

	// connor 2019/01/25  return error when ipnut invalid a mode which the band is not support
	mode_chk = quec_match_nwmode_with_band(mode_chk);
	prefer_mode_chk = quec_match_nwmode_with_band(prefer_mode_chk);

	if (mode_chk == 0xff || prefer_mode_chk == 0xff)
	{
		Network_Info_Log(" mode set not match band config %d %d", mode_chk, prefer_mode_chk);
		return -1;
	}
    
    //we need to check nw mode and prefer mode, to ensure the prefer mode is the subset of nw mode
    //and prefer mode should be single mode
    switch (mode_chk)
    {
        case CI_DEV_NW_GSM:
        case CI_DEV_NW_UMTS:
        case CI_DEV_NW_LTE:
            if (mode_chk != prefer_mode_chk)
            {
		        Network_Info_Log("nw/prefer mode not match %d %d, update prefer as nw mode", mode_chk, prefer_mode_chk);
                prefer_mode_chk = mode_chk;
            }
            break;
        case CI_DEV_NW_GSM_UMTS:
            if ((mode_chk != prefer_mode_chk) && (CI_DEV_NW_GSM != prefer_mode_chk) && (CI_DEV_NW_UMTS != prefer_mode_chk))
            {
		        Network_Info_Log("nw/prefer mode not match %d %d, update prefer as nw mode", mode_chk, prefer_mode_chk);
                prefer_mode_chk = mode_chk;
            }
            break;
        case CI_DEV_NW_GSM_LTE:
            if ((mode_chk != prefer_mode_chk) && (CI_DEV_NW_GSM != prefer_mode_chk) && (CI_DEV_NW_LTE != prefer_mode_chk))
            {
		        Network_Info_Log("nw/prefer mode not match %d %d, update prefer as nw mode", mode_chk, prefer_mode_chk);
                prefer_mode_chk = mode_chk;
            }
            break;
        case CI_DEV_NW_UMTS_LTE:
            if ((mode_chk != prefer_mode_chk) && (CI_DEV_NW_UMTS != prefer_mode_chk) && (CI_DEV_NW_LTE != prefer_mode_chk))
            {
		        Network_Info_Log("nw/prefer mode not match %d %d, update prefer as nw mode", mode_chk, prefer_mode_chk);
                prefer_mode_chk = mode_chk;
            }
            break;
        case CI_DEV_NW_GSM_UMTS_LTE:
            if ((mode_chk != prefer_mode_chk) && (CI_DEV_NW_GSM != prefer_mode_chk) && (CI_DEV_NW_UMTS != prefer_mode_chk) && (CI_DEV_NW_LTE != prefer_mode_chk))
            {
		        Network_Info_Log("nw/prefer mode not match %d %d, update prefer as nw mode", mode_chk, prefer_mode_chk);
                prefer_mode_chk = mode_chk;
            }
            break;
        default:
		    Network_Info_Log("nw/prefer mode not match %d %d: nw mode is wrong!", mode_chk, prefer_mode_chk);
            return -1;
    }
    
    p_quec_net_cfg->net_mode = mode_chk;
    p_quec_net_cfg->pref_mode = prefer_mode_chk;
	//if the mode is valid, then to save it
	return quec_update_mode_pref(p_quec_net_cfg);
}

void quec_processGetBandModeConf(UINT32 atHandle, const void *paras)
{
	CiDevPrimGetBandModeCnf* getBandModeCnf = (CiDevPrimGetBandModeCnf *)paras;
	char bandBuf[100];
    UINT8 mode_check_ret = -1;
    QuecNetModeCfgType  quec_net_cfg_toWrite = {0};
	
    Network_Info_Log("network mode:%d, prefer:%d ,srdomain:%d,roaming:%d,result=%d,bandPriority=%d,isLteDualLink=%d,qcfg_cmd_type_bitmask=%x",
        getBandModeCnf->networkMode, getBandModeCnf->preferredMode,getBandModeCnf->srvDomain,
        getBandModeCnf->roamingConfig,getBandModeCnf->result,getBandModeCnf->bandPriorityFlag, getBandModeCnf->isLteDualLink,qcfg_cmd_type_bitmask);
   
    Network_Info_Log("GSM:0x%x, UMTS:0x%x ,EUTRANH:0x%x,EUTRANL:0x%x,EUTRANExt=%x",
               getBandModeCnf->GSMBandMode, getBandModeCnf->UMTSBandMode,getBandModeCnf->EUTRANBandModeH,getBandModeCnf->EUTRANBandModeL,getBandModeCnf->EUTRANBandModeExt);

	if(getBandModeCnf->result == CIRC_DEV_SUCCESS)
	{
		if(getBandModeCnf->isLteDualLink)
		{
			switch(getBandModeCnf->networkMode)
			{
			case CI_DEV_NW_GSM_LTE:
			case CI_DEV_NW_UMTS_LTE:
			case CI_DEV_NW_GSM_UMTS_LTE:
				break;
			default:
                qcfg_cmd_type_bitmask=0;
                Network_Info_Log("isLteDualLink=%d networkMode=%d ERROR!", getBandModeCnf->isLteDualLink, getBandModeCnf->networkMode);
				ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
				return;
			}
		}
        
		if (getBandModeCnf->networkMode == CI_DEV_NW_GSM)
		{
		}
		else if (getBandModeCnf->networkMode == CI_DEV_NW_UMTS)
		{
		}
		else if (getBandModeCnf->networkMode == CI_DEV_NW_GSM_UMTS)
		{
		}
        else if(getBandModeCnf->networkMode == CI_DEV_NW_LTE)
	    {
	    }
	    else if(getBandModeCnf->networkMode == CI_DEV_NW_GSM_UMTS_LTE)
	    {
	    }
	    else if(getBandModeCnf->networkMode == CI_DEV_NW_UMTS_LTE)
	    {
	    }
	    else if(getBandModeCnf->networkMode == CI_DEV_NW_GSM_LTE)
	    {
	    }
		else
		{
            Network_Info_Log("networkMode=%d,bit=0x%X ERROR!", getBandModeCnf->networkMode, qcfg_cmd_type_bitmask);
            qcfg_cmd_type_bitmask=0;
		    ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
            return;
		}
		
		memcpy(&quec_net_cfg_toWrite, &QuecNetModeCfg, sizeof(QuecNetModeCfgType));
        Network_Info_Log("NetModeCfg: %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", QuecNetModeCfg.net_mode,
                    QuecNetModeCfg.pref_mode, QuecNetModeCfg.gprsattach, QuecNetModeCfg.service_domain, QuecNetModeCfg.gsm_band,
                    QuecNetModeCfg.umts_band, QuecNetModeCfg.lte_band_h, QuecNetModeCfg.lte_band_l, QuecNetModeCfg.lte_band_ext,
                    QuecNetModeCfg.roamservice, QuecNetModeCfg.update_flag, QuecNetModeCfg.operation, QuecNetModeCfg.atp_index);
        
        if(CHECK_BIT_SET(qcfg_cmd_type_bitmask ,QCFG_GPRSATTACH_GET))
        {
            sprintf((char *)bandBuf, "+QCFG: \"gprsattach\",%d\r\n", (getBandModeCnf->srvDomain==0)? 0:1);
	        ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, bandBuf);
            BIT_CLR(qcfg_cmd_type_bitmask,QCFG_GPRSATTACH_GET);
        }
        else if(CHECK_BIT_SET(qcfg_cmd_type_bitmask ,QCFG_GPRSATTACH_SET))
        {
            BIT_CLR(qcfg_cmd_type_bitmask,QCFG_GPRSATTACH_SET);
            if(getBandModeCnf->srvDomain ==1 && qcfg_gprsattach==0) // ps only,set to cs only so return error 
            {
                Network_Info_Log("GPRSATTACH_SET error ps only,set to cs only ");
				ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                return;
            }
			else if((getBandModeCnf->srvDomain ==0 && qcfg_gprsattach==0) 
                ||(getBandModeCnf->srvDomain !=0 && qcfg_gprsattach==1))
            {
                Network_Info_Log("GPRSATTACH_SET just return : srvDomain=%d,qcfg_gprsattach=%d",
                    getBandModeCnf->srvDomain,qcfg_gprsattach);
				ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
                return;
            }

            UINT8 quec_service_domain = (qcfg_gprsattach==0) ? 0:2;
            
			quectel_read_urc_ind_flag(QUECTEL_URC_ACTCHGRPT_IND);

            quec_net_cfg_toWrite.gprsattach = qcfg_gprsattach;
            quec_net_cfg_toWrite.service_domain = quec_service_domain;
            quec_net_cfg_toWrite.operation = QCFG_GPRSATTACH_SET;
            quec_net_cfg_toWrite.atp_index =  GET_ATP_INDEX(atHandle);
            
            mode_check_ret = quec_mode_check(&quec_net_cfg_toWrite);
            if (1 == mode_check_ret)
            {
    			quectel_read_urc_ind_flag(QUECTEL_URC_ACTCHGRPT_IND);
                qcfg_service_domain = quec_service_domain;
    	        DEV_SetBandModeReq(atHandle, quec_net_cfg_toWrite.net_mode, quec_net_cfg_toWrite.pref_mode,
                    getBandModeCnf->GSMBandMode, getBandModeCnf->UMTSBandMode, getBandModeCnf->EUTRANBandModeH,   
                    getBandModeCnf->EUTRANBandModeL, getBandModeCnf->roamingConfig, qcfg_service_domain, getBandModeCnf->bandPriorityFlag, 0, getBandModeCnf->EUTRANBandModeExt);
            }
            else if (0 == mode_check_ret)
            {
		        ATRESP( atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
                return;
            }
            else
            {
		        ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                return;
            }            
        }
        else if(CHECK_BIT_SET(qcfg_cmd_type_bitmask ,QCFG_SERVICEDOMIAN_GET))
        {
            sprintf((char *)bandBuf, "+QCFG: \"servicedomain\",%d\r\n", getBandModeCnf->srvDomain);
	        ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, bandBuf);
            BIT_CLR(qcfg_cmd_type_bitmask,QCFG_SERVICEDOMIAN_GET);
        }
        else if(CHECK_BIT_SET(qcfg_cmd_type_bitmask ,QCFG_SERVICEDOMIAN_SET))
        {
            BIT_CLR(qcfg_cmd_type_bitmask,QCFG_SERVICEDOMIAN_SET);
            
            quec_net_cfg_toWrite.service_domain = qcfg_service_domain;
            quec_net_cfg_toWrite.operation = QCFG_SERVICEDOMIAN_SET;
            quec_net_cfg_toWrite.atp_index =  GET_ATP_INDEX(atHandle);
            
            mode_check_ret = quec_mode_check(&quec_net_cfg_toWrite);
            if (1 == mode_check_ret)
            {
    	        DEV_SetBandModeReq(atHandle, quec_net_cfg_toWrite.net_mode, quec_net_cfg_toWrite.pref_mode,
                    getBandModeCnf->GSMBandMode, getBandModeCnf->UMTSBandMode, getBandModeCnf->EUTRANBandModeH,   
                    getBandModeCnf->EUTRANBandModeL, getBandModeCnf->roamingConfig, qcfg_service_domain, getBandModeCnf->bandPriorityFlag, 0, getBandModeCnf->EUTRANBandModeExt);
            }
            else if (0 == mode_check_ret)
            {
		        ATRESP( atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
                return;
            }
            else
            {
		        ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                return;
            }            
        }
        else if(CHECK_BIT_SET(qcfg_cmd_type_bitmask ,QCFG_ROAMSERVICE_GET))
        {
            sprintf((char *)bandBuf, "+QCFG: \"roamservice\",%d\r\n", getBandModeCnf->roamingConfig+1);
	        ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, bandBuf);
            BIT_CLR(qcfg_cmd_type_bitmask,QCFG_ROAMSERVICE_GET);
        }
        else if(CHECK_BIT_SET(qcfg_cmd_type_bitmask ,QCFG_ROAMSERVICE_SET))
        {
            BIT_CLR(qcfg_cmd_type_bitmask,QCFG_ROAMSERVICE_SET);
            
            quec_net_cfg_toWrite.service_domain = qcfg_roamservice;
            quec_net_cfg_toWrite.operation = QCFG_ROAMSERVICE_SET;
            quec_net_cfg_toWrite.atp_index =  GET_ATP_INDEX(atHandle);
            
            mode_check_ret = quec_mode_check(&quec_net_cfg_toWrite);
            if (1 == mode_check_ret)
            {
                DEV_SetBandModeReq(atHandle, quec_net_cfg_toWrite.net_mode, quec_net_cfg_toWrite.pref_mode,
                    getBandModeCnf->GSMBandMode, getBandModeCnf->UMTSBandMode, getBandModeCnf->EUTRANBandModeH,   
                    getBandModeCnf->EUTRANBandModeL, qcfg_roamservice-1, getBandModeCnf->srvDomain, getBandModeCnf->bandPriorityFlag, 0, getBandModeCnf->EUTRANBandModeExt);
            }
            else if (0 == mode_check_ret)
            {
		        ATRESP( atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
                return;
            }
            else
            {
		        ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                return;
            }
        }
        else if(CHECK_BIT_SET(qcfg_cmd_type_bitmask ,QCFG_NWSCANMODE_GET))
        {
            UINT8 nw_scanmode=QUEC_AUTO;
            if(CI_DEV_NW_GSM==getBandModeCnf->networkMode)
                nw_scanmode=QUEC_GSM; 
            else if(CI_DEV_NW_UMTS==getBandModeCnf->networkMode)
                nw_scanmode=QUEC_WCDMA;
            else if(CI_DEV_NW_LTE==getBandModeCnf->networkMode)
                nw_scanmode=QUEC_LTE;
            else if(CI_DEV_NW_GSM_UMTS_LTE==getBandModeCnf->networkMode)
                nw_scanmode=QUEC_AUTO;
            sprintf((char *)bandBuf, "+QCFG: \"nwscanmode\",%d\r\n", nw_scanmode);
	        ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, bandBuf);
            BIT_CLR(qcfg_cmd_type_bitmask,QCFG_NWSCANMODE_GET);
        }
        else if(CHECK_BIT_SET(qcfg_cmd_type_bitmask ,QCFG_NWSCANMODE_SET))
        {
            BIT_CLR(qcfg_cmd_type_bitmask,QCFG_NWSCANMODE_SET);
            quec_net_cfg_toWrite.net_mode = qcfg_nwscanmode;
            quec_net_cfg_toWrite.pref_mode = qcfg_nwscanmode;
			if (qcfg_nwscanmode == quec_match_nwmode_with_band(CI_DEV_NW_GSM_UMTS_LTE))
            {
#if !QUEC_LTE_SUPPORT
			    //jensen.fang: if atuo mode, change prefer as WCDMA first.
                quec_net_cfg_toWrite.pref_mode = CI_DEV_NW_UMTS;
#else
			    //jensen.fang: if atuo mode, change prefer as LTE first.
                quec_net_cfg_toWrite.pref_mode = CI_DEV_NW_LTE;
#endif
            }
            quec_net_cfg_toWrite.operation = QCFG_NWSCANMODE_SET;
            quec_net_cfg_toWrite.atp_index =  GET_ATP_INDEX(atHandle);
            
            mode_check_ret = quec_mode_check(&quec_net_cfg_toWrite);
            if (1 == mode_check_ret)
            {
    			DEV_SetBandModeReq(atHandle, quec_net_cfg_toWrite.net_mode, quec_net_cfg_toWrite.pref_mode,
                    getBandModeCnf->GSMBandMode, getBandModeCnf->UMTSBandMode, getBandModeCnf->EUTRANBandModeH,   
                    getBandModeCnf->EUTRANBandModeL, getBandModeCnf->roamingConfig, getBandModeCnf->srvDomain, getBandModeCnf->bandPriorityFlag, 0, getBandModeCnf->EUTRANBandModeExt);
            }
            else if (0 == mode_check_ret)
            {
		        ATRESP( atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
                return;
            }
            else
            {
		        ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                return;
            }
        }
		 else if(CHECK_BIT_SET(qcfg_cmd_type_bitmask ,QCFG_NWSCANMODEEX_GET))
        {
            UINT8 nw_scanmode=QUEC_AUTO;
            nw_scanmode=quec_asrmode2_nwscanmodeex(getBandModeCnf->networkMode);
			if(nw_scanmode != 0xff)
            {
            	sprintf((char *)bandBuf, "+QCFG: \"nwscanmodeex\",%d\r\n", nw_scanmode);
				ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, bandBuf);
			}
			else
			{
				Network_Info_Log(":ERROR invalid nwscanmodeex!!!!!!!!");
				ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
			}
	        
            BIT_CLR(qcfg_cmd_type_bitmask,QCFG_NWSCANMODEEX_GET);
        }
        else if(CHECK_BIT_SET(qcfg_cmd_type_bitmask ,QCFG_NWSCANMODEEX_SET))
        {
            BIT_CLR(qcfg_cmd_type_bitmask,QCFG_NWSCANMODEEX_SET);;

            quec_net_cfg_toWrite.net_mode = qcfg_nwscanmode;
            quec_net_cfg_toWrite.pref_mode = qcfg_nwscanmodeex_prefmode;
            quec_net_cfg_toWrite.operation = QCFG_NWSCANMODEEX_SET;
            quec_net_cfg_toWrite.atp_index =  GET_ATP_INDEX(atHandle);
            
            mode_check_ret = quec_mode_check(&quec_net_cfg_toWrite);
            if (1 == mode_check_ret)
            {
    			DEV_SetBandModeReq(atHandle, quec_net_cfg_toWrite.net_mode, quec_net_cfg_toWrite.pref_mode,
                    getBandModeCnf->GSMBandMode, getBandModeCnf->UMTSBandMode, getBandModeCnf->EUTRANBandModeH,   
                    getBandModeCnf->EUTRANBandModeL, getBandModeCnf->roamingConfig, getBandModeCnf->srvDomain, getBandModeCnf->bandPriorityFlag, 0, getBandModeCnf->EUTRANBandModeExt);
            }
            else if (0 == mode_check_ret)
            {
		        ATRESP( atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
                return;
            }
            else
            {
		        ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                return;
            }
        }
        else if(CHECK_BIT_SET(qcfg_cmd_type_bitmask ,QCFG_NWSCANSEQ_GET))
        {
            UINT8 nw_scanseq=QUEC_SEQ_AUTO;
            quec_map_netmode_modepref2nwscanseq(&nw_scanseq,getBandModeCnf->networkMode,getBandModeCnf->preferredMode);
            sprintf((char *)bandBuf, "+QCFG: \"nwscanseq\",%d\r\n", nw_scanseq);
	        ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, bandBuf);
            BIT_CLR(qcfg_cmd_type_bitmask,QCFG_NWSCANSEQ_GET);
        }
        else if(CHECK_BIT_SET(qcfg_cmd_type_bitmask ,QCFG_NWSCANSEQ_SET))
        {
            BIT_CLR(qcfg_cmd_type_bitmask,QCFG_NWSCANSEQ_SET);
			
			quec_map_nwscanseq2netmode_modepref(qcfg_nwscanseq, &(quec_net_cfg_toWrite.net_mode), &(quec_net_cfg_toWrite.pref_mode));
            quec_net_cfg_toWrite.operation = QCFG_NWSCANSEQ_SET;
            quec_net_cfg_toWrite.atp_index =  GET_ATP_INDEX(atHandle);
			//net_mode_temp=net_mode;//connor 19/04/28 in 3g project if we set a seq include LTE return error directly
            //jensen.fang 20191216: remove it, check the mode at the AT handler(quectel_exec_qcfg_nwscanseq_cmd)
			//connor 19/04/28 in 3g project if we set a seq include LTE return error directly
			//if(net_mode_temp != net_mode)
			//{
			//	Network_Info_Log(" ERROR mode set not match band config !!!!!!!!");
			//	ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
			//	return;
			//}
            
            mode_check_ret = quec_mode_check(&quec_net_cfg_toWrite);
            if (1 == mode_check_ret)
            {
    	        DEV_SetBandModeReq(atHandle, quec_net_cfg_toWrite.net_mode, quec_net_cfg_toWrite.pref_mode,
                    getBandModeCnf->GSMBandMode, getBandModeCnf->UMTSBandMode, getBandModeCnf->EUTRANBandModeH,   
                    getBandModeCnf->EUTRANBandModeL, getBandModeCnf->roamingConfig, getBandModeCnf->srvDomain, getBandModeCnf->bandPriorityFlag, 0, getBandModeCnf->EUTRANBandModeExt);
            }
            else if (0 == mode_check_ret)
            {
		        ATRESP( atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
                return;
            }
            else
            {
		        ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                return;
            }
        }
        else if(CHECK_BIT_SET(qcfg_cmd_type_bitmask ,QCFG_BAND_GET))
        {
            UINT32 gsm_band=0;
            UINT32 umts_band=0;
            UINT64 quec_gw_band=0;
            UINT64 quec_lte_band=0;
            UINT64 quec_lte_band_ext=0;
            
            quec_map_AsrbandQuecband(&quec_gw_band,&quec_lte_band,&quec_lte_band_ext,getBandModeCnf->GSMBandMode,getBandModeCnf->UMTSBandMode,getBandModeCnf->EUTRANBandModeH,getBandModeCnf->EUTRANBandModeL,getBandModeCnf->EUTRANBandModeExt);
			//connor.wu 2018/12/13 fix the isuuse when the band is invalid it return ff but we expect it return 0
			gsm_band=quec_get_gsm_band();
			umts_band=quec_get_wcdma_band();
			quec_gw_band=(quec_gw_band & (gsm_band | umts_band));
			quec_lte_band=(quec_lte_band & quec_get_lte_band());
            quec_lte_band_ext=(quec_lte_band_ext & quec_get_lte_band_ext());
#if !QUEC_LTE_SUPPORT
			sprintf((char *)bandBuf, "+QCFG: \"band\",0x%llx\r\n", quec_gw_band);
#else
            if (quec_lte_band_ext > 0)
            {
			    sprintf((char *)bandBuf, "+QCFG: \"band\",0x%llx,0x%llx%016llx\r\n", quec_gw_band, quec_lte_band_ext, quec_lte_band);
            }
            else
            {
			    sprintf((char *)bandBuf, "+QCFG: \"band\",0x%llx,0x%llx\r\n", quec_gw_band, quec_lte_band);
            }
#endif
	        ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, bandBuf);
            BIT_CLR(qcfg_cmd_type_bitmask,QCFG_BAND_GET);
        }
        else if(CHECK_BIT_SET(qcfg_cmd_type_bitmask ,QCFG_BAND_SET))
        {
            quec_net_cfg_toWrite.gsm_band = 0;
            quec_net_cfg_toWrite.umts_band = 0;
            quec_net_cfg_toWrite.lte_band_h = 0;
            quec_net_cfg_toWrite.lte_band_l = 0;
            quec_net_cfg_toWrite.lte_band_ext = 0;
            quec_map_Quecband2Asrband(qcfg_band[0],qcfg_band[1],qcfg_band[2],&(quec_net_cfg_toWrite.gsm_band),&(quec_net_cfg_toWrite.umts_band),
                &(quec_net_cfg_toWrite.lte_band_h),&(quec_net_cfg_toWrite.lte_band_l),&(quec_net_cfg_toWrite.lte_band_ext));
            BIT_CLR(qcfg_cmd_type_bitmask,QCFG_BAND_SET);
            
            quec_net_cfg_toWrite.operation = QCFG_BAND_SET;
            quec_net_cfg_toWrite.atp_index =  GET_ATP_INDEX(atHandle);
            
            mode_check_ret = quec_mode_check(&quec_net_cfg_toWrite);
            if (1 == mode_check_ret)
            {
                DEV_SetBandModeReq(atHandle, quec_net_cfg_toWrite.net_mode, quec_net_cfg_toWrite.pref_mode,
                        quec_net_cfg_toWrite.gsm_band, quec_net_cfg_toWrite.umts_band, quec_net_cfg_toWrite.lte_band_h,quec_net_cfg_toWrite.lte_band_l, 
                        getBandModeCnf->roamingConfig, getBandModeCnf->srvDomain, getBandModeCnf->bandPriorityFlag, 0, quec_net_cfg_toWrite.lte_band_ext);
            }
            else if (0 == mode_check_ret)
            {
		        ATRESP( atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
                return;
            }
            else
            {
		        ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                return;
            }
        }
        Network_Info_Log("processGetBandModeConf: qcfg_cmd_type_bitmask=%x",qcfg_cmd_type_bitmask);
	}
	else
	{
        qcfg_cmd_type_bitmask=0;
		checkDevRet(atHandle, getBandModeCnf->result);
	}

    return;
}
#endif


#ifdef QUECTEL_CELL_SELECT_CFG
void quec_log_cell_select_offset(CiDevPrimSetCellSelectCfgReq *pCellSelectOffset)
{
	if (NULL == pCellSelectOffset)
	{
		CPUartLogPrintf("[quec cell select cfg] pCellSelectOffset is NULL");
		return;		
	}
	CPUartLogPrintf("[quec cell select cfg] scell=%d,scell_qual=%d,ncell_lte=%d,ncell_lte_qual=%d",
						pCellSelectOffset->offset_scell,
						pCellSelectOffset->offset_scell_qual,
						pCellSelectOffset->offset_ncell_lte,
						pCellSelectOffset->offset_ncell_lte_qual);
	CPUartLogPrintf("[quec cell select cfg] ncell_umts=%d,ncell_umts_qual=%d,ncell_gsm=%d",
						pCellSelectOffset->offset_ncell_umts,
						pCellSelectOffset->offset_ncell_umts_qual,
						pCellSelectOffset->offset_ncell_gsm);
}

/****************************************************************************************
*  FUNCTION:  DEV_SetCellSelectOffset
*
*  PARAMETERS: 
*  		CiDevPrimSetCellSelectCfgReq 
*
*  DESCRIPTION: set cell select offset value to control cell switch
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/

CiReturnCode DEV_SetCellSelectOffset(UINT32 atHandle, CiDevPrimSetCellSelectCfgReq *cellSelectOffset)
{
	CiReturnCode ret = CIRC_FAIL;
	UINT32 reqHandle = 0;
	CiDevPrimSetCellSelectCfgReq *pSetCellSelectCfgReq = NULL;

	if (NULL == cellSelectOffset)
	{
		CPUartLogPrintf("[quec cell select cfg] cellSelectOffset is NULL");
		return CIRC_FAIL;		
	}
	quec_log_cell_select_offset(cellSelectOffset);
	reqHandle = MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_SET_CELL_SELECT_CFG_REQ);
	pSetCellSelectCfgReq = (CiDevPrimSetCellSelectCfgReq *)utlCalloc(1, sizeof(CiDevPrimSetCellSelectCfgReq));
	if (NULL == pSetCellSelectCfgReq)
	{
		CPUartLogPrintf("[quec cell select cfg] pSetCellSelectCfgReq is NULL");
		return CIRC_FAIL;
	}
	pSetCellSelectCfgReq->offset_scell 		     = 	cellSelectOffset->offset_scell;
	pSetCellSelectCfgReq->offset_scell_qual 	 = 	cellSelectOffset->offset_scell_qual;
	pSetCellSelectCfgReq->offset_ncell_lte 		 = 	cellSelectOffset->offset_ncell_lte;
	pSetCellSelectCfgReq->offset_ncell_lte_qual  = 	cellSelectOffset->offset_ncell_lte_qual;
	pSetCellSelectCfgReq->offset_ncell_umts 	 = 	cellSelectOffset->offset_ncell_umts;
	pSetCellSelectCfgReq->offset_ncell_umts_qual = 	cellSelectOffset->offset_ncell_umts_qual;
	pSetCellSelectCfgReq->offset_ncell_gsm 	     = 	cellSelectOffset->offset_ncell_gsm;
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_CELL_SELECT_CFG_REQ, reqHandle, (void *)pSetCellSelectCfgReq );
	
	return ret;
}

CiReturnCode DEV_CellSelectOffset_req(UINT32 atHandle)
{
	CiDevPrimGetCellSelectCfgReq *pGetCellSelectCfgReq = NULL;
	CiReturnCode ret = CIRC_FAIL;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_CELL_SELECT_CFG_REQ,
		 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_CELL_SELECT_CFG_REQ), (void*)pGetCellSelectCfgReq);

	return ret;
}

#endif

/****************************************************************************************
*  FUNCTION:  DEV_SetPOWERIND
*
*  PARAMETERS: 
*  		powerState: 1 means suspend; 0 means resume
*
*  DESCRIPTION: interface to set AP Power Ind, implementation of AT*POWERIND=
*
*  RETURNS: CiReturnCode
*
****************************************************************************************/
CiReturnCode DEV_SetPOWERIND(UINT32 atHandle, UINT32 powerState)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimApPowerNotifyReq                         *apPowerNotifyReq=NULL;
	
	apPowerNotifyReq = (CiDevPrimApPowerNotifyReq *)utlCalloc(1, sizeof(CiDevPrimApPowerNotifyReq));
	if (apPowerNotifyReq == NULL)
		return CIRC_FAIL;

	apPowerNotifyReq->powerState = powerState;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_AP_POWER_NOTIFY_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_AP_POWER_NOTIFY_REQ), (void*)apPowerNotifyReq);
	return ret;
}

static void processGetCellinfoConf(UINT32 atHandle, const void *paras)
{
	CiDevPrimGetEngmodeInfoCnf* getEngModeInfoCnf = (CiDevPrimGetEngmodeInfoCnf *)paras;
	char EngModeInfo[50];

	if (getEngModeInfoCnf->rc == CIRC_DEV_SUCCESS)
	{
		sprintf(EngModeInfo, "+CELLINFO: %d,%d,%u,%d\r\n", gcell_mcc, gcell_mnc, gcell_ci, gcell_lac);
		ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, EngModeInfo);
	}
	else
		checkDevRet(atHandle, getEngModeInfoCnf->rc);
}


/****************************************************************
 *  F@: processGetSinrConf - Process CI cnf msg of AT*SINR
 */
static void processGetSinrConf(UINT32 atHandle)
{
	char rspBuf[50];
	BOOL *pSINRUpdate;
	int sinr;

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
		pSINRUpdate = &gSINRUpdate;
		sinr = gSINR;
	} else {
		pSINRUpdate = &gSINRUpdate_1;
		sinr = gSINR_1;
	}
#else
	pSINRUpdate = &gSINRUpdate;
	sinr = gSINR;
#endif

	if (*pSINRUpdate)
	{
		sprintf((char *)rspBuf, "*SINR: %d\r\n", sinr);
		ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, rspBuf);
	}
	else
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);

	*pSINRUpdate = FALSE;

	return;
}

/****************************************************************
 *  F@: processGetRssiConf - Process CI cnf msg of AT*RSSI
 */
static void processGetRssiConf(UINT32 atHandle)
{
	char rspBuf[50];
	BOOL *pRSSIUpdate;
	int rssi;
	
#ifndef SINGLE_SIM	
	if (!GET_SIM1_FLAG(atHandle)) {
		pRSSIUpdate = &gRSSIUpdate;
		rssi = gRSSI;
	} else {
		pRSSIUpdate = &gRSSIUpdate_1;
		rssi = gRSSI_1;
	}
#else
	pRSSIUpdate = &gRSSIUpdate;
	rssi = gRSSI;
#endif

	if (*pRSSIUpdate)
	{
		sprintf((char *)rspBuf, "*RSSI: %d\r\n", rssi);
		ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, rspBuf);
	}
	else
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);

	*pRSSIUpdate = FALSE;

	return;
}

/****************************************************************
 *  F@: processGetEngModeInfoConf - Process CI cnf msg of AT+EEMGINFO?
 */
static void processGetEngModeInfoConf(UINT32 atHandle, const void *paras)
{
	CiDevPrimGetEngmodeInfoCnf* getEngModeInfoCnf = (CiDevPrimGetEngmodeInfoCnf *)paras;
	char EngModeInfo[50];

	memset(EngModeInfo, 0, sizeof(EngModeInfo));
	DBGMSG("%s: CI_DEV_PRIM_GET_ENGMODE_INFO_CNF rc: %d, network: %d\n", getEngModeInfoCnf->rc, getEngModeInfoCnf->network);
	if (getEngModeInfoCnf->rc == CIRC_DEV_SUCCESS)
	{
		sprintf((char *)EngModeInfo, "+EEMGINFO: %d, %d\r\n", getEngModeInfoCnf->mode, getEngModeInfoCnf->network);
		ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, EngModeInfo);
	}
	else
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);

	return;
}
#ifdef AGPS_ENABLE

/****************************************************************
 *  F@: processGetSVConf - Process CI cnf msg of
 */
static void processlpNwulConf(UINT32 atHandle, const void *paras)
{
	char rspBuf[50];       /* large enough for IMEI response */
	CiDevPrimLpNwulMsgCnf *lpNwulMsgCnf = (CiDevPrimLpNwulMsgCnf *)paras;

	memset(rspBuf, 0, sizeof(rspBuf));
	rspBuf[0] = '\0';
	sprintf(rspBuf, "+LPNWUL:%d\r\n", lpNwulMsgCnf->result);

	ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)rspBuf);

	return;
}
#endif
#ifndef LTEONLY_THIN
/****************************************************************
 *  F@: processSetHsdpaModeConf - Process CI cnf msg of AT*EHSDPA=
 */
static void processSetHsdpaModeConf(UINT32 atHandle, const void *paras)
{
	CiDevPrimEnableHsdpaCnf *enableHsdpaCnf = (CiDevPrimEnableHsdpaCnf *)paras;

	if ( enableHsdpaCnf->rc == CIRC_DEV_SUCCESS)
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, 0);
	}
	else
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
	}

	return;
}
/****************************************************************
 *  F@: processGetHsdpaModeConf - Process CI cnf msg of AT*EHSDPA?
 */
static void processGetHsdpaModeConf(UINT32 atHandle, const void *paras)
{
	char rspBuf[100];
	UINT8 mode=0;
	CiDevPrimGetHsdpaStatusCnf *getHsdpaStatusCnf = (CiDevPrimGetHsdpaStatusCnf *)paras;

	memset(rspBuf, 0, sizeof(rspBuf));
	if ( (getHsdpaStatusCnf->rc == CIRC_DEV_SUCCESS) && libConvertHsdpaMode2At(getHsdpaStatusCnf->hspaConfig, &mode))
	{

		sprintf(rspBuf, "*EHSDPA:%d,%d,%d,%d,%d,%d,%d,%d\r\n", mode, getHsdpaStatusCnf->dlCategory, getHsdpaStatusCnf->ulCategory,
			getHsdpaStatusCnf->cpcState, getHsdpaStatusCnf->dpaCategoryExt, getHsdpaStatusCnf->edchCategoryExt, getHsdpaStatusCnf->fdpchState,
			getHsdpaStatusCnf->eFdpchState);
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, rspBuf);
	}
	else
	{
		checkDevRet(atHandle, getHsdpaStatusCnf->rc);
	}

	return;
}
#endif

/* table for mapping Dev return code to CME error code */
static UINT16 DevRc2CmeErrorTbl[CIRC_DEV_NUM_RESCODES] = {
	0xffff,            /* CIRC_DEV_SUCCESS */
	CME_PHONE_FAILURE, /* CIRC_DEV_FAILURE */
	CME_NO_CONNECTION, /* CIRC_DEV_NO_CONNECTION */
	CME_UNKNOWN        /* CIRC_DEV_UNKNOWN */
};



/****************************************************************
 *  F@: processGetInternalReversionCnf  - Process CI cnf msg of AT*CGMR
 */
static void processGetInternalReversionCnf(UINT32 atHandle, const void *paras)
{
	char rspBuf[500]="\0";
	CiDevPrimGetInternalRevisionIdCnf *getInternalRevesionConfigCnf = (CiDevPrimGetInternalRevisionIdCnf *)paras;

	if(getInternalRevesionConfigCnf->rc == CIRC_DEV_SUCCESS)
	{
		extern char * getCustVersion();	
		sprintf(rspBuf,"*CGMR: \"%s%s\",\"%s\"", getInternalRevesionConfigCnf->internalRevisionStr.valStr, getCustVersion(),getInternalRevesionConfigCnf->buildTimeStr.valStr);
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, rspBuf);
	}
	else
	{
		checkDevRet(atHandle, getInternalRevesionConfigCnf->rc);
	}

	return;
}

/****************************************************************
 *  F@: processSetPowerBackOffCnf  - Process CI cnf msg of AT*GRIP=
 */
static void processSetPowerBackOffCnf(UINT32 atHandle, const void *paras)
{
	CiDevPrimSetPowerBackOffCnf *setPowerBackOffCnf = (CiDevPrimSetPowerBackOffCnf *)paras;

	if(setPowerBackOffCnf->rc == CIRC_DEV_SUCCESS)
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
	}
	else
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
	}

	return;
}


/****************************************************************
 *  F@: processGetComConfigCnf  - Process CI cnf msg of AT*COMCFG=0,XXX
 */
static void processGetComConfigCnf(UINT32 atHandle, const void *paras)
{
	char rspBuf[50] = {0};
	CiDevPrimGetComConfigCnf *getComConfigCnf = (CiDevPrimGetComConfigCnf *)paras;
	UINT8 numTokens=0;
	UINT8 sequenceNum = 0;
	int i=0, j=0;

	if(getComConfigCnf->rc == CIRC_DEV_SUCCESS)
	{
		numTokens = getComConfigCnf->numTokens;
		snprintf(rspBuf, utlNumberOf(rspBuf), "*COMCFG:");
		for(i = 0; i < numTokens; i++)
		{
			for(j = sequenceNum; j < getComConfigCnf->Token[i].name; j++)
			{
				/*coverity[overlapping_copy] */
				snprintf(rspBuf, utlNumberOf(rspBuf), "%s,", rspBuf);
			}
			/*ignored*/
			/*klocwork[Unexpected type of a print function parameter]*/
			snprintf(rspBuf, utlNumberOf(rspBuf), "%s%d", rspBuf, getComConfigCnf->Token[i].value);

			sequenceNum = getComConfigCnf->Token[i].name;
		}

		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, rspBuf);
	}
	else
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
	}

	return;
}

#ifndef LTEONLY_THIN

/****************************************************************
 *  F@: processSetLteCoexReportOptionCnf  - Process CI cnf msg of *LTECOEX=
 */
static void processSetLteCoexReportOptionCnf(UINT32 atHandle, const void *paras)
{
	CiDevPrimSetLteCoexReportOptionCnf *setLteCoexReportOptionCnf = (CiDevPrimSetLteCoexReportOptionCnf *)paras;

	if(setLteCoexReportOptionCnf->result == CIRC_DEV_SUCCESS)
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
	}
	else
	{
		checkDevRet(atHandle, setLteCoexReportOptionCnf->result);
	}

	return;
}

/****************************************************************
 *  F@: CiDevPrimGetLteCoexInfoCnf  - Process CI cnf msg of *LTECOEX?
 */
static void processGetLteCoexInfoCnf(UINT32 atHandle, const void *paras)
{
	char rspBuf[100];
	char tmpBuf[50];
	CiDevPrimGetLteCoexInfoCnf *getLteCoexInfoCnf = (CiDevPrimGetLteCoexInfoCnf *)paras;

	memset(rspBuf, 0, sizeof(rspBuf));
	memset(tmpBuf, 0, sizeof(tmpBuf));
	if(getLteCoexInfoCnf->result == CIRC_DEV_SUCCESS)
	{
		/*ignored*/
		/*klocwork[Unexpected type of a print function parameter]*/
		snprintf(rspBuf, utlNumberOf(rspBuf), "*LTECOEX:%d,%d,%d,%d", getLteCoexInfoCnf->isLteOn,
				getLteCoexInfoCnf->rrcState, getLteCoexInfoCnf->lteBand, getLteCoexInfoCnf->earfcn);

		if(getLteCoexInfoCnf->tddSubframeConfigPresent)
		{
			snprintf(tmpBuf, utlNumberOf(tmpBuf), ",%d,%d", getLteCoexInfoCnf->tddUlDlConfig, getLteCoexInfoCnf->tddSpecialSubframeConfig);
			strlcat(rspBuf, tmpBuf, utlNumberOf(rspBuf));
		}
		else
			strlcat(rspBuf, ",,", utlNumberOf(rspBuf));

		if(getLteCoexInfoCnf->longDRXCyclePresent)
		{
			snprintf(tmpBuf, utlNumberOf(tmpBuf), ",%d", getLteCoexInfoCnf->longDRXCycle);
			strlcat(rspBuf, tmpBuf, utlNumberOf(rspBuf));
		}
		else
			strlcat(rspBuf, ",", utlNumberOf(rspBuf));

		if(getLteCoexInfoCnf->shortDRXCyclePresent)
		{
			snprintf(tmpBuf, utlNumberOf(tmpBuf), ",%d", getLteCoexInfoCnf->shortDRXCycle);
			strlcat(rspBuf, tmpBuf, utlNumberOf(rspBuf));
		}
		else
			strlcat(rspBuf, ",", utlNumberOf(rspBuf));

		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, rspBuf);
	}
	else
	{
		checkDevRet(atHandle, getLteCoexInfoCnf->result);
	}

	return;
}

#endif


/****************************************************************
 *  F@: processSetComConfigCnf  - Process CI cnf msg of AT*COMCFG=1,XXX
 */
static void processSetComConfigCnf(UINT32 atHandle, const void *paras)
{
	char rspBuf[50];
	CiDevPrimSetComConfigCnf *setComConfigCnf = (CiDevPrimSetComConfigCnf *)paras;

	memset(rspBuf, 0, sizeof(rspBuf));
	if(setComConfigCnf->rc == CIRC_DEV_SUCCESS)
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
	}
	else
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
	}

	return;
}
extern UINT8 vzwmeas_status;
extern UINT8 vzwmeas_status_1;

/****************************************************************
 *  F@: processGetLteMeasCnf  - Process CI cnf msg of +VZWRSRP,+VZWRSRQ?
 */
static void processGetLteMeasCnf(UINT32 atHandle, const void *paras)
{
	char* rspBuf_p=NULL;
	char* tmpBuf_p=NULL;
	CiDevPrimGetLteMeasCnf *getLteMeasCnf = (CiDevPrimGetLteMeasCnf *)paras;
	int i=0;
	UINT8 tmp_vzwmeas_status;

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
		tmp_vzwmeas_status = vzwmeas_status;
	} else {
		tmp_vzwmeas_status = vzwmeas_status_1;
	}
#else
	tmp_vzwmeas_status = vzwmeas_status;
#endif

	
	rspBuf_p = (char* )utlMalloc(20 + getLteMeasCnf->num * 30);
	if(rspBuf_p == NULL)
	{
		ERRMSG("%s: can't malloc enough space!", __FUNCTION__);
		ATRESP( atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
		return;
	}

	tmpBuf_p = rspBuf_p;
	if(tmp_vzwmeas_status==LTE_MEAS_RSRP)
	{
		tmpBuf_p += sprintf(tmpBuf_p, "+VZWRSRP:");
	}
	else
	{
		tmpBuf_p += sprintf(tmpBuf_p, "+VZWRSRQ:");
	}
	
	for(i = 0; i < getLteMeasCnf->num; i++)
	{
		float dbm;
		dbm = -141.0 + getLteMeasCnf->eMeasInfo[i].rsrp;
		if(i != 0)
			tmpBuf_p += sprintf(tmpBuf_p,",");

		tmpBuf_p += sprintf(tmpBuf_p,"%d,%d,\"%.2f\"", getLteMeasCnf->eMeasInfo[i].cellID, getLteMeasCnf->eMeasInfo[i].earfcn, dbm);
	}
	ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, rspBuf_p);
	utlFree(rspBuf_p);

	return;
}
extern UINT8 temptest_flg;

/****************************************************************
 *  F@: processReadRFTemperatureCnf  - Process CI cnf msg of *RFTEMP=
 */
static void processReadRFTemperatureCnf(UINT32 reqHandle, const void *paras)
{
	char rspBuf[50];
	CiDevPrimReadRfTemperatureCnf *readRfTemperatureCnf = (CiDevPrimReadRfTemperatureCnf *)paras;

	memset(rspBuf, 0, sizeof(rspBuf));
	if(readRfTemperatureCnf->rc == CIRC_DEV_SUCCESS)
	{
		/*ignored*/
		/*klocwork[Unexpected type of a print function parameter]*/
		snprintf(rspBuf, utlNumberOf(rspBuf), "*RFTEMP:%d,%d", GET_REQ_ID(reqHandle), readRfTemperatureCnf->tempData);
		ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, rspBuf);
	}
	else
	{
		ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
	}

	return;
}

/****************************************************************
 *  F@: processSetComConfigCnf  - Process CI cnf msg of AT*MCCMNCCC=
 */
static void processSetMccMncCcReqCnf(UINT32 atHandle, const void *paras)
{
	CiDevPrimSetMccMncCcCnf *setMccMncCcCnf = (CiDevPrimSetMccMncCcCnf *)paras;

	if(setMccMncCcCnf->rc == CIRC_DEV_SUCCESS)
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
	}
	else
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
	}

	return;
}
/****************************************************************
 *  F@: processGetMccMncCcReqCnf  - Process CI cnf msg of AT*MCCMNCCC=
 */
static void processGetMccMncCcReqCnf(UINT32 atHandle, const void *paras)
{
	char rspBuf[50] = {0};
	CiDevPrimGetMccMncCcCnf *getMccMncCcCnf = (CiDevPrimGetMccMncCcCnf *)paras;
	UINT32     countryCode=0;
    UINT32     operCode=0;
	/*Fix klocwork[Buffer Overflow]*/
    UINT8       customerCode[4] = {0};
	

	if(getMccMncCcCnf->rc == CIRC_DEV_SUCCESS)
	{
		countryCode = getMccMncCcCnf->countryCode;
		operCode = getMccMncCcCnf->operCode;
		customerCode[0] = getMccMncCcCnf->customerCode[0];
		customerCode[1] = getMccMncCcCnf->customerCode[1];
		customerCode[2] = getMccMncCcCnf->customerCode[2];
		/*ignored*/
		/*klocwork[Unexpected type of a print function parameter]*/
		snprintf(rspBuf, utlNumberOf(rspBuf), "+MCCMNCCC:%d, %d, \"%s\"", countryCode, operCode, (char *)&customerCode[0]);
		strcat(rspBuf, "\r\n");
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, rspBuf);
	}
	else
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
	}

	return;
}
#ifndef LTEONLY_THIN

/****************************************************************
 *  F@: processGetWbAmrCnf  - Process CI cnf msg of AT*WBAMR=0,XXX
 */
static void processGetWbAmrCnf(UINT32 atHandle, const void *paras)
{
	char rspBuf[50] = {0};
	CiDevPrimGetComConfigCnf *getComConfigCnf = (CiDevPrimGetComConfigCnf *)paras;
	UINT8 numTokens;
	UINT8 sequenceNum = 0;
	int i, j;

	if(getComConfigCnf->rc == CIRC_DEV_SUCCESS)
	{
		numTokens = getComConfigCnf->numTokens;
		snprintf(rspBuf, utlNumberOf(rspBuf), "*WBAMR:");
		for(i = 0; i < numTokens; i++)
		{
			for(j = sequenceNum; j < getComConfigCnf->Token[i].name; j++)
				snprintf(rspBuf, utlNumberOf(rspBuf), "%s,", rspBuf);
			/* coverity[overlapping_copy] */
			snprintf(rspBuf, utlNumberOf(rspBuf), "%s%d", rspBuf, getComConfigCnf->Token[i].value);

			sequenceNum = getComConfigCnf->Token[i].name;
		}

		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, rspBuf);
	}
	else
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
	}

	return;
}

/****************************************************************
 *  F@: processSetWbAmrCnf  - Process CI cnf msg of AT*WBAMR=1,XXX
 */
static void processSetWbAmrCnf(UINT32 atHandle, const void *paras)
{
	char rspBuf[50];
	CiDevPrimSetComConfigCnf *setComConfigCnf = (CiDevPrimSetComConfigCnf *)paras;

	if(setComConfigCnf->rc == CIRC_DEV_SUCCESS)
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
	}
	else
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
	}

	return;
}




/****************************************************************
 *  F@: processSetIMLConfigConf - Process CI cnf msg of *IMLCONFIG=
 */
static void processSetIMLConfigConf(UINT32 atHandle, const void *paras)
{
	CiDevPrimSetImlConfigCnf *setImlConfigCnf = (CiDevPrimSetImlConfigCnf *)paras;

	if(setImlConfigCnf->rc == CIRC_DEV_SUCCESS)
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
	}
	else
	{
		checkDevRet(atHandle, setImlConfigCnf->rc);
	}
	return;
}

/****************************************************************
 *  F@: processGetIMLConfigConf - Process CI cnf msg of *IMLCONFIG?
 */
static void processGetIMLConfigConf(UINT32 atHandle, const void *paras)
{
	CiDevPrimGetImlConfigCnf *getImlConfigCnf = (CiDevPrimGetImlConfigCnf *)paras;
	char rspBuf[2 * CI_DEV_MAX_IML_CFG_LEN + 30];

	if(getImlConfigCnf->rc == CIRC_DEV_SUCCESS)
	{
		sprintf(rspBuf, "*IMLCONFIG: %d", getImlConfigCnf->imlLogType);
		if(getImlConfigCnf->cfgDataLen > 0)
		{
			strcat(rspBuf, ",\"");
			libConvertNumToHex((char *)(getImlConfigCnf->cfgData), getImlConfigCnf->cfgDataLen, rspBuf);
			strcat(rspBuf, "\"");
		}
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, rspBuf);
	}
	else
	{
		checkDevRet(atHandle, getImlConfigCnf->rc);
	}
	return;
}

#endif

#ifndef LTEONLY_THIN

#ifdef PLATFORM_FOR_PS_LW

/****************************************************************
 *  F@: processSetLTEBandConf - Process CI cnf msg of *LTEBAND=XX,XX?
 */

static void processSetLTEBandConf(UINT32 atHandle, const void *paras)
{

	CiDevPrimSetLteBandOrderCnf *SetLteBandOrderCnf = (CiDevPrimSetLteBandOrderCnf *)paras;
	if(SetLteBandOrderCnf->rc==CIRC_DEV_SUCCESS)
	ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
	else
	ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
	
}


/****************************************************************
 *  F@: processGetLTEBandConf - Process CI cnf msg of *LTEBAND?
 */

static void processGetLTEBandConf(UINT32 atHandle, const void *paras)
{

	UINT8 index=0;
	char RspBuf[100]={0};
	CiDevPrimGetLteBandOrderCnf *GetLteBandOrderCnf = (CiDevPrimGetLteBandOrderCnf *)paras;
	if(GetLteBandOrderCnf->rc == CIRC_DEV_SUCCESS)
	{

		if(GetLteBandOrderCnf->numOfLteBands>0)
		{

			snprintf(RspBuf, sizeof(RspBuf), "*LTEBAND:");

			for(index=0;index<GetLteBandOrderCnf->numOfLteBands;index++)
			{
				snprintf(RspBuf+strlen(RspBuf), sizeof(RspBuf)-strlen(RspBuf), ",%d", GetLteBandOrderCnf->lteBands[index]);
			}
			
			ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, RspBuf);
		}

		
	}
	else
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
	}
	return;

	
}
#endif
#endif
#ifdef AGPS_ENABLE

/****************************************************************
*  F@: processLpECIDMeasCnf  - Process CI cnf msg of +LPECID=
*/
static void processLpECIDMeasCnf(UINT32 atHandle, const void *paras)
{
	char *pRspBuf;
	int paramlen;
	CiDevPrimLpEcidMeasCnf *lpecidmeascnf = (CiDevPrimLpEcidMeasCnf *)paras;

	if(lpecidmeascnf->rc == CIRC_DEV_SUCCESS)
	{
		pRspBuf = (char* )malloc(20 + sizeof(CiDevPrimLpEcidMeasCnf) * 2 + 4);
		if(pRspBuf == NULL)
		{
			ATRESP( atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
			return;
		}
		
		pRspBuf[0] = '\0';
		
		sprintf(pRspBuf,"+LPECID:%d,%d,\"", lpecidmeascnf->rc,lpecidmeascnf->networkType);

		paramlen = sizeof(CiDevEcidInfo);
		libConvertNumToHex((char*)&lpecidmeascnf->info, paramlen, pRspBuf);

		strcat(pRspBuf, "\"");
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, pRspBuf);
		free(pRspBuf);
		
	} else {
		char rspBuf[100];
		rspBuf[0] = '\0';
		
		snprintf(rspBuf, sizeof(rspBuf),"+LPECID:%d,%d\r\n", lpecidmeascnf->rc,lpecidmeascnf->networkType);
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, rspBuf);
	}
	
	return;
}

/****************************************************************
 *  F@: processLpOtdoaMeasCnf  - Process CI cnf msg of +LPOTDOAREQ=
*/
static void processLpOtdoaMeasCnf(UINT32 atHandle, const void *paras)
{
	char rspBuf[50];
	CiDevPrimLpOtdoaMeasCnf *lpotdoameascnf = (CiDevPrimLpOtdoaMeasCnf *)paras;

	if(lpotdoameascnf->rc == CIRC_DEV_SUCCESS)
	{
		snprintf(rspBuf, sizeof(rspBuf), "+LPOTDOAREQ:%d\r\n", lpotdoameascnf->rc);
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, rspBuf);
	}
	else
	{
		checkDevRet(atHandle, lpotdoameascnf->rc);
	}

	return;
}

/****************************************************************
*  F@: processLpOtdoaAbortCnf  - Process CI cnf msg of +LPOTDOAABORT=
*/
static void processLpOtdoaAbortCnf(UINT32 atHandle, const void *paras)
{
	char rspBuf[50];
	CiDevPrimLpOtdoaMeasAbortCnf *lpotdoaabortcnf = (CiDevPrimLpOtdoaMeasAbortCnf *)paras;

	if(lpotdoaabortcnf->rc == CIRC_DEV_SUCCESS)
	{
		snprintf(rspBuf, sizeof(rspBuf), "+LPOTDOAABORT:%d\r\n", lpotdoaabortcnf->rc);
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, rspBuf);
	}
	else
	{
		checkDevRet(atHandle, lpotdoaabortcnf->rc);
	}

	return;
}
#endif

#ifdef PLATFORM_FOR_PS_LW
static void processSetCscConf(UINT32 atHandle, const void *paras)
{

	CiDevPrimSetSalesCodeCnf *SetCSCcnf = (CiDevPrimSetSalesCodeCnf *)paras;
	if(SetCSCcnf->rc==CIRC_DEV_SUCCESS)
	ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
	else
	ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
	
}



static void processGetCscConf(UINT32 atHandle, const void *paras)
{

	UINT8 index=0;
	char RspBuf[100]={0};
	
	char RspBuf_temp[100]={0};

	
	CiDevPrimGetSalesCodeCnf *GetCSCcnf = (CiDevPrimGetSalesCodeCnf *)paras;
	if(GetCSCcnf->rc == CIRC_DEV_SUCCESS)
	{
		sprintf(RspBuf,"+CSC:");

		if(GetCSCcnf->codeNum>0)
		{

			snprintf(RspBuf, sizeof(RspBuf), "+CSC:");

			for(index=0;index<(GetCSCcnf->codeNum-1);index++)
			{
				if(index==(GetCSCcnf->codeNum-1))
				{
				
				 sprintf(RspBuf_temp, "\"%s\"", GetCSCcnf->code[index].data);
				}
				else
				{
					sprintf(RspBuf_temp, "\"%s\",", GetCSCcnf->code[index].data);
				}
				strcat((char *)RspBuf, (char *)RspBuf_temp);
			}
			
			ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, RspBuf);
		}
		else
		{
			ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
		}

		
	}
	else
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
	}
	return;

	
}

#endif

static void processSetOperCfgConf(UINT32 atHandle, const void *paras)
{

	CiDevPrimSetOperConfigCnf *SetOpercfgcnf = (CiDevPrimSetOperConfigCnf *)paras;
	if(SetOpercfgcnf->rc==CIRC_DEV_SUCCESS)
	ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
	else
	ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
	
}
static void processGetOperCfgConf(UINT32 reqHandle, const void *paras)
{

    UINT16 index, validNum;
    char *RspBuf;
    int len = 0;

    CiDevFeature *pCiDevFeature = NULL;
    static CiDevFeature *pCiDevFeatureArray = NULL;
    static UINT16 featureNum = 0;

    CiDevPrimGetOperConfigCnf *getOpercfgCnf = (CiDevPrimGetOperConfigCnf *)paras;
    if(getOpercfgCnf->rc == CIRC_DEV_SUCCESS)
    {
        UINT32 reqId = GET_REQ_ID(reqHandle);
        if(reqId % CI_DEV_MAX_NUM_FEATURES == 0)
        {
            if(reqId + CI_DEV_MAX_NUM_FEATURES < getOpercfgCnf->totalNum)
            {
                if(reqId == 0)
                {
                    /*This may be a memory leak that CP not response for this request, but since it will
                    leak at most once, so leave it here.*/
                    if(NULL != pCiDevFeatureArray)
                        utlFree(pCiDevFeatureArray);
                    featureNum = 0;
                    pCiDevFeatureArray = utlCalloc(getOpercfgCnf->totalNum, sizeof(CiDevFeature));
                    if(NULL == pCiDevFeatureArray)
                    {
                        ERRMSG(processGetOperCfgConf, "processGetOperCfgConf: alloc fail");
                        ATRESP(reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
                        return;
                    }
                }
                memcpy(&pCiDevFeatureArray[featureNum], getOpercfgCnf->feature, getOpercfgCnf->validNum * sizeof(CiDevFeature));
                featureNum += getOpercfgCnf->validNum;
                DEV_GetOperCfg_req(reqHandle, 0, reqId + CI_DEV_MAX_NUM_FEATURES);
                return;
            }
            else if(reqId == 0)
            {
                validNum = getOpercfgCnf->validNum;
                pCiDevFeature = getOpercfgCnf->feature;
            }
            else
            {
                memcpy(&pCiDevFeatureArray[featureNum], getOpercfgCnf->feature, getOpercfgCnf->validNum * sizeof(CiDevFeature));
                featureNum += getOpercfgCnf->validNum;
                validNum = featureNum;
                pCiDevFeature = pCiDevFeatureArray;
            }
        }
        else
        {
            validNum = getOpercfgCnf->validNum;
            pCiDevFeature = getOpercfgCnf->feature;
        }

        if(validNum > 0)
        {
            RspBuf = utlCalloc(1, 10 + validNum * 20);
            if(NULL == RspBuf)
            {
                ERRMSG(processGetOperCfgConf1, "processGetOperCfgConf: alloc fail");
                ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
                goto error;
            }

            len = sprintf(RspBuf, "+OPERCFG: ");

            for(index = 0; index < validNum; index++)
            {
                if(index == (validNum - 1))
                {
                    len += sprintf(RspBuf + len, "%u,%d", pCiDevFeature[index].featureId, pCiDevFeature[index].featureValue);
                }
                else
                {
                    len += sprintf(RspBuf + len, "%u,%d,", pCiDevFeature[index].featureId, pCiDevFeature[index].featureValue);
                }
            }
            ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, RspBuf);
            utlFree(RspBuf);
        }
        else
        {
            ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
        }
    }
    else
    {
        ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
    }

error:
    if(NULL != pCiDevFeatureArray)
        utlFree(pCiDevFeatureArray);
    featureNum = 0;
    return;
}

#ifndef LTEONLY_THIN
static void processSetGsmModeTxRxConf(UINT32 atHandle, const void *paras)
{
	char rspBuf[50];
	CiDevPrimSetGsmModeTxRxCnf *setGsmModeTxRxCnf = (CiDevPrimSetGsmModeTxRxCnf *)paras;
//	CPUartLogPrintf("%s,rc=%d",__func__,setGsmModeTxRxCnf->rc);
	if(setGsmModeTxRxCnf->rc == CIRC_DEV_SUCCESS)
	{
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
#ifdef QUECTEL_AT_RFTEST_SUPPORT
		memset(rspBuf,0,sizeof(rspBuf));
		if(quec_ftm_state_flag)  
		{
			sprintf(rspBuf,"+QRXFTM: %d\r\n",setGsmModeTxRxCnf->rssiDbmValue);	//rx need urc,tx no need
			quec_ftm_state_flag=0;
		}
#else
		sprintf(rspBuf,"*GSMTR:%d\r\n",  setGsmModeTxRxCnf->rssiDbmValue);
#endif
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)rspBuf);
}//MiniSystem
else
{
		sprintf(rspBuf,"*GSMTR:%d\r\n",  setGsmModeTxRxCnf->rssiDbmValue);
		ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)rspBuf);
}
#endif /*MIN_SYS*/	

	}
	else
	{
		checkDevRet(atHandle, setGsmModeTxRxCnf->rc);
	}
	return;
}
#endif /* LTEONLY_THIN */

#if defined(QUEC_BLACK_CELL_SUPPORT)|| defined(QUEC_THIN_BLACK_CELL_SUPPORT)
static void processSetBlackCellConf(UINT32 atHandle, const void *paras)
{
	CiDevPrimSetBlackCellCnf *setBlackCellCnf = (CiDevPrimSetBlackCellCnf *)paras;

	CPUartLogPrintf("quec blackcell: rc=%d",setBlackCellCnf->rc);

	if(setBlackCellCnf->rc == CIRC_DEV_SUCCESS)
	{
        ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL );
	}
	else
	{
		checkDevRet(atHandle, setBlackCellCnf->rc);
	}
	return;
}

static void processGetBlackCellConf(UINT32 atHandle, const void *paras)
{

	UINT8 index = 0;
	char RspBuf[300] = {0};
    
    CiDevPrimGetBlackCellCnf *GetBlackCellCnf = (CiDevPrimGetBlackCellCnf *)paras;
	
	if(GetBlackCellCnf->rc == CIRC_DEV_SUCCESS)
	{
	    snprintf(RspBuf, sizeof(RspBuf), "+QBLACKCELL: ");
		if(GetBlackCellCnf->GsmBlackCellList.numOfBlackCell > 0)
		{
            snprintf(RspBuf+strlen(RspBuf), sizeof(RspBuf)-strlen(RspBuf), "0,\""); /*0 is GSM Black cell*/
			for(index = 0;index < GetBlackCellCnf->GsmBlackCellList.numOfBlackCell; index++)
			{
				snprintf(RspBuf+strlen(RspBuf), sizeof(RspBuf)-strlen(RspBuf), "%d:%d&",
                                GetBlackCellCnf->GsmBlackCellList.blackCellIdList[index].afrcn,
                                GetBlackCellCnf->GsmBlackCellList.blackCellIdList[index].cellId);
			}
            CPUartLogPrintf("quec blackcell: RspBuf=%s",RspBuf);
			RspBuf[strlen(RspBuf)-1] = '\"'; /*delete the last & character*/
            CPUartLogPrintf("quec blackcell: RspBuf1=%s",RspBuf);
            RspBuf[strlen(RspBuf)] = '\0';
            CPUartLogPrintf("quec blackcell: RspBuf2=%s",RspBuf);
		}
        
        if (GetBlackCellCnf->UmtsBlackCellList.numOfBlackCell > 0)
        {
            if (GetBlackCellCnf->GsmBlackCellList.numOfBlackCell > 0)
            {
                snprintf(RspBuf+strlen(RspBuf), sizeof(RspBuf)-strlen(RspBuf), "\r\n1,\""); /*1 is umts Black cell*/
            }
            else 
            {
                snprintf(RspBuf+strlen(RspBuf), sizeof(RspBuf)-strlen(RspBuf), "1,\""); /*1 is umts Black cell*/
            }
			for(index = 0;index < GetBlackCellCnf->UmtsBlackCellList.numOfBlackCell; index++)
			{
				snprintf(RspBuf+strlen(RspBuf), sizeof(RspBuf)-strlen(RspBuf), "%d:%d&",
                                GetBlackCellCnf->UmtsBlackCellList.blackCellIdList[index].afrcn,
                                GetBlackCellCnf->UmtsBlackCellList.blackCellIdList[index].cellId);
			}
			RspBuf[strlen(RspBuf)-1] = '\"'; /*delete the last & character*/
            RspBuf[strlen(RspBuf)] = '\0';
        }
        
        if (GetBlackCellCnf->LteBlackCellList.numOfBlackCell > 0)
        {
            if ((GetBlackCellCnf->GsmBlackCellList.numOfBlackCell > 0) || (GetBlackCellCnf->UmtsBlackCellList.numOfBlackCell > 0))
            {
                snprintf(RspBuf+strlen(RspBuf), sizeof(RspBuf)-strlen(RspBuf), "\r\n2,\""); /*2 is lte Black cell*/
            }
            else 
            {
                snprintf(RspBuf+strlen(RspBuf), sizeof(RspBuf)-strlen(RspBuf), "2,\""); /*2 is lte Black cell*/
            }
			for(index = 0;index < GetBlackCellCnf->LteBlackCellList.numOfBlackCell; index++)
			{
				snprintf(RspBuf+strlen(RspBuf), sizeof(RspBuf)-strlen(RspBuf), "%d:%d&",
                                GetBlackCellCnf->LteBlackCellList.blackCellIdList[index].afrcn,
                                GetBlackCellCnf->LteBlackCellList.blackCellIdList[index].cellId);
			}
			RspBuf[strlen(RspBuf)-1] = '\"'; /*delete the last & character*/
            RspBuf[strlen(RspBuf)] = '\0';
        }
        
        ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, RspBuf);
	}
	else
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
	}
	return;
}

#endif

extern UINT8 comcfg_flag;
extern UINT8 comcfg_flag_1;
extern UINT8 wbamr_flag;
extern UINT8 wbamr_flag_1;
extern UINT8 ltepower_flag;
extern UINT8 ltepower_flag_1;
#ifdef QUECTEL_AT_RFTEST_SUPPORT
extern quec_rftestmode_param_type quec_rftestmode;
#endif
#ifdef AT_FOR_GW20180208SN
extern int gMMZRSSI;
#endif
/****************************************************************************************
*
*  DESCRIPTION: Callback function when receiving confirmation CI message related with Dev
*
****************************************************************************************/
void devCnf_2(CiSgOpaqueHandle opSgCnfHandle,
	    CiServiceGroupID svgId,
	    CiPrimitiveID primId,
	    CiRequestHandle reqHandle,
	    void*              paras)
{
	UNUSEDPARAM(opSgCnfHandle)

	UINT32 atHandle = GET_AT_HANDLE(reqHandle);
	
	#ifdef QUECTEL_NETWORK_SUPPORT
		Network_Info_Log("atHandle=%d, reqHandle=%d,primId=%d", atHandle, reqHandle,primId);
		char resBuf[200]={0};
	#endif

	/* Validate the para pointer */
	if ( (paras == NULL) && (primId < CI_DEV_PRIM_LAST_COMMON_PRIM) )
	{
		ERRMSG("para pointer of CI cnf msg is NULL!");
		return;
	}
	/*
	**  Determine the primitive being confirmed.
	*/
	switch (primId)
	{
		case CI_DEV_PRIM_GET_SERIALNUM_ID_CNF:
		{
			processGetSerialNumIdConf(atHandle, paras);
			break;
		}

		#ifndef MORE_ATC_SPACE_OPT 
		case CI_DEV_PRIM_SET_ENGMODE_REPORT_OPTION_CNF:
		{
			#ifdef AT_FOR_GW20180208SN
			if(gMMZRSSI == 3)
			{
				break;
			}
			#endif
			// for EEMOPT
			processSetEngModeReportOptionConf(atHandle, paras);
			break;
		}
		#endif		
		
		case CI_DEV_PRIM_GET_ENGMODE_INFO_CNF:
		{
			// for EEMOPT
			if(GET_REQ_ID(reqHandle) == CI_DEV_PRIM_GET_SINR_REQ)
			{
				processGetSinrConf(atHandle);
			}
			else if(GET_REQ_ID(reqHandle) == CI_DEV_PRIM_GET_RSSI_REQ)
			{
				processGetRssiConf(atHandle);
			}
			else if(GET_REQ_ID(reqHandle) == CI_DEV_PRIM_GET_CELL_INFO)
			{
				processGetCellinfoConf(atHandle, paras);
			}
			else
			{	
				char* quec_ResBuf = NULL;
				bool quec_ResBufSaved;
				
				quec_ResBufSaved = FALSE;
				if(quec_QengResDataLen)
				{
					quec_ResBuf = malloc(sizeof(char)*(quec_QengResDataLen+1));
					memset(quec_ResBuf,0,sizeof(char)*(quec_QengResDataLen+1));
					memcpy(quec_ResBuf,quec_QengResBuf,quec_QengResDataLen); /*copy cell info*/
					quec_ResBufSaved = TRUE;
					free(quec_QengResBuf); 
	                quec_QengResDataLen = 0;
	                quec_QengResBufLen = 0;
				}
				
				#ifdef QUECTEL_NETWORK_SUPPORT
				if(CHECK_BIT_SET(network_infor_bitmsk ,QNWINFO_GET))
				{
					BIT_CLR(network_infor_bitmsk, QNWINFO_GET);
				#if QUEC_DUAL_SIM_SUPPORT
					extern BOOL isHandleForSim0(UINT32 reqHandle);
					uint8 current_sim = isHandleForSim0(reqHandle) ? SIM1 : SIM2;
					sprintf(resBuf,"+QNWINFO: \"%s\",\"%s\",\"%s\",%d\r\n",quec_qnwinfo[current_sim].act,quec_qnwinfo[current_sim].plmn,quec_qnwinfo[current_sim].band_description,quec_qnwinfo[current_sim].active_channel);	 
				#else	
                    sprintf(resBuf,"+QNWINFO: \"%s\",\"%s\",\"%s\",%d\r\n",quec_qnwinfo.act,quec_qnwinfo.plmn,quec_qnwinfo.band_description,quec_qnwinfo.active_channel);
				#endif
					//connor 2018/12/04 when query netinfo did not need to enter Engineering mode just use EEMGINFO
					//DEV_SetEngModeIndicatorOption(atHandle, 0, 0);//close engmode
					ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
				}
				#if defined (__QUEC_OEM_VER_PAX__) || defined (QUEC_NETWORK_GET_ECNO)
				else if((TRUE == g_ecno_ci_send) && CHECK_BIT_SET(network_infor_bitmsk ,QENG_SERVINGCELL_GET))//Chaim 20190917 get ecno
				{
					BIT_CLR(network_infor_bitmsk, QENG_SERVINGCELL_GET);
					Network_Info_Log("atHandle=%d,ecno cnf", atHandle);
					g_ecno_ci_send = FALSE;
					quec_report_qcsq(1,resBuf);
					ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, quec_ResBuf);
				}
				#endif
				else if(CHECK_BIT_SET(network_infor_bitmsk ,QENG_SERVINGCELL_GET))
				{
					BIT_CLR(network_infor_bitmsk, QENG_SERVINGCELL_GET);
					ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, quec_ResBuf);
				}
				else if(CHECK_BIT_SET(network_infor_bitmsk ,QENG_NEIGHBOURCELL_GET))
				{
					BIT_CLR(network_infor_bitmsk, QENG_NEIGHBOURCELL_GET);
					ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, quec_ResBuf);
				}
				#ifndef ENABLE_DM_LTEONLY
				else if(CHECK_BIT_SET(network_infor_bitmsk ,QENG_3GCOMM_GET))
				{
					BIT_CLR(network_infor_bitmsk, QENG_3GCOMM_GET);
					ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, quec_ResBuf);
				}
				else if(CHECK_BIT_SET(network_infor_bitmsk ,QSMONC))
				{
					BIT_CLR(network_infor_bitmsk, QSMONC);
					ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, quec_ResBuf);
				}
				#endif
				#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
				else if(CHECK_BIT_SET(network_infor_bitmsk ,MCELL))
				{
					BIT_CLR(network_infor_bitmsk, MCELL);
					if(QUEC_FIBO_MCELL_SYSN == quec_fibo_mcell_show())
					{
						ATRESP(reqHandle, ATCI_RESULT_CODE_OK, 0, quec_ResBuf);
					}
					else if(QUEC_FIBO_MCELL_SYSN_EX == quec_fibo_mcell_show())
					{
                    #ifdef __QUEC_OEM_VER_NL__
                         quec_fibo_mcell_format(quec_ResBuf);
                    #else
						//ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, "\r\n",FALSE);
						quec_siolib_transmit_to_atp(GET_ATP_INDEX(atHandle), "\r\n", strlen("\r\n"), NULL);
                    #endif
						ATRESP(reqHandle, ATCI_RESULT_CODE_OK, 0, quec_ResBuf);
					}
					else if(QUEC_FIBO_MCELL_ASYN == quec_fibo_mcell_show())
					{
						quec_siolib_transmit_to_atp(GET_ATP_INDEX(atHandle), "\r\n", strlen("\r\n"), NULL);
						quec_siolib_transmit_to_atp(GET_ATP_INDEX(atHandle),(uint8 *)quec_ResBuf,strlen(quec_ResBuf),NULL);
					}
				}
				#endif
				#ifdef QUEC_ENGINEER_OUTPUT
				else if(CHECK_BIT_SET(network_infor_bitmsk ,QENG_ALL_INFO))
				{
					BIT_CLR(network_infor_bitmsk, QENG_ALL_INFO);
					//ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, quec_QengineerResBuf);
					ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
				}
				#endif	
				#ifdef QUECTEL_CELL
                else if(CHECK_BIT_SET(network_infor_bitmsk ,CELL_GET))
			    {
			    	BIT_CLR(network_infor_bitmsk, CELL_GET);
			        ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, quec_ResBuf);
                    if (1 == quec_get_qcellex())
                    {
                        memset(quec_cellex_info_buf,0,sizeof(quec_cellex_info_buf));
                        quec_qeng_cellex_info_max_limited(quec_ResBuf,strlen(quec_ResBuf));
                        if (strlen(quec_ResBuf) <= QUEC_CELLEX_INFO_MAX_LEN)
                        {
                            memcpy(quec_cellex_info_buf,quec_ResBuf,strlen(quec_ResBuf)); /*update cell info*/
                        }
                    }
			    }
				#endif
				#ifdef QUEC_RSRP_SUPPORT
				else if(CHECK_BIT_SET(network_infor_bitmsk ,RSRP_GET))
				{
					BIT_CLR(network_infor_bitmsk, RSRP_GET);
					ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, quec_ResBuf);
				}	   
				#endif
				#ifdef QUEC_QCELLINFO_SUPPORT
                else if(CHECK_BIT_SET(network_infor_bitmsk ,QCELLINFOEX_GET))
                {
                    BIT_CLR(network_infor_bitmsk, QCELLINFOEX_GET);
                    ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, quec_ResBuf);
                    if(quec_ResBuf)
                    {
                        quec_qeng_cellex_info_max_limited(quec_ResBuf,strlen(quec_ResBuf));
                        if (strlen(quec_ResBuf) <= QUEC_CELLEX_INFO_MAX_LEN)
                        {
                            /*qcellinfo 缓存与at+qcellex 共用quec_cellex_info_buf
                             *节省1k字节内存，因此两者只能取其一，不能同时使用at+qcellinfo和at+qcellex*/
                            memset(quec_cellex_info_buf,0,sizeof(quec_cellex_info_buf));
                            memcpy(quec_cellex_info_buf,quec_ResBuf,strlen(quec_ResBuf)); /*update cell info*/
                        }
                    }
                }
				#endif
				#ifdef QUEC_CCED_SUPPORT
				else if(CHECK_BIT_SET(network_infor_bitmsk ,QUEC_CCED_S_GET))
				{
					BIT_CLR(network_infor_bitmsk, QUEC_CCED_S_GET);
					ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, quec_ResBuf);
				}
				else if(CHECK_BIT_SET(network_infor_bitmsk ,QUEC_CCED_NB_GET))
				{
					BIT_CLR(network_infor_bitmsk, QUEC_CCED_NB_GET);
					ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, quec_ResBuf);
				}
				#endif
				#ifdef QUEC_QNWCFG_SUPPORT
				else if(CHECK_BIT_SET(network_infor_bitmsk ,QCQI_MCS_GET))
				{
					BIT_CLR(network_infor_bitmsk, QCQI_MCS_GET); 
					sprintf(resBuf,"+QNWCFG: \"lte_csi_ext\",1,%d,%d,-,%d,-,-,-,-\r\n",qnwcfg_csi_info.DLMCS0,qnwcfg_csi_info.DLMCS1,qnwcfg_csi_info.CQI);
					ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, resBuf); 
				}						
				#endif
				else
				#endif
					processGetEngModeInfoConf(atHandle, paras);
#ifdef QUECTEL_NETWORK_SUPPORT
				if(quec_ResBufSaved)
				{
					free(quec_ResBuf); 
				}
#endif
			
			}
			break;
		}

		/*Michal Bukai - AT*BAND support - END*/

		case CI_DEV_PRIM_SET_SV_CNF:
		{
			processSetSVConf(atHandle, paras);
			break;
		}

		case CI_DEV_PRIM_GET_SV_CNF:
		{
			processGetSVConf(atHandle, paras);
			break;
		}
#ifdef QUECTEL_CELL_SELECT_CFG
        case CI_DEV_PRIM_SET_CELL_SELECT_CFG_CNF:
        {
            CiDevPrimSetCellSelectCfgCnf *pCellSelectCfg = (CiDevPrimSetCellSelectCfgCnf *)paras;
                     
            if (NULL != pCellSelectCfg)
            {
                Network_Info_Log("[quec cell select cfg] CI_DEV_PRIM_SET_CELL_SELECT_CFG_CNF: rc: %d!\n", pCellSelectCfg->rc);
                if (pCellSelectCfg->rc == CIRC_DEV_SUCCESS)
                {
                    ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
                }
                else 
                {
                    ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                }
            }
            else 
            {
                Network_Info_Log("[quec cell select cfg] CI_DEV_PRIM_SET_CELL_SELECT_CFG_CNF: pCellSelectCfg is NULL");
                ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
            }
            break;
        }
                
        case CI_DEV_PRIM_GET_CELL_SELECT_CFG_CNF:
        {
            char RspBuf[128] = {0};
            CiDevPrimGetCellSelectCfgCnf *pGetCellSelCfg = (CiDevPrimGetCellSelectCfgCnf *)paras;
            if (NULL != pGetCellSelCfg)
            {
                Network_Info_Log("[quec cell select cfg] CI_DEV_PRIM_GET_CELL_SELECT_CFG_CNF: rc: %d\n", pGetCellSelCfg->rc);
                if (pGetCellSelCfg->rc == CIRC_DEV_SUCCESS)
                {
                    sprintf((char *)RspBuf, "+QCELLSELECTCFG: %d,%d,%d,%d,%d,%d,%d", 
                                 pGetCellSelCfg->offset_scell,
                                 pGetCellSelCfg->offset_scell_qual,
                                 pGetCellSelCfg->offset_ncell_lte,
                                 pGetCellSelCfg->offset_ncell_lte_qual,
                                 pGetCellSelCfg->offset_ncell_umts,
                                 pGetCellSelCfg->offset_ncell_umts_qual,
                                 pGetCellSelCfg->offset_ncell_gsm);
                        
                    ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, RspBuf);
                }
                else 
                {
                    ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                }
            }
            else 
            {
                Network_Info_Log("[quec cell select cfg] CI_DEV_PRIM_GET_CELL_SELECT_CFG_CNF: pCellSelectCfg is NULL");
                ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
            }
            break;
        }
#endif  
#ifndef MORE_ATC_SPACE_OPT		
		case CI_DEV_PRIM_AP_POWER_NOTIFY_CNF:
		{

			CiDevPrimApPowerNotifyCnf *apPowerNotifyCnf = (CiDevPrimApPowerNotifyCnf *)paras;
			if (apPowerNotifyCnf->rc == CIRC_DEV_SUCCESS)
				ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			else
				ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);

			break;
		}
#endif		
		case CI_DEV_PRIM_GET_REVISION_ID_CNF:
		{
			CiDevPrimGetRevisionIdCnf *revisionIdCnf = (CiDevPrimGetRevisionIdCnf *)paras;
			char *pRevisionId;
			
			pRevisionId = revisionId;
			DPRINTF("CI_DEV_PRIM_GET_REVISION_ID_CNF: rc: %d!\n", revisionIdCnf->rc);
			if (revisionIdCnf->rc == CIRC_DEV_SUCCESS)
			{
				memcpy(pRevisionId, revisionIdCnf->revisionStr.valStr, revisionIdCnf->revisionStr.len);
				pRevisionId[revisionIdCnf->revisionStr.len] = '\0';
				DPRINTF("CI_DEV_PRIM_GET_REVISION_ID_CNF: revisionID: %s!\n", pRevisionId);
			}
			break;
		}
#ifndef LTEONLY_THIN		
		case CI_DEV_PRIM_ENABLE_HSDPA_CNF:
		{
			processSetHsdpaModeConf(atHandle, paras);
			break;
		}
		case CI_DEV_PRIM_GET_HSDPA_STATUS_CNF:
		{
			processGetHsdpaModeConf(atHandle, paras);
			break;
		}
#endif		
		case CI_ERR_PRIM_HASNOSUPPORT_CNF:
		{
			ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
			break;
		}
		case CI_ERR_PRIM_HASINVALIDPARAS_CNF:
		{
			ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
			break;
		}
		case CI_ERR_PRIM_ISINVALIDREQUEST_CNF:
		{
			ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
			break;
		}
#ifdef AGPS_ENABLE		
		case CI_DEV_PRIM_LP_NWUL_MSG_CNF:
		{
			processlpNwulConf(atHandle, paras);
			break;
		}
#endif		
		case CI_DEV_PRIM_SET_LTE_MODE_TX_RX_CNF:
		{
			
			char rspBuf[50]="\0";
			CiDevPrimSetLteModeTxRxCnf *SetLteModeTxRxCnf = (CiDevPrimSetLteModeTxRxCnf *)paras;			
#ifdef QUECTEL_AT_RFTEST_SUPPORT 
			memset(rspBuf,0,sizeof(rspBuf));
			if(quec_ftm_state_flag)  
			{	
				sprintf(rspBuf,"+QRXFTM: %d,%d\r\n",SetLteModeTxRxCnf->rssiPri,SetLteModeTxRxCnf->rssiSec);  //rx need urc,tx no need
				quec_ftm_state_flag=0;	
			}
			if (SetLteModeTxRxCnf->rc == CIRC_DEV_SUCCESS)
				ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, rspBuf);
			else
				ATRESP(atHandle,ATCI_RESULT_CODE_SUPPRESS,0,(char*)"NG");		
#else		
			UINT8 *p_ltepower_flag;
			
#ifndef SINGLE_SIM			
			if (!GET_SIM1_FLAG(atHandle)) {
				p_ltepower_flag = &ltepower_flag;
			} else {
				p_ltepower_flag = &ltepower_flag_1;
			}
#else
			p_ltepower_flag = &ltepower_flag;
#endif

			//CPUartLogPrintf("ltepower_flag:%d",*p_ltepower_flag);
			if(*p_ltepower_flag == 1)
			{
				if (SetLteModeTxRxCnf->rc == CIRC_DEV_SUCCESS)
				{
					//sprintf(rspBuf,"+LTEPOWER:0,OK");
					sprintf(rspBuf,"+LTEPOWER:0,OK; RX:rssiPri=%d,rssiSec=%d",SetLteModeTxRxCnf->rssiPri,SetLteModeTxRxCnf->rssiSec);
				}
				else
				{
					sprintf(rspBuf,"+LTEPOWER:0,NG");
				}
				ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, rspBuf);
				*p_ltepower_flag = 0;
			}
#endif /* QUECTEL_AT_RFTEST_SUPPORT */
			break;
		}
		case CI_DEV_PRIM_GET_INTERNAL_REVISION_ID_CNF:
		{
			processGetInternalReversionCnf(atHandle, paras);
			/*Fixed coverity[unterminated_case]*/
			break;
		}
		case CI_DEV_PRIM_SET_POWER_BACK_OFF_CNF:
		{
			processSetPowerBackOffCnf(atHandle, paras);
			break;
		}
		case CI_DEV_PRIM_GET_COM_CONFIG_CNF:
		{
			UINT8 *p_comcfg_flag, *p_wbamr_flag;
#ifndef SINGLE_SIM			
			
						
			if (!GET_SIM1_FLAG(atHandle)) {
				p_comcfg_flag = &comcfg_flag;
				p_wbamr_flag = &wbamr_flag;
			} else {
				p_comcfg_flag = &comcfg_flag_1;
				p_wbamr_flag = &wbamr_flag_1;
			}
#else
			p_comcfg_flag = &comcfg_flag;
			p_wbamr_flag = &wbamr_flag;
#endif

			if(*p_comcfg_flag == 1)
			{
				processGetComConfigCnf(atHandle, paras);
				*p_comcfg_flag = 0;
			}
			else if(*p_wbamr_flag == 1)
			{
#ifndef LTEONLY_THIN			
				processGetWbAmrCnf(atHandle, paras);
#endif				
				*p_wbamr_flag = 0;
			}		
			break;
		}
		case CI_DEV_PRIM_SET_COM_CONFIG_CNF:
		{
			UINT8 *p_comcfg_flag, *p_wbamr_flag;
			
#ifndef SINGLE_SIM						
			if (!GET_SIM1_FLAG(atHandle)) {
				p_comcfg_flag = &comcfg_flag;
				p_wbamr_flag = &wbamr_flag;
			} else {
				p_comcfg_flag = &comcfg_flag_1;
				p_wbamr_flag = &wbamr_flag_1;
			}
#else
			p_comcfg_flag = &comcfg_flag;
			p_wbamr_flag = &wbamr_flag;
			
#endif

			if(*p_comcfg_flag == 1)
			{
				processSetComConfigCnf(atHandle, paras);
				*p_comcfg_flag = 0;
			}
			else if(*p_wbamr_flag == 1)
			{
#ifndef LTEONLY_THIN			
				processSetWbAmrCnf(atHandle, paras);
#endif				
				*p_wbamr_flag = 0;
			}
			break;
		}
#ifndef LTEONLY_THIN
		case CI_DEV_PRIM_GET_LTE_MEAS_CNF:
		{
			processGetLteMeasCnf(atHandle, paras);
			break;
		}
#endif		
		
		case CI_DEV_PRIM_SET_MCC_MNC_CC_CNF:
		{
			processSetMccMncCcReqCnf(atHandle, paras);
			break;
		}
		case CI_DEV_PRIM_READ_RF_TEMPERATURE_CNF:
		{
			processReadRFTemperatureCnf(atHandle, paras);
			break;
		}
		
		case CI_DEV_PRIM_GET_MCC_MNC_CC_CNF:
		{
			processGetMccMncCcReqCnf(atHandle, paras);
			break;
		}
		
#ifndef LTEONLY_THIN		
		case CI_DEV_PRIM_SET_LTE_COEX_REPORT_OPTION_CNF:
		{
			processSetLteCoexReportOptionCnf(atHandle, paras);
			break;
		}
		case CI_DEV_PRIM_GET_LTE_COEX_INFO_CNF:
		{
			processGetLteCoexInfoCnf(atHandle, paras);
			break;
		}
		case CI_DEV_PRIM_SET_IMLCONFIG_CNF:
		{
			processSetIMLConfigConf(atHandle, paras);	
			break;


		}
			
		case CI_DEV_PRIM_GET_IMLCONFIG_CNF:
		{
			processGetIMLConfigConf(atHandle, paras);	
			break;
		}
		
		#ifdef PLATFORM_FOR_PS_LW
		case CI_DEV_PRIM_SET_LTE_BAND_ORDER_CNF:
		{
			processSetLTEBandConf(atHandle, paras);	
			break;
		}

		case CI_DEV_PRIM_GET_LTE_BAND_ORDER_CNF:
		{
			processGetLTEBandConf(atHandle, paras); 
			break;
		}
		#endif
#endif	
#ifdef AGPS_ENABLE
		case CI_DEV_PRIM_LP_ECID_MEAS_CNF:
		{
			processLpECIDMeasCnf(atHandle, paras);
			break;
		}

		case CI_DEV_PRIM_LP_OTDOA_MEAS_CNF:
		{
			processLpOtdoaMeasCnf(atHandle, paras);
			break;
		}

		case CI_DEV_PRIM_LP_OTDOA_MEAS_ABORT_CNF:
		{
			processLpOtdoaAbortCnf(atHandle, paras);
			break;
		}
#endif
#ifndef LTEONLY_THIN
#ifdef PLATFORM_FOR_PS_LW
		case CI_DEV_PRIM_SET_SALES_CODE_CNF:
		{
			
			processSetCscConf(atHandle, paras); 
			break;
		}

		case CI_DEV_PRIM_GET_SALES_CODE_CNF:
		{
			processGetCscConf(atHandle, paras); 
			break;
		}
#endif
#endif        
		case CI_DEV_PRIM_SET_OPER_CONFIG_CNF:
		{
			
			processSetOperCfgConf(atHandle, paras); 
			break;
		}
		
		case CI_DEV_PRIM_GET_OPER_CONFIG_CNF:
		{	
			processGetOperCfgConf(reqHandle, paras); 
			break;
		}


		case CI_DEV_PRIM_MRD_CONFIG_CNF:
		{			
			CiDevPrimCpMrdOperCnf *CpMrdOperCnf = (CiDevPrimCpMrdOperCnf *)paras;
			checkDevRet(atHandle, CpMrdOperCnf->rc);
			break;
		}
#ifndef LTEONLY_THIN

		case CI_DEV_PRIM_SET_GSM_MODE_TX_RX_CNF:
		{
			processSetGsmModeTxRxConf(atHandle, paras);
			break;
		}
#endif		
		case CI_DEV_PRIM_SET_L1DEBUG_CNF:
		{
			processL1DebugCnf(atHandle, paras);
			break;
		}
#if defined(QUEC_BLACK_CELL_SUPPORT)|| defined(QUEC_THIN_BLACK_CELL_SUPPORT)
		case CI_DEV_PRIM_SET_BLACK_CELL_CNF:
		{
			processSetBlackCellConf(atHandle,paras);
			break;
		}
		case CI_DEV_PRIM_GET_BLACK_CELL_CNF:
		{
			processGetBlackCellConf(atHandle,paras);
			break;
		}
#endif
		default:
		{
			break;
		}
	}

	/* free up the confirmation memory */
//	atciSvgFreeCnfMem( svgId, primId, paras );

	return;
}

/****************************************************************************************
*
*  DESCRIPTION: Code to process indication message
*
****************************************************************************************/
#define UMTS_EM_IND_NUM_MAX 4 // totally 4 indication for UMTS.
#define EngmodeInfoEachMaxLen 100
#define EM_INFO_OUTPUT(s) ATRESP((reqHandle), 0, 0, (s))

#ifdef QUECTEL_NETWORK_SUPPORT
int8 quec_assemble_qeng_resp(char * start, char * end)
{
    uint32 to_add_len = end-start;
    if (to_add_len >= QUEC_QENG_RESBUFLEN_MIN)
    {
        Network_Info_Log("to_add_len=%d error", to_add_len);
        return -1;
    }
    if (to_add_len+1 > quec_QengResBufLen-quec_QengResDataLen)//add the end character
    {
        if (quec_QengResBufLen >= QUEC_QENG_RESBUFLEN_MAX)
        {
            Network_Info_Log("quec_QengResBufLen=%d error", quec_QengResBufLen);
            return -1;
        }
        char * new_qeng_buf = NULL;
        new_qeng_buf = realloc(quec_QengResBuf, quec_QengResBufLen+QUEC_QENG_RESBUFLEN_MIN);
        if (NULL == new_qeng_buf)
        {
            Network_Info_Log("quec_QengResBuf realloc error", quec_QengResBufLen);
            return -1;//do not free here, free it when AT Resp
        
        }
        quec_QengResBuf = new_qeng_buf;
        memset(quec_QengResBuf+quec_QengResBufLen, 0, QUEC_QENG_RESBUFLEN_MIN);
        quec_QengResBufLen += QUEC_QENG_RESBUFLEN_MIN;
    }
    strcat(quec_QengResBuf, start);
    quec_QengResDataLen += to_add_len;
    Network_Info_Log("Buf=%p, len=%d, data_len=%d,%d,%s", quec_QengResBuf, quec_QengResBufLen, quec_QengResDataLen, to_add_len, start);

    return 1;
}
#endif

#if defined(QUEC_BLACK_CELL_SUPPORT)|| defined(QUEC_THIN_BLACK_CELL_SUPPORT)
quec_blackcell_item_s_t g_quec_blackcell_lte[QUEC_BLACKCELL_REJECT_COUNT_MAX] = {0};

/*set gsm,wcdma,lte cell to black cell list or delete gsm,wcdma,lte cell from black cell list*/
void quec_gwl_blackcell_process(UINT32 arfcn,UINT16 bsic,UINT8 rat,UINT8 optype)
{
	quec_cellid_s_t gwl_black_cell = {0};

	gwl_black_cell.arfcn = arfcn;
	gwl_black_cell.cellid = bsic;
	gwl_black_cell.rat = rat;
	gwl_black_cell.Optype = optype;
	
	quec_send_msg_to_handle_task(QUEC_GWL_BLACKCELL_PROCESS_MSG, (char *)&gwl_black_cell, sizeof(quec_cellid_s_t));
}
#endif

#ifdef QUEC_BLACK_CELL_SUPPORT
void quec_update_ltecellid_to_blackcell_check(UINT32 arfcn,UINT16 cell_id,UINT8 rat,UINT8 optype)
{
	UINT8 i = 0;
	static UINT8 quec_lteblackcell_mode = 0;
	static UINT8 quec_lteblackcell_num = 0;
	static UINT8 quec_lteblackcell_count[QUEC_BLACKCELL_REJECT_COUNT_MAX] = {0};//accumulate
	bool IsVaild = FALSE;
	int tempindex = -1; 
    UINT8 mincount = 0; 	
    UINT8 minindex = 0; 
	static UINT32 tick_mark = 0;
	static UINT32 tick_count = 0;
	UINT32 tick_temp = 0;

	tick_temp = OSAGetTicks();
	CPUartLogPrintf("quec_black update_ltecellid_to_blackcell_check: current_tick %ld tick_mark %ld tick_count %ld fence %ld",
						tick_temp,tick_mark,tick_count,quec_get_black_cell_reject_judge_num()*720000);
	if(tick_mark != 0)
	{
		tick_count += (tick_temp - tick_mark);
		//T3402 12min-720000ms
		if((tick_count*5) >= quec_get_black_cell_reject_judge_num()*720000)
		{
			tick_mark = 0;
			tick_count = 0;
			quec_lteblackcell_num = 0;
			memset(g_quec_blackcell_lte,0,sizeof(g_quec_blackcell_lte));
			memset(quec_lteblackcell_count,0,sizeof(quec_lteblackcell_count));
			CPUartLogPrintf("quec_black update_ltecellid_to_blackcell_check: tick clear");
		}
	}
	tick_mark = tick_temp;
		
	if((arfcn == 0) || (arfcn == 0xFFFFFFFF))
	{
		CPUartLogPrintf("quec_update_ltecellid_to_blackcell_check: cell invaild");
	    return;
	}

	if(quec_lteblackcell_mode != quec_get_black_cell_reject_judge_mode())
	{
		CPUartLogPrintf("quec_black update_ltecellid_to_blackcell_check: mode %d to %d clear",quec_lteblackcell_mode,quec_get_black_cell_reject_judge_mode());
		quec_lteblackcell_mode = quec_get_black_cell_reject_judge_mode();
		quec_lteblackcell_num = 0;
		memset(g_quec_blackcell_lte,0,sizeof(g_quec_blackcell_lte));
		memset(quec_lteblackcell_count,0,sizeof(quec_lteblackcell_count));
	}

	if(quec_get_black_cell_reject_judge_mode() == QUEC_BLACK_ELECTRIC_FENCE_CONTINUOUS_JUDGE)
	{
		if(quec_get_oneshot_type() != BLACKCELL_ATTACH_SUCCESS)
		{	
			g_quec_blackcell_lte[quec_lteblackcell_num].arfcn = arfcn;
			g_quec_blackcell_lte[quec_lteblackcell_num].cell_id = cell_id;
			g_quec_blackcell_lte[quec_lteblackcell_num].event = quec_get_oneshot_type();
			
			if(quec_lteblackcell_num > 0)
			{
				if ((g_quec_blackcell_lte[quec_lteblackcell_num].arfcn != g_quec_blackcell_lte[quec_lteblackcell_num-1].arfcn) || 
					(g_quec_blackcell_lte[quec_lteblackcell_num].cell_id != g_quec_blackcell_lte[quec_lteblackcell_num-1].cell_id)|| 
					(g_quec_blackcell_lte[quec_lteblackcell_num].event != g_quec_blackcell_lte[quec_lteblackcell_num-1].event))
				{
					CPUartLogPrintf("quec_black update_ltecellid_to_blackcell_check: find different cellid not set blackcell list");
					quec_lteblackcell_num = 0;
					
					g_quec_blackcell_lte[0].arfcn = arfcn;
					g_quec_blackcell_lte[0].cell_id = cell_id;
					g_quec_blackcell_lte[0].event = quec_get_oneshot_type();
				}
			}

			if(quec_get_oneshot_type() == BLACKCELL_REGISTER_TIMEOUT)
			{
				// this event is reported every five times it is triggered, so every report counts five times
				if (((quec_lteblackcell_num+1)*5) >= quec_get_black_cell_reject_judge_num())
				{
					quec_electric_fence_list_set_blackcell(optype,rat,g_quec_blackcell_lte[quec_lteblackcell_num].arfcn,
								g_quec_blackcell_lte[quec_lteblackcell_num].cell_id,quec_get_black_event_weight(FENCE_NAS_TIMEOUT_EVENT),FENCE_NAS_TIMEOUT_EVENT);

					quec_lteblackcell_num = 0; //clear
				}
				else 
				{ 	
					quec_lteblackcell_num++;
					CPUartLogPrintf("quec_black update_ltecellid_to_blackcell_check: continuous arfcn %d cell_id %d count update %d event %d",arfcn,cell_id,quec_lteblackcell_num,quec_get_oneshot_type());
				}	
			}
			else 
			{
				if ((quec_lteblackcell_num+1) == quec_get_black_cell_reject_judge_num())
				{
					if (QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg_ex())
				   	{
						if(quec_get_oneshot_type() == BLACKCELL_REGISTER_SERVICE_REJECT)
						{
							quec_electric_fence_list_set_blackcell(optype,rat,g_quec_blackcell_lte[quec_lteblackcell_num].arfcn,
								g_quec_blackcell_lte[quec_lteblackcell_num].cell_id,quec_get_black_event_weight(FENCE_NAS_REJECT_EVENT),FENCE_NAS_REJECT_EVENT);
						}
						else if(quec_get_oneshot_type() == BLACKCELL_SERVICE_TIMEOUT)
						{
							quec_electric_fence_list_set_blackcell(optype,rat,g_quec_blackcell_lte[quec_lteblackcell_num].arfcn,
								g_quec_blackcell_lte[quec_lteblackcell_num].cell_id,quec_get_black_event_weight(FENCE_NAS_SERVICE_NOT_RECEIVE),FENCE_NAS_SERVICE_NOT_RECEIVE);
						}
				   	}
					else if (QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg())
					{
						if(quec_get_oneshot_type() == BLACKCELL_REGISTER_SERVICE_REJECT)
						{
							quec_gwl_blackcell_process(g_quec_blackcell_lte[quec_lteblackcell_num].arfcn,g_quec_blackcell_lte[quec_lteblackcell_num].cell_id,rat,optype);
						}
					}

					quec_lteblackcell_num = 0; //clear
				}
				else
				{ 	
					quec_lteblackcell_num++;
					CPUartLogPrintf("quec_black update_ltecellid_to_blackcell_check: continuous arfcn %d cell_id %d count update %d event %d",arfcn,cell_id,quec_lteblackcell_num,quec_get_oneshot_type());
				}
			}

			quec_set_oneshot_flag(FALSE);
			return;
		}
		else if(quec_get_oneshot_type() == BLACKCELL_ATTACH_SUCCESS)
		{
			if ((g_quec_blackcell_lte[0].arfcn == arfcn) && 
				(g_quec_blackcell_lte[0].cell_id == cell_id))
			{
				quec_lteblackcell_num = 0; //clear
				quec_set_oneshot_flag(FALSE);
				return;
			}
			
		}
	}
	else if(quec_get_black_cell_reject_judge_mode() == QUEC_BLACK_ELECTRIC_FENCE_ACCUMULATE_JUDGE)
	{
		if(quec_get_oneshot_type() != BLACKCELL_ATTACH_SUCCESS)
		{			
			for(i=0; i<quec_lteblackcell_num; i++)
			{
				if ((g_quec_blackcell_lte[i].arfcn == arfcn) && 
					(g_quec_blackcell_lte[i].cell_id == cell_id))
				{
					tempindex = i;
				    IsVaild = TRUE;
					if(g_quec_blackcell_lte[i].event == quec_get_oneshot_type())
					{
						quec_lteblackcell_count[i]++;
						CPUartLogPrintf("quec_black update_ltecellid_to_blackcell_check: index %d arfcn %d cell_id %d count accumulate update %d event %d",i,arfcn,cell_id,quec_lteblackcell_count[i],quec_get_oneshot_type());
					}
					else 
					{
						g_quec_blackcell_lte[i].event = quec_get_oneshot_type();
						quec_lteblackcell_count[i] = 1;
						CPUartLogPrintf("quec_black update_ltecellid_to_blackcell_check: index %d arfcn %d cell_id %d count init update %d event  %d",i,arfcn,cell_id,1,quec_get_oneshot_type())
					}
				}
			}

			if(IsVaild == FALSE)
			{
				if(quec_lteblackcell_num < QUEC_BLACKCELL_REJECT_COUNT_MAX)
				{
					tempindex = quec_lteblackcell_num;
					g_quec_blackcell_lte[quec_lteblackcell_num].arfcn = arfcn; 
					g_quec_blackcell_lte[quec_lteblackcell_num].cell_id = cell_id;
					g_quec_blackcell_lte[quec_lteblackcell_num].event = quec_get_oneshot_type();
					quec_lteblackcell_count[quec_lteblackcell_num] = 1;
					quec_lteblackcell_num++; //index
					
					CPUartLogPrintf("quec_black update_ltecellid_to_blackcell_check: index %d arfcn %d cell_id %d count init update %d event %d",quec_lteblackcell_num,arfcn,cell_id,1,quec_get_oneshot_type());
				}
				else if (quec_lteblackcell_num == QUEC_BLACKCELL_REJECT_COUNT_MAX)
				{
					mincount = quec_lteblackcell_count[0];
					minindex = 0;
					for(i=0; i<quec_lteblackcell_num; i++)
					{
						if (quec_lteblackcell_count[i] < mincount)
						{
							mincount = quec_lteblackcell_count[i];
							minindex = i;
						}
					}

					tempindex = minindex;
					g_quec_blackcell_lte[minindex].arfcn = arfcn; 
					g_quec_blackcell_lte[minindex].cell_id = cell_id;
					g_quec_blackcell_lte[minindex].event = quec_get_oneshot_type();
					quec_lteblackcell_count[minindex] = 1;	
					
					CPUartLogPrintf("quec_blackupdate_ltecellid_to_blackcell_check: change index %d arfcn %d cell_id %d count init update %d event %d",minindex,arfcn,cell_id,1,quec_get_oneshot_type());
				}
				else
				{
					CPUartLogPrintf("quec_update_ltecellid_to_blackcell_check: quec_lteblackcell_num %d is invaild",quec_lteblackcell_num);
				}
			}

			if(tempindex != -1)
			{
				if(quec_get_oneshot_type() == BLACKCELL_REGISTER_TIMEOUT)
				{
					if((quec_lteblackcell_count[tempindex]*5) >= quec_get_black_cell_reject_judge_num())
					{
						quec_electric_fence_list_set_blackcell(optype,rat,g_quec_blackcell_lte[tempindex].arfcn,
							g_quec_blackcell_lte[tempindex].cell_id,quec_get_black_event_weight(FENCE_NAS_TIMEOUT_EVENT),FENCE_NAS_TIMEOUT_EVENT);

						quec_lteblackcell_count[tempindex] = 0;
					}
				}
				else 
				{
					if(quec_lteblackcell_count[tempindex] == quec_get_black_cell_reject_judge_num())
					{
						if (QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg_ex())
						{
							if(quec_get_oneshot_type() == BLACKCELL_REGISTER_SERVICE_REJECT)
							{
								quec_electric_fence_list_set_blackcell(optype,rat,g_quec_blackcell_lte[tempindex].arfcn,
									g_quec_blackcell_lte[tempindex].cell_id,quec_get_black_event_weight(FENCE_NAS_REJECT_EVENT),FENCE_NAS_REJECT_EVENT);
							}
							else if(quec_get_oneshot_type() == BLACKCELL_SERVICE_TIMEOUT)
							{
								quec_electric_fence_list_set_blackcell(optype,rat,g_quec_blackcell_lte[tempindex].arfcn,
									g_quec_blackcell_lte[tempindex].cell_id,quec_get_black_event_weight(FENCE_NAS_SERVICE_NOT_RECEIVE),FENCE_NAS_SERVICE_NOT_RECEIVE);
							}
						}
						else if (QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg())
						{
							if(quec_get_oneshot_type() == BLACKCELL_REGISTER_SERVICE_REJECT)
							{
								quec_gwl_blackcell_process(g_quec_blackcell_lte[tempindex].arfcn,g_quec_blackcell_lte[tempindex].cell_id,rat,optype);
							}
						}
						
						quec_lteblackcell_count[tempindex] = 0;
					}
				}
			}
		
			quec_set_oneshot_flag(FALSE);
			return;
		}
		else if(quec_get_oneshot_type() == BLACKCELL_ATTACH_SUCCESS)
		{
			for(i=0; i<quec_lteblackcell_num; i++)
			{
				if ((g_quec_blackcell_lte[i].arfcn == arfcn) && 
					(g_quec_blackcell_lte[i].cell_id == cell_id))
				{
				    IsVaild = TRUE;
					quec_lteblackcell_count[i] = 0;
					CPUartLogPrintf("quec_black update_ltecellid_to_blackcell_check: index %d arfcn %d cell_id %d count clear %d event %d",i,arfcn,cell_id,quec_lteblackcell_count[i],quec_get_oneshot_type());
					quec_set_oneshot_flag(FALSE);
					return;
				}
			}
		}
	}

	quec_set_oneshot_flag(FALSE);
	return;
}
#elif defined (QUEC_THIN_BLACK_CELL_SUPPORT)
UINT8 quec_blackcell_reject_threshold = 5;
void quec_update_ltecellid_to_blackcell_check(UINT32 arfcn,UINT16 cell_id,UINT8 rat,UINT8 optype)
{
    UINT8 i = 0;
    UINT8 black_cell_set_flag = TRUE;
    static UINT8 quec_lteblackcell_num = 0;
    
    if (quec_lteblackcell_num >= quec_blackcell_reject_threshold)
    {
        CPUartLogPrintf("quec blackcell: blackcell num %d is overflow",quec_lteblackcell_num);
        quec_lteblackcell_num = 0;
        return;
    }

    g_quec_blackcell_lte[quec_lteblackcell_num].arfcn = arfcn;
    g_quec_blackcell_lte[quec_lteblackcell_num].cell_id = cell_id;

    if (quec_lteblackcell_num == quec_blackcell_reject_threshold-1)
    {
        for (i=0;i < quec_blackcell_reject_threshold-1;i++)
        {
            if ((g_quec_blackcell_lte[i].arfcn != g_quec_blackcell_lte[i+1].arfcn) || 
                (g_quec_blackcell_lte[i].cell_id != g_quec_blackcell_lte[i+1].cell_id))
            {
                quec_lteblackcell_num = 0;
                black_cell_set_flag = FALSE;
                break;
            }
        }
		
        if ((quec_lteblackcell_num != 0) && (TRUE == black_cell_set_flag))
        {
            quec_gwl_blackcell_process(g_quec_blackcell_lte[0].arfcn,g_quec_blackcell_lte[0].cell_id,rat,optype);
            quec_set_oneshot_flag(FALSE);
            quec_lteblackcell_num = 0; //clear
        }
        else 
        {
            CPUartLogPrintf("quec blackcell: find different cellid not set blackcell list");
            quec_lteblackcell_num = 0; //clear
        }
    }
    else 
    {
        quec_lteblackcell_num++;
    }
    return;
}
#endif

#ifdef QUEC_CCED_SUPPORT
extern int quec_cced_mode;
extern int quec_requested_dump;
int quec_cced_lteneigmaximum;
#endif

#ifdef PLATFORM_FOR_PS_LW

/****************************************************************
 *  F@: processEEMOPTInfoInd - Process engine mode info ind msg
 */
static void processEEMOPTInfoInd(UINT32 reqHandle, const void *pParam)
{
	CiDevPrimGsmEngmodeInfoInd * pGsmEngmodeInfoInd;
	CiDevEngModeGsmData* pGSMEngModeInfo;
	CiDevGsmServingCellInfo * pSVCCellInfo;
	CiDevGPRSPTMInfo * pGPRSPTMInfo;
	CiDevGsmGMMInfo * pGMMInfo;
	CiDevEngModeReportOption *pEngModeRepOpt;
	char resBuf[500];
	char tempBuf[50];
	UINT8 cellNUM;
	
#if defined QUEC_CODECHECK_MODIFICATION_ASR
	memset(tempBuf, 0, sizeof(tempBuf));
#endif

	if (reqHandle == IND_REQ_HANDLE) {
		pEngModeRepOpt = &gEngModeRepOpt;
	} else {
		pEngModeRepOpt = &gEngModeRepOpt_1;
	}

	pGsmEngmodeInfoInd = (CiDevPrimGsmEngmodeInfoInd *)pParam;
	pGSMEngModeInfo = &(pGsmEngmodeInfoInd->info);
	pSVCCellInfo = &(pGSMEngModeInfo->svcCellInfo);
	pGPRSPTMInfo = &(pGSMEngModeInfo->GPRSPTMInfo);
	pGMMInfo = &(pGSMEngModeInfo->GMMInfo);

	gcell_lac = pSVCCellInfo->lac;
	gcell_ci  = pSVCCellInfo->ci;
	gcell_mcc = pSVCCellInfo->mcc;
	gcell_mnc = pSVCCellInfo->mnc;
#ifdef QUECTEL_NETWORK_SUPPORT
	char *p;
	char state[20]={0};
#ifdef __QUEC_OEM_VER_LD__
	char					   lac_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   cid_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   bsic_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   arfcn_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   plmn_buf[LANDI_VAL_BUF_MAX] ={0};
	UINT8					   uiCnt=0;
#endif 

	if(CHECK_BIT_SET(network_infor_bitmsk ,QNWINFO_GET))
	{
	#if QUEC_DUAL_SIM_SUPPORT
		Quec_qnwinfo_type *p_quec_qnwinfo = &quec_qnwinfo[(reqHandle == IND_REQ_HANDLE) ? SIM1 : SIM2)];
	#else
		Quec_qnwinfo_type *p_quec_qnwinfo = &quec_qnwinfo;
	#endif		

		Network_Info_Log("processEMLteINFOSVCInfoInd,band=%d,dlEuArfcn=%d",pSVCCellInfo->gsmBand,pSVCCellInfo->arfcn);
		sprintf( &p_quec_qnwinfo->plmn[0],
					"%03x%02x",
					pSVCCellInfo->mcc,
					pSVCCellInfo->mnc );
	
		if(pSVCCellInfo->gsmBand==0 ||pSVCCellInfo->gsmBand==3)
		{	 
			sprintf( &p_quec_qnwinfo->band_description[0],"GSM 900");
		}
		else if(pSVCCellInfo->gsmBand==1 )
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"GSM 1800");
		}
		else if(pSVCCellInfo->gsmBand==2 )
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"GSM 1900");
		}
		else if(pSVCCellInfo->gsmBand==4 )
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"GSM 450");
		}
		else if(pSVCCellInfo->gsmBand==5 )
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"GSM 480");
		}
		else if(pSVCCellInfo->gsmBand==6 )
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"GSM 850");
		}
		else 
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"GSM BAND UNKNOWN");
		}

		
		if(pSVCCellInfo->EGPRSSupport)
		{
			sprintf( &p_quec_qnwinfo->act[0],"EDGE");
		}
		else if(p_quec_qnwinfo->service_domain==1 || p_quec_qnwinfo->service_domain==2)
		{
			sprintf( &p_quec_qnwinfo->act[0],"GPRS");
		}
		else
		{
			sprintf( &p_quec_qnwinfo->act[0],"GSM");
		}
		p_quec_qnwinfo->active_channel=pSVCCellInfo->arfcn;
		
		#ifdef QUECTEL_OPEN_CPU
		if(!IsMiniSystem())
		{
			quec_nw_event_ind(reqHandle, p_quec_qnwinfo->act, QUEC_NW_EVENT_ACT_INFO);
		}
		#endif
		//sprintf(resBuf,"+QNWINFO: \"%s\",\"%s\",\"%s\",%d",quec_qnwinfo.act,quec_qnwinfo.plmn,quec_qnwinfo.band_description,quec_qnwinfo.active_channel);    
		//ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
		
		//DEV_SetEngModeIndicatorOption(atHandle, 0, 0);//close engmode
		//BIT_CLR(network_infor_bitmsk, QNWINFO_GET);
	}
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_SERVINGCELL_GET))
	{
			#ifdef __QUEC_OEM_VER_PAX__
			CiDevGsmServingCellInfo last_scell_param ={0};
			INT16     last_rscp = 0;
			INT16     last_cpichEcN0 =0;
			static  bool last_gsm_scell_ok_flag = FALSE;
			
		Network_Info_Log("servingcell_test,gsm,mcc=%d,mnc=%d,ci=%d",pSVCCellInfo->mcc,pSVCCellInfo->mnc,pSVCCellInfo->ci);
		//Chaim 20200803 invalid mcc mnc 
		if(((QUEC_ENG_INVALID_VALUE== pSVCCellInfo->mcc)||(0 == pSVCCellInfo->mcc)||
			(QUEC_ENG_INVALID_VALUE== pSVCCellInfo->mnc)||
			(0== pSVCCellInfo->ci)||(QUEC_ENG_INVALID_VALUE == pSVCCellInfo->ci))
			&&(TRUE == last_gsm_scell_ok_flag))
		{
			
			Network_Info_Log("servingcell_test last_servingcell,mcc=%d,mnc=%d,ci=%d",pSVCCellInfo->mcc,pSVCCellInfo->mnc,pSVCCellInfo->ci);
			last_scell_param.mcc = pSVCCellInfo->mcc;
			last_scell_param.mnc = pSVCCellInfo->mnc;
			last_scell_param.lac = pSVCCellInfo->lac;
			last_scell_param.ci = pSVCCellInfo->ci;
			last_scell_param.bsic = pSVCCellInfo->bsic;
			last_scell_param.arfcn = pSVCCellInfo->arfcn;
			last_scell_param.lenOfMnc = pSVCCellInfo->lenOfMnc;
			last_scell_param.gsmBand = pSVCCellInfo->gsmBand;
			last_scell_param.rxSigLevel = pSVCCellInfo->rxSigLevel;
			last_scell_param.RLA = pSVCCellInfo->RLA;
			last_scell_param.TxPowerLevel = pSVCCellInfo->TxPowerLevel;
			last_scell_param.C1 = pSVCCellInfo->C1;
			last_scell_param.C2 = pSVCCellInfo->C2;
			last_scell_param.EGPRSSupport = pSVCCellInfo->EGPRSSupport;
		}
		else
		{
			last_gsm_scell_ok_flag = TRUE;
		}
		#endif
		quec_qeng_get_currrent_state(state);
        memset(resBuf, 0, sizeof(resBuf));
		p = resBuf;
		p+=sprintf(p, "+QENG: \"%s\",\"%s\",\"%s\",%3X","servingcell",state,"GSM",pSVCCellInfo->mcc);
		
		if(pSVCCellInfo->lenOfMnc==3)
		{
			p+=sprintf(p, ",%03X",pSVCCellInfo->mnc);
		}
		else
		{
			p+=sprintf(p, ",%02X",pSVCCellInfo->mnc);
		}
#ifdef __QUEC_OEM_VER_LD__
		if (TRUE == Quectel_IsOEMLandiEnable())
		{

			GET_VALID_VAL(lac_buf, pSVCCellInfo->lac);
			GET_VALID_VAL(cid_buf, pSVCCellInfo->ci);
			GET_VALID_VAL(bsic_buf, pSVCCellInfo->bsic);
			GET_VALID_VAL(arfcn_buf, pSVCCellInfo->arfcn);
			p+=sprintf(p, ",%s,%s,%s,%s", 
							lac_buf,
							cid_buf,
							bsic_buf,
							arfcn_buf);
		}
		else
#endif
		p+=sprintf(p, ",%X,%X,%d,%d", 
						pSVCCellInfo->lac,
						pSVCCellInfo->ci,
						pSVCCellInfo->bsic,
						pSVCCellInfo->arfcn);
	
		//to be consistent with Qualcomm
		if(pSVCCellInfo->gsmBand==1 )
		{
			p+=sprintf(p, ",%d", 0); //GSM_1800
		}
		else if(pSVCCellInfo->gsmBand==2 )
		{
			p+=sprintf(p, ",%d", 1); //GSM_1900
		}
		else if(pSVCCellInfo->gsmBand==0 ||pSVCCellInfo->gsmBand==3 )
		{
			p+=sprintf(p, ",%d", 2); //GSM_900
		}
		else
		{
			p+=sprintf(p, ",-");
		}

		//to be consistent with Qualcomm
		if(pSVCCellInfo->rxSigLevel <=63  )
		{
			p+=sprintf(p, ",%d", pSVCCellInfo->rxSigLevel-111);
		}
		else
		{
			p+=sprintf(p, ",%d",63-111);
		}

		p+=sprintf(p, ",%d,%d,%d,%d,%d,%d", 
						pSVCCellInfo->RLA,
						pSVCCellInfo->TxPowerLevel,
						0,	  //pSVCCellInfo->DRX  to be consistent with Qualcomm
						pSVCCellInfo->C1,
						pSVCCellInfo->C2,
						pSVCCellInfo->EGPRSSupport);
#if 0
		if(quec_audio_get_call_status())
#else
		if(quec_led_get_call_status())
#endif
		{
			p+=sprintf(p, ",-,-,-,-,-,-,-,-,-,\"-\""); 
		}
		else 
		{
			p+=sprintf(p, ",-,-,-,-,-,-,-,-,-,\"-\""); 
			//when we support voice call add code here
		}

		p+=sprintf(p, "\r\n");
        if (1 != quec_assemble_qeng_resp(resBuf, p))
        {
            return;
        }
			#ifdef __QUEC_OEM_VER_PAX__
			
			pSVCCellInfo->mcc=last_scell_param.mcc;
			pSVCCellInfo->mnc =last_scell_param.mnc;
			pSVCCellInfo->lac =last_scell_param.lac;
			pSVCCellInfo->ci =last_scell_param.ci;
			pSVCCellInfo->bsic = last_scell_param.bsic;
			pSVCCellInfo->arfcn =last_scell_param.arfcn;
			pSVCCellInfo->lenOfMnc =last_scell_param.lenOfMnc;
			pSVCCellInfo->gsmBand =last_scell_param.gsmBand;
			pSVCCellInfo->rxSigLevel =last_scell_param.rxSigLevel;
			pSVCCellInfo->RLA =last_scell_param.RLA;
			pSVCCellInfo->TxPowerLevel =last_scell_param.TxPowerLevel;
			pSVCCellInfo->C1 =last_scell_param.C1;
			pSVCCellInfo->C2 =last_scell_param.C2 ;
			pSVCCellInfo->EGPRSSupport=last_scell_param.EGPRSSupport;
		#endif
	}
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_NEIGHBOURCELL_GET))
	{
		UINT8 lenofmnc=2;//wait asr to support ,add this api
		
		//neighber cell of GSM
		Network_Info_Log("numNCells=%d,numInterRATNCells=%d,numNcellLte=%d", pGSMEngModeInfo->numNCells,pGSMEngModeInfo->numInterRATNCells,pGSMEngModeInfo->nCellInfoListLte.numNcellLte);
		for (cellNUM = 0; cellNUM < pGSMEngModeInfo->numNCells; cellNUM++)
		{
			if( pGSMEngModeInfo->nbCellInfo[cellNUM].ci ==0 )
				continue;
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
			p+=sprintf(p, "+QENG: \"%s\",\"%s\",%3X","neighbourcell","GSM",pGSMEngModeInfo->nbCellInfo[cellNUM].mcc);

			if(lenofmnc==3)
			{
				p+=sprintf(p, ",%03X",pGSMEngModeInfo->nbCellInfo[cellNUM].mnc);
			}
			else
			{
				p+=sprintf(p, ",%02X",pGSMEngModeInfo->nbCellInfo[cellNUM].mnc);
			}
			
	#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(lac_buf,0,sizeof(lac_buf));
				memset(cid_buf,0,sizeof(cid_buf));
				memset(bsic_buf,0,sizeof(bsic_buf));
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				GET_VALID_VAL(lac_buf, pGSMEngModeInfo->nbCellInfo[cellNUM].lac);
				GET_VALID_VAL(cid_buf, pGSMEngModeInfo->nbCellInfo[cellNUM].ci);
				GET_VALID_VAL(bsic_buf, pGSMEngModeInfo->nbCellInfo[cellNUM].bsic);
				GET_VALID_VAL(arfcn_buf, pGSMEngModeInfo->nbCellInfo[cellNUM].arfcn);
				p+=sprintf(p, ",%s,%s,%s,%s", 
								lac_buf,
								cid_buf,
								bsic_buf,
								arfcn_buf);
			}
			else
	#endif
			{
				p+=sprintf(p, ",%X,%X,%d,%d", 
							pGSMEngModeInfo->nbCellInfo[cellNUM].lac,
							pGSMEngModeInfo->nbCellInfo[cellNUM].ci,
							pGSMEngModeInfo->nbCellInfo[cellNUM].bsic,
							pGSMEngModeInfo->nbCellInfo[cellNUM].arfcn);
			}
		
			if(pSVCCellInfo->rxSigLevel <=63  )
			{
				p+=sprintf(p, ",%d", pSVCCellInfo->rxSigLevel-111);
			}
			else
			{
				p+=sprintf(p, ",%d",63-111);
			}
			p+=sprintf(p, ",%d,%d,%d,%d\r\n", 
						pGSMEngModeInfo->nbCellInfo[cellNUM].C1,
						pGSMEngModeInfo->nbCellInfo[cellNUM].C2,
						pGSMEngModeInfo->nbCellInfo[cellNUM].C31,
						pGSMEngModeInfo->nbCellInfo[cellNUM].C32);
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
		
		//neighber cell of UMTS
		for (cellNUM = 0; cellNUM < pGSMEngModeInfo->numInterRATNCells; cellNUM++)
		{
			if(pGSMEngModeInfo->InterRATCellInfo[cellNUM].arfcn ==0)
				continue;
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				memset(cid_buf,0,sizeof(cid_buf));
				GET_VALID_VAL(cid_buf, pGSMEngModeInfo->InterRATCellInfo[cellNUM].psc_cellParameterId);
				GET_VALID_VAL(arfcn_buf, pGSMEngModeInfo->InterRATCellInfo[cellNUM].arfcn);
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%s,%s,%d,%d\r\n","neighbourcell","WCDMA",
					arfcn_buf,
					cid_buf,
					pGSMEngModeInfo->InterRATCellInfo[cellNUM].rscp,
					pGSMEngModeInfo->InterRATCellInfo[cellNUM].cpichEcN0);
			}
			else
#endif
			{
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%d,%d,%d,%d\r\n","neighbourcell","WCDMA",
						pGSMEngModeInfo->InterRATCellInfo[cellNUM].arfcn,
						pGSMEngModeInfo->InterRATCellInfo[cellNUM].psc_cellParameterId,
						pGSMEngModeInfo->InterRATCellInfo[cellNUM].rscp,
						pGSMEngModeInfo->InterRATCellInfo[cellNUM].cpichEcN0);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}

		//neighber cell of LTE
		for (cellNUM = 0; cellNUM < pGSMEngModeInfo->nCellInfoListLte.numNcellLte; cellNUM++)
		{
			if(pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].earfcn ==0)
				continue;
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
	#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				memset(cid_buf,0,sizeof(cid_buf));
				GET_VALID_VAL(cid_buf, pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].physCellId);
				GET_VALID_VAL(arfcn_buf, pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].earfcn);
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%s,%s,%d,%d\r\n","neighbourcell","LTE",
					arfcn_buf,
					cid_buf,
					pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].rsrp-140,
					pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].rsrq/2-20);
			}
			else
	#endif
			{
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%d,%d,%X,%d\r\n","neighbourcell","LTE",
					pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].earfcn,
					pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].physCellId,
					pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].rsrp-140,
					pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].rsrq/2-20);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
	}
#ifndef ENABLE_DM_LTEONLY 
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QSMONC))
	{
		Network_Info_Log("mcc=%d,ci=%d",pSVCCellInfo->mcc,pSVCCellInfo->ci);
        memset(resBuf, 0, sizeof(resBuf));
		p = resBuf;
		if((pSVCCellInfo->mcc > 0 && pSVCCellInfo->mcc < 0x999 ) //check if mcc valid
			&& (pSVCCellInfo->ci > 0 && pSVCCellInfo->ci < 0xFFFF ) )	//check if cell id valid
		{
			memset(plmn_buf,0,sizeof(plmn_buf));
			if(pSVCCellInfo->lenOfMnc==3)
			{
				sprintf(plmn_buf, "%lx,%03lx",pSVCCellInfo->mcc,pSVCCellInfo->mnc );
			}
			else
			{
				sprintf(plmn_buf, "%lx,%02lx",pSVCCellInfo->mcc,pSVCCellInfo->mnc );
			}
			
			p=Quectel_SMONCPrintf(1, p, plmn_buf, pSVCCellInfo->lac, pSVCCellInfo->ci, pSVCCellInfo->bsic,
				pSVCCellInfo->arfcn, pSVCCellInfo->rxSigLevel, pSVCCellInfo->C1, pSVCCellInfo->C2);
		}
		else
		{
			p=Quectel_SMONCPrintf(1, p, "000,000", 0, 0, 0, 0, 0, QUEC_INVALID_C_VALUE, QUEC_INVALID_C_VALUE);
		}
        if (1 != quec_assemble_qeng_resp(resBuf, p))
        {
            return;
        }
		
		for( cellNUM = 0; cellNUM < pGSMEngModeInfo->numNCells && cellNUM<QUEC_MAX_SMONC_ITEMS; cellNUM++)
		{
			Network_Info_Log("mcc=%d,ci=%d",pGSMEngModeInfo->nbCellInfo[cellNUM].mcc,pGSMEngModeInfo->nbCellInfo[cellNUM].ci);
			if((pGSMEngModeInfo->nbCellInfo[cellNUM].mcc > 0 && pGSMEngModeInfo->nbCellInfo[cellNUM].mcc < 0x999 ) //check if mcc valid
			&& (pGSMEngModeInfo->nbCellInfo[cellNUM].ci > 0 && pGSMEngModeInfo->nbCellInfo[cellNUM].ci < 0xFFFF ) )   //check if cell id valid
			{
				memset(plmn_buf,0,sizeof(plmn_buf));
				if(pSVCCellInfo->lenOfMnc==3)
				{
					sprintf(plmn_buf, "%lx,%03lx",pGSMEngModeInfo->nbCellInfo[cellNUM].mcc,pGSMEngModeInfo->nbCellInfo[cellNUM].mnc );
				}
				else
				{
					sprintf(plmn_buf, "%lx,%02lx",pGSMEngModeInfo->nbCellInfo[cellNUM].mcc,pGSMEngModeInfo->nbCellInfo[cellNUM].mnc );
				}
				uiCnt++;
                memset(resBuf, 0, sizeof(resBuf));
        		p = resBuf;
				p=Quectel_SMONCPrintf(0, p, plmn_buf, pGSMEngModeInfo->nbCellInfo[cellNUM].lac, pGSMEngModeInfo->nbCellInfo[cellNUM].ci, pGSMEngModeInfo->nbCellInfo[cellNUM].bsic,
					pGSMEngModeInfo->nbCellInfo[cellNUM].arfcn, pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel, pGSMEngModeInfo->nbCellInfo[cellNUM].C1,pGSMEngModeInfo->nbCellInfo[cellNUM].C2);
                if (1 != quec_assemble_qeng_resp(resBuf, p))
                {
                    return;
                }
			}
		}
		
		for( cellNUM = uiCnt; cellNUM<QUEC_MAX_SMONC_ITEMS; cellNUM++)
		{
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
			p=Quectel_SMONCPrintf(0, p, "000,000", 0, 0, 0, 0, 0, QUEC_INVALID_C_VALUE, QUEC_INVALID_C_VALUE);
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
        memset(resBuf, 0, sizeof(resBuf));
		p = resBuf;
		p+=sprintf(p, "\r\n");
        if (1 != quec_assemble_qeng_resp(resBuf, p))
        {
            return;
        }
	}
#endif
#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
	else if(CHECK_BIT_SET(network_infor_bitmsk ,MCELL))
	{
		Network_Info_Log("mcc=%d,ci=%d",pSVCCellInfo->mcc,pSVCCellInfo->ci);
        memset(resBuf, 0, sizeof(resBuf));
		p = resBuf;
		p+=sprintf(p, "MCC: %x,MNC: %x,LAC: %5d,Cell ID: %9d,BSIC:%d,(P)BCCH ARFCN: %04x,RxLev: %03X",
				   pSVCCellInfo->mcc, pSVCCellInfo->mnc, pSVCCellInfo->lac, pSVCCellInfo->ci, pSVCCellInfo->bsic, 
				   pSVCCellInfo->arfcn,pSVCCellInfo->rxSigLevel);
		
		if(pSVCCellInfo->rxSigLevel <=63  )
		{
			p+=sprintf(p, ",RxDbm: %d\r\n", pSVCCellInfo->rxSigLevel-111);
		}
		else
		{
			p+=sprintf(p, ",RxDbm: %d\r\n",63-111);
		}
        if (1 != quec_assemble_qeng_resp(resBuf, p))
        {
            return;
        }

		for( cellNUM = 0; cellNUM < pGSMEngModeInfo->numNCells && cellNUM<QUEC_MAX_SMONC_ITEMS; cellNUM++)
		{
			//check if cell msg is valid
			if((pGSMEngModeInfo->nbCellInfo[cellNUM].mcc <= 0 || pGSMEngModeInfo->nbCellInfo[cellNUM].mcc > 0x999)
				||(pGSMEngModeInfo->nbCellInfo[cellNUM].ci == 0)
				||(pGSMEngModeInfo->nbCellInfo[cellNUM].lac == 0))
			{
				continue;
			}
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
				
			p+=sprintf(p,"MCC: %x,MNC: %x,LAC: %5d,Cell ID: %9d,BSIC: %03x,(P)BCCH ARFCN: %04x,RxLev: %03x",
					  pGSMEngModeInfo->nbCellInfo[cellNUM].mcc, pGSMEngModeInfo->nbCellInfo[cellNUM].mnc,
					  pGSMEngModeInfo->nbCellInfo[cellNUM].lac, pGSMEngModeInfo->nbCellInfo[cellNUM].ci,
					  pGSMEngModeInfo->nbCellInfo[cellNUM].bsic,pGSMEngModeInfo->nbCellInfo[cellNUM].arfcn,
					  pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel);
			if(pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel <=63  )
			{
				p+=sprintf(p, ",RxDbm: %d\r\n", pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel-111);
			}
			else
			{
				p+=sprintf(p, ",RxDbm: %d\r\n",63-111);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
	}
#endif
	#ifdef QUEC_ENGINEER_OUTPUT
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_ALL_INFO))
	{
		uint8 i=0;
		uint8 *ptemp= (uint8 *)quec_QengineerResBuf;
		Network_Info_Log("ASR_ENG_MODE Start,scellinfo:rxSigLevel=%d,rxSigLevelFull=%d,rxSigLevelSub=%d,rxQualityFull=%d,rxQualitySub=%d",
			pGSMEngModeInfo->svcCellInfo.rxSigLevel,
			pGSMEngModeInfo->svcCellInfo.rxSigLevelFull,
			pGSMEngModeInfo->svcCellInfo.rxSigLevelSub,
			pGSMEngModeInfo->svcCellInfo.rxQualityFull,
			pGSMEngModeInfo->svcCellInfo.rxQualitySub);
		
       ptemp+=sprintf((char *)ptemp,"+QENGINFO: GSM,rxSigLevel:%d,rxSigLevelFull:%d,rxSigLevelSub:%d,rxQualityFull:%d,rxQualitySub:%d",
			    pGSMEngModeInfo->svcCellInfo.rxSigLevel,
				pGSMEngModeInfo->svcCellInfo.rxSigLevelFull,
				pGSMEngModeInfo->svcCellInfo.rxSigLevelSub,
				pGSMEngModeInfo->svcCellInfo.rxQualityFull,
				pGSMEngModeInfo->svcCellInfo.rxQualitySub);

		Network_Info_Log("ASR_ENG_MODE,scellinfo:rac=%d,bsic=%d,nom=%d,nco=%d,bs_pa_mfrms=%d",
				pGSMEngModeInfo->svcCellInfo.rac,
				pGSMEngModeInfo->svcCellInfo.bsic,
				pGSMEngModeInfo->svcCellInfo.nom,
				pGSMEngModeInfo->svcCellInfo.nco,
				pGSMEngModeInfo->svcCellInfo.bs_pa_mfrms);

		ptemp+=sprintf((char *)ptemp,",rac:%d,bsic:%d,nom:%d,nco:%d,bs_pa_mfrms:%d",
			    pGSMEngModeInfo->svcCellInfo.rac,
				pGSMEngModeInfo->svcCellInfo.bsic,
				pGSMEngModeInfo->svcCellInfo.nom,
				pGSMEngModeInfo->svcCellInfo.nco,
				pGSMEngModeInfo->svcCellInfo.bs_pa_mfrms); 

		
		Network_Info_Log("ASR_ENG_MODE,scellinfo:mcc=%d,mnc=%d,lac=%d,ci=%d,arfcn=%d",
				pGSMEngModeInfo->svcCellInfo.mcc,
				pGSMEngModeInfo->svcCellInfo.mnc,
				pGSMEngModeInfo->svcCellInfo.lac,
				pGSMEngModeInfo->svcCellInfo.ci,
				pGSMEngModeInfo->svcCellInfo.arfcn);

		ptemp+=sprintf((char *)ptemp,",mcc:%d,mnc:%d,lac:%d,ci:%d,arfcn:%d",
			pGSMEngModeInfo->svcCellInfo.mcc,
			pGSMEngModeInfo->svcCellInfo.mnc,
			pGSMEngModeInfo->svcCellInfo.lac,
			pGSMEngModeInfo->svcCellInfo.ci,
			pGSMEngModeInfo->svcCellInfo.arfcn);


		Network_Info_Log("ASR_ENG_MODE,scellinfo,c1=%d,c2=%d,c31=%d,c32=%d,t3212=%d,t3312=%d",
			pGSMEngModeInfo->svcCellInfo.C1,
			pGSMEngModeInfo->svcCellInfo.C2,
			pGSMEngModeInfo->svcCellInfo.C31,
			pGSMEngModeInfo->svcCellInfo.C32,
			pGSMEngModeInfo->svcCellInfo.t3212,
			pGSMEngModeInfo->svcCellInfo.t3312);
		
	    ptemp+=sprintf((char *)ptemp,",C1:%d,C2:%d,C31:%d,C32:%d,t3212:%d,t3312:%d",
			pGSMEngModeInfo->svcCellInfo.C1,
			pGSMEngModeInfo->svcCellInfo.C2,
			pGSMEngModeInfo->svcCellInfo.C31,
			pGSMEngModeInfo->svcCellInfo.C32,
			pGSMEngModeInfo->svcCellInfo.t3212,
			pGSMEngModeInfo->svcCellInfo.t3312);
		quec_siolib_transmit_to_atp(quec_qengineer_atp, "\r\n", 2, NULL);
		quec_siolib_transmit_to_atp(quec_qengineer_atp,(uint8 *)quec_QengineerResBuf,ptemp-(uint8 *)quec_QengineerResBuf,NULL);
		memset(quec_QengineerResBuf,0,QUEC_QENG_RESBUFLEN_MIN);
		ptemp =quec_QengineerResBuf;
		Network_Info_Log("ASR_ENG_MODE,scellinfo,pbcchSupport=%d,TxPowerLevel=%d,timingAdv=%d,hoppingChannel=%d,EGPRSSupport=%d,ChType=%d",
			pGSMEngModeInfo->svcCellInfo.pbcchSupport,
			pGSMEngModeInfo->svcCellInfo.TxPowerLevel,
			pGSMEngModeInfo->svcCellInfo.timingAdv,
			pGSMEngModeInfo->svcCellInfo.hoppingChannel,
			pGSMEngModeInfo->svcCellInfo.EGPRSSupport,
			pGSMEngModeInfo->svcCellInfo.ChType);

		 ptemp+=sprintf((char *)ptemp,",pbcchSupport:%d,TxPowerLevel:%d,timingAdv:%d,hoppingChannel:%d,EGPRSSupport:%d,ChType:%d",
			pGSMEngModeInfo->svcCellInfo.pbcchSupport,
			pGSMEngModeInfo->svcCellInfo.TxPowerLevel,
			pGSMEngModeInfo->svcCellInfo.timingAdv,
			pGSMEngModeInfo->svcCellInfo.hoppingChannel,
			pGSMEngModeInfo->svcCellInfo.EGPRSSupport,
			pGSMEngModeInfo->svcCellInfo.ChType);

		Network_Info_Log("ASR_ENG_MODE,scellinfo,nccPermitted=%d,RadioLinkTimeout=%d,hoCount=%d,hoSuccessCount=%d,chanAssCount=%d,chanAssSuccessCount=%d",		
				pGSMEngModeInfo->svcCellInfo.nccPermitted,
			pGSMEngModeInfo->svcCellInfo.RadioLinkTimeout,
			pGSMEngModeInfo->svcCellInfo.hoCount,
			pGSMEngModeInfo->svcCellInfo.hoSuccessCount,
			pGSMEngModeInfo->svcCellInfo.chanAssCount,
			pGSMEngModeInfo->svcCellInfo.chanAssSuccessCount);
		
		ptemp+=sprintf((char *)ptemp,",nccPermitted:%d,RadioLinkTimeout:%d,hoCount:%d,hoSuccessCount:%d,chanAssCount:%d,chanAssSuccessCount:%d",
				pGSMEngModeInfo->svcCellInfo.nccPermitted,
			pGSMEngModeInfo->svcCellInfo.RadioLinkTimeout,
			pGSMEngModeInfo->svcCellInfo.hoCount,
			pGSMEngModeInfo->svcCellInfo.hoSuccessCount,
			pGSMEngModeInfo->svcCellInfo.chanAssCount,
			pGSMEngModeInfo->svcCellInfo.chanAssSuccessCount);
	
		Network_Info_Log("ASR_ENG_MODE,scellinfo,arfcnTch=%d,timeSlot=%d,isInPacketIdle=%d,IsForbiddenLA=%d,CellPriority=%d,HSN=%d",	
				pGSMEngModeInfo->svcCellInfo.arfcnTch,
			pGSMEngModeInfo->svcCellInfo.timeSlot,
			pGSMEngModeInfo->svcCellInfo.isInPacketIdle,
			pGSMEngModeInfo->svcCellInfo.IsForbiddenLA,
			pGSMEngModeInfo->svcCellInfo.CellPriority,
			pGSMEngModeInfo->svcCellInfo.HSN);

		ptemp+=sprintf((char *)ptemp,",arfcnTch:%d,timeSlot:%d,isInPacketIdle:%d,IsForbiddenLA:%d,CellPriority:%d,HSN:%d",
				pGSMEngModeInfo->svcCellInfo.arfcnTch,
			pGSMEngModeInfo->svcCellInfo.timeSlot,
			pGSMEngModeInfo->svcCellInfo.isInPacketIdle,
			pGSMEngModeInfo->svcCellInfo.IsForbiddenLA,
			pGSMEngModeInfo->svcCellInfo.CellPriority,
			pGSMEngModeInfo->svcCellInfo.HSN);
		
		quec_siolib_transmit_to_atp(quec_qengineer_atp,(uint8 *)quec_QengineerResBuf,ptemp-(uint8 *)quec_QengineerResBuf,NULL);
		memset(quec_QengineerResBuf,0,QUEC_QENG_RESBUFLEN_MIN);
		ptemp =quec_QengineerResBuf;
		
		Network_Info_Log("ASR_ENG_MODE,scellinfo,HoppingGroup=%d,gsmBand=%d,channelMode=%d,lenOfMnc=%d,codecType=%d,speechCodecRate=%d",	
				pGSMEngModeInfo->svcCellInfo.HoppingGroup,
			pGSMEngModeInfo->svcCellInfo.gsmBand,
			pGSMEngModeInfo->svcCellInfo.channelMode,
			pGSMEngModeInfo->svcCellInfo.lenOfMnc,
			pGSMEngModeInfo->svcCellInfo.codecType,
			pGSMEngModeInfo->svcCellInfo.speechCodecRate);
		
		ptemp+=sprintf((char *)ptemp,",HoppingGroup:%d,gsmBand:%d,channelMode:%d,lenOfMnc:%d,codecType:%d,speechCodecRate:%d",
				pGSMEngModeInfo->svcCellInfo.HoppingGroup,
			pGSMEngModeInfo->svcCellInfo.gsmBand,
			pGSMEngModeInfo->svcCellInfo.channelMode,
			pGSMEngModeInfo->svcCellInfo.lenOfMnc,
			pGSMEngModeInfo->svcCellInfo.codecType,
			pGSMEngModeInfo->svcCellInfo.speechCodecRate);
				
		
		Network_Info_Log("ASR_ENG_MODE,scellinfo,RLA=%d,DRX=%d,maio=%d,succeededGsmIratReselectionCount=%d,succeededGsmHandoverCount=%d",
			pGSMEngModeInfo->svcCellInfo.RLA,
			pGSMEngModeInfo->svcCellInfo.DRX,
			pGSMEngModeInfo->svcCellInfo.maio,
			pGSMEngModeInfo->svcCellInfo.succeededGsmIratReselectionCount,
			pGSMEngModeInfo->svcCellInfo.succeededGsmHandoverCount);
       ptemp+=sprintf((char *)ptemp,",RLA:%d,DRX:%d,maio:%d,succeededGsmIratReselectionCount:%d,succeededGsmHandoverCount:%d",
			pGSMEngModeInfo->svcCellInfo.RLA,
			pGSMEngModeInfo->svcCellInfo.DRX,
			pGSMEngModeInfo->svcCellInfo.maio,
			pGSMEngModeInfo->svcCellInfo.succeededGsmIratReselectionCount,
			pGSMEngModeInfo->svcCellInfo.succeededGsmHandoverCount);
	    quec_siolib_transmit_to_atp(quec_qengineer_atp,(uint8 *)quec_QengineerResBuf,ptemp-(uint8 *)quec_QengineerResBuf,NULL);
		memset(quec_QengineerResBuf,0,QUEC_QENG_RESBUFLEN_MIN);
		ptemp =quec_QengineerResBuf;
		Network_Info_Log("ASR_ENG_MODE,END,scell_meas_6,ptemp=%p,quec_QengineerResLen=%p,%d",ptemp,quec_QengineerResBuf,ptemp-(uint8 *)quec_QengineerResBuf);
	}
	#endif
#ifdef QUECTEL_CELL
    else if (CHECK_BIT_SET(network_infor_bitmsk ,CELL_GET))
	{
        memset(resBuf, 0, sizeof(resBuf));
	    p = resBuf;
        /*isaac 20201223 serving cell info,若不插卡扫描，显示驻留小区信息，
         *不再显示state "CONNECT","NOCONN","LIMSRV"
         */
        p+=sprintf(p, "+QCELL: \"%s\",\"%s\",%03x","servingcell","GSM",pSVCCellInfo->mcc); 
        
        if(pSVCCellInfo->lenOfMnc==3)
		{
			p+=sprintf(p, ",%03X",pSVCCellInfo->mnc);
		}
		else
		{
			p+=sprintf(p, ",%02X",pSVCCellInfo->mnc);
		}
        p+=sprintf(p, ",%04X,%x,%d,%d\r\n",pSVCCellInfo->lac,
                        pSVCCellInfo->ci,
                        pSVCCellInfo->bsic,
                        pSVCCellInfo->rxSigLevel);
       
        if (1 != quec_assemble_qeng_resp(resBuf, p))
		{
			return;
		}
        
        //neighber cell of GSM
		Network_Info_Log("[quec ncell] pGSMEngModeInfo: numNCells %d",pGSMEngModeInfo->numNCells);
      
		for( cellNUM = 0; (cellNUM < pGSMEngModeInfo->numNCells) && (cellNUM < QUEC_MAX_SMONC_ITEMS-1); cellNUM++)
		{  
		    /*check vaild neighbourcell cell info */
		    if ( (pGSMEngModeInfo->nbCellInfo[cellNUM].ci == NCELL_CELL_ID_MAX) ||
                 (pGSMEngModeInfo->nbCellInfo[cellNUM].ci == NCELL_CELL_ID_MIN) ||
                 (pGSMEngModeInfo->nbCellInfo[cellNUM].bsic == NCELL_BSIC_MAX) ||
  				 (pGSMEngModeInfo->nbCellInfo[cellNUM].mcc == NCELL_CELL_MCC_INVALID) )
            {
                continue;
            }
            memset(resBuf, 0, sizeof(resBuf));
	        p = resBuf;
			p+=sprintf(p, "+QNCELL: \"%s\",\"%s\",%03x,%02x,%02x,%x,%d,%d\r\n","neighbourcell","GSM",
                            pGSMEngModeInfo->nbCellInfo[cellNUM].mcc,
                            pGSMEngModeInfo->nbCellInfo[cellNUM].mnc,
                            pGSMEngModeInfo->nbCellInfo[cellNUM].lac,
                            pGSMEngModeInfo->nbCellInfo[cellNUM].ci,
                            pGSMEngModeInfo->nbCellInfo[cellNUM].bsic,
                            pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel);
            if (1 != quec_assemble_qeng_resp(resBuf, p))
	        {
	            return;
	        }
		}   
	}
#endif
#ifdef QUEC_QCELLINFO_SUPPORT
    else if (CHECK_BIT_SET(network_infor_bitmsk ,QCELLINFOEX_GET))
	{
        memset(resBuf, 0, sizeof(resBuf));
	    p = resBuf;
        p+=sprintf(p, "+QCELLINFO: \"%s\",\"%s\",%03x","servingcell","GSM",pSVCCellInfo->mcc); 
        
        if(pSVCCellInfo->lenOfMnc==3)
		{
	        p+=sprintf(p, ",%03X",pSVCCellInfo->mnc);
		}
		else
		{
			p+=sprintf(p, ",%02X",pSVCCellInfo->mnc);
		}
        p+=sprintf(p, ",%04X,%x,%d,%d,%d,%d\r\n",pSVCCellInfo->lac,
                        pSVCCellInfo->ci,
                        pSVCCellInfo->bsic,
                        pSVCCellInfo->rxSigLevel,
                        pSVCCellInfo->rxSigLevel-111,
                        pSVCCellInfo->arfcn);
        
        if (1 != quec_assemble_qeng_resp(resBuf, p))
		{
			return;
		}
        
        Network_Info_Log("[quec qcellinfo] pGSMEngModeInfo: numNCells %d",pGSMEngModeInfo->numNCells);
      
		for( cellNUM = 0; (cellNUM < pGSMEngModeInfo->numNCells) && (cellNUM < QUEC_MAX_SMONC_ITEMS-1); cellNUM++)
		{  
		    /*check vaild neighbourcell cell info */
		    if ( (pGSMEngModeInfo->nbCellInfo[cellNUM].ci == NCELL_CELL_ID_MAX) ||
                 (pGSMEngModeInfo->nbCellInfo[cellNUM].ci == NCELL_CELL_ID_MIN) ||
                 (pGSMEngModeInfo->nbCellInfo[cellNUM].bsic == NCELL_BSIC_MAX) )
            {
                continue;
            }
            memset(resBuf, 0, sizeof(resBuf));
	        p = resBuf;
            
			p+=sprintf(p, "+QCELLINFO: \"%s\",\"%s\",%03x,%02x,%02x,%x,%d,%d,%d,%d\r\n","neighbourcell","GSM",
                             pGSMEngModeInfo->nbCellInfo[cellNUM].mcc,
                             pGSMEngModeInfo->nbCellInfo[cellNUM].mnc,
                             pGSMEngModeInfo->nbCellInfo[cellNUM].lac,
                             pGSMEngModeInfo->nbCellInfo[cellNUM].ci,
                             pGSMEngModeInfo->nbCellInfo[cellNUM].bsic,
                             pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel,
                             pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel-111,
                             pGSMEngModeInfo->nbCellInfo[cellNUM].arfcn);
           
            if (1 != quec_assemble_qeng_resp(resBuf, p))
	        {
	            return;
	        }
		}
	}
#endif
#ifdef QUEC_CCED_SUPPORT
		else if (CHECK_BIT_SET(network_infor_bitmsk,QUEC_CCED_S_GET))
		{
			int quec_scell_rxlev = 0;
			memset(resBuf, 0, sizeof(resBuf));
			p = resBuf;
	
			//info-servingcell
			if(quec_cced_mode == QUEC_CCED_NO_AUTO_MODE) 
			{
				p+=sprintf(p, "+CCED:%s:%X", 
					"GSM current cell",
					pSVCCellInfo->mcc);

				if(pSVCCellInfo->lenOfMnc==3)
				{
			        p+=sprintf(p, ",%03X",pSVCCellInfo->mnc);
				}
				else
				{
					p+=sprintf(p, ",%02X",pSVCCellInfo->mnc);
				}

				p+=sprintf(p, ",%X,%X,%d", 
					pSVCCellInfo->lac,
					pSVCCellInfo->ci,
					pSVCCellInfo->bsic);
				
				//Consistent with QDM038_EU_IE parameters
				quec_scell_rxlev = pSVCCellInfo->rxSigLevel;
				if(quec_scell_rxlev < 0  )								 
				{
					p+=sprintf(p, ",%d", 0);
				}
				else if (quec_scell_rxlev > 63	)
				{
					p+=sprintf(p, ",%d",63);
				}
				else 
				{
					p+=sprintf(p, ",%d", quec_scell_rxlev);
				}
				
				p+=sprintf(p, ",%d\r\n", pSVCCellInfo->rxSigLevelSub);
				p+=sprintf(p, ",%d\r\n", pSVCCellInfo->arfcn);
				
				if (1 != quec_assemble_qeng_resp(resBuf, p))
				{
					return;
				}
			}
		}
		else if (CHECK_BIT_SET(network_infor_bitmsk,QUEC_CCED_NB_GET))
		{
			int quec_nbcell_rxlev = 0;
			int neighbourmaximum = 6;
			int neighbourvaild = 0;
			memset(resBuf, 0, sizeof(resBuf));
			p = resBuf;
			
			//info-neighbourcell of GSM
			if (quec_cced_mode == QUEC_CCED_NO_AUTO_MODE) 
			{
				for (cellNUM = 0; cellNUM < pGSMEngModeInfo->numNCells; cellNUM++)
				{
					if( pGSMEngModeInfo->nbCellInfo[cellNUM].ci ==0 )
						continue;

					neighbourvaild++;
					if( neighbourvaild == neighbourmaximum )
					{
						break;
					}
					memset(resBuf, 0, sizeof(resBuf));
					p = resBuf;
						
					p+=sprintf(p, "+CCED:%s:%X", 
						"GSM neighbour cell",
						pGSMEngModeInfo->nbCellInfo[cellNUM].mcc);
		
					if(pGSMEngModeInfo->nbCellInfo[cellNUM].lenOfMnc==3)
					{
				        p+=sprintf(p, ",%03X",pGSMEngModeInfo->nbCellInfo[cellNUM].mnc);
					}
					else
					{
						p+=sprintf(p, ",%02X",pGSMEngModeInfo->nbCellInfo[cellNUM].mnc);
					}	


					p+=sprintf(p, ",%X,%X,%d", 
						pGSMEngModeInfo->nbCellInfo[cellNUM].lac,
						pGSMEngModeInfo->nbCellInfo[cellNUM].ci,
						pGSMEngModeInfo->nbCellInfo[cellNUM].bsic);
					
					//Consistent with QDM038_EU_IE parameters	
					quec_nbcell_rxlev = pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel;
					if(quec_nbcell_rxlev < 0  ) 							  
					{
						p+=sprintf(p, ",%d", 0);
					}
					else if (quec_nbcell_rxlev > 63  )
					{
						p+=sprintf(p, ",%d",63);
					}
					else 
					{
						p+=sprintf(p, ",%d", quec_nbcell_rxlev);
					}
					
					p+=sprintf(p, "\r\n");
		
					if (1 != quec_assemble_qeng_resp(resBuf, p))
					{
						return;
					}
				}	
			}
		}

#endif

	else
	{
#endif

	// Part I: +EEMGINFOBASIC
	sprintf(resBuf, "+EEMGINFOBASIC: %d\r\n", pGsmEngmodeInfoInd->mode);
	ATRESP(reqHandle, 0, 0, resBuf);

	// Part II: +EEMGINFOSVC
	// -6- mcc, mnc, lac, ci, nom, nco
	sprintf(resBuf, "+EEMGINFOSVC: %d, %d, %d, %d, %d, %d, %d,", pSVCCellInfo->mcc,
															 pSVCCellInfo->lenOfMnc,
	                                                         pSVCCellInfo->mnc,
	                                                         pSVCCellInfo->lac,
	                                                         pSVCCellInfo->ci,
	                                                         pSVCCellInfo->nom,
	                                                         pSVCCellInfo->nco);

	// -5- bsic, C1, C2, TA, TxPwr
	sprintf(tempBuf, " %d, %d, %d, %d, %d, ", pSVCCellInfo->bsic,
	                                          pSVCCellInfo->C1,
	                                          pSVCCellInfo->C2,
	                                          pSVCCellInfo->timingAdv,
	                                          pSVCCellInfo->TxPowerLevel);
	strcat(resBuf, tempBuf);
	// -5- RxSig, RxSigFull, RxSigSub, RxQualFull, RxQualSub
	sprintf(tempBuf, " %d, %d, %d, %d, %d, ", pSVCCellInfo->rxSigLevel,
	                                          pSVCCellInfo->rxSigLevelFull,
	                                          pSVCCellInfo->rxSigLevelSub,
	                                          pSVCCellInfo->rxQualityFull,
	                                          pSVCCellInfo->rxQualitySub);
	strcat(resBuf, tempBuf);
	// -7- ARFCB_tch, hopping_chnl, chnl_type, TS, PacketIdle, rac, arfcn
	sprintf(tempBuf, " %d, %d, %d, %d, %d, %d, %d, ", pSVCCellInfo->arfcnTch,
	                                                  pSVCCellInfo->hoppingChannel,
	                                                  pSVCCellInfo->ChType,
	                                                  pSVCCellInfo->timeSlot,
	                                                  pSVCCellInfo->isInPacketIdle,
	                                                  pSVCCellInfo->rac,
	                                                  pSVCCellInfo->arfcn);
	strcat(resBuf, tempBuf);
	// -7- bs_pa_mfrms, C31, C32, t3212, t3312, pbcch_support, EDGE_support
	sprintf(tempBuf, " %d, %d, %d, %d, %d, %d, %d, ", pSVCCellInfo->bs_pa_mfrms,
	                                                  pSVCCellInfo->C31,
	                                                  pSVCCellInfo->C32,
	                                                  pSVCCellInfo->t3212,
	                                                  pSVCCellInfo->t3312,
	                                                  pSVCCellInfo->pbcchSupport,
	                                                  pSVCCellInfo->EGPRSSupport);
	strcat(resBuf, tempBuf);
	// -6- ncc_permitted, rl_timeout, ho_count, ho_succ, chnl_access_count, chnl_access_succ_count
	sprintf(tempBuf, " %d, %d, %d, %d, %d, %d,", pSVCCellInfo->nccPermitted,
	                                                pSVCCellInfo->RadioLinkTimeout,
	                                                pSVCCellInfo->hoCount,
	                                                pSVCCellInfo->hoSuccessCount,
	                                                pSVCCellInfo->chanAssCount,
	                                                pSVCCellInfo->chanAssSuccessCount);
	strcat(resBuf, tempBuf);
    // add for two paramters  -2-- gsmBand,channelMode
	sprintf(tempBuf, " %d, %d\r\n", pSVCCellInfo->gsmBand,
	                                                pSVCCellInfo->channelMode);
	strcat(resBuf, tempBuf);

	
	ATRESP(reqHandle, 0, 0, resBuf);

	// Part III: +EEMGINFOPS
	// -5- PS_attached, attach_type, service_type, tx_power, c_value
	sprintf(resBuf, "+EEMGINFOPS: %d, %d, %d, %d, %d, ", pGPRSPTMInfo->GPRSAttached,
	                                                     pGPRSPTMInfo->GPRSAttachType,
	                                                     pGPRSPTMInfo->gprsServiceType,
	                                                     pGPRSPTMInfo->txPower,
	                                                     pGPRSPTMInfo->cValue);

	// -6- ul_ts, dl_ts, ul_cs, dl_cs, ul_modulation, dl_modulation
	sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, ", pGPRSPTMInfo->ulTimeSlot,
                                                 pGPRSPTMInfo->dlTimeSlot,
                                                 pGPRSPTMInfo->CodingSchemeUL,
                                                 pGPRSPTMInfo->CodingSchemeDL,
                                                 pGPRSPTMInfo->ulMod,
                                                 pGPRSPTMInfo->dlMod);

	strcat(resBuf, tempBuf);
	// -6- gmsk_cv_bep, 8psk_cv_bep, gmsk_mean_bep, 8psk_mean_bep, EDGE_bep_period, single_gmm_rej_cause
	sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, ", pGPRSPTMInfo->egprsBep.gmskCvBep,
                                                 pGPRSPTMInfo->egprsBep.eightPskCvBep,
                                                 pGPRSPTMInfo->egprsBep.gmskMeanBep,
                                                 pGPRSPTMInfo->egprsBep.eightPskMeanBep,
                                                 pGPRSPTMInfo->EGPRSBEPPeriod,
                                                 pGPRSPTMInfo->IsSingleGmmRejectCause);

	strcat(resBuf, tempBuf);
	// -6- pdp_active_num, mac_mode, network_control, network_mode, EDGE_slq_measurement_mode, edge_status
	//[klockwork][issue id: 1051]
	snprintf(tempBuf, sizeof(tempBuf), "%d, %d, %d, %d, %d, %d,%d\r\n", pGPRSPTMInfo->NumActivePDPContext,
                                                   pGPRSPTMInfo->MacMode,
                                                   pGPRSPTMInfo->NetworkControl,
                                                   pGPRSPTMInfo->NetworkMode,
                                                   pGPRSPTMInfo->EGPRSLQMeasurementMode,
                                                   pGPRSPTMInfo->egprsBep.status,
													pGPRSPTMInfo->GMMRejectCause);

	strcat(resBuf, tempBuf);
	ATRESP(reqHandle, 0, 0, resBuf);

	// Part IV: +EEMGINFONC

	/* Neighbors number */
	if (pGSMEngModeInfo->numNCells > MAX_GSM_NEIGHBORING_CELLS)
	{
		ERRMSG("pGSMEngModeInfo->numNCells  %d larger than MAX_GSM_NEIGHBORING_CELLS \r\n", pGSMEngModeInfo->numNCells);
		return;
	}
	for (cellNUM = 0; cellNUM < pGSMEngModeInfo->numNCells; cellNUM++)
	{
		// -6- nc_num, mcc, mnc, lac, rac, ci
		sprintf(resBuf, "+EEMGINFONC: %d, %d, %d, %d, %d, %d,", cellNUM,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].mcc,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].mnc,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].lac,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].rac,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].ci);

		// -7- rx_lv, bsic, C1, C2, arfcn, C31, C32
		sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, %d\r\n",
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].bsic,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].C1,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].C2,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].arfcn,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].C31,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].C32);
		strcat(resBuf, tempBuf);
		ATRESP(reqHandle, 0, 0, resBuf);
	}

	// Part V: +EEMGINBFTM
	// -8- EngMode, mcc, mnc, lac, ci, bsic, C1, C2
	sprintf(resBuf, "+EEMGINBFTM: %d, %d, %d, %d, %d, %d, %d, %d, ", *pEngModeRepOpt,
	                                                                 pSVCCellInfo->mcc,
	                                                                 pSVCCellInfo->mnc,
	                                                                 pSVCCellInfo->lac,
	                                                                 pSVCCellInfo->ci,
	                                                                 pSVCCellInfo->bsic,
	                                                                 pSVCCellInfo->C1,
	                                                                 pSVCCellInfo->C2);
	// -5- Timing advace, TxPowerLevel, rxSigLevel, rxSigLevelFull, rxSigLevelSub
	sprintf(tempBuf, "%d, %d, %d, %d, %d,", pSVCCellInfo->timingAdv,
	                                        pSVCCellInfo->TxPowerLevel,
	                                        pSVCCellInfo->rxSigLevel,
	                                        pSVCCellInfo->rxSigLevelFull,
	                                        pSVCCellInfo->rxSigLevelSub);
	strcat(resBuf, tempBuf);

	// -6- rxQualityFull, rxQualitySub, arfcnTch, hopping status, channel type, server timeslot
	sprintf(tempBuf, "%d, %d, %d, %d, %d, %d\r\n", pSVCCellInfo->rxQualityFull,
	                                               pSVCCellInfo->rxQualitySub,
	                                               pSVCCellInfo->arfcnTch,
	                                               pSVCCellInfo->hoppingChannel,
	                                               pSVCCellInfo->ChType,
	                                               pSVCCellInfo->timeSlot);
	strcat(resBuf, tempBuf);
	ATRESP(reqHandle, 0, 0, resBuf);

	//+EEMGINFOGMM : 4+3+4+3(serviceStatus,LAU_status,LAU_count)
	sprintf(resBuf, "+EEMGINFOGMM: %d, %d, %d, %d,", pGMMInfo->MccLastRegisteredNetwork,
	                                                 pGMMInfo->MncLastRegisteredNetwork,
	                                                 pGMMInfo->TMSI,
	                                                 pGMMInfo->PTMSI);

	sprintf(tempBuf, "%d, %d, %d,", pGMMInfo->IsSingleMmRejectCause,
	                                pGMMInfo->MMRejectCause,
	                                pGMMInfo->currentBandMode);
	strcat(resBuf, tempBuf);


	sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, %d, %d, %d\r\n", pGMMInfo->mmState,
	                                       pGMMInfo->gmmState,
	                                       pGMMInfo->gprsReadyState,
	                                       pGMMInfo->readyTimerValueInSecs,
	                                       pGMMInfo->serviceStatus,
	                                       pGMMInfo->LAU_status,
	                                       pGMMInfo->LAU_count,
	                                       pGMMInfo->RAU_status,
	                                       pGMMInfo->RAU_count);
	strcat(resBuf, tempBuf);
	ATRESP(reqHandle, 0, 0, resBuf);
#ifdef QUECTEL_NETWORK_SUPPORT      
	}
#endif

	return;
}
#else
/****************************************************************
 *  F@: processEEMOPTInfoInd - Process engine mode info ind msg
 */
static void processEEMOPTInfoInd(UINT32 reqHandle, const void *pParam)
{
	CiDevPrimGsmEngmodeInfoInd * pGsmEngmodeInfoInd;
	CiDevEngModeGsmData* pGSMEngModeInfo;
	CiDevGsmServingCellInfo * pSVCCellInfo;
	CiDevGPRSPTMInfo * pGPRSPTMInfo;
	CiDevGsmGMMInfo * pGMMInfo;
	CiDevEngModeReportOption *pEngModeRepOpt;
	char resBuf[500];
	char tempBuf[50];
	UINT8 cellNUM;
	
#if defined QUEC_CODECHECK_MODIFICATION_ASR
	memset(tempBuf, 0, sizeof(tempBuf));
#endif

	if (reqHandle == IND_REQ_HANDLE) {
		pEngModeRepOpt = &gEngModeRepOpt;
	} else {
		pEngModeRepOpt = &gEngModeRepOpt_1;
	}

	pGsmEngmodeInfoInd = (CiDevPrimGsmEngmodeInfoInd *)pParam;
	pGSMEngModeInfo = &(pGsmEngmodeInfoInd->info);
	pSVCCellInfo = &(pGSMEngModeInfo->svcCellInfo);
	pGPRSPTMInfo = &(pGSMEngModeInfo->GPRSPTMInfo);
	pGMMInfo = &(pGSMEngModeInfo->GMMInfo);

	gcell_lac = pSVCCellInfo->lac;
	gcell_ci  = pSVCCellInfo->ci;
	gcell_mcc = pSVCCellInfo->mcc;
	gcell_mnc = pSVCCellInfo->mnc;

#ifdef QUECTEL_NETWORK_SUPPORT
	char *p;
	char state[20]={0};
#ifdef __QUEC_OEM_VER_LD__
	char					   lac_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   cid_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   bsic_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   arfcn_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   plmn_buf[LANDI_VAL_BUF_MAX] ={0};
	UINT8					   uiCnt=0;
#endif 

	if(CHECK_BIT_SET(network_infor_bitmsk ,QNWINFO_GET))
	{
	#if QUEC_DUAL_SIM_SUPPORT
		Quec_qnwinfo_type *p_quec_qnwinfo = &quec_qnwinfo[((reqHandle == IND_REQ_HANDLE) ? SIM1 : SIM2)];
	#else
		Quec_qnwinfo_type *p_quec_qnwinfo = &quec_qnwinfo;
	#endif
	
		Network_Info_Log("processEMLteINFOSVCInfoInd,band=%d,dlEuArfcn=%d",pSVCCellInfo->gsmBand,pSVCCellInfo->arfcn);
		sprintf( &p_quec_qnwinfo->plmn[0],
					"%03x%02x",
					pSVCCellInfo->mcc,
					pSVCCellInfo->mnc );
	
		if(pSVCCellInfo->gsmBand==0 ||pSVCCellInfo->gsmBand==3)
		{	 
			sprintf( &p_quec_qnwinfo->band_description[0],"GSM 900");
		}
		else if(pSVCCellInfo->gsmBand==1 )
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"GSM 1800");
		}
		else if(pSVCCellInfo->gsmBand==2 )
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"GSM 1900");
		}
		else if(pSVCCellInfo->gsmBand==4 )
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"GSM 450");
		}
		else if(pSVCCellInfo->gsmBand==5 )
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"GSM 480");
		}
		else if(pSVCCellInfo->gsmBand==6 )
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"GSM 850");
		}
		else 
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"GSM BAND UNKNOWN");
		}

		
		if(pSVCCellInfo->EGPRSSupport)
		{
			sprintf( &p_quec_qnwinfo->act[0],"EDGE");
		}
		else if(p_quec_qnwinfo->service_domain==1 || p_quec_qnwinfo->service_domain==2)
		{
			sprintf( &p_quec_qnwinfo->act[0],"GPRS");
		}
		else
		{
			sprintf( &p_quec_qnwinfo->act[0],"GSM");
		}
		p_quec_qnwinfo->active_channel=pSVCCellInfo->arfcn;
#ifdef QUECTEL_OPEN_CPU
		if(!IsMiniSystem())
		{
			quec_nw_event_ind(reqHandle, p_quec_qnwinfo->act, QUEC_NW_EVENT_ACT_INFO);
		}
#endif
		//sprintf(resBuf,"+QNWINFO: \"%s\",\"%s\",\"%s\",%d",quec_qnwinfo.act,quec_qnwinfo.plmn,quec_qnwinfo.band_description,quec_qnwinfo.active_channel);    
		//ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
		
		//DEV_SetEngModeIndicatorOption(atHandle, 0, 0);//close engmode
		//BIT_CLR(network_infor_bitmsk, QNWINFO_GET);
	}
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_SERVINGCELL_GET))
	{
		quec_qeng_get_currrent_state(state);
        memset(resBuf, 0, sizeof(resBuf));
		p = resBuf;
		p+=sprintf(p, "+QENG: \"%s\",\"%s\",\"%s\",%3X","servingcell",state,"GSM",pSVCCellInfo->mcc);
		
		if(pSVCCellInfo->lenOfMnc==3)
		{
			p+=sprintf(p, ",%03X",pSVCCellInfo->mnc);
		}
		else
		{
			p+=sprintf(p, ",%02X",pSVCCellInfo->mnc);
		}
#ifdef __QUEC_OEM_VER_LD__
		if (TRUE == Quectel_IsOEMLandiEnable())
		{

			GET_VALID_VAL(lac_buf, pSVCCellInfo->lac);
			GET_VALID_VAL(cid_buf, pSVCCellInfo->ci);
			GET_VALID_VAL(bsic_buf, pSVCCellInfo->bsic);
			GET_VALID_VAL(arfcn_buf, pSVCCellInfo->arfcn);
			p+=sprintf(p, ",%s,%s,%s,%s", 
							lac_buf,
							cid_buf,
							bsic_buf,
							arfcn_buf);
		}
		else
#endif
		p+=sprintf(p, ",%X,%X,%d,%d", 
						pSVCCellInfo->lac,
						pSVCCellInfo->ci,
						pSVCCellInfo->bsic,
						pSVCCellInfo->arfcn);
	
		//to be consistent with Qualcomm
		if(pSVCCellInfo->gsmBand==1 )
		{
			p+=sprintf(p, ",%d", 0); //GSM_1800
		}
		else if(pSVCCellInfo->gsmBand==2 )
		{
			p+=sprintf(p, ",%d", 1); //GSM_1900
		}
		else if(pSVCCellInfo->gsmBand==0 ||pSVCCellInfo->gsmBand==3 )
		{
			p+=sprintf(p, ",%d", 2); //GSM_900
		}
		else
		{
			p+=sprintf(p, ",-");
		}

		//to be consistent with Qualcomm
		if(pSVCCellInfo->rxSigLevel <=63  )
		{
			p+=sprintf(p, ",%d", pSVCCellInfo->rxSigLevel-111);
		}
		else
		{
			p+=sprintf(p, ",%d",63-111);
		}

		p+=sprintf(p, ",%d,%d,%d,%d,%d,%d", 
						pSVCCellInfo->TxPowerLevel,     /*isaac-20200818 保持与文档描述一致*/
						pSVCCellInfo->RLA,
						0,	  //pSVCCellInfo->DRX  to be consistent with Qualcomm
						pSVCCellInfo->C1,
						pSVCCellInfo->C2,
						pSVCCellInfo->EGPRSSupport);

#if 0
		if(quec_audio_get_call_status())
#else
		if(quec_led_get_call_status())
#endif
		{
			p+=sprintf(p, ",-,-,-,-,-,-,-,-,-,\"-\""); 
		}
		else 
		{
			p+=sprintf(p, ",-,-,-,-,-,-,-,-,-,\"-\""); 
			//when we support voice call add code here
		}

		p+=sprintf(p, "\r\n");
        if (1 != quec_assemble_qeng_resp(resBuf, p))
        {
            return;
        }
	}
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_NEIGHBOURCELL_GET))
	{
		UINT8 lenofmnc=2;//wait asr to support ,add this api
		
		//neighber cell of GSM
		Network_Info_Log("numNCells=%d,numInterRATNCells=%d,numNcellLte=%d", pGSMEngModeInfo->numNCells,pGSMEngModeInfo->numInterRATNCells,pGSMEngModeInfo->nCellInfoListLte.numNcellLte);
		for (cellNUM = 0; cellNUM < pGSMEngModeInfo->numNCells; cellNUM++)
		{
			if( pGSMEngModeInfo->nbCellInfo[cellNUM].ci ==0 )
				continue;
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
			p+=sprintf(p, "+QENG: \"%s\",\"%s\",%3X","neighbourcell","GSM",pGSMEngModeInfo->nbCellInfo[cellNUM].mcc);

			if(lenofmnc==3)
			{
				p+=sprintf(p, ",%03X",pGSMEngModeInfo->nbCellInfo[cellNUM].mnc);
			}
			else
			{
				p+=sprintf(p, ",%02X",pGSMEngModeInfo->nbCellInfo[cellNUM].mnc);
			}
			
#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(lac_buf,0,sizeof(lac_buf));
				memset(cid_buf,0,sizeof(cid_buf));
				memset(bsic_buf,0,sizeof(bsic_buf));
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				GET_VALID_VAL(lac_buf, pGSMEngModeInfo->nbCellInfo[cellNUM].lac);
				GET_VALID_VAL(cid_buf, pGSMEngModeInfo->nbCellInfo[cellNUM].ci);
				GET_VALID_VAL(bsic_buf, pGSMEngModeInfo->nbCellInfo[cellNUM].bsic);
				GET_VALID_VAL(arfcn_buf, pGSMEngModeInfo->nbCellInfo[cellNUM].arfcn);
				p+=sprintf(p, ",%s,%s,%s,%s", 
								lac_buf,
								cid_buf,
								bsic_buf,
								arfcn_buf);
			}
			else
#endif
			{
				p+=sprintf(p, ",%X,%X,%d,%d", 
							pGSMEngModeInfo->nbCellInfo[cellNUM].lac,
							pGSMEngModeInfo->nbCellInfo[cellNUM].ci,
							pGSMEngModeInfo->nbCellInfo[cellNUM].bsic,
							pGSMEngModeInfo->nbCellInfo[cellNUM].arfcn);
			}
		
			if(pSVCCellInfo->rxSigLevel <=63  )
			{
				p+=sprintf(p, ",%d", pSVCCellInfo->rxSigLevel-111);
			}
			else
			{
				p+=sprintf(p, ",%d",63-111);
			}
			p+=sprintf(p, ",%d,%d,%d,%d\r\n", 
						pGSMEngModeInfo->nbCellInfo[cellNUM].C1,
						pGSMEngModeInfo->nbCellInfo[cellNUM].C2,
						pGSMEngModeInfo->nbCellInfo[cellNUM].C31,
						pGSMEngModeInfo->nbCellInfo[cellNUM].C32);;
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
		
		//neighber cell of UMTS
		for (cellNUM = 0; cellNUM < pGSMEngModeInfo->numInterRATNCells; cellNUM++)
		{
			if(pGSMEngModeInfo->InterRATCellInfo[cellNUM].arfcn ==0)
				continue;
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				memset(cid_buf,0,sizeof(cid_buf));
				GET_VALID_VAL(cid_buf, pGSMEngModeInfo->InterRATCellInfo[cellNUM].psc_cellParameterId);
				GET_VALID_VAL(arfcn_buf, pGSMEngModeInfo->InterRATCellInfo[cellNUM].arfcn);
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%s,%s,%d,%d\r\n","neighbourcell","WCDMA",
					arfcn_buf,
					cid_buf,
					pGSMEngModeInfo->InterRATCellInfo[cellNUM].rscp,
					pGSMEngModeInfo->InterRATCellInfo[cellNUM].cpichEcN0);
			}
			else
#endif
			{
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%d,%d,%d,%d\r\n","neighbourcell","WCDMA",
						pGSMEngModeInfo->InterRATCellInfo[cellNUM].arfcn,
						pGSMEngModeInfo->InterRATCellInfo[cellNUM].psc_cellParameterId,
						pGSMEngModeInfo->InterRATCellInfo[cellNUM].rscp,
						pGSMEngModeInfo->InterRATCellInfo[cellNUM].cpichEcN0);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}

		//neighber cell of LTE
		for (cellNUM = 0; cellNUM < pGSMEngModeInfo->nCellInfoListLte.numNcellLte; cellNUM++)
		{
			if(pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].earfcn ==0)
				continue;
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				memset(cid_buf,0,sizeof(cid_buf));
				GET_VALID_VAL(cid_buf, pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].physCellId);
				GET_VALID_VAL(arfcn_buf, pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].earfcn);
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%s,%s,%d,%d\r\n","neighbourcell","LTE",
					arfcn_buf,
					cid_buf,
					pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].rsrp-140,
					pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].rsrq/2-20);
			}
			else
#endif
			{
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%d,%d,%X,%d\r\n","neighbourcell","LTE",
					pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].earfcn,
					pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].physCellId,
					pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].rsrp-140,
					pGSMEngModeInfo->nCellInfoListLte.nCellInfoLte[cellNUM].rsrq/2-20);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
	}
#ifndef ENABLE_DM_LTEONLY
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QSMONC))
	{
		Network_Info_Log("mcc=%d,ci=%d",pSVCCellInfo->mcc,pSVCCellInfo->ci);
        memset(resBuf, 0, sizeof(resBuf));
		p = resBuf;
		if((pSVCCellInfo->mcc > 0 && pSVCCellInfo->mcc < 0x999 ) //check if mcc valid
			&& (pSVCCellInfo->ci > 0 && pSVCCellInfo->ci < 0xFFFF ) )	//check if cell id valid
		{
			memset(plmn_buf,0,sizeof(plmn_buf));
			if(pSVCCellInfo->lenOfMnc==3)
			{
				sprintf(plmn_buf, "%lx,%03lx",pSVCCellInfo->mcc,pSVCCellInfo->mnc );
			}
			else
			{
				sprintf(plmn_buf, "%lx,%02lx",pSVCCellInfo->mcc,pSVCCellInfo->mnc );
			}
			
			p=(char *)Quectel_SMONCPrintf(1, p, plmn_buf, pSVCCellInfo->lac, pSVCCellInfo->ci, pSVCCellInfo->bsic,
				pSVCCellInfo->arfcn, pSVCCellInfo->rxSigLevel, pSVCCellInfo->C1, pSVCCellInfo->C2);
		}
		else
		{
			p=(char *)Quectel_SMONCPrintf(1, p, "000,000", 0, 0, 0, 0, 0, QUEC_INVALID_C_VALUE, QUEC_INVALID_C_VALUE);
		}
        if (1 != quec_assemble_qeng_resp(resBuf, p))
        {
            return;
        }
		
		for( cellNUM = 0; cellNUM < pGSMEngModeInfo->numNCells && cellNUM<QUEC_MAX_SMONC_ITEMS; cellNUM++)
		{
			Network_Info_Log("mcc=%d,ci=%d",pGSMEngModeInfo->nbCellInfo[cellNUM].mcc,pGSMEngModeInfo->nbCellInfo[cellNUM].ci);
			if((pGSMEngModeInfo->nbCellInfo[cellNUM].mcc > 0 && pGSMEngModeInfo->nbCellInfo[cellNUM].mcc < 0x999 ) //check if mcc valid
			&& (pGSMEngModeInfo->nbCellInfo[cellNUM].ci > 0 && pGSMEngModeInfo->nbCellInfo[cellNUM].ci < 0xFFFF ) )   //check if cell id valid
			{
				memset(plmn_buf,0,sizeof(plmn_buf));
				if(pSVCCellInfo->lenOfMnc==3)
				{
					sprintf(plmn_buf, "%lx,%03lx",pGSMEngModeInfo->nbCellInfo[cellNUM].mcc,pGSMEngModeInfo->nbCellInfo[cellNUM].mnc );
				}
				else
				{
					sprintf(plmn_buf, "%lx,%02lx",pGSMEngModeInfo->nbCellInfo[cellNUM].mcc,pGSMEngModeInfo->nbCellInfo[cellNUM].mnc );
				}
				uiCnt++;
                memset(resBuf, 0, sizeof(resBuf));
        		p = resBuf;
				p=(char *)Quectel_SMONCPrintf(0, p, plmn_buf, pGSMEngModeInfo->nbCellInfo[cellNUM].lac, pGSMEngModeInfo->nbCellInfo[cellNUM].ci, pGSMEngModeInfo->nbCellInfo[cellNUM].bsic,
					pGSMEngModeInfo->nbCellInfo[cellNUM].arfcn, pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel, pGSMEngModeInfo->nbCellInfo[cellNUM].C1,pGSMEngModeInfo->nbCellInfo[cellNUM].C2);
                if (1 != quec_assemble_qeng_resp(resBuf, p))
                {
                    return;
                }
			}
		}
		
		for( cellNUM = uiCnt; cellNUM<QUEC_MAX_SMONC_ITEMS; cellNUM++)
		{
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
			p=(char *)Quectel_SMONCPrintf(0, p, "000,000", 0, 0, 0, 0, 0, QUEC_INVALID_C_VALUE, QUEC_INVALID_C_VALUE);
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
        memset(resBuf, 0, sizeof(resBuf));
		p = resBuf;
		p+=sprintf(p, "\r\n");
        if (1 != quec_assemble_qeng_resp(resBuf, p))
        {
            return;
        }
	}
#endif
#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
	else if(CHECK_BIT_SET(network_infor_bitmsk ,MCELL))
	{
		Network_Info_Log("mcc=%d,ci=%d",pSVCCellInfo->mcc,pSVCCellInfo->ci);
        memset(resBuf, 0, sizeof(resBuf));
		p = resBuf;
		p+=sprintf(p, "MCC: %x,MNC: %x,LAC: %5d,Cell ID: %9d,BSIC:%d,(P)BCCH ARFCN: %04x,RxLev: %03X",
				   pSVCCellInfo->mcc, pSVCCellInfo->mnc, pSVCCellInfo->lac, pSVCCellInfo->ci, pSVCCellInfo->bsic, 
				   pSVCCellInfo->arfcn,pSVCCellInfo->rxSigLevel);
		
		if(pSVCCellInfo->rxSigLevel <=63  )
		{
			p+=sprintf(p, ",RxDbm: %d\r\n", pSVCCellInfo->rxSigLevel-111);
		}
		else
		{
			p+=sprintf(p, ",RxDbm: %d\r\n",63-111);
		}
        if (1 != quec_assemble_qeng_resp(resBuf, p))
        {
            return;
        }
	

		for( cellNUM = 0; cellNUM < pGSMEngModeInfo->numNCells && cellNUM<QUEC_MAX_SMONC_ITEMS; cellNUM++)
		{
			//check if cell msg is valid
			if((pGSMEngModeInfo->nbCellInfo[cellNUM].mcc <= 0 || pGSMEngModeInfo->nbCellInfo[cellNUM].mcc > 0x999)
				||(pGSMEngModeInfo->nbCellInfo[cellNUM].ci == 0)
				||(pGSMEngModeInfo->nbCellInfo[cellNUM].lac == 0))
			{
				continue;
			}
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
				
			p+=sprintf(p,"MCC: %x,MNC: %x,LAC: %5d,Cell ID: %9d,BSIC: %03x,(P)BCCH ARFCN: %04x,RxLev: %03x",
					  pGSMEngModeInfo->nbCellInfo[cellNUM].mcc, pGSMEngModeInfo->nbCellInfo[cellNUM].mnc,
					  pGSMEngModeInfo->nbCellInfo[cellNUM].lac, pGSMEngModeInfo->nbCellInfo[cellNUM].ci,
					  pGSMEngModeInfo->nbCellInfo[cellNUM].bsic,pGSMEngModeInfo->nbCellInfo[cellNUM].arfcn,
					  pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel);
			if(pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel <=63  )
			{
				p+=sprintf(p, ",RxDbm: %d\r\n", pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel-111);
			}
			else
			{
				p+=sprintf(p, ",RxDbm: %d\r\n",63-111);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
	}
#endif
	#ifdef QUEC_ENGINEER_OUTPUT
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_ALL_INFO))
	{
		uint8 i=0;
		uint8 *ptemp= (uint8 *)quec_QengineerResBuf;
		Network_Info_Log("ASR_ENG_MODE Start,scellinfo:rxSigLevel=%d,rxSigLevelFull=%d,rxSigLevelSub=%d,rxQualityFull=%d,rxQualitySub=%d",
			pGSMEngModeInfo->svcCellInfo.rxSigLevel,
			pGSMEngModeInfo->svcCellInfo.rxSigLevelFull,
			pGSMEngModeInfo->svcCellInfo.rxSigLevelSub,
			pGSMEngModeInfo->svcCellInfo.rxQualityFull,
			pGSMEngModeInfo->svcCellInfo.rxQualitySub);
		
       ptemp+=sprintf((char *)ptemp,"+QENGINFO: GSM,rxSigLevel:%d,rxSigLevelFull:%d,rxSigLevelSub:%d,rxQualityFull:%d,rxQualitySub:%d",
			    pGSMEngModeInfo->svcCellInfo.rxSigLevel,
				pGSMEngModeInfo->svcCellInfo.rxSigLevelFull,
				pGSMEngModeInfo->svcCellInfo.rxSigLevelSub,
				pGSMEngModeInfo->svcCellInfo.rxQualityFull,
				pGSMEngModeInfo->svcCellInfo.rxQualitySub);

		Network_Info_Log("ASR_ENG_MODE,scellinfo:rac=%d,bsic=%d,nom=%d,nco=%d,bs_pa_mfrms=%d",
				pGSMEngModeInfo->svcCellInfo.rac,
				pGSMEngModeInfo->svcCellInfo.bsic,
				pGSMEngModeInfo->svcCellInfo.nom,
				pGSMEngModeInfo->svcCellInfo.nco,
				pGSMEngModeInfo->svcCellInfo.bs_pa_mfrms);

		ptemp+=sprintf((char *)ptemp,",rac:%d,bsic:%d,nom:%d,nco:%d,bs_pa_mfrms:%d",
			    pGSMEngModeInfo->svcCellInfo.rac,
				pGSMEngModeInfo->svcCellInfo.bsic,
				pGSMEngModeInfo->svcCellInfo.nom,
				pGSMEngModeInfo->svcCellInfo.nco,
				pGSMEngModeInfo->svcCellInfo.bs_pa_mfrms); 

		
		Network_Info_Log("ASR_ENG_MODE,scellinfo:mcc=%d,mnc=%d,lac=%d,ci=%d,arfcn=%d",
				pGSMEngModeInfo->svcCellInfo.mcc,
				pGSMEngModeInfo->svcCellInfo.mnc,
				pGSMEngModeInfo->svcCellInfo.lac,
				pGSMEngModeInfo->svcCellInfo.ci,
				pGSMEngModeInfo->svcCellInfo.arfcn);

		ptemp+=sprintf((char *)ptemp,",mcc:%d,mnc:%d,lac:%d,ci:%d,arfcn:%d",
			pGSMEngModeInfo->svcCellInfo.mcc,
			pGSMEngModeInfo->svcCellInfo.mnc,
			pGSMEngModeInfo->svcCellInfo.lac,
			pGSMEngModeInfo->svcCellInfo.ci,
			pGSMEngModeInfo->svcCellInfo.arfcn);


		Network_Info_Log("ASR_ENG_MODE,scellinfo,c1=%d,c2=%d,c31=%d,c32=%d,t3212=%d,t3312=%d",
			pGSMEngModeInfo->svcCellInfo.C1,
			pGSMEngModeInfo->svcCellInfo.C2,
			pGSMEngModeInfo->svcCellInfo.C31,
			pGSMEngModeInfo->svcCellInfo.C32,
			pGSMEngModeInfo->svcCellInfo.t3212,
			pGSMEngModeInfo->svcCellInfo.t3312);
		
	    ptemp+=sprintf((char *)ptemp,",C1:%d,C2:%d,C31:%d,C32:%d,t3212:%d,t3312:%d",
			pGSMEngModeInfo->svcCellInfo.C1,
			pGSMEngModeInfo->svcCellInfo.C2,
			pGSMEngModeInfo->svcCellInfo.C31,
			pGSMEngModeInfo->svcCellInfo.C32,
			pGSMEngModeInfo->svcCellInfo.t3212,
			pGSMEngModeInfo->svcCellInfo.t3312);
		quec_siolib_transmit_to_atp(quec_qengineer_atp, "\r\n", 2, NULL);
		quec_siolib_transmit_to_atp(quec_qengineer_atp,(uint8 *)quec_QengineerResBuf,ptemp-(uint8 *)quec_QengineerResBuf,NULL);
		memset(quec_QengineerResBuf,0,QUEC_QENG_RESBUFLEN_MIN);
		ptemp = (uint8 *)quec_QengineerResBuf;
		Network_Info_Log("ASR_ENG_MODE,scellinfo,pbcchSupport=%d,TxPowerLevel=%d,timingAdv=%d,hoppingChannel=%d,EGPRSSupport=%d,ChType=%d",
			pGSMEngModeInfo->svcCellInfo.pbcchSupport,
			pGSMEngModeInfo->svcCellInfo.TxPowerLevel,
			pGSMEngModeInfo->svcCellInfo.timingAdv,
			pGSMEngModeInfo->svcCellInfo.hoppingChannel,
			pGSMEngModeInfo->svcCellInfo.EGPRSSupport,
			pGSMEngModeInfo->svcCellInfo.ChType);

		 ptemp+=sprintf((char *)ptemp,",pbcchSupport:%d,TxPowerLevel:%d,timingAdv:%d,hoppingChannel:%d,EGPRSSupport:%d,ChType:%d",
			pGSMEngModeInfo->svcCellInfo.pbcchSupport,
			pGSMEngModeInfo->svcCellInfo.TxPowerLevel,
			pGSMEngModeInfo->svcCellInfo.timingAdv,
			pGSMEngModeInfo->svcCellInfo.hoppingChannel,
			pGSMEngModeInfo->svcCellInfo.EGPRSSupport,
			pGSMEngModeInfo->svcCellInfo.ChType);

		Network_Info_Log("ASR_ENG_MODE,scellinfo,nccPermitted=%d,RadioLinkTimeout=%d,hoCount=%d,hoSuccessCount=%d,chanAssCount=%d,chanAssSuccessCount=%d",		
				pGSMEngModeInfo->svcCellInfo.nccPermitted,
			pGSMEngModeInfo->svcCellInfo.RadioLinkTimeout,
			pGSMEngModeInfo->svcCellInfo.hoCount,
			pGSMEngModeInfo->svcCellInfo.hoSuccessCount,
			pGSMEngModeInfo->svcCellInfo.chanAssCount,
			pGSMEngModeInfo->svcCellInfo.chanAssSuccessCount);
		
		ptemp+=sprintf((char *)ptemp,",nccPermitted:%d,RadioLinkTimeout:%d,hoCount:%d,hoSuccessCount:%d,chanAssCount:%d,chanAssSuccessCount:%d",
				pGSMEngModeInfo->svcCellInfo.nccPermitted,
			pGSMEngModeInfo->svcCellInfo.RadioLinkTimeout,
			pGSMEngModeInfo->svcCellInfo.hoCount,
			pGSMEngModeInfo->svcCellInfo.hoSuccessCount,
			pGSMEngModeInfo->svcCellInfo.chanAssCount,
			pGSMEngModeInfo->svcCellInfo.chanAssSuccessCount);
	
		Network_Info_Log("ASR_ENG_MODE,scellinfo,arfcnTch=%d,timeSlot=%d,isInPacketIdle=%d,IsForbiddenLA=%d,CellPriority=%d,HSN=%d",	
				pGSMEngModeInfo->svcCellInfo.arfcnTch,
			pGSMEngModeInfo->svcCellInfo.timeSlot,
			pGSMEngModeInfo->svcCellInfo.isInPacketIdle,
			pGSMEngModeInfo->svcCellInfo.IsForbiddenLA,
			pGSMEngModeInfo->svcCellInfo.CellPriority,
			pGSMEngModeInfo->svcCellInfo.HSN);

		ptemp+=sprintf((char *)ptemp,",arfcnTch:%d,timeSlot:%d,isInPacketIdle:%d,IsForbiddenLA:%d,CellPriority:%d,HSN:%d",
				pGSMEngModeInfo->svcCellInfo.arfcnTch,
			pGSMEngModeInfo->svcCellInfo.timeSlot,
			pGSMEngModeInfo->svcCellInfo.isInPacketIdle,
			pGSMEngModeInfo->svcCellInfo.IsForbiddenLA,
			pGSMEngModeInfo->svcCellInfo.CellPriority,
			pGSMEngModeInfo->svcCellInfo.HSN);
		
		quec_siolib_transmit_to_atp(quec_qengineer_atp,(uint8 *)quec_QengineerResBuf,ptemp-(uint8 *)quec_QengineerResBuf,NULL);
		memset(quec_QengineerResBuf,0,QUEC_QENG_RESBUFLEN_MIN);
		ptemp =(uint8 *)quec_QengineerResBuf;
/*		
		Network_Info_Log("ASR_ENG_MODE,scellinfo,HoppingGroup=%d,gsmBand=%d,channelMode=%d,lenOfMnc=%d,codecType=%d,speechCodecRate=%d",	
				pGSMEngModeInfo->svcCellInfo.HoppingGroup,
			pGSMEngModeInfo->svcCellInfo.gsmBand,
			pGSMEngModeInfo->svcCellInfo.channelMode,
			pGSMEngModeInfo->svcCellInfo.lenOfMnc,
			pGSMEngModeInfo->svcCellInfo.codecType,
			pGSMEngModeInfo->svcCellInfo.speechCodecRate);
		
		ptemp+=sprintf((char *)ptemp,",HoppingGroup:%d,gsmBand:%d,channelMode:%d,lenOfMnc:%d,codecType:%d,speechCodecRate:%d",
				pGSMEngModeInfo->svcCellInfo.HoppingGroup,
			pGSMEngModeInfo->svcCellInfo.gsmBand,
			pGSMEngModeInfo->svcCellInfo.channelMode,
			pGSMEngModeInfo->svcCellInfo.lenOfMnc,
			pGSMEngModeInfo->svcCellInfo.codecType,
			pGSMEngModeInfo->svcCellInfo.speechCodecRate);
*/				
		
		Network_Info_Log("ASR_ENG_MODE,scellinfo,RLA=%d,DRX=%d,maio=%d,succeededGsmIratReselectionCount=%d,succeededGsmHandoverCount=%d",
			pGSMEngModeInfo->svcCellInfo.RLA,
			pGSMEngModeInfo->svcCellInfo.DRX,
			pGSMEngModeInfo->svcCellInfo.maio,
			pGSMEngModeInfo->svcCellInfo.succeededGsmIratReselectionCount,
			pGSMEngModeInfo->svcCellInfo.succeededGsmHandoverCount);
       ptemp+=sprintf((char *)ptemp,",RLA:%d,DRX:%d,maio:%d,succeededGsmIratReselectionCount:%d,succeededGsmHandoverCount:%d",
			pGSMEngModeInfo->svcCellInfo.RLA,
			pGSMEngModeInfo->svcCellInfo.DRX,
			pGSMEngModeInfo->svcCellInfo.maio,
			pGSMEngModeInfo->svcCellInfo.succeededGsmIratReselectionCount,
			pGSMEngModeInfo->svcCellInfo.succeededGsmHandoverCount);
	    quec_siolib_transmit_to_atp(quec_qengineer_atp,(uint8 *)quec_QengineerResBuf,ptemp-(uint8 *)quec_QengineerResBuf,NULL);
		memset(quec_QengineerResBuf,0,QUEC_QENG_RESBUFLEN_MIN);
		ptemp =(uint8 *)quec_QengineerResBuf;
		Network_Info_Log("ASR_ENG_MODE,END,scell_meas_6,ptemp=%p,quec_QengineerResLen=%p,%d",ptemp,quec_QengineerResBuf,ptemp-(uint8 *)quec_QengineerResBuf);
	}
	#endif
#ifdef QUECTEL_CELL
    else if (CHECK_BIT_SET(network_infor_bitmsk ,CELL_GET))
	{
        memset(resBuf, 0, sizeof(resBuf));
	    p = resBuf;
        /*isaac 20201223 serving cell info,若不插卡扫描，显示驻留小区信息，
         *不再显示state "CONNECT","NOCONN","LIMSRV"
         */
        p+=sprintf(p, "+QCELL: \"%s\",\"%s\",%03x","servingcell","GSM",pSVCCellInfo->mcc); 
        
        if(pSVCCellInfo->lenOfMnc==3)
		{
	        p+=sprintf(p, ",%03X",pSVCCellInfo->mnc);
		}
		else
		{
			p+=sprintf(p, ",%02X",pSVCCellInfo->mnc);
		}
        p+=sprintf(p, ",%04X,%x,%d,%d\r\n",pSVCCellInfo->lac,
                        pSVCCellInfo->ci,
                        pSVCCellInfo->bsic,
                        pSVCCellInfo->rxSigLevel);
        
        if (1 != quec_assemble_qeng_resp(resBuf, p))
		{
			return;
		}
        
        Network_Info_Log("[quec ncell]pGSMEngModeInfo: numNCells %d",pGSMEngModeInfo->numNCells);
      
		for( cellNUM = 0; (cellNUM < pGSMEngModeInfo->numNCells) && (cellNUM < QUEC_MAX_SMONC_ITEMS-1); cellNUM++)
		{  
		    /*check vaild neighbourcell cell info */
		    if ( (pGSMEngModeInfo->nbCellInfo[cellNUM].ci == NCELL_CELL_ID_MAX) ||
                 (pGSMEngModeInfo->nbCellInfo[cellNUM].ci == NCELL_CELL_ID_MIN) ||
                 (pGSMEngModeInfo->nbCellInfo[cellNUM].bsic == NCELL_BSIC_MAX) ||
  				   (pGSMEngModeInfo->nbCellInfo[cellNUM].mcc == NCELL_CELL_MCC_INVALID) )
            {
                continue;
            }
            memset(resBuf, 0, sizeof(resBuf));
	        p = resBuf;
            
			p+=sprintf(p, "+QCELL: \"%s\",\"%s\",%03x,%02x,%02x,%x,%d,%d\r\n","neighbourcell","GSM",
                             pGSMEngModeInfo->nbCellInfo[cellNUM].mcc,
                             pGSMEngModeInfo->nbCellInfo[cellNUM].mnc,
                             pGSMEngModeInfo->nbCellInfo[cellNUM].lac,
                             pGSMEngModeInfo->nbCellInfo[cellNUM].ci,
                             pGSMEngModeInfo->nbCellInfo[cellNUM].bsic,
                             pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel);
           
            if (1 != quec_assemble_qeng_resp(resBuf, p))
	        {
	            return;
	        }
		}
	}
#endif
#ifdef QUEC_QCELLINFO_SUPPORT
        else if (CHECK_BIT_SET(network_infor_bitmsk ,QCELLINFOEX_GET))
        {
            memset(resBuf, 0, sizeof(resBuf));
            p = resBuf;
            p+=sprintf(p, "+QCELLINFO: \"%s\",\"%s\",%03x","servingcell","GSM",pSVCCellInfo->mcc); 
            
            if(pSVCCellInfo->lenOfMnc==3)
            {
                p+=sprintf(p, ",%03X",pSVCCellInfo->mnc);
            }
            else
            {
                p+=sprintf(p, ",%02X",pSVCCellInfo->mnc);
            }
            p+=sprintf(p, ",%04X,%x,%d,%d,%d,%d\r\n",pSVCCellInfo->lac,
                            pSVCCellInfo->ci,
                            pSVCCellInfo->bsic,
                            pSVCCellInfo->rxSigLevel,
                            pSVCCellInfo->rxSigLevel-111,
                            pSVCCellInfo->arfcn);
            
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
            
            Network_Info_Log("[quec qcellinfo] pGSMEngModeInfo: numNCells %d",pGSMEngModeInfo->numNCells);
          
            for( cellNUM = 0; (cellNUM < pGSMEngModeInfo->numNCells) && (cellNUM < QUEC_MAX_SMONC_ITEMS-1); cellNUM++)
            {  
                /*check vaild neighbourcell cell info */
                if ( (pGSMEngModeInfo->nbCellInfo[cellNUM].ci == NCELL_CELL_ID_MAX) ||
                     (pGSMEngModeInfo->nbCellInfo[cellNUM].ci == NCELL_CELL_ID_MIN) ||
                     (pGSMEngModeInfo->nbCellInfo[cellNUM].bsic == NCELL_BSIC_MAX) )
                {
                    continue;
                }
                memset(resBuf, 0, sizeof(resBuf));
                p = resBuf;
                
                p+=sprintf(p, "+QCELLINFO: \"%s\",\"%s\",%03x,%02x,%02x,%x,%d,%d,%d,%d\r\n","neighbourcell","GSM",
                                 pGSMEngModeInfo->nbCellInfo[cellNUM].mcc,
                                 pGSMEngModeInfo->nbCellInfo[cellNUM].mnc,
                                 pGSMEngModeInfo->nbCellInfo[cellNUM].lac,
                                 pGSMEngModeInfo->nbCellInfo[cellNUM].ci,
                                 pGSMEngModeInfo->nbCellInfo[cellNUM].bsic,
                                 pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel,
                                 pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel-111,
                                 pGSMEngModeInfo->nbCellInfo[cellNUM].arfcn);
               
                if (1 != quec_assemble_qeng_resp(resBuf, p))
                {
                    return;
                }
            }
        }
#endif
#ifdef QUEC_CCED_SUPPORT
		else if (CHECK_BIT_SET(network_infor_bitmsk,QUEC_CCED_S_GET))
		{
			int quec_scell_rxlev = 0;
			memset(resBuf, 0, sizeof(resBuf));
			p = resBuf;
	
			//info-servingcell
			if(quec_cced_mode == QUEC_CCED_NO_AUTO_MODE) 
			{
				p+=sprintf(p, "+CCED:%s:%X", 
					"GSM current cell",
					pSVCCellInfo->mcc);

				if(pSVCCellInfo->lenOfMnc==3)
				{
			        p+=sprintf(p, ",%03X",pSVCCellInfo->mnc);
				}
				else
				{
					p+=sprintf(p, ",%02X",pSVCCellInfo->mnc);
				}

				p+=sprintf(p, ",%X,%X,%d", 
					pSVCCellInfo->lac,
					pSVCCellInfo->ci,
					pSVCCellInfo->bsic);
				
				//Consistent with QDM038_EU_IE parameters
				quec_scell_rxlev = pSVCCellInfo->rxSigLevel;
				if(quec_scell_rxlev < 0  )								 
				{
					p+=sprintf(p, ",%d", 0);
				}
				else if (quec_scell_rxlev > 63	)
				{
					p+=sprintf(p, ",%d",63);
				}
				else 
				{
					p+=sprintf(p, ",%d", quec_scell_rxlev);
				}
				
				p+=sprintf(p, ",%d\r\n", pSVCCellInfo->rxSigLevelSub);
				p+=sprintf(p, ",%d\r\n", pSVCCellInfo->arfcn);
				
				if (1 != quec_assemble_qeng_resp(resBuf, p))
				{
					return;
				}
			}
		}
		else if (CHECK_BIT_SET(network_infor_bitmsk,QUEC_CCED_NB_GET))
		{
			int quec_nbcell_rxlev = 0;
			int neighbourmaximum = 6;
			int neighbourvaild = 0;
			memset(resBuf, 0, sizeof(resBuf));
			p = resBuf;
			
			//info-neighbourcell of GSM
			if (quec_cced_mode == QUEC_CCED_NO_AUTO_MODE) 
			{
				for (cellNUM = 0; cellNUM < pGSMEngModeInfo->numNCells; cellNUM++)
				{
					if( pGSMEngModeInfo->nbCellInfo[cellNUM].ci ==0 )
						continue;

					neighbourvaild++;
					if( neighbourvaild == neighbourmaximum )
					{
						break;
					}
					memset(resBuf, 0, sizeof(resBuf));
					p = resBuf;
						
					p+=sprintf(p, "+CCED:%s:%X", 
						"GSM neighbour cell",
						pGSMEngModeInfo->nbCellInfo[cellNUM].mcc);
		
					if(pGSMEngModeInfo->nbCellInfo[cellNUM].lenOfMnc==3)
					{
				        p+=sprintf(p, ",%03X",pGSMEngModeInfo->nbCellInfo[cellNUM].mnc);
					}
					else
					{
						p+=sprintf(p, ",%02X",pGSMEngModeInfo->nbCellInfo[cellNUM].mnc);
					}	


					p+=sprintf(p, ",%X,%X,%d", 
						pGSMEngModeInfo->nbCellInfo[cellNUM].lac,
						pGSMEngModeInfo->nbCellInfo[cellNUM].ci,
						pGSMEngModeInfo->nbCellInfo[cellNUM].bsic);
					
					//Consistent with QDM038_EU_IE parameters	
					quec_nbcell_rxlev = pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel;
					if(quec_nbcell_rxlev < 0  ) 							  
					{
						p+=sprintf(p, ",%d", 0);
					}
					else if (quec_nbcell_rxlev > 63  )
					{
						p+=sprintf(p, ",%d",63);
					}
					else 
					{
						p+=sprintf(p, ",%d", quec_nbcell_rxlev);
					}
					
					p+=sprintf(p, "\r\n");
		
					if (1 != quec_assemble_qeng_resp(resBuf, p))
					{
						return;
					}
				}	
			}
		}

#endif

	else
	{
#endif

#ifdef AT_FOR_GW20180208SN
	current_accessTechnology = 0;
	current_bandInd = pSVCCellInfo->gsmBand;
	m_channel = (UINT32)pSVCCellInfo->arfcn; 
	if((pSVCCellInfo->mcc != 0xFFFF) && (pSVCCellInfo->mnc != 0xFFFF))
	{
		sprintf( (char *)curr_operIdLongStr, "%03x+%02x", pSVCCellInfo->mcc,pSVCCellInfo->mnc);
	}
	else if(pSVCCellInfo->ci == 0xFFFF)
	{
		sprintf( (char *)curr_operIdLongStr, "");
	}
	if(((pSVCCellInfo->lac == 0xFFFF) || (pSVCCellInfo->lac == 0xFFFE)) && (pSVCCellInfo->ci == 0xFFFF))
	{
		m_lac_tac = 0;
		m_cell_id = 0;
	}
	else
	{
		m_lac_tac = pSVCCellInfo->lac;
		m_cell_id = pSVCCellInfo->ci;
	}
		
	//m_cell_id = pSVCCellInfo->ci;
	m_bsic_phycellid = pSVCCellInfo->bsic;
	if(pSVCCellInfo->rxSigLevel != 0xFF)
	{
		m_rxdbm = pSVCCellInfo->rxSigLevel-111;
	}
	else
	{
		m_rxdbm = 199;
	}
			
	if(pGPRSPTMInfo->txPower != 0xFF)
	{
		m_txdbm = pGPRSPTMInfo->txPower;
	}
	else
	{
		m_txdbm = 199;
	}

	m_rsrp = 0;
	m_rsrq = 0;
	m_sinr = 0;
	if(gMMZRSSI == 3)
	{
		return;
	}
#endif

	// Part I: +EEMGINFOBASIC
	sprintf(resBuf, "+EEMGINFOBASIC: %d\r\n", pGsmEngmodeInfoInd->mode);
	ATRESP(reqHandle, 0, 0, resBuf);

	// Part II: +EEMGINFOSVC
	// -6- mcc, mnc, lac, ci, nom, nco
	sprintf(resBuf, "+EEMGINFOSVC: %d, %d, %d, %d, %d, %d,", pSVCCellInfo->mcc,
	                                                         pSVCCellInfo->mnc,
	                                                         pSVCCellInfo->lac,
	                                                         pSVCCellInfo->ci,
	                                                         pSVCCellInfo->nom,
	                                                         pSVCCellInfo->nco);

	// -5- bsic, C1, C2, TA, TxPwr
	sprintf(tempBuf, " %d, %d, %d, %d, %d, ", pSVCCellInfo->bsic,
	                                          pSVCCellInfo->C1,
	                                          pSVCCellInfo->C2,
	                                          pSVCCellInfo->timingAdv,
	                                          pSVCCellInfo->TxPowerLevel);
	strcat(resBuf, tempBuf);
	// -5- RxSig, RxSigFull, RxSigSub, RxQualFull, RxQualSub
	sprintf(tempBuf, " %d, %d, %d, %d, %d, ", pSVCCellInfo->rxSigLevel,
	                                          pSVCCellInfo->rxSigLevelFull,
	                                          pSVCCellInfo->rxSigLevelSub,
	                                          pSVCCellInfo->rxQualityFull,
	                                          pSVCCellInfo->rxQualitySub);
	strcat(resBuf, tempBuf);
	// -7- ARFCB_tch, hopping_chnl, chnl_type, TS, PacketIdle, rac, arfcn
	sprintf(tempBuf, " %d, %d, %d, %d, %d, %d, %d, ", pSVCCellInfo->arfcnTch,
	                                                  pSVCCellInfo->hoppingChannel,
	                                                  pSVCCellInfo->ChType,
	                                                  pSVCCellInfo->timeSlot,
	                                                  pSVCCellInfo->isInPacketIdle,
	                                                  pSVCCellInfo->rac,
	                                                  pSVCCellInfo->arfcn);
	strcat(resBuf, tempBuf);
	// -7- bs_pa_mfrms, C31, C32, t3212, t3312, pbcch_support, EDGE_support
	sprintf(tempBuf, " %d, %d, %d, %d, %d, %d, %d, ", pSVCCellInfo->bs_pa_mfrms,
	                                                  pSVCCellInfo->C31,
	                                                  pSVCCellInfo->C32,
	                                                  pSVCCellInfo->t3212,
	                                                  pSVCCellInfo->t3312,
	                                                  pSVCCellInfo->pbcchSupport,
	                                                  pSVCCellInfo->EGPRSSupport);
	strcat(resBuf, tempBuf);
	// -6- ncc_permitted, rl_timeout, ho_count, ho_succ, chnl_access_count, chnl_access_succ_count
	sprintf(tempBuf, " %d, %d, %d, %d, %d, %d,", pSVCCellInfo->nccPermitted,
	                                                pSVCCellInfo->RadioLinkTimeout,
	                                                pSVCCellInfo->hoCount,
	                                                pSVCCellInfo->hoSuccessCount,
	                                                pSVCCellInfo->chanAssCount,
	                                                pSVCCellInfo->chanAssSuccessCount);
	strcat(resBuf, tempBuf);
    // add for two paramters  -2-- gsmBand,channelMode
	sprintf(tempBuf, " %d, %d\r\n", pSVCCellInfo->gsmBand,
	                                                pSVCCellInfo->channelMode);
	strcat(resBuf, tempBuf);

	
	ATRESP(reqHandle, 0, 0, resBuf);

	// Part III: +EEMGINFOPS
	// -5- PS_attached, attach_type, service_type, tx_power, c_value
	sprintf(resBuf, "+EEMGINFOPS: %d, %d, %d, %d, %d, ", pGPRSPTMInfo->GPRSAttached,
	                                                     pGPRSPTMInfo->GPRSAttachType,
	                                                     pGPRSPTMInfo->gprsServiceType,
	                                                     pGPRSPTMInfo->txPower,
	                                                     pGPRSPTMInfo->cValue);

	// -6- ul_ts, dl_ts, ul_cs, dl_cs, ul_modulation, dl_modulation
	sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, ", pGPRSPTMInfo->ulTimeSlot,
                                                 pGPRSPTMInfo->dlTimeSlot,
                                                 pGPRSPTMInfo->CodingSchemeUL,
                                                 pGPRSPTMInfo->CodingSchemeDL,
                                                 pGPRSPTMInfo->ulMod,
                                                 pGPRSPTMInfo->dlMod);

	strcat(resBuf, tempBuf);
	// -6- gmsk_cv_bep, 8psk_cv_bep, gmsk_mean_bep, 8psk_mean_bep, EDGE_bep_period, single_gmm_rej_cause
	sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, ", pGPRSPTMInfo->egprsBep.gmskCvBep,
                                                 pGPRSPTMInfo->egprsBep.eightPskCvBep,
                                                 pGPRSPTMInfo->egprsBep.gmskMeanBep,
                                                 pGPRSPTMInfo->egprsBep.eightPskMeanBep,
                                                 pGPRSPTMInfo->EGPRSBEPPeriod,
                                                 pGPRSPTMInfo->IsSingleGmmRejectCause);

	strcat(resBuf, tempBuf);
	// -6- pdp_active_num, mac_mode, network_control, network_mode, EDGE_slq_measurement_mode, edge_status
	//[klockwork][issue id: 1051]
	snprintf(tempBuf, sizeof(tempBuf), "%d, %d, %d, %d, %d, %d\r\n", pGPRSPTMInfo->NumActivePDPContext,
                                                   pGPRSPTMInfo->MacMode,
                                                   pGPRSPTMInfo->NetworkControl,
                                                   pGPRSPTMInfo->NetworkMode,
                                                   pGPRSPTMInfo->EGPRSLQMeasurementMode,
                                                   pGPRSPTMInfo->egprsBep.status);

	strcat(resBuf, tempBuf);
	ATRESP(reqHandle, 0, 0, resBuf);

	// Part IV: +EEMGINFONC

	/* Neighbors number */
	if (pGSMEngModeInfo->numNCells > MAX_GSM_NEIGHBORING_CELLS)
	{
		ERRMSG("pGSMEngModeInfo->numNCells  %d larger than MAX_GSM_NEIGHBORING_CELLS \r\n", pGSMEngModeInfo->numNCells);
		return;
	}
	for (cellNUM = 0; cellNUM < pGSMEngModeInfo->numNCells; cellNUM++)
	{
		// -6- nc_num, mcc, mnc, lac, rac, ci
		sprintf(resBuf, "+EEMGINFONC: %d, %d, %d, %d, %d, %d,", cellNUM,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].mcc,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].mnc,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].lac,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].rac,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].ci);

		// -7- rx_lv, bsic, C1, C2, arfcn, C31, C32
		sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, %d\r\n",
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].rxSigLevel,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].bsic,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].C1,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].C2,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].arfcn,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].C31,
		                       pGSMEngModeInfo->nbCellInfo[cellNUM].C32);
		strcat(resBuf, tempBuf);
		ATRESP(reqHandle, 0, 0, resBuf);
	}

	// Part V: +EEMGINBFTM
	// -8- EngMode, mcc, mnc, lac, ci, bsic, C1, C2
	sprintf(resBuf, "+EEMGINBFTM: %d, %d, %d, %d, %d, %d, %d, %d, ", *pEngModeRepOpt,
	                                                                 pSVCCellInfo->mcc,
	                                                                 pSVCCellInfo->mnc,
	                                                                 pSVCCellInfo->lac,
	                                                                 pSVCCellInfo->ci,
	                                                                 pSVCCellInfo->bsic,
	                                                                 pSVCCellInfo->C1,
	                                                                 pSVCCellInfo->C2);
	// -5- Timing advace, TxPowerLevel, rxSigLevel, rxSigLevelFull, rxSigLevelSub
	sprintf(tempBuf, "%d, %d, %d, %d, %d,", pSVCCellInfo->timingAdv,
	                                        pSVCCellInfo->TxPowerLevel,
	                                        pSVCCellInfo->rxSigLevel,
	                                        pSVCCellInfo->rxSigLevelFull,
	                                        pSVCCellInfo->rxSigLevelSub);
	strcat(resBuf, tempBuf);

	// -6- rxQualityFull, rxQualitySub, arfcnTch, hopping status, channel type, server timeslot
	sprintf(tempBuf, "%d, %d, %d, %d, %d, %d\r\n", pSVCCellInfo->rxQualityFull,
	                                               pSVCCellInfo->rxQualitySub,
	                                               pSVCCellInfo->arfcnTch,
	                                               pSVCCellInfo->hoppingChannel,
	                                               pSVCCellInfo->ChType,
	                                               pSVCCellInfo->timeSlot);
	strcat(resBuf, tempBuf);
	ATRESP(reqHandle, 0, 0, resBuf);

	//+EEMGINFOGMM : 4+3+4+3(serviceStatus,LAU_status,LAU_count)
	sprintf(resBuf, "+EEMGINFOGMM: %d, %d, %d, %d,", pGMMInfo->MccLastRegisteredNetwork,
	                                                 pGMMInfo->MncLastRegisteredNetwork,
	                                                 pGMMInfo->TMSI,
	                                                 pGMMInfo->PTMSI);

	sprintf(tempBuf, "%d, %d, %d,", pGMMInfo->IsSingleMmRejectCause,
	                                pGMMInfo->MMRejectCause,
	                                pGMMInfo->currentBandMode);
	strcat(resBuf, tempBuf);


	sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, %d\r\n", pGMMInfo->mmState,
	                                       pGMMInfo->gmmState,
	                                       pGMMInfo->gprsReadyState,
	                                       pGMMInfo->readyTimerValueInSecs,
	                                       pGMMInfo->serviceStatus,
	                                       pGMMInfo->LAU_status,
	                                       pGMMInfo->LAU_count);
	strcat(resBuf, tempBuf);
	ATRESP(reqHandle, 0, 0, resBuf);
#ifdef QUECTEL_NETWORK_SUPPORT      
	}
#endif

	return;
}


#endif

/****************************************************************
 *  F@: processEMumtsINFOSVCInfoInd - Process UMTS engine mode info
 */
static void processEMumtsINFOSVCInfoInd(UINT32 reqHandle, const void *pParam)
{
	CiDevPrimUmtsEngmodeScellInfoInd * pUmtsEngmodeScellInfoInd=NULL;
	CiDevUmtsServingCellInfo *pUmtsServingCellInfo=NULL;
	char resBuf[500];
	char tempBuf[80];
	UINT8 *p_UMTS_EM_IND_SEQ;
	
	if (reqHandle == IND_REQ_HANDLE) {
		p_UMTS_EM_IND_SEQ = &g_UMTS_EM_IND_SEQ;
	} else {
		p_UMTS_EM_IND_SEQ = &g_UMTS_EM_IND_SEQ_1;
	}

	memset(resBuf, 0, sizeof(resBuf));
	memset(tempBuf, 0, sizeof(tempBuf));
	
	pUmtsEngmodeScellInfoInd = (CiDevPrimUmtsEngmodeScellInfoInd *)pParam;
	pUmtsServingCellInfo = &(pUmtsEngmodeScellInfoInd->info);
	
#ifdef QUECTEL_NETWORK_SUPPORT
	char *p;
	UINT32 atHandle = GET_AT_HANDLE(reqHandle);
	char state[20]={0};
#ifdef __QUEC_OEM_VER_LD__//chaozhou add for landi format 2016/09/25
	char					   cid_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   pci_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   lac_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   earfcn_buf[LANDI_VAL_BUF_MAX] = {0};
#endif

#ifdef QUECTEL_NETWORK_REJECT_URC_SUPPORT
	if((netreject_mode==1) && (report_flag==TRUE))
	{
		char tempBuf[256] = {0};
		memset(tempBuf, 0, 256);
		report_flag=FALSE;
		if(report_type==CI_DEV_COMMON_REPORT_MM)
		{
			sprintf(tempBuf, "+QNETWORKSTATUS: MM LU_REJECT,%d,\"%s\",%03x%02x\r\n",
														reject_cause,result_ptr->text,
														pUmtsServingCellInfo->sCellParam.mcc,
														pUmtsServingCellInfo->sCellParam.mnc);
		}
		else if(report_type==CI_DEV_COMMON_REPORT_GMM)
		{
			sprintf(tempBuf, "+QNETWORKSTATUS: GMM REJECT,%d,\"%s\",%03x%02x\r\n",
														reject_cause,result_ptr->text, 
														pUmtsServingCellInfo->sCellParam.mcc,
														pUmtsServingCellInfo->sCellParam.mnc);
		}
		else
		{
			sprintf(tempBuf, "+QNETWORKSTATUS: SM REJECT,%d,\"%s\",%03x%02x\r\n",
														reject_cause,result_ptr->text, 
														pUmtsServingCellInfo->sCellParam.mcc,
														pUmtsServingCellInfo->sCellParam.mnc);
		}
		at_urc_send(NUM_OF_TEL_ATP, (UINT8 *)tempBuf, strlen(tempBuf), TRUE, URC_OUT_METHOD_UNICAST, NULL);
	}
#endif

	if(CHECK_BIT_SET(network_infor_bitmsk ,QNWINFO_GET))
	{
		
	#if QUEC_DUAL_SIM_SUPPORT
		Quec_qnwinfo_type *p_quec_qnwinfo = &quec_qnwinfo[(reqHandle == IND_REQ_HANDLE) ? SIM1 : SIM2];
	#else
		Quec_qnwinfo_type *p_quec_qnwinfo = &quec_qnwinfo;
	#endif	
	
		Network_Info_Log("processEMLteINFOSVCInfoInd,band=%d,dlEuArfcn=%d",pUmtsServingCellInfo->sCellParam.band,pUmtsServingCellInfo->sCellParam.arfcn);
		sprintf( &p_quec_qnwinfo->plmn[0],
					"%03x%02x",
					pUmtsServingCellInfo->sCellParam.mcc,
					pUmtsServingCellInfo->sCellParam.mnc);
	
		if(pUmtsServingCellInfo->sCellParam.arfcn >=10562 &&pUmtsServingCellInfo->sCellParam.arfcn <=10838)//band 1
		{	 
			sprintf( &p_quec_qnwinfo->band_description[0],"WCDMA 2100");
		}
		else if(pUmtsServingCellInfo->sCellParam.arfcn >=9662 &&pUmtsServingCellInfo->sCellParam.arfcn <=9938)//band 2
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"WCDMA 1900");
		}
		else if(pUmtsServingCellInfo->sCellParam.arfcn >=1162 &&pUmtsServingCellInfo->sCellParam.arfcn <=1513)//band 3
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"WCDMA 1800");
		}
		else if(pUmtsServingCellInfo->sCellParam.arfcn >=1537 &&pUmtsServingCellInfo->sCellParam.arfcn <=1738)//band 4
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"WCDMA 1700");
		}
		else if(pUmtsServingCellInfo->sCellParam.arfcn >=4357 &&pUmtsServingCellInfo->sCellParam.arfcn <=4458)//band 5,6
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"WCDMA 850");
		}
		else if(pUmtsServingCellInfo->sCellParam.arfcn >=2237 &&pUmtsServingCellInfo->sCellParam.arfcn <=2563)//band 7
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"WCDMA 2500");
		}
		else if(pUmtsServingCellInfo->sCellParam.arfcn >=2937 &&pUmtsServingCellInfo->sCellParam.arfcn <=3088)//band 8
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"WCDMA 900");
		}
		else if(pUmtsServingCellInfo->sCellParam.arfcn >=9237 &&pUmtsServingCellInfo->sCellParam.arfcn <=9387)//band 9
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"WCDMA 1700");
		}
		else 
		{
			sprintf( &p_quec_qnwinfo->band_description[0],"WCDMA BAND UNKNOWN");
		}

		
		if(pUmtsServingCellInfo->sCellParam.HSDPASupport && pUmtsServingCellInfo->sCellParam.HSUPASupport )
		{
			sprintf( &p_quec_qnwinfo->act[0],"HSPA+");
		}
		else if(pUmtsServingCellInfo->sCellParam.HSDPASupport )
		{
			sprintf( &p_quec_qnwinfo->act[0],"HSDPA");
		}
		else if(pUmtsServingCellInfo->sCellParam.HSUPASupport )
		{
			sprintf( &p_quec_qnwinfo->act[0],"HSUPA");
		}
		else
		{
			sprintf( &p_quec_qnwinfo->act[0],"WCDMA");
		}
		
		p_quec_qnwinfo->active_channel=pUmtsServingCellInfo->sCellParam.arfcn;
		
		//sprintf(resBuf,"+QNWINFO: \"%s\",\"%s\",\"%s\",%d ",quec_qnwinfo.act,quec_qnwinfo.plmn,quec_qnwinfo.band_description,quec_qnwinfo.active_channel);	
		//ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
		
		//DEV_SetEngModeIndicatorOption(atHandle, 0, 0);//close engmode
		//BIT_CLR(network_infor_bitmsk, QNWINFO_GET);
	}
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_SERVINGCELL_GET))
	{
		Network_Info_Log("utraRssi=%d", pUmtsServingCellInfo->sCellMeas.utraRssi);
		quec_qeng_get_currrent_state(state);
        memset(resBuf, 0, sizeof(resBuf));
		p = resBuf;
		p+=sprintf(p, "+QENG: \"%s\",\"%s\",\"%s\",%3X","servingcell",state,"WCDMA",pUmtsServingCellInfo->sCellParam.mcc);
		
		if(pUmtsServingCellInfo->sCellParam.lenOfMnc==3)
		{
			p+=sprintf(p, ",%03X",pUmtsServingCellInfo->sCellParam.mnc);
		}
		else
		{
			p+=sprintf(p, ",%02X",pUmtsServingCellInfo->sCellParam.mnc);
		}
#ifdef __QUEC_OEM_VER_LD__
		if (TRUE == Quectel_IsOEMLandiEnable())
		{
			GET_VALID_VAL(cid_buf, pUmtsServingCellInfo->sCellParam.ci);
			GET_VALID_VAL(pci_buf, pUmtsServingCellInfo->sCellParam.psc_cellParameterId);
			GET_VALID_VAL(earfcn_buf, pUmtsServingCellInfo->sCellParam.arfcn);
			GET_VALID_VAL(lac_buf, pUmtsServingCellInfo->sCellParam.lac);
			p+=sprintf(p, ",%s,%s,%s,%s,%d,%d,%d", 
							lac_buf,
							cid_buf,
							earfcn_buf,
							pci_buf,
							pUmtsServingCellInfo->sCellParam.rac,
							pUmtsServingCellInfo->sCellMeas.rscp,
							pUmtsServingCellInfo->sCellMeas.cpichEcN0);
		}
		else
#endif
		{
			p+=sprintf(p, ",%X,%X,%d,%d,%d,%d,%d", 
						pUmtsServingCellInfo->sCellParam.lac,
						pUmtsServingCellInfo->sCellParam.ci,
						pUmtsServingCellInfo->sCellParam.arfcn,
						pUmtsServingCellInfo->sCellParam.psc_cellParameterId,
						pUmtsServingCellInfo->sCellParam.rac,
						pUmtsServingCellInfo->sCellMeas.rscp,
						pUmtsServingCellInfo->sCellMeas.cpichEcN0);
		}
	#if defined (__QUEC_OEM_VER_PAX__) || defined (QUEC_NETWORK_GET_ECNO)  //Chaim 20190928 only for wcdma
			extern quec_network_mode_type quec_get_current_rat(uint8 need_attach);
			g_3g_ecno = pUmtsServingCellInfo->sCellMeas.cpichEcN0;	
			Network_Info_Log("servingcell,rat=%d,rscp=%d,ecno=%d",quec_get_current_rat(1),pUmtsServingCellInfo->sCellMeas.rscp,g_3g_ecno);
	#endif

#if 0
		if(quec_audio_get_call_status())
#else
		if(quec_led_get_call_status())
#endif
		{
			p+=sprintf(p, ",-,-,-,-,-"); 
		}
		else 
		{
			p+=sprintf(p, ",-,-,-,-,-"); 
			//when we support voice call add code here
		}

		p+=sprintf(p, "\r\n");
        if (1 != quec_assemble_qeng_resp(resBuf, p))
        {
            return;
        }
	}
#ifndef ENABLE_DM_LTEONLY 
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_3GCOMM_GET))//仅用于3G
	{
		quec_qeng_get_currrent_state(state);
        memset(resBuf, 0, sizeof(resBuf));
		p = resBuf;
		p+=sprintf(p, "+QENG: \"%s\",\"%s\",\"%s\",\"%s\",%3X","3gcomm","servingcell","3G",state,pUmtsServingCellInfo->sCellParam.mcc);
		
		if(pUmtsServingCellInfo->sCellParam.lenOfMnc==3)
		{
			p+=sprintf(p, ",%03X",pUmtsServingCellInfo->sCellParam.mnc);
		}
		else
		{
			p+=sprintf(p, ",%02X",pUmtsServingCellInfo->sCellParam.mnc);
		}
		#ifdef __QUEC_OEM_VER_LD__
		if (TRUE == Quectel_IsOEMLandiEnable())
		{
			GET_VALID_VAL(cid_buf, pUmtsServingCellInfo->sCellParam.ci);
			GET_VALID_VAL(pci_buf, pUmtsServingCellInfo->sCellParam.psc_cellParameterId);
			GET_VALID_VAL(earfcn_buf, pUmtsServingCellInfo->sCellParam.arfcn);
			GET_VALID_VAL(lac_buf, pUmtsServingCellInfo->sCellParam.lac);
			p+=sprintf(p, ",%s,%s,%s,%s,%d,%d,%d,-,-", 
							lac_buf,
							cid_buf,
							earfcn_buf,
							pci_buf,
							pUmtsServingCellInfo->sCellMeas.utraRssi-95,
							pUmtsServingCellInfo->sCellMeas.rscp,
							pUmtsServingCellInfo->sCellMeas.cpichEcN0);
		}
		else
		#endif
		{
			p+=sprintf(p, ",%X,%X,%d,%d,%d,%d,%d,-,-", 
							pUmtsServingCellInfo->sCellParam.lac,
							pUmtsServingCellInfo->sCellParam.ci,
							pUmtsServingCellInfo->sCellParam.arfcn,
							pUmtsServingCellInfo->sCellParam.psc_cellParameterId,
							pUmtsServingCellInfo->sCellMeas.utraRssi-95,
							pUmtsServingCellInfo->sCellMeas.rscp,
							pUmtsServingCellInfo->sCellMeas.cpichEcN0);
		}

		p+=sprintf(p, "\r\n");
        if (1 != quec_assemble_qeng_resp(resBuf, p))
        {
            return;
        }
	}
#endif
#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
	else if(CHECK_BIT_SET(network_infor_bitmsk ,MCELL))
	{
		Network_Info_Log("mcc=%d,ci=%d",pUmtsServingCellInfo->sCellParam.mcc,pUmtsServingCellInfo->sCellParam.ci);
        memset(resBuf, 0, sizeof(resBuf));
		p = resBuf;
		p+=sprintf(p, "MCC: %x,MNC: %x,LAC: %5d,Cell ID: %9d,BSIC: -,(P)BCCH ARFCN: %04x,RxLev: %03X",
				   pUmtsServingCellInfo->sCellParam.mcc, pUmtsServingCellInfo->sCellParam.mnc, pUmtsServingCellInfo->sCellParam.lac, 
				   pUmtsServingCellInfo->sCellParam.ci,  pUmtsServingCellInfo->sCellParam.arfcn, pUmtsServingCellInfo->sCellMeas.sRxLev);
		
		if(pUmtsServingCellInfo->sCellMeas.sRxLev <=63	)
		{
			p+=sprintf(p, ",RxDbm: %d\r\n", pUmtsServingCellInfo->sCellMeas.sRxLev-111);
		}
		else
		{
			p+=sprintf(p, ",RxDbm: %d\r\n",63-111);
		}
        if (1 != quec_assemble_qeng_resp(resBuf, p))
        {
            return;
        }
	}
#endif
	#ifdef QUEC_ENGINEER_OUTPUT
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_ALL_INFO))
	{
		uint8 i=0;
		uint8 *ptemp= (uint8 *)quec_QengineerResBuf;
		Network_Info_Log("ASR_ENG_MODE Start,scellinfo:rscp=%d,utraRssi=%d,cpichEcN0=%d,sQual=%d,sRxLev=%d,txPower=%d,rxPower=%d",
			pUmtsServingCellInfo->sCellMeas.rscp,
			pUmtsServingCellInfo->sCellMeas.utraRssi,
			pUmtsServingCellInfo->sCellMeas.cpichEcN0,
			pUmtsServingCellInfo->sCellMeas.sQual,
			pUmtsServingCellInfo->sCellMeas.sRxLev,
			pUmtsServingCellInfo->sCellMeas.txPower,
			pUmtsServingCellInfo->sCellMeas.RxPower);
		
       ptemp+=sprintf((char *)ptemp,"+QENGINFO: UMTS,%d,%d,%d,%d,%d,%d,%d",
			   pUmtsServingCellInfo->sCellMeas.rscp,
				pUmtsServingCellInfo->sCellMeas.utraRssi,
				pUmtsServingCellInfo->sCellMeas.cpichEcN0,
				pUmtsServingCellInfo->sCellMeas.sQual,
				pUmtsServingCellInfo->sCellMeas.sRxLev,
				pUmtsServingCellInfo->sCellMeas.txPower,
				pUmtsServingCellInfo->sCellMeas.RxPower);

		Network_Info_Log("ASR_ENG_MODE,scellinfo:rac=%d,nom=%d,mcc=%d,mnc=%d,lac=%d,ci=%d,uraid=%d,psc_cellParameterId=%d,arfcn=%d",
				pUmtsServingCellInfo->sCellParam.rac,
				pUmtsServingCellInfo->sCellParam.nom,
				pUmtsServingCellInfo->sCellParam.mcc,
				pUmtsServingCellInfo->sCellParam.mnc,
				pUmtsServingCellInfo->sCellParam.lac,
				pUmtsServingCellInfo->sCellParam.ci,
				pUmtsServingCellInfo->sCellParam.uraId,
				pUmtsServingCellInfo->sCellParam.psc_cellParameterId,
				pUmtsServingCellInfo->sCellParam.arfcn);

		ptemp+=sprintf((char *)ptemp,"+QENGINFO: %d,%d,%d,%d,%d,%d,%d,%d,%d",
			    pUmtsServingCellInfo->sCellParam.rac,
				pUmtsServingCellInfo->sCellParam.nom,
				pUmtsServingCellInfo->sCellParam.mcc,
				pUmtsServingCellInfo->sCellParam.mnc,
				pUmtsServingCellInfo->sCellParam.lac,
				pUmtsServingCellInfo->sCellParam.ci,
				pUmtsServingCellInfo->sCellParam.uraId,
				pUmtsServingCellInfo->sCellParam.psc_cellParameterId,
				pUmtsServingCellInfo->sCellParam.arfcn);

		
		Network_Info_Log("ASR_ENG_MODE,scellinfo:t3212=%d,mt3312nc=%d,hcs=%d,attdetallow=%d,csdrx=%d,psdrc=%d",
				pUmtsServingCellInfo->sCellParam.t3212,
				pUmtsServingCellInfo->sCellParam.t3312,
				pUmtsServingCellInfo->sCellParam.hcsUsed,
				pUmtsServingCellInfo->sCellParam.attDetAllowed,
				pUmtsServingCellInfo->sCellParam.csDrxCycleLen,
				pUmtsServingCellInfo->sCellParam.psDrxCycleLen);

		ptemp+=sprintf((char *)ptemp,",%d,%d,%d,%d,%d,%d",
				pUmtsServingCellInfo->sCellParam.t3212,
				pUmtsServingCellInfo->sCellParam.t3312,
				pUmtsServingCellInfo->sCellParam.hcsUsed,
				pUmtsServingCellInfo->sCellParam.attDetAllowed,
				pUmtsServingCellInfo->sCellParam.csDrxCycleLen,
				pUmtsServingCellInfo->sCellParam.psDrxCycleLen);


		Network_Info_Log("ASR_ENG_MODE,scellinfo,utranDrxCycleLen=%d,HSDPASupport=%d,HSUPASupport=%d,lenOfMnc=%d,band=%d",
			pUmtsServingCellInfo->sCellParam.utranDrxCycleLen,
				pUmtsServingCellInfo->sCellParam.HSDPASupport,
				pUmtsServingCellInfo->sCellParam.HSUPASupport,
				pUmtsServingCellInfo->sCellParam.lenOfMnc,
				pUmtsServingCellInfo->sCellParam.band);
/*		
	    ptemp+=sprintf((char *)ptemp,",%d,%d,%d,%d,%d",
			pUmtsServingCellInfo->sCellParam.utranDrxCycleLen,
				pUmtsServingCellInfo->sCellParam.HSDPASupport,
				pUmtsServingCellInfo->sCellParam.HSUPASupport,
				pUmtsServingCellInfo->sCellParam.lenOfMnc,
				pUmtsServingCellInfo->sCellParam.band);

		
		Network_Info_Log("ASR_ENG_MODE,scellinfo,rrcState=%d,numLinks=%d,srncId=%d,sRnti=%d,csCipherInfo=%d,psCipherInfo=%d",
			pUmtsServingCellInfo->ueOpStatus.rrcState,
			pUmtsServingCellInfo->ueOpStatus.numLinks,
			pUmtsServingCellInfo->ueOpStatus.srncId,
			pUmtsServingCellInfo->ueOpStatus.sRnti,
			pUmtsServingCellInfo->ueOpStatus.csCipherInfo,
			pUmtsServingCellInfo->ueOpStatus.psCipherInfo);

		 ptemp+=sprintf((char *)ptemp,",%d,%d,%d,%d,%d,%d",
			pUmtsServingCellInfo->ueOpStatus.rrcState,
			pUmtsServingCellInfo->ueOpStatus.numLinks,
			pUmtsServingCellInfo->ueOpStatus.srncId,
			pUmtsServingCellInfo->ueOpStatus.sRnti,
			pUmtsServingCellInfo->ueOpStatus.csCipherInfo,
			pUmtsServingCellInfo->ueOpStatus.psCipherInfo);
*/		
		//Network_Info_Log("ASR_ENG_MODE,scell_meas_6,quec_QengineerResLen=%d,strlen=%d,quec_QengineerResBuf=%s",quec_QengineerResLen,strlen(quec_QengineerResBuf),quec_QengineerResBuf);

		Network_Info_Log("ASR_ENG_MODE,scellinfo,HSDPAActive=%d,numLinks=%d,HSUPAActive=%d,MccLastRegisteredNetwork=%d,MncLastRegisteredNetwork=%d",
			pUmtsServingCellInfo->ueOpStatus.HSDPAActive,
			pUmtsServingCellInfo->ueOpStatus.numLinks,
			pUmtsServingCellInfo->ueOpStatus.HSUPAActive,
			pUmtsServingCellInfo->ueOpStatus.MccLastRegisteredNetwork,
			pUmtsServingCellInfo->ueOpStatus.MncLastRegisteredNetwork);
		
		ptemp+=sprintf((char *)ptemp,",%d,%d,%d,%d,%d",
			pUmtsServingCellInfo->ueOpStatus.HSDPAActive,
			pUmtsServingCellInfo->ueOpStatus.numLinks,
			pUmtsServingCellInfo->ueOpStatus.HSUPAActive,
			pUmtsServingCellInfo->ueOpStatus.MccLastRegisteredNetwork,
			pUmtsServingCellInfo->ueOpStatus.MncLastRegisteredNetwork);

		Network_Info_Log("ASR_ENG_MODE,scellinfo,tmsi=%d,ptmsi=%d,hoCount=%d,IsSingleMmRejectCause=%d,IsSingleGmmRejectCause=%d,MMRejectCause=%d,GMMRejectCause=%d",		
			pUmtsServingCellInfo->ueOpStatus.TMSI,
			pUmtsServingCellInfo->ueOpStatus.PTMSI,
			pUmtsServingCellInfo->ueOpStatus.IsSingleMmRejectCause,
			pUmtsServingCellInfo->ueOpStatus.IsSingleGmmRejectCause,
			pUmtsServingCellInfo->ueOpStatus.MMRejectCause,
			pUmtsServingCellInfo->ueOpStatus.GMMRejectCause);
		
		ptemp+=sprintf((char *)ptemp,",%d,%d,%d,%d,%d,%d",
			pUmtsServingCellInfo->ueOpStatus.TMSI,
			pUmtsServingCellInfo->ueOpStatus.PTMSI,
			pUmtsServingCellInfo->ueOpStatus.IsSingleMmRejectCause,
			pUmtsServingCellInfo->ueOpStatus.IsSingleGmmRejectCause,
			pUmtsServingCellInfo->ueOpStatus.MMRejectCause,
			pUmtsServingCellInfo->ueOpStatus.GMMRejectCause);
	
		Network_Info_Log("ASR_ENG_MODE,scellinfo,mmState=%d,gmmState=%d,gprsReadyState=%d,readyTimerValueInSecs=%d,NumActivePDPContext=%d",	
			pUmtsServingCellInfo->ueOpStatus.mmState,
			pUmtsServingCellInfo->ueOpStatus.gmmState,
			pUmtsServingCellInfo->ueOpStatus.gprsReadyState,
			pUmtsServingCellInfo->ueOpStatus.readyTimerValueInSecs,
			pUmtsServingCellInfo->ueOpStatus.NumActivePDPContext);

		ptemp+=sprintf((char *)ptemp,",%d,%d,%d,%d,%d",
			pUmtsServingCellInfo->ueOpStatus.mmState,
			pUmtsServingCellInfo->ueOpStatus.gmmState,
			pUmtsServingCellInfo->ueOpStatus.gprsReadyState,
			pUmtsServingCellInfo->ueOpStatus.readyTimerValueInSecs,
			pUmtsServingCellInfo->ueOpStatus.NumActivePDPContext);
	
		Network_Info_Log("ASR_ENG_MODE,scellinfo,ULThroughput=%d,DLThroughput=%d,serviceStatus=%d,pmmState=%d,LAU_status=%d",	
			pUmtsServingCellInfo->ueOpStatus.ULThroughput,
			pUmtsServingCellInfo->ueOpStatus.DLThroughput,
			pUmtsServingCellInfo->ueOpStatus.serviceStatus,
			pUmtsServingCellInfo->ueOpStatus.pmmState,
			pUmtsServingCellInfo->ueOpStatus.LAU_status);
		
		ptemp+=sprintf((char *)ptemp,",%d,%d,%d,%d,%d",
			pUmtsServingCellInfo->ueOpStatus.ULThroughput,
			pUmtsServingCellInfo->ueOpStatus.DLThroughput,
			pUmtsServingCellInfo->ueOpStatus.serviceStatus,
			pUmtsServingCellInfo->ueOpStatus.pmmState,
			pUmtsServingCellInfo->ueOpStatus.LAU_status);
				

		Network_Info_Log("ASR_ENG_MODE,scellinfo,LAU_count=%d,RAU_status=%d,RAU_count=%d,phyChType=%d,sf=%d,slotFormat=%d",
			pUmtsServingCellInfo->ueOpStatus.LAU_count,
			pUmtsServingCellInfo->ueOpStatus.RAU_status,
			pUmtsServingCellInfo->ueOpStatus.RAU_count,
			pUmtsServingCellInfo->ueOpStatus.phyChType,
			pUmtsServingCellInfo->ueOpStatus.sf,
			pUmtsServingCellInfo->ueOpStatus.slotFormat);
       ptemp+=sprintf((char *)ptemp,",%d,%d,%d,%d,%d,%d",
			pUmtsServingCellInfo->ueOpStatus.LAU_count,
			pUmtsServingCellInfo->ueOpStatus.RAU_status,
			pUmtsServingCellInfo->ueOpStatus.RAU_count,
			pUmtsServingCellInfo->ueOpStatus.phyChType,
			pUmtsServingCellInfo->ueOpStatus.sf,
			pUmtsServingCellInfo->ueOpStatus.slotFormat);

		Network_Info_Log("ASR_ENG_MODE,scellinfo,compressMode=%d,codecType=%d,speechCodecRate=%d,rssi=%d,isSinrPresent=%d,sinr=%d",
			pUmtsServingCellInfo->ueOpStatus.compressMode,
			pUmtsServingCellInfo->ueOpStatus.codecType,
			pUmtsServingCellInfo->ueOpStatus.speechCodecRate,
			pUmtsServingCellInfo->ueOpStatus.rssi,
			pUmtsServingCellInfo->ueOpStatus.isSinrPresent,
			pUmtsServingCellInfo->ueOpStatus.sinr);
       ptemp+=sprintf((char *)ptemp,",%d,%d,%d,%d,%d,%d",
			pUmtsServingCellInfo->ueOpStatus.compressMode,
			pUmtsServingCellInfo->ueOpStatus.codecType,
			pUmtsServingCellInfo->ueOpStatus.speechCodecRate,
			pUmtsServingCellInfo->ueOpStatus.rssi,
			pUmtsServingCellInfo->ueOpStatus.isSinrPresent,
			pUmtsServingCellInfo->ueOpStatus.sinr);
		   Network_Info_Log("ASR_ENG_MODE,END,scell_meas_6,ptemp=%p,quec_QengineerResLen=%p,%d",ptemp,quec_QengineerResBuf,ptemp-(uint8 *)quec_QengineerResBuf);
	}
	#endif
#ifdef QUECTEL_CELL
    else if(CHECK_BIT_SET(network_infor_bitmsk ,CELL_GET))
	{
		Network_Info_Log("[quec ncell] mcc=%d,ci=%d",pUmtsServingCellInfo->sCellParam.mcc,pUmtsServingCellInfo->sCellParam.ci);

        memset(resBuf, 0, sizeof(resBuf));
	    p = resBuf;
        //serving cell info
        p+=sprintf(p, "+QCELL: \"%s\",\"%s\",%3X","servingcell","WCDMA",pUmtsServingCellInfo->sCellParam.mcc); 
       
        if(pUmtsServingCellInfo->sCellParam.lenOfMnc==3)
		{
			p+=sprintf(p, ",%03X",pUmtsServingCellInfo->sCellParam.mnc);
		}
		else
		{
			p+=sprintf(p, ",%02X",pUmtsServingCellInfo->sCellParam.mnc);
		}
        /*check rssi range: 0-63*/
        if (pUmtsServingCellInfo->sCellMeas.utraRssi < QUEC_CELL_RSSI_MIN)
        {
             pUmtsServingCellInfo->sCellMeas.utraRssi = QUEC_CELL_RSSI_MIN;
        }
        else if (pUmtsServingCellInfo->sCellMeas.utraRssi > QUEC_CELL_RSSI_MAX)
        {
             pUmtsServingCellInfo->sCellMeas.utraRssi = QUEC_CELL_RSSI_MAX;
        }
        p+=sprintf(p, ",%04X,%x,%d,%d\r\n",pUmtsServingCellInfo->sCellParam.lac,
                        pUmtsServingCellInfo->sCellParam.ci,
                        pUmtsServingCellInfo->sCellParam.psc_cellParameterId,
                        pUmtsServingCellInfo->sCellMeas.utraRssi); //sRxLev
        
        if (1 != quec_assemble_qeng_resp(resBuf, p))
		{
			return;
        }
	}
#endif
#ifdef QUEC_QCELLINFO_SUPPORT
        else if(CHECK_BIT_SET(network_infor_bitmsk ,QCELLINFOEX_GET))
        {
            Network_Info_Log("[quec qcellinfo] mcc=%d,ci=%d",pUmtsServingCellInfo->sCellParam.mcc,pUmtsServingCellInfo->sCellParam.ci);
    
            memset(resBuf, 0, sizeof(resBuf));
            p = resBuf;
            //serving cell info
            p+=sprintf(p, "+QCELLINFO: \"%s\",\"%s\",%3X","servingcell","WCDMA",pUmtsServingCellInfo->sCellParam.mcc); 
           
            if(pUmtsServingCellInfo->sCellParam.lenOfMnc==3)
            {
                p+=sprintf(p, ",%03X",pUmtsServingCellInfo->sCellParam.mnc);
            }
            else
            {
                p+=sprintf(p, ",%02X",pUmtsServingCellInfo->sCellParam.mnc);
            }
            p+=sprintf(p, ",%04X,%x,%d,%d,%d,%d\r\n",pUmtsServingCellInfo->sCellParam.lac,
                            pUmtsServingCellInfo->sCellParam.ci,
                            pUmtsServingCellInfo->sCellParam.psc_cellParameterId,
                            pUmtsServingCellInfo->sCellMeas.sRxLev,
                            pUmtsServingCellInfo->sCellMeas.sRxLev-111,
                            pUmtsServingCellInfo->sCellParam.arfcn);
            
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
        }
#endif

	else
	{
#endif

	(*p_UMTS_EM_IND_SEQ)++;

	DBGMSG("Output EM info after receiving UMTS CI_DEV_PRIM_UMTS_ENGMODE_SVCCELL_INFO_IND once \r\n");
	*p_UMTS_EM_IND_SEQ = 0;
#ifdef AT_FOR_GW20180208SN
	current_accessTechnology = 1;
	current_bandInd = pUmtsServingCellInfo->sCellParam.band;
	m_channel = pUmtsServingCellInfo->sCellParam.arfcn; 
		
	if((pUmtsServingCellInfo->sCellParam.mcc != 0xFFFF) && (pUmtsServingCellInfo->sCellParam.mnc != 0xFFFF))
	{
		sprintf( (char *)curr_operIdLongStr, "%03x+%02x", pUmtsServingCellInfo->sCellParam.mcc,pUmtsServingCellInfo->sCellParam.mnc);
	}
	else if(pUmtsServingCellInfo->sCellParam.ci == 0xFFFFFFFF)
	{
		sprintf( (char *)curr_operIdLongStr, "");
	}
	if(pUmtsServingCellInfo->sCellParam.lac != 0xFFFE)
	{
		m_lac_tac = pUmtsServingCellInfo->sCellParam.lac;
	}
	else if(pUmtsServingCellInfo->sCellParam.ci == 0xFFFFFFFF)
	{
		m_lac_tac = 0;
	}
				
	m_cell_id = pUmtsServingCellInfo->sCellParam.ci;
	m_bsic_phycellid = pUmtsServingCellInfo->sCellParam.psc_cellParameterId;
	if(pUmtsServingCellInfo->sCellMeas.utraRssi != -32768)
	{
		m_rxdbm = pUmtsServingCellInfo->sCellMeas.utraRssi-100;
	}
	else
	{
		m_rxdbm = 199;
	}
			
	if(pUmtsServingCellInfo->sCellMeas.txPower != -32768)
	{
		m_txdbm = pUmtsServingCellInfo->sCellMeas.txPower;
	}
	else
	{
		m_txdbm = 199;
	}
			
	m_rsrp = 0;
	m_rsrq = 0;
	m_sinr = 0;
	if(gMMZRSSI == 3)
	{
		return;
	}
#endif	
	// +EEMUMTSSVC
	sprintf(resBuf, "+EEMUMTSSVC:");

	// -4- Mode, sCMeasPresent, sCParamPresent, ueOpStatusPresent
	sprintf(tempBuf, "%d, %d, %d, %d,", pUmtsEngmodeScellInfoInd->mode,
	                                    pUmtsServingCellInfo->sCellMeasPresent,
	                                    pUmtsServingCellInfo->sCellParamPresent,
	                                    pUmtsServingCellInfo->ueOpStatusPresent);
	strcat(resBuf, tempBuf);

	if (pUmtsServingCellInfo->sCellMeasPresent)
	{
#ifndef TD_SUPPORT
		// -6- cpichRSCP, utraRssi, cpichEcN0, sQual, sRxLev, txPower
			sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, ", pUmtsServingCellInfo->sCellMeas.rscp,
		                                             pUmtsServingCellInfo->sCellMeas.utraRssi,
		                                             pUmtsServingCellInfo->sCellMeas.cpichEcN0,
		                                             pUmtsServingCellInfo->sCellMeas.sQual,
		                                             pUmtsServingCellInfo->sCellMeas.sRxLev,
		                                             pUmtsServingCellInfo->sCellMeas.txPower);
#else
		// -4- pccpchRSCP, utraRssi, sRxLev, txPower
			sprintf(tempBuf, "%d, %d, %d, %d, ", pUmtsServingCellInfo->sCellMeas.rscp,
		                                     pUmtsServingCellInfo->sCellMeas.utraRssi,
		                                     pUmtsServingCellInfo->sCellMeas.sRxLev,
		                                     pUmtsServingCellInfo->sCellMeas.txPower);

#endif
		strcat(resBuf, tempBuf);
	}
	if (pUmtsServingCellInfo->sCellParamPresent)
	{
	
		gcell_lac = pUmtsServingCellInfo->sCellParam.lac;
		gcell_ci  = pUmtsServingCellInfo->sCellParam.ci;
		gcell_mcc = pUmtsServingCellInfo->sCellParam.mcc;
		gcell_mnc = pUmtsServingCellInfo->sCellParam.mnc;
		
		#ifdef PLATFORM_FOR_PS_LW
		
		// -6- rac, nom, mcc, mnc, lac, ci
		sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, %d,", pUmtsServingCellInfo->sCellParam.rac,
		                                             pUmtsServingCellInfo->sCellParam.nom,
		                                             pUmtsServingCellInfo->sCellParam.mcc,
		                                             pUmtsServingCellInfo->sCellParam.lenOfMnc,
		                                             pUmtsServingCellInfo->sCellParam.mnc,
		                                             pUmtsServingCellInfo->sCellParam.lac,
		                                             pUmtsServingCellInfo->sCellParam.ci);
		#else
		// -6- rac, nom, mcc, mnc, lac, ci
		sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, ", pUmtsServingCellInfo->sCellParam.rac,
		                                             pUmtsServingCellInfo->sCellParam.nom,
		                                             pUmtsServingCellInfo->sCellParam.mcc,
		                                             pUmtsServingCellInfo->sCellParam.mnc,
		                                             pUmtsServingCellInfo->sCellParam.lac,
		                                             pUmtsServingCellInfo->sCellParam.ci);

		#endif
		strcat(resBuf, tempBuf);
#ifndef TD_SUPPORT

		// -7- uraId, psc, arfcn, t3212, t3312, hcsUsed, attDetAllowed
		sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, %d, ", pUmtsServingCellInfo->sCellParam.uraId,
			                                             pUmtsServingCellInfo->sCellParam.psc_cellParameterId,
		                                             pUmtsServingCellInfo->sCellParam.arfcn,
		                                             pUmtsServingCellInfo->sCellParam.t3212,
		                                             pUmtsServingCellInfo->sCellParam.t3312,
		                                             pUmtsServingCellInfo->sCellParam.hcsUsed,
		                                             pUmtsServingCellInfo->sCellParam.attDetAllowed);
#else
		// -7- uraId, cellParameterId, arfcn, t3212, t3312, hcsUsed, attDetAllowed
		sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, %d, ", pUmtsServingCellInfo->sCellParam.uraId,
			                                             pUmtsServingCellInfo->sCellParam.psc_cellParameterId,
		                                             pUmtsServingCellInfo->sCellParam.arfcn,
		                                             pUmtsServingCellInfo->sCellParam.t3212,
		                                             pUmtsServingCellInfo->sCellParam.t3312,
		                                             pUmtsServingCellInfo->sCellParam.hcsUsed,
		                                             pUmtsServingCellInfo->sCellParam.attDetAllowed);
#endif	  

		strcat(resBuf, tempBuf);


		// -5- csDrxCycleLen, psDrxCycleLen, utranDrxCycleLen, HSDPASupport, HSUPASupport
		sprintf(tempBuf, "%d, %d, %d, %d, %d, ", pUmtsServingCellInfo->sCellParam.csDrxCycleLen,
		                                             pUmtsServingCellInfo->sCellParam.psDrxCycleLen,
		                                             pUmtsServingCellInfo->sCellParam.utranDrxCycleLen,
		                                             pUmtsServingCellInfo->sCellParam.HSDPASupport,
		                                             pUmtsServingCellInfo->sCellParam.HSUPASupport);
		strcat(resBuf, tempBuf);
	}
	if (pUmtsServingCellInfo->ueOpStatusPresent)
	{
		// -4- rrcState, numLinks, srncId, sRnti
		sprintf(tempBuf, "%d, %d, %d, %d, ", pUmtsServingCellInfo->ueOpStatus.rrcState,
		                                             pUmtsServingCellInfo->ueOpStatus.numLinks,
		                                             pUmtsServingCellInfo->ueOpStatus.srncId,
		                                             pUmtsServingCellInfo->ueOpStatus.sRnti);
		strcat(resBuf, tempBuf);

		// -6- algPresent, cipherAlg, cipherOn, algPresent, cipherAlg, cipherOn
		sprintf(tempBuf, "%d, %d, %d, %d, %d, %d,", pUmtsServingCellInfo->ueOpStatus.csCipherInfo.algPresent,
		                                             pUmtsServingCellInfo->ueOpStatus.csCipherInfo.cipherAlg,
		                                             pUmtsServingCellInfo->ueOpStatus.csCipherInfo.cipherOn,
		                                             pUmtsServingCellInfo->ueOpStatus.psCipherInfo.algPresent,
		                                             pUmtsServingCellInfo->ueOpStatus.psCipherInfo.cipherAlg,
		                                             pUmtsServingCellInfo->ueOpStatus.psCipherInfo.cipherOn);
		strcat(resBuf, tempBuf);

		// -8- HSDPAActive, HSUPAActive, MccLastRegisteredNetwork, MncLastRegisteredNetwork
		//     TMSI, PTMSI, IsSingleMmRejectCause, IsSingleGmmRejectCause
		sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, %d, %d,", pUmtsServingCellInfo->ueOpStatus.HSDPAActive,
		                                             pUmtsServingCellInfo->ueOpStatus.HSUPAActive,
		                                             pUmtsServingCellInfo->ueOpStatus.MccLastRegisteredNetwork,
		                                             pUmtsServingCellInfo->ueOpStatus.MncLastRegisteredNetwork,
		                                             pUmtsServingCellInfo->ueOpStatus.TMSI,
		                                             pUmtsServingCellInfo->ueOpStatus.PTMSI,
		                                             pUmtsServingCellInfo->ueOpStatus.IsSingleMmRejectCause,
		                                             pUmtsServingCellInfo->ueOpStatus.IsSingleGmmRejectCause);
		strcat(resBuf, tempBuf);
		#ifdef PLATFORM_FOR_PS_LW
		// -11- MMRejectCause, GMMRejectCause, mmState, gmmState, gprsReadyState
		//     readyTimerValueInSecs, NumActivePDPContext, ULThroughput, DLThroughput,serviceStatus,pmmState
		/*Fix klocwork[Buffer Overflow]*/
		snprintf(tempBuf, sizeof(tempBuf), "%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", pUmtsServingCellInfo->ueOpStatus.MMRejectCause,
		                                             pUmtsServingCellInfo->ueOpStatus.GMMRejectCause,
		                                             pUmtsServingCellInfo->ueOpStatus.mmState,
		                                             pUmtsServingCellInfo->ueOpStatus.gmmState,
		                                             pUmtsServingCellInfo->ueOpStatus.gprsReadyState,
		                                             pUmtsServingCellInfo->ueOpStatus.readyTimerValueInSecs,
		                                             pUmtsServingCellInfo->ueOpStatus.NumActivePDPContext,
		                                             pUmtsServingCellInfo->ueOpStatus.ULThroughput,
		                                             pUmtsServingCellInfo->ueOpStatus.DLThroughput,
		                                             pUmtsServingCellInfo->ueOpStatus.serviceStatus,
		                                             pUmtsServingCellInfo->ueOpStatus.pmmState,
													pUmtsServingCellInfo->ueOpStatus.LAU_status,
													pUmtsServingCellInfo->ueOpStatus.LAU_count,
													pUmtsServingCellInfo->ueOpStatus.RAU_status,
													pUmtsServingCellInfo->ueOpStatus.RAU_count
		);

		#else
		// -11- MMRejectCause, GMMRejectCause, mmState, gmmState, gprsReadyState
		//     readyTimerValueInSecs, NumActivePDPContext, ULThroughput, DLThroughput,serviceStatus,pmmState
		/*Fix klocwork[Buffer Overflow]*/
		snprintf(tempBuf, sizeof(tempBuf), "%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", pUmtsServingCellInfo->ueOpStatus.MMRejectCause,
		                                             pUmtsServingCellInfo->ueOpStatus.GMMRejectCause,
		                                             pUmtsServingCellInfo->ueOpStatus.mmState,
		                                             pUmtsServingCellInfo->ueOpStatus.gmmState,
		                                             pUmtsServingCellInfo->ueOpStatus.gprsReadyState,
		                                             pUmtsServingCellInfo->ueOpStatus.readyTimerValueInSecs,
		                                             pUmtsServingCellInfo->ueOpStatus.NumActivePDPContext,
		                                             pUmtsServingCellInfo->ueOpStatus.ULThroughput,
		                                             pUmtsServingCellInfo->ueOpStatus.DLThroughput,
		                                             pUmtsServingCellInfo->ueOpStatus.serviceStatus,
		                                             pUmtsServingCellInfo->ueOpStatus.pmmState
		);
		#endif
		strcat(resBuf, tempBuf);
	}

	strcat(resBuf, "\r\n");

	ATRESP(reqHandle, 0, 0, resBuf);
#ifdef QUECTEL_NETWORK_SUPPORT
	 }
#endif

	return;
}

/****************************************************************
 *  F@: processEMUmtsIntraFreqInfoInd - Process UMTS engine mode info
 */
static void processEMUmtsIntraFreqInfoInd(UINT32 reqHandle, const void *pParam)
{
	CiDevPrimUmtsEngmodeIntraFreqInfoInd * pUmtsEngmodeIntraFreqInfoInd=NULL;
	UINT8 index=0;
	char resBuf[200];
	char tempBuf[50];
	UINT8 *p_UMTS_EM_IND_SEQ;
	
	if (reqHandle == IND_REQ_HANDLE) {
		p_UMTS_EM_IND_SEQ = &g_UMTS_EM_IND_SEQ;
	} else {
		p_UMTS_EM_IND_SEQ = &g_UMTS_EM_IND_SEQ_1;
	}
	
	memset(resBuf, 0, sizeof(resBuf));
	memset(tempBuf, 0, sizeof(tempBuf));
	
	pUmtsEngmodeIntraFreqInfoInd = (CiDevPrimUmtsEngmodeIntraFreqInfoInd *)pParam;

	/* Neighboring Cell information */
	if (pUmtsEngmodeIntraFreqInfoInd->numIntraFreq > MAX_UMTS_NEIGHBORING_CELLS)
	{
		ERRMSG("pUmtsEngmodeIntraFreqInfoInd->numIntraFreq %d larger than MAX_UMTS_NEIGHBORING_CELLS \r\n", pUmtsEngmodeIntraFreqInfoInd->numIntraFreq   );
		return;
	}

	(*p_UMTS_EM_IND_SEQ)++;
	//if ( g_UMTS_EM_IND_SEQ == UMTS_EM_IND_NUM_MAX)
#ifdef QUECTEL_NETWORK_SUPPORT
	char *p;
	UINT8 cellNUM=0;
#ifdef __QUEC_OEM_VER_LD__
	char					   pci_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   arfcn_buf[LANDI_VAL_BUF_MAX] = {0};
#endif 

	if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_NEIGHBOURCELL_GET))
	{
		//intra neighber cell of UMTS
		Network_Info_Log("numIntraFreq=%d", pUmtsEngmodeIntraFreqInfoInd->numIntraFreq);
		for (cellNUM = 0; cellNUM < pUmtsEngmodeIntraFreqInfoInd->numIntraFreq; cellNUM++)
		{
			//not supoort rank so rplace with -
			if(pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].arfcn ==0)
				continue;
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
	#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(pci_buf,0,sizeof(pci_buf));
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				GET_VALID_VAL(pci_buf, pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].psc_cellParameterId);
				GET_VALID_VAL(arfcn_buf, pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].arfcn);
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%s,%d,%s,%d,%d,%d,-,%d\r\n","neighbourcell","WCDMA",
					pci_buf,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].sQual,
					arfcn_buf,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rscp,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].cpichEcN0,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].set,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].sRxLev);
			}
			else
	#endif
			{
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%d,%d,%d,%d,%d,%d,-,%d\r\n","neighbourcell","WCDMA",
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].arfcn,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].sQual,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].psc_cellParameterId,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rscp,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].cpichEcN0,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].set,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].sRxLev);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
	}
#ifndef ENABLE_DM_LTEONLY 
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_3GCOMM_GET))
	{
		//intra neighber cell of UMTS
		Network_Info_Log("numIntraFreq=%d", pUmtsEngmodeIntraFreqInfoInd->numIntraFreq);
		for (cellNUM = 0; cellNUM < pUmtsEngmodeIntraFreqInfoInd->numIntraFreq; cellNUM++)
		{
			//not supoort rank so rplace with -
			if(pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].arfcn ==0)
				continue;
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
	#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(pci_buf,0,sizeof(pci_buf));
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				GET_VALID_VAL(pci_buf, pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].psc_cellParameterId);
				GET_VALID_VAL(arfcn_buf, pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].arfcn);
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",\"%s\",-,-,-,-,%s,%s,%d,%d,%d\r\n", "3gcomm","neighbourcell","3G",
					arfcn_buf,
					pci_buf,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rscp,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rscp,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].cpichEcN0);
			}
			else
	#endif
			{
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",\"%s\",-,-,-,-,%d,%d,%d,%d,%d\r\n", "3gcomm","neighbourcell","3G",
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].arfcn,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].psc_cellParameterId,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rscp,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rscp,
					pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].cpichEcN0);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
	}
#endif
#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
	else if(CHECK_BIT_SET(network_infor_bitmsk ,MCELL))
	{
		Network_Info_Log("numIntraFreq=%d", pUmtsEngmodeIntraFreqInfoInd->numIntraFreq);
		for (cellNUM = 0; cellNUM < pUmtsEngmodeIntraFreqInfoInd->numIntraFreq; cellNUM++)
		{
			//check if cell msg is valid
			if((pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mcc <= 0 || pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mcc >0x999)
				||(pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].ci == 0)
				||(pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].lac == 0))
			{
				continue;
			}
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
				
			p+=sprintf(p,"MCC: %x,MNC: %x,LAC: %5d,Cell ID: %9d,BSIC: -,(P)BCCH ARFCN: %04x,RxLev: %03x",
					  pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mcc, pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mnc,
					  pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].lac, pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].ci,
					  pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].arfcn,
					  pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].sRxLev);
			if(pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].sRxLev <=63  )
			{
				p+=sprintf(p, ",RxDbm: %d\r\n", pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].sRxLev-111);
			}
			else
			{
				p+=sprintf(p, ",RxDbm: %d\r\n",63-111);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
	}
#endif
#ifdef QUECTEL_CELL
    else if(CHECK_BIT_SET(network_infor_bitmsk ,CELL_GET))
    {
		Network_Info_Log("[quec ncell] numIntraFreq=%d", pUmtsEngmodeIntraFreqInfoInd->numIntraFreq);
       
		for (cellNUM = 0; (cellNUM < pUmtsEngmodeIntraFreqInfoInd->numIntraFreq)&&(cellNUM < CI_DEV_MAX_UMTS_NEIGHBORING_CELLS); cellNUM++)
		{
		    /*check ci psc data */
		    if ((pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].ci == NCELL_CELL_ID_MAX) ||
                (pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].ci == NCELL_CELL_ID_MIN) ||
                (pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].psc_cellParameterId == NCELL_PSC_MAX) ||
                  (pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mcc == NCELL_CELL_MCC_INVALID) )
            {
                continue;
            }
		    memset(resBuf, 0, sizeof(resBuf));
			p = resBuf;
            
            /*check rssi range: 0-63*/
            if (pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].utraRssi < QUEC_CELL_RSSI_MIN)
            {
                 pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].utraRssi = QUEC_CELL_RSSI_MIN;
            }
            else if (pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].utraRssi > QUEC_CELL_RSSI_MAX)
            {
                 pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].utraRssi = QUEC_CELL_RSSI_MAX;
            }

		    p+=sprintf(p, "+QCELL: \"%s\",\"%s\",%03x,%02x,%04X,%x,%d,%d\r\n","neighbourcell","WCDMA",
                            pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mcc,
                            pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mnc,
                            pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].lac,
                            pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].ci,
                            pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].psc_cellParameterId,
                            pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].utraRssi); //sRxLev
            
			if (1 != quec_assemble_qeng_resp(resBuf, p))
			{
				return;
			}
		}
	}
#endif
#ifdef QUEC_QCELLINFO_SUPPORT
        else if(CHECK_BIT_SET(network_infor_bitmsk ,QCELLINFOEX_GET))
        {
            Network_Info_Log("[quec qcellinfo] numIntraFreq=%d", pUmtsEngmodeIntraFreqInfoInd->numIntraFreq);
           
            for (cellNUM = 0; (cellNUM < pUmtsEngmodeIntraFreqInfoInd->numIntraFreq)&&(cellNUM < CI_DEV_MAX_UMTS_NEIGHBORING_CELLS); cellNUM++)
            {
                /*check ci psc data */
                if ((pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].ci == NCELL_CELL_ID_MAX) ||
                    (pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].ci == NCELL_CELL_ID_MIN) ||
                    (pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].psc_cellParameterId == NCELL_PSC_MAX))
                {
                    continue;
                }
                memset(resBuf, 0, sizeof(resBuf));
                p = resBuf;
    
                p+=sprintf(p, "+QCELLINFO: \"%s\",\"%s\",%03x,%02x,%04X,%x,%d,%d,%d,%d\r\n","neighbourcell","WCDMA",
                                pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mcc,
                                pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mnc,
                                pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].lac,
                                pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].ci,
                                pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].psc_cellParameterId,
                                pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].sRxLev,
                                pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].sRxLev-111,
                                pUmtsEngmodeIntraFreqInfoInd->intraFreq[cellNUM].arfcn);
                
                if (1 != quec_assemble_qeng_resp(resBuf, p))
                {
                    return;
                }
            }
        }
#endif

	else
#endif
	{
		DBGMSG("Output EM info after receiving UMTS CI_DEV_PRIM_UMTS_ENGMODE_INTRAFREQ_INFO_IND once \r\n");
		*p_UMTS_EM_IND_SEQ = 0;

		// +EEMUMTSINTRA

		for (index = 0; index < pUmtsEngmodeIntraFreqInfoInd->numIntraFreq; index++)
		{
			sprintf(resBuf, "+EEMUMTSINTRA: %d, ", index);

#ifndef TD_SUPPORT
			// -5- cpichRSCP, utraRssi, cpichEcN0, sQual, sRxLev
				sprintf(tempBuf, "%d, %d, %d, %d, %d, ", pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].rscp,
			                                  pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].utraRssi,
			                                  pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].cpichEcN0,
			                                  pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].sQual,
			                                  pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].sRxLev);
			strcat(resBuf, tempBuf);

			// -6- mcc, mnc, lac, ci, arfcn, psc
			sprintf(tempBuf, "%d, %d, %d, %d, %d, %d", pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].mcc,
			                                  pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].mnc,
			                                  pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].lac,
			                                  pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].ci,
			                                  pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].arfcn,
				                                  pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].psc_cellParameterId);
			strcat(resBuf, tempBuf);
#else
			// -3- pccpchRSCP, utraRssi, sRxLev
				sprintf(tempBuf, "%d, %d, %d, ", pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].rscp,
			                                  pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].utraRssi,
			                                  pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].sRxLev);
			strcat(resBuf, tempBuf);
			// -6- mcc, mnc, lac, ci, arfcn, cellParameterId
			sprintf(tempBuf, "%d, %d, %d, %d, %d, %d", pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].mcc,
											  pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].mnc,
											  pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].lac,
											  pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].ci,
											  pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].arfcn,
									pUmtsEngmodeIntraFreqInfoInd->intraFreq[index].psc_cellParameterId);
			strcat(resBuf, tempBuf);
#endif
			strcat(resBuf, "\r\n");

			ATRESP(reqHandle, 0, 0, resBuf);

		}
	}

	return;
}

/****************************************************************
 *  F@: processEMUmtsInterFreqInfoInd - Process UMTS engine mode info
 */
static void processEMUmtsInterFreqInfoInd(UINT32 reqHandle, const void *pParam)
{
	CiDevPrimUmtsEngmodeInterFreqInfoInd * pUmtsEngmodeInterFreqInfoInd=NULL;
	UINT8 index=0;
	char resBuf[200];
	char tempBuf[50];
	UINT8 *p_UMTS_EM_IND_SEQ;
	
	if (reqHandle == IND_REQ_HANDLE) {
		p_UMTS_EM_IND_SEQ = &g_UMTS_EM_IND_SEQ;
	} else {
		p_UMTS_EM_IND_SEQ = &g_UMTS_EM_IND_SEQ_1;
	}
	
	memset(resBuf, 0, sizeof(resBuf));
	memset(tempBuf, 0, sizeof(tempBuf));
	
	pUmtsEngmodeInterFreqInfoInd = (CiDevPrimUmtsEngmodeInterFreqInfoInd *)pParam;

	/* Number of Inter-Frequency FDD Cells */
	if (pUmtsEngmodeInterFreqInfoInd->numInterFreq > MAX_UMTS_NEIGHBORING_CELLS)
	{
		ERRMSG("pUmtsEngmodeInterFreqInfoInd->numInterFreq  %d larger than MAX_UMTS_NEIGHBORING_CELLS \r\n", pUmtsEngmodeInterFreqInfoInd->numInterFreq );
		return;
	}
	(*p_UMTS_EM_IND_SEQ)++;
	//if ( g_UMTS_EM_IND_SEQ == UMTS_EM_IND_NUM_MAX)
#ifdef QUECTEL_NETWORK_SUPPORT
	char *p;
	UINT8 cellNUM=0;
#ifdef __QUEC_OEM_VER_LD__
	char					   pci_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   arfcn_buf[LANDI_VAL_BUF_MAX] = {0};
#endif 

	if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_NEIGHBOURCELL_GET))
	{
		//inter neighber cell of UMTS
		Network_Info_Log("numInterFreq=%d", pUmtsEngmodeInterFreqInfoInd->numInterFreq);
		for (cellNUM = 0; cellNUM < pUmtsEngmodeInterFreqInfoInd->numInterFreq; cellNUM++)
		{
			//not supoort rank so rplace with -
			if(pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].arfcn ==0)
				continue;
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
	#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				memset(pci_buf,0,sizeof(pci_buf));
				GET_VALID_VAL(pci_buf, pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].psc_cellParameterId);
				GET_VALID_VAL(arfcn_buf, pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].arfcn);
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%s,%d,%s,%d,%d,%d,-,%d\r\n","neighbourcell","WCDMA",
					arfcn_buf,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].sQual,
					pci_buf,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].rscp,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].cpichEcN0,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].set,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].sRxLev);
			}
			else
	#endif
			{
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%d,%d,%d,%d,%d,%d,-,%d\r\n","neighbourcell","WCDMA",
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].arfcn,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].sQual,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].psc_cellParameterId,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].rscp,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].cpichEcN0,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].set,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].sRxLev);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
	}
#ifndef ENABLE_DM_LTEONLY 
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_3GCOMM_GET))
	{
		//inter neighber cell of UMTS
		Network_Info_Log("numInterFreq=%d", pUmtsEngmodeInterFreqInfoInd->numInterFreq);
		for (cellNUM = 0; cellNUM < pUmtsEngmodeInterFreqInfoInd->numInterFreq; cellNUM++)
		{
			//not supoort rank so rplace with -
			if(pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].arfcn ==0)
				continue;
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
	#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				memset(pci_buf,0,sizeof(pci_buf));
				GET_VALID_VAL(pci_buf, pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].psc_cellParameterId);
				GET_VALID_VAL(arfcn_buf, pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].arfcn);
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",\"%s\",-,-,-,-,%s,%s,%d,%d,%d,%d,%d\r\n", "3gcomm","neighbourcell","3G",
					arfcn_buf,
					pci_buf,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].rscp,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].rscp,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].cpichEcN0,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].cpichEcN0,
					pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].sRxLev);
			}
			else
	#endif
			p+=sprintf(p, "+QENG: \"%s\",\"%s\",\"%s\",-,-,-,-,%d,%d,%d,%d,%d,%d,%d\r\n", "3gcomm","neighbourcell","3G",
				pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].arfcn,
				pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].psc_cellParameterId,
				pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].rscp,
				pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].rscp,
				pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].cpichEcN0,
				pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].cpichEcN0,
				pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].sRxLev);
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
	}
#endif 
#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
	else if(CHECK_BIT_SET(network_infor_bitmsk ,MCELL))
	{
		Network_Info_Log("numInterFreq=%d", pUmtsEngmodeInterFreqInfoInd->numInterFreq);
		for (cellNUM = 0; cellNUM < pUmtsEngmodeInterFreqInfoInd->numInterFreq; cellNUM++)
		{
			//check if cell msg is valid
			if((pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].mcc <=0 || pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].mcc >0x999)
				||(pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].lac == 0)
				||(pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].ci == 0))
			{
				continue;
			}
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
			p+=sprintf(p,"MCC: %x,MNC: %x,LAC: %5d,Cell ID: %9d,BSIC: -,(P)BCCH ARFCN: %04x,RxLev: %03x",
					  pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].mcc, pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].mnc,
					  pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].lac, pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].ci,
					  pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].arfcn,
					  pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].sRxLev);
			if(pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].sRxLev <=63  )
			{
				p+=sprintf(p, ",RxDbm: %d\r\n", pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].sRxLev-111);
			}
			else
			{
				p+=sprintf(p, ",RxDbm: %d\r\n",63-111);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
	}
#endif
#ifdef QUECTEL_CELL
    else if(CHECK_BIT_SET(network_infor_bitmsk ,CELL_GET))
    {
       Network_Info_Log("[quec ncell] wcdma Inter numInterFreq=%d",pUmtsEngmodeInterFreqInfoInd->numInterFreq);
      
	   for (cellNUM = 0; (cellNUM < pUmtsEngmodeInterFreqInfoInd->numInterFreq)&&(cellNUM < CI_DEV_MAX_UMTS_NEIGHBORING_CELLS); cellNUM++)
	   { 
	       /*check ci psc data */
	       if ( (pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].ci == NCELL_CELL_ID_MAX) ||
                (pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].ci == NCELL_CELL_ID_MIN) ||
                (pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].psc_cellParameterId == NCELL_PSC_MAX) ||
				(pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].mcc == NCELL_CELL_MCC_INVALID) )
           {
               continue;
           }
		   memset(resBuf, 0, sizeof(resBuf));
		   p = resBuf;

           /*check rssi range: 0-63*/
           if (pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].utraRssi < QUEC_CELL_RSSI_MIN)
           {
                pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].utraRssi = QUEC_CELL_RSSI_MIN;
           }
           else if (pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].utraRssi > QUEC_CELL_RSSI_MAX)
           {
                pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].utraRssi = QUEC_CELL_RSSI_MAX;
           }
           
           p+=sprintf(p, "+QCELL: \"%s\",\"%s\",%03x,%02x,%04X,%x,%d,%d\r\n","neighbourcell","WCDMA",
                            pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].mcc,
                            pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].mnc,
                            pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].lac,
                            pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].ci,
                            pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].psc_cellParameterId,
                            pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].utraRssi); //sRxLev
           
		   if (1 != quec_assemble_qeng_resp(resBuf, p))
		   {
			   return;
		   }
	   }
   }
#endif
#ifdef QUEC_QCELLINFO_SUPPORT
        else if(CHECK_BIT_SET(network_infor_bitmsk ,QCELLINFOEX_GET))
        {
           Network_Info_Log("[quec qcellinfo] wcdma Inter numInterFreq=%d",pUmtsEngmodeInterFreqInfoInd->numInterFreq);
          
           for (cellNUM = 0; (cellNUM < pUmtsEngmodeInterFreqInfoInd->numInterFreq)&&(cellNUM < CI_DEV_MAX_UMTS_NEIGHBORING_CELLS); cellNUM++)
           { 
               /*check ci psc data */
               if ( (pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].ci == NCELL_CELL_ID_MAX) ||
                    (pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].ci == NCELL_CELL_ID_MIN) ||
                    (pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].psc_cellParameterId == NCELL_PSC_MAX) )
               {
                   continue;
               }
               memset(resBuf, 0, sizeof(resBuf));
               p = resBuf;
               p+=sprintf(p, "+QCELLINFO: \"%s\",\"%s\",%03x,%02x,%04X,%x,%d,%d,%d,%d\r\n","neighbourcell","WCDMA",
                                pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].mcc,
                                pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].mnc,
                                pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].lac,
                                pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].ci,
                                pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].psc_cellParameterId,
                                pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].sRxLev,
                                pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].sRxLev-111,
                                pUmtsEngmodeInterFreqInfoInd->interFreq[cellNUM].arfcn);
               
               if (1 != quec_assemble_qeng_resp(resBuf, p))
               {
                   return;
               }
           }
       }
#endif

	else
#endif
	{
		DBGMSG("Output EM info after receiving UMTS CI_DEV_PRIM_UMTS_ENGMODE_INTERFREQ_INFO_IND once \r\n");
		*p_UMTS_EM_IND_SEQ = 0;

		// +EEMUMTSINTER
		for (index = 0; index < pUmtsEngmodeInterFreqInfoInd->numInterFreq; index++)
		{
			sprintf(resBuf, "+EEMUMTSINTER: %d, ", index);

#ifndef TD_SUPPORT
			// -5- cpichRSCP, utraRssi, cpichEcN0, sQual, sRxLev
				sprintf(tempBuf, "%d, %d, %d, %d, %d, ", pUmtsEngmodeInterFreqInfoInd->interFreq[index].rscp,
			                                  pUmtsEngmodeInterFreqInfoInd->interFreq[index].utraRssi,
			                                  pUmtsEngmodeInterFreqInfoInd->interFreq[index].cpichEcN0,
			                                  pUmtsEngmodeInterFreqInfoInd->interFreq[index].sQual,
			                                  pUmtsEngmodeInterFreqInfoInd->interFreq[index].sRxLev);
			strcat(resBuf, tempBuf);

			// -6- mcc, mnc, lac, ci, arfcn, psc
			sprintf(tempBuf, "%d, %d, %d, %d, %d, %d", pUmtsEngmodeInterFreqInfoInd->interFreq[index].mcc,
			                                  pUmtsEngmodeInterFreqInfoInd->interFreq[index].mnc,
			                                  pUmtsEngmodeInterFreqInfoInd->interFreq[index].lac,
			                                  pUmtsEngmodeInterFreqInfoInd->interFreq[index].ci,
			                                  pUmtsEngmodeInterFreqInfoInd->interFreq[index].arfcn,
				                                  pUmtsEngmodeInterFreqInfoInd->interFreq[index].psc_cellParameterId);
			strcat(resBuf, tempBuf);
#else
			// -3- pccpchRSCP, utraRssi, sRxLev
				sprintf(tempBuf, "%d, %d, %d, ", pUmtsEngmodeInterFreqInfoInd->interFreq[index].rscp,
			                                  pUmtsEngmodeInterFreqInfoInd->interFreq[index].utraRssi,
			                                  pUmtsEngmodeInterFreqInfoInd->interFreq[index].sRxLev);
			strcat(resBuf, tempBuf);
			// -6- mcc, mnc, lac, ci, arfcn, cellParameterId
			sprintf(tempBuf, "%d, %d, %d, %d, %d, %d", pUmtsEngmodeInterFreqInfoInd->interFreq[index].mcc,
											  pUmtsEngmodeInterFreqInfoInd->interFreq[index].mnc,
											  pUmtsEngmodeInterFreqInfoInd->interFreq[index].lac,
											  pUmtsEngmodeInterFreqInfoInd->interFreq[index].ci,
											  pUmtsEngmodeInterFreqInfoInd->interFreq[index].arfcn,
									pUmtsEngmodeInterFreqInfoInd->interFreq[index].psc_cellParameterId);
			strcat(resBuf, tempBuf);
#endif
			strcat(resBuf, "\r\n");

			ATRESP(reqHandle, 0, 0, resBuf);
		}

	}

	return;
}

/****************************************************************
 *  F@: processEMUmtsInterRatInfoInd - Process UMTS engine mode info
 */
static void processEMUmtsInterRatInfoInd(UINT32 reqHandle, const void *pParam)
{
	CiDevPrimUmtsEngmodeInterRatInfoInd * pUmtsEngmodeInterRatInfoInd=NULL;
	UINT8 index=0;
	char resBuf[200];
	char tempBuf[50];
	UINT8 *p_UMTS_EM_IND_SEQ;
	
	if (reqHandle == IND_REQ_HANDLE) {
		p_UMTS_EM_IND_SEQ = &g_UMTS_EM_IND_SEQ;
	} else {
		p_UMTS_EM_IND_SEQ = &g_UMTS_EM_IND_SEQ_1;
	}

	memset(resBuf, 0, sizeof(resBuf));
	memset(tempBuf, 0, sizeof(tempBuf));
	
	pUmtsEngmodeInterRatInfoInd = (CiDevPrimUmtsEngmodeInterRatInfoInd *)pParam;

	/* Number of Inter-Frequency FDD Cells */
	if (pUmtsEngmodeInterRatInfoInd->numInterRAT > MAX_UMTS_NEIGHBORING_CELLS)
	{
		ERRMSG("pUmtsEngmodeInterRatInfoInd->numInterRAT  %d larger than MAX_UMTS_NEIGHBORING_CELLS \r\n", pUmtsEngmodeInterRatInfoInd->numInterRAT );
		return;
	}

	(*p_UMTS_EM_IND_SEQ)++;
#ifdef QUECTEL_NETWORK_SUPPORT
	char *p;
	UINT8 cellNUM=0;
#ifdef __QUEC_OEM_VER_LD__
	char					   pci_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   arfcn_buf[LANDI_VAL_BUF_MAX] = {0};
#endif 

	if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_NEIGHBOURCELL_GET))
	{
		//inter rat neighber cell of GSM

		Network_Info_Log("numInterRAT=%d,numNcellLte=%d", pUmtsEngmodeInterRatInfoInd->numInterRAT,pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.numNcellLte);
		for (cellNUM = 0; cellNUM < pUmtsEngmodeInterRatInfoInd->numInterRAT; cellNUM++)
		{
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
			//not supoort rank so rplace with -
	#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(pci_buf,0,sizeof(pci_buf));
				GET_VALID_VAL(pci_buf, pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].bsic);
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%s,%d,%d,%d\r\n","neighbourcell","GSM",
					pci_buf,
					pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].gsmRssi,
					pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rxLev,
					pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rank);
			}
			else
	#endif
			{
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%d,%d,%d,%d\r\n","neighbourcell","GSM",
					pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].bsic,
					pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].gsmRssi,
					pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rxLev,
					pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rank);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}

		//inter rat neighber cell of LTE
		for (cellNUM = 0; cellNUM < pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.numNcellLte; cellNUM++)
		{
			//not supoort rank so rplace with -
			if(pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.nCellInfoLte[cellNUM].earfcn ==0)
				continue;
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
	#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(pci_buf,0,sizeof(pci_buf));
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				GET_VALID_VAL(pci_buf, pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.nCellInfoLte[cellNUM].physCellId);
				GET_VALID_VAL(arfcn_buf, pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.nCellInfoLte[cellNUM].earfcn);
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%s,%s,%d,%d,%d\r\n","neighbourcell","LTE",
					arfcn_buf,
					pci_buf,
					pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.nCellInfoLte[cellNUM].rsrp-140,
					pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.nCellInfoLte[cellNUM].rsrq/2-20,
					pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.nCellInfoLte[cellNUM].s_rxlev);
			}
			else
	#endif
			{
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%d,%d,%d,%d,%d\r\n","neighbourcell","LTE",
					pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.nCellInfoLte[cellNUM].earfcn,
					pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.nCellInfoLte[cellNUM].physCellId,
					pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.nCellInfoLte[cellNUM].rsrp-140,
					pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.nCellInfoLte[cellNUM].rsrq/2-20,
					pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.nCellInfoLte[cellNUM].s_rxlev);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
	}
#ifndef ENABLE_DM_LTEONLY 
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_3GCOMM_GET))
	{
		//inter rat neighber cell of GSM
		Network_Info_Log("numInterRAT=%d,numNcellLte=%d", pUmtsEngmodeInterRatInfoInd->numInterRAT,pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.numNcellLte);
		for (cellNUM = 0; cellNUM < pUmtsEngmodeInterRatInfoInd->numInterRAT; cellNUM++)
		{
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
			//not supoort rank so rplace with -
	#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(pci_buf,0,sizeof(pci_buf));
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				GET_VALID_VAL(pci_buf, pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].bsic);
				GET_VALID_VAL(arfcn_buf, pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].arfcn);
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",\"%s\",%s,%s,%d,%d,%d\r\n", "3gcomm","neighbourcell","2G",
					arfcn_buf,
					pci_buf,
					pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].gsmRssi,
					pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rxLev,
					pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rank);
			}
			else
	#endif
			{
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",\"%s\",%d,%d,%d,%d,%d\r\n", "3gcomm","neighbourcell","2G",
					pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].arfcn,
					pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].bsic,
					pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].gsmRssi,
					pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rxLev,
					pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rank);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
	}
#endif
#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
   else if(CHECK_BIT_SET(network_infor_bitmsk ,MCELL))
   {
		   Network_Info_Log("numInterRAT=%d,numNcellLte=%d", pUmtsEngmodeInterRatInfoInd->numInterRAT,pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.numNcellLte);
		   for (cellNUM = 0; cellNUM < pUmtsEngmodeInterRatInfoInd->numInterRAT; cellNUM++)
		   {
			   //check if cell msg is valid
			   if((pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].mcc <= 0 || pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].mcc >0x999)
				  ||(pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].lac == 0)
				  ||(pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].ci == 0))
			   {
				   continue;
			   }
               memset(resBuf, 0, sizeof(resBuf));
      		   p = resBuf;
			   
			   p+=sprintf(p,"MCC: %x,MNC: %x,LAC: %5d,Cell ID: %9d,BSIC: %03X,(P)BCCH ARFCN: %04x,RxLev: %03x",
						 pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].mcc, pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].mnc,
						 pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].lac, pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].ci,
						 pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].bsic,
						 pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].arfcn,
						 pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rxLev);
			   if(pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rxLev <=63 )
			   {
				   p+=sprintf(p, ",RxDbm: %d\r\n", pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rxLev-111);
			   }
			   else
			   {
				   p+=sprintf(p, ",RxDbm: %d\r\n",63-111);
			   }
               if (1 != quec_assemble_qeng_resp(resBuf, p))
               {
                   return;
               }
		   }
		   // do not have lac info,do not show the msg
		   /*
		   for (cellNUM = 0; cellNUM < pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.numNcellLte && p<QUEC_QENG_RESBUF_END; cellNUM++)
		   {
			   p+=sprintf(p,"MCC: %x,MNC: %x,LAC: 	0,Cell ID: %9d,BSIC: -,(P)BCCH ARFCN: %04x,RxLev: %03x,RxDbm: %d\r\n",
						 quec_cereg_info.rplmnInfo.CountryCode,
						 quec_cereg_info.rplmnInfo.NetworkCode,
						 pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.nCellInfoLte[cellNUM].physCellId,
						 pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.nCellInfoLte[cellNUM].earfcn,
						 pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.nCellInfoLte[cellNUM].rsrp,
						 pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.nCellInfoLte[cellNUM].rsrp/10);
		   }
		   */
	   }
#endif
#ifdef QUECTEL_CELL
    else if(CHECK_BIT_SET(network_infor_bitmsk ,CELL_GET))
	{
		Network_Info_Log("[quec ncell] gsm numInterRAT=%d,numNcellLte=%d", pUmtsEngmodeInterRatInfoInd->numInterRAT,
                                                                    pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.numNcellLte);
		for (cellNUM = 0; (cellNUM < pUmtsEngmodeInterRatInfoInd->numInterRAT)&&(cellNUM < CI_DEV_MAX_UMTS_NEIGHBORING_CELLS); cellNUM++)
		{
		    if ((pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].ci == NCELL_CELL_ID_MAX) ||
                (pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].ci == NCELL_CELL_ID_MIN) ||
                (pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].bsic == NCELL_BSIC_MAX) ||
                (pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].mcc == NCELL_CELL_MCC_INVALID) )
            {
                continue;
            }
		    memset(resBuf, 0, sizeof(resBuf));
	        p = resBuf;

            /*check rssi range: 0-63*/
            if (pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rxLev < QUEC_CELL_RSSI_MIN)
            {
                 pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rxLev = QUEC_CELL_RSSI_MIN;
            }
            else if (pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rxLev > QUEC_CELL_RSSI_MAX)
            {
                 pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rxLev = QUEC_CELL_RSSI_MAX;
            }
            
			p+=sprintf(p, "+QCELL: \"%s\",\"%s\",%03x,%02x,%02x,%x,%d,%d\r\n","neighbourcell","GSM",
                            pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].mcc,
                            pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].mnc,
                            pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].lac,
                            pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].ci,
                            pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].bsic,
                            pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rxLev);
           
			if (1 != quec_assemble_qeng_resp(resBuf, p))
			{
				return;
			}
		}
	}
#endif
#ifdef QUEC_QCELLINFO_SUPPORT
        else if(CHECK_BIT_SET(network_infor_bitmsk ,QCELLINFOEX_GET))
        {
            Network_Info_Log("[quec qcellinfo] gsm numInterRAT=%d,numNcellLte=%d", pUmtsEngmodeInterRatInfoInd->numInterRAT,
                                              pUmtsEngmodeInterRatInfoInd->nCellInfoListLte.numNcellLte);
            for (cellNUM = 0; (cellNUM < pUmtsEngmodeInterRatInfoInd->numInterRAT)&&(cellNUM < CI_DEV_MAX_UMTS_NEIGHBORING_CELLS); cellNUM++)
            {
                if ((pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].ci == NCELL_CELL_ID_MAX) ||
                    (pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].ci == NCELL_CELL_ID_MIN) ||
                    (pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].bsic == NCELL_BSIC_MAX))
                {
                    continue;
                }
                memset(resBuf, 0, sizeof(resBuf));
                p = resBuf;
                p+=sprintf(p, "+QCELLINFO: \"%s\",\"%s\",%03x,%02x,%02x,%x,%d,%d,%d,%d\r\n","neighbourcell","GSM",
                                pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].mcc,
                                pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].mnc,
                                pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].lac,
                                pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].ci,
                                pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].bsic,
                                pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rxLev,
                                pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].rxLev-111,
                                pUmtsEngmodeInterRatInfoInd->interRAT[cellNUM].arfcn);
               
                if (1 != quec_assemble_qeng_resp(resBuf, p))
                {
                    return;
                }
            }
        }
#endif

	else
#endif
	//if ( g_UMTS_EM_IND_SEQ == UMTS_EM_IND_NUM_MAX)
	{
		DBGMSG("Output EM info after receiving UMTS CI_DEV_PRIM_UMTS_ENGMODE_INTERRAT_INFO_IND once \r\n");
		*p_UMTS_EM_IND_SEQ = 0;

		// +EEMUMTSINTERRAT:
		for (index = 0; index < pUmtsEngmodeInterRatInfoInd->numInterRAT; index++)
		{
			sprintf(resBuf, "+EEMUMTSINTERRAT: %d, ", index);

			// -4- gsmRssi, rxLev, C1, C2
			sprintf(tempBuf, "%d, %d, %d, %d, ", pUmtsEngmodeInterRatInfoInd->interRAT[index].gsmRssi,
			                                  pUmtsEngmodeInterRatInfoInd->interRAT[index].rxLev,
			                                  pUmtsEngmodeInterRatInfoInd->interRAT[index].C1,
			                                  pUmtsEngmodeInterRatInfoInd->interRAT[index].C2);
			strcat(resBuf, tempBuf);

			// -6- mcc, mnc, lac, ci, arfcn, bsic
			sprintf(tempBuf, "%d, %d, %d, %d, %d, %d\r\n", pUmtsEngmodeInterRatInfoInd->interRAT[index].mcc,
			                                  pUmtsEngmodeInterRatInfoInd->interRAT[index].mnc,
			                                  pUmtsEngmodeInterRatInfoInd->interRAT[index].lac,
			                                  pUmtsEngmodeInterRatInfoInd->interRAT[index].ci,
			                                  pUmtsEngmodeInterRatInfoInd->interRAT[index].arfcn,
			                                  pUmtsEngmodeInterRatInfoInd->interRAT[index].bsic	);
			strcat(resBuf, tempBuf);

			ATRESP(reqHandle, 0, 0, resBuf);
		}
	}
	return;
}
#ifdef QUEC_ASR_ATCMD_PAGING_UPDATE_SUPPORT
extern quec_pg_keepalive_cfg pg_cfg;
#endif
/****************************************************************
 *  F@: processEMLteINFOSVCInfoInd - Process LTE engine mode info
 */
static void processEMLteINFOSVCInfoInd(UINT32 reqHandle, const void *pParam)
{
	CiDevPrimLteEngmodeScellInfoInd * pLteEngmodeScellInfoInd;
	CiDevLteEngScellInfo *pLteEngScellInfo;
	char resBuf[500];
	char tempBuf[120];
	int *pSINR,  *pRSSI;
	BOOL *pSINRUpdate;
	BOOL *pRSSIUpdate;
	
	if (reqHandle == IND_REQ_HANDLE) {
		pSINR = &gSINR;
		pSINRUpdate = &gSINRUpdate;
		pRSSI = &gRSSI;
		pRSSIUpdate = &gRSSIUpdate;
	} else {
		pSINR = &gSINR_1;
		pSINRUpdate = &gSINRUpdate_1;
		pRSSI = &gRSSI_1;
		pRSSIUpdate = &gRSSIUpdate_1;
	}

	pLteEngmodeScellInfoInd = (CiDevPrimLteEngmodeScellInfoInd *)pParam;
	pLteEngScellInfo = &(pLteEngmodeScellInfoInd->info);

		
#ifdef QUECTEL_NETWORK_SUPPORT
	char *p;
	Quec_LTE_scell_type quec_scell ;
	static  Quec_LTE_scell_type quec_last_scell_ok={0};
	static  bool last_scell_ok_flag = FALSE;
	memset(&quec_scell,0,sizeof(quec_scell));
#ifdef __QUEC_OEM_VER_LD__//chaozhou add for landi format 2016/09/25
	char					   cid_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   pci_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   tac_buf[LANDI_VAL_BUF_MAX] = {0};
	char					   earfcn_buf[LANDI_VAL_BUF_MAX] = {0};
#endif

#if defined (QUEC_BLACK_CELL_SUPPORT)|| defined(QUEC_THIN_BLACK_CELL_SUPPORT)
#if defined (QUEC_BLACK_CELL_SUPPORT)
    if (((QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg_ex()) || (QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg()))
		&& (TRUE == quec_get_oneshot_flag()) )
#elif defined(QUEC_THIN_BLACK_CELL_SUPPORT)
    if ((QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg()) && (TRUE == quec_get_oneshot_flag()))
#endif          
    {
        quec_update_ltecellid_to_blackcell_check(pLteEngScellInfo->params.dlEuArfcn,
                                   pLteEngScellInfo->params.phyCellId,
                                   BLACKCELL_LTE,BLACKCELL_ADD);
        quec_set_oneshot_flag(FALSE);
    }
#endif

#ifdef QUECTEL_NETWORK_REJECT_URC_SUPPORT
	if((netreject_mode==1) && (report_flag==TRUE))
	{
		char tempBuf[256] = {0};
		memset(tempBuf, 0, 256);
		report_flag=FALSE;
		if(TRUE == quec_get_oneshot_flag())
		{
			quec_set_oneshot_flag(FALSE);
		}
		if(report_type==CI_DEV_COMMON_REPORT_EMM)
		{
			sprintf(tempBuf, "+QNETWORKSTATUS: EMM REJECT,%d,\"%s\",%03x%02x\r\n",
														reject_cause,result_ptr->text, 
														pLteEngScellInfo->params.mcc,
														pLteEngScellInfo->params.mnc);
		}
		else if(report_type==CI_DEV_COMMON_REPORT_ESM)
		{
			sprintf(tempBuf, "+QNETWORKSTATUS: ESM REJECT,%d,\"%s\",%03x%02x\r\n",
														reject_cause,result_ptr->text, 
														pLteEngScellInfo->params.mcc,
														pLteEngScellInfo->params.mnc);
		}
		else
		{
			sprintf(tempBuf, "+QNETWORKSTATUS: AS ABNORMAL,%d,\"%s\",%x,%03x%02x,%d,%d,%d,%d,%d\r\n",
														reject_cause,result_ptr->text,pLteEngScellInfo->params.dlEuArfcn, 
														pLteEngScellInfo->params.mcc,
														pLteEngScellInfo->params.mnc,
														pLteEngScellInfo->params.tac,
														pLteEngScellInfo->params.cellId,
														pLteEngScellInfo->params.phyCellId,
														pLteEngScellInfo->meas.rsrp-140,
														pLteEngScellInfo->meas.sinr);
		}
		at_urc_send(NUM_OF_TEL_ATP, (UINT8 *)tempBuf, strlen(tempBuf), TRUE, URC_OUT_METHOD_UNICAST, NULL);
	}
#endif

	if(CHECK_BIT_SET(network_infor_bitmsk ,QNWINFO_GET))
	{
		if(pLteEngmodeScellInfoInd->sCellPresent)
		{
		#if QUEC_DUAL_SIM_SUPPORT
			Quec_qnwinfo_type *p_quec_qnwinfo = &quec_qnwinfo[(reqHandle == IND_REQ_HANDLE) ? SIM1 : SIM2];
		#else
			Quec_qnwinfo_type *p_quec_qnwinfo = &quec_qnwinfo;
		#endif
			
			Network_Info_Log("processEMLteINFOSVCInfoInd,band=%d,dlEuArfcn=%d",pLteEngScellInfo->params.band,pLteEngScellInfo->params.dlEuArfcn);
			sprintf( &p_quec_qnwinfo->plmn[0],
						"%03x%02x",
						pLteEngScellInfo->params.mcc,
						pLteEngScellInfo->params.mnc );

		#ifdef QUECTEL_NETWORK_SUPPORT //Chaim 20190922 band34 is tdd
			if(pLteEngScellInfo->params.band >=33 && pLteEngScellInfo->params.band <=43)	
		#else
			if(pLteEngScellInfo->params.band >=38 && pLteEngScellInfo->params.band <=41)
		#endif
			{	 
				sprintf( &p_quec_qnwinfo->act[0],"TDD LTE");
			}
			else
			{
				sprintf( &p_quec_qnwinfo->act[0],"FDD LTE");
			}
			sprintf( &p_quec_qnwinfo->band_description[0],"LTE BAND %d",pLteEngScellInfo->params.band );
			p_quec_qnwinfo->active_channel=pLteEngScellInfo->params.dlEuArfcn;
			
			#ifdef QUECTEL_OPEN_CPU
			if(!IsMiniSystem())
			{
				quec_nw_event_ind(reqHandle, p_quec_qnwinfo->act, QUEC_NW_EVENT_ACT_INFO);
			}
			#endif
			//sprintf(resBuf,"+QNWINFO: \"%s\",\"%s\",\"%s\",%d ",quec_qnwinfo.act,quec_qnwinfo.plmn,quec_qnwinfo.band_description,quec_qnwinfo.active_channel);	
			//ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
		}
		else
		{
			Network_Info_Log("processEMLteINFOSVCInfoInd ERROR");
			//ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
		}
		//DEV_SetEngModeIndicatorOption(atHandle, 0, 0);//close engmode
		//BIT_CLR(network_infor_bitmsk, QNWINFO_GET);
	}
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_SERVINGCELL_GET))
	{
	#ifdef QUEC_ASR_ATCMD_PAGING_UPDATE_SUPPORT
	    Network_Info_Log("errcModeState=%d",pLteEngScellInfo->ueOpStatus.errcModeState);
	    if(pLteEngScellInfo->ueOpStatus.errcModeState == 2)
        {
            pg_cfg.pkt_chg_flag = FALSE;
        }
     #endif   
		quec_qeng_get_currrent_state(quec_scell.state);
		
		if(pLteEngScellInfo->params.isTdd==1)
		{
			memcpy(&quec_scell.tdd_fdd,(char *)"TDD",strlen((char *)"TDD"));
		}
		else
		{
			
			memcpy(&quec_scell.tdd_fdd,(char *)"FDD",strlen((char *)"FDD"));
		}
        memset(resBuf, 0, sizeof(resBuf));
		p = resBuf;

		#ifdef QUECTEL_NETWORK_SUPPORT
		//Chaim 20200803 invalid mcc mnc 
		if((0xFFFF== pLteEngScellInfo->params.mcc)&&(0XFFFF == pLteEngScellInfo->params.mnc)&&(TRUE == last_scell_ok_flag))
		{
			
			Network_Info_Log("use last servingcell,mcc=%d,mnc=%d,flag=%d",pLteEngScellInfo->params.mcc,pLteEngScellInfo->params.mnc,last_scell_ok_flag);
			quec_debug_print_uart("use last servingcell,mcc=%d,mnc=%d,flag=%d",pLteEngScellInfo->params.mcc,pLteEngScellInfo->params.mnc,last_scell_ok_flag);
			memcpy(&quec_scell,&quec_last_scell_ok,sizeof(quec_scell));
		}
		else
		{
		#endif
		quec_scell.mcc=pLteEngScellInfo->params.mcc;
		quec_scell.mnc=pLteEngScellInfo->params.mnc;
		quec_scell.cid=pLteEngScellInfo->params.cellId;
		quec_scell.pci=pLteEngScellInfo->params.phyCellId;
		quec_scell.earfcn=pLteEngScellInfo->params.dlEuArfcn;
		quec_scell.band=pLteEngScellInfo->params.band;
		quec_scell.ul_bandwidth=pLteEngScellInfo->params.dlBandwidth;
		quec_scell.dl_bandwidth=pLteEngScellInfo->params.dlBandwidth;
		quec_scell.tac=pLteEngScellInfo->params.tac;
		quec_scell.rsrp=pLteEngScellInfo->meas.rsrp-140;
		quec_scell.rsrq=pLteEngScellInfo->meas.rsrq/2-20;
#ifdef QUECTEL_NETWORK_SUPPORT
        /* 1601 Enhance engineer mode 时 L1不会上报当前的rssi信息，因此上报的CiDevPrimLteEngmodeScellInfoInd的rssi为0 
         * 从csq中上报的CiMmPrimExtendedSigQualityInfoInd获取rssi
         */
        #if QUEC_DUAL_SIM_SUPPORT
		quec_scell.rssi=quec_netquality_info[isMasterSim0() ? SIM1 : SIM2].rssi-128;
		#else
        quec_scell.rssi=quec_netquality_info.rssi-128;
		#endif
        Network_Info_Log("[quec csq]quec_scell.mcc=%d,quec_scell.mnc=%d",pLteEngScellInfo->params.mcc,pLteEngScellInfo->params.mnc);
#else
		quec_scell.rssi=pLteEngScellInfo->meas.rssi-128;
#endif		
		Network_Info_Log("quec_scell.rssi=%d,meas.rssi=%d,lenOfMnc=%d",quec_scell.rssi,pLteEngScellInfo->meas.rssi,pLteEngScellInfo->params.lenOfMnc);
		
		quec_scell.sinr=pLteEngScellInfo->meas.sinr;
#if 0 //#ifdef QUECTEL_NETWORK_SUPPORT
        Network_Info_Log("pLteEngScellInfo->meas.srxlev=%d",pLteEngScellInfo->meas.srxlev);
        /* isaac-20200717 rxlev：0-63 */
        quec_scell.srxlev = (pLteEngScellInfo->meas.srxlev/64 > QENG_SERVINGCELL_RXLEV_MAX)? QENG_SERVINGCELL_RXLEV_MAX : (pLteEngScellInfo->meas.srxlev/64);
#else
		quec_scell.srxlev=pLteEngScellInfo->meas.srxlev;
#endif	

		#ifdef QUECTEL_NETWORK_SUPPORT
			memcpy(&quec_last_scell_ok,&quec_scell,sizeof(quec_scell));
			last_scell_ok_flag =TRUE;
		}
		#endif
		
		p+=sprintf(p, "+QENG: \"%s\",\"%s\",\"%s\",\"%s\",%3X","servingcell",quec_scell.state,"LTE",
						quec_scell.tdd_fdd,
						quec_scell.mcc);
		
		if(pLteEngScellInfo->params.lenOfMnc==3)
		{
			p+=sprintf(p, ",%03X",quec_scell.mnc);
		}
		else
		{
			p+=sprintf(p, ",%02X",quec_scell.mnc);
		}
#ifdef __QUEC_OEM_VER_LD__
		if (TRUE == Quectel_IsOEMLandiEnable())
		{
			GET_VALID_VAL(cid_buf, quec_scell.cid);
			GET_VALID_VAL(pci_buf, quec_scell.pci);
			GET_VALID_VAL(earfcn_buf, quec_scell.earfcn);
			GET_VALID_VAL(tac_buf, quec_scell.tac);
			p+=sprintf(p, ",%s,%s,%s,%d,%d,%d,%s", 
							cid_buf,
							pci_buf,
							earfcn_buf,
							quec_scell.band,
							quec_scell.ul_bandwidth,
							quec_scell.dl_bandwidth,
							tac_buf);
		}
		else
#endif
		{
			p+=sprintf(p, ",%X,%d,%d,%d,%d,%d,%X", 
							quec_scell.cid,
							quec_scell.pci,
							quec_scell.earfcn,
							quec_scell.band,
							quec_scell.ul_bandwidth,
							quec_scell.dl_bandwidth,
							quec_scell.tac);
		}
	
		if(quec_scell.rsrp < 0 )
		{
			p+=sprintf(p, ",%d", quec_scell.rsrp);
		}
		else
		{
			p+=sprintf(p, ",-");
		}
		
		if(quec_scell.rsrq < 0 )
		{
			p+=sprintf(p, ",%d", quec_scell.rsrq);
		}
		else
		{
			p+=sprintf(p, ",-");
		}

		if(quec_scell.rssi < 0 )
		{
			p+=sprintf(p, ",%d", quec_scell.rssi);
		}
		else
		{
			p+=sprintf(p, ",-");
		}
		
		p+=sprintf(p, ",%d,%d\r\n", quec_scell.sinr,quec_scell.srxlev);
		#ifdef QUECTEL_CTWing_SUPPORT
		quec_g_txpower = pLteEngScellInfo->meas.currPuschTxPower;
		quec_g_rsrp = quec_scell.rsrp;
		quec_g_sinr = quec_scell.sinr;
		#endif
        if (1 != quec_assemble_qeng_resp(resBuf, p))
        {
            return;
        }
		//(void)at_urc_send(NUM_OF_TEL_ATP, resBuf, strlen(resBuf), FALSE, URC_OUT_METHOD_UNICAST);
	}
#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
	else if(CHECK_BIT_SET(network_infor_bitmsk ,MCELL))
	{
        memset(resBuf, 0, sizeof(resBuf));
		p = resBuf;
		quec_qeng_get_currrent_state(quec_scell.state);

		quec_scell.mcc=pLteEngScellInfo->params.mcc;
		quec_scell.mnc=pLteEngScellInfo->params.mnc;
		quec_scell.cid=pLteEngScellInfo->params.cellId;
		quec_scell.pci=pLteEngScellInfo->params.phyCellId;
		quec_scell.earfcn=pLteEngScellInfo->params.dlEuArfcn;
		quec_scell.band=pLteEngScellInfo->params.band;
		quec_scell.ul_bandwidth=pLteEngScellInfo->params.dlBandwidth;
		quec_scell.dl_bandwidth=pLteEngScellInfo->params.dlBandwidth;
		quec_scell.tac=pLteEngScellInfo->params.tac;
		quec_scell.rsrp=pLteEngScellInfo->meas.rsrp-140;
		quec_scell.rsrq=pLteEngScellInfo->meas.rsrq/2-20;
		quec_scell.rssi=pLteEngScellInfo->meas.rssi-128;

		quec_scell.sinr=pLteEngScellInfo->meas.sinr;
		quec_scell.srxlev=pLteEngScellInfo->meas.srxlev;
		
		p+=sprintf(p, "MCC: %x,MNC: %x,LAC: %5d,Cell ID: %9d,BSIC: -,(P)BCCH ARFCN: %04x,RxLev: %03x",
				   quec_scell.mcc, quec_scell.mnc, quec_scell.tac, quec_scell.pci, 
				   quec_scell.earfcn,quec_scell.srxlev);
		
		if(quec_scell.srxlev <=63  )
		{
			p+=sprintf(p, ",RxDbm: %d\r\n", quec_scell.srxlev-111);
		}
		else
		{
			p+=sprintf(p, ",RxDbm: %d\r\n",63-111);
		}
        if (1 != quec_assemble_qeng_resp(resBuf, p))
        {
            return;
        }
	}
#endif	
	#ifdef QUEC_ENGINEER_OUTPUT
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_ALL_INFO))
	{
		uint8 i=0;
		uint8 *ptemp= (uint8 *)quec_QengineerResBuf;	
		Network_Info_Log("ASR_ENG_MODE Start,scellinfo: sCellPresent=%d,res1U8[0]=%d,res1U8[1]=%d,res1U8[2]=%d",
			pLteEngmodeScellInfoInd->sCellPresent,
			pLteEngmodeScellInfoInd->res1U8[0],
			pLteEngmodeScellInfoInd->res1U8[1],
			pLteEngmodeScellInfoInd->res1U8[2]);


		Network_Info_Log("ASR_ENG_MODE,scell params_1,mcc=%d,lenOfMnc=%d,mnc=%d,tac=%d,phyCellId=%d,dlEuArfcn=%d,ulEuArfcn=%d",
				pLteEngScellInfo->params.mcc,
				pLteEngScellInfo->params.lenOfMnc,
				pLteEngScellInfo->params.mnc,
				pLteEngScellInfo->params.tac,
				pLteEngScellInfo->params.phyCellId,
				pLteEngScellInfo->params.dlEuArfcn,
				pLteEngScellInfo->params.ulEuArfcn);

		ptemp+=sprintf((char *)ptemp,"+QENGINFO: LTE,mcc:%d,lenOfMnc:%d,mnc:%d,tac:%d,phyCellId:%d,dlEuArfcn:%d,ulEuArfcn:%d",
			    pLteEngScellInfo->params.mcc,
				pLteEngScellInfo->params.lenOfMnc,
				pLteEngScellInfo->params.mnc,
				pLteEngScellInfo->params.tac,
				pLteEngScellInfo->params.phyCellId,
				pLteEngScellInfo->params.dlEuArfcn,
				pLteEngScellInfo->params.ulEuArfcn);
	
		
		Network_Info_Log("ASR_ENG_MODE,scell params_2,band=%d,dlBandwidth=%d,cellId=%d,",
			pLteEngScellInfo->params.band,
			pLteEngScellInfo->params.dlBandwidth,
			pLteEngScellInfo->params.cellId);

		ptemp+=sprintf((char *)ptemp,",band:%d,dlBandwidth:%d,cellId:%d",
			pLteEngScellInfo->params.band,
			pLteEngScellInfo->params.dlBandwidth,
			pLteEngScellInfo->params.cellId);
	
		Network_Info_Log("ASR_ENG_MODE,scell params_3,subFrameAssignType=%d,specialSubframePatterns=%d,transMode=%d,totalHandoversCount=%d",
				pLteEngScellInfo->params.subFrameAssignType,
				pLteEngScellInfo->params.specialSubframePatterns,
				pLteEngScellInfo->params.transMode,
				pLteEngScellInfo->params.totalHandoversCount);
	    ptemp+=sprintf((char *)ptemp,",subFrameAssignType:%d,specialSubframePatterns:%d,transMode:%d,totalHandoversCount:%d",
				pLteEngScellInfo->params.subFrameAssignType,
				pLteEngScellInfo->params.specialSubframePatterns,
				pLteEngScellInfo->params.transMode,
				pLteEngScellInfo->params.totalHandoversCount);
	
		
		Network_Info_Log("ASR_ENG_MODE,scell_params_4,succeededHandoversCount=%d,isTdd=%d,subframeAssignment=%d,succeededLteReselectionCount=%d",
			pLteEngScellInfo->params.succeededHandoversCount,
			pLteEngScellInfo->params.isTdd,
			pLteEngScellInfo->params.subframeAssignment,
			pLteEngScellInfo->params.succeededLteReselectionCount);

		 ptemp+=sprintf((char *)ptemp,",succeededHandoversCount:%d,isTdd:%d,subframeAssignment:%d,succeededLteReselectionCount:%d",
				pLteEngScellInfo->params.succeededHandoversCount,
			pLteEngScellInfo->params.isTdd,
			pLteEngScellInfo->params.subframeAssignment,
			pLteEngScellInfo->params.succeededLteReselectionCount);
        quec_siolib_transmit_to_atp(quec_qengineer_atp, "\r\n", 2, NULL);
		quec_siolib_transmit_to_atp(quec_qengineer_atp,(uint8 *)quec_QengineerResBuf,ptemp-(uint8 *)quec_QengineerResBuf,NULL);
		memset(quec_QengineerResBuf,0,QUEC_QENG_RESBUFLEN_MIN);
		ptemp =(uint8 *)quec_QengineerResBuf;
		
		Network_Info_Log("ASR_ENG_MODE,meas_1,succeededLteReestCounter=%d,timeStayConnectedMode=%d,rsrp=%d,rsrq=%d,sinr=%d,mainrsrp=%d",
				pLteEngScellInfo->params.succeededLteReestCounter,
				pLteEngScellInfo->params.timeStayConnectedMode,
				pLteEngScellInfo->meas.rsrp,
				pLteEngScellInfo->meas.rsrq,
				pLteEngScellInfo->meas.sinr,
				pLteEngScellInfo->meas.mainRsrp);
		
		ptemp+=sprintf((char *)ptemp,",succeededLteReestCounter:%d,timeStayConnectedMode:%d,rsrp:%d,rsrq:%d,sinr:%d,mainRsrp:%d",
				pLteEngScellInfo->params.succeededLteReestCounter,
				pLteEngScellInfo->params.timeStayConnectedMode,
				pLteEngScellInfo->meas.rsrp-140,
				pLteEngScellInfo->meas.rsrq,
				pLteEngScellInfo->meas.sinr,
				pLteEngScellInfo->meas.mainRsrp);
	
		Network_Info_Log("ASR_ENG_MODE,meas_2,diversityRsrp=%d,mainRsrq=%d,diversityRsrq=%d,rssi=%d,cqi=%d,pathLoss=%d",		
				pLteEngScellInfo->meas.diversityRsrp,
				pLteEngScellInfo->meas.mainRsrq,
				pLteEngScellInfo->meas.diversityRsrq,
				pLteEngScellInfo->meas.rssi,
				pLteEngScellInfo->meas.cqi,
				pLteEngScellInfo->meas.pathLoss);
		
		ptemp+=sprintf((char *)ptemp,",diversityRsrp:%d,mainRsrq:%d,diversityRsrq:%d,rssi:%d,cqi:%d,pathLoss:%d",
				pLteEngScellInfo->meas.diversityRsrp,
				pLteEngScellInfo->meas.mainRsrq,
				pLteEngScellInfo->meas.diversityRsrq,
				pLteEngScellInfo->meas.rssi,
				pLteEngScellInfo->meas.cqi,
				pLteEngScellInfo->meas.pathLoss);
	
		Network_Info_Log("ASR_ENG_MODE,meas_3,tb0DlTpt=%d,tb1DlTpt=%d,tb0DlPeakTpt=%d,tb1DlPeakTpt=%d,tb0UlPeakTpt=%d,tb1UlPeakTpt=%d",	
				pLteEngScellInfo->meas.tb0DlTpt,
				pLteEngScellInfo->meas.tb1DlTpt,
				pLteEngScellInfo->meas.tb0DlPeakTpt,
				pLteEngScellInfo->meas.tb1DlPeakTpt,
				pLteEngScellInfo->meas.tb0UlPeakTpt,
				pLteEngScellInfo->meas.tb1UlPeakTpt);

		ptemp+=sprintf((char *)ptemp,",tb0DlTpt:%d,tb1DlTpt:%d,tb0DlPeakTpt:%d,tb1DlPeakTpt:%d,tb0UlPeakTpt:%d,tb1UlPeakTpt:%d",
				pLteEngScellInfo->meas.tb0DlTpt,
				pLteEngScellInfo->meas.tb1DlTpt,
				pLteEngScellInfo->meas.tb0DlPeakTpt,
				pLteEngScellInfo->meas.tb1DlPeakTpt,
				pLteEngScellInfo->meas.tb0UlPeakTpt,
				pLteEngScellInfo->meas.tb1UlPeakTpt);
	
		Network_Info_Log("ASR_ENG_MODE,meas_4,dlThroughPut=%d,dlPeakThroughPut=%d,averDlPRB=%d,averCQITb0=%d",	
				pLteEngScellInfo->meas.dlThroughPut,
				pLteEngScellInfo->meas.dlPeakThroughPut,
				pLteEngScellInfo->meas.averDlPRB,
				pLteEngScellInfo->meas.averCQITb0);
		
		ptemp+=sprintf((char *)ptemp,",dlThroughPut:%d,dlPeakThroughPut:%d,averDlPRB:%d,averCQITb0:%d",
				pLteEngScellInfo->meas.dlThroughPut,
				pLteEngScellInfo->meas.dlPeakThroughPut,
				pLteEngScellInfo->meas.averDlPRB,
				pLteEngScellInfo->meas.averCQITb0);
		Network_Info_Log("ASR_ENG_MODE,meas_5,averCQITb1=%d,rankIndex=%d,grantTotal=%d,ulThroughPut=%d,ulPeakThroughPut=%d,currPuschTxPower=%d,averUlPRB=%d,averULMcs=%d",
				pLteEngScellInfo->meas.averCQITb1,
				pLteEngScellInfo->meas.rankIndex,
				pLteEngScellInfo->meas.grantTotal,
				pLteEngScellInfo->meas.ulThroughPut,
				pLteEngScellInfo->meas.ulPeakThroughPut,
				pLteEngScellInfo->meas.currPuschTxPower,
				pLteEngScellInfo->meas.averUlPRB,
				pLteEngScellInfo->meas.averULMcs);
       ptemp+=sprintf((char *)ptemp,",averCQITb1:%d,rankIndex:%d,grantTotal:%d,ulThroughPut:%d,ulPeakThroughPut:%d,currPuschTxPower:%d,averUlPRB:%d,averULMcs:%d",
				pLteEngScellInfo->meas.averCQITb1,
				pLteEngScellInfo->meas.rankIndex,
				pLteEngScellInfo->meas.grantTotal,
				pLteEngScellInfo->meas.ulThroughPut,
				pLteEngScellInfo->meas.ulPeakThroughPut,
				pLteEngScellInfo->meas.currPuschTxPower,
				pLteEngScellInfo->meas.averUlPRB,
				pLteEngScellInfo->meas.averULMcs);
				
		quec_siolib_transmit_to_atp(quec_qengineer_atp,(uint8 *)quec_QengineerResBuf,ptemp-(uint8 *)quec_QengineerResBuf,NULL);
		memset(quec_QengineerResBuf,0,QUEC_QENG_RESBUFLEN_MIN);
		ptemp =(uint8 *)quec_QengineerResBuf;
		
		Network_Info_Log("ASR_ENG_MODE,meas_6,dlBler=%d,ulBler=%d,reserved1=%d,reserved2=%d",
				pLteEngScellInfo->meas.dlBler,
				pLteEngScellInfo->meas.ulBler,
				pLteEngScellInfo->meas.diversitySinr,
				pLteEngScellInfo->meas.reserved2_1);
		ptemp+=sprintf((char *)ptemp,",dlBler:%d,ulBler:%d,reserved1:%d,reserved2:%d",
				pLteEngScellInfo->meas.dlBler,
				pLteEngScellInfo->meas.ulBler,
				pLteEngScellInfo->meas.diversitySinr,
				pLteEngScellInfo->meas.reserved2_1);


		Network_Info_Log("ASR_ENG_MODE,meas_6,reserved3=%d,reserved4=%d,srxlev=%d,txPower=%d",
				pLteEngScellInfo->meas.reserved3,
				pLteEngScellInfo->meas.reserved4,
				pLteEngScellInfo->meas.srxlev,
				pLteEngScellInfo->meas.txPower);
		ptemp+=sprintf((char *)ptemp,",reserved3:%d,reserved4:%d,srxlev:%d,txPower:%d",
				pLteEngScellInfo->meas.reserved3,
				pLteEngScellInfo->meas.reserved4,
				pLteEngScellInfo->meas.srxlev,
				pLteEngScellInfo->meas.txPower);

				
	
		Network_Info_Log("ASR_ENG_MODE,meas_7,mainDLMcs=%d,diversityDLMcs=%d,averDlMcsTb0=%d,averDlMcsTb1=%d",
				pLteEngScellInfo->meas.mainDLMcs,
				pLteEngScellInfo->meas.diversityDLMcs,
				pLteEngScellInfo->meas.averDlMcsTb0,
				pLteEngScellInfo->meas.averDlMcsTb1);
		
        ptemp+=sprintf((char *)ptemp,",mainDLMcs:%d,diversityDLMcs:%d,averDlMcsTb0:%d,averDlMcsTb1:%d",
				pLteEngScellInfo->meas.mainDLMcs,
				pLteEngScellInfo->meas.diversityDLMcs,
				pLteEngScellInfo->meas.averDlMcsTb0,
				pLteEngScellInfo->meas.averDlMcsTb1);
		

		Network_Info_Log("ASR_ENG_MODE,operation_1,errcModeState=%d,emmState=%d,serviceState=%d,IsSingleEmmRejectCause=%d,EMMRejectCause=%d",
				pLteEngScellInfo->ueOpStatus.errcModeState,
				pLteEngScellInfo->ueOpStatus.emmState,
				pLteEngScellInfo->ueOpStatus.serviceState,
				pLteEngScellInfo->ueOpStatus.IsSingleEmmRejectCause,
				pLteEngScellInfo->ueOpStatus.EMMRejectCause);

		 ptemp+=sprintf((char *)ptemp,",errcModeState:%d,emmState:%d,serviceState:%d,IsSingleEmmRejectCause:%d,EMMRejectCause:%d",
				pLteEngScellInfo->ueOpStatus.errcModeState,
				pLteEngScellInfo->ueOpStatus.emmState,
				pLteEngScellInfo->ueOpStatus.serviceState,
				pLteEngScellInfo->ueOpStatus.IsSingleEmmRejectCause,
				pLteEngScellInfo->ueOpStatus.EMMRejectCause);
	
		Network_Info_Log("ASR_ENG_MODE,operation_2,mmeGroupId=%d,mmeCode=%d,mTmsi=%d",
				pLteEngScellInfo->ueOpStatus.mmeGroupId,
				pLteEngScellInfo->ueOpStatus.mmeCode,
				pLteEngScellInfo->ueOpStatus.mTmsi);

		ptemp+=sprintf((char *)ptemp,",mmeGroupId:%d,mmeCode:%d,mTmsi:%d",
				pLteEngScellInfo->ueOpStatus.mmeGroupId,
				pLteEngScellInfo->ueOpStatus.mmeCode,
				pLteEngScellInfo->ueOpStatus.mTmsi);
		quec_siolib_transmit_to_atp(quec_qengineer_atp,(uint8 *)quec_QengineerResBuf,ptemp-(uint8 *)quec_QengineerResBuf,NULL);
		memset(quec_QengineerResBuf,0,QUEC_QENG_RESBUFLEN_MIN);
		ptemp =(uint8 *)quec_QengineerResBuf;
		
		Network_Info_Log("ASR_ENG_MODE,END,scell_meas_6,ptemp=%p,quec_QengineerResLen=%p,%d",ptemp,quec_QengineerResBuf,ptemp-(uint8 *)quec_QengineerResBuf);
	}
	#endif
#ifdef QUECTEL_CELL
    else if(CHECK_BIT_SET(network_infor_bitmsk ,CELL_GET))
	{
        quec_scell.mcc=pLteEngScellInfo->params.mcc;
		quec_scell.mnc=pLteEngScellInfo->params.mnc;
        quec_scell.tac=pLteEngScellInfo->params.tac;
		quec_scell.cid=pLteEngScellInfo->params.cellId;
		quec_scell.pci=pLteEngScellInfo->params.phyCellId;
		
        /* 1601 Enhance engineer mode 时 L1不会上报当前的rssi信息，因此上报的CiDevPrimLteEngmodeScellInfoInd的rssi为0 
         * 从csq中上报的CiMmPrimExtendedSigQualityInfoInd获取rssi
         */
        #if QUEC_DUAL_SIM_SUPPORT
		quec_scell.rssi=quec_netquality_info[isMasterSim0() ? SIM1 : SIM2].rssi;
		#else
        quec_scell.rssi=quec_netquality_info.rssi;
		#endif
		quec_scell.srxlev=pLteEngScellInfo->meas.srxlev;
        Network_Info_Log("[quec ncell] serving cell info : rssi=%d", quec_scell.rssi);
        
        memset(resBuf, 0, sizeof(resBuf));
		p = resBuf;

        /*check rssi range: 0-63*/
        if (quec_scell.rssi < QUEC_CELL_RSSI_MIN)
        {
             quec_scell.rssi = QUEC_CELL_RSSI_MIN;
        }
        else if (quec_scell.rssi > QUEC_CELL_RSSI_MAX)
        {
             quec_scell.rssi = QUEC_CELL_RSSI_MAX;
        }
        
		p+=sprintf(p, "+QCELL: \"%s\",\"%s\",%03x,%02x,%04x,%x,%d,%d\r\n","servingcell","LTE",
                        quec_scell.mcc,
                        quec_scell.mnc,
                        quec_scell.tac,
                        quec_scell.cid,
                        quec_scell.pci,
                        quec_scell.rssi);

		if (1 != quec_assemble_qeng_resp(resBuf, p))
		{
			return;
		}
	}
#endif
#ifdef QUEC_RSRP_SUPPORT
	else if (CHECK_BIT_SET(network_infor_bitmsk ,RSRP_GET))
	{
		INT16 rsrp = -120;
		char res_buf[32];
		rsrp = pLteEngScellInfo->meas.rsrp-140;
		Network_Info_Log("meas rsrp=%d,rsrp=%d",pLteEngScellInfo->meas.rsrp,rsrp);
		memset(res_buf, 0, sizeof(res_buf));
		p = res_buf; 
		p+=sprintf(p, "+RSRP: %d\r\n",rsrp);
		if (1 != quec_assemble_qeng_resp(res_buf, p))
		{
			return;
		}
	}
#endif
#ifdef QUEC_QCELLINFO_SUPPORT
        else if(CHECK_BIT_SET(network_infor_bitmsk ,QCELLINFOEX_GET))
        {
            quec_scell.mcc=pLteEngScellInfo->params.mcc;
            quec_scell.mnc=pLteEngScellInfo->params.mnc;
            quec_scell.tac=pLteEngScellInfo->params.tac;
            quec_scell.cid=pLteEngScellInfo->params.cellId;
            quec_scell.pci=pLteEngScellInfo->params.phyCellId;
            quec_scell.earfcn=pLteEngScellInfo->params.dlEuArfcn;
            /* 1601 Enhance engineer mode 时 L1不会上报当前的rssi信息，因此上报的CiDevPrimLteEngmodeScellInfoInd的rssi为0 
             * 从csq中上报的CiMmPrimExtendedSigQualityInfoInd获取rssi
             */
            #if QUEC_DUAL_SIM_SUPPORT
			quec_scell.rssi=quec_netquality_info[isMasterSim0() ? SIM1 : SIM2].rssi;
			#else
            quec_scell.rssi=quec_netquality_info.rssi;
			#endif
            quec_scell.srxlev=pLteEngScellInfo->meas.srxlev;
            Network_Info_Log("[quec qcellinfo] serving cell info : rssi=%d", quec_scell.rssi);
            
            memset(resBuf, 0, sizeof(resBuf));
            p = resBuf;
            p+=sprintf(p, "+QCELLINFO: \"%s\",\"%s\",%03x,%02x,%04x,%x,%d,%d,%d,%d\r\n","servingcell","LTE",
                            quec_scell.mcc,
                            quec_scell.mnc,
                            quec_scell.tac,
                            quec_scell.cid,
                            quec_scell.pci,
                            quec_scell.rssi,
                            quec_scell.rssi-128,
                            quec_scell.earfcn);
    
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
        }
#endif
#ifdef QUEC_QNWCFG_SUPPORT
		else if(CHECK_BIT_SET(network_infor_bitmsk ,QCQI_MCS_GET))
		{
			if(pLteEngmodeScellInfoInd->sCellPresent)
			{
				Network_Info_Log("processEMLteINFOSVCInfoInd,CQI=%d,MCS=%d,MCSd=%d,MCS0=%d,MCS1=%d",pLteEngScellInfo->meas.cqi,
										pLteEngScellInfo->meas.averDlMcsTb0);
				qnwcfg_csi_info.CQI=pLteEngScellInfo->meas.cqi;
				qnwcfg_csi_info.DLMCS0=pLteEngScellInfo->meas.averDlMcsTb0;
				qnwcfg_csi_info.DLMCS1=pLteEngScellInfo->meas.averDlMcsTb1;
			}
			else
			{
				qnwcfg_csi_info.CQI=0;
				qnwcfg_csi_info.DLMCS0=0;
				qnwcfg_csi_info.DLMCS1=0;
				Network_Info_Log("processEMLteINFOSVCInfoInd ERROR");
			}
		}
#endif
#ifdef QUEC_CCED_SUPPORT
		else if (CHECK_BIT_SET(network_infor_bitmsk,QUEC_CCED_S_GET))
		{
			//reset lteneighbourmaximum
			quec_cced_lteneigmaximum = 7;
			extern char IMSI[];
			char cced_dlbangwidth[5];
			
			//info-servingcell
			if(quec_cced_mode == QUEC_CCED_NO_AUTO_MODE)
			{
				#ifdef QUECTEL_NETWORK_SUPPORT
				//Chaim 20200803 invalid mcc mnc 
				if((0xFFFF== pLteEngScellInfo->params.mcc)&&(0XFFFF == pLteEngScellInfo->params.mnc)&&(TRUE == last_scell_ok_flag))
				{
					
					Network_Info_Log("use last servingcell,mcc=%d,mnc=%d,flag=%d",pLteEngScellInfo->params.mcc,pLteEngScellInfo->params.mnc,last_scell_ok_flag);
					quec_debug_print_uart("use last servingcell,mcc=%d,mnc=%d,flag=%d",pLteEngScellInfo->params.mcc,pLteEngScellInfo->params.mnc,last_scell_ok_flag);
					memcpy(&quec_scell,&quec_last_scell_ok,sizeof(quec_scell));
				}
				else
				{
#endif
					quec_scell.mcc=pLteEngScellInfo->params.mcc;
					quec_scell.mnc=pLteEngScellInfo->params.mnc;
					quec_scell.cid=pLteEngScellInfo->params.cellId;
					quec_scell.pci=pLteEngScellInfo->params.phyCellId;
					quec_scell.earfcn=pLteEngScellInfo->params.dlEuArfcn;
					quec_scell.band=pLteEngScellInfo->params.band;
					quec_scell.ul_bandwidth=pLteEngScellInfo->params.dlBandwidth;
					quec_scell.dl_bandwidth=pLteEngScellInfo->params.dlBandwidth;
					quec_scell.tac=pLteEngScellInfo->params.tac;
					//Consistent with QDM038_EU_IE parameters
					quec_scell.rsrp=pLteEngScellInfo->meas.rsrp;
					if(quec_scell.rsrp < 0)
					{
						quec_scell.rsrp = 0;
					}
					//Parameter upper limit
					else if(quec_scell.rsrp > 97)
					{
						quec_scell.rsrp = 97;
					}
					quec_scell.rsrq=abs(pLteEngScellInfo->meas.rsrq/2-20);

					memset(resBuf, 0, sizeof(resBuf));
					if (quec_scell.dl_bandwidth == 0)
					{
						sprintf(cced_dlbangwidth,"n6");
					}
					else if(quec_scell.dl_bandwidth == 1)
					{
						sprintf(cced_dlbangwidth,"n15");
					}
					else if(quec_scell.dl_bandwidth == 2)
					{
						sprintf(cced_dlbangwidth,"n25");
					}
					else if(quec_scell.dl_bandwidth == 3)
					{
						sprintf(cced_dlbangwidth,"n50");
					}
					else if(quec_scell.dl_bandwidth == 4)
					{
						sprintf(cced_dlbangwidth,"n75");
					}
					else if(quec_scell.dl_bandwidth == 5)
					{
						sprintf(cced_dlbangwidth,"n100");
					}
#ifdef QUECTEL_NETWORK_SUPPORT
					/* 1601 Enhance engineer mode 鏃? L1涓嶄細涓婃姤褰撳墠鐨剅ssi淇℃伅锛屽洜姝や笂鎶ョ殑CiDevPrimLteEngmodeScellInfoInd鐨剅ssi涓?0 
					 * 浠巆sq涓笂鎶ョ殑CiMmPrimExtendedSigQualityInfoInd鑾峰彇rssi
					 */
#if QUEC_DUAL_SIM_SUPPORT
					quec_scell.rssi=quec_netquality_info[isMasterSim0() ? SIM1 : SIM2].rssi-128;
#else
					quec_scell.rssi=quec_netquality_info.rssi-128;
#endif
					Network_Info_Log("[quec csq]quec_scell.mcc=%d,quec_scell.mnc=%d",pLteEngScellInfo->params.mcc,pLteEngScellInfo->params.mnc);
#else
					quec_scell.rssi=pLteEngScellInfo->meas.rssi-128;
#endif		
					Network_Info_Log("quec_scell.rssi=%d,meas.rssi=%d,lenOfMnc=%d",quec_scell.rssi,pLteEngScellInfo->meas.rssi,pLteEngScellInfo->params.lenOfMnc);
					//Consistent with EG91 parameters
					quec_scell.sinr= ((pLteEngScellInfo->meas.sinr + 20)* 5);
#if 0//#ifdef QUECTEL_NETWORK_SUPPORT
					Network_Info_Log("pLteEngScellInfo->meas.srxlev=%d",pLteEngScellInfo->meas.srxlev);
					/* isaac-20200717 rxlev锛?0-63 */
					quec_scell.srxlev = (pLteEngScellInfo->meas.srxlev/64 > QENG_SERVINGCELL_RXLEV_MAX)? QENG_SERVINGCELL_RXLEV_MAX : (pLteEngScellInfo->meas.srxlev%64);
#else
					quec_scell.srxlev=pLteEngScellInfo->meas.srxlev;
#endif	
		
#ifdef QUECTEL_NETWORK_SUPPORT
					memcpy(&quec_last_scell_ok,&quec_scell,sizeof(quec_scell));
					last_scell_ok_flag =TRUE;
				}
#endif
		
				memset(resBuf, 0, sizeof(resBuf));
				p = resBuf;
			
				p+=sprintf(p, "+CCED:%s:%X", 
					"LTE current cell",
					quec_scell.mcc);		

				if(pLteEngScellInfo->params.lenOfMnc==3)
				{
					p+=sprintf(p, ",%03X",quec_scell.mnc);
				}
				else
				{
					p+=sprintf(p, ",%02X",quec_scell.mnc);
				}

				p+=sprintf(p, ",%s,%u,%d,%s,%d,%ld,%d,%d,%d,%d,%d\r\n", 
					IMSI,
					0,//Currently not supported
					quec_scell.band,
					cced_dlbangwidth,
					quec_scell.earfcn,
					quec_scell.cid,
					quec_scell.rsrp,
					quec_scell.rsrq,
					quec_scell.tac,
					quec_scell.srxlev,
					quec_scell.pci);	
				
				if (1 != quec_assemble_qeng_resp(resBuf, p))
				{
					return;
				}	
			}
		}
#endif

	else
	{
#endif
	if(pLteEngmodeScellInfoInd->sCellPresent!=0)
	{
		DBGMSG("Output EM info after receiving LTE CI_DEV_PRIM_LTE_ENGMODE_SVCCELL_INFO_IND once\r\n");

		*pSINR = pLteEngScellInfo->meas.sinr;
		*pSINRUpdate = TRUE;
		*pRSSI = pLteEngScellInfo->meas.rssi;
		*pRSSIUpdate = TRUE;

		
		gcell_lac = pLteEngScellInfo->params.tac;
		gcell_ci  = pLteEngScellInfo->params.cellId;
		gcell_mcc = pLteEngScellInfo->params.mcc;
		gcell_mnc = pLteEngScellInfo->params.mnc;
		
#ifdef AT_FOR_GW20180208SN
		current_accessTechnology = 2;
		current_bandInd = pLteEngScellInfo->params.band;
		m_channel = pLteEngScellInfo->params.dlEuArfcn; 
		sprintf( (char *)curr_operIdLongStr, "%03x+%02x", pLteEngScellInfo->params.mcc,pLteEngScellInfo->params.mnc);
		m_lac_tac = pLteEngScellInfo->params.tac;
	
		m_cell_id = pLteEngScellInfo->params.cellId;
		m_bsic_phycellid = pLteEngScellInfo->params.phyCellId;
		if(pLteEngScellInfo->meas.rssi != 0xFF)
		{
			m_rxdbm = pLteEngScellInfo->meas.rssi-128;
		}
		else
		{
			m_rxdbm = 199;
		}
		
		if(pLteEngScellInfo->meas.currPuschTxPower != 0xFFFF)
		{
			m_txdbm = pLteEngScellInfo->meas.currPuschTxPower;
		}
		else
		{
			m_txdbm = 199;
		}
		m_rsrp = pLteEngScellInfo->meas.rsrp;
		m_rsrq = pLteEngScellInfo->meas.rsrq;
		m_sinr = pLteEngScellInfo->meas.sinr*10;
		
		if(gMMZRSSI == 3)
		{
			return;
		}

#endif
		// +EEMLTESVC

		sprintf(resBuf, "+EEMLTESVC:");



		sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, %d, %d, %d, ", pLteEngScellInfo->params.mcc,
				pLteEngScellInfo->params.lenOfMnc,
				pLteEngScellInfo->params.mnc,
				pLteEngScellInfo->params.tac,
				pLteEngScellInfo->params.phyCellId,
				pLteEngScellInfo->params.dlEuArfcn,
				pLteEngScellInfo->params.ulEuArfcn,
				pLteEngScellInfo->params.band,
				pLteEngScellInfo->params.dlBandwidth);

		strcat(resBuf, tempBuf);

		sprintf(tempBuf, "%d, %d, %d, ", pLteEngScellInfo->meas.rsrp,
				pLteEngScellInfo->meas.rsrq,
				pLteEngScellInfo->meas.sinr);
		
		strcat(resBuf, tempBuf);

		sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, %d, %d,", pLteEngScellInfo->ueOpStatus.errcModeState,
			pLteEngScellInfo->ueOpStatus.emmState,
			pLteEngScellInfo->ueOpStatus.serviceState,
			pLteEngScellInfo->ueOpStatus.IsSingleEmmRejectCause,
			pLteEngScellInfo->ueOpStatus.EMMRejectCause,
			pLteEngScellInfo->ueOpStatus.mmeGroupId,
			pLteEngScellInfo->ueOpStatus.mmeCode,
			pLteEngScellInfo->ueOpStatus.mTmsi);
		strcat(resBuf, tempBuf);

		sprintf(tempBuf, "%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d,%d, %d, %d", pLteEngmodeScellInfoInd->sCellPresent,
			pLteEngScellInfo->params.cellId,
			pLteEngScellInfo->params.subFrameAssignType,
			pLteEngScellInfo->params.specialSubframePatterns,
			pLteEngScellInfo->params.transMode,
			pLteEngScellInfo->meas.mainRsrp,
			pLteEngScellInfo->meas.diversityRsrp,
			pLteEngScellInfo->meas.mainRsrq,
			pLteEngScellInfo->meas.diversityRsrq,
			pLteEngScellInfo->meas.rssi,
			pLteEngScellInfo->meas.cqi,
			pLteEngScellInfo->meas.pathLoss,
			pLteEngScellInfo->meas.tb0DlTpt,
			pLteEngScellInfo->meas.tb1DlTpt,			
			pLteEngScellInfo->meas.tb0DlPeakTpt,
			pLteEngScellInfo->meas.tb1DlPeakTpt,
			pLteEngScellInfo->meas.tb0UlPeakTpt
			
			);
		strcat(resBuf, tempBuf);

		sprintf(tempBuf, ", %d, %d, %d, %d, %d, %d, %d, %u, %u, %u, %d, %d", pLteEngScellInfo->meas.tb1UlPeakTpt,
			pLteEngScellInfo->meas.dlThroughPut,
			pLteEngScellInfo->meas.dlPeakThroughPut,
			pLteEngScellInfo->meas.averDlPRB,
			pLteEngScellInfo->meas.averCQITb0,
			pLteEngScellInfo->meas.averCQITb1,
			pLteEngScellInfo->meas.rankIndex,
			pLteEngScellInfo->meas.grantTotal,
			pLteEngScellInfo->meas.ulThroughPut,
			pLteEngScellInfo->meas.ulPeakThroughPut,
			pLteEngScellInfo->meas.currPuschTxPower,
			pLteEngScellInfo->meas.averUlPRB);
		strcat(resBuf, tempBuf);

		sprintf(tempBuf, ", %d, %d", pLteEngScellInfo->meas.dlBler,
			pLteEngScellInfo->meas.ulBler);
		strcat(resBuf, tempBuf);
		
		strcat(resBuf, "\r\n");

		ATRESP(reqHandle, 0, 0, resBuf);
	}
#ifdef QUECTEL_NETWORK_SUPPORT		
	}
#endif

	return;
}


/****************************************************************
 *  F@: processEMLteIntraFreqInfoInd - Process LTE engine mode info
 */
static void processEMLteIntraFreqInfoInd(UINT32 reqHandle, const void *pParam)
{
	CiDevPrimLteEngmodeIntraFreqInfoInd * pLteEngmodeIntraFreqInfoInd=NULL;
	UINT8 index=0;
	char resBuf[200];
	char tempBuf[50];

	memset(resBuf, 0, sizeof(resBuf));
	memset(tempBuf, 0, sizeof(tempBuf));
	
	pLteEngmodeIntraFreqInfoInd = (CiDevPrimLteEngmodeIntraFreqInfoInd *)pParam;

	//test
	#ifdef QUEC_ENGINEER_OUTPUT
		uint8 i=0;
		Network_Info_Log("ASR_ENG_MODE,lteintrafreq:numIntraFreq=%d,res1U8[0]=%d,res1U8[1]=%d,res1U8[2]=%d",
			pLteEngmodeIntraFreqInfoInd->numIntraFreq,
			pLteEngmodeIntraFreqInfoInd->res1U8[0],
			pLteEngmodeIntraFreqInfoInd->res1U8[1],
			pLteEngmodeIntraFreqInfoInd->res1U8[2]);

			 
		for(i=0;i<pLteEngmodeIntraFreqInfoInd->numIntraFreq;i++)
		{
			CiDevLteEngIntraFreqNcellInfo *ptemp_pointer = &(pLteEngmodeIntraFreqInfoInd->intraFreq[i]);
			
			Network_Info_Log("ASR_ENG_MODE,intrafreq_1,i=%d,phyCellId=%d,euArfcn=%d,rsrp=%d,mcc=%d,lenOfMnc=%d,mnc=%d,tac=%d,cellId=%d,srxlev=%d",
					i,
					ptemp_pointer->phyCellId,
					ptemp_pointer->euArfcn,
					ptemp_pointer->rsrp,
					ptemp_pointer->rsrq,
					ptemp_pointer->mcc,
					ptemp_pointer->lenOfMnc,
					ptemp_pointer->mnc,
					ptemp_pointer->tac,
					ptemp_pointer->cellId,
					ptemp_pointer->srxlev);

					Network_Info_Log("ASR_ENG_MODE,intrafreq_2,i=%d,cellReselectionPriority=%d,sNonIntraSearch=%d,threshServingLow=%d,threshServingLow=%d",
					i,
					ptemp_pointer->cellReselectionPriority,
					ptemp_pointer->sNonIntraSearch,
					ptemp_pointer->threshServingLow,
					ptemp_pointer->threshServingLow);	
		}

	#endif
	
	/* Neighboring Cell information */
	if (pLteEngmodeIntraFreqInfoInd->numIntraFreq > CI_DEV_LTE_MAX_CELL_INTRA)
	{
		ERRMSG("pUmtsEngmodeIntraFreqInfoInd->numIntraFreq %d larger than CI_DEV_PRIM_LTE_ENGMODE_INTRAFREQ_INFO_IND \r\n", pLteEngmodeIntraFreqInfoInd->numIntraFreq   );
		return;
	}
#ifdef QUECTEL_NETWORK_SUPPORT
	char *p;
	if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_NEIGHBOURCELL_GET))
	{
		UINT8 cellNUM=0;
#ifdef __QUEC_OEM_VER_LD__
		char					   pci_buf[LANDI_VAL_BUF_MAX] = {0};
		char					   arfcn_buf[LANDI_VAL_BUF_MAX] = {0};
#endif 
		Network_Info_Log("numIntraFreq=%d", pLteEngmodeIntraFreqInfoInd->numIntraFreq);
		//inter rat neighber cell of GSM
		for (cellNUM = 0; cellNUM < pLteEngmodeIntraFreqInfoInd->numIntraFreq; cellNUM++)
		{
			//not supoort rssi,sinr so rplace with -
			if(pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].euArfcn ==0)
				continue;
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
	#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				memset(pci_buf,0,sizeof(pci_buf));
				GET_VALID_VAL(pci_buf, pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].phyCellId);
				GET_VALID_VAL(arfcn_buf, pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].euArfcn);
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%s,%s,%d,%d,-,-,%d,%d,%d,%d,%d\r\n","neighbourcell intra","LTE",
					arfcn_buf,
					pci_buf,
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rsrp-140,
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rsrq/2-20,
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].srxlev,
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].cellReselectionPriority,
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].sNonIntraSearch,
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].threshServingLow,
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].sIntraSearch);
			}
			else
	#endif
			{
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%d,%d,%d,%d,-,-,%d,%d,%d,%d,%d\r\n","neighbourcell intra","LTE",
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].euArfcn,
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].phyCellId,
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rsrp-140,
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rsrq/2-20,
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].srxlev,
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].cellReselectionPriority,
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].sNonIntraSearch,
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].threshServingLow,
					pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].sIntraSearch);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
	}
#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
	else if(CHECK_BIT_SET(network_infor_bitmsk ,MCELL))
	{
		UINT8 cellNUM=0;
		 Network_Info_Log("numIntraFreq=%d", pLteEngmodeIntraFreqInfoInd->numIntraFreq);
		 
		 for (cellNUM = 0; cellNUM < pLteEngmodeIntraFreqInfoInd->numIntraFreq; cellNUM++)
		 {
			  //check if cell msg is valid
			   if((pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].tac == 0)
				  ||(pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].phyCellId == 0))
			   {
				   continue;
			   }
               memset(resBuf, 0, sizeof(resBuf));
               p = resBuf;
			   p+=sprintf(p,"MCC: %x,MNC: %x,LAC: %5d,Cell ID: %9d,BSIC: -,(P)BCCH ARFCN: %04x,RxLev: %03x,RxDbm: %d\r\n",
					#if QUEC_DUAL_SIM_SUPPORT 
						 quec_cereg_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].rplmnInfo.CountryCode,
						 quec_cereg_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].rplmnInfo.NetworkCode,
					#else
			   			 quec_cereg_info.rplmnInfo.CountryCode,
						 quec_cereg_info.rplmnInfo.NetworkCode,
				 	#endif
						 pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].tac,
						 pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].phyCellId,
						 pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].euArfcn,
						 pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rsrp,
						 pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rsrp/10);
               if (1 != quec_assemble_qeng_resp(resBuf, p))
               {
                   return;
               }
		 }
	}
#endif	
#ifdef QUECTEL_CELL
    else if(CHECK_BIT_SET(network_infor_bitmsk ,CELL_GET))
	{
		UINT8 cellNUM=0;
       
		Network_Info_Log("[quec ncell] numIntraFreq=%d", pLteEngmodeIntraFreqInfoInd->numIntraFreq);
		
		for (cellNUM = 0; (cellNUM < pLteEngmodeIntraFreqInfoInd->numIntraFreq)&&(cellNUM < CI_DEV_LTE_MAX_CELL_INTRA); cellNUM++)
		{    
		    if ((pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].cellId == NCELL_CELL_ID_MAX) ||
                (pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].cellId == NCELL_CELL_ID_MIN) ||
                (pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].phyCellId == NCELL_PSC_MAX) ||
                (pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mcc == NCELL_CELL_MCC_INVALID) )
            {
                continue;
            }
			memset(resBuf, 0, sizeof(resBuf));
			p = resBuf;
            
			p+=sprintf(p, "+QCELL: \"%s\",\"%s\",%03x","neighbourcell intra","LTE",pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mcc); 
            
            if (pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].lenOfMnc == 3)
            {
                p+=sprintf(p, ",%03x",pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mnc); 
            }
            else 
            {
                p+=sprintf(p, ",%02x",pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mnc);
            }
            
			/*check rssi range: 0-63*/
			if (pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rsrp <= QUEC_CELL_RSSI_MIN)
			{
				 pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rsrp = QUEC_CELL_RSSI_MIN;
			}
			else if (pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rsrp > QUEC_CELL_RSSI_MAX)
			{
				 pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rsrp = QUEC_CELL_RSSI_MAX;
			}

            p+=sprintf(p, ",%04x,%x,%d,%d\r\n",
                    pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].tac,
				    pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].cellId, 
				    pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].phyCellId,
				    pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rsrp); //rxlev: rsrp
				    
			if (1 != quec_assemble_qeng_resp(resBuf, p))
			{ 
			    Network_Info_Log("[quec ncell] qeng rrsp error!");
				return;
			}
		}
	}
#endif
#ifdef QUEC_QCELLINFO_SUPPORT
        else if(CHECK_BIT_SET(network_infor_bitmsk ,QCELLINFOEX_GET))
        {
            UINT8 cellNUM=0;
           
            Network_Info_Log("[quec qcellinfo] numIntraFreq=%d", pLteEngmodeIntraFreqInfoInd->numIntraFreq);
            
            for (cellNUM = 0; (cellNUM < pLteEngmodeIntraFreqInfoInd->numIntraFreq)&&(cellNUM < CI_DEV_LTE_MAX_CELL_INTRA); cellNUM++)
            {    
                if ((pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].cellId == NCELL_CELL_ID_MAX) ||
                    (pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].cellId == NCELL_CELL_ID_MIN) ||
                    (pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].phyCellId == NCELL_PSC_MAX))
                {
                    continue;
                }
                memset(resBuf, 0, sizeof(resBuf));
                p = resBuf;
                
                p+=sprintf(p, "+QCELLINFO: \"%s\",\"%s\",%03x","neighbourcell intra","LTE",pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mcc); 
                
                if (pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].lenOfMnc == 3)
                {
                    p+=sprintf(p, ",%03x",pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mnc); 
                }
                else 
                {
                    p+=sprintf(p, ",%02x",pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mnc);
                }
             
                p+=sprintf(p, ",%04x,%x,%d,%d,%d,%d\r\n",
                        pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].tac,
                        pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].cellId, 
                        pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].phyCellId,
                        pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rsrp, //rxlev: rsrp
                        pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rsrp-140,
                        pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].euArfcn);
                        
                if (1 != quec_assemble_qeng_resp(resBuf, p))
                { 
                    Network_Info_Log("[quec ncell] qeng rrsp error!");
                    return;
                }
            }
        }
#endif
#ifdef QUEC_CCED_SUPPORT
		else if (CHECK_BIT_SET(network_infor_bitmsk,QUEC_CCED_NB_GET))
		{
			if(quec_cced_mode == QUEC_CCED_NO_AUTO_MODE)
			{
				UINT8 cellNUM=0;
				int vaildcellnumbner = 0;
				int quec_nbcell_rsrp = 0;
				Network_Info_Log("numIntraFreq=%d", pLteEngmodeIntraFreqInfoInd->numIntraFreq);
				
				for (cellNUM = 0; cellNUM < pLteEngmodeIntraFreqInfoInd->numIntraFreq; cellNUM++)
				{
					//not supoort rssi,sinr so rplace with -
					if(pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].euArfcn ==0)
						continue;

					quec_cced_lteneigmaximum--;
					if(quec_cced_lteneigmaximum<0)
					{
						break;
					}
					memset(resBuf, 0, sizeof(resBuf));
					p = resBuf;
					
					//Consistent with QDM038_EU_IE parameters
					quec_nbcell_rsrp = pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rsrp;
					if(quec_nbcell_rsrp < 0)			
					{
						quec_nbcell_rsrp = 0;
					}
					//Parameter upper limit
					else if(quec_nbcell_rsrp > 97)	
					{
						quec_nbcell_rsrp = 97;
					}
					
#ifdef QUECTEL_NETWORK_SUPPORT
					INT16 quec_nbcell_srxlev;
					quec_nbcell_srxlev = pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].srxlev;

				//	/* isaac-20200717 rxlev锛?0-63 */
				//	quec_nbcell_srxlev = (pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].srxlev/64 > QENG_SERVINGCELL_RXLEV_MAX)? QENG_SERVINGCELL_RXLEV_MAX : (pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].srxlev%64);
#endif	
					p+=sprintf(p, "+CCED:%s:%X", 
						"LTE neighbour cell",
						pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mcc);

					if(pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].lenOfMnc==3)
					{
						p+=sprintf(p, ",%03X",pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mnc);
					}
					else
					{
						p+=sprintf(p, ",%02X",pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].mnc);
					}

					p+=sprintf(p, ",%u,%ld,%d,%d,%d,%d,%d\r\n", 
						0,//Currently not supported
						pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].cellId,
						quec_nbcell_rsrp,
						abs(pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].rsrq/2-20),
						pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].tac,
						quec_nbcell_srxlev,
						pLteEngmodeIntraFreqInfoInd->intraFreq[cellNUM].phyCellId);
					
					if (1 != quec_assemble_qeng_resp(resBuf, p))
					{
						return;
					}
				}
			}
		}	
#endif

	else
#endif

	{
		DBGMSG("Output EM info after receiving UMTS CI_DEV_PRIM_LTE_ENGMODE_INTRAFREQ_INFO_IND once \r\n");

		// +EEMLTEINTRA

		for (index = 0; index < pLteEngmodeIntraFreqInfoInd->numIntraFreq; index++)
		{
			sprintf(resBuf, "+EEMLTEINTRA: %d, ", index);


			// -4- phyCellId, euArfcn, rsrp,rsrq
				sprintf(tempBuf, "%d, %d, %d, %d", pLteEngmodeIntraFreqInfoInd->intraFreq[index].phyCellId,
			                                  pLteEngmodeIntraFreqInfoInd->intraFreq[index].euArfcn,
										      pLteEngmodeIntraFreqInfoInd->intraFreq[index].rsrp,
			                                  pLteEngmodeIntraFreqInfoInd->intraFreq[index].rsrq);

			strcat(resBuf, tempBuf);
			
			strcat(resBuf, "\r\n");

			ATRESP(reqHandle, 0, 0, resBuf);

		}
	}

	return;
}


/****************************************************************
 *  F@: processEMLteInterFreqInfoInd - Process LTE engine mode info
 */
static void processEMLteInterFreqInfoInd(UINT32 reqHandle,const void *pParam)
{
	CiDevPrimLteEngmodeInterFreqInfoInd * pLteEngmodeInterFreqInfoInd=NULL;
	UINT8 index=0;
	char resBuf[200];
	char tempBuf[50];

	memset(resBuf, 0, sizeof(resBuf));
	memset(tempBuf, 0, sizeof(tempBuf));
	
	pLteEngmodeInterFreqInfoInd = (CiDevPrimLteEngmodeInterFreqInfoInd *)pParam;
	//test
	#ifdef QUEC_ENGINEER_OUTPUT
		uint8 i=0;
		Network_Info_Log("ASR_ENG_MODE,lteinterfreq:numInterFreq=%d,res1U8[0]=%d,res1U8[1]=%d,res1U8[2]=%d",
			pLteEngmodeInterFreqInfoInd->numInterFreq,
			pLteEngmodeInterFreqInfoInd->res1U8[0],
			pLteEngmodeInterFreqInfoInd->res1U8[1],
			pLteEngmodeInterFreqInfoInd->res1U8[2]);

			 
		for(i=0;i<pLteEngmodeInterFreqInfoInd->numInterFreq;i++)
		{
			CiDevLteEngInterFreqNcellInfo *ptemp_pointer = &(pLteEngmodeInterFreqInfoInd->interFreq[i]);
			
			Network_Info_Log("ASR_ENG_MODE,interratfreq_1,i=%d,phyCellId=%d,euArfcn=%d,rsrp=%d,mcc=%d,lenOfMnc=%d,mnc=%d,tac=%d",
					i,
					ptemp_pointer->phyCellId,
					ptemp_pointer->euArfcn,
					ptemp_pointer->rsrp,
					ptemp_pointer->rsrq,
					ptemp_pointer->mcc,
					ptemp_pointer->lenOfMnc,
					ptemp_pointer->mnc,
					ptemp_pointer->tac);
			
			Network_Info_Log("ASR_ENG_MODE,interratfreq_2,i=%d,srxlev=%d,threshXLow=%d,threshhigh=%d,cellReselectionPriority=%d",
					i,
					ptemp_pointer->srxlev,
					ptemp_pointer->threshXLow,
					ptemp_pointer->threshXHigh,
					ptemp_pointer->cellReselectionPriority);
					
		}

	#endif
	
	/* Neighboring Cell information */
	if (pLteEngmodeInterFreqInfoInd->numInterFreq > CI_DEV_LTE_MAX_CELL_INTER)
	{
		ERRMSG("pUmtsEngmodeIntraFreqInfoInd->numIntraFreq %d larger than CI_DEV_PRIM_LTE_ENGMODE_INTERFREQ_INFO_IND \r\n", pLteEngmodeIntraFreqInfoInd->numIntraFreq   );
		return;
	}
#ifdef QUECTEL_NETWORK_SUPPORT
	char *p;
	if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_NEIGHBOURCELL_GET))
	{
		UINT8 cellNUM=0;
#ifdef __QUEC_OEM_VER_LD__
		char					   pci_buf[LANDI_VAL_BUF_MAX] = {0};
		char					   arfcn_buf[LANDI_VAL_BUF_MAX] = {0};
#endif 
		Network_Info_Log("numInterFreq=%d", pLteEngmodeInterFreqInfoInd->numInterFreq);
		//inter rat neighber cell of GSM
		for (cellNUM = 0; cellNUM < pLteEngmodeInterFreqInfoInd->numInterFreq; cellNUM++)
		{
			//not supoort rssi,sinr so rplace with -
			if(pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].euArfcn ==0)
				continue;
            memset(resBuf, 0, sizeof(resBuf));
    		p = resBuf;
	#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				memset(pci_buf,0,sizeof(pci_buf));
				GET_VALID_VAL(pci_buf, pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].phyCellId);
				GET_VALID_VAL(arfcn_buf, pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].euArfcn);
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%s,%s,%d,%d,-,-,%d,%d,%d,%d\r\n","neighbourcell inter","LTE",
					arfcn_buf,
					pci_buf,
					pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].rsrp-140,
					pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].rsrq/2-20,
					pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].srxlev,
					pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].threshXLow,
					pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].threshXHigh,
					pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].cellReselectionPriority);
			}
			else
	#endif
			{
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%d,%d,%d,%d,-,-,%d,%d,%d,%d\r\n","neighbourcell inter","LTE",
					pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].euArfcn,
					pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].phyCellId,
					pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].rsrp-140,
					pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].rsrq/2-20,
					pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].srxlev,
					pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].threshXLow,
					pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].threshXHigh,
					pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].cellReselectionPriority);
			}
            if (1 != quec_assemble_qeng_resp(resBuf, p))
            {
                return;
            }
		}
	}
#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
	else if(CHECK_BIT_SET(network_infor_bitmsk ,MCELL))
	{
		UINT8 cellNUM=0;
		 Network_Info_Log("numInterFreq=%d", pLteEngmodeInterFreqInfoInd->numInterFreq);
		 
		 for (cellNUM = 0; cellNUM < pLteEngmodeInterFreqInfoInd->numInterFreq; cellNUM++)
		 {
			   //check if cell msg is valid
			   if((pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].phyCellId  == 0)
				   ||(pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].tac == 0))
			   {
				   continue;
			   }
               memset(resBuf, 0, sizeof(resBuf));
       		   p = resBuf;
			   p+=sprintf(p,"MCC: %x,MNC: %x,LAC: %5d,Cell ID: %9d,BSIC: -,(P)BCCH ARFCN: %04x,RxLev: %03x,RxDbm: %d\r\n",
			   		#if QUEC_DUAL_SIM_SUPPORT
						 quec_cereg_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].rplmnInfo.CountryCode,
						 quec_cereg_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].rplmnInfo.NetworkCode,
					#else
						 quec_cereg_info.rplmnInfo.CountryCode,
						 quec_cereg_info.rplmnInfo.NetworkCode,
					#endif
						 pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].tac,
						 pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].phyCellId,
						 pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].euArfcn,
						 pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].rsrp,
						 pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].rsrp/10);
               if (1 != quec_assemble_qeng_resp(resBuf, p))
               {
                   return;
               }
		 } 
	}
#endif
#ifdef QUECTEL_CELL
    else if(CHECK_BIT_SET(network_infor_bitmsk, CELL_GET))
	{
	    UINT8 cellNUM=0;
       
        Network_Info_Log("[quec ncell] numInterFreq=%d",pLteEngmodeInterFreqInfoInd->numInterFreq);
       
		for (cellNUM = 0; (cellNUM < pLteEngmodeInterFreqInfoInd->numInterFreq)&&(cellNUM < CI_DEV_LTE_MAX_CELL_INTRA); cellNUM++)
        { 
            if ((pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].cellId == NCELL_CELL_ID_MAX) || 
                (pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].cellId == NCELL_CELL_ID_MIN) ||
                (pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].phyCellId == NCELL_PSC_MAX) ||
                    (pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].mcc == NCELL_CELL_MCC_INVALID) )
            {
                continue;
            }
            memset(resBuf, 0, sizeof(resBuf));
			p = resBuf;
			p+=sprintf(p, "+QCELL: \"%s\",\"%s\",%03x","neighbourcell inter","LTE",pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].mcc); 
            
            if (pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].lenOfMnc == 3)
            {
                p+=sprintf(p, ",%03x",pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].mnc); 
            }
            else 
            {
                p+=sprintf(p, ",%02x",pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].mnc);
            }

            /*check rssi range: 0-63*/
            if (pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].rsrp <= QUEC_CELL_RSSI_MIN)
            {
                 pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].rsrp = QUEC_CELL_RSSI_MIN;
            }
            else if (pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].rsrp > QUEC_CELL_RSSI_MAX)
            {
                 pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].rsrp = QUEC_CELL_RSSI_MAX;
            }

            p+=sprintf(p, ",%04x,%x,%d,%d\r\n",
                    pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].tac,
				    pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].cellId, 
				    pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].phyCellId,
				    pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].rsrp); //srxlev
           
		    if (1 != quec_assemble_qeng_resp(resBuf, p))
			{
				return;
			}
		}
	  }
#endif
#ifdef QUEC_QCELLINFO_SUPPORT
        else if(CHECK_BIT_SET(network_infor_bitmsk, QCELLINFOEX_GET))
        {
            UINT8 cellNUM=0;
           
            Network_Info_Log("[quec qcellinfo] numInterFreq=%d",pLteEngmodeInterFreqInfoInd->numInterFreq);
           
            for (cellNUM = 0; (cellNUM < pLteEngmodeInterFreqInfoInd->numInterFreq)&&(cellNUM < CI_DEV_LTE_MAX_CELL_INTRA); cellNUM++)
            { 
                if ((pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].cellId == NCELL_CELL_ID_MAX) || 
                    (pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].cellId == NCELL_CELL_ID_MIN) ||
                    (pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].phyCellId == NCELL_PSC_MAX))
                {
                    continue;
                }
                memset(resBuf, 0, sizeof(resBuf));
                p = resBuf;
                p+=sprintf(p, "+QCELLINFO: \"%s\",\"%s\",%03x","neighbourcell inter","LTE",pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].mcc); 
                
                if (pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].lenOfMnc == 3)
                {
                    p+=sprintf(p, ",%03x",pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].mnc); 
                }
                else 
                {
                    p+=sprintf(p, ",%02x",pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].mnc);
                }
                
                p+=sprintf(p, ",%04x,%x,%d,%d,%d,%d\r\n",
                        pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].tac,
                        pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].cellId, 
                        pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].phyCellId,
                        pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].rsrp, //srxlev
                        pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].rsrp-140,
                        pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].euArfcn);
               
                if (1 != quec_assemble_qeng_resp(resBuf, p))
                {
                    return;
                }
            }
        }
#endif
#ifdef QUEC_CCED_SUPPORT
		else if (CHECK_BIT_SET(network_infor_bitmsk,QUEC_CCED_NB_GET))
		{
			if(quec_cced_mode == QUEC_CCED_NO_AUTO_MODE)
			{
				UINT8 cellNUM=0;
				int quec_nbcell_rsrp = 0;
				Network_Info_Log("numInterFreq=%d", pLteEngmodeInterFreqInfoInd->numInterFreq);
				
				for (cellNUM = 0; cellNUM < pLteEngmodeInterFreqInfoInd->numInterFreq; cellNUM++)
				{
					//not supoort rssi,sinr so rplace with -
					if(pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].euArfcn ==0)
						continue;

					quec_cced_lteneigmaximum--;
					if(quec_cced_lteneigmaximum<0)
					{
						break;
					}
					memset(resBuf, 0, sizeof(resBuf));
					p = resBuf;
					
					//Consistent with QDM038_EU_IE parameters
					quec_nbcell_rsrp = pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].rsrp;
					if(quec_nbcell_rsrp < 0)			
					{
						quec_nbcell_rsrp = 0;
					}
					//Parameter upper limit
					else if(quec_nbcell_rsrp > 97)	
					{
						quec_nbcell_rsrp = 97;
					}
					
#ifdef QUECTEL_NETWORK_SUPPORT
					INT16 quec_nbcell_srxlev;
					quec_nbcell_srxlev = pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].srxlev;

					///* isaac-20200717 rxlev锛?0-63 */
					//quec_nbcell_srxlev = (pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].srxlev/64 > QENG_SERVINGCELL_RXLEV_MAX)? QENG_SERVINGCELL_RXLEV_MAX : (pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].srxlev%64);
#endif	
					p+=sprintf(p, "+CCED:%s:%X", 
						"LTE neighbour cell",
						pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].mcc);

					if(pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].lenOfMnc==3)
					{
						p+=sprintf(p, ",%03X",pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].mnc);
					}
					else
					{
						p+=sprintf(p, ",%02X",pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].mnc);
					}

					p+=sprintf(p, ",%u,%ld,%d,%d,%d,%d,%d\r\n", 
						0,//Currently not supported
						pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].cellId,
						quec_nbcell_rsrp,
						abs(pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].rsrq/2-20),
						pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].tac,
						quec_nbcell_srxlev,
						pLteEngmodeInterFreqInfoInd->interFreq[cellNUM].phyCellId);
					
					if (1 != quec_assemble_qeng_resp(resBuf, p))
					{
						return;
					}
				}
			}
		}	
#endif

	else
#endif

	{
		DBGMSG("Output EM info after receiving UMTS CI_DEV_PRIM_LTE_ENGMODE_INTERFREQ_INFO_IND once \r\n");

		// +EEMLTEINTER

		for (index = 0; index < pLteEngmodeInterFreqInfoInd->numInterFreq; index++)
		{
			sprintf(resBuf, "+EEMLTEINTER: %d, ", index);


			// -4- phyCellId, euArfcn, rsrp,rsrq
				sprintf(tempBuf, "%d, %d, %d, %d", pLteEngmodeInterFreqInfoInd->interFreq[index].phyCellId,
			                                  pLteEngmodeInterFreqInfoInd->interFreq[index].euArfcn,
										      pLteEngmodeInterFreqInfoInd->interFreq[index].rsrp,
			                                  pLteEngmodeInterFreqInfoInd->interFreq[index].rsrq);

			strcat(resBuf, tempBuf);
			
			strcat(resBuf, "\r\n");

			ATRESP(reqHandle, 0, 0, resBuf);

		}
	}

	return;

}

#ifndef LTEONLY_THIN

/****************************************************************
 *  F@: processEMLteInterRatInfoInd - Process LTE engine mode info
 */
static void processEMLteInterRatInfoInd(UINT32 reqHandle,const void *pParam)
{
	CiDevPrimLteEngmodeInterRatInfoInd * pLteEngmodeInterRatInfoInd=NULL;
	char rspBuf[1024];
	char tempBuf[50];
	UINT8 cellNUM=0;
#ifdef QUECTEL_NETWORK_SUPPORT
	UINT8 index;
	char *p;
#endif 

	memset(rspBuf, 0, sizeof(rspBuf));
	memset(tempBuf, 0, sizeof(tempBuf));
	
	pLteEngmodeInterRatInfoInd = (CiDevPrimLteEngmodeInterRatInfoInd *)pParam;

	//test
	#ifdef QUEC_ENGINEER_OUTPUT
		uint8 i=0;
		Network_Info_Log("ASR_ENG_MODE,lteinterrat:numInterRATUtra=%d,numInterRATGsm=%d,res1U8[0]=%d,res1U8[1]=%d",
			pLteEngmodeInterRatInfoInd->numInterRATUtra,
			pLteEngmodeInterRatInfoInd->numInterRATGsm,
			pLteEngmodeInterRatInfoInd->res1U8[0],
			pLteEngmodeInterRatInfoInd->res1U8[1]);

			 
		for(i=0;i<pLteEngmodeInterRatInfoInd->numInterRATUtra;i++)
		{
			CiDevLteEngUtraCellParams *ptemp_pointer = &(pLteEngmodeInterRatInfoInd->interRATUtra[i].params);
			
			Network_Info_Log("ASR_ENG_MODE,interratumts_1,i=%d,mcc=%d,mnc=%d,lac=%d,ci=%d,uarfcn=%d,psc_cellParameterId=%d",
					i,
					ptemp_pointer->mcc,
					ptemp_pointer->mnc,
					ptemp_pointer->lac,
					ptemp_pointer->ci,
					ptemp_pointer->uArfcn,
					ptemp_pointer->psc_cellParameterId);	

		  Network_Info_Log("ASR_ENG_MODE,interratumts_2,i=%d,cellresel=%d,thresxhigh=%d,thresxlow=%d",
					i,
					ptemp_pointer->cellReselectionPriority,
					ptemp_pointer->threshXHigh,
					ptemp_pointer->threshXLow);
		}

		for(i=0;i<pLteEngmodeInterRatInfoInd->numInterRATGsm;i++)
		{
			CiDevLteEngGsmCellMeas *ptemp_pointer = &(pLteEngmodeInterRatInfoInd->interRATGsm[i].meas);
			
			Network_Info_Log("ASR_ENG_MODE,interratgsm,i=%d,rssi=%d,srxlev=%d",
					i,
					ptemp_pointer->rssi,
					ptemp_pointer->srxlev);	
		}
	#endif
	


	if (pLteEngmodeInterRatInfoInd->numInterRATGsm > CI_DEV_LTE_MAX_CELL_GSM)
	{
		ERRMSG("pLteEngmodeInterRatInfoInd->numInterRATGsm %d larger than CI_DEV_LTE_MAX_CELL_GSM \r\n", pLteEngmodeInterRatInfoInd->numInterRATGsm );
	}
#ifdef QUECTEL_NETWORK_SUPPORT
	else if (CHECK_BIT_SET(network_infor_bitmsk ,QENG_NEIGHBOURCELL_GET))
	{

#ifdef __QUEC_OEM_VER_LD__
		char					   bsic_buf[LANDI_VAL_BUF_MAX] = {0};
		char					   arfcn_buf[LANDI_VAL_BUF_MAX] = {0};
#endif 
		//inter rat neighber cell of GSM
		Network_Info_Log("numInterRATGsm=%d", pLteEngmodeInterRatInfoInd->numInterRATGsm);
		for (index = 0; index < pLteEngmodeInterRatInfoInd->numInterRATGsm; index++)
		{
			//not supoort rssi,sinr so rplace with -
			if(pLteEngmodeInterRatInfoInd->interRATGsm[index].params.arfcn ==0)
				continue;
            memset(rspBuf, 0, sizeof(rspBuf));
    		p = rspBuf;
	#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				memset(bsic_buf,0,sizeof(bsic_buf));
				GET_VALID_VAL(bsic_buf, pLteEngmodeInterRatInfoInd->interRATGsm[index].params.bsic);
				GET_VALID_VAL(arfcn_buf, pLteEngmodeInterRatInfoInd->interRATGsm[index].params.arfcn);
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%s,%d,%d,%d,%d,%d,%s,%d,%d\r\n","neighbourcell","GSM",
					arfcn_buf,
					pLteEngmodeInterRatInfoInd->interRATGsm[index].params.cellReselectionPriority,
					pLteEngmodeInterRatInfoInd->interRATGsm[index].params.threshXHigh,
					pLteEngmodeInterRatInfoInd->interRATGsm[index].params.threshXLow,
					pLteEngmodeInterRatInfoInd->interRATGsm[index].params.nccPermitted,
					pLteEngmodeInterRatInfoInd->interRATGsm[index].params.gsmBandIndicator,
					bsic_buf,
					pLteEngmodeInterRatInfoInd->interRATGsm[index].meas.rssi,
					pLteEngmodeInterRatInfoInd->interRATGsm[index].meas.srxlev);
			}
			else
	#endif
			{
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%d,%d,%d,%d,%d,%d,%d,%d,%d\r\n","neighbourcell","GSM",
					pLteEngmodeInterRatInfoInd->interRATGsm[index].params.arfcn,
					pLteEngmodeInterRatInfoInd->interRATGsm[index].params.cellReselectionPriority,
					pLteEngmodeInterRatInfoInd->interRATGsm[index].params.threshXHigh,
					pLteEngmodeInterRatInfoInd->interRATGsm[index].params.threshXLow,
					pLteEngmodeInterRatInfoInd->interRATGsm[index].params.nccPermitted,
					pLteEngmodeInterRatInfoInd->interRATGsm[index].params.gsmBandIndicator,
					pLteEngmodeInterRatInfoInd->interRATGsm[index].params.bsic,
					pLteEngmodeInterRatInfoInd->interRATGsm[index].meas.rssi,
					pLteEngmodeInterRatInfoInd->interRATGsm[index].meas.srxlev);
			}
            if (1 != quec_assemble_qeng_resp(rspBuf, p))
            {
                return;
            }
		}
		//inter rat neighber cell of WCDMA
		Network_Info_Log("numInterRATUtra=%d", pLteEngmodeInterRatInfoInd->numInterRATUtra);
		for (index = 0; index < pLteEngmodeInterRatInfoInd->numInterRATUtra; index++)
		{
			//not supoort rssi,sinr so rplace with -
			if(pLteEngmodeInterRatInfoInd->interRATUtra[index].params.uArfcn ==0)
				continue;
            memset(rspBuf, 0, sizeof(rspBuf));
    		p = rspBuf;
	#ifdef __QUEC_OEM_VER_LD__
			if (TRUE == Quectel_IsOEMLandiEnable())
			{
				memset(arfcn_buf,0,sizeof(arfcn_buf));
				memset(bsic_buf,0,sizeof(bsic_buf));
				GET_VALID_VAL(bsic_buf, pLteEngmodeInterRatInfoInd->interRATUtra[index].params.psc_cellParameterId);
				GET_VALID_VAL(arfcn_buf, pLteEngmodeInterRatInfoInd->interRATUtra[index].params.uArfcn);
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%s,%d,%d,%d,%s,%d,%d,%d\r\n","neighbourcell","WCDMA",
					arfcn_buf,
					pLteEngmodeInterRatInfoInd->interRATUtra[index].params.cellReselectionPriority,
					pLteEngmodeInterRatInfoInd->interRATUtra[index].params.threshXHigh,
					pLteEngmodeInterRatInfoInd->interRATUtra[index].params.threshXLow,
					bsic_buf,
					pLteEngmodeInterRatInfoInd->interRATUtra[index].meas.rscp,
					pLteEngmodeInterRatInfoInd->interRATUtra[index].meas.cpichEcN0,
					pLteEngmodeInterRatInfoInd->interRATUtra[index].meas.srxlev);
			}
			else
	#endif	
			{
				p+=sprintf(p, "+QENG: \"%s\",\"%s\",%d,%d,%d,%d,%d,%d,%d,%d\r\n","neighbourcell","WCDMA",
					pLteEngmodeInterRatInfoInd->interRATUtra[index].params.uArfcn,
					pLteEngmodeInterRatInfoInd->interRATUtra[index].params.cellReselectionPriority,
					pLteEngmodeInterRatInfoInd->interRATUtra[index].params.threshXHigh,
					pLteEngmodeInterRatInfoInd->interRATUtra[index].params.threshXLow,
					pLteEngmodeInterRatInfoInd->interRATUtra[index].params.psc_cellParameterId,
					pLteEngmodeInterRatInfoInd->interRATUtra[index].meas.rscp,
					pLteEngmodeInterRatInfoInd->interRATUtra[index].meas.cpichEcN0,
					pLteEngmodeInterRatInfoInd->interRATUtra[index].meas.srxlev);
			}
            if (1 != quec_assemble_qeng_resp(rspBuf, p))
            {
                return;
            }
		}
	}
#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
	 else if(CHECK_BIT_SET(network_infor_bitmsk ,MCELL))
	 {
		 UINT8 cellNUM=0;
         UINT32 p_rspBuf_end = &rspBuf[0]+sizeof(rspBuf);
         
		 Network_Info_Log("numInterRATGsm=%d,numInterRATUtra=%d", 
						  pLteEngmodeInterRatInfoInd->numInterRATGsm, pLteEngmodeInterRatInfoInd->numInterRATUtra);
		 for (cellNUM = 0; cellNUM < pLteEngmodeInterRatInfoInd->numInterRATGsm; cellNUM++)
		 {
			   //check if cell msg is valid
				if((pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.mcc <=0 ||pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.mcc >0x999)
					||(pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.lac == 0)
					||(pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.ci == 0))
				{
					continue;
				}
                memset(rspBuf, 0, sizeof(rspBuf));
        		p = rspBuf;
			   p+=sprintf(p,"MCC: %x,MNC: %x,LAC: %5d,Cell ID: %9d,BSIC: %03d,(P)BCCH ARFCN: %04x,RxLev: %03x",
						 pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.mcc,
						 pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.mnc,
						 pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.lac,
						 pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.ci,
						 pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.bsic,
						 pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.arfcn,
						 pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].meas.srxlev);
			   
			   if(pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].meas.srxlev <=63  )
			   {
					p+=sprintf(p, ",RxDbm: %d\r\n", pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].meas.srxlev-111);
			   }
			   else
				{
					p+=sprintf(p, ",RxDbm: %d\r\n",63-111);
				}
                if (1 != quec_assemble_qeng_resp(rspBuf, p))
                {
                    return;
                }
	
		 }
		 for (cellNUM = 0; cellNUM < pLteEngmodeInterRatInfoInd->numInterRATUtra && p < p_rspBuf_end; cellNUM++)
		 {
			if((pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.mcc <= 0 || pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.mcc > 0x999)
				|| (pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.lac == 0)
				|| (pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.ci == 0))
			{
				continue;
			}
            memset(rspBuf, 0, sizeof(rspBuf));
    		p = rspBuf;
				
			p+=sprintf(p,"MCC: %x,MNC: %x,LAC: %5d,Cell ID: %9d,BSIC: -,(P)BCCH ARFCN: %04x,RxLev: %03x",
						 pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.mcc,
						 pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.mnc,
						 pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.lac,
						 pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.ci,
						 pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.uArfcn,
						 pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].meas.srxlev);
			 if(pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].meas.srxlev <=63	)
			 {
				p+=sprintf(p, ",RxDbm: %d\r\n", pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].meas.srxlev-111);
			 }
			 else
			 {
				p+=sprintf(p, ",RxDbm: %d\r\n",63-111);
			 }
             if (1 != quec_assemble_qeng_resp(rspBuf, p))
             {
                 return;
             }
		 }
	}
#endif	
#ifdef QUECTEL_CELL
    else if(CHECK_BIT_SET(network_infor_bitmsk ,CELL_GET))
	{
		 UINT8 cellNUM=0;
		 Network_Info_Log("[quec ncell] numInterRATGsm=%d,numInterRATUtra=%d", 
						  pLteEngmodeInterRatInfoInd->numInterRATGsm, pLteEngmodeInterRatInfoInd->numInterRATUtra);
         //gsm rat  
         for (cellNUM = 0; (cellNUM < pLteEngmodeInterRatInfoInd->numInterRATGsm) && (cellNUM < CI_DEV_LTE_MAX_CELL_GSM); cellNUM++)
		 {  
		    //check ci bsic data
		    if ( (pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.ci == NCELL_CELL_ID_MIN) ||
                 (pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.ci == NCELL_CELL_ID_MAX) ||
                 (pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.bsic == NCELL_BSIC_MAX) ||
				 (pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.mcc == NCELL_CELL_MCC_INVALID) )
            {
                continue;
            }
            /* check rssi： rxlev range: 0-63 */
            if (pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].meas.rssi > QUEC_NECLL_GSM_MAX_RSSI)
            {
                pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].meas.rssi = QUEC_NECLL_GSM_MAX_RSSI;
            }
            else if (pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].meas.rssi < QUEC_NECLL_GSM_MIN_RSSI)
            {
                pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].meas.rssi = QUEC_NECLL_GSM_MIN_RSSI;
            }
		    memset(rspBuf, 0, sizeof(rspBuf));
			p = rspBuf;
            
			p+=sprintf(p, "+QCELL: \"%s\",\"%s\",%03x,%02x,%04x,%x,%d,%d\r\n","neighbourcell","GSM",
                            pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.mcc,
                            pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.mnc,
                            pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.lac,
				            pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.ci, 
				            pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.bsic,
				            pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].meas.rssi+128); 
              
			if (1 != quec_assemble_qeng_resp(rspBuf, p))
			{
				 return;
			}
		 }
         //umts rat
		 for (cellNUM = 0; (cellNUM < pLteEngmodeInterRatInfoInd->numInterRATUtra) && (cellNUM < CI_DEV_LTE_MAX_CELL_UTRA); cellNUM++)
		 {
		    //check ci bsic data
		    if ( (pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.ci == NCELL_CELL_ID_MIN) ||
                 (pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.ci == NCELL_CELL_ID_MAX) ||
                 (pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.psc_cellParameterId == NCELL_PSC_MAX) ||
 				 (pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.mcc == NCELL_CELL_MCC_INVALID) )
            {
                continue;
            }
			memset(rspBuf, 0, sizeof(rspBuf));
			p = rspBuf;
           
			p+=sprintf(p, "+QCELL: \"%s\",\"%s\",%03x,%02x,%04x,%x,%d,%d\r\n","neighbourcell","WCDMA",
                        pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.mcc,
                        pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.mnc,
                        pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.lac,
				        pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.ci, 
				        pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.psc_cellParameterId,
				        pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].meas.srxlev); 
       	
			if (1 != quec_assemble_qeng_resp(rspBuf, p))
			{
				return;
			}
		 }
	}
#endif
#ifdef QUEC_QCELLINFO_SUPPORT
    else if(CHECK_BIT_SET(network_infor_bitmsk ,QCELLINFOEX_GET))
	{
		 UINT8 cellNUM=0;
		 Network_Info_Log("[quec qcellinfo] numInterRATGsm=%d,numInterRATUtra=%d", 
						  pLteEngmodeInterRatInfoInd->numInterRATGsm, pLteEngmodeInterRatInfoInd->numInterRATUtra);
         //gsm rat  
         for (cellNUM = 0; (cellNUM < pLteEngmodeInterRatInfoInd->numInterRATGsm) && (cellNUM < CI_DEV_LTE_MAX_CELL_GSM); cellNUM++)
		 {  
		    //check ci bsic data
		    if ( (pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.ci == NCELL_CELL_ID_MIN) ||
                 (pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.ci == NCELL_CELL_ID_MAX) ||
                 (pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.bsic == NCELL_BSIC_MAX) )
            {
                continue;
            }
		    memset(rspBuf, 0, sizeof(rspBuf));
			p = rspBuf;
            
			p+=sprintf(p, "+QCELLINFO: \"%s\",\"%s\",%03x,%02x,%04x,%x,%d,%d,%d,%d\r\n","neighbourcell","GSM",
                            pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.mcc,
                            pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.mnc,
                            pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.lac,
				            pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.ci, 
				            pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.bsic,
				            pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].meas.rssi+128,
				            pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].meas.rssi,
				            pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.arfcn);
              
			if (1 != quec_assemble_qeng_resp(rspBuf, p))
			{
				 return;
			}
		 }
         //umts rat
		 for (cellNUM = 0; (cellNUM < pLteEngmodeInterRatInfoInd->numInterRATUtra) && (cellNUM < CI_DEV_LTE_MAX_CELL_UTRA); cellNUM++)
		 {
		    //check ci bsic data
		    if ( (pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.ci == NCELL_CELL_ID_MIN) ||
                 (pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.ci == NCELL_CELL_ID_MAX) ||
                 (pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.psc_cellParameterId == NCELL_PSC_MAX) )
            {
                continue;
            }
			memset(rspBuf, 0, sizeof(rspBuf));
			p = rspBuf;
           
			p+=sprintf(p, "+QCELL: \"%s\",\"%s\",%03x,%02x,%04x,%x,%d,%d,%d,%d\r\n","neighbourcell","WCDMA",
                        pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.mcc,
                        pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.mnc,
                        pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.lac,
				        pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.ci, 
				        pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.psc_cellParameterId,
				        pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].meas.srxlev+111,
				        pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].meas.srxlev,
				        pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.uArfcn);
       	
			if (1 != quec_assemble_qeng_resp(rspBuf, p))
			{
				return;
			}
		 }
	}
#endif

#endif
	else
	{
#ifdef AT_FOR_GW20180208SN
		if(gMMZRSSI == 3)
		{
			return;
		}
#endif
		// for  Inter-RAT GSM Cells
		sprintf(rspBuf, "+EEMLTEINTERRAT:%d,%d",CI_DEV_EM_NETWORK_GSM,pLteEngmodeInterRatInfoInd->numInterRATGsm);

		for (cellNUM = 0; cellNUM < pLteEngmodeInterRatInfoInd->numInterRATGsm; cellNUM++)
		{
#ifdef QUECTEL_NETWORK_SUPPORT
            //Network_Info_Log("[Ramos] 1111 p=0x%x, rspBuf=0x%x (p-rspBuf)=0x%x ,(p-rspBuf)=%d", p, rspBuf,(p-rspBuf),(p-rspBuf));
            if(((p-rspBuf) + 100) > sizeof(rspBuf)) 
            {
                break;
            }
#endif
			// -7- mcc, mnc, lac, ci, arfcn, bsic,rssi

				sprintf(tempBuf, ",%d,%d,%d,%d,%d,%d,%d",	 pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.mcc,
				pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.mnc,
				pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.lac,
				pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.ci,
				pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.arfcn,
				pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].params.bsic,
				pLteEngmodeInterRatInfoInd->interRATGsm[cellNUM].meas.rssi);
			strcat(rspBuf, tempBuf);
		
		}
		strcat(rspBuf, "\r\n");
		ATRESP(reqHandle, 0, 0, rspBuf);
	}
	
	   if (pLteEngmodeInterRatInfoInd->numInterRATUtra > CI_DEV_LTE_MAX_CELL_UTRA)
		{
			ERRMSG("pLteEngmodeInterRatInfoInd->numInterRATUtra %d larger than CI_DEV_LTE_MAX_CELL_UTRA \r\n", pLteEngmodeInterRatInfoInd->numInterRATUtra );
		}
		else
		{
#ifdef AT_FOR_GW20180208SN
			if(gMMZRSSI == 3)
			{
				return;
			}
#endif
		// for  Inter-RAT UMTS Cells
		sprintf(rspBuf, "+EEMLTEINTERRAT:%d,%d",CI_DEV_EM_NETWORK_UMTS,pLteEngmodeInterRatInfoInd->numInterRATUtra);
		
		for (cellNUM = 0; cellNUM < pLteEngmodeInterRatInfoInd->numInterRATUtra; cellNUM++)
		{
#ifdef QUECTEL_NETWORK_SUPPORT
            //Network_Info_Log("[Ramos] 2222 p=0x%x, rspBuf=0x%x (p-rspBuf)=0x%x ,(p-rspBuf)=%d", p, rspBuf,(p-rspBuf),(p-rspBuf));
            if(((p-rspBuf) + 100) > sizeof(rspBuf)) 
            {
                break;
            }
#endif
			// -8- mcc, mnc, lac, ci, uArfcn, psc_cellParameterId,cpichEcN0
				/*Fix klocwork[Too many arguments in a print function ]*/
				snprintf(tempBuf,sizeof(tempBuf),",%d,%d,%d,%d,%d,%d,%d,%d",	 pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.mcc,
				pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.mnc,
				pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.lac,
				pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.ci,
				pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.uArfcn,
				pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].params.psc_cellParameterId,
				pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].meas.rscp,
				pLteEngmodeInterRatInfoInd->interRATUtra[cellNUM].meas.cpichEcN0);
			strcat(rspBuf, tempBuf);
		
		}
		strcat(rspBuf, "\r\n");
		ATRESP(reqHandle, 0, 0, rspBuf);
	}
	return;
}

/****************************************************************
 *  F@: processNwMonitorInfoInd - Process network monitor info
 */
static void processNwMonitorInfoInd(UINT32 reqHandle, const void *pParam)
{
	char respBuffer[255];
	CiDevPrimNetworkMonitorInfoInd *pCiDevPrimNetworkMonitorInfoInd=NULL;

	pCiDevPrimNetworkMonitorInfoInd = (CiDevPrimNetworkMonitorInfoInd*)pParam;

	memset(respBuffer, 0, sizeof(respBuffer));
	sprintf(respBuffer, "+SNETIND:%d\r\n", pCiDevPrimNetworkMonitorInfoInd->info.mode);
	ATRESP(reqHandle, 0, 0, respBuffer);
	return;
}
#endif
/****************************************************************
 *  F@: processLpNwdlMsgInfoInd - Process RRC/RRLP positioning-related
 *      message
 */
void processLpNwdlMsgInfoInd(UINT32 reqHandle, const void *pParam)
{
	char *respBuffer=NULL;//[CI_DEV_MAX_APGS_MSG_SIZE*2+50+2];
	char temp[50] = {0};
	CiDevPrimLpNwdlMsgInd *pCiDevPrimLpNwdlMsgInd=NULL;
	extern void libConvertNumToHex(char *inData, int inLen, char *outData);

	pCiDevPrimLpNwdlMsgInd = (CiDevPrimLpNwdlMsgInd *)pParam;

	if (pCiDevPrimLpNwdlMsgInd->msg_size > CI_DEV_MAX_APGS_MSG_SIZE)
	{
		return;
	}
	/* Get msg_data in HEX format */
	respBuffer = (char *)malloc(sizeof(char) * (CI_DEV_MAX_APGS_MSG_SIZE*2+50+ CI_DEV_MAX_ADD_INFO_LEN*2+2));
	if (respBuffer == NULL)
		return;

	sprintf(respBuffer, "+LPNWDL: %d,", pCiDevPrimLpNwdlMsgInd->BearerType);

	if (pCiDevPrimLpNwdlMsgInd->msg_size >= CI_DEV_MAX_APGS_MSG_SIZE)
	{
		libConvertNumToHex((char *)pCiDevPrimLpNwdlMsgInd->msg_data,
							CI_DEV_MAX_APGS_MSG_SIZE, respBuffer);
	}
	else
	{
		libConvertNumToHex((char *)pCiDevPrimLpNwdlMsgInd->msg_data,
		pCiDevPrimLpNwdlMsgInd->msg_size, respBuffer);
	}

	sprintf(temp, ",%d,%d,%d,%d,",  pCiDevPrimLpNwdlMsgInd->msg_size,
										pCiDevPrimLpNwdlMsgInd->sessionType,
										pCiDevPrimLpNwdlMsgInd->RrcState,
										pCiDevPrimLpNwdlMsgInd->count);
	strcat(respBuffer, temp);

	libConvertNumToHex((char *)pCiDevPrimLpNwdlMsgInd->additional_info,
					   pCiDevPrimLpNwdlMsgInd->additional_info_len, respBuffer);
	sprintf(temp, ",%d\r\n", pCiDevPrimLpNwdlMsgInd->additional_info_len);

	strcat(respBuffer, temp);
	ATRESP(reqHandle, 0, 0, respBuffer);
	free(respBuffer);

	return;
}

#ifndef LTEONLY_THIN	
/****************************************************************
 *	F@: processLpRRCStateInd - Process RRC/RRLP state change
 */
static void processLpRRCStateInd(UINT32 reqHandle, const void *pParam)
{
	char respBuffer[50] = {0};
	CiDevPrimLpRrcStateInd *pCiDevPrimLpRrcStateInd=NULL;

	pCiDevPrimLpRrcStateInd = (CiDevPrimLpRrcStateInd *)pParam;

	sprintf(respBuffer, "+LPSTATE:%d, %d\r\n",
										pCiDevPrimLpRrcStateInd->bearer_type,
										pCiDevPrimLpRrcStateInd->rrc_state);

	ATRESP(reqHandle, 0, 0, respBuffer);
	return;
}
#endif
/****************************************************************
 *	F@: processLpMeasTerminateInd - Erase all assistance data
 */
static void processLpMeasTerminateInd(UINT32 reqHandle, const void *pParam)
{
	char respBuffer[50] = {0};
	CiDevPrimLpMeasTerminateInd *pCiDevPrimLpMeasTerminateInd;

	pCiDevPrimLpMeasTerminateInd = (CiDevPrimLpMeasTerminateInd *)pParam;

	sprintf(respBuffer, "+LPMEAST: %d\r\n",
										pCiDevPrimLpMeasTerminateInd->bearer_type);

	ATRESP(reqHandle, 0, 0, respBuffer);
	return;
}

/****************************************************************
 *	F@: processLpResetUEPosInd - Process measurement termination
 */
static void processLpResetUEPosInd(UINT32 reqHandle, const void *pParam)
{
	char respBuffer[50] = {0};
	CiDevPrimLpResetStoreUePosInd *pCiDevPrimLpResetStoreUePosInd;

	pCiDevPrimLpResetStoreUePosInd = (CiDevPrimLpResetStoreUePosInd *)pParam;

	sprintf(respBuffer, "+LPRESET:%d\r\n",
										pCiDevPrimLpResetStoreUePosInd->bearer_type);

	ATRESP(reqHandle, 0, 0, respBuffer);
	return;
}
extern BOOL InDipChannel;
extern BOOL InDipChannel_qspi;
extern UINT32 networkmode;
/****************************************************************
 *	F@: processDIPChannelChangeInd - Process dip channel change ind
 */
static void processDIPChannelChangeInd(UINT32 indHandle, const void *pParam)
{
	char respBuffer[50];
	CiDevPrimDipChannelChangeInd *pCiDevPrimDipChannelChangeInd=NULL;

	pCiDevPrimDipChannelChangeInd = (CiDevPrimDipChannelChangeInd *)pParam;

	memset(respBuffer, 0, sizeof(respBuffer));
	

	sprintf(respBuffer, "+DIP:%d,%d,%d,%d\r\n", pCiDevPrimDipChannelChangeInd->band,
		pCiDevPrimDipChannelChangeInd->arfcn, pCiDevPrimDipChannelChangeInd->servicetype, pCiDevPrimDipChannelChangeInd->networkMode);
    if(!ifPsramLimit200M() && (pCiDevPrimDipChannelChangeInd->networkMode == 3) && (pCiDevPrimDipChannelChangeInd->band == 3) \
        && (pCiDevPrimDipChannelChangeInd->arfcn >= 1377) && (pCiDevPrimDipChannelChangeInd->arfcn <= 1761))
    {
        InDipChannel = TRUE;
    }
    else if(ifPsramLimit200M() && (pCiDevPrimDipChannelChangeInd->networkMode == 3) && (pCiDevPrimDipChannelChangeInd->band == 5) \
        && (pCiDevPrimDipChannelChangeInd->arfcn >= 2407) && (pCiDevPrimDipChannelChangeInd->arfcn <= 2643))
    {       
        InDipChannel = TRUE;
    }
    else if(ifPsramLimit200M() && (pCiDevPrimDipChannelChangeInd->networkMode == 3) && (pCiDevPrimDipChannelChangeInd->band == 41) \
        && (pCiDevPrimDipChannelChangeInd->arfcn >= 40970) && (pCiDevPrimDipChannelChangeInd->arfcn <= 41070))
    {       
        InDipChannel = TRUE;
    }
    else if((pCiDevPrimDipChannelChangeInd->networkMode == 3) && (pCiDevPrimDipChannelChangeInd->band == 20) \
        && (pCiDevPrimDipChannelChangeInd->arfcn >= 6350) && (pCiDevPrimDipChannelChangeInd->arfcn <= 6449))
    {       
        InDipChannel_qspi = TRUE;
    }
    else if(!ifPsramLimit200M() && (pCiDevPrimDipChannelChangeInd->networkMode == 0) && (pCiDevPrimDipChannelChangeInd->band == 1) \
        && (pCiDevPrimDipChannelChangeInd->arfcn >= 636) && (pCiDevPrimDipChannelChangeInd->arfcn <= 772))
    {       
        InDipChannel = TRUE;
    }
    else
    {   
        InDipChannel = FALSE;
        InDipChannel_qspi = FALSE;
    }
    networkmode = pCiDevPrimDipChannelChangeInd->networkMode;

	ATRESP(indHandle, 0, 0, respBuffer);
	return;
}

#ifndef LTEONLY_THIN
/****************************************************************
 *	F@: processCurrentAMRCodecInd - Process current AMR codec ind
 */
static void processCurrentAMRCodecInd(UINT32 indHandle, const void *pParam)
{
	char respBuffer[50];
	CiDevPrimCurrentAmrCodecInd *pCiDevPrimCurrentAmrCodecInd=NULL;

	pCiDevPrimCurrentAmrCodecInd = (CiDevPrimCurrentAmrCodecInd *)pParam;

	memset(respBuffer, 0, sizeof(respBuffer));
	
	if(pCiDevPrimCurrentAmrCodecInd->codecType < CI_DEV_NUM_OF_CODEC_TYPES)
	{
		sprintf(respBuffer, "*AMRCODEC:%d,%d\r\n", pCiDevPrimCurrentAmrCodecInd->codecType,pCiDevPrimCurrentAmrCodecInd->speechCodecRate);
		 ATRESP(indHandle, 0, 0, respBuffer);
	}
	else
		DBGMSG("%s: invalid AMR codec type %d\n", pCiDevPrimCurrentAmrCodecInd->codecType);
	return;
}
/****************************************************************
 *	F@: processLteCoexInfoInd - Process lte coex info ind
 */
static void processLteCoexInfoInd(UINT32 indHandle, const void *pParam)
{
	char respBuffer[100];
	char tmpBuf[50];

	CiDevPrimLteCoexInfoInd *pCiDevPrimLteCoexInfoInd=NULL;

	memset(respBuffer, 0, sizeof(respBuffer));
	memset(tmpBuf, 0, sizeof(tmpBuf));
	
	pCiDevPrimLteCoexInfoInd = (CiDevPrimLteCoexInfoInd *)pParam;
	snprintf(respBuffer, utlNumberOf(respBuffer), "*LTECOEX:%d,%d,%d,%d", pCiDevPrimLteCoexInfoInd->isLteOn,
			pCiDevPrimLteCoexInfoInd->rrcState, pCiDevPrimLteCoexInfoInd->lteBand, pCiDevPrimLteCoexInfoInd->earfcn);

	if(pCiDevPrimLteCoexInfoInd->tddSubframeConfigPresent)
	{
		snprintf(tmpBuf, utlNumberOf(tmpBuf), ",%d,%d", pCiDevPrimLteCoexInfoInd->tddUlDlConfig, pCiDevPrimLteCoexInfoInd->tddSpecialSubframeConfig);
		strlcat(respBuffer, tmpBuf, utlNumberOf(respBuffer));
	}
	else
		strlcat(respBuffer, ",,", utlNumberOf(respBuffer));


	if(pCiDevPrimLteCoexInfoInd->longDRXCyclePresent)
	{
		snprintf(tmpBuf, utlNumberOf(tmpBuf), ",%d", pCiDevPrimLteCoexInfoInd->longDRXCycle);
		strlcat(respBuffer, tmpBuf, utlNumberOf(respBuffer));
	}
	else
		strlcat(respBuffer, ",", utlNumberOf(respBuffer));

	if(pCiDevPrimLteCoexInfoInd->shortDRXCyclePresent)
	{
		snprintf(tmpBuf, utlNumberOf(tmpBuf), ",%d", pCiDevPrimLteCoexInfoInd->shortDRXCycle);
		strlcat(respBuffer, tmpBuf, utlNumberOf(respBuffer));
	}
	else
		strlcat(respBuffer, ",", utlNumberOf(respBuffer));

	strlcat(respBuffer, "\r\n", utlNumberOf(respBuffer));
	ATRESP( indHandle, 0, 0, respBuffer);

	return;
}

#ifdef PLATFORM_FOR_PS_LW

/****************************************************************
 *	F@: process23GRBTestLoopbackModeInd - RB Test Loopback Mode status
 */
static void processRBTestLoopbackModeInd(UINT32 indHandle, const void *pParam)
{


	CiDevPrimRbTestModeInd *pCiDevPrimRbTestModeInd=NULL;
	char respBuffer[50];
	memset(respBuffer, 0, sizeof(respBuffer));

	pCiDevPrimRbTestModeInd = (CiDevPrimRbTestModeInd *)pParam;	
	 // 0: RB test mode stop; 1: RB test mode start
	snprintf(respBuffer, sizeof(respBuffer),"*RBLOOP:%d\r\n", pCiDevPrimRbTestModeInd->rbModeStatus);

	ATRESP(indHandle, 0, 0, respBuffer);  

	return;
}
#endif
/****************************************************************
 *	F@: processT323Ind - Process T323 Indication
 */
static void processT323Ind(UINT32 indHandle, const void *pParam)
{
	CiDevPrimT323Ind *t323Ind;
	char respBuffer[50];
	t323Ind = (CiDevPrimT323Ind *)pParam;

	snprintf(respBuffer, sizeof(respBuffer), "*TIMERTWT:%d", t323Ind->t323Valid);
	ATRESP(indHandle, 0, 0, respBuffer);
	return;
}
#endif
#ifdef AGPS_ENABLE

/****************************************************************
 *	F@: processLpOtdoaMeasInd - Process signaling report
 */
static void processLpOtdoaMeasInd(UINT32 indHandle, const void *pParam)
{
	char *pRspBuf;
	int paramlen;
	CiDevPrimLpOtdoaMeasInd *pCiDevOtdoaMeasInd = (CiDevPrimLpOtdoaMeasInd *)pParam;

	pRspBuf = (char* )malloc(20 + sizeof(CiDevPrimLpOtdoaMeasInd) * 2 + 4);
	if(pRspBuf == NULL)
		return;
	
	pRspBuf[0] = '\0';
	sprintf(pRspBuf,"+LPOTDOAMEAS:%d,\"", pCiDevOtdoaMeasInd->networkType);

	paramlen = sizeof(CiDevOtdoaInfo);
	libConvertNumToHex((char*)&pCiDevOtdoaMeasInd->info, paramlen, pRspBuf);
	strcat(pRspBuf, "\"");
	ATRESP( indHandle, 0, 0, pRspBuf);
	free(pRspBuf);
	return;
}

void processRetrieveLocationInd(UINT32 indHandle,const void *paras)
{
	char respBuffer[50];
    //build resp struct

	CiDevPrimRetrieveLocationInd *retrievelocationind = (CiDevPrimRetrieveLocationInd *)paras;

    //call gps callback func to fill available location service info
	sprintf(respBuffer, "*LPLOCR:%d\r\n",retrievelocationind->seqNum);

    ATRESP( indHandle, 0, 0, respBuffer);
    //response RESP cimsg back to CP
	return;
}
#endif

#ifdef ENABLE_WIFI_SCAN 

#ifdef QUEC_USB_QWIFISCAN_SUPPORT
extern uint32 qSortEnValue;
extern uint32 qMaskValue;
extern uint32 qWifiScanEn;
extern uint32 wifi_Handle;
extern UINT8 g_wifi_rsp_flag;
extern wifiScanCache_t wifiScanCallBackCache;
extern quec_wifiscan_callback wifiscan_callback;
extern unsigned char sendWifiscanUrcFlag;

enum WifiScanMode{
	WIFI_ECN_SHOW_MODE=0x01,
	WIFI_SSID_SHOW_MODE=0x02,
	WIFI_RSSI_SHOW_MODE=0x04,
	WIFI_MAC_SHOW_MODE=0x08,
	WIFI_CHANNEL_SHOW_MODE=0x10
}WifiScanShowMode;
extern void quec_wifiscan_release(void);
extern int  quec_loac_get_wifi_band_state(void);
extern void  quec_loac_wifi_request(char *ptrmac, char *ptrrssi, int num);

static void quec_libConvertNumToHex(char *inData, int inLen, char *outData)
{
    int i=0;
    char tmpBuf[10];
	memset(tmpBuf, 0, sizeof(tmpBuf));

    if ((NULL == inData) || (NULL == outData))
    {
        return;
    }

    if (inLen > 0)
    {
		for ( i = 0; i < inLen; i++ )
		{
			if(qWifiScanEn){
				if(i==inLen-1){
					sprintf( tmpBuf, "%02X", inData[i] );
				}else{
			        sprintf( tmpBuf, "%02X:", inData[i] );
				}
			}else{
				sprintf( tmpBuf, "%02X", inData[i] );
			}
				strcat( outData, tmpBuf );
		}
    }
}
/*AT+QLBS=1 成功获取WIFI扫频地址后,调用此函数发送消息,向服务器请求定位*/
void quec_loac_proc_wifiinfo(const void *paras)
{
	UINT8 bssid_num = 0;
	int index = 0;
	UINT8			   wifiMac[6][18];
	INT16			   wifiRssi[6];/*注意大小和类型要和一致quectel_apptcpip_qcellloc_cmd_info,直接内存拷贝*/
	WFScanInd_ts *wifiHotspotInfoInd = (WFScanInd_ts *)paras;
	CPUartLogPrintf("lbs wifi%s","in");
	memset(&wifiMac[0], 0, sizeof(wifiMac));
	memset(&wifiRssi[0], 0, sizeof(wifiRssi));
	CPUartLogPrintf("size=%d,%d",sizeof(wifiMac),sizeof(wifiRssi));
	bssid_num = wifiHotspotInfoInd->bssid_number;
	if(bssid_num > 6) 
		bssid_num = 6;
	for(index = 0; index < bssid_num; index++ )
	{
		/*取mac地址*/
		quec_libConvertNumToHex((char*)wifiHotspotInfoInd->channelCellList[index].bssid, sizeof(wifiHotspotInfoInd->channelCellList[index].bssid), (char *)&wifiMac[index]);
		wifiRssi[index] = wifiHotspotInfoInd->channelCellList[index].rssi;
		
		CPUartLogPrintf("%s, lbs_log mac=%s, rssi=%d",__FUNCTION__,wifiMac[index],wifiRssi[index]);
	}
	/*清零状态*/
	quec_loac_set_wifi_band_state(0);
	CPUartLogPrintf("wifi exit done. line=%d",__LINE__);
	
#ifdef FEATURE_QUECTEL_LOCATOR_APP
	/*发送消息,开始想服务器请求经纬度信息*/
	quec_loac_wifi_request((char *)wifiMac, (char *)wifiRssi, bssid_num);
#endif
}

BOOL bwifiscan_repeat_flag = FALSE;


#ifdef QUEC_PATCH_3601_WIFISCAN_BUG_18654
//ICAT EXPORTED ENUM
typedef enum {
	Ps_High =0,
	Wifi_High
}ScanPriority_te;


//ICAT EXPORTED STRUCT
typedef struct{
	
	UINT8 ScanRoundNum;  //from 1 to 3. and the default value is 3 
	UINT8 ScanMaxBssidNum; //from 4 to 10, and the default value is 5 
	UINT8 ScanTimeout;  // uint:second and the default value is 25s
	ScanPriority_te ScanPriority; //the prioprity of PS and wifi
}MMWFScanStartReq_ts;


extern MMWFScanStartReq_ts wifiScanCfg;
extern wifiScanCache_t wifiScanCache;
extern void MM2WifiStartScanReqExt(MMWFScanStartReq_ts* MMWFScanStartReqParam);;
extern void MM2WifiStopScanReq(void);
extern QuecOSStatus quec_wifiscan_traffic_statistics_timer_start(uint32 init_time, bool cyclical_enable, void(* callback_routine)(void), uint32 timer_argc);
#endif

#define QUEC_COMPARE_RSSI_VALUE(a,b) ( ((a)>(b)) ? ((a)-(b)) : ((b)-(a)) )
#define QUEC_RSSI_ADJACENT_THRESHOLD  8

typedef struct{
  BOOL  valid_flag;
  UINT32 relevant_index;
}channelCellList;

void quec_wifiscan_traffic_statistics_timer_callback(void)
{
    quec_ipr_msg_s  ipr_msg={0,0};
    quec_send_msg_to_handle_task(QUEC_WIFISCAN_TRAFFIC_STATICS_MSG, (char*)&ipr_msg, sizeof(ipr_msg));
}


/* 填充mac地址，当wifiscan扫描的mac地址数量不够时，判断同一个mac的信号差值是否在一定范围内，如果在，认为在相近位置。从上一次 扫描的mac中选择信号好的填充 */
void quec_wifi_mac_pad(WFScanInd_ts *wifiHotspotInfoInd, UINT8 bssid_diff_threshold)
{
    static WFScanInd_ts tmpWifiHotspotInfoInd;
    UINT8 bssid_index = 0;
    UINT8 tmp_bssid_index = 0;
    UINT8 pad_bssid_index = 0;
    UINT8 pad_bssid_num = 0;
    UINT8 i = 0;
    UINT8 j = 0;
    BOOL mac_equal_flag = FALSE;
    channelCellList tmp_same_mac_channelCellList[MAX_BSSID_NUM_TOTAL];
    char macBuf[50];
    char tmp_macBuf[50];
    channelCellInfo_ts tmp;

    tmp_bssid_index = tmpWifiHotspotInfoInd.bssid_number;

    memset(&tmp_same_mac_channelCellList, 0, sizeof(tmp_same_mac_channelCellList));
    memset(macBuf, 0, sizeof(macBuf));
    memset(tmp_macBuf, 0, sizeof(tmp_macBuf));
    memset(&tmp, 0, sizeof(tmp));
    if(NULL == wifiHotspotInfoInd)
    {
        CPUartLogPrintf("wifiHotspotInfoInd is a null pointer");
        return;
    }
    pad_bssid_num = wifiScanCfg.ScanMaxBssidNum - wifiHotspotInfoInd->bssid_number;
    if((wifiHotspotInfoInd->bssid_number < wifiScanCfg.ScanMaxBssidNum) && (tmpWifiHotspotInfoInd.bssid_number > 0))
    {
        for(bssid_index = 0; bssid_index < wifiHotspotInfoInd->bssid_number; bssid_index++)
        {
            memset(macBuf, 0, sizeof(macBuf));
            quec_libConvertNumToHex((char*)wifiHotspotInfoInd->channelCellList[bssid_index].bssid, sizeof(wifiHotspotInfoInd->channelCellList[bssid_index].bssid), macBuf);
            tmp_bssid_index = tmpWifiHotspotInfoInd.bssid_number;
            while(tmp_bssid_index)
            {
                memset(tmp_macBuf, 0, sizeof(tmp_macBuf));
                quec_libConvertNumToHex((char*)tmpWifiHotspotInfoInd.channelCellList[tmp_bssid_index - 1].bssid, sizeof(tmpWifiHotspotInfoInd.channelCellList[tmp_bssid_index - 1].bssid), tmp_macBuf);
                if(strncmp((char*)macBuf, (char*)tmp_macBuf, 17) == 0 \
                    && (QUEC_COMPARE_RSSI_VALUE((wifiHotspotInfoInd->channelCellList[bssid_index].rssi), (tmpWifiHotspotInfoInd.channelCellList[tmp_bssid_index - 1].rssi)) <= bssid_diff_threshold ))
                {
                    /* 标记相同的mac地址 */
                    tmp_same_mac_channelCellList[tmp_bssid_index - 1].valid_flag = TRUE; 
                    tmp_same_mac_channelCellList[tmp_bssid_index - 1].relevant_index = bssid_index;
                    mac_equal_flag = TRUE;
                }
                tmp_bssid_index--;
            }
        }

        if(TRUE == mac_equal_flag)
        {
            for(tmp_bssid_index = 0; tmp_bssid_index < (wifiHotspotInfoInd->bssid_number + pad_bssid_num); tmp_bssid_index++)
            {
                if((FALSE == tmp_same_mac_channelCellList[tmp_bssid_index].valid_flag) \
                    && (pad_bssid_index < pad_bssid_num) \
                    && (tmp_bssid_index < MAX_BSSID_NUM_TOTAL) \
                    && (tmpWifiHotspotInfoInd.channelCellList[tmp_bssid_index].rssi != 0))
                {
                    /* 填充不够的mac地址 */
                    wifiHotspotInfoInd->channelCellList[wifiHotspotInfoInd->bssid_number + pad_bssid_index] = tmpWifiHotspotInfoInd.channelCellList[tmp_bssid_index];
                    pad_bssid_index++;
                    CPUartLogPrintf("quec_wifi_mac_pad bssid_number = %d pad_bssid_index=%d pad_bssid_num = %d", wifiHotspotInfoInd->bssid_number , pad_bssid_index, pad_bssid_num);
                }
            }
            wifiHotspotInfoInd->bssid_number += pad_bssid_index;
            /* 按照信号值由强到弱排序 */
            for (i=0;i< wifiHotspotInfoInd->bssid_number;i++)
            {
                for(j=0;j< wifiHotspotInfoInd->bssid_number-i-1;j++)
                {
                    if (wifiHotspotInfoInd->channelCellList[j].rssi < wifiHotspotInfoInd->channelCellList[j+1].rssi)
                    {
                        tmp = wifiHotspotInfoInd->channelCellList[j];
                        wifiHotspotInfoInd->channelCellList[j] = wifiHotspotInfoInd->channelCellList[j+1];
                        wifiHotspotInfoInd->channelCellList[j+1] = tmp;
                    }
                }
            }        
        }
    }
    else
    {
        tmpWifiHotspotInfoInd = *wifiHotspotInfoInd;
    }
}
void _processWifiHotspotInfoInd(const void *paras)
{
	char macBuf[50];
	char *respBuffer = NULL;
	WFScanInd_ts *wifiHotspotInfoInd = (WFScanInd_ts *)paras;
	UINT8 bssid_num;

#ifdef QUEC_USB_QWIFISCAN_SUPPORT
	char tmp_str[60];
    QuecOSStatus ret = 0;
    static BOOL bwifiscan_repeat_flag = FALSE;
    UINT8 hot_Spot_Num = 0;;
	CPUartLogPrintf("wifi bssid_number=%d,%s",wifiHotspotInfoInd->bssid_number,"in");

    if((wifiHotspotInfoInd->bssid_number > 0))
    {
        quec_wifi_mac_pad(wifiHotspotInfoInd, QUEC_RSSI_ADJACENT_THRESHOLD);
    }

	if(2 == quec_loac_get_wifi_band_state())
	{
		quec_loac_proc_wifiinfo(paras);/*AT+QLBS=1*/
		return;
	}
	
    respBuffer = (char* )malloc(WIFISCAN_IND_BUFFER_LEN);
    if(NULL == respBuffer)
    {
        Network_Info_Log("processWifiHotspotInfoInd maclloc failed");
        return;
    }
    memset(respBuffer,0,WIFISCAN_IND_BUFFER_LEN);
    for(bssid_num = 0; bssid_num < wifiHotspotInfoInd->bssid_number ;bssid_num++ )
    {
        //CPUartLogPrintf("respBuffer=%s","for");
        memset(macBuf,0,sizeof(macBuf));
        memset(tmp_str,0,sizeof(tmp_str));
        quec_libConvertNumToHex((char*)wifiHotspotInfoInd->channelCellList[bssid_num].bssid, sizeof(wifiHotspotInfoInd->channelCellList[bssid_num].bssid), macBuf);
        if(quec_loac_get_wifi_band_state())
        {
            memset(tmp_str,0,sizeof(tmp_str));
            if ((wifiHotspotInfoInd->channelCellList[bssid_num].bssid[0] == 0x00) && (wifiHotspotInfoInd->channelCellList[bssid_num].bssid[1] == 0x00) && (wifiHotspotInfoInd->channelCellList[bssid_num].bssid[2] == 0x00)\
                && (wifiHotspotInfoInd->channelCellList[bssid_num].bssid[3] == 0x00) && (wifiHotspotInfoInd->channelCellList[bssid_num].bssid[4] == 0x00) && (wifiHotspotInfoInd->channelCellList[bssid_num].bssid[5] == 0x00))
            {
				CPUartLogPrintf("processWifiHotspotInfoInd, invalid mac");
				continue;
			}
			if(strstr(respBuffer,macBuf) != NULL)
			{
				CPUartLogPrintf("processWifiHotspotInfoInd, repeated mac");
                continue;
            }
            hot_Spot_Num++;
            sprintf(tmp_str, "+QWIFISCAN: (-,-,%d,\"%s\",%d)\r\n",wifiHotspotInfoInd->channelCellList[bssid_num].rssi,macBuf,wifiHotspotInfoInd->channelCellList[bssid_num].channel_number);
            //CPUartLogPrintf("respBuffer=%s",tmp_str);
        }
        strcat(respBuffer,tmp_str);
        if(hot_Spot_Num == wifiScanCfg.ScanMaxBssidNum)
        {
            break;
        }
    }
    if(quec_loac_get_wifi_band_state() && (wifiHotspotInfoInd->bssid_number > 0))
    {
        memset(wifiScanCache.respTempBuffer, 0, sizeof(wifiScanCache.respTempBuffer));
        wifiScanCache.hot_Spot_Num = hot_Spot_Num;
        strncpy(wifiScanCache.respTempBuffer, respBuffer, strlen(respBuffer));
    }
    CPUartLogPrintf("hot_Spot_Num=%d, %d\r\n",hot_Spot_Num, quec_loac_get_wifi_band_state());
    if(quec_loac_get_wifi_band_state())
    {
        if((strlen(macBuf) == 17) && (hot_Spot_Num == wifiScanCfg.ScanMaxBssidNum))        
        {
            if(1 == sendWifiscanUrcFlag)
            {
            	strcat(respBuffer, "\r\nOK\r\n");
            	at_urc_send(NUM_OF_TEL_ATP, (uint8*)respBuffer, strlen(respBuffer), FALSE, URC_OUT_METHOD_UNICAST, NULL);
            }
			else 
            {
                if (wifiscan_callback != NULL)
                {
                    memset(&wifiScanCallBackCache, 0, sizeof(wifiScanCallBackCache));
                    wifiScanCallBackCache.hot_Spot_Num = hot_Spot_Num;
                    strncpy(wifiScanCallBackCache.respTempBuffer, respBuffer, strlen(respBuffer));
    			    wifiscan_callback(wifiScanCallBackCache.hot_Spot_Num, (const char *)wifiScanCallBackCache.respTempBuffer);
    		    }
            }
            quec_loac_set_wifi_band_state(0);
            quec_wifiscan_release();/*成功执行,销毁定时器*/
        }
        else
        {
            quec_wifiscan_traffic_statistics_timer_start(1000, TRUE, quec_wifiscan_traffic_statistics_timer_callback, 0); 
        }      
    }
    
#else
    respBuffer = (char* )malloc(WIFISCAN_IND_BUFFER_LEN);
    if(NULL == respBuffer)
    {
        Network_Info_Log("processWifiHotspotInfoInd maclloc failed");
        return;
    }
    for(bssid_num = 0; bssid_num < wifiHotspotInfoInd->bssid_number;bssid_num++ )
    {
        memset(respBuffer,0,WIFISCAN_IND_BUFFER_LEN);
        memset(macBuf,0,sizeof(macBuf));

        quec_libConvertNumToHex((char*)wifiHotspotInfoInd->channelCellList[bssid_num].bssid, sizeof(wifiHotspotInfoInd->channelCellList[bssid_num].bssid), macBuf);
        sprintf(respBuffer, "*WIFICELLINFO: \"%s\",%d, %d\r\n",macBuf,
            wifiHotspotInfoInd->channelCellList[bssid_num].rssi,wifiHotspotInfoInd->channelCellList[bssid_num].channel_number);
        

        ATRESP( IND_REQ_HANDLE, 0, 0, respBuffer);
    //  ATRESP( IND_REQ_HANDLE_1, 0, 0, respBuffer);
    }

    
    ATRESP(IND_REQ_HANDLE, 0, 0, "*WIFICELLINFO: ,0, 0\r\n");
//  ATRESP(IND_REQ_HANDLE_1, 0, 0, "*WIFICELLINFO: ,0, 0\r\n");

#endif
    if(NULL != respBuffer)
    {
        free(respBuffer);
    }

    return;
}
#endif /*QUEC_USB_QWIFISCAN_SUPPORT*/

#endif

#ifdef QUEC_BLACK_CELL_SUPPORT

UINT8 quec_oneshot_type = 0;// 0-success 1-reject 2-timeout

void quec_set_oneshot_type(UINT8 type)
{
    quec_oneshot_type = type;
}

// 0-success 1-reject 2-timeout 3-rrcnotreceive
UINT8 quec_get_oneshot_type(void)
{
    return quec_oneshot_type;
}

#endif

#if defined(QUEC_BLACK_CELL_SUPPORT)|| defined(QUEC_THIN_BLACK_CELL_SUPPORT)
UINT8 quec_oneshot_flag = FALSE; 
void quec_set_oneshot_flag(UINT8 flag)
{
    quec_oneshot_flag = flag;
}
UINT8 quec_get_oneshot_flag(void)
{
    return quec_oneshot_flag;
}

void quec_send_oneshot_get_cellid(UINT8 type)
{
    CiReturnCode ret = CIRC_FAIL;

	if(quec_get_oneshot_flag() == TRUE)
    {
    	Network_Info_Log("quec_black: oneshot_flag=TRUE, not send oneshot");
		return;
	}
	
    if (CI_DEV_COMMON_REPORT_EMM == type)
    {
        {
            ret = DEV_GetEngModeInfo(MAKE_AT_HANDLE(TEL_AT_CMD_ATP_BLACKCELL), CI_DEV_ENGINEER_MODE_ONESHOT);
            if (ret != CIRC_SUCCESS)
            {
                Network_Info_Log("quec_black:ret is %d,send oneshot failed",ret);
            }
            else 
            {
                quec_set_oneshot_flag(TRUE);
            }
        }
    }
    else 
    {
        Network_Info_Log("quec_black:type=%d not send oneshot",type);
    }
    return;
}
#endif
/****************************************************************
 *	20200417,harley quec_process_lte_report_ind - Process lte reject info
 */
#ifdef QUEC_QSCLKEX_ENABLE
/*
    20200417,harley,VERY IMPORTANT STATEMENT: this is a special customization for Quectel only(developed by ASR Li Lei)
    this IND is reported only when LTE attach reject happens. 
*/

// destin 2020.10.28 esm reject cause code start
#ifdef QUEC_CEER_ESM_REJECT_CAUSE_SUPPORT
extern char gErrCauseBuf[256];
#ifndef LTEONLY_THIN_SINGLE_SIM
extern char gErrCauseBuf_1[256];
#endif

#define EMM_ERROR "EMM"
#define ESM_ERROR "ESM"

/* +CEER Error lookup tables */
#define DSAT_CEER_MAX_ERROR_MSG_LEN 44
#define DSAT_CEER_LIST_TERMINATOR  (-2)

/* PS lte esm cause lookup */
const ceer_lookup_s_type ceer_ps_lte_cause_codes[] =
{
    { (INT16)NAS_ESM_OPTR_DETERMINED_BARRING,                    "Operator determined barring" },
    { (INT16)NAS_ESM_INSUFFICIENT_RESOURCES,                     "Insufficient Resources" },
    { (INT16)NAS_ESM_UNKNOWN_MISSING_APN,                        "Missing or unknown APN" },
    { (INT16)NAS_ESM_UNKNOWN_PDN_TYPE,                           "Unknown PDP address or PDP type" },
    { (INT16)NAS_ESM_USER_AUTHENTICATION_FAILED,                 "User Aauthentication faile" },
    { (INT16)NAS_ESM_OPN_REJ_SERVICING_GW_OR_PDN_GW,             "Activation rejected by Servicing GW or PDN GW" },
    { (INT16)NAS_ESM_ACTIVATION_REJECTED,                        "Activation rejected, unspecified" },
    { (INT16)NAS_ESM_SERV_OPT_NOT_SUPPORTED,                     "Service option not supported" },
    { (INT16)NAS_ESM_REQ_SERV_OPT_NOT_SPECIFIED,                 "Requested service option not subscribed" },
    { (INT16)NAS_ESM_SERV_OPT_TEMP_OUT_OF_ORDER,                 "Service option temporarily out of order" },
    { (INT16)NAS_ESM_PTI_ALREADY_IN_USE,                         "PTI already In use" },
    { (INT16)NAS_ESM_REGULAR_DEACTIVATION,                       "Regular deactivation" },
    { (INT16)NAS_ESM_EPS_QOS_NOT_ACCEPTED,                       "QoS not accepted" },
    { (INT16)NAS_ESM_NETWORK_FAILURE,                            "Network failure" },
    { (INT16)NAS_ESM_REACTIVATION_REQUIRED,                      "Reactivation required" },
    { (INT16)NAS_ESM_FEATURE_NOT_SUPPORTED,                      "Feature not supported" },
    { (INT16)NAS_ESM_SEMANTIC_ERR_IN_TFT_OPERATION,              "Semantic error in the TFT operation" },
    { (INT16)NAS_ESM_SYNTACTICAL_ERR_IN_TFT_OPERATION,           "Syntactical error in the TFT operation" },
    { (INT16)NAS_ESM_UNKNOWN_EPS_BEARER_CONTEXT,                 "Unknown Bearer context" },
    { (INT16)NAS_ESM_SYMANTIC_ERR_IN_PKT_FILTER,                 "Semantic errors in packet filter" },
    { (INT16)NAS_ESM_SYNTACTICAL_ERR_IN_PKT_FILTER,              "Syntactical errors in packet filter" },
    { (INT16)NAS_ESM_EPS_BEARER_CONT_WO_TFT_ALREADY_ACT,         "Bearer Context without TFT already Active" },
    { (INT16)NAS_ESM_PTI_MISMATCH,                               "PTI mismatch" },
    /* This is not in the standard in table 9.9.4.4.1, but
       is referred to in section 7.3 of the standard */
    { (INT16)NAS_ESM_LAST_PDN_DISCONNECTED_NOT_ALLOWED,          "PDN disconnected ,Not allowed" },
    { (INT16)NAS_ESM_PDN_TYPE_IPV4_ONLY_ALLOWED,                 "PDN type IPV4 only Allowed" },
    { (INT16)NAS_ESM_PDN_TYPE_IPV6_ONLY_ALLOWED,                 "PDN type IPV6 only Allowed" },
    { (INT16)NAS_ESM_SINGLE_ADR_BEARERS_ONLY_ALLOWED,            "Single ADR bearers only Allowed" },
    { (INT16)NAS_ESM_ESM_INFO_NOT_RECEIVED,                      "ESM info not recieved" },
    { (INT16)NAS_ESM_PDN_CONN_DOES_NOT_EXIST,                    "PDN connection does not exist" },
    { (INT16)NAS_ESM_MULTIPLE_PDN_CONN_FOR_GIVEN_APN_NOT_ALLOWED,"Multiple PDN connection for given APN not allowed" },
    { (INT16)NAS_ESM_COLLISION_WITH_NW_INIT_REQ,                 "Collision with network init request" },
    { (INT16)NAS_ESM_UNSUPPORTED_QCI_VALUE,                      "Unsupported QCI value" },
    /* 60 65 66 not in this table before */    
    { (INT16)NAS_ESM_BEARER_HANDLING_NOT_SUPPORTED,              "Bearer handling not supported" }, 
    { (INT16)NAS_ESM_MAX_PDP_CONTEXT_REACHED,                    "Maximum number of EPS bearers reached" }, 
    { (INT16)NAS_ESM_APN_NOT_SUPPORTED_IN_PLMN_RAT_COMBINATION,  "Requested APN not supported in current RAT and PLMN combination" }, 
        
    { (INT16)NAS_ESM_INVALID_PTI_VALUE,                          "Invalid PTI value" },
    { (INT16)NAS_ESM_SYMANTICALLY_INVALID_MSG,                   "Symantically invalid message" },
    { (INT16)NAS_ESM_INVALID_MANDATORY_INFORMATION,              "Invalid mandatory information" },
    { (INT16)NAS_ESM_MSG_TYPE_NON_EXISTANT,                      "Message non-existent/not implemented" },
    { (INT16)NAS_ESM_MSG_TYPE_INCOMPATIBLE_PROT_STATE,           "Message type not compatible with state" },
    { (INT16)NAS_ESM_INFO_ELEMENT_NON_EXISTANT,                  "Info Elemant non existent" },
    { (INT16)NAS_ESM_CONDITIONAL_IE_ERR,                         "Conditional IE error" },
    { (INT16)NAS_ESM_MSG_INCOMPATIBLE_WITH_PRO_STATE,            "Message type not compatible with state" },
    { (INT16)NAS_ESM_PROTOCOL_ERROR,                             "Protocol error, unspecified" },
    { (INT16)NAS_ESM_APN_RESTRICT_VAL_INCOMPAT_WITH_ACT_CONTEXT, "APN restrict value incompatible with ACT context" },
    { (INT16)NAS_ESM_NO_FAILURE,                                 "No Failure" },

    { DSAT_CEER_LIST_TERMINATOR,                                  "" }
};

/* isaac 20210101 support ps emm cause ：lte attach reject cause*/

const ceer_lookup_s_type ceer_emm_attach_reject_codes[] =
{
    { (INT16)LTE_NAS_IMSI_UNKNOWN_IN_HSS,                           "IMSI unknown in HSS" },
    { (INT16)LTE_NAS_ILLEGAL_UE,                                    "Illegal UE" },
    { (INT16)LTE_NAS_IMSI_UNKNOWN_IN_VLR,                           "IMSI unknown in VLR" },
    { (INT16)LTE_NAS_IMEI_NOT_ACCEPTED,                             "IMEI not acceplted"  },
    { (INT16)LTE_NAS_ILLEGAL_ME,                                    "Illegal ME" },
    { (INT16)LTE_NAS_EPS_SERVICES_NOT_ALLOWED,                      "EPS services not allowed" },
    { (INT16)LTE_NAS_EPS_SERVICES_AND_NON_EPS_SERVICES_NOT_ALLOWED, "EPS services and non-EPS services not allowed" },
    { (INT16)LTE_NAS_UE_ID_CANNOT_BE_DERIVED_BY_NW,                 "UE identity cannot be derived by the network" },
    { (INT16)LTE_NAS_IMPLICITLY_DETACHED,                           "Implicitly detached" },
    { (INT16)LTE_NAS_PLMN_NOT_ALLOWED,                              "PLMN not allowed" },
    { (INT16)LTE_NAS_TRACKING_AREA_NOT_ALLOWED,                     "Tracking area not allowed" },
    { (INT16)LTE_NAS_ROAMING_NOT_ALLOWED_IN_THIS_TRACKING_AREA,     "Roaming not allowed in this tracking area" },
    { (INT16)LTE_NAS_EPS_SERVICES_NOT_ALLOWED_IN_PLMN,              "EPS services not allowed in this PLMN" },
    { (INT16)LTE_NAS_NO_SUITABLE_CELLS_IN_TRACKING_AREA,            "No Suitable Cells In tracking Area" },
    { (INT16)LTE_NAS_MSC_TEMPORARILY_NOT_REACHABLE,                 "MSC temporarily not reachable" },
    { (INT16)LTE_NAS_NW_FAILURE,                                    "Network failure" },
    { (INT16)LTE_NAS_CS_DOMAIN_NOT_AVAILABLE,                       "CS domain not available" },
    { (INT16)LTE_NAS_ESM_FAILURE,                                   "ESM failure" },
    { (INT16)LTE_NAS_MAC_FAILURE,                                   "MAC failure" },
    { (INT16)LTE_NAS_SYNCH_FAILURE,                                 "Synch failure" },
    { (INT16)LTE_NAS_CONGESTION,                                    "Congestion" },
    { (INT16)LTE_NAS_UE_SECURITY_CAPABILITIES_MISMATCH,             "UE security capabilities mismatch" },
    { (INT16)LTE_NAS_SECURITY_MODE_REJ_UNSPECIFIED,                 "Security mode reject unspecified" },
    { (INT16)LTE_NAS_NOT_AUTHORIZED_FOR_THIS_CSG,                   "Not authorized for this CSG" },
    { (INT16)LTE_NON_EPS_AUTH_UNACCEPTABLE,                         "EPS auth unacceptable" },
    { (INT16)LTE_NAS_CS_FALLBACK_CALL_EST_NOT_ALLOWED,              "CS fallback call est not allowed" },
    { (INT16)LTE_NAS_CS_DOMAIN_TEMP_NOT_AVAILABLE,                  "CS domain temp not available" },
    { (INT16)LTE_NAS_NO_EPS_BEARER_CONTEXT_ACTIVATED,               "No EPS bearer context activated" },
    { (INT16)LTE_NAS_SEVERE_NW_FAILURE,                             "Severe network failure" },
    { (INT16)LTE_NAS_SEMANTICALLY_INCORRECT_MSG,                    "Semantically incorrect msg " },
    { (INT16)LTE_NAS_INVALID_MANDATORY_INFO,                        "Invalid mandatory info" },
    { (INT16)LTE_NAS_NON_EXISTENT_MSG_TYPE,                         "Non existent msg type" },
    { (INT16)LTE_NAS_MSG_TYPE_INCOMPATIBLE_WITH_PROTOCOL_STATE,     "Msg type incompatible with protocol state" },
    { (INT16)LTE_NAS_NON_EXISTANT_INFO,                             "Non existant info" },
    { (INT16)LTE_NAS_CONDITIONAL_IE_ERROR,                          "Conditional IE error" },
    { (INT16)LTE_NAS_MSG_INCOMPATIBLE_WITH_PROTOCOL_STATE,          "Msg incompatible with protocol state" },
    { (INT16)LTE_NAS_PROTOCOL_ERROR_UNSPECIFIED,                    "Protocol error unspecified" },
    { (INT16)LTE_NAS_NO_FAILURE,                                    "No failure" },
    { (INT16)DSAT_CEER_LIST_TERMINATOR,                             "" }
};

/* 2g/3g ps: attach 拒绝原因值*/
const ceer_lookup_s_type ceer_ps_gmm_cause_codes[] = 
{
  { (int16)SM_UNKNOWN_CAUSE,            	 "No cause information available" 			    },
  { (int16)IMSI_UNKNOWN_IN_HLR,              "IMSI unknown in HLR #2" 			 			},
  { (int16)ILLEGAL_MS,                       "Illegal MS #3" 								},
  { (int16)IMSI_UNKNOWN_IN_VLR,              "IMSI unknown in VLR #4" 						},
  { (int16)IMEI_NOT_ACCEPTED,                "IMEI not accepted #5" 						},
  { (int16)ILLEGAL_ME,                       "Illegal ME #6" 								},
  { (int16)GPRS_SERVICES_NOT_ALLOWED,        "GPRS services not allowed #7"				    },
  { (int16)GPRS_SERVICES_AND_NON_GPRS_SERVICES_NOT_ALLOWED,
                                      		 "GPRS and non GPRS services not allowed #8"    },
  { (int16)MS_IDENTITY_CANNOT_BE_DERIVED_BY_THE_NETWORK,
                                      		 "MS identity cannot be derived #9" 			},
  { (int16)IMPLICITLY_DETACHED,              "Implicitly detached #10" 						},
  { (int16)PLMN_NOT_ALLOWED,                 "PLMN not allowed #11" 						},
  { (int16)LA_NOT_ALLOWED,                   "Location Area not allowed #12" 				},
  { (int16)NATIONAL_ROAMING_NOT_ALLOWED,     "Roaming not allowed #13"						},
  { (int16)GPRS_SERVICES_NOT_ALLOWED_IN_THIS_PLMN,
                                      		 "GPRS services not allowed in PLMN #14" 		},
  { (int16)NO_SUITABLE_CELLS_IN_LA,          "No Suitable Cells In Location Area #15" 		},
  { (int16)MSC_TEMPORARILY_NOT_REACHABLE,    "MSC temporarily not reachable #16" 			},
  { (int16)NETWORK_FAILURE,                  "Network failure #17" 							},
  { (int16)MAC_FAILURE,                      "MAC failure #20"								},
  { (int16)SYNCH_FAILURE,                    "Synch failure #21" 							},
  { (int16)CONGESTTION,                      "Congestion #22"								},
  { (int16)GSM_AUTH_UNACCEPTED,              "GSM authentication unacceptable #23" 			},
  { (int16)CSG_NOT_AUTHORIZED,               "CSG not authorized #25" 						},
  { (int16)SMS_PROVIDED_VIA_GPRS_IN_THIS_ROUTING_AREA, 
                        "SMS provided via gprs in this routing area #28" 					},
  { (int16)SERVICE_OPTION_NOT_SUPPORTED,     "Service option not supported #32" 			},
  { (int16)REQ_SERV_OPT_NOT_SUBSCRIBED,      "Requested service option not subscribed #33" 	},
  { (int16)SERVICE_OPT__OUT_OF_ORDER,        "Service option temporarily out of order #34" 	},
  { (int16)CALL_CANNOT_BE_IDENTIFIED,        "Call cannot be identified #38" 				},
  { (int16)NO_PDP_CONTEXT_ACTIVATED,         "No PDP context activated #40" 				},
  { (int16)RETRY_UPON_ENTRY_INTO_A_NEW_CELL_MIN_VALUE,         
  											 "Retry upon entry into a new cell #48" 		},
  { (int16)SEMANTICALLY_INCORRECT_MSG,       "Semantically incorrect message #95"			},
  { (int16)INVALID_MANDATORY_INFO,           "Invalid mandatory information #96" 			},
  { (int16)MESSAGE_TYPE_NON_EXISTANT,        "Message type non-existent #97" 				},
  { (int16)MESSAGE_TYPE_NOT_COMP_PRT_ST,     "Message type not compatible with state #98" 	},
  { (int16)IE_NON_EXISTANT,                  "Information element non-existent #99" 		},
  { (int16)CONDITIONAL_IE_ERROR,             "Conditional IE error #100"					},
  { (int16)MSG_NOT_COMPATIBLE_PROTOCOL_STATE,"Message not compatible with state #101" 		},
  { (int16)PROTOCOL_ERROR_UNSPECIFIED,		 "Protocol error,unspecified #111" 				},
  { (int16)DSAT_CEER_LIST_TERMINATOR,   	 "" 										    },
};


/*2g/3g ps： pdp激活拒绝值*/
const ceer_lookup_s_type ceer_ps_sm_cause_codes[] =
{
  { (int16)SM_OPERATOR_DETERMINED_BARRING,          "Operator determined barring" 									},
  { (int16)SM_MBMS_BEARER_CAP_INSUFFICIENT,         "MBMS bearer cap insufficient" 									},
  { (int16)SM_LLC_SNDCP_FAILURE,                    "LLC or SNDCP failure"											},
  { (int16)SM_INSUFFICIENT_RESOURCES,               "Insufficient resources"										},
  { (int16)SM_MISSING_OR_UNKNOWN_APN,        		"Unknow or missing APN"											},
  { (int16)SM_UNKNOWN_PDP_ADDRESS_OR_TYPE,   		"Unknown PDP address or PDP type"								},
  { (int16)SM_USER_AUTHENTICATION_FAILED,    		"User Aauthentication failed"									},
  { (int16)SM_ACTIVATION_REJECTED_BY_GGSN,   		"Activation rejected by GGSN"									},
  { (int16)SM_ACTIVATION_REJECTED_UNSPECIFIED, 		"Activation rejected, unspecified"								},
  { (int16)SM_SERVICE_OPTION_NOT_SUPPORTED,  		"Service option not supported"									},
  { (int16)SM_SERVICE_NOT_SUBSCRIBED,        		"Requested service option not subscribed"						},
  { (int16)SM_SERVICE_OUT_OR_ORDER,          		"Service option temporarily out of order"						},
  { (int16)SM_NSAPI_ALREADY_USED,            		"NSAPI already used (not sent)"									},
  { (int16)SM_REGULAR_DEACTIVATION,          		"Regular deactivation"											},
  { (int16)SM_QOS_NOT_ACCEPTED,              		"QoS not accepted"												},
  { (int16)SM_NETWORK_FAILURE,               		"Network failure"												},
  { (int16)SM_REACTIVATION_REQUIRED,         		"Reactivation required"											},
  { (int16)SM_FEATURE_NOT_SUPPORTED,         		"Feature not supported"											},
  { (int16)SM_SEMANTIC_ERR_IN_TFT,           		"Semantic error in the TFT operation"							},
  { (int16)SM_SYNTACTIC_ERR_IN_TFT,          		"Syntactical error in the TFT operation"						},
  { (int16)SM_UNKNOWN_PDP_CONTEXT,           		"Unknown PDP context",											},
  { (int16)SM_SEMANTIC_ERR_IN_FILTER,        		"Semantic errors in packet filter"		    					},
  { (int16)SM_SYNTACTIC_ERR_IN_FILTER,       		"Syntactical errors in packet filter"							},
  { (int16)SM_PDP_WITHOUT_TFT_ACTIVE,        		"PDP context without TFT already activated" 					},
  { (int16)SM_MBMS_GROUP_MEMBERSHIP_TIMEOUT,        "Multicast group membership timeout"							},
  { (int16)SM_ACTIVATION_REJECTED_BCM_VIOLATION,	"Activation rejected BCM violation"								},
  { (int16)SM_PDP_TYPE_IPV4_ONLY_ALLOWED,           "PDP type IPV4 only allowed"									},
  { (int16)SM_PDP_TYPE_IPV6_ONLY_ALLOWED,           "PDP type IPV6 only allowed"									},
  { (int16)SM_SINGLE_ADR_BEARERS_ONLY_ALLOWED,      "Single ADR bearers only allowed"		   					 	},
  { (int16)SM_COLLISION_WITH_NET_INITIATED_REQ,     "Collision with net initiated req"		   					 	},
  { (int16)SM_INVALID_TRANS_ID,              		"Invalid transaction identifier value"							},
  { (int16)SM_SEMANTIC_INCORRECT_MESG,       		"Semantically incorrect message"								},
  { (int16)SM_INVALID_MANDATORY_INFO,        		"Invalid mandatory information"									},
  { (int16)SM_MESG_TYPE_NON_EXISTENT,        		"Message type non-existent or not implemented" 					},
  { (int16)SM_MESG_TYPE_NOT_COMPATIBLE,      		"Message not compatible with protocol state"   					},
  { (int16)SM_IE_NON_EXISTENT,               		"Information element non-existent or not implemented" 			},
  { (int16)SM_CONDITIONAL_IE_ERR,            		"Conditional IE error"											},
  { (int16)SM_MESG_NOT_COMPATIBLE,           		"Message not compatible with portocol state"   					},
  { (int16)SM_PROTOCOL_ERR,                  		"Protocol error, unspecified"									},
  { (int16)SM_APN_TYPE_CONFLICT,           			"APN restriction value incompatible with active PDP context" 	},
  { (int16)DSAT_CEER_LIST_TERMINATOR,   	 		"" 															 	},
};
  
#ifdef QUECTEL_NETWORK_REJECT_URC_SUPPORT
  const ceer_lookup_s_type as_event_codes[] =
  {
	{ (int16)CI_DEV_RRC_EVENT_RACH_FAIL,			  "Rach Fail"													  },
	{ (int16)CI_DEV_RRC_EVENT_DL_LOSS_SYNC, 		  "DL Loss Sync"												  },
	{ (int16)CI_DEV_RRC_EVENT_IRAT_RESELECTION_FAIL,  "IRAT_RESELECTION_FAIL"										  },
	{ (int16)CI_DEV_RRC_EVENT_LTE_RRC_CONN_SETUP_NOT_RECEIVED,	"RRC_CONN_SETUP_NOT_RECEIVED"						  },
	{ (int16)DSAT_CEER_LIST_TERMINATOR, 			  ""															  },
  };
#endif

/**
* @func:  quec_clear_reject_cause_buff
* @brief: clear +CEER buffer,init it.
*/
void quec_clear_reject_cause_buff(void)
{
    Network_Info_Log("marvin, clear gErrCauseBuf");
    memset(gErrCauseBuf,0,sizeof(gErrCauseBuf));
	
    sprintf(gErrCauseBuf,"0 Unknown");
#ifndef LTEONLY_THIN_SINGLE_SIM
    memset(gErrCauseBuf_1,0,sizeof(gErrCauseBuf_1));
    
    sprintf(gErrCauseBuf_1,"0 Unknown");
#endif
}

/**
* @func:  quec_ci_lookup_cause_code
* @brief: code reject in code table
*/
unsigned char quec_ci_lookup_cause_code
(
  const ceer_lookup_s_type  *table_ptr,
  const INT16                code,
  const ceer_lookup_s_type  **row_pptr
)
{
  unsigned char result = FALSE;
  *row_pptr = NULL;
  
  while( DSAT_CEER_LIST_TERMINATOR != table_ptr->code )
  {
    if( table_ptr->code == code )
    {
      *row_pptr = table_ptr; 
      result = TRUE;
      break;
    }
    table_ptr++;
  }
  
  return result;
} 

extern char quec_err_cause[QUEC_ERR_CAUSE_LEN];

/*
*@func:quec_get_lte_attach_reject_cause_string
*@brief:just lte attach pdn reject write done,copy string to +CEER buffer.
*/
static void quec_get_lte_attach_reject_cause_string(CiIndicationHandle indHandle, const void *pParam)
{
    CiDevPrimCommonReportInd *p_lte_report_ind = NULL;
	p_lte_report_ind = (CiDevPrimCommonReportInd *)pParam;
    CiDevEventTypeMm emm_event =0;
	CiDevEventTypeSm esm_event =0;
	CiDevEventTypeMm mm_event=0;
	CiDevEventTypeMm gmm_event =0;
	CiDevEventTypeSm sm_event =0;
    char *pErrCauseBuf;
    const ceer_lookup_s_type  *result_ptr = NULL;
    char tempBuf[256] = {0};
    char *quec_err_cause_p = quec_err_cause;

#ifndef LTEONLY_THIN_SINGLE_SIM
    if (!GET_SIM1_FLAG(indHandle)) {
        pErrCauseBuf = gErrCauseBuf;
    } else {
        pErrCauseBuf = gErrCauseBuf_1;
    }
#else
	pErrCauseBuf = gErrCauseBuf;
#endif
    memset(quec_err_cause_p, 0, QUEC_ERR_CAUSE_LEN);
    switch (p_lte_report_ind->type)
    {
        case CI_DEV_COMMON_REPORT_EMM: /* not support all */
            emm_event = p_lte_report_ind->info.emm.event;
            switch(emm_event)
            {
                case CI_DEV_EMM_EVENT_ATTACH_REJECT:
                case CI_DEV_EMM_EVENT_TAU_REJECT:
                case CI_DEV_EMM_EVENT_SERVICE_REJECT:
                case CI_DEV_EMM_EVENT_AUTHENTICATION_REJECT:
                    if(TRUE != quec_ci_lookup_cause_code(ceer_emm_attach_reject_codes,p_lte_report_ind->info.esm.cause,&result_ptr))
                    {
                        Network_Info_Log("ceer: event %d,emm cause %d failed to lookup reject code",emm_event,p_lte_report_ind->info.emm.cause);
                        sprintf(quec_err_cause_p,"No report available");
                        sprintf(pErrCauseBuf,"0 Unknown");
                        break;
                    }
                    //for QCEER
                    snprintf(quec_err_cause_p, QUEC_ERR_CAUSE_LEN, "\"%s\",%d,\"%s\"", EMM_ERROR, p_lte_report_ind->info.esm.cause, result_ptr->text);
                    if(TRUE == quec_get_err_cause_urc_en()){
                        snprintf(tempBuf, sizeof(tempBuf), "+QCEER: %s", quec_err_cause_p);
                        at_urc_send(NUM_OF_TEL_ATP, (uint8 *)tempBuf, strlen(tempBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
                    }
                    //for CEER
                    sprintf(pErrCauseBuf, "%d %s", p_lte_report_ind->info.esm.cause, result_ptr->text);
                    Network_Info_Log("%d,marvin pErrCauseBuf = %s",__LINE__, pErrCauseBuf);
                    break;
                default:
                    sprintf(pErrCauseBuf,"0 Unknown");
                    Network_Info_Log("%d,marvin pErrCauseBuf = %s",__LINE__, pErrCauseBuf);
                    break;
            }
            Network_Info_Log("marvin pErrCauseBuf = %s",pErrCauseBuf);
            break;
        case CI_DEV_COMMON_REPORT_ESM:
            esm_event = p_lte_report_ind->info.esm.event;
            switch (esm_event)
            {
                case CI_DEV_SM_EVENT_PDP_ACT_REJ:
                case CI_DEV_SM_EVENT_PDP_MODIFY_REJ:
                    if(TRUE != quec_ci_lookup_cause_code(ceer_ps_lte_cause_codes,p_lte_report_ind->info.esm.cause,&result_ptr))
                    {
                        Network_Info_Log(" Failed to lookup reject code");
                        sprintf(quec_err_cause_p,"No report available");
                        sprintf(pErrCauseBuf,"0 Unknown");
                        Network_Info_Log("%d,marvin pErrCauseBuf = %s",__LINE__, pErrCauseBuf);
                        break;
                    }
                    //for QCEER
                    snprintf(quec_err_cause_p, QUEC_ERR_CAUSE_LEN, "\"%s\",%d,\"%s\"", ESM_ERROR, p_lte_report_ind->info.esm.cause, result_ptr->text);
                    if(TRUE == quec_get_err_cause_urc_en()){
                        snprintf(tempBuf, sizeof(tempBuf), "+QCEER: %s", quec_err_cause_p);
                        at_urc_send(NUM_OF_TEL_ATP, (uint8 *)tempBuf, strlen(tempBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
                    }
                    //for CEER
                    sprintf(pErrCauseBuf, "%d %s", p_lte_report_ind->info.esm.cause, result_ptr->text);
                    break;
                default:
                    sprintf(pErrCauseBuf,"0 Unknown");
                    Network_Info_Log("%d,marvin pErrCauseBuf = %s",__LINE__, pErrCauseBuf);
                    break;
            }
        
            break;
        /*  below no support yet */
        case CI_DEV_COMMON_REPORT_MM:
            //sprintf(pErrCauseBuf,"MM event:%d cause:%d",p_lte_report_ind->info.esm.event, p_lte_report_ind->info.esm.cause);
            mm_event = p_lte_report_ind->info.mm.event;
			if(CI_DEV_MM_EVENT_LU_REJECT == mm_event)
			{
				sprintf(pErrCauseBuf,"%d MM LU_REJECT cause:%d",p_lte_report_ind->info.mm.event, p_lte_report_ind->info.mm.cause);	
		    }
		    else
		    {
				sprintf(pErrCauseBuf,"0 Unknown");
                Network_Info_Log("%d,marvin pErrCauseBuf = %s",__LINE__, pErrCauseBuf);
			}
            break;
        case CI_DEV_COMMON_REPORT_GMM:
            //sprintf(pErrCauseBuf,"GMM event:%d cause:%d",p_lte_report_ind->info.esm.event, p_lte_report_ind->info.esm.cause);
            gmm_event = p_lte_report_ind->info.gmm.event;
            switch (gmm_event)
            {
                case CI_DEV_GMM_EVENT_ATTACH_REJECT:
                   // sprintf(pErrCauseBuf,"%d GMM ATTACH_REJECT cause:%d",p_lte_report_ind->info.gmm.event, p_lte_report_ind->info.gmm.cause);
                   // break;
                case CI_DEV_GMM_EVENT_RAU_REJECT:
                   //sprintf(pErrCauseBuf,"%d GMM RAU_REJECT cause:%d",p_lte_report_ind->info.gmm.event, p_lte_report_ind->info.gmm.cause);
                   //break;
                case CI_DEV_GMM_EVENT_SERVICE_REJECT:
                   // sprintf(pErrCauseBuf,"%d GMM SERVICE_REJECT cause:%d",p_lte_report_ind->info.gmm.event, p_lte_report_ind->info.gmm.cause);
                   // break; 
                default:
                    sprintf(pErrCauseBuf,"0 Unknown");
                    Network_Info_Log("%d,marvin pErrCauseBuf = %s",__LINE__, pErrCauseBuf);
                    break;
            }
                
            break;
        case CI_DEV_COMMON_REPORT_SM:
            sm_event = p_lte_report_ind->info.sm.event;
            switch (sm_event)
            {
                case CI_DEV_SM_EVENT_PDP_ACT_REJ:
                   // sprintf(pErrCauseBuf,"%d SM PDP_ACT_REJ cause:%d",p_lte_report_ind->info.sm.event, p_lte_report_ind->info.sm.cause);
                   // break;
                case CI_DEV_SM_EVENT_PDP_MODIFY_REJ:
                   // sprintf(pErrCauseBuf,"%d SM PDP_MODIFY_REJ cause:%d",p_lte_report_ind->info.sm.event, p_lte_report_ind->info.sm.cause);
                   // break;
                case CI_DEV_SM_EVENT_PDP_DEACT_REJ:
                   // sprintf(pErrCauseBuf,"%d SM PDP_DEACT_REJ cause:%d",p_lte_report_ind->info.sm.event, p_lte_report_ind->info.sm.cause);
                   // break; 
                default:
                    sprintf(pErrCauseBuf,"0 Unknown");
                    Network_Info_Log("%d,marvin pErrCauseBuf = %s",__LINE__, pErrCauseBuf);
                    break;
            }
            break;
        case CI_DEV_COMMON_REPORT_AS:
        default:
            sprintf(pErrCauseBuf,"0 Unknown");
            Network_Info_Log("%d,marvin pErrCauseBuf = %s",__LINE__, pErrCauseBuf);
            break;
    }
}
#endif
// destin 2020.10.28 esm reject cause code end

static void quec_process_lte_attach_reject_ind(const void *pParam)
{
	CiDevPrimCommonReportInd *p_lte_report_ind = NULL;
	p_lte_report_ind = (CiDevPrimCommonReportInd *)pParam;
	CiDevEventTypeMm emm_event =0;
	CiDevEventTypeSm esm_event =0;
	CiDevEventTypeMm mm_event=0;
	CiDevEventTypeMm gmm_event =0;
	CiDevEventTypeSm sm_event =0;
#ifdef QUEC_BLACK_CELL_SUPPORT
	CiDevEventTypeAs as_event =0;
	int ret = 0;
#endif
	Network_Info_Log("LTE EVENT type:%d event:%d cause:%d",p_lte_report_ind->type, p_lte_report_ind->info.emm.event, p_lte_report_ind->info.emm.cause);
	switch(p_lte_report_ind->type)
	{
		case CI_DEV_COMMON_REPORT_EMM:
			emm_event = p_lte_report_ind->info.emm.event;
			if( (CI_DEV_EMM_EVENT_ATTACH_REJECT ==emm_event)
				||(CI_DEV_EMM_EVENT_TAU_REJECT ==emm_event)
				||(CI_DEV_EMM_EVENT_SERVICE_REJECT ==emm_event)
				||(CI_DEV_EMM_EVENT_AUTHENTICATION_REJECT ==emm_event))
			{
				Network_Info_Log("LTE EVENT emm reject,event:%d cause:%d",p_lte_report_ind->info.emm.event, p_lte_report_ind->info.emm.cause);	

#ifdef	QUECTEL_NETWORK_REJECT_URC_SUPPORT
				if(netreject_mode==1)
				{
					if(TRUE != quec_ci_lookup_cause_code(ceer_emm_attach_reject_codes, p_lte_report_ind->info.emm.cause, &result_ptr))
					{
						report_flag=FALSE;
					}
					else
					{
						report_type=p_lte_report_ind->type;
						reject_cause=p_lte_report_ind->info.emm.cause;
						report_flag=TRUE;
					}
				}
#endif

#if defined (QUEC_BLACK_CELL_SUPPORT)
				if ((QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg_ex()) || (QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg()))
				{
					quec_set_oneshot_type(BLACKCELL_REGISTER_SERVICE_REJECT);
					quec_send_oneshot_get_cellid(p_lte_report_ind->type);
				}
#ifdef QUECTEL_NETWORK_REJECT_URC_SUPPORT
				else if(report_flag==TRUE)
				{
					quec_send_oneshot_get_cellid(p_lte_report_ind->type);
				}
#endif
#elif defined (QUEC_THIN_BLACK_CELL_SUPPORT)
				if (QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg())
				{
					quec_send_oneshot_get_cellid(p_lte_report_ind->type);
				}
#else
#ifdef QUECTEL_NETWORK_REJECT_URC_SUPPORT
				if(report_flag==TRUE)
				{
					quec_send_oneshot_get_cellid(p_lte_report_ind->type);
				}
#endif
#endif
			}
#ifdef QUEC_BLACK_CELL_SUPPORT
			else if( (CI_DEV_EMM_ATTACH_TIMEOUT ==emm_event)
				||(CI_DEV_EMM_TAU_TIMEOUT ==emm_event))
			{
				Network_Info_Log("LTE EVENT emm reject,event:%d cause:%d",p_lte_report_ind->info.emm.event, p_lte_report_ind->info.emm.cause);	
				if (QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg_ex())
				{
					quec_set_oneshot_type(BLACKCELL_REGISTER_TIMEOUT);
					quec_send_oneshot_get_cellid(p_lte_report_ind->type);
				}
				return;
			}	
			else if(CI_DEV_EMM_SERVICE_REQ_TIMEOUT ==emm_event)
			{
				Network_Info_Log("LTE EVENT emm reject,event:%d cause:%d",p_lte_report_ind->info.emm.event, p_lte_report_ind->info.emm.cause);	
				if (QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg_ex())	
				{
					quec_set_oneshot_type(BLACKCELL_SERVICE_TIMEOUT);
					quec_send_oneshot_get_cellid(p_lte_report_ind->type);
				}
				return;
			}
#endif
			else
			{
				Network_Info_Log("LTE EVENT emm not reject,event:%d cause:%d",p_lte_report_ind->info.emm.event, p_lte_report_ind->info.emm.cause);
				if(CI_DEV_EMM_EVENT_DETACH_REQ == emm_event)
				{
					if(0 == quec_qsclkex_punishtime_get())
					{
						quec_qsclkex_punishtime_set(qsclkex_cfg.punish_time);
					}
				}
				return;
			}
			break;
		case CI_DEV_COMMON_REPORT_ESM:
			esm_event = p_lte_report_ind->info.esm.event;
			if((CI_DEV_SM_EVENT_PDP_ACT_REJ ==esm_event)
				 ||(CI_DEV_SM_EVENT_PDP_MODIFY_REJ ==esm_event))
			{
				Network_Info_Log("LTE EVENT esm reject,event:%d cause:%d",p_lte_report_ind->info.esm.event, p_lte_report_ind->info.esm.cause);	

#ifdef	QUECTEL_NETWORK_REJECT_URC_SUPPORT
				if(netreject_mode==1)
				{
					if(TRUE != quec_ci_lookup_cause_code(ceer_ps_lte_cause_codes,p_lte_report_ind->info.esm.cause,&result_ptr))
					{
						report_flag=FALSE;
					}
					else
					{
						report_type=p_lte_report_ind->type;
						reject_cause=p_lte_report_ind->info.emm.cause;
						report_flag=TRUE;
						quec_send_oneshot_get_cellid(p_lte_report_ind->type);
					}
				}
#endif
			}
			else
			{
				Network_Info_Log("LTE EVENT esm not reject,event:%d cause:%d",p_lte_report_ind->info.esm.event, p_lte_report_ind->info.esm.cause);	
				return;
			}
			break;
		 case CI_DEV_COMMON_REPORT_MM:
			mm_event = p_lte_report_ind->info.mm.event;
			if(CI_DEV_MM_EVENT_LU_REJECT ==mm_event)
			{
				Network_Info_Log("LTE EVENT mm reject,event:%d cause:%d",p_lte_report_ind->info.mm.event, p_lte_report_ind->info.mm.cause); 
#ifdef	QUECTEL_NETWORK_REJECT_URC_SUPPORT
				if(netreject_mode==1)
				{
					report_type=p_lte_report_ind->type;
					reject_cause=p_lte_report_ind->info.mm.cause;
					report_flag=TRUE;
					quec_send_oneshot_get_cellid(p_lte_report_ind->type);
				}
#endif
			}
			else
			{
				Network_Info_Log("LTE EVENT mm not reject,event:%d cause:%d",p_lte_report_ind->info.mm.event, p_lte_report_ind->info.mm.cause); 
				return;
			}
			break;
		case CI_DEV_COMMON_REPORT_GMM:
			gmm_event = p_lte_report_ind->info.gmm.event;
			if((CI_DEV_GMM_EVENT_ATTACH_REJECT == gmm_event)
				||(CI_DEV_GMM_EVENT_RAU_REJECT == gmm_event)
				||(CI_DEV_GMM_EVENT_SERVICE_REJECT == gmm_event)
				||(CI_DEV_GMM_EVENT_AUTHENTICATION_REJECT == gmm_event))
			{
				Network_Info_Log("GSM,WCDMA EVENT gmm reject,event:%d cause:%d",p_lte_report_ind->info.gmm.event, p_lte_report_ind->info.gmm.cause);	
#ifdef	QUECTEL_NETWORK_REJECT_URC_SUPPORT
				if(netreject_mode==1)
				{
					if(TRUE != quec_ci_lookup_cause_code(ceer_ps_gmm_cause_codes,p_lte_report_ind->info.gmm.cause,&result_ptr))
					{
						report_flag=FALSE;
					}
					else
					{
						report_type=p_lte_report_ind->type;
						reject_cause=p_lte_report_ind->info.gmm.cause;
						report_flag=TRUE;
						quec_send_oneshot_get_cellid(p_lte_report_ind->type);
					}
				}
#endif
			}
			else
			{
				Network_Info_Log("LTE EVENT gmm not reject,event:%d cause:%d",p_lte_report_ind->info.gmm.event, p_lte_report_ind->info.gmm.cause);	
				return;
			}
			break;
		case CI_DEV_COMMON_REPORT_SM:
			sm_event = p_lte_report_ind->info.sm.event;
			if((CI_DEV_SM_EVENT_PDP_ACT_REJ ==sm_event)
				||(CI_DEV_SM_EVENT_PDP_MODIFY_REJ ==sm_event)				 
				||(CI_DEV_SM_EVENT_PDP_DEACT_REJ ==sm_event))
			{
				Network_Info_Log("LTE EVENT sm reject,event:%d cause:%d",p_lte_report_ind->info.sm.event, p_lte_report_ind->info.sm.cause); 
#ifdef	QUECTEL_NETWORK_REJECT_URC_SUPPORT
				if(netreject_mode==1)
				{
					if(TRUE != quec_ci_lookup_cause_code(ceer_ps_sm_cause_codes,p_lte_report_ind->info.sm.cause,&result_ptr))
					{
						report_flag=FALSE;
					}
					else
					{
						report_type=p_lte_report_ind->type;
						reject_cause=p_lte_report_ind->info.sm.cause;
						report_flag=TRUE;
						quec_send_oneshot_get_cellid(p_lte_report_ind->type);
					}
				}
#endif
			}
			else
			{
				Network_Info_Log("LTE EVENT sm not reject,event:%d cause:%d",p_lte_report_ind->info.sm.event, p_lte_report_ind->info.sm.cause); 
				return;
			}
			break;
			
		case CI_DEV_COMMON_REPORT_AS:
#ifdef QUEC_BLACK_CELL_SUPPORT
		as_event = p_lte_report_ind->info.as.event;
		if( (CI_DEV_RRC_EVENT_LTE_RESELECTION_SUCCESS ==as_event)
			/*
			||(CI_DEV_RRC_EVENT_LTE_HANDOVER_SUCCESS ==as_event)
			||(CI_DEV_RRC_EVENT_LTE_REDIRECTION_SUCCESS ==as_event)
			*/
			)
		{
			Network_Info_Log("LTE EVENT as reject,event:%d",p_lte_report_ind->info.as.event);	
			   if (QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg_ex())
				{
					extern QuecScellALGragh g_quec_scellalgragh;
					ret = quec_insert_scell_arc(&g_quec_scellalgragh,
						p_lte_report_ind->info.as.sourceLteCell, 
						p_lte_report_ind->info.as.currentLteCell,
						p_lte_report_ind->info.as.rsrpOfsourceCell,
						p_lte_report_ind->info.as.rsrqOfsourceCell,
						p_lte_report_ind->info.as.rsrpOfcurrentCell,
						p_lte_report_ind->info.as.rsrqOfcurrentCell,
						CI_DEV_RRC_EVENT_LTE_RESELECTION_SUCCESS);
				}
			 return;
		}
		else if( (CI_DEV_RRC_EVENT_LTE_RRC_CONN_SETUP_NOT_RECEIVED ==as_event))
		{
			Network_Info_Log("LTE EVENT as reject,event:%d",p_lte_report_ind->info.as.event);	
			if (QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg_ex()) 
			{
				quec_set_oneshot_type(BLACKCELL_SERVICE_TIMEOUT);
				quec_set_oneshot_flag(TRUE);
				quec_update_ltecellid_to_blackcell_check(p_lte_report_ind->info.as.currentLteCell.euArfcn,
						   p_lte_report_ind->info.as.currentLteCell.phyCellId,
						   BLACKCELL_LTE,BLACKCELL_ADD);
				quec_set_oneshot_flag(FALSE);
			}
			return;
		}
#ifdef	QUECTEL_NETWORK_REJECT_URC_SUPPORT
		else if((CI_DEV_RRC_EVENT_RACH_FAIL ==as_event)
				|| (CI_DEV_RRC_EVENT_DL_LOSS_SYNC ==as_event)
				||(CI_DEV_RRC_EVENT_IRAT_RESELECTION_FAIL ==as_event))
		{
			if(netreject_mode==1)
			{
				if(TRUE != quec_ci_lookup_cause_code(as_event_codes,p_lte_report_ind->info.as.event,&result_ptr))
				{
					report_flag=FALSE;
				}
				else
				{
					report_type=p_lte_report_ind->type;
					reject_cause=p_lte_report_ind->info.as.event;
					report_flag=TRUE;
					quec_send_oneshot_get_cellid(p_lte_report_ind->type);
				}
			}
		}
#endif
		else
		{
			Network_Info_Log("LTE EVENT as not reject,event:%d",p_lte_report_ind->info.as.event);	
			return;
		}
		//break;	
#endif
		default:
			Network_Info_Log("LTE EVENT not support!");
			return;
	}

	
	if(0 == quec_qsclkex_punishtime_get())
	{
		quec_qsclkex_punishtime_set(qsclkex_cfg.punish_time);
	}
	/*
	quec_gw_pdp_syn_msg_t * pdp_reg_netdeny_event = NULL;
	quec_gw_pdp_syn_info * pdp_syn_info_p = quec_gw_pdp_syn_info_get();
	if(TRUE == pdp_syn_info_p->auth_retry_enable)
	{
		pdp_reg_netdeny_event = malloc(sizeof(quec_gw_pdp_syn_msg_t));
		if(NULL != pdp_reg_netdeny_event)
		{
			memset(pdp_reg_netdeny_event, 0x00,sizeof(quec_gw_pdp_syn_msg_t));
			quec_gw_service_requst(QUEC_GW_SERVICE_PDP_LTE_NET_DENY_EVENT3, pdp_reg_netdeny_event);
		}
		else 
		{
			Network_Info_Log("ERROR fail to allcote buff for pdp_reg_netdeny_event");
		}
	}*/

	return;
}

#endif
/****************************************************************
 *	F@: processL1debugInd - Process L1 Debug info
 */
static void processL1debugInd(const void *pParam)
{
	CiDevPrimL1DebugInfoInd *pCiDevPrimL1DebugInfoInd;
	char *respBuffer = NULL;
	char tmp[10] = {0};
	int i=0;

	respBuffer = (char* )malloc(560);
	if(respBuffer == NULL)
		return;
	
	sprintf(respBuffer,"*L1DEBUG:");

	pCiDevPrimL1DebugInfoInd = (CiDevPrimL1DebugInfoInd *)pParam;

	for(i=0; i<pCiDevPrimL1DebugInfoInd->length; i++)
	{
        sprintf(tmp, "%02X", pCiDevPrimL1DebugInfoInd->data[i]);
        strcat(respBuffer, tmp);

	}

	ATRESP(IND_REQ_HANDLE, 0, 0, respBuffer);

	free(respBuffer);
	
	return;
}

static void processCommonReportInd(const void *pParam) //#5221
{	
	CiDevPrimCommonReportInd *pReportInd = NULL;
	char resBuf[128] = {0};

	pReportInd = (CiDevPrimCommonReportInd *)pParam;

	CPUartLogPrintf("%s, type %d", __func__, pReportInd->type);
	switch(pReportInd->type)
	{
		case CI_DEV_COMMON_REPORT_AS:
			//ATDBGMSG(atcmdsrv,6,"%s, report-as, networkMode %d, event %d", __func__, pReportInd->info.as.networkMode, pReportInd->info.as.event);
			sprintf(resBuf, "+COMMRPTAS: %d, %d\r\n", pReportInd->info.as.networkMode, pReportInd->info.as.event);
			break;

		case CI_DEV_COMMON_REPORT_MM:
			//ATDBGMSG(atcmdsrv,7,"%s, report-mm, event %d, cause %d", __func__, pReportInd->info.mm.event, pReportInd->info.mm.cause);
			sprintf(resBuf, "+COMMRPTMM: %d, %d\r\n", pReportInd->info.mm.event, pReportInd->info.mm.cause);
			break;

		case CI_DEV_COMMON_REPORT_GMM:
			//ATDBGMSG(atcmdsrv,8,"%s, report-gmm, event %d, cause %d", __func__, pReportInd->info.gmm.event, pReportInd->info.gmm.cause);
			sprintf(resBuf, "+COMMRPTGMM: %d, %d\r\n", pReportInd->info.gmm.event, pReportInd->info.gmm.cause);
			break;

		case CI_DEV_COMMON_REPORT_SM:
			//ATDBGMSG(atcmdsrv,9,"%s, report-sm, event %d, cause %d", __func__, pReportInd->info.sm.event, pReportInd->info.sm.cause);
			sprintf(resBuf, "+COMMRPTSM: %d, %d\r\n", pReportInd->info.sm.event, pReportInd->info.sm.cause);
			break;

		case CI_DEV_COMMON_REPORT_EMM:
			//ATDBGMSG(atcmdsrv,10,"%s, report-emm, event %d, cause %d", __func__, pReportInd->info.emm.event, pReportInd->info.emm.cause);
			sprintf(resBuf, "+COMMRPTEMM: %d, %d\r\n", pReportInd->info.emm.event, pReportInd->info.emm.cause);
			break;

		case CI_DEV_COMMON_REPORT_ESM:
			//ATDBGMSG(atcmdsrv,11,"%s, report-esm, event %d, cause %d", __func__, pReportInd->info.esm.event, pReportInd->info.esm.cause);
			sprintf(resBuf, "+COMMRPTESM: %d, %d\r\n", pReportInd->info.esm.event, pReportInd->info.esm.cause);
			break;

		case CI_DEV_NUM_COMMON_REPORT_TYPES:
		default:
			//ATDBGMSG(atcmdsrv,12,"%s, wrong type %d", __func__, pReportInd->type);
			break;

	}

	ATRESP(IND_REQ_HANDLE, 0, 0, resBuf);
	return;
}


#ifdef QUECTEL_JAMDET_FEATURE
extern bool quec_is_nw_mode_vaild(CiDevEngModeNetwork nw_mode);
extern void quec_log_gms_cell_info(CiDevPrimCellsInfoInd *pCiDevPrimCellsInfoInd);
extern void quec_log_cell_info(CiDevPrimCellsInfoInd *pCiDevPrimCellsInfoInd);
/****************************************************************
 *	F@: processJammingDetectionByCellsInfoInd - Process cells info,
 *  then check modem is jamming or not
 ****************************************************************/
static void processJammingDetectionByCellsInfoInd(UINT32 indHandle, const void *pParam)
{
	uint8 i = 0;
	bool is_high_sensitivity = FALSE; /*WCDMA support jamming detection quickly*/
	uint16 decode_success_num = 0,decode_fail_num = 0;
	static uint16 no_jd_count = 0,jd_count = 0,umts_jd_count = 0,lte_jd_count = 0; /*防抖*/
	
	CiDevPrimCellsInfoInd *pCiDevPrimCellsInfoInd = (CiDevPrimCellsInfoInd *)pParam;
	
	Network_Info_Log("[quec jd]processJammingDetectionByCellsInfoInd: Reached");
	if (0 == quec_get_jdcfg_val(JDENABLE))
	{
		return;
	}
	
	if (NULL != pCiDevPrimCellsInfoInd)
	{
		if (FALSE == quec_is_nw_mode_vaild(pCiDevPrimCellsInfoInd->network))
		{
			Network_Info_Log("[quec jd] nw mode %d is vaild",pCiDevPrimCellsInfoInd->network); 
			return;
		}
		quec_log_cell_info(pCiDevPrimCellsInfoInd);
		switch(pCiDevPrimCellsInfoInd->network)
		{
			case QUEC_GSM_MODE:
				Network_Info_Log("[quec jd] GSM mode");
				decode_fail_num = 0; decode_success_num = 0; is_high_sensitivity = FALSE;
				
				for (i = 0;(i < pCiDevPrimCellsInfoInd->numGsmCells) && (i < CI_DEV_MAX_CELLS_INFO);i++)
				{
					 if ( (CI_DEV_CELL_DECODE_SUCCESS != pCiDevPrimCellsInfoInd->gsmCellInfo[i].decodeRc) &&
						  (pCiDevPrimCellsInfoInd->gsmCellInfo[i].rssi >= quec_get_jdcfg_val(JDRXLEV)) &&
						  (CI_DEV_CELL_TYPE_SVC != pCiDevPrimCellsInfoInd->gsmCellInfo[i].cellType) )
					 {
					 	is_high_sensitivity = FALSE;
						decode_fail_num++;
					 }
                    /*isaac 20210119 对于010基线，小区类型不是服务小区，解码结果失败也认为受到干扰
                     * 但要区分弱信号搜网情形，因此加上所有的小区都失败并配合rssi
                     */
                    else if ( (CI_DEV_CELL_DECODE_SUCCESS != pCiDevPrimCellsInfoInd->gsmCellInfo[i].decodeRc) &&
						      (CI_DEV_CELL_TYPE_SVC != pCiDevPrimCellsInfoInd->gsmCellInfo[i].cellType) &&
						      (pCiDevPrimCellsInfoInd->numGsmCells > CI_DEV_MAX_CELLS_INFO/3) )
                    {
                        /* 长时间干扰情况下，低概率rssi小于门限值，不做判断*/
                        return;
                    }
					else if ( (CI_DEV_CELL_DECODE_SUCCESS == pCiDevPrimCellsInfoInd->gsmCellInfo[i].decodeRc) &&
					 	      ((QUEC_JD_ARFCN_INVALID == pCiDevPrimCellsInfoInd->gsmCellInfo[i].arfcn) ||
					 	       (pCiDevPrimCellsInfoInd->gsmCellInfo[i].rssi < quec_get_jdcfg_min_val(JDRXLEV))) )
					{
						/* 长时间干扰情况下，低概率解码成功，但频点，无效值不做判断*/
					    return;
					}	 
                    else if ( (QUEC_JD_BSIC_MIN_INVALID == pCiDevPrimCellsInfoInd->gsmCellInfo[i].bsic) &&
                              (CI_DEV_CELL_DECODE_SUCCESS != pCiDevPrimCellsInfoInd->gsmCellInfo[i].decodeRc) &&
                              (CI_DEV_CELL_TYPE_SVC != pCiDevPrimCellsInfoInd->gsmCellInfo[i].cellType) )
                     {
                        /* GSM 长时间干扰情况下，低概率解码失败，bsic无效，无效值不做判断 */
					     return;
                     }
					 else 
					 {
						decode_success_num++;
					 }
				}
				Network_Info_Log("[quec jd]: decode_success_num = %d,decode_fail_num = %d",decode_success_num,decode_fail_num);
				if (decode_fail_num > pCiDevPrimCellsInfoInd->numGsmCells/2)
				{
				    jd_count++;
                    if (jd_count >= quec_get_jdcfg_val(JDSHAKEPERIOD))
                    {
                        quec_jam_detect_indicate_urc(JAM_DET_GSM_TYPE, JAM_DET_INSERT);
                        jd_count = 0;
                    }
                    no_jd_count = 0; 	/* if jamming,reset no_jd_count */
				}
				else 
				{	
				    no_jd_count++; jd_count = 0;
				    if (no_jd_count >= quec_get_jdcfg_val(JDSHAKEPERIOD))
					{
						quec_jam_detect_indicate_urc(JAM_DET_GSM_TYPE, JAM_DET_REMOVE);
						no_jd_count = 0;
					}
				}
				break;
				
			case QUEC_UMTS_MODE:
				Network_Info_Log("[quec jd] UMTS mode"); /*切换制式： gsm to wcdma,clear jd_count */
				decode_fail_num = 0; decode_success_num = 0; is_high_sensitivity = FALSE; jd_count = 0;
		
				for (i = 0;(i < pCiDevPrimCellsInfoInd->numUmtsCells) && (i < CI_DEV_MAX_CELLS_INFO);i++)
				{
					 if ( (CI_DEV_CELL_DECODE_SUCCESS != pCiDevPrimCellsInfoInd->umtsCellInfo[i].decodeRc) &&
						  (pCiDevPrimCellsInfoInd->umtsCellInfo[i].rssi >= quec_get_jdcfg_val(JDRSSI)) &&
						  (pCiDevPrimCellsInfoInd->umtsCellInfo[i].rssi <= quec_get_jdcfg_max_val(JDRSSI)) &&
						  (CI_DEV_CELL_TYPE_SVC != pCiDevPrimCellsInfoInd->umtsCellInfo[i].cellType))
					 {
					 	/*迟钝模式，触发oos,解码失败，rssi触发门限，所有频点解码都失败*/
						decode_fail_num++;
						is_high_sensitivity = FALSE;
					 }
					 else if ( (CI_DEV_CELL_DECODE_SUCCESS == pCiDevPrimCellsInfoInd->umtsCellInfo[i].decodeRc) &&
							   (pCiDevPrimCellsInfoInd->umtsCellInfo[i].rssi >= quec_get_jdcfg_val(JDRSSI)) &&
							   (pCiDevPrimCellsInfoInd->umtsCellInfo[i].sinr <= quec_get_jdcfg_val(JDSINR)) &&
							   (pCiDevPrimCellsInfoInd->umtsCellInfo[i].sinr >= quec_get_jdcfg_min_val(JDSINR)))
					 {
						/*灵敏模式，上报jamming*/
					 	is_high_sensitivity = TRUE;
						decode_fail_num++;
					 }
                     else if (pCiDevPrimCellsInfoInd->umtsCellInfo[i].rssi > quec_get_jdcfg_max_val(JDRSSI))
                     {
                        /*长时间干扰，rssi概率性是无效值，不做判断*/
                        return;
                     }
					 else 
					 {
						decode_success_num++;
					 }
				}
				
				if ( /*(TRUE == is_high_sensitivity) ||*/
					 (decode_fail_num > pCiDevPrimCellsInfoInd->numUmtsCells/2) ||
					 (decode_fail_num > quec_get_jdcfg_val(JDMINCH)))
				{
				    umts_jd_count++;
                    if (umts_jd_count >= quec_get_jdcfg_val(JDSHAKEPERIOD)-1)
                    {
                        quec_jam_detect_indicate_urc(JAM_DET_WCDMA_TYPE, JAM_DET_INSERT);
                        umts_jd_count = 0;
                    }
					no_jd_count = 0; 	/* if jamming,reset no_jd_count */
				}
				else 
				{
				    no_jd_count++; umts_jd_count = 0;
					if (no_jd_count >= quec_get_jdcfg_val(JDSHAKEPERIOD))
					{
						quec_jam_detect_indicate_urc(JAM_DET_WCDMA_TYPE, JAM_DET_REMOVE);
						no_jd_count = 0;
					}
				}
				break;
			case QUEC_LTE_MODE:
				Network_Info_Log("[quec jd] LTE mode");
                decode_fail_num = 0; is_high_sensitivity = FALSE; jd_count = 0;
                if ( ((CI_DEV_CELL_TYPE_SVC == pCiDevPrimCellsInfoInd->lteCellInfo[0].cellType) && 
                       (pCiDevPrimCellsInfoInd->lteCellInfo[0].rssi >= quec_get_jdcfg_val(JDRSSI)) &&
                       (pCiDevPrimCellsInfoInd->lteCellInfo[0].rssi <= quec_get_jdcfg_max_val(JDRSSI)) &&
                       ((pCiDevPrimCellsInfoInd->lteCellInfo[0].rsrq < quec_get_jdcfg_val(JDRSRQ)) || 
                        (pCiDevPrimCellsInfoInd->lteCellInfo[0].sinr < quec_get_jdcfg_val(JDSINR))))
                  || ((pCiDevPrimCellsInfoInd->lteCellInfo[0].rssi >= quec_get_jdcfg_val(JDRSSI)) && 
                      (pCiDevPrimCellsInfoInd->lteCellInfo[0].rssi <= quec_get_jdcfg_max_val(JDRSSI)) &&
                      (CI_DEV_CELL_TYPE_SVC != pCiDevPrimCellsInfoInd->lteCellInfo[0].cellType) &&
                      (0 == quec_get_ps_regstatus())) )
                {
                    quec_jam_detect_indicate_urc(JAM_DET_FDD_LTE_TYPE, JAM_DET_INSERT);
                }
                else if ( ((CI_DEV_CELL_TYPE_SVC == pCiDevPrimCellsInfoInd->lteCellInfo[0].cellType) && 
                            (CI_DEV_CELL_DECODE_SUCCESS == pCiDevPrimCellsInfoInd->lteCellInfo[0].decodeRc) && 
                            (pCiDevPrimCellsInfoInd->lteCellInfo[0].rssi < quec_get_jdcfg_val(JDRSSI)) &&
                            ((pCiDevPrimCellsInfoInd->lteCellInfo[0].rsrq > quec_get_jdcfg_val(JDRSRQ)) || 
                             (pCiDevPrimCellsInfoInd->lteCellInfo[0].sinr > quec_get_jdcfg_val(JDSINR)))) )
                {
                    /* 防抖 */
					no_jd_count++;
					if (no_jd_count >= quec_get_jdcfg_val(JDSHAKEPERIOD)-1)
					{
						quec_jam_detect_indicate_urc(JAM_DET_FDD_LTE_TYPE, JAM_DET_REMOVE);
						no_jd_count = 0;
					}
                }
                else if ((CI_DEV_CELL_TYPE_SVC == pCiDevPrimCellsInfoInd->lteCellInfo[0].cellType) && 
                         (CI_DEV_CELL_DECODE_SUCCESS == pCiDevPrimCellsInfoInd->lteCellInfo[0].decodeRc) && 
                         (pCiDevPrimCellsInfoInd->lteCellInfo[0].rsrq > quec_get_jdcfg_val(JDRSRQ)) && 
                         (pCiDevPrimCellsInfoInd->lteCellInfo[0].sinr > quec_get_jdcfg_val(JDSINR)))
                {
                    /* 防抖 */
					no_jd_count++;
					if (no_jd_count >= quec_get_jdcfg_val(JDSHAKEPERIOD)-1)
					{
						quec_jam_detect_indicate_urc(JAM_DET_FDD_LTE_TYPE, JAM_DET_REMOVE);
						no_jd_count = 0; /*优化电信卡关闭干扰rssi上报太强*/
					}
                }
                else 
                {
                    /*invaild params,not process*/
                }
				break;
			default:
				break;
		}

	}
	return;
}
#endif

#if defined(QUEC_BLACK_CELL_SUPPORT)|| defined(QUEC_THIN_BLACK_CELL_SUPPORT)
CiReturnCode Quec_DEV_SetBlackCellReq(UINT32 atHandle, quec_black_cell_s_t *pBlack_cell_list)
{
	CiReturnCode ret = CIRC_FAIL;
	CiDevPrimSetBlackCellReq *SetBlackCellReq = NULL;
	int i = 0;
	SetBlackCellReq = utlCalloc(1, sizeof(CiDevPrimSetBlackCellReq));
	if (SetBlackCellReq == NULL)
    {
        CPUartLogPrintf("quec blackcell: calloc failed");
        return CIRC_FAIL;
    }
    
	if(pBlack_cell_list != NULL)
	{
	    memset(SetBlackCellReq,0,sizeof(CiDevPrimSetBlackCellReq));
        SetBlackCellReq->cmdType = pBlack_cell_list->opType;
        memcpy(&SetBlackCellReq->GsmBlackCellList,&pBlack_cell_list->GsmBlackCellList,sizeof(CiDevGsmBlackCellList));
        memcpy(&SetBlackCellReq->UmtsBlackCellList,&pBlack_cell_list->UmtsBlackCellList,sizeof(CiDevUmtsBlackCellList));
        memcpy(&SetBlackCellReq->LteBlackCellList,&pBlack_cell_list->LteBlackCellList,sizeof(CiDevLteBlackCellList));

		ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_SET_BLACK_CELL_REQ,
			             MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_SET_BLACK_CELL_REQ), (void *)SetBlackCellReq);
	}
	else
	{
	    if (SetBlackCellReq != NULL)
        {   
		    utlFree(SetBlackCellReq);
        }
	}
	
	return ret;
}

CiReturnCode Quec_DEV_GetBlackCellReq(UINT32 atHandle)
{

    CiReturnCode ret = CIRC_FAIL;

    CiDevPrimGetBlackCellReq *GetBlackCellReq = NULL;

    ret = ciRequest( gAtciSvgHandle[CI_SG_ID_DEV], CI_DEV_PRIM_GET_BLACK_CELL_REQ,
                        MAKE_CI_REQ_HANDLE(atHandle, CI_DEV_PRIM_GET_BLACK_CELL_REQ), (void*)GetBlackCellReq);

    return ret;
}

#endif

/****************************************************************************************
*
*  DESCRIPTION: Callback function when receiving indication CI message related with Dev
*
****************************************************************************************/
void devInd_2(CiSgOpaqueHandle opSgOpaqueHandle,
	    CiServiceGroupID svgId,
	    CiPrimitiveID primId,
	    CiIndicationHandle indHandle,
	    void*               pParam)
{
	UNUSEDPARAM(opSgOpaqueHandle)
	UNUSEDPARAM(indHandle)
	UINT32 reqHandle;
	CiDevStatus *pDeviceStatus;

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(indHandle)) {
		reqHandle = IND_REQ_HANDLE;
		pDeviceStatus = &gDeviceStatus;
	} else {
		reqHandle = IND_REQ_HANDLE_1;
		pDeviceStatus = &gDeviceStatus_1;
	}
#else
	reqHandle = IND_REQ_HANDLE;
	pDeviceStatus = &gDeviceStatus;
#endif

	DBGMSG("%s:primId=%d\n", __FUNCTION__, primId);
	
#ifdef QUECTEL_NETWORK_SUPPORT
	Network_Info_Log("devInd: svgId: %d, primId: %d,indHandle:%d", svgId, primId,indHandle);
#endif

	switch (primId)
	{
		case CI_DEV_PRIM_STATUS_IND:
		{
			CiDevPrimStatusInd  *devStatusInd;
			devStatusInd = (CiDevPrimStatusInd *)pParam;
			*pDeviceStatus = devStatusInd->status;
			break;
		}
#ifndef LTEONLY_THIN	
		case CI_DEV_PRIM_GSM_ENGMODE_INFO_IND:         //CiDevPrimGsmEngmodeInfoInd
		{
			// for EEMOPT
			processEEMOPTInfoInd(reqHandle, pParam);

			break;
		}
		/* 1. UMTS */
		case CI_DEV_PRIM_UMTS_ENGMODE_SVCCELL_INFO_IND:         //CiDevPrimUmtsEngmodeScellInfoInd
		{

			// for EEMOPT
			processEMumtsINFOSVCInfoInd(reqHandle, pParam);

			break;
		}
		/* 2. UMTS */
		case CI_DEV_PRIM_UMTS_ENGMODE_INTRAFREQ_INFO_IND:         //CiDevPrimUmtsEngmodeIntraFreqInfoInd
		{
			// for EEMOPT
			processEMUmtsIntraFreqInfoInd(reqHandle, pParam);

			break;
		}
		/* 3. UMTS */
		case CI_DEV_PRIM_UMTS_ENGMODE_INTERFREQ_INFO_IND:         //CiDevPrimUmtsEngmodeInterFreqInfoInd
		{

			// 1 for EEMOPT
			processEMUmtsInterFreqInfoInd(reqHandle, pParam);

			break;
		}
		/* 4. UMTS */
		case CI_DEV_PRIM_UMTS_ENGMODE_INTERRAT_INFO_IND:        //CiDevPrimUmtsEngmodeInterRatInfoInd
		{

			// for EEMOPT
			processEMUmtsInterRatInfoInd(reqHandle, pParam);

			break;
		}
#endif
		case CI_DEV_PRIM_LTE_ENGMODE_SVCCELL_INFO_IND:
		{
			// for EEMOPT
			processEMLteINFOSVCInfoInd(reqHandle, pParam);
			
			#ifdef QUECTEL_OPEN_CPU
			if(!IsMiniSystem())
			{
			quec_nw_event_ind(GET_AT_HANDLE(reqHandle),pParam,QUEC_NW_EVENT_LTE_ENGMODE_SVCCELL_INFO);
			}
			#endif
			break;
		}
		case CI_DEV_PRIM_LTE_ENGMODE_INTRAFREQ_INFO_IND:
		{
			processEMLteIntraFreqInfoInd(reqHandle,pParam);
			#ifdef QUECTEL_OPEN_CPU
			
			if(!IsMiniSystem())
			{
			quec_nw_event_ind(GET_AT_HANDLE(reqHandle),pParam,QUEC_NW_EVENT_LTE_ENGMODE_INTRAFREQ_INFO);
			}
			#endif

			break;
		}
		case CI_DEV_PRIM_LTE_ENGMODE_INTERFREQ_INFO_IND:
		{
			#ifdef AT_FOR_GW20180208SN
			if(gMMZRSSI == 3)
			{
				break;
			}
			#endif
			processEMLteInterFreqInfoInd(reqHandle,pParam);
			#ifdef QUECTEL_OPEN_CPU
			if(!IsMiniSystem())
			{
			quec_nw_event_ind(GET_AT_HANDLE(reqHandle),pParam,QUEC_NW_EVENT_LTE_ENGMODE_INTERFREQ_INFO);
			}
			#endif
			break;
		}
#ifndef LTEONLY_THIN		
		case CI_DEV_PRIM_LTE_ENGMODE_INTERRAT_INFO_IND:
		{
			processEMLteInterRatInfoInd(reqHandle,pParam);
			#ifdef QUECTEL_OPEN_CPU
			
			if(!IsMiniSystem())
			{
            quec_nw_event_ind(GET_AT_HANDLE(reqHandle),pParam,QUEC_NW_EVENT_LTE_ENGMODE_INTERRAT_INFO);
			}
			#endif
			break;
		}	
		case CI_DEV_PRIM_NETWORK_MONITOR_INFO_IND:        //CiDevPrimNetworkMonitorInfoInd
		{
			processNwMonitorInfoInd(reqHandle, pParam);
			break;
		}
#endif		
		case CI_DEV_PRIM_LP_NWDL_MSG_IND:
		{
			processLpNwdlMsgInfoInd(reqHandle, pParam);
			break;
		}
#ifndef LTEONLY_THIN			
		case CI_DEV_PRIM_LP_RRC_STATE_IND:
		{
			processLpRRCStateInd(reqHandle, pParam);
			break;
		}
#endif		
		case CI_DEV_PRIM_LP_MEAS_TERMINATE_IND:
		{
			processLpMeasTerminateInd(reqHandle, pParam);
			break;
		}
		case CI_DEV_PRIM_LP_RESET_STORED_UE_POS_IND:
		{
			processLpResetUEPosInd(reqHandle, pParam);
			break;
		}
		case CI_DEV_PRIM_DIP_CHANNEL_CHANGE_IND:
		{
			processDIPChannelChangeInd(reqHandle, pParam);
			break;
		}
#ifndef LTEONLY_THIN			
		case CI_DEV_PRIM_CURRENT_AMR_CODEC_IND:
		{
#ifdef AT_FOR_GW20180208SN
			if(gMMZRSSI == 3)
			{
				break;
			}
#endif
			processCurrentAMRCodecInd(reqHandle, pParam);
			break;
		}
		case CI_DEV_PRIM_LTE_COEX_INFO_IND:
		{
			processLteCoexInfoInd(reqHandle, pParam);
			break;
		}
		#ifdef PLATFORM_FOR_PS_LW

		case 
		/**< \brief Indicates RB Test Loopback Mode status. */
		CI_DEV_PRIM_RB_TEST_MODE_IND:
		{
			processRBTestLoopbackModeInd(reqHandle, pParam);
			break;
		}
		#endif
		case CI_DEV_PRIM_T323_IND:
		{
			processT323Ind(reqHandle, pParam);
			break;
		}
#endif	
#ifdef AGPS_ENABLE
		case CI_DEV_PRIM_LP_OTDOA_MEAS_IND:
		{
			processLpOtdoaMeasInd(reqHandle, pParam);
			break;
		}
	    case CI_DEV_PRIM_RETRIEVE_LOCATION_IND:
	    {
			DBGMSG("[MDT][%s] CI_DEV_PRIM_RETRIEVE_LOCATION_IND",__FUNCTION__);
	        processRetrieveLocationInd(reqHandle,pParam);
	        break;
	    }
#endif		
		case CI_DEV_PRIM_L1DEBUG_INFO_IND:
		{
			processL1debugInd(pParam);
			break;
		}
		
		#ifdef QUEC_QSCLKEX_ENABLE
        case CI_DEV_PRIM_COMMON_REPORT_IND:
        {
            quec_process_lte_attach_reject_ind(pParam);
            //destin reject code 2020.10.27
#ifdef QUEC_CEER_ESM_REJECT_CAUSE_SUPPORT
            quec_get_lte_attach_reject_cause_string(indHandle, pParam);
#endif
            break;
        }
        #endif
        #ifdef QUECTEL_JAMDET_FEATURE
	    case CI_DEV_PRIM_CELLS_INFO_IND:
	    {
		    processJammingDetectionByCellsInfoInd(reqHandle,pParam);
		    break;
	    }
        #endif
		default:
			break;
	}

	/* free up the indication memory */
//	atciSvgFreeIndMem( svgId, primId, pParam );

	return;
}

#ifdef AGPS_ENABLE	
/****************************************************************************************
*  FUNCTION:  agpsSendInd
*
*  PARAMETERS: 
*  		sim_slot: 1 means SIM1; 2 means SIM2
*       ind_str:  
*
*  DESCRIPTION: interface to send IND to all AT channels
*
*  RETURNS: void
*
****************************************************************************************/
void agpsSendInd(UINT32 sim_slot, char* ind_str)
{
    UINT32 ind_channel = IND_REQ_HANDLE;

    if(ind_str == NULL)
    {
        CPUartLogPrintf("%s: exit, ind_str is NULL", __FUNCTION__);
        return;
    }        
    
    if(sim_slot == 1)
        ind_channel = IND_REQ_HANDLE;
    else if(sim_slot == 2)
        ind_channel = IND_REQ_HANDLE_1;
    else
    {
        CPUartLogPrintf("%s: exit, invalid sim_slot value", __FUNCTION__);
        return;
    }

	ATRESP(ind_channel, 0, 0, ind_str);    
}
#endif

