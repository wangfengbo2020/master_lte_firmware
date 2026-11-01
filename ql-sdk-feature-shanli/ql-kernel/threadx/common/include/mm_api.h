/******************************************************************************
*(C) Copyright 2008 Marvell International Ltd.
* All Rights Reserved
******************************************************************************/
/*--------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  Filename: mm_api.h
 *
 *  Description: API interface for Network service
 *
 *  History:
 *   Oct 15, 2008 - Qiang XU Creation of file
 *
 *  Notes:
 *
 ******************************************************************************/


#ifndef __MM_API_H__
#define __MM_API_H__

#include "ci_mm.h"

#ifdef CRANE_MCU_DONGLE
struct mmExtendedSignal
{
	int rssi;
	int ber;
	int rscp;
	int ecno;
	int rsrq;
	int rsrp;
	int sinr;
};
#ifdef QUECTEL_NETWORK_SUPPORT //connor 2018/11/16 typedef this struct for quec to use
typedef struct mmExtendedSignal mmExtendedSignal_quec;
#endif

struct mmSignal
{
	int rssi;
	int ber;
};

void getExtendedSignal(UINT32 atHandle, struct mmExtendedSignal *retExtendSignal);
void getSignal(UINT32 atHandle, struct mmSignal *retSignal);
void getSavedSignal(UINT32 atHandle, struct mmExtendedSignal *retSavedSignal);
void getSysMode(UINT32 atHandle, INT32 *sysMainMode, INT32 *sysSubMode);
void getSavedSysMode(UINT32 atHandle, INT32 *sysMainMode);

#endif

#ifdef QUECTEL_NETWORK_SUPPORT
//±|à?csq issue
int quec_get_current_net_regstatus(void);
/*isaac 20201114 无卡取基站信息*/
void quec_save_current_reg_mode(int CurrRegMode);
int quec_get_current_reg_mode(void);
#endif

CiReturnCode MM_QueryRegOption(UINT32 atHandle);
CiReturnCode MM_GetRegStatus(UINT32 atHandle);
CiReturnCode MM_SetRegOption(UINT32 atHandle, INT32 regOption);
CiReturnCode MM_QuerySuppOperator(UINT32 atHandle);
CiReturnCode MM_GetCurrOperator(UINT32 atHandle);
CiReturnCode MM_SetCurrOperator(UINT32 atHandle, int modeVal, int formatVal, char *networkOperator, int opeStrLen, int accTchVal);
CiReturnCode MM_GetPrefOperator(UINT32 atHandle);
CiReturnCode MM_SetPrefOperator(UINT32 atHandle, int indexVal, int formatVal, INT32 ActVal, char *networkOperator, int length);
CiReturnCode MM_GetTimeZoneReportOption(UINT32 atHandle);
CiReturnCode MM_QuerySuppOpeInfo(UINT32 atHandle, int opeIndex);
CiReturnCode MM_GetPrefOpeInfo(UINT32 atHandle, int opeIndex);
CiReturnCode MM_GetSignalQuality(UINT32 atHandle);
CiReturnCode MM_GetSubscriber(UINT32 atHandle, int index);
CiReturnCode MM_GetNumberOfEntries(UINT32 atHandle);
CiReturnCode MM_SetNwModeIndSetting(UINT32 atHandle, int bNwModeInd);
CiReturnCode MM_GetNwModeIndSetting(UINT32 atHandle);
CiReturnCode MM_SelectCPLS(UINT32 atHandle, UINT8 listIndex);
CiReturnCode MM_GetCPLS(UINT32 atHandle);
CiReturnCode MM_GetBANDIND(UINT32 atHandle);
CiReturnCode MM_SetBANDIND(UINT32 atHandle, BOOL bEnableBandInd);
CiReturnCode MM_GetstarTimeZoneReportOption(UINT32 atHandle);
CiReturnCode MM_SetCellLOCK(UINT32 atHandle, UINT8 mode, UINT8 act, UINT8 band, INT32 freq, INT16 cellId);
CiReturnCode MM_GetCellLOCK(UINT32 atHandle);
CiReturnCode MM_SetRejectCauseStatus(UINT32 atHandle, int bEnableRejectCauseInd);
CiReturnCode MM_GetRejectCauseStatus(UINT32 atHandle);
CiReturnCode MM_GetRejectCauseHistory(UINT32 atHandle);
CiReturnCode MM_GetSysInfo(UINT32 atHandle);
CiReturnCode MM_GetNASIntegrityCheckFlag(UINT32 atHandle);
CiReturnCode MM_SetNASIntegrityCheckFlag(UINT32 atHandle, BOOL nasIntegrityCheckFlag);
CiReturnCode MM_GetExtendedSignalQuality(UINT32 atHandle);
CiReturnCode MM_GetOperatorName(UINT32 atHandle);
CiReturnCode MM_GetRealTimeClock(UINT32 atHandle);
CiReturnCode MM_SetRealTimeClock(UINT32 atHandle, int year, int month, int day, int hour, int min, int sec, int timezone);

CiReturnCode MM_CancelPlmnSearch(UINT32 atHandle);

CiReturnCode MM_SetWbCellLock(UINT32 atHandle, UINT8 mode, UINT8 act, UINT8 gsmBand, UINT8 umtsBand, UINT16 arfcn, UINT16 scramblingCode);

void mmCnf(CiSgOpaqueHandle opSgCnfHandle,      CiServiceGroupID svgId, CiPrimitiveID primId, CiRequestHandle reqHandle, void* paras);
void mmInd(CiSgOpaqueHandle opSgOpaqueHandle, CiServiceGroupID svgId, CiPrimitiveID primId, CiIndicationHandle indHandle, void* pParam);
void mmCnf_2(CiSgOpaqueHandle opSgCnfHandle,      CiServiceGroupID svgId, CiPrimitiveID primId, CiRequestHandle reqHandle, void* paras);
void mmInd_2(CiSgOpaqueHandle opSgOpaqueHandle, CiServiceGroupID svgId, CiPrimitiveID primId, CiIndicationHandle indHandle, void* pParam);

void resetMmParas(void);
//mengliang add 20120314 for LTE PC AT command server  -s
CiReturnCode MM_QueryAct(UINT32 atHandle);
//mengliang add 20120314 for LTE PC AT command server  -e

/*Added by Alan for at+bglteplmn on 08032012, begin*/
CiReturnCode MM_QuerySuppLteOperator(UINT32 atHandle);
CiReturnCode MM_QuerySuppLteOpeInfo(UINT32 atHandle, int opeIndex);
CiReturnCode MM_GetLteCurrOperator(UINT32 atHandle);
CiReturnCode MM_SetLteCurrOperator(UINT32 atHandle, BOOL modeVal, UINT16 intervalVal);
/*Added by Alan for at+bglteplmn on 08032012, end*/

CiReturnCode MM_SetCSQConfig(UINT32 atHandle, UINT8 option, UINT8 config);
CiReturnCode MM_TriggerUserReselection(UINT32 atHandle);
CiReturnCode MM_SetEmergencyNumbersReport(UINT32 atHandle, UINT8 reporting);
CiReturnCode MM_GetCSQConfig(UINT32 atHandle);
CiReturnCode MM_GetEmergencyNumbers(UINT32 atHandle);
CiReturnCode MM_SetNwEmergencyBearerService(UINT32 atHandle, UINT8 reporting);
CiReturnCode MM_GetNwEmergencyBearerService(UINT32 atHandle);
CiReturnCode MM_SetSrvccSupport(UINT32 atHandle, UINT8 uesrvcc);
CiReturnCode MM_GetSrvccSupport(UINT32 atHandle);
#ifdef PLATFORM_FOR_PS_LW
CiReturnCode MM_GetSecurityCapability_Req(UINT32 atHandle);
CiReturnCode MM_SetSecurityCapability_Req(UINT32 atHandle, INT32 nasSeccap, INT16 umtsRrcCAPCap, INT16 umtsRrcIPCcap);
#endif
CiReturnCode MM_SetImsNwReportMode(UINT32 atHandle, UINT8 reporting);
CiReturnCode MM_GetImsNwReportMode(UINT32 atHandle);
CiReturnCode MM_GetCurrentCsg(UINT32 atHandle);
CiReturnCode MM_GetSsacStatus(UINT32 atHandle);
CiReturnCode MM_GetOperInfo(UINT32 atHandle);
CiReturnCode MM_GetAsrCurrOperator(UINT32 atHandle);
CiReturnCode MM_GetRegMode(UINT32 atHandle);
CiReturnCode MM_EcallRegSet(UINT32 atHandle, int action);



BOOL libCheckMMRet( CiRequestHandle atHandle, CiMmResultCode result );



#define CI_MM_PRIM_GET_STAR_NITZ_REQ (CI_MM_PRIM_LAST_COMMON_PRIM + 1)
#define CI_MM_PRIM_GET_OPER_NITZ_REQ (CI_MM_PRIM_LAST_COMMON_PRIM + 2)
#define CI_MM_PRIM_GET_NUM_NETWORK_SEARCH_REQ	(CI_MM_PRIM_LAST_COMMON_PRIM + 3)
#define CI_MM_PRIM_GET_CURRENT_REG_MODE_REQ 	(CI_MM_PRIM_LAST_COMMON_PRIM + 4)
#define MAX_REJECTCAUSE_HISTORY 10



#endif



