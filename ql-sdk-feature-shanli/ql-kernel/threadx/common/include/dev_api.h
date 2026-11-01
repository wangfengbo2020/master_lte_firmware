/******************************************************************************
*(C) Copyright 2008 Marvell International Ltd.
* All Rights Reserved
******************************************************************************/
/*--------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  Filename: dev_api.h
 *
 *  Description: API interface for Device service
 *
 *  History:
 *   Oct 17, 2008 - Qiang XU Creation of file
 *
 *  Notes:
 *
 ******************************************************************************/

#ifndef __DEV_API_H__
#define __DEV_API_H__

#include "ci_dev.h"

typedef struct ComConfig_struct
{
    int umtsWbAmr;
    int gsmWbAmr;
    int vendor;
    int manufacture;
    int lteCategory;
    int mutiSlotPowerProfile;
    int lteSMSOnly;
    int ecSupported;
    int epcoSupported;
    int hccpSupported;
    int mdrbSupported;
    int cpBackoff;
    int nslp;
    int eab;
    int rohc;
}ComConfig;

CiReturnCode DEV_GetFunc(UINT32 atHandle, BOOL bCpConfig);
CiReturnCode DEV_SetFunc(UINT32 atHandle, int funcVal, int resetVal, BOOL isExt, INT32 IsCommFeatureConfig, INT32 CommFeatureConfig);
CiReturnCode DEV_GetDevStatus(UINT32 atHandle);
CiReturnCode DEV_SetEngineModeReportOption(UINT32 atHandle, int modeVal, int timeVal);
CiReturnCode DEV_GetSerialNumId(UINT32 atHandle);
CiReturnCode DEV_GetEngineModeInfo(UINT32 atHandle);
CiReturnCode DEV_GetSupportedBandModeReq(UINT32 atHandle);
CiReturnCode DEV_GetBandModeReq(UINT32 atHandle);
CiReturnCode DEV_SetBandModeReq(UINT32 atHandle, UINT8 networkMode, UINT8 preferredMode,  UINT32 gsmMode, UINT32 umtsMode, UINT32 eutranModeH, UINT32 eutranModeL, UINT8 roamingConfig, UINT8 srvDomain, UINT8 bandPriorityFlag,BOOL islteduallink,UINT32 EUTRANBandModeExt);
CiReturnCode DEV_GetWirelessModeReq(UINT32 atHandle);
CiReturnCode DEV_SetWirelessModeReq(UINT32 atHandle, UINT8 networkMode, UINT8 preferredMode);
CiReturnCode DEV_SetPOWERIND(UINT32 atHandle, UINT32 powerState);

CiReturnCode DEV_SetEngModeIndicatorOption(UINT32 atHandle, int modeVal, int timeVal);
CiReturnCode DEV_GetEngModeInfo(UINT32 atHandle, CiDevEngmodeType type );
CiReturnCode DEV_setLPNWUL(UINT32 atHandle, UINT8 *msg_data, UINT32 msg_data_len, UINT8 count, UINT8 bearer_type, UINT8 isFinalRsp, UINT8 *add_info, UINT32 add_info_len);
CiReturnCode DEV_SysConfig(UINT32 atHandle, int modVal, int acqVal, int bandVal, int roamVal, int srvVal );
CiReturnCode DEV_GetSysConfig(UINT32 atHandle);
CiReturnCode DEV_GetLteMeas(UINT32 atHandle);
CiReturnCode DEV_GetSoftwareVersionNumber(UINT32 atHandle);
CiReturnCode DEV_SetSoftwareVersionNumber(UINT32 atHandle, const char* sv);
CiReturnCode DEV_SetHsdpaModeReq(UINT32 atHandle, UINT8 mode, UINT8 dl_category, UINT8 ul_category, UINT8 cpc_state, UINT8 dpaCategoryExt, UINT8 edchCategoryExt, UINT8 fdpchState, UINT8 efdpchState);
CiReturnCode DEV_GetHsdpaModeReq(UINT32 atHandle);

CiReturnCode DEV_SetPowerBackOffReq(UINT32 atHandle, UINT8 option,UINT8 value, UINT8 nwMode, UINT8 band);
CiReturnCode DEV_GetComConfigReq(UINT32 atHandle, UINT32 tokens);
CiReturnCode DEV_SetComConfigReq(UINT32 atHandle, ComConfig* ComConfigData);
CiReturnCode DEV_GetRsrpReq(UINT32 atHandle);
CiReturnCode DEV_GetRsrqReq(UINT32 atHandle);
CiReturnCode DEV_Get_internal_revision_Req(UINT32 atHandle);


CiReturnCode DEV_SetGsmModeTxRxReq(UINT32 atHandle, CiDevGsmTxRxOption option, UINT8 gsmBandMode, UINT16 arfcn, UINT32 afcDac, UINT32 txRampScale, UINT32 rxGainCode);
CiReturnCode DEV_ReadRFTemperatureReq(UINT32 atHandle, UINT8 tempType);
CiReturnCode DEV_SetLTEModeTxRxReq(UINT32 atHandle, CiDevLteTxRxOption option, UINT16 frequency, INT16 power, UINT8 bandwidth);

CiReturnCode DEV_SetMccMncCcReq(UINT32 atHandle, UINT16 countryCode, UINT16 operCode, UINT8 *customerCode);
CiReturnCode DEV_GetMccMncCcReq(UINT32 atHandle);
CiReturnCode DEV_GetSinrReq(UINT32 atHandle);
CiReturnCode DEV_GetRssiReq(UINT32 atHandle);

void devCnf(CiSgOpaqueHandle opSgCnfHandle,     CiServiceGroupID svgId, CiPrimitiveID primId, CiRequestHandle reqHandle, void* paras);
void devInd(CiSgOpaqueHandle opSgOpaqueHandle, CiServiceGroupID svgId, CiPrimitiveID primId, CiIndicationHandle indHandle, void* pParam);
void resetDevParas(void);
CiReturnCode DEV_SetWcdmaModeTxRxReq(UINT32 atHandle, CiDevGsmTxRxOption option, UINT16 dlUarfcn,
				UINT16 ulUarfcn, UINT8 paMode, UINT16 apcDac, INT16 afcDac);

CiReturnCode DEV_GetLteCoexInfoReq(UINT32 atHandle);
CiReturnCode DEV_SetLteCoexReportOptionReq(UINT32 atHandle, UINT8 enable);


CiReturnCode DEV_GetWbAmrReq(UINT32 atHandle, UINT32 tokens);
CiReturnCode DEV_SetWbAmrReq(UINT32 atHandle, UINT32 umtsWbAmr, UINT32 gsmWbAmr);
CiReturnCode DEV_SetEngModeIndicatorOption(UINT32 atHandle, int modeVal, int timeVal);

CiReturnCode DEV_SetIMLConfigReq(UINT32 atHandle, UINT8 IMLType, int datalen, char *data);
CiReturnCode DEV_GetIMLConfigReq(UINT32 atHandle);

#ifdef PLATFORM_FOR_PS_LW
CiReturnCode DEV_SetLTEBand(UINT32 atHandle, UINT8 numOfLteBands, int*lteBands);
CiReturnCode DEV_GetLTEBand(UINT32 atHandle);
CiReturnCode DEV_GetCsc_req(UINT32 atHandle);
#endif
CiReturnCode DEV_GetOperCfg_req(UINT32 atHandle, UINT8 mode, UINT32 val);
CiReturnCode DEV_SetOperCfg_req(UINT32 atHandle, CiDevPrimSetOperConfigReq *setOperCfgReq);
CiReturnCode DEV_GetMEDCR(UINT32 atHandle, UINT8 position);
CiReturnCode DEV_SetMEDCR(UINT32 atHandle, UINT8 position, UINT8 value);
CiReturnCode DEV_GetCellInfo(UINT32 atHandle);
CiReturnCode DEV_GetLPECID(UINT32 atHandle);
CiReturnCode DEV_GetLPOtdoaReq(UINT32 atHandle, UINT8 *msg_data, UINT32 msg_data_len, UINT8 count);
CiReturnCode DEV_SetLPOtdoaAbort(UINT32 atHandle);

void checkDevRet( CiRequestHandle reqHandle, CiDevRc result );
void devInd_2(CiSgOpaqueHandle opSgOpaqueHandle,
	    CiServiceGroupID svgId,
	    CiPrimitiveID primId,
	    CiIndicationHandle indHandle,
	    void*               pParam);


void devCnf_2(CiSgOpaqueHandle opSgCnfHandle,
	    CiServiceGroupID svgId,
	    CiPrimitiveID primId,
	    CiRequestHandle reqHandle,
	    void*              paras);




#define CI_DEV_PRIM_GET_WIRELESS_MODE_REQ (CI_DEV_PRIM_LAST_COMMON_PRIM + 1)
#define CI_DEV_PRIM_GET_SINR_REQ (CI_DEV_PRIM_LAST_COMMON_PRIM + 2)
#define CI_DEV_PRIM_GET_RSSI_REQ (CI_DEV_PRIM_LAST_COMMON_PRIM + 3)
#define CI_DEV_PRIM_GET_CELL_INFO (CI_DEV_PRIM_LAST_COMMON_PRIM + 4)
#define PRI_DEV_PRIM_GET_CP_FUNC_REQ (CI_DEV_PRIM_LAST_COMMON_PRIM + 1)
#define PRI_DEV_PRIM_GET_RSRP_REQ (CI_DEV_PRIM_LAST_COMMON_PRIM + 2)
#define PRI_DEV_PRIM_GET_RSRQ_REQ (CI_DEV_PRIM_LAST_COMMON_PRIM + 3)

typedef enum ATCI_HSDPA_MODE {
	ATCI_HSDPA_OFF_HSUPA_OFF = 0,
	ATCI_HSDPA_ON_HSUPA_ON,
	ATCI_HSDPA_ON_HSUPA_OFF,
	ATCI_HSDPA_ON_HSUPA_ON_DLDC,
	ATCI_HSPA_REL6,
} AtciHsdpaMode;

#define MAX_RESPBUFF_SIZE (2048 - 4)      //4 is the space for the '\r', '\n' added at the begin and end of respString in function atRespStr()
/* enum of wireless parameter type*/

#define CI_DEV_SIGNALING_PACKET_NON_PAYLOAD_LEN 17
#define BIT_NUM_ONE_OCTET 8
#define TEST_BIT(val, nr)	(((1UL << ((nr) & ((sizeof(val) * BIT_NUM_ONE_OCTET - 1)))) & (val)) != 0)

//fix build warnning
int GetCfunValue(void);
void SetCfunValue(int value);
void wait_cfun_done(void);
BOOL isHandleForMasterSim(UINT32 reqHandle);
CiReturnCode Dev_L1Debug(UINT32 atHandle, CHAR *data, UINT16 length);

#if defined(QUEC_BLACK_CELL_SUPPORT)|| defined(QUEC_THIN_BLACK_CELL_SUPPORT)
#define QUEC_BLACKCELL_REJECT_COUNT_MAX (10)

typedef struct 
{
    UINT32 arfcn;   /*gsm:arfcn wcdma: uarfcn lte:earfcn*/
    UINT16 cellid;  /*gsm:bsic wcdma:psc lte:pci*/
    UINT8  rat;     /*0:gsm 1:wcdma 2:lte*/
    UINT8  Optype;  /*0 is add,1 is delete blackcell*/
}quec_cellid_s_t;

typedef struct 
{
    UINT32 arfcn;
    UINT16 cell_id;
	UINT8  event;
}quec_blackcell_item_s_t;

UINT8 quec_get_oneshot_flag(void);
void quec_set_oneshot_flag(UINT8 flag);
void quec_send_oneshot_get_cellid(UINT8 type);
#endif

#ifdef QUEC_BLACK_CELL_SUPPORT
void quec_set_oneshot_type(UINT8 type);
UINT8 quec_get_oneshot_type(void);
#endif

#ifdef SINGLE_SIM
CiReturnCode DEV_SetSimSlot(UINT32 atHandle, int simSlot);
CiReturnCode DEV_GetSimSlot(UINT32 atHandle);
#endif

#endif

