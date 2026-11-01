/******************************************************************************
*(C) Copyright 2008 Marvell International Ltd.
* All Rights Reserved
******************************************************************************/
/*--------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  Filename: ps_api.h
 *
 *  Description: API interface for packet service
 *
 *  History:
 *   Sep 18, 2008 - Rovin Yu Creation of file
 *
 *  Notes:
 *
 ******************************************************************************/


#ifndef __PS_API_H__
#define __PS_API_H__

#include "ci_ps.h"

/*UPGRADE_LTE_ONLY for FP LTE_ONLY*/
#if defined(ENABLE_DM_LTEONLY) || defined(UPGRADE_LTE_ONLY)
#define ATCMD_UNIFY_ACT_CI
#endif

//#define TEL_REG_OPTION_PERSIST
#ifdef CRANE_MCU_DONGLE
#include "mm_api.h"
#define ATCMD_PDP_CONTEXT
typedef void (*networkStatusChangeCb) (int, int);
typedef void (*signalChangeCb) (int, struct mmSignal *);
typedef void (*extendSignalChangeCb) (int, struct mmExtendedSignal *);
typedef void (*networkModeChangeCb) (int, int);
typedef void (*simStatusChangedCb) (int, int);
typedef void (*pinStatusChangedCb) (int, int);
typedef struct _networkInfoCbs {
	networkStatusChangeCb    nwStatusChanged;
	networkModeChangeCb  nwModeChanged;
	signalChangeCb  signalChanged;
	extendSignalChangeCb  extendSignalChanged;
	simStatusChangedCb       simStatusChanged;
	pinStatusChangedCb      pinStatusChanged;
} networkInfoCbs;
extern void setupNetworkCbs(networkInfoCbs *customerCbs);
#endif

#if defined QUECTEL_PROJECT_CUST
typedef struct
{
	CiPsPrimAuthenticateReq authReq_backup;
	const char *info_text_p_backup;
	CiPsPrimSetDefaultPdpAuthenticateReq setDefPdpAuthReq_backup;
} quec_pdpauthinfo_type;
#endif

#ifdef LWIP_IPNETBUF_SUPPORT
typedef struct {
	CHAR apn[TEL_AT_CGDCONT_2_APN_STR_MAX_LEN + 1];
	UINT8 ipType;
	UINT8 defined;
}telPsPdpApn;

typedef struct {
	CHAR userName[TEL_AT_AUTH_2_USERNAME_STR_MAX_LEN + 1];
	CHAR password[TEL_AT_AUTH_3_PASSWORD_STR_MAX_LEN + 1];
	UINT8 authType;
	UINT8 defined;
}telPsPdpAuth;

typedef struct
{
    CiPsPdpIpAddr     ipv4Addr;
    CiPsPdpIpAddr     ipv6Addr;
    CiBoolean         dcompPresent;
    CiPsDcomp         dcomp;
    CiBoolean         hcompPresent;
    CiPsHcomp         hcomp;
    CiBoolean         pdParasPresent;
    CiString          pdParas;
    CiBoolean         ipAddrAllocPresent;
    CiPsIpv4AllocType ipAddrAlloc;
    CiBoolean         reqTypePresent;
    CiPsReqType       reqType;
    CiBoolean         pCscfDiscoveryPresent;
    CiPsPcscfDiscoveryType pCscfDiscovery;
    CiBoolean         imCnSignallingFlagIndPresent;
    CiPsImCnSignallingFlagIndType  imCnSignallingFlagInd;
}telPsPdpOpt;

typedef struct {
	telPsPdpApn apnInfo;
	telPsPdpAuth authInfo;
	telPsPdpApn activedApnInfo;
	telPsPdpOpt opt;
	UINT8 cid;
	UINT8 reDefined;
	UINT8 bActived;
	UINT8 activedStatus;
}telPsPdpCtx;

typedef struct {
	CHAR apn[TEL_AT_CGDCONT_2_APN_STR_MAX_LEN + 1];
	CHAR epsApn[TEL_AT_CGDCONT_2_APN_STR_MAX_LEN + 1];
	UINT8 ipType;
	UINT8 epsIpType;
	UINT8 defined;
}telPsDefaultPdpApn;

#ifdef ATCMD_PDP_CONTEXT
typedef struct {
	telPsDefaultPdpApn apnInfo;
	UINT8 cid;
	Ipv4Info * ip4Info;
	Ipv6Info * ip6Info;
	void *next;
} telPdpInfo;

void telUpdatePdpInfoListApn(UINT8 cid,  CHAR *apn, UINT8 ipType);
telPdpInfo *telGetPdpInfo(UINT8 cid);
telPdpInfo *telGetPdpApnInfo(UINT8 cid);
#endif
telPsPdpCtx *telGetPdpCtx(UINT8 cid);
void freePacketFilterList(PacketFilterInfo* PFList);
void freePdpContextList(PdpContextList *pList);
void freePdpCtxList(UINT32 sAtpIndex);
PdpContextList *getPdpListHead(int sAtpIndex);
PacketFilterInfo *getTftListHead(int sAtpIndex);
PdpContextList *GetCurrentPdpList(int sAtpIndex);
PacketFilterInfo* GetCurrentTFTList(int sAtpIndex);
BOOL telSetPdpCtxApnDS(UINT32 reqHandle, UINT8 cid, telPsPdpApn *apnInfo);
BOOL telSetPdpCtxAuthDS(UINT32 reqHandle, UINT8 cid, telPsPdpAuth *authInfo);
BOOL telSetPdpCtxApn(UINT8 cid, telPsPdpApn *apnInfo);
BOOL telSetPdpCtxAuth(UINT8 cid, telPsPdpAuth *authInfo);
BOOL telSetPdpCtxOptDS(UINT32 reqHandle, UINT8 cid, telPsPdpOpt *opt);
void copyCiPdpCtx2Opt(telPsPdpOpt *telPdpOpt, CiPsPdpCtx *ciPdpCtx);
void telUpdateActiveApnInfo(UINT8 cid, CHAR *apn, UINT8 ipType);
UINT8 getCregReady(UINT32 atHandle);
UINT8 getCgregReady(UINT32 atHandle);
INT32 getCgregStatus(UINT32 atHandle);
UINT8 getCeregReady(UINT32 atHandle);
INT32 getCeregStatus(UINT32 atHandle);
INT32 get_current_reg_status(UINT32 atHandle);
int is_E20_module_type(void);
void updateCregReady(int atHandle, int regStatus);
UINT8 get_force_reg_flag(void);
void set_force_reg_flag(UINT8 flag);
void setMtPdp(UINT8 cid, BOOL isMT);
BOOL isMtPdp(UINT8 cid);
BOOL isLTENetwork(INT32 atHandle);
BOOL IsDatalinkAllowed(void);
BOOL GetBIPEnableFlag(void);
BOOL isHandleForSim0(UINT32 reqHandle);
BOOL isHandleForMasterSim(UINT32 reqHandle);
BOOL ppp_get_connect_flag(UINT8 cid);
void setUnknownPdpCause(UINT32 atHandle, UINT8 setVaue);
UINT16 getUnknownPdpCause(UINT32 atHandle);
BOOL getErrorIndFlag(int atHandle, UINT8 cid);
void clearErrorIndFlag(int atHandle, UINT8 cid);
void sendRedialToCm(UINT32 atHandle);
void removeEpsApnSuffix(CHAR *apn);
void telClearPdpRedefinedFlag(UINT8 cid);
void sendQueryCgdcont(UINT32 reqHandle);
void reset_redial_times_cm(void);
void updateMTPdpTft(UINT32 reqHandle, UINT8 changeReason);
void updateSysMode(UINT32 atHandle, UINT8 Act, INT32 regStatus);
void updateCgregStatus(int atHandle, int regStatus);
void updateCeregStatus(int atHandle, int regStatus);
void telClearPdpInfo(UINT8 cid);
CiReturnCode PS_GetSysGPRSRegStatus (UINT32 atHandle);
CiReturnCode PS_Get4GSysInfoRegStatus(UINT32 atHandle);

#endif
#ifdef VOLTE_ENABLE
extern int is_ims_cid(int simid, int cid,char *apn);
#endif
#ifdef PPP_ENABLE
extern int get_cgreg_status_rsp(int atp_index, char *rsp_buf, int type);
extern void ppp_clear_use_eps_apn(UINT32 atp_index);
void ppp_store_configure_params(int atp_index, int cid, char *apn,  int ip_type);
BOOL need_ppp_process_at_response(int atp_index);
#endif

CiReturnCode PS_GetTftList (UINT32 atHandle);
CiReturnCode PS_GetTFTCapsREQ (UINT32 atHandle);//mengliang add 20110320
CiReturnCode PS_DeleteTft (UINT32 atHandle, UINT32 dwContextID);
CiReturnCode PS_SetTftFilter (UINT32 atHandle, UINT32 dwContextID, const CiPsTftFilter *tftFilter);
CiReturnCode PS_GetGPRSActiveCidList (UINT32 atHandle);
CiReturnCode PS_ModifyGPRSContext(UINT32 atHandle, UINT32 dwContextID, BOOL doAll);
CiReturnCode PS_SetGPRSRegStatus (UINT32 atHandle, UINT32 state);
CiReturnCode PS_GetGPRSRegStatus (UINT32 atHandle);
CiReturnCode PS_GetGPRSContextList (UINT32 atHandle);
CiReturnCode PS_SetGPRSContext (UINT32 atHandle, const CiPsPdpCtx* lpGprsContext);
CiReturnCode PS_DeleteGPRSContext (UINT32 atHandle, UINT32 dwContextID);
CiReturnCode PS_GetQualityOfServiceList (UINT32 atHandle, BOOL isMin);
CiReturnCode PS_SetQualityOfService (UINT32 atHandle, UINT32 dwContextID, const CiPsQosProfile* lpGprsQosProfile, BOOL isMin);
CiReturnCode PS_SetGPRSAttached(UINT32 atHandle, BOOL fAttached, CiPsAttachStateCause cause);
CiReturnCode PS_GetGPRSAttached (UINT32 atHandle);
CiReturnCode PS_GetGPRSContextActivatedList (UINT32 atHandle);
CiReturnCode PS_SetGPRSContextActivated(UINT32 atHandle, UINT32 dwContextID, BOOL fContextActivation, BOOL doAll);
CiReturnCode PS_EnterGPRSDataMode (UINT32 atHandle, UINT32 dwContextID, CiPsL2P l2p);
CiReturnCode PS_Get3GQualityOfServiceList(UINT32 atHandle,CiPs3GQosType type);
CiReturnCode PS_Set3GQualityOfService(UINT32 atHandle,UINT32 dwContextID,const CiPs3GQosProfile * lp3GQosProfile,CiPs3GQosType type);
CiReturnCode PS_GetGprsCapsQos(UINT32 atHandle,BOOL isMin);
CiReturnCode PS_Get3GCapsQos(UINT32 atHandle,CiPs3GQosType type);
CiReturnCode PS_GetSecondaryContextList(UINT32 atHandle);
CiReturnCode PS_SetSecondaryPDPContext(UINT32 atHandle,const CiPsSecPdpCtx * lpSecondaryPDPContext);
CiReturnCode PS_GetSecondaryContextRange (UINT32 atHandle);
CiReturnCode PS_DeleteSecondaryPDPContext(UINT32 atHandle, UINT32 dwContextID);
CiReturnCode PS_SendAUTHReq(UINT32 atHandle, const CiPsPrimAuthenticateReq * lpAuthReq );
CiReturnCode PS_GetGPRSContextIP (UINT32 atHandle, UINT32 dwContextID);
CiReturnCode PS_FastDormancy(UINT32 atHandle);
/* Added by Daniel for LTE PC AT command server 20120201, begin */
CiReturnCode PS_Get4GQualityOfServiceList(UINT32 atHandle,UINT32 dwContextID);
CiReturnCode PS_Set4GQualityOfService(UINT32 atHandle,UINT32 dwContextID,const CiPs4GQosProfile * lp3GQosProfile);
CiReturnCode PS_Get4GCapsQos(UINT32 atHandle);
CiReturnCode PS_Delete4GEPSContext (UINT32 atHandle, UINT32 dwContextID);
CiReturnCode PS_ReadDynActPara(UINT32 atHandle);
CiReturnCode PS_ReadDynPara(UINT32 atHandle, UINT32 dwContextID);
CiReturnCode PS_defineCGDFLTtPara(UINT32 atHandle,const CiPsPrimDefineDefaultPdpCtxReq* ltedefalutpdp);
CiReturnCode PS_ReadCGDFLTtPara(UINT32 atHandle);

CiReturnCode PS_ReadSecDynActPara(UINT32 atHandle);
CiReturnCode PS_ReadSecDynPara(UINT32 atHandle, UINT32 dwContextID);

CiReturnCode PS_ReadDynActTFT(UINT32 atHandle);
CiReturnCode PS_ReadDynTFT(UINT32 atHandle, UINT32 dwContextID);

CiReturnCode PS_ReadDynActQOS(UINT32 atHandle);
CiReturnCode PS_ReadDynQOS(UINT32 atHandle, UINT32 dwContextID);

CiReturnCode PS_Get4GRep(UINT32 atHandle);
CiReturnCode PS_Get4GCapsRep(UINT32 atHandle);
CiReturnCode PS_Set4GRep(UINT32 atHandle, UINT32 mode, UINT32 bfr);

CiReturnCode PS_GetVoiceMode(UINT32 atHandle, UINT32 dwContextID);
CiReturnCode PS_GetCapsVoiceMode(UINT32 atHandle);
CiReturnCode PS_SetVoiceMode(UINT32 atHandle, UINT32 dwContextID, UINT32 mode);

CiReturnCode PS_GetEpsMode(UINT32 atHandle);
CiReturnCode PS_GetCapsEpsMode(UINT32 atHandle);
CiReturnCode PS_SetEpsMode(UINT32 atHandle, UINT32 mode);

CiReturnCode PS_Get4GCapsAddr(UINT32 atHandle);
CiReturnCode PS_Get4GAddr(UINT32 atHandle, UINT32 num, UINT32 *pCID);

CiReturnCode PS_Get4GRegStatus(UINT32 atHandle);
CiReturnCode PS_Set4GRegOption(UINT32 atHandle, INT32 regOption);

CiReturnCode PS_GetImsRegStatus(UINT32 atHandle);
CiReturnCode PS_SetImsRegOption(UINT32 atHandle, INT32 regOption);

CiReturnCode PS_GetGsmGprsClass(UINT32 atHandle);
CiReturnCode PS_GetGsmGprsClasses(UINT32 atHandle);
CiReturnCode PS_SetGsmGprsClass(UINT32 atHandle, char *classString, UINT16 length);

/* Added by Daniel for LTE PC AT command server 20120201, end */
CiReturnCode PS_SetFDY(UINT32 atHandle, UINT8 mode, UINT32 lcdOnTimerInterval, UINT32 lcdOffTimerInterval, UINT32 rel8LcdOnTimerInterval, UINT32 rel8LcdOffTimerInterval);
CiReturnCode PS_SetPsPowerOnAutoAttach(UINT32 atHandle, BOOL enable);
CiReturnCode PS_GetPsPowerOnAutoAttach(UINT32 atHandle);
CiReturnCode PS_SetPsPlusPaging(UINT32 atHandle, BOOL enable);

CiReturnCode PS_GetDefaultPDPContext(UINT32 atHandle, UINT8 type);
CiReturnCode PS_SetDefaultPDPContext(UINT32 atHandle, const CiPsPrimDefineDefaultPdpCtxReq* defaultPdpCtxInfo);

CiReturnCode PS_GetDefaultPdpAuthenticate(UINT32 atHandle,UINT8 type);
CiReturnCode PS_SetDefaultPdpAuthenticate(UINT32 atHandle, const CiPsPrimSetDefaultPdpAuthenticateReq* setDefPdpAuthReq);

CiReturnCode PS_GetAPNList(UINT32 atHandle);
CiReturnCode PS_SetAPNList(UINT32 atHandle, const CiPsPrimSetApnReq* setApnReq);

CiReturnCode PS_GetVoiceDomainPreference(UINT32 atHandle, CiBoolean eutran);
CiReturnCode PS_SetVoiceDomainPreference(UINT32 atHandle, UINT8 setting, CiBoolean eutran);

CiReturnCode PS_GetEpsUsageSetting(UINT32 atHandle);
CiReturnCode PS_SetEpsUsageSetting(UINT32 atHandle, UINT8 setting);
CiReturnCode PS_SetAclCheck (UINT32 atHandle, BOOL gsimAclPresent,BOOL gsimAclEnable,BOOL gpsAclPresent,BOOL gpsAclEnable);
CiReturnCode PS_SetPsdc_req(UINT32 atHandle, INT32 domainOption);
CiReturnCode PS_GetPsdc_req(UINT32 atHandle);
CiReturnCode PS_NotifyImsRegStateToCp(UINT32 atHandle, UINT8 state);

CiReturnCode PS_GetImsVoiceCallAvailability(UINT32 atHandle);
CiReturnCode PS_SetImsVoiceCallAvailability(UINT32 atHandle, UINT8 state);
CiReturnCode PS_GetImsSmsAvailability(UINT32 atHandle);
CiReturnCode PS_SetImsSmsAvailability(UINT32 atHandle, UINT8 state);

CiReturnCode PS_GetMmImsVoiceTermination(UINT32 atHandle);
CiReturnCode PS_SetMmImsVoiceTermination(UINT32 atHandle, UINT8 setting);
CiReturnCode PS_SetImsSrv(UINT32 atHandle,  UINT8 imsSrvType, UINT8 imsSrvStatus, UINT8 srvFailCause);
CiReturnCode PS_SendChapAuthReq(UINT32 atHandle, UINT8 cid,  CHAR *challenge,  CHAR *response);
void getPdpTypeStr (CiPsPdpType pdpType, char  *typeStr);
void convertIpUnit2Str(UINT32 reqHandle, int addrType, unsigned char* valData, char* ippStr);

CiReturnCode PS_SetPsmConfig(UINT32 atHandle,  CiPsPrimSetPsmConfigReq *req);
CiReturnCode PS_GetPsmConfig(UINT32 atHandle);

CiReturnCode PS_SetEdrxConfig(UINT32 atHandle,  CiPsPrimSetEdrxConfigReq *req);
CiReturnCode PS_GetEdrxConfig(UINT32 atHandle);

CiReturnCode PS_ReadEdrxDynParaReq(UINT32 atHandle);

CiReturnCode PS_SetCiotConfigReq(UINT32 atHandle, UINT8 mode, UINT8 supportedUeOpt, UINT8 preferredUeOpt);
CiReturnCode PS_GetCiotConfigReq(UINT32 atHandle);
CiReturnCode PS_ReadCoverEnhStatusReq(UINT32 atHandle);

CiReturnCode PS_SetConfigSignallingConnectionOptionReq(UINT32 atHandle, UINT8 option);
CiReturnCode PS_GetSignallingConnectionStausReq(UINT32 atHandle);

CiReturnCode PS_SetInitialPdpActivationOptReq(UINT32 atHandle, UINT8 option, UINT8 attachWithoutPdn);
CiReturnCode PS_GetInitialPdpActivationOptReq(UINT32 atHandle);

CiReturnCode PS_SetApnBackoffTimerStatusReq(UINT32 atHandle, UINT8 option);
CiReturnCode PS_GetApnBackoffTimerStatusReq(UINT32 atHandle);
CiReturnCode PS_ReadApnBackoffTimerDynPara(UINT32 atHandle, CiPsPrimReadApnBackoffTimerDynParaReq *req);

CiReturnCode PS_GetApnRateControl(UINT32 atHandle, CiPsPrimGetApnRateControlReq *req);
CiReturnCode PS_GetApnRateControlActCid(UINT32 atHandle);

void psCnf(CiSgOpaqueHandle opSgCnfHandle,
		CiServiceGroupID svgId,
		CiPrimitiveID    primId,
		CiRequestHandle  reqHandle,
		void*            paras);

void psInd(CiSgOpaqueHandle    opSgIndHandle,
		CiServiceGroupID    svgId,
		CiPrimitiveID       primId,
		CiIndicationHandle  indHandle,
		void*               paras);

void resetCidList(CiRequestHandle reqHandle);
int deactive_ps_connection(UINT8 atpIdx);
void resetPsParas(void);
void setRegOptionPersist(int type, int option);
int getRegOptionPersist(int type);
CiReturnCode PS_InitRegOption (UINT32 atHandle);
int isIMSChannel(int atpIndex);
CiReturnCode PS_GetGPRSContextIPExt (UINT32 atHandle, UINT32 dwContextID);
    
#ifdef GPS_SUPPORT
void asr_gps_handle_cellID(void *regInd);
#endif
#endif

