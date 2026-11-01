/******************************************************************************
*(C) Copyright 2008 Marvell International Ltd.
* All Rights Reserved
******************************************************************************/
/*--------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  Filename: ps_api.c
 *
 *  Description: API interface implementation for packet service
 *
 *  History:
 *   Sep 18, 2008 - Rovin Yu Creation of file
 *
 *  Notes:
 *
 ******************************************************************************/
#include "ci_api_types.h"
#include "ci_api_client.h"
#include "teldef.h"
#include "telutl.h"
#include "telatparamdef.h"
#include "ci_ps.h"
#include "telatci.h"
#include "utlMalloc.h"
#include "utlTrace.h"
#include "global_types.h"
#ifdef LWIP_IPNETBUF_SUPPORT
#include "bsp.h"
#include "dialer_task.h"
#include "duster.h"
#include "connect_management.h"
#include "platform.h"
//#include "sockets.h"
#include "ps_api.h"
#endif
#include "mm_api.h"
#include "quec_cust_feature.h"
#include "quec_atcmd_general.h"
#include "quec_atcmd_network.h"
#include "quec_debug.h"
#include "quec_urc.h"
#include "quec_net.h"
#include "quec_pwm.h"
#include "quec_event_mgr.h"
#include "quec_sockets.h"
#include "quec_pwm.h"
#include "quec_net.h"
#include "quec_power_manager.h"
#include "quec_apptcpip_main.h"
#ifdef QUECTEL_AT_COMMAND
#include "telps.h"
#endif
#ifdef PSM_ENABLE
#include "psm_wrapper.h"
#endif
#ifdef QUECTEL_IPC_ENTERSLEEP_SUPPORT
#include "quec_atcmd_ipc.h"
#endif

#ifndef MIN_SYS
#ifdef QUECTEL_OPEN_CPU
#include "ql_nw.h"
#endif
#endif

#ifdef CRANE_MCU_DONGLE
#ifndef INET6_ADDRSTRLEN
#define INET6_ADDRSTRLEN 64
#endif

#ifndef INET_ADDRSTRLEN
#define INET_ADDRSTRLEN 16
#endif

#ifndef PROPERTY_VALUE_MAX
#define PROPERTY_VALUE_MAX 16
#endif
#endif

#ifdef QUECTEL_NETWORK_SUPPORT
#include "quec_net_app.h"
#include "dev_api.h"
#include "netif_td_api.h"

#define Quec_NetInfo_log(msg, ...)  custom_log("NETWORK_INFO", msg, ##__VA_ARGS__)

extern char mob_sw_rev[];
int QuecSetDefaultPdpFlag = 0;

#if QUEC_DUAL_SIM_SUPPORT
extern CiPsNwRegInfo quec_cgreg_info[2];
extern CiPs4GNwRegInfo quec_cereg_info[2];
extern CiMmPrimRegResultInd quec_creg_info[2];
#else
extern CiPsNwRegInfo quec_cgreg_info;
extern CiPs4GNwRegInfo quec_cereg_info;
extern CiMmPrimRegResultInd quec_creg_info;
#endif
//extern UINT32 gUpdatePdpProfileCmdInPsmFlag;
extern UINT32  quec_UpdateDfltPdpProfileCmdbyPsmFlag;

CiReturnCode PS_SetDefaultPDPContextByReqHandler (UINT32 reqHandle, const CiPsPrimDefineDefaultPdpCtxReq* defaultPdpCtxInfo);

#if QUEC_CEER_ESM_REJECT_CAUSE_SUPPORT
extern char quec_err_cause[QUEC_ERR_CAUSE_LEN];
extern const ceer_lookup_s_type ceer_ps_lte_cause_codes[];
extern unsigned char quec_ci_lookup_cause_code(const ceer_lookup_s_type  *table_ptr, const INT16 code, const ceer_lookup_s_type  **row_pptr);
extern BOOL quec_get_err_cause_urc_en(void);
#endif

#endif
#if defined (__QUEC_OEM_VER_XGD__)
	extern uint8 quec_fibo_get_gprsreact_value(void);
#endif

#ifdef QUECTEL_PROJECT_CUST

extern char *psm_get_wrapper(char *mod_name, char *subspace, char *variable);
#endif

AtciCurrentPsCntxList   gCIDList;

DIRECTIPCONFIGLIST *directIpAddressList=NULL;

extern CiServiceHandle    gAtciSvgHandle[CI_SG_NUMIDS+1];

#ifdef PLATFORM_FOR_PS_LW
extern unsigned char IsLteMode(void);
#else
extern Boolean IsLteMode(UINT8 simId);

#endif

#if defined QUECTEL_PROJECT_CUST
quec_pdpauthinfo_type quec_pdpauthinfo = {0};
extern int updateAuthParamCmdInPsm(UINT32 atHandle,INT32 iCid, const char *pParaString, UINT8 byUpdateFlag);
#endif

extern int gCurrRegOption[2];
extern int gCurrRegOption_1[2];

extern int gRequestedRegOption[2];
extern int gRequestedRegOption_1[2];

#if 1//ndef LTEONLY_THIN
static int gCurrentPSRegOption[2] = {CI_PS_NW_REG_IND_ENABLE_DETAIL};
static int gPSRequestedRegOption[2] = {CI_PS_NW_REG_IND_DISABLE};
#ifndef SINGLE_SIM
static int gCurrentPSRegOption_1[2] = {CI_PS_NW_REG_IND_ENABLE_DETAIL};
static int gPSRequestedRegOption_1[2] = {CI_PS_NW_REG_IND_DISABLE};
#endif
#endif

int gCurrentPSRegStatus = CI_PS_NW_REG_STA_NOT_REGED;

int gPsActDetail = 0;
#ifdef CRANE_MCU_DONGLE
extern int gSysMode;
extern int gSysMode_1;
extern int gSysMainMode;
extern int gSysMainMode_1;
#endif

int g4gCurrentPSRegStatus = CI_PS_NW_REG_STA_NOT_REGED;
int g4gCurrentPSRegOption[2] = {CI_PS_NW_REG_IND_ENABLE_MORE_DETAIL};
static int g4gPSRequestedRegOption[2] = {CI_PS_NW_REG_IND_DISABLE};
static int gGetEutranVoiceDomainPreference = 0;
static int gQueryCidAddrNum = 0;
static int gQueryCidAddrCount = 0;
static int gCgpaddrCidArray[CI_PS_MAX_CID] = { 0 };

#ifndef SINGLE_SIM
int gCurrentPSRegStatus_1 = CI_PS_NW_REG_STA_NOT_REGED;
int gPsActDetail_1 = 0;
static int g4gPSRequestedRegOption_1[2] = {CI_PS_NW_REG_IND_DISABLE};
int g4gCurrentPSRegOption_1[2] = {CI_PS_NW_REG_IND_ENABLE_MORE_DETAIL};
int g4gCurrentPSRegStatus_1 = CI_PS_NW_REG_STA_NOT_REGED;
static int gGetEutranVoiceDomainPreference_1 = 0;
static int gQueryCidAddrNum_1 = 0;
static int gQueryCidAddrCount_1 = 0;
static int gCgpaddrCidArray_1[CI_PS_MAX_CID] = { 0 };
int gIPv6_AddressFormat_1 = 0;
int gIPv6_SubnetNotation_1 = 0;
int gIPv6_LeadingZeros_1 = 0;
int gIPv6_CompressZeros_1 = 1;
char gPdpErrCauseBuf_1[128];
BOOL gImsRegState_1 = FALSE;
BOOL gQueryAllCid_1 = FALSE;
#endif

int gIPv6_AddressFormat = 0;
int gIPv6_SubnetNotation = 0;
int gIPv6_LeadingZeros = 0;
int gIPv6_CompressZeros = 1;
char gPdpErrCauseBuf[128];
BOOL gImsRegState = FALSE;
BOOL gQueryAllCid = FALSE;

#ifdef LWIP_IPNETBUF_SUPPORT
UINT8 CgregReady = FALSE;
UINT8 CregReady = FALSE;
UINT8 CeregReady = FALSE;
CiPsNwRegInfo psRegDetail;
CiPs4GNwRegInfo ps4GRegDetail;
UINT8 CurrentRoamingStatus = 0;        //0-no_roaming, 1--roaming
BOOL  NWReadyFlag = FALSE;
BOOL LastNWReadyFlag = FALSE;
BOOL ErrorIndFlag[CI_PS_MAX_CID] = { 0 };
UINT16 UnknownPdpCause = CIRC_PS_SUCCESS;
INT32 gLastNwStatus = CI_PS_NW_REG_STA_NOT_REGED;
BOOL gPdpMT[CI_PS_MAX_CID] = { 0 };
//telPsPdpCtx psPdpCtx[TEL_AT_PS_CID_VAL_MAX + 1];
telPsPdpCtx *psPdpCtx[TEL_AT_PS_CID_VAL_MAX + 1];

telPsDefaultPdpApn psDefaultPdpApn;
BOOL gForceReg = 0;

#ifndef SINGLE_SIM

CiPsNwRegInfo psRegDetail_1;
CiPs4GNwRegInfo ps4GRegDetail_1;
BOOL ErrorIndFlag_1[CI_PS_MAX_CID] = { 0 };
UINT8 CurrentRoamingStatus_1 = 0;        //0-no_roaming, 1--roaming
BOOL  NWReadyFlag_1 = FALSE;
BOOL LastNWReadyFlag_1 = FALSE;
UINT16 UnknownPdpCause_1;
INT32 gLastNwStatus_1 = CI_PS_NW_REG_STA_NOT_REGED;
UINT8 CregReady_1 = FALSE;
UINT8 CgregReady_1 = FALSE;
UINT8 CeregReady_1 = FALSE;
#endif

#endif
#ifdef QUEC_APPTCPIP_SUPPORT
int quec_net_set_pdp_profile(int pdp_cid, quec_pdp_profile  *profile_info);
extern void quec_pdp_deatch_handler(int cid);
#endif
#if QUEC_DEFAULT_AUTH_CHECK_SUPPORT
    extern quec_pdp_profile quec_default_pdn_gki_back[2];
    extern quec_pdp_profile quec_default_pdn_gki[2];
#endif
#ifdef CRANE_MCU_DONGLE
int nw_switch_state;
#endif

#ifdef QUEC_QSCLKEX_ENABLE
extern quec_qsclk_ex_s qsclkex_cfg;		
#endif

#define MAX_ADDR_PRESENTATION_BUF_LEN (sizeof "ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.255")
#define CI_PS_PDP_IPV4_ADDR_LENGTH 4
#define CI_PS_PDP_FULL_IPV6_ADDR_LENGTH 16
#define CI_PS_PDP_IPV6_INTERFACE_ADDR_LENGTH 8
#define IPV4_ADDR_LENGTH                   4
#define IPV6_FULL_ADDR_LENGTH              16
#define IPV6_INTERFACE_ADDR_LENGTH         8

int pdpAddrlength[4] = {0, IPV4_ADDR_LENGTH, IPV6_FULL_ADDR_LENGTH, IPV6_INTERFACE_ADDR_LENGTH};

UINT8 gCurrSignalConnetcionOption = CIPS_CSCON_ENABLE_ACCESS;
UINT8 gCurrSignalConnetcionOption_1 = CIPS_CSCON_ENABLE_ACCESS;


/* Define some private primitives for PS service */
#define PRI_PS_PRIM_GET_SECOND_PDP_CTXS_RANGE_REQ (CI_PS_PRIM_LAST_COMMON_PRIM + 1)
#define PRI_PS_PRIM_GET_MIN_QOS_CAPS_REQ (CI_PS_PRIM_LAST_COMMON_PRIM + 2)
#define PRI_PS_PRIM_GET_NEG_QOS_CAPS_REQ (CI_PS_PRIM_LAST_COMMON_PRIM + 3)
#define PRI_PS_PRIM_GET_MIN_QOS_REQ (CI_PS_PRIM_LAST_COMMON_PRIM + 4)
#define PRI_PS_PRIM_GET_NEG_QOS_REQ (CI_PS_PRIM_LAST_COMMON_PRIM + 5)
#define PRI_PS_PRIM_SET_PDP_CTX_DEACT_STATE_REQ (CI_PS_PRIM_LAST_COMMON_PRIM + 6)
#define PRI_PS_PRIM_SET_DETACH_STATE_REQ (CI_PS_PRIM_LAST_COMMON_PRIM + 7)
#define PRI_PS_PRIM_GET_TFT_REQ (CI_PS_PRIM_LAST_COMMON_PRIM + 8)
#define PRI_PS_PRIM_GET_IP_REQ (CI_PS_PRIM_LAST_COMMON_PRIM + 9)
#define PRI_PS_PRIM_GET_APN_RATE_CONTROL_ACT_CID (CI_PS_PRIM_LAST_COMMON_PRIM + 10)
#define CI_PS_PRIM_GET_SYSINFO_NW_REG_STATUS_REQ (CI_PS_PRIM_LAST_COMMON_PRIM + 11)
#define PRI_PS_PRIM_GET_PCO_REQ (CI_PS_PRIM_LAST_COMMON_PRIM + 12)
#define PRI_PS_PRIM_GET_ACL_STATUS_REQ (CI_PS_PRIM_LAST_COMMON_PRIM + 13)
#define PRI_PS_PRIM_SET_UNRESERVED_CID_REQ (CI_PS_PRIM_LAST_COMMON_PRIM + 14)
#define PRI_PS_PRIM_GET_IP_EXTEND_REQ (CI_PS_PRIM_LAST_COMMON_PRIM + 15)

#define TIOPPPON        _IOW('T', 208, int)

#ifdef LWIP_IPNETBUF_SUPPORT
extern TelAtpCtrl gAtpCtrl[NUM_OF_TEL_ATP];
extern OSMsgQRef gCMMsgQ;
extern int gSysMode;
extern int gSysMode_1;
extern int gSysMainMode;
extern int gSysMainMode_1;
extern int gSavedSysMainMode;
extern int gSavedSysMainMode_1;
#endif

void resetCurrCntx(UINT8 atpIdx);
CiReturnCode   sendDefineDefaultPdpContext( CiRequestHandle reqHandle, INT8 cid );
//In order to reset PS paras in case of CP assertion
void resetPsParas(void);
 void  removeNodeByCid(unsigned char cid);

 void addToList(DIRECTIPCONFIGLIST *newdrvnode);
 BOOL  searchListByCid(unsigned char cid, DIRECTIPCONFIGLIST ** ppBuf);
 #ifdef LWIP_IPNETBUF_SUPPORT
 BOOL isHandleForSim0(UINT32 reqHandle);
 #endif
 UINT8 getPdpIndexByCid(UINT8 cid, AtciCurrentSetCntx *pdp_table);
 

#define IPV4_SUBNETMUX_MAX_LEN  32

#ifndef AF_INET6
#define AF_INET6		2
#endif

#ifndef AF_INET
#define AF_INET         1
#endif


#ifdef LWIP_IPNETBUF_SUPPORT
extern BOOL isMasterSim0(void);
extern UINT8 getMultiPdpSameApnFlag(void);
extern BOOL matchApn(char *eps_apn, char *apn);
extern void sendEventToHandler(INT32 id, CHAR *data);
extern void showPFInfo(PacketFilterInfo *PF_info);
extern UINT8 getDefaultCidNum(void);
#ifndef NO_DIALER
extern void updatePdpTimeIpInfo(UINT8 ipType, void *data, UINT8 cid);
extern void updatePdpConnectedTime(PdpContextList *list, UINT8 cid);
extern void updateMTPdpTimeConnect(UINT32 atHandle, UINT8 cid);
extern int get_auto_apn_iptype(int simID);
extern char getCurrentCid(void);
#endif
#endif

#ifdef PPP_ENABLE
extern void modem_update_reg_option( int atp_index, int option);
#endif
extern CiReturnCode MM_SetRegOption(UINT32 atHandle, INT32 regOption);
extern void handle_dial(int atp_index);
#if QUECTEL_PROJECT_CUST
extern uint8 quec_netcard_get_cid(void);
extern int quec_qsclkex_punishtime_set(uint16 punish_time);
extern uint8 quec_netcard_get_cid(void);
extern void resetDefaultCidReplaceFlag(void);

//cid 0-15 pdpmodify count
int quec_pdpmodify_count[16]={0};
#define QUEC_PDPMODIFY_PUNISH_COUNT (3)
#endif

#ifdef QUEC_MINISYS_USEFOR_APN_ACTIVATE
extern void quec_minisys_set_regstatus(int status);
extern void quec_minifota_start(void);

#endif


/*this funtion will convert the Ipaddress send from SAC will hex arry, convert to the stand netaddr
** for ipv4  a.b.c.d
** for ipv6
*/
void _inet_ntop(int af_type, unsigned char* valData, char* ippStr, int cnt)
{
	int i=0;
	char ippBuf[CI_PS_PDP_IP_V6_SIZE] = { '\0' };

	if(af_type==AF_INET)
	{
		sprintf ( (char *)ippBuf, "%d.%d.%d.%d", *valData,*(valData+1),*(valData+2),*(valData+3));
	}
	else if(af_type==AF_INET6)
	{
		/*Fixed klocwork[Buffer Overflow ]*/
		snprintf ( (char *)ippBuf, sizeof(ippBuf), "%x:%x:%x:%x:%x:%x:%x:%x",
            valData[ 0] << 8 | valData[ 1],
            valData[ 2] << 8 | valData[ 3],
            valData[ 4] << 8 | valData[ 5],
            valData[ 6] << 8 | valData[ 7],
            valData[ 8] << 8 | valData[ 9],
            valData[10] << 8 | valData[11],
            valData[12] << 8 | valData[13],
            valData[14] << 8 | valData[15]);
	}
	strcpy((char *)ippStr, (char *)ippBuf);

}

#ifdef LWIP_IPNETBUF_SUPPORT

telPsPdpCtx *newPsPdpCtx(UINT8 cid)
{
    telPsPdpCtx *ctx = psPdpCtx[cid];

   	if (cid > TEL_AT_PS_CID_VAL_MAX)
		return NULL;
		
    if (!ctx)
    {
        ctx  = malloc(sizeof(telPsPdpCtx));
        if (!ctx )
            return NULL;

        psPdpCtx[cid] = ctx;
        memset(ctx, 0, sizeof(telPsPdpCtx));
        
    }
    return ctx;
}

UINT32 telGetPdpCtxMoAndMtNum(UINT32 atHandle)
{
	telPsPdpCtx *ctx = NULL;
	int i = 0;
	int num = 0;
	AtciCurrentSetCntx *p_cInfo;
	UINT8 index;

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
		p_cInfo = gCIDList.cInfo;
	} else {
		p_cInfo = gCIDList.cInfo_1;
	}
#else
	p_cInfo = gCIDList.cInfo;
#endif
	for( i = 0; i <= TEL_AT_PS_CID_VAL_MAX; i++)
	{
		ctx = telGetPdpCtx(i);
		/* MO */
		if (ctx && ctx->reDefined)
			num++;
		else
		{
			 /* check MT */
			index = getPdpIndexByCid(i, p_cInfo);
			if (index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
				num++;
		}

	}

	//ATDBGMSG(atcmdsrv,193,"%s: redefined num %d", __func__, num);
	return num;
}


BOOL telCheckPdpCtxApn(UINT32 reqHandle, UINT8 cid, telPsPdpApn *apnInfo)
{
    telPsPdpCtx *currentPdpCtx = psPdpCtx[cid];
    
	if (!apnInfo || cid > TEL_AT_PS_CID_VAL_MAX)
		return FALSE;
		
    if (telGetPdpCtxMoAndMtNum(reqHandle) == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
	{
	    /* not allow to define new cid */
	    if (apnInfo->defined == TRUE && currentPdpCtx && currentPdpCtx->reDefined == FALSE)
	    {
	        //ATDBGMSG("%s: redefine pdp ctx full, not allow to define new cid %d", __func__, cid);
	        return FALSE;
	    }
	}

	return TRUE;
}

BOOL telSetPdpCtxApn(UINT8 cid, telPsPdpApn *apnInfo)
{
	telPsPdpCtx *currentPdpCtx = psPdpCtx[cid];
	char *ptr = NULL;
	int apnLen = 0;

	if (!apnInfo || cid > TEL_AT_PS_CID_VAL_MAX)
		return FALSE;

	if (!currentPdpCtx)
	{
		currentPdpCtx = newPsPdpCtx(cid);
		if (!currentPdpCtx)
			return FALSE;
	}
		
	currentPdpCtx->cid = cid;
	/*set or clear apn info*/
	memcpy(&currentPdpCtx->apnInfo, apnInfo, sizeof(*apnInfo));
	CPUartLogPrintf("%s: defined %d,ip_type %d, APN %s", __func__, currentPdpCtx->apnInfo.defined, currentPdpCtx->apnInfo.ipType,
							(strlen(currentPdpCtx->apnInfo.apn) > 0)?currentPdpCtx->apnInfo.apn:"NULL");

	currentPdpCtx->reDefined = TRUE;

	if (currentPdpCtx->apnInfo.defined == FALSE)
		currentPdpCtx->reDefined = FALSE;

	/*reconfig APN,  should NOT show the ip info in +CGDCONT before actived the PDP*/
	//telSetPdpActivedFlag(currentPdpCtx->cid, FALSE);

	return currentPdpCtx->reDefined;
}

BOOL isHandleForMasterSim(UINT32 reqHandle)
{
	if ((isMasterSim0() && isHandleForSim0(reqHandle)) ||
		(!isMasterSim0() && !isHandleForSim0(reqHandle)))
		return TRUE;
	else
		return FALSE;
}

BOOL telSetPdpCtxApnDS(UINT32 reqHandle, UINT8 cid, telPsPdpApn *apnInfo)
{
	if (isHandleForMasterSim(reqHandle))
	{
	    if (telCheckPdpCtxApn(reqHandle, cid, apnInfo))
		    return telSetPdpCtxApn(cid, apnInfo);
		else
		    return FALSE;
	}
	else
		return FALSE;
}
#ifdef QUECTEL_PROJECT_CUST	//Bug #109660 STASR1602-404
BOOL telGetPdpCtxAuth(UINT8 cid, telPsPdpAuth *authInfo)
{
	telPsPdpCtx *currentPdpCtx = psPdpCtx[cid];

	if (!authInfo)
		return FALSE;

	if((currentPdpCtx != NULL) && (&currentPdpCtx->authInfo != NULL))
	{
		memcpy(authInfo, &currentPdpCtx->authInfo, sizeof(*authInfo));
		return TRUE;
	}
	else
	{
		CPUartLogPrintf("%s:invalid telPsPdpAuth Info", __func__);
		return TRUE;
	}
}

BOOL telGetPdpCtxAuthDS(UINT32 reqHandle, UINT8 cid, telPsPdpAuth *authInfo)
{
	if (isHandleForMasterSim(reqHandle))
		return telGetPdpCtxAuth(cid, authInfo);
	else
		return FALSE;
}
#endif

BOOL telSetPdpCtxAuth(UINT8 cid, telPsPdpAuth *authInfo)
{
	telPsPdpCtx *currentPdpCtx = NULL;

	if (!authInfo || cid > TEL_AT_PS_CID_VAL_MAX)
		return FALSE;

	currentPdpCtx = psPdpCtx[cid];

	if (!currentPdpCtx)
	{
		currentPdpCtx = newPsPdpCtx(cid);
		if (!currentPdpCtx)
			return FALSE;
	}

	if (currentPdpCtx->reDefined == FALSE)
	{
		if (currentPdpCtx->authInfo.defined == TRUE)
		{
			if (currentPdpCtx->authInfo.authType != authInfo->authType)
			{
				/*authType changed*/
				currentPdpCtx->reDefined = TRUE;
			}
			else if (currentPdpCtx->authInfo.authType != 0 &&
				   (strcmp(currentPdpCtx->authInfo.userName, authInfo->userName)
				    ||strcmp(currentPdpCtx->authInfo.password, authInfo->password)))
			{
				/*username or password changed*/
				currentPdpCtx->reDefined = TRUE;
			}
		}
	}

	/*set or clear auth info*/
	memcpy(&currentPdpCtx->authInfo, authInfo, sizeof(*authInfo));

	return currentPdpCtx->reDefined;
}

BOOL telSetPdpCtxAuthDS(UINT32 reqHandle, UINT8 cid, telPsPdpAuth *authInfo)
{
	if (isHandleForMasterSim(reqHandle))
		return telSetPdpCtxAuth(cid, authInfo);
	else
		return FALSE;
}

BOOL telSetPdpCtxOpt(UINT8 cid, telPsPdpOpt *opt)
{
	telPsPdpCtx *currentPdpCtx = psPdpCtx[cid];

	if (!opt || cid > TEL_AT_PS_CID_VAL_MAX)
		return FALSE;
		
	if (!currentPdpCtx)
	{
		currentPdpCtx = newPsPdpCtx(cid);
		if (!currentPdpCtx)
			return FALSE;
	}
	
	/*set or clear opt */
	memcpy(&currentPdpCtx->opt, opt, sizeof(*opt));

	return currentPdpCtx->reDefined;
}

BOOL telSetPdpCtxOptDS(UINT32 reqHandle, UINT8 cid, telPsPdpOpt *opt)
{
	if (isHandleForMasterSim(reqHandle))
		return telSetPdpCtxOpt(cid, opt);
	else
		return FALSE;
}

void copyCiPdpCtx2Opt(telPsPdpOpt *telPdpOpt, CiPsPdpCtx *ciPdpCtx)
{

	if (!telPdpOpt || !ciPdpCtx)
		return;

	telPdpOpt->ipv4Addr = ciPdpCtx->ipv4Addr;
	telPdpOpt->ipv6Addr = ciPdpCtx->ipv6Addr;
	telPdpOpt->dcompPresent = ciPdpCtx->dcompPresent;
	telPdpOpt->dcomp = ciPdpCtx->dcomp;
	telPdpOpt->hcompPresent = ciPdpCtx->hcompPresent;
	telPdpOpt->hcomp = ciPdpCtx->hcomp;
	telPdpOpt->pdParasPresent = ciPdpCtx->pdParasPresent;
	telPdpOpt->pdParas = ciPdpCtx->pdParas;
	telPdpOpt->ipAddrAllocPresent = ciPdpCtx->ipAddrAllocPresent;
	telPdpOpt->ipAddrAlloc = ciPdpCtx->ipAddrAlloc;
	telPdpOpt->reqTypePresent = ciPdpCtx->reqTypePresent;
	telPdpOpt->reqType = ciPdpCtx->reqType;
	telPdpOpt->pCscfDiscoveryPresent = ciPdpCtx->pCscfDiscoveryPresent;
	telPdpOpt->pCscfDiscovery = ciPdpCtx->pCscfDiscovery;
	telPdpOpt->imCnSignallingFlagIndPresent = ciPdpCtx->imCnSignallingFlagIndPresent;
	telPdpOpt->imCnSignallingFlagInd = ciPdpCtx->imCnSignallingFlagInd;
}

void copyOpt2CiPdpCtx(CiPsPdpCtx *ciPdpCtx, telPsPdpOpt *telPdpOpt)
{

	if (!telPdpOpt || !ciPdpCtx)
		return;

	ciPdpCtx->ipv4Addr = telPdpOpt->ipv4Addr;
	ciPdpCtx->ipv6Addr = telPdpOpt->ipv6Addr;
	ciPdpCtx->dcompPresent = telPdpOpt->dcompPresent;
	ciPdpCtx->dcomp = telPdpOpt->dcomp;
	ciPdpCtx->hcompPresent = telPdpOpt->hcompPresent;
	ciPdpCtx->hcomp = telPdpOpt->hcomp;
	ciPdpCtx->pdParasPresent = telPdpOpt->pdParasPresent;
	ciPdpCtx->pdParas = telPdpOpt->pdParas;
	ciPdpCtx->ipAddrAllocPresent = telPdpOpt->ipAddrAllocPresent;
	ciPdpCtx->ipAddrAlloc = telPdpOpt->ipAddrAlloc;
	ciPdpCtx->reqTypePresent = telPdpOpt->reqTypePresent;
	ciPdpCtx->reqType = telPdpOpt->reqType;
	ciPdpCtx->pCscfDiscoveryPresent = telPdpOpt->pCscfDiscoveryPresent;
	ciPdpCtx->pCscfDiscovery = telPdpOpt->pCscfDiscovery;
	ciPdpCtx->imCnSignallingFlagIndPresent = telPdpOpt->imCnSignallingFlagIndPresent;
	ciPdpCtx->imCnSignallingFlagInd = telPdpOpt->imCnSignallingFlagInd;
}

telPsPdpCtx *telGetPdpCtx(UINT8 cid)
{
	return psPdpCtx[cid];
}

telPsDefaultPdpApn *telGetDefaultPdpApn(void)
{
	return &psDefaultPdpApn;
}

BOOL telMatchDefaultApn(UINT8 cid)
{
	telPsPdpCtx *pdpCtx = telGetPdpCtx(cid);
	telPsDefaultPdpApn *defaultPdpApn = telGetDefaultPdpApn();
	BOOL sameApn = FALSE;

	if (getMultiPdpSameApnFlag() != 0)
		return FALSE;

	if (matchApn(pdpCtx->apnInfo.apn, defaultPdpApn->apn) || matchApn(pdpCtx->apnInfo.apn, defaultPdpApn->epsApn))
	{
		if (pdpCtx->apnInfo.ipType == defaultPdpApn->epsIpType)
		{
			sameApn = TRUE;
		}
	}

	return sameApn;
}

void sendmatchCgdcontapn()
{
	if (!isMasterSim0())
		sendEventToHandler(send_cgdont_1, NULL);
	else
		sendEventToHandler(send_cgdont, NULL);

	//CPUartLogPrintf("%s:send sendmatchCgdcontapn to event Handler", __func__);
}

void removeEpsApnSuffix(CHAR *apn)
{
	char tmp[MAX_APN_INFO_LEN + 1];
	char *pEnd = NULL;

	if (apn == NULL || strlen(apn) == 0)
		return;

	memset(tmp, 0 , MAX_APN_INFO_LEN + 1);

	pEnd = strstr(apn, ".mnc");

	if (pEnd)
	{
		memcpy(tmp, apn, pEnd - apn);
		tmp[pEnd - apn] = '\0';
		strcpy(apn, tmp);
	}
	else
	{
		pEnd = strstr(apn, ".MNC");
		if (pEnd)
		{
			memcpy(tmp, apn, pEnd - apn);
			tmp[pEnd - apn] = '\0';
			strcpy(apn, tmp);
		}
	}

	return;
}

void updateAttachPdpApnInfo(CHAR *apn, UINT8 ipType)
{
	telPsDefaultPdpApn *defaultPdpApn = telGetDefaultPdpApn();

	strcpy(defaultPdpApn->epsApn, apn);
	defaultPdpApn->epsIpType = ipType;

	removeEpsApnSuffix(defaultPdpApn->epsApn);

	//ATDBGMSG("%s: update default PDP info APN [%s],  ipType %d", __func__, strlen(defaultPdpApn->epsApn)?defaultPdpApn->epsApn:"NULL", ipType);
}

void updateAttachPdpApnInfoDS(UINT32 reqHandle, CHAR *apn, UINT8 ipType)
{
	if (isHandleForMasterSim(reqHandle))
		updateAttachPdpApnInfo(apn, ipType);
}

void updateCgdfltApnInfo(CHAR *apn, UINT8 ipType)
{
	telPsDefaultPdpApn *defaultPdpApn = telGetDefaultPdpApn();

	strcpy(defaultPdpApn->apn, apn);
	defaultPdpApn->ipType = ipType;

	//ATDBGMSG("%s: update CGDFLT info APN [%s],  ipType %d", __func__, apn?apn:"NULL", ipType);
}

void updateCgdfltApnInfoDS(UINT32 reqHandle, CHAR *apn, UINT8 ipType)
{
	if (isHandleForMasterSim(reqHandle))
		updateCgdfltApnInfo(apn, ipType);
}

void initPsPdpCtx()
{
	int i = 0;

	for (i = 0; i < TEL_AT_PS_CID_VAL_MAX; i++)
	{
		memset(&psPdpCtx[i], 0 , sizeof(telPsPdpCtx));
	}
}

void telClearPdpRedefinedFlag(UINT8 cid)
{
	telPsPdpCtx *currentPdpCtx = psPdpCtx[cid];
	
	if (cid > TEL_AT_PS_CID_VAL_MAX)
		return;
		
	if (currentPdpCtx)
		currentPdpCtx->reDefined = FALSE;
}


void telUpdateActiveApnInfo(UINT8 cid, CHAR *apn, UINT8 ipType)
{
	telPsPdpCtx *currentPdpCtx = psPdpCtx[cid];
	
	if (cid > TEL_AT_PS_CID_VAL_MAX)
		return;

	if (currentPdpCtx)
	{
		strncpy(currentPdpCtx->activedApnInfo.apn, apn, TEL_AT_CGDCONT_2_APN_STR_MAX_LEN);
		currentPdpCtx->activedApnInfo.ipType = ipType;
	}
}

void telSetPdpActivedFlag(UINT8 cid, UINT8 actived)
{
	telPsPdpCtx *currentPdpCtx = psPdpCtx[cid];

	if (cid > TEL_AT_PS_CID_VAL_MAX)
		return;
		
	if (!currentPdpCtx)
	{
		CPUartLogPrintf("%s: no psPdpCtx[%d] exist!", __func__, cid);
		return;
	}
	 
	currentPdpCtx->bActived = actived;

	if (actived)
	{
		CPUartLogPrintf("%s: cid %d, actived %d, reDefined %d", __func__, cid, actived, currentPdpCtx->reDefined);
		if (currentPdpCtx->reDefined)
		{
			memcpy(&(currentPdpCtx->activedApnInfo), &(currentPdpCtx->apnInfo), sizeof(telPsPdpApn));
#ifdef ATCMD_PDP_CONTEXT
			telUpdatePdpInfoListApn( cid + 1, currentPdpCtx->activedApnInfo.apn, currentPdpCtx->activedApnInfo.ipType);
#endif
		}
		if (isMtPdp(cid))
			setMtPdp(cid, FALSE);
	}
	else
		memset(&(currentPdpCtx->activedApnInfo), 0, sizeof(telPsPdpApn));
}

UINT8 telGetPdpActivedFlag(UINT8 cid)
{
	telPsPdpCtx *currentPdpCtx = psPdpCtx[cid];
	
	if (cid > TEL_AT_PS_CID_VAL_MAX)
		return FALSE;
		
	if (currentPdpCtx)
		return currentPdpCtx->bActived;
	else
		return FALSE;
}

#ifdef ATCMD_PDP_CONTEXT
telPdpInfo *telPdpInfoList = NULL;

telPdpInfo *telMallocPdpInfoList()
{
	telPdpInfo *list = telPdpInfoList, *preList = telPdpInfoList;
	telPdpInfo **head =  &telPdpInfoList;

	if (*head == NULL)
	{
		*head = malloc(sizeof(telPdpInfo));
		if (*head == NULL)
			return NULL;

		memset(*head, 0, sizeof(telPdpInfo));
		(*head)->apnInfo.ipType = CI_PS_PDP_NUM_TYPES;
		(*head)->apnInfo.epsIpType = CI_PS_PDP_NUM_TYPES;
		
		return *head;
	}

	while(list)
	{
		preList = list;
		list = list->next;
	}

	list = malloc(sizeof(telPdpInfo));
	if (!list)
		return NULL;

	memset(list, 0, sizeof(telPdpInfo));
	list->apnInfo.ipType = CI_PS_PDP_NUM_TYPES;
	list->apnInfo.epsIpType = CI_PS_PDP_NUM_TYPES;
	
	preList->next  = list;
	return list;
}

telPdpInfo *telGetPdpInfoList(UINT8 cid)
{
	telPdpInfo *list = telPdpInfoList;
	BOOL listExist = FALSE;

	if (cid > TEL_AT_PS_CID_VAL_MAX || cid < 1)
		return NULL;

	while(list)
	{
		if (list->cid == cid)
		{
			listExist = TRUE;
			break;
		}

		list = list->next;
	}

	if (listExist)
		return list;
	else
		return NULL;
}

void telUpdatePdpInfoListApn(UINT8 cid,  CHAR *apn, UINT8 ipType)
{
	telPdpInfo *list = NULL;

	CPUartLogPrintf("%s: cid %d", __func__, cid);
	if (cid > TEL_AT_PS_CID_VAL_MAX || cid < 1)
		return;

	list = telGetPdpInfoList(cid);
	if (list == NULL)
	{
		list = telMallocPdpInfoList();
		if (list == NULL)
			return;

		//CPUartLogPrintf("%s: malloc a new list", __func__);
		list->cid = cid;
	}

	if (apn && strlen(apn)){
	#if QUEC_QIACT_ANP_CHECK
		memset(list->apnInfo.apn,0, TEL_AT_CGDCONT_2_APN_STR_MAX_LEN);
	#endif
		strncpy(list->apnInfo.apn, apn, TEL_AT_CGDCONT_2_APN_STR_MAX_LEN);
	}
	if (ipType != 0)
	{
		if (ipType == CI_PS_PDP_TYPE_IPV4V6)
			list->apnInfo.ipType = 0;
		else
		       list->apnInfo.ipType = ipType;
	}

	CPUartLogPrintf("%s: cid %d, apn %s, iptype %d", __func__, cid, strlen(list->apnInfo.apn)?list->apnInfo.apn:"NULL",  list->apnInfo.ipType);
}

void telUpdatePdpInfoListEpsApn(UINT8 cid,  CHAR *apn, UINT8 ipType)
{
	telPdpInfo *list = NULL;

	CPUartLogPrintf("%s: cid %d", __func__, cid);
	if (cid > TEL_AT_PS_CID_VAL_MAX || cid < 1)
		return;

	list = telGetPdpInfoList(cid);
	if (list == NULL)
	{
		list = telMallocPdpInfoList();
		if (list == NULL)
			return;

		CPUartLogPrintf("%s: cid %d", __func__, cid);
		list->cid = cid;
	}

	strncpy(list->apnInfo.epsApn, apn, TEL_AT_CGDCONT_2_APN_STR_MAX_LEN);

	if (ipType != 0)
	{
		if (ipType == CI_PS_PDP_TYPE_IPV4V6)
			list->apnInfo.epsIpType = 0;
		else
		       list->apnInfo.epsIpType = ipType;
	}

	CPUartLogPrintf("%s: cid %d, apn %s, iptype %d", __func__, cid, strlen(list->apnInfo.epsApn)?list->apnInfo.epsApn:"NULL",  list->apnInfo.epsIpType);
}

void telUpdatePdpInfoListIp(UINT8 cid, Ipv4Info *ipInfo)
{
	telPdpInfo *list = NULL;

	if (cid > TEL_AT_PS_CID_VAL_MAX || cid < 1)
		return;

	list = telGetPdpInfoList(cid);
	if (list == NULL)
	{
		list = telMallocPdpInfoList();
		if (list == NULL)
			return;

		CPUartLogPrintf("%s: cid %d", __func__, cid);
		list->cid = cid;
	}

	if (list->ip4Info == NULL)
	{
		list->ip4Info = malloc(sizeof(Ipv4Info));
		if (list->ip4Info == NULL)
			return;
	}

	memcpy(list->ip4Info, ipInfo, sizeof(Ipv4Info));
}

void telUpdatePdpInfoListIp6(UINT8 cid, Ipv6Info *ip6Info)
{
	telPdpInfo *list = NULL;

	if (cid > TEL_AT_PS_CID_VAL_MAX || cid < 1)
		return;

	list = telGetPdpInfoList(cid);
	if (list == NULL)
	{
		list = telMallocPdpInfoList();
		if (list == NULL)
			return;

		//CPUartLogPrintf("%s: cid %d", __func__, cid);
		list->cid = cid;
	}

	if (list->ip6Info == NULL)
	{
		list->ip6Info = malloc(sizeof(Ipv6Info));
		if (list->ip6Info == NULL)
			return;
	}

	memcpy(list->ip6Info, ip6Info, sizeof(Ipv6Info));
}

void telClearPdpInfo(UINT8 cid)
{
	telPdpInfo *list = NULL;

	if (cid > TEL_AT_PS_CID_VAL_MAX || cid < 1)
		return;

	list = telGetPdpInfoList(cid);
	if (list == NULL)
		return;

	/*clear ip and apn info*/
	if (list->ip4Info)
	{
		free(list->ip4Info);
		list->ip4Info = NULL;
	}

	if (list->ip6Info)
	{
		free(list->ip6Info);
		list->ip6Info = NULL;
	}

	memset(&(list->apnInfo), 0, sizeof(telPsDefaultPdpApn));
	list->apnInfo.ipType = CI_PS_PDP_NUM_TYPES;
	list->apnInfo.epsIpType = CI_PS_PDP_NUM_TYPES;
	
	CPUartLogPrintf("%s: cid %d", __func__, cid);
}

telPdpInfo *telGetPdpInfo(UINT8 cid)
{
	telPdpInfo *list = NULL;

	if (cid > TEL_AT_PS_CID_VAL_MAX || cid < 1)
		return NULL;

	list = telGetPdpInfoList(cid);

	if (list->ip4Info || list->ip6Info)
		return list;
	else
		return NULL;
}

telPdpInfo *telGetPdpApnInfo(UINT8 cid)
{
	telPdpInfo *list = NULL;

	if (cid > TEL_AT_PS_CID_VAL_MAX || cid < 1)
		return NULL;

	list = telGetPdpInfoList(cid);

	if (strlen(list->apnInfo.epsApn) || strlen(list->apnInfo.apn))
		return list;
	else
		return NULL;
}

#endif

#ifndef LTEONLY_THIN
void save3GOption(int simslot, int IMS_flag, int option_flag, int option_value)
{
    char path_buf[40] = {0};
    char tmp_buf[10] = {0};

    CPUartLogPrintf("%s : simslot %d, IMS_flag %d, option_flag %d, option_value %d", __FUNCTION__, simslot, IMS_flag, option_flag, option_value);

    if(option_flag == REQUEST_OPTION_FLAG)  //reg
    {
        if (!simslot)
        {
            if(IMS_flag)
                sprintf(path_buf, "%s", "3G_regOption_sim0_None_IMS");
            else
                sprintf(path_buf, "%s", "3G_regOption_sim0_IMS");            
        }
        else
        {
            if(IMS_flag)
                sprintf(path_buf, "%s", "3G_regOption_sim1_None_IMS");
            else
                sprintf(path_buf, "%s", "3G_regOption_sim1_IMS");            
        } 
    }
    else if(option_flag == CURRENT_OPTION_FLAG)
    {
        if (!simslot)
        {
            if(IMS_flag)
                sprintf(path_buf, "%s", "3G_curOption_sim0_None_IMS");
            else
                sprintf(path_buf, "%s", "3G_curOption_sim0_IMS");            
        }
        else
        {
            if(IMS_flag)
                sprintf(path_buf, "%s", "3G_curOption_sim1_None_IMS");
            else
                sprintf(path_buf, "%s", "3G_curOption_sim1_IMS");            
        } 
    }
    else
    {
      CPUartLogPrintf("%s : incorrect option_flag\r\n", __FUNCTION__);    
      return;
    }
    
    sprintf(tmp_buf, "%d", option_value);
    psm_set_wrapper(PSM_MOD_LOCALE,  NULL, path_buf, tmp_buf);
    psm_commit__();
}
#endif

void save4GOption(int simslot, int IMS_flag, int option_flag, INT32 option_value)
{
    char path_buf[40] = {0};
    char tmp_buf[10] = {0};

    CPUartLogPrintf("%s : simslot %d, IMS_flag %d, option_flag %d, option_value %d", __FUNCTION__, simslot, IMS_flag, option_flag, option_value);

    if(option_flag == REQUEST_OPTION_FLAG)  //reg
    {
        if (!simslot)
        {
            if(IMS_flag)
                sprintf(path_buf, "%s", "4G_regOption_sim0_None_IMS");
            else
                sprintf(path_buf, "%s", "4G_regOption_sim0_IMS");            
        }
        else
        {
            if(IMS_flag)
                sprintf(path_buf, "%s", "4G_regOption_sim1_None_IMS");
            else
                sprintf(path_buf, "%s", "4G_regOption_sim1_IMS");            
        } 
    }
    else if(option_flag == CURRENT_OPTION_FLAG)
    {
        if (!simslot)
        {
            if(IMS_flag)
                sprintf(path_buf, "%s", "4G_curOption_sim0_None_IMS");
            else
                sprintf(path_buf, "%s", "4G_curOption_sim0_IMS");            
        }
        else
        {
            if(IMS_flag)
                sprintf(path_buf, "%s", "4G_curOption_sim1_None_IMS");
            else
                sprintf(path_buf, "%s", "4G_curOption_sim1_IMS");            
        } 
    }
    else
    {
      CPUartLogPrintf("%s : incorrect option_flag\r\n", __FUNCTION__);    
      return;
    }
    
    sprintf(tmp_buf, "%d", option_value);
    psm_set_wrapper(PSM_MOD_LOCALE,  NULL, path_buf, tmp_buf);
    psm_commit__();
}

//检查是不是IMS通道发送的AT
//返回1，代表是IMS通道
//返回0，代表不是IMS通道
int isIMSChannel(int atpIndex)
{
    int ret = NONE_IMS_FLAG;
    
    if((atpIndex == TEL_AT_CMD_ATP_11) || (atpIndex == (TEL_AT_CMD_ATP_11 + 36)))
        ret = IMS_FLAG;

    CPUartLogPrintf("%s:  atHandle is %d, idx is %d", __FUNCTION__, atpIndex, ret); 

    return ret;
}

#ifndef LTEONLY_THIN
void update3GPsRegOption(int atHandle)
{
	int *pOption, *pReqOption;
    int idx = isIMSChannel(GET_ATP_INDEX(atHandle));    

#ifndef SINGLE_SIM
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))) {
		pOption = &gCurrentPSRegOption[idx];
		pReqOption = &gPSRequestedRegOption[idx];
	} else {
		pOption = &gCurrentPSRegOption_1[idx];
		pReqOption = &gPSRequestedRegOption_1[idx];
	}
#else
	pOption = &gCurrentPSRegOption[idx];
	pReqOption = &gPSRequestedRegOption[idx];

#endif

	*pOption = *pReqOption;
    CPUartLogPrintf("%s:  set pOption as %d", __FUNCTION__, *pReqOption);        
    save3GOption(GET_SIM1_FLAG(atHandle), idx, CURRENT_OPTION_FLAG, *pReqOption);
    
	#ifdef PPP_ENABLE
	if(isHandleForMasterSim(atHandle))
		modem_update_reg_option(GET_ATP_INDEX(atHandle), *pOption);
	#endif
	setRegOptionPersist(1,*pOption);
}
#endif

void update4GPsRegOption(int atHandle)
{
	int *pOption, *pReqOption;
    int idx = isIMSChannel(GET_ATP_INDEX(atHandle));
    
#ifndef SINGLE_SIM
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))) {
		pOption = &g4gCurrentPSRegOption[idx];
		pReqOption = &g4gPSRequestedRegOption[idx];
	} else {
		pOption = &g4gCurrentPSRegOption_1[idx];
		pReqOption = &g4gPSRequestedRegOption_1[idx];
	}
#else
	pOption = &g4gCurrentPSRegOption[idx];
	pReqOption = &g4gPSRequestedRegOption[idx];

#endif


	*pOption = *pReqOption;
    CPUartLogPrintf("%s:  set pOption as %d", __FUNCTION__,*pReqOption);      
    save4GOption(GET_SIM1_FLAG(atHandle), idx, CURRENT_OPTION_FLAG, *pReqOption);   


	#ifdef PPP_ENABLE
	if(isHandleForMasterSim(atHandle))
		modem_update_reg_option(GET_ATP_INDEX(atHandle), *pOption);
	#endif
	setRegOptionPersist(2,*pOption);
}

#ifndef LTEONLY_THIN
void updateCgregStatus(int atHandle, int regStatus)
{
	UINT8 *pCgregReady;
	int *pCurrentPSRegStatus;
	int sim = 1;

#ifndef SINGLE_SIM
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))) {
		pCgregReady = &CgregReady;
		pCurrentPSRegStatus = &gCurrentPSRegStatus;
	} else {
		pCgregReady = &CgregReady_1;
		pCurrentPSRegStatus = &gCurrentPSRegStatus_1;
		sim = 2;
	}
#else
	pCgregReady = &CgregReady;
	pCurrentPSRegStatus = &gCurrentPSRegStatus;
#endif


	if((regStatus == CI_PS_NW_REG_STA_REG_HPLMN) || (regStatus == CI_PS_NW_REG_STA_REG_ROAMING))
		*pCgregReady = 1;
	else
		*pCgregReady = 0;

	*pCurrentPSRegStatus = regStatus;

	if (*pCgregReady == 1 && isHandleForMasterSim(atHandle))
		set_force_reg_flag(0);

	CPUartLogPrintf("%s: SIM%d regStatus %d, CgregReady %d", __func__, sim, regStatus, *pCgregReady);
}
#endif

void updateCeregStatus(int atHandle, int regStatus)
{
	UINT8 *pCeregReady;
	int *pCurrentPSRegStatus;
	int sim = 1;

#ifndef SINGLE_SIM
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))) {
		pCeregReady = &CeregReady;
		pCurrentPSRegStatus = &g4gCurrentPSRegStatus;
	} else {
		pCeregReady = &CeregReady_1;
		pCurrentPSRegStatus = &g4gCurrentPSRegStatus_1;
		sim = 2;
	}
#else
	pCeregReady = &CeregReady;
	pCurrentPSRegStatus = &g4gCurrentPSRegStatus;
#endif


	if((regStatus == CI_PS_NW_REG_STA_REG_HPLMN) || (regStatus == CI_PS_NW_REG_STA_REG_ROAMING))
		*pCeregReady = 1;
	else
		*pCeregReady = 0;

	*pCurrentPSRegStatus = regStatus;

	if (*pCeregReady == 1 && isHandleForMasterSim(atHandle))
		set_force_reg_flag(0);

	CPUartLogPrintf("%s: SIM%d regStatus %d, CeregReady %d", __func__, sim, regStatus, *pCeregReady);
}

#ifndef LTEONLY_THIN
void updatePsRegDetail(UINT32 atHandle, CiPsNwRegInfo *detailInfo)
{
	CiPsNwRegInfo *pDetail;

#ifndef SINGLE_SIM
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))){
		pDetail = &psRegDetail;
	} else {
		pDetail = &psRegDetail_1;
	}
#else
	pDetail = &psRegDetail;

#endif


	if (detailInfo->lacPresent)
		memcpy(pDetail, detailInfo, sizeof(*pDetail));
}
#endif

void updatePs4GRegDetail(UINT32 atHandle, CiPs4GNwRegInfo *detailInfo)
{
	CiPs4GNwRegInfo *pDetail;

#ifndef SINGLE_SIM
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))){
		pDetail = &ps4GRegDetail;
	} else {
		pDetail = &ps4GRegDetail_1;
	}
#else
	pDetail = &ps4GRegDetail;
#endif

	if (detailInfo->tacPresent)
		memcpy(pDetail, detailInfo, sizeof(*pDetail));
}

void updateRoamingStatus(int atHandle, UINT8 roaming)
{
	UINT8 *pRoaming;

#ifndef SINGLE_SIM
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))) {
		pRoaming = &CurrentRoamingStatus;
	} else {
		pRoaming = &CurrentRoamingStatus_1;
	}
#else
	pRoaming = &CurrentRoamingStatus;
#endif

	*pRoaming = roaming;
}

void updateCregReady(int atHandle, int regStatus)
{
	UINT8 *pCregReady;

#ifndef SINGLE_SIM
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))) {
		pCregReady = &CregReady;
	} else {
		pCregReady = &CregReady_1;
	}
#else
	pCregReady = &CregReady;
#endif

	if((regStatus == CIMM_REGSTATUS_HOME) || (regStatus == CIMM_REGSTATUS_ROAMING) ||
	    (regStatus == CIMM_REGSTATUS_SMS_ONLY_HOME) || (regStatus == CIMM_REGSTATUS_SMS_ONLY_ROAMING))
		*pCregReady = 1;
	else
		*pCregReady = 0;

}


UINT8 getCregReady(UINT32 atHandle)
{
	UINT8 *pReady;
#ifndef SINGLE_SIM
	
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))){
		pReady = &CregReady;
	} else {
		pReady = &CregReady_1;
	}
#else
	pReady = &CregReady;
#endif

	return *pReady;
}

UINT8 getCgregReady(UINT32 atHandle)
{
	UINT8 *pReady;
#ifndef SINGLE_SIM	
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))){
		pReady = &CgregReady;
	} else {
		pReady = &CgregReady_1;
	}
#else
	pReady = &CgregReady;
#endif

	return *pReady;
}

INT32 getCgregStatus(UINT32 atHandle)
{
	int *pStatus;
#ifndef SINGLE_SIM	
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))){
		pStatus = &gCurrentPSRegStatus;
	} else {
		pStatus = &gCurrentPSRegStatus_1;
	}
#else
	pStatus = &gCurrentPSRegStatus;
#endif

	return *pStatus;
}

UINT8 getCeregReady(UINT32 atHandle)
{
	UINT8 *pReady;
#ifndef SINGLE_SIM	
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))){
		pReady = &CeregReady;
	} else {
		pReady = &CeregReady_1;
	}
#else
	pReady = &CeregReady;
#endif

	return *pReady;
}

INT32 getCeregStatus(UINT32 atHandle)
{
	int *pStatus;
#ifndef SINGLE_SIM	
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))){
		pStatus = &g4gCurrentPSRegStatus;
	} else {
		pStatus = &g4gCurrentPSRegStatus_1;
	}
#else
	pStatus = &g4gCurrentPSRegStatus;

#endif


	return *pStatus;
}

UINT32 getCellID(UINT32 atHandle)
{
	CiPsNwRegInfo *pDetail;
	CiPs4GNwRegInfo *p4GDetail;
	UINT32 cellID;

#ifndef SINGLE_SIM

	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))){
	    if (getCgregReady(atHandle))
		    pDetail = &psRegDetail;
		else
		    p4GDetail = &ps4GRegDetail;
		    
	} else {
	    if (getCgregReady(atHandle))
		    pDetail = &psRegDetail_1;
		else
		    p4GDetail = &ps4GRegDetail_1;
	}
#else
	if (getCgregReady(atHandle))
		pDetail = &psRegDetail;
	else
		p4GDetail = &ps4GRegDetail;

#endif


    if (getCgregReady(atHandle))
        cellID = pDetail->cellId;
    else
        cellID = p4GDetail->cellId;
        
	return cellID;
}

UINT16 getLac(UINT32 atHandle)
{
	CiPsNwRegInfo *pDetail;
	CiPs4GNwRegInfo *p4GDetail;
	UINT16 lac;

#ifndef SINGLE_SIM

	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))){
	    if (getCgregReady(atHandle))
		    pDetail = &psRegDetail;
		else
		    p4GDetail = &ps4GRegDetail;
	} else {
		if (getCgregReady(atHandle))
		    pDetail = &psRegDetail_1;
		else
		    p4GDetail = &ps4GRegDetail_1;
	}
#else
	if (getCgregReady(atHandle))
		pDetail = &psRegDetail;
	else
		p4GDetail = &ps4GRegDetail;
#endif


    if (getCgregReady(atHandle))
        lac = pDetail->lac;
    else
        lac = p4GDetail->tac;

	return lac;
}

UINT8* getRoamingStatusP(UINT32 atHandle)
{
	UINT8 *pRoaming;

#ifndef SINGLE_SIM
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))) {
		pRoaming = &CurrentRoamingStatus;
	} else {
		pRoaming = &CurrentRoamingStatus_1;
	}
#else
	pRoaming = &CurrentRoamingStatus;
#endif


	return pRoaming;
}

void showPDP(PdpContext *Pdp)
{
	if(Pdp == NULL)
        return;
/*
	int i;

	ATDBGMSG(atcmdsrv,197,"%s: start =====", __FUNCTION__);

	ATDBGMSG(atcmdsrv,198,"ConnectionNumber is %d, connected_tick is %u, total_connected_tick is %u, PDP_Type is %d, IP_Type is %d", Pdp->ConnectionNumber, \
		Pdp->Pdp_Info.connected_tick,Pdp->Pdp_Info.total_connected_tick, Pdp->Pdp_Info.PDP_Type, Pdp->Pdp_Info.IP_Type );

	ATDBGMSG(atcmdsrv,199,"IsDefaultConnection is %d, PrimaryCID is %d, SecondaryCID is %d, QCI is %d, BearerID is %d", Pdp->Pdp_Info.IsDefaultConnection, \
		Pdp->Pdp_Info.PrimaryCID, Pdp->Pdp_Info.SecondaryCID, Pdp->Pdp_Info.QCI, Pdp->Pdp_Info.BearerID);

	ATDBGMSG(atcmdsrv,200,"iptype_dialer is %d, iptype_to_dialer is %d, APN is %s, LTE_APN is %s", Pdp->Pdp_Info.iptype_dialer, \
		Pdp->Pdp_Info.iptype_to_dialer, Pdp->Pdp_Info.APN, Pdp->Pdp_Info.LteAPN);

	ATDBGMSG(atcmdsrv,201,"Usr2G3G is %s, PASWD2G3G is %s, Authtype2G3G is %s, Usr4G is %s, PASWD4G is %s, Authtype4G is %s", Pdp->Pdp_Info.Usr2G3G,\
		Pdp->Pdp_Info.PASWD2G3G, Pdp->Pdp_Info.Authtype2G3G, Pdp->Pdp_Info.Usr4G, Pdp->Pdp_Info.PASWD4G, Pdp->Pdp_Info.Authtype4G);

	if(Pdp->PF)
	{
		showPFInfo(Pdp->PF);
	}
	else
		ATDBGMSG(atcmdsrv,202,"Pdp->PF is NULL");


	if(Pdp->IPV4)
	{
		ATDBGMSG(atcmdsrv,203,"IPV4 Addr=%d.%d.%d.%d\n",(Pdp->IPV4->IPAddr & 0xff000000)>>24,
		                   (Pdp->IPV4->IPAddr & 0x00ff0000)>>16,(Pdp->IPV4->IPAddr & 0x0000ff00)>>8,(Pdp->IPV4->IPAddr & 0x0000ff));

		ATDBGMSG(atcmdsrv,204,"IPV4 PrimaryDns is %X", Pdp->IPV4->PrimaryDNS);
		ATDBGMSG(atcmdsrv,205,"IPV4 SecondaryDns is %X", Pdp->IPV4->SecondaryDNS);
		ATDBGMSG(atcmdsrv,206,"IPV4 submask is %X", Pdp->IPV4->Mask);

		ATDBGMSG(atcmdsrv,207,"IPV4 GateWay=%d.%d.%d.%d\n",(Pdp->IPV4->GateWay & 0xff000000)>>24,
		                   (Pdp->IPV4->GateWay & 0x00ff0000)>>16,(Pdp->IPV4->GateWay & 0x0000ff00)>>8,(Pdp->IPV4->GateWay & 0x0000ff));
	}
	else
		ATDBGMSG(atcmdsrv,208,"Pdp->IPV4 is NULL");

	if(Pdp->IPV6)
	{
		for(i=0; i<4; i++)
		{
			ATDBGMSG(atcmdsrv,209,"IPV6 Addr[%d]=%X",i,Pdp->IPV6->IPV6Addr[i]);
		}
	}
	else
		ATDBGMSG(atcmdsrv,210,"Pdp->IPV6 is NULL");

	ATDBGMSG(atcmdsrv,211,"%s: end =====", __FUNCTION__);
	*/
}

PacketFilterInfo* CopyTFTList(PacketFilterInfo *SrcList)
{
#define BUFFER_ALIGN_SIZE 8
	PacketFilterInfo *pPF = NULL;
	PacketFilterInfo *DstpPF = NULL;
	PacketFilterInfo *header = NULL;
	int i=0;
	INT32 buf_size, padding_size, extend_size = 0;

	buf_size = sizeof(PacketFilterInfo);
	padding_size = buf_size % BUFFER_ALIGN_SIZE;
	//ATDBGMSG("%s: pf info size %d, padding size %d", __FUNCTION__, buf_size, padding_size);

	if (padding_size != 0)
		extend_size = (BUFFER_ALIGN_SIZE - padding_size) + 32;
	else
		extend_size = 32;

	buf_size += extend_size;

	for(pPF = SrcList; pPF != NULL; i++)
	{
		if(i==0)
		{
			DstpPF = malloc(buf_size);
			ASSERT(DstpPF!=NULL)
			header = DstpPF;
		}
		else
		{
			DstpPF->next = malloc(buf_size);
			ASSERT(DstpPF->next!=NULL)

			DstpPF = DstpPF->next;
		}
		//ATDBGMSG("%s: src pPF 0x%x, dst 0x%x", __FUNCTION__, pPF, DstpPF);
		memset(DstpPF, 0, buf_size);
		memcpy(DstpPF, pPF, sizeof(PacketFilterInfo));
		DstpPF->next = NULL;
		/*set extend buffer to 0x5A*/
		memset((char *)DstpPF+sizeof(PacketFilterInfo), 0x5A, extend_size);
		showPFInfo(DstpPF);

		pPF = (PacketFilterInfo *)pPF->next;
	}

	//ATDBGMSG("%s done with list number %d, head 0x%x", __FUNCTION__,i, header);
	return header;
}

PdpContextList* CopyPdpList(PdpContextList *SrcList)
{
	PdpContextList *pdp=NULL;
	PdpContextList *Dstpdp=NULL;
	int i=0;
	PdpContextList* header=NULL;

	for(pdp = SrcList; pdp != NULL; )
	{
		//ATDBGMSG("%s: src pdp 0x%x", __FUNCTION__, pdp);
		showPDP(&(pdp->PDP));

		if(i==0)
		{
			Dstpdp = malloc(sizeof(PdpContextList));
			ASSERT(Dstpdp!=NULL)

			header = Dstpdp;
		}
		else
		{
			Dstpdp->next=malloc(sizeof(PdpContextList));
			ASSERT(Dstpdp->next!=NULL)

			Dstpdp=Dstpdp->next;
		}
		memset(Dstpdp,0,sizeof(PdpContextList));
		Dstpdp->next=NULL;

		memcpy(Dstpdp, pdp, sizeof(PdpContextList));

		//ATDBGMSG("%s: dst pdp 0x%x", __FUNCTION__, Dstpdp);

		if(pdp->PDP.IPV4)
		{
			Dstpdp->PDP.IPV4 = (Ipv4Info *)malloc(sizeof(Ipv4Info));
			ASSERT(Dstpdp->PDP.IPV4 != NULL);
			memcpy(Dstpdp->PDP.IPV4, pdp->PDP.IPV4, sizeof(Ipv4Info));
		}

		if(pdp->PDP.IPV6)
		{
			Dstpdp->PDP.IPV6 = (Ipv6Info *)malloc(sizeof(Ipv6Info));
			ASSERT(Dstpdp->PDP.IPV6 != NULL);
			memcpy(Dstpdp->PDP.IPV6, pdp->PDP.IPV6, sizeof(Ipv6Info));
		}

		if(pdp->PDP.PF)
		{
			Dstpdp->PDP.PF = (PacketFilterInfo *)malloc(sizeof(PacketFilterInfo));
			ASSERT(Dstpdp->PDP.PF != NULL);
			memcpy(Dstpdp->PDP.PF, pdp->PDP.PF, sizeof(PacketFilterInfo));
		}

		pdp = (PdpContextList *)pdp->next;

		i++;
	}

	//ATDBGMSG("%s done with list number %d", __FUNCTION__,i);
	return header;
}

PdpContextList *getPdpListHead(int sAtpIndex)
{
	return gAtpCtrl[sAtpIndex].pdpCtx.head;
}

PacketFilterInfo *getTftListHead(int sAtpIndex)
{
	return gAtpCtrl[sAtpIndex].tftCtx.head;
}

PdpContextList *GetCurrentPdpList(int sAtpIndex)
{
	PdpContextList *pdpList = NULL;
	PdpContextList *pdpListHead = gAtpCtrl[sAtpIndex].pdpCtx.head;

	pdpList = CopyPdpList(pdpListHead);

	return pdpList;
}

PacketFilterInfo* GetCurrentTFTList(int sAtpIndex)
{
	PacketFilterInfo* pTFTList = NULL;
	PacketFilterInfo* tftListHead = gAtpCtrl[sAtpIndex].tftCtx.head;

   	pTFTList = CopyTFTList(tftListHead);
	return pTFTList;
}

INT32 get_current_reg_status(UINT32 atHandle)
{
	int *psRegStatus;
	int *ps4gRegStatus;

#ifndef SINGLE_SIM
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))){
		psRegStatus = &gCurrentPSRegStatus;
		ps4gRegStatus = &g4gCurrentPSRegStatus;
	} else {
		psRegStatus = &gCurrentPSRegStatus_1;
		ps4gRegStatus = &g4gCurrentPSRegStatus_1;
	}
#else
	psRegStatus = &gCurrentPSRegStatus;
	ps4gRegStatus = &g4gCurrentPSRegStatus;

#endif


	if(*psRegStatus == CI_PS_NW_REG_STA_REG_HPLMN || *ps4gRegStatus == CI_PS_NW_REG_STA_REG_HPLMN)
		return CI_PS_NW_REG_STA_REG_HPLMN;
	else if(*psRegStatus == CI_PS_NW_REG_STA_NOT_REGED && *ps4gRegStatus == CI_PS_NW_REG_STA_NOT_REGED)
		return CI_PS_NW_REG_STA_NOT_REGED;
	else if(*psRegStatus == CI_PS_NW_REG_STA_REG_EMERGENCY && *ps4gRegStatus == CI_PS_NW_REG_STA_REG_EMERGENCY)
		return CI_PS_NW_REG_STA_REG_EMERGENCY;
	else if(*psRegStatus == CI_PS_NW_REG_STA_REG_ROAMING || *ps4gRegStatus == CI_PS_NW_REG_STA_REG_ROAMING)
		return CI_PS_NW_REG_STA_REG_ROAMING;
	else if(*psRegStatus == CI_PS_NW_REG_STA_REG_DENIED && *ps4gRegStatus == CI_PS_NW_REG_STA_REG_DENIED)
		return CI_PS_NW_REG_STA_REG_DENIED;
	else
		return *ps4gRegStatus;
}

UINT8 get_force_reg_flag(void)
{
	return gForceReg;
}

void set_force_reg_flag(UINT8 flag)
{
	gForceReg = flag;
}

void setMtPdp(UINT8 cid, BOOL isMT)
{
    if (cid >= CI_PS_MAX_CID)
        return;

	gPdpMT[cid] = isMT;
}

BOOL isMtPdp(UINT8 cid)
{
    if (cid >= CI_PS_MAX_CID)
        return FALSE;

	return gPdpMT[cid];
}

BOOL isLTENetwork(INT32 atHandle)
{
	int *pPsActDetail = &gPsActDetail;
#ifndef SINGLE_SIM	
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))) {
		pPsActDetail = &gPsActDetail;
	} else {
		pPsActDetail = &gPsActDetail_1;
	}
#else
	pPsActDetail = &gPsActDetail;
#endif


	if (*pPsActDetail == CI_PS_ACT_EUTRAN || *pPsActDetail == CI_PS_ACT_EUTRAN_PLUS)
		return TRUE;
	else
		return FALSE;
}

UINT16 gNwLac;
UINT8 gNwRac;

UINT16 gNwLac_1;
UINT8 gNwRac_1;

int updateRAU(UINT32 atHandle, CiPsNwRegInfo *nwRegInfo)
{
	UINT16 *pLac;
	UINT8 *pRac;

	if(nwRegInfo == NULL)
		return 0;

#ifndef SINGLE_SIM	
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))) {
		pLac = &gNwLac;
		pRac = &gNwRac;
	} else {
		pLac = &gNwLac_1;
		pRac = &gNwRac_1;
	}
#else
	pLac = &gNwLac;
	pRac = &gNwRac;

#endif


	if(nwRegInfo != NULL && (nwRegInfo->status == 1 ||nwRegInfo->status == 5))
	{
		if(nwRegInfo->lacPresent)
		{
			if(*pLac == 0 && *pRac == 0)
			{
				*pLac = nwRegInfo->lac;
				*pRac = nwRegInfo->rac;
				return 0;
			}
			else if(*pLac != nwRegInfo->lac || *pRac != nwRegInfo->rac)
			{
				CPUartLogPrintf("%s: LAC %d -> %d, RAC %d -> %d",__FUNCTION__,*pLac,nwRegInfo->lac,*pRac,nwRegInfo->rac);
				*pLac = nwRegInfo->lac;
				*pRac = nwRegInfo->rac;
				return 1;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	else
		return 0;

}

#endif

#ifdef CRANE_MCU_DONGLE
void updateNwSwitchState(int atHandle, UINT8 lastNwReady, UINT8 currNwReady)
{
	if (lastNwReady == 0 && currNwReady == 1)
	{
	  	/*0 -> 1*/
		nw_switch_state = NW_STATE_IN;
	}
	else if (lastNwReady == 1 && currNwReady == 0)
	{
		/*1 -> 0*/
		nw_switch_state = NW_STATE_OUT;
	}
	else
		nw_switch_state = NW_STATE_NO_CHANGE;
}
#endif


void convertIpv4Unit2Str(unsigned char* addrData,  char* ippStr)
{
	int i=0;
	char tmpBuf[20];
	char ippBuf[CI_PS_PDP_IP_V4_SIZE] = { '\0' };

	memset(tmpBuf, 0, sizeof(tmpBuf));

	for(i = 0 ; i < IPV4_ADDR_LENGTH - 1; i++)
	{
		sprintf ( (char *)tmpBuf, "%d.", *(addrData+i));
		/*safe use, mischecked by coverity*/
		/*coverity[string_overflow]*/
		strcat((char *)ippBuf, (char *)tmpBuf);
	}
	sprintf ( (char *)tmpBuf, "%d", *(addrData+i));
	/*safe use, mischecked by coverity*/
	/*coverity[string_overflow]*/
	strcat((char *)ippBuf, (char *)tmpBuf);

	strcpy((char *)ippStr, (char *)ippBuf);
	return;
}

void convertIpv6Unit2DotStr(int ipv6AddrType, unsigned char* addrData, char* ippStr)
{
	int i=0;
	char tmpBuf[20];
	char ippBuf[CI_PS_PDP_IP_V6_SIZE] = { '\0' };
	memset(tmpBuf, 0, sizeof(tmpBuf));

	if(ipv6AddrType == CI_PS_PDP_IPV6_INTERFACE)
		sprintf ( (char *)ippBuf, "254.128.0.0.0.0.0.0.");
	for(i = 0;i < pdpAddrlength[ipv6AddrType] - 1; i++)
	{
		sprintf ( (char *)tmpBuf, "%d.", *(addrData+i));
		strcat((char *)ippBuf, (char *)tmpBuf);
	}
	sprintf ( (char *)tmpBuf, "%d", *(addrData+i));
	strcat((char *)ippBuf, (char *)tmpBuf);

	strcpy((char *)ippStr, (char *)ippBuf);
	return;
}

void convertIpv6Unit2ColonStr(UINT32 reqHandle, int ipv6AddrType,unsigned char* addrData, char* ippStr)
{
	char tmpBuf[20];
	char ippBuf[CI_PS_PDP_IP_V6_SIZE] = { '\0' };
	int i=0, addrVal=0;
	int *pIPv6_LeadingZeros;
#ifndef SINGLE_SIM		
	if (!GET_SIM1_FLAG(reqHandle)) {
		pIPv6_LeadingZeros = &gIPv6_LeadingZeros;
	} else {
		pIPv6_LeadingZeros = &gIPv6_LeadingZeros_1;
	}
#else
	pIPv6_LeadingZeros = &gIPv6_LeadingZeros;
#endif


	memset(tmpBuf, 0, sizeof(tmpBuf));
	if(ipv6AddrType == CI_PS_PDP_IPV6_INTERFACE)
	{
		if(*pIPv6_LeadingZeros)
			sprintf ( (char *)ippBuf, "FE80:0000:0000:0000:");
		else
			sprintf ( (char *)ippBuf, "FE80:0:0:0:");
	}
	for(i = 0; i < pdpAddrlength[ipv6AddrType] - 2; i = i + 2)
	{
		addrVal = (*(addrData + i) << 8) | (*(addrData + i + 1));
		if(*pIPv6_LeadingZeros)
			sprintf ( (char *)tmpBuf,"%04X:", addrVal);
		else
			sprintf ( (char *)tmpBuf,"%X:", addrVal);
		strcat((char *)ippBuf, (char *)tmpBuf);
	}

	addrVal = (*(addrData+i) << 8) | (*(addrData + i + 1));
	if(*pIPv6_LeadingZeros)
		sprintf ( (char *)tmpBuf,"%04X", addrVal);
	else
		sprintf ( (char *)tmpBuf,"%X", addrVal);
	strcat((char *)ippBuf, (char *)tmpBuf);

	strcpy((char *)ippStr, (char *)ippBuf);
	return;
}

void convertIpv6Unit2CompZeroStr(int ipv6AddrType, unsigned char* addrData, char* ippStr)
{
	char ippBuf[CI_PS_PDP_IP_V6_SIZE] = { '\0' };
	unsigned char ipv6full[CI_PS_PDP_ADDR_MAX_LENGTH] = { 0 };

	if(ipv6AddrType == CI_PS_PDP_IPV6_INTERFACE)
	{
		ipv6full[0] = 0xFE;
		ipv6full[1] = 0x80;
		memcpy(ipv6full + 8, addrData, 8);
	}
	else
		memcpy(ipv6full, addrData, 16);

	_inet_ntop(AF_INET6, ipv6full, ippBuf, MAX_ADDR_PRESENTATION_BUF_LEN);

	strcpy((char *)ippStr, (char *)ippBuf);
	return;
}

void convertIpv6Unit2Str(UINT32 reqHandle, int ipv6AddrType, unsigned char* addrData,  char* ippStr)
{
	int *pIPv6_AddressFormat, *pIPv6_LeadingZeros, *pIPv6_CompressZeros;
#ifndef SINGLE_SIM	
	if (!GET_SIM1_FLAG(reqHandle)) {
		pIPv6_AddressFormat = &gIPv6_AddressFormat;
		pIPv6_LeadingZeros = &gIPv6_LeadingZeros;
		pIPv6_CompressZeros = &gIPv6_CompressZeros;
	} else {
		pIPv6_AddressFormat = &gIPv6_AddressFormat_1;
		pIPv6_LeadingZeros = &gIPv6_LeadingZeros_1;
		pIPv6_CompressZeros = &gIPv6_CompressZeros_1;
	}
#else
	pIPv6_AddressFormat = &gIPv6_AddressFormat;
	pIPv6_LeadingZeros = &gIPv6_LeadingZeros;
	pIPv6_CompressZeros = &gIPv6_CompressZeros;
#endif

	if(*pIPv6_AddressFormat == 0)
		convertIpv6Unit2DotStr(ipv6AddrType, addrData, ippStr);
	else
	{
		if(*pIPv6_LeadingZeros || ((*pIPv6_LeadingZeros == 0) && (*pIPv6_CompressZeros == 0)))
			convertIpv6Unit2ColonStr(reqHandle, ipv6AddrType, addrData, ippStr);
		else
			convertIpv6Unit2CompZeroStr(ipv6AddrType, addrData, ippStr);
	}
	return;
}

void convertIpUnit2Str(UINT32 reqHandle, int addrType, unsigned char* valData, char* ippStr)
{
	if(addrType == CI_PS_PDP_IPV4)
		convertIpv4Unit2Str(valData, ippStr);

	else if((addrType == CI_PS_PDP_FULL_IPV6) || (addrType == CI_PS_PDP_IPV6_INTERFACE))
		convertIpv6Unit2Str(reqHandle, addrType, valData, ippStr);

	return;
}

 //this fucntion is change the mask_len to the mask address
char* subnetmask_Len2Str(UINT32 reqHandle, int addrType, UINT16 maskLen, char* maskStr)
{
	int i=0, loop=0, len_temp=0;
	UINT32  i_mask=0;
	UINT16 ipv6_falg = 0;
	UINT8 shift_offset = 0;
	UINT8 shift_temp = 0;
	char tempBuf[50] = "\0";
	char maskStrBuf[CI_PS_PDP_IP_V6_SIZE] = "\0";
	int *pIPv6_AddressFormat;
#ifndef SINGLE_SIM		
	if (!GET_SIM1_FLAG(reqHandle)) {
		pIPv6_AddressFormat = &gIPv6_AddressFormat;
	} else {
		pIPv6_AddressFormat = &gIPv6_AddressFormat_1;
	}
#else
	pIPv6_AddressFormat = &gIPv6_AddressFormat;
#endif


	len_temp = maskLen;

	if(addrType == CI_PS_PDP_IPV4)
		loop = 1;
	else
		loop = 4;

	while(loop)
	{
		len_temp = maskLen - shift_offset;

		if(len_temp <= 0)
		{
			shift_temp = 0;
		}
		else if((len_temp > 0) && ( len_temp <= IPV4_SUBNETMUX_MAX_LEN))
		{
			shift_temp = len_temp;
		}
		else
		{
			shift_temp = IPV4_SUBNETMUX_MAX_LEN;
		}

		for (i = 0, i_mask = 0; i < shift_temp; i++)
		{
			i_mask = (i_mask << 1) | 1;
		}

		i_mask = i_mask << (32 - shift_temp);
		if(ipv6_falg == 0)
		{
			if(*pIPv6_AddressFormat && ((addrType == CI_PS_PDP_FULL_IPV6) || (addrType == CI_PS_PDP_IPV6_INTERFACE)))
				sprintf( tempBuf, "%04x:%04X", (i_mask >> 16) & 0xffff, i_mask & 0xffff);
			else
				sprintf( tempBuf, "%d.%d.%d.%d", (i_mask >> 24) & 0xff, (i_mask >> 16) & 0xff, (i_mask >> 8) & 0xff, i_mask & 0xff);
		}
		else
		{
			if(*pIPv6_AddressFormat && ((addrType == CI_PS_PDP_FULL_IPV6) || (addrType == CI_PS_PDP_IPV6_INTERFACE)))
				sprintf( tempBuf, ":%04X:%04X", (i_mask >> 16) & 0xffff, i_mask & 0xffff);
			else
				sprintf( tempBuf, ".%d.%d.%d.%d", (i_mask >> 24) & 0xff, (i_mask >> 16) & 0xff, (i_mask >> 8) & 0xff, i_mask & 0xff);
		}

		/*Fix klocwork[Buffer Overflow]*/
		strncat(maskStrBuf, tempBuf, CI_PS_PDP_IP_V6_SIZE-strlen(maskStrBuf)-1);
		ipv6_falg++;
		loop--;
		shift_offset += IPV4_SUBNETMUX_MAX_LEN;
	}

	strcpy((char *)maskStr, (char *)maskStrBuf);
	return maskStr;
}
 //this fucntion is change the mask_len,to the mask addressf
 char* subnetmask_len2str(UINT16 mask_len, char* mask_str)
 {
	 int i=0;
	 UINT32  i_mask=0;
	  UINT16 len_temp=0;
	UINT16 ipv6_falg=0;
	 UINT8 shift_offset=0;
	  UINT8 shift_temp=0;
	 char tempbuf1[100]="\0";
	 char tempbuf2[200]="\0";
	 INT32 tmpLen = 0;

	 len_temp=mask_len;

	 while(shift_offset<len_temp)
	 {
		 if((len_temp-shift_offset)<=IPV4_SUBNETMUX_MAX_LEN)
		 {
			 shift_temp=len_temp-shift_offset;
		 }
		 else
		 {
			 shift_temp=IPV4_SUBNETMUX_MAX_LEN;
		 }
		 for (i = 1, i_mask = 1; i < shift_temp; i++)
		 {
			  i_mask = (i_mask << 1) | 1;
		 }

		 i_mask =i_mask << (32 - shift_temp);
		 if(ipv6_falg==0)
			 sprintf( tempbuf1, "%d.%d.%d.%d", (i_mask>>24)&0xff, (i_mask>>16)&0xff,(i_mask>>8)&0xff,i_mask&0xff);
		 else
			  sprintf( tempbuf1, ".%d.%d.%d.%d", (i_mask>>24)&0xff, (i_mask>>16)&0xff,(i_mask>>8)&0xff,i_mask&0xff);
		 //[klockwork][issue id:  2298]
		 STRNCAT_CHAR_BYTES(tempbuf2, tempbuf1,tmpLen);
		 //strcat( tempbuf2, tempbuf1);

		 ipv6_falg++;

		 shift_offset+=IPV4_SUBNETMUX_MAX_LEN;

	 }

	 strcpy(mask_str,(char *)tempbuf2);
	 return mask_str;
 }
 /**this function will conerterd the subsnet addr to len ,used for both IPV4 and IPV6*/
int subnetmask_Str2Len(char* mask)
{
	int netmask = 0;
	UINT8  mask_tmp=0;
	UINT8 *start_p=NULL, *end_p=NULL, i=0;
	/*Fix klocwork[Buffer Overflow]*/
	UINT32  tmpVal[256]={0};
	BOOL success = FALSE;
	UINT8  count = 0;

	start_p =(UINT8* )mask;
	end_p = (UINT8* )mask;

	for(i = 0; i < 128; i++)
	{
		if(*(start_p+i) == '.')
			count++;
		else if(*(start_p+i) == '\0')
			break;
	}

	for (i = 0; i < count + 1; i++) /* LoopForeverCatch */
	{
		tmpVal[i] = strtoul ((const char *)start_p, (char **)&end_p, 10);

		if (tmpVal[i] > 255)
		{
			break;
		}

		if (i == (count))
		{
			if (*end_p == '\0')
			{
				success = TRUE;
			}
		}
		else if (*end_p != '.')
		{
			break;
		}
		else
		{
			start_p = end_p + 1;
		}
	}

	if(success)
	{
		for(i = 0;i < (count + 1); i++)
		{
			mask_tmp = (UINT8)tmpVal[i];
			while (mask_tmp & 0x80)
			{
				netmask++;
				mask_tmp = (mask_tmp << 1);
			}
		}
	}
	return netmask;
}

 /**this function will conerterd the subsnet add to len ,used for both IPV4 and IPV6*/
 int subnetmask_str2len(char* mask)
 {
	int netmask = 0;
	UINT8  mask_tmp=0;
	UINT8 *start_p=NULL, *end_p=NULL, i=0;
	//[klockwork][issue id: 2291]
	UINT32  tmpVal[255]={0};
	BOOL success = FALSE;
	UINT8  count = 0;

	start_p = (UINT8 *)mask;
	end_p = (UINT8 *)mask;

	for(i = 0; i < 128; i++)
	{
		if(*(start_p+i) == '.')
			count++;
		else if(*(start_p+i) == '\0')
			break;
	}

	for (i = 0; i < count + 1; i++) /* LoopForeverCatch */
	{
		tmpVal[i] = strtoul ((const char *)start_p, (char **)&end_p, 10);

		CPUartLogPrintf("strtoul out,i:%d,value: %d,nd_P:%d\r\n",i,tmpVal[i] ,*end_p);
		if (tmpVal[i] > 255)
		{
			break;
		}

		if (i == (count))
		{
			if (*end_p == '\0')
			{
				success = TRUE;
			}
		}
		else if (*end_p != '.')
		{
			break;
		}
		else
		{
			start_p = end_p + 1;
		}
	}
	CPUartLogPrintf("strtoul_2 ,will set the converted  iput value:sucees:%d\r\n",success );


	for(i=0;i<(count+1);i++)
	{
		mask_tmp=(UINT8)tmpVal[i];
		while (mask_tmp & 0x80)
		{
			 netmask++;
			 mask_tmp = (mask_tmp << 1);
		}
	}
	return netmask;
 }

void getMaskAttachStr(UINT32 reqHandle, int addrType,  int subnetLen, char* maskAttachStr)
{
	char tempBuf[CI_PS_PDP_IP_V6_SIZE + 10] = { '\0' };
	char maskStr[CI_PS_PDP_IP_V6_SIZE + 10] = { '\0' };
	int *pIPv6_AddressFormat, *pIPv6_SubnetNotation;
#ifndef SINGLE_SIM	
	if (!GET_SIM1_FLAG(reqHandle)) {
		pIPv6_AddressFormat = &gIPv6_AddressFormat;
		pIPv6_SubnetNotation = &gIPv6_SubnetNotation;
	} else {
		pIPv6_AddressFormat = &gIPv6_AddressFormat_1;
		pIPv6_SubnetNotation = &gIPv6_SubnetNotation_1;
	}
#else
	pIPv6_AddressFormat = &gIPv6_AddressFormat;
	pIPv6_SubnetNotation = &gIPv6_SubnetNotation;

#endif

	if(*pIPv6_AddressFormat && *pIPv6_SubnetNotation && ((addrType == CI_PS_PDP_FULL_IPV6) || (addrType == CI_PS_PDP_IPV6_INTERFACE)))
	{
		sprintf(tempBuf, "/%d", subnetLen);
	}
	else
	{
		subnetmask_Len2Str(reqHandle, addrType, subnetLen, maskStr);
		if(addrType == CI_PS_PDP_IPV4)
		{
			sprintf((char *)tempBuf, ".");
		}
		else
		{
			if(*pIPv6_AddressFormat == 0)
				sprintf((char *)tempBuf, ".");
			else
				sprintf((char *)tempBuf, " ");
		}
		strcat((char *)tempBuf, (char *)maskStr);
	}

	strcpy((char *)maskAttachStr, (char *)tempBuf);

	return;
}

void addToList(DIRECTIPCONFIGLIST *newdrvnode)
{
    DIRECTIPCONFIGLIST *pCurrNode=NULL;

    if(directIpAddressList== NULL)
    {
        directIpAddressList = newdrvnode;
    }
    else
    {
        pCurrNode = directIpAddressList;
        while(pCurrNode->next != NULL)
            pCurrNode = pCurrNode->next;

        pCurrNode->next = newdrvnode;

    }
    return;
}
 BOOL  searchListByCid(unsigned char cid, DIRECTIPCONFIGLIST ** ppBuf)
{
    DIRECTIPCONFIGLIST *pCurrBuf=NULL;

    if(directIpAddressList == NULL)
        return FALSE;

    pCurrBuf = directIpAddressList;
    while((pCurrBuf!=NULL)&&(pCurrBuf->directIpAddress.dwContextId != cid))
    {
        pCurrBuf=pCurrBuf->next;
    }

    if(pCurrBuf!=NULL)
    {
        *ppBuf=pCurrBuf;
        return TRUE;
    }

    return FALSE;
}


void  removeNodeByCid(unsigned char cid)
{
    DIRECTIPCONFIGLIST *pCurrNode=NULL, *pPrevNode=NULL;

    pPrevNode = pCurrNode = directIpAddressList;
    while(pCurrNode!=NULL)
    {
        if(pCurrNode->directIpAddress.dwContextId == cid)
        {
            if(pCurrNode == directIpAddressList)
            {
                directIpAddressList = pCurrNode ->next;
		free(pCurrNode);
                pPrevNode = pCurrNode = directIpAddressList;
            }
            else
            {
                pPrevNode->next = pCurrNode->next;
		free(pCurrNode);
                pCurrNode = pPrevNode->next;
            }
        }
        else
        {
            pPrevNode = pCurrNode;
            pCurrNode=pCurrNode->next;
        }
	}
}

UINT8 getPdpIndexByCid(UINT8 cid, AtciCurrentSetCntx *pdp_table)
{
	UINT8 index;
	for(index =0; index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM; index++)
	{
		if(pdp_table[index].cid == cid)
			break;
	}
	#ifdef QUEC_CID_INFO_CFUN0_CLEAR_RESUME_12352
		ATDBGMSG("%s: index %d", __func__, index);
	#endif
	return index;
}

static UINT8 getFreePdpIndexFromTable(AtciCurrentSetCntx *pdp_table)
{
	UINT8 index;
	for(index =0; index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM; index++)
	{
		if(pdp_table[index].cid == CI_PS_MAX_CID)
			break;
	}
	#ifdef QUEC_CID_INFO_CFUN0_CLEAR_RESUME_12352
		ATDBGMSG("%s: index %d", __func__, index);
        ATDBGMSG("%s: CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM %d", __func__, CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM);
	#endif
	//ASSERT(index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM);
	//if (index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
	//{
	    //ATDBGMSG("%s: table full",__func__);
	//}
	return index;
}
//#ifndef LTEONLY_THIN
//AT+CGREG=
CiReturnCode PS_SetGPRSRegStatus (UINT32 atHandle, UINT32 state)
{
	CiReturnCode                        ret = CIRC_FAIL;
	CiPsPrimEnableNwRegIndReq    *setNwRegIndReq=NULL;
	int *pPSRequestedRegOption = NULL;
    int *pCurrRegOption = NULL;
	UINT32 at_Handle = GET_AT_HANDLE( atHandle );
	UINT32 sAtpIndex = GET_ATP_INDEX( at_Handle );    
    int idx = isIMSChannel(sAtpIndex); 
    
#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
		pCurrRegOption = &gCurrentPSRegOption[idx];
		pPSRequestedRegOption = &gPSRequestedRegOption[idx];
	} else {
		pCurrRegOption = &gCurrentPSRegOption_1[idx];
		pPSRequestedRegOption = &gPSRequestedRegOption_1[idx];
	}
#else
	pCurrRegOption = &gCurrentPSRegOption[idx];
	pPSRequestedRegOption = &gPSRequestedRegOption[idx];
#endif

    *pPSRequestedRegOption = (CiPsNwRegIndFlag)state;        
#ifndef LTEONLY_THIN
    save3GOption(GET_SIM1_FLAG(atHandle), idx, REQUEST_OPTION_FLAG, state);
#endif

    if(!isIMSChannel(sAtpIndex) && ( state < CI_PS_NW_REG_IND_ENABLE_DETAIL))
    {
        *pCurrRegOption = (CiPsNwRegIndFlag)state;        
        CPUartLogPrintf("%s 1:  set pPSRequestedRegOption as %d", __FUNCTION__, state);
		
#ifndef LTEONLY_THIN
        save3GOption(GET_SIM1_FLAG(atHandle), idx, CURRENT_OPTION_FLAG, state);  
#endif
        ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,NULL);
        return ret;
    }
    
	setNwRegIndReq = utlCalloc(1, sizeof(*setNwRegIndReq));
	if (setNwRegIndReq == NULL)
		return CIRC_FAIL;
	setNwRegIndReq->flag = state;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_ENABLE_NW_REG_IND_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_ENABLE_NW_REG_IND_REQ), (void *)setNwRegIndReq);

	return ret;
}
//#endif

#ifdef LWIP_IPNETBUF_SUPPORT

#ifndef ATCMD_UNIFY_ACT_CI
CiReturnCode setRedefinePdpActiveReq(UINT32 reqHandle, UINT8 cid, BOOL activation)
{
	CiReturnCode ret = CIRC_FAIL;
	telPsPdpCtx *setPdpCtx = telGetPdpCtx(cid);
	telPsDefaultPdpApn *defaultPdpApn = telGetDefaultPdpApn();
        CiPsPrimActivateReconfigPdpCtxReq *setReconfigActStateReq = NULL;
        UINT32 atHandle = GET_AT_HANDLE(reqHandle);
        UINT8 index = 0;
        AtciCurrentSetCntx *p_cInfo = NULL;

	if (!activation)
		return ret;

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
				p_cInfo = gCIDList.cInfo;
				} else {
				p_cInfo = gCIDList.cInfo_1;
	}
#else
	p_cInfo = gCIDList.cInfo;
#endif

#ifdef QUECTEL_NETWORK_SUPPORT
	CPUartLogPrintf("%s,%d,cid=%d,reDefined=%d",__func__,__LINE__,cid,setPdpCtx->reDefined);
#endif

	//ATDBGMSG("%s: reqHandle %lx, cid %d", __func__, reqHandle, cid);
	if (setPdpCtx && setPdpCtx->reDefined )
	{
		#if 1
		setReconfigActStateReq = (CiPsPrimActivateReconfigPdpCtxReq*)utlCalloc(1, sizeof(CiPsPrimActivateReconfigPdpCtxReq));
		if (setReconfigActStateReq == NULL)
			return CIRC_FAIL;

		memset(setReconfigActStateReq,  0, sizeof(*setReconfigActStateReq));

		setReconfigActStateReq->pdpCtx.cid = cid;
		if (setPdpCtx->apnInfo.defined)
		{
			setReconfigActStateReq->pdpCtx.type = setPdpCtx->apnInfo.ipType;
			if (strlen(setPdpCtx->apnInfo.apn) > 0)
			{
				if (telMatchDefaultApn(cid) && isLTENetwork(reqHandle))
				{
#ifdef QUECTEL_FIX_INCORRECT_PDP_INIT_TYPE
					if(!IsMiniSystem()){
						#ifndef MIN_SYS
						//
						#endif
					}
					else
#endif
					{
					if (cid == (getDefaultCidNum() - 1) && getCeregReady(reqHandle))
						{
							ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
							utlFree(setReconfigActStateReq);
							return CIRC_SUCCESS;
						}
					}
					/*should change apn to attach apn*/
					if (strlen(defaultPdpApn->epsApn) && cid == (getDefaultCidNum() - 1))
					{
						strncpy(setReconfigActStateReq->pdpCtx.apn.valStr, defaultPdpApn->epsApn, TEL_AT_CGDCONT_2_APN_STR_MAX_LEN - 1);
						setReconfigActStateReq->pdpCtx.apn.len = strlen(defaultPdpApn->epsApn);
						setReconfigActStateReq->pdpCtx.apnPresent = TRUE;
					}
					else
					{
						strncpy(setReconfigActStateReq->pdpCtx.apn.valStr, setPdpCtx->apnInfo.apn, TEL_AT_CGDCONT_2_APN_STR_MAX_LEN - 1);
						setReconfigActStateReq->pdpCtx.apn.len = strlen(setPdpCtx->apnInfo.apn);
						setReconfigActStateReq->pdpCtx.apnPresent = TRUE;
					}
				}
				else
				{
					strncpy(setReconfigActStateReq->pdpCtx.apn.valStr, setPdpCtx->apnInfo.apn, TEL_AT_CGDCONT_2_APN_STR_MAX_LEN - 1);
					setReconfigActStateReq->pdpCtx.apn.len = strlen(setPdpCtx->apnInfo.apn);
					setReconfigActStateReq->pdpCtx.apnPresent = TRUE;
				}
			}
		}

		if (setPdpCtx->authInfo.defined)
		{
			setReconfigActStateReq->authInfoPresent = TRUE;
			setReconfigActStateReq->authenticationType = setPdpCtx->authInfo.authType;

			if (setPdpCtx->authInfo.authType != 0)
			{
				strncpy(setReconfigActStateReq->userName.valStr, setPdpCtx->authInfo.userName, TEL_AT_AUTH_2_USERNAME_STR_MAX_LEN - 1);
				setReconfigActStateReq->userName.len = strlen(setPdpCtx->authInfo.userName);

				strncpy(setReconfigActStateReq->password.valStr, setPdpCtx->authInfo.password, TEL_AT_AUTH_3_PASSWORD_STR_MAX_LEN - 1);
				setReconfigActStateReq->password.len = strlen(setPdpCtx->authInfo.password);
			}
		}

        copyOpt2CiPdpCtx(&(setReconfigActStateReq->pdpCtx), &(setPdpCtx->opt));

		/* if no gCIDList info for current cid, should set current cid info */
		index = getPdpIndexByCid(cid,p_cInfo);
		if (index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
		{
			
			index = getFreePdpIndexFromTable(p_cInfo);
		    if (index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
		    {
		        utlFree(setReconfigActStateReq);
		        ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, 0);
		        return ret;
		    }
			gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = cid;
			p_cInfo[index].pdpType = setReconfigActStateReq->pdpCtx.type;
			p_cInfo[index].cid = cid;
			ATDBGMSG("%s: no gCIDList info for current cid:%d, set it up here", __func__, cid);
		}

		/*
		 **  Send the actual activate CI Request.
		 */
		ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_ACTIVATE_RECONF_PDP_CTX_REQ,
				reqHandle, (void *)setReconfigActStateReq );
		#ifdef QUEC_PPP_ENABLE
			CPUartLogPrintf("%s,%d,ret=%d,reqhandle=%d",__func__,__LINE__,ret,reqHandle);
		/*	if(CIRC_SUCCESS == ret)
			{
				g_cgdata_handle_record = reqHandle;	
			}*/
		#endif
		#endif

	}

	return ret;
}
#endif

//AT$SYSINFO?
CiReturnCode PS_GetSysGPRSRegStatus (UINT32 atHandle)
{
	CiReturnCode                        ret = CIRC_FAIL;
	CiPsPrimGetNwRegStatusReq    *getPsRegStatusReq = NULL;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_NW_REG_STATUS_REQ,
					MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_SYSINFO_NW_REG_STATUS_REQ), (void *)getPsRegStatusReq );
	return ret;
}
#endif
//AT+CGREG?
CiReturnCode PS_GetGPRSRegStatus (UINT32 atHandle)
{
	CiReturnCode                        ret = CIRC_FAIL;
	CiPsPrimGetNwRegStatusReq    *getPsRegStatusReq = NULL;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_NW_REG_STATUS_REQ,
					MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_NW_REG_STATUS_REQ), (void *)getPsRegStatusReq );
	return ret;
}

//AT+CTFT?
CiReturnCode PS_GetTftList (UINT32 atHandle)
{
	CiReturnCode			ret = CIRC_FAIL;
	CiPsPrimGetPdpCtxReq    *getPdpCtxReq=NULL;
	UINT32 reqHandle=0;

	getPdpCtxReq = utlCalloc(1,sizeof(*getPdpCtxReq));
	if (getPdpCtxReq == NULL)
		return CIRC_FAIL;
	getPdpCtxReq->cid = ATCI_FIRST_CID;
	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = ATCI_FIRST_CID;
	reqHandle = MAKE_CI_REQ_HANDLE(atHandle,PRI_PS_PRIM_GET_TFT_REQ);

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ,
				reqHandle, (void *)getPdpCtxReq );

	return ret;
}

//AT+CGTFT=?
CiReturnCode PS_GetTFTCapsREQ (UINT32 atHandle)
{
	CiReturnCode			ret = CIRC_FAIL;
	CiPsPrimGetPdpCtxReq    *getPdpCtxReq=NULL;
	UINT32 reqHandle=0;

	getPdpCtxReq = utlCalloc(1,sizeof(*getPdpCtxReq));
	if (getPdpCtxReq == NULL)
		return CIRC_FAIL;
	getPdpCtxReq->cid = ATCI_FIRST_CID;
	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = ATCI_FIRST_CID;
	reqHandle = MAKE_CI_REQ_HANDLE(atHandle,PRI_PS_PRIM_GET_TFT_REQ);

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_CAPS_REQ,
				reqHandle, (void *)getPdpCtxReq );

	return ret;


}
//AT+CTFT = cid, only cid is included
CiReturnCode PS_DeleteTft (UINT32 atHandle, UINT32 dwContextID)
{
	CiReturnCode			ret = CIRC_FAIL;
	CiPsPrimDeleteTftReq			*deleteTftReq=NULL;
	UINT32 reqHandle=0;

	deleteTftReq = utlCalloc(1,sizeof(*deleteTftReq));
	if (deleteTftReq == NULL)
		return CIRC_FAIL;

	deleteTftReq->cid = (UINT8)dwContextID;
	reqHandle = MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_DELETE_TFT_REQ);
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_DELETE_TFT_REQ,
				reqHandle, (void *)deleteTftReq );

	return ret;
}

//AT+CTFT = cid, pfi, , ,
CiReturnCode PS_SetTftFilter (UINT32 atHandle, UINT32 dwContextID, const CiPsTftFilter *tftFilter)
{
	CiReturnCode			ret = CIRC_FAIL;
	CiPsPrimDefineTftFilterReq	*defineTftFilterReq=NULL;
	UINT32 reqHandle=0;

	defineTftFilterReq = utlCalloc(1,sizeof(*defineTftFilterReq));
	if (defineTftFilterReq == NULL)
		return CIRC_FAIL;

	defineTftFilterReq->cid = (UINT8)dwContextID;
	memcpy(&defineTftFilterReq->filter, tftFilter, sizeof(CiPsTftFilter));
	reqHandle = MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_DEFINE_TFT_FILTER_REQ);
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_DEFINE_TFT_FILTER_REQ,
				reqHandle, (void *)defineTftFilterReq );

	return ret;
}

//AT+CGCMOD=?
CiReturnCode PS_GetGPRSActiveCidList (UINT32 atHandle)
{
	CiReturnCode			ret = CIRC_FAIL;
	CiPsPrimGetPdpCtxsActStateReq	*pdpCtxsActStateReq = NULL;
	UINT32 reqHandle=0;

	reqHandle = MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_PDP_CTXS_ACT_STATE_REQ);

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTXS_ACT_STATE_REQ,
					reqHandle, (void *)pdpCtxsActStateReq);

	return ret;
}

//AT+CGCMOD=cid,
CiReturnCode PS_ModifyGPRSContext(UINT32 atHandle, UINT32 dwContextID, BOOL doAll)
{
	CiReturnCode			ret = CIRC_FAIL;
	CiPsPrimModifyPdpCtxReq			*modifyPdpCtxReq=NULL;
	UINT32 reqHandle=0;

	modifyPdpCtxReq = utlCalloc(1, sizeof(*modifyPdpCtxReq));
	if (modifyPdpCtxReq == NULL)
		return CIRC_FAIL;
	modifyPdpCtxReq->cid = (UINT32)dwContextID;
	modifyPdpCtxReq->doAll = doAll;
	reqHandle = MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_MODIFY_PDP_CTX_REQ);

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_MODIFY_PDP_CTX_REQ,
					reqHandle, (void *)modifyPdpCtxReq);

	return ret;

}

//AT+CGDCONT?
CiReturnCode PS_GetGPRSContextList (UINT32 atHandle)
{
	CiReturnCode			ret = CIRC_FAIL;
	CiPsPrimGetPdpCtxReq    *getPdpCtxReq=NULL;
	UINT32 reqHandle=0;

	getPdpCtxReq = utlCalloc(1,sizeof(*getPdpCtxReq));
	if (getPdpCtxReq == NULL)
		return CIRC_FAIL;
	getPdpCtxReq->cid = ATCI_FIRST_CID;
	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = ATCI_FIRST_CID;
	reqHandle = MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_PDP_CTX_REQ);

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ,
				reqHandle, (void *)getPdpCtxReq );

	return ret;
}

#ifdef QUECTEL_NETWORK_SUPPORT
typedef struct
{
	CiPsPdpCtx pdpCtxInfo_backup;
	UINT8   update_flag;
#if QUEC_DUAL_SIM_SUPPORT
    BOOL   sim0_default_apn_set;
    BOOL   sim1_default_apn_set;
#endif
} quec_pdpCtxInfo_type;

quec_pdpCtxInfo_type   quec_pdpCtxInfo={0};

bool quec_pdpindex_isfull(UINT32 atHandle,uint8 cid)
{
	char *pAtCmdStr = NULL; 
	char PdpProfileName[20]={0};
	UINT8 actual_id =0;
	uint8 i=1;
	do
	{
		sprintf(PdpProfileName, "Profile%d", i);
		pAtCmdStr = psm_get_wrapper(PSM_MOD_WAN, "cellular", PdpProfileName);
		if(pAtCmdStr !=NULL && strlen(pAtCmdStr) != 0)
		{
			actual_id++;
			CPUartLogPrintf("%s,%d,cid=%d,i=%d,len=%d,%s",__FUNCTION__,__LINE__,cid,i,strlen(pAtCmdStr),pAtCmdStr);
			if(cid == i)
			{
				CPUartLogPrintf("%s,%d,update,return",__FUNCTION__,__LINE__);
				free(pAtCmdStr);
				pAtCmdStr = NULL;
				return FALSE;	
			}
			free(pAtCmdStr);
			pAtCmdStr = NULL;
		}
        else
        {
           if(pAtCmdStr !=NULL )
           {
                free(pAtCmdStr);
    			pAtCmdStr = NULL;    
           }
        }
             
		i++;		
	}while(i<QUEC_PDP_CONTEX_INDEX_MAX);

	
	CPUartLogPrintf("%s,%d,actual_id=%d,INDEX_MAX =%d,CI_PS_MAX_PDP_CTX_NUM=%d",__FUNCTION__,__LINE__,actual_id,QUEC_PDP_CONTEX_INDEX_MAX,CI_PS_MAX_PDP_CTX_NUM);
	if(actual_id < CI_PS_MAX_PDP_CTX_NUM)
	{
		/*
		if(pAtCmdStr != NULL){
			free(pAtCmdStr);
			pAtCmdStr = NULL;
		}
		*/
		return FALSE;
	}
	/*
	if(pAtCmdStr != NULL){
		free(pAtCmdStr);
		pAtCmdStr = NULL;
	}
	*/
	return TRUE;
}

#ifndef MIN_SYS
#if QUEC_DUAL_SIM_SUPPORT
extern UINT8 qcfg_ltedftcid_1;
BOOL quec_get_default_flag(uint8 simid)
{
      if(simid==0)
        return quec_pdpCtxInfo.sim0_default_apn_set;
      else
        return quec_pdpCtxInfo.sim1_default_apn_set;
}
void quec_set_default_pdp(void)
{
    char *pAtCmdStr = NULL, PdpProfileName[20]={0};
     char resp_str[64] = {'\0'};
     quec_pdpCtxInfo.sim1_default_apn_set=TRUE;
    if(quec_get_dualSimType()!=CM_DUAL_SIM_SINGLE_STANDBY)//双卡单待向双卡双待切 配置SIM2 cid5为默认承载
       snprintf(PdpProfileName,sizeof(PdpProfileName),"Profile%d", qcfg_ltedftcid_1);
    else if(quec_get_dualSimType()==CM_DUAL_SIM_SINGLE_STANDBY)//双卡双待向双卡单待切 配置SIM2 cid1为默认承载
        {
            snprintf(PdpProfileName,sizeof(PdpProfileName),"Profile%d", qcfg_ltedftcid);
        }
    else
        {
           CPUartLogPrintf("%s,%d,Set Default PDP error",__FUNCTION__,__LINE__);
           quec_pdpCtxInfo.sim1_default_apn_set=FALSE;
           return;
        }
        pAtCmdStr = psm_get_wrapper("wan", "cellular", PdpProfileName);
    if(pAtCmdStr)
     {
       SendATCMDWaitResp(EVENT_HANDLER_ATP_INDEX_1, pAtCmdStr, 20, NULL,1, "+CME ERROR", resp_str,sizeof(resp_str));
       CPUartLogPrintf("sim2 read_cfg=%s", pAtCmdStr);
       duster_free(pAtCmdStr);
     }
    else
    {   
        memset(PdpProfileName,0,sizeof(PdpProfileName));
        snprintf(PdpProfileName,sizeof(PdpProfileName), "AT+CGDCONT=%d,\"IPV4V6\",\"\"\r\n", qcfg_ltedftcid_1);
        SendATCMDWaitResp(EVENT_HANDLER_ATP_INDEX_1, PdpProfileName, 20, NULL,1, "+CME ERROR", resp_str,sizeof(resp_str));
    }
}
#endif
#endif
#endif
//AT+CGDCONT=cid, type, apn,
CiReturnCode PS_SetGPRSContext (UINT32 atHandle, const CiPsPdpCtx* lpGprsContext)
{
	CiReturnCode			ret = CIRC_FAIL;
	CiPsPrimDefinePdpCtxReq  *defPdpReq;
	AtciCurrentSetCntx *p_cInfo;
	UINT8 pdp_table_index;

#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
#ifdef QUEC_APPTCPIP_SUPPORT
	quec_pdp_profile  pdp_profile;
#endif
#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
		p_cInfo = gCIDList.cInfo;
	} else {
		p_cInfo = gCIDList.cInfo_1;
	}

#else
	p_cInfo = gCIDList.cInfo;

#endif
	DIAG_FILTER(PCAC, ATCMDSrv, PS_SetGPRSContext_1, DIAG_INFORMATION)
	diagPrintf("cid is %d, atHandle is 0x%x, reqHandle is 0x%x",lpGprsContext->cid, atHandle,p_cInfo[lpGprsContext->cid].reqHandle);
	//If the PDP context is already in active state, we should reject it
	pdp_table_index = getPdpIndexByCid(lpGprsContext->cid,p_cInfo);
	if(pdp_table_index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM )
	{

		if(p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
		{
		    /* allow PDP redefine in PDP actived state*/
#ifndef LWIP_IPNETBUF_SUPPORT
			DIAG_FILTER(PCAC, ATCMDSrv, PS_SetGPRSContext_2, DIAG_INFORMATION)
			diagPrintf("the cid %d context is already active!", lpGprsContext->cid);
			ERRMSG("%s: the cid %d context is already active!\n", __FUNCTION__, lpGprsContext->cid);
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, 0);
			return ret;
#endif
		}
	}
	else if(pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
	{
		pdp_table_index = getFreePdpIndexFromTable(p_cInfo);
		if (pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
		{
#ifdef LWIP_IPNETBUF_SUPPORT
            telPsPdpApn       pdpApnInfo = {0};
            telPsPdpOpt       pdpOpt = {0};

            telSetPdpCtxApnDS(atHandle, lpGprsContext->cid, &pdpApnInfo);
            telSetPdpCtxOptDS(atHandle, lpGprsContext->cid, &pdpOpt);
#endif			
		    ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, 0);
			return ret;
		}
	}

	defPdpReq = utlCalloc(1,sizeof(*defPdpReq));
	if (defPdpReq == NULL)
		return CIRC_FAIL;
	memcpy(&(defPdpReq->pdpCtx), lpGprsContext, sizeof(CiPsPdpCtx));
	Quec_NetInfo_log("PS_SetGPRSContext:%d %d",lpGprsContext->cid,lpGprsContext->type);

	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = lpGprsContext->cid;
	p_cInfo[pdp_table_index].pdpType = lpGprsContext->type;
	p_cInfo[pdp_table_index].cid= lpGprsContext->cid;
#ifdef QUEC_APPTCPIP_SUPPORT
	{
		memset(&pdp_profile, 0, sizeof(quec_pdp_profile));
		quec_net_get_pdp_profile(lpGprsContext->cid+1, &pdp_profile);
		
		if(lpGprsContext->type == CI_PS_PDP_TYPE_IP)
			pdp_profile.pdp_type = QUEC_PDP_IPV4;
		else if(lpGprsContext->type == CI_PS_PDP_TYPE_IPV6)
			pdp_profile.pdp_type = QUEC_PDP_IPV6;
		else 
			pdp_profile.pdp_type = QUEC_PDP_IPV4V6;

		memset(pdp_profile.apn, 0, 128);
		strcpy(pdp_profile.apn, lpGprsContext->apn.valStr);

		quec_net_set_pdp_profile(lpGprsContext->cid+1, &pdp_profile);
	}
#endif
    /**
    * AT+CGDCONT config pdp will call PS_SetGPRSContext() twice
    * in PS_SetGPRSContext() 
    * if quec_pdpCtxInfo.update_flag == 0 will call CI_PS_PRIM_DEFINE_DEFAULT_PDP_CTX_REQ
    * if quec_pdpCtxInfo.update_flag == 1 will call CI_PS_PRIM_DEFINE_PDP_CTX_REQ
    * normal process  CI_PS_PRIM_DEFINE_DEFAULT_PDP_CTX_REQ->CI_PS_PRIM_DEFINE_DEFAULT_PDP_CTX_CNF->
    *                 ->CI_PS_PRIM_DEFINE_PDP_CTX_REQ->CI_PS_PRIM_DEFINE_PDP_CTX_CNF
    * quec_pdpCtxInfo.update_flag value change like  0 -> 1 -> 0
    **/
#ifdef QUECTEL_NETWORK_SUPPORT
	if((lpGprsContext->cid+1 == qcfg_ltedftcid && quec_pdpCtxInfo.update_flag == 0)
   #if QUEC_DUAL_SIM_SUPPORT
        ||
       (((getDualSimType() != CM_DUAL_SIM_SINGLE_STANDBY))&&((lpGprsContext->cid+1 == qcfg_ltedftcid_1 && quec_pdpCtxInfo.update_flag == 0))&&(GET_SIM1_FLAG(atHandle)==TRUE))
       ||((quec_pdpCtxInfo.sim1_default_apn_set==TRUE)&&(getDualSimType() == CM_DUAL_SIM_SINGLE_STANDBY)&&((lpGprsContext->cid+1 == qcfg_ltedftcid_1 && quec_pdpCtxInfo.update_flag == 0)&&(GET_SIM1_FLAG(atHandle)==TRUE)))//用于双卡单待切卡前更新卡2默认承载
       #endif
    /* && gUpdatePdpProfileCmdInPsmFlag !=0*/) /* CI - SAC use cid range starting from 0 */
    {

		Quec_NetInfo_log("sync param to LTE attach default profile");
		memset(&quec_pdpCtxInfo.pdpCtxInfo_backup,0,sizeof(quec_pdpCtxInfo.pdpCtxInfo_backup));
		memcpy(&(quec_pdpCtxInfo.pdpCtxInfo_backup), lpGprsContext, sizeof(CiPsPdpCtx));
		quec_pdpCtxInfo.update_flag=1;
		
		//variable need initialization avoids unexceptions result
		CiPsPrimDefineDefaultPdpCtxReq defaultPdpCtxInfo={0};

		//mode
		//defaultPdpCtxInfo.modeType = 1;
	
		//destin check PsmFlag to adjust save NVM mode 
		//双卡单待向双卡双待切换时需要将cid5更新默认承载并且需要保存到gki，虽然下发cgdcont判同，默认承载需要更新。
		if((quec_UpdateDfltPdpProfileCmdbyPsmFlag == FALSE)
            #if QUEC_DUAL_SIM_SUPPORT
            &&((quec_pdpCtxInfo.sim1_default_apn_set==FALSE))
            #endif
            ){
			Quec_NetInfo_log("[PPP] chap set cgcont info is the same as psm not save *cgdflt to nv");
			defaultPdpCtxInfo.modeType = 0; //is the same as the last not save nv
		}else{
			#if QUEC_DUAL_SIM_SUPPORT
            quec_pdpCtxInfo.sim1_default_apn_set=FALSE;
			#endif
			defaultPdpCtxInfo.modeType = 1; 
		}

		//pdp type	
		defaultPdpCtxInfo.pdpType=lpGprsContext->type;
		defaultPdpCtxInfo.pdpTypePresent=TRUE;

		//apn
		if (lpGprsContext->apnPresent)
		{
			defaultPdpCtxInfo.apn.len = lpGprsContext->apn.len;
			memcpy( defaultPdpCtxInfo.apn.valStr, lpGprsContext->apn.valStr, lpGprsContext->apn.len );
		}

		//emgInd
		/*if(lpGprsContext->emergencyIndPresent)
		{
			defaultPdpCtxInfo.emgInd=lpGprsContext->type;
			defaultPdpCtxInfo.emgIndPresent=TRUE;
		}
		else
		{
			defaultPdpCtxInfo.emgInd=TEL_AT_CGDFLT_3_EMGIND_VAL_DEFAULT;
			defaultPdpCtxInfo.emgIndPresent=FALSE;
		}*/

		//ipcpreq
		defaultPdpCtxInfo.ipcpReq=TEL_AT_CGDFLT_4_IPCPREQ_VAL_DEFAULT;
		defaultPdpCtxInfo.ipcpReqPresent=FALSE;

		//pcscfIpv6Req
		defaultPdpCtxInfo.pcscfIpv6Req=TEL_AT_CGDFLT_5_PCSCFIPV6REQ_VAL_DEFAULT;
		defaultPdpCtxInfo.pcscfIpv6ReqPresent=FALSE;
		
		//imcnSig
		if(lpGprsContext->imCnSignallingFlagIndPresent)
		{
			defaultPdpCtxInfo.imcnSig=lpGprsContext->imCnSignallingFlagInd;
			defaultPdpCtxInfo.imcnSigPresent=TRUE;
		}
		else
		{
			defaultPdpCtxInfo.imcnSig=TEL_AT_CGDFLT_6_IMCNSIG_VAL_DEFAULT;
			defaultPdpCtxInfo.imcnSigPresent=FALSE;
		}
		
		//dnsIpv6
		defaultPdpCtxInfo.dnsIpv6=TEL_AT_CGDFLT_7_DNSIPV6_VAL_DEFAULT;
		defaultPdpCtxInfo.dnsIpv6Present=FALSE;

		//nwBear
		defaultPdpCtxInfo.nwBear=TEL_AT_CGDFLT_8_NWBEAR_VAL_DEFAULT;
		defaultPdpCtxInfo.nwBearPresent=FALSE;

		//dsmIpv6Ha
		defaultPdpCtxInfo.dsmIpv6Ha=TEL_AT_CGDFLT_9_DSMIPV6HA_VAL_DEFAULT;
		defaultPdpCtxInfo.dsmIpv6HaPresent=FALSE;

		//dsmIpv6Ha
		defaultPdpCtxInfo.dsmIpv6Pref=TEL_AT_CGDFLT_10_DSMIPV6PREF_VAL_DEFAULT;
		defaultPdpCtxInfo.dsmIpv6PrefPresent=FALSE;

		//dsmIpv4Ha
		defaultPdpCtxInfo.dsmIpv6HaIpv4=TEL_AT_CGDFLT_11_DSMIPV6HAIPV4_VAL_DEFAULT;
		defaultPdpCtxInfo.dsmIpv6HaIpv4Present=FALSE;

		//ipViaNas && ipViaDhcp
		if(lpGprsContext->ipAddrAllocPresent && lpGprsContext->ipAddrAlloc == 1) //IPv4 address allocated through DHCP
		{
			defaultPdpCtxInfo.ipViaNas=TEL_AT_CGDFLT_12_IPVIANAS_VAL_DEFAULT;
			defaultPdpCtxInfo.ipViaNasPresent=FALSE;
			defaultPdpCtxInfo.ipViaDhcp=1;
			defaultPdpCtxInfo.ipViaDhcpPresent=TRUE;
		}
		else
		{
			defaultPdpCtxInfo.ipViaNas=1;
			defaultPdpCtxInfo.ipViaNasPresent=TRUE;
			defaultPdpCtxInfo.ipViaDhcp=TEL_AT_CGDFLT_13_IPVIADHCP_VAL_DEFAULT;
			defaultPdpCtxInfo.ipViaDhcpPresent=FALSE;
		}

		//pcscfIpv4
		defaultPdpCtxInfo.pcscfIpv4=TEL_AT_CGDFLT_14_PCSCFIPV4_VAL_DEFAULT;
		defaultPdpCtxInfo.pcscfIpv4Present=FALSE;

		//dnsIpv4
		defaultPdpCtxInfo.dnsIpv4=TEL_AT_CGDFLT_15_DNSIPV4_VAL_DEFAULT;
		defaultPdpCtxInfo.dnsIpv4Present=FALSE;

		//msisdn
		defaultPdpCtxInfo.msisdn=TEL_AT_CGDFLT_16_MSISDN_VAL_DEFAULT;
		defaultPdpCtxInfo.msisdnPresent=FALSE;
		
		//ifom
		defaultPdpCtxInfo.ifom=TEL_AT_CGDFLT_17_IFOM_VAL_DEFAULT;
		defaultPdpCtxInfo.ifomPresent=FALSE;
		
		//v4mtu we need IPv4 Link MTU  
		defaultPdpCtxInfo.v4mtu=1;
		defaultPdpCtxInfo.v4mtuPresent=TRUE;

		//localTft
		defaultPdpCtxInfo.localTft=TEL_AT_CGDFLT_19_LOCALTFT_VAL_DEFAULT;
		defaultPdpCtxInfo.localTftPresent=FALSE;

		//etifFlag we need open this flag as default acording to asr
		defaultPdpCtxInfo.etifFlag=1;
		defaultPdpCtxInfo.etifPresent=TRUE;

		ret=PS_SetDefaultPDPContextByReqHandler(MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_DEFINE_PDP_CTX_REQ),&defaultPdpCtxInfo);
		Quec_NetInfo_log("free defPdpReq=%p",defPdpReq);
		utlFree(defPdpReq); //Chaim 20190920 avoid memory leak	come here.
	}
	else
	{
    //evin 20211104 fix set default PDP,the programm order is mass,when default PDP CI req has been sent ,.
	//other cid PDP set then. FAE-24935
        if(((lpGprsContext->cid+1) == qcfg_ltedftcid)
            #if QUEC_DUAL_SIM_SUPPORT
            ||((getDualSimType() != CM_DUAL_SIM_SINGLE_STANDBY)&&((lpGprsContext->cid+1 == qcfg_ltedftcid_1)&&(GET_SIM1_FLAG(atHandle)==TRUE)))
            ||((quec_pdpCtxInfo.update_flag==1)&&(GET_SIM1_FLAG(atHandle)==TRUE)&&(getDualSimType() == CM_DUAL_SIM_SINGLE_STANDBY)&&(lpGprsContext->cid+1 == qcfg_ltedftcid_1))//用于双卡单待切卡前更新卡2默认承载
            #endif
          )
       {
		quec_pdpCtxInfo.update_flag=0;
       }
#endif
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_DEFINE_PDP_CTX_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_DEFINE_PDP_CTX_REQ), (void *)defPdpReq );
#ifdef QUECTEL_NETWORK_SUPPORT
	}
#endif
}//MiniSystem
else
{
#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
		p_cInfo = gCIDList.cInfo;
	} else {
		p_cInfo = gCIDList.cInfo_1;
	}
#else
	p_cInfo = gCIDList.cInfo;
#endif
	DIAG_FILTER(PCAC, ATCMDSrv, PS_SetGPRSContext_1, DIAG_INFORMATION)
	diagPrintf("cid is %d, atHandle is 0x%x, reqHandle is 0x%x",lpGprsContext->cid, atHandle,p_cInfo[lpGprsContext->cid].reqHandle);
	//If the PDP context is already in active state, we should reject it
	pdp_table_index = getPdpIndexByCid(lpGprsContext->cid,p_cInfo);
	if(pdp_table_index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM )
	{

		if(p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
		{
		    /* allow PDP redefine in PDP actived state*/
#ifndef LWIP_IPNETBUF_SUPPORT
			DIAG_FILTER(PCAC, ATCMDSrv, PS_SetGPRSContext_2, DIAG_INFORMATION)
			diagPrintf("the cid %d context is already active!", lpGprsContext->cid);
			ERRMSG("%s: the cid %d context is already active!\n", __FUNCTION__, lpGprsContext->cid);
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, 0);
			return ret;
#endif
		}
	}
	else if(pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
	{
		pdp_table_index = getFreePdpIndexFromTable(p_cInfo);
		if (pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
		{
#ifdef LWIP_IPNETBUF_SUPPORT
            telPsPdpApn       pdpApnInfo = {0};
            telPsPdpOpt       pdpOpt = {0};

            telSetPdpCtxApnDS(atHandle, lpGprsContext->cid, &pdpApnInfo);
            telSetPdpCtxOptDS(atHandle, lpGprsContext->cid, &pdpOpt);
#endif			
		    ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, 0);
			return ret;
		}
	}

	defPdpReq = utlCalloc(1,sizeof(*defPdpReq));
	if (defPdpReq == NULL)
		return CIRC_FAIL;
	memcpy(&(defPdpReq->pdpCtx), lpGprsContext, sizeof(CiPsPdpCtx));

	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = lpGprsContext->cid;
	p_cInfo[pdp_table_index].pdpType = lpGprsContext->type;
	p_cInfo[pdp_table_index].cid= lpGprsContext->cid;
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_DEFINE_PDP_CTX_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_DEFINE_PDP_CTX_REQ), (void *)defPdpReq );
}
#endif /*MIN_SYS*/
	return ret;
}

//AT+CGDCONT=cid only cid is included
CiReturnCode PS_DeleteGPRSContext (UINT32 atHandle, UINT32 dwContextID)
{
	CiReturnCode				   ret = CIRC_FAIL;
	CiPsPrimDeletePdpCtxReq  *deletePdpCtxReq=NULL;

	/* Delete PDP context */
	deletePdpCtxReq = utlCalloc(1, sizeof(*deletePdpCtxReq));
	if (deletePdpCtxReq == NULL)
		return CIRC_FAIL;
	deletePdpCtxReq->cid = dwContextID;
	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = dwContextID;
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_DELETE_PDP_CTX_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_DELETE_PDP_CTX_REQ), (void *)deletePdpCtxReq );

	return ret;
}

//AT+CGQREQ?
CiReturnCode PS_GetQualityOfServiceList (UINT32 atHandle, BOOL isMin)
{
	CiReturnCode				   ret = CIRC_FAIL;
	CiPsPrimGetQosReq	   *getQosReq=NULL;
	UINT32 reqHandle=0;

	getQosReq = utlCalloc(1, sizeof(*getQosReq));
	if (getQosReq == NULL)
		return CIRC_FAIL;

	getQosReq->cid = ATCI_FIRST_CID;
	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = ATCI_FIRST_CID;
	getQosReq->isMin = isMin;

	if (isMin)
		reqHandle = MAKE_CI_REQ_HANDLE(atHandle,PRI_PS_PRIM_GET_MIN_QOS_REQ);
	else
		reqHandle = MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_QOS_REQ);

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_QOS_REQ,
			reqHandle, (void *)getQosReq );

	return ret;
}

//AT+CGQREQ=
CiReturnCode PS_SetQualityOfService (UINT32 atHandle, UINT32 dwContextID, const CiPsQosProfile* lpGprsQosProfile, BOOL isMin)
{
	CiReturnCode				   ret = CIRC_FAIL;
	CiPsPrimSetQosReq       *setQosReq = utlCalloc(1, sizeof(*setQosReq));

	if (setQosReq == NULL)
		return CIRC_FAIL;
	setQosReq->isMin = isMin;
	setQosReq->cid = dwContextID;
	memcpy(&setQosReq->qosProf, lpGprsQosProfile, sizeof(CiPsQosProfile));

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_QOS_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_QOS_REQ), (void *)setQosReq );

	return ret;
}

//AT+CGATT=
CiReturnCode PS_SetGPRSAttached (UINT32 atHandle, BOOL fAttached, CiPsAttachStateCause cause)
{
	CiReturnCode                        ret = CIRC_FAIL;
	CiPsPrimSetAttachStateReq    *setAttStateReq=NULL;
	UINT32 reqHandle = MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_ATTACH_STATE_REQ);

	setAttStateReq = utlCalloc(1, sizeof(*setAttStateReq));
	if (setAttStateReq == NULL)
		return CIRC_FAIL;
	setAttStateReq->state = fAttached;
	setAttStateReq->cause = cause;
	if (!fAttached)
		reqHandle = MAKE_CI_REQ_HANDLE(atHandle,PRI_PS_PRIM_SET_DETACH_STATE_REQ);
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_ATTACH_STATE_REQ,
			reqHandle, (void *)setAttStateReq );
	return ret;
}

//AT+CGATT?
CiReturnCode PS_GetGPRSAttached (UINT32 atHandle)
{
	CiReturnCode                        ret = CIRC_FAIL;
	CiPsPrimGetAttachStateReq    *getAttStateReq = NULL;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_ATTACH_STATE_REQ,
					MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_ATTACH_STATE_REQ), (void *)getAttStateReq );
	return ret;
}

//AT+CGACT?
CiReturnCode PS_GetGPRSContextActivatedList (UINT32 atHandle)
{
	CiReturnCode			ret = CIRC_FAIL;
	CiPsPrimGetPdpCtxReq	*getPdpCtxReq=NULL;
	UINT32 reqHandle=0;

	getPdpCtxReq = utlCalloc(1,sizeof(*getPdpCtxReq));
	if (getPdpCtxReq == NULL)
		return CIRC_FAIL;
	getPdpCtxReq->cid = ATCI_FIRST_CID;
	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = ATCI_FIRST_CID;
	reqHandle = MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_ACTIVE_CID_LIST_REQ);

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ,
				reqHandle, (void *)getPdpCtxReq );

	return ret;

}

//AT+CGACT=
CiReturnCode PS_SetGPRSContextActivated (UINT32 atHandle, UINT32 dwContextID, BOOL fContextActivation, BOOL doAll)
{
	CiReturnCode ret = CIRC_FAIL;
	UINT32 reqHandle=0;

	CiPsL2P l2p = CI_PS_L2P_NONE;

	CiPsPrimSetPdpCtxActStateReq   *setActStateReq=NULL;
	AtciCurrentSetCntx *p_cInfo;
	UINT8 index;
	#ifdef LWIP_IPNETBUF_SUPPORT
	telPsPdpCtx *setPdpCtx = telGetPdpCtx(dwContextID);
#ifdef QUECTEL_PROJECT_CUST	//Bug #109660 STASR1602-404
	telPsPdpAuth pdpAuth;
#endif
	#endif

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
		p_cInfo = gCIDList.cInfo;
	} else {
		p_cInfo = gCIDList.cInfo_1;
	}
#else
	p_cInfo = gCIDList.cInfo;
#endif

	/* Determine the l2p type */
	if ( fContextActivation == TRUE )
	{
		index = getPdpIndexByCid(dwContextID,p_cInfo);

		if ( (index <  CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM) && (p_cInfo[index].bDefined == TRUE))
		{
			switch ( p_cInfo[index].pdpType )
			{
				case CI_PS_PDP_TYPE_IP:
					l2p = CI_PS_L2P_NONE;
					break;
				default:
					l2p = CI_PS_L2P_NONE;
					break;
			}
#ifdef QUEC_PDP_TYPE_PPP_FIX
            if (CI_PS_PDP_TYPE_PPP == p_cInfo[index].pdpType)
            {
                /*PPP类型激活报错，和高通保持一致*/
                ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, 0);
                return ret;
            }
#endif
		}
#ifdef LWIP_IPNETBUF_SUPPORT
		else if (setPdpCtx && setPdpCtx->reDefined == TRUE)
		{
			DBGMSG("%s: the dwContextID:%d redefined\n", __FUNCTION__, dwContextID);
		}
#endif
		else
		{
			/* If the context is not defined - we cannot activate it */
			ERRMSG("%s: the dwContextID:%d is not defined. Please define it first!\n", __FUNCTION__, dwContextID);
			return ret;
		}
		reqHandle = MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ);

	}
	else
		reqHandle = MAKE_CI_REQ_HANDLE(atHandle, PRI_PS_PRIM_SET_PDP_CTX_DEACT_STATE_REQ);

	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = dwContextID;
#if defined (LWIP_IPNETBUF_SUPPORT)
	//gAtpCtrl[GET_ATP_INDEX(atHandle)].psCurrCid = dwContextID;

	if (setPdpCtx && setPdpCtx->reDefined && fContextActivation && isHandleForMasterSim(reqHandle))
	{
		#if !defined(ATCMD_UNIFY_ACT_CI)
		ret = setRedefinePdpActiveReq(reqHandle, dwContextID, fContextActivation);
		#else
		if(index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
		{
			index = getFreePdpIndexFromTable(p_cInfo);
			if (index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
			{
	            telPsPdpApn       pdpApnInfo = {0};
	            telPsPdpOpt       pdpOpt = {0};

	            telSetPdpCtxApnDS(atHandle, dwContextID, &pdpApnInfo);
	            telSetPdpCtxOptDS(atHandle, dwContextID, &pdpOpt);
			    ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, 0);
				return ret;
			}
		}

		CiPsPrimDefinePdpCtxReq *defPdpReq = utlCalloc(1,sizeof(*defPdpReq));
		if (defPdpReq == NULL)
			return CIRC_FAIL;

		defPdpReq->pdpCtx.cid = dwContextID;
		if (setPdpCtx->apnInfo.defined)
		{
			defPdpReq->pdpCtx.type = setPdpCtx->apnInfo.ipType;
			if (strlen(setPdpCtx->apnInfo.apn) > 0)
			{
				strncpy(defPdpReq->pdpCtx.apn.valStr, setPdpCtx->apnInfo.apn, TEL_AT_CGDCONT_2_APN_STR_MAX_LEN - 1);
				defPdpReq->pdpCtx.apn.len = strlen(setPdpCtx->apnInfo.apn);
				defPdpReq->pdpCtx.apnPresent = TRUE;
			}
		}
		copyOpt2CiPdpCtx(&(defPdpReq->pdpCtx), &(setPdpCtx->opt));

		p_cInfo[index].pdpType = defPdpReq->pdpCtx.type;
		p_cInfo[index].cid= defPdpReq->pdpCtx.cid;
#ifdef QUECTEL_PROJECT_CUST	//Bug #109660 STASR1602-404
		memset(&pdpAuth, 0, sizeof(pdpAuth));
		if (telGetPdpCtxAuthDS(atHandle, dwContextID, &pdpAuth))
		{
			if (pdpAuth.defined && pdpAuth.authType > 0)
			{
				CiPsPrimAuthenticateReq *pdpAuthReq = NULL;
				pdpAuthReq = (CiPsPrimAuthenticateReq*)utlCalloc(1, sizeof(CiPsPrimAuthenticateReq));
				if (pdpAuthReq == NULL)
					return CIRC_FAIL;
				
				pdpAuthReq->AuthenticationType = pdpAuth.authType;
				pdpAuthReq->cid = dwContextID;
				strncpy(pdpAuthReq->UserName.valStr, pdpAuth.userName, sizeof(pdpAuthReq->UserName.valStr) - 1);
				pdpAuthReq->UserName.len = strlen(pdpAuthReq->UserName.valStr);
				strncpy(pdpAuthReq->Password.valStr, pdpAuth.password, sizeof(pdpAuthReq->Password.valStr) - 1);
				pdpAuthReq->Password.len = strlen(pdpAuthReq->Password.valStr);

				gCIDList.currCntx[GET_ATP_INDEX(atHandle)].reqMsg = pdpAuthReq;

				ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_DEFINE_PDP_CTX_REQ,
					MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_AUTHENTICATE_REQ), (void *)defPdpReq);

				return ret;
			}
		}

#endif

		setActStateReq = (CiPsPrimSetPdpCtxActStateReq*)utlCalloc(1, sizeof(CiPsPrimSetPdpCtxActStateReq));
		if (setActStateReq == NULL)
			return CIRC_FAIL;

		setActStateReq->state = fContextActivation;
		setActStateReq->cid = dwContextID;
		setActStateReq->doAll = doAll;
		setActStateReq->l2p = l2p;

		gCIDList.currCntx[GET_ATP_INDEX(atHandle)].reqMsg = setActStateReq;
		
		ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_DEFINE_PDP_CTX_REQ,
				MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ), (void *)defPdpReq );
		#endif
		
	}
	else
#endif
	{
	setActStateReq = (CiPsPrimSetPdpCtxActStateReq*)utlCalloc(1, sizeof(CiPsPrimSetPdpCtxActStateReq));
	if (setActStateReq == NULL)
		return CIRC_FAIL;

	setActStateReq->state = fContextActivation;
	setActStateReq->cid = dwContextID;
	setActStateReq->doAll = doAll;
	setActStateReq->l2p = l2p;

	/*
	**  Send the actual activate CI Request.
	*/
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ,
			 reqHandle, (void *)setActStateReq );
	}

	return ret;

}
//AT*AUTHReq
CiReturnCode PS_SendAUTHReq(UINT32 atHandle, const CiPsPrimAuthenticateReq * lpAuthReq )
{
	CiReturnCode ret = CIRC_FAIL;
	UINT32 reqHandle = MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_AUTHENTICATE_REQ);
	UINT8 atpIndex = GET_ATP_INDEX(atHandle);
	CiPsPrimAuthenticateReq *pdpAuthReq = NULL;
	AtciCurrentSetCntx *p_cInfo;
	UINT8 index;

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
		p_cInfo = gCIDList.cInfo;
	} else {
		p_cInfo = gCIDList.cInfo_1;
	}
#else
	p_cInfo = gCIDList.cInfo;
#endif

	index = getPdpIndexByCid(lpAuthReq->cid,p_cInfo);
	gCIDList.currCntx[atpIndex].currCid = lpAuthReq->cid;

	if ( (index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM) &&(p_cInfo[index].bDefined == TRUE) )
	{
		if (p_cInfo[index].reqHandle != INVALID_REQ_HANDLE)
		{
			#if defined QUECTEL_PROJECT_CUST
			#else
			CPUartLogPrintf("%s: the dwContextID:%d has been actived. So reject to reactivate it!\n", __FUNCTION__, lpAuthReq->cid);
			return ret;
			#endif
		}
		pdpAuthReq = utlCalloc(1, sizeof(*pdpAuthReq));
		if (pdpAuthReq == NULL)
			return CIRC_FAIL;

		memcpy((void *)pdpAuthReq, (void *)lpAuthReq, sizeof(*pdpAuthReq));

		//ATDBGMSG("ciSendAUTHReq:cid=%d,Autytype=%d,Username-%s, PassWord-%s\n",
		//       pdpAuthReq->cid, pdpAuthReq->AuthenticationType, pdpAuthReq->UserName.valStr, pdpAuthReq->Password.valStr);

		ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_AUTHENTICATE_REQ,
				 reqHandle, (void *)pdpAuthReq);
	}
	else
	{
		//ATDBGMSG("%s: the dwContextID:%d is not defined. Please define it first!\n", __FUNCTION__, lpAuthReq->cid);
		return ret;
	}
	return ret;
}

//AT*CHAPAUTH
CiReturnCode PS_SendChapAuthReq(UINT32 atHandle, UINT8 cid,  CHAR *challenge,  CHAR *response)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimChapAuthenticateReq *authReq = NULL;
	INT32 i, j, len;


	authReq = utlCalloc(1, sizeof(CiPsPrimChapAuthenticateReq));
	if (authReq == NULL)
		return CIRC_FAIL;

	len = strlen(challenge);
	for (i = 0, j = 0; j < len; i++, j += 2 )
	{
		authReq->challenge.valStr[i] = (hexToNum(challenge[j]) << 4) + hexToNum(challenge[j + 1]);
	}
	authReq->challenge.len = i;

	len = strlen(response);
	for (i = 0, j = 0; j < len; i++, j += 2 )
	{
		authReq->response.valStr[i] = (hexToNum(response[j]) << 4) + hexToNum(response[j + 1]);
	}
	authReq->response.len = i;

	authReq->cid = cid;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_CHAP_AUTHENTICATE_REQ,
				 MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_CHAP_AUTHENTICATE_REQ), (void *)authReq);

	return ret;
}

//AT+GETIP=cid
CiReturnCode PS_GetGPRSContextIP (UINT32 atHandle, UINT32 dwContextID)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetPdpCtxReq    *getPdpCtxReq=NULL;
	UINT32 reqHandle=0;

	getPdpCtxReq = utlCalloc(1, sizeof(*getPdpCtxReq));
	if (getPdpCtxReq == NULL)
		return CIRC_FAIL;

	getPdpCtxReq->cid = dwContextID; //ATCI_FIRST_CID;

	reqHandle = MAKE_CI_REQ_HANDLE(atHandle, PRI_PS_PRIM_GET_IP_REQ);

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ,
			 reqHandle, (void *)getPdpCtxReq );

	return ret;

}

//AT*GETIP=cid
CiReturnCode PS_GetGPRSContextIPExt (UINT32 atHandle, UINT32 dwContextID)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetPdpCtxReq    *getPdpCtxReq=NULL;
	UINT32 reqHandle=0;

	getPdpCtxReq = utlCalloc(1, sizeof(*getPdpCtxReq));
	if (getPdpCtxReq == NULL)
		return CIRC_FAIL;

	getPdpCtxReq->cid = dwContextID;
	
	reqHandle = MAKE_CI_REQ_HANDLE(atHandle, PRI_PS_PRIM_GET_IP_EXTEND_REQ);

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ,
			 reqHandle, (void *)getPdpCtxReq );

	return ret;

}

//AT+CGDATA=
CiReturnCode PS_EnterGPRSDataMode (UINT32 atHandle, UINT32 dwContextID, CiPsL2P l2p)
{
	CiReturnCode                          ret = CIRC_SUCCESS;
	UINT32  		reqHandle = MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_ENTER_DATA_STATE_REQ);
	UINT8		atpIndex = GET_ATP_INDEX(atHandle);

	CiPsPrimEnterDataStateReq      *pdpEnterDataReq = NULL;
#ifdef ATCMD_UNIFY_ACT_CI
	CiPsPrimSetPdpCtxActStateReq   *setActStateReq = NULL;
	CiPsPrimDefinePdpCtxReq *defPdpReq = NULL;
#endif
	AtciCurrentSetCntx *p_cInfo;
	UINT8 index;
#ifdef LWIP_IPNETBUF_SUPPORT
	telPsPdpCtx *setPdpCtx = telGetPdpCtx(dwContextID);
#endif
#ifdef PPP_ENABLE
    if (l2p == CI_PS_L2P_PPP)
    {
        ret = ATRESP( atHandle, ATCI_RESULT_CODE_SUPPRESS, 0, (CHAR *)"CONNECT");
        handle_dial(atpIndex);
        return ret;
    }
#endif

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
		p_cInfo = gCIDList.cInfo;
	} else {
		p_cInfo = gCIDList.cInfo_1;
	}
#else
	p_cInfo = gCIDList.cInfo;
#endif
	gCIDList.currCntx[atpIndex].currCid = dwContextID;


	index = getPdpIndexByCid(dwContextID,p_cInfo);
	/* Mark the context as waiting to enter data state */

#ifdef LWIP_IPNETBUF_SUPPORT
	if (((index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM) &&(p_cInfo[index].bDefined == TRUE))
		|| (setPdpCtx && setPdpCtx->reDefined == TRUE))
#else
	if ((index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM) &&(p_cInfo[index].bDefined == TRUE))
#endif
	{
#if defined (LWIP_IPNETBUF_SUPPORT)
		if (setPdpCtx && setPdpCtx->reDefined && isHandleForMasterSim(reqHandle))
		{
		#if !defined(ATCMD_UNIFY_ACT_CI)
			ret = setRedefinePdpActiveReq(reqHandle, dwContextID, TRUE);
		#else
			if(index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
			{
				index = getFreePdpIndexFromTable(p_cInfo);
				if (index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
				{
					telPsPdpApn 	  pdpApnInfo = {0};
					telPsPdpOpt 	  pdpOpt = {0};
			
					telSetPdpCtxApnDS(atHandle, dwContextID, &pdpApnInfo);
					telSetPdpCtxOptDS(atHandle, dwContextID, &pdpOpt);
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, 0);
					return CIRC_FAIL;
				}
			}
			
			defPdpReq = utlCalloc(1,sizeof(*defPdpReq));
			if (defPdpReq == NULL)
			{
				ret = CIRC_FAIL;
				goto end;
			}

			defPdpReq->pdpCtx.cid = dwContextID;
			if (setPdpCtx->apnInfo.defined)
			{
				defPdpReq->pdpCtx.type = setPdpCtx->apnInfo.ipType;
				if (strlen(setPdpCtx->apnInfo.apn) > 0)
				{
					strncpy(defPdpReq->pdpCtx.apn.valStr, setPdpCtx->apnInfo.apn, TEL_AT_CGDCONT_2_APN_STR_MAX_LEN - 1);
					defPdpReq->pdpCtx.apn.len = strlen(setPdpCtx->apnInfo.apn);
					defPdpReq->pdpCtx.apnPresent = TRUE;
				}
			}
			copyOpt2CiPdpCtx(&(defPdpReq->pdpCtx), &(setPdpCtx->opt));
			
			p_cInfo[index].pdpType = defPdpReq->pdpCtx.type;
			p_cInfo[index].cid= defPdpReq->pdpCtx.cid;

			if (GET_ATP_INDEX(atHandle) == TEL_MODEM_AT_CMD_ATP)
				p_cInfo[index].connectionType = ATCI_REMOTE;
			else
				p_cInfo[index].connectionType = ATCI_LOCAL;
			
			setActStateReq = (CiPsPrimSetPdpCtxActStateReq*)utlCalloc(1, sizeof(CiPsPrimSetPdpCtxActStateReq));
			if (setActStateReq == NULL)
			{
				ret = CIRC_FAIL;
				goto end;
			}

			setActStateReq->state = TRUE;
			setActStateReq->cid = dwContextID;
			setActStateReq->doAll = FALSE;
			setActStateReq->l2p = l2p;
			
			gCIDList.currCntx[GET_ATP_INDEX(atHandle)].reqMsg = setActStateReq;
		
			ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_DEFINE_PDP_CTX_REQ,
				MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ), (void *)defPdpReq );
		#endif
		}
		else
#endif
		{
			p_cInfo[index].pdpType = CI_PS_PDP_TYPE_IP;

			if (GET_ATP_INDEX(atHandle) == TEL_MODEM_AT_CMD_ATP)
				p_cInfo[index].connectionType = ATCI_REMOTE;
			else
				p_cInfo[index].connectionType = ATCI_LOCAL;
		
			/*Fixed me: shall we allow to reactivate one active PDP context*/
			if (p_cInfo[index].reqHandle != INVALID_REQ_HANDLE)
			{
				ERRMSG("%s: the dwContextID:%d has been actived. So reject to reactivate it!\n", __FUNCTION__, dwContextID);
				utlFree(pdpEnterDataReq);
#ifdef QUECTEL_NETWORK_SUPPORT
				CPUartLogPrintf("%s,%d,re active,return ok directly ",__func__,__LINE__);	
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
				return CIRC_FAIL;
#else
				return ret;
#endif
			}
#ifdef ATCMD_UNIFY_ACT_CI
			setActStateReq = (CiPsPrimSetPdpCtxActStateReq*)utlCalloc(1, sizeof(CiPsPrimSetPdpCtxActStateReq));
			if (setActStateReq == NULL)
				return CIRC_FAIL;

			setActStateReq->state = TRUE;
			setActStateReq->cid = dwContextID;
			setActStateReq->doAll = FALSE;
			setActStateReq->l2p = l2p;
			
			ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ,
					 reqHandle, (void *)setActStateReq );

#else
			pdpEnterDataReq = utlCalloc(1, sizeof(*pdpEnterDataReq));
			if (pdpEnterDataReq == NULL)
				return CIRC_FAIL;

			pdpEnterDataReq->optimizedData = TRUE;
			pdpEnterDataReq->cid = dwContextID;
			pdpEnterDataReq->l2p = l2p;
	
			DBGMSG("ciEnterData:cid=%d,l2p=%d,opt-%d\n",
			       pdpEnterDataReq->cid, pdpEnterDataReq->l2p, pdpEnterDataReq->optimizedData);

			/* Send the CI Request */
			ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_ENTER_DATA_STATE_REQ,
					 reqHandle, (void *)pdpEnterDataReq );
#endif

		}

	}
	else
	{
		/* If the CID is not defined, we think it's no sense to use the default PDP to activate it
		 * because we cannot assume the default PDP APN is fixed.
		 * Therefore, we just reject the request.
		 */
		ERRMSG("%s: the dwContextID:%d is not defined. Please define it first!\n", __FUNCTION__, dwContextID);
		return CIRC_FAIL;
	}
end:
	if (ret == CIRC_FAIL)
	{
		if (pdpEnterDataReq)
			utlFree(pdpEnterDataReq);
		
#ifdef ATCMD_UNIFY_ACT_CI
		if (defPdpReq)
			utlFree(defPdpReq);
		
		if (setActStateReq)
			utlFree(setActStateReq);
#endif
	}

	return ret;

}
#ifndef LTEONLY_THIN

//AT+CGEQREQ?
CiReturnCode PS_Get3GQualityOfServiceList (UINT32 atHandle, CiPs3GQosType type)
{
	CiReturnCode				   ret = CIRC_FAIL;
	CiPsPrimGet3GQosReq      *get3GQosReq=NULL;
	UINT32 reqHandle=0;

	get3GQosReq = utlCalloc(1, sizeof(*get3GQosReq));
	if (get3GQosReq == NULL)
		return CIRC_FAIL;

	get3GQosReq->cid = ATCI_FIRST_CID;
	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = ATCI_FIRST_CID;
	get3GQosReq->qosType = type;

	if (type == CI_PS_3G_QOSTYPE_MIN)
		reqHandle = MAKE_CI_REQ_HANDLE(atHandle,PRI_PS_PRIM_GET_MIN_QOS_REQ);
	else if (type == CI_PS_3G_QOSTYPE_NEG)
		reqHandle = MAKE_CI_REQ_HANDLE(atHandle,PRI_PS_PRIM_GET_NEG_QOS_REQ);
	else
		reqHandle = MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_3G_QOS_REQ);

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_3G_QOS_REQ,
			reqHandle, (void *)get3GQosReq );

	return ret;
}

//AT+CGEQREQ=
CiReturnCode PS_Set3GQualityOfService (UINT32 atHandle, UINT32 dwContextID, const CiPs3GQosProfile* lp3GQosProfile, CiPs3GQosType type)
{
	CiReturnCode				   ret = CIRC_FAIL;
	CiPsPrimSet3GQosReq      *set3GQosReq=NULL;

	set3GQosReq = utlCalloc(1, sizeof(*set3GQosReq));
	if (set3GQosReq == NULL)
		return CIRC_FAIL;

	set3GQosReq->cid = dwContextID;
	set3GQosReq->qosType = type;
	memcpy(&set3GQosReq->qosProf, lp3GQosProfile, sizeof(CiPs3GQosProfile));

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_3G_QOS_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_3G_QOS_REQ), (void *)set3GQosReq );

	return ret;
}

//AT+CGEQREQ=?
CiReturnCode PS_Get3GCapsQos (UINT32 atHandle, CiPs3GQosType type)
{
	CiReturnCode				   ret = CIRC_FAIL;
	CiPsPrimGet3GQosCapsReq  *get3GQosCapsReq=NULL;
	UINT32 reqHandle=0;

	get3GQosCapsReq = utlCalloc(1, sizeof(*get3GQosCapsReq));
	if (get3GQosCapsReq == NULL)
		return CIRC_FAIL;

	get3GQosCapsReq->qosType = type;
	if (type == CI_PS_3G_QOSTYPE_MIN)
		reqHandle = MAKE_CI_REQ_HANDLE(atHandle,PRI_PS_PRIM_GET_MIN_QOS_CAPS_REQ);
	else if (type == CI_PS_3G_QOSTYPE_NEG)
		reqHandle = MAKE_CI_REQ_HANDLE(atHandle,PRI_PS_PRIM_GET_NEG_QOS_CAPS_REQ);
	else
		reqHandle = MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_3G_QOS_CAPS_REQ);

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_3G_QOS_CAPS_REQ,
			reqHandle, (void *)get3GQosCapsReq );

	return ret;
}


//AT+CGQREQ=?
CiReturnCode PS_GetGprsCapsQos (UINT32 atHandle, BOOL isMin)
{

	CiReturnCode				   ret = CIRC_FAIL;
	CHAR *rspBuf = NULL;
	CHAR tmpBuf[80] = {0};

    rspBuf = (char *)utlCalloc(360,1);
	if(rspBuf == NULL)
	{
		ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);		
		return ret;
	}

	if(isMin)
	{
		sprintf(rspBuf, "+CGQMIN: \"IP\",(0-3),(0-4),(0-5),(0-9),(0-18,31)\r\n");

		sprintf(tmpBuf, "+CGQMIN: \"IPV6\",(0-3),(0-4),(0-5),(0-9),(0-18,31)\r\n");
		strcat(rspBuf, tmpBuf);

		sprintf(tmpBuf, "+CGQMIN: \"IPV4V6\",(0-3),(0-4),(0-5),(0-9),(0-18,31)\r\n");
		strcat(rspBuf, tmpBuf);
	}
	else
	{
		sprintf(rspBuf, "+CGQREQ: \"IP\",(0-3),(0-4),(0-5),(0-9),(0-18,31)\r\n");

		sprintf(tmpBuf, "+CGQREQ: \"IPV6\",(0-3),(0-4),(0-5),(0-9),(0-18,31)\r\n");
		strcat(rspBuf, tmpBuf);

		sprintf(tmpBuf, "+CGQREQ: \"IPV4V6\",(0-3),(0-4),(0-5),(0-9),(0-18,31)\r\n");
		strcat(rspBuf, tmpBuf);
	}
	
	ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0,(char *)rspBuf);

	utlFree(rspBuf);
	
	return ret;
}
#endif
//AT+CGDSCONT?
CiReturnCode PS_GetSecondaryContextList (UINT32 atHandle)
{
	CiReturnCode			ret = CIRC_FAIL;
	CiPsPrimGetSecPdpCtxReq        *getSecPdpReq=NULL;

	getSecPdpReq = utlCalloc(1,sizeof(*getSecPdpReq));
	if (getSecPdpReq == NULL)
		return CIRC_FAIL;
	getSecPdpReq->cid = ATCI_FIRST_CID;
	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = ATCI_FIRST_CID;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_SEC_PDP_CTX_REQ,
				MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_SEC_PDP_CTX_REQ), (void *)getSecPdpReq );

	return ret;
}

//AT+CGDSCONT=
CiReturnCode PS_SetSecondaryPDPContext (UINT32 atHandle, const CiPsSecPdpCtx* lpSecondaryPDPContext)
{
	CiReturnCode                          ret = CIRC_FAIL;
	CiPsPrimDefineSecPdpCtxReq     *defSecPdpReq=NULL;

	//if ( gCIDList.cInfo[lpSecondaryPDPContext->p_cid].bDefined == TRUE )
	{
		gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = lpSecondaryPDPContext->cid;
		defSecPdpReq = utlCalloc(1, sizeof(*defSecPdpReq));
		if (defSecPdpReq == NULL)
			return CIRC_FAIL;
		memcpy(&defSecPdpReq->secPdpCtx, lpSecondaryPDPContext, sizeof(CiPsSecPdpCtx));
		ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_DEFINE_SEC_PDP_CTX_REQ,
				MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_DEFINE_SEC_PDP_CTX_REQ), (void *)defSecPdpReq );
	}

	return ret;

}
//AT+CGDSCONT=only CID
CiReturnCode PS_DeleteSecondaryPDPContext (UINT32 atHandle, UINT32 dwContextID)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimDeleteSecPdpCtxReq  *deletePdpCtxReq=NULL;

	/* Delete Second PDP context */
	deletePdpCtxReq = utlCalloc(1, sizeof(*deletePdpCtxReq));
	if (deletePdpCtxReq == NULL)
		return CIRC_FAIL;
	deletePdpCtxReq->cid = dwContextID;
	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = dwContextID;
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_DELETE_SEC_PDP_CTX_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_DELETE_SEC_PDP_CTX_REQ), (void *)deletePdpCtxReq );

	return ret;

}

//AT+CGDSCONT=?
CiReturnCode PS_GetSecondaryContextRange (UINT32 atHandle)
{
	CiReturnCode			ret = CIRC_FAIL;
	CiPsPrimGetPdpCtxReq    *getPdpCtxReq=NULL;
	UINT32 reqHandle=0;

	getPdpCtxReq = utlCalloc(1,sizeof(*getPdpCtxReq));
	if (getPdpCtxReq == NULL)
		return CIRC_FAIL;
	getPdpCtxReq->cid = ATCI_FIRST_CID;
	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = ATCI_FIRST_CID;
	reqHandle = MAKE_CI_REQ_HANDLE(atHandle,PRI_PS_PRIM_GET_SECOND_PDP_CTXS_RANGE_REQ);

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ,
				reqHandle, (void *)getPdpCtxReq );

	return ret;
}

//AT*FastDorm
CiReturnCode PS_FastDormancy(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	UINT32 reqHandle=0;
	reqHandle = MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_FAST_DORMANT_REQ);
	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_FAST_DORMANT_REQ, reqHandle, NULL);
	return ret;
}

#ifndef LTEONLY_THIN
//AT*FDY=
CiReturnCode PS_SetFDY(UINT32 atHandle, UINT8 mode, UINT32 lcdOnTimerInterval, UINT32 lcdOffTimerInterval, UINT32 rel8LcdOnTimerInterval, UINT32 rel8LcdOffTimerInterval)
{
		CiReturnCode ret = CIRC_FAIL;
		CiPsPrimSetFastDormancyConfigReq *setFastDormancyConfigReq = NULL;
		setFastDormancyConfigReq = utlCalloc(1, sizeof(CiPsPrimSetFastDormancyConfigReq));
		if (setFastDormancyConfigReq == NULL)
			return CIRC_FAIL;
		/* enable fast dormancy: mode:1, timer not set to zeo
			disbale fast dormancy: mode:1, timer set to zero */

		setFastDormancyConfigReq->mode = mode;
		if(mode == 1)
		{
			setFastDormancyConfigReq->lcdOnTimerMsLength= lcdOnTimerInterval;
			setFastDormancyConfigReq->lcdOffTimerMsLength= lcdOffTimerInterval;
			setFastDormancyConfigReq->rel8LcdOnTimerMsLength= rel8LcdOnTimerInterval;
			setFastDormancyConfigReq->rel8LcdOffTimerMsLength= rel8LcdOffTimerInterval;
		}
		ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_FAST_DORMANCY_CONFIG_REQ,
			MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_SET_FAST_DORMANCY_CONFIG_REQ), (void*)setFastDormancyConfigReq);
		return ret;
}
#endif
//AT*CGATT=
CiReturnCode PS_SetPsPowerOnAutoAttach(UINT32 atHandle, BOOL enable)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimEnablePoweronAutoAttachReq *enablePoweronAutoAttachReq = NULL;
	enablePoweronAutoAttachReq = utlCalloc(1, sizeof(CiPsPrimEnablePoweronAutoAttachReq));
	if (enablePoweronAutoAttachReq == NULL)
		return CIRC_FAIL;
	enablePoweronAutoAttachReq->enableAutoAttach = enable;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_ENABLE_POWERON_AUTO_ATTACH_REQ,
		MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_ENABLE_POWERON_AUTO_ATTACH_REQ), (void*)enablePoweronAutoAttachReq);
	return ret;
}

//AT*CGATT?
CiReturnCode PS_GetPsPowerOnAutoAttach(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetPoweronAutoAttachStatusReq *getPoweronAutoAttachStatusReq = NULL;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_POWERON_AUTO_ATTACH_STATUS_REQ,
		MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_GET_POWERON_AUTO_ATTACH_STATUS_REQ), (void*)getPoweronAutoAttachStatusReq);
	return ret;
}

//AT*CGDFLT?
CiReturnCode PS_GetDefaultPDPContext (UINT32 atHandle, UINT8 type)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetDefaultPdpReq  *getdefPdpReq = NULL;
	getdefPdpReq = utlCalloc(1, sizeof(CiPsPrimGetDefaultPdpReq));
	if (getdefPdpReq == NULL)
		return CIRC_FAIL;
	getdefPdpReq->modeType = type;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_DEFAULT_PDP_CTX_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_GET_DEFAULT_PDP_CTX_REQ), (void *)getdefPdpReq );

	return ret;
}

//AT*CGDFLT=
CiReturnCode PS_SetDefaultPDPContext (UINT32 atHandle, const CiPsPrimDefineDefaultPdpCtxReq* defaultPdpCtxInfo)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimDefineDefaultPdpCtxReq *defaultPdpCtxReq = NULL;
	defaultPdpCtxReq = utlCalloc(1, sizeof(CiPsPrimDefineDefaultPdpCtxReq));
	if (defaultPdpCtxReq == NULL)
		return CIRC_FAIL;
	memcpy(defaultPdpCtxReq, defaultPdpCtxInfo, sizeof(CiPsPrimDefineDefaultPdpCtxReq));
#ifndef MIN_SYS
    if (!IsMiniSystem()) 
    {//MiniSystem
#if QUEC_DEFAULT_AUTH_CHECK_SUPPORT
                UINT8 quec_sim_id=GET_SIM1_FLAG(atHandle);
               memset(&quec_default_pdn_gki_back[quec_sim_id].apn,0,sizeof(quec_default_pdn_gki_back[quec_sim_id].apn));
               quec_default_pdn_gki_back[quec_sim_id].pdp_type=(int)defaultPdpCtxReq->pdpType;
               strncpy(quec_default_pdn_gki_back[quec_sim_id].apn,defaultPdpCtxReq->apn.valStr,defaultPdpCtxReq->apn.len);
#endif
    }
#endif
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_DEFINE_DEFAULT_PDP_CTX_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_DEFINE_DEFAULT_PDP_CTX_REQ), (void *)defaultPdpCtxReq );

	return ret;
}
#ifdef QUECTEL_NETWORK_SUPPORT //connor.wu 2018/02/22 synchronous cgdcont with CGDFLT when cid=1
CiReturnCode PS_SetDefaultPDPContextByReqHandler (UINT32 reqHandle, const CiPsPrimDefineDefaultPdpCtxReq* defaultPdpCtxInfo)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimDefineDefaultPdpCtxReq *defaultPdpCtxReq = NULL;
	defaultPdpCtxReq = utlCalloc(1, sizeof(CiPsPrimDefineDefaultPdpCtxReq));
	if (defaultPdpCtxReq == NULL)
		return CIRC_FAIL;
	memcpy(defaultPdpCtxReq, defaultPdpCtxInfo, sizeof(CiPsPrimDefineDefaultPdpCtxReq));
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
#if QUEC_DEFAULT_AUTH_CHECK_SUPPORT
            UINT8 quec_sim_id=GET_SIM1_FLAG(reqHandle);
           memset(&quec_default_pdn_gki_back[quec_sim_id].apn,0,sizeof(quec_default_pdn_gki_back[quec_sim_id].apn));
           quec_default_pdn_gki_back[quec_sim_id].pdp_type=(int)defaultPdpCtxReq->pdpType;
           strncpy(quec_default_pdn_gki_back[quec_sim_id].apn,defaultPdpCtxReq->apn.valStr,defaultPdpCtxReq->apn.len);
#endif
}
#endif
	ret = ciRequestExt( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_DEFINE_DEFAULT_PDP_CTX_REQ,
			 reqHandle, (void *)defaultPdpCtxReq );

	return ret;
}
#endif

//AT*CGDFAUTH? or AT*CGDFAUTH=<0|1>
CiReturnCode PS_GetDefaultPdpAuthenticate(UINT32 atHandle, UINT8 type)

{
	//type:	0 - current used
	//      1 - from NVM
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetDefaultPdpAuthenticateReq  *getdefPdpAuthReq = NULL;

	getdefPdpAuthReq = utlCalloc(1, sizeof(CiPsPrimGetDefaultPdpAuthenticateReq));
	if(getdefPdpAuthReq == NULL)
		return CIRC_FAIL;
	getdefPdpAuthReq->modeType = type;


	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_DEFAULT_PDP_AUTHENTICATE_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_GET_DEFAULT_PDP_AUTHENTICATE_REQ), (void *)getdefPdpAuthReq );

	return ret;
}

//AT*CGDFAUTH=
CiReturnCode PS_SetDefaultPdpAuthenticate(UINT32 atHandle, const CiPsPrimSetDefaultPdpAuthenticateReq* setDefPdpAuthReqInfo)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetDefaultPdpAuthenticateReq* setDefPdpAuthReq = NULL;
	setDefPdpAuthReq = utlCalloc(1, sizeof(CiPsPrimSetDefaultPdpAuthenticateReq));
	if (setDefPdpAuthReq == NULL)
		return CIRC_FAIL;
	memcpy(setDefPdpAuthReq, setDefPdpAuthReqInfo, sizeof(CiPsPrimSetDefaultPdpAuthenticateReq));
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
#if QUEC_DEFAULT_AUTH_CHECK_SUPPORT
        UINT8 quec_sim_id=GET_SIM1_FLAG(atHandle);
       quec_default_pdn_gki_back[quec_sim_id].auth_type=(int)setDefPdpAuthReqInfo->authenticationType;
       memset(quec_default_pdn_gki_back[quec_sim_id].password,0,sizeof(quec_default_pdn_gki_back[quec_sim_id].password));
       memset(quec_default_pdn_gki_back[quec_sim_id].user_name,0,sizeof(quec_default_pdn_gki_back[quec_sim_id].user_name));
       strncpy(quec_default_pdn_gki_back[quec_sim_id].password,setDefPdpAuthReqInfo->password.valStr,setDefPdpAuthReqInfo->password.len);
       strncpy(quec_default_pdn_gki_back[quec_sim_id].user_name,setDefPdpAuthReqInfo->userName.valStr,setDefPdpAuthReqInfo->userName.len);
#if 0
	   if(strstr(mob_sw_rev, "CIVER"))
#endif
	   {
		  QuecSetDefaultPdpFlag = 1;
	   }
#endif
}
#endif
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_DEFAULT_PDP_AUTHENTICATE_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_SET_DEFAULT_PDP_AUTHENTICATE_REQ), (void *)setDefPdpAuthReq );

	return ret;
}

#ifndef LTEONLY_THIN
//AT+VZWAPNE?
CiReturnCode PS_GetAPNList (UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetApnReq  *getApnReq = NULL;
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem

#ifdef QUECTEL_NETWORK_SUPPORT
	ret = ciRequestExt( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_APN_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_GET_APN_REQ), (void *)getApnReq );
#else
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_APN_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_GET_APN_REQ), (void *)getApnReq );
#endif
}//MiniSystem
else
{
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_APN_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_GET_APN_REQ), (void *)getApnReq );
}
#endif /*MIN_SYS*/
	return ret;
}

//AT+VZWAPNE=
CiReturnCode PS_SetAPNList (UINT32 atHandle, const CiPsPrimSetApnReq* setApnReqInfo)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetApnReq *setApnReq = NULL;
	setApnReq = utlCalloc(1, sizeof(CiPsPrimSetApnReq));
	if (setApnReq == NULL)
		return CIRC_FAIL;
	memcpy(setApnReq, setApnReqInfo, sizeof(CiPsPrimSetApnReq));

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_APN_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_SET_APN_REQ), (void *)setApnReq );

	return ret;
}
#endif
//AT*PSPG=
CiReturnCode PS_SetPsPlusPaging(UINT32 atHandle, BOOL enable)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetPsPagingyConfigReq *setPsPagingyConfigReq = NULL;
	setPsPagingyConfigReq = utlCalloc(1, sizeof(CiPsPrimSetPsPagingyConfigReq));
	if (setPsPagingyConfigReq == NULL)
		return CIRC_FAIL;
	setPsPagingyConfigReq->enable = enable;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_PS_PAGING_CONFIG_REQ,
		MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_SET_PS_PAGING_CONFIG_REQ), (void*)setPsPagingyConfigReq);
	return ret;
}

#ifdef VOLTE_ENABLE
//AT+CVDP? / AT+CEVDP?
CiReturnCode PS_GetVoiceDomainPreference(UINT32 atHandle, CiBoolean eutran)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetVoiceDomainPreferenceReq *getVoiceDomainPreferenceReq = NULL;
	int *pGetEutranVoiceDomainPreference;

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle))
	{
		pGetEutranVoiceDomainPreference = &gGetEutranVoiceDomainPreference;
	}
	else
	{
		pGetEutranVoiceDomainPreference = &gGetEutranVoiceDomainPreference_1;
	}
#else

	pGetEutranVoiceDomainPreference = &gGetEutranVoiceDomainPreference;
#endif


	*pGetEutranVoiceDomainPreference = eutran;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_VOICE_DOMAIN_PREFERENCE_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_VOICE_DOMAIN_PREFERENCE_REQ), (void *)getVoiceDomainPreferenceReq);

	return ret;
}

//AT+CVDP= / AT+CEVDP=
CiReturnCode PS_SetVoiceDomainPreference(UINT32 atHandle, UINT8 setting, CiBoolean eutran)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetVoiceDomainPreferenceReq *setVoiceDomainPreferenceReq;

	setVoiceDomainPreferenceReq = utlCalloc(1, sizeof(CiPsPrimSetVoiceDomainPreferenceReq));
	if (setVoiceDomainPreferenceReq != NULL)
	{
		setVoiceDomainPreferenceReq->eutran = eutran;
		setVoiceDomainPreferenceReq->setting = setting - 1;

		ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_VOICE_DOMAIN_PREFERENCE_REQ,
				MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_VOICE_DOMAIN_PREFERENCE_REQ), (void *)setVoiceDomainPreferenceReq);
	}

	return ret;
}
#endif

//AT+CEUS?
CiReturnCode PS_GetEpsUsageSetting(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetEpsUsageSettingReq *getEpsUsageSettingReq = NULL;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_EPS_USAGE_SETTING_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_EPS_USAGE_SETTING_REQ), (void *)getEpsUsageSettingReq);

	return ret;
}

//AT+CEUS=
CiReturnCode PS_SetEpsUsageSetting(UINT32 atHandle, UINT8 setting)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetEpsUsageSettingReq *setEpsUsageSettingReq;
	setEpsUsageSettingReq = utlCalloc(1, sizeof(CiPsPrimSetEpsUsageSettingReq));
	if (setEpsUsageSettingReq != NULL)
	{
		setEpsUsageSettingReq->epsUsageSetting = setting;
		ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_EPS_USAGE_SETTING_REQ,
				MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_EPS_USAGE_SETTING_REQ), (void *)setEpsUsageSettingReq);
	}

	return ret;
}

/************************************************************************************
 * F@: sendDefineDefaultPdpContext
 *
 */
CiReturnCode   sendDefineDefaultPdpContext( CiRequestHandle reqHandle, INT8 cid )
{
	CiReturnCode                          ret = CIRC_FAIL;
	CiPsPrimDefinePdpCtxReq        *enterDataDefPdpReq=NULL;

	/* initialize the request fields to the default values */
	enterDataDefPdpReq = utlCalloc(1, sizeof(*enterDataDefPdpReq));
	if (enterDataDefPdpReq == NULL)
		return CIRC_FAIL;

	enterDataDefPdpReq->pdpCtx.cid = cid;
	enterDataDefPdpReq->pdpCtx.type = CI_PS_PDP_TYPE_IP;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_DEFINE_PDP_CTX_REQ,
			reqHandle, (void *)enterDataDefPdpReq );

	return ret;
}

#ifdef PLATFORM_FOR_PS_LW

/************************************************************************************
 * F@: PS_SetAclCheck
 *
 */
CiReturnCode PS_SetAclCheck (UINT32 atHandle, BOOL gsimAclPresent,BOOL gsimAclEnable,BOOL gpsAclPresent,BOOL gpsAclEnable)
{
	CiReturnCode                        ret = CIRC_FAIL;
	CiPsPrimSetAclReq    *setAcl;
	UINT32 reqHandle = MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_ACL_SERVICE_REQ);

	setAcl = utlCalloc(1, sizeof(*setAcl));
	setAcl->simAclPresent = gsimAclPresent;
	setAcl->simAclEnable = gsimAclEnable;
	setAcl->psAclPresent= gpsAclPresent;
	setAcl->psAclEnable= gpsAclEnable;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_ACL_SERVICE_REQ,
			reqHandle, (void *)setAcl);
	utlFree(setAcl);
	return ret;
}

#endif

/*******************************************************************
 *  FUNCTION:  ciMakeGPRSDataCallbyAtd
 *
 *  DESCRIPTION: To support GPRS Data Call triggered by ATD, such as ATDT*99#
 *
 *
 *  RETURNS: _CiReturnCode
 *
 *******************************************************************/
CiReturnCode ciMakeGPRSDataCallbyAtd (UINT32 atHandle, const char *command_name_p)
{
	CiReturnCode                 ret = CIRC_FAIL;
	UINT16                 dialDigitsLen = strlen(command_name_p);
	UINT8 cid = 0;
	CiPsL2P l2p=0;

	/* this is gprs data call*/
	if(dialDigitsLen > strlen("*99***"))
		cid= atoi(&command_name_p[strlen("*99***")]) - 1 ;

	if (cid >= CI_PS_MAX_CID)
	{
		ERRMSG("%s:Invalid cid:%d\n",__FUNCTION__, cid);
		return CIRC_FAIL;
	}

	l2p = CI_PS_L2P_PPP;

	ret = PS_EnterGPRSDataMode(atHandle, cid, l2p);

	return ret;

}

void resetCurrCntx(UINT8 atpIdx)
{
	AtciCurrentSetCntx *p_cInfo;
	UINT8 index;

#ifndef SINGLE_SIM
	if (atpIdx < TEL_AT_CMD_ATP_36) {
		p_cInfo = gCIDList.cInfo;
	} else {
		p_cInfo = gCIDList.cInfo_1;
	}
#else
	p_cInfo = gCIDList.cInfo;
#endif

	if (atpIdx < NUM_OF_TEL_ATP)
	{
		if (gCIDList.currCntx[atpIdx].currCid != CI_PS_MAX_CID)
		{
			index = getPdpIndexByCid(gCIDList.currCntx[atpIdx].currCid,p_cInfo);
			if(index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
			{
				p_cInfo[index].reqHandle = INVALID_REQ_HANDLE;
			}
			gCIDList.currCntx[atpIdx].currCid = CI_PS_MAX_CID;

		}
		if (gCIDList.currCntx[atpIdx].reqMsg != NULL)
		{
			utlFree(gCIDList.currCntx[atpIdx].reqMsg);
			gCIDList.currCntx[atpIdx].reqMsg = NULL;
		}
	}
}

static void resetPdpInfo(AtciCurrentSetCntx* p_Info)
{

	p_Info->bDefined = FALSE;
	p_Info->cid = CI_PS_MAX_CID;
	p_Info->connectionType = ATCI_LOCAL;
	p_Info->pdpAddress[0] = 0;
	p_Info->pdpType = CI_PS_PDP_NUM_TYPES;
	p_Info->reqHandle = INVALID_REQ_HANDLE;
}

void resetCidList(CiRequestHandle reqHandle)
{
	int i;
	int from, to;
	AtciCurrentSetCntx *p_cInfo;

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(reqHandle)) {
		from = TEL_AT_CMD_ATP_0;
		to = TEL_AT_CMD_ATP_35 + 1;
		p_cInfo = gCIDList.cInfo;
	} else {
		from = TEL_AT_CMD_ATP_36;
		to = TEL_AT_CMD_ATP_71 + 1;
		p_cInfo = gCIDList.cInfo_1;
	}
#else
	from = TEL_AT_CMD_ATP_0;
	to = TEL_AT_CMD_ATP_35 + 1;
	p_cInfo = gCIDList.cInfo;
#endif


	for ( i = from; i < to; i++ )
		resetCurrCntx(i);

	for ( i = 0; i < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM; i++ ) {
		if (p_cInfo[i].reqHandle == INVALID_REQ_HANDLE)
		{
			p_cInfo[i].bDefined = FALSE;
			p_cInfo[i].cid= CI_PS_MAX_CID;
		}
}
}
void resetPsParas(void)
{
#ifndef SINGLE_SIM
#ifndef LTEONLY_THIN
		gCurrentPSRegOption[0] = CI_PS_NW_REG_IND_ENABLE_DETAIL;
		gCurrentPSRegOption_1[0] = CI_PS_NW_REG_IND_ENABLE_DETAIL;
		g4gCurrentPSRegOption[0] = CI_PS_NW_REG_IND_ENABLE_DETAIL;
		g4gCurrentPSRegOption_1[0] = CI_PS_NW_REG_IND_ENABLE_DETAIL;
	
		gCurrentPSRegOption[1] = CI_PS_NW_REG_IND_ENABLE_DETAIL;
		gCurrentPSRegOption_1[1] = CI_PS_NW_REG_IND_ENABLE_DETAIL;
		g4gCurrentPSRegOption[1] = CI_PS_NW_REG_IND_ENABLE_DETAIL;
		g4gCurrentPSRegOption_1[1] = CI_PS_NW_REG_IND_ENABLE_DETAIL;
#endif
	
		gCurrentPSRegStatus = CI_PS_NW_REG_STA_NOT_REGED;
		gCurrentPSRegStatus_1 = CI_PS_NW_REG_STA_NOT_REGED;
		g4gCurrentPSRegStatus = CI_PS_NW_REG_STA_NOT_REGED;
		g4gCurrentPSRegStatus_1 = CI_PS_NW_REG_STA_NOT_REGED;
		gPsActDetail = 0;
		gPsActDetail_1 = 0;
#else
#ifndef LTEONLY_THIN
		gCurrentPSRegOption[0] = CI_PS_NW_REG_IND_ENABLE_DETAIL;
		g4gCurrentPSRegOption[0] = CI_PS_NW_REG_IND_ENABLE_DETAIL;
	
		gCurrentPSRegOption[1] = CI_PS_NW_REG_IND_ENABLE_DETAIL;
		g4gCurrentPSRegOption[1] = CI_PS_NW_REG_IND_ENABLE_DETAIL;
#endif
	
		gCurrentPSRegStatus = CI_PS_NW_REG_STA_NOT_REGED;
		g4gCurrentPSRegStatus = CI_PS_NW_REG_STA_NOT_REGED;
		gPsActDetail = 0;
#endif

}

/************************************************************************************
 *
 * PS CI confirmations
 *
 *************************************************************************************/
void getPdpTypeStr (CiPsPdpType pdpType, char  *typeStr)
{
	/* PDP type number */
	switch ( pdpType )
	{
		case CI_PS_PDP_TYPE_IP:      /* IPv4 */
		{
			sprintf((char *)typeStr, "\"IP\"");
			break;
		}
		case CI_PS_PDP_TYPE_IPV6:    /* IPv6 */
		{
			sprintf((char *)typeStr, "\"IPV6\"");
			break;
		}
		case CI_PS_PDP_TYPE_IPV4V6:    /* IPv4IPv6 */
		{
			sprintf((char *)typeStr, "\"IPV4V6\"");
			break;
		}
		default:
			break;
	}
}

static void getApnTypeStr (CiPsApnAddrType apnType, char  *typeStr)
{
	/* Apn type number */
	switch ( apnType )
	{
		case CI_PS_APN_ADDR_IPV4_TYPE:      /* IPv4 */
		{
			sprintf((char *)typeStr, "\"IP\"");
			break;
		}
		case CI_PS_APN_ADDR_IPV6_TYPE:    /* IPv6 */
		{
			sprintf((char *)typeStr, "\"IPv6\"");
			break;
		}
		case CI_PS_APN_ADDR_IPV4V6_TYPE:    /* IPv4IPv6 */
		{
			sprintf((char *)typeStr, "\"IPv4v6\"");
			break;
		}
		default:
			sprintf((char *)typeStr, "\"Invalid\"");
			break;
	}
}

/* -----------------------------------------------------------------
 * Function    : Decode3GBitRate
 * Description : Decodes 3G QoS Bit Rate parameter value.
 * Parameters  : codedValue - encoded 8-bit value
 * Returns     : 16-bit decoded value, in kbps
 * Notes       : See 3GPP TS 24.008/V3.11.0, Table 10.5.156 for
 *               the coding scheme.
 *               This function is used for the Maximum and Guaranteed
 *               Bit Rate (both Uplink and Downlink) parameters.
 * ----------------------------------------------------------------- */
static INT32 Decode3GBitRate( UINT8 codedValue ,BOOL isExtension)
{
	INT32 rawValue = 0;
    if(isExtension==FALSE)
    {
		if( codedValue >= 0x01 && codedValue <= 0x3f )
		{
			/* 0x01..0x3f -> 1kbps..63kbps, in 1kbps steps */
			rawValue = (INT16) codedValue;
		}
		else if( codedValue >= 0x40 && codedValue <= 0x7f )
		{
			/* 0x40..0x7f -> 64kbps..568kbps, in 8kbps steps */
			rawValue = (INT16) ( ( codedValue - 0x40 ) * 8 ) + 64;
		}
		else if( codedValue >= 0x80 && codedValue <= 0xfe )
		{
			/* 0x80..0xfe -> 576kbps..8640kbps, in 64kbps steps */
			rawValue = (INT16) ( ( codedValue - 0x80 ) * 64 ) + 576;
		}
		else
		{
			/* 0xff -> 0kbps (explicitly) */
			rawValue = 0;
		}
    	}
	else/*isExtension == TRUE*/
	{
		if( codedValue <= 0x4a )
		{
			/* 0x01 .. 0x4a -> 8700 kbps .. 16000 kbps, in 100 kbps steps */
			rawValue = ( codedValue + 86 ) * 100;
		}
		else if( codedValue <= 0xba )
		{
			/* 0x4b .. 0xba -> 17 Mbps .. 128 Mbps, in 1 Mbps steps */
			rawValue = ( codedValue - 58 ) * 1000;
		}
		else if( codedValue <= 0xfa )
		{
			/* 0xbb .. 0xfa -> 130 Mbps .. 256 Mbps, in 2 Mbps steps */
			rawValue = ( codedValue - 122 ) * 2000;
		}
		else if(codedValue == 0xfe)
		{
			codedValue=0xfa;
			rawValue = ( codedValue - 122 ) * 2000;
		}
	}
	return( rawValue );
}


/* Added by Daniel for LTE PC AT command server 20120306, begin */
/* -----------------------------------------------------------------
 * Function    : Decode4GBitRate
 * Description : Decodes 4G QoS Bit Rate parameter value.
 * Parameters  : codedValue - encoded 8-bit value
 * Returns     : 16-bit decoded value, in kbps
 * Notes       : See 3GPP TS 24.008/V3.11.0, Table 10.5.156 for
 *               the coding scheme.
 *               This function is used for the Maximum and Guaranteed
 *               Bit Rate (both Uplink and Downlink) parameters.
 * ----------------------------------------------------------------- */
static UINT32 Decode4GBitRate( UINT16 codedValue )
{
	UINT32 rawValue = 0;

	if( codedValue >= 0x01 && codedValue <= 0x3f )
	{
		/* 0x01..0x3f -> 1kbps..63kbps, in 1kbps steps */
		rawValue = (UINT32)codedValue;
	}
	else if( codedValue >= 0x40 && codedValue <= 0x7f )
	{
		/* 0x40..0x7f -> 64kbps..568kbps, in 8kbps steps */
		rawValue = (UINT32)((codedValue - 0x40) * 8) + 64;
	}
	else if( codedValue >= 0x80 && codedValue <= 0xfe )
	{
		/* 0x80..0xfe -> 576kbps..8640kbps, in 64kbps steps */
		rawValue = (UINT32)((codedValue - 0x80) * 64) + 576;
	}
	else if( codedValue >= 0xFE && codedValue <= 0x4AFE )
	{
	    /* 0x00FE..0x4AFE -> 8700kbps..16000kbps, in 100kbps steps */
		rawValue = (UINT32)(((codedValue - 0xFE) >> 8)*100 + 8600);
	}
	else if( codedValue >= 0x4BFE && codedValue <= 0xBAFE )
	{
	    /* 0x4BFE..0xBAFE -> 17Mbps..128Mbps, in 1Mbps steps */
		rawValue = (UINT32)(((codedValue - 0x4BFE) >> 8)*1000 + 16000);
	}
	else if( codedValue >= 0xBBFE && codedValue <= 0xFAFE )
	{
	    /* 0xBBFE..0xFAFE -> 130Mbps..256Mbps, in 2Mbps steps */
		rawValue = (UINT32)(((codedValue - 0xBBFE) >> 8)*2000 + 128000);
	}
	/*Fix coverity[dead_error_line]*/
	#if 0
	else if( codedValue == 0xff )
	{
		/* 0xff -> 0kbps (explicitly) */
		rawValue = 0;
	}
	#endif
	return( rawValue );
}
/* Added by Daniel for LTE PC AT command server 20120306, end */

/* -----------------------------------------------------------------
 * Function    : Decode3GTransDelay
 * Description : Decodes 3G QoS Transfer Delay parameter value.
 * Parameters  : codedValue - encoded 8-bit value
 * Returns     : 16-bit decoded value, in ms
 * Notes       : See 3GPP TS 24.008/V3.11.0, Table 10.5.156 for
 *               the coding scheme.
 * ----------------------------------------------------------------- */
static INT16 Decode3GTransDelay( UINT8 codedValue )
{
	INT16 rawValue = 0;

	if( codedValue >= 0x01 && codedValue <= 0x0f )
	{
		/* 0x01..0x0f -> 10ms..150ms, in 10ms steps */
		rawValue = (INT16) ( codedValue * 10 );
	}
	else if( codedValue >= 0x10 && codedValue <= 0x1f )
	{
		/* 0x10..0x1f -> 200ms..950ms, in 50ms steps */
		rawValue = (INT16) ( ( codedValue - 0x10 ) * 50 ) + 200;
	}
	else if( codedValue >= 0x20 && codedValue <= 0x3e )
	{
		/* 0x20..0x3e -> 1000ms..4000ms, in 100ms steps */
		rawValue = (INT16) ( ( codedValue - 0x20 ) * 100 ) + 1000;
	}

	return( rawValue );
}

/* -----------------------------------------------------------------
 * Function    : Decode3GMaxSduSize
 * Description : Decodes 3G QoS Maximum SDU Size parameter value.
 * Parameters  : codedValue - encoded 8-bit value
 * Returns     : 16-bit decoded value, in octets
 * Notes       : See 3GPP TS 24.008/V3.11.0, Table 10.5.156 for
 *               the coding scheme.
 * ----------------------------------------------------------------- */
static INT16 Decode3GMaxSduSize( UINT8 codedValue )
{
	INT16 rawValue = 0;

	if( codedValue >= 0x01 && codedValue <= 0x96 )
	{
		/* 0x01..0x96 -> 10..1500 octets, in 10-octet steps */
		rawValue = (INT16) ( codedValue * 10 );
	}
	else if( codedValue == 0x97 )
	{
		/* 0x97 -> 1502 octets */
		rawValue = 1502;
	}
	else if( codedValue == 0x98 )
	{
		/* 0x98 -> 1510 octets */
		rawValue = 1510;
	}
	else if( codedValue == 0x99 )
	{
		/* 0x99 -> 1520 octets */
		rawValue = 1520;
	}

	return( rawValue );
}

static void printSduErrRatio( char *outStr, CiPs3GSduErrorRatio SduErrRatio )
{
	switch ( SduErrRatio )
	{
		case CI_PS_3G_SDU_ERROR_RATIO_1EM2:
			sprintf( outStr, "1E2" );
			break;

		case CI_PS_3G_SDU_ERROR_RATIO_7EM3:
			sprintf( outStr, "7E3" );
			break;

		case CI_PS_3G_SDU_ERROR_RATIO_1EM3:
			sprintf( outStr, "1E3" );
			break;

		case CI_PS_3G_SDU_ERROR_RATIO_1EM4:
			sprintf( outStr, "1E4" );
			break;

		case CI_PS_3G_SDU_ERROR_RATIO_1EM5:
			sprintf( outStr, "1E5" );
			break;

		case CI_PS_3G_SDU_ERROR_RATIO_1EM6:
			sprintf( outStr, "1E6" );
			break;

		case CI_PS_3G_SDU_ERROR_RATIO_1EM1:
			sprintf( outStr, "1E1" );
			break;

		case  CI_PS_3G_SDU_ERROR_RATIO_SUBSCRIBED:
		default:
			sprintf( outStr, "0E0" );
			break;
	}
}

static void printResBER( char *outStr, CiPs3GResidualBer ResBer )
{
	switch ( ResBer )
	{
		case CI_PS_3G_RESIDUAL_BER_5EM2:
			sprintf( outStr, "5E2" );
			break;

		case CI_PS_3G_RESIDUAL_BER_1EM2:
			sprintf( outStr, "1E2" );
			break;

		case CI_PS_3G_RESIDUAL_BER_5EM3:
			sprintf( outStr, "5E3" );
			break;

		case CI_PS_3G_RESIDUAL_BER_4EM3:
			sprintf( outStr, "4E3" );
			break;

		case CI_PS_3G_RESIDUAL_BER_1EM3:
			sprintf( outStr, "1E3" );
			break;

		case CI_PS_3G_RESIDUAL_BER_1EM4:
			sprintf( outStr, "1E4" );
			break;

		case CI_PS_3G_RESIDUAL_BER_1EM5:
			sprintf( outStr, "1E5" );
			break;

		case CI_PS_3G_RESIDUAL_BER_1EM6:
			sprintf( outStr, "1E6" );
			break;

		case CI_PS_3G_RESIDUAL_BER_6EM8:
			sprintf( outStr, "6E8" );
			break;

		case  CI_PS_3G_RESIDUAL_BER_SUBSCRIBED:
		default:
			sprintf( outStr, "0E0" );
			break;
	}
}

/* Record PDP activation fail cause, refer to 3GPP Spec TS 24.008  section 6.1.3.1.3 */
static void getPdpErrCauseString( CiPsRc cause, char *sBuf )
{
	char *tBuf=NULL;

	switch (cause)
	{
		case CIRC_PS_GPRS_SERVICES_NOT_ALLOWED:
		case CIRC_PS_OPER_DETERMINED_BARRING:
		case CIRC_PS_PLMN_NOT_ALLOWED:
		case CIRC_PS_ROAMING_NOT_ALLOWED:
		case CIRC_PS_INVALID_MS_CLASS:
			tBuf = "8 Operator Determined Barring";
			break;

		case CIRC_PS_LA_NOT_ALLOWED:
		case CIRC_PS_RESOURCE_INSUFF:
			tBuf = "26 Insufficient resources";
			break;

		case CIRC_PS_APN:
			tBuf = "27 Missing or unknown APN";
			break;
		case CIRC_PS_UNKNOWN_PDP_ADD_TYPE:
			tBuf = "28 Unknown PDP address or type";
			break;

		case CIRC_PS_USER_AUTH_FAIL:
		case CIRC_PS_PDP_AUTHEN_FAILURE:
			tBuf = "29 User authentication failed";
			break;
		case CIRC_PS_ACT_REJECT_GGSN:
			tBuf = "30 Activation rejected by GGSN";
			break;
		case CIRC_PS_ACT_REJECT:
		case CIRC_PS_UNSPECIFIED_ERROR:
			tBuf = "31 Activation rejected, unspecified";
			break;

		case CIRC_PS_SRVOPT_NOT_SUPPORTED:
			tBuf = "32 Service option not supported";
			break;

		case CIRC_PS_SRVOPT_NOT_SUBSCRIBED:
			tBuf = "33 Requested service option not subscribed";
			break;

		case CIRC_PS_SRVOPT_TEMP_OUT_OF_ORDER:
			tBuf = "34 Service option temporarily out of order";
			break;
		case CIRC_PS_NSAPI_ALREADY_USED:
			tBuf = "35 NSAPI in use";
			break;
		case CIRC_PS_QOS:
			tBuf = "37 QOS not accepted";
			break;
		case CIRC_PS_NETWORK_FAILURE:
			tBuf = "38 Network failure";
			break;
		case CIRC_PS_REACTIVATION_REQ:
			tBuf = "39 Reactivation required";
			break;
		case CIRC_PS_ESM_SEMANTIC_ERROR_IN_THE_TFT_OPERATION:
			tBuf = "41 Semantic error in the TFT operation";
			break;
		case CIRC_PS_ESM_SYNTACTICAL_ERROR_IN_THE_TFT_OPERATION:
			tBuf = "42 Syntactical error in the TFT operation";
			break;
		case CIRC_PS_ESM_INVALID_EPS_BEARER_IDENTITY:
			tBuf = "43 Invalid EPS bearer identity";
			break;
		case CIRC_PS_ESM_SEMANTIC_ERRORS_IN_PACKET_FILTER:
			tBuf = "44 Semantic error in packet filter";
			break;
		case CIRC_PS_ESM_SYNTACTICAL_ERRORS_IN_PACKET_FILTER:
			tBuf = "45 Syntactical error in packet filter";
			break;
		case CIRC_PS_ESM_EPS_BEARER_CONTEXT_WITHOUT_TFT_ALREADY_ACTIVATED:
			tBuf = "46 EPS bearer context without TFT already activated";
			break;
		case CIRC_PS_ESM_LAST_PDN_DISCONNECTION_NOT_ALLOWED:
			tBuf = "49 Last PDN disconnection not allowed";
			break;
		case CIRC_PS_ESM_PDN_TYPE_IPV4_ONLY_ALLOWED:
			tBuf = "50 Only IPv4 allowed";
			break;
		case CIRC_PS_ESM_PDN_TYPE_IPV6_ONLY_ALLOWED:
			tBuf = "51 Only IPv6 allowed";
			break;
		case CIRC_PS_ESM_PDN_TYPE_SINGLE_IP_ALLOWED:
			tBuf = "52 Only single bearer allowed";
			break;

		case CIRC_PS_INFO_UNAVAILABLE:
			tBuf = "200 Requested information is unavailable";
			break;
		case CIRC_PS_ALREADY_PROCESSING:
			tBuf = "201 The requested command is already being processed";
			break;
		case CIRC_PS_BUSY_WITH_OTHER_JOB:
			tBuf = "202 CP is busy processing another command";
			break;
		case CIRC_PS_INVALID_PARAMETER:
			tBuf = "203 The requested service primitive has invalid parameters";
			break;
		case CIRC_PS_INVALID_REQ:
			tBuf = "204 The requested service primitive can not be handled at current state";
			break;
		case CIRC_PS_PROTOCOL_ERROR_MAX:
			tBuf = "111 Protocol errors";
			break;
		case CIRC_PS_SIM_NOT_READY:
			tBuf = "205 SIM is not ready";
			break;
		case CIRC_PS_ACCESS_DENIED:
			tBuf = "206 Access is denied";
			break;
		case CIRC_PS_INVALID_CID:
			tBuf = "207 Cid is invalid";
			break;
		case CIRC_PS_TFT_PACKET_ERROR_DEFAULT_PDP:
			tBuf = "208 the TFT is invalid for default MT PDP";
			break;
		case CIRC_PS_TFT_PACKET_ERROR_NON_DEFAULT_PDP:
			tBuf = "209 the TFT is invalid for NON default MT PDP";
			break;
		case CIRC_PS_PENDING_SUCCESS:
			tBuf = "210 LTE MO PDP equest completed successfully";
			break;
		case CIRC_PS_RPM_REJECT:
			tBuf = "880 the RPM manager rejected the request";
			break;
		case CIRC_PS_PDP_REJECT_DSDS:
			tBuf = "13056 PDP reject on DSDS";
			break;

		default:
			tBuf = "Generic error";
			break;

	}

	if (CIRC_PS_PROTOCOL_ERROR_MIN <= cause && cause <= CIRC_PS_PROTOCOL_ERROR_MAX)
		sprintf(sBuf, "%u Protocol errors", cause);
	else if (tBuf != NULL)
		strcpy(sBuf, tBuf);
	else
		sprintf(sBuf, "%u Generic error", cause);
	DPRINTF("%s: %s!\n", __FUNCTION__, sBuf);

	return;
}

const CircCodeMap circPsCodeMapping[] =
{
	{CIRC_PS_SUCCESS,    "CIRC_PS_SUCCESS"},
	{CIRC_PS_FAILURE,    "CIRC_PS_FAILURE"},
	{CIRC_PS_ILLEGAL_MS,    "CIRC_PS_ILLEGAL_MS"},
	{CIRC_PS_ILLEGAL_ME,    "CIRC_PS_ILLEGAL_ME"},
	{CIRC_PS_GPRS_SERVICES_NOT_ALLOWED,    "CIRC_PS_GPRS_SERVICES_NOT_ALLOWED"},
	{CIRC_PS_OPER_DETERMINED_BARRING,    "CIRC_PS_OPER_DETERMINED_BARRING"},
	{CIRC_PS_DETACH,    "CIRC_PS_DETACH"},
	{CIRC_PS_PLMN_NOT_ALLOWED,    "CIRC_PS_PLMN_NOT_ALLOWED"},
	{CIRC_PS_LA_NOT_ALLOWED,    "CIRC_PS_LA_NOT_ALLOWED"},
	{CIRC_PS_ROAMING_NOT_ALLOWED,    "CIRC_PS_ROAMING_NOT_ALLOWED"},
	{CIRC_PS_MSC_NOT_REACH,    "CIRC_PS_MSC_NOT_REACH"},
	{CIRC_PS_NW_CONGESTION,    "CIRC_PS_NW_CONGESTION"},
	{CIRC_PS_RESOURCE_INSUFF,    "CIRC_PS_RESOURCE_INSUFF"},
	{CIRC_PS_APN,    "CIRC_PS_APN"},
	{CIRC_PS_UNKNOWN_PDP_ADD_TYPE,    "CIRC_PS_UNKNOWN_PDP_ADD_TYPE"},
	{CIRC_PS_USER_AUTH_FAIL,    "CIRC_PS_USER_AUTH_FAIL"},
	{CIRC_PS_ACT_REJECT_GGSN,    "CIRC_PS_ACT_REJECT_GGSN"},
	{CIRC_PS_ACT_REJECT,    "CIRC_PS_ACT_REJECT"},
	{CIRC_PS_SRVOPT_NOT_SUPPORTED,    "CIRC_PS_SRVOPT_NOT_SUPPORTED"},
	{CIRC_PS_SRVOPT_NOT_SUBSCRIBED,    "CIRC_PS_SRVOPT_NOT_SUBSCRIBED"},
	{CIRC_PS_SRVOPT_TEMP_OUT_OF_ORDER,    "CIRC_PS_SRVOPT_TEMP_OUT_OF_ORDER"},
	{CIRC_PS_NSAPI_ALREADY_USED,    "CIRC_PS_NSAPI_ALREADY_USED"},
	{CIRC_PS_QOS,    "CIRC_PS_QOS"},
	{CIRC_PS_NETWORK_FAILURE,    "CIRC_PS_NETWORK_FAILURE"},
	{CIRC_PS_REACTIVATION_REQ,    "CIRC_PS_REACTIVATION_REQ"},
	{CIRC_PS_ESM_SEMANTIC_ERROR_IN_THE_TFT_OPERATION,    "CIRC_PS_ESM_SEMANTIC_ERROR_IN_THE_TFT_OPERATION"},
	{CIRC_PS_ESM_SYNTACTICAL_ERROR_IN_THE_TFT_OPERATION,    "CIRC_PS_ESM_SYNTACTICAL_ERROR_IN_THE_TFT_OPERATION"},
	{CIRC_PS_ESM_INVALID_EPS_BEARER_IDENTITY,    "CIRC_PS_ESM_INVALID_EPS_BEARER_IDENTITY"},
	{CIRC_PS_ESM_SEMANTIC_ERRORS_IN_PACKET_FILTER,    "CIRC_PS_ESM_SEMANTIC_ERRORS_IN_PACKET_FILTER"},
	{CIRC_PS_ESM_SYNTACTICAL_ERRORS_IN_PACKET_FILTER,    "CIRC_PS_ESM_SYNTACTICAL_ERRORS_IN_PACKET_FILTER"},
	{CIRC_PS_ESM_EPS_BEARER_CONTEXT_WITHOUT_TFT_ALREADY_ACTIVATED,    "CIRC_PS_ESM_EPS_BEARER_CONTEXT_WITHOUT_TFT_ALREADY_ACTIVATED"},
	{CIRC_PS_ESM_LAST_PDN_DISCONNECTION_NOT_ALLOWED,    "CIRC_PS_ESM_LAST_PDN_DISCONNECTION_NOT_ALLOWED"},
	{CIRC_PS_ESM_PDN_TYPE_IPV4_ONLY_ALLOWED,    "CIRC_PS_ESM_PDN_TYPE_IPV4_ONLY_ALLOWED"},
	{CIRC_PS_ESM_PDN_TYPE_IPV6_ONLY_ALLOWED,    "CIRC_PS_ESM_PDN_TYPE_IPV6_ONLY_ALLOWED"},
	{CIRC_PS_ESM_PDN_TYPE_SINGLE_IP_ALLOWED,    "CIRC_PS_ESM_PDN_TYPE_SINGLE_IP_ALLOWED"},
	{CIRC_PS_PROTOCOL_ERROR_MIN,    "CIRC_PS_PROTOCOL_ERROR_MIN"},
	{CIRC_PS_PROTOCOL_ERROR_MAX,    "CIRC_PS_PROTOCOL_ERROR_MAX"},
	{CIRC_PS_UNSPECIFIED_ERROR,    "CIRC_PS_UNSPECIFIED_ERROR"},
	{CIRC_PS_PDP_AUTHEN_FAILURE,    "CIRC_PS_PDP_AUTHEN_FAILURE"},
	{CIRC_PS_INVALID_MS_CLASS,    "CIRC_PS_INVALID_MS_CLASS"},
	{CIRC_PS_INFO_UNAVAILABLE,    "CIRC_PS_INFO_UNAVAILABLE"},
	{CIRC_PS_ALREADY_PROCESSING,    "CIRC_PS_ALREADY_PROCESSING"},
	{CIRC_PS_BUSY_WITH_OTHER_JOB,    "CIRC_PS_BUSY_WITH_OTHER_JOB"},
	{CIRC_PS_INVALID_PARAMETER,    "CIRC_PS_INVALID_PARAMETER"},
	{CIRC_PS_INVALID_REQ,    "CIRC_PS_INVALID_REQ"},
	{CIRC_PS_SIM_NOT_READY,    "CIRC_PS_SIM_NOT_READY"},
	{CIRC_PS_ACCESS_DENIED,    "CIRC_PS_ACCESS_DENIED"},
	{CIRC_PS_INVALID_CID,    "CIRC_PS_INVALID_CID"},
	{CIRC_PS_TFT_PACKET_ERROR_DEFAULT_PDP,    "CIRC_PS_TFT_PACKET_ERROR_DEFAULT_PDP"},
	{CIRC_PS_TFT_PACKET_ERROR_NON_DEFAULT_PDP,    "CIRC_PS_TFT_PACKET_ERROR_NON_DEFAULT_PDP"},
	{CIRC_PS_PENDING_SUCCESS,    "CIRC_PS_PENDING_SUCCESS"},
	{CIRC_PS_RPM_REJECT,    "CIRC_PS_RPM_REJECT"},
	{CIRC_PS_PDP_REJECT_DSDS,    "CIRC_PS_PDP_REJECT_DSDS"}
};

const unsigned int circPsCodeMapping_num = utlNumberOf(circPsCodeMapping);

//Added by Michal Bukai - support for CMEE command (present eroor code\string)
/************************************************************************************
 * Function: checkPSRet
 *
 * Parameters:
 *
 * Returned value:
 *
 * Description:    prints appropriate message based on result code
 */
static void checkPSRet( CiRequestHandle reqHandle, CiPsRc result )
{
	unsigned int i;
	for (i = 0; i < circPsCodeMapping_num; i++)
		if(result == circPsCodeMapping[i].Rc)
			break;
		
	if(i >= circPsCodeMapping_num)
	{
		DBGMSG("[%s] Line(%d) CIRC_PS_CODE = unknown(%d)\n", __FUNCTION__, __LINE__, result);
	}
	else if(result != CIRC_PS_SUCCESS)
	{
		DBGMSG("[%s] Line(%d) CIRC_PS_CODE = %s(%d)\n", __FUNCTION__, __LINE__, circPsCodeMapping[i].RcStr, result);
	}

	switch ( result )
	{
		case CIRC_PS_SUCCESS:               /* Request completed successfully         */
			ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			break;
		case CIRC_PS_ILLEGAL_MS:
			ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_ILLEGAL_MS, NULL);
			break;
		case CIRC_PS_ILLEGAL_ME:
			ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_ILLEGAL_ME, NULL);
			break;
		case CIRC_PS_GPRS_SERVICES_NOT_ALLOWED:
			ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_GPRS_NOT_ALLOWED, NULL);
			break;
		case CIRC_PS_PLMN_NOT_ALLOWED:
			ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_PLMN_NOT_ALLOWED, NULL);
			break;
		case CIRC_PS_LA_NOT_ALLOWED:
			ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_LA_NOT_ALLOWED, NULL);
			break;
		case CIRC_PS_ROAMING_NOT_ALLOWED:
			ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_ROAMING_NOT_ALLOWED, NULL);
			break;
		case CIRC_PS_SRVOPT_NOT_SUPPORTED:
			ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_SERVICE_OP_NOT_SUPPORTED, NULL);
			break;
		case CIRC_PS_SRVOPT_NOT_SUBSCRIBED:
			ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_SERVICE_OP_NOT_SUBSCRIBED, NULL);
			break;
		case CIRC_PS_SRVOPT_TEMP_OUT_OF_ORDER:
			ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_SERVICE_OP_OUT_OF_ORDER, NULL);
			break;
		case CIRC_PS_UNSPECIFIED_ERROR:
			ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNSPECIFIED_GPRS_ERR, NULL);
			break;
		case CIRC_PS_PDP_AUTHEN_FAILURE:
			ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_PDP_AUTH_FAILURE, NULL);
			break;
		case CIRC_PS_INVALID_MS_CLASS:
			ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_MOBILE_CLASS, NULL);
			break;
		default:
			ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
			break;
	}
	return;
}

#ifdef QUECTEL_NETWORK_SUPPORT
static
CiReturnCode setReservedPdpLocked(AtciCurrentSetCntx *cntx, UINT32 atHandle, UINT8 cid, UINT8 status)
{
#ifndef COMPLETE_PXA1826_CI
	CiReturnCode ret = CIRC_FAIL;
#else
	int atp_idx = GET_ATP_INDEX(atHandle);
	CiPrimitiveID primId;

	if (status != 0) {
		if (cntx->owner != -1 && cntx->owner != atp_idx) {
			ERRMSG("setReservedPdpLocked: the cid %d context is already owned by ATPort[%d]\n",
				cid, cntx->owner);
			return ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, NULL);
		}

		if (cntx->definer != -1 && cntx->definer != atp_idx) {
			ERRMSG("setReservedPdpLocked: the cid %d context is already defined by ATPort[%d]\n",
				cid, cntx->definer);
			return ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, NULL);
		}
		primId = CI_PS_PRIM_SET_RESERVED_CID_REQ;
	} else {
		if (cntx->owner != atp_idx) {
			ERRMSG("setReservedPdpLocked: the cid %d context is not owned by ATPort[%d], it is owned by ATPort[%d]\n",
				cid, atp_idx, cntx->owner);
			return ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, NULL);
		}
		primId = PRI_PS_PRIM_SET_UNRESERVED_CID_REQ;
	}
	CiPsPrimSetReservedCidReq *req = utlCalloc(1, sizeof(CiPsPrimSetReservedCidReq));
	if (req == NULL)
		return CIRC_FAIL;
	req->cid = cid;
	req->status = status;
	DBGMSG("[setReservedPdpLocked] req = {cid=%d, status=%d}\n", cid, status);
	CiReturnCode ret = ciRequestExt(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_RESERVED_CID_REQ, MAKE_CI_REQ_HANDLE(atHandle, primId), (void *)req );
	gAtpCtrl[atp_idx].psCurrCid = cid;

	if (status != 0) {
		// Pre-owning to prevent others to own
		cntx->owner = atp_idx;
	}
#endif
	return ret;
}

static inline
CiReturnCode unreservePdpLocked(AtciCurrentSetCntx *cntx, UINT32 atHandle, UINT8 cid)
{
	return setReservedPdpLocked(cntx, atHandle, cid, 0);
}

void clearPdpContextOwner(UINT8 atpIdx)
{
	/*AtciCurrentSetCntx *p_cInfo;
	if (!isTelAtpCurrentForSIM2(atpIdx)) {
		p_cInfo = gCIDList.cInfo;
	} else {
		p_cInfo = gCIDList.cInfo_1;
	}

	UINT8 i;
	for (i = 0; i < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM; i++ ) {
		AtciCurrentSetCntx *cntx = &p_cInfo[i];
		//pthread_mutex_lock(&cntx->mutex);
		if (cntx->definer == (int)atpIdx)
			cntx->definer = -1;
		UINT32 atHandle = MAKE_AT_HANDLE(atpIdx);
		if (cntx->owner == (int)atpIdx)
			unreservePdpLocked(cntx, atHandle, i);
		//pthread_mutex_unlock(&cntx->mutex);
	}*/
}
#endif
void initPSContext( UINT32 atHandle )
{
	int i;
	AtciCurrentSetCntx *p_cInfo;
	TelAtParserID atpIdx = (TelAtParserID)(GET_ATP_INDEX(atHandle));
	int from, to;

#ifndef SINGLE_SIM
		if (atpIdx < TEL_AT_CMD_ATP_36) {
			p_cInfo = gCIDList.cInfo;
			from = TEL_AT_CMD_ATP_0;
			to = TEL_AT_CMD_ATP_36;
		} else {
			/*msichecked by coverity*/
			/*coverity[dead_error_begin]*/
			p_cInfo = gCIDList.cInfo_1;
			from = TEL_AT_CMD_ATP_36;
			to = NUM_OF_TEL_ATP;
		}
#else
		p_cInfo = gCIDList.cInfo;
		from = TEL_AT_CMD_ATP_0;
		to = TEL_AT_CMD_ATP_36;
#endif


	for ( i = from; i < to; i++ )
	{
		gCIDList.currCntx[i].currCid = CI_PS_MAX_CID;
		gCIDList.currCntx[i].reqMsg = NULL;
	}
	for( i = 0; i < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM; i++ )
	{
		p_cInfo[i].bDefined = FALSE;
		p_cInfo[i].cid = CI_PS_MAX_CID;
		p_cInfo[i].connectionType = ATCI_LOCAL;
		p_cInfo[i].pdpAddress[0] = 0;
		p_cInfo[i].pdpType = CI_PS_PDP_NUM_TYPES;
		p_cInfo[i].reqHandle = INVALID_REQ_HANDLE;
	}
}

/* deactive_ps_connection:
    deactive ps connection
    return value:
    0 for successful.  -1 for failure.
*/
int deactive_ps_connection(UINT8 atpIdx)
{
	int ret = 0;
	unsigned char index=0;
	_AtciConnectionType conntype=ATCI_LOCAL;
	UINT32 atHandle=0;
	AtciCurrentSetCntx *p_cInfo;

#ifndef SINGLE_SIM
		if (atpIdx < TEL_AT_CMD_ATP_36) {
			p_cInfo = gCIDList.cInfo;
		} else {
			p_cInfo = gCIDList.cInfo_1;
		}
#else
		p_cInfo = gCIDList.cInfo;
#endif

	if (atpIdx == TEL_MODEM_AT_CMD_ATP)
		conntype = ATCI_REMOTE;
	else
		conntype = ATCI_LOCAL;

	for (index = 0; index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM; index++)
	{
		if ((p_cInfo[index].cid != CI_PS_MAX_CID) &&(p_cInfo[index].reqHandle != INVALID_REQ_HANDLE)
			&&(p_cInfo[index].connectionType == conntype))
		{
			atHandle = GET_AT_HANDLE(p_cInfo[index].reqHandle);
			if (PS_SetGPRSContextActivated (atHandle, p_cInfo[index].cid, FALSE, FALSE) == CIRC_SUCCESS)
			{
				DBGMSG("[%s]: deactivated cid %d successful!\n", __FUNCTION__, p_cInfo[index].cid);
			}
			else
			{
				DBGMSG("[%s]: deactivated cid %d failed!\n", __FUNCTION__, p_cInfo[index].cid);
				ret = -1;
				break;
			}
		}
	}

	return ret;
}

/* Added by Daniel for LTE PC AT command server 20120201, begin */

//AT+CGEQOS=cid only cid is included
CiReturnCode PS_Delete4GEPSContext (UINT32 atHandle, UINT32 dwContextID)
{
	CiReturnCode				   ret = CIRC_FAIL;
	CiPsPrimDeletePdpCtxReq  *deletePdpCtxReq=NULL;

	/* Delete PDP context */
	deletePdpCtxReq = utlCalloc(1, sizeof(*deletePdpCtxReq));
	//[klockwork][issue id: 2270]
	if(deletePdpCtxReq == NULL)
	{
		ASSERT(0);
		return ret;
	}
	deletePdpCtxReq->cid = dwContextID;
	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = dwContextID;
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_DELETE_PDP_CTX_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_DELETE_PDP_CTX_REQ), (void *)deletePdpCtxReq);

	return ret;
}

//AT+CGEQOS?
CiReturnCode PS_Get4GQualityOfServiceList (UINT32 atHandle,UINT32 dwContextID)
{
	CiReturnCode				   ret = CIRC_FAIL;
	CiPsPrimGet4GQosReq            *get4GQosReq=NULL;
	UINT32 reqHandle=0;

	get4GQosReq = utlCalloc(1, sizeof(*get4GQosReq));

	//[klockwork][issue id: 2270]
	ASSERT(get4GQosReq != NULL);
	get4GQosReq->cid = dwContextID;
    gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = dwContextID;

	reqHandle = MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_4G_QOS_REQ);

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_4G_QOS_REQ,
			reqHandle, (void *)get4GQosReq);

	return ret;
}

//AT+CGEQOS=?
CiReturnCode PS_Get4GCapsQos (UINT32 atHandle)
{
	CiReturnCode				   ret = CIRC_FAIL;
	CiPsPrimGet4GQosCapsReq        *get4GQosCapsReq=NULL;
	UINT32 reqHandle=0;

	get4GQosCapsReq = utlCalloc(1, sizeof(*get4GQosCapsReq));


	//[klockwork][issue id: 2297]
	ASSERT(get4GQosCapsReq != NULL);
	reqHandle = MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_4G_QOS_CAPS_REQ);

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_4G_QOS_CAPS_REQ,
			reqHandle, (void *)get4GQosCapsReq);

	return ret;
}

//AT+CGEQOS=
CiReturnCode PS_Set4GQualityOfService (UINT32 atHandle, UINT32 dwContextID, const CiPs4GQosProfile* lp4GQosProfile)
{
	CiReturnCode				   ret = CIRC_FAIL;
	CiPsPrimSet4GQosReq            *set4GQosReq=NULL;

	set4GQosReq = utlCalloc(1, sizeof(*set4GQosReq));

	//[klockwork][issue id: 2294]
	ASSERT(set4GQosReq != NULL);

	set4GQosReq->cid = dwContextID;
	memcpy(&set4GQosReq->qosProfile, lp4GQosProfile, sizeof(CiPs4GQosProfile));
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_4G_QOS_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_4G_QOS_REQ), (void *)set4GQosReq);

	return ret;
}

//AT+CGCONTRDP=?
CiReturnCode PS_ReadDynActPara(UINT32 atHandle)
{
	CiReturnCode				   		ret = CIRC_FAIL;
	CiPsPrimRead4GPdpCtxsActDynParaReq	*read4GPdpCtxActDynParaReq=NULL;

	read4GPdpCtxActDynParaReq = utlCalloc(1, sizeof(*read4GPdpCtxActDynParaReq));

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_READ_4G_PDP_CTXS_ACT_DYN_PARA_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_READ_4G_PDP_CTXS_ACT_DYN_PARA_REQ), (void *)read4GPdpCtxActDynParaReq);
	return ret;
}

//AT+CGCONTRDP=
CiReturnCode PS_ReadDynPara(UINT32 atHandle, UINT32 dwContextID)
{
	CiReturnCode				   		ret = CIRC_FAIL;
	UINT32 query_cid=0;
	CiPsPrimRead4GPdpCtxDynParaReq *read4GPdpCtxDynParaReq=NULL;
	BOOL *pQueryAllCid;
	
#ifndef SINGLE_SIM	
	if (!GET_SIM1_FLAG(atHandle)) {
		pQueryAllCid = &gQueryAllCid;
	} else {
		pQueryAllCid = &gQueryAllCid_1;
	}
#else
	pQueryAllCid = &gQueryAllCid;
#endif

	read4GPdpCtxDynParaReq = utlCalloc(1, sizeof(*read4GPdpCtxDynParaReq));

	//[klockwork][issue id: 2292]
	ASSERT(read4GPdpCtxDynParaReq != NULL);
	if(dwContextID == 0xFF)
	{
		query_cid = 0;
		*pQueryAllCid = TRUE;
	}
	else
	{
		query_cid = dwContextID;
		*pQueryAllCid = FALSE;
	}

	read4GPdpCtxDynParaReq->cid = query_cid;
	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = query_cid;
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_READ_4G_PDP_CTX_DYN_PARA_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_READ_4G_PDP_CTX_DYN_PARA_REQ), (void *)read4GPdpCtxDynParaReq);

	return ret;
}

//AT+CGSCONTRDP=?
CiReturnCode PS_ReadSecDynActPara(UINT32 atHandle)
{
	CiReturnCode				   		ret = CIRC_FAIL;
	CiPsPrimRead4GSecPdpCtxsActDynParaReq	*read4GSecPdpCtxActDynParaReq=NULL;

	read4GSecPdpCtxActDynParaReq = utlCalloc(1, sizeof(*read4GSecPdpCtxActDynParaReq));

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_READ_4G_SEC_PDP_CTXS_ACT_DYN_PARA_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_READ_4G_SEC_PDP_CTXS_ACT_DYN_PARA_REQ), (void *)read4GSecPdpCtxActDynParaReq);

	return ret;
}

//AT+CGSCONTRDP=
CiReturnCode PS_ReadSecDynPara(UINT32 atHandle, UINT32 dwContextID)
{
	CiReturnCode				   		ret = CIRC_FAIL;
	CiPsPrimRead4GSecPdpCtxDynParaReq 		*read4GSecPdpCtxDynParaReq=NULL;

	read4GSecPdpCtxDynParaReq = utlCalloc(1, sizeof(*read4GSecPdpCtxDynParaReq));

	//[klockwork][issue id: 2266]
	ASSERT(read4GSecPdpCtxDynParaReq != NULL);
	read4GSecPdpCtxDynParaReq->cid = dwContextID;
    gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = dwContextID;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_READ_4G_SEC_PDP_CTX_DYN_PARA_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_READ_4G_SEC_PDP_CTX_DYN_PARA_REQ), (void *)read4GSecPdpCtxDynParaReq);

	return ret;
}

//AT+CGTFTRDP=?
CiReturnCode PS_ReadDynActTFT(UINT32 atHandle)
{
	CiReturnCode				   				ret = CIRC_FAIL;
	CiPsPrimRead4GTrafficFlowTempDynParaCapsReq	*read4GTFTDynParaCapsReq=NULL;

	read4GTFTDynParaCapsReq = utlCalloc(1, sizeof(*read4GTFTDynParaCapsReq));

	//[klockwork][issue id: 2290]
	ASSERT(read4GTFTDynParaCapsReq != NULL);

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_CAPS_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_CAPS_REQ), (void *)read4GTFTDynParaCapsReq);

	return ret;
}

//AT+CGTFTRDP=
CiReturnCode PS_ReadDynTFT(UINT32 atHandle, UINT32 dwContextID)
{
	CiReturnCode				   				ret = CIRC_FAIL;
	CiPsPrimRead4GTrafficFlowTempDynParaReq 	*read4GTFTDynParaReq=NULL;

	read4GTFTDynParaReq = utlCalloc(1, sizeof(*read4GTFTDynParaReq));

	//[klockwork][issue id: 2290]
	if(read4GTFTDynParaReq == NULL)
	{
		ASSERT(0);
		return ret;
	}
	read4GTFTDynParaReq->cid = dwContextID;
    gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = dwContextID;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_REQ), (void *)read4GTFTDynParaReq);

	return ret;
}

//AT+CGEQOSRDP=?
CiReturnCode PS_ReadDynActQOS(UINT32 atHandle)
{
	CiReturnCode				   				ret = CIRC_FAIL;
	CiPsPrimGet4GQosCapsReq						*get4GQOSCapsReq=NULL;

	get4GQOSCapsReq = utlCalloc(1, sizeof(*get4GQOSCapsReq));

    ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_READ_4G_QOS_DYN_PARA_CAPS_REQ,
            MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_READ_4G_QOS_DYN_PARA_CAPS_REQ), (void *)get4GQOSCapsReq);

	return ret;
}

//AT+CGEQOSRDP=
CiReturnCode PS_ReadDynQOS(UINT32 atHandle, UINT32 dwContextID)
{
	CiReturnCode				   				ret = CIRC_FAIL;
	CiPsPrimRead4GQosDynParaReq					*read4GQOSDynDynParaReq=NULL;

	read4GQOSDynDynParaReq = utlCalloc(1, sizeof(*read4GQOSDynDynParaReq));

	//[klockwork][issue id: 2268]
	ASSERT(read4GQOSDynDynParaReq != NULL);
	read4GQOSDynDynParaReq->cid = dwContextID;
    gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = dwContextID;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_READ_4G_QOS_DYN_PARA_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_READ_4G_QOS_DYN_PARA_REQ), (void *)read4GQOSDynDynParaReq);

	return ret;
}

//AT+CGEREP?
CiReturnCode PS_Get4GRep(UINT32 atHandle)
{
	CiReturnCode				   				ret = CIRC_FAIL;
	CiPsPrimGet4GEventRepReq					*get4GEventRepReq=NULL;

	get4GEventRepReq = utlCalloc(1, sizeof(*get4GEventRepReq));


	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_4G_EVET_REP_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_4G_EVET_REP_REQ), (void *)get4GEventRepReq);

	return ret;
}

//AT+CGEREP=?
CiReturnCode PS_Get4GCapsRep(UINT32 atHandle)
{
	CiReturnCode				   				ret = CIRC_FAIL;
	CiPsPrimGet4GEventRepCapsReq				*get4GEventRepCapsReq=NULL;

	get4GEventRepCapsReq = utlCalloc(1, sizeof(*get4GEventRepCapsReq));

	//[klockwork][issue id: 2295]
	ASSERT(get4GEventRepCapsReq != NULL);
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_4G_EVET_REP_CAPS_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_4G_EVET_REP_CAPS_REQ), (void *)get4GEventRepCapsReq);

	return ret;
}

//AT+CGEREP=
CiReturnCode PS_Set4GRep(UINT32 atHandle, UINT32 mode, UINT32 bfr)
{
	CiReturnCode				   				ret = CIRC_FAIL;
	CiPsPrimSet4GEventRepReq					*set4GEventRepReq=NULL;

	set4GEventRepReq = utlCalloc(1, sizeof(*set4GEventRepReq));

	//[klockwork][issue id: 2283]
	ASSERT(set4GEventRepReq != NULL);

	set4GEventRepReq->mode = mode;
	set4GEventRepReq->bfr = bfr;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_4G_EVET_REP_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_4G_EVET_REP_REQ), (void *)set4GEventRepReq);

	return ret;
}

//AT+CVMODE?
CiReturnCode PS_GetVoiceMode(UINT32 atHandle, UINT32 dwContextID)
{
	CiReturnCode				   				ret = CIRC_FAIL;
	CiPsPrimGet4GVoiceCallModeReq				*get4GVoiceCallModeReq=NULL;

	get4GVoiceCallModeReq = utlCalloc(1, sizeof(*get4GVoiceCallModeReq));

	//[klockwork][issue id: 2283]
	if(get4GVoiceCallModeReq == NULL)
	{
		ASSERT(0);
		return ret;
	}
	get4GVoiceCallModeReq->cid = dwContextID;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_REQ), (void *)get4GVoiceCallModeReq);
	return ret;
}

//AT+CVMODE=?
CiReturnCode PS_GetCapsVoiceMode(UINT32 atHandle)
{
	CiReturnCode				   				ret = CIRC_FAIL;
	CiPsPrimGet4GVoiceCallModeCapsReq			*get4GVoiceCallModeCapsReq=NULL;

	get4GVoiceCallModeCapsReq = utlCalloc(1, sizeof(*get4GVoiceCallModeCapsReq));

	//[klockwork][issue id: 2271]
	ASSERT(get4GVoiceCallModeCapsReq != NULL);

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_CAPS_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_CAPS_REQ), (void *)get4GVoiceCallModeCapsReq);

	return ret;
}

//AT+CVMODE=
CiReturnCode PS_SetVoiceMode(UINT32 atHandle, UINT32 dwContextID, UINT32 mode)
{
	CiReturnCode				   				ret = CIRC_FAIL;
	CiPsPrimSet4GVoiceCallModeReq				*set4GVoiceCallModeReq=NULL;

	set4GVoiceCallModeReq = utlCalloc(1, sizeof(*set4GVoiceCallModeReq));

	//[klockwork][issue id: 2271]
	if(set4GVoiceCallModeReq == NULL)
	{
		ASSERT(0);
		return ret;
	}

	set4GVoiceCallModeReq->cid = dwContextID;
	set4GVoiceCallModeReq->mode = mode;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_4G_VOICE_CALL_MODE_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_4G_VOICE_CALL_MODE_REQ), (void *)set4GVoiceCallModeReq);


	return ret;
}

//AT+CEMODE?
CiReturnCode PS_GetEpsMode(UINT32 atHandle)
{
	CiReturnCode				   				ret = CIRC_FAIL;
	CiPsPrimGet4GModeReq				        *get4GModeReq=NULL;

	get4GModeReq = utlCalloc(1, sizeof(*get4GModeReq));

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_4G_MODE_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_4G_MODE_REQ), (void *)get4GModeReq);

	return ret;
}

//AT+CEMODE=?
CiReturnCode PS_GetCapsEpsMode(UINT32 atHandle)
{
	CiReturnCode				   				ret = CIRC_FAIL;
	CiPsPrimGet4GModeCapsReq			        *get4GModeCapsReq=NULL;

	get4GModeCapsReq = utlCalloc(1, sizeof(*get4GModeCapsReq));

	//[klockwork][issue id: 2282]
	ASSERT(get4GModeCapsReq != NULL);
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_4G_MODE_CAPS_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_4G_MODE_CAPS_REQ), (void *)get4GModeCapsReq);

	return ret;
}

//AT+CEMODE=
CiReturnCode PS_SetEpsMode(UINT32 atHandle, UINT32 mode)
{
	CiReturnCode				   				ret = CIRC_FAIL;
	CiPsPrimSet4GModeReq				        *set4GModeReq=NULL;

	set4GModeReq = utlCalloc(1, sizeof(*set4GModeReq));
	//[klockwork][issue id: 2282]
	if(set4GModeReq == NULL)
	{
		ASSERT(0);
		return ret;
	}

	set4GModeReq->cipslteOperateMode = mode;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_4G_MODE_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_4G_MODE_REQ), (void *)set4GModeReq);

	return ret;
}

//AT+CGADDR=?
CiReturnCode PS_Get4GCapsAddr(UINT32 atHandle)
{
	CiReturnCode				   				ret = CIRC_FAIL;
	CiPsPrimGetPdpAddrListReq                   *getPdpAddrListReq=NULL;

	getPdpAddrListReq = utlCalloc(1, sizeof(*getPdpAddrListReq));

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_ADDR_LIST_REQ,
			MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_PDP_ADDR_LIST_REQ), (void *)getPdpAddrListReq);

	return ret;
}

//AT+CGADDR=
CiReturnCode PS_Get4GAddr(UINT32 atHandle, UINT32 num, UINT32* pCID)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetPdpCtxReq    *getPdpCtxReq=NULL;
	UINT32 reqHandle = MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_GET_PDP_ADDR_REQ);
	UINT32 i = 0;
	int *pQueryCidAddrCount, *pQueryCidAddrNum;
	int *pCgpaddrCidArray;

#ifndef SINGLE_SIM	
	if (!GET_SIM1_FLAG(reqHandle)) {
		pQueryCidAddrCount = &gQueryCidAddrCount;
		pQueryCidAddrNum = &gQueryCidAddrNum;
		pCgpaddrCidArray = gCgpaddrCidArray;
	} else {
		pQueryCidAddrCount = &gQueryCidAddrCount_1;
		pQueryCidAddrNum = &gQueryCidAddrNum_1;
		pCgpaddrCidArray = gCgpaddrCidArray_1;
	}
#else
	pQueryCidAddrCount = &gQueryCidAddrCount;
	pQueryCidAddrNum = &gQueryCidAddrNum;
	pCgpaddrCidArray = gCgpaddrCidArray;
#endif


	*pQueryCidAddrCount = 0;
	*pQueryCidAddrNum = num;

	for(i = 0; i < num; i++)
	{
		pCgpaddrCidArray[i] = *(pCID + i);
	}

	getPdpCtxReq = utlCalloc(1, sizeof(*getPdpCtxReq));
	if (getPdpCtxReq == NULL)
		return CIRC_FAIL;

	getPdpCtxReq->cid = pCgpaddrCidArray[(*pQueryCidAddrCount)++];
	gCIDList.currCntx[GET_ATP_INDEX(atHandle)].currCid = getPdpCtxReq->cid;
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ, reqHandle, (void *)getPdpCtxReq );

	return ret;
}

#ifdef VOLTE_ENABLE
//AT+CIREG?
CiReturnCode PS_GetImsRegStatus(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetImsRegInfoReq *getImsRegStatusReq = NULL;
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem

#ifdef QUECTEL_NETWORK_SUPPORT
	ret = ciRequestExt( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_IMS_REG_INFO_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_IMS_REG_INFO_REQ), (void *)getImsRegStatusReq);
#else
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_IMS_REG_INFO_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_IMS_REG_INFO_REQ), (void *)getImsRegStatusReq);
#endif
}//MiniSystem
else
{
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_IMS_REG_INFO_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_IMS_REG_INFO_REQ), (void *)getImsRegStatusReq);

}
#endif /*MIN_SYS*/
	return ret;
}

//AT+CIREG=
CiReturnCode PS_SetImsRegOption(UINT32 atHandle, INT32 regOption)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetImsRegInfoIndReq *setImsRegInfoIndReq=NULL;

	setImsRegInfoIndReq = utlCalloc(1, sizeof(CiPsPrimSetImsRegInfoIndReq));
	if (setImsRegInfoIndReq == NULL)
		return CIRC_FAIL;
	setImsRegInfoIndReq->reportState = (UINT8)regOption;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_IMS_REG_INFO_IND_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_IMS_REG_INFO_IND_REQ), (void *)setImsRegInfoIndReq);

	return ret;
}
#endif

#ifdef LWIP_IPNETBUF_SUPPORT
//AT$MYSYSINFO?
CiReturnCode PS_Get4GSysInfoRegStatus(UINT32 atHandle)
{
    CiReturnCode    ret = CIRC_FAIL;
    CiPsPrimGet4GNwRegStatusReq *get4GRegStatusReq;

    get4GRegStatusReq = utlCalloc(1, sizeof(CiPsPrimGet4GNwRegStatusReq));
	if (get4GRegStatusReq == NULL)
		return CIRC_FAIL;

    ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_4G_NW_REG_STATUS_REQ,
        MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_SYSINFO_NW_REG_STATUS_REQ), (void *)get4GRegStatusReq);
    //utlFree(get4GRegStatusReq);

    return ret;
}
#endif
//AT+CEREG?
CiReturnCode PS_Get4GRegStatus(UINT32 atHandle)
{
    CiReturnCode    ret = CIRC_FAIL;
    CiPsPrimGet4GNwRegStatusReq *get4GRegStatusReq=NULL;

    get4GRegStatusReq = utlCalloc(1, sizeof(CiPsPrimGet4GNwRegStatusReq));
    ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_4G_NW_REG_STATUS_REQ,
        MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_4G_NW_REG_STATUS_REQ), (void *)get4GRegStatusReq);

    return ret;
}

//AT+CEREG=
CiReturnCode PS_Set4GRegOption(UINT32 atHandle, INT32 regOption)
{
    CiReturnCode    ret = CIRC_FAIL;
    CiPsPrimEnable4GNwRegIndReq *enable4GNwRegIndReq=NULL;
	int *pPSRequestedRegOption = NULL;
    int *pCurrRegOption = NULL;
	UINT32 at_Handle = GET_AT_HANDLE( atHandle );
	UINT32 sAtpIndex = GET_ATP_INDEX( at_Handle );    
    int idx = isIMSChannel(sAtpIndex); 

#ifndef SINGLE_SIM	
	if (!GET_SIM1_FLAG(atHandle)) {
		pCurrRegOption = &g4gCurrentPSRegOption[idx];
		pPSRequestedRegOption = &g4gPSRequestedRegOption[idx];
	} else {
		pCurrRegOption = &g4gCurrentPSRegOption_1[idx];
		pPSRequestedRegOption = &g4gPSRequestedRegOption_1[idx];
	}
#else
	pCurrRegOption = &g4gCurrentPSRegOption[idx];
	pPSRequestedRegOption = &g4gPSRequestedRegOption[idx];
#endif

    *pPSRequestedRegOption = (CiPs4GNwRegIndFlag)regOption;    
    save4GOption(GET_SIM1_FLAG(atHandle), idx, REQUEST_OPTION_FLAG, regOption);  

    if(!isIMSChannel(sAtpIndex) && ( regOption < CI_PS_NW_REG_IND_ENABLE_DETAIL))
    {
        *pCurrRegOption = (CiPs4GNwRegIndFlag)regOption;         
        //CPUartLogPrintf("%s 1:  set pPSRequestedRegOption as %d", __FUNCTION__, regOption);         
        save4GOption(GET_SIM1_FLAG(atHandle), idx, CURRENT_OPTION_FLAG, regOption);         
        ret = ATRESP( atHandle,ATCI_RESULT_CODE_OK,0,NULL);
        return ret;
    }
    
    enable4GNwRegIndReq = utlCalloc(1, sizeof(CiPsPrimEnable4GNwRegIndReq));

	//[klockwork][issue id: 2267]
	ASSERT(enable4GNwRegIndReq != NULL);
    enable4GNwRegIndReq->flag = (CiPs4GNwRegIndFlag)regOption;
    ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_ENABLE_4G_NW_REG_IND_REQ,
        MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_ENABLE_4G_NW_REG_IND_REQ), (void *)enable4GNwRegIndReq);

    return ret;
}
//AT*PSDC=
CiReturnCode PS_SetPsdc_req(UINT32 atHandle, INT32 domainOption)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetPsServiceDomainReq *setPsdomainReq=NULL;

	setPsdomainReq = utlCalloc(1, sizeof(CiPsPrimSetPsServiceDomainReq));
	if (setPsdomainReq == NULL)
		return CIRC_FAIL;
	setPsdomainReq->psServiceEnable= (UINT8)domainOption;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_PS_SERVICE_DOMAIN_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_PS_SERVICE_DOMAIN_REQ), (void *)setPsdomainReq);

	return ret;
}
//AT*PSDC?
CiReturnCode PS_GetPsdc_req(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetPsServiceDomainReq *GetPsdomainReq=NULL;

	GetPsdomainReq = utlCalloc(1, sizeof(CiPsPrimGetPsServiceDomainReq));
	if (GetPsdomainReq == NULL)
		return CIRC_FAIL;


	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PS_SERVICE_DOMAIN_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_PS_SERVICE_DOMAIN_REQ), (void *)GetPsdomainReq);

	return ret;
}
#ifndef LTEONLY_THIN

//AT+CGCLASS?
CiReturnCode PS_GetGsmGprsClass(UINT32 atHandle)
{
    CiReturnCode        ret = CIRC_FAIL;
    CiPsPrimGetGsmGprsClassReq *getGsmGprsClassReq=NULL;

    getGsmGprsClassReq = utlCalloc(1, sizeof(CiPsPrimGetGsmGprsClassReq));

    ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_GSMGPRS_CLASS_REQ,
            MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_GSMGPRS_CLASS_REQ), (void *)getGsmGprsClassReq);
    //utlFree(getGsmGprsClassReq);

    return ret;
}

//AT+CGCLASS=?
CiReturnCode PS_GetGsmGprsClasses(UINT32 atHandle)
{
    CiReturnCode        ret = CIRC_FAIL;
    CiPsPrimGetGsmGprsClassesReq *getGsmGprsClassesReq=NULL;

    getGsmGprsClassesReq = utlCalloc(1, sizeof(CiPsPrimGetGsmGprsClassesReq));

    ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_GSMGPRS_CLASSES_REQ,
            MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_GSMGPRS_CLASSES_REQ), (void *)getGsmGprsClassesReq);

    return ret;
}
#endif
//get the +cgcontrdp cnf
/*Fixed unused coverity[missing_return]*/
static void processgetcgdcontrdpConf( UINT32 reqHandle,const void *paras)
{
}

//AT+CGCLASS=
CiReturnCode PS_SetGsmGprsClass(UINT32 atHandle, char *classString, UINT16 length)
{
    CiReturnCode    ret = CIRC_FAIL;
    CiPsPrimSetGsmGprsClassReq *setGsmGprsClassReq=NULL;

    setGsmGprsClassReq = utlCalloc(1, sizeof(CiPsPrimSetGsmGprsClassReq));

	//[klockwork][issue id: 2273]
	ASSERT(setGsmGprsClassReq != NULL);
    if(memcmp(classString,"A",length) == 0)
    {
        setGsmGprsClassReq->classType = (CiPsGsmGprsClass)0;
    }
    else if(memcmp(classString,"B",length) == 0)
    {
        setGsmGprsClassReq->classType = (CiPsGsmGprsClass)1;
    }
    else if(memcmp(classString,"CG",length) == 0)
    {
        setGsmGprsClassReq->classType = (CiPsGsmGprsClass)2;
    }
    else if(memcmp(classString,"CC",length) == 0)
    {
        setGsmGprsClassReq->classType = (CiPsGsmGprsClass)3;
    }
    else
    {
        setGsmGprsClassReq->classType = (CiPsGsmGprsClass)0;
    }
    ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_GSMGPRS_CLASS_REQ,
        MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_GSMGPRS_CLASS_REQ), (void *)setGsmGprsClassReq);

    return ret;
}

#ifdef VOLTE_ENABLE
//AT+CMMIVT?
CiReturnCode PS_GetMmImsVoiceTermination(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetMmImsVoiceTerminationReq *getMmImsVoiceTerminationReq = NULL;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_MM_IMS_VOICE_TERMINATION_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_MM_IMS_VOICE_TERMINATION_REQ), (void *)getMmImsVoiceTerminationReq);

	return ret;
}

//AT+CMMIVT=
CiReturnCode PS_SetMmImsVoiceTermination(UINT32 atHandle, UINT8 setting)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetMmImsVoiceTerminationReq *setMmImsVoiceTerminationReq;
	setMmImsVoiceTerminationReq = utlCalloc(1, sizeof(CiPsPrimSetMmImsVoiceTerminationReq));
	if (setMmImsVoiceTerminationReq != NULL)
	{
		setMmImsVoiceTerminationReq->setting = setting;
		ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_MM_IMS_VOICE_TERMINATION_REQ,
				MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_MM_IMS_VOICE_TERMINATION_REQ), (void *)setMmImsVoiceTerminationReq);
	}

	return ret;
}
#endif

#ifdef LWIP_IPNETBUF_SUPPORT
#ifdef VOLTE_ENABLE

//AT*CIIND=
CiReturnCode PS_NotifyImsRegStateToCp(UINT32 atHandle, UINT8 state)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetImsRegStateReq *setImsRegStateReq = NULL;
	setImsRegStateReq = utlCalloc(1, sizeof(CiPsPrimSetImsRegStateReq));
	if (setImsRegStateReq == NULL)
		return ret;

	setImsRegStateReq->state = state;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_IMS_REG_STATE_REQ,
		MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_SET_IMS_REG_STATE_REQ), (void*)setImsRegStateReq);
	return ret;
}

//AT+CAVIMS?
CiReturnCode PS_GetImsVoiceCallAvailability(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetImsVoiceCallAvailabilityReq *getImsVoiceCallAvailabilityReq = NULL;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_IMS_VOICE_CALL_AVAILABILITY_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_IMS_VOICE_CALL_AVAILABILITY_REQ), (void *)getImsVoiceCallAvailabilityReq);

	return ret;
}

//AT+CAVIMS=
CiReturnCode PS_SetImsVoiceCallAvailability(UINT32 atHandle, UINT8 state)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetImsVoiceCallAvailabilityReq *setImsVoiceCallAvailabilityReq;
	setImsVoiceCallAvailabilityReq = utlCalloc(1, sizeof(CiPsPrimSetImsVoiceCallAvailabilityReq));
	if (setImsVoiceCallAvailabilityReq != NULL)
	{
		setImsVoiceCallAvailabilityReq->state = state;
		ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_IMS_VOICE_CALL_AVAILABILITY_REQ,
				MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_IMS_VOICE_CALL_AVAILABILITY_REQ), (void *)setImsVoiceCallAvailabilityReq);
	}

	return ret;
}

//AT+CASIMS?
CiReturnCode PS_GetImsSmsAvailability(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetImsSmsAvailabilityReq *getImsSmsAvailabilityReq = NULL;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_IMS_SMS_AVAILABILITY_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_IMS_SMS_AVAILABILITY_REQ), (void *)getImsSmsAvailabilityReq);

	return ret;
}

//AT+CASIMS=
CiReturnCode PS_SetImsSmsAvailability(UINT32 atHandle, UINT8 state)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetImsSmsAvailabilityReq *setImsSmsAvailabilityReq;
	setImsSmsAvailabilityReq = utlCalloc(1, sizeof(CiPsPrimSetImsSmsAvailabilityReq));
	if (setImsSmsAvailabilityReq != NULL)
	{
		setImsSmsAvailabilityReq->state = state;
		ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_IMS_SMS_AVAILABILITY_REQ,
				MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_IMS_SMS_AVAILABILITY_REQ), (void *)setImsSmsAvailabilityReq);
	}

	return ret;
}

BOOL pocFlag = FALSE;

//at*IMSSRV=<imsSrvType>,<imsSrvStatus>,<srvFailCause>
CiReturnCode PS_SetImsSrv(UINT32 atHandle,  UINT8 imsSrvType, UINT8 imsSrvStatus, UINT8 srvFailCause)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetImsServiceStatusReq *setImsSrvReq = NULL;
	setImsSrvReq = utlCalloc(1, sizeof(CiPsPrimSetImsServiceStatusReq));
	if (setImsSrvReq == NULL)
		return CIRC_FAIL;

	setImsSrvReq->imsSrvType = imsSrvType;
	setImsSrvReq->imsSrvStatus = imsSrvStatus;
	setImsSrvReq->srvFailCause = srvFailCause;

    if((imsSrvType == 7) || (imsSrvType == 8))
        pocFlag = TRUE;
    
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_IMS_SERVICE_STATUS_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_IMS_SERVICE_STATUS_REQ), (void *)setImsSrvReq );

	return ret;
}
#endif
#endif


//AT+CPSMS=
CiReturnCode PS_SetPsmConfig(UINT32 atHandle,  CiPsPrimSetPsmConfigReq *req)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetPsmConfigReq *setPsmConfigReq = NULL;
	setPsmConfigReq = utlCalloc(1, sizeof(CiPsPrimSetPsmConfigReq));
	if (setPsmConfigReq == NULL)
		return CIRC_FAIL;

	memcpy(setPsmConfigReq, req, sizeof(CiPsPrimSetPsmConfigReq));

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_PSM_CONFIG_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_PSM_CONFIG_REQ), (void *)setPsmConfigReq );

	return ret;
}

//AT+CPSMS?
CiReturnCode PS_GetPsmConfig(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetPsmConfigReq *getPsmConfigReq = NULL;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PSM_CONFIG_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_PSM_CONFIG_REQ), (void *)getPsmConfigReq);

	return ret;
}

//AT+CEDRXS=
CiReturnCode PS_SetEdrxConfig(UINT32 atHandle,  CiPsPrimSetEdrxConfigReq *req)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetEdrxConfigReq *setEdrxConfigReq = NULL;
	setEdrxConfigReq = utlCalloc(1, sizeof(CiPsPrimSetEdrxConfigReq));
	if (setEdrxConfigReq == NULL)
		return CIRC_FAIL;

	memcpy(setEdrxConfigReq, req, sizeof(CiPsPrimSetEdrxConfigReq));

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_EDRX_CONFIG_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_EDRX_CONFIG_REQ), (void *)setEdrxConfigReq );

	return ret;
}

//AT+CEDRXS?
CiReturnCode PS_GetEdrxConfig(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetEdrxConfigReq *getEdrxConfigReq = NULL;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_EDRX_CONFIG_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_EDRX_CONFIG_REQ), (void *)getEdrxConfigReq);

	return ret;
}

//AT+CEDRXRDP?
CiReturnCode PS_ReadEdrxDynParaReq(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimReadEdrxDynParaReq *readEdrxDynParaReq = NULL;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_READ_EDRX_DYN_PARA_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_READ_EDRX_DYN_PARA_REQ), (void *)readEdrxDynParaReq);

	return ret;
}

//AT+CCIOTOPT=
CiReturnCode PS_SetCiotConfigReq(UINT32 atHandle, UINT8 mode, UINT8 supportedUeOpt, UINT8 preferredUeOpt)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetCiotConfigReq *setCiotConfigReq = NULL;
	setCiotConfigReq = utlCalloc(1, sizeof(CiPsPrimSetCiotConfigReq));
	if (setCiotConfigReq == NULL)
		return CIRC_FAIL;

	setCiotConfigReq->option = mode;
	setCiotConfigReq->supportedUeOpt = supportedUeOpt;
	setCiotConfigReq->preferUeOpt = preferredUeOpt;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_CIOT_CONFIG_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_CIOT_CONFIG_REQ), (void *)setCiotConfigReq );

	return ret;
}

//AT+CCIOTOPT?
CiReturnCode PS_GetCiotConfigReq(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetCiotConfigReq *getCiotConfigReq = NULL;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_CIOT_CONFIG_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_CIOT_CONFIG_REQ), (void *)getCiotConfigReq);

	return ret;
}

//AT+CSCON=
CiReturnCode PS_SetConfigSignallingConnectionOptionReq(UINT32 atHandle, UINT8 option)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimConfigSignallingConnectionReq *configSignallingConnectionReq = NULL;
	UINT8 *pCurrSignalConnetcionOption;

#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(atHandle)) {
		pCurrSignalConnetcionOption = &gCurrSignalConnetcionOption;
	} else {
		pCurrSignalConnetcionOption = &gCurrSignalConnetcionOption_1;
	}
#else
	pCurrSignalConnetcionOption = &gCurrSignalConnetcionOption;
#endif


	configSignallingConnectionReq = utlCalloc(1, sizeof(CiPsPrimConfigSignallingConnectionReq));
	if (configSignallingConnectionReq == NULL)
		return CIRC_FAIL;

	configSignallingConnectionReq->option = option;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_CONFIG_SIGNALLING_CONNECTION_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_CONFIG_SIGNALLING_CONNECTION_REQ), (void *)configSignallingConnectionReq);


    if(ret == CIRC_SUCCESS)
    {
        *pCurrSignalConnetcionOption = (CiPsSignallingConnectionOpt)option;
    }
	return ret;
}

//AT+CSCON?
CiReturnCode PS_GetSignallingConnectionStausReq(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetSignallingConnectionStatusReq *getSignallingConnectionStatusReq = NULL;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_SIGNALLING_CONNECTION_STATUS_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_SIGNALLING_CONNECTION_STATUS_REQ), (void *)getSignallingConnectionStatusReq);

	return ret;
}

//AT+CIPCA=
CiReturnCode PS_SetInitialPdpActivationOptReq(UINT32 atHandle, UINT8 option, UINT8 attachWithoutPdn)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetInitialPdpActivationOptReq *setInitialPdpActivationOptReq = NULL;


	setInitialPdpActivationOptReq = utlCalloc(1, sizeof(CiPsPrimSetInitialPdpActivationOptReq));
	if (setInitialPdpActivationOptReq == NULL)
		return CIRC_FAIL;

	setInitialPdpActivationOptReq->option = option;
	setInitialPdpActivationOptReq->attachWithoutPdn = attachWithoutPdn;
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_INITIAL_PDP_ACTIVATION_OPT_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_INITIAL_PDP_ACTIVATION_OPT_REQ), (void *)setInitialPdpActivationOptReq);

	return ret;
}

//AT+CIPCA?
CiReturnCode PS_GetInitialPdpActivationOptReq(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetInitialPdpActivationOptReq *getInitialPdpActivationOptReq = NULL;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_INITIAL_PDP_ACTIVATION_OPT_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_INITIAL_PDP_ACTIVATION_OPT_REQ), (void *)getInitialPdpActivationOptReq);

	return ret;
}

//AT+CABTSR=
CiReturnCode PS_SetApnBackoffTimerStatusReq(UINT32 atHandle, UINT8 option)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimSetApnBackoffTimerStatusReq *setApnBackoffTimerStatusReq = NULL;


	setApnBackoffTimerStatusReq = utlCalloc(1, sizeof(CiPsPrimSetApnBackoffTimerStatusReq));
	if (setApnBackoffTimerStatusReq == NULL)
		return CIRC_FAIL;

	setApnBackoffTimerStatusReq->option = option;
	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_APN_BACKOFF_TIMER_STATUS_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_SET_APN_BACKOFF_TIMER_STATUS_REQ), (void *)setApnBackoffTimerStatusReq);

	return ret;
}

//AT+CABTSR?
CiReturnCode PS_GetApnBackoffTimerStatusReq(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetApnBackoffTimerStatusReq *getApnBackoffTimerStatusReq = NULL;

	ret = ciRequest(gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_APN_BACKOFF_TIMER_STATUS_REQ,
		MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_APN_BACKOFF_TIMER_STATUS_REQ), (void *)getApnBackoffTimerStatusReq);

	return ret;
}

//AT+CABTRDP?
CiReturnCode PS_ReadApnBackoffTimerDynPara(UINT32 atHandle, CiPsPrimReadApnBackoffTimerDynParaReq *req)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimReadApnBackoffTimerDynParaReq *readApnBackoffTimerDynParaReq = NULL;
	readApnBackoffTimerDynParaReq = utlCalloc(1, sizeof(CiPsPrimReadApnBackoffTimerDynParaReq));
	if (readApnBackoffTimerDynParaReq == NULL)
		return CIRC_FAIL;

	memcpy(readApnBackoffTimerDynParaReq, req, sizeof(CiPsPrimReadApnBackoffTimerDynParaReq));

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_READ_APN_BACKOFF_TIMER_DYN_PARA_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_READ_APN_BACKOFF_TIMER_DYN_PARA_REQ), (void *)readApnBackoffTimerDynParaReq );

	return ret;
}

//AT+CGAPNRC=
CiReturnCode PS_GetApnRateControl(UINT32 atHandle, CiPsPrimGetApnRateControlReq *req)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetApnRateControlReq *getApnRateControlReq = NULL;
	getApnRateControlReq = utlCalloc(1, sizeof(CiPsPrimGetApnRateControlReq));
	if (getApnRateControlReq == NULL)
		return CIRC_FAIL;

	memcpy(getApnRateControlReq, req, sizeof(CiPsPrimGetApnRateControlReq));

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_APN_RATE_CONTROL_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle,CI_PS_PRIM_GET_APN_RATE_CONTROL_REQ), (void *)getApnRateControlReq );

	return ret;
}

//AT+CGAPNRC=?
CiReturnCode PS_GetApnRateControlActCid(UINT32 atHandle)
{
	CiReturnCode ret = CIRC_FAIL;
	CiPsPrimGetApnRateControlReq *getApnRateControlReq = NULL;
	getApnRateControlReq = utlCalloc(1, sizeof(CiPsPrimGetApnRateControlReq));
	if (getApnRateControlReq == NULL)
		return CIRC_FAIL;


	getApnRateControlReq->cidPresent = FALSE;

	ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_APN_RATE_CONTROL_REQ,
			 MAKE_CI_REQ_HANDLE(atHandle,PRI_PS_PRIM_GET_APN_RATE_CONTROL_ACT_CID), (void *)getApnRateControlReq );

	return ret;
}

/* Added by Daniel for LTE PC AT command server 20120201, end */

int inCid = 0;
int inIPAddress = 0;
int inDefaultGateway = 0;
int inSubnetMask = 0xffffff00;
int inPrimaryDNS = 0;
int inSecondaryDNS = 0;

void parseAddr(CiPsPdpCtxInfo *pCtx)
{
	if (pCtx != NULL)
	{
		//reconstruct IP addr in network order
		if(( pCtx->pdpCtx.ipv4Addr.addrType!=0)||( pCtx->pdpCtx.ipv6Addr.addrType!=0))//mask mengliang
		{
			UINT8 *ipaddr;
			UINT8 oct;

			inIPAddress = 0;
			if( pCtx->pdpCtx.ipv4Addr.addrType!=0)
			{
				ipaddr = pCtx->pdpCtx.ipv4Addr.valData;
			}
			else
			{
				ipaddr = pCtx->pdpCtx.ipv6Addr.valData;
			}

			inIPAddress |= (*ipaddr << 24);
			ipaddr++;
			inIPAddress |= (*ipaddr << 16);
			ipaddr++;
			inIPAddress |= (*ipaddr << 8);
			ipaddr++;
			inIPAddress |= *ipaddr;


			//SCR2113833: data_abort during 2 PDP contexts live testing in UK
			inDefaultGateway = inIPAddress ^ 0xFF;

			// calculate mask according to ip address
			oct = (UINT8)((inIPAddress & 0xFF000000) >> 24);
			if (oct >= 192)
			{
				inSubnetMask = 0xFFFFFF00;       // 255.255.255.0
			}
			else if (oct >= 128)
			{
				inSubnetMask = 0xFFFF0000;       // 255.255.0.0
			}
			else
			{
				inSubnetMask = 0xFF000000;       // 255.0.0.0
			}
		}

		// parse the following info according to IPCP and PPP
		if(pCtx->pdpCtx.pdParasPresent)
		{
			UINT8 *buf, *packetEnd, *ipcpEnd;

			buf = (UINT8*)pCtx->pdpCtx.pdParas.valStr;
			packetEnd=buf+pCtx->pdpCtx.pdParas.len;
			while (buf < packetEnd)
			{
				unsigned short type=buf[0]<<8 | buf[1];
				UINT8  len=buf[2]; //  this length field includes only what follows it
				switch (type)
				{
					// we are currently interested only on one type
					// but will specify some more for fute
					case 0x23C0:
						// PAP - not used  - ignore
						buf+=len+3;
						break;
					case 0x8021:
						// IPCP option for IP configuration - we are looking for DNS parameters.
						// it seem that this option may appear more than once!
						ipcpEnd = buf + len + 3;
						buf += 3;
						// 3gpp TS29.061 conf-nak or conf-ack both can be here and has DNS infomation
						if (*buf == 0x02 || *buf == 0x03)
						{
							// Config-Nak found, advance to IPCP data start
							buf += 4;
							// parse any configuration
							while(buf < ipcpEnd)
							{
								if (*buf == 129)
								{
									// Primary DNS address
									buf += 2;
	//								diagmPrintf(0, "Primary DNS %d.%d.%d.%d\n",buf[0],buf[1],buf[2],buf[3]);
									inPrimaryDNS = ((buf[0]<<24) | (buf[1]<<16) | (buf[2]<<8) | buf[3]);
									buf += 4;
									continue;
								}

								if (*buf == 131)
								{
									// Secondary DNS address
									buf += 2;
									diagmPrintf(0, "Secondary DNS %d.%d.%d.%d\r\n",buf[0],buf[1],buf[2],buf[3]);
									inSecondaryDNS = ((buf[0]<<24) | (buf[1]<<16) | (buf[2]<<8) | buf[3]);
									buf += 4;
									continue;
								}
								// buf[0] includes the ipcp type, buf[1] the length of this field includes the whole TLV
								buf+=buf[1];
							}
						}
						else
						{
							buf+=len;
						}
						break;
					default:
						buf+=len+3;
						break;
				}
			}
		}
	}
}
/*new IP parser interface for usbnet*/
typedef struct IpArray_TAG{
	int IPAddress;
	int DefaultGateway;
	int SubnetMask;
	int PrimaryDNS;
	int SecondaryDNS;
	int valid;
}IpArray;
IpArray PDPCtxIpInfo[8]={
{0,0,0xffffff00,0,0,0},
{0,0,0xffffff00,0,0,0},
{0,0,0xffffff00,0,0,0},
{0,0,0xffffff00,0,0,0},
{0,0,0xffffff00,0,0,0},
{0,0,0xffffff00,0,0,0},
{0,0,0xffffff00,0,0,0},
{0,0,0xffffff00,0,0,0}
};
void parseAddrByCid(unsigned int cid,CiPsPdpCtxInfo *pCtx)
{
	if(cid>7) return;

	if (pCtx != NULL)
	{
		if((pCtx->actState==0)||(pCtx->pdpCtx.ipv6Addr.addrType!=0))
		{
			DIAG_FILTER(PCAC, ATCMDSrv, ParseIPAddrbyCidInvalid, DIAG_INFORMATION)
			diagPrintf("cid %d,actstate %d,IPv6flag %d",cid, pCtx->actState,pCtx->pdpCtx.ipv6Addr.addrType);
			memset(&PDPCtxIpInfo[cid],0x00,sizeof(IpArray));
			return;
		}

		//reconstruct IP addr in network order
		if( pCtx->pdpCtx.ipv4Addr.addrType!=0)//mask mengliang
		{
			UINT8 *ipaddr;
			UINT8 oct;

			PDPCtxIpInfo[cid].IPAddress = 0;
			ipaddr = pCtx->pdpCtx.ipv4Addr.valData;
			PDPCtxIpInfo[cid].IPAddress |= (*ipaddr << 24);
			ipaddr++;
			PDPCtxIpInfo[cid].IPAddress |= (*ipaddr << 16);
			ipaddr++;
			PDPCtxIpInfo[cid].IPAddress |= (*ipaddr << 8);
			ipaddr++;
			PDPCtxIpInfo[cid].IPAddress |= *ipaddr;

			PDPCtxIpInfo[cid].DefaultGateway = PDPCtxIpInfo[cid].IPAddress ^ 0xFF;

			// calculate mask according to ip address
			oct = (UINT8)((PDPCtxIpInfo[cid].IPAddress & 0xFF000000) >> 24);
			if (oct >= 192)
			{
				PDPCtxIpInfo[cid].SubnetMask = 0xFFFFFF00;       // 255.255.255.0
			}
			else if (oct >= 128)
			{
				PDPCtxIpInfo[cid].SubnetMask = 0xFFFF0000;       // 255.255.0.0
			}
			else
			{
				PDPCtxIpInfo[cid].SubnetMask = 0xFF000000;       // 255.0.0.0
			}
		}else{
			memset(&PDPCtxIpInfo[cid],0x00,sizeof(IpArray));
			return;
		}

		PDPCtxIpInfo[cid].PrimaryDNS=0;
		PDPCtxIpInfo[cid].SecondaryDNS=0;

		// parse the following info according to IPCP and PPP
		if(pCtx->pdpCtx.pdParasPresent)
		{
			UINT8 *buf, *packetEnd, *ipcpEnd;

			buf = (UINT8*)pCtx->pdpCtx.pdParas.valStr;
			packetEnd=buf+pCtx->pdpCtx.pdParas.len;
			while (buf < packetEnd)
			{
				unsigned short type=buf[0]<<8 | buf[1];
				UINT8  len=buf[2]; //  this length field includes only what follows it
				switch (type)
				{
					// we are currently interested only on one type
					// but will specify some more for fute
					case 0x23C0:
						// PAP - not used  - ignore
						buf+=len+3;
						break;
					case 0x8021:
						// IPCP option for IP configuration - we are looking for DNS parameters.
						// it seem that this option may appear more than once!
						ipcpEnd = buf + len + 3;
						buf += 3;
						// 3gpp TS29.061 conf-nak or conf-ack both can be here and has DNS infomation
						if (*buf == 0x02 || *buf == 0x03)
						{
							// Config-Nak found, advance to IPCP data start
							buf += 4;
							// parse any configuration
							while(buf < ipcpEnd)
							{
								if (*buf == 129)
								{
									// Primary DNS address
									buf += 2;
	//								diagmPrintf(0, "Primary DNS %d.%d.%d.%d\n",buf[0],buf[1],buf[2],buf[3]);
									PDPCtxIpInfo[cid].PrimaryDNS = ((buf[0]<<24) | (buf[1]<<16) | (buf[2]<<8) | buf[3]);
									buf += 4;
									continue;
								}

								if (*buf == 131)
								{
									// Secondary DNS address
									buf += 2;
									diagmPrintf(0, "Secondary DNS %d.%d.%d.%d\r\n",buf[0],buf[1],buf[2],buf[3]);
									PDPCtxIpInfo[cid].SecondaryDNS = ((buf[0]<<24) | (buf[1]<<16) | (buf[2]<<8) | buf[3]);
									buf += 4;
									continue;
								}
								// buf[0] includes the ipcp type, buf[1] the length of this field includes the whole TLV
								buf+=buf[1];
							}
						}
						else
						{
							buf+=len;
						}
						break;
					default:
						buf+=len+3;
						break;
				}
			}
		}

		PDPCtxIpInfo[cid].valid=1;
	}else{
		memset(&PDPCtxIpInfo[cid],0x00,sizeof(IpArray));
		return;
	}
}

static BOOL convertDecIntToBinStr(UINT8 inValue, UINT8 *outStr,UINT8 maxLength)
{
	UINT8 i=0,j=0,index=0,outLen;
	UINT8 *pTmp;
	UINT8 tmpBuf[32]= {0};
	UINT32 input = inValue;

	pTmp = tmpBuf;
	while(input)
	{
		pTmp[i++] = input%2+'0';
		input = input/2;
	}
	pTmp[i]='\0';

	outLen = MAX(maxLength,i);

	pTmp = outStr;
	for(j=0; j<(outLen-i); j++)
	{
		pTmp[j] = '0';
	}

	for(index=0; j<outLen && index<i; j++,index++)
	{
		pTmp[j] = tmpBuf[i-index-1];
	}
	pTmp[j]='\0';


	DIAG_FILTER(PCAC, ATCMDSrv, convertDecIntToBinStr_result, DIAG_INFORMATION)
	diagPrintf("in 0x%lx,out %s, tmp %s",inValue,outStr,tmpBuf);
	return TRUE;
}

#ifdef LWIP_IPNETBUF_SUPPORT
void setUnknownPdpCause(UINT32 atHandle, UINT8 setVaue)
{
	UINT16 *pCause;

#ifndef SINGLE_SIM
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))) {
		pCause = &UnknownPdpCause;
	} else {
		pCause = &UnknownPdpCause_1;
	}
#else
	pCause = &UnknownPdpCause;
#endif

	*pCause = setVaue;

	if (bspGetBoardType() == TIGX_MIFI)
	{
		 /* TODO, CI not updated into 1802s */
		#if 1
		if (setVaue == CI_PS_ESM_ATTACH_REJECT_NO_EITF)
		{
			//ATDBGMSG("%s: ATTACH_REJECT_NO_EITF, force reg status", __func__);
			if (get_force_reg_flag() != 0x02)
				set_force_reg_flag(0x01);
		}
		#endif
	}
}

UINT16 getUnknownPdpCause(UINT32 atHandle)
{
	UINT16 *pCause;

#ifndef SINGLE_SIM	
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))) {
		pCause = &UnknownPdpCause;
	} else {
		pCause = &UnknownPdpCause_1;
	}
#else
	pCause = &UnknownPdpCause;
#endif

    return *pCause;
}

#ifdef CRANE_MCU_DONGLE
networkInfoCbs atcmdNetworkInfoCbs;

void setupNetworkCbs(networkInfoCbs *customerCbs)
{
    memcpy(&atcmdNetworkInfoCbs, customerCbs, sizeof(networkInfoCbs));
}
#endif

/* 
*@input simID - 0: SIM1 1: SIM2
*       status - as enum CIPSNWREGSTATUS_TAG defined in ci_ps.h
**/
void atcmdNetworkStatusChanged(int simID, int status)
{
    //ATDBGMSG("%s: sim%d network status %d\r", __func__, (simID+1), status);
#ifdef CRANE_MCU_DONGLE
    if (atcmdNetworkInfoCbs.nwStatusChanged)
        atcmdNetworkInfoCbs.nwStatusChanged(simID, status);
#endif
}

/* 
*@input simID - 0: SIM1 1: SIM2
*       mode - as enum ATCI_SYSINFO_SYSTEM_MODE defined in mm_api_mini.c
**/
void atcmdNetworkModeChanged(int simID, int mode)
{
    //ATDBGMSG("%s: sim%d network mode %d\r", __func__, (simID+1), mode);
#ifdef CRANE_MCU_DONGLE
    if (atcmdNetworkInfoCbs.nwModeChanged)
        atcmdNetworkInfoCbs.nwModeChanged(simID, mode);
#endif
}

void atcmdSignalChanged(int simID, struct mmSignal *signal)
{
    //ATDBGMSG("%s: sim%d signal rssi %d, ber %d\r", __func__, (simID+1), signal->rssi, signal->ber);
#ifdef CRANE_MCU_DONGLE
    if (atcmdNetworkInfoCbs.signalChanged)
        atcmdNetworkInfoCbs.signalChanged(simID, signal);
#endif
}

void atcmdExtendSignalChanged(int simID, struct mmExtendedSignal *signal)
{
    //ATDBGMSG("%s: sim%d extend signal rssi %d, ber %d\r", __func__, (simID+1), signal->rssi, signal->ber);
#ifdef CRANE_MCU_DONGLE
    if (atcmdNetworkInfoCbs.extendSignalChanged)
        atcmdNetworkInfoCbs.extendSignalChanged(simID, signal);
#endif
}

/* 
*@input simID - 0: SIM1 1: SIM2
*       status - 0: absent 1: present 
**/
void atcmdSimStatusChanged(int simID,int status)
{
    //ATDBGMSG("%s: sim%d sim present %d\r", __func__, (simID+1), status);
#ifdef CRANE_MCU_DONGLE
    if (atcmdNetworkInfoCbs.simStatusChanged)
        atcmdNetworkInfoCbs.simStatusChanged(simID, status);
#endif
}

/* 
*@input simID - 0: SIM1 1: SIM2
*       status - as enum CISIMPINSTATE_TAG defined in ci_sim.h
**/
void atcmdPinStatusChanged(int simID,int status)
{
    //ATDBGMSG("%s: sim%d pin status %d\r", __func__, (simID+1), status);
#ifdef CRANE_MCU_DONGLE
    if (atcmdNetworkInfoCbs.pinStatusChanged)
        atcmdNetworkInfoCbs.pinStatusChanged(simID, status);
#endif
}

void checkNWRegStatus(UINT32 atHandle)
{
    CMMsg rsp_msg;
    OSA_STATUS osa_status;
	UINT8 *pNwReadyFlag, *pLastNwReadyFlag;
	UINT8 *pCgreg, *pCereg;
	int *pSysMainMode, *pSysMode;
	int sim = 1;
	INT32 nwStatus, *pLastNwStatus;

#ifndef SINGLE_SIM
		if(atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle)))
		{
			pNwReadyFlag = &NWReadyFlag;
			pLastNwReadyFlag = &LastNWReadyFlag;
			pCgreg = &CgregReady;
			pCereg = &CeregReady;
			pSysMainMode = &gSysMainMode;
			pSysMode = &gSysMode;
			nwStatus = get_current_reg_status(IND_REQ_HANDLE);
			pLastNwStatus = &gLastNwStatus;
		}
		else
		{
			pNwReadyFlag = &NWReadyFlag_1;
			pLastNwReadyFlag = &LastNWReadyFlag_1;
			pCgreg = &CgregReady_1;
			pCereg = &CeregReady_1;
			pSysMainMode = &gSysMainMode_1;
			pSysMode = &gSysMode_1;
			sim = 2;
			nwStatus = get_current_reg_status(IND_REQ_HANDLE_1);
			pLastNwStatus = &gLastNwStatus_1;
		}
	
#else
		pNwReadyFlag = &NWReadyFlag;
		pLastNwReadyFlag = &LastNWReadyFlag;
		pCgreg = &CgregReady;
		pCereg = &CeregReady;
		pSysMainMode = &gSysMainMode;
		pSysMode = &gSysMode;
		nwStatus = get_current_reg_status(IND_REQ_HANDLE);
		pLastNwStatus = &gLastNwStatus;
#endif


    *pNwReadyFlag = FALSE;

    if(*pCgreg || *pCereg)
       *pNwReadyFlag = TRUE;
    else
    {
        *pSysMainMode = 0;
        *pSysMainMode  = 0;
    }

    CPUartLogPrintf("%s: SIM%d NWReadyFlag is %d, LastNWReadyFlag is %d", __FUNCTION__, sim, *pNwReadyFlag, *pLastNwReadyFlag);
    CPUartLogPrintf("%s: SIM%d gSysMode is %d, CgregReady is %d, CeregReady is %d", __FUNCTION__, sim, *pSysMode,*pCgreg, *pCereg);

    if (*pLastNwStatus != nwStatus)
    {
        *pLastNwStatus =  nwStatus;
        atcmdNetworkStatusChanged((sim == 1)? SIM1 : SIM2, nwStatus);
    }
    if(*pLastNwReadyFlag != *pNwReadyFlag)
    {
	*pLastNwReadyFlag = *pNwReadyFlag;

    cmUpdateNwStatus((sim == 1)? CM_SIM_0 : CM_SIM_1, (char)*pNwReadyFlag);
	if (!isHandleForMasterSim(atHandle))
		return;
	
	rsp_msg.MsgData= pNwReadyFlag;
	rsp_msg.MsgID = NWReady;
	rsp_msg.tick = OSAGetTicks();

	if (gCMMsgQ == NULL)
	{
		//ATDBGMSG("%s: gCMMsgQ not init", __func__);
		return;
	}
	osa_status = OSAMsgQSend(gCMMsgQ, sizeof(rsp_msg), (UINT8 *)&rsp_msg, OSA_NO_SUSPEND);
	ASSERT(osa_status == OS_SUCCESS);
    }
}

void updatePdpCtxPdpInfo(PdpContextList *list, CiPsPdpCtxInfo *psCtx)
{

	CPUartLogPrintf("updatePdpCtxPdpInfo: ps pdp bear type %d, cid %d, p_cid %d, bearer_id %d", psCtx->pdpCtx.pdpBearType, psCtx->pdpCtx.cid, psCtx->pdpCtx.p_cid, psCtx->pdpCtx.bearer_id);
	telPsPdpCtx *psPdpInfo = telGetPdpCtx(psCtx->pdpCtx.cid);

	/* primary PDP */
	if(psCtx->pdpCtx.pdpBearType == CI_PS_PRIMARY_PDP)
	{
		list->PDP.Pdp_Info.PDP_Type = 1;
		list->PDP.Pdp_Info.PrimaryCID = psCtx->pdpCtx.cid;

		//FixMe: If we want to check which CID is used for dedicate APN, we need to record APN information here  Yhuang 20160321
		if ( psCtx->pdpCtx.apnPresent )
		{
			if (psPdpInfo && psPdpInfo->reDefined)
			{
				if (strlen(psPdpInfo->apnInfo.apn) > 0)
				{
					strncpy(list->PDP.Pdp_Info.APN, psPdpInfo->apnInfo.apn, MAX_APN_INFO_LEN);
					strncpy(list->PDP.Pdp_Info.LteAPN, psPdpInfo->apnInfo.apn, MAX_APN_INFO_LEN);
				}
				else
				{
					list->PDP.Pdp_Info.APN[0] = '\0';
					list->PDP.Pdp_Info.LteAPN[0] = '\0';
				}
			}
			else
			{
				memcpy( list->PDP.Pdp_Info.APN, psCtx->pdpCtx.apn.valStr, psCtx->pdpCtx.apn.len );
				list->PDP.Pdp_Info.APN[psCtx->pdpCtx.apn.len] = '\0';
				memcpy( list->PDP.Pdp_Info.LteAPN, psCtx->pdpCtx.apn.valStr, psCtx->pdpCtx.apn.len );
				list->PDP.Pdp_Info.LteAPN[psCtx->pdpCtx.apn.len] = '\0';
			}
#ifdef ATCMD_PDP_CONTEXT
			if (psPdpInfo)
			{
				telUpdatePdpInfoListApn( psCtx->pdpCtx.cid + 1, psPdpInfo->activedApnInfo.apn, psPdpInfo->activedApnInfo.ipType);
				psCtx->pdpCtx.apn.valStr[psCtx->pdpCtx.apn.len] = '\0';
			}
			telUpdatePdpInfoListEpsApn( psCtx->pdpCtx.cid + 1, psCtx->pdpCtx.apn.valStr, psCtx->pdpCtx.type);
#endif
		}
		else
		{
			list->PDP.Pdp_Info.APN[0] = '\0';
			list->PDP.Pdp_Info.LteAPN[0] = '\0';
		}
	}
	else if (psCtx->pdpCtx.pdpBearType == CI_PS_SECONDARY_PDP)           //Secondary PDP
	{
		list->PDP.Pdp_Info.PDP_Type = 0;
		list->PDP.Pdp_Info.SecondaryCID = psCtx->pdpCtx.cid;
		list->PDP.Pdp_Info.PrimaryCID = psCtx->pdpCtx.p_cid;

		psPdpInfo = telGetPdpCtx(psCtx->pdpCtx.p_cid);
		if ( psCtx->pdpCtx.apnPresent )
		{
			if (psPdpInfo && psPdpInfo->reDefined)
			{
				if (strlen(psPdpInfo->apnInfo.apn) > 0)
				{
					strncpy(list->PDP.Pdp_Info.APN, psPdpInfo->apnInfo.apn, MAX_APN_INFO_LEN);
					strncpy(list->PDP.Pdp_Info.LteAPN, psPdpInfo->apnInfo.apn, MAX_APN_INFO_LEN);
				}
				else
				{
					list->PDP.Pdp_Info.APN[0] = '\0';
					list->PDP.Pdp_Info.LteAPN[0] = '\0';
				}
			}
			else
			{
				memcpy( list->PDP.Pdp_Info.APN, psCtx->pdpCtx.apn.valStr, psCtx->pdpCtx.apn.len );
				list->PDP.Pdp_Info.APN[psCtx->pdpCtx.apn.len] = '\0';
				memcpy( list->PDP.Pdp_Info.LteAPN, psCtx->pdpCtx.apn.valStr, psCtx->pdpCtx.apn.len );
				list->PDP.Pdp_Info.LteAPN[psCtx->pdpCtx.apn.len] = '\0';
			}
		}
	}
	if (isMtPdp(psCtx->pdpCtx.cid))
		list->PDP.Pdp_Info.IsDefaultConnection = TRUE;

       list->PDP.Pdp_Info.BearerID = psCtx->pdpCtx.bearer_id;
}//MiniSystem

void updatePdpCtxIpv4Info(PdpContextList *list, CiPsPdpCtxInfo *psCtx)
{
	INT32 cid = psCtx->pdpCtx.cid;
	UINT8 *ipaddr, oct;
	INT32 i;

	list->PDP.IPV4 = (Ipv4Info *)malloc(sizeof(Ipv4Info));
	ASSERT(list->PDP.IPV4 != NULL);
	memset(list->PDP.IPV4, 0, sizeof(Ipv4Info));

	ipaddr = psCtx->pdpCtx.ipv4Addr.valData;
	for (i = 0; i < 4; i++)
	{
		list->PDP.IPV4->IPAddr |= (*ipaddr << (8*(3 - i)));
		ipaddr++;
	}
	list->PDP.IPV4->GateWay = list->PDP.IPV4->IPAddr ^ 0xFF;
	oct = (UINT8)((list->PDP.IPV4->IPAddr & 0xFF000000) >> 24);
	if (oct >= 192)
		list->PDP.IPV4->Mask = 0xFFFFFF00;		 // 255.255.255.0
	else if (oct >= 128)
		list->PDP.IPV4->Mask = 0xFFFF0000;		 // 255.255.0.0
	else
		list->PDP.IPV4->Mask = 0xFF000000;		 // 255.0.0.0

#ifndef NO_DIALER
	updatePdpTimeIpInfo(1, &list->PDP.IPV4->IPAddr, cid);
#endif

	CPUartLogPrintf("updatePdpCtxIpInfo: inIPAddr=%d.%d.%d.%d\n",(list->PDP.IPV4->IPAddr & 0xff000000)>>24,
			(list->PDP.IPV4->IPAddr & 0x00ff0000)>>16,(list->PDP.IPV4->IPAddr & 0x0000ff00)>>8,
			(list->PDP.IPV4->IPAddr & 0x0000ff));

}

void updatePdpCtxIpv6Info(PdpContextList *list, CiPsPdpCtxInfo *psCtx)
{
	INT32 cid = psCtx->pdpCtx.cid;
	UINT8 *ipaddr;
	INT32 i = 0;

	list->PDP.IPV6 = (Ipv6Info *)malloc(sizeof(Ipv6Info));
	if(list->PDP.IPV6 == NULL)
		return;
	memset(list->PDP.IPV6, 0, sizeof(Ipv6Info));

	ipaddr = psCtx->pdpCtx.ipv6Addr.valData;

	if (psCtx->pdpCtx.ipv6Addr.addrType == CI_PS_PDP_IPV6_INTERFACE)
	{
		list->PDP.IPV6->IPV6Addr[0] = 0xfe800000;
		list->PDP.IPV6->IPV6Addr[1] = 0;
		i = 2;
		CPUartLogPrintf("updatePdpCtxIpv6Info: inIPV6Addr[0]=%X, inIPV6Addr[1]=%X", list->PDP.IPV6->IPV6Addr[0], list->PDP.IPV6->IPV6Addr[1]);
	}

	while(i < 4)
	{
		list->PDP.IPV6->IPV6Addr[i] |= (*ipaddr << 24);
		ipaddr++;
		list->PDP.IPV6->IPV6Addr[i] |= (*ipaddr << 16);
		ipaddr++;
		list->PDP.IPV6->IPV6Addr[i] |= (*ipaddr << 8);
		ipaddr++;
		list->PDP.IPV6->IPV6Addr[i] |= *ipaddr;
		ipaddr++;

		CPUartLogPrintf("updatePdpCtxIpv6Info: inIPV6Addr[%d]=%X", i, list->PDP.IPV6->IPV6Addr[i]);
		i++;
	}
	

}


void updatePdpCtxDnsInfo(PdpContextList *list, CiPsPdpCtxInfo *psCtx)
{
	if(psCtx->pdpCtx.pdParasPresent)
	{
		UINT8 *buf, *packetEnd, *ipcpEnd, *tbuf;
		unsigned char is_IPV6_primary_dns = 1, is_IPV4_primary_dns = 1;

	    buf = (UINT8*)psCtx->pdpCtx.pdParas.valStr;
		packetEnd = buf + psCtx->pdpCtx.pdParas.len;
		while (buf < packetEnd)
		{

			unsigned short type = buf[0]<<8 | buf[1];
			UINT8  len = buf[2]; //  this length field includes only what follows it
			CPUartLogPrintf("updatePdpCtxDnsInfo: type 0x%x", type);
			switch (type)
			{
				// we are currently interested only on one type
				// but will specify some more for fute
				case 0x23C0:
					// PAP - not used  - ignore
					buf+=len+3;
					break;
				case 0x8021:
					// IPCP option for IP configuration - we are looking for DNS parameters.
					// it seem that this option may appear more than once!
					ipcpEnd = buf + len + 3;
					buf += 3;
					// 3gpp TS29.061 conf-nak or conf-ack both can be here and has DNS infomation
					if (*buf == 0x02 || *buf == 0x03)
					{
						// Config-Nak found, advance to IPCP data start
						buf += 4;
						// parse any configuration
						while(buf < ipcpEnd)
						{
							if (*buf == 129)
							{
								// Primary DNS address
								buf += 2;
								DPRINTF("updatePdpCtxDnsInfo: Primary DNS %d.%d.%d.%d\n",buf[0],buf[1],buf[2],buf[3]);
								if (list->PDP.IPV4)
									list->PDP.IPV4->PrimaryDNS  = ((buf[0]<<24) | (buf[1]<<16) | (buf[2]<<8) | buf[3]);
								buf += 4;
								continue;
							}
							if (*buf == 131)
							{
								// Secondary DNS address
								buf += 2;
								DPRINTF("updatePdpCtxDnsInfo: secondary DNS %d.%d.%d.%d\r\n",buf[0],buf[1],buf[2],buf[3]);
								if (list->PDP.IPV4)
									list->PDP.IPV4->SecondaryDNS = ((buf[0]<<24) | (buf[1]<<16) | (buf[2]<<8) | buf[3]);
								buf += 4;
								continue;
							}
							// buf[0] includes the ipcp type, buf[1] the length of this field includes the whole TLV
							buf+=buf[1];
						}

					}
					else
					{
						buf += len;
					}
					break;
				case 0x0003:
					tbuf = buf+3;
					CPUartLogPrintf("updatePdpCtxDnsInfo: IPV6 DNS Address exist,len=%d is_primary_dns=%d",len,is_IPV6_primary_dns);
					if (list->PDP.IPV6)
					{
						if (is_IPV6_primary_dns)
						{
							list->PDP.IPV6->PrimaryDNS[0]=((tbuf[0]<<24) | (tbuf[1]<<16) | (tbuf[2]<<8) | tbuf[3]);
							tbuf+=4;
							list->PDP.IPV6->PrimaryDNS[1]=((tbuf[0]<<24) | (tbuf[1]<<16) | (tbuf[2]<<8) | tbuf[3]);
							tbuf+=4;
							list->PDP.IPV6->PrimaryDNS[2]=((tbuf[0]<<24) | (tbuf[1]<<16) | (tbuf[2]<<8) | tbuf[3]);
							tbuf+=4;
							list->PDP.IPV6->PrimaryDNS[3]=((tbuf[0]<<24) | (tbuf[1]<<16) | (tbuf[2]<<8) | tbuf[3]);

							CPUartLogPrintf("updatePdpCtxDnsInfo: IPV6 Primary DNS Address:%x %x %x %x",list->PDP.IPV6->PrimaryDNS[0], list->PDP.IPV6->PrimaryDNS[1],
								list->PDP.IPV6->PrimaryDNS[2], list->PDP.IPV6->PrimaryDNS[3]);
							is_IPV6_primary_dns = 0;
						} else {
							list->PDP.IPV6->SecondaryDNS[0]=((tbuf[0]<<24) | (tbuf[1]<<16) | (tbuf[2]<<8) | tbuf[3]);
							tbuf+=4;
							list->PDP.IPV6->SecondaryDNS[1]=((tbuf[0]<<24) | (tbuf[1]<<16) | (tbuf[2]<<8) | tbuf[3]);
							tbuf+=4;
							list->PDP.IPV6->SecondaryDNS[2]=((tbuf[0]<<24) | (tbuf[1]<<16) | (tbuf[2]<<8) | tbuf[3]);
							tbuf+=4;
							list->PDP.IPV6->SecondaryDNS[3]=((tbuf[0]<<24) | (tbuf[1]<<16) | (tbuf[2]<<8) | tbuf[3]);

							CPUartLogPrintf("updatePdpCtxDnsInfo :IPV6 Secondary DNS Address:%x %x %x %x",list->PDP.IPV6->SecondaryDNS[0], list->PDP.IPV6->SecondaryDNS[1],
								list->PDP.IPV6->SecondaryDNS[2], list->PDP.IPV6->SecondaryDNS[3]);

						}
					}

					buf += (len+3);
					break;

				case 0x000d:
					tbuf=buf+3;

					CPUartLogPrintf("updatePdpCtxDnsInfo : IPV4 DNS Address exist,len=%d",len);
					if (list->PDP.IPV4)
					{
						if(is_IPV4_primary_dns)
						{
							list->PDP.IPV4->PrimaryDNS = ((tbuf[0]<<24) | (tbuf[1]<<16) | (tbuf[2]<<8) | tbuf[3]);
							CPUartLogPrintf("updatePdpCtxDnsInfo: IPV4 Primary DNS %d.%d.%d.%d\n",tbuf[0],tbuf[1],tbuf[2],tbuf[3]);
							is_IPV4_primary_dns = 0;
						} else {
							list->PDP.IPV4->SecondaryDNS = ((tbuf[0]<<24) | (tbuf[1]<<16) | (tbuf[2]<<8) | tbuf[3]);
							CPUartLogPrintf("updatePdpCtxDnsInfo: IPV4 Secondary DNS %d.%d.%d.%d\n",tbuf[0],tbuf[1],tbuf[2],tbuf[3]);
						}
					}

					buf+=(len+3);
					break;
				default:
				{
					//ATDBGMSG(atcmdsrv0,136,"updatePdpCtxDnsInfo: default branch of PCO:%x%x len=%d",buf[0],buf[1],len);
					buf += (len+3);
					break;
				}
			}
		}
	}
}
#ifdef QUEC_POWER_BACKOFF_SUPPORT
extern void quec_check_nv_enable_rflte_pwrbackoff(void);
#endif	
#ifdef QUECTEL_IPC_ENTERSLEEP_SUPPORT
extern quec_user_conf user_conf;
extern quec_ipc_conf ipcapp_msg;
#endif

void updatePdpCtxIpInfo(PdpContextList *list, CiPsPdpCtxInfo *psCtx)
{
	INT32 cid = psCtx->pdpCtx.cid;
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
	
#ifdef QUEC_POWER_BACKOFF_SUPPORT
	quec_check_nv_enable_rflte_pwrbackoff();
#endif	

#ifdef QUEC_LWM2M_SUPPORT	
#ifdef QUECTEL_IPC_ENTERSLEEP_SUPPORT
    CPUartLogPrintf("updatePdpCtxIpInfo: cid %d benable %d\n", cid, ipcapp_msg.benable);
    if(TRUE == ipcapp_msg.benable)
    {
        if(user_conf.register_times == 0)
        {
            quec_event_notify_report(EVENT_PDP_DEFAULT_ACT,NULL);
        }
    }
    else 
    {
        quec_event_notify_report(EVENT_PDP_DEFAULT_ACT,NULL);
    }

#else
    quec_event_notify_report(EVENT_PDP_DEFAULT_ACT,NULL);
#endif
#endif
}//MiniSystem
#endif /*MIN_SYS*/

	CPUartLogPrintf("updatePdpCtxIpInfo: type %d\n", psCtx->pdpCtx.type);
	if (psCtx->pdpCtx.type == CI_PS_PDP_TYPE_IP)
	{
		//ATDBGMSG(atcmdsrv0,138,"updatePdpCtxIpInfo: CI_PS_PDP_TYPE_IPV4\n");
		if(psCtx->pdpCtx.ipv4Addr.addrType!= CI_PS_PDP_INVALID_ADDR)
		{
			list->PDP.Pdp_Info.IP_Type = 1;
			updatePdpCtxIpv4Info(list, psCtx);
#ifndef NO_DIALER
			updatePdpTimeIpInfo(1, &list->PDP.IPV4->IPAddr, cid);
#endif
		}

		if(psCtx->pdpCtx.pdParasPresent)
		{
			updatePdpCtxDnsInfo(list, psCtx);
		}
#ifdef ATCMD_PDP_CONTEXT
		telUpdatePdpInfoListIp(psCtx->pdpCtx.cid + 1, list->PDP.IPV4);
#endif
	}
	else if (psCtx->pdpCtx.type == CI_PS_PDP_TYPE_IPV6)
	{
		//ATDBGMSG(atcmdsrv0,139,"updatePdpCtxIpInfo: CI_PS_PDP_TYPE_IPV6\n");
		list->PDP.Pdp_Info.IP_Type = 2;
		if(psCtx->pdpCtx.ipv6Addr.addrType != CI_PS_PDP_INVALID_ADDR)
		{
			list->PDP.Pdp_Info.IP_Type = 2;
			updatePdpCtxIpv6Info(list, psCtx);
#ifndef NO_DIALER
			updatePdpTimeIpInfo(2, list->PDP.IPV6->IPV6Addr, cid);
#endif
			if(psCtx->pdpCtx.pdParasPresent)
			{
				updatePdpCtxDnsInfo(list, psCtx);
			}
#ifdef ATCMD_PDP_CONTEXT
			telUpdatePdpInfoListIp6(psCtx->pdpCtx.cid + 1, list->PDP.IPV6);
#endif
		}
	}
	else if(psCtx->pdpCtx.type == CI_PS_PDP_TYPE_IPV4V6)
	{
	 	//ATDBGMSG(atcmdsrv0,140,"updatePdpCtxIpInfo: CI_PS_PDP_TYPE_IPV4V6\n");
		if(psCtx->pdpCtx.ipv6Addr.addrType != CI_PS_PDP_INVALID_ADDR)
		{
			list->PDP.Pdp_Info.IP_Type = 0;
			updatePdpCtxIpv6Info(list, psCtx);
#ifndef NO_DIALER
			updatePdpTimeIpInfo(2, list->PDP.IPV6->IPV6Addr, cid);
#endif
			if(psCtx->pdpCtx.pdParasPresent)
			{
				updatePdpCtxDnsInfo(list, psCtx);
			}
#ifdef ATCMD_PDP_CONTEXT
			telUpdatePdpInfoListIp6(psCtx->pdpCtx.cid + 1, list->PDP.IPV6);
#endif
		}

		if (psCtx->pdpCtx.ipv4Addr.addrType != CI_PS_PDP_INVALID_ADDR)
		{
			list->PDP.Pdp_Info.IP_Type = 0;
			updatePdpCtxIpv4Info(list, psCtx);
#ifndef NO_DIALER
			updatePdpTimeIpInfo(1, &list->PDP.IPV4->IPAddr, cid);
#endif
			if(psCtx->pdpCtx.pdParasPresent)
			{
				updatePdpCtxDnsInfo(list, psCtx);
			}
#ifdef ATCMD_PDP_CONTEXT
			telUpdatePdpInfoListIp(psCtx->pdpCtx.cid + 1, list->PDP.IPV4);
#endif
		}
	}
}

void exitQueryPdpCtx(UINT32 reqHandle)
{
	BOOL *pInProcess;
	pInProcess = &(gAtpCtrl[GET_ATP_INDEX(reqHandle)].pdpCtx.queryInProcess);

	//ATDBGMSG("%s for reqHandle %x", __func__, reqHandle);
	*pInProcess = FALSE;
}

BOOL getQueryPdpCtxInProcess(UINT32 reqHandle)
{
	BOOL inProcess;
	inProcess = gAtpCtrl[GET_ATP_INDEX(reqHandle)].pdpCtx.queryInProcess;

	return inProcess;
}

void freePacketFilterList(PacketFilterInfo* PFList)
{
	PacketFilterInfo* pPF = NULL;
	PacketFilterInfo* t_pPF = NULL;
	int i=0;
	int j = 0, size = 0;
	UINT8 dumpBuf[40*2];
	UINT8 *pBuf;

	//ATDBGMSG("Enter %s, list=%lx", __FUNCTION__, PFList);

	for(pPF=PFList; pPF!=NULL;)
	{
		t_pPF = pPF->next;
		//ATDBGMSG("%s: pPF 0x%x, nextPF 0x%x", __FUNCTION__, pPF, t_pPF);
		size = 0;
		memset(dumpBuf, 0, 40*2);
		pBuf = (UINT8 *)(pPF + sizeof(PacketFilterInfo));
		for (j = 0; j < 36; j++)
		{
			size += sprintf((char *)(dumpBuf + size), "%02x", pBuf[j]);
		}
		//ATDBGMSG("%s: extend buffer %s", __FUNCTION__, dumpBuf);

		free(pPF);
		pPF = t_pPF;
		i++;
	}

	//ATDBGMSG("exit %s:%d", __FUNCTION__, i);
}

void freePdpContextList(PdpContextList *pList)
{
	PdpContextList *pdp=NULL;
	PdpContextList *pdptmp=NULL;

	for(pdp = pList; pdp != NULL; )
	{
		pdptmp = pdp->next;

		if(pdp->PDP.IPV4)
			free(pdp->PDP.IPV4);

		if(pdp->PDP.IPV6)
			free(pdp->PDP.IPV6);

		if(pdp->PDP.PF)
			free(pdp->PDP.PF);

		free(pdp);
		pdp = pdptmp;
	}
	//ATDBGMSG("%s done", __FUNCTION__);
}

void freePdpCtxList(UINT32 sAtpIndex)
{
	BOOL *pInProcess;
	PdpContextList **plist_current, **plist_head = NULL;

	pInProcess = &(gAtpCtrl[sAtpIndex].pdpCtx.queryInProcess);
	plist_head = &(gAtpCtrl[sAtpIndex].pdpCtx.head);
	plist_current = &(gAtpCtrl[sAtpIndex].pdpCtx.current);

	if(*plist_head != NULL && *pInProcess == FALSE)
	{
		CPUartLogPrintf("%s:  free list for sAtpIndex %d", __func__, sAtpIndex);
		freePdpContextList(*plist_head);
		*plist_head = NULL;
		*plist_current = NULL;
	}
}

void processGetPdpCtxCnf(UINT32 reqHandle, const void *paras)
{
	CiPsPrimGetPdpCtxCnf *getPdpPrimCnf = (CiPsPrimGetPdpCtxCnf *)paras;
	CiPsPdpCtxInfo *pCtx = &(getPdpPrimCnf->ctx);
	BOOL *pInProcess;
	PdpContextList **plist_current, **plist_head = NULL;
	PdpContextList *list_current = NULL;
#ifdef QUECTEL_NETWORK_SUPPORT
	telPsPdpCtx *psPdpInfo = NULL;
#endif

	pInProcess = &(gAtpCtrl[GET_ATP_INDEX(reqHandle)].pdpCtx.queryInProcess);
	plist_head = &(gAtpCtrl[GET_ATP_INDEX(reqHandle)].pdpCtx.head);
	plist_current = &(gAtpCtrl[GET_ATP_INDEX(reqHandle)].pdpCtx.current);

	//ATDBGMSG("processGetPdpCtxCnf: head %x, current %x, in process %d", *plist_head, *plist_current, *pInProcess);
	if(*plist_head != NULL && *pInProcess == FALSE)
       {
		CPUartLogPrintf("processGetPdpCtxCnf: list process done, free list first!");
		freePdpContextList(*plist_head);
		*plist_head = NULL;
		*plist_current = NULL;
       }

	if (!getPdpPrimCnf->ctxPresent || !pCtx->actState)
		return;

    if(pCtx->actState)
    {
	    if(*pInProcess == FALSE)
	    {
	        *pInProcess = TRUE;
			*plist_current = (void *)malloc(sizeof(PdpContextList));
			ASSERT(*plist_current != NULL);
			memset(*plist_current, 0, sizeof(PdpContextList));
			*plist_head = *plist_current;
			CPUartLogPrintf("processGetPdpCtxCnf: list head %x", *plist_head);

		}
		else
		{
			(*plist_current)->next = (void *)malloc(sizeof(PdpContextList));
			ASSERT((*plist_current)->next != NULL);
			memset((*plist_current)->next, 0, sizeof(PdpContextList));
			*plist_current = (PdpContextList *)(*plist_current)->next;
		}

		list_current = *plist_current;

	       list_current->PDP.Pdp_Info.BearerID = pCtx->pdpCtx.bearer_id;

		updatePdpCtxPdpInfo(list_current, pCtx);
		#ifndef NO_DIALER
		updatePdpConnectedTime(list_current, pCtx->pdpCtx.cid);
		#endif

		if ((pCtx->pdpCtx.ipv4Addr.addrType != CI_PS_PDP_INVALID_ADDR) || (pCtx->pdpCtx.ipv6Addr.addrType != CI_PS_PDP_INVALID_ADDR))
		{
			updatePdpCtxIpInfo(list_current, pCtx);
		}
		else if(pCtx->pdpCtx.esmCausePresent)
		{
			//CPUartLogPrintf("processGetPdpCtxCnf: esmCause is %d", pCtx->pdpCtx.esmCause);

#ifdef VOLTE_ENABLE
			if (is_ims_cid(GET_SIM1_FLAG(reqHandle)?1:0, pCtx->pdpCtx.cid+1, pCtx->pdpCtx.apn.valStr) == 1)
			{
				return;
			}
#endif
			setUnknownPdpCause(GET_AT_HANDLE(reqHandle), pCtx->pdpCtx.esmCause);
		}
    }

}

void sendPdpCxtListToCm(UINT32 reqHandle)
{
	OSA_STATUS osa_status;
	CMMsg rsp_msg;
	PdpContextList	*tmp_list = NULL, *PDPList = NULL, **plist_head = NULL, **plist_current =NULL;
	INT32 dialer_iptype = 0;
	CHAR cid;
	BOOL needSend = FALSE;
	
    if (gCMMsgQ == NULL)
        goto end;
        
	plist_head = &(gAtpCtrl[GET_ATP_INDEX(reqHandle)].pdpCtx.head);
	plist_current = &(gAtpCtrl[GET_ATP_INDEX(reqHandle)].pdpCtx.current);

	/* input from AT port. 2. MT pdp */
#if QUEC_DUAL_SIM_DATA_SERVICE_SUPPORT
	if (GET_ATP_INDEX(reqHandle) == AT_MODEM_CHANNLE || GET_ATP_INDEX(reqHandle) == EVENT_HANDLER_ATP_INDEX)
	{
		if (getDualSimType() == CM_DUAL_SIM_SINGLE_STANDBY)
		{
			if (isMasterSim0())
				needSend = TRUE;
		}
		else
		{
			needSend = TRUE; 
		}
	}

	if (GET_ATP_INDEX(reqHandle) == AT_MODEM_CHANNLE_1 || GET_ATP_INDEX(reqHandle) == EVENT_HANDLER_ATP_INDEX_1)
	{
		if (getDualSimType() == CM_DUAL_SIM_SINGLE_STANDBY)
		{
			if (!isMasterSim0())
				needSend = TRUE;
		}
		else
		{
			needSend = TRUE; 
		}
	}
#else
	if (GET_ATP_INDEX(reqHandle) == AT_MODEM_CHANNLE || GET_ATP_INDEX(reqHandle) == EVENT_HANDLER_ATP_INDEX)
		if (isMasterSim0())
			needSend = TRUE;

	if (GET_ATP_INDEX(reqHandle) == AT_MODEM_CHANNLE_1 || GET_ATP_INDEX(reqHandle) == EVENT_HANDLER_ATP_INDEX_1)
		if (!isMasterSim0())
			needSend = TRUE;
#endif

	if(needSend)
	{
		if(*plist_head != NULL)
		{
			memset(&rsp_msg, 0, sizeof(CMMsg));
			PDPList = CopyPdpList(*plist_head);
#if defined(NEZHA_PCIE_DONGLE)
			dialer_iptype = -1;
		//	CPUartLogPrintf("%s: Dongle Platform, dialer_iptype %d", __func__, dialer_iptype);
#endif

#ifndef NO_DIALER
			dialer_iptype = get_auto_apn_iptype(isHandleForSim0(reqHandle) ? SIM1: SIM2);
		//	CPUartLogPrintf("%s: dialer_iptype %d", __func__, dialer_iptype);
#endif
			if(dialer_iptype >= 0)
			{
				tmp_list = PDPList;
				while(tmp_list)
				{
					if(tmp_list->PDP.Pdp_Info.PDP_Type == 1)
						cid = tmp_list->PDP.Pdp_Info.PrimaryCID;
					else
						cid = tmp_list->PDP.Pdp_Info.SecondaryCID;

					#ifndef NO_DIALER
					if(getCurrentCid() == cid)
					{
						if(dialer_iptype == 0)/*IPV4V6*/
						{
							tmp_list->PDP.Pdp_Info.iptype_dialer = 1;
						}
						else if(dialer_iptype == 1) /*IPV4*/
						{
							tmp_list->PDP.Pdp_Info.iptype_dialer = 2;
						}
						else if(dialer_iptype == 2)/*IPV6*/
						{
							tmp_list->PDP.Pdp_Info.iptype_dialer = 3;
						}
						CPUartLogPrintf("%s: set iptype_dialer to %d", __func__, tmp_list->PDP.Pdp_Info.iptype_dialer);
					}
					#endif
					tmp_list = tmp_list->next;
				}
			}

			/*The PDPList will free in CM*/
			rsp_msg.MsgData= PDPList;
			rsp_msg.MsgID = AtcmdCgdcont;
			rsp_msg.tick = OSAGetTicks();

			osa_status = OSAMsgQSend(gCMMsgQ, sizeof(rsp_msg), (UINT8 *)&rsp_msg, OSA_NO_SUSPEND);
			ASSERT(osa_status == OS_SUCCESS);
			CPUartLogPrintf("%s: send done", __func__);
		}
		//MT_PDP_FLAG = FALSE;
	}

end:
	/*free the pdp ctx list in dailer task for DIALER_ATP_INDEX*/
	if (GET_ATP_INDEX(reqHandle) != DIALER_ATP_INDEX && GET_ATP_INDEX(reqHandle) != DIALER_ATP_INDEX_1)
	{
		freePdpCtxList(GET_ATP_INDEX(reqHandle));
	}
}

void exitQueryTftCtx(UINT32 reqHandle)
{
	BOOL *pInProcess;
	pInProcess = &(gAtpCtrl[GET_ATP_INDEX(reqHandle)].tftCtx.queryInProcess);

	*pInProcess = FALSE;

	//ATDBGMSG("exitQueryTftCtx: done");
}

BOOL getQueryTftCtxInProcess(UINT32 reqHandle)
{
	BOOL inProcess;
	inProcess = gAtpCtrl[GET_ATP_INDEX(reqHandle)].tftCtx.queryInProcess;

	return inProcess;
}

void sendTftCtxListToCm(UINT32 reqHandle)
{
	OSA_STATUS osa_status;
	CMMsg rsp_msg;
	PacketFilterInfo *list_head, *list_send = NULL;

    if (gCMMsgQ == NULL)
        return;
        
	list_head = gAtpCtrl[GET_ATP_INDEX(reqHandle)].tftCtx.head;
	if(GET_ATP_INDEX(reqHandle) == AT_MODEM_CHANNLE || GET_ATP_INDEX(reqHandle) == EVENT_HANDLER_ATP_INDEX)	 //caused by AT input
	{
		if(list_head)
		{
			list_send = CopyTFTList(list_head);
			freePacketFilterList(list_head);
			memset(&(gAtpCtrl[GET_ATP_INDEX(reqHandle)].tftCtx), 0, sizeof(TelAtpTftCtx));
		}
		else
		{
		    list_send = NULL;
		}
        memset(&rsp_msg, 0, sizeof(CMMsg));
        rsp_msg.MsgData = list_send;
        rsp_msg.MsgID = DialerTFTResponse;
        rsp_msg.tick = OSAGetTicks();

        //ATDBGMSG("sendTftCtxListToCm: send SIM0 tft response to CM, head=%p", list_send);
        osa_status = OSAMsgQSend(gCMMsgQ, sizeof(rsp_msg), (UINT8 *)&rsp_msg, OSA_NO_SUSPEND);
        ASSERT(osa_status == OS_SUCCESS);
	}
    else
    {
    	/* SIM1*/
    	if(GET_ATP_INDEX(reqHandle) == AT_MODEM_CHANNLE_1 || GET_ATP_INDEX(reqHandle) == EVENT_HANDLER_ATP_INDEX_1)
    	{
    		if(list_head)
    		{
    			list_send = CopyTFTList(list_head);
    			freePacketFilterList(list_head);
    			memset(&(gAtpCtrl[GET_ATP_INDEX(reqHandle)].tftCtx), 0, sizeof(TelAtpTftCtx));
    		}
    		else
    		{
    		    list_send = NULL;
    		}
            memset(&rsp_msg, 0, sizeof(CMMsg));
            rsp_msg.MsgData = list_send;
            rsp_msg.MsgID = DialerTFTResponse_1;
            rsp_msg.tick = OSAGetTicks();

            //ATDBGMSG("sendTftCtxListToCm: send SIM1 tft response to CM, head=%p", list_send);
            osa_status = OSAMsgQSend(gCMMsgQ, sizeof(rsp_msg), (UINT8 *)&rsp_msg, OSA_NO_SUSPEND);
            ASSERT(osa_status == OS_SUCCESS);
    	}
	}
}


void updateTftList(UINT32 reqHandle, const void *paras)
{
	UINT8 currcid,i,k;
	UINT8 *valdata = NULL;
	INT32 subnet_len = 0;
	UINT16 add_len = 0;
	BOOL *pInProcess;
	PacketFilterInfo **plist_current, **plist_head = NULL;
	PacketFilterInfo *list_current = NULL;
	CiPsPrimGetTftCnf  *getTftCnf = (CiPsPrimGetTftCnf *)paras;

	pInProcess = &(gAtpCtrl[GET_ATP_INDEX(reqHandle)].tftCtx.queryInProcess);
	plist_head = &(gAtpCtrl[GET_ATP_INDEX(reqHandle)].tftCtx.head);
	plist_current = &(gAtpCtrl[GET_ATP_INDEX(reqHandle)].tftCtx.current);
	//currcid = gAtpCtrl[GET_ATP_INDEX(reqHandle)].psCurrCid;
	//currcid = gCIDList.currCntx[GET_ATP_INDEX(GET_ATP_INDEX(reqHandle))].currCid;

	if (getTftCnf->rc != CIRC_PS_SUCCESS)
		return;

//	CPUartLogPrintf("updateTftList: numFilters %d, InProcess %d, packageSize=%d", getTftCnf->numFilters, *pInProcess, sizeof(PacketFilterInfo));
	for (k = 0; k < getTftCnf->numFilters; k++)
       {
		if(*pInProcess == FALSE)
		{
			*pInProcess = TRUE;
			if(*plist_head != NULL)
			{
			//	CPUartLogPrintf("updateTftList:  freePacketFilterList!");
				freePacketFilterList(*plist_head);
				*plist_head = NULL;
			}
			*plist_current = (void *)malloc(sizeof(PacketFilterInfo));
			ASSERT(*plist_current != NULL);
			memset(*plist_current, 0, sizeof(PacketFilterInfo));
			*plist_head = *plist_current;
			(*plist_head)->next = NULL;

		}
		else
		{
			(*plist_current)->next = (void *)malloc(sizeof(PacketFilterInfo));
			ASSERT((*plist_current)->next != NULL);
			memset((*plist_current)->next, 0, sizeof(PacketFilterInfo));
			*plist_current = (PacketFilterInfo *)(*plist_current)->next;
			(*plist_current)->next = NULL;
		}

		list_current = *plist_current;

		CPUartLogPrintf("updateTftList: CID %d, list_head %x, CurrentPFList %x, number=%d", getTftCnf->filters[k].cid, *plist_head, *plist_current, k);
        //<cid>
		//list_current->SecondaryCID = currcid;
		list_current->SecondaryCID = getTftCnf->filters[k].cid;
        // <packet filter identifier>, <evaluation precedence index>
		list_current->EpIdx = getTftCnf->filters[k].epIndex;
		list_current->PfIdx = getTftCnf->filters[k].pfId;

		if(getTftCnf->filters[k].remoteAddrAndMask.addrType != CI_PS_PDP_INVALID_ADDR)
		{
			if(getTftCnf->filters[k].remoteAddrAndMask.addrType == CI_PS_PDP_IPV4)
			{
			    list_current->IPType=IP_TYPE_IPV4;
				add_len = CI_PS_PDP_IPV4_ADDR_LENGTH;
				list_current->RemoteAddressPresent = 1;
			}
			else if(getTftCnf->filters[k].remoteAddrAndMask.addrType==CI_PS_PDP_FULL_IPV6)
			{
			    list_current->IPType=IP_TYPE_IPV6;
				add_len = CI_PS_PDP_FULL_IPV6_ADDR_LENGTH;
				list_current->RemoteAddressPresent = 1;
			}
			else if(getTftCnf->filters[k].remoteAddrAndMask.addrType==CI_PS_PDP_IPV6_INTERFACE)
			{
			    list_current->IPType=IP_TYPE_IPV4V6;
				add_len = CI_PS_PDP_IPV6_INTERFACE_ADDR_LENGTH;
				list_current->RemoteAddressPresent = 1;
			}
			valdata = getTftCnf->filters[k].remoteAddrAndMask.valData;

			#if 0
			for ( i = 0; i < add_len; i++ )
			{
				list_current->RemoteAddress[i] = valdata[i];
				list_current->SubnetMask[i] = 0;
			}
			#endif
			 CPUartLogPrintf("updateTftList: ip_type %d, RemoteAddressPresent:%d, addr len %d, subnet:%d",list_current->IPType,
			getTftCnf->filters[k].remoteAddrAndMask.addrType, add_len, getTftCnf->filters[k].remoteAddrAndMask.subnetLength);

			memcpy(list_current->RemoteAddress, valdata, add_len);

			{

				UINT8 maskbits = getTftCnf->filters[k].remoteAddrAndMask.subnetLength;

				UINT8 y=0,z=0;
				UINT32 mask=0;
				if (maskbits > 0)
					list_current->SubnetMaskPresent = 1;

				if(list_current->IPType == IP_TYPE_IPV4)
				{
					for(y=0;y<maskbits;y++)
					{
						mask|=0x1<<y;
					}
					list_current->SubnetMask[0] = mask;

					CPUartLogPrintf("updateTftList: maskbits %d, remote ip %x, mask %x for ipv4", maskbits, list_current->RemoteAddress[0], mask);
				} else if(list_current->IPType == IP_TYPE_IPV6)
				{

				  	unsigned int *SubnetMask;
					SubnetMask = &(list_current->SubnetMask[0]);
				   	for(y=0;y<maskbits;y++)
					{
						mask|=0x1<<((y-(z)*32));
						if(mask == 0xffffffff)
						{
							SubnetMask[z] = mask;
							z++;
							mask=0;
						}
				   	}

					if (z*32 < maskbits)
						list_current->SubnetMask[z%4]= mask;

					CPUartLogPrintf("updateTftList: maskbits %d, subnetmask int size %d, remote ip %x:%x:%x:%x, mask %lx:%lx:%lx:%lx for ipv6", maskbits, z, list_current->RemoteAddress[0], list_current->RemoteAddress[1],
																			list_current->RemoteAddress[2], list_current->RemoteAddress[3],SubnetMask[0],SubnetMask[1],SubnetMask[2],SubnetMask[3]);
				}
			}

			#if 0
			subnet_len = getTftCnf->filters[k].remoteAddrAndMask.subnetLength >> 3;
			for ( i = 0; i < subnet_len; i++)
			{
				list_current->SubnetMaskPresent=1;
				list_current->SubnetMask[i]=0xFF;
			}
			subnet_len = getTftCnf->filters[k].remoteAddrAndMask.subnetLength%8;
			if(subnet_len > 0)
				list_current->SubnetMask[i] = 0xFF << (8 - subnet_len);
			#endif

		}
        //<protocol number (ipv4) / next header (ipv6)>
		list_current->pIdNextHdrPresent = getTftCnf->filters[k].pIdNextHdrPresent;
        if (getTftCnf->filters[k].pIdNextHdrPresent) {
           list_current->pIdNextHdr = getTftCnf->filters[k].pIdNextHdr;
           CPUartLogPrintf("updateTftList: pIdNextHdr %d", getTftCnf->filters[k].pIdNextHdr);           
        }

        // Dest port range "xxxx.xxxx"
        list_current->RemotePortRangePresent = getTftCnf->filters[k].dstPortRangePresent;
        if (getTftCnf->filters[k].dstPortRangePresent)
        {
           	list_current->RemotePortRange.min = getTftCnf->filters[k].dstPortRange.min;
			list_current->RemotePortRange.max = getTftCnf->filters[k].dstPortRange.max;
            CPUartLogPrintf("updateTftList: RemotePort %d-->%d", getTftCnf->filters[k].dstPortRange.min, getTftCnf->filters[k].dstPortRange.max);           			
        }

        // Source port range "xxxx.xxxx"
        list_current->localPortRangePresent = getTftCnf->filters[k].srcPortRangePresent;
        if (getTftCnf->filters[k].srcPortRangePresent)
        {
            list_current->localPortRange.min = getTftCnf->filters[k].srcPortRange.min;
			list_current->localPortRange.max = getTftCnf->filters[k].srcPortRange.max;
            CPUartLogPrintf("updateTftList: SourcePort %d-->%d", getTftCnf->filters[k].srcPortRange.min, getTftCnf->filters[k].srcPortRange.max);           			
			
        }

        //<ipsec security parameter index (spi)>
        list_current->SpiPresent = getTftCnf->filters[k].ipSecSPIPresent;
        if (getTftCnf->filters[k].ipSecSPIPresent) {
            list_current->SPI=getTftCnf->filters[k].ipSecSPI;
            CPUartLogPrintf("updateTftList: ipSecSPI %d", getTftCnf->filters[k].ipSecSPI);           
            
        }

        // tos
        list_current->TosPresent = getTftCnf->filters[k].tosPresent;
        if (getTftCnf->filters[k].tosPresent)
        {
			list_current->Tos = getTftCnf->filters[k].tosTc;
			list_current->TosMask = getTftCnf->filters[k].tosTcMask;
            CPUartLogPrintf("updateTftList: tosTc %d, tosTcMask %d", getTftCnf->filters[k].tosTc, getTftCnf->filters[k].tosTcMask);           			
        }

		list_current->direction = getTftCnf->filters[k].direction;
        CPUartLogPrintf("updateTftList: direction %d", getTftCnf->filters[k].direction);           
		
		if (list_current->direction  > 0)
			list_current->directionPresent = 1;

	//	CPUartLogPrintf("updateTftList: show PF START");
		//showPFInfo(list_current);
	//	CPUartLogPrintf("updateTftList: show PF END");
    }

}

/****************************************************************
 *  F@: processGetPsmConfigConf - Process CI cnf msg of AT+CPSMS?
 */
static void processGetPsmConfigConf(UINT32 reqHandle, const void *paras)
{
	CiPsPrimGetPsmConfigCnf *getPsmConfigCnf;
	char psRspBuf[60];
	char tempBuf[16];

	memset(psRspBuf, 0, sizeof(psRspBuf));
	memset(tempBuf, 0, sizeof(tempBuf));

	getPsmConfigCnf = (CiPsPrimGetPsmConfigCnf *)paras;


	if ( getPsmConfigCnf->rc== CIRC_PS_SUCCESS )
	{
		sprintf(psRspBuf, "+CPSMS: %d,\"", getPsmConfigCnf->mode);

		/* display the location info only if regOption is CI_PS_NW_REG_IND_ENABLE_DETAIL */
		if (getPsmConfigCnf->requestedPeriodRauPresent)
		{
			if(convertDecIntToBinStr(getPsmConfigCnf->requestedPeriodRau,(UINT8 *)tempBuf, 8)==TRUE)
			{
				strcat(psRspBuf, tempBuf);
			}

		}
		strcat(psRspBuf,"\",\"");
		if (getPsmConfigCnf->requestedGprsReadyTimerPresent)
		{
			memset(tempBuf, 0, sizeof(tempBuf));
			if(convertDecIntToBinStr(getPsmConfigCnf->requestedGprsReadyTimer,(UINT8 *)tempBuf, 8)==TRUE)
			{
				strcat(psRspBuf, tempBuf);
			}

		}
		strcat(psRspBuf,"\",\"");

		if (getPsmConfigCnf->requestedPeriodicTauPresent)
		{
			memset(tempBuf, 0, sizeof(tempBuf));
			if(convertDecIntToBinStr(getPsmConfigCnf->requestedPeriodicTau,(UINT8 *)tempBuf, 8)==TRUE)
			{
				strcat(psRspBuf, tempBuf);
			}
		}
		strcat(psRspBuf,"\",\"");

		if (getPsmConfigCnf->requestedActiveTimePresent)
		{
			memset((void *)tempBuf, 0, sizeof(tempBuf));
			if(convertDecIntToBinStr(getPsmConfigCnf->requestedActiveTime,(UINT8 *)tempBuf, 8)==TRUE)
			{
				strcat(psRspBuf, tempBuf);
			}
		}
		strcat(psRspBuf,"\"");
		ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, psRspBuf );
	}
	else
	{
		checkPSRet(reqHandle, getPsmConfigCnf->rc);
	}
}

/****************************************************************
 *  F@: processGetEdrxConfigConf - Process CI cnf msg of AT+CEDRXS?
 */
static void processGetEdrxConfigConf(UINT32 reqHandle, const void *paras)
{
	CiPsPrimGetEdrxConfigCnf *getEdrxConfigCnf;
	char psRspBuf[50];
	char tempBuf[16];

	memset(psRspBuf, 0, sizeof(psRspBuf));
	memset(tempBuf, 0, sizeof(tempBuf));

	getEdrxConfigCnf = (CiPsPrimGetEdrxConfigCnf *)paras;


	if ( getEdrxConfigCnf->rc== CIRC_PS_SUCCESS )
	{
		sprintf(psRspBuf, "+CEDRXS: %d,\"", getEdrxConfigCnf->eDrxAct);

		/* display the location info only if regOption is CI_PS_NW_REG_IND_ENABLE_DETAIL */
		if (getEdrxConfigCnf->requestedEdrxValuePresent)
		{
			if(convertDecIntToBinStr(getEdrxConfigCnf->requestedEdrxValue&0x0F,(UINT8 *)tempBuf,4)==TRUE)
			{
				strcat(psRspBuf, tempBuf);

			}
		}
		strcat(psRspBuf,"\"");
		ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, psRspBuf );
	}
	else
	{
		checkPSRet(reqHandle, getEdrxConfigCnf->rc);
	}
}

/****************************************************************
 *  F@: processReadEdrxDynParaConf - Process CI cnf msg of AT+CEDRXRDP
 */
static void processReadEdrxDynParaConf(UINT32 reqHandle, const void *paras)
{
	CiPsPrimReadEdrxDynParaCnf *readEdrxDynParaCnf;
	char psRspBuf[50];
	char tempBuf[16];

	memset(psRspBuf, 0, sizeof(psRspBuf));
	memset(tempBuf, 0, sizeof(tempBuf));

	readEdrxDynParaCnf = (CiPsPrimReadEdrxDynParaCnf *)paras;


	if ( readEdrxDynParaCnf->rc== CIRC_PS_SUCCESS )
	{
		sprintf(psRspBuf, "+CEDRXRDP: %d", readEdrxDynParaCnf->eDrxAct);

		if(readEdrxDynParaCnf->eDrxAct == CIPS_EDRX_ACT_NONE)
		{
			ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, psRspBuf );
		}
		else
		{
			strcat(psRspBuf,",\"");
			if (readEdrxDynParaCnf->requestedEdrxValuePresent)
			{
				memset(tempBuf, 0, sizeof(tempBuf));
				if(convertDecIntToBinStr(readEdrxDynParaCnf->requestedEdrxValue&0x0F,(UINT8 *)tempBuf, 4)==TRUE)
				{
					strcat(psRspBuf, tempBuf);
				}

			}

			strcat(psRspBuf,"\",\"");

			if (readEdrxDynParaCnf->nwProvidedEdrxvaluePresent)
			{
				memset(tempBuf, 0, sizeof(tempBuf));
				if(convertDecIntToBinStr(readEdrxDynParaCnf->nwProvidedEdrxvalue&0x0F,(UINT8 *)tempBuf, 4)==TRUE)
				{
					strcat(psRspBuf, tempBuf);
				}

			}
			strcat(psRspBuf,"\",\"");

			if (readEdrxDynParaCnf->pagingTimerWindowPresent)
			{
				memset(tempBuf, 0, sizeof(tempBuf));
				if(convertDecIntToBinStr(readEdrxDynParaCnf->pagingTimerWindow&0x0F,(UINT8 *)tempBuf, 4)==TRUE)
				{
					strcat(psRspBuf, tempBuf);
				}

			}
			strcat(psRspBuf,"\"");
			ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, psRspBuf );
		}
	}
	else
	{
		checkPSRet(reqHandle, readEdrxDynParaCnf->rc);
	}
}

/****************************************************************
 *  F@: processGetSignallingConnectionStatusConf - Process CI cnf msg of AT+CSCON?
 */
static void processGetSignallingConnectionStatusConf(UINT32 reqHandle, const void *paras)
{
	CiPsPrimGetSignallingConnectionStatusCnf *getSignallingConnectionStatusCnf;
	char psRspBuf[100];
	char tempBuf[50];

	memset(psRspBuf, 0, sizeof(psRspBuf));
	memset(tempBuf, 0, sizeof(tempBuf));

	getSignallingConnectionStatusCnf = (CiPsPrimGetSignallingConnectionStatusCnf *)paras;


	if ( getSignallingConnectionStatusCnf->rc== CIRC_PS_SUCCESS )
	{
		sprintf(psRspBuf, "+CSCON: %d", getSignallingConnectionStatusCnf->option);

		/* display the location info only if regOption is CI_PS_NW_REG_IND_ENABLE_DETAIL */
		if (getSignallingConnectionStatusCnf->option == CIPS_CSCON_ENABLE_MODE)
		{
			sprintf(tempBuf, ",%d", getSignallingConnectionStatusCnf->mode);
		}else if (getSignallingConnectionStatusCnf->option == CIPS_CSCON_ENABLE_STATE)
		{

			if(getSignallingConnectionStatusCnf->statePresent == TRUE)
			{
				sprintf(tempBuf, ",%d,%d", getSignallingConnectionStatusCnf->mode,getSignallingConnectionStatusCnf->state);
			}else
			{
				sprintf(tempBuf, ",%d", getSignallingConnectionStatusCnf->mode);
			}
			strcat((char *)psRspBuf,(char *)tempBuf);
		}else if (getSignallingConnectionStatusCnf->option == CIPS_CSCON_ENABLE_ACCESS)
		{
			sprintf(tempBuf, ",%d", getSignallingConnectionStatusCnf->mode);
			strcat((char *)psRspBuf,(char *)tempBuf);

			if(getSignallingConnectionStatusCnf->statePresent == TRUE)
			{
				sprintf(tempBuf, ",%d", getSignallingConnectionStatusCnf->state);
			}
			strcat((char *)psRspBuf,(char *)tempBuf);


			if(getSignallingConnectionStatusCnf->accessPresent== TRUE)
			{
				if(getSignallingConnectionStatusCnf->statePresent == FALSE)
				{
					sprintf(tempBuf, ",");
					strcat((char *)psRspBuf,(char *)tempBuf);
				}

				sprintf(tempBuf, ",%d",getSignallingConnectionStatusCnf->access);
				strcat((char *)psRspBuf,(char *)tempBuf);
			}

		}
		ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, psRspBuf );
	}
	else
	{
		checkPSRet(reqHandle, getSignallingConnectionStatusCnf->rc);
	}
}

/****************************************************************
 *  F@: processGetInitialPdpActivationOptCnf - Process CI cnf msg of AT+CIPCA?
 */
static void processGetInitialPdpActivationOptCnf(UINT32 reqHandle, const void *paras)
{
	CiPsPrimGetInitialPdpActivationOptCnf *getInitialPdpActivationOptCnf;
	char psRspBuf[100];

	memset(psRspBuf, 0, sizeof(psRspBuf));

	getInitialPdpActivationOptCnf = (CiPsPrimGetInitialPdpActivationOptCnf *)paras;


	if ( getInitialPdpActivationOptCnf->rc== CIRC_PS_SUCCESS )
	{
		sprintf(psRspBuf, "+CIPCA: %d,%d", getInitialPdpActivationOptCnf->option,getInitialPdpActivationOptCnf->attachWithoutPdn);
		ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, psRspBuf );
	}
	else
	{
		checkPSRet(reqHandle, getInitialPdpActivationOptCnf->rc);
	}
}


/****************************************************************
 *  F@: processReadApnBackoffTimerDynParaConf - Process CI cnf msg of AT+CABTRDP=
 */
static void processReadApnBackoffTimerDynParaConf(UINT32 reqHandle, const void *paras)
{
	CiPsPrimReadApnBackoffTimerDynParaCnf *readApnBackoffTimerDynParaCnf;
	char AtRspBuf[200]="\0";
	char tempBuf[100]="\0";
	UINT8 i;

	memset(AtRspBuf, 0, sizeof(AtRspBuf));

	readApnBackoffTimerDynParaCnf = (CiPsPrimReadApnBackoffTimerDynParaCnf *)paras;


	if ( readApnBackoffTimerDynParaCnf->rc== CIRC_PS_SUCCESS )
	{
		 if(readApnBackoffTimerDynParaCnf->num > 0)
        {
            for(i = 0;i < readApnBackoffTimerDynParaCnf->num;i ++)
            {
            	sprintf((char *)AtRspBuf,"+CABTRDP: \"");

                memcpy( tempBuf, readApnBackoffTimerDynParaCnf->list[i].apn.valStr, readApnBackoffTimerDynParaCnf->list[i].apn.len);
				tempBuf[readApnBackoffTimerDynParaCnf->list[i].apn.len]='\0';
				strcat((char *)AtRspBuf,(char *)tempBuf);

				sprintf((char *)tempBuf,"\",%d",readApnBackoffTimerDynParaCnf->list[i].backoffTimerValue);
            	strcat((char *)AtRspBuf,(char *)tempBuf);

				if(readApnBackoffTimerDynParaCnf->list[i].reAttempPresent== TRUE)
				{
					sprintf(tempBuf, ",%d,%d",readApnBackoffTimerDynParaCnf->list[i].reAttemptRatIndication,readApnBackoffTimerDynParaCnf->list[i].reAttemptEplmnIndication);
					strcat((char *)AtRspBuf,(char *)tempBuf);
				}

				if(readApnBackoffTimerDynParaCnf->list[i].nslpiPresent == TRUE)
				{
					if(readApnBackoffTimerDynParaCnf->list[i].reAttempPresent == FALSE)
					{
						strcat((char *)AtRspBuf,",,");
					}

					sprintf(tempBuf, ",%d",readApnBackoffTimerDynParaCnf->list[i].nslpi);
					strcat((char *)AtRspBuf,(char *)tempBuf);
				}
				ATRESP( reqHandle, 0,0,(char *)AtRspBuf);

            }
        }
		ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
	}
	else
	{
		checkPSRet(reqHandle, readApnBackoffTimerDynParaCnf->rc);
	}
}

/****************************************************************
 *  F@: processGetApnRateControlCnf - Process CI cnf msg of AT+CGAPNRC=/ AT+CGAPNRC=?
 */
static void processGetApnRateControlCnf(UINT32 reqHandle, const void *paras)
{
	CiPsPrimGetApnRateControlCnf *getApnRateControlCnf;
	char AtRspBuf[100]="\0";
	char tmpBuf[50]="\0";
	UINT8 i;

	memset(AtRspBuf, 0, sizeof(AtRspBuf));

	getApnRateControlCnf = (CiPsPrimGetApnRateControlCnf *)paras;


	if ( getApnRateControlCnf->rc== CIRC_PS_SUCCESS )
	{
		if(getApnRateControlCnf->num > 0)
        {
        	if(GET_REQ_ID(reqHandle) == PRI_PS_PRIM_GET_APN_RATE_CONTROL_ACT_CID)
        	{
        		sprintf((char *)AtRspBuf,"+CGAPNRC: ");
				for(i = 0;i < getApnRateControlCnf->num;i ++)
				{
	        		if(i < getApnRateControlCnf->num - 1)
	                {
	                    sprintf((char *)tmpBuf,"%d,",getApnRateControlCnf->cid[i]+1);
	                }
	                else
	                {
	                    sprintf((char *)tmpBuf,"%d",getApnRateControlCnf->cid[i]+1);
	                }
               		strcat((char *)AtRspBuf,(char *)tmpBuf);
				}
				ATRESP( reqHandle, 0,0,(char *)AtRspBuf);
        	}
			else
			{
	            for(i = 0;i < getApnRateControlCnf->num;i ++)
	            {
	        		sprintf((char *)AtRspBuf,"+CGAPNRC: %d,%d,%d,%d",getApnRateControlCnf->cid[i],getApnRateControlCnf->list[i].addExceptionReports,
						getApnRateControlCnf->list[i].ulTimeUnit,getApnRateControlCnf->list[i].maxUlRate);
					ATRESP( reqHandle, 0,0,(char *)AtRspBuf);
	            }
			}
        }
		ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
	}
	else
	{
		checkPSRet(reqHandle, getApnRateControlCnf->rc);
	}
}

#ifdef CRANE_MCU_DONGLE
void processGetSysInfoCnf(UINT32 reqHandle, const void *paras)
{
	UINT16 network_status = 0;
       UINT16  NetworkCode = 0;
	char AtRspBuf[32] = { 0 };

	CiPsPrimGetNwRegStatusCnf *cnf = (CiPsPrimGetNwRegStatusCnf *)paras;

    if(cnf->nwRegInfo.act==2 || cnf->nwRegInfo.act==4 || cnf->nwRegInfo.act==5 || cnf->nwRegInfo.act==6){
        network_status = 3;
    } else if(cnf->nwRegInfo.act == 7){
        network_status = 4;
    } else{
        network_status = 2;
    }

    if( (cnf->nwRegInfo.status == 1) || (cnf->nwRegInfo.status == 5)){
        if(cnf->nwRegInfo.rplmnInfo.NetworkCode == 1
            || cnf->nwRegInfo.rplmnInfo.NetworkCode == 5
            || cnf->nwRegInfo.rplmnInfo.NetworkCode == 7){

            NetworkCode = 2;
        } else if(cnf->nwRegInfo.rplmnInfo.NetworkCode == 0
                || cnf->nwRegInfo.rplmnInfo.NetworkCode == 2
                || cnf->nwRegInfo.rplmnInfo.NetworkCode == 4
                || cnf->nwRegInfo.rplmnInfo.NetworkCode == 6){

             NetworkCode = 1;
        } else if(cnf->nwRegInfo.rplmnInfo.NetworkCode == 3){
            NetworkCode = 3;
        } else{
            NetworkCode = 0;
        }
        sprintf ( (char *)AtRspBuf,"$MYSYSINFO: %d,%02d",network_status,NetworkCode);
     }else{
         sprintf ( (char *)AtRspBuf,"$MYSYSINFO: %d,0",network_status);
     }
     ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0, AtRspBuf);
}

void processGet4GSysInfoCnf(UINT32 reqHandle, const void *paras)
{
	UINT16 network_status = 0;
    	UINT16  NetworkCode = 0;
	char AtRspBuf[32] = { 0 };

	CiPsPrimGet4GNwRegStatusCnf *cnf = (CiPsPrimGet4GNwRegStatusCnf *)paras;

    if(cnf->nwRegInfo.act==2 || cnf->nwRegInfo.act==4 || cnf->nwRegInfo.act==5 || cnf->nwRegInfo.act==6){
        network_status = 3;
    } else if(cnf->nwRegInfo.act == 7){
        network_status = 4;
    } else{
        network_status = 2;
    }

    if( (cnf->nwRegInfo.status == 1) || (cnf->nwRegInfo.status == 5)){
        if(cnf->nwRegInfo.rplmnInfo.NetworkCode == 1
            || cnf->nwRegInfo.rplmnInfo.NetworkCode == 5
            || cnf->nwRegInfo.rplmnInfo.NetworkCode == 7){

            NetworkCode = 2;
        } else if(cnf->nwRegInfo.rplmnInfo.NetworkCode == 0
                || cnf->nwRegInfo.rplmnInfo.NetworkCode == 2
                || cnf->nwRegInfo.rplmnInfo.NetworkCode == 4
                || cnf->nwRegInfo.rplmnInfo.NetworkCode == 6){

             NetworkCode = 1;
        } else if(cnf->nwRegInfo.rplmnInfo.NetworkCode == 3){
            NetworkCode = 3;
        } else{
            NetworkCode = 0;
        }
        sprintf ( (char *)AtRspBuf,"$MYSYSINFO: %d,%02d",network_status,NetworkCode);
     }else{
         sprintf ( (char *)AtRspBuf,"$MYSYSINFO: %d,0",network_status);
     }
     ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0, AtRspBuf);
}
#endif
#endif


/*new IP parser interface for usbnet*/

extern void DbgPrintf(char* fmt, ...);
UINT8 cgcontrdp_cid=0;
#ifndef MIN_SYS
#ifdef QUEC_NETDUALCH_CFG
extern quec_net_dualch_cfg_s_t g_quec_net_dualch_cfg[QUEC_NET_DUALCH_MAX-1];
#endif
#endif
void psCnf(CiSgOpaqueHandle opSgCnfHandle,
		CiServiceGroupID svgId,
		CiPrimitiveID    primId,
		CiRequestHandle  reqHandle,
		void*            paras)
{
    //UNUSEDPARAM(opSgCnfHandle)
	CiReturnCode                    ret = CIRC_SUCCESS;
	INT32                           i=0,j=0;

	CiPsPrimEnableNwRegIndCnf		*nwRegIndCnf=NULL;
	CiPsPrimGetNwRegStatusCnf		*nwRegStatusCnf=NULL;
	CiPsPrimDefinePdpCtxCnf         *defPdpCnf=NULL;
	CiPsPrimGetAttachStateCnf       *getAttachCnf=NULL;
	CiPsPrimSetAttachStateCnf       *setAttachCnf=NULL;
	CiPsPrimSetPdpCtxActStateCnf    *pdpActCnf=NULL;
	CiPsPrimEnterDataStateCnf       *enterDataCnf=NULL;
	CiPsPrimSetQosCnf               *setQosCnf=NULL;
	CiPsPrimDefineSecPdpCtxCnf      *defPdpSecCnf=NULL;
	CiPsPrimGet3GQosCnf             *getQos3GCnf=NULL;
	CiPsPrimSet3GQosCnf             *setQos3GCnf=NULL;
	CiPsPrimGetPdpCtxCnf            *getPdpPrimCnf=NULL;
	CiPsPrimGetSecPdpCtxCnf         *getPdpSecCnf=NULL;
	CiPsPrimGetQosCnf               *getQosCnf=NULL;
	CiPsPrimGetQosCapsCnf           *getQosCapsCnf=NULL;
	CiPsPrimGet3GQosCapsCnf         *get3GQosCapsCnf=NULL;
	CiPsPrimGetPdpCtxReq     *getNxtPdpCtxReq=NULL;
	CiPsPrimGetQosReq        *getQosReq=NULL;
	CiPsPrimGet3GQosReq      *getQos3GReq=NULL;
	CiPsPrimGetPdpCtxReq  *getPdpCtxReq=NULL;
	CiPsPrimGetSecPdpCtxReq        *getSecPdpReq=NULL;
    CiPsPrimModifyPdpCtxCnf			*modifyPdpCtxCnf=NULL;//Added by Michal Buaki
	CiPsPrimGetPdpCtxsActStateCnf	*getCtxAtcListCnf=NULL;//Added by Michal Bukai
	/*Added by Michal Bukai - CGTFT support - START*/
	CiPsPrimDefineTftFilterCnf	*defineTftFilterCnf=NULL;
	CiPsPrimDeleteTftCnf 		*deleteTftCnf=NULL;
	CiPsPrimGetTftCnf 			*getTftCnf=NULL;
	CiPsPrimGetTftReq	*getTftReq=NULL;
	CiPsPrimFastDormantCnf *getFastDormancyCnf=NULL;
	CiPsPrimAuthenticateCnf *getAuthenticateCnf=NULL;

	/*Added by Michal Bukai - CGTFT support - END*/
	/* Added by Daniel for LTE PC AT command server 20120301, begin */
	CiPsPrimGet4GQosCnf            *get4GQoSCnf=NULL;
	CiPsPrimGet4GQosCapsCnf        *get4GQosCapsCnf=NULL;
	CiPsPrimSet4GQosCnf            *set4GQosCnf=NULL;

    CiPsPrimSet4GEventRepCnf       *set4GEventRepCnf=NULL;
	CiPsPrimGet4GEventRepCnf       *get4GEventRepCnf=NULL;
	CiPsPrimGet4GEventRepCapsCnf   *get4GEventRepCapsCnf=NULL;

	CiPsPrimRead4GPdpCtxDynParaCnf *read4GPdpCtxDynParaCnf=NULL;
    CiPsPrimRead4GPdpCtxsActDynParaCnf *read4GPdpCtxsActDynParaCnf=NULL;
	CiPsPrimRead4GPdpCtxDynParaReq *read4GPdpCtxDynParaReq=NULL;

	CiPsPrimRead4GSecPdpCtxDynParaCnf *read4GSecPdpCtxDynParaCnf=NULL;
    CiPsPrimRead4GSecPdpCtxsActDynParaCnf *read4GSecPdpCtxsActDynParaCnf=NULL;

	CiPsPrimSet4GVoiceCallModeCnf  *set4GVoiceCallModeCnf=NULL;
	CiPsPrimGet4GVoiceCallModeCnf  *get4GVoiceCallModeCnf=NULL;
	CiPsPrimGet4GVoiceCallModeCapsCnf *get4GVoiceCallModeCapsCnf=NULL;

	CiPsPrimRead4GQosDynParaCnf    *read4GQosDynParaCnf=NULL;
    CiPsPrimRead4GQosDynParaCapsCnf *read4GQosDynParaCapsCnf=NULL;

	CiPsPrimRead4GTrafficFlowTempDynParaCnf *read4GTFTDynParaCnf=NULL;
	CiPsPrimRead4GTrafficFlowTempDynParaCapsCnf *read4GTFTDynParaCapsCnf=NULL;

	CiPsPrimGet4GModeCapsCnf       *get4GModeCapsCnf=NULL;
    CiPsPrimSet4GModeCnf           *set4GModeCnf=NULL;
    CiPsPrimGet4GModeCnf           *get4GModeCnf=NULL;

	CiPsPrimGetPdpAddrListCnf *getPdpAddrListCnf=NULL;
	CiPsPrimGetPdpAddrCnf     *getPdpAddrCnf=NULL;

    CiPsPrimEnable4GNwRegIndCnf *enable4GNwRegIndCnf=NULL;
	CiPsPrimGetImsRegInfoCnf *getImsRegStatusCnf=NULL;
    CiPsPrimGet4GNwRegStatusCnf *get4GNwRegStatusCnf=NULL;
    CiPsPrimGetGsmGprsClassCnf      *getGsmGprsClassCnf=NULL;
    CiPsPrimGetGsmGprsClassesCnf    *getGsmGprsClassesCnf=NULL;
    CiPsPrimSetGsmGprsClassCnf      *setGsmGprsClassCnf=NULL;
	CiPsPrimDefineDefaultPdpCtxCnf  *defineDefaultPdpCtxCnf=NULL;
	CiPsPrimDefineDefaultPdpCtxCnf  *setltedefalutpdpcnf=NULL;
	CiPsPrimGetDefaultPdpCtx        *getltedefalutpdpcnf=NULL;
	CiPsPrimGetDefaultPdpCtxCnf  *getDefaultPdpCtxCnf=NULL;

	CiPsPrimSetDefaultPdpAuthenticateCnf    *setDefPdpAuthCnf;
	CiPsPrimGetDefaultPdpAuthenticateCnf    *getDefPdpAuthCnf;

	CiPsPrimSetVoiceDomainPreferenceCnf *setVoiceDomainPreferenceCnf;
	CiPsPrimGetVoiceDomainPreferenceCnf *getVoiceDomainPreferenceCnf;

	CiPsPrimSetEpsUsageSettingCnf *setEpsUsageSettingCnf;
	CiPsPrimGetEpsUsageSettingCnf *getEpsUsageSettingCnf;

	CiPsPrimSetAclCnf	*setAclCnf=NULL;
	CiPsPrimSetPsServiceDomainCnf  *sepadomaincnf=NULL;
	CiPsPrimGetPsServiceDomainCnf  *gepadomaincnf=NULL;
	/* Added by Daniel for LTE PC AT command server 20120301, end */
	CiPsPrimSetApnCnf    *setApnCnf=NULL;
	CiPsPrimGetApnCnf    *getApnCnf=NULL;
	CiPsPrimSetImsRegStateCnf *setImsRegStateCnf;
	CiPsPrimSetImsServiceStatusCnf *setImsSrvStatusCnf;

	CiPsPrimSetImsVoiceCallAvailabilityCnf *setImsVoiceCallAvailabilityCnf;
	CiPsPrimGetImsVoiceCallAvailabilityCnf *getImsVoiceCallAvailabilityCnf;
	CiPsPrimSetImsSmsAvailabilityCnf *setImsSmsAvailabilityCnf;
	CiPsPrimGetImsSmsAvailabilityCnf *getImsSmsAvailabilityCnf;

	CiPsPrimSetMmImsVoiceTerminationCnf *setMmImsVoiceTerminationCnf;
	CiPsPrimGetMmImsVoiceTerminationCnf *getMmImsVoiceTerminationCnf;
	CiPsPrimDeletePdpCtxCnf   *deletePdpCtxCnf;
	CiPsPrimDeleteSecPdpCtxCnf *deleteSecPdpCtxCnf;
	CiPsPrimSetPsmConfigCnf *setPsmConfigCnf;
	CiPsPrimSetEdrxConfigCnf *setEdrxConfigCnf;

	CiPsPrimSetCiotConfigCnf *setCiotConfigCnf;
	CiPsPrimGetCiotConfigCnf *getCiotConfigCnf;

	CiPsPrimConfigSignallingConnectionCnf *configSignallingConnectionCnf;
	CiPsPrimSetInitialPdpActivationOptCnf *setInitialPdpActivationOptCnf;

	CiPsPrimSetApnBackoffTimerStatusCnf *setApnBackoffTimerStatusCnf;
	CiPsPrimGetApnBackoffTimerStatusCnf *getApnBackoffTimerStatusCnf;

    char *AtRspBuf=NULL;
    char *TempBuf=NULL;
    UINT8                           atpIdx=0;
    UINT8                           cid=0;
    UINT8                           currCid=0;
    UINT8                           nextCid=0;
    CiPs3GQosType                   qosType=0;
	UINT16    pdp_addr=0;
	UINT16 add_len=0;
	CHAR mask_addr[512];
	AtciCurrentSetCntx *p_cInfo;
	int *pCurrentPSRegOption, *p4GCurrentPSRegOption;
	int pSRequestedRegOption, pS4GRequestedRegOption;
	int *pCurrentPSRegStatus, *pCurrent4gPSRegStatus;
	int *pPsActDetail;
	char *pPdpErrCauseBuf;
	int *pQueryCidAddrCount, *pQueryCidAddrNum, *pCgpaddrCidArray;
	BOOL *pQueryAllCid;
	int *pGetEutranVoiceDomainPreference;
	UINT8 pdp_table_index=0;
	UINT32 atHandle = GET_AT_HANDLE(reqHandle);
	char *classes[4] = {"A","B","CG","CC"};
	UINT32 sAtpIndex = GET_ATP_INDEX( atHandle );    
    int idx = isIMSChannel(sAtpIndex); 
#if QUEC_DEFAULT_AUTH_CHECK_SUPPORT
    UINT8 quec_sim_id=GET_SIM1_FLAG(reqHandle);
#endif
#ifndef SINGLE_SIM
	if (!GET_SIM1_FLAG(reqHandle)) {
		#ifndef LTEONLY_THIN
		pCurrentPSRegOption = &gCurrentPSRegOption[idx];
		pSRequestedRegOption = gPSRequestedRegOption[idx];
		#endif
		p4GCurrentPSRegOption = &g4gCurrentPSRegOption[idx];
		pS4GRequestedRegOption = g4gPSRequestedRegOption[idx];
		pCurrentPSRegStatus = &gCurrentPSRegStatus;
		pCurrent4gPSRegStatus = &g4gCurrentPSRegStatus;
		pPsActDetail = &gPsActDetail;
		pPdpErrCauseBuf = gPdpErrCauseBuf;
		p_cInfo = gCIDList.cInfo;
		pQueryCidAddrCount = &gQueryCidAddrCount;
		pQueryCidAddrNum = &gQueryCidAddrNum;
		pCgpaddrCidArray = gCgpaddrCidArray;
		pQueryAllCid = &gQueryAllCid;
		pGetEutranVoiceDomainPreference = &gGetEutranVoiceDomainPreference;
	} else {
		#ifndef LTEONLY_THIN
		pCurrentPSRegOption = &gCurrentPSRegOption_1[idx];
		pSRequestedRegOption = gPSRequestedRegOption_1[idx];
		#endif
		p4GCurrentPSRegOption = &g4gCurrentPSRegOption_1[idx];
		pS4GRequestedRegOption = g4gPSRequestedRegOption_1[idx];
		pCurrentPSRegStatus = &gCurrentPSRegStatus_1;
		pCurrent4gPSRegStatus = &g4gCurrentPSRegStatus_1;
		pPsActDetail = &gPsActDetail_1;
		pPdpErrCauseBuf = gPdpErrCauseBuf_1;
		p_cInfo = gCIDList.cInfo_1;
		pQueryCidAddrCount = &gQueryCidAddrCount_1;
		pQueryCidAddrNum = &gQueryCidAddrNum_1;
		pCgpaddrCidArray = gCgpaddrCidArray_1;
		pQueryAllCid = &gQueryAllCid_1;
		pGetEutranVoiceDomainPreference = &gGetEutranVoiceDomainPreference_1;
	}
#else
	#ifndef LTEONLY_THIN
	pCurrentPSRegOption = &gCurrentPSRegOption[idx];
	pSRequestedRegOption = gPSRequestedRegOption[idx];
	#endif
	p4GCurrentPSRegOption = &g4gCurrentPSRegOption[idx];
	pS4GRequestedRegOption = g4gPSRequestedRegOption[idx];
	pCurrentPSRegStatus = &gCurrentPSRegStatus;
	pCurrent4gPSRegStatus = &g4gCurrentPSRegStatus;
	pPsActDetail = &gPsActDetail;
	pPdpErrCauseBuf = gPdpErrCauseBuf;
	p_cInfo = gCIDList.cInfo;
	pQueryCidAddrCount = &gQueryCidAddrCount;
	pQueryCidAddrNum = &gQueryCidAddrNum;
	pCgpaddrCidArray = gCgpaddrCidArray;
	pQueryAllCid = &gQueryAllCid;
	pGetEutranVoiceDomainPreference = &gGetEutranVoiceDomainPreference;
	
#endif

	memset(mask_addr, 0, sizeof(mask_addr));

	DBGMSG("psCnf: reqHandle(%d), primId(%d).\n", reqHandle, primId);

#ifndef LWIP_IPNETBUF_SUPPORT
	extern int ModemCiPrimitiveCnfFileter(CiServiceGroupID id,CiPrimitiveID primId,CiRequestHandle reqHandle,void* paras);

  	if(ModemCiPrimitiveCnfFileter(svgId,primId, reqHandle, paras)==1)
  	{
		/* free up the confirmation memory */
		atciSvgFreeCnfMem( svgId, primId, paras);
		return;
  	}
#endif

	/* Added by Daniel for LTE PC AT command server 20120307, begin */
    AtRspBuf = (char *)utlMalloc( 1000);
	if( AtRspBuf == NULL )
	{
		atciSvgFreeCnfMem( svgId, primId, paras);
		return ;
	}

	TempBuf = (char *)utlMalloc( 1000);
	if( TempBuf == NULL )
	{
		utlFree(AtRspBuf);
		atciSvgFreeCnfMem( svgId, primId, paras);
		return ;
	}

	memset(AtRspBuf,0,1000); //P140322-01082
	memset(TempBuf,0,1000); //P140322-01082

	/* Added by Daniel for LTE PC AT command server 20120307, end */

	/*
	 **  Determine the primitive being confirmed.
	 */
	switch(primId)
	{
#ifndef LTEONLY_THIN
		case CI_PS_PRIM_ENABLE_NW_REG_IND_CNF:
		{
			nwRegIndCnf = (CiPsPrimEnableNwRegIndCnf *)paras;
			DBGMSG("%s: CI_PS_PRIM_ENABLE_NW_REG_IND_CNF reqHandle = %d.\n", __FUNCTION__, reqHandle);
			if ( nwRegIndCnf->rc == CIRC_PS_SUCCESS )
			{
				#ifdef LWIP_IPNETBUF_SUPPORT
				update3GPsRegOption(reqHandle);
				#else
				*pCurrentPSRegOption = pSRequestedRegOption;
                save3GOption(GET_SIM1_FLAG(atHandle), idx, 1, pSRequestedRegOption);
                CPUartLogPrintf("%s:  CI_PS_PRIM_ENABLE_NW_REG_IND_CNF set pPSRequestedRegOption as %d", __FUNCTION__, pSRequestedRegOption);                       
				#endif
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, 0);
			}
			else
				checkPSRet(reqHandle, nwRegIndCnf->rc);
			break;
		}
		case CI_PS_PRIM_GET_NW_REG_STATUS_CNF:
		{
			nwRegStatusCnf = (CiPsPrimGetNwRegStatusCnf *)paras;
			if ( nwRegStatusCnf->rc == CIRC_PS_SUCCESS )
			{
				#ifndef MIN_SYS
				#ifdef QUECTEL_OPEN_CPU
				if(!IsMiniSystem()){
					quec_nw_event_ind(GET_AT_HANDLE(reqHandle),paras,QUEC_NW_CMD_RESP_DATE_REG_STATUS_NO_LTE);
				}
				#endif
				#endif
				switch (GET_REQ_ID(reqHandle))
				{
					 #ifdef CRANE_MCU_DONGLE
					 case CI_PS_PRIM_GET_SYSINFO_NW_REG_STATUS_REQ:
					 {
						processGetSysInfoCnf(reqHandle, paras);
						break;
					 }
					 #endif
					 case CI_PS_PRIM_GET_NW_REG_STATUS_REQ:
					 {
                         CPUartLogPrintf("%s:  *pCurrentPSRegOption %d", __FUNCTION__, *pCurrentPSRegOption); 

                        
						#ifdef PPP_ENABLE
						if(isHandleForMasterSim(atHandle))
							modem_update_reg_option(GET_ATP_INDEX(atHandle), *pCurrentPSRegOption);
						#endif

						#ifdef LWIP_IPNETBUF_SUPPORT
						updateCgregStatus(atHandle, nwRegStatusCnf->nwRegInfo.status);
						updatePsRegDetail(atHandle, &(nwRegStatusCnf->nwRegInfo));
					       checkNWRegStatus(atHandle);
						#endif

						*pCurrentPSRegStatus = nwRegStatusCnf->nwRegInfo.status;
						/* this must be received for an AT+CGREG? command */
						sprintf(AtRspBuf, "+CGREG: %d,%d", *pCurrentPSRegOption, nwRegStatusCnf->nwRegInfo.status);

						/* display the location info only if regOption is CI_PS_NW_REG_IND_ENABLE_DETAIL */
						if (( *pCurrentPSRegOption == CI_PS_NW_REG_IND_ENABLE_DETAIL ) &&
						    ( nwRegStatusCnf->nwRegInfo.lacPresent == TRUE ))
						{
							*pPsActDetail = nwRegStatusCnf->nwRegInfo.act;
							sprintf(TempBuf, ",\"%04x\",\"%08x\",%d,%d", nwRegStatusCnf->nwRegInfo.lac,
									nwRegStatusCnf->nwRegInfo.cellId, *pPsActDetail, nwRegStatusCnf->nwRegInfo.rac);
							strcat(AtRspBuf, TempBuf);
						}
						else if ( *pCurrentPSRegOption == CI_PS_NW_REG_IND_ENABLE_MORE_DETAIL )
						{
							if(nwRegStatusCnf->nwRegInfo.lacPresent == TRUE)
							{
								*pPsActDetail = nwRegStatusCnf->nwRegInfo.act;
								sprintf(TempBuf, ",\"%04x\",\"%08x\",%d,%d", nwRegStatusCnf->nwRegInfo.lac, nwRegStatusCnf->nwRegInfo.cellId,
										*pPsActDetail, nwRegStatusCnf->nwRegInfo.rac);
								strcat(AtRspBuf, TempBuf);
							}
							if(nwRegStatusCnf->nwRegInfo.causePresent == TRUE)
							{
								if(nwRegStatusCnf->nwRegInfo.lacPresent == FALSE)
								{
									sprintf(TempBuf, ",,,,");
									strcat(AtRspBuf, TempBuf);
								}
								sprintf(TempBuf, ",%d,%d", nwRegStatusCnf->nwRegInfo.causeType, nwRegStatusCnf->nwRegInfo.rejectCause);
								strcat(AtRspBuf, TempBuf);
							}
						}
						ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, AtRspBuf);

						break;
					}
					default:
						ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
						break;
				}
			}
			else
			{
				checkPSRet(reqHandle, nwRegStatusCnf->rc);
			}
			break;
		}
#endif
		case CI_PS_PRIM_GET_ATTACH_STATE_CNF:
		{
			getAttachCnf = (CiPsPrimGetAttachStateCnf *)paras;
			DBGMSG("%s: CI_PS_PRIM_GET_ATTACH_STATE_CNF reqHandle = %d.\n", __FUNCTION__, reqHandle);
			if ( getAttachCnf->rc == CIRC_PS_SUCCESS )
			{
				extern INT32 CGATT_CGATTEX_FLAG;
				#ifndef MIN_SYS
				if (!IsMiniSystem()) 
				{//MiniSystem
							
					#ifdef QUECTEL_AT_COMMAND
						if(CGATT_CGATTEX_FLAG==1)
						{
							sprintf( (char *)AtRspBuf, "+CGATTEX: %d\r\n", getAttachCnf->state );
						}else{
							sprintf( (char *)AtRspBuf, "+CGATT: %d\r\n", getAttachCnf->state );
						}
					#else
						sprintf( (char *)AtRspBuf, "+CGATT: %d\r\n", getAttachCnf->state );
					#endif
						ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, (char *)AtRspBuf);
					#ifdef QUECTEL_AT_COMMAND
						CGATT_CGATTEX_FLAG=0;
					#endif
				}//MiniSystem
				#endif /*MIN_SYS*/

			}
			else
			{
				checkPSRet(reqHandle, getAttachCnf->rc);
			}

			break;
		}

		case CI_PS_PRIM_SET_ATTACH_STATE_CNF:
		{
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
		
			setAttachCnf = (CiPsPrimSetAttachStateCnf *)paras;
			if( setAttachCnf->rc == CIRC_PS_SUCCESS )
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
#ifdef QUECTEL_NETWORK_SUPPORT
				if (GET_REQ_ID(reqHandle) == PRI_PS_PRIM_SET_DETACH_STATE_REQ)
				{
					/*Report +CGEV */
			     #ifdef QUECTEL_NETWORK_SUPPORT //connor.wu 2018/11/29 fix the bug of use the wrong athandle here need use IND_REQ_HANDLE
				    ATRESP( IND_REQ_HANDLE, 0, 0, (char*)"+CGEV: ME DETACH");
#ifndef QUECTEL_CGEV_NOT_SHOW  //evin  20210427 fix at+cgatt=0;+CGEV: ME DETACH report twice.
				 	char atBuf[50] = {0};
					sprintf(atBuf, "+CGEV: ME DETACH");
					if(quectel_read_urc_ind_flag(QUECTEL_URC_ALL_IND))
					{
					#if QUEC_DUAL_SIM_SUPPORT
						if(cgerep_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].mode==1 ||
						   cgerep_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].mode==2)
					#else	
						if(cgerep_info.mode==1 ||cgerep_info.mode==2) //connor.wu 2018/11/29  when mode=1/2 open the Packet Domain Event Reporting
					#endif	
						{
					       (void)at_urc_send(NUM_OF_TEL_ATP, (uint8 *)atBuf, strlen(atBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
						}
					}
#endif
			     #else
					ATRESP( reqHandle, 0, 0, (char*)"+CGEV: ME DETACH");
				 #endif
					/*
					**  Flag all CIDs not in use
					*/
					resetCidList(reqHandle);
					resetDefaultCidReplaceFlag();
				}
#endif
			}
			else
			{
				checkPSRet(reqHandle, setAttachCnf->rc);
			}
			#ifdef QUECTEL_AT_COMMAND
			CGATT_CGATTEX_FLAG=0;
			#endif
}//MiniSystem
else
{
			setAttachCnf = (CiPsPrimSetAttachStateCnf *)paras;
			if( setAttachCnf->rc == CIRC_PS_SUCCESS )
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				checkPSRet(reqHandle, setAttachCnf->rc);
			}

}
#endif /*MIN_SYS*/
			break;
		}

		case CI_PS_PRIM_DEFINE_PDP_CTX_CNF:
		{
			defPdpCnf = (CiPsPrimDefinePdpCtxCnf *)paras;
	        atpIdx = GET_ATP_INDEX(reqHandle);
			if(gCIDList.currCntx[atpIdx].currCid >= CI_PS_MAX_CID)
			{
				resetCurrCntx(atpIdx);
				ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				break;
			}

			if ( defPdpCnf->rc == CIRC_PS_SUCCESS )
			{
				pdp_table_index = getPdpIndexByCid(gCIDList.currCntx[atpIdx].currCid,p_cInfo);

				CPUartLogPrintf("CI_PS_PRIM_DEFINE_PDP_CTX_CNF: pdp_table_index %d, REQ_ID %d", pdp_table_index, GET_REQ_ID(reqHandle));
				/* this was sent when an enter data was requested with no PDP context defined */
				if ( GET_REQ_ID(reqHandle) == CI_PS_PRIM_ENTER_DATA_STATE_REQ )
				{
					/* mark connection waiting to enter the data mode */

					CiPsPrimEnterDataStateReq       *pdpEnterDataReq;
					pdpEnterDataReq = (CiPsPrimEnterDataStateReq *)gCIDList.currCntx[atpIdx].reqMsg;
					if (pdpEnterDataReq == NULL)
					{
						resetCurrCntx(atpIdx);
						ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, CME_UNKNOWN, NULL);
					}
					else
					{
						if(pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
						{
							pdp_table_index = getFreePdpIndexFromTable(p_cInfo);
							if (pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
                    		{
                    		    ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, 0);
                    			break;
                    		}
						}
						p_cInfo[pdp_table_index].bDefined = TRUE;
						p_cInfo[pdp_table_index].cid = gCIDList.currCntx[atpIdx].currCid;
						gCIDList.currCntx[atpIdx].reqMsg = NULL;

						/* make request to activate context and enter data mode */
						ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_ENTER_DATA_STATE_REQ,
							   reqHandle, (void *)pdpEnterDataReq );
					}
				}
				else if (GET_REQ_ID(reqHandle) == CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ)
				{
					CiPsPrimSetPdpCtxActStateReq *setActStateReq;
					setActStateReq = (CiPsPrimSetPdpCtxActStateReq *)gCIDList.currCntx[atpIdx].reqMsg;
					if (setActStateReq == NULL)
					{
						resetCurrCntx(atpIdx);
						ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, CME_UNKNOWN, NULL);
					}
					else
					{
						if(pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
						{
							pdp_table_index = getFreePdpIndexFromTable(p_cInfo);
							if (pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
                    		{
                    		    ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, 0);
                    			break;
                    		}
						}
						p_cInfo[pdp_table_index].bDefined = TRUE;
						p_cInfo[pdp_table_index].cid = gCIDList.currCntx[atpIdx].currCid;
						gCIDList.currCntx[atpIdx].reqMsg = NULL;

						/* make request to activate context */
						ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ,
							   reqHandle, (void *)setActStateReq );
					}
				}
#ifdef QUECTEL_PROJECT_CUST    //Bug #109660 STASR1602-404
				else if (GET_REQ_ID(reqHandle) == CI_PS_PRIM_AUTHENTICATE_REQ)
				{
					CiPsPrimAuthenticateReq *pdpAuthReq = NULL;
					pdpAuthReq = (CiPsPrimAuthenticateReq *)gCIDList.currCntx[atpIdx].reqMsg;
					if (pdpAuthReq == NULL)
					{
						resetCurrCntx(atpIdx);
						ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, CME_UNKNOWN, NULL);
					}
					else
					{
						CiPsPrimSetPdpCtxActStateReq *setActStateReq = NULL;
						
						if(pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
						{
							pdp_table_index = getFreePdpIndexFromTable(p_cInfo);
							if (pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
							{
								ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, 0);
								break;
							}
						}

						setActStateReq = (CiPsPrimSetPdpCtxActStateReq*)utlCalloc(1, sizeof(CiPsPrimSetPdpCtxActStateReq));
						if (setActStateReq == NULL)
						{
							resetCurrCntx(atpIdx);
							ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, CME_UNKNOWN, NULL);
						}

						setActStateReq->state = 1;
						setActStateReq->cid = gCIDList.currCntx[atpIdx].currCid;
						setActStateReq->doAll = 0;
						setActStateReq->l2p = CI_PS_L2P_NONE;
						
						p_cInfo[pdp_table_index].bDefined = TRUE;
						p_cInfo[pdp_table_index].cid = gCIDList.currCntx[atpIdx].currCid;
						gCIDList.currCntx[atpIdx].reqMsg = setActStateReq;

						/* make request to set auth context */
						ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_AUTHENTICATE_REQ,
							   MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ), (void *)pdpAuthReq );
					}
				}
#endif
				else
				{
					if(pdp_table_index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
					{
						p_cInfo[pdp_table_index].bDefined = TRUE;
						p_cInfo[pdp_table_index].cid = gCIDList.currCntx[atpIdx].currCid;
					}
					else
						pdp_table_index = 0;
					ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
				}
			}
			else
			{
#ifdef LWIP_IPNETBUF_SUPPORT
				/*ignore the error return, just return OK*/
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
				if (GET_REQ_ID(reqHandle) == CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ || GET_REQ_ID(reqHandle) == CI_PS_PRIM_ENTER_DATA_STATE_REQ)
					resetCurrCntx(atpIdx);

#else
				/* reset PS related info */
				resetCurrCntx(atpIdx);
				/* Save PDP activation fail cause in local variable */
				getPdpErrCauseString(defPdpCnf->rc, pPdpErrCauseBuf);

				checkPSRet(reqHandle, defPdpCnf->rc);
#endif

			}

			break;
		}

		case CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_CNF:
		{
			UINT8 currCid;
			pdpActCnf = (CiPsPrimSetPdpCtxActStateCnf *)paras;
			DBGMSG("[%s]:line(%d), CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_CNF received.\n", __FUNCTION__, __LINE__ );
			DBGMSG("[%s]:line(%d), pdpActCnf->rc(%d).\n", __FUNCTION__, __LINE__, pdpActCnf->rc );
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem

			currCid = gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid;
			telPsPdpCtx *psPdpInfo = telGetPdpCtx(currCid);
			//quectel modification: jensen.fang 20190124, added rc to log
			CPUartLogPrintf("CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_CNF: currCid=%d, rc(%d)", currCid, pdpActCnf->rc);

			if(currCid >= CI_PS_MAX_CID)
			{
				resetCurrCntx(GET_ATP_INDEX(reqHandle));
				ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				break;
			}

			if ( pdpActCnf->rc == CIRC_PS_SUCCESS )
			{

				DBGMSG("[%s]:line(%d), currCid(%d), reqHandle(%d).\n", __FUNCTION__, __LINE__, currCid, reqHandle);

				if (GET_REQ_ID(reqHandle) == PRI_PS_PRIM_SET_PDP_CTX_DEACT_STATE_REQ)
				{
					if(psPdpInfo != NULL)
					    psPdpInfo->activedStatus = 0;

					resetCurrCntx(GET_ATP_INDEX(reqHandle));
#ifdef QUECTEL_NETWORK_SUPPORT
					telSetPdpActivedFlag(currCid, FALSE);
#endif 

					ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL); //OK for AT+CGACT=0,*

                /* After PDP activated, obtained IP address, bind netif */
				}
				else    /*Save the current Handle */
				{
					if(psPdpInfo != NULL)
					    psPdpInfo->activedStatus = 1;
					pdp_table_index = getPdpIndexByCid(currCid,p_cInfo);
					if(pdp_table_index >= CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
				        break;
					p_cInfo[pdp_table_index].reqHandle = reqHandle;
#ifdef QUECTEL_NETWORK_SUPPORT
					telSetPdpActivedFlag(currCid, TRUE);
#endif
					ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
#ifdef LWIP_IPNETBUF_SUPPORT
					sendQueryCgdcont(reqHandle);
#endif
				}
			}
#ifdef QUECTEL_NETWORK_SUPPORT 
			else if ( pdpActCnf->rc == CI_PS_ESM_LAST_PDN_DISCONNECTION_NOT_ALLOWED )
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
#endif
			else
			{
				resetCurrCntx(GET_ATP_INDEX(reqHandle));

				/* Save PDP activation fail cause in local variable */
				getPdpErrCauseString(pdpActCnf->rc, pPdpErrCauseBuf);

				checkPSRet(reqHandle, pdpActCnf->rc);
			}
}//MiniSystem
else
{
			currCid = gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid;

			if(currCid >= CI_PS_MAX_CID)
			{
				resetCurrCntx(GET_ATP_INDEX(reqHandle));
				ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				break;
			}

			if ( pdpActCnf->rc == CIRC_PS_SUCCESS )
			{

				DBGMSG("[%s]:line(%d), currCid(%d), reqHandle(%d).\n", __FUNCTION__, __LINE__, currCid, reqHandle);

				if (GET_REQ_ID(reqHandle) == PRI_PS_PRIM_SET_PDP_CTX_DEACT_STATE_REQ)
				{

					resetCurrCntx(GET_ATP_INDEX(reqHandle));

					ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL); //OK for AT+CGACT=0,*
				}
				else    /*Save the current Handle */
				{
					pdp_table_index = getPdpIndexByCid(currCid,p_cInfo);
					ASSERT(pdp_table_index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM);
					p_cInfo[pdp_table_index].reqHandle = reqHandle;
					ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
#ifdef LWIP_IPNETBUF_SUPPORT
					telSetPdpActivedFlag(currCid, TRUE);
					sendQueryCgdcont(reqHandle);
#endif
				}
			}
			else
			{
				resetCurrCntx(GET_ATP_INDEX(reqHandle));

				/* Save PDP activation fail cause in local variable */
				getPdpErrCauseString(pdpActCnf->rc, pPdpErrCauseBuf);

				checkPSRet(reqHandle, pdpActCnf->rc);
			}
}
#endif /*MIN_SYS*/
			break;
		}

		case CI_PS_PRIM_ENTER_DATA_STATE_CNF:
		{
			DBGMSG("[%s]:line(%d), CI_PS_PRIM_ENTER_DATA_STATE_CNF received.\n", __FUNCTION__, __LINE__ );
			enterDataCnf = (CiPsPrimEnterDataStateCnf *)paras;
			DBGMSG("[%s]:line(%d), enterDataCnf->rc(%d).\n", __FUNCTION__, __LINE__, enterDataCnf->rc );

			cid = gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid;
			telPsPdpCtx *psPdpInfo = telGetPdpCtx(cid);

			if(cid >= CI_PS_MAX_CID)
			{
				resetCurrCntx(GET_ATP_INDEX(reqHandle));
				ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				break;
			}
			if ( enterDataCnf->rc == CIRC_PS_SUCCESS )
			{
				pdp_table_index = getPdpIndexByCid(cid,p_cInfo);
				if(pdp_table_index >= CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
			        break;

				p_cInfo[pdp_table_index].reqHandle = reqHandle;

				if (bLocalTest)
				{
					/* Try to obtain the IP address information for the activated CID*/
					getPdpCtxReq = utlCalloc(1, sizeof(*getPdpCtxReq));
					if (getPdpCtxReq == NULL) {
						ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						break;
					}
					getPdpCtxReq->cid = cid;
					ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ,
						MAKE_CI_REQ_HANDLE(GET_AT_HANDLE(reqHandle), CI_PS_PRIM_GET_PDP_CTX_REQ), (void *)getPdpCtxReq);
				}
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
				
#ifdef QUECTEL_NETWORK_SUPPORT
				telSetPdpActivedFlag(cid, TRUE);
#endif
}//MiniSystem
#endif /*MIN_SYS*/

#ifdef LWIP_IPNETBUF_SUPPORT
                if(psPdpInfo != NULL)
				    psPdpInfo->activedStatus = 1;

				sendQueryCgdcont(reqHandle);
#endif
			}
			else
			{
				resetCurrCntx(GET_ATP_INDEX(reqHandle));
				/* Save PDP activation fail cause in local variable */
				getPdpErrCauseString(enterDataCnf->rc, pPdpErrCauseBuf);

				checkPSRet(reqHandle, enterDataCnf->rc);
			}

			break;
		}
#ifdef LWIP_IPNETBUF_SUPPORT
		case CI_PS_PRIM_ACTIVATE_RECONF_PDP_CTX_CNF:
		{
			UINT8 currCid;
			pdpActCnf = (CiPsPrimSetPdpCtxActStateCnf *)paras;
			DBGMSG("[%s]:line(%d), CI_PS_PRIM_ACTIVATE_RECONF_PDP_CTX_CNF received.", __FUNCTION__,__LINE__ );
			DBGMSG("[%s]:line(%d), pdpActCnf->rc(%d).", __FUNCTION__,__LINE__,pdpActCnf->rc );

			//currCid = gAtpCtrl[GET_ATP_INDEX(reqHandle)].psCurrCid;
			currCid = gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid;
			//ATDBGMSG("CI_PS_PRIM_ACTIVATE_RECONF_PDP_CTX_CNF: currCid=%d", currCid);
			telPsPdpCtx *psPdpInfo = telGetPdpCtx(currCid);

			#ifdef QUEC_PPP_ENABLE
				CPUartLogPrintf("reconfig_cnf,pdpActCnf->rc=%d,reqHandle=%d,atp=%d,currid=%d",pdpActCnf->rc,reqHandle,GET_ATP_INDEX(reqHandle),currCid);
				//g_cgdata_handle_record = 0;	  //invalid value
			#endif
			if(currCid >= CI_PS_MAX_CID)
			{
				resetCurrCntx(GET_ATP_INDEX(reqHandle));
				ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				break;
			}

			if ( pdpActCnf->rc == CIRC_PS_SUCCESS )
			{

				//ATDBGMSG(atcmdsrv,241,"[%s]:line(%d), currCid(%d), reqHandle(%lx).\n", __FUNCTION__, __LINE__, currCid, reqHandle);

				/* RECONFIG active PDP success*/
				/*actived once, should show the ip info in +CGDCONT*/
				telSetPdpActivedFlag(currCid, TRUE);
				
                if(psPdpInfo != NULL)
				    psPdpInfo->activedStatus = 1;

				if (GET_REQ_ID(reqHandle) == CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ)
				{
					/*only AT+CGACT=1,cid will return OK*/
					ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL); //OK for AT+CGACT=1,*

                /* After PDP activated, obtained IP address, bind netif */
				}
				#ifndef MIN_SYS
				if (!IsMiniSystem()) 
				{//MiniSystem
					#ifdef QUECTEL_NETWORK_SUPPORT
						pdp_table_index = getPdpIndexByCid(currCid,p_cInfo); //Chaim 20200304 cid always zero,not correct
					#else
						pdp_table_index = getPdpIndexByCid(cid,p_cInfo);
					#endif
				}//MiniSystem
				else
				{
					pdp_table_index = getPdpIndexByCid(currCid,p_cInfo);
				}
				#endif /*MIN_SYS*/

				/* index may delete in deact ind */
				if(pdp_table_index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM){
                    #ifdef QUECTEL_NETWORK_SUPPORT
                    CPUartLogPrintf("index may delete in deact ind");
                    #endif
				    p_cInfo[pdp_table_index].reqHandle = reqHandle;
				}

				sendQueryCgdcont(reqHandle);
			}
			else
			{
				/*not reset the defined ctx*/
				//resetCurrCntx(GET_ATP_INDEX(reqHandle));

				/* Save PDP activation fail cause in local variable */
				getPdpErrCauseString(pdpActCnf->rc, pPdpErrCauseBuf);
				/* Delete the CID Context */
				//		  PS_DeleteGPRSContext(IND_REQ_HANDLE, currCid);

				#ifdef PPP_ENABLE
				if (bspGetBoardType() == TIGX_MIFI)
				{
					if (isHandleForMasterSim(reqHandle))
					{
						if ((ppp_get_connect_flag(currCid)) && (pdpActCnf->rc == CIRC_PS_APN))
							     sendmatchCgdcontapn();
					}
				}
				#endif

				checkPSRet(reqHandle, pdpActCnf->rc);
			}

			break;
		}
#endif
		case CI_PS_PRIM_GET_QOS_CAPS_CNF:
		{
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
		
			getQosCapsCnf = (CiPsPrimGetQosCapsCnf *)paras;
			if ( getQosCapsCnf->rc == CIRC_PS_SUCCESS )
			{
				if (getQosCapsCnf->qosCapsPresent)
				{
					CiPsQosCap *pCtxCaps = getQosCapsCnf->qosCaps.caps;

					for ( i = 0; i < getQosCapsCnf->qosCaps.size; i++ )
					{
						/* get PDP type string */
						getPdpTypeStr ( pCtxCaps->type, TempBuf );

						/* requested Qos is not defined for this CID */
						if (GET_REQ_ID(reqHandle) == PRI_PS_PRIM_GET_MIN_QOS_CAPS_REQ)
						{
#ifdef QUECTEL_NETWORK_SUPPORT
							sprintf( (char *)AtRspBuf, "\r\n+CGQMIN: %s,(%d-%d),(%d-%d),", TempBuf,
#else
							sprintf( (char *)AtRspBuf, "+CGQMIN: %s,(%d-%d),(%d-%d),", TempBuf,
#endif
								 pCtxCaps->precedenceCap.min,   /* Precedence class [0-4] */
								 pCtxCaps->precedenceCap.max,   /* Precedence class [0-4] */
								 pCtxCaps->delayCap.min,        /* Delay class [0-3] */
								 pCtxCaps->delayCap.max );      /* Delay class [0-3] */
							sprintf( (char *)TempBuf, "(%d-%d),(%d-%d),(",
								 pCtxCaps->reliabilityCap.min,  /* Reliability class [0-5] */
								 pCtxCaps->reliabilityCap.max,  /* Reliability class [0-5] */
								 pCtxCaps->peakCap.min,         /* Peak throughput [0-9] */
								 pCtxCaps->peakCap.max );       /* Peak throughput [0-9] */
							strcat( AtRspBuf, TempBuf );
						}
						else
						{
#ifdef QUECTEL_NETWORK_SUPPORT
							sprintf( (char *)AtRspBuf, "\r\n+CGQREQ: %s,(%d-%d),(%d-%d),", TempBuf,
#else
							sprintf( (char *)AtRspBuf, "+CGQREQ: %s,(%d-%d),(%d-%d),", TempBuf,
#endif
								 pCtxCaps->precedenceCap.min,   /* Precedence class [0-4] */
								 pCtxCaps->precedenceCap.max,   /* Precedence class [0-4] */
								 pCtxCaps->delayCap.min,        /* Delay class [0-3] */
								 pCtxCaps->delayCap.max );      /* Delay class [0-3] */
							sprintf( (char *)TempBuf, "(%d-%d),(%d-%d),(",
								 pCtxCaps->reliabilityCap.min,  /* Reliability class [0-5] */
								 pCtxCaps->reliabilityCap.max,  /* Reliability class [0-5] */
								 pCtxCaps->peakCap.min,         /* Peak throughput [0-9] */
								 pCtxCaps->peakCap.max );       /* Peak throughput [0-9] */
							strcat( AtRspBuf, TempBuf );
						}

						if ( pCtxCaps->meanCap.hasRange == TRUE )
						{
							sprintf ( (char *)TempBuf, "%d-%d", pCtxCaps->meanCap.rangeLst[0].min,
									pCtxCaps->meanCap.rangeLst[0].max );
							strcat ( (char *)AtRspBuf, (char *)TempBuf );

							for (i = 1; i < pCtxCaps->meanCap.rangeLstSize; i++ )
							{
								sprintf ( (char *)TempBuf, ",%d-%d", pCtxCaps->meanCap.rangeLst[i].min,
										pCtxCaps->meanCap.rangeLst[i].max );
								strcat ( (char *)AtRspBuf, (char *)TempBuf );
							}
						}

						if ( pCtxCaps->meanCap.hasIndvNums == TRUE )
						{
							for ( i = 0; i < pCtxCaps->meanCap.indvLstSize; i++ )
							{
								sprintf ( (char *)TempBuf, ",%d", pCtxCaps->meanCap.indvList[i] );
								strcat ( (char *)AtRspBuf, (char *)TempBuf );
							}
						}
						
#ifdef QUECTEL_NETWORK_SUPPORT
						strcat((char *)AtRspBuf, ")" );
						ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, AtRspBuf, FALSE);
#else
						strcat ( (char *)AtRspBuf, ")\r\n" );

						ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,(char *)AtRspBuf);
#endif

						pCtxCaps++;
					}
#ifdef QUECTEL_NETWORK_SUPPORT
					ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, "\r\n", FALSE);
					ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
#endif
				}
			}
			else
			{
				checkPSRet(reqHandle, getQosCapsCnf->rc);
			}
}//MiniSystem
else
{
			getQosCapsCnf = (CiPsPrimGetQosCapsCnf *)paras;
			if ( getQosCapsCnf->rc == CIRC_PS_SUCCESS )
			{
				if (getQosCapsCnf->qosCapsPresent)
				{
					CiPsQosCap *pCtxCaps = getQosCapsCnf->qosCaps.caps;

					for ( i = 0; i < getQosCapsCnf->qosCaps.size; i++ )
					{
						/* get PDP type string */
						getPdpTypeStr ( pCtxCaps->type, TempBuf );

						/* requested Qos is not defined for this CID */
						if (GET_REQ_ID(reqHandle) == PRI_PS_PRIM_GET_MIN_QOS_CAPS_REQ)
						{
							sprintf( (char *)AtRspBuf, "+CGQMIN: %s,(%d-%d),(%d-%d),", TempBuf,
								 pCtxCaps->precedenceCap.min,   /* Precedence class [0-4] */
								 pCtxCaps->precedenceCap.max,   /* Precedence class [0-4] */
								 pCtxCaps->delayCap.min,        /* Delay class [0-3] */
								 pCtxCaps->delayCap.max );      /* Delay class [0-3] */
							sprintf( (char *)TempBuf, "(%d-%d),(%d-%d),(",
								 pCtxCaps->reliabilityCap.min,  /* Reliability class [0-5] */
								 pCtxCaps->reliabilityCap.max,  /* Reliability class [0-5] */
								 pCtxCaps->peakCap.min,         /* Peak throughput [0-9] */
								 pCtxCaps->peakCap.max );       /* Peak throughput [0-9] */
							strcat( AtRspBuf, TempBuf );
						}
						else
						{
							sprintf( (char *)AtRspBuf, "+CGQREQ: %s,(%d-%d),(%d-%d),", TempBuf,
								 pCtxCaps->precedenceCap.min,   /* Precedence class [0-4] */
								 pCtxCaps->precedenceCap.max,   /* Precedence class [0-4] */
								 pCtxCaps->delayCap.min,        /* Delay class [0-3] */
								 pCtxCaps->delayCap.max );      /* Delay class [0-3] */
							sprintf( (char *)TempBuf, "(%d-%d),(%d-%d),(",
								 pCtxCaps->reliabilityCap.min,  /* Reliability class [0-5] */
								 pCtxCaps->reliabilityCap.max,  /* Reliability class [0-5] */
								 pCtxCaps->peakCap.min,         /* Peak throughput [0-9] */
								 pCtxCaps->peakCap.max );       /* Peak throughput [0-9] */
							strcat( AtRspBuf, TempBuf );
						}

						if ( pCtxCaps->meanCap.hasRange == TRUE )
						{
							sprintf ( (char *)TempBuf, "%d-%d", pCtxCaps->meanCap.rangeLst[0].min,
									pCtxCaps->meanCap.rangeLst[0].max );
							strcat ( (char *)AtRspBuf, (char *)TempBuf );

							for (i = 1; i < pCtxCaps->meanCap.rangeLstSize; i++ )
							{
								sprintf ( (char *)TempBuf, ",%d-%d", pCtxCaps->meanCap.rangeLst[i].min,
										pCtxCaps->meanCap.rangeLst[i].max );
								strcat ( (char *)AtRspBuf, (char *)TempBuf );
							}
						}

						if ( pCtxCaps->meanCap.hasIndvNums == TRUE )
						{
							for ( i = 0; i < pCtxCaps->meanCap.indvLstSize; i++ )
							{
								sprintf ( (char *)TempBuf, ",%d", pCtxCaps->meanCap.indvList[i] );
								strcat ( (char *)AtRspBuf, (char *)TempBuf );
							}
						}

						strcat ( (char *)AtRspBuf, ")\r\n" );

						ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,(char *)AtRspBuf);

						pCtxCaps++;
					}
				}
			}
			else
			{
				checkPSRet(reqHandle, getQosCapsCnf->rc);
			}

}
#endif /*MIN_SYS*/
			break;
		}

		case CI_PS_PRIM_GET_QOS_CNF:
		{
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
		
			getQosCnf = (CiPsPrimGetQosCnf *)paras;
			currCid = gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid;

			if(currCid >= CI_PS_MAX_CID)
			{
				resetCurrCntx(GET_ATP_INDEX(reqHandle));
				ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				break;
			}

			if (( getQosCnf->rc == CIRC_PS_SUCCESS ) && getQosCnf->qosProfPresent )
			{
				/* requested Qos is not defined for this CID */
				if (GET_REQ_ID(reqHandle) == PRI_PS_PRIM_GET_MIN_QOS_REQ)
				{
#ifdef QUECTEL_NETWORK_SUPPORT
					sprintf( (char *)AtRspBuf, "\r\n+CGQMIN: %d,%d,%d,%d,", currCid + 1,
						 getQosCnf->qosProf.precedence,
						 getQosCnf->qosProf.delay,
						 getQosCnf->qosProf.reliability);
					sprintf( TempBuf, "%d,%d",
						 getQosCnf->qosProf.peak,
						 getQosCnf->qosProf.mean );
					strcat( AtRspBuf, TempBuf );
					ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, AtRspBuf, FALSE);
#else
					sprintf( (char *)AtRspBuf, "CGQMIN: %d,%d,%d,%d,", currCid + 1,
						 getQosCnf->qosProf.precedence,
						 getQosCnf->qosProf.delay,
						 getQosCnf->qosProf.reliability);
					sprintf( TempBuf, "%d,%d\r\n",
						 getQosCnf->qosProf.peak,
						 getQosCnf->qosProf.mean );
					strcat( AtRspBuf, TempBuf );
					ATRESP( reqHandle, 0, 0, (char *)AtRspBuf);
#endif
				}
				else
				{
#ifdef QUECTEL_NETWORK_SUPPORT
					sprintf( (char *)AtRspBuf, "\r\n+CGQREQ: %d,%d,%d,%d,", currCid + 1,
						 getQosCnf->qosProf.precedence,
						 getQosCnf->qosProf.delay,
						 getQosCnf->qosProf.reliability);
					sprintf( TempBuf, "%d,%d",
						 getQosCnf->qosProf.peak,
						 getQosCnf->qosProf.mean );
					strcat( AtRspBuf, TempBuf );
					ATRESPEX( reqHandle, ATCI_RESULT_CODE_NULL, 0, AtRspBuf, FALSE);
#else
					sprintf( (char *)AtRspBuf, "CGQREQ: %d,%d,%d,%d,\r\n", currCid + 1,
						 getQosCnf->qosProf.precedence,
						 getQosCnf->qosProf.delay,
						 getQosCnf->qosProf.reliability);
					sprintf( TempBuf, "%d,%d\r\n",
						 getQosCnf->qosProf.peak,
						 getQosCnf->qosProf.mean );
					strcat( AtRspBuf, TempBuf );
					ATRESP( reqHandle, 0, 0, (char *)AtRspBuf);
#endif
				}
			}



			/* send query for next CID */
			currCid++;
			if ( currCid < CI_PS_MAX_CID)
			{
				getQosReq = utlCalloc(1, sizeof(*getQosReq));
				if (getQosReq == NULL) {
					ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
					break;
				}

				gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = currCid;
				getQosReq->cid = currCid;
				getQosReq->isMin = ( GET_REQ_ID(reqHandle) == PRI_PS_PRIM_GET_MIN_QOS_REQ )?TRUE:FALSE;
				ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_QOS_REQ,
						reqHandle, (void *)getQosReq );
			}
			else
			{
				//resetCurrCntx(GET_ATP_INDEX(reqHandle));
#if defined QUECTEL_NETWORK_SUPPORT
				ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, "\r\n", FALSE);
#endif
				ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
			}
}//MiniSystem
else
{
			getQosCnf = (CiPsPrimGetQosCnf *)paras;
			currCid = gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid;

			if(currCid >= CI_PS_MAX_CID)
			{
				resetCurrCntx(GET_ATP_INDEX(reqHandle));
				ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				break;
			}

			if (( getQosCnf->rc == CIRC_PS_SUCCESS ) && getQosCnf->qosProfPresent )
			{
				/* requested Qos is not defined for this CID */
				if (GET_REQ_ID(reqHandle) == PRI_PS_PRIM_GET_MIN_QOS_REQ)
				{
					sprintf( (char *)AtRspBuf, "CGQMIN: %d,%d,%d,%d,", currCid + 1,
						 getQosCnf->qosProf.precedence,
						 getQosCnf->qosProf.delay,
						 getQosCnf->qosProf.reliability);
					sprintf( TempBuf, "%d,%d\r\n",
						 getQosCnf->qosProf.peak,
						 getQosCnf->qosProf.mean );
					strcat( AtRspBuf, TempBuf );
					ATRESP( reqHandle, 0, 0, (char *)AtRspBuf);
				}
				else
				{
					sprintf( (char *)AtRspBuf, "CGQREQ: %d,%d,%d,%d,\r\n", currCid + 1,
						 getQosCnf->qosProf.precedence,
						 getQosCnf->qosProf.delay,
						 getQosCnf->qosProf.reliability);
					sprintf( TempBuf, "%d,%d\r\n",
						 getQosCnf->qosProf.peak,
						 getQosCnf->qosProf.mean );
					strcat( AtRspBuf, TempBuf );
					ATRESP( reqHandle, 0, 0, (char *)AtRspBuf);
				}
			}



			/* send query for next CID */
			currCid++;
			if ( currCid < CI_PS_MAX_CID)
			{
				getQosReq = utlCalloc(1, sizeof(*getQosReq));
				if (getQosReq == NULL) {
					ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
					break;
				}

				gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = currCid;
				getQosReq->cid = currCid;
				getQosReq->isMin = ( GET_REQ_ID(reqHandle) == PRI_PS_PRIM_GET_MIN_QOS_REQ )?TRUE:FALSE;
				ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_QOS_REQ,
						reqHandle, (void *)getQosReq );
			}
			else
			{
				//resetCurrCntx(GET_ATP_INDEX(reqHandle));
				ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
			}

}
#endif /*MIN_SYS*/
			break;
		}
		case CI_PS_PRIM_SET_QOS_CNF:
		{
			setQosCnf = (CiPsPrimSetQosCnf *)paras;
			if( setQosCnf->rc == CIRC_PS_SUCCESS )
			{
				ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
			}
			else
			{
				checkPSRet(reqHandle, setQosCnf->rc);
			}
			break;
		}

#ifndef MORE_ATC_SPACE_OPT
		case CI_PS_PRIM_DEFINE_SEC_PDP_CTX_CNF:
		{
			defPdpSecCnf = (CiPsPrimDefineSecPdpCtxCnf *)paras;
			if ( defPdpSecCnf->rc == CIRC_PS_SUCCESS )
			{
				atpIdx = GET_ATP_INDEX(reqHandle);
				if(gCIDList.currCntx[atpIdx].currCid >= CI_PS_MAX_CID)
				{
					resetCurrCntx(atpIdx);
					ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
					break;
				}

				pdp_table_index = getPdpIndexByCid(gCIDList.currCntx[atpIdx].currCid,p_cInfo);
				if(pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
				{
					pdp_table_index = getFreePdpIndexFromTable(p_cInfo);
					if (pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
            		{
            		    ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, 0);
            			break;
            		}
				}

				p_cInfo[pdp_table_index].bDefined = TRUE;
				p_cInfo[pdp_table_index].cid = gCIDList.currCntx[atpIdx].currCid;

				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				resetCurrCntx(GET_ATP_INDEX(reqHandle));
				checkPSRet(reqHandle, defPdpSecCnf->rc);
			}
			break;
		}

		case CI_PS_PRIM_GET_SEC_PDP_CTX_CNF:
		{

			/* query was for an AT+CGDSCONT */
			getPdpSecCnf = (CiPsPrimGetSecPdpCtxCnf *)paras;
			if (( getPdpSecCnf->rc == CIRC_PS_SUCCESS ) &&  getPdpSecCnf->ctxPresent )
			{
				sprintf ( (char *)AtRspBuf,"+CGDSCONT: %d,%d,",
						getPdpSecCnf->ctx.secPdpCtx.cid + 1,
						getPdpSecCnf->ctx.secPdpCtx.p_cid + 1 );

				if ( getPdpSecCnf->ctx.secPdpCtx.dcompPresent )
				{
					sprintf((char *)TempBuf, "%d,", getPdpSecCnf->ctx.secPdpCtx.dcomp);
				}
				else
				{
					sprintf((char *)TempBuf, ",");
				}

				strcat((char *)AtRspBuf, (char *)TempBuf);

				if ( getPdpSecCnf->ctx.secPdpCtx.hcompPresent )
				{
					sprintf((char *)TempBuf, "%d,", getPdpSecCnf->ctx.secPdpCtx.hcomp);
				}
				else
				{
					sprintf((char *)TempBuf, ",");
				}
				strcat((char *)AtRspBuf, (char *)TempBuf);

				if ( getPdpSecCnf->ctx.secPdpCtx.imCnSigFlagPresent )
				{
					sprintf((char *)TempBuf, "%d", getPdpSecCnf->ctx.secPdpCtx.imCnSigFlag);
				}
				strcat((char *)AtRspBuf, (char *)TempBuf);

				strcat((char *)AtRspBuf, "\r\n");

				ATRESP( reqHandle,0,0,(char *)AtRspBuf);
			}

			nextCid = gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid + 1;

			/* did we receive all confirmations ? */
			if( nextCid < CI_PS_MAX_CID)
			{
				/* Require the next CI */
				getSecPdpReq = utlCalloc(1, sizeof(*getSecPdpReq));
				if (getSecPdpReq == NULL) {
					ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
					break;
				}
				getSecPdpReq->cid = nextCid;

				gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = nextCid;

				/*
				 **  Send the CI Request.
				 */
				ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_SEC_PDP_CTX_REQ,
							reqHandle, (void *)getSecPdpReq );
			}
			else
			{
				/* Received all the response */
				//resetCurrCntx(GET_ATP_INDEX(reqHandle));
				ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
			}

			break;
		}
#endif
		case CI_PS_PRIM_GET_PDP_CTX_CNF:
		{
			static INT32 activePrimPdp[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM] = {0 };
			static INT32 idx = 0;
			static INT32 activeCounter = 0;
#ifdef LWIP_IPNETBUF_SUPPORT
			telPsPdpCtx *psPdpInfo = NULL;
#endif

			currCid = gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid;

			if(currCid >= CI_PS_MAX_CID)
			{
				resetCurrCntx(GET_ATP_INDEX(reqHandle));
#ifdef LWIP_IPNETBUF_SUPPORT
				exitQueryPdpCtx(reqHandle);
				exitQueryTftCtx(reqHandle);
#endif
				ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				break;
			}


			DBGMSG("got CI_PS_PRIM_GET_PDP_CTX_CNF\n");
			DBGMSG("gCurrentPdpSetCtx.cid=%d, .pdpType:%d\n", currCid, p_cInfo[currCid].pdpType);
			pdp_table_index = getPdpIndexByCid(currCid,p_cInfo);

			#ifdef PLATFORM_FOR_PS_LW
			if ((pdp_table_index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM )&& (p_cInfo[pdp_table_index].pdpType == CI_PS_PDP_TYPE_IP||(IsLteMode())))
			#else
			if ((pdp_table_index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM ) && (p_cInfo[pdp_table_index].pdpType == CI_PS_PDP_TYPE_IP||(IsLteMode(0)||IsLteMode(1))) )
			#endif
			{
				getPdpPrimCnf = (CiPsPrimGetPdpCtxCnf *)paras;
				DBGMSG("CI_PS_PRIM_GET_PDP_CTX_CNF,rc=%d\n", getPdpPrimCnf->rc);

				if (getPdpPrimCnf->ctxPresent)
				{
					CiPsPdpCtxInfo* pCtx;
					int cid;

					pCtx = &getPdpPrimCnf->ctx;
					cid = pCtx->pdpCtx.cid;


					DIAG_FILTER(PCAC, ATCMDSrv, ParseIPAddr, DIAG_INFORMATION)
					diagPrintf("Parse IP Address on CID: %d", currCid);

					parseAddrByCid(currCid,pCtx);
				}else{
					DIAG_FILTER(PCAC, ATCMDSrv, ParseIPAddr22, DIAG_INFORMATION)
					diagPrintf("No IP Address on CID: %d", currCid);
					parseAddrByCid(currCid,NULL);
				}
			}else{
					DIAG_FILTER(PCAC, ATCMDSrv, ParseIPAddr23, DIAG_INFORMATION)
					diagPrintf("No IP Address on CID: %d", currCid);
					parseAddrByCid(currCid,NULL);
			}

			//ATDBGMSG("CI_PS_PRIM_GET_PDP_CTX_CNF: GET_REQ_ID %d", GET_REQ_ID(reqHandle));
			/* a query operation must be in progress */
			if (GET_REQ_ID(reqHandle) == PRI_PS_PRIM_GET_SECOND_PDP_CTXS_RANGE_REQ)
			{
				/* query was for an AT+CGDSCONT=? */
				getPdpPrimCnf = (CiPsPrimGetPdpCtxCnf *)paras;
				if (( getPdpPrimCnf->rc == CIRC_PS_SUCCESS ) && getPdpPrimCnf->ctxPresent )
				{
					/* check if active context */
					if ( getPdpPrimCnf->ctx.actState )
					{
						activePrimPdp[activeCounter++] = getPdpPrimCnf->ctx.pdpCtx.cid + 1;
					}
				}

				/* send request for next CID  */
				currCid++;
				if ( currCid < CI_PS_MAX_CID)
				{
					/* request info about every primary context */
					getNxtPdpCtxReq = utlCalloc(1, sizeof(*getNxtPdpCtxReq));
					if (getNxtPdpCtxReq == NULL) {
						ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						break;
					}
					getNxtPdpCtxReq->cid = currCid;

					gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = currCid;

					/*
					 **  Send the CI Request.
					 */
					ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ,
							reqHandle, (void *)getNxtPdpCtxReq );
				}
				else
				{
					/*  we received all confirmations ? */
					sprintf ( (char *)AtRspBuf,"+CGDSCONT: (1-%d),", CI_PS_MAX_CID);

					if ( activeCounter > 0 )
					{
						sprintf((char *)TempBuf, "(%d", activePrimPdp[0]);
						strcat((char *)AtRspBuf, (char *)TempBuf);

						for( idx = 1; idx < activeCounter; idx++ )
						{
							sprintf((char *)TempBuf, ", %d", activePrimPdp[idx]);
							strcat((char *)AtRspBuf, (char *)TempBuf);
						}
					}
					else
					{
						strcat((char *)AtRspBuf, "(");
					}

					strcat((char *)AtRspBuf, "),(0-2),(0-2),(0-1)");

					ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,(char *)AtRspBuf);

					/* reinit all variables */
					//resetCurrCntx(GET_ATP_INDEX(reqHandle));
					activeCounter = 0;
					for( idx = 0; idx < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM; idx++ )
					{
						activePrimPdp[idx] = 0;
					}
				}
			}  /* if ( ==PRI_PS_PRIM_GET_SECOND_PDP_CTXS_RANGE_REQ  */

			else if (GET_REQ_ID(reqHandle) == CI_PS_PRIM_GET_ACTIVE_CID_LIST_REQ)
			{
#ifndef MIN_SYS
			if (!IsMiniSystem()) 
			{//MiniSystem
			
				/* query was for an AT+CGACT */
				getPdpPrimCnf = (CiPsPrimGetPdpCtxCnf *)paras;
			#ifdef QUECTEL_NETWORK_SUPPORT
				telPsPdpCtx *psPdpInfo =  telGetPdpCtx(currCid);
				ATDBGMSG("AT+CGACT=Get PDP CTX:%d %d currCid=%d",getPdpPrimCnf->rc,getPdpPrimCnf->ctxPresent,currCid);
				Quec_NetInfo_log("currCid=%d,pdpctx.cid=%d,psPdpInfo.cid=%d,rc=%d,ctxpresent=%d",
				currCid,getPdpPrimCnf->ctx.pdpCtx.cid,psPdpInfo->cid,getPdpPrimCnf->rc,getPdpPrimCnf->ctxPresent);

				/* act as per status */
				if (( getPdpPrimCnf->rc == CIRC_PS_SUCCESS ) &&  getPdpPrimCnf->ctxPresent )
				{
					sprintf(AtRspBuf, "\r\n+CGACT: %d,", getPdpPrimCnf->ctx.pdpCtx.cid + 1 );
					/* check if active context */
					if ( getPdpPrimCnf->ctx.actState )
					{
						strcat(AtRspBuf, "1"); /* activated */
					}
					else
					{
						strcat(AtRspBuf, "0"); /* deactivated */
					}
				#if QUEC_DUAL_SIM_SUPPORT
					if (getDualSimType() == CM_DUAL_SIM_SINGLE_STANDBY)
					{
						ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, AtRspBuf, FALSE);
					}
					else
					{
						// Fitz.xu 20211223: currCid: 0-3, 4-7
						if (((GET_ATP_INDEX(reqHandle) < 36) && (currCid < 4)) || 
							((GET_ATP_INDEX(reqHandle) >= 36) && (currCid > 3)) )
						{
							ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, AtRspBuf, FALSE);
						}
					}
				#else
					ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, AtRspBuf, FALSE);
				#endif

				}
				else if(getPdpPrimCnf->ctxPresent == 0 && (psPdpInfo) && (psPdpInfo->cid <= TEL_AT_PS_CID_VAL_MAX))
				{
					/* if redefine pdp exist, display it*/
					if (psPdpInfo->reDefined && (strlen(psPdpInfo->apnInfo.apn) > 0))
					{
						char *p = AtRspBuf;

						p += sprintf(p, "\r\n+CGACT: %d,", psPdpInfo->cid + 1 );
						if(psPdpInfo->bActived == 1)
							strcpy(p, "1"); /* activated */
						else
							strcpy(p, "0"); /* deactivated */
							
						//Fitz.xu 20211223: To fix STASR1601-4917
						
						//Fitz.xu 20211020: For SIM2, when execute at+cgact? do not show cid1-4
					#if QUEC_DUAL_SIM_SUPPORT
						if (getDualSimType() == CM_DUAL_SIM_SINGLE_STANDBY)
						{
							ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, AtRspBuf, FALSE);
						}
						else
						{
							// Fitz.xu 20211223: currCid: 0-3, 4-7
							if (((GET_ATP_INDEX(reqHandle) < 36) && (currCid < 4)) || 
								((GET_ATP_INDEX(reqHandle) >= 36) && (currCid > 3)) )
							{
								ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, AtRspBuf, FALSE);
							}
						}
					#else
						ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, AtRspBuf, FALSE);
					#endif				
					}
				}
			#else
				/* act as per status */
				if (( getPdpPrimCnf->rc == CIRC_PS_SUCCESS ) &&  getPdpPrimCnf->ctxPresent )
				{
					sprintf ( (char *)AtRspBuf,"+CGACT: %d,", getPdpPrimCnf->ctx.pdpCtx.cid+1 );
					if ( getPdpPrimCnf->ctx.actState )
					{
						strcat((char *)AtRspBuf, "1\r\n");   /* activated */
					}
					else
					{
						strcat((char *)AtRspBuf, "0\r\n");   /* deactivated */
					}
					ATRESP( reqHandle,0,0,(char *)AtRspBuf);
				}
			#endif
				else
				{
					/* just ignore the confirmation - nothing to dislplay*/
				}

				/* send request for next CID  */
				currCid++;
				if ( currCid < CI_PS_MAX_CID)
				{
					/* request info about every primary context */
					getNxtPdpCtxReq = utlCalloc(1, sizeof(*getNxtPdpCtxReq));
					if (getNxtPdpCtxReq == NULL) {
						ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						break;
					}
					getNxtPdpCtxReq->cid = currCid;

					gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = currCid;

					/*
					**  Send the CI Request.
					*/
					ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ,
							 reqHandle, (void *)getNxtPdpCtxReq );
				}
				else
				{
					/* completed operation */
				#if defined QUECTEL_NETWORK_SUPPORT
					ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, "\r\n", FALSE);
				#endif
					ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
					//resetCurrCntx(GET_ATP_INDEX(reqHandle));
				}
			}//MiniSystem
			else
			{
				/* query was for an AT+CGACT */
				getPdpPrimCnf = (CiPsPrimGetPdpCtxCnf *)paras;

				/* act as per status */
				if (( getPdpPrimCnf->rc == CIRC_PS_SUCCESS ) &&  getPdpPrimCnf->ctxPresent )
				{
					sprintf ( (char *)AtRspBuf,"+CGACT: %d,", getPdpPrimCnf->ctx.pdpCtx.cid+1 );

					/* check if active context */
					if ( getPdpPrimCnf->ctx.actState )
					{
						strcat((char *)AtRspBuf, "1\r\n");   /* activated */
					}
					else
					{
						strcat((char *)AtRspBuf, "0\r\n");   /* deactivated */
					}

					ATRESP( reqHandle,0,0,(char *)AtRspBuf);
				}
				else
				{
					#ifdef LWIP_IPNETBUF_SUPPORT
					if(psPdpInfo && (psPdpInfo->apnInfo.defined == TRUE))
					{
						sprintf ( (char *)AtRspBuf,"+CGACT: %d,", currCid + 1 );

							/* check if active context */
						if (psPdpInfo->activedStatus)
						{
							strcat((char *)AtRspBuf, "1\r\n");   /* activated */
						}
						else
						{
							strcat((char *)AtRspBuf, "0\r\n");   /* deactivated */
						}

						ATRESP( reqHandle,0,0,(char *)AtRspBuf);
					}
					#endif
				}

				/* send request for next CID  */
				currCid++;
				if ( currCid < CI_PS_MAX_CID)
				{
					/* request info about every primary context */
					getNxtPdpCtxReq = utlCalloc(1, sizeof(*getNxtPdpCtxReq));
					if (getNxtPdpCtxReq == NULL) {
						ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						break;
					}
					getNxtPdpCtxReq->cid = currCid;

					gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = currCid;

					/*
					**  Send the CI Request.
					*/
					ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ,
							 reqHandle, (void *)getNxtPdpCtxReq );
				}
				else
				{
					/* completed operation */
					ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
					//resetCurrCntx(GET_ATP_INDEX(reqHandle));
				}
			}
			#endif /*MIN_SYS*/				
			}       /* if ( ==CI_PS_PRIM_GET_ACTIVE_CID_LIST_REQ ) */
			   /*Added by Michal Bukai - CGTFT support*/
			else if (GET_REQ_ID(reqHandle) == PRI_PS_PRIM_GET_TFT_REQ)
			{
#ifndef MIN_SYS
				if (!IsMiniSystem()) 
				{//MiniSystem
				
					getPdpPrimCnf = (CiPsPrimGetPdpCtxCnf *)paras;
					
					#ifdef QUECTEL_NETWORK_SUPPORT
						currCid++;
						//gAtpCtrl[GET_ATP_INDEX(reqHandle)].psCurrCid = currCid;
						gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = currCid;
					#endif

					//ATDBGMSG("PRI_PS_PRIM_GET_TFT_REQ: pdpCtxPresent %d, currCid %d", getPdpPrimCnf->ctxPresent, currCid);
					if (( getPdpPrimCnf->rc == CIRC_PS_SUCCESS ) &&  ( getPdpPrimCnf->ctxPresent))
					{
						getTftReq = utlCalloc(1,sizeof(*getTftReq));
						if (getTftReq == NULL) {
							ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
							#ifdef LWIP_IPNETBUF_SUPPORT
								exitQueryTftCtx(reqHandle);
							#endif
							break;
						}
						getTftReq->cid = getPdpPrimCnf->ctx.pdpCtx.cid;
						ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_TFT_REQ,
								reqHandle, (void *)getTftReq );
					}
					else
					{
						#ifdef QUECTEL_NETWORK_SUPPORT
						//Sharon.li@20240429 解决单卡协议栈Volte通话中断的问题,FAE-116063
						/* check whether get tft done*/
						#if 0
							//Fitz.xu 20211206: To fix CMCC sim card call ul no voice issue, 
							//cause can not get tft of cid that larger than 7, like cid9
							#if QUEC_DUAL_SIM_SUPPORT
							if (gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid >= CI_PS_MAX_CID)
							#else
							//if(gAtpCtrl[GET_ATP_INDEX(reqHandle)].psCurrCid >= CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
							if(gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid >= CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
							#endif
						#else
							if (gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid >= CI_PS_MAX_CID)
						#endif
						
						{
							/* completed operation */
							ATDBGMSG("CI_PS_PRIM_GET_TFT_CNF:completed operation\n");
							ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
							sendTftCtxListToCm(reqHandle);
							exitQueryTftCtx(reqHandle);
							//resetCurrCntx(GET_ATP_INDEX(reqHandle)); 
							break;
						}
						
						#endif
					}

					/* send request for next CID  */
					#ifndef QUECTEL_NETWORK_SUPPORT
					currCid++;
					#endif
					
					if ( currCid < CI_PS_MAX_CID)
					{
						/* request info about every primary context */
						getNxtPdpCtxReq = utlCalloc(1, sizeof(*getNxtPdpCtxReq));
						if (getNxtPdpCtxReq == NULL) {
							ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
							#ifdef LWIP_IPNETBUF_SUPPORT
							exitQueryTftCtx(reqHandle);
							#endif
							break;
						}
						getNxtPdpCtxReq->cid = currCid;
						#ifdef QUECTEL_NETWORK_SUPPORT
						//gAtpCtrl[GET_ATP_INDEX(reqHandle)].psCurrCid = currCid;
						#else
						//gAtpCtrl[GET_ATP_INDEX(reqHandle)].psCurrCid = currCid;
						gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = currCid;
						#endif

						gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = currCid;

						/*
						 **  Send the CI Request.
						 */
						ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ,
								reqHandle, (void *)getNxtPdpCtxReq );
					}
					#ifndef QUECTEL_NETWORK_SUPPORT
					else
					{
						/* completed operation */
						#ifndef LWIP_IPNETBUF_SUPPORT
						ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
						#endif

						#ifdef LWIP_IPNETBUF_SUPPORT
						gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = currCid;
						ATDBGMSG("PRI_PS_PRIM_GET_TFT_REQ: get all cid doen, currCid %d, max PDP num %d", gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid, CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM );
						if(gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid >= CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
						{
							/* completed operation */
							CPUartLogPrintf("CI_PS_PRIM_GET_TFT_CNF:completed operation\n");
							ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
							sendTftCtxListToCm(reqHandle);
							exitQueryTftCtx(reqHandle);
							//resetCurrCntx(GET_ATP_INDEX(reqHandle));
						}
						#endif
					}
					#endif
				}//MiniSystem
				else
				{
					getPdpPrimCnf = (CiPsPrimGetPdpCtxCnf *)paras;

					ATDBGMSG("PRI_PS_PRIM_GET_TFT_REQ: pdpCtxPresent %d, currCid %d", getPdpPrimCnf->ctxPresent, currCid);
					if (( getPdpPrimCnf->rc == CIRC_PS_SUCCESS ) &&  ( getPdpPrimCnf->ctxPresent))
					{
						getTftReq = utlCalloc(1,sizeof(*getTftReq));
						if (getTftReq == NULL) {
							ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
							#ifdef LWIP_IPNETBUF_SUPPORT
							exitQueryTftCtx(reqHandle);
							#endif
							break;
						}
						getTftReq->cid = getPdpPrimCnf->ctx.pdpCtx.cid;
						ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_TFT_REQ,
								reqHandle, (void *)getTftReq );
					}

					/* send request for next CID  */
					currCid++;
					if ( currCid < CI_PS_MAX_CID)
					{
						/* request info about every primary context */
						getNxtPdpCtxReq = utlCalloc(1, sizeof(*getNxtPdpCtxReq));
						if (getNxtPdpCtxReq == NULL) {
							ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
#ifdef LWIP_IPNETBUF_SUPPORT
							exitQueryTftCtx(reqHandle);
#endif	
							break;
						}
						getNxtPdpCtxReq->cid = currCid;

						gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = currCid;

						/*
						 **  Send the CI Request.
						 */
						ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ,
								reqHandle, (void *)getNxtPdpCtxReq );
					}
					else
					{
						/* completed operation */
#ifndef LWIP_IPNETBUF_SUPPORT
						ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
#endif

#ifdef LWIP_IPNETBUF_SUPPORT
						gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = currCid;
						//ATDBGMSG("PRI_PS_PRIM_GET_TFT_REQ: get all cid doen, currCid %d, max PDP num %d", gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid, CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM );
						if(gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid >= CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
						{
							/* completed operation */
							CPUartLogPrintf("CI_PS_PRIM_GET_TFT_CNF:completed operation\n");
							ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
							sendTftCtxListToCm(reqHandle);
							exitQueryTftCtx(reqHandle);
							//resetCurrCntx(GET_ATP_INDEX(reqHandle));
						}
#endif
					}

				}
#endif /*MIN_SYS*/
			}  /* if ( gAtCgTftQuery ) */

			else if (GET_REQ_ID(reqHandle) == CI_PS_PRIM_GET_PDP_CTX_REQ)
			{
				/* query was for an AT+CGDCONT? */
				getPdpPrimCnf = (CiPsPrimGetPdpCtxCnf *)paras;
#ifdef LWIP_IPNETBUF_SUPPORT
				psPdpInfo =  telGetPdpCtx(currCid);
				BOOL reconfigApn = FALSE;
				UINT32 atHandle = GET_AT_HANDLE(reqHandle);
				TelAtParserID sAtpIndex = (TelAtParserID)GET_ATP_INDEX(atHandle);
#endif
				if (( getPdpPrimCnf->rc == CIRC_PS_SUCCESS ) &&  ( getPdpPrimCnf->ctxPresent))
				{
#ifdef LWIP_IPNETBUF_SUPPORT
					processGetPdpCtxCnf(reqHandle, getPdpPrimCnf);
#endif
					sprintf( (char *)AtRspBuf, "+CGDCONT: %d,", getPdpPrimCnf->ctx.pdpCtx.cid+1 );
#ifdef LWIP_IPNETBUF_SUPPORT
					CPUartLogPrintf("cgdcont: cid %d, reDefined %d, apn defined %d", getPdpPrimCnf->ctx.pdpCtx.cid+1, psPdpInfo->reDefined, psPdpInfo->apnInfo.defined);

					if (psPdpInfo && psPdpInfo->reDefined && getPdpPrimCnf->ctx.pdpCtx.apnPresent && isHandleForMasterSim(reqHandle))
					{
						getPdpTypeStr ( psPdpInfo->apnInfo.ipType, TempBuf );
						strcat((char *)AtRspBuf, (char *)TempBuf);
						strcat((char *)AtRspBuf, ",\"");

						if (strlen(psPdpInfo->apnInfo.apn) > 0)
							strcpy(TempBuf, psPdpInfo->apnInfo.apn);
						else
							TempBuf[0] = '\0';

						strcat((char *)AtRspBuf, (char *)TempBuf);
						strcat((char *)AtRspBuf, "\"");
						reconfigApn = TRUE;;
					}
					else
#endif
					{
						/* PDP type number */
						getPdpTypeStr ( getPdpPrimCnf->ctx.pdpCtx.type, TempBuf );
						strcat((char *)AtRspBuf, (char *)TempBuf);
						strcat((char *)AtRspBuf, ",\"" );

						/* PDP access point */
						if ( getPdpPrimCnf->ctx.pdpCtx.apnPresent )
						{
							memcpy( TempBuf, getPdpPrimCnf->ctx.pdpCtx.apn.valStr, getPdpPrimCnf->ctx.pdpCtx.apn.len );
							TempBuf[getPdpPrimCnf->ctx.pdpCtx.apn.len] = '\0';
						}
						else
						{
							TempBuf[0] = '\0';
						}

						strcat((char *)AtRspBuf, (char *)TempBuf);
						//strcat((char *)AtRspBuf, "\",\"" );
						strcat((char *)AtRspBuf, "\"" );
					}

#ifdef LWIP_IPNETBUF_SUPPORT
					/* reconfig APN and actived, should show IP info in +CGDCONT*/
					if ((reconfigApn && telGetPdpActivedFlag(getPdpPrimCnf->ctx.pdpCtx.cid) && isHandleForMasterSim(reqHandle))
						|| !reconfigApn
						|| ((psPdpInfo->activedStatus == 1) && (getDefaultCidNum() == (getPdpPrimCnf->ctx.pdpCtx.cid+1))))
#endif
					/* PDP address */
					{
						int addrType;
						unsigned char* valData;
						char ipp4[CI_PS_PDP_IP_V4_SIZE] = { '\0' };
						char ipp6[CI_PS_PDP_IP_V6_SIZE] = { '\0' };
						UINT16 pdp_addr;
						UINT8 configIPType = CI_PS_PDP_TYPE_IP;

						strcat((char *)AtRspBuf, ",\"");
						addrType = getPdpPrimCnf->ctx.pdpCtx.ipv4Addr.addrType;
						valData = getPdpPrimCnf->ctx.pdpCtx.ipv4Addr.valData;
						if(addrType == CI_PS_PDP_IPV4)
						{
							convertIpUnit2Str(reqHandle, addrType, valData, ipp4);
						}

						addrType = getPdpPrimCnf->ctx.pdpCtx.ipv6Addr.addrType;
						valData = getPdpPrimCnf->ctx.pdpCtx.ipv6Addr.valData;
						if((addrType == CI_PS_PDP_FULL_IPV6) || (addrType == CI_PS_PDP_IPV6_INTERFACE))
						{
							convertIpUnit2Str(reqHandle, addrType, valData, ipp6);
						}
#ifdef LWIP_IPNETBUF_SUPPORT
                        if (reconfigApn && telGetPdpActivedFlag(getPdpPrimCnf->ctx.pdpCtx.cid) && isHandleForMasterSim(reqHandle))
                        {
                            if(psPdpInfo != NULL)
                                configIPType = psPdpInfo->apnInfo.ipType;
                        }
                        else
#endif
                            configIPType = getPdpPrimCnf->ctx.pdpCtx.type;
                            	
						if(configIPType == CI_PS_PDP_TYPE_IP)
							strcat((char *)AtRspBuf, (char *)ipp4);
						else if(configIPType == CI_PS_PDP_TYPE_IPV6)
							strcat((char *)AtRspBuf, (char *)ipp6);
						else if(configIPType == CI_PS_PDP_TYPE_IPV4V6)
						{
							strcat((char *)AtRspBuf, (char *)ipp4);
							strcat((char *)AtRspBuf, " ");
							strcat((char *)AtRspBuf, (char *)ipp6);
						}
					}

					strcat((char *)AtRspBuf, "\",");

					/* PDP data compression */
					if ( getPdpPrimCnf->ctx.pdpCtx.dcompPresent )
					{
						sprintf( (char *)TempBuf, "%d", getPdpPrimCnf->ctx.pdpCtx.dcomp );
						strcat((char *)AtRspBuf, (char *)TempBuf);
					}
					else
					{
						sprintf( (char *)TempBuf, "%d", 0 );
						strcat((char *)AtRspBuf, (char *)TempBuf);
					}

					strcat((char *)AtRspBuf, ",");

					/* PDP header compression */
					if ( getPdpPrimCnf->ctx.pdpCtx.hcompPresent )
					{
						sprintf( (char *)TempBuf, "%d", getPdpPrimCnf->ctx.pdpCtx.hcomp );
						strcat((char *)AtRspBuf, (char *)TempBuf);
					}
					else
					{
						sprintf( (char *)TempBuf, "%d", 0 );
						strcat((char *)AtRspBuf, (char *)TempBuf);
					}

					strcat((char *)AtRspBuf, ",");

					if(getPdpPrimCnf->ctx.pdpCtx.ipAddrAllocPresent)
					{
						sprintf((char *)TempBuf, "%d", getPdpPrimCnf->ctx.pdpCtx.ipAddrAlloc);
						strcat((char *)AtRspBuf, (char *)TempBuf);
					}

					strcat((char *)AtRspBuf, ",");


					if(getPdpPrimCnf->ctx.pdpCtx.reqTypePresent)
					{
						sprintf((char *)TempBuf, "%d", getPdpPrimCnf->ctx.pdpCtx.reqType);
						strcat((char *)AtRspBuf, (char *)TempBuf);
					}
					strcat((char *)AtRspBuf, ",");

					if(getPdpPrimCnf->ctx.pdpCtx.pCscfDiscoveryPresent)
					{
						sprintf((char *)TempBuf, "%d", getPdpPrimCnf->ctx.pdpCtx.pCscfDiscovery);
						strcat((char *)AtRspBuf, (char *)TempBuf);
					}

					strcat((char *)AtRspBuf, ",");

					if(getPdpPrimCnf->ctx.pdpCtx.imCnSignallingFlagIndPresent)
					{
						sprintf((char *)TempBuf, "%d", getPdpPrimCnf->ctx.pdpCtx.imCnSignallingFlagInd);
						strcat((char *)AtRspBuf, (char *)TempBuf);
					}


#ifdef LWIP_IPNETBUF_SUPPORT
					/* dialer atp index do not send the query result to dialer*/
					UINT32 atHandle = GET_AT_HANDLE(reqHandle);
					TelAtParserID sAtpIndex = (TelAtParserID)GET_ATP_INDEX(atHandle);
					if (sAtpIndex != DIALER_ATP_INDEX|| getPdpPrimCnf->ctx.actState == TRUE)
#endif
					{
				//Fitz.xu 20211020: For SIM2, when execute at+cgdcont? do not show cid1-4
					#if QUEC_DUAL_SIM_SUPPORT
						if (getDualSimType() == CM_DUAL_SIM_SINGLE_STANDBY)
						{
							ATRESP( reqHandle,0,0,(char *)AtRspBuf);
						}
						else
						{
							//Fitz.xu 20211206: To fix asr channel can not get query info.
							if (QUEC_IS_VALID_ATP(GET_ATP_INDEX(reqHandle)))
							{
								if (((GET_ATP_INDEX(reqHandle) < 36) && (currCid < 4)) || 
									((GET_ATP_INDEX(reqHandle) >= 36) && (currCid > 3)) )
								{
									ATRESP( reqHandle,0,0,(char *)AtRspBuf);
								}
							}
							else
							{
								ATRESP( reqHandle,0,0,(char *)AtRspBuf);	
							}
						}
					#else
						ATRESP( reqHandle,0,0,(char *)AtRspBuf);
					#endif
					}
				}  /* if (CIRC_PS_SUCCESS) */
#ifdef LWIP_IPNETBUF_SUPPORT
				else if (getPdpPrimCnf->ctxPresent == 0)
				{
					/* if redefine APN exist, display it*/
					if (psPdpInfo && psPdpInfo->reDefined)
					{
						char *p = AtRspBuf;
						p += sprintf(p, "+CGDCONT: %d,", currCid + 1 );

						getPdpTypeStr ( psPdpInfo->apnInfo.ipType, TempBuf );
						strcat((char *)AtRspBuf, (char *)TempBuf);
						strcat((char *)AtRspBuf, ",\"" );
						if (strlen(psPdpInfo->apnInfo.apn) > 0)
							strcpy(TempBuf, psPdpInfo->apnInfo.apn);
						else
							TempBuf[0] = '\0';

						strcat((char *)AtRspBuf, (char *)TempBuf);
						strcat((char *)AtRspBuf, "\"" );

						/*do not send the query result to dialer*/
						if (sAtpIndex != DIALER_ATP_INDEX)
						{
						#if QUEC_DUAL_SIM_SUPPORT
							if (getDualSimType() == CM_DUAL_SIM_SINGLE_STANDBY)
							{
								ATRESP( reqHandle,0,0,(char *)AtRspBuf);
							}
							else
							{
								if (((GET_ATP_INDEX(reqHandle) < 36) && (currCid < 4)) || 
									((GET_ATP_INDEX(reqHandle) >= 36) && (currCid > 3)) )
								{
									ATRESP( reqHandle,0,0,(char *)AtRspBuf);
								}
							}
						#else
							ATRESP( reqHandle,0,0,(char *)AtRspBuf);
						#endif
						}
					}
					/* should set to deactived status, the cid may remapd by other cid
                     * but SAC will not report deact/nok ind for remaped cid, here should cleanup the status
                     */
					if (psPdpInfo)
					    psPdpInfo->activedStatus = 0;
				}
#endif
				else
				{
					/* just ignore the confirmation - nothing to display*/
				}

				/* send request for next CID  */
				currCid++;
				if ( currCid < CI_PS_MAX_CID)
				{
					/* request info about every primary context */
					getNxtPdpCtxReq = utlCalloc(1, sizeof(*getNxtPdpCtxReq));
					if (getNxtPdpCtxReq == NULL) {
#ifdef LWIP_IPNETBUF_SUPPORT
						exitQueryPdpCtx(reqHandle);
#endif
						ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						break;
					}
					getNxtPdpCtxReq->cid = currCid;

					gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = currCid;

					/*
					 **  Send the CI Request.
					 */
					ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ,
							reqHandle, (void *)getNxtPdpCtxReq );
				}
				else
				{
					/* completed operation */
#ifdef LWIP_IPNETBUF_SUPPORT
					if (getQueryPdpCtxInProcess(reqHandle) == FALSE)
					{
						if (GET_ATP_INDEX(reqHandle) == DIALER_ATP_INDEX)
							ATRESP( reqHandle,ATCI_RESULT_CODE_ERROR,0, NULL);
						else
							ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0, NULL);
						break;
					}
					else
					{
						exitQueryPdpCtx(reqHandle);
						ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0, NULL);
					}
					sendPdpCxtListToCm(reqHandle);
#else
                    ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
#endif
//					extern void UsbnetUpdatePdpLinkStatusEnd(void);
//					UsbnetUpdatePdpLinkStatusEnd();
				}
			}
			else if (GET_REQ_ID(reqHandle) == PRI_PS_PRIM_GET_IP_REQ || GET_REQ_ID(reqHandle) == PRI_PS_PRIM_GET_IP_EXTEND_REQ)
			{
				getPdpPrimCnf = (CiPsPrimGetPdpCtxCnf *)paras;

				if (( getPdpPrimCnf->rc == CIRC_PS_SUCCESS ) &&  ( getPdpPrimCnf->ctxPresent))
				{
					int len4 = 0;
					int len6 = 0;
					const UINT8 *ip4 = getPdpPrimCnf->ctx.pdpCtx.ipv4Addr.valData;
					const UINT8 *ip6 = getPdpPrimCnf->ctx.pdpCtx.ipv6Addr.valData;
					UINT8 gw4[CI_PS_PDP_IP_V4_SIZE] = {0};
					UINT8 gw6[CI_PS_PDP_IP_V6_SIZE] = {0};
					char ipp4[CI_PS_PDP_IP_V4_SIZE] = {0};
					char ipp6[CI_PS_PDP_IP_V6_SIZE] = {0};
					char gwp4[CI_PS_PDP_IP_V4_SIZE] = {0};
					char gwp6[CI_PS_PDP_IP_V6_SIZE] = {0};
                    int addrType;
					unsigned char* valData;

					if(getPdpPrimCnf->ctx.pdpCtx.ipv4Addr.addrType == CI_PS_PDP_IPV4)
						len4 = IPV4_ADDR_LENGTH;
					if(getPdpPrimCnf->ctx.pdpCtx.ipv6Addr.addrType == CI_PS_PDP_FULL_IPV6)
						len6 = IPV6_FULL_ADDR_LENGTH;
					else if(getPdpPrimCnf->ctx.pdpCtx.ipv6Addr.addrType == CI_PS_PDP_IPV6_INTERFACE)
						len6 = IPV6_INTERFACE_ADDR_LENGTH;

					memcpy(gw4, ip4, len4);
                    gw4[len4 - 1] ^= 0xFF;

                    _inet_ntop(AF_INET, gw4, gwp4, CI_PS_PDP_IP_V4_SIZE);

                    if (len6 == IPV6_INTERFACE_ADDR_LENGTH)					
						memcpy(gw6 + IPV6_INTERFACE_ADDR_LENGTH, ip6, len6);						
					else if (len6 == IPV6_FULL_ADDR_LENGTH)
						memcpy(gw6, ip6, len6);
										
					gw6[IPV6_FULL_ADDR_LENGTH - 1] ^= 0xFF;
					convertIpUnit2Str(reqHandle, CI_PS_PDP_FULL_IPV6, gw6, gwp6);                  

                    addrType = getPdpPrimCnf->ctx.pdpCtx.ipv4Addr.addrType;
					valData = getPdpPrimCnf->ctx.pdpCtx.ipv4Addr.valData;
					if(addrType == CI_PS_PDP_IPV4)
						convertIpUnit2Str(reqHandle, addrType, valData, ipp4);

					addrType = getPdpPrimCnf->ctx.pdpCtx.ipv6Addr.addrType;
					valData = getPdpPrimCnf->ctx.pdpCtx.ipv6Addr.valData;
					if((addrType == CI_PS_PDP_FULL_IPV6) || (addrType == CI_PS_PDP_IPV6_INTERFACE))
						convertIpUnit2Str(reqHandle, addrType, valData, ipp6);

					if(getPdpPrimCnf->ctx.pdpCtx.type == CI_PS_PDP_TYPE_IP)
					{
						if ( GET_REQ_ID(reqHandle) == PRI_PS_PRIM_GET_IP_EXTEND_REQ)
						{
							if (getPdpPrimCnf->ctx.pdpCtx.apnPresent==1)
								snprintf(AtRspBuf, 1000*sizeof(char), "*GETIP: %d, \"%s\", \"%s\", \"%s\"", CI_PS_PDP_TYPE_IP, ipp4, gwp4, 
										getPdpPrimCnf->ctx.pdpCtx.apn.valStr);
							else
								snprintf(AtRspBuf, 1000*sizeof(char), "*GETIP: %d, \"%s\", \"%s\"", CI_PS_PDP_TYPE_IP, ipp4, gwp4);
						}
						else
							snprintf(AtRspBuf, 1000*sizeof(char), "+GETIP: \"%s\", \"%s\"", ipp4, gwp4);

					}
					else if(getPdpPrimCnf->ctx.pdpCtx.type == CI_PS_PDP_TYPE_IPV6)
					{
						if ( GET_REQ_ID(reqHandle) == PRI_PS_PRIM_GET_IP_EXTEND_REQ)
						{
							if (getPdpPrimCnf->ctx.pdpCtx.apnPresent==1)
								snprintf(AtRspBuf, 1000*sizeof(char), "*GETIP: %d, \"%s\", \"%s\", \"%s\"", CI_PS_PDP_TYPE_IPV6, ipp6, gwp6,
										getPdpPrimCnf->ctx.pdpCtx.apn.valStr);
							else
								snprintf(AtRspBuf, 1000*sizeof(char), "*GETIP: %d, \"%s\", \"%s\"", CI_PS_PDP_TYPE_IPV6, ipp6, gwp6);
						}
						else
							snprintf(AtRspBuf, 1000*sizeof(char), "+GETIP: \"%s\", \"%s\"", ipp6, gwp6);

					}
					else if(getPdpPrimCnf->ctx.pdpCtx.type == CI_PS_PDP_TYPE_IPV4V6)
					{
						if ( GET_REQ_ID(reqHandle) == PRI_PS_PRIM_GET_IP_EXTEND_REQ)
						{
							if (getPdpPrimCnf->ctx.pdpCtx.apnPresent==1)
								snprintf(AtRspBuf, 1000*sizeof(char), "*GETIP: %d, \"%s\", \"%s\", \"%s\", \"%s\", \"%s\"", CI_PS_PDP_TYPE_IPV4V6, ipp4, 
										gwp4, ipp6, gwp6, getPdpPrimCnf->ctx.pdpCtx.apn.valStr);
							else
								snprintf(AtRspBuf, 1000*sizeof(char), "*GETIP: %d, \"%s\", \"%s\", \"%s\", \"%s\"", CI_PS_PDP_TYPE_IPV4V6, ipp4, 
										gwp4, ipp6, gwp6);
						}
						else
							snprintf(AtRspBuf, 1000*sizeof(char), "+GETIP: \"%s %s\", \"%s %s\"", ipp4, gwp4, ipp6, gwp6);

					}
					else
					{
						/*Fixed coverity[suspicious_sizeof]*/
						if ( GET_REQ_ID(reqHandle) == PRI_PS_PRIM_GET_IP_EXTEND_REQ)
							snprintf(AtRspBuf, 1000*sizeof(char), "*GETIP:");
						else
							snprintf(AtRspBuf, 1000*sizeof(char), "+GETIP:");

					}

					ATRESP(reqHandle, ATCI_RESULT_CODE_OK, 0, AtRspBuf);
				}
				else
				{
					ATRESP(reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				}
#ifdef LWIP_IPNETBUF_SUPPORT
				exitQueryPdpCtx(reqHandle);
#endif
			}
			else if (GET_REQ_ID(reqHandle) == CI_PS_PRIM_GET_PDP_ADDR_REQ)
			{
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
			
				/* query was for an AT+CGPADDR? */
				getPdpPrimCnf = (CiPsPrimGetPdpCtxCnf *)paras;
#ifdef QUECTEL_NETWORK_SUPPORT
				if ((*pQueryCidAddrNum > 0 ) && ( getPdpPrimCnf->ctxPresent))
				{
				    /*isaac 20211001 解决iptype ppp format issue*/
					snprintf(AtRspBuf, 1000*sizeof(char), "\r\n+CGPADDR: %d,\"0.0.0.0\"", getPdpPrimCnf->ctx.pdpCtx.cid + 1);
				}
#endif

				if (( getPdpPrimCnf->rc == CIRC_PS_SUCCESS ) &&  ( getPdpPrimCnf->ctxPresent))
				{
					int i, addrType;
					unsigned char* valData;
					char tempBuf[50];
					char ipp4Buf[CI_PS_PDP_IP_V4_SIZE] = { '\0' };
					char ipp6Buf[CI_PS_PDP_IP_V6_SIZE] = { '\0' };
#ifdef QUECTEL_NETWORK_SUPPORT
					sprintf(ipp4Buf, "%s", "0.0.0.0");
					sprintf(ipp6Buf, "%s", "0:0:0:0:0:0:0:0");
#endif


					addrType = getPdpPrimCnf->ctx.pdpCtx.ipv4Addr.addrType;
					if(addrType == CI_PS_PDP_IPV4)
					{
						valData = getPdpPrimCnf->ctx.pdpCtx.ipv4Addr.valData;
						convertIpUnit2Str(reqHandle, addrType, valData, ipp4Buf);
					}

					addrType = getPdpPrimCnf->ctx.pdpCtx.ipv6Addr.addrType;
					if((addrType == CI_PS_PDP_FULL_IPV6) || (addrType == CI_PS_PDP_IPV6_INTERFACE))
					{
#ifdef QUECTEL_NETWORK_SUPPORT	
#ifdef QUEC_NETDUALCH_CFG
                        if(QUEC_NET_DEFAULT_PASS_FLAG != g_quec_net_dualch_cfg[getPdpPrimCnf->ctx.pdpCtx.cid].net_flag)
#endif
                        {
						    struct sockaddr_in6 ip6;
	                        char *ip_addr = NULL;

							memset(&ip6, 0, sizeof(struct sockaddr_in6));
							extern int quec_cm_get_ip6_addr(int pdp_cid, struct sockaddr_in6 * _sockaddr,UINT8 *cm_addr);
	                        quec_cm_get_ip6_addr(getPdpPrimCnf->ctx.pdpCtx.cid + 1,&ip6,getPdpPrimCnf->ctx.pdpCtx.ipv6Addr.valData);
	                        
	                        ip_addr = inet6_ntoa(ip6.sin6_addr);
						    memcpy(ipp6Buf,ip_addr,strlen(ip_addr));
                        }
#ifdef QUEC_NETDUALCH_CFG
						else 
						{
							valData = getPdpPrimCnf->ctx.pdpCtx.ipv6Addr.valData;
							if(QUEC_NET_DEFAULT_PASS_FLAG == g_quec_net_dualch_cfg[getPdpPrimCnf->ctx.pdpCtx.cid].net_flag)
							{
								if(CI_PS_PDP_FULL_IPV6 == getPdpPrimCnf->ctx.pdpCtx.ipv6Addr.addrType)
								{
								   for(i = 0; i < IPV6_INTERFACE_ADDR_LENGTH; i++)
								   {
									   valData[i] = getPdpPrimCnf->ctx.pdpCtx.ipv6Addr.valData[i + IPV6_INTERFACE_ADDR_LENGTH]; 
								   }
								   addrType = CI_PS_PDP_IPV6_INTERFACE;
								}								 
							}
							convertIpUnit2Str(reqHandle, addrType, valData, ipp6Buf);							
						} 
#endif

#else
						valData = getPdpPrimCnf->ctx.pdpCtx.ipv6Addr.valData;
						convertIpUnit2Str(reqHandle, addrType, valData, ipp6Buf);
#endif
					}
					if(getPdpPrimCnf->ctx.pdpCtx.type == CI_PS_PDP_TYPE_IP)
					{
#ifdef QUECTEL_NETWORK_SUPPORT
						sprintf(AtRspBuf, "\r\n+CGPADDR: %d,\"%s\"", getPdpPrimCnf->ctx.pdpCtx.cid + 1, ipp4Buf);
#else
						/*Fixed coverity[suspicious_sizeof]*/
						snprintf(AtRspBuf, 1000*sizeof(char), "+CGPADDR: %d, \"%s\"", getPdpPrimCnf->ctx.pdpCtx.cid + 1, ipp4Buf);
#endif
					}
					else if(getPdpPrimCnf->ctx.pdpCtx.type == CI_PS_PDP_TYPE_IPV6)
					{
#ifdef QUECTEL_NETWORK_SUPPORT
						sprintf(AtRspBuf, "\r\n+CGPADDR: %d,\"%s\"", getPdpPrimCnf->ctx.pdpCtx.cid + 1, ipp6Buf);
#else
						/*Fixed coverity[suspicious_sizeof]*/
						snprintf(AtRspBuf, 1000*sizeof(char), "+CGPADDR: %d, \"%s\"", getPdpPrimCnf->ctx.pdpCtx.cid + 1, ipp6Buf);
#endif
					}
					else if(getPdpPrimCnf->ctx.pdpCtx.type == CI_PS_PDP_TYPE_IPV4V6)
					{
#ifdef QUECTEL_NETWORK_SUPPORT
						sprintf(AtRspBuf, "\r\n+CGPADDR: %d,\"%s\",\"%s\"", getPdpPrimCnf->ctx.pdpCtx.cid + 1, ipp4Buf, ipp6Buf);
#else
						/*Fixed coverity[suspicious_sizeof]*/
						snprintf(AtRspBuf, 1000*sizeof(char), "+CGPADDR: %d, \"%s\", \"%s\"", getPdpPrimCnf->ctx.pdpCtx.cid + 1, ipp4Buf, ipp6Buf);
#endif
					}
					else
					{
						/*Fixed coverity[suspicious_sizeof]*/
						#ifdef QUECTEL_NETWORK_SUPPORT  //Chaim 20200317 repair iptype is ppp display format 
                            /*isaac 20211001 解决iptype ppp format issue*/
							snprintf(AtRspBuf, 1000*sizeof(char), "\r\n+CGPADDR: %d,\"%s\"", getPdpPrimCnf->ctx.pdpCtx.cid + 1, ipp4Buf);
						#else
						snprintf(AtRspBuf, 1000*sizeof(char), "+CGPADDR:");
						#endif
					}

#ifndef QUECTEL_NETWORK_SUPPORT
					ATRESP(reqHandle, 0, 0, AtRspBuf);
#endif
				}
				
#ifdef QUECTEL_NETWORK_SUPPORT
				if (strlen(AtRspBuf) > 0)
				{
					ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, AtRspBuf, FALSE);
				}
#endif

				if(*pQueryCidAddrCount == *pQueryCidAddrNum)
				{
#if defined QUECTEL_PROJECT_CUST
					ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, "\r\n", FALSE);
#endif
					ATRESP(reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
				}
				else
				{
					/* send request for next CID  */
					getNxtPdpCtxReq = utlCalloc(1, sizeof(*getNxtPdpCtxReq));
					if (getNxtPdpCtxReq == NULL) {
						ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						break;
					}

					getNxtPdpCtxReq->cid = pCgpaddrCidArray[(*pQueryCidAddrCount)++];
					gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = getNxtPdpCtxReq->cid;
					/*
					**  Send the CI Request.
					*/
					ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ,
							 reqHandle, (void *)getNxtPdpCtxReq );
				}
#ifdef LWIP_IPNETBUF_SUPPORT
				exitQueryPdpCtx(reqHandle);
#endif
}//MiniSystem
else
{
				/* query was for an AT+CGPADDR? */
				getPdpPrimCnf = (CiPsPrimGetPdpCtxCnf *)paras;

				if (( getPdpPrimCnf->rc == CIRC_PS_SUCCESS ) &&  ( getPdpPrimCnf->ctxPresent))
				{
					int i, addrType;
					unsigned char* valData;
					char tempBuf[50];
					char ipp4Buf[CI_PS_PDP_IP_V4_SIZE] = { '\0' };
					char ipp6Buf[CI_PS_PDP_IP_V6_SIZE] = { '\0' };


					addrType = getPdpPrimCnf->ctx.pdpCtx.ipv4Addr.addrType;
					if(addrType == CI_PS_PDP_IPV4)
					{
						valData = getPdpPrimCnf->ctx.pdpCtx.ipv4Addr.valData;
						convertIpUnit2Str(reqHandle, addrType, valData, ipp4Buf);
					}

					addrType = getPdpPrimCnf->ctx.pdpCtx.ipv6Addr.addrType;
					if((addrType == CI_PS_PDP_FULL_IPV6) || (addrType == CI_PS_PDP_IPV6_INTERFACE))
					{
						valData = getPdpPrimCnf->ctx.pdpCtx.ipv6Addr.valData;
						convertIpUnit2Str(reqHandle, addrType, valData, ipp6Buf);
					}
					if(getPdpPrimCnf->ctx.pdpCtx.type == CI_PS_PDP_TYPE_IP)
					{
						/*Fixed coverity[suspicious_sizeof]*/
						snprintf(AtRspBuf, 1000*sizeof(char), "+CGPADDR: %d, \"%s\"", getPdpPrimCnf->ctx.pdpCtx.cid + 1, ipp4Buf);
					}
					else if(getPdpPrimCnf->ctx.pdpCtx.type == CI_PS_PDP_TYPE_IPV6)
					{
						/*Fixed coverity[suspicious_sizeof]*/
						snprintf(AtRspBuf, 1000*sizeof(char), "+CGPADDR: %d, \"%s\"", getPdpPrimCnf->ctx.pdpCtx.cid + 1, ipp6Buf);
					}
					else if(getPdpPrimCnf->ctx.pdpCtx.type == CI_PS_PDP_TYPE_IPV4V6)
					{
						/*Fixed coverity[suspicious_sizeof]*/
						snprintf(AtRspBuf, 1000*sizeof(char), "+CGPADDR: %d, \"%s\", \"%s\"", getPdpPrimCnf->ctx.pdpCtx.cid + 1, ipp4Buf, ipp6Buf);
					}
					else
					{
						/*Fixed coverity[suspicious_sizeof]*/
						snprintf(AtRspBuf, 1000*sizeof(char), "+CGPADDR:");
					}

					ATRESP(reqHandle, 0, 0, AtRspBuf);
				}

				if(*pQueryCidAddrCount == *pQueryCidAddrNum)
					ATRESP(reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
				else
				{
					/* send request for next CID  */
					getNxtPdpCtxReq = utlCalloc(1, sizeof(*getNxtPdpCtxReq));
					if (getNxtPdpCtxReq == NULL) {
						ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						break;
					}

					getNxtPdpCtxReq->cid = pCgpaddrCidArray[(*pQueryCidAddrCount)++];
					gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = getNxtPdpCtxReq->cid;
					/*
					**  Send the CI Request.
					*/
					ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_PDP_CTX_REQ,
							 reqHandle, (void *)getNxtPdpCtxReq );
				}
#ifdef LWIP_IPNETBUF_SUPPORT
				exitQueryPdpCtx(reqHandle);
#endif

}
#endif /*MIN_SYS*/
			}
			break;
		}
#ifndef LTEONLY_THIN

		case CI_PS_PRIM_GET_3G_QOS_CAPS_CNF:
		{
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
		
			get3GQosCapsCnf = (CiPsPrimGet3GQosCapsCnf *)paras;

			if ( get3GQosCapsCnf->rc == CIRC_PS_SUCCESS )
			{
				if (get3GQosCapsCnf->qosCapsPresent)
				{
					CiPs3GQosCap *pCtxCaps = get3GQosCapsCnf->qosCaps.caps;

					for ( i = 0; i < get3GQosCapsCnf->qosCaps.size; i++ )
					{
						/* get PDP type string */
						getPdpTypeStr ( pCtxCaps->type, TempBuf );

						switch (GET_REQ_ID(reqHandle))
						{
#ifdef QUECTEL_NETWORK_SUPPORT
							case PRI_PS_PRIM_GET_MIN_QOS_CAPS_REQ:
								{
									sprintf ( (char *)AtRspBuf,"\r\n+CGEQMIN: " );
									ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, AtRspBuf, FALSE);
									break;
								}
							case CI_PS_PRIM_GET_3G_QOS_CAPS_REQ:
								{
									sprintf ( (char *)AtRspBuf,"\r\n+CGEQREQ: " );
									ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, AtRspBuf, FALSE);
									break;
								}
							case PRI_PS_PRIM_GET_NEG_QOS_CAPS_REQ:
								{
									sprintf ( (char *)AtRspBuf,"\r\n+CGEQNEG: " );
									ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, AtRspBuf, FALSE);
									break;
								}
#else
							case PRI_PS_PRIM_GET_MIN_QOS_CAPS_REQ:
							{
								sprintf( (char *)AtRspBuf, "CGEQMIN: " );
								ATRESP( reqHandle, 0, 0, (char *)AtRspBuf);
								break;
							}
							case CI_PS_PRIM_GET_3G_QOS_CAPS_REQ:
							{
								sprintf( (char *)AtRspBuf, "CGEQREQ: " );
								ATRESP( reqHandle, 0, 0, (char *)AtRspBuf);
								break;
							}
							case PRI_PS_PRIM_GET_NEG_QOS_CAPS_REQ:
							{
								sprintf( (char *)AtRspBuf, "CGEQNEG: " );
								ATRESP( reqHandle, 0, 0, (char *)AtRspBuf);
								break;
							}
#endif
							default:
								ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
								goto end;
						}
						sprintf( (char *)AtRspBuf, "%s,(%d-%d),",
							 TempBuf,
							 pCtxCaps->trafficClass.min,
							 pCtxCaps->trafficClass.max);
						sprintf( (char *)TempBuf, "(%d-%d),(%d-%d),",
							 Decode3GBitRate(pCtxCaps->maxULRate.min,FALSE),
							 Decode3GBitRate(pCtxCaps->maxULRate.max,TRUE),
							 Decode3GBitRate(pCtxCaps->maxDLRate.min,FALSE),
							 Decode3GBitRate(pCtxCaps->maxDLRate.max,TRUE));
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						sprintf( (char *)TempBuf, "(%d-%d),(%d-%d),",
							 Decode3GBitRate(pCtxCaps->guaranteedULRate.min, FALSE),
							 Decode3GBitRate(pCtxCaps->guaranteedULRate.max, TRUE),
							 Decode3GBitRate(pCtxCaps->guaranteedDLRate.min, FALSE),
							 Decode3GBitRate(pCtxCaps->guaranteedDLRate.max, TRUE));
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						sprintf( (char *)TempBuf, "(%d-%d),(%d-%d),(\"",
							 pCtxCaps->deliveryOrder.min,
							 pCtxCaps->deliveryOrder.max,
							 Decode3GMaxSduSize(pCtxCaps->maxSduSize.min),
							 Decode3GMaxSduSize(pCtxCaps->maxSduSize.max));
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						printSduErrRatio( (char *)TempBuf, pCtxCaps->errRatio.min );
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						strcat( (char *)AtRspBuf, "\"-\"" );
						printSduErrRatio( (char *)TempBuf, pCtxCaps->errRatio.max );
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						strcat( (char *)AtRspBuf, "\"),(\"" );
						printResBER( (char *)TempBuf, pCtxCaps->resBER.min );
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						strcat( (char *)AtRspBuf, "\"-\"" );
						printResBER( (char *)TempBuf, pCtxCaps->resBER.max );
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						strcat( (char *)AtRspBuf, "\")," );
						sprintf( (char *)TempBuf, "(%d-%d),(%d-%d),",
							 pCtxCaps->deliverErrSdu.min,
							 pCtxCaps->deliverErrSdu.max,
							 pCtxCaps->transDelay.min,
							 pCtxCaps->transDelay.max);
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						sprintf( (char *)TempBuf, "(%d-%d),",
							 pCtxCaps->thPriority.min,
							 pCtxCaps->thPriority.max );
						strcat( (char *)AtRspBuf, (char *)TempBuf );
#ifdef QUECTEL_NETWORK_SUPPORT
						sprintf( (char *)TempBuf, "(0,1),(0,1)");
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, AtRspBuf, FALSE);
#else
						sprintf( (char *)TempBuf, "(0-1),(0-1)");
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						ATRESP( reqHandle, 0, 0, (char *)AtRspBuf);
#endif

						pCtxCaps++;
					}
#if defined QUECTEL_NETWORK_SUPPORT
					ATRESPEX(reqHandle, ATCI_RESULT_CODE_NULL, 0, "\r\n", FALSE);
#endif
				}
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
				checkPSRet(reqHandle, get3GQosCapsCnf->rc);

}//MiniSystem
else
{
			get3GQosCapsCnf = (CiPsPrimGet3GQosCapsCnf *)paras;

			if ( get3GQosCapsCnf->rc == CIRC_PS_SUCCESS )
			{
				if (get3GQosCapsCnf->qosCapsPresent)
				{
					CiPs3GQosCap *pCtxCaps = get3GQosCapsCnf->qosCaps.caps;

					for ( i = 0; i < get3GQosCapsCnf->qosCaps.size; i++ )
					{
						/* get PDP type string */
						getPdpTypeStr ( pCtxCaps->type, TempBuf );

						switch (GET_REQ_ID(reqHandle))
						{
							case PRI_PS_PRIM_GET_MIN_QOS_CAPS_REQ:
							{
								sprintf( (char *)AtRspBuf, "CGEQMIN: " );
								ATRESP( reqHandle, 0, 0, (char *)AtRspBuf);
								break;
							}
							case CI_PS_PRIM_GET_3G_QOS_CAPS_REQ:
							{
								sprintf( (char *)AtRspBuf, "CGEQREQ: " );
								ATRESP( reqHandle, 0, 0, (char *)AtRspBuf);
								break;
							}
							case PRI_PS_PRIM_GET_NEG_QOS_CAPS_REQ:
							{
								sprintf( (char *)AtRspBuf, "CGEQNEG: " );
								ATRESP( reqHandle, 0, 0, (char *)AtRspBuf);
								break;
							}
							default:
								ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
								goto end;
						}
						sprintf( (char *)AtRspBuf, "%s,(%d-%d),",
							 TempBuf,
							 pCtxCaps->trafficClass.min,
							 pCtxCaps->trafficClass.max);
						sprintf( (char *)TempBuf, "(%d-%d),(%d-%d),",
							 Decode3GBitRate(pCtxCaps->maxULRate.min,FALSE),
							 Decode3GBitRate(pCtxCaps->maxULRate.max,TRUE),
							 Decode3GBitRate(pCtxCaps->maxDLRate.min,FALSE),
							 Decode3GBitRate(pCtxCaps->maxDLRate.max,TRUE));
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						sprintf( (char *)TempBuf, "(%d-%d),(%d-%d),",
							 Decode3GBitRate(pCtxCaps->guaranteedULRate.min, FALSE),
							 Decode3GBitRate(pCtxCaps->guaranteedULRate.max, TRUE),
							 Decode3GBitRate(pCtxCaps->guaranteedDLRate.min, FALSE),
							 Decode3GBitRate(pCtxCaps->guaranteedDLRate.max, TRUE));
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						sprintf( (char *)TempBuf, "(%d-%d),(%d-%d),(\"",
							 pCtxCaps->deliveryOrder.min,
							 pCtxCaps->deliveryOrder.max,
							 Decode3GMaxSduSize(pCtxCaps->maxSduSize.min),
							 Decode3GMaxSduSize(pCtxCaps->maxSduSize.max));
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						printSduErrRatio( (char *)TempBuf, pCtxCaps->errRatio.min );
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						strcat( (char *)AtRspBuf, "\"-\"" );
						printSduErrRatio( (char *)TempBuf, pCtxCaps->errRatio.max );
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						strcat( (char *)AtRspBuf, "\"),(\"" );
						printResBER( (char *)TempBuf, pCtxCaps->resBER.min );
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						strcat( (char *)AtRspBuf, "\"-\"" );
						printResBER( (char *)TempBuf, pCtxCaps->resBER.max );
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						strcat( (char *)AtRspBuf, "\")," );
						sprintf( (char *)TempBuf, "(%d-%d),(%d-%d),",
							 pCtxCaps->deliverErrSdu.min,
							 pCtxCaps->deliverErrSdu.max,
							 pCtxCaps->transDelay.min,
							 pCtxCaps->transDelay.max);
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						sprintf( (char *)TempBuf, "(%d-%d),",
							 pCtxCaps->thPriority.min,
							 pCtxCaps->thPriority.max );
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						sprintf( (char *)TempBuf, "(0-1),(0-1)");
						strcat( (char *)AtRspBuf, (char *)TempBuf );
						ATRESP( reqHandle, 0, 0, (char *)AtRspBuf);

						pCtxCaps++;
					}
				}
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
				checkPSRet(reqHandle, get3GQosCapsCnf->rc);

}
#endif /*MIN_SYS*/
			break;
		}

		case CI_PS_PRIM_GET_3G_QOS_CNF:
		{
			getQos3GCnf = (CiPsPrimGet3GQosCnf *)paras;
			CiPs3GQosType qosType;
			int ulRate, dlRate, maxSdu;
			UINT8 currCid = gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid;

			if(currCid >= CI_PS_MAX_CID)
			{
				resetCurrCntx(GET_ATP_INDEX(reqHandle));
				ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				break;
			}


			switch (GET_REQ_ID(reqHandle))
			{
				case PRI_PS_PRIM_GET_MIN_QOS_REQ:
				{
					sprintf( (char *)AtRspBuf, "%s", "+CGEQMIN: " );
					qosType = CI_PS_3G_QOSTYPE_MIN;
					break;
				}
				case CI_PS_PRIM_GET_3G_QOS_REQ:
				{
					sprintf( (char *)AtRspBuf, "%s", "+CGEQREQ: " );
					qosType = CI_PS_3G_QOSTYPE_REQ;
					break;
				}
				case PRI_PS_PRIM_GET_NEG_QOS_REQ:
				{
					sprintf( (char *)AtRspBuf, "%s", "+CGEQNEG: " );
					qosType = CI_PS_3G_QOSTYPE_NEG;
					break;
				}
				default:
				{
					ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
					goto end;
				}
			}

			if (( getQos3GCnf->rc == CIRC_PS_SUCCESS ) && getQos3GCnf->qosProfPresent )
			{

				/* Print the part that is common to REQ,MIN, and NEG */
				ulRate = Decode3GBitRate(getQos3GCnf->qosProf.maxULRate,
					(((getQos3GCnf->qosProf.IsExtension & (1<<CI_PS_3G_MAX_BIT_RATE_FOR_UL)) != 0) ? TRUE : FALSE));
				dlRate = Decode3GBitRate(getQos3GCnf->qosProf.maxDLRate,
					(((getQos3GCnf->qosProf.IsExtension & (1<<CI_PS_3G_MAX_BIT_RATE_FOR_DL)) != 0) ? TRUE : FALSE));

				sprintf( (char *)TempBuf, "%d,%d,%d,%d,",
					 currCid + 1, /* in SAC, PDP contexts start at 0 */
					 getQos3GCnf->qosProf.trafficClass,
					 ulRate, dlRate );
				strcat( (char *)AtRspBuf, (char *)TempBuf );
				ulRate = Decode3GBitRate(getQos3GCnf->qosProf.guaranteedULRate,
					(((getQos3GCnf->qosProf.IsExtension & (1<<CI_PS_3G_GUARNTEED_BIT_RATE_FOR_UL)) != 0) ? TRUE : FALSE));
				dlRate = Decode3GBitRate(getQos3GCnf->qosProf.guaranteedDLRate,
					(((getQos3GCnf->qosProf.IsExtension & (1<<CI_PS_3G_GUARNTEED_BIT_RATE_FOR_DL)) != 0) ? TRUE : FALSE));
				maxSdu = Decode3GMaxSduSize(getQos3GCnf->qosProf.maxSduSize);
				sprintf( (char *)TempBuf, "%d,%d,%d,%d,\"",
					 ulRate, dlRate,
					 getQos3GCnf->qosProf.deliveryOrder, maxSdu);
				strcat( (char *)AtRspBuf, (char *)TempBuf );
				printSduErrRatio( (char *)TempBuf, getQos3GCnf->qosProf.sduErrRatio );
				strcat( (char *)AtRspBuf, (char *)TempBuf );
				strcat( (char *)AtRspBuf, "\",\"" );
				printResBER( (char *)TempBuf, getQos3GCnf->qosProf.resBER );
				strcat( (char *)AtRspBuf, (char *)TempBuf );
				sprintf( (char *)TempBuf, "\",%d,%d,%d,%d,%d",
					 getQos3GCnf->qosProf.deliveryOfErrSdu,
					 Decode3GTransDelay(getQos3GCnf->qosProf.transDelay),
					 getQos3GCnf->qosProf.thPriority, getQos3GCnf->qosProf.SourceStatisticDescriptor,
					 getQos3GCnf->qosProf.SignallingIndication);
				strcat( (char *)AtRspBuf, (char *)TempBuf );
				ATRESP( reqHandle, 0, 0, (char *)AtRspBuf );

			}

			/* send query for next CID */
			currCid++;
			if ( currCid < CI_PS_MAX_CID)
			{
				getQos3GReq = utlCalloc(1, sizeof(*getQos3GReq));
				if (getQos3GReq == NULL) {
					ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
					break;
				}
				getQos3GReq->cid = currCid;
				getQos3GReq->qosType = qosType;
				gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = currCid;
				ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_GET_3G_QOS_REQ,
						reqHandle, (void *)getQos3GReq );
			}
			else
			{
				//resetCurrCntx(GET_ATP_INDEX(reqHandle));
				ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
			}
			break;
		}

		case CI_PS_PRIM_SET_3G_QOS_CNF:
		{
			setQos3GCnf = (CiPsPrimSet3GQosCnf *)paras;
			if( setQos3GCnf->rc == CIRC_PS_SUCCESS )
			{
				ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
			}
			else
			{
				checkPSRet(reqHandle, setQos3GCnf->rc);
			}
			break;
		}
#endif
		case CI_PS_PRIM_DELETE_PDP_CTX_CNF:
		{
			deletePdpCtxCnf = (CiPsPrimDeletePdpCtxCnf*)paras;
			
			DBGMSG("%s: at line %d.\n", __FUNCTION__, __LINE__);
			/*
			 * DELETE PDP CTX may be triggered by AT CMD Server internally,
			 *  in this case, we don't need to respond "OK"
			 */
			if (reqHandle != IND_REQ_HANDLE&&reqHandle != IND_REQ_HANDLE_1)
			{
				if(deletePdpCtxCnf->rc == CIRC_PS_SUCCESS)
				{
					atpIdx = GET_ATP_INDEX(reqHandle);
					if (gCIDList.currCntx[atpIdx].currCid != CI_PS_MAX_CID)
					{
						telPsPdpCtx *psPdpInfo =  telGetPdpCtx(gCIDList.currCntx[atpIdx].currCid);

						if((psPdpInfo != NULL) && (psPdpInfo->reDefined != 0))
						{
							psPdpInfo->reDefined = 0;
							psPdpInfo->apnInfo.defined = 0;
						}
					
						pdp_table_index = getPdpIndexByCid(gCIDList.currCntx[atpIdx].currCid,p_cInfo);
						if(pdp_table_index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
						{
							resetCurrCntx(atpIdx);
							p_cInfo[pdp_table_index].bDefined = FALSE;
							p_cInfo[pdp_table_index].cid = CI_PS_MAX_CID;
						}
					}
					
					ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
				}
				else
				{
					checkPSRet(reqHandle, deletePdpCtxCnf->rc);
				}
				
			}
			else
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			break;
		}

#ifndef MORE_ATC_SPACE_OPT
		case CI_PS_PRIM_DELETE_SEC_PDP_CTX_CNF:
		{
			deleteSecPdpCtxCnf = (CiPsPrimDeleteSecPdpCtxCnf*)paras;
			
			DBGMSG("CI_PS_PRIM_DELETE_SEC_PDP_CTX_CNF: at line %d.\n", __LINE__);
			if (reqHandle != IND_REQ_HANDLE&&reqHandle != IND_REQ_HANDLE_1)
			{
			
				if(deleteSecPdpCtxCnf->rc == CIRC_PS_SUCCESS)
				{
					atpIdx = GET_ATP_INDEX(reqHandle);
					if (gCIDList.currCntx[atpIdx].currCid != CI_PS_MAX_CID)
					{
						pdp_table_index = getPdpIndexByCid(gCIDList.currCntx[atpIdx].currCid,p_cInfo);
						if(pdp_table_index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
						{
							resetCurrCntx(atpIdx);
							p_cInfo[pdp_table_index].bDefined = FALSE;
							p_cInfo[pdp_table_index].cid = CI_PS_MAX_CID;
							
						}
					}
					ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
				}
				else
				{
					checkPSRet(reqHandle, deleteSecPdpCtxCnf->rc);
				}
				
			}
			else
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			break;
		}
#endif

		case CI_ERR_PRIM_HASNOSUPPORT_CNF:
		case CI_ERR_PRIM_HASINVALIDPARAS_CNF:
		case CI_ERR_PRIM_ISINVALIDREQUEST_CNF:
		{
			/* Reply with an "Operation not supported" error (CME ERROR 4) */
			ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
			//resetCurrCntx(GET_ATP_INDEX(reqHandle));
			break;
		}
#ifndef MORE_ATC_SPACE_OPT		
		//Added by Michal Bukai - CGCMOD Set command support
		case CI_PS_PRIM_MODIFY_PDP_CTX_CNF:
		{
			modifyPdpCtxCnf = (CiPsPrimModifyPdpCtxCnf *)paras;
			checkPSRet(reqHandle, modifyPdpCtxCnf->rc);
			break;
		}
#endif		
		//Added by Michal Bukai - CGCMOD Test command
		case CI_PS_PRIM_GET_PDP_CTXS_ACT_STATE_CNF:
		{
			getCtxAtcListCnf = (CiPsPrimGetPdpCtxsActStateCnf *)paras;
			if ( getCtxAtcListCnf->rc == CIRC_PS_SUCCESS )
			{
				CiPsPdpCtxActStateListPtr pCtxActLst = getCtxAtcListCnf->lst;
				char outputInfo[100];
				char tmp[10];
				memset(&outputInfo, 0, 100);
				memset(&tmp, 0, 10);

				sprintf(outputInfo, "+CGCMOD: ");
				UINT8 index = 0;

				for (index = 0; index < getCtxAtcListCnf->num && pCtxActLst; index++)
				{
					if (pCtxActLst->activated)
					{
						if (index != 0)
							strcat(outputInfo, ", ");

						sprintf(tmp, "%d", pCtxActLst->cid + 1);
						strcat(outputInfo, tmp);
					}
					pCtxActLst++;
				}

				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, outputInfo);
			}
			else
			{
				checkPSRet(reqHandle, getCtxAtcListCnf->rc);
			}
			break;
		}
#if 1//ndef MORE_ATC_SPACE_OPT
		/*Added by Michal Bukai - CGTFT support - START*/
		case CI_PS_PRIM_DEFINE_TFT_FILTER_CNF:
		{
			defineTftFilterCnf = (CiPsPrimDefineTftFilterCnf *)paras;
			checkPSRet(reqHandle, defineTftFilterCnf->rc);
			break;
		}
		case CI_PS_PRIM_DELETE_TFT_CNF:
		{
			deleteTftCnf = (CiPsPrimDeleteTftCnf *)paras;
			checkPSRet(reqHandle, deleteTftCnf->rc);
			break;
		}
		case CI_PS_PRIM_GET_TFT_CNF:
		{
			UINT8 currcid,i,j,k,len,addrType,subnetLen;
			UINT8 *valdata;
			unsigned char* valData;
			char ippBuf[CI_PS_PDP_IP_V6_SIZE] = { '\0' };
			char maskBuf[CI_PS_PDP_IP_V6_SIZE] = { '\0' };

			getTftCnf = (CiPsPrimGetTftCnf *)paras;

			//ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0, (char *)"MyTest1");
			if (getTftCnf->rc == CIRC_PS_SUCCESS)
			{
				currcid = gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid;

				sprintf((char *)AtRspBuf,"+CGTFT:%d,,,\"\",,\"\",,\"\",,,",currcid);

				for (k = 0; k < getTftCnf->numFilters; k++)
				{
					*(char *)AtRspBuf = '\0'; // clear buffer for filters
#ifdef LWIP_IPNETBUF_SUPPORT
					//<cid>
					currcid = getTftCnf->filters[k].cid + 1;
#endif
					sprintf((char *)TempBuf,"+CGTFT:%d,",currcid);
					strcat((char *)AtRspBuf,(char *)TempBuf);

					// <packet filter identifier>, <evaluation precedence index>
					sprintf((char *)TempBuf,"%d,%d,", getTftCnf->filters[k].pfId,
													  getTftCnf->filters[k].epIndex);
					strcat((char *)AtRspBuf,(char *)TempBuf);

					//<source address and subnet mask>
					strcat((char *)AtRspBuf, "\"" );

					addrType = getTftCnf->filters[k].remoteAddrAndMask.addrType;
					if(addrType != CI_PS_PDP_INVALID_ADDR)
					{
						valData = getTftCnf->filters[k].remoteAddrAndMask.valData;
						convertIpUnit2Str(reqHandle, addrType, valData, ippBuf);
						strcat((char *)AtRspBuf,(char *)ippBuf);

						subnetLen = getTftCnf->filters[k].remoteAddrAndMask.subnetLength;
						if(subnetLen > 0)
						{
							getMaskAttachStr(reqHandle, addrType, subnetLen, maskBuf);
							strcat((char *)AtRspBuf, (char *)maskBuf);
						}
					}

					strcat((char *)AtRspBuf, "\",");

					//<protocol number (ipv4) / next header (ipv6)>
					if (!getTftCnf->filters[k].pIdNextHdrPresent)
					{
						sprintf ((char *)TempBuf,",");
					}
					else
					{
						sprintf ((char *)TempBuf,"%d,",getTftCnf->filters[k].pIdNextHdr);
					}
					strcat((char *)AtRspBuf,(char *)TempBuf);
					// Source port range "xxxx.xxxx"
					if (!getTftCnf->filters[k].srcPortRangePresent)
					{
						sprintf ((char *)TempBuf,"\"\",");
					}
					else
					{
						sprintf ((char *)TempBuf,"\"%d.%d\",",getTftCnf->filters[k].srcPortRange.min,
															 getTftCnf->filters[k].srcPortRange.max);
					}
					strcat((char *)AtRspBuf,(char *)TempBuf);

					// Dest port range "xxxx.xxxx"
					if (!getTftCnf->filters[k].dstPortRangePresent)
					{
						sprintf ((char *)TempBuf,"\"\",");
					}
					else
					{
						sprintf ((char *)TempBuf,"\"%d.%d\",",getTftCnf->filters[k].dstPortRange.min,
															 getTftCnf->filters[k].dstPortRange.max);
					}
					strcat((char *)AtRspBuf,(char *)TempBuf);


					//<ipsec security parameter index (spi)>
					if (!getTftCnf->filters[k].ipSecSPIPresent)
					{
						sprintf ((char *)TempBuf," ,");
					}
					else
					{
						sprintf ((char *)TempBuf,"%d,",getTftCnf->filters[k].ipSecSPI);
					}
					strcat((char *)AtRspBuf,(char *)TempBuf);

					// tos
					if (!getTftCnf->filters[k].tosPresent)
					{
						sprintf ((char *)TempBuf,"\"\",");
					}
					else
					{
						sprintf ((char *)TempBuf,"%d.%d,",getTftCnf->filters[k].tosTc,
														 getTftCnf->filters[k].tosTcMask);
					}
					strcat((char *)AtRspBuf,(char *)TempBuf);
					sprintf ((char *)TempBuf,"%d",getTftCnf->filters[k].direction);
					strcat((char *)AtRspBuf,(char *)TempBuf);
					strcat((char *)AtRspBuf, "\r\n");
#ifdef LWIP_IPNETBUF_SUPPORT
					ATRESP( reqHandle,ATCI_RESULT_CODE_NULL, 0, AtRspBuf);
#endif
				}

#ifndef LWIP_IPNETBUF_SUPPORT
				ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0, AtRspBuf);
#else
				updateTftList(reqHandle, paras);
#endif
			}
			else
			{
				checkPSRet(reqHandle,getTftCnf->rc);
			}
			
			#ifndef MIN_SYS
			if (!IsMiniSystem()) 
			{//MiniSystem
						
			#ifdef QUECTEL_NETWORK_SUPPORT
				/* check whether get tft done*/
			
				//Sharon.li@20240429 解决单卡协议栈Volte通话中断的问题,FAE-116063
				#if 0
						//Fitz.xu 20211206: To fix CMCC sim card call ul no voice issue, cause can not get tft of cid9
					#if QUEC_DUAL_SIM_SUPPORT
						if (gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid >= CI_PS_MAX_CID)
					#else
						//if(gAtpCtrl[GET_ATP_INDEX(reqHandle)].psCurrCid >= CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
						if(gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid >= CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
					#endif
				#else
					if (gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid >= CI_PS_MAX_CID)
				#endif
				{	
					/* completed operation */
					CPUartLogPrintf("CI_PS_PRIM_GET_TFT_CNF:completed operation\n");
					ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
					sendTftCtxListToCm(reqHandle);
					exitQueryTftCtx(reqHandle);
					//resetCurrCntx(GET_ATP_INDEX(reqHandle)); 
				}
			#endif
			}//MiniSystem
			#endif /*MIN_SYS*/
			
			break;
		}
#endif
		case CI_PS_PRIM_FAST_DORMANT_CNF:
		{
			getFastDormancyCnf = (CiPsPrimFastDormantCnf *)paras;

		#if QUEC_DUAL_SIM_SUPPORT
			extern QuecOSStatus quec_siolib_transmit_to_atp(TelAtParserID atp_index, uint8 *buf, uint32 len, uint32 * pActualTransLen);
			CPUartLogPrintf("%s,%d, FAST_DORMANT_CNF, rc=%d", __func__, __LINE__, getFastDormancyCnf->rc);
			if (!QUEC_IS_VALID_ATP(GET_ATP_INDEX(reqHandle)))
			{
				if ( getFastDormancyCnf->rc == CIRC_PS_SUCCESS )
					ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, 0);
				else
					checkPSRet(reqHandle, getFastDormancyCnf->rc);
			}
			else
			{
			#ifndef MIN_SYS
				if (!IsMiniSystem()) 
				{//MiniSystem
					//Fitz.xu 20211222: To fix STASR1601-4911
					extern bool quec_qdsrelease_flag_get(void);
					extern void quec_qdsrelease_flag_set(bool flag);
					
					if (quec_qdsrelease_flag_get())
					{
						char rsp_buf[32] = {0};
						char simid = 0;
						char atp_index = 0;

						atp_index = GET_ATP_INDEX(reqHandle);
						if (atp_index < 36)
						{
							simid = 0;
						}
						else
						{
							simid = 1;
						}
						
						if ( getFastDormancyCnf->rc == CIRC_PS_SUCCESS )
						{
							snprintf(rsp_buf, sizeof(rsp_buf), "\r\n+QDSRELEASE: %d,%s\r\n", simid, "success");
						}
						else
						{
							snprintf(rsp_buf, sizeof(rsp_buf), "\r\n+QDSRELEASE: %d,%s\r\n", simid, "fail");
						}
						
						quec_siolib_transmit_to_atp(atp_index, (uint8 *)rsp_buf, strlen(rsp_buf), NULL);

						quec_qdsrelease_flag_set(FALSE);
					}
					else
					{
						if ( getFastDormancyCnf->rc == CIRC_PS_SUCCESS )
							ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, 0);
						else
							checkPSRet(reqHandle, getFastDormancyCnf->rc);	
					}
				}//MiniSystem
			#endif /*MIN_SYS*/
			}
		#else
			if ( getFastDormancyCnf->rc == CIRC_PS_SUCCESS )
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, 0);
			else
				checkPSRet(reqHandle, getFastDormancyCnf->rc);
		#endif
			break;
		}
		case CI_PS_PRIM_AUTHENTICATE_CNF:
		{
		#if defined QUECTEL_PROJECT_CUST
			#ifndef MIN_SYS
			if (!IsMiniSystem()) 
			{
				CiReturnCode temp_ret = CIRC_FAIL;
			
				getAuthenticateCnf = (CiPsPrimAuthenticateCnf *)paras;
				if(getAuthenticateCnf->rc == CIRC_PS_SUCCESS)
				{				
				if ( GET_REQ_ID(reqHandle) == CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ )//Bug #109660 STASR1602-404
				{
					CiPsPrimSetPdpCtxActStateReq *setActStateReq;
		
					atpIdx = GET_ATP_INDEX(reqHandle);

					if(gCIDList.currCntx[atpIdx].currCid >= CI_PS_MAX_CID)
					{
						resetCurrCntx(atpIdx);
						ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						break;
					}

					pdp_table_index = getPdpIndexByCid(gCIDList.currCntx[atpIdx].currCid,p_cInfo);
					CPUartLogPrintf("CI_PS_PRIM_AUTHENTICATE_CNF: pdp_table_index %d, REQ_ID %d", pdp_table_index, GET_REQ_ID(reqHandle));
				
					setActStateReq = (CiPsPrimSetPdpCtxActStateReq *)gCIDList.currCntx[atpIdx].reqMsg;
					if (setActStateReq == NULL)
					{
						resetCurrCntx(atpIdx);
						ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, CME_UNKNOWN, NULL);
					}
					else
					{
						if(pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
						{
							pdp_table_index = getFreePdpIndexFromTable(p_cInfo);
							if (pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
                    		{
                    		    ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, 0);
                    			break;
                    		}
						}
						p_cInfo[pdp_table_index].bDefined = TRUE;
						p_cInfo[pdp_table_index].cid = gCIDList.currCntx[atpIdx].currCid;
						gCIDList.currCntx[atpIdx].reqMsg = NULL;

						/* make request to activate context */
						ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ,
							   reqHandle, (void *)setActStateReq );
					}
				}
				else
				{
					temp_ret = updateAuthParamCmdInPsm(GET_AT_HANDLE(reqHandle), quec_pdpauthinfo.authReq_backup.cid+1, quec_pdpauthinfo.info_text_p_backup, 1);
					
					if(temp_ret == 1)
					{
						if(quec_pdpauthinfo.authReq_backup.cid+1 == qcfg_ltedftcid
							#if QUEC_DUAL_SIM_SUPPORT
							||
							(((getDualSimType()==CM_DUAL_SIM_DUAL_STANDBY_FP)||(getDualSimType()==CM_DUAL_SIM_DUAL_STANDBY))&&
							(quec_pdpauthinfo.authReq_backup.cid+1 == qcfg_ltedftcid_1 ))
							#endif
						)
						{
						#if 0
							if(strstr(mob_sw_rev, "CIVER"))
							{
						#endif
								if(QuecSetDefaultPdpFlag == 0)
								{
									quec_pdpauthinfo.setDefPdpAuthReq_backup.modeType = 0;
									PS_SetDefaultPdpAuthenticate(GET_AT_HANDLE(reqHandle), &quec_pdpauthinfo.setDefPdpAuthReq_backup);
								}
								else
								{
									CPUartLogPrintf("The CI request of the same type has been sent,Reject!");
									ATRESP(reqHandle, ATCI_RESULT_CODE_ERROR, 0, 0);
								}
						#if 0
							}
							else
							{
								quec_pdpauthinfo.setDefPdpAuthReq_backup.modeType = 0;
								PS_SetDefaultPdpAuthenticate(GET_AT_HANDLE(reqHandle), &quec_pdpauthinfo.setDefPdpAuthReq_backup);
							}
						#endif
						}
						else if(quec_pdpauthinfo.authReq_backup.cid+1 != qcfg_ltedftcid
							#if QUEC_DUAL_SIM_SUPPORT
							||
							(((getDualSimType()==CM_DUAL_SIM_DUAL_STANDBY_FP)||(getDualSimType()==CM_DUAL_SIM_DUAL_STANDBY))&&
							(quec_pdpauthinfo.authReq_backup.cid+1 != qcfg_ltedftcid_1 ))
							#endif
						)
						{
							ATRESP(reqHandle, ATCI_RESULT_CODE_OK, 0, 0);
						}
						
					}
					else if(temp_ret == 0)
					{
						if(quec_pdpauthinfo.authReq_backup.cid+1 == qcfg_ltedftcid
							 #if QUEC_DUAL_SIM_SUPPORT
							||
							(((getDualSimType()==CM_DUAL_SIM_DUAL_STANDBY_FP)||(getDualSimType()==CM_DUAL_SIM_DUAL_STANDBY))&&
							(quec_pdpauthinfo.authReq_backup.cid+1 == qcfg_ltedftcid_1 ))
							#endif
						)
						{
						#if 0
							if(strstr(mob_sw_rev, "CIVER"))
							{
						#endif
								if(QuecSetDefaultPdpFlag == 0)
								{
									quec_pdpauthinfo.setDefPdpAuthReq_backup.modeType = 1;
									PS_SetDefaultPdpAuthenticate(GET_AT_HANDLE(reqHandle), &quec_pdpauthinfo.setDefPdpAuthReq_backup);
								}
								else
								{
									CPUartLogPrintf("The CI request of the same type has been sent,Reject!");
									ATRESP(reqHandle, ATCI_RESULT_CODE_ERROR, 0, 0);
								}
						#if 0
							}
							else
							{
								quec_pdpauthinfo.setDefPdpAuthReq_backup.modeType = 1;
								PS_SetDefaultPdpAuthenticate(GET_AT_HANDLE(reqHandle), &quec_pdpauthinfo.setDefPdpAuthReq_backup);
							}
						#endif
						}
						else if(quec_pdpauthinfo.authReq_backup.cid+1 != qcfg_ltedftcid
							#if QUEC_DUAL_SIM_SUPPORT
							||
							(((getDualSimType()==CM_DUAL_SIM_DUAL_STANDBY_FP)||(getDualSimType()==CM_DUAL_SIM_DUAL_STANDBY))&&
							(quec_pdpauthinfo.authReq_backup.cid+1 != qcfg_ltedftcid_1 ))
							#endif
						)
						{
							ATRESP(reqHandle, ATCI_RESULT_CODE_OK, 0, 0);
						}
					}
					else
					{
						ATRESP(reqHandle, ATCI_RESULT_CODE_ERROR, 0, 0);
					}
					
					memset(&quec_pdpauthinfo, 0, sizeof(quec_pdpauthinfo));
				}
				}
				else
				{
					checkPSRet(reqHandle, getAuthenticateCnf->rc);
				}
			}
			#endif
		#else
		{
			getAuthenticateCnf = (CiPsPrimAuthenticateCnf *)paras;
			if(getAuthenticateCnf->rc == CIRC_PS_SUCCESS)
#ifdef QUECTEL_PROJECT_CUST    //Bug #109660 STASR1602-404				
			{
				if ( GET_REQ_ID(reqHandle) == CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ )
				{
					CiPsPrimSetPdpCtxActStateReq *setActStateReq;
		
					atpIdx = GET_ATP_INDEX(reqHandle);

					if(gCIDList.currCntx[atpIdx].currCid >= CI_PS_MAX_CID)
					{
						resetCurrCntx(atpIdx);
						ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						break;
					}

					pdp_table_index = getPdpIndexByCid(gCIDList.currCntx[atpIdx].currCid,p_cInfo);
					CPUartLogPrintf("CI_PS_PRIM_AUTHENTICATE_CNF: pdp_table_index %d, REQ_ID %d", pdp_table_index, GET_REQ_ID(reqHandle));
				
					setActStateReq = (CiPsPrimSetPdpCtxActStateReq *)gCIDList.currCntx[atpIdx].reqMsg;
					if (setActStateReq == NULL)
					{
						resetCurrCntx(atpIdx);
						ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, CME_UNKNOWN, NULL);
					}
					else
					{
						if(pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
						{
							pdp_table_index = getFreePdpIndexFromTable(p_cInfo);
							if (pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
							{
								ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, 0);
								break;
							}
						}
						p_cInfo[pdp_table_index].bDefined = TRUE;
						p_cInfo[pdp_table_index].cid = gCIDList.currCntx[atpIdx].currCid;
						gCIDList.currCntx[atpIdx].reqMsg = NULL;

						/* make request to activate context */
						ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ,
							   reqHandle, (void *)setActStateReq );
					}
				}
				else				
					ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, 0);
			}
#else
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, 0);
#endif
			else
				checkPSRet(reqHandle, getAuthenticateCnf->rc);
		}
		#endif
			break;
		}
#ifndef LTEONLY_THIN		
		case CI_PS_PRIM_SET_FAST_DORMANCY_CONFIG_CNF:
		{
			CiPsPrimSetFastDormancyConfigCnf *setFastDormancyConfigCnf = (CiPsPrimSetFastDormancyConfigCnf *)paras;
			if(setFastDormancyConfigCnf->rc == CIRC_PS_SUCCESS)
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, 0);
			else
				checkPSRet(reqHandle, setFastDormancyConfigCnf->rc);
			break;
		}
#endif	

#ifndef MORE_ATC_SPACE_OPT	
		case CI_PS_PRIM_ENABLE_POWERON_AUTO_ATTACH_CNF:
		{
			CiPsPrimEnablePoweronAutoAttachCnf *enablePoweronAutoAttachCnf = (CiPsPrimEnablePoweronAutoAttachCnf *)paras;
			if(enablePoweronAutoAttachCnf->rc == CIRC_PS_SUCCESS)
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, 0);
			else
				checkPSRet(reqHandle, enablePoweronAutoAttachCnf->rc);
			break;
		}
		case CI_PS_PRIM_SET_PS_PAGING_CONFIG_CNF:
		{
			CiPsPrimSetPsPagingyConfigCnf *setPsPagingyConfigCnf = (CiPsPrimSetPsPagingyConfigCnf *)paras;
			if(setPsPagingyConfigCnf->rc == CIRC_PS_SUCCESS)
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, 0);
			else
				ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
			break;
		}
		case CI_PS_PRIM_GET_POWERON_AUTO_ATTACH_STATUS_CNF:
		{
			CiPsPrimGetPoweronAutoAttachStatusCnf *getPoweronAutoAttachStatusCnf = (CiPsPrimGetPoweronAutoAttachStatusCnf *)paras;
			if(getPoweronAutoAttachStatusCnf->rc == CIRC_PS_SUCCESS)
			{
				sprintf((char *)AtRspBuf, "*CGATT:%d", getPoweronAutoAttachStatusCnf->AutoAttachStatus);
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, AtRspBuf);
			}
			else
			{
				checkPSRet(reqHandle, getPoweronAutoAttachStatusCnf->rc);
			}
			break;
		}
#endif		
		#ifdef CRANE_MCU_DONGLE
		case CI_PS_PRIM_CHAP_AUTHENTICATE_CNF:
		{
			getAuthenticateCnf = (CiPsPrimAuthenticateCnf *)paras;
			if(getAuthenticateCnf->rc == CIRC_PS_SUCCESS)
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, 0);
			else
				ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_UNKNOWN, NULL);
			break;
		}
		#endif
		case CI_PS_PRIM_DEFINE_DEFAULT_PDP_CTX_CNF:
		{
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
		
			defineDefaultPdpCtxCnf = (CiPsPrimDefineDefaultPdpCtxCnf *)paras;
			if(defineDefaultPdpCtxCnf->rc == CIRC_PS_SUCCESS)
			{

#if QUEC_DEFAULT_AUTH_CHECK_SUPPORT
                quec_default_pdn_gki[quec_sim_id].pdp_type=quec_default_pdn_gki_back[quec_sim_id].pdp_type;
                memset(quec_default_pdn_gki[quec_sim_id].apn,0,sizeof(quec_default_pdn_gki[quec_sim_id].apn));
                strncpy(quec_default_pdn_gki[quec_sim_id].apn, quec_default_pdn_gki_back[quec_sim_id].apn, sizeof(quec_default_pdn_gki_back[quec_sim_id].apn));
#endif

#ifdef QUECTEL_NETWORK_SUPPORT
				if(GET_REQ_ID(reqHandle) == CI_PS_PRIM_DEFINE_PDP_CTX_REQ)
				{
					//connor.wu 2019/05/28 fix the bug when we change apn and sync to cgdflt we need to update cgdfltinfo 
					if(quec_pdpCtxInfo.pdpCtxInfo_backup.apnPresent == TRUE)
					{
						updateCgdfltApnInfo(quec_pdpCtxInfo.pdpCtxInfo_backup.apn.valStr, quec_pdpCtxInfo.pdpCtxInfo_backup.type);
					}
					PS_SetGPRSContext(GET_AT_HANDLE(reqHandle), &quec_pdpCtxInfo.pdpCtxInfo_backup);
				}
				else
#endif
				{
					ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
				}
			}
			else
			{
	        #ifdef QUECTEL_NETWORK_SUPPORT
				if(GET_REQ_ID(reqHandle) == CI_PS_PRIM_DEFINE_PDP_CTX_REQ)
				{
					// here CI_PS_PRIM_DEFINE_DEFAULT_PDP_CTX_CNF return fail,if we cannot call PS_SetGPRSContext(), 
					// we need clear quec_pdpCtxInfo.update_flag
					quec_pdpCtxInfo.update_flag = 0;
				}
		    #endif
				checkPSRet(reqHandle, defineDefaultPdpCtxCnf->rc);
			}
}//MiniSystem
else
{
			defineDefaultPdpCtxCnf = (CiPsPrimDefineDefaultPdpCtxCnf *)paras;
			if(defineDefaultPdpCtxCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
			}
			else
			{
				checkPSRet(reqHandle, defineDefaultPdpCtxCnf->rc);
			}

}
#endif /*MIN_SYS*/
			break;
		}
		case CI_PS_PRIM_GET_DEFAULT_PDP_CTX_CNF:
		{
			getDefaultPdpCtxCnf = (CiPsPrimGetDefaultPdpCtxCnf *)paras;
			CiPsPrimGetDefaultPdpCtx getDefaultPdpCtx = getDefaultPdpCtxCnf->pdpCtx;

			if(getDefaultPdpCtxCnf->rc == CIRC_PS_SUCCESS)
			{
#ifndef MIN_SYS
                if (!IsMiniSystem()) 
                {//MiniSystem
#if QUEC_DEFAULT_AUTH_CHECK_SUPPORT
                quec_default_pdn_gki[quec_sim_id].pdp_type=getDefaultPdpCtx.pdpType;
                memset(quec_default_pdn_gki[quec_sim_id].apn,0,sizeof(quec_default_pdn_gki[quec_sim_id].apn));
                strncpy(quec_default_pdn_gki[quec_sim_id].apn, getDefaultPdpCtx.apn.valStr, getDefaultPdpCtx.apn.len);
#endif
                }
#endif
				sprintf ( (char *)AtRspBuf,"*CGDFLT: ");
				getPdpTypeStr(getDefaultPdpCtx.pdpType, TempBuf);
				strcat((char *)AtRspBuf, (char *)TempBuf);
				strcat((char *)AtRspBuf, ",\"");

				memcpy(TempBuf, getDefaultPdpCtx.apn.valStr, getDefaultPdpCtx.apn.len);
				TempBuf[getDefaultPdpCtx.apn.len] = '\0';
#ifdef LWIP_IPNETBUF_SUPPORT
				//updateCgdfltApnInfo(TempBuf, getDefaultPdpCtx.pdpType);
				updateCgdfltApnInfoDS(reqHandle, TempBuf, getDefaultPdpCtx.pdpType);
#endif

				strcat((char *)AtRspBuf, (char *)TempBuf);
				strcat((char *)AtRspBuf, "\",");

				sprintf ( (char *)TempBuf,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
						getDefaultPdpCtx.emgInd, getDefaultPdpCtx.ipcpReq, getDefaultPdpCtx.pcscfIpv6Req,
						getDefaultPdpCtx.imcnSig, getDefaultPdpCtx.dnsIpv6, getDefaultPdpCtx.nwBear,
						getDefaultPdpCtx.dsmIpv6Ha, getDefaultPdpCtx.dsmIpv6Pref, getDefaultPdpCtx.dsmIpv6HaIpv4,
						getDefaultPdpCtx.ipViaNas, getDefaultPdpCtx.ipViaDhcp, getDefaultPdpCtx.pcscfIpv4,
						getDefaultPdpCtx.dnsIpv4, getDefaultPdpCtx.msisdn, getDefaultPdpCtx.ifom,
						getDefaultPdpCtx.v4mtu, getDefaultPdpCtx.localTft, getDefaultPdpCtx.etifFlag);
				strcat((char *)AtRspBuf, (char *)TempBuf);

				ATRESP(reqHandle,ATCI_RESULT_CODE_OK,0,(char *)AtRspBuf);
			}
			else
			{
				checkPSRet(reqHandle, getDefaultPdpCtxCnf->rc);
			}

			break;
		}
		case CI_PS_PRIM_SET_DEFAULT_PDP_AUTHENTICATE_CNF:
		{
			setDefPdpAuthCnf = (CiPsPrimSetDefaultPdpAuthenticateCnf *)paras;
			if(setDefPdpAuthCnf->rc == CIRC_PS_SUCCESS)
			{
#ifndef MIN_SYS
        if (!IsMiniSystem()) 
        {//MiniSystem
#if QUEC_DEFAULT_AUTH_CHECK_SUPPORT
           quec_default_pdn_gki[quec_sim_id].auth_type=quec_default_pdn_gki_back[quec_sim_id].auth_type;
           memset(quec_default_pdn_gki[quec_sim_id].password,0,sizeof(quec_default_pdn_gki[quec_sim_id].password));
           memset(quec_default_pdn_gki[quec_sim_id].user_name,0,sizeof(quec_default_pdn_gki[quec_sim_id].user_name));
           memcpy(&quec_default_pdn_gki[quec_sim_id].password,&quec_default_pdn_gki_back[quec_sim_id].password,sizeof(quec_default_pdn_gki[quec_sim_id].password));
           memcpy(&quec_default_pdn_gki[quec_sim_id].user_name,&quec_default_pdn_gki_back[quec_sim_id].user_name,sizeof(quec_default_pdn_gki[quec_sim_id].user_name));
#if 0
		   if(strstr(mob_sw_rev, "CIVER"))
#endif
		   {
		   		QuecSetDefaultPdpFlag = 0;
		   }
#endif
        }
#endif
                ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
			}
			else
			{
#ifdef QUEC_AT_CIVER_SUPPORT
#if 0
				if(strstr(mob_sw_rev, "CIVER"))
#endif
		  	 	{
		   			QuecSetDefaultPdpFlag = 0;
		   		}
#endif
				checkPSRet(reqHandle, setDefPdpAuthCnf->rc);
			}

			break;
		}
		case CI_PS_PRIM_GET_DEFAULT_PDP_AUTHENTICATE_CNF:
		{
			getDefPdpAuthCnf = (CiPsPrimGetDefaultPdpAuthenticateCnf *)paras;
			if(getDefPdpAuthCnf->rc == CIRC_PS_SUCCESS)
			{
#ifdef AUTH_PAP_CHAP_OPTIMIZE
				if (getDefPdpAuthCnf->authenticationType == CI_PS_AUTHENTICATION_TYPE_PAP_CHAP)
					getDefPdpAuthCnf->authenticationType = CI_PS_AUTHENTICATION_TYPE_PAP;
				else if (getDefPdpAuthCnf->authenticationType == CI_PS_AUTHENTICATION_TYPE_CHAP_PAP)
					getDefPdpAuthCnf->authenticationType = CI_PS_AUTHENTICATION_TYPE_CHAP;
#endif
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
#if QUEC_DEFAULT_AUTH_CHECK_SUPPORT
                            quec_default_pdn_gki[quec_sim_id].auth_type=getDefPdpAuthCnf->authenticationType;
                            memset(quec_default_pdn_gki[quec_sim_id].password,0,sizeof(quec_default_pdn_gki[quec_sim_id].password));
                            strncpy(quec_default_pdn_gki[quec_sim_id].password, getDefPdpAuthCnf->password.valStr, getDefPdpAuthCnf->password.len);
                            memset(quec_default_pdn_gki[quec_sim_id].user_name,0,sizeof(quec_default_pdn_gki[quec_sim_id].user_name));
                            strncpy(quec_default_pdn_gki[quec_sim_id].user_name, getDefPdpAuthCnf->userName.valStr, getDefPdpAuthCnf->userName.len);
#endif
}
#endif
				sprintf ( (char *)AtRspBuf,"*CGDFAUTH:%d,\"", getDefPdpAuthCnf->authenticationType);

				memcpy(TempBuf, getDefPdpAuthCnf->userName.valStr, getDefPdpAuthCnf->userName.len);
				TempBuf[getDefPdpAuthCnf->userName.len] = '\0';

				strcat((char *)AtRspBuf, (char *)TempBuf);
				strcat((char *)AtRspBuf, "\",\"");

				memcpy(TempBuf, getDefPdpAuthCnf->password.valStr, getDefPdpAuthCnf->password.len);
				TempBuf[getDefPdpAuthCnf->password.len] = '\0';

				strcat((char *)AtRspBuf, (char *)TempBuf);
				strcat((char *)AtRspBuf, "\"");

				ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,AtRspBuf);
			}
			else
			{
				checkPSRet(reqHandle, getDefPdpAuthCnf->rc);
			}

			break;
		}
#ifndef MORE_ATC_SPACE_OPT //LTEONLY_THIN as below	
		/* Added by Daniel for LTE PC AT command server 20120201, begin */
		case CI_PS_PRIM_SET_APN_CNF:
		{
			setApnCnf = (CiPsPrimSetApnCnf *)paras;
			if(setApnCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
			}
			else
			{
				checkPSRet(reqHandle, setApnCnf->rc);
			}

			break;
		}
#endif
#ifndef LTEONLY_THIN
		case CI_PS_PRIM_GET_APN_CNF:
		{
			getApnCnf = (CiPsPrimGetApnCnf *)paras;

			if(getApnCnf->rc == CIRC_PS_SUCCESS)
			{
				int i;
				sprintf ( (char *)AtRspBuf, "+VZWAPNE:");
				for(i = 0; i < getApnCnf->num; i++)
				{
					if(i != 0)
						strcat((char *)AtRspBuf, ",");

					sprintf ( (char *)TempBuf,"%d,\"",getApnCnf ->apnInfo[i].apncl);
					strcat((char *)AtRspBuf, (char *)TempBuf);
					memcpy( TempBuf, getApnCnf ->apnInfo[i].apnni.valStr, getApnCnf ->apnInfo[i].apnni.len );
					TempBuf[getApnCnf ->apnInfo[i].apnni.len] = '\0';
					strcat((char *)AtRspBuf, (char *)TempBuf);
					strcat((char *)AtRspBuf, "\",");

					getApnTypeStr((CiPsApnAddrType)(getApnCnf ->apnInfo[i].apnType), TempBuf);
					strcat((char *)AtRspBuf, (char *)TempBuf);
					strcat((char *)AtRspBuf, ",\"");

					if(getApnCnf->apnInfo[i].apnBear == CI_PS_APN_BEAR_LTE_TYPE)
					{
						sprintf ( (char *)TempBuf, "LTE");
						strcat((char *)AtRspBuf, (char *)TempBuf);
					}
					strcat((char *)AtRspBuf, "\",\"");

					if(getApnCnf->apnInfo[i].apned)
						sprintf ( (char *)TempBuf, "Enabled");
					else
						sprintf ( (char *)TempBuf, "Disabled");
					strcat((char *)AtRspBuf, (char *)TempBuf);
					strcat((char *)AtRspBuf, "\",");

					sprintf ( (char *)TempBuf,"%d", getApnCnf ->apnInfo[i].apnTime);
					strcat((char *)AtRspBuf, (char *)TempBuf);
				}
				ATRESP(reqHandle,ATCI_RESULT_CODE_OK,0,(char *)AtRspBuf);
			}
			else
			{
				checkPSRet(reqHandle, getApnCnf->rc);
			}

			break;
		}
#endif
		case CI_PS_PRIM_GET_4G_QOS_CNF:
		{
			get4GQoSCnf = (CiPsPrimGet4GQosCnf *)paras;
			if(get4GQoSCnf->rc == CIRC_PS_SUCCESS)
	        {
	            switch (GET_REQ_ID(reqHandle))
	            {
	                case CI_PS_PRIM_GET_4G_QOS_REQ:
	                {
	                    if (get4GQoSCnf->qosProfPresent)
	                    {
	                        sprintf ( (char *)AtRspBuf,"+CGEQOS: %d,%d,%d,%d,%d,%d",
	                            get4GQoSCnf->cid+1,
	                            get4GQoSCnf->qosProfile.qci,
							    get4GQoSCnf->qosProfile.guaranteedDLRate,
							    get4GQoSCnf->qosProfile.guaranteedULRate,
							    get4GQoSCnf->qosProfile.maxDLRate,
							    get4GQoSCnf->qosProfile.maxULRate);
	                        ATRESP( reqHandle, 0,0,(char *)AtRspBuf);
	                    }
	                    if(gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid < CI_PS_MAX_CID- 1)
	                    {
	                        gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid += 1;
	                        PS_Get4GQualityOfServiceList((UINT32)(reqHandle),(UINT32)(gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid));
	                    }
	                    else
	                    {
	                        ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
	                    }
	                    break;
	                }
	                default:
	                    ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
	                    goto end;
	            }
	        }
				else
			{
				checkPSRet(reqHandle, get4GQoSCnf->rc);
			}
			break;
		}

		case CI_PS_PRIM_GET_4G_QOS_CAPS_CNF:
		{
			get4GQosCapsCnf = (CiPsPrimGet4GQosCapsCnf *)paras;
			if(get4GQosCapsCnf->rc == CIRC_PS_SUCCESS)
			{
				switch (GET_REQ_ID(reqHandle))
	            {
	                case CI_PS_PRIM_GET_4G_QOS_CAPS_REQ:
	                {
	                    if (get4GQosCapsCnf->qosCapsPresent)
	                    {
	                        CiPs4GQosCap *pCtxCaps = get4GQosCapsCnf->qosCaps.caps;
	                        for ( i = 0; i < get4GQosCapsCnf->qosCaps.size; i++ )
	                        {
	                            sprintf ( (char *)AtRspBuf,"+CGEQOS: (1-15),(0-9,128-254),(%d-%d),(%d-%d),(%d-%d),(%d-%d)",
								    pCtxCaps->guaranteedDLRate.min,
								    pCtxCaps->guaranteedDLRate.max,
								    pCtxCaps->guaranteedULRate.min,
								    pCtxCaps->guaranteedULRate.max,
								    pCtxCaps->maxDLRate.min,
								    pCtxCaps->maxDLRate.max,
								    pCtxCaps->maxULRate.min,
								    pCtxCaps->maxULRate.max);
	                            ATRESP( reqHandle, 0,0,(char *)AtRspBuf);
	                            pCtxCaps++;
	                        }
	                    }
	                    ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
	                    break;
	                }
	                case CI_PS_PRIM_SET_4G_MODE_REQ:
	                {
	                    break;
	                }
	                case CI_PS_PRIM_GET_4G_MODE_CAPS_REQ:
	                {
	                    break;
	                }
	                default:
	                    ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
	                    goto end;
	            }
	        }
	        else
	        {
				checkPSRet(reqHandle, get4GQosCapsCnf->rc);
	        }
        	break;
    	}

		case CI_PS_PRIM_SET_4G_QOS_CNF:
		{
			set4GQosCnf = (CiPsPrimSet4GQosCnf *)paras;
			if(set4GQosCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
			}
			else
			{
				checkPSRet(reqHandle, set4GQosCnf->rc);
			}
			break;
		}

    	case CI_PS_PRIM_READ_4G_PDP_CTX_DYN_PARA_CNF:
	    {
	        UINT32    j;
			UINT8 currCid;
			UINT32 len;
			read4GPdpCtxDynParaCnf = (CiPsPrimRead4GPdpCtxDynParaCnf *)paras;

			currCid = gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid;
			if(currCid >= CI_PS_MAX_CID)
			{
				resetCurrCntx(GET_ATP_INDEX(reqHandle));
				ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				break;
			}

			if((read4GPdpCtxDynParaCnf->rc == CIRC_PS_SUCCESS) && (read4GPdpCtxDynParaCnf->ctxPresent))
			{
				int addrType, subnetLen;
				unsigned char* valData;
				char preBuf[20 + CI_MAX_CI_STRING_LENGTH] = { '\0' };
				char ipp4Buf[CI_PS_PDP_IP_V4_SIZE] = { '\0' };
				char mask4Buf[CI_PS_PDP_IP_V4_SIZE] = { '\0' };
				char ipp6Buf[CI_PS_PDP_IP_V6_SIZE] = { '\0' };
				char mask6Buf[CI_PS_PDP_IP_V6_SIZE] = { '\0' };
				char gwBuf[CI_PS_PDP_MAX_NW_ADDR_NUM][CI_PS_PDP_IP_V6_SIZE] = { { '\0' }, { '\0' }, { '\0' } , { '\0' } };
				char dnsBuf[CI_PS_PDP_MAX_NW_ADDR_NUM][CI_PS_PDP_IP_V6_SIZE] = { { '\0' }, { '\0' }, { '\0' } , { '\0' } };
				char cscfBuf[CI_PS_PDP_MAX_NW_ADDR_NUM][CI_PS_PDP_IP_V6_SIZE] = { { '\0' }, { '\0' }, { '\0' } , { '\0' } };
				switch (GET_REQ_ID(reqHandle))
				{
					case CI_PS_PRIM_READ_4G_PDP_CTX_DYN_PARA_REQ:
					{
#ifdef LWIP_IPNETBUF_SUPPORT
						telPsPdpCtx *psPdpInfo = NULL;
						psPdpInfo = telGetPdpCtx(read4GPdpCtxDynParaCnf->ctxDynPara.cid);
#endif
						sprintf ( (char *)preBuf,"+CGCONTRDP: " );
						sprintf ( (char *)TempBuf,"%d,",read4GPdpCtxDynParaCnf->ctxDynPara.cid+1);
						strcat((char *)preBuf,(char *)TempBuf);
						if(read4GPdpCtxDynParaCnf->ctxDynPara.bidPresent == TRUE)
						{
							sprintf ( (char *)TempBuf,"%d,",read4GPdpCtxDynParaCnf->ctxDynPara.bid);
							strcat((char *)preBuf,(char *)TempBuf);
						}
						else
						{
							strcat((char *)preBuf,",");
						}

						strcat((char *)preBuf,"\"");
						if(read4GPdpCtxDynParaCnf->ctxDynPara.apnPresent == TRUE)
						{
#ifdef LWIP_IPNETBUF_SUPPORT
							if (psPdpInfo && psPdpInfo->reDefined && telGetPdpActivedFlag(read4GPdpCtxDynParaCnf->ctxDynPara.cid) && isHandleForMasterSim(reqHandle))
							{
								if (strlen(psPdpInfo->apnInfo.apn) > 0)
									strcpy(TempBuf, psPdpInfo->apnInfo.apn);
								else
									TempBuf[0] = '\0';

								strcat((char *)preBuf,(char *)TempBuf);
							}
							else
#endif
							{
								if(read4GPdpCtxDynParaCnf->ctxDynPara.apn.len > 0)
								{
									memcpy(TempBuf, read4GPdpCtxDynParaCnf->ctxDynPara.apn.valStr, read4GPdpCtxDynParaCnf->ctxDynPara.apn.len);
									TempBuf[read4GPdpCtxDynParaCnf->ctxDynPara.apn.len] = '\0';
									strcat((char *)preBuf,(char *)TempBuf);
								}
							}
						}
						strcat((char *)preBuf,"\",");

						addrType = read4GPdpCtxDynParaCnf->ctxDynPara.ipv4Addr.addrType;
						if(addrType == CI_PS_PDP_IPV4)
						{
							valData = read4GPdpCtxDynParaCnf->ctxDynPara.ipv4Addr.valData;
							convertIpUnit2Str(reqHandle, addrType, valData, ipp4Buf);
						}

						addrType = read4GPdpCtxDynParaCnf->ctxDynPara.ipv6Addr.addrType;
						if((addrType == CI_PS_PDP_FULL_IPV6) || (addrType == CI_PS_PDP_IPV6_INTERFACE))
						{
							valData = read4GPdpCtxDynParaCnf->ctxDynPara.ipv6Addr.valData;
							convertIpUnit2Str(reqHandle, addrType, valData, ipp6Buf);
						}

						for(i = 0; i < CI_PS_PDP_MAX_NW_ADDR_NUM; i++)
						{
							addrType = read4GPdpCtxDynParaCnf->ctxDynPara.gwAddr[i].addrType;
							if(addrType != CI_PS_PDP_INVALID_ADDR)
							{
								valData = read4GPdpCtxDynParaCnf->ctxDynPara.gwAddr[i].valData;
								convertIpUnit2Str(reqHandle, addrType, valData, gwBuf[i]);
							}
						}

						CiBoolean dualstack = (read4GPdpCtxDynParaCnf->ctxDynPara.ipv4Addr.addrType == CI_PS_PDP_IPV4) &&
							((read4GPdpCtxDynParaCnf->ctxDynPara.ipv6Addr.addrType == CI_PS_PDP_FULL_IPV6) ||
							 (read4GPdpCtxDynParaCnf->ctxDynPara.ipv6Addr.addrType == CI_PS_PDP_IPV6_INTERFACE));

						int tmpAddrType = CI_PS_PDP_INVALID_ADDR;
						if (!dualstack)
						{
							if(read4GPdpCtxDynParaCnf->ctxDynPara.ipv4Addr.addrType == CI_PS_PDP_IPV4)
							{
								tmpAddrType = read4GPdpCtxDynParaCnf->ctxDynPara.ipv4Addr.addrType;
							}
							else if((read4GPdpCtxDynParaCnf->ctxDynPara.ipv6Addr.addrType == CI_PS_PDP_FULL_IPV6) ||
									(read4GPdpCtxDynParaCnf->ctxDynPara.ipv6Addr.addrType == CI_PS_PDP_IPV6_INTERFACE))
							{
								tmpAddrType = read4GPdpCtxDynParaCnf->ctxDynPara.ipv6Addr.addrType;
							}
						}

						int validDnsNumber = 0;
						for(i = 0; i < CI_PS_PDP_MAX_NW_ADDR_NUM; i++)
						{
							addrType = read4GPdpCtxDynParaCnf->ctxDynPara.dnsAddr[i].addrType;
							if(addrType != CI_PS_PDP_INVALID_ADDR)
							{
								if (!dualstack && tmpAddrType != CI_PS_PDP_INVALID_ADDR)
								{
									if ((tmpAddrType == CI_PS_PDP_IPV4 && addrType != tmpAddrType)
										|| (tmpAddrType != CI_PS_PDP_IPV4 && addrType == CI_PS_PDP_IPV4))
										continue;
								}
								valData = read4GPdpCtxDynParaCnf->ctxDynPara.dnsAddr[i].valData;
								convertIpUnit2Str(reqHandle, addrType, valData, dnsBuf[validDnsNumber++]);
							}
						}

						int validPcscfNumber = 0;
						for(i = 0; i < CI_PS_PDP_MAX_NW_ADDR_NUM; i++)
						{
							addrType = read4GPdpCtxDynParaCnf->ctxDynPara.pCscfAddr[i].addrType;
							if(addrType != CI_PS_PDP_INVALID_ADDR)
							{
								if (!dualstack && tmpAddrType != CI_PS_PDP_INVALID_ADDR)
								{
									if ((tmpAddrType == CI_PS_PDP_IPV4 && addrType != tmpAddrType)
										|| (tmpAddrType != CI_PS_PDP_IPV4 && addrType == CI_PS_PDP_IPV4))
										continue;
								}
								valData = read4GPdpCtxDynParaCnf->ctxDynPara.pCscfAddr[i].valData;
								convertIpUnit2Str(reqHandle, addrType, valData, cscfBuf[validPcscfNumber++]);
							}
						}

						int linenum = 1;
						if((read4GPdpCtxDynParaCnf->ctxDynPara.gwAddrNum > 1) ||
								(validDnsNumber > 2 ) ||(validPcscfNumber > 2))
										linenum = 2;
						if(!dualstack)
						{
							for(i = 0; i/2 < linenum; i = i + 2)
							{
								/*[Fixed][coverity]*/
								memset((char *)AtRspBuf,0,1000*sizeof(char));

								strcat((char *)AtRspBuf,(char *)preBuf);
								strcat((char *)AtRspBuf,"\"");
								if(read4GPdpCtxDynParaCnf->ctxDynPara.ipv4Addr.addrType == CI_PS_PDP_IPV4)
								{
									strcat((char *)AtRspBuf,(char *)ipp4Buf);
									addrType = read4GPdpCtxDynParaCnf->ctxDynPara.ipv4Addr.addrType;
									subnetLen = read4GPdpCtxDynParaCnf->ctxDynPara.ipv4Addr.subnetLength;
									if(subnetLen != 0)
									{
										getMaskAttachStr(reqHandle, addrType, subnetLen, mask4Buf);
										strcat((char *)AtRspBuf,(char *)mask4Buf);
									}
								}
								else if((read4GPdpCtxDynParaCnf->ctxDynPara.ipv6Addr.addrType == CI_PS_PDP_FULL_IPV6) ||
										(read4GPdpCtxDynParaCnf->ctxDynPara.ipv6Addr.addrType == CI_PS_PDP_IPV6_INTERFACE))
								{
									strcat((char *)AtRspBuf,(char *)ipp6Buf);
									addrType = read4GPdpCtxDynParaCnf->ctxDynPara.ipv6Addr.addrType;
									subnetLen = read4GPdpCtxDynParaCnf->ctxDynPara.ipv6Addr.subnetLength;
									if(subnetLen != 0)
									{
										getMaskAttachStr(reqHandle, addrType, subnetLen, mask6Buf);
										strcat((char *)AtRspBuf,(char *)mask6Buf);
									}
								}

								strcat((char *)AtRspBuf,"\",\"");
								if(read4GPdpCtxDynParaCnf->ctxDynPara.gwAddr[i].addrType != CI_PS_PDP_INVALID_ADDR)
									strcat((char *)AtRspBuf,(char *)gwBuf[i/2]);
								strcat((char *)AtRspBuf,"\",\"");
								if(read4GPdpCtxDynParaCnf->ctxDynPara.dnsAddr[i].addrType != CI_PS_PDP_INVALID_ADDR)
									strcat((char *)AtRspBuf,(char *)dnsBuf[i]);
								strcat((char *)AtRspBuf,"\",\"");
								if(read4GPdpCtxDynParaCnf->ctxDynPara.dnsAddr[i+1].addrType != CI_PS_PDP_INVALID_ADDR)
									strcat((char *)AtRspBuf,(char *)dnsBuf[i+1]);
								strcat((char *)AtRspBuf,"\",\"");
								if(read4GPdpCtxDynParaCnf->ctxDynPara.pCscfAddr[i].addrType != CI_PS_PDP_INVALID_ADDR)
									strcat((char *)AtRspBuf,(char *)cscfBuf[i]);
								strcat((char *)AtRspBuf,"\",\"");
								if(read4GPdpCtxDynParaCnf->ctxDynPara.pCscfAddr[i+1].addrType != CI_PS_PDP_INVALID_ADDR)
									strcat((char *)AtRspBuf,(char *)cscfBuf[i+1]);
								strcat((char *)AtRspBuf,"\",");
								sprintf ( (char *)TempBuf,"%d",read4GPdpCtxDynParaCnf->ctxDynPara.imCnSigFlag);
								strcat((char *)AtRspBuf,(char *)TempBuf);
								strcat((char *)AtRspBuf,",");
								sprintf ( (char *)TempBuf,"%d",read4GPdpCtxDynParaCnf->ctxDynPara.lipaInd);
								strcat((char *)AtRspBuf,(char *)TempBuf);

								ATRESP( reqHandle,0,0,(char *)AtRspBuf);
							}
						}
						else
						{
							int count = 0;
							//for ipv4 stack:
							/*[Fixed][coverity]*/
							memset((char *)AtRspBuf,0,1000*sizeof(char));

							strcat((char *)AtRspBuf,(char *)preBuf);
							strcat((char *)AtRspBuf,"\"");
							strcat((char *)AtRspBuf,(char *)ipp4Buf);
							addrType = read4GPdpCtxDynParaCnf->ctxDynPara.ipv4Addr.addrType;
							subnetLen = read4GPdpCtxDynParaCnf->ctxDynPara.ipv4Addr.subnetLength;
							if(subnetLen != 0)
							{
								getMaskAttachStr(reqHandle, addrType, subnetLen, mask4Buf);
								strcat((char *)AtRspBuf,(char *)mask4Buf);
							}

							strcat((char *)AtRspBuf,"\",\"");
							for(i = 0; i < CI_PS_PDP_MAX_NW_ADDR_NUM; i++)
							{
								if(read4GPdpCtxDynParaCnf->ctxDynPara.gwAddr[i].addrType == CI_PS_PDP_IPV4)
								{
									strcat((char *)AtRspBuf,(char *)gwBuf[i]);
									break;
								}
							}
							strcat((char *)AtRspBuf,"\",\"");

							for(i = 0; i < CI_PS_PDP_MAX_NW_ADDR_NUM; i++)
							{
								if(read4GPdpCtxDynParaCnf->ctxDynPara.dnsAddr[i].addrType == CI_PS_PDP_IPV4)
								{
									strcat((char *)AtRspBuf,(char *)dnsBuf[i]);
									strcat((char *)AtRspBuf,"\",\"");
									count++;
									if(count == 2)
										break;
								}
							}
							if(count == 0)
								strcat((char *)AtRspBuf,"\",\"\",\"");
							else if(count == 1)
								strcat((char *)AtRspBuf,"\",\"");

							count = 0;
							for(i = 0; i < CI_PS_PDP_MAX_NW_ADDR_NUM; i++)
							{
								if(read4GPdpCtxDynParaCnf->ctxDynPara.pCscfAddr[i].addrType == CI_PS_PDP_IPV4)
								{
									strcat((char *)AtRspBuf,(char *)cscfBuf[i]);
									strcat((char *)AtRspBuf,"\",");
									count++;
									if(count == 1)
										strcat((char *)AtRspBuf,"\"");
									else if(count == 2)
										break;
								}
							}
							if(count == 0)
								strcat((char *)AtRspBuf,"\",\"\",");
							else if(count == 1)
								strcat((char *)AtRspBuf,"\",");

							sprintf ( (char *)TempBuf,"%d",read4GPdpCtxDynParaCnf->ctxDynPara.imCnSigFlag);
							strcat((char *)AtRspBuf,(char *)TempBuf);
							strcat((char *)AtRspBuf,",");
							sprintf ( (char *)TempBuf,"%d",read4GPdpCtxDynParaCnf->ctxDynPara.lipaInd);
							strcat((char *)AtRspBuf,(char *)TempBuf);
							ATRESP( reqHandle,0,0,(char *)AtRspBuf);

							//for ipv6 stack:
							/*[Fixed][coverity]*/
							memset((char *)AtRspBuf,0,1000*sizeof(char));

							strcat((char *)AtRspBuf,(char *)preBuf);
							strcat((char *)AtRspBuf,"\"");
							strcat((char *)AtRspBuf,(char *)ipp6Buf);
							addrType = read4GPdpCtxDynParaCnf->ctxDynPara.ipv6Addr.addrType;
							subnetLen = read4GPdpCtxDynParaCnf->ctxDynPara.ipv6Addr.subnetLength;
							if(subnetLen != 0)
							{
								getMaskAttachStr(reqHandle, addrType, subnetLen, mask6Buf);
								strcat((char *)AtRspBuf,(char *)mask6Buf);
							}

							strcat((char *)AtRspBuf, "\",\"");
							for(i = 0; i < CI_PS_PDP_MAX_NW_ADDR_NUM; i++)
							{
								if((read4GPdpCtxDynParaCnf->ctxDynPara.gwAddr[i].addrType == CI_PS_PDP_FULL_IPV6) ||
										(read4GPdpCtxDynParaCnf->ctxDynPara.gwAddr[i].addrType == CI_PS_PDP_IPV6_INTERFACE))
								{
									strcat((char *)AtRspBuf,(char *)gwBuf[i]);
									break;
								}
							}
							strcat((char *)AtRspBuf, "\",\"");

							count = 0;
							for(i = 0; i < CI_PS_PDP_MAX_NW_ADDR_NUM; i++)
							{
								if((read4GPdpCtxDynParaCnf->ctxDynPara.dnsAddr[i].addrType == CI_PS_PDP_FULL_IPV6) ||
										(read4GPdpCtxDynParaCnf->ctxDynPara.dnsAddr[i].addrType == CI_PS_PDP_IPV6_INTERFACE))
								{
									strcat((char *)AtRspBuf, (char *)dnsBuf[i]);
									strcat((char *)AtRspBuf, "\",\"");
									count++;
									if(count == 2)
										break;

								}
							}
							if(count == 0)
								strcat((char *)AtRspBuf, "\",\"\",\"");
							else if(count == 1)
								strcat((char *)AtRspBuf, "\",\"");

							count = 0;
							for(i = 0; i < CI_PS_PDP_MAX_NW_ADDR_NUM; i++)
							{
								if((read4GPdpCtxDynParaCnf->ctxDynPara.pCscfAddr[i].addrType == CI_PS_PDP_FULL_IPV6) ||
										(read4GPdpCtxDynParaCnf->ctxDynPara.pCscfAddr[i].addrType == CI_PS_PDP_IPV6_INTERFACE))
								{
									strcat((char *)AtRspBuf, (char *)cscfBuf[i]);
									strcat((char *)AtRspBuf, "\",");
									count++;
									if(count == 1)
										strcat((char *)AtRspBuf, "\"");
									else if(count == 2)
										break;
								}
							}
							if(count == 0)
								strcat((char *)AtRspBuf, "\",\"\",");
							else if(count == 1)
								strcat((char *)AtRspBuf, "\",");

							sprintf ( (char *)TempBuf, "%d", read4GPdpCtxDynParaCnf->ctxDynPara.imCnSigFlag);
							strcat((char *)AtRspBuf, (char *)TempBuf);
							strcat((char *)AtRspBuf, ",");
							sprintf ( (char *)TempBuf, "%d", read4GPdpCtxDynParaCnf->ctxDynPara.lipaInd);
							strcat((char *)AtRspBuf, (char *)TempBuf);
							ATRESP( reqHandle, 0, 0, (char *)AtRspBuf);
						}
						break;
					}
					default:
						ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
						goto end;
				}
			}
			if (*pQueryAllCid == TRUE)
			{
				currCid++;
				if ( currCid < CI_PS_MAX_CID)
				{
					read4GPdpCtxDynParaReq= utlCalloc(1, sizeof(*read4GPdpCtxDynParaReq));
					if (read4GPdpCtxDynParaReq == NULL) {
						ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
						break;
					}

					read4GPdpCtxDynParaReq->cid = currCid;
					gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid = currCid;
					
					#ifndef MIN_SYS
					if (!IsMiniSystem()) 
					{//MiniSystem
							
						#ifdef QUECTEL_NETWORK_SUPPORT
							ret = ciRequestExt( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_READ_4G_PDP_CTX_DYN_PARA_REQ,
									reqHandle, (void *)read4GPdpCtxDynParaReq );
						#else
							ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_READ_4G_PDP_CTX_DYN_PARA_REQ,
									reqHandle, (void *)read4GPdpCtxDynParaReq );
						#endif
					}//MiniSystem
					else
					{
						ret = ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_READ_4G_PDP_CTX_DYN_PARA_REQ,
								reqHandle, (void *)read4GPdpCtxDynParaReq );
					}
					#endif /*MIN_SYS*/
				}
				else
				{
					ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
				}
			}
			else
			{
				checkPSRet(reqHandle, read4GPdpCtxDynParaCnf->rc);
			}
			break;
		}

		case CI_PS_PRIM_READ_4G_PDP_CTXS_ACT_DYN_PARA_CNF:
		{
			read4GPdpCtxsActDynParaCnf = (CiPsPrimRead4GPdpCtxsActDynParaCnf *)paras;
			if(read4GPdpCtxsActDynParaCnf->rc == CIRC_PS_SUCCESS)
			{
				switch (GET_REQ_ID(reqHandle))
		        {
		            case CI_PS_PRIM_READ_4G_PDP_CTXS_ACT_DYN_PARA_REQ:
		            {
		                if(read4GPdpCtxsActDynParaCnf->num > 0)
		                {
		                    sprintf((char *)AtRspBuf,"+CGCONTRDP: ");
		                    for(i = 0;i < read4GPdpCtxsActDynParaCnf->num;i ++)
		                    {
		                        if(i < read4GPdpCtxsActDynParaCnf->num - 1)
		                        {
		                            sprintf((char *)TempBuf,"%d,",read4GPdpCtxsActDynParaCnf->cid[i]+1);
		                        }
		                        else
		                        {
		                            sprintf((char *)TempBuf,"%d",read4GPdpCtxsActDynParaCnf->cid[i]+1);
		                        }
		                        strcat((char *)AtRspBuf,(char *)TempBuf);
		                    }
		                    ATRESP( reqHandle, 0,0,(char *)AtRspBuf);
		                }
		                ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
		                break;
		            }
		            default:
		                ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
		                goto end;
		        }
		    }
		    else
		    {
				checkPSRet(reqHandle, read4GPdpCtxsActDynParaCnf->rc);
		    }
		    break;
		}

		case CI_PS_PRIM_READ_4G_SEC_PDP_CTX_DYN_PARA_CNF:
		{
			read4GSecPdpCtxDynParaCnf = (CiPsPrimRead4GSecPdpCtxDynParaCnf *)paras;
			if(read4GSecPdpCtxDynParaCnf->rc == CIRC_PS_SUCCESS)
			{
				switch (GET_REQ_ID(reqHandle))
				{
            		case CI_PS_PRIM_READ_4G_SEC_PDP_CTX_DYN_PARA_REQ:
		            {
		                if(gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid == 0xFF)
		                {
		                    for(i = 0;i < read4GSecPdpCtxDynParaCnf->num;i ++)
		                    {
								sprintf((char *)AtRspBuf,"+CGSCONTRDP: %d,%d,%d,%d",
									read4GSecPdpCtxDynParaCnf->psId[i].cid+1,
									read4GSecPdpCtxDynParaCnf->psId[i].p_cid+1,
									read4GSecPdpCtxDynParaCnf->psId[i].bearer_id,
									read4GSecPdpCtxDynParaCnf->imCnSigFlag[i]);
								ATRESP(reqHandle,0,0,(char *)AtRspBuf);
							}
						}
						else
						{
							if(read4GSecPdpCtxDynParaCnf->num == 1)
							{
								sprintf((char *)AtRspBuf,"+CGSCONTRDP: %d,%d,%d,%d",
									read4GSecPdpCtxDynParaCnf->psId[0].cid+1,
									read4GSecPdpCtxDynParaCnf->psId[0].p_cid+1,
									read4GSecPdpCtxDynParaCnf->psId[0].bearer_id,
									read4GSecPdpCtxDynParaCnf->imCnSigFlag[0]);
			                        ATRESP(reqHandle,0,0,(char *)AtRspBuf);
			                    }
			                }
		                ATRESP(reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
		                break;
		            }
		            default:
		                ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
		                goto end;
		        }
		    }
		    else
		    {
				checkPSRet(reqHandle, read4GSecPdpCtxDynParaCnf->rc);
			}

			break;
		}

		case CI_PS_PRIM_READ_4G_SEC_PDP_CTXS_ACT_DYN_PARA_CNF:
		{
			read4GSecPdpCtxsActDynParaCnf = (CiPsPrimRead4GSecPdpCtxsActDynParaCnf *)paras;
			if(read4GSecPdpCtxsActDynParaCnf->rc == CIRC_PS_SUCCESS)
			{
        		switch (GET_REQ_ID(reqHandle))
		        {
		            case CI_PS_PRIM_READ_4G_SEC_PDP_CTXS_ACT_DYN_PARA_REQ:
		            {
		                if(read4GSecPdpCtxsActDynParaCnf->num > 0)
		                {
		                    sprintf((char *)AtRspBuf,"+CGSCONTRDP: ");
		                    for(i = 0;i < read4GSecPdpCtxsActDynParaCnf->num;i ++)
		                    {
		                        if(i < read4GSecPdpCtxsActDynParaCnf->num - 1)
		                        {
		                            sprintf((char *)TempBuf,"%d,",read4GSecPdpCtxsActDynParaCnf->cid[i]+1);
		                        }
		                        else
		                        {
		                            sprintf((char *)TempBuf,"%d",read4GSecPdpCtxsActDynParaCnf->cid[i]+1);
		                        }
		                        strcat((char *)AtRspBuf,(char *)TempBuf);
		                    }
		                    ATRESP( reqHandle, 0,0,(char *)AtRspBuf);
		                }
		                ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
		                break;
		            }
		            default:
		                ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
		                goto end;
		        }
		    }
		    else
		    {
				checkPSRet(reqHandle, read4GSecPdpCtxsActDynParaCnf->rc);
		    }
		    break;
		}
    	case CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_CNF:
	    {
	        UINT32    j = 0;
	        UINT32    k = 0;
	        read4GTFTDynParaCnf = (CiPsPrimRead4GTrafficFlowTempDynParaCnf *)paras;
	        if(read4GTFTDynParaCnf->rc == CIRC_PS_SUCCESS)
	        {
	            switch (GET_REQ_ID(reqHandle))
	            {
	                case CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_REQ:
	                {
	                    if(1 /*gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid == 0xFF*/)
	                    {
	                        for(j = 0; j < read4GTFTDynParaCnf->numFilters; j ++)
	                        {
								if((gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid != 0xFF) && (
									gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid !=read4GTFTDynParaCnf->filters[j].cid ))
									continue ;
								sprintf ( (char *)AtRspBuf,"+CGTFTRDP: " );

								sprintf((char *)TempBuf,"%d,",read4GTFTDynParaCnf->filters[j].cid+1);
								strcat((char *)AtRspBuf,(char *)TempBuf);

								sprintf ( (char *)TempBuf,"%d,",read4GTFTDynParaCnf->filters[j].pfId+1);
								strcat((char *)AtRspBuf,(char *)TempBuf);

								sprintf ( (char *)TempBuf,"%d,",read4GTFTDynParaCnf->filters[j].epIndex);
								strcat((char *)AtRspBuf,(char *)TempBuf);

								strcat((char *)AtRspBuf,"\"");
								//mask mengliang
								if(read4GTFTDynParaCnf->filters[j].remoteAddrAndMask.addrType!=CI_PS_PDP_INVALID_ADDR)
								{
									if(read4GTFTDynParaCnf->filters[j].remoteAddrAndMask.addrType==CI_PS_PDP_IPV4)
									{
									  		add_len=CI_PS_PDP_IPV4_ADDR_LENGTH;
									}
									else if(read4GTFTDynParaCnf->filters[j].remoteAddrAndMask.addrType==CI_PS_PDP_FULL_IPV6)
									{
									   		add_len=CI_PS_PDP_FULL_IPV6_ADDR_LENGTH;

									}
									  else if(read4GTFTDynParaCnf->filters[j].remoteAddrAndMask.addrType==CI_PS_PDP_IPV6_INTERFACE)
									{
									   		add_len=CI_PS_PDP_IPV6_INTERFACE_ADDR_LENGTH;

									}
									for(k = 0;k < add_len;k ++)
									{
										if(k < add_len - 1)
										{
											sprintf((char *)TempBuf,"%d.",read4GTFTDynParaCnf->filters[j].remoteAddrAndMask.valData[k]);
											strcat((char *)AtRspBuf,(char *)TempBuf);
										}
										else
										{
											sprintf((char *)TempBuf,"%d",read4GTFTDynParaCnf->filters[j].remoteAddrAndMask.valData[k]);
											strcat((char *)AtRspBuf,(char *)TempBuf);
										}
									}

								}

								strcat((char *)AtRspBuf,".");

								if(read4GTFTDynParaCnf->filters[j].remoteAddrAndMask.subnetLength==0)
								{
								   if(read4GTFTDynParaCnf->filters[j].remoteAddrAndMask.addrType==CI_PS_PDP_IPV4)
								   {//IPV4 subnetmask
									   strcat((char *)AtRspBuf,(char *)"255.255.255.0");
								   }
								   else
								   {//ipv6 subnet mask
									   strcat((char *)AtRspBuf,(char *)"255.255.255.0.0.0.0.0.0.0.0.0.0.0.0.0");
								   }
								}
								else
								{
								   subnetmask_len2str(read4GTFTDynParaCnf->filters[j].remoteAddrAndMask.subnetLength,mask_addr);

								   strcat((char *)AtRspBuf,(char *)mask_addr);
								}

								strcat((char *)AtRspBuf,"\"");
								strcat((char *)AtRspBuf,",");

								if(read4GTFTDynParaCnf->filters[j].pIdNextHdrPresent == TRUE)
								{
								    sprintf ( (char *)TempBuf,"%d",read4GTFTDynParaCnf->filters[j].pIdNextHdr);
								    strcat((char *)AtRspBuf,(char *)TempBuf);
								}
								strcat((char *)AtRspBuf,",");

								if(read4GTFTDynParaCnf->filters[j].srcPortRangePresent == TRUE)
								{
									sprintf ( (char *)TempBuf,"%d.%d",read4GTFTDynParaCnf->filters[j].srcPortRange.min,
										read4GTFTDynParaCnf->filters[j].srcPortRange.max);
									strcat((char *)AtRspBuf,(char *)TempBuf);
								}
								strcat((char *)AtRspBuf,",");


								if(read4GTFTDynParaCnf->filters[j].dstPortRangePresent == TRUE)
								{
									sprintf ( (char *)TempBuf,"%d.%d",read4GTFTDynParaCnf->filters[j].dstPortRange.min,
										read4GTFTDynParaCnf->filters[j].dstPortRange.max);
									strcat((char *)AtRspBuf,(char *)TempBuf);
								}
								strcat((char *)AtRspBuf,",");

								if(read4GTFTDynParaCnf->filters[j].ipSecSPIPresent == TRUE)
								{
	                                sprintf ( (char *)TempBuf,"%d",read4GTFTDynParaCnf->filters[j].ipSecSPI);
	                                strcat((char *)AtRspBuf,(char *)TempBuf);
	                            }
	                            strcat((char *)AtRspBuf,",");

	                            if(read4GTFTDynParaCnf->filters[j].tosPresent == TRUE)
	                            {
	                                sprintf ( (char *)TempBuf,"%d.",read4GTFTDynParaCnf->filters[j].tosTc);
	                                strcat((char *)AtRspBuf,(char *)TempBuf);
	                                sprintf ( (char *)TempBuf,"%d",read4GTFTDynParaCnf->filters[j].tosTcMask);
	                                strcat((char *)AtRspBuf,(char *)TempBuf);
	                            }
	                            strcat((char *)AtRspBuf,",");

	                            if(read4GTFTDynParaCnf->filters[j].flowLabelPresent == TRUE)
	                            {
	                                sprintf ( (char *)TempBuf,"%d",read4GTFTDynParaCnf->filters[j].flowLabel);
	                                strcat((char *)AtRspBuf,(char *)TempBuf);
	                            }
	                            strcat((char *)AtRspBuf,",");

	                            sprintf((char *)TempBuf,"%d",read4GTFTDynParaCnf->filters[j].direction);
	                            strcat((char *)AtRspBuf,(char *)TempBuf);

	                            ATRESP( reqHandle,0,0,(char *)AtRspBuf);
	                        }
	                    }
	                    else
	                    {

	                        if(read4GTFTDynParaCnf->numFilters == 1)
	                        {
	                            sprintf ( (char *)AtRspBuf,"+CGTFTRDP: " );

	                            sprintf((char *)TempBuf,"%d,",read4GTFTDynParaCnf->filters[0].cid+1);
	                            strcat((char *)AtRspBuf,(char *)TempBuf);

	                            sprintf ( (char *)TempBuf,"%d,",read4GTFTDynParaCnf->filters[0].pfId+1);
	                            strcat((char *)AtRspBuf,(char *)TempBuf);

	                            sprintf ( (char *)TempBuf,"%d,",read4GTFTDynParaCnf->filters[0].epIndex);
	                            strcat((char *)AtRspBuf,(char *)TempBuf);

	                            strcat((char *)AtRspBuf,"\"");
								//mask mengliang
								if(read4GTFTDynParaCnf->filters[0].remoteAddrAndMask.addrType!=CI_PS_PDP_INVALID_ADDR)
								{
									if(read4GTFTDynParaCnf->filters[0].remoteAddrAndMask.addrType==CI_PS_PDP_IPV4)
									{
										add_len=CI_PS_PDP_IPV4_ADDR_LENGTH;
									}
									else if(read4GTFTDynParaCnf->filters[0].remoteAddrAndMask.addrType==CI_PS_PDP_FULL_IPV6)
									{
										add_len=CI_PS_PDP_FULL_IPV6_ADDR_LENGTH;

									}
									else if(read4GTFTDynParaCnf->filters[0].remoteAddrAndMask.addrType==CI_PS_PDP_IPV6_INTERFACE)
									{
										add_len=CI_PS_PDP_IPV6_INTERFACE_ADDR_LENGTH;

									}
								   for(k = 0;k < add_len;k ++)
								   {
									   if(k < add_len - 1)
									   {
										   sprintf((char *)TempBuf,"%d.",read4GTFTDynParaCnf->filters[0].remoteAddrAndMask.valData[k]);
										   strcat((char *)AtRspBuf,(char *)TempBuf);
									   }
									   else
									   {
										   sprintf((char *)TempBuf,"%d",read4GTFTDynParaCnf->filters[0].remoteAddrAndMask.valData[k]);
										   strcat((char *)AtRspBuf,(char *)TempBuf);
									   }
								   }

							   }

								strcat((char *)AtRspBuf,".");

								if(read4GTFTDynParaCnf->filters[0].remoteAddrAndMask.subnetLength==0)
								{
									if(read4GTFTDynParaCnf->filters[0].remoteAddrAndMask.addrType==CI_PS_PDP_IPV4)
									{//IPV4 subnetmask
										strcat((char *)AtRspBuf,(char *)"255.255.255.0");
									}
									else
									{//ipv6 subnet mask
										strcat((char *)AtRspBuf,(char *)"255.255.255.0.0.0.0.0.0.0.0.0.0.0.0.0");
									}
								}
								else
								{
									subnetmask_len2str(read4GTFTDynParaCnf->filters[0].remoteAddrAndMask.subnetLength,mask_addr);

									strcat((char *)AtRspBuf,(char *)mask_addr);
								}

	                            strcat((char *)AtRspBuf,"\"");
	                            strcat((char *)AtRspBuf,",");

	                            if(read4GTFTDynParaCnf->filters[0].pIdNextHdrPresent == TRUE)
	                            {
	                                sprintf ( (char *)TempBuf,"%d",read4GTFTDynParaCnf->filters[0].pIdNextHdr);
	                                strcat((char *)AtRspBuf,(char *)TempBuf);
	                            }
	                            strcat((char *)AtRspBuf,",");

								if(read4GTFTDynParaCnf->filters[0].srcPortRangePresent == TRUE)
								{
									sprintf ( (char *)TempBuf,"%d.%d",read4GTFTDynParaCnf->filters[0].srcPortRange.min,
										read4GTFTDynParaCnf->filters[0].srcPortRange.max);
									strcat((char *)AtRspBuf,(char *)TempBuf);
								}
								strcat((char *)AtRspBuf,",");

								if(read4GTFTDynParaCnf->filters[0].dstPortRangePresent == TRUE)
								{
									sprintf ( (char *)TempBuf,"%d.%d",read4GTFTDynParaCnf->filters[0].dstPortRange.min,
										read4GTFTDynParaCnf->filters[0].dstPortRange.max);
									strcat((char *)AtRspBuf,(char *)TempBuf);
		                        }
	                            strcat((char *)AtRspBuf,",");

	                            if(read4GTFTDynParaCnf->filters[0].ipSecSPIPresent == TRUE)
	                            {
	                                sprintf ( (char *)TempBuf,"%d",read4GTFTDynParaCnf->filters[0].ipSecSPI);
	                                strcat((char *)AtRspBuf,(char *)TempBuf);
	                            }
	                            strcat((char *)AtRspBuf,",");

	                            if(read4GTFTDynParaCnf->filters[0].tosPresent == TRUE)
	                            {
	                                sprintf ( (char *)TempBuf,"%d.",read4GTFTDynParaCnf->filters[0].tosTc);
	                                strcat((char *)AtRspBuf,(char *)TempBuf);
	                                sprintf ( (char *)TempBuf,"%d",read4GTFTDynParaCnf->filters[0].tosTcMask);
	                                strcat((char *)AtRspBuf,(char *)TempBuf);
	                            }
	                            strcat((char *)AtRspBuf,",");

	                            if(read4GTFTDynParaCnf->filters[0].flowLabelPresent == TRUE)
	                            {
	                                sprintf ( (char *)TempBuf,"%d",read4GTFTDynParaCnf->filters[0].flowLabel);
	                                strcat((char *)AtRspBuf,(char *)TempBuf);
	                            }
	                            strcat((char *)AtRspBuf,",");

	                            sprintf((char *)TempBuf,"%d",read4GTFTDynParaCnf->filters[0].direction);
	                            strcat((char *)AtRspBuf,(char *)TempBuf);

	                            ATRESP( reqHandle,0,0,(char *)AtRspBuf);
	                        }
	                    }
	                    ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
	                    break;
	                }
	                default:
	                    ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
	                    goto end;
	            }
			}
			else
			{
				checkPSRet(reqHandle, read4GTFTDynParaCnf->rc);
			}
			break;
		}

		case CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_CAPS_CNF:
		{
			read4GTFTDynParaCapsCnf = (CiPsPrimRead4GTrafficFlowTempDynParaCapsCnf *)paras;
			if(read4GTFTDynParaCapsCnf->rc == CIRC_PS_SUCCESS)
			{
        		switch (GET_REQ_ID(reqHandle))
		        {
		            case CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_CAPS_REQ:
		            {
		                if(read4GTFTDynParaCapsCnf->num > 0)
		                {
		                    sprintf((char *)AtRspBuf,"+CGTFTRDP: (");
		                    for(i = 0;i < read4GTFTDynParaCapsCnf->num;i ++)
		                    {
		                        if(i < read4GTFTDynParaCapsCnf->num - 1)
		                        {
		                            sprintf((char *)TempBuf,"%d,",read4GTFTDynParaCapsCnf->cid[i]+1);
		                        }
		                        else
		                        {
		                            sprintf((char *)TempBuf,"%d",read4GTFTDynParaCapsCnf->cid[i]+1);
		                        }
		                        strcat((char *)AtRspBuf,(char *)TempBuf);
		                    }
							strcat((char *)AtRspBuf,")");
		                    ATRESP( reqHandle, 0,0,(char *)AtRspBuf);
		                }
		                ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
		                break;
		            }
		            default:
		                ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
		                goto end;
		        }
		    }
		    else
			{
				checkPSRet(reqHandle, read4GTFTDynParaCapsCnf->rc);
			}
			break;
		}

		case CI_PS_PRIM_READ_4G_QOS_DYN_PARA_CNF:
		{
			read4GQosDynParaCnf = (CiPsPrimRead4GQosDynParaCnf *)paras;
			if(read4GQosDynParaCnf->rc == CIRC_PS_SUCCESS)
			{
				switch (GET_REQ_ID(reqHandle))
				{
					case CI_PS_PRIM_READ_4G_QOS_DYN_PARA_REQ:
		            {
		                if(gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid == 0xFF)
		                {
		                    for(i = 0;i < read4GQosDynParaCnf->num;i ++)
							{
								sprintf((char *)AtRspBuf,"+CGEQOSRDP: %d,%d", i+1, read4GQosDynParaCnf->qosProfile[i].qci);
								if(read4GQosDynParaCnf->qosProfile[i].gbrMbrPresent)
								{
									sprintf((char *)TempBuf, ",%d,%d,%d,%d",
											read4GQosDynParaCnf->qosProfile[i].guaranteedDLRate,
											read4GQosDynParaCnf->qosProfile[i].guaranteedULRate,
											read4GQosDynParaCnf->qosProfile[i].maxDLRate,
											read4GQosDynParaCnf->qosProfile[i].maxULRate);
									strcat(AtRspBuf, TempBuf);
								}

								if(read4GQosDynParaCnf->qosProfile[i].ambrPresent)
								{
									sprintf((char *)TempBuf, ",%d,%d",
											read4GQosDynParaCnf->qosProfile[i].apnDLAmbr,
											read4GQosDynParaCnf->qosProfile[i].apnULAmbr);
									strcat(AtRspBuf, TempBuf);
								}
								ATRESP(reqHandle,0,0,(char *)AtRspBuf);
							}
						}
						else
						{
							if(read4GQosDynParaCnf->num == 1)
							{
								sprintf((char *)AtRspBuf,"+CGEQOSRDP: %d,%d",
									gCIDList.currCntx[GET_ATP_INDEX(reqHandle)].currCid+1,
									read4GQosDynParaCnf->qosProfile[0].qci);
								if(read4GQosDynParaCnf->qosProfile[0].gbrMbrPresent)
								{
									sprintf((char *)TempBuf, ",%d,%d,%d,%d",
											read4GQosDynParaCnf->qosProfile[0].guaranteedDLRate,
											read4GQosDynParaCnf->qosProfile[0].guaranteedULRate,
											read4GQosDynParaCnf->qosProfile[0].maxDLRate,
											read4GQosDynParaCnf->qosProfile[0].maxULRate);
									strcat(AtRspBuf, TempBuf);
								}

								if(read4GQosDynParaCnf->qosProfile[0].ambrPresent)
								{
									sprintf((char *)TempBuf, ",%d,%d",
											read4GQosDynParaCnf->qosProfile[0].apnDLAmbr,
											read4GQosDynParaCnf->qosProfile[0].apnULAmbr);
									strcat(AtRspBuf, TempBuf);
								}
								ATRESP(reqHandle,0,0,(char *)AtRspBuf);
		                    }
		                }
		                ATRESP(reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
		                break;
					}
		            case CI_PS_PRIM_SET_4G_MODE_REQ:
		            {
		                break;
		            }
		            case CI_PS_PRIM_GET_4G_MODE_CAPS_REQ:
		            {
		                break;
		            }
		            default:
		                ATRESP(reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
		                goto end;
			    }
		    }
		    else
		    {
				checkPSRet(reqHandle, read4GQosDynParaCnf->rc);
		    }
		    break;
		}

    	case CI_PS_PRIM_READ_4G_QOS_DYN_PARA_CAPS_CNF:
	    {
	        read4GQosDynParaCapsCnf = (CiPsPrimRead4GQosDynParaCapsCnf *)paras;
	        if(read4GQosDynParaCapsCnf->rc == CIRC_PS_SUCCESS)
	        {
	            switch(GET_REQ_ID(reqHandle))
	            {
	                case CI_PS_PRIM_READ_4G_QOS_DYN_PARA_CAPS_REQ:
	                {
	                    if(read4GQosDynParaCapsCnf->num > 0)
	                    {
	                        sprintf((char *)AtRspBuf,"+CGEQOSRDP: ");
	                        for(i = 0;i < read4GQosDynParaCapsCnf->num;i ++)
	                        {
	                            if(i < read4GQosDynParaCapsCnf->num - 1)
	                            {
	                                sprintf((char *)TempBuf,"%d,",read4GQosDynParaCapsCnf->cid[i]+1);
	                            }
	                            else
	                            {
	                                sprintf((char *)TempBuf,"%d",read4GQosDynParaCapsCnf->cid[i]+1);
	                            }
	                            strcat((char *)AtRspBuf,(char *)TempBuf);
	                        }
	                        ATRESP( reqHandle, 0,0,(char *)AtRspBuf);
	                    }
	                    ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
	                    break;
	                }
	                default:
	                    ATRESP(reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
	                    goto end;
	            }
	        }
	        else
	        {
				checkPSRet(reqHandle, read4GQosDynParaCapsCnf->rc);
	        }
	        break;
	    }
    	case CI_PS_PRIM_GET_4G_EVET_REP_CNF:
	    {
	        get4GEventRepCnf = (CiPsPrimGet4GEventRepCnf *)paras;
	        if(get4GEventRepCnf->rc == CIRC_PS_SUCCESS)
	        {
	            switch (GET_REQ_ID(reqHandle))
	            {
	                case CI_PS_PRIM_GET_4G_EVET_REP_REQ:
	                {
	                    sprintf((char *)AtRspBuf,"+CGEREP: %d,%d",get4GEventRepCnf->mode,get4GEventRepCnf->bfr);
	                    ATRESP( reqHandle, 0,0,(char *)AtRspBuf);
	                    break;
	                }
	                default:
	                    ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
	                    goto end;
	            }
	            ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
	        }
	        else
	        {
				checkPSRet(reqHandle, get4GEventRepCnf->rc);
	        }
	        break;
	    }

	    case CI_PS_PRIM_GET_4G_EVET_REP_CAPS_CNF:
	    {
	        get4GEventRepCapsCnf = (CiPsPrimGet4GEventRepCapsCnf *)paras;
	        if(get4GEventRepCapsCnf->rc == CIRC_PS_SUCCESS)
	        {
	            switch (GET_REQ_ID(reqHandle))
	            {
	                case CI_PS_PRIM_GET_4G_EVET_REP_CAPS_REQ:
	                {
	                    sprintf ((char *)AtRspBuf,"+CGEREP: %d,%d,%d,%d",
	                        get4GEventRepCapsCnf->reportCaps.mode_min,
	                        get4GEventRepCapsCnf->reportCaps.mode_max,
	                        get4GEventRepCapsCnf->reportCaps.buffer_min,
	                        get4GEventRepCapsCnf->reportCaps.buffer_max);
	                    ATRESP( reqHandle,0,0,(char *)AtRspBuf);
	                    ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
	                    break;
	                }
	                default:
	                    ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
	                    goto end;
	            }
	        }
	        else
	        {
				checkPSRet(reqHandle, get4GEventRepCapsCnf->rc);
	        }
	        break;
		}

		case CI_PS_PRIM_SET_4G_EVET_REP_CNF:
		{
			set4GEventRepCnf = (CiPsPrimSet4GEventRepCnf *)paras;
			if(set4GEventRepCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
			}
			else
			{
				checkPSRet(reqHandle, set4GEventRepCnf->rc);
			}
			break;
		}
#ifdef VOLTE_ENABLE
		case CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_CNF:
		{
			get4GVoiceCallModeCnf = (CiPsPrimGet4GVoiceCallModeCnf *)paras;
			if(get4GVoiceCallModeCnf->rc == CIRC_PS_SUCCESS)
			{
	       		switch (GET_REQ_ID(reqHandle))
	            {
	                case CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_REQ:
	                {
	                    sprintf ( (char *)AtRspBuf,"+CVMOD: " );
	                    sprintf ( (char *)TempBuf,"%d",
	                        get4GVoiceCallModeCnf->mode);
						strcat((char *)AtRspBuf, (char *)TempBuf);
	                    ATRESP( reqHandle, 0,0,(char *)AtRspBuf);
	                    break;
	                }
	                default:
	                    ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
	                    goto end;
	            }
		        ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
		    }
		    else
		    {
				checkPSRet(reqHandle, get4GVoiceCallModeCnf->rc);
		    }
		    break;
		}

	    case CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_CAPS_CNF:
	    {
	        get4GVoiceCallModeCapsCnf = (CiPsPrimGet4GVoiceCallModeCapsCnf *)paras;
	        if(get4GVoiceCallModeCapsCnf->rc == CIRC_PS_SUCCESS)
	        {
	            switch (GET_REQ_ID(reqHandle))
	            {
	                case CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_CAPS_REQ:
	                {
	                    sprintf ( (char *)AtRspBuf,"+CVMOD: " );
	                    sprintf ( (char *)TempBuf,"%d",
	                        get4GVoiceCallModeCapsCnf->modebitmap);
	                    strcat((char *)AtRspBuf,(char *)TempBuf);
	                    ATRESP( reqHandle, 0,0,(char *)AtRspBuf);
	                    break;
	                }
	                default:
	                    ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
	                    goto end;
	            }
	            ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
			}
			else
			{
				checkPSRet(reqHandle, get4GVoiceCallModeCapsCnf->rc);
			}
			break;
		}

		case CI_PS_PRIM_SET_4G_VOICE_CALL_MODE_CNF:
		{
			set4GVoiceCallModeCnf = (CiPsPrimSet4GVoiceCallModeCnf *)paras;
			if(set4GVoiceCallModeCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
			}
			else
			{
				checkPSRet(reqHandle, set4GVoiceCallModeCnf->rc);
			}
			break;
		}
#endif
   		case CI_PS_PRIM_SET_4G_MODE_CNF:
	    {
	        set4GModeCnf = (CiPsPrimSet4GModeCnf *)paras;
	        if(set4GModeCnf->rc == CIRC_PS_SUCCESS)
	        {
	            ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
	        }
	        else
	        {
				checkPSRet(reqHandle, set4GModeCnf->rc);
	        }
	        break;
	    }

    	case CI_PS_PRIM_GET_4G_MODE_CNF:
	    {
	        get4GModeCnf = (CiPsPrimGet4GModeCnf *)paras;
	        if(get4GModeCnf->rc == CIRC_PS_SUCCESS)
	        {
	            switch(GET_REQ_ID(reqHandle))
	            {
	                case CI_PS_PRIM_GET_4G_MODE_REQ:
	                    sprintf ( (char *)AtRspBuf,"+CEMODE: %d", get4GModeCnf->cipslteOperateMode);
	                    ATRESP( reqHandle, 0,0,(char *)AtRspBuf);
	                    ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
	                    break;
	                default:
	                    ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
	                    goto end;
	            }
	        }
	        else
	        {
				checkPSRet(reqHandle, get4GModeCnf->rc);
	        }
	        break;
		}
		case CI_PS_PRIM_GET_4G_MODE_CAPS_CNF:
		{
			get4GModeCapsCnf = (CiPsPrimGet4GModeCapsCnf *)paras;
			switch (GET_REQ_ID(reqHandle))
			{
				case CI_PS_PRIM_GET_4G_MODE_CAPS_REQ:
		        {
		            sprintf ( (char *)AtRspBuf,"+CEMODE: " );
		            break;
		        }
		        default:
		            ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
		            goto end;
	    	}
		    for(i = 0; i < 4; i ++)
		    {
		        sprintf ( (char *)TempBuf,"%d,",get4GModeCapsCnf->ciPsLteOperateModes.ciPsLteOperateMode[i]);
		        strcat((char *)AtRspBuf,(char *)TempBuf);
		        ATRESP( reqHandle, 0,0,(char *)AtRspBuf);

				/*[Fixed][coverity]*/
		        memset((char *)AtRspBuf,0,1000*sizeof(char));
		    }
			ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
			break;
		}

		case CI_PS_PRIM_GET_PDP_ADDR_CNF:
		{
	        UINT32 j;
			getPdpAddrCnf = (CiPsPrimGetPdpAddrCnf *)paras;
			if(getPdpAddrCnf->rc == CIRC_PS_SUCCESS)
			{
				switch (GET_REQ_ID(reqHandle))
				{
					case CI_PS_PRIM_GET_PDP_ADDR_REQ:
					{
		                sprintf ( (char *)AtRspBuf,"+CGPADDR: " );
		                ATRESP( reqHandle, 0,0,(char *)AtRspBuf);

		                for(i = 0;i < getPdpAddrCnf->num;i ++)
		                {
		                    sprintf((char *)AtRspBuf,"%d,\"",getPdpAddrCnf->cid[i]+1);
		                    for(j = 0;j < getPdpAddrCnf->pdpAddress[i].len;j ++)
		                    {
		                        if(j < getPdpAddrCnf->pdpAddress[i].len - 1)
		                        {
		                            sprintf((char *)TempBuf,"%d.",getPdpAddrCnf->pdpAddress[i].valData[j]);
		                            strcat((char *)AtRspBuf,(char *)TempBuf);
		                        }
		                        else
		                        {
		                            sprintf((char *)TempBuf,"%d",getPdpAddrCnf->pdpAddress[i].valData[j]);
		                            strcat((char *)AtRspBuf,(char *)TempBuf);
		                        }
		                    }
		                    strcat((char *)AtRspBuf,"\"");
		                    ATRESP( reqHandle, 0,0,(char *)AtRspBuf);
		                }
		                ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);

		                break;
		            }
		            default:
		                ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
		                goto end;
		        }
		    }
	        else
	        {
					ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
			}
			break;
		}

		case CI_PS_PRIM_GET_PDP_ADDR_LIST_CNF:
		{
			getPdpAddrListCnf = (CiPsPrimGetPdpAddrListCnf *)paras;
			if(getPdpAddrListCnf->rc == CIRC_PS_SUCCESS)
			{
				switch (GET_REQ_ID(reqHandle))
		        {
		            case CI_PS_PRIM_GET_PDP_ADDR_LIST_REQ:
		            {
#ifdef QUECTEL_NETWORK_SUPPORT //connor.wu 2018/11/30 fix the result to be same with Qualcomm
						strcat ( (char *)AtRspBuf,"+CGPADDR: (" );
#else                    
		                sprintf ( (char *)AtRspBuf,"+CGPADDR: " );
#endif
		                for(i = 0; i < getPdpAddrListCnf->nums; i ++)
		                {
							
					
		                    sprintf((char *)TempBuf,"%d",getPdpAddrListCnf->cid[i]+1);
		                    strcat((char *)AtRspBuf,(char *)TempBuf);
		                    if(i < getPdpAddrListCnf->nums - 1)
		                    {
		                        strcat((char *)AtRspBuf,",");
		                    }
		                }
#ifdef QUECTEL_NETWORK_SUPPORT
						strcat ( (char *)AtRspBuf,")" );
#endif
		                ATRESP( reqHandle, 0,0,(char *)AtRspBuf);
		                ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);

		                break;
		            }
		            default:
		                ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
		                goto end;
		        }
			}
			else
			{
				checkPSRet(reqHandle, getPdpAddrListCnf->rc);
			}
			break;
		}

    	case CI_PS_PRIM_ENABLE_4G_NW_REG_IND_CNF:
	    {
	        enable4GNwRegIndCnf = (CiPsPrimEnable4GNwRegIndCnf *)paras;
	        if(enable4GNwRegIndCnf->rc == CIRC_PS_SUCCESS)
	        {
#ifdef LWIP_IPNETBUF_SUPPORT
			    update4GPsRegOption(reqHandle);
#else
			    *p4GCurrentPSRegOption = pS4GRequestedRegOption;
#endif
	            ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
	        }
	        else
			{
				checkPSRet(reqHandle, enable4GNwRegIndCnf->rc);
			}
			break;
		}

#ifdef VOLTE_ENABLE
		case CI_PS_PRIM_GET_IMS_REG_INFO_CNF:
		{
			getImsRegStatusCnf = (CiPsPrimGetImsRegInfoCnf *)paras;
			if(getImsRegStatusCnf->rc == CIRC_PS_SUCCESS)
			{
				sprintf ( (char *)AtRspBuf,"+CIREG: %d,%d", getImsRegStatusCnf->reportState,
						getImsRegStatusCnf->info.regInfo);

				if(getImsRegStatusCnf->reportState == CI_PS_NW_REG_IND_ENABLE_DETAIL)
				{
					sprintf(TempBuf, ",%d", getImsRegStatusCnf->info.extInfo);
					strcat((char *)AtRspBuf,(char *)TempBuf);
				}

				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, AtRspBuf);

			}
			else
			{
				checkPSRet(reqHandle, getImsRegStatusCnf->rc);
			}
			break;
		}
#endif
    	case CI_PS_PRIM_GET_4G_NW_REG_STATUS_CNF:
	    {
			//UINT8 regPram = get4GNwRegStatusCnf->regIndflag;
			UINT8 tempBuf[16];
	        get4GNwRegStatusCnf = (CiPsPrimGet4GNwRegStatusCnf *)paras;
			
			if(get4GNwRegStatusCnf->rc == CIRC_PS_SUCCESS)
			{	
				#ifdef QUECTEL_OPEN_CPU
				#ifndef MIN_SYS
				if(!IsMiniSystem()){
					quec_nw_event_ind(GET_AT_HANDLE(reqHandle),paras,QUEC_NW_CMD_RESP_DATE_REG_STATUS_LTE);
				}
				#endif
				#endif
				
				switch (GET_REQ_ID(reqHandle))
				{
					#ifdef CRANE_MCU_DONGLE
					case CI_PS_PRIM_GET_SYSINFO_NW_REG_STATUS_REQ:
					{
						processGet4GSysInfoCnf(reqHandle, paras);
						break;
					}
					#endif
					case CI_PS_PRIM_GET_4G_NW_REG_STATUS_REQ:
					{
                        
						#ifdef PPP_ENABLE
						if(isHandleForMasterSim(atHandle))
							modem_update_reg_option(GET_ATP_INDEX(atHandle), *p4GCurrentPSRegOption);
						#endif

						#ifdef LWIP_IPNETBUF_SUPPORT
						updateCeregStatus(atHandle, get4GNwRegStatusCnf->nwRegInfo.status);
	                			checkNWRegStatus(atHandle);
						if (*p4GCurrentPSRegOption >= CI_PS_NW_REG_IND_ENABLE_DETAIL)
							updatePs4GRegDetail(atHandle, &(get4GNwRegStatusCnf->nwRegInfo));
						#endif

						*pCurrent4gPSRegStatus = get4GNwRegStatusCnf->nwRegInfo.status;
						#ifdef QUEC_MINI_SYSTEM_SUPPORT //add by Chaim 20201231,not support 3,so fore to 2
							get4GNwRegStatusCnf->regIndflag = CI_PS_NW_REG_IND_ENABLE_DETAIL;
							//regPram = get4GNwRegStatusCnf->regIndflag;
							CPUartLogPrintf("fore to n=2");
						#endif
						sprintf ( (char *)AtRspBuf,"+CEREG: %d,%d", *p4GCurrentPSRegOption,
								get4GNwRegStatusCnf->nwRegInfo.status);

						DBGMSG("g4gCurrentPSRegOption=0x%x,present=0x%x\r\n",get4GNwRegStatusCnf->regIndflag,get4GNwRegStatusCnf->nwRegInfo.tacPresent);
						if(*p4GCurrentPSRegOption >CI_PS_NW_REG_IND_ENABLE_STA_ONLY)
						{
							if(get4GNwRegStatusCnf->nwRegInfo.tacPresent == TRUE)
							{
								*pPsActDetail = get4GNwRegStatusCnf->nwRegInfo.act;
								sprintf(TempBuf, ",\"%04x\",\"%08x\",%d", get4GNwRegStatusCnf->nwRegInfo.tac,
										get4GNwRegStatusCnf->nwRegInfo.cellId, *pPsActDetail);
								strcat((char *)AtRspBuf,(char *)TempBuf);
							}
							if( *p4GCurrentPSRegOption >  CI_PS_NW_REG_IND_ENABLE_DETAIL )
							{
								if(get4GNwRegStatusCnf->nwRegInfo.causePresent == TRUE)
								{
									if(get4GNwRegStatusCnf->nwRegInfo.tacPresent == FALSE)
									{
										sprintf(TempBuf, ",,,");
										strcat((char *)AtRspBuf,(char *)TempBuf);
									}
									if(*p4GCurrentPSRegOption == CI_PS_NW_REG_IND_ENABLE_PSM)
									{
										strcat((char *)AtRspBuf,",,");
									}else
									{
										
										sprintf(TempBuf, ",%d,%d", get4GNwRegStatusCnf->nwRegInfo.causeType,
											get4GNwRegStatusCnf->nwRegInfo.rejectCause);
										strcat((char *)AtRspBuf,(char *)TempBuf);
									}

								}
								
								if(*p4GCurrentPSRegOption >  CI_PS_NW_REG_IND_ENABLE_MORE_DETAIL )
								{
									if((get4GNwRegStatusCnf->nwRegInfo.activeTimePresent== TRUE) || (get4GNwRegStatusCnf->nwRegInfo.periodicTauPresent== TRUE))
									{
										if(get4GNwRegStatusCnf->nwRegInfo.causePresent == FALSE)
										{
											if(get4GNwRegStatusCnf->nwRegInfo.tacPresent == FALSE)
											{
												strcat((char *)AtRspBuf,",,,,,");
											}
											else
											{
												strcat((char *)AtRspBuf,",,");
											}
										}
									}
								
									
									if(get4GNwRegStatusCnf->nwRegInfo.activeTimePresent== TRUE)
									{
										strcat(AtRspBuf,",\"");
										memset(tempBuf, 0, sizeof(tempBuf));
										if(convertDecIntToBinStr(get4GNwRegStatusCnf->nwRegInfo.activeTime,tempBuf, 8)==TRUE)
										{
											strcat((char *)AtRspBuf,(char *)TempBuf);
										}
								
										strcat(AtRspBuf,"\"");
									}
								
									if(get4GNwRegStatusCnf->nwRegInfo.periodicTauPresent== TRUE)
									{
										if(get4GNwRegStatusCnf->nwRegInfo.activeTimePresent== FALSE)
										{
											strcat((char *)AtRspBuf,",");
										}
								
										strcat(AtRspBuf,",\"");
										memset(tempBuf, 0, sizeof(tempBuf));
										if(convertDecIntToBinStr(get4GNwRegStatusCnf->nwRegInfo.periodicTau,tempBuf, 8)==TRUE)
										{
											strcat((char *)AtRspBuf,(char *)TempBuf);
										}
										strcat(AtRspBuf,"\"");
								
									}
								
								}

							}
						}
						ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, AtRspBuf);
						break;
					}
					default:
						ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
						break;
				}

			}
			else
			{
				checkPSRet(reqHandle, get4GNwRegStatusCnf->rc);
			}
			break;
		}
#ifndef LTEONLY_THIN  		
		case CI_PS_PRIM_SET_GSMGPRS_CLASS_CNF:
	    {
	        setGsmGprsClassCnf = (CiPsPrimSetGsmGprsClassCnf *)paras;
	        if(setGsmGprsClassCnf->rc == CIRC_PS_SUCCESS)
	        {
	            ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
	        }
	        else
	        {
				checkPSRet(reqHandle, setGsmGprsClassCnf->rc);
	        }

	        break;
	    }
    	case CI_PS_PRIM_GET_GSMGPRS_CLASS_CNF:
	    {
	        getGsmGprsClassCnf = (CiPsPrimGetGsmGprsClassCnf *)paras;
	        if(getGsmGprsClassCnf->rc == CIRC_PS_SUCCESS)
	        {
	            switch (GET_REQ_ID(reqHandle))
	            {
	                case CI_PS_PRIM_GET_GSMGPRS_CLASS_REQ:
	                {						
						if (getGsmGprsClassCnf->classType<CI_PS_GSMGPRS_NUM_CLASSES)
						{
#ifdef QUECTEL_NETWORK_SUPPORT //fix the result of CGCLASS to be same with Qualcomm
	                    	sprintf ( (char *)AtRspBuf,"+CGCLASS: \"%s\"",classes[getGsmGprsClassCnf->classType]);
#else				
	                    	sprintf ( (char *)AtRspBuf,"+CGCLASS: %s",classes[getGsmGprsClassCnf->classType]);
#endif
	                    	ATRESP(reqHandle, 0,0,(char *)AtRspBuf);
	                    	ATRESP(reqHandle,ATCI_RESULT_CODE_OK,0,NULL);
						}
						else
							ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
	                    break;
	                }
	                default:
	                    ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
	                    goto end;
	            }
	        }
	        else
	        {
				checkPSRet(reqHandle, getGsmGprsClassCnf->rc);
	        }

	        break;
	    }
   		case CI_PS_PRIM_GET_GSMGPRS_CLASSES_CNF:
	    {
	        getGsmGprsClassesCnf = (CiPsPrimGetGsmGprsClassesCnf *)paras;
	        if(getGsmGprsClassesCnf->rc == CIRC_PS_SUCCESS)
	        {
	            switch (GET_REQ_ID(reqHandle))
	            {
	                case CI_PS_PRIM_GET_GSMGPRS_CLASSES_REQ:
	                {
						char comma = 0;						
						sprintf ((char *)AtRspBuf,"+CGCLASS: (");
												
						if (getGsmGprsClassesCnf->classes & (1<<CI_PS_GSMGPRS_CLASS_A)){
							comma = 1;
#ifdef QUECTEL_NETWORK_SUPPORT //fix the result of CGCLASS to be same with Qualcomm
	                    	strcat(AtRspBuf ,"\"");
#endif
	                    	strcat(AtRspBuf, classes[CI_PS_GSMGPRS_CLASS_A]);
#ifdef QUECTEL_NETWORK_SUPPORT
	                    	strcat(AtRspBuf ,"\"");
#endif
						}
						if (getGsmGprsClassesCnf->classes & (1<<CI_PS_GSMGPRS_CLASS_B)){
							if (comma)
								strcat(AtRspBuf, ",");
							comma = 1;
#ifdef QUECTEL_NETWORK_SUPPORT
	                    	strcat(AtRspBuf ,"\"");
#endif
	                    	strcat(AtRspBuf, classes[CI_PS_GSMGPRS_CLASS_B]);
#ifdef QUECTEL_NETWORK_SUPPORT
	                    	strcat(AtRspBuf ,"\"");
#endif							
						}
						if (getGsmGprsClassesCnf->classes & (1<<CI_PS_GSMGPRS_CLASS_CS)){
							if (comma)
								strcat(AtRspBuf, ",");
							comma = 1;
#ifdef QUECTEL_NETWORK_SUPPORT
	                    	strcat(AtRspBuf ,"\"");
#endif
	                    	strcat(AtRspBuf, classes[CI_PS_GSMGPRS_CLASS_CS]);
#ifdef QUECTEL_NETWORK_SUPPORT
	                    	strcat(AtRspBuf ,"\"");
#endif					
						}
						if (getGsmGprsClassesCnf->classes & (1<<CI_PS_GSMGPRS_CLASS_CC)){
							if (comma)
								strcat(AtRspBuf, ",");
#ifdef QUECTEL_NETWORK_SUPPORT
	                    	strcat(AtRspBuf ,"\"");
#endif
	                    	strcat(AtRspBuf, classes[CI_PS_GSMGPRS_CLASS_CC]);
#ifdef QUECTEL_NETWORK_SUPPORT
	                    	strcat(AtRspBuf ,"\"");
#endif
						}

						strcat(AtRspBuf, ")");
						
	                    ATRESP(reqHandle, 0,0,(char *)AtRspBuf);
	                    ATRESP(reqHandle,ATCI_RESULT_CODE_OK,0,NULL);

	                    break;
	                }
	                default:
	                    ATRESP( reqHandle,ATCI_RESULT_CODE_CME_ERROR,CME_UNKNOWN,NULL);
	                    goto end;
	            }
	        }
	        else
	        {
				checkPSRet(reqHandle, getGsmGprsClassesCnf->rc);
	        }

	        break;
	    }
#endif
#ifdef VOLTE_ENABLE
		case CI_PS_PRIM_SET_VOICE_DOMAIN_PREFERENCE_CNF:
		{
			setVoiceDomainPreferenceCnf = (CiPsPrimSetVoiceDomainPreferenceCnf *)paras;
			if(setVoiceDomainPreferenceCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				checkPSRet(reqHandle, setVoiceDomainPreferenceCnf->rc);
			}

			break;
		}
		case CI_PS_PRIM_GET_VOICE_DOMAIN_PREFERENCE_CNF:
		{
			getVoiceDomainPreferenceCnf = (CiPsPrimGetVoiceDomainPreferenceCnf *)paras;
			if(getVoiceDomainPreferenceCnf->rc == CIRC_PS_SUCCESS)
			{
				if(*pGetEutranVoiceDomainPreference)
				{
					sprintf ( (char *)AtRspBuf,"+CEVDP: %d",getVoiceDomainPreferenceCnf->eutan_setting + 1);
				}
				else
				{
					sprintf ( (char *)AtRspBuf,"+CVDP: %d",getVoiceDomainPreferenceCnf->utran_setting + 1);
				}
				ATRESP(reqHandle, ATCI_RESULT_CODE_OK,0,(char *)AtRspBuf);
			}
			else
			{
				checkPSRet(reqHandle, getVoiceDomainPreferenceCnf->rc);
			}
			break;
		}
#endif		
		case CI_PS_PRIM_SET_EPS_USAGE_SETTING_CNF:
		{
			setEpsUsageSettingCnf = (CiPsPrimSetEpsUsageSettingCnf *)paras;
			if(setEpsUsageSettingCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				checkPSRet(reqHandle, setEpsUsageSettingCnf->rc);
			}

			break;
		}
		case CI_PS_PRIM_GET_EPS_USAGE_SETTING_CNF:
		{
			getEpsUsageSettingCnf = (CiPsPrimGetEpsUsageSettingCnf *)paras;
			if(getEpsUsageSettingCnf->rc == CIRC_PS_SUCCESS)
			{
				sprintf ( (char *)AtRspBuf,"+CEUS: %d",getEpsUsageSettingCnf->epsUsageSetting);
				ATRESP(reqHandle, ATCI_RESULT_CODE_OK,0,(char *)AtRspBuf);
			}
			else
			{
				checkPSRet(reqHandle, getEpsUsageSettingCnf->rc);
			}
			break;
		}

#ifndef MORE_ATC_SPACE_OPT
		case CI_PS_PRIM_SET_PS_SERVICE_DOMAIN_CNF:
		{
			sepadomaincnf = (CiPsPrimSetPsServiceDomainCnf *)paras;

			if( sepadomaincnf->rc == CIRC_PS_SUCCESS )
			{
				ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,(char *)AtRspBuf);
			}
			else
			{
				checkPSRet(reqHandle, sepadomaincnf->rc);
			}

			break;
		}
		case CI_PS_PRIM_GET_PS_SERVICE_DOMAIN_CNF:
		{
			gepadomaincnf = (CiPsPrimGetPsServiceDomainCnf *)paras;

			sprintf ( (char *)AtRspBuf,"*PSDC: %d\r\n", gepadomaincnf->psServiceEnable);
			ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,(char *)AtRspBuf);

			break;
		}
#endif
		#ifdef PLATFORM_FOR_PS_LW
		case CI_PS_PRIM_SET_ACL_SERVICE_CNF:
		{
			setAclCnf = (CiPsPrimSetAclCnf *)paras;
			if( setAclCnf->rc == CIRC_PS_SUCCESS )
			{
				sprintf ( (char *)AtRspBuf,"+CACL: %d, %d\r\n", setAclCnf->simAclEnable,setAclCnf->psAclEnable);
				ATRESP( reqHandle,ATCI_RESULT_CODE_OK,0,(char *)AtRspBuf);
			}
			else
			{
				checkPSRet(reqHandle, getEpsUsageSettingCnf->rc);
			}

			break;
		}

		#endif
		
#ifdef LWIP_IPNETBUF_SUPPORT
#ifdef VOLTE_ENABLE
		case CI_PS_PRIM_SET_IMS_REG_STATE_CNF:
		{
			setImsRegStateCnf = (CiPsPrimSetImsRegStateCnf *)paras;
			if(setImsRegStateCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				checkPSRet(reqHandle, setImsRegStateCnf->rc);
			}

			break;
		}
		case CI_PS_PRIM_SET_IMS_SERVICE_STATUS_CNF:
		{
			setImsSrvStatusCnf = (CiPsPrimSetImsServiceStatusCnf*) paras;
			if(setImsSrvStatusCnf->rc == CIRC_PS_SUCCESS)
			{
				sprintf ( (char *)AtRspBuf,"*IMSSRV: %d",setImsSrvStatusCnf->cause);
				ATRESP(reqHandle, ATCI_RESULT_CODE_OK,0,(char *)AtRspBuf);
			}
			else
			{
                if(pocFlag && (setImsSrvStatusCnf->cause == CIPS_IMS_SRV_CAUSE_REDIAL))
                {
				    ATRESP( reqHandle, ATCI_RESULT_CODE_ERROR, 0, (char *)"*POCCMD: need retry\r\n");
                    pocFlag = FALSE;
                }
                else
					ATRESP( reqHandle, ATCI_RESULT_CODE_CME_ERROR, CME_IMS_SRV_FAILURE+setImsSrvStatusCnf->cause, NULL);
				//checkPSRet(reqHandle, setImsSrvStatusCnf->rc);
			}
			break;
		}
		case CI_PS_PRIM_SET_IMS_VOICE_CALL_AVAILABILITY_CNF:
		{
			setImsVoiceCallAvailabilityCnf = (CiPsPrimSetImsVoiceCallAvailabilityCnf *)paras;
			if(setImsVoiceCallAvailabilityCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				checkPSRet(reqHandle, setImsVoiceCallAvailabilityCnf->rc);
			}

			break;
		}
		case CI_PS_PRIM_GET_IMS_VOICE_CALL_AVAILABILITY_CNF:
		{
			getImsVoiceCallAvailabilityCnf = (CiPsPrimGetImsVoiceCallAvailabilityCnf *)paras;
			if(getImsVoiceCallAvailabilityCnf->rc == CIRC_PS_SUCCESS)
			{
				sprintf ( (char *)AtRspBuf,"+CAVIMS: %d",getImsVoiceCallAvailabilityCnf->state);
				ATRESP(reqHandle, ATCI_RESULT_CODE_OK,0,(char *)AtRspBuf);
			}
			else
			{
				checkPSRet(reqHandle, getImsVoiceCallAvailabilityCnf->rc);
			}
			break;
		}
		case CI_PS_PRIM_SET_IMS_SMS_AVAILABILITY_CNF:
		{
			setImsSmsAvailabilityCnf = (CiPsPrimSetImsSmsAvailabilityCnf *)paras;
			if(setImsSmsAvailabilityCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				checkPSRet(reqHandle, setImsSmsAvailabilityCnf->rc);
			}

			break;
		}
		case CI_PS_PRIM_GET_IMS_SMS_AVAILABILITY_CNF:
		{
			getImsSmsAvailabilityCnf = (CiPsPrimGetImsSmsAvailabilityCnf *)paras;
			if(getImsSmsAvailabilityCnf->rc == CIRC_PS_SUCCESS)
			{
				sprintf ( (char *)AtRspBuf,"+CASIMS: %d",getImsSmsAvailabilityCnf->state);
				ATRESP(reqHandle, ATCI_RESULT_CODE_OK,0,(char *)AtRspBuf);
			}
			else
			{
				checkPSRet(reqHandle, getImsSmsAvailabilityCnf->rc);
			}
			break;
		}
#endif
#endif

#ifdef VOLTE_ENABLE		
		case CI_PS_PRIM_SET_MM_IMS_VOICE_TERMINATION_CNF:
		{
			setMmImsVoiceTerminationCnf = (CiPsPrimSetMmImsVoiceTerminationCnf *)paras;
			if(setMmImsVoiceTerminationCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				checkPSRet(reqHandle, setMmImsVoiceTerminationCnf->rc);
			}

			break;
		}
		case CI_PS_PRIM_GET_MM_IMS_VOICE_TERMINATION_CNF:
		{
			getMmImsVoiceTerminationCnf = (CiPsPrimGetMmImsVoiceTerminationCnf *)paras;
			if(getMmImsVoiceTerminationCnf->rc == CIRC_PS_SUCCESS)
			{
				sprintf ( (char *)AtRspBuf,"+CMMIVT: %d",getMmImsVoiceTerminationCnf->setting);
				ATRESP(reqHandle, ATCI_RESULT_CODE_OK,0,(char *)AtRspBuf);
			}
			else
			{
				checkPSRet(reqHandle, getMmImsVoiceTerminationCnf->rc);
			}
			break;
		}
#endif
		case CI_PS_PRIM_SET_PSM_CONFIG_CNF:
		{
			setPsmConfigCnf = (CiPsPrimSetPsmConfigCnf *)paras;
			if(setPsmConfigCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				checkPSRet(reqHandle, setPsmConfigCnf->rc);
			}
			break;
		}
		case CI_PS_PRIM_GET_PSM_CONFIG_CNF:
		{
			processGetPsmConfigConf(reqHandle, paras);
			break;
		}
#ifndef MORE_ATC_SPACE_OPT
		case CI_PS_PRIM_SET_EDRX_CONFIG_CNF:
		{
			setEdrxConfigCnf = (CiPsPrimSetEdrxConfigCnf *)paras;
			if(setEdrxConfigCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				checkPSRet(reqHandle, setEdrxConfigCnf->rc);
			}
			break;
		}

		case CI_PS_PRIM_GET_EDRX_CONFIG_CNF:
		{
			processGetEdrxConfigConf(reqHandle, paras);
			break;
		}

		case CI_PS_PRIM_READ_EDRX_DYN_PARA_CNF:
		{
			processReadEdrxDynParaConf(reqHandle, paras);
			break;
		}

		case CI_PS_PRIM_SET_CIOT_CONFIG_CNF:
		{
			setCiotConfigCnf = (CiPsPrimSetCiotConfigCnf *)paras;
			if(setCiotConfigCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				checkPSRet(reqHandle, setCiotConfigCnf->rc);
			}

			break;
		}
		case CI_PS_PRIM_GET_CIOT_CONFIG_CNF:
		{
			getCiotConfigCnf = (CiPsPrimGetCiotConfigCnf *)paras;
			if(getCiotConfigCnf->rc == CIRC_PS_SUCCESS)
			{
				sprintf ( (char *)AtRspBuf,"+CCIOTOPT: %d,%d,%d",getCiotConfigCnf->option,getCiotConfigCnf->supportedUeOpt,getCiotConfigCnf->preferUeOpt);
				ATRESP(reqHandle, ATCI_RESULT_CODE_OK,0,(char *)AtRspBuf);
			}
			else
			{
				checkPSRet(reqHandle, setCiotConfigCnf->rc);
			}

			break;
		}
		case CI_PS_PRIM_CONFIG_SIGNALLING_CONNECTION_CNF:
		{
			configSignallingConnectionCnf = (CiPsPrimConfigSignallingConnectionCnf *)paras;
			if(configSignallingConnectionCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				checkPSRet(reqHandle, configSignallingConnectionCnf->rc);
			}

			break;
		}

		case CI_PS_PRIM_GET_SIGNALLING_CONNECTION_STATUS_CNF:
		{
			processGetSignallingConnectionStatusConf(reqHandle, paras);
			break;
		}

		case CI_PS_PRIM_SET_INITIAL_PDP_ACTIVATION_OPT_CNF:
		{
			setInitialPdpActivationOptCnf = (CiPsPrimSetInitialPdpActivationOptCnf *)paras;
			if(setInitialPdpActivationOptCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				checkPSRet(reqHandle, setInitialPdpActivationOptCnf->rc);
			}

			break;
		}

		case CI_PS_PRIM_GET_INITIAL_PDP_ACTIVATION_OPT_CNF:
		{
			processGetInitialPdpActivationOptCnf(reqHandle, paras);
			break;
		}

		case CI_PS_PRIM_SET_APN_BACKOFF_TIMER_STATUS_CNF:
		{
			setApnBackoffTimerStatusCnf	= (CiPsPrimSetApnBackoffTimerStatusCnf *)paras;
			if(setApnBackoffTimerStatusCnf->rc == CIRC_PS_SUCCESS)
			{
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else
			{
				checkPSRet(reqHandle, setApnBackoffTimerStatusCnf->rc);
			}

			break;
		}

		case CI_PS_PRIM_GET_APN_BACKOFF_TIMER_STATUS_CNF:
		{

			getApnBackoffTimerStatusCnf	= (CiPsPrimGetApnBackoffTimerStatusCnf *)paras;
			if(getApnBackoffTimerStatusCnf->rc == CIRC_PS_SUCCESS)
			{

				sprintf(AtRspBuf, "+CABTSR: %d", getApnBackoffTimerStatusCnf->option);
				ATRESP( reqHandle, ATCI_RESULT_CODE_OK, 0, AtRspBuf);
			}
			else
			{
				checkPSRet(reqHandle, getApnBackoffTimerStatusCnf->rc);
			}

			break;
		}

		case CI_PS_PRIM_READ_APN_BACKOFF_TIMER_DYN_PARA_CNF:
		{
			processReadApnBackoffTimerDynParaConf(reqHandle, paras);
			break;
		}

		case CI_PS_PRIM_GET_APN_RATE_CONTROL_CNF:
		{
			processGetApnRateControlCnf(reqHandle, paras);
			break;
		}
#endif	

		default:
			ERRMSG("Unknown primId:%d in psCnf \n", primId);

			break;
	}

end:

    utlFree(AtRspBuf);

    utlFree(TempBuf);
	/* free up the confirmation memory */
	atciSvgFreeCnfMem( svgId, primId, paras );

	return;
}

#ifdef LWIP_IPNETBUF_SUPPORT
void updateNwRegInd(UINT32 atHandle, void *paras, BOOL isLTE)
{
	BOOL RoamingStatusChanged = FALSE;
	OSA_STATUS osa_status;
	CMMsg rsp_msg;
	UINT8 *pRoaming, curReady, lastReady;

	//ATDBGMSG("%s: reqHandle %x", __func__, atHandle);
	if (isLTE)
	{
		CiPsPrim4GNwRegInd *nwRegInd = (CiPsPrim4GNwRegInd *)paras;
		lastReady = getCeregReady(atHandle);
		updateCeregStatus(atHandle, nwRegInd->nwRegInfo.status);
		curReady = getCeregReady(atHandle);
		updatePs4GRegDetail(atHandle, &(nwRegInd->nwRegInfo));

		if (nwRegInd->nwRegInfo.tacPresent)
			updateSysMode(atHandle, nwRegInd->nwRegInfo.act, nwRegInd->nwRegInfo.status);
		else
			updateSysMode(atHandle, CI_MM_NUM_ACT, nwRegInd->nwRegInfo.status);

#ifdef CRANE_MCU_DONGLE
		updateNwSwitchState(atHandle, lastReady, curReady);
#endif
		if(updateRAU(atHandle, (CiPsNwRegInfo *)(&(nwRegInd->nwRegInfo))))
		{
			//send RAU reset redial times for TELCEL carrier
			CPUartLogPrintf("%s: LAC or RAC changed", __func__);
			if (isHandleForMasterSim(atHandle))
				reset_redial_times_cm();
		}

	}
#ifndef LTEONLY_THIN
	else
	{
		CiPsPrimNwRegInd *nwRegInd = (CiPsPrimNwRegInd *)paras;
		lastReady = getCgregReady(atHandle);
		updateCgregStatus(atHandle, nwRegInd->nwRegInfo.status);
		curReady = getCgregReady(atHandle);
		updatePsRegDetail(atHandle, &(nwRegInd->nwRegInfo));

		if (nwRegInd->nwRegInfo.lacPresent)
			updateSysMode(atHandle, nwRegInd->nwRegInfo.act, nwRegInd->nwRegInfo.status);
		else
			updateSysMode(atHandle, CI_MM_NUM_ACT, nwRegInd->nwRegInfo.status);

#ifdef CRANE_MCU_DONGLE
		updateNwSwitchState(atHandle, lastReady, curReady);
#endif
		if(updateRAU(atHandle, &(nwRegInd->nwRegInfo)))
		{
			//send RAU reset redial times for TELCEL carrier
			CPUartLogPrintf("%s: LAC or RAC changed", __func__);
			if (isHandleForMasterSim(atHandle))
				reset_redial_times_cm();
		}
	}
#endif

    pRoaming = getRoamingStatusP(atHandle);
    if((0 == *pRoaming) && (get_current_reg_status(atHandle) == CIMM_REGSTATUS_ROAMING))
    {
    	updateRoamingStatus(atHandle, 1);
        RoamingStatusChanged = TRUE;
    }
    else if((1 == *pRoaming) && (get_current_reg_status(atHandle) != CIMM_REGSTATUS_ROAMING))
    {
    	updateRoamingStatus(atHandle, 0);
        RoamingStatusChanged = TRUE;
    }

    if(RoamingStatusChanged)
    {
        if (gCMMsgQ == NULL)
		    return;
		    
    	if (!isHandleForMasterSim(atHandle))
		return;
		
        rsp_msg.MsgData = pRoaming;
        rsp_msg.MsgID = RoamStart;
	 rsp_msg.tick = OSAGetTicks();

        CPUartLogPrintf("%s: send RoamStart msg, CurrentRoamingStatus is %d", __func__, *pRoaming);
        osa_status = OSAMsgQSend(gCMMsgQ, sizeof(rsp_msg), (UINT8 *)&rsp_msg, OSA_NO_SUSPEND);
        ASSERT(osa_status == OS_SUCCESS);
    }

}

void sendQueryCgdcont(UINT32 reqHandle)
{
#if QUEC_DUAL_SIM_DATA_SERVICE_SUPPORT
	if (getDualSimType() == CM_DUAL_SIM_SINGLE_STANDBY)
	{
		if (isMasterSim0() && isHandleForSim0(reqHandle))
			sendEventToHandler(QUERY_CGDCONT, NULL);
		else if (!isMasterSim0() && !isHandleForSim0(reqHandle))
			sendEventToHandler(QUERY_CGDCONT_1, NULL);
	}
	else
	{
		if (isHandleForSim0(reqHandle))
			sendEventToHandler(QUERY_CGDCONT, NULL);
		else if (!isHandleForSim0(reqHandle))
			sendEventToHandler(QUERY_CGDCONT_1, NULL);
	}
#else
	if (isMasterSim0() && isHandleForSim0(reqHandle))
		sendEventToHandler(QUERY_CGDCONT, NULL);
	else if (!isMasterSim0() && !isHandleForSim0(reqHandle))
		sendEventToHandler(QUERY_CGDCONT_1, NULL);
#endif
}

void mtDataLinkAllowCheck(UINT32 atHandle, UINT8 cid, UINT8 bearType)
{
	/*1. only MT PDP*/
	/*2.  is Dongle*/

	//ATDBGMSG("%s: project type %d, connect mode %d,  isDataLinkAllow %d", __func__,
	//					PlatformGetProjectType(), getConnectMode(), IsDatalinkAllowed());

#ifdef ATCMD_PDP_CONTEXT
	goto linkAllow;
#else

	if (PlatformGetProjectType() == NEZHA_PCIE_DGLE)
	{
		goto linkAllow;
	}
	/*3. data link allow in manual mode*/
	else if ((getConnectMode() == CONNECT_MODE_MANUAL))
	{
		goto linkAllow;
	}
	/*4. data link allow in auto mode*/
	else if ((getConnectMode() == CONNECT_MODE_AUTO) && (IsDatalinkAllowed() == TRUE))
	{
		goto linkAllow;
	}
	else if (is_E20_module_type())
	{
		/*just sent PDP context to CM, cm will record context but not configure netif in this project*/
		goto linkAllow;
	}
	/*5. bip enabled */
	else if (GetBIPEnableFlag())
	{
		/* for bip enabeld, cm should record the contexxt and configure default netif*/
		goto linkAllow;
	}
	else
		return;
#endif
linkAllow:
		sendQueryCgdcont(atHandle);
	if (bearType == CI_PS_SECONDARY_PDP)
		updateMTPdpTft(atHandle, CI_PS_PDP_MODIFY_TFT);

#ifndef NO_DIALER
    if (isMtPdp(cid))
	    updateMTPdpTimeConnect(atHandle, cid);
#endif
}

BOOL isHandleForSim0(UINT32 reqHandle)
{
	if (reqHandle == IND_REQ_HANDLE ||(reqHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(reqHandle)))
		return TRUE;
	else
		return FALSE;
}

void updateMTPdpTft(UINT32 reqHandle, UINT8 changeReason)
{
	OSA_STATUS osa_status;
	CHAR *pBuf;

	if((changeReason == CI_PS_PDP_MODIFY_TFT) || (changeReason == CI_PS_PDP_MODIFY_QOS_AND_TFT))
	{
		CPUartLogPrintf("updateMTPdpTft: MT Modify PDP update TFT: change_reason is %d", changeReason);

		pBuf = malloc(strlen("AT+CGTFT?\r\n")+1);
		ASSERT(pBuf != NULL);

		memset(pBuf, 0, strlen("AT+CGTFT?\r\n")+1);
		sprintf(pBuf, "AT+CGTFT?\r\n");

		//CPUartLogPrintf("%s:send %s to event Handler", __func__, pBuf);
		if (isHandleForSim0(reqHandle) )
			sendEventToHandler(SEND_AT, pBuf);
		else
			sendEventToHandler(SEND_AT_1, pBuf);
	}
}

void sendRedialToCm(UINT32 atHandle)
{
	OSA_STATUS osa_status;
	CMMsg msg;
	UINT16 pdpCause = getUnknownPdpCause(atHandle);

	if (gCMMsgQ == NULL)
	    return;
	    
	if (!isHandleForMasterSim(atHandle))
		return;
	
	if(pdpCause == CIRC_PS_APN || pdpCause == CIRC_PS_USER_AUTH_FAIL || pdpCause == CIRC_PS_SRVOPT_NOT_SUPPORTED
		|| pdpCause == CIRC_PS_SRVOPT_NOT_SUBSCRIBED || CIRC_PS_SRVOPT_NOT_SUBSCRIBED == CIRC_PS_SRVOPT_TEMP_OUT_OF_ORDER)
	{

		msg.MsgData= NULL;
		msg.MsgID = DialerReStart;
		msg.tick = OSAGetTicks();

		osa_status = OSAMsgQSend(gCMMsgQ, sizeof(msg), (UINT8 *)&msg, OSA_NO_SUSPEND);
		ASSERT(osa_status == OS_SUCCESS);

		//setErrorIndFlag(atHandle);
	}
}
#endif


/***************************************************************
 * F@: processApnBackoffTimerStatusReportInd - Process CI ind msg of  +CABTSRI
 */
static void processApnBackoffTimerStatusReportInd(UINT32 reqHandle, const void *pParam)
{
   	CiPsPrimApnBackoffTimerStatusReportInd *apnBackoffTimerStatusReportInd = (CiPsPrimApnBackoffTimerStatusReportInd *)pParam;
	char psIndBuf[100]="\0";
	char tempBuf[100]="\0";


	memcpy( tempBuf, apnBackoffTimerStatusReportInd->apn.valStr, apnBackoffTimerStatusReportInd->apn.len);
	tempBuf[apnBackoffTimerStatusReportInd->apn.len]='\0';

	sprintf( psIndBuf, "+CABTSRI:\"%s\",%d,%d",tempBuf,apnBackoffTimerStatusReportInd->eventType,apnBackoffTimerStatusReportInd->backoffTimerValue);

	if(apnBackoffTimerStatusReportInd->reAttempPresent== TRUE)
	{

		sprintf(tempBuf, ",%d,%d",apnBackoffTimerStatusReportInd->reAttemptRatIndication,apnBackoffTimerStatusReportInd->reAttemptEplmnIndication);
		strcat((char *)psIndBuf,(char *)tempBuf);
	}

	if(apnBackoffTimerStatusReportInd->nslpiPresent == TRUE)
	{
		if(apnBackoffTimerStatusReportInd->reAttempPresent== FALSE)
		{
			strcat((char *)psIndBuf,",,");
		}

		sprintf(tempBuf, ",%d",apnBackoffTimerStatusReportInd->nslpi);
		strcat((char *)psIndBuf,(char *)tempBuf);
	}


	ATRESP( reqHandle, 0, 0, psIndBuf );
	return;
}

#ifdef LWIP_IPNETBUF_SUPPORT
BOOL getErrorIndFlag(int atHandle, UINT8 cid)
{
	BOOL *pErrorIndFlag = NULL;
#ifndef SINGLE_SIM	
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))) {
		pErrorIndFlag = ErrorIndFlag;
	} else {
		pErrorIndFlag = ErrorIndFlag_1;
	}
#else
	pErrorIndFlag = ErrorIndFlag;
#endif

    return pErrorIndFlag[cid];
}

void setErrorIndFlag(int atHandle, INT8 cid)
{
	BOOL *pErrorIndFlag = NULL;
#ifndef SINGLE_SIM	
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))) {
		pErrorIndFlag = ErrorIndFlag;
	} else {
		pErrorIndFlag = ErrorIndFlag_1;
	}
#else
	pErrorIndFlag = ErrorIndFlag;
#endif


	UINT16 pdpCause = getUnknownPdpCause(atHandle);

	if(pdpCause == CIRC_PS_APN || pdpCause == CIRC_PS_USER_AUTH_FAIL || pdpCause == CIRC_PS_SRVOPT_NOT_SUPPORTED
		|| pdpCause == CIRC_PS_SRVOPT_NOT_SUBSCRIBED || pdpCause == CIRC_PS_SRVOPT_TEMP_OUT_OF_ORDER)
	{
		pErrorIndFlag[cid] = TRUE;
	}
}

void clearErrorIndFlag(int atHandle, UINT8 cid)
{
	BOOL *pErrorIndFlag = NULL;
#ifndef SINGLE_SIM	
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))) {
		pErrorIndFlag = ErrorIndFlag;
	} else {
		pErrorIndFlag = ErrorIndFlag_1;
	}
#else
	pErrorIndFlag = ErrorIndFlag;
#endif

	pErrorIndFlag[cid] = FALSE;
}

void clearErrorIndFlagAll(int atHandle)
{
	BOOL *pErrorIndFlag = NULL;
#ifndef SINGLE_SIM		
	if (atHandle == IND_REQ_HANDLE ||(atHandle > IND_REQ_HANDLE_1 && !GET_SIM1_FLAG(atHandle))) {
		pErrorIndFlag = ErrorIndFlag;
	} else {
		pErrorIndFlag = ErrorIndFlag_1;
	}
#else
	pErrorIndFlag = ErrorIndFlag;
#endif

	memset(pErrorIndFlag, 0, sizeof(ErrorIndFlag));
}

#endif

/************************************************************************************
 *
 * PS CI notifications
 *
 *************************************************************************************/

static INT8 SIMInPS = -1;
INT8 getSimIdForPS(void)
{
	INT8 simId = 0;
	
	#ifdef LWIP_IPNETBUF_SUPPORT
	simId=isMasterSim0() ? 0 : 1;	
	#else
	UINT32 cpsr;
	cpsr = disableInterrupts();
	simId=(SIMInPS == -1)? 0 : SIMInPS;
	restoreInterrupts(cpsr);
	#endif
	return simId;
}

extern Boolean sacPsIsDualLteMode(void);

void setSimIdForPS(INT8 simID)
{
	#ifndef LWIP_IPNETBUF_SUPPORT
	UINT32 cpsr;

	cpsr = disableInterrupts();
	if(AC_IS_CPONLY && (sacPsIsDualLteMode() == TRUE))
	{
		if(SIMInPS == -1)
			SIMInPS=simID;
	}
	else
	{
		SIMInPS=simID;
	}

	restoreInterrupts(cpsr);
	#endif
	return ;
}
/***************************************************************
 * F@: processSignallingConnectionInd - Process CI ind msg of  +CSCON
 */
static void processSignallingConnectionInd(UINT32 reqHandle, const void *pParam)
{
       CiPsPrimSignallingConnectionInd *signallingConnectionInd = (CiPsPrimSignallingConnectionInd *)pParam;
    char psIndBuf[100]="\0";
    char tempBuf[50]="\0";
    UINT8 currSignalConnetcionOption;

    if (reqHandle == IND_REQ_HANDLE) {
        currSignalConnetcionOption = gCurrSignalConnetcionOption;
    } else {
        currSignalConnetcionOption = gCurrSignalConnetcionOption_1;
    }

    switch ( currSignalConnetcionOption )
    {
        case CIPS_CSCON_DISABLE:
            /* Nothing to show */
            break;

        case CIPS_CSCON_ENABLE_MODE:
        {
            sprintf(psIndBuf, "+CSCON:%d", signallingConnectionInd->mode);
            ATRESP( reqHandle,0,0,psIndBuf);
            break;
        }
        case CIPS_CSCON_ENABLE_STATE:
        {
            sprintf(psIndBuf, "+CSCON: %d", signallingConnectionInd->mode);

            if(signallingConnectionInd->statePresent == TRUE)
            {
                sprintf(tempBuf, ",%d", signallingConnectionInd->state);
            }
            strcat((char *)psIndBuf,(char *)tempBuf);

            ATRESP( reqHandle,0,0,psIndBuf);
            break;
        }
        case CIPS_CSCON_ENABLE_ACCESS:
        {
            sprintf(psIndBuf, "+CSCON:%d", signallingConnectionInd->mode);
			
			#ifdef QUECTEL_NETWORK_SUPPORT
				quec_set_rrc_state(signallingConnectionInd->mode);
			#endif

            if(signallingConnectionInd->statePresent == TRUE)
            {
                sprintf(tempBuf, ",%d", signallingConnectionInd->state);
            }
            strcat((char *)psIndBuf,(char *)tempBuf);

            if(signallingConnectionInd->accessPresent== TRUE)
            {
                if(signallingConnectionInd->statePresent == FALSE)
                {
                    sprintf(tempBuf, ",");
                    strcat((char *)psIndBuf,(char *)tempBuf);
                }

                sprintf(tempBuf, ",%d",signallingConnectionInd->access);
                strcat((char *)psIndBuf,(char *)tempBuf);
            }

            ATRESP( reqHandle,0,0,psIndBuf);
            break;
        }
        default:
            break;

    }

    return;
}

#ifdef QUEC_ASR_ATCMD_PAGING_UPDATE_SUPPORT
extern quec_sem_t        quec_pg_kalive_netif_notify_sem;
#endif
void psInd(CiSgOpaqueHandle    opSgOpaqueHandle,
		CiServiceGroupID    svgId,
		CiPrimitiveID       primId,
		CiIndicationHandle  indHandle,
		void*               pParam)
{
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem

	UNUSEDPARAM(opSgOpaqueHandle)
	UNUSEDPARAM(indHandle)
	F_ENTER();

	DBGMSG("psInd:primId=%d\n", primId);
	//[klockwork][issue id: 2293]
	UINT8 add_len = 0;
	UINT16 add_data=0;
	CiPsPrimPdpCtxDeactedInd  *pdpCtxDeactedInd=NULL;
	CiPsPrimNwRegInd    *nwRegInd=NULL;
	CiPsPrim4GNwRegInd	*nw4gRegInd=NULL;
	/* Added by Daniel for LTE PC AT command server 20120117, begin */
	CiPsPrimMtPdpCtxActedInd  *MtPdpCtxActedInd=NULL;
	CiPsPrimMtPdpCtxActModifyInd	*MtPdpCtxActModifyInd=NULL;
	CiPsPrimDetachedInd             *detachInd=NULL;
	CiPsPrimDetachedInd             *detachedInd;
    /* Added by Daniel for LTE PC AT command server 20120117, end */
	CiPsPrimImsRegInfoInd *imsRegInfoInd=NULL;
	CiPsPrimUeEventToImsInd *ueEventToImsInd=NULL;
	CiPsPrimPdpActivationRejectCauseInd *pdpActivationRejectCauseInd;

	UINT32 reqHandle;
	int *pCurrentPSRegOption, *p4gCurrentPSRegOption;
	int *pCurrentPSRegStatus;
	int *pPsActDetail;
	AtciCurrentSetCntx *p_cInfo;
	int *p4gCurrentPSRegStatus;
	BOOL *pImsRegState;
	UINT8 pdp_table_index;
	int idx = IMS_FLAG; 
	#ifndef PLATFORM_FOR_PS_LW
	int simcardNum = 0;
	#endif
#ifdef QUECTEL_NETWORK_SUPPORT
    UINT8 reg_status=0;
    char resBuf[300] = {0};
    QuecOSStatus err = kNoErr;
	UINT8 value_change_flag=0;
	UINT8 net_status=0;
    bool temp = FALSE;
#endif
#ifdef QUECTEL_AT_QINDCFG_SUPPORT //connor 2019/01/21 add the qindcfg="act"
	char rat_string_buf[20]={0};
	char resp_buf[50]={0};
#endif
#ifdef QUEC_PATCH_1803S_FPLMN_66302
#ifdef QUEC_UESTAT_SUPPORT
extern void quec_set_uestat_limit(BOOL set_limit);
extern BOOL quec_get_uestat_enable(void);
#endif
#endif
#ifdef QUEC_AUTOAPN_ADJUST_SUPPORT	
	int autoapn_msg;
#endif
#if defined QUEC_CODECHECK_MODIFICATION_ASR
	if (NULL == pParam)
	{
		Quec_NetInfo_log("pParam is NULL!!!");
		return;
	}
#endif
#ifndef SINGLE_SIM	
	if (!GET_SIM1_FLAG(indHandle)) {
		#ifndef PLATFORM_FOR_PS_LW
		DIAG_FILTER(PCAC, ATCMDSrv, ParseIPAddr23_jyz, DIAG_INFORMATION)
		diagPrintf("sim 1 psind");
		simcardNum = 1;
		#endif

		reqHandle = IND_REQ_HANDLE;
		#ifndef LTEONLY_THIN
        pCurrentPSRegOption = &gCurrentPSRegOption[idx];
		#endif
		pCurrentPSRegStatus = &gCurrentPSRegStatus;
		pPsActDetail = &gPsActDetail;
		p_cInfo = gCIDList.cInfo;
		p4gCurrentPSRegStatus = &g4gCurrentPSRegStatus;
		p4gCurrentPSRegOption = &g4gCurrentPSRegOption[idx];
		pImsRegState = &gImsRegState;
	} else {
		#ifndef PLATFORM_FOR_PS_LW
		DIAG_FILTER(PCAC, ATCMDSrv, ParseIPAddr23_jyz1, DIAG_INFORMATION)
		diagPrintf("sim 2 psind");

		simcardNum = 2;
		#endif
		reqHandle = IND_REQ_HANDLE_1;
		#ifndef LTEONLY_THIN
		pCurrentPSRegOption = &gCurrentPSRegOption_1[idx];
		#endif
			pCurrentPSRegStatus = &gCurrentPSRegStatus_1;
			pPsActDetail = &gPsActDetail_1;
			p_cInfo = gCIDList.cInfo_1;
			p4gCurrentPSRegStatus = &g4gCurrentPSRegStatus_1;
			p4gCurrentPSRegOption = &g4gCurrentPSRegOption_1[idx];
			pImsRegState = &gImsRegState_1;
	}
#else
#ifndef PLATFORM_FOR_PS_LW
	DIAG_FILTER(PCAC, ATCMDSrv, ParseIPAddr23_jyz, DIAG_INFORMATION)
	diagPrintf("sim 1 psind");
	simcardNum = 1;
#endif

	reqHandle = IND_REQ_HANDLE;
	#ifndef LTEONLY_THIN
	pCurrentPSRegOption = &gCurrentPSRegOption[idx];
	#endif
	pCurrentPSRegStatus = &gCurrentPSRegStatus;
	pPsActDetail = &gPsActDetail;
	p_cInfo = gCIDList.cInfo;
	p4gCurrentPSRegStatus = &g4gCurrentPSRegStatus;
	p4gCurrentPSRegOption = &g4gCurrentPSRegOption[idx];
	pImsRegState = &gImsRegState;
	
	
#endif /*LTEONLY_THIN_SINGLE_SIM*/

	extern void ModemCiPrimitiveIndFileter(CiServiceGroupID id,CiPrimitiveID primId, CiIndicationHandle indHandle, void* paras);
	ModemCiPrimitiveIndFileter(svgId,primId,indHandle,pParam);
	#ifdef QUECTEL_AT_QINDCFG_SUPPORT //connor 2018/11/23 add the asr DATASTATUS urc report control
		Quec_NetInfo_log("psind=%d",primId);
	#endif
	switch(primId)
	{
		case CI_PS_PRIM_PDP_CTX_DEACTED_IND:
		{
			//[klockwork][issue id: 2296]
			char atBuf[200] = {0};
			char tmpBuf[50] = {0};

			int i;
			pdpCtxDeactedInd = (CiPsPrimPdpCtxDeactedInd *)pParam;
#ifdef QUECTEL_AT_COMMAND
			memset(atBuf, 0, sizeof(atBuf));
			memset(tmpBuf, 0, sizeof(tmpBuf));
#endif

			pdp_table_index = getPdpIndexByCid(pdpCtxDeactedInd->indedPdpCtx.cid,p_cInfo);
			telPsPdpCtx *psPdpInfo =  telGetPdpCtx(pdpCtxDeactedInd->indedPdpCtx.cid);
			
			if(pdp_table_index >= CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
				break;

            if(psPdpInfo != NULL)
			    psPdpInfo->activedStatus = 0;

			if(1/*(*pPsActDetail == 7) || (*pPsActDetail == 9)*/)
	        {
				//[klocwork][issue id: 2275]
				//if(pdpCtxDeactedInd->indedPdpCtx.p_cid < CI_PS_MAX_CID)
				if((pdpCtxDeactedInd->indedPdpCtx.pdpBearType == CI_PS_DEDICATED_PDP)
					&& (pdpCtxDeactedInd->indedPdpCtx.p_cid < CI_PS_MAX_CID)
					&& (pdpCtxDeactedInd->indedPdpCtx.cid < CI_PS_MAX_CID))
				{
				    if(pdpCtxDeactedInd->isMEInitiated == FALSE)
	                {
	                    sprintf(atBuf, "+CGEV: NW DEACT ");
	                }
	                else
	                {
	                    sprintf(atBuf, "+CGEV: ME DEACT ");

	                }
					sprintf(tmpBuf, "%d,%d\r\n", pdpCtxDeactedInd->indedPdpCtx.p_cid + 1, pdpCtxDeactedInd->indedPdpCtx.cid + 1);
                    strcat(atBuf, tmpBuf);
#ifdef QUECTEL_NETWORK_SUPPORT
					quec_pdp_act_state[pdpCtxDeactedInd->indedPdpCtx.p_cid].pdp_act_status=0;
					quec_pdp_act_state[pdpCtxDeactedInd->indedPdpCtx.cid].pdp_act_status=0;
#endif
#if QUEC_NETINFO_REPORT_ENABLE
					do
					{
						pdp_act_status_t pdp_act_status = {0};
						
						pdp_act_status.op = PDP_OP_DACT;
						pdp_act_status.status = 1;
				
						pdp_act_status.pdp_cid = pdpCtxDeactedInd->indedPdpCtx.p_cid + 1;
						quec_event_notify_report(EVENT_NET_PDP_ACT, &pdp_act_status);
				
						quec_pdp_deatch_handler(pdp_act_status.pdp_cid);
					} while(0);
#endif
                    if(p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
                    {
                        reqHandle = p_cInfo[pdp_table_index].reqHandle;
                    }

                    //If the CID is already deleted, don't send +CGEV
#ifdef QUECTEL_NETWORK_SUPPORT
					if (p_cInfo[pdp_table_index].bDefined)
                    {
                        if (QUEC_IS_VALID_ATP(GET_ATP_INDEX(GET_AT_HANDLE(reqHandle))))
                        {
                            //nothing
                        }
                        else
                        {
                        	ATRESP(reqHandle, 0, 0, atBuf);
                        }
                    }
#else
					if (p_cInfo[pdp_table_index].bDefined)
                        ATRESP(reqHandle, 0, 0, atBuf);
#endif
	            }
				//[klockwork][issue id: 2275]
				//else if(pdpCtxDeactedInd->indedPdpCtx.cid < CI_PS_MAX_CID)
#ifndef QUECTEL_NETWORK_SUPPORT
				else if((pdpCtxDeactedInd->indedPdpCtx.pdpBearType == CI_PS_DEFAULT_PDP)
					&& (pdpCtxDeactedInd->indedPdpCtx.p_cid < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM))
#else
				else if((pdpCtxDeactedInd->indedPdpCtx.pdpBearType == CI_PS_DEFAULT_PDP)
					&& (pdpCtxDeactedInd->indedPdpCtx.cid < CI_PS_MAX_CID))
#endif
				{
				    if(pdpCtxDeactedInd->isMEInitiated == FALSE)
				    {
	                    sprintf(atBuf, "+CGEV: NW PDN DEACT ");

	                }
					else
					{
	                    sprintf(atBuf, "+CGEV: ME PDN DEACT ");
	                }
					sprintf(tmpBuf, "%d\r\n", pdpCtxDeactedInd->indedPdpCtx.cid + 1);
                    strcat(atBuf, tmpBuf);
					
#ifdef QUECTEL_NETWORK_SUPPORT
					quec_pdp_act_state[pdpCtxDeactedInd->indedPdpCtx.cid].pdp_act_status=0;
#endif
#if QUEC_NETINFO_REPORT_ENABLE
					do
					{
						pdp_act_status_t pdp_act_status = {0};
						
						pdp_act_status.op = PDP_OP_DACT;
						pdp_act_status.status = 1;
						pdp_act_status.pdp_cid = pdpCtxDeactedInd->indedPdpCtx.cid + 1;
						
						quec_event_notify_report(EVENT_NET_PDP_ACT, &pdp_act_status);
						quec_pdp_deatch_handler(pdp_act_status.pdp_cid);
					} while(0);
#endif
                    if(p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
                    {
                        reqHandle = p_cInfo[pdp_table_index].reqHandle;
                    }
                    
                    //If the CID is already deleted, don't send +CGEV
#ifdef QUECTEL_NETWORK_SUPPORT
					if (p_cInfo[pdp_table_index].bDefined)
                    {
                        if (QUEC_IS_VALID_ATP(GET_ATP_INDEX(GET_AT_HANDLE(reqHandle))))
                        {
                            //nothing
                        }
                        else
                        {
                        	ATRESP(reqHandle, 0, 0, atBuf);
                        }
                    }
#else
					if (p_cInfo[pdp_table_index].bDefined)
                        ATRESP(reqHandle, 0, 0, atBuf);
#endif
	            }
	        }
        	else
	        {
				//[klockwork][issue id: 2276]
	            //if(pdpCtxDeactedInd->indedPdpCtx.cid < CI_PS_MAX_CID)
				if(((pdpCtxDeactedInd->indedPdpCtx.pdpBearType == CI_PS_PRIMARY_PDP)
					||(pdpCtxDeactedInd->indedPdpCtx.pdpBearType == CI_PS_SECONDARY_PDP))
					&& (pdpCtxDeactedInd->indedPdpCtx.cid < CI_PS_MAX_CID))
				{
					if(pdpCtxDeactedInd->isMEInitiated == FALSE)
						sprintf(atBuf, "+CGEV: NW PDN DEACT ");
					else
						sprintf(atBuf, "+CGEV: ME PDN DEACT ");
					sprintf(tmpBuf, "%d\r\n", pdpCtxDeactedInd->indedPdpCtx.cid + 1);
					strcat(atBuf, tmpBuf);
#ifdef QUECTEL_NETWORK_SUPPORT
					quec_pdp_act_state[pdpCtxDeactedInd->indedPdpCtx.cid].pdp_act_status=0;
#endif
#if QUEC_NETINFO_REPORT_ENABLE
					do
					{
						pdp_act_status_t pdp_act_status = {0};
						
						pdp_act_status.op = PDP_OP_DACT;
						pdp_act_status.status = 1;
						pdp_act_status.pdp_cid = pdpCtxDeactedInd->indedPdpCtx.cid + 1;
						
						quec_event_notify_report(EVENT_NET_PDP_ACT, &pdp_act_status);
						quec_pdp_deatch_handler(pdp_act_status.pdp_cid);
					} while(0);
#endif
					if (p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
					{
						reqHandle = p_cInfo[pdp_table_index].reqHandle;
						p_cInfo[pdp_table_index].reqHandle=INVALID_REQ_HANDLE;
					}

					/*Fixed coverity[overrun-local]*/
					//If the CID is already deleted, don't send +CGEV
#ifdef QUECTEL_NETWORK_SUPPORT
					if (p_cInfo[pdp_table_index].bDefined)
                    {
                        if (QUEC_IS_VALID_ATP(GET_ATP_INDEX(GET_AT_HANDLE(reqHandle))))
                        {
                            //nothing
                        }
                        else
                        {
                        	ATRESP(reqHandle, 0, 0, atBuf);
                        }
                    }
#else
					if (p_cInfo[pdp_table_index].bDefined)
						ATRESP(reqHandle, 0, 0, atBuf);
#endif

				}

		   }
#ifdef QUEC_NETINFO_REPORT_ENABLE
			telSetPdpActivedFlag(pdpCtxDeactedInd->indedPdpCtx.cid, FALSE);	
#ifdef LWIP_IPNETBUF_SUPPORT
			/*remove the netif*/
			if (!CM_allowSetNetif())
			{
#ifdef QUEC_NETWORK_CARD_ENABLE
				Quec_NetInfo_log("asr origin,deact, delete netcard,cid=%d",pdpCtxDeactedInd->indedPdpCtx.cid + 1);
#endif
				//asr request,case:Bug #17185
				//20200702
				Quec_NetInfo_log("pdpBearType=%d",pdpCtxDeactedInd->indedPdpCtx.pdpBearType);
				if (pdpCtxDeactedInd->indedPdpCtx.pdpBearType == CI_PS_SECONDARY_PDP)
				{
					if(p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
                    {
                        reqHandle = p_cInfo[pdp_table_index].reqHandle;
                    }
				 	updateMTPdpTft(reqHandle,CI_PS_PDP_MODIFY_TFT);
				}
				else
				{
					#ifdef QUEC_3601_PDPDEACT_NETCARD_FAIL_26489
					#ifdef VOLTE_ENABLE
			    		if(is_ims_cid(GET_SIM1_FLAG(indHandle) ? SIM2 : SIM1, pdpCtxDeactedInd->indedPdpCtx.cid + 1, NULL) == 0)
			 		#endif
					{
					#if QUEC_DUAL_SIM_SUPPORT
                		configureLwipNetif(0xFF, pdpCtxDeactedInd->indedPdpCtx.cid | (isMasterSim0() ? 0x0 : (0x01 << 7)), 1);
					#else		
						configureLwipNetif(0xFF, pdpCtxDeactedInd->indedPdpCtx.cid, 1);	
					#endif
					}
					#else
						configureLwipNetif(0xFF, pdpCtxDeactedInd->indedPdpCtx.cid, 1);
					#endif
				}
			}
#endif
#endif
#ifdef QUECTEL_NETWORK_SUPPORT
			if(quectel_read_urc_ind_flag(QUECTEL_URC_ALL_IND))
			{
			#if QUEC_DUAL_SIM_SUPPORT
				if(cgerep_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].mode==1 ||
				   cgerep_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].mode==2)
			#else	
				if(cgerep_info.mode==1 ||cgerep_info.mode==2)//connor.wu 2018/11/15  when mode=1/2 open the Packet Domain Event Reporting
			#endif	
				(void)at_urc_send(NUM_OF_TEL_ATP, (uint8 *)atBuf, strlen(atBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
			}
#endif
#ifdef QUEC_NETWORK_CARD_ENABLE  //Chaim 2019.03.04 send network deactive indication
			if(quec_netcard_get_cid() == pdpCtxDeactedInd->indedPdpCtx.cid + 1)
			{
				Quec_NetInfo_log("netdevctl,deact,disconenct netcard,cid=%d",pdpCtxDeactedInd->indedPdpCtx.cid + 1);
				quec_netdevctl_set_auto_time_interval_default();
				quec_netdevctl_lwip_config(QUEC_NETIF_DISCONNECT, pdpCtxDeactedInd->indedPdpCtx.cid + 1);
				quec_netdevctl_urc_report(QUEC_NETDEVCTL_URC_TYPE_CLOSE); 
				quec_netdevctl_network_ind_msg_send(QUEC_NETDEVCTL_MSG_FROM_IND, QUEC_NETCARD_NETWORK_STATE_IND, (uint8 *)&primId, sizeof(primId));  //CI_PS_PRIM_PDP_CTX_DEACTED_IND
			}
#endif
#ifdef QUEC_NETDUALCH_CFG
            (void)quec_qnetdualchcfg_urc_report(QUEC_QNETDUALCHCFG_NETIF_BIND_URC,pdpCtxDeactedInd->indedPdpCtx.cid+1,FALSE);
#endif
#ifdef QUECTEL_PROJECT_CUST
			if(pdpCtxDeactedInd->indedPdpCtx.type ==CI_PS_PDP_TYPE_IPV6 || pdpCtxDeactedInd->indedPdpCtx.type ==CI_PS_PDP_TYPE_IPV4V6)
			{
                lwip_ip_configinfo info;
                memset(&info, 0, sizeof(info));
                info.cid =  MtPdpCtxActedInd->pdpCtx.cid;
                info.cid |= (simcardNum==2?1:0)<<7;
                info.status=0xFF;
                lwip_set_pdpinfo(&info);
			}
#endif

#if defined (__QUEC_OEM_VER_XGD__)
			if(QUEC_FIBO_GPRSREACT_MIN != quec_fibo_get_gprsreact_value())
			{
				char resp_buf[20]={0};
				Quec_NetInfo_log("fibo re-attach");
				SendATCMDWaitResp(TEL_AT_CMD_ATP_QUEC_INTERNAL, "AT+CGATT=1\r", 20, NULL, 1, NULL, resp_buf, sizeof(resp_buf));
			}
#endif
			DIAG_FILTER(PCAC, pdp_index, resetPdpInfo, DIAG_INFORMATION)
			diagPrintf("index is %d", pdp_table_index);
			resetPdpInfo(&p_cInfo[pdp_table_index]);
			break;
		}
#ifndef LTEONLY_THIN
		case CI_PS_PRIM_NW_REG_IND:
		{
			char atBuf[100] = {0};
			int i =0;

			nwRegInd = (CiPsPrimNwRegInd *)pParam;
			*pCurrentPSRegStatus = nwRegInd->nwRegInfo.status;
			#ifdef QUECTEL_OPEN_CPU
			if(!IsMiniSystem())
			{
				quec_nw_event_ind(reqHandle, pParam, QUEC_NW_EVENT_DATE_REG_STATUS_NO_LTE);
			}
			#endif
#ifdef LWIP_IPNETBUF_SUPPORT
			ATDBGMSG("CI_PS_PRIM_NW_REG_IND: lacPresent is %d", nwRegInd->nwRegInfo.lacPresent);
			updateNwRegInd(reqHandle, pParam, FALSE);
        	checkNWRegStatus(reqHandle);
#endif
#ifdef QUEC_ASR_ATCMD_PAGING_UPDATE_SUPPORT
		#if QUEC_DUAL_SIM_SUPPORT
			CiPsNwRegInfo *p_cgreg_info = &quec_cgreg_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)];
		#else
			CiPsNwRegInfo *p_cgreg_info = &quec_cgreg_info;
		#endif
			
            Quec_NetInfo_log("2g_3g old: tac %04X,cellid %04X---new:tac %04X,cellid %04X", p_cgreg_info->lac, p_cgreg_info->cellId, nwRegInd->nwRegInfo.lac,nwRegInd->nwRegInfo.cellId);
            if(nwRegInd->nwRegInfo.cellId != p_cgreg_info->cellId)
			{
				if(quec_pg_kalive_netif_notify_sem != NULL)
	            {
	                quec_rtos_semaphore_release(quec_pg_kalive_netif_notify_sem);
	            }			
			}

#endif
#ifdef QUECTEL_NETWORK_SUPPORT
	#ifdef __QUEC_OEM_VER_LD__
					char lac_buf[LANDI_VAL_BUF_MAX] = {0};
					char cid_buf[LANDI_VAL_BUF_MAX] = {0};
	#endif
					net_status=quec_regstatus_asr2quec(nwRegInd->nwRegInfo.status, 0);
                    UINT8 report_status = net_status;
                    if (6 == report_status)
                    {
                        report_status = 0;
                        if (1 != quec_creg_report_emergency)
                        {
                            net_status = 0;
                        }
                    }
				
	#ifdef QUECTEL_AT_QCFG_ACQDB_OPT_SUPPORT
					if(net_status ==1 || net_status == 5)
					{
						quec_update_earfcn_list(0);
					}
	#endif
				#if QUEC_DUAL_SIM_SUPPORT
					if(memcmp(&quec_cgreg_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)],&(nwRegInd->nwRegInfo),sizeof(CiPsNwRegInfo))!=0)
						value_change_flag=1;
					memcpy(&quec_cgreg_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)],&(nwRegInd->nwRegInfo) , sizeof(CiPsNwRegInfo));
				#else
					if(memcmp(&quec_cgreg_info,&(nwRegInd->nwRegInfo),sizeof(CiPsNwRegInfo))!=0)
						value_change_flag=1;
					memcpy(&quec_cgreg_info,&(nwRegInd->nwRegInfo) , sizeof(CiPsNwRegInfo));
				#endif	
#ifdef QUECTEL_AT_QINDCFG_SUPPORT //connor 2019/01/21 add the qindcfg="act"
					if( quectel_read_urc_ind_flag(QUECTEL_URC_ALL_IND) 
						&& quectel_read_urc_ind_flag(QUECTEL_URC_ACTCHGRPT_IND))
					{
						//connor.wu 2018/05/16 map asr act 8/9 to 6/7
						if(quec_ratchg_indication(0,quec_act_asr2quec(nwRegInd->nwRegInfo.act),net_status,rat_string_buf))
						{
							sprintf( resp_buf,"+QIND: \"act\",\"%s\"\r\n",rat_string_buf);
							if(strlen(resp_buf)!=0)
							{
								err = at_urc_send(NUM_OF_TEL_ATP, (uint8 *)resp_buf, strlen(resp_buf), TRUE, URC_OUT_METHOD_UNICAST, NULL);
								if (err != kNoErr)
								{
									Quec_NetInfo_log("at_urc_send failed");
								}
							}
						}
					}
#endif
					
					
	#if QUEC_NETINFO_REPORT_ENABLE
                    if (net_status == 1 || net_status == 5)
                    {
                        temp = TRUE;    
                    }
                    else
                    {
                        temp = FALSE;
                    }
					quec_event_notify_report(EVENT_NET_REGISTER, &temp);
	#endif
#if QUEC_CEER_ESM_REJECT_CAUSE_SUPPORT
                    extern void quec_set_clear_err_cause(void);
                    if(net_status ==1 || net_status == 5){
                        quec_set_clear_err_cause();
                    }
#endif
					quectel_current_config_value_get(AT_CGREG, (int *)&reg_status);
					Quec_NetInfo_log("2g_3g_status=%d,act=%d,gPSActDetail=%d,reg_status=%d",nwRegInd->nwRegInfo.status,nwRegInd->nwRegInfo.act,*pPsActDetail,reg_status);
					//if(value_change_flag==1 && cgreg_already_report_flag==0)
				#if QUEC_DUAL_SIM_SUPPORT
					if(value_change_flag==1 && quec_cereg_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].act != 7)
				#else
					if(value_change_flag==1 && quec_cereg_info.act !=7)
				#endif
					{
						if(reg_status==1)
						{
							sprintf( resBuf,"+CGREG: %d\r\n",report_status);
						}
						else if(reg_status==2)
						{	 
							if(nwRegInd->nwRegInfo.lacPresent &&(net_status == 1 || net_status == 5 || net_status == 6))
							{	 
								#ifdef __QUEC_OEM_VER_LD__  
								if (TRUE == Quectel_IsOEMLandiEnable())
								{
									GET_VALID_VAL(lac_buf, nwRegInd->nwRegInfo.lac);
									GET_VALID_VAL(cid_buf, nwRegInd->nwRegInfo.cellId);
									//connor.wu 2018/05/16 map asr act 8/9 to 6/7
									sprintf( resBuf,"+CGREG: %d,\"%s\",\"%s\",%d\r\n",report_status,lac_buf,cid_buf,quec_act_asr2quec(nwRegInd->nwRegInfo.act));
								}
								else
								#endif
								{
									//connor.wu 2018/05/16 map asr act 8/9 to 6/7
									sprintf( resBuf,"+CGREG: %d,\"%04X\",\"%04X\",%d\r\n",report_status,nwRegInd->nwRegInfo.lac,nwRegInd->nwRegInfo.cellId,quec_act_asr2quec(nwRegInd->nwRegInfo.act));
								}
							}
							else
							{
								Quec_NetInfo_log("LAC not present");
								sprintf( resBuf,"+CGREG: %d\r\n",report_status);
							}
						}
						if(strlen(resBuf)!=0 && quec_report_cgreg(resBuf,reqHandle)==1)
						{
                            quec_dual_nw_reoprt(resBuf,sizeof(resBuf), reqHandle);
                            #ifdef QUEC_URC_ORDER_FIX
                            err = at_urc_send(NUM_OF_TEL_ATP, (uint8 *)resBuf, strlen(resBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
                            #else
							err = at_urc_send(NUM_OF_TEL_ATP, (uint8 *)resBuf, strlen(resBuf), TRUE, URC_OUT_METHOD_UNICAST, NULL);
                            #endif
							if (err != kNoErr)
							{
								Quec_NetInfo_log("at_urc_send failed");
							}
						}
					}
					#if 0 //temporary modifaction so that the first beta firmware can be relesed. we need double check here later
					#if !QUEC_LTE_SUPPORT//connor.wu 2019/03/19 the LTE light is for 3g to use in 3g project        
					 //connor 2018/12/13 add the lte net light control
					if((net_status==1 || net_status==5) && quec_get_current_rat(1) == QUEC_NETMODE_WCDMA )
					{
						quec_netmodelight_switch(QUEC_NETMODELIGHT_LTE);
					}
					else
					{
						quec_netmodelight_switch(QUEC_NETMODELIGHT_OTHER);
					}
					#endif
					#endif
#endif

			#ifndef PLATFORM_FOR_PS_LW
			if((*pCurrentPSRegStatus == CI_PS_NW_REG_STA_REG_HPLMN)||(*pCurrentPSRegStatus == CI_PS_NW_REG_STA_REG_ROAMING))
			{
				if(AC_IS_CPONLY)
				{
					ASSERT((simcardNum == 1)||(simcardNum == 2));
					setSimIdForPS(simcardNum-1);
				}

			}
			#endif

			if ((nwRegInd->nwRegInfo.lacPresent == TRUE)&&((*pCurrentPSRegStatus==CI_PS_NW_REG_STA_REG_HPLMN)||(*pCurrentPSRegStatus==CI_PS_NW_REG_STA_REG_ROAMING)))
			{
				*pPsActDetail = nwRegInd->nwRegInfo.act;
			}
			DBGMSG("[%s]:line(%d), CI_PS_PRIM_NW_REG_IND received, regstatus: %d!\n", __FUNCTION__, __LINE__, nwRegInd->nwRegInfo.status);
            CPUartLogPrintf("%s:  CI_PS_PRIM_NW_REG_IND pCurrentPSRegOption is %d", __FUNCTION__,*pCurrentPSRegOption); 

            for(i = NONE_IMS_FLAG; i <= IMS_FLAG; i++)
            {
                idx = i;
                
				#ifndef SINGLE_SIM
	            	if (!GET_SIM1_FLAG(indHandle))
	            		pCurrentPSRegOption = &gCurrentPSRegOption[idx];
	            	else
	            		pCurrentPSRegOption = &gCurrentPSRegOption_1[idx];
				#else
					pCurrentPSRegOption = &gCurrentPSRegOption[idx];
				#endif      
                
			    /* show the registration status */
			    switch ( *pCurrentPSRegOption )
    			{
    				case CI_PS_NW_REG_IND_DISABLE:
    					/* Nothing to show */
    					break;

					case CI_PS_NW_REG_IND_ENABLE_STA_ONLY:

						sprintf(atBuf, "+CGREG: %d\r\n", nwRegInd->nwRegInfo.status);
						atRespStr_NW_REG(reqHandle,idx,atBuf);
						break;

    				case CI_PS_NW_REG_IND_ENABLE_DETAIL:
    				{
    					if (nwRegInd->nwRegInfo.lacPresent == TRUE)
    					{
    						*pPsActDetail = nwRegInd->nwRegInfo.act;

							sprintf( atBuf, "+CGREG: %d, \"%04x\",\"%08x\", %d\r\n", nwRegInd->nwRegInfo.status,
								 nwRegInd->nwRegInfo.lac,
								 nwRegInd->nwRegInfo.cellId,
								 *pPsActDetail);
							atRespStr_NW_REG(reqHandle,idx,atBuf);
						}
						else
						{
							sprintf(atBuf, "+CGREG: %d\r\n", nwRegInd->nwRegInfo.status);
							atRespStr_NW_REG(reqHandle,idx,atBuf);
						}

						break;
					}
					case CI_PS_NW_REG_IND_ENABLE_MORE_DETAIL:
					{
						if ((nwRegInd->nwRegInfo.lacPresent == TRUE)&&(nwRegInd->nwRegInfo.causePresent  == TRUE))
						{
							sprintf( atBuf, "+CGREG: %d, \"%04x\",\"%08x\", %d,%d,%d\r\n", nwRegInd->nwRegInfo.status,
								 nwRegInd->nwRegInfo.lac,
								 nwRegInd->nwRegInfo.cellId,
								 *pPsActDetail,
							     nwRegInd->nwRegInfo.causeType,
								 nwRegInd->nwRegInfo.rejectCause);
							atRespStr_NW_REG(reqHandle,idx,atBuf);
						}
						else
						{
							sprintf(atBuf, "+CGREG: %d\r\n", nwRegInd->nwRegInfo.status);
							atRespStr_NW_REG(reqHandle,idx,atBuf);
						}

						break;
					}
					default:
						break;
				}
            }
			
#ifdef QUEC_NETWORK_CARD_ENABLE  //Chaim 2019.03.04 send network deactive indication
		#ifdef QUECTEL_AT_QCFG_ROAMSERVICEEX
            /*isaac 20201228 support at+qcfg="roamserviceex",1 or 3 漫游下，不发绑定网卡消息*/
            if (TRUE == quectel_roam_disable_status_get_bit(0))
            {
                if(net_status ==1)
		        {
			        quec_netdevctl_network_ind_msg_send(QUEC_NETDEVCTL_MSG_FROM_IND, QUEC_NETCARD_NETWORK_STATE_IND, (uint8 *)&primId, sizeof(primId));  //CI_PS_PRIM_4G_NW_REG_IND
		        }
            }
            else 
            {
                if((net_status ==1) || (net_status==5))
		        {
			        quec_netdevctl_network_ind_msg_send(QUEC_NETDEVCTL_MSG_FROM_IND, QUEC_NETCARD_NETWORK_STATE_IND, (uint8 *)&primId, sizeof(primId));  //CI_PS_PRIM_4G_NW_REG_IND
		        }
            }
        #endif
#endif

#ifdef QUECTEL_AT_QCFG_ROAMSERVICEEX
            /* Isaac 20201228 support at+qcfg="roamserviceex",1 or 3 
             * bit0:disable the internet access(NIC dialing) ;bit1:disable voice call
             */
            if ( (TRUE == quec_is_roam_status()) && 
                 (TRUE == quectel_roam_disable_status_get_bit(0)) )
            {
                /*网络状态若变为漫游，解绑网卡*/
                CPUartLogPrintf("%s: line[%d]set roamserviceex is 1 or 3,disable netcard dial",__func__,__LINE__);
                if(0 != quec_netcard_get_cid())
                {
                    quec_netdevctl_lwip_config(QUEC_NETIF_DISCONNECT, quec_netcard_get_cid());
                }
            }
#endif
#ifdef QUEC_PATCH_1803S_FPLMN_66302
			if(((net_status == 1) || (net_status == 5)) && ((0x250 == nwRegInd->nwRegInfo.rplmnInfo.CountryCode) || (0x432 == nwRegInd->nwRegInfo.rplmnInfo.CountryCode)))
			{
#if QUEC_DUAL_SIM_SUPPORT
			    if (getDualSimType() == CM_DUAL_SIM_SINGLE_STANDBY)
			    {
			     	DEV_SetFunc(isMasterSim0() ? SIMULATE_SIM1_REQ_HANDLE : SIMULATE_SIM2_REQ_HANDLE, 4, 0, FALSE, 0, 0); 
			    }
			    else
			    {
			     	DEV_SetFunc(SIMULATE_SIM1_REQ_HANDLE, 4, 0, FALSE, 0, 0);
			     	DEV_SetFunc(SIMULATE_SIM2_REQ_HANDLE, 4, 0, FALSE, 0, 0);
			    }
#else 
			    DEV_SetFunc(reqHandle, 4, 0, FALSE, 0, 0);
#endif
				#ifdef QUEC_UESTAT_SUPPORT
				quec_set_uestat_limit(TRUE);
				if(quec_get_uestat_enable()==TRUE)
				{
                    err = at_urc_send(NUM_OF_TEL_ATP, (uint8 *)"+QUESTAT: 1,1", strlen("+QUESTAT: 1,1"), TRUE, URC_OUT_METHOD_UNICAST, NULL);
                    if (err != kNoErr)
                    {
                        Quec_NetInfo_log("at_urc_send failed");
                    }
				}
				#endif
			}
			#ifdef QUEC_UESTAT_SUPPORT
			else if((net_status == 1) || (net_status == 5))
			{
                quec_set_uestat_limit(FALSE);
			}
			#endif
#endif
			break;
		}
#endif /* LTEONLY_THIN */

		case CI_PS_PRIM_4G_NW_REG_IND:
		{
			char atBuf[200] = {0};
			char tmpBuf[50] = {0};
			nw4gRegInd = (CiPsPrim4GNwRegInd *)pParam;
			*p4gCurrentPSRegStatus = nw4gRegInd->nwRegInfo.status;
			int i =0;
			#ifdef QUECTEL_OPEN_CPU
			if(!IsMiniSystem())
			{
			quec_nw_event_ind(reqHandle, pParam, QUEC_NW_EVENT_DATE_REG_STATUS_LTE);
			}
			#endif
			#ifdef LWIP_IPNETBUF_SUPPORT
				updateNwRegInd(reqHandle, pParam, TRUE);
	        	checkNWRegStatus(reqHandle);
			#endif
		#ifdef QUEC_ASR_ATCMD_PAGING_UPDATE_SUPPORT
		#if QUEC_DUAL_SIM_SUPPORT
			CiPs4GNwRegInfo *p_cereg_info = &quec_cereg_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)];
		#else
			CiPs4GNwRegInfo *p_cereg_info = &quec_cereg_info;
		#endif
            Quec_NetInfo_log("4g old: tac %04X,cellid %04X---new:tac %04X,cellid %04X", p_cereg_info->tac, p_cereg_info->cellId, nw4gRegInd->nwRegInfo.tac, nw4gRegInd->nwRegInfo.cellId);
            if(nw4gRegInd->nwRegInfo.cellId != p_cereg_info->cellId)
			{
				if(quec_pg_kalive_netif_notify_sem != NULL)
	            {
	                quec_rtos_semaphore_release(quec_pg_kalive_netif_notify_sem);
	            }			
			}

		#endif			
#ifdef QUECTEL_NETWORK_SUPPORT
		#if QUEC_DUAL_SIM_SUPPORT
			if(memcmp(&quec_cereg_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)],&(nw4gRegInd->nwRegInfo),sizeof(CiPs4GNwRegInfo))!=0)
		#else
			if(memcmp(&quec_cereg_info,&(nw4gRegInd->nwRegInfo),sizeof(CiPs4GNwRegInfo))!=0)
		#endif
				value_change_flag=1;
			#ifdef __QUEC_OEM_VER_LD__
			char tac_buf[LANDI_VAL_BUF_MAX] = {0};
			char cid_buf[LANDI_VAL_BUF_MAX] = {0};
			#endif
			net_status=quec_regstatus_asr2quec(nw4gRegInd->nwRegInfo.status, 0);
            UINT8 report_status = net_status;
            if (6 == report_status)
            {
                report_status = 0;
                if (1 != quec_creg_report_emergency)
                {
                    net_status = 0;
                }
            }

		#ifdef QUECTEL_AT_QCFG_ACQDB_OPT_SUPPORT
			if(net_status ==1 || net_status == 5)
			{
				quec_update_earfcn_list(1);
			}
		#endif
#if QUEC_CEER_ESM_REJECT_CAUSE_SUPPORT
            extern void quec_set_clear_err_cause(void);
            if(net_status ==1 || net_status == 5){
                quec_set_clear_err_cause();
            }
#endif
		#if QUEC_DUAL_SIM_SUPPORT
			memcpy(&quec_cereg_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)],&(nw4gRegInd->nwRegInfo) , sizeof(CiPs4GNwRegInfo));
		#else
			memcpy(&quec_cereg_info,&(nw4gRegInd->nwRegInfo) , sizeof(CiPs4GNwRegInfo));
		#endif
#ifdef QUEC_BLACK_CELL_SUPPORT
		UINT8 read_cfg=0;
		UINT8 preventimer_status=0;
		extern UINT16 get_commonReserved_1_value(UINT8 positionToGet, UINT8 SimID);
		if (QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg_ex())
		{
			if(net_status ==1 || net_status == 5)
			{
				if( (0x460 == nw4gRegInd->nwRegInfo.rplmnInfo.CountryCode) || quec_get_electric_blackextand_cfg() == QUEC_BLACKE_EXTAND_CONFIG_OFF)
				{
					CPUartLogPrintf("quec_black update_ltecellid_to_blackcell_check: clear judge");
					quec_set_oneshot_type(BLACKCELL_ATTACH_SUCCESS);
					quec_send_oneshot_get_cellid(CI_DEV_COMMON_REPORT_EMM);

					read_cfg = get_commonReserved_1_value(41,SIM1);//73-32
					if(read_cfg != 1)
					{
						DEV_SetMEDCR(SIMULATE_SIM1_REQ_HANDLE, 73, 1);
					}
					
#if QUEC_DUAL_SIM_SUPPORT
					read_cfg = get_commonReserved_1_value(41,SIM2);//73-32
					if(read_cfg != 1)
					{
						DEV_SetMEDCR(SIMULATE_SIM2_REQ_HANDLE, 73, 1);
					}
#endif
				}
				else 
				{
					quec_set_black_cell_cfg_ex(QUEC_BLACKCELL_DISABLE);
					quec_delete_all_blackcell();
					quec_electric_fence_delete_all_blackcell();
					
					read_cfg = get_commonReserved_1_value(41,SIM1);//73-32
					if(read_cfg != 0)
					{
						DEV_SetMEDCR(SIMULATE_SIM1_REQ_HANDLE, 73, 0);
					}
					
#if QUEC_DUAL_SIM_SUPPORT
					read_cfg = get_commonReserved_1_value(41,SIM2);//73-32
					if(read_cfg != 0)
					{
						DEV_SetMEDCR(SIMULATE_SIM2_REQ_HANDLE, 73, 0);
					}
#endif
				}
			}
			else
			{
				if (quec_get_black_cell_prevention_mode() == QUEC_BLACK_ELECTRIC_FENCE_PREVENTION_MODE_ON)
				{
					preventimer_status = quec_electric_fence_preventiontimer_get_status();
					if((preventimer_status == PREVENTMR_STA_NULL) || (preventimer_status == PREVENTMR_STA_DISABLED))
					{
						quec_electric_fence_send_prevent_event_msg(QUEC_BLACKCELL_NETWORK_DROPOUT);
					}
				}
			}	
		}
#endif

#ifdef QUEC_THIN_BLACK_CELL_SUPPORT
		if (QUEC_BLACKCELL_ENABLE == quec_get_black_cell_cfg())
		{
			if(net_status ==1 || net_status == 5)
			{
				if(0x460 != nw4gRegInd->nwRegInfo.rplmnInfo.CountryCode) 
				{	
					if(quec_get_electric_blackextand_cfg() == QUEC_BLACKE_EXTAND_CONFIG_ON)
					{
						quec_set_black_cell_cfg(QUEC_BLACKCELL_DISABLE);
					}
				}
			}
		}
#endif

			quectel_current_config_value_get(AT_CEREG, (int *)&reg_status);
			#ifdef QUECTEL_AT_QINDCFG_SUPPORT //connor 2019/01/21 add the qindcfg="act"
			//when in WCDMA/GSM we had report in cgreg so we do not need to report here
			if(  quectel_read_urc_ind_flag(QUECTEL_URC_ALL_IND)  
				&& quectel_read_urc_ind_flag(QUECTEL_URC_ACTCHGRPT_IND) )
			{
				//connor.wu 2018/05/16 map asr act 8/9 to 6/7
				if(quec_ratchg_indication(0,quec_act_asr2quec(nw4gRegInd->nwRegInfo.act),net_status,rat_string_buf))
				{
					sprintf( resp_buf,"+QIND: \"act\",\"%s\"\r\n",rat_string_buf);
					if(strlen(resp_buf)!=0)
					{
						err = at_urc_send(NUM_OF_TEL_ATP, (uint8 *)resp_buf, strlen(resp_buf), TRUE, URC_OUT_METHOD_UNICAST, NULL);
						if (err != kNoErr)
						{
							Quec_NetInfo_log("at_urc_send failed");
						}
					}
				}
			}
			#endif
		   
			#if QUEC_NETINFO_REPORT_ENABLE
            if (net_status == 1 || net_status == 5)
            {
                temp = TRUE;    
            }
            else
            {
                temp = FALSE;
            }
			quec_event_notify_report(EVENT_NET_REGISTER, &temp);
			#endif
			memset(resBuf,0,sizeof(resBuf));
			Quec_NetInfo_log("4g_status=%d,act=%d,gPSActDetail=%d,reg_status=%d",nw4gRegInd->nwRegInfo.status,nw4gRegInd->nwRegInfo.act,*pPsActDetail,reg_status);
			if(value_change_flag==1)
			{
				if(reg_status==1 )
				{
					sprintf( resBuf,"+CEREG: %d\r\n",report_status);
				}
				else if(reg_status==2 )
				{	 
					if(nw4gRegInd->nwRegInfo.tacPresent &&(net_status == 1 || net_status == 5 || net_status == 6))
					{	 
						#ifdef __QUEC_OEM_VER_LD__  
						if (TRUE == Quectel_IsOEMLandiEnable())
						{
							GET_VALID_VAL(tac_buf, nw4gRegInd->nwRegInfo.tac);
							GET_VALID_VAL(cid_buf, nw4gRegInd->nwRegInfo.cellId);
							//connor.wu 2018/05/16 map asr act 8/9 to 6/7
							sprintf( resBuf,"+CEREG: %d,\"%s\",\"%s\",%d\r\n",report_status,tac_buf,cid_buf,quec_act_asr2quec(nw4gRegInd->nwRegInfo.act));
						}
						else
						#endif
						{
							//connor.wu 2018/05/16 map asr act 8/9 to 6/7
							sprintf( resBuf,"+CEREG: %d,\"%04X\",\"%04X\",%d\r\n",report_status,nw4gRegInd->nwRegInfo.tac,nw4gRegInd->nwRegInfo.cellId,quec_act_asr2quec(nw4gRegInd->nwRegInfo.act));
						}
					}
					else
					{
						Quec_NetInfo_log("TAC not present");
						sprintf( resBuf,"+CEREG: %d\r\n",report_status);
					}
				}
				if(strlen(resBuf)!=0 && quec_report_cereg(resBuf,reqHandle)==1)
				{
                    quec_dual_nw_reoprt(resBuf,sizeof(resBuf), reqHandle);
					err = at_urc_send(NUM_OF_TEL_ATP, (uint8 *)resBuf, strlen(resBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
					if (err != kNoErr)
					{
						Quec_NetInfo_log("at_urc_send failed");
					}
				}
				
				//also report cgreg when register on LTE
				quectel_current_config_value_get(AT_CGREG, (int *)&reg_status);
				memset(resBuf,0,sizeof(resBuf));
				if(reg_status==1 )
				{
					sprintf( resBuf,"+CGREG: %d\r\n",report_status);
				}
				else if(reg_status==2 )
				{	 
					if(nw4gRegInd->nwRegInfo.tacPresent &&(net_status == 1 || net_status == 5 || net_status == 6))
					{	 
						#ifdef __QUEC_OEM_VER_LD__  
						if (TRUE == Quectel_IsOEMLandiEnable())
						{
							GET_VALID_VAL(tac_buf, nw4gRegInd->nwRegInfo.tac);
							GET_VALID_VAL(cid_buf, nw4gRegInd->nwRegInfo.cellId);
							//connor.wu 2018/05/16 map asr act 8/9 to 6/7
							sprintf( resBuf,"+CGREG: %d,\"%s\",\"%s\",%d\r\n",report_status,tac_buf,cid_buf,quec_act_asr2quec(nw4gRegInd->nwRegInfo.act));
						}
						else
						#endif
						{
							//connor.wu 2018/05/16 map asr act 8/9 to 6/7
							sprintf( resBuf,"+CGREG: %d,\"%04X\",\"%04X\",%d\r\n",report_status,nw4gRegInd->nwRegInfo.tac,nw4gRegInd->nwRegInfo.cellId,quec_act_asr2quec(nw4gRegInd->nwRegInfo.act));
						}
					}
					else
					{
						Quec_NetInfo_log("TAC/LAC not present");
						sprintf( resBuf,"+CGREG: %d\r\n",report_status);
					}
				}
				if(strlen(resBuf)!=0 && quec_report_cgreg(resBuf,reqHandle)==1)
				{
					quec_dual_nw_reoprt(resBuf,sizeof(resBuf), reqHandle);
					err = at_urc_send(NUM_OF_TEL_ATP, (uint8 *)resBuf, strlen(resBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
					if (err != kNoErr)
					{
						Quec_NetInfo_log("at_urc_send failed");
					}
				}

			#ifdef LTEONLY_THIN_SINGLE_SIM
				//also report creg when register on LTE
				quectel_current_config_value_get(AT_CREG, (int *)&reg_status);
				memset(resBuf,0,sizeof(resBuf));
				if(reg_status == 1 ){
					sprintf( resBuf,"+CREG: %d\r\n",report_status);
				}else if(reg_status == 2 ){	
					if(nw4gRegInd->nwRegInfo.tacPresent && (net_status == 1 || net_status == 5 || net_status == 6))
					{	 
					#ifdef __QUEC_OEM_VER_LD__  
						if (TRUE == Quectel_IsOEMLandiEnable()){
							GET_VALID_VAL(tac_buf, nw4gRegInd->nwRegInfo.tac);
							GET_VALID_VAL(cid_buf, nw4gRegInd->nwRegInfo.cellId);
							//connor.wu 2018/05/16 map asr act 8/9 to 6/7
							sprintf( resBuf,"+CREG: %d,\"%s\",\"%s\",%d\r\n",report_status,tac_buf,cid_buf,quec_act_asr2quec(nw4gRegInd->nwRegInfo.act));
						}
						else
					#endif
						{
							//connor.wu 2018/05/16 map asr act 8/9 to 6/7
							sprintf( resBuf,"+CREG: %d,\"%04X\",\"%04X\",%d\r\n",report_status,nw4gRegInd->nwRegInfo.tac,nw4gRegInd->nwRegInfo.cellId,quec_act_asr2quec(nw4gRegInd->nwRegInfo.act));
						}
					}
					else
					{
						Quec_NetInfo_log("TAC/LAC not present");
						sprintf( resBuf,"+CREG: %d\r\n",report_status);
					}
				}
				
				if(strlen(resBuf)!=0 && quec_report_creg(resBuf,reqHandle)==1){
					quec_dual_nw_reoprt(resBuf,sizeof(resBuf), reqHandle);
					err = at_urc_send(NUM_OF_TEL_ATP, (uint8 *)resBuf, strlen(resBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
					if (err != kNoErr){
						Quec_NetInfo_log("at_urc_send failed");
					}
				}
			#endif
			
			}
		
#endif

			#ifndef PLATFORM_FOR_PS_LW
			if((*p4gCurrentPSRegStatus == CI_PS_NW_REG_STA_REG_HPLMN)||(*p4gCurrentPSRegStatus == CI_PS_NW_REG_STA_REG_ROAMING))
			{
				if(AC_IS_CPONLY)
				{
					ASSERT((simcardNum == 1)||(simcardNum == 2));
					setSimIdForPS(simcardNum-1);
				}
			}
#endif

            if ((nw4gRegInd->nwRegInfo.tacPresent == TRUE)&&((*p4gCurrentPSRegStatus==CI_PS_NW_REG_STA_REG_HPLMN)||(*p4gCurrentPSRegStatus==CI_PS_NW_REG_STA_REG_ROAMING)))
            {
               *pPsActDetail = nw4gRegInd->nwRegInfo.act;
            }
            
            DBGMSG("[%s]:line(%d), CI_PS_PRIM_4G_NW_REG_IND received, regstatus: %d!\n", __FUNCTION__, __LINE__, nw4gRegInd->nwRegInfo.status);
                               
            CPUartLogPrintf("%s:  CI_PS_PRIM_4G_NW_REG_IND p4gCurrentPSRegOption is %d", __FUNCTION__,*p4gCurrentPSRegOption); 

            for(i = NONE_IMS_FLAG; i <= IMS_FLAG; i++)
            {
                idx = i;
                
#ifndef SINGLE_SIM
				if (!GET_SIM1_FLAG(indHandle))
					p4gCurrentPSRegOption = &g4gCurrentPSRegOption[idx];
				else
					p4gCurrentPSRegOption = &g4gCurrentPSRegOption_1[idx];
#else
				p4gCurrentPSRegOption = &g4gCurrentPSRegOption[idx];
#endif
				 
				 /* show the registration status */
				 switch ( *p4gCurrentPSRegOption )
				 {
					 case CI_PS_NW_REG_IND_DISABLE:
						 /* Nothing to show */
						 break;
			
					 case CI_PS_NW_REG_IND_ENABLE_STA_ONLY:
			
						 sprintf(atBuf, "+CEREG: %d",nw4gRegInd->nwRegInfo.status);
			
						 atRespStr_NW_REG(reqHandle,idx,atBuf);
						 break;
			
					 case CI_PS_NW_REG_IND_ENABLE_DETAIL:
					 {
						 *pPsActDetail = nw4gRegInd->nwRegInfo.act; 						   
						 if(nw4gRegInd->nwRegInfo.tacPresent == TRUE)
							 sprintf(atBuf, "+CEREG: %d, \"%04x\", \"%08x\", %d",nw4gRegInd->nwRegInfo.status , nw4gRegInd->nwRegInfo.tac,
									 nw4gRegInd->nwRegInfo.cellId, *pPsActDetail);
						 else
							 sprintf(atBuf, "+CEREG: %d",nw4gRegInd->nwRegInfo.status);
			
						 atRespStr_NW_REG(reqHandle,idx,atBuf); 	   
						 break;
					 }
					 
					 case CI_PS_NW_REG_IND_ENABLE_MORE_DETAIL:
					 {
						 *pPsActDetail = nw4gRegInd->nwRegInfo.act; 							 
						 sprintf ( (char *)atBuf,"+CEREG: %d",nw4gRegInd->nwRegInfo.status);
			
						 //tac, cellId, act
						 if(nw4gRegInd->nwRegInfo.tacPresent == TRUE)
						 {
							 sprintf(tmpBuf, ", \"%04x\", \"%08x\", %d" , nw4gRegInd->nwRegInfo.tac,
									 nw4gRegInd->nwRegInfo.cellId, *pPsActDetail);
							 strcat((char *)atBuf,(char *)tmpBuf);	
							 
							 // causeType and rejectCause
							 if(nw4gRegInd->nwRegInfo.causePresent == TRUE)
							 {
								 sprintf(tmpBuf, ", %d, %d", nw4gRegInd->nwRegInfo.causeType,
									 nw4gRegInd->nwRegInfo.rejectCause);
								 
								 strcat((char *)atBuf,(char *)tmpBuf);	
							 }							  
						 }
						 else
							 sprintf(atBuf, "+CEREG: %d",nw4gRegInd->nwRegInfo.status);
						 
						 atRespStr_NW_REG(reqHandle,idx,atBuf); 	 
						 break;
					 }
			
					 case CI_PS_NW_REG_IND_ENABLE_PSM:
					 {
						 *pPsActDetail = nw4gRegInd->nwRegInfo.act; 							 
						 sprintf ( (char *)atBuf,"+CEREG: %d",nw4gRegInd->nwRegInfo.status);
			
						 //tac, cellId, act
						 if(nw4gRegInd->nwRegInfo.tacPresent == TRUE)
						 {
							 sprintf(tmpBuf, ", \"%04x\", \"%08x\", %d" , nw4gRegInd->nwRegInfo.tac,
									 nw4gRegInd->nwRegInfo.cellId, *pPsActDetail);
							 strcat((char *)atBuf,(char *)tmpBuf);	
			
							 if(nw4gRegInd->nwRegInfo.causePresent == TRUE)
							 {
								 sprintf(tmpBuf, ", , ");
								 strcat((char *)atBuf,(char *)tmpBuf); 
								 
			
								 if(nw4gRegInd->nwRegInfo.activeTimePresent== TRUE)
								 {
									 strcat(atBuf,",\"");
									 memset(tmpBuf, 0, sizeof(tmpBuf));
									 if(convertDecIntToBinStr(nw4gRegInd->nwRegInfo.activeTime,(UINT8 *)tmpBuf, 8)==TRUE)
									 {
										 strcat((char *)atBuf,(char *)tmpBuf);
									 }
								 
									 strcat(atBuf,"\"");
								 }
								 
								 if(nw4gRegInd->nwRegInfo.periodicTauPresent== TRUE)
								 {
									 if(nw4gRegInd->nwRegInfo.activeTimePresent== FALSE)
									 {
										 strcat((char *)atBuf,", ");
									 }
								 
									 strcat(atBuf,",\"");
									 memset(tmpBuf, 0, sizeof(tmpBuf));
									 if(convertDecIntToBinStr(nw4gRegInd->nwRegInfo.periodicTau,(UINT8 *)tmpBuf, 8)==TRUE)
									 {
										 strcat((char *)atBuf,(char *)tmpBuf);
									 }
								 
									 strcat(atBuf,"\"");
								 }	
								 
							 }
						 }
						 else
							 sprintf(atBuf, "+CEREG: %d",nw4gRegInd->nwRegInfo.status); 						  
			
						 atRespStr_NW_REG(reqHandle,idx,atBuf); 	  
						 break;
					 }
			
					 case CI_PS_NW_REG_IND_ENABLE_PSM_DETAIL:
					 {
						 *pPsActDetail = nw4gRegInd->nwRegInfo.act; 							 
						 sprintf ( (char *)atBuf,"+CEREG: %d",nw4gRegInd->nwRegInfo.status);
			
						 //tac, cellId, act
						 if(nw4gRegInd->nwRegInfo.tacPresent == TRUE)
						 {
							 sprintf(tmpBuf, ", \"%04x\", \"%08x\", %d" , nw4gRegInd->nwRegInfo.tac,
									 nw4gRegInd->nwRegInfo.cellId, *pPsActDetail);
							 strcat((char *)atBuf,(char *)tmpBuf);	
			
							 if(nw4gRegInd->nwRegInfo.causePresent == TRUE)
							 {
								 sprintf(tmpBuf, ", %d, %d", nw4gRegInd->nwRegInfo.causeType,
									 nw4gRegInd->nwRegInfo.rejectCause);
			
								 strcat((char *)atBuf,(char *)tmpBuf); 
								 
			
								 if(nw4gRegInd->nwRegInfo.activeTimePresent== TRUE)
								 {
									 strcat(atBuf,",\"");
									 memset(tmpBuf, 0, sizeof(tmpBuf));
									 if(convertDecIntToBinStr(nw4gRegInd->nwRegInfo.activeTime,(UINT8 *)tmpBuf, 8)==TRUE)
									 {
										 strcat((char *)atBuf,(char *)tmpBuf);
									 }
								 
									 strcat(atBuf,"\"");
								 }
								 
								 if(nw4gRegInd->nwRegInfo.periodicTauPresent== TRUE)
								 {
									 if(nw4gRegInd->nwRegInfo.activeTimePresent== FALSE)
									 {
										 strcat((char *)atBuf,", ");
									 }
								 
									 strcat(atBuf,",\"");
									 memset(tmpBuf, 0, sizeof(tmpBuf));
									 if(convertDecIntToBinStr(nw4gRegInd->nwRegInfo.periodicTau,(UINT8 *)tmpBuf, 8)==TRUE)
									 {
										 strcat((char *)atBuf,(char *)tmpBuf);
									 }
								 
									 strcat(atBuf,"\"");
								 }	
								 
							 }
						 }
						 else
							 sprintf(atBuf, "+CEREG: %d",nw4gRegInd->nwRegInfo.status); 						  
			
						 atRespStr_NW_REG(reqHandle,idx,atBuf); 	   
						 break;
					 }
					 
					 default:
						 break;
			
				 }
			 }
#ifdef QUEC_NETWORK_CARD_ENABLE  //Chaim 2019.03.04 send network deactive indication
		#ifdef QUECTEL_AT_QCFG_ROAMSERVICEEX
            /*isaac 20201228 support at+qcfg="roamserviceex",1 or 3 漫游下，不发绑定网卡消息*/
            if (TRUE == quectel_roam_disable_status_get_bit(0))
            {
                if(net_status ==1)
		        {
			        quec_netdevctl_network_ind_msg_send(QUEC_NETDEVCTL_MSG_FROM_IND, QUEC_NETCARD_NETWORK_STATE_IND, (uint8 *)&primId, sizeof(primId));
		        }
            }
            else 
            {
                if((net_status ==1) || (net_status==5))
		        {
			        quec_netdevctl_network_ind_msg_send(QUEC_NETDEVCTL_MSG_FROM_IND, QUEC_NETCARD_NETWORK_STATE_IND, (uint8 *)&primId, sizeof(primId));
		        }
            }
        #endif
#endif
#ifdef QUECTEL_AT_QCFG_ROAMSERVICEEX
       /* Isaac 20201228 support at+qcfg="roamserviceex",1 or 3 
        * bit0:disable the internet access(NIC dialing) ;bit1:disable voice call
        */
       if ( (TRUE == quec_is_roam_status()) && 
            (TRUE == quectel_roam_disable_status_get_bit(0)) )
       {
            /*网络状态若变为漫游，解绑网卡*/
            CPUartLogPrintf("%s: line[%d]set roamserviceex is 1 or 3,disable netcard dial",__func__,__LINE__);
            if(0 != quec_netcard_get_cid())
            {
                quec_netdevctl_lwip_config(QUEC_NETIF_DISCONNECT, quec_netcard_get_cid());
            }
       }
#endif
#ifdef QUEC_PATCH_1803S_FPLMN_66302
			if(((net_status == 1) || (net_status == 5)) && ((0x250 == nw4gRegInd->nwRegInfo.rplmnInfo.CountryCode) || (0x432 == nw4gRegInd->nwRegInfo.rplmnInfo.CountryCode)))
			{
#if QUEC_DUAL_SIM_SUPPORT
				if (getDualSimType() == CM_DUAL_SIM_SINGLE_STANDBY)
				{
				 	DEV_SetFunc(isMasterSim0() ? SIMULATE_SIM1_REQ_HANDLE : SIMULATE_SIM2_REQ_HANDLE, 4, 0, FALSE, 0, 0); 
				}
				else
				{
				 	DEV_SetFunc(SIMULATE_SIM1_REQ_HANDLE, 4, 0, FALSE, 0, 0);
				 	DEV_SetFunc(SIMULATE_SIM2_REQ_HANDLE, 4, 0, FALSE, 0, 0);
				}
#else 
				DEV_SetFunc(reqHandle, 4, 0, FALSE, 0, 0);
#endif
				#ifdef QUEC_UESTAT_SUPPORT
				quec_set_uestat_limit(TRUE);
				if(quec_get_uestat_enable()==TRUE)
				{
                    err = at_urc_send(NUM_OF_TEL_ATP, (uint8 *)"+QUESTAT: 1,1", strlen("+QUESTAT: 1,1"), TRUE, URC_OUT_METHOD_UNICAST, NULL);
                    if (err != kNoErr)
                    {
                        Quec_NetInfo_log("at_urc_send failed");
                    }
				}
				#endif
			}
			#ifdef QUEC_UESTAT_SUPPORT
			else if((net_status == 1) || (net_status == 5))
			{
            quec_set_uestat_limit(FALSE);
			}
			#endif
#endif
			break;
		}

		case CI_PS_PRIM_DETACHED_IND:
		{
			char atBuf[200] = {0};
			char tmpBuf[50] = {0};
			detachInd = (CiPsPrimDetachedInd *)pParam;

			#ifdef QUECTEL_OPEN_CPU
				quec_nw_event_ind(reqHandle, pParam, QUEC_NW_EVENT_DETACHED_INFO);
			#endif

			if(detachInd->isMeDetach == FALSE)
			{
				ATRESP( reqHandle, 0, 0, (char*)"+CGEV: NW DETACH\r\n");
			}
			else
			{
			    ATRESP( reqHandle, 0, 0, (char*)"+CGEV: ME DETACH\r\n");
			}
#ifdef QUECTEL_NETWORK_SUPPORT
		if(quectel_read_urc_ind_flag(QUECTEL_URC_ALL_IND))
		{
		#if QUEC_DUAL_SIM_SUPPORT
			if(cgerep_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].mode==1 ||
			   cgerep_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].mode==2)
		#else	
			if(cgerep_info.mode==1 ||cgerep_info.mode==2)//connor.wu 2018/11/15  when mode=1/2 open the Packet Domain Event Reporting
		#endif
		{
		        sprintf( atBuf, "+CGEV: %s DETACH\r\n", detachedInd->isMeDetach ? "ME" : "NW" );
	        	(void)at_urc_send(NUM_OF_TEL_ATP, (uint8 *)atBuf, strlen(atBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
	    }
		}
#endif
#ifdef QUEC_NETWORK_CARD_ENABLE  //Chaim 2019.03.04 send network deactive indication
				if(0 != quec_netcard_get_cid())
				{
					Quec_NetInfo_log("netdevctl,detach,disconenct netcard,cid=%d",quec_netcard_get_cid());
					quec_netdevctl_set_auto_time_interval_default();
					quec_netdevctl_lwip_config(QUEC_NETIF_DISCONNECT, quec_netcard_get_cid());
					quec_netdevctl_urc_report(QUEC_NETDEVCTL_URC_TYPE_CLOSE); 
					quec_pdp_deatch_handler(quec_netcard_get_cid());
				}
				quec_netdevctl_network_ind_msg_send(QUEC_NETDEVCTL_MSG_FROM_IND, QUEC_NETCARD_NETWORK_STATE_IND, (uint8 *)&primId, sizeof(primId));	//CI_PS_PRIM_DETACHED_IND
#endif
#ifdef QUEC_NETDUALCH_CFG
			quec_netdualchcfg_pdpdeacted_urc_report();
#endif
			break;
		}
		case CI_PS_PRIM_PDP_ACTIVATION_REJECT_CAUSE_IND:
		{
			char atBuf[200]="\0";
			char tmpBuf[50]="\0";
			pdpActivationRejectCauseInd = (CiPsPrimPdpActivationRejectCauseInd *)pParam;
#ifdef QUECTEL_NETWORK_SUPPORT
            memset(atBuf,0,sizeof(atBuf));
            memset(tmpBuf,0,sizeof(tmpBuf));
#endif
#ifdef QUEC_AUTOAPN_ADJUST_SUPPORT	
			if( (pdpActivationRejectCauseInd->cidPresent == 0) && (pdpActivationRejectCauseInd->pdpType == CI_PS_4G_DEFAULT_PDP_TYPE) )
			{
				pdpActivationRejectCauseInd->cidPresent = 1;
				pdpActivationRejectCauseInd->cid = getDefaultCidNum() - 1;
			}

			static UINT32 tick_mark = 0;
			static UINT32 tick_current = 0;
			if(quec_get_autoapn_cfg_vaild() == TRUE)
			{
				if(pdpActivationRejectCauseInd->smCausePresent)
				{
					CPUartLogPrintf("quec_autoapn %s, pdp active rej cid %d cause %d state %d", __func__,pdpActivationRejectCauseInd->cid,pdpActivationRejectCauseInd->smCause,quec_get_autoapn_adjust_status());
					if(pdpActivationRejectCauseInd->cid == (qcfg_ltedftcid-1) )
					{
						if((quec_get_autoapn_adjust_status() != QUEC_AUTOAPN_FAIL)
							&& (quec_get_autoapn_adjust_status() != QUEC_AUTOAPN_SUSPEND))
						{
							if((pdpActivationRejectCauseInd->smCause == CI_PS_ESM_UNKNOWN_OR_MISSING_APN)
							||(pdpActivationRejectCauseInd->smCause == CI_PS_ESM_USER_AUTHENTICATION_FAILED)
							||(pdpActivationRejectCauseInd->smCause == CI_PS_ESM_SERVICE_OPTION_NOT_SUPPORTED)
							||(pdpActivationRejectCauseInd->smCause == CI_PS_ESM_REQUESTED_SERVICE_OPTION_NOT_SUBSCRIBED))
							{
								tick_current = OSAGetTicks();
								//400 tick = 2s
								if( ((tick_current - tick_mark) > 400)
								  || (tick_mark == 0))
								{
									autoapn_msg = QUEC_PDP_REJECT_SPECIAL;
									quec_send_msg_to_handle_task(QUEC_AUTO_APN_EVENT_MSG, (char *)&autoapn_msg, sizeof(int));
								}
								tick_mark = tick_current;
							}
						}
					}
				}
			}
#endif
			if((*pPsActDetail == 7) || (*pPsActDetail == 9))
				sprintf( atBuf, "+CNEC_ESM:");
			else
				sprintf( atBuf, "+CNEC_GSM:");
			
			if(pdpActivationRejectCauseInd->smCausePresent)
			{
				sprintf(tmpBuf, " %d,", pdpActivationRejectCauseInd->smCause);
				#ifdef LWIP_IPNETBUF_SUPPORT
				
				#ifdef VOLTE_ENABLE
				if (is_ims_cid((reqHandle == IND_REQ_HANDLE)? 0: 1, pdpActivationRejectCauseInd->cid + 1, NULL) != 1)
				{
					setUnknownPdpCause(reqHandle, pdpActivationRejectCauseInd->smCause);
				}
				#else
				setUnknownPdpCause(reqHandle, pdpActivationRejectCauseInd->smCause);
				#endif
				
				#ifdef PPP_ENABLE
				if (bspGetBoardType() == TIGX_MIFI)
				{
					if (isHandleForMasterSim(reqHandle))
					{
						if ((ppp_get_connect_flag(pdpActivationRejectCauseInd->cid)) && 
							(pdpActivationRejectCauseInd->smCause == CIRC_PS_APN))
							sendmatchCgdcontapn();
					}
				}
				else
				#endif
				{
					if (getAutoApn() && !getOptimizeEtifFlag())
					{
						if (!pdpActivationRejectCauseInd->cidPresent || pdpActivationRejectCauseInd->cid == getDefaultCidNum() - 1)
						{
							setErrorIndFlag(reqHandle, getDefaultCidNum() - 1);
							#ifdef ATCMD_PDP_CONTEXT
							telClearPdpInfo(getDefaultCidNum());
							#endif
						}
						else
						{
							setErrorIndFlag(reqHandle, pdpActivationRejectCauseInd->cid);
						}
					}
				}
				#endif

#if QUEC_CEER_ESM_REJECT_CAUSE_SUPPORT
			char *quec_err_cause_p = quec_err_cause;
			const ceer_lookup_s_type  *result_ptr = NULL;
			char tempBuf[256] = {0};
			
			// is lte esm and not care ims attach
			if ( (*pPsActDetail == 7) 
#ifdef VOLTE_ENABLE
            &&  (!is_ims_cid((reqHandle == IND_REQ_HANDLE)? 0: 1, pdpActivationRejectCauseInd->cid + 1, NULL))
#endif
            )
			{
				// ignore PS ip only/ipv6 only report;
				if(pdpActivationRejectCauseInd->smCause != CIRC_PS_ESM_PDN_TYPE_IPV4_ONLY_ALLOWED 
				&& pdpActivationRejectCauseInd->smCause != CIRC_PS_ESM_PDN_TYPE_IPV6_ONLY_ALLOWED)
				{
				
					if(TRUE != quec_ci_lookup_cause_code(ceer_ps_lte_cause_codes, pdpActivationRejectCauseInd->smCause, &result_ptr)){
						CPUartLogPrintf(" Failed to lookup reject code cause:%d", pdpActivationRejectCauseInd->smCause);
						sprintf(quec_err_cause_p,"No report available");
						break;
					}
					snprintf(quec_err_cause_p, QUEC_ERR_CAUSE_LEN, "\"%s\",%d,\"%s\"", "ESM", pdpActivationRejectCauseInd->smCause, result_ptr->text);
					if(TRUE == quec_get_err_cause_urc_en()){
						snprintf(tempBuf, sizeof(tempBuf), "+QCEER: %s", quec_err_cause_p);
						at_urc_send(NUM_OF_TEL_ATP, (uint8 *)tempBuf, strlen(tempBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
					}
				}
			}
#endif

			}
			else
				sprintf(tmpBuf, " ,");
			strlcat(atBuf, tmpBuf, sizeof(atBuf));

			if(pdpActivationRejectCauseInd->cidPresent)
			{
				sprintf(tmpBuf, "%d", pdpActivationRejectCauseInd->cid + 1);
				strcat(atBuf, tmpBuf);
			}
			ATRESP(reqHandle, 0, 0, atBuf);
#ifdef QUECTEL_NETWORK_SUPPORT
			if(quectel_read_urc_ind_flag(QUECTEL_URC_ALL_IND))
			{
			#if QUEC_DUAL_SIM_SUPPORT
				if(cgerep_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].mode==1 ||
				   cgerep_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].mode==2)
			#else	
				if(cgerep_info.mode==1 ||cgerep_info.mode==2) //connor.wu 2018/11/15  when mode=1/2 open the Packet Domain Event Reporting
			#endif
					(void)at_urc_send(NUM_OF_TEL_ATP, (uint8 *)atBuf, strlen(atBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
			}
#endif

			break;
		}

        /* Added by Daniel for LTE PC AT command server 20120117, begin */
		case CI_PS_PRIM_MT_PDP_CTX_ACTED_IND:
		{
			/* Added by Daniel for LTE PC AT command server 20120117, begin */
			//[klockwork][issue id: 2296]
			char atBuf[200]={0};
			char tmpBuf[50]="\0";
#ifdef LWIP_IPNETBUF_SUPPORT
			BOOL mt_pdp = FALSE;
#endif
			int i;
			MtPdpCtxActedInd = (CiPsPrimMtPdpCtxActedInd *)pParam;
			pdp_table_index = getPdpIndexByCid(MtPdpCtxActedInd->pdpCtx.cid,p_cInfo);
			if(pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
			{
				pdp_table_index = getFreePdpIndexFromTable(p_cInfo);
				if (pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
        		{
        		    ASSERT(0);
        		}
			}
			telPsPdpCtx *psPdpInfo =  telGetPdpCtx(MtPdpCtxActedInd->pdpCtx.cid);

			if(psPdpInfo != NULL && (simcardNum == (getMasterSimID() + 1)))
			{
				//ATDBGMSG("%s:psPdpInfo=0x%lx", __func__, psPdpInfo);
				if(MtPdpCtxActedInd->pdpCtx.cid == getDefaultCidNum()-1)
				{
					psPdpInfo->reDefined = 1;
					psPdpInfo->apnInfo.defined = 1;
					psPdpInfo->apnInfo.ipType = MtPdpCtxActedInd->pdpCtx.type;
					if(MtPdpCtxActedInd->pdpCtx.apnPresent == 1)
					{
						memcpy(psPdpInfo->apnInfo.apn, MtPdpCtxActedInd->pdpCtx.apn.valStr, TEL_AT_CGDCONT_2_APN_STR_MAX_LEN);
						removeEpsApnSuffix(psPdpInfo->apnInfo.apn);
					}					
				}
				
				psPdpInfo->activedStatus = 1;

				//ATDBGMSG("%s:reDefined[%d],defined[%d],apn[%s]", __func__, psPdpInfo->reDefined, psPdpInfo->apnInfo.defined, psPdpInfo->apnInfo.apn);
			}
			
#ifdef QUECTEL_PROJECT_CUST
			if(MtPdpCtxActedInd->pdpCtx.type==CI_PS_PDP_TYPE_IPV6 || MtPdpCtxActedInd->pdpCtx.type==CI_PS_PDP_TYPE_IPV4V6)
			{
                lwip_ip_configinfo info;
                memset(&info, 0, sizeof(info));
                info.cid =  MtPdpCtxActedInd->pdpCtx.cid;
                info.cid |= (simcardNum==2?1:0)<<7;
                info.status=1;
                lwip_set_pdpinfo(&info);
			}
#endif			
			  #if defined(__QUEC_OEM_VER_DM__)
			  #include "quec_atcmd_dmhttp.h"
			  extern dmhttp_ctx_t dmhttp_ctx;
			   Quec_NetInfo_log("psind cid:%d enable:%d",MtPdpCtxActedInd->pdpCtx.cid,dmhttp_ctx.resume_save_enable);
			  if(MtPdpCtxActedInd->pdpCtx.cid == 0 && dmhttp_ctx.resume_save_enable == 1)
			  	{
					quec_apptcpip_pdp_active_req  *active_msg = NULL;
				    active_msg = malloc(sizeof(quec_apptcpip_pdp_active_req));
				    active_msg->atHandle = 0XFFFFFFFE;
				    active_msg->pdp_cid = 1;
				    quec_apptcpip_requst(QUEC_APPTCPIP_PDP_ACTIVE_REQ, active_msg);
			  	}
			#endif
#ifdef QUECTEL_PROJECT_CUST
			int quec_pdpmodify_cid;
			CPUartLogPrintf("quec_pdpmodify_count reset");
			for(quec_pdpmodify_cid=0; quec_pdpmodify_cid<CI_PS_MAX_CID; quec_pdpmodify_cid++)
			{
				quec_pdpmodify_count[quec_pdpmodify_cid] = 0;
			}
#endif
#ifdef QUEC_AUTOAPN_ADJUST_SUPPORT	
			if(quec_get_autoapn_cfg_vaild() == TRUE)
			{
				if(MtPdpCtxActedInd->pdpCtx.cid == (qcfg_ltedftcid-1))
				{
					autoapn_msg = QUEC_PDP_ACTIVATE;
					quec_send_msg_to_handle_task(QUEC_AUTO_APN_EVENT_MSG, (char *)&autoapn_msg, sizeof(int));
				}
			}
#endif

        	if(1/*(*pPsActDetail == 7) || (*pPsActDetail == 9)*/)
	        {
				/* PDP type number */
				//getPdpTypeStr ( MtPdpCtxActedInd->pdpCtx.type, tmpBuf );
				//[klockwork][issue id: 2277]
				//if(MtPdpCtxActedInd->pdpCtx.p_cid < CI_PS_MAX_CID)
				if((MtPdpCtxActedInd->pdpCtx.pdpBearType == CI_PS_DEDICATED_PDP)
				&& (MtPdpCtxActedInd->pdpCtx.p_cid < CI_PS_MAX_CID)
				&& (MtPdpCtxActedInd->pdpCtx.cid < CI_PS_MAX_CID))
				{

	                if(MtPdpCtxActedInd->isMEInitiated == FALSE)
	                {
	                    sprintf(atBuf, "+CGEV: NW ACT ");
	                    sprintf( tmpBuf, "%d,%d\r\n", MtPdpCtxActedInd->pdpCtx.p_cid + 1, MtPdpCtxActedInd->pdpCtx.cid + 1);
	                    strcat( atBuf, tmpBuf );
	                    p_cInfo[pdp_table_index].bDefined = TRUE;
	                    p_cInfo[pdp_table_index].cid= MtPdpCtxActedInd->pdpCtx.cid;
	                    if (p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
	                    {
	                        reqHandle = p_cInfo[pdp_table_index].reqHandle;
	                    }
#ifdef LWIP_IPNETBUF_SUPPORT
						mt_pdp = TRUE;
#endif
#ifdef QUECTEL_NETWORK_SUPPORT
						quec_pdp_act_state[MtPdpCtxActedInd->pdpCtx.p_cid].pdp_act_status=1;
						quec_pdp_act_state[MtPdpCtxActedInd->pdpCtx.cid].pdp_act_status=1;
#endif
#ifdef QUECTEL_NETWORK_SUPPORT
                        if (QUEC_IS_VALID_ATP(GET_ATP_INDEX(GET_AT_HANDLE(reqHandle))))
                        {
                            //nothing
                        }
                        else
                        {
                        	ATRESP(reqHandle, 0, 0, atBuf);
                        }
#else
	                    ATRESP(reqHandle, 0, 0, atBuf);
#endif
	                }
	                else
	                {
	                    sprintf(atBuf, "+CGEV: ME ACT ");
	                    sprintf( tmpBuf, "%d,%d\r\n", MtPdpCtxActedInd->pdpCtx.p_cid + 1, MtPdpCtxActedInd->pdpCtx.cid + 1);
	                    strcat( atBuf, tmpBuf );
	                    p_cInfo[pdp_table_index].bDefined = TRUE;
	                    p_cInfo[pdp_table_index].cid= MtPdpCtxActedInd->pdpCtx.cid;
	                    if (p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
	                    {
	                        reqHandle = p_cInfo[pdp_table_index].reqHandle;
	                    }
#ifdef QUECTEL_NETWORK_SUPPORT
                        if (QUEC_IS_VALID_ATP(GET_ATP_INDEX(GET_AT_HANDLE(reqHandle))))
                        {
                            //nothing
                        }
                        else
                        {
                        	ATRESP(reqHandle, 0, 0, atBuf);
                        }
#else
	                    ATRESP(reqHandle, 0, 0, atBuf);
#endif
	                }
	            }
				//[klockwork][issue id: 2278]
				//else if(MtPdpCtxActedInd->pdpCtx.cid < CI_PS_MAX_CID)
				else if((MtPdpCtxActedInd->pdpCtx.pdpBearType == CI_PS_DEFAULT_PDP)
				&& (MtPdpCtxActedInd->pdpCtx.cid < CI_PS_MAX_CID))
				{
#ifdef QUECTEL_NETWORK_SUPPORT
					quec_pdp_act_state[MtPdpCtxActedInd->pdpCtx.cid].pdp_act_status=1;
#endif
	                if(MtPdpCtxActedInd->isMEInitiated == FALSE)
	                {
	                	if((*pPsActDetail == 7) || (*pPsActDetail == 9))
	                	{
	                		sprintf(atBuf, "+CGEV: EPS PDN ACT ");
	                	}
						else
						{
							sprintf(atBuf, "+CGEV: NW PDN ACT ");
						}

	                    sprintf(tmpBuf, "%d\r\n", MtPdpCtxActedInd->pdpCtx.cid + 1);
	                    strcat(atBuf, tmpBuf);
	                    p_cInfo[pdp_table_index].bDefined = TRUE;
						p_cInfo[pdp_table_index].cid = MtPdpCtxActedInd->pdpCtx.cid;
	                    if (p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
	                    {
	                        reqHandle = p_cInfo[pdp_table_index].reqHandle;
	                    }
#ifdef LWIP_IPNETBUF_SUPPORT
				mt_pdp = TRUE;
				//updateAttachPdpApnInfo(MtPdpCtxActedInd->pdpCtx.apn.valStr, MtPdpCtxActedInd->pdpCtx.type);
				updateAttachPdpApnInfoDS(reqHandle, MtPdpCtxActedInd->pdpCtx.apn.valStr, MtPdpCtxActedInd->pdpCtx.type);
#endif
#ifdef QUECTEL_NETWORK_SUPPORT
                        if (QUEC_IS_VALID_ATP(GET_ATP_INDEX(GET_AT_HANDLE(reqHandle))))
                        {
                            //nothing
                        }
                        else
                        {
                        	ATRESP(reqHandle, 0, 0, atBuf);
                        }
#else
	                    ATRESP(reqHandle, 0, 0, atBuf);
#endif
	                }
	                else
	                {

	                    sprintf(atBuf, "+CGEV: ME PDN ACT ");
						if((MtPdpCtxActedInd->pdpReason == CI_PS_PDP_SINGLE_ONLY_ALLOWED_SEC_SUCC)
						&& (MtPdpCtxActedInd->cid_other < CI_PS_MAX_CID))
						{
							sprintf(tmpBuf, "%d,%d,%d\r\n", MtPdpCtxActedInd->pdpCtx.cid + 1, MtPdpCtxActedInd->pdpReason, MtPdpCtxActedInd->cid_other + 1);
						}
						else
						{
						#ifdef QUECTEL_NETWORK_SUPPORT
							if((MtPdpCtxActedInd->pdpReason == CI_PS_PDP_INVALID_REASON)){//no need show invaild reason;
								sprintf(atBuf, "+CGEV: ME PDN ACT %d\r\n", MtPdpCtxActedInd->pdpCtx.cid + 1);
							}
							else
						#endif
							{
								sprintf(tmpBuf, "%d,%d\r\n", MtPdpCtxActedInd->pdpCtx.cid + 1, MtPdpCtxActedInd->pdpReason);
							}
						}
	                    strcat(atBuf, tmpBuf);
	                    p_cInfo[pdp_table_index].bDefined = TRUE;
						p_cInfo[pdp_table_index].cid= MtPdpCtxActedInd->pdpCtx.cid;
	                    if (p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
	                    {
	                        reqHandle = p_cInfo[pdp_table_index].reqHandle;
	                    }
#ifdef QUECTEL_NETWORK_SUPPORT
                        if (QUEC_IS_VALID_ATP(GET_ATP_INDEX(GET_AT_HANDLE(reqHandle))))
                        {
                            //nothing
                        }
                        else
                        {
                        	ATRESP(reqHandle, 0, 0, atBuf);
                        }
#else
	                    ATRESP(reqHandle, 0, 0, atBuf);
#endif
	                }
	            }
				else
				{
					break;
				}
	        }
        	else
	        {
	            /* PDP type number */
	         //   getPdpTypeStr ( MtPdpCtxActedInd->pdpCtx.type, tmpBuf );
				//[klockwork][issue id: 2279]
	           // if(MtPdpCtxActedInd->pdpCtx.cid < CI_PS_MAX_CID)
	           	if(((MtPdpCtxActedInd->pdpCtx.pdpBearType == CI_PS_PRIMARY_PDP)
					||(MtPdpCtxActedInd->pdpCtx.pdpBearType == CI_PS_SECONDARY_PDP))
					&& (MtPdpCtxActedInd->pdpCtx.cid < CI_PS_MAX_CID))
	            {
#ifdef QUECTEL_NETWORK_SUPPORT
					quec_pdp_act_state[MtPdpCtxActedInd->pdpCtx.cid].pdp_act_status=1;
#endif
	                if(MtPdpCtxActedInd->isMEInitiated == FALSE)
	                {
#ifdef LWIP_IPNETBUF_SUPPORT
                        mt_pdp = TRUE;
#endif
						sprintf(atBuf, "+CGEV: NW PDN ACT %d\r\n", MtPdpCtxActedInd->pdpCtx.cid + 1);
	                }
	                else
	                {
						if((MtPdpCtxActedInd->pdpReason == CI_PS_PDP_SINGLE_ONLY_ALLOWED_SEC_SUCC)
						&& (MtPdpCtxActedInd->cid_other < CI_PS_MAX_CID))
						{

							sprintf(atBuf, "+CGEV: ME PDN ACT %d,%d,%d\r\n", MtPdpCtxActedInd->pdpCtx.cid + 1, MtPdpCtxActedInd->pdpReason, MtPdpCtxActedInd->cid_other + 1);
						}
						else
						{
						#ifdef QUECTEL_NETWORK_SUPPORT
							if((MtPdpCtxActedInd->pdpReason == CI_PS_PDP_INVALID_REASON)){//no need show invaild reason;
								sprintf(atBuf, "+CGEV: ME PDN ACT %d\r\n", MtPdpCtxActedInd->pdpCtx.cid + 1);
							}
							else
						#endif
							{
								sprintf(atBuf, "+CGEV: ME PDN ACT %d,%d\r\n", MtPdpCtxActedInd->pdpCtx.cid + 1, MtPdpCtxActedInd->pdpReason);
							}
						}
	                }

					p_cInfo[pdp_table_index].bDefined = TRUE;
					p_cInfo[pdp_table_index].cid= MtPdpCtxActedInd->pdpCtx.cid;

					if (p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
					{
						reqHandle = p_cInfo[pdp_table_index].reqHandle;
					}
                    
#ifdef QUECTEL_NETWORK_SUPPORT
                    if (QUEC_IS_VALID_ATP(GET_ATP_INDEX(GET_AT_HANDLE(reqHandle))))
                    {
                        //nothing
                    }
                    else
                    {
                        ATRESP(reqHandle, 0, 0, atBuf);
                    }
#else
                    ATRESP(reqHandle, 0, 0, atBuf);
#endif


	            }
				else
				{
					break;
				}

			}
#ifdef QUECTEL_NETWORK_SUPPORT
			if(quectel_read_urc_ind_flag(QUECTEL_URC_ALL_IND))
			{
			#if QUEC_DUAL_SIM_SUPPORT
				if(cgerep_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].mode==1 ||
				   cgerep_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].mode==2)
			#else	
				if(cgerep_info.mode==1 ||cgerep_info.mode==2) //connor.wu 2018/11/15  when mode=1/2 open the Packet Domain Event Reporting
			#endif
					(void)at_urc_send(NUM_OF_TEL_ATP, (uint8 *)atBuf, strlen(atBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
			}
#endif
#ifdef LWIP_IPNETBUF_SUPPORT
			setMtPdp(MtPdpCtxActedInd->pdpCtx.cid, mt_pdp);
	#ifdef ATCMD_PDP_CONTEXT
			if (MtPdpCtxActedInd->pdpCtx.apnPresent)
			{
				MtPdpCtxActedInd->pdpCtx.apn.valStr[MtPdpCtxActedInd->pdpCtx.apn.len] = '\0';
				telUpdatePdpInfoListEpsApn(MtPdpCtxActedInd->pdpCtx.cid + 1, MtPdpCtxActedInd->pdpCtx.apn.valStr, MtPdpCtxActedInd->pdpCtx.type);
			}
	#endif
			mtDataLinkAllowCheck(reqHandle, MtPdpCtxActedInd->pdpCtx.cid, MtPdpCtxActedInd->pdpCtx.pdpBearType);
#endif		
#ifdef QUEC_NETWORK_CARD_ENABLE  //Chaim 2019.03.04 send network deactive indication
			quec_netdevctl_network_ind_msg_send(QUEC_NETDEVCTL_MSG_FROM_IND, QUEC_NETCARD_NETWORK_STATE_IND, (uint8 *)&primId, sizeof(primId));  //CI_PS_PRIM_MT_PDP_CTX_ACTED_IND
#endif
			break;
		}

		/* Added by Daniel for LTE PC AT command server 20120117, end */

        /* Added by Daniel for LTE PC AT command server 20120319, begin */
		case CI_PS_PRIM_MT_PDP_CTX_ACT_MODIFY_IND:
		{
			char atBuf[200]="\0";
			char tmpBuf[50]="\0";

			int i = 0;
			MtPdpCtxActModifyInd = (CiPsPrimMtPdpCtxActModifyInd *)pParam;

#ifdef QUECTEL_PROJECT_CUST
		if(MtPdpCtxActModifyInd->pdpCtx.cid < CI_PS_MAX_CID)
		{
			quec_pdpmodify_count[MtPdpCtxActModifyInd->pdpCtx.cid]++;
			if(quec_pdpmodify_count[MtPdpCtxActModifyInd->pdpCtx.cid] >= QUEC_PDPMODIFY_PUNISH_COUNT)
			{
				CPUartLogPrintf("quec_pdpmodify_count cid %d more than three times",MtPdpCtxActModifyInd->pdpCtx.cid);
				if(0 == quec_qsclkex_punishtime_get())
				{
					quec_qsclkex_punishtime_set(qsclkex_cfg.punish_time);
				}
			}
		}
#endif
			//[klockwork][issue id: 2280]
	        //if(MtPdpCtxActModifyInd->pdpCtx.cid < CI_PS_MAX_CID)
			if(((MtPdpCtxActModifyInd->pdpCtx.pdpBearType == CI_PS_DEFAULT_PDP)
				||(MtPdpCtxActModifyInd->pdpCtx.pdpBearType == CI_PS_DEDICATED_PDP))
				&& (MtPdpCtxActModifyInd->pdpCtx.cid< CI_PS_MAX_CID))
	        {
	        	pdp_table_index = getPdpIndexByCid(MtPdpCtxActModifyInd->pdpCtx.cid,p_cInfo);
				
				telPsPdpCtx *psPdpInfo =  telGetPdpCtx(MtPdpCtxActModifyInd->pdpCtx.cid);
                if(psPdpInfo != NULL)
				    psPdpInfo->activedStatus = 1;

	            if(MtPdpCtxActModifyInd->actionType == CI_PS_ACT_IND_ACTION)
	            {
	                sprintf( atBuf, "+CGEV: EPS ACT ");
	                sprintf(tmpBuf, "%d\r\n", MtPdpCtxActModifyInd->pdpCtx.cid + 1);
	                strcat(atBuf, tmpBuf );
#ifdef LWIP_IPNETBUF_SUPPORT
			        sendQueryCgdcont(reqHandle);
#endif
	            }
	            else if(MtPdpCtxActModifyInd->actionType == CI_PS_MODIFY_IND_ACTION)
	            {
	                sprintf( atBuf, "+CGEV: NW MODIFY ");

	                sprintf(tmpBuf, "%d,", MtPdpCtxActModifyInd->pdpCtx.cid + 1);
	                strcat(atBuf, tmpBuf );

	                sprintf( tmpBuf, "%d\r\n",MtPdpCtxActModifyInd->change_reason);
	                strcat( atBuf, tmpBuf );
#ifdef LWIP_IPNETBUF_SUPPORT
				    sendQueryCgdcont(reqHandle);
					  //query and update TFT
               		updateMTPdpTft(reqHandle, MtPdpCtxActModifyInd->change_reason);
#endif
	            }
				else
				{
					break;
				}
				if (pdp_table_index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
				{
    				/*Fix coverity[overrun-local]*/
    				if (p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
    				{
    					reqHandle = p_cInfo[pdp_table_index].reqHandle;
    				}
				}
	        }
#ifdef QUECTEL_NETWORK_SUPPORT
            if (QUEC_IS_VALID_ATP(GET_ATP_INDEX(GET_AT_HANDLE(reqHandle))))
            {
                //nothing
            }
            else
            {
               ATRESP(reqHandle, 0, 0, atBuf);
            }
#else
            ATRESP(reqHandle, 0, 0, atBuf);
#endif    
			extern void usbnet_set_mode_disable( int cid);
			usbnet_set_mode_disable(MtPdpCtxActModifyInd->pdpCtx.cid);
#ifdef QUECTEL_NETWORK_SUPPORT
	
			if(quectel_read_urc_ind_flag(QUECTEL_URC_ALL_IND))
			{
			#if QUEC_DUAL_SIM_SUPPORT
				if(cgerep_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].mode==1 ||
				   cgerep_info[(isHandleForSim0(reqHandle) ? SIM1 : SIM2)].mode==2)
			#else	
				if(cgerep_info.mode==1 ||cgerep_info.mode==2) //connor.wu 2018/11/15  when mode=1/2 open the Packet Domain Event Reporting
			#endif
		        	(void)at_urc_send(NUM_OF_TEL_ATP, (uint8 *)atBuf, strlen(atBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
			}
#endif
			break;
		}

		/* Added by Daniel for LTE PC AT command server 20120319, end */
		case CI_PS_PRIM_IMS_REG_INFO_IND:
		{
			//IMS registration information +CIREGU: <reg_info>[,<ext_info>]
			char atBuf[200] = {0};
			BOOL oldRegState=FALSE;
			CiPsPrimSetImsRegStateReq *setImsRegStateReq = NULL;
			UINT32 atHandle=0;
			BOOL hasDetail = FALSE;
			BOOL vopsSupported = FALSE;
			BOOL smsOverImsSupported = FALSE;

			imsRegInfoInd = (CiPsPrimImsRegInfoInd *)pParam;

			DBGMSG("[%s]:line(%d), CI_PS_PRIM_IMS_REG_INFO_IND received, report state is %d \n", __FUNCTION__, __LINE__, imsRegInfoInd->reportState);

			oldRegState = gImsRegState;
			if (imsRegInfoInd->reportState == CI_PS_NW_REG_IND_ENABLE_STA_ONLY)
			{
				sprintf(atBuf, "+CIREGU: %d", imsRegInfoInd->newInfo.regInfo);
				ATRESP( reqHandle, 0, 0, atBuf);
			}
			else if (imsRegInfoInd->reportState == CI_PS_NW_REG_IND_ENABLE_DETAIL)
			{
				sprintf(atBuf, "+CIREGU: %d, %d", imsRegInfoInd->newInfo.regInfo, imsRegInfoInd->newInfo.extInfo);
				ATRESP( reqHandle, 0, 0, atBuf);
			}
			else
			{
				//do nothing
			}
			*pImsRegState = (imsRegInfoInd->newInfo.regInfo == 1) ? TRUE : FALSE;
			DBGMSG("[%s]:line(%d), gImsRegState is %d \n", __FUNCTION__, __LINE__, *pImsRegState);

			//if the register state change, tell the new state to CP,
			//if ims stack run in CP in the feature, don't do this step.
			if (oldRegState != *pImsRegState)
			{
				if(reqHandle == IND_REQ_HANDLE)
					atHandle = MAKE_AT_HANDLE(TEL_AT_CMD_ATP_7);
				else
					atHandle = MAKE_AT_HANDLE(TEL_AT_CMD_ATP_44);

				setImsRegStateReq = (CiPsPrimSetImsRegStateReq *)utlCalloc(1, sizeof(CiPsPrimSetImsRegStateReq));
				setImsRegStateReq->state = imsRegInfoInd->newInfo.regInfo;
				ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_IMS_REG_STATE_REQ,
					MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_SET_IMS_REG_STATE_REQ), (void*)setImsRegStateReq);
			}

			break;
		}
		case CI_PS_PRIM_UE_EVENT_TO_IMS_IND:
		{
			ueEventToImsInd = (CiPsPrimUeEventToImsInd *)pParam;
			CiPsPrimSetImsRegStateReq *setImsRegStateReq = NULL;
			UINT32 atHandle;

			DBGMSG("[%s]:line(%d), CI_PS_PRIM_UE_EVENT_TO_IMS_IND received, reason is %d, now ims stack is %d \n",
				__FUNCTION__, __LINE__, ueEventToImsInd->ueEvent, *pImsRegState);
			if(ueEventToImsInd->ueEvent == CIPS_TO_IMS_EVENT_REATTACH)
			{
				char atBuf[200] = {0};

				sprintf(atBuf, "+CGEV: NW REATTACH");
				ATRESP( reqHandle, 0, 0, atBuf);
			}
			else
			{

				//send de-register message to IMS stack.
				if (ueEventToImsInd->imsNeedDeReg == 1)
				{
					/*Fixed coverity[leaked_storage]*/
					#if 0
					atHandle = MAKE_AT_HANDLE(TEL_AT_CMD_ATP_UART);
					setImsRegStateReq = (CiPsPrimSetImsRegStateReq *)utlCalloc(1, sizeof(CiPsPrimSetImsRegStateReq));
					setImsRegStateReq->state = 0; //send de-register to IMS stack.
					#endif
					//ciImsRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_IMS_REG_STATE_REQ,
					//	MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_SET_IMS_REG_STATE_REQ), (void*)setImsRegStateReq);
				}
			}
			break;
		}
		case CI_PS_PRIM_SUSPEND_RESUME_IND:
		{
			CiPsPrimSuspendResumeInd *suspendresumeind=NULL;

			suspendresumeind = (CiPsPrimSuspendResumeInd *)pParam;
			char atBuf[200] = {0};
			sprintf(atBuf, "*DATASTATUS: %d, %d", suspendresumeind->suspended,suspendresumeind->suspendReason);
			ATRESP( reqHandle, 0, 0, atBuf);
			#ifdef QUEC_AT_URC_SUPPORT
			#ifdef QUECTEL_AT_QINDCFG_SUPPORT //connor 2018/11/23 add the asr DATASTATUS urc report control
			if(quectel_read_urc_ind_flag(QUECTEL_URC_DATASTATUS_IND)  && quectel_read_urc_ind_flag(QUECTEL_URC_ALL_IND))
			#endif
			(void)at_urc_send(NUM_OF_TEL_ATP, (uint8 *)atBuf, strlen(atBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
			#endif

			break;
		}
		
		#ifdef QUECTEL_NETWORK_SUPPORT
		case CI_PS_PRIM_SIGNALLING_CONNECTION_IND:
		{
			processSignallingConnectionInd(reqHandle,pParam);
			break;
		}
		#endif
		default:
			break;
	}

	/* free up the indication memory */
	atciSvgFreeIndMem( svgId, primId, pParam );

	F_LEAVE();
}//MiniSystem
else
{
	UNUSEDPARAM(opSgOpaqueHandle)
	UNUSEDPARAM(indHandle)
	F_ENTER();

	DBGMSG("psInd:primId=%d\n", primId);
	//[klockwork][issue id: 2293]
	UINT8 add_len = 0;
	UINT16 add_data=0;
	CiPsPrimPdpCtxDeactedInd  *pdpCtxDeactedInd=NULL;
	CiPsPrimNwRegInd    *nwRegInd=NULL;
	CiPsPrim4GNwRegInd	*nw4gRegInd=NULL;
	/* Added by Daniel for LTE PC AT command server 20120117, begin */
	CiPsPrimMtPdpCtxActedInd  *MtPdpCtxActedInd=NULL;
	CiPsPrimMtPdpCtxActModifyInd	*MtPdpCtxActModifyInd=NULL;
	CiPsPrimDetachedInd             *detachInd=NULL;
	CiPsPrimDetachedInd             *detachedInd;
    /* Added by Daniel for LTE PC AT command server 20120117, end */
	CiPsPrimImsRegInfoInd *imsRegInfoInd=NULL;
	CiPsPrimUeEventToImsInd *ueEventToImsInd=NULL;
	CiPsPrimPdpActivationRejectCauseInd *pdpActivationRejectCauseInd;
	int idx = IMS_FLAG; 

	UINT32 reqHandle;
	int *pCurrentPSRegOption, *p4gCurrentPSRegOption;
	int *pCurrentPSRegStatus;
	int *pPsActDetail;
	AtciCurrentSetCntx *p_cInfo;
	int *p4gCurrentPSRegStatus;
	BOOL *pImsRegState;
	UINT8 pdp_table_index;
	#ifndef PLATFORM_FOR_PS_LW
	int simcardNum = 0;
	#endif
	
#ifndef LTEONLY_THIN_SINGLE_SIM	
		if (!GET_SIM1_FLAG(indHandle)) {
		#ifndef PLATFORM_FOR_PS_LW
			DIAG_FILTER(PCAC, ATCMDSrv, ParseIPAddr23_jyz, DIAG_INFORMATION)
			diagPrintf("sim 1 psind");
			simcardNum = 1;
		#endif
	
			reqHandle = IND_REQ_HANDLE;
		#ifndef LTEONLY_THIN
			pCurrentPSRegOption = &gCurrentPSRegOption[idx];
		#endif
			pCurrentPSRegStatus = &gCurrentPSRegStatus;
			pPsActDetail = &gPsActDetail;
			p_cInfo = gCIDList.cInfo;
			p4gCurrentPSRegStatus = &g4gCurrentPSRegStatus;
			p4gCurrentPSRegOption = &g4gCurrentPSRegOption[idx];
			pImsRegState = &gImsRegState;
		} else {
		#ifndef PLATFORM_FOR_PS_LW
			DIAG_FILTER(PCAC, ATCMDSrv, ParseIPAddr23_jyz1, DIAG_INFORMATION)
			diagPrintf("sim 2 psind");
	
			simcardNum = 2;
		#endif
			reqHandle = IND_REQ_HANDLE_1;
		#ifndef LTEONLY_THIN
			pCurrentPSRegOption = &gCurrentPSRegOption_1[idx];
		#endif
				pCurrentPSRegStatus = &gCurrentPSRegStatus_1;
				pPsActDetail = &gPsActDetail_1;
				p_cInfo = gCIDList.cInfo_1;
				p4gCurrentPSRegStatus = &g4gCurrentPSRegStatus_1;
				p4gCurrentPSRegOption = &g4gCurrentPSRegOption_1[idx];
				pImsRegState = &gImsRegState_1;
		}
#else
#ifndef PLATFORM_FOR_PS_LW
		DIAG_FILTER(PCAC, ATCMDSrv, ParseIPAddr23_jyz, DIAG_INFORMATION)
		diagPrintf("sim 1 psind");
		simcardNum = 1;
#endif
	
		reqHandle = IND_REQ_HANDLE;
	#ifndef LTEONLY_THIN
		pCurrentPSRegOption = &gCurrentPSRegOption[idx];
	#endif
		pCurrentPSRegStatus = &gCurrentPSRegStatus;
		pPsActDetail = &gPsActDetail;
		p_cInfo = gCIDList.cInfo;
		p4gCurrentPSRegStatus = &g4gCurrentPSRegStatus;
		p4gCurrentPSRegOption = &g4gCurrentPSRegOption[idx];
		pImsRegState = &gImsRegState;
		
		
#endif /*LTEONLY_THIN_SINGLE_SIM*/

	extern void ModemCiPrimitiveIndFileter(CiServiceGroupID id,CiPrimitiveID primId, CiIndicationHandle indHandle, void* paras);
	ModemCiPrimitiveIndFileter(svgId,primId,indHandle,pParam);

	switch(primId)
	{
		case CI_PS_PRIM_PDP_CTX_DEACTED_IND:
		{
			//[klockwork][issue id: 2296]
			char atBuf[200]="\0";
			char tmpBuf[50]="\0";

			int i;
			pdpCtxDeactedInd = (CiPsPrimPdpCtxDeactedInd *)pParam;

			pdp_table_index = getPdpIndexByCid(pdpCtxDeactedInd->indedPdpCtx.cid,p_cInfo);
			telPsPdpCtx *psPdpInfo =  telGetPdpCtx(pdpCtxDeactedInd->indedPdpCtx.cid);

			if(pdp_table_index >= CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
				break;
            if(psPdpInfo != NULL)
			    psPdpInfo->activedStatus = 0;

			if(1/*(*pPsActDetail == 7) || (*pPsActDetail == 9)*/)
	        {
				//[klocwork][issue id: 2275]
				//if(pdpCtxDeactedInd->indedPdpCtx.p_cid < CI_PS_MAX_CID)
				if((pdpCtxDeactedInd->indedPdpCtx.pdpBearType == CI_PS_DEDICATED_PDP)
					&& (pdpCtxDeactedInd->indedPdpCtx.p_cid < CI_PS_MAX_CID)
					&& (pdpCtxDeactedInd->indedPdpCtx.cid < CI_PS_MAX_CID))
				{
				    if(pdpCtxDeactedInd->isMEInitiated == FALSE)
	                {
	                    sprintf(atBuf, "+CGEV: NW DEACT ");
	                }
	                else
	                {
	                    sprintf(atBuf, "+CGEV: ME DEACT ");

	                }
					sprintf(tmpBuf, "%d,%d\r\n", pdpCtxDeactedInd->indedPdpCtx.p_cid + 1, pdpCtxDeactedInd->indedPdpCtx.cid + 1);
                    strcat(atBuf, tmpBuf);

                    if(p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
                    {
                        reqHandle = p_cInfo[pdp_table_index].reqHandle;
                    }

                    //If the CID is already deleted, don't send +CGEV
                    if(p_cInfo[pdp_table_index].bDefined)
                        ATRESP(reqHandle, 0, 0, atBuf);
	            }
				//[klockwork][issue id: 2275]
				//else if(pdpCtxDeactedInd->indedPdpCtx.cid < CI_PS_MAX_CID)
				else if((pdpCtxDeactedInd->indedPdpCtx.pdpBearType == CI_PS_DEFAULT_PDP)
					&& (pdpCtxDeactedInd->indedPdpCtx.cid < CI_PS_MAX_CID))
				{
				    if(pdpCtxDeactedInd->isMEInitiated == FALSE)
				    {
	                    sprintf(atBuf, "+CGEV: NW PDN DEACT ");

	                }
					else
					{
	                    sprintf(atBuf, "+CGEV: ME PDN DEACT ");
	                }
					sprintf(tmpBuf, "%d\r\n", pdpCtxDeactedInd->indedPdpCtx.cid + 1);
                    strcat(atBuf, tmpBuf);

                    if(p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
                    {
                        reqHandle = p_cInfo[pdp_table_index].reqHandle;
                    }

                    //If the CID is already deleted, don't send +CGEV
                    if(p_cInfo[pdp_table_index].bDefined)
                        ATRESP(reqHandle, 0, 0, atBuf);
	            }
	        }
        	else
	        {
				//[klockwork][issue id: 2276]
	            //if(pdpCtxDeactedInd->indedPdpCtx.cid < CI_PS_MAX_CID)
				if(((pdpCtxDeactedInd->indedPdpCtx.pdpBearType == CI_PS_PRIMARY_PDP)
					||(pdpCtxDeactedInd->indedPdpCtx.pdpBearType == CI_PS_SECONDARY_PDP))
					&& (pdpCtxDeactedInd->indedPdpCtx.cid < CI_PS_MAX_CID))
				{
					if(pdpCtxDeactedInd->isMEInitiated == FALSE)
						sprintf(atBuf, "+CGEV: NW PDN DEACT ");
					else
						sprintf(atBuf, "+CGEV: ME PDN DEACT ");
					sprintf(tmpBuf, "%d\r\n", pdpCtxDeactedInd->indedPdpCtx.cid + 1);
					strcat(atBuf, tmpBuf);

					if (p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
					{
						reqHandle = p_cInfo[pdp_table_index].reqHandle;
						p_cInfo[pdp_table_index].reqHandle=INVALID_REQ_HANDLE;
					}

					/*Fixed coverity[overrun-local]*/
					//If the CID is already deleted, don't send +CGEV
					if (p_cInfo[pdp_table_index].bDefined)
						ATRESP(reqHandle, 0, 0, atBuf);

				}

		   }
#ifdef LWIP_IPNETBUF_SUPPORT
		    /*remove the netif*/
			if (!CM_allowSetNetif())
			{
				#ifdef QUEC_3601_PDPDEACT_NETCARD_FAIL_26489
					#ifdef VOLTE_ENABLE
						if (is_ims_cid(GET_SIM1_FLAG(indHandle) ? SIM2 : SIM1, pdpCtxDeactedInd->indedPdpCtx.cid + 1, NULL) == 0)
			 		#endif
					{
						configureLwipNetif(0xFF, pdpCtxDeactedInd->indedPdpCtx.cid, 1);	
					}
					#else
						configureLwipNetif(0xFF, pdpCtxDeactedInd->indedPdpCtx.cid, 1);
					#endif
			}
#endif
        	DIAG_FILTER(PCAC, pdp_index, resetPdpInfo, DIAG_INFORMATION)
			diagPrintf("index is %d", pdp_table_index);
			resetPdpInfo(&p_cInfo[pdp_table_index]);
			break;
		}
#ifndef LTEONLY_THIN
		case CI_PS_PRIM_NW_REG_IND:
		{
			char atBuf[100]="\0";
			int i =0;
			nwRegInd = (CiPsPrimNwRegInd *)pParam;
			*pCurrentPSRegStatus = nwRegInd->nwRegInfo.status;

#ifdef LWIP_IPNETBUF_SUPPORT
			//ATDBGMSG("CI_PS_PRIM_NW_REG_IND: lacPresent is %d", nwRegInd->nwRegInfo.lacPresent);
			updateNwRegInd(reqHandle, pParam, FALSE);
        	checkNWRegStatus(reqHandle);
#endif
#ifdef QUEC_MINISYS_USEFOR_APN_ACTIVATE
			quec_minisys_set_regstatus(nwRegInd->nwRegInfo.status);
#endif
			#ifndef PLATFORM_FOR_PS_LW
			if((*pCurrentPSRegStatus == CI_PS_NW_REG_STA_REG_HPLMN)||(*pCurrentPSRegStatus == CI_PS_NW_REG_STA_REG_ROAMING))
			{
				if(AC_IS_CPONLY)
				{
					ASSERT((simcardNum == 1)||(simcardNum == 2));
					setSimIdForPS(simcardNum-1);
				}

			}
			#endif

			if ((nwRegInd->nwRegInfo.lacPresent == TRUE)&&((*pCurrentPSRegStatus==CI_PS_NW_REG_STA_REG_HPLMN)||(*pCurrentPSRegStatus==CI_PS_NW_REG_STA_REG_ROAMING)))
			{
				*pPsActDetail = nwRegInd->nwRegInfo.act;
			}
			DBGMSG("[%s]:line(%d), CI_PS_PRIM_NW_REG_IND received, regstatus: %d!\n", __FUNCTION__, __LINE__, nwRegInd->nwRegInfo.status);
#ifdef QUEC_MINISYS_USEFOR_APN_ACTIVATE
			quec_minifota_start();//evan 2020 12 04 minifota task init
#endif
			CPUartLogPrintf("%s:  CI_PS_PRIM_NW_REG_IND pCurrentPSRegOption is %d", __FUNCTION__,*pCurrentPSRegOption); 
			
			
			 for(i = NONE_IMS_FLAG; i <= IMS_FLAG; i++)
			 {
				 idx = i;
                
#ifndef SINGLE_SIM
					 if (!GET_SIM1_FLAG(indHandle)) 
						 pCurrentPSRegOption = &gCurrentPSRegOption[idx];
					 else 
						 pCurrentPSRegOption = &gCurrentPSRegOption_1[idx];
#else
				pCurrentPSRegOption = &gCurrentPSRegOption[idx];
				 #endif 
				 
				 /* show the registration status */
				 switch ( *pCurrentPSRegOption )
				 {
					 case CI_PS_NW_REG_IND_DISABLE:
						 /* Nothing to show */
						 break;
			
					 case CI_PS_NW_REG_IND_ENABLE_STA_ONLY:
			
						 sprintf(atBuf, "+CGREG: %d\r\n", nwRegInd->nwRegInfo.status);
			
						 atRespStr_NW_REG(reqHandle,idx,atBuf);
						 break;
			
					 case CI_PS_NW_REG_IND_ENABLE_DETAIL:
					 {
						 if (nwRegInd->nwRegInfo.lacPresent == TRUE)
						 {
							 *pPsActDetail = nwRegInd->nwRegInfo.act;
			
							 sprintf( atBuf, "+CGREG: %d, \"%04x\",\"%08x\", %d\r\n", nwRegInd->nwRegInfo.status,
								  nwRegInd->nwRegInfo.lac,
								  nwRegInd->nwRegInfo.cellId,
								  *pPsActDetail);
							 atRespStr_NW_REG(reqHandle,idx,atBuf);
						 }
						 else
						 {
							 sprintf(atBuf, "+CGREG: %d\r\n", nwRegInd->nwRegInfo.status);
							 atRespStr_NW_REG(reqHandle,idx,atBuf);
						 }
			
						 break;
					 }
					 case CI_PS_NW_REG_IND_ENABLE_MORE_DETAIL:
					 {
						 if ((nwRegInd->nwRegInfo.lacPresent == TRUE)&&(nwRegInd->nwRegInfo.causePresent  == TRUE))
						 {
							 sprintf( atBuf, "+CGREG: %d, \"%04x\", \"%08x\", %d, %d, %d\r\n", nwRegInd->nwRegInfo.status,
								  nwRegInd->nwRegInfo.lac,
								  nwRegInd->nwRegInfo.cellId,
								  *pPsActDetail,						  
								  nwRegInd->nwRegInfo.causeType,
								  nwRegInd->nwRegInfo.rejectCause);
							 atRespStr_NW_REG(reqHandle,idx,atBuf);
						 }
						 else
						 {
							 sprintf(atBuf, "+CGREG: %d\r\n", nwRegInd->nwRegInfo.status);
							 atRespStr_NW_REG(reqHandle,idx,atBuf);
						 }
			
						 break;
					 }
					 default:
						 break;
				 }
			 }

			break;
		}
#endif /* LTEONLY_THIN */
		case CI_PS_PRIM_4G_NW_REG_IND:
		{
			char atBuf[200]="\0";
			char tmpBuf[50]="\0";
			nw4gRegInd = (CiPsPrim4GNwRegInd *)pParam;
			*p4gCurrentPSRegStatus = nw4gRegInd->nwRegInfo.status;
			int i =0;

#ifdef LWIP_IPNETBUF_SUPPORT
			updateNwRegInd(reqHandle, pParam, TRUE);
        	checkNWRegStatus(reqHandle);
#endif
#ifdef QUEC_MINISYS_USEFOR_APN_ACTIVATE
			quec_minisys_set_regstatus(nw4gRegInd->nwRegInfo.status);
#endif
#ifdef QUEC_MINISYS_USEFOR_APN_ACTIVATE
			quec_minifota_start();//evan 2020 12 04 minifota task init
#endif

			#ifndef PLATFORM_FOR_PS_LW
			if((*p4gCurrentPSRegStatus == CI_PS_NW_REG_STA_REG_HPLMN)||(*p4gCurrentPSRegStatus == CI_PS_NW_REG_STA_REG_ROAMING))
			{
				if(AC_IS_CPONLY)
				{
					ASSERT((simcardNum == 1)||(simcardNum == 2));
					setSimIdForPS(simcardNum-1);
				}
			}
			#endif
			if ((nw4gRegInd->nwRegInfo.tacPresent == TRUE)&&((*p4gCurrentPSRegStatus==CI_PS_NW_REG_STA_REG_HPLMN)||(*p4gCurrentPSRegStatus==CI_PS_NW_REG_STA_REG_ROAMING)))
			{
			   *pPsActDetail = nw4gRegInd->nwRegInfo.act;
			}

			DBGMSG("[%s]:line(%d), CI_PS_PRIM_4G_NW_REG_IND received, regstatus: %d!\n", __FUNCTION__, __LINE__, nw4gRegInd->nwRegInfo.status);

            CPUartLogPrintf("%s:  CI_PS_PRIM_4G_NW_REG_IND p4gCurrentPSRegOption is %d", __FUNCTION__,*p4gCurrentPSRegOption); 

#ifdef GPS_SUPPORT
            if (isHandleForMasterSim(reqHandle))
            {
                p4gCurrentPSRegOption = &g4gCurrentPSRegOption[0];
                if ((*p4gCurrentPSRegOption != CI_PS_NW_REG_IND_DISABLE) 
                 && (*p4gCurrentPSRegOption != CI_PS_NW_REG_IND_ENABLE_STA_ONLY))
                {
                    asr_gps_handle_cellID(nw4gRegInd);
                }
            }
#endif
            for(i = NONE_IMS_FLAG; i <= IMS_FLAG; i++)
            {
                idx = i;
                
#ifndef SINGLE_SIM
	            	if (!GET_SIM1_FLAG(indHandle)) 
	                    p4gCurrentPSRegOption = &g4gCurrentPSRegOption[idx];
	            	else 
	                    p4gCurrentPSRegOption = &g4gCurrentPSRegOption_1[idx]; 
                #else
				
					p4gCurrentPSRegOption = &g4gCurrentPSRegOption[idx];
				#endif
                /* show the registration status */
                switch ( *p4gCurrentPSRegOption )
                {
                    case CI_PS_NW_REG_IND_DISABLE:
                        /* Nothing to show */
                        break;

                    case CI_PS_NW_REG_IND_ENABLE_STA_ONLY:

                        sprintf(atBuf, "+CEREG: %d",nw4gRegInd->nwRegInfo.status);

                        atRespStr_NW_REG(reqHandle,idx,atBuf);
                        break;

                    case CI_PS_NW_REG_IND_ENABLE_DETAIL:
                    {
        				*pPsActDetail = nw4gRegInd->nwRegInfo.act;                            
        				if(nw4gRegInd->nwRegInfo.tacPresent == TRUE)
        					sprintf(atBuf, "+CEREG: %d, \"%04x\", \"%08x\", %d",nw4gRegInd->nwRegInfo.status , nw4gRegInd->nwRegInfo.tac,
        							nw4gRegInd->nwRegInfo.cellId, *pPsActDetail);
                        else
        					sprintf(atBuf, "+CEREG: %d",nw4gRegInd->nwRegInfo.status);

                        atRespStr_NW_REG(reqHandle,idx,atBuf);        
                        break;
                    }
                    
                    case CI_PS_NW_REG_IND_ENABLE_MORE_DETAIL:
                    {
        				*pPsActDetail = nw4gRegInd->nwRegInfo.act;                              
                        sprintf ( (char *)atBuf,"+CEREG: %d",nw4gRegInd->nwRegInfo.status);

                        //tac, cellId, act
                        if(nw4gRegInd->nwRegInfo.tacPresent == TRUE)
                        {
                            sprintf(tmpBuf, ", \"%04x\", \"%08x\", %d" , nw4gRegInd->nwRegInfo.tac,
        							nw4gRegInd->nwRegInfo.cellId, *pPsActDetail);
                            strcat((char *)atBuf,(char *)tmpBuf);  
                            
                            // causeType and rejectCause
                            if(nw4gRegInd->nwRegInfo.causePresent == TRUE)
                            {
                                sprintf(tmpBuf, ", %d, %d", nw4gRegInd->nwRegInfo.causeType,
                                    nw4gRegInd->nwRegInfo.rejectCause);
                                
                                strcat((char *)atBuf,(char *)tmpBuf);  
                            }                            
                        }
                        else
                            sprintf(atBuf, "+CEREG: %d",nw4gRegInd->nwRegInfo.status);
                        
                        atRespStr_NW_REG(reqHandle,idx,atBuf);      
                        break;
                    }

                    case CI_PS_NW_REG_IND_ENABLE_PSM:
                    {
        				*pPsActDetail = nw4gRegInd->nwRegInfo.act;                              
                        sprintf ( (char *)atBuf,"+CEREG: %d",nw4gRegInd->nwRegInfo.status);

                        //tac, cellId, act
                        if(nw4gRegInd->nwRegInfo.tacPresent == TRUE)
                        {
                            sprintf(tmpBuf, ", \"%04x\", \"%08x\", %d" , nw4gRegInd->nwRegInfo.tac,
        							nw4gRegInd->nwRegInfo.cellId, *pPsActDetail);
                            strcat((char *)atBuf,(char *)tmpBuf);  

                            if(nw4gRegInd->nwRegInfo.causePresent == TRUE)
                            {
                                sprintf(tmpBuf, ", , ");
                                strcat((char *)atBuf,(char *)tmpBuf); 
                                

                                if(nw4gRegInd->nwRegInfo.activeTimePresent== TRUE)
                                {
                                    strcat(atBuf,",\"");
                                    memset(tmpBuf, 0, sizeof(tmpBuf));
                                    if(convertDecIntToBinStr(nw4gRegInd->nwRegInfo.activeTime,(UINT8 *)tmpBuf, 8)==TRUE)
                                    {
                                        strcat((char *)atBuf,(char *)tmpBuf);
                                    }
                                
                                    strcat(atBuf,"\"");
                                }
                                
                                if(nw4gRegInd->nwRegInfo.periodicTauPresent== TRUE)
                                {
                                    if(nw4gRegInd->nwRegInfo.activeTimePresent== FALSE)
                                    {
                                        strcat((char *)atBuf,", ");
                                    }
                                
                                    strcat(atBuf,",\"");
                                    memset(tmpBuf, 0, sizeof(tmpBuf));
                                    if(convertDecIntToBinStr(nw4gRegInd->nwRegInfo.periodicTau,(UINT8 *)tmpBuf, 8)==TRUE)
                                    {
                                        strcat((char *)atBuf,(char *)tmpBuf);
                                    }
                                
                                    strcat(atBuf,"\"");
                                }  
                                
                            }
                        }
                        else
                            sprintf(atBuf, "+CEREG: %d",nw4gRegInd->nwRegInfo.status);                           

                        atRespStr_NW_REG(reqHandle,idx,atBuf);       
                        break;
                    }

                    case CI_PS_NW_REG_IND_ENABLE_PSM_DETAIL:
                    {
        				*pPsActDetail = nw4gRegInd->nwRegInfo.act;                              
                        sprintf ( (char *)atBuf,"+CEREG: %d",nw4gRegInd->nwRegInfo.status);

                        //tac, cellId, act
                        if(nw4gRegInd->nwRegInfo.tacPresent == TRUE)
                        {
                            sprintf(tmpBuf, ", \"%04x\", \"%08x\", %d" , nw4gRegInd->nwRegInfo.tac,
        							nw4gRegInd->nwRegInfo.cellId, *pPsActDetail);
                            strcat((char *)atBuf,(char *)tmpBuf);  

                            if(nw4gRegInd->nwRegInfo.causePresent == TRUE)
                            {
                                sprintf(tmpBuf, ", %d, %d", nw4gRegInd->nwRegInfo.causeType,
                                    nw4gRegInd->nwRegInfo.rejectCause);

                                strcat((char *)atBuf,(char *)tmpBuf); 
                                

                                if(nw4gRegInd->nwRegInfo.activeTimePresent== TRUE)
                                {
                                    strcat(atBuf,",\"");
                                    memset(tmpBuf, 0, sizeof(tmpBuf));
                                    if(convertDecIntToBinStr(nw4gRegInd->nwRegInfo.activeTime,(UINT8 *)tmpBuf, 8)==TRUE)
                                    {
                                        strcat((char *)atBuf,(char *)tmpBuf);
                                    }
                                
                                    strcat(atBuf,"\"");
                                }
                                
                                if(nw4gRegInd->nwRegInfo.periodicTauPresent== TRUE)
                                {
                                    if(nw4gRegInd->nwRegInfo.activeTimePresent== FALSE)
                                    {
                                        strcat((char *)atBuf,", ");
                                    }
                                
                                    strcat(atBuf,",\"");
                                    memset(tmpBuf, 0, sizeof(tmpBuf));
                                    if(convertDecIntToBinStr(nw4gRegInd->nwRegInfo.periodicTau,(UINT8 *)tmpBuf, 8)==TRUE)
                                    {
                                        strcat((char *)atBuf,(char *)tmpBuf);
                                    }
                                
                                    strcat(atBuf,"\"");
                                }  
                                
                            }
                        }
                        else
                            sprintf(atBuf, "+CEREG: %d",nw4gRegInd->nwRegInfo.status);                           

                        atRespStr_NW_REG(reqHandle,idx,atBuf);        
                        break;
                    }
                    
                    default:
                        break;

                }
            }
			break;
		}

		case CI_PS_PRIM_DETACHED_IND:
		{
			char atBuf[200]="\0";
			char tmpBuf[50]="\0";
			detachInd = (CiPsPrimDetachedInd *)pParam;
			if(detachInd->isMeDetach == FALSE)
			{
				ATRESP( reqHandle, 0, 0, (char*)"+CGEV: NW DETACH\r\n");
			}
			else
			{
			    ATRESP( reqHandle, 0, 0, (char*)"+CGEV: ME DETACH\r\n");
			}
			break;
		}
		case CI_PS_PRIM_PDP_ACTIVATION_REJECT_CAUSE_IND:
		{
			char atBuf[200]="\0";
			char tmpBuf[50]="\0";
			pdpActivationRejectCauseInd = (CiPsPrimPdpActivationRejectCauseInd *)pParam;

			if((*pPsActDetail == 7) || (*pPsActDetail == 9))
				sprintf( atBuf, "+CNEC_ESM:");
			else
				sprintf( atBuf, "+CNEC_GSM:");

			if(pdpActivationRejectCauseInd->smCausePresent)
			{
				sprintf(tmpBuf, " %d,", pdpActivationRejectCauseInd->smCause);
				#ifdef LWIP_IPNETBUF_SUPPORT

				#ifdef VOLTE_ENABLE
				if (is_ims_cid((reqHandle == IND_REQ_HANDLE)? 0: 1, pdpActivationRejectCauseInd->cid + 1, NULL) != 1)
				{
					setUnknownPdpCause(reqHandle, pdpActivationRejectCauseInd->smCause);
				}
				#else
				setUnknownPdpCause(reqHandle, pdpActivationRejectCauseInd->smCause);
				#endif

				#ifdef PPP_ENABLE
				if (bspGetBoardType() == TIGX_MIFI)
				{
					if (isHandleForMasterSim(reqHandle))
					{
						if ((ppp_get_connect_flag(pdpActivationRejectCauseInd->cid)) &&
							(pdpActivationRejectCauseInd->smCause == CIRC_PS_APN))
							sendmatchCgdcontapn();
					}
				}
				else
				#endif
				{
					if (getAutoApn() && !getOptimizeEtifFlag())
					{
						if (!pdpActivationRejectCauseInd->cidPresent || pdpActivationRejectCauseInd->cid == getDefaultCidNum() - 1)
						{
							setErrorIndFlag(reqHandle, getDefaultCidNum() - 1);
							#ifdef ATCMD_PDP_CONTEXT
							telClearPdpInfo(getDefaultCidNum());
							#endif
						}
						else
						{
							setErrorIndFlag(reqHandle, pdpActivationRejectCauseInd->cid);
						}
					}
				}
				#endif
			}
			else
				sprintf(tmpBuf, " ,");
			strlcat(atBuf, tmpBuf, sizeof(atBuf));

			if(pdpActivationRejectCauseInd->cidPresent)
			{
				sprintf(tmpBuf, "%d", pdpActivationRejectCauseInd->cid + 1);
				strcat(atBuf, tmpBuf);
			}
			ATRESP(reqHandle, 0, 0, atBuf);

			break;
		}

        /* Added by Daniel for LTE PC AT command server 20120117, begin */
		case CI_PS_PRIM_MT_PDP_CTX_ACTED_IND:
		{
			/* Added by Daniel for LTE PC AT command server 20120117, begin */
			//[klockwork][issue id: 2296]
			char atBuf[200]={0};
			char tmpBuf[50]="\0";
#ifdef LWIP_IPNETBUF_SUPPORT
			BOOL mt_pdp = FALSE;
#endif
			int i;
			MtPdpCtxActedInd = (CiPsPrimMtPdpCtxActedInd *)pParam;
			pdp_table_index = getPdpIndexByCid(MtPdpCtxActedInd->pdpCtx.cid,p_cInfo);
			if(pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
			{
				pdp_table_index = getFreePdpIndexFromTable(p_cInfo);
				if (pdp_table_index == CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
        		{
        		    ASSERT(0);
        		}
			}

			telPsPdpCtx *psPdpInfo =  telGetPdpCtx(MtPdpCtxActedInd->pdpCtx.cid);
			if(psPdpInfo != NULL && (simcardNum == (getMasterSimID() + 1)))
			{
				if(MtPdpCtxActedInd->pdpCtx.cid == getDefaultCidNum()-1)
				{
					psPdpInfo->reDefined = 1;
					psPdpInfo->apnInfo.defined = 1;
					psPdpInfo->apnInfo.ipType = MtPdpCtxActedInd->pdpCtx.type;
					if(MtPdpCtxActedInd->pdpCtx.apnPresent == 1)
					{
						memcpy(psPdpInfo->apnInfo.apn, MtPdpCtxActedInd->pdpCtx.apn.valStr, TEL_AT_CGDCONT_2_APN_STR_MAX_LEN);
						removeEpsApnSuffix(psPdpInfo->apnInfo.apn);
					}					
				}
				psPdpInfo->activedStatus = 1;
			}
        	if(1/*(*pPsActDetail == 7) || (*pPsActDetail == 9)*/)
	        {
				/* PDP type number */
				//getPdpTypeStr ( MtPdpCtxActedInd->pdpCtx.type, tmpBuf );
				//[klockwork][issue id: 2277]
				//if(MtPdpCtxActedInd->pdpCtx.p_cid < CI_PS_MAX_CID)
				if((MtPdpCtxActedInd->pdpCtx.pdpBearType == CI_PS_DEDICATED_PDP)
				&& (MtPdpCtxActedInd->pdpCtx.p_cid < CI_PS_MAX_CID)
				&& (MtPdpCtxActedInd->pdpCtx.cid < CI_PS_MAX_CID))
				{

	                if(MtPdpCtxActedInd->isMEInitiated == FALSE)
	                {
	                    sprintf(atBuf, "+CGEV: NW ACT ");
	                    sprintf( tmpBuf, "%d,%d\r\n", MtPdpCtxActedInd->pdpCtx.p_cid + 1, MtPdpCtxActedInd->pdpCtx.cid + 1);
	                    strcat( atBuf, tmpBuf );
	                    p_cInfo[pdp_table_index].bDefined = TRUE;
	                    p_cInfo[pdp_table_index].cid= MtPdpCtxActedInd->pdpCtx.cid;
	                    if (p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
	                    {
	                        reqHandle = p_cInfo[pdp_table_index].reqHandle;
	                    }
#ifdef LWIP_IPNETBUF_SUPPORT
						mt_pdp = TRUE;
#endif
	                    ATRESP(reqHandle, 0, 0, atBuf);
	                }
	                else
	                {
	                    sprintf(atBuf, "+CGEV: ME ACT ");
	                    sprintf( tmpBuf, "%d,%d\r\n", MtPdpCtxActedInd->pdpCtx.p_cid + 1, MtPdpCtxActedInd->pdpCtx.cid + 1);
	                    strcat( atBuf, tmpBuf );
	                    p_cInfo[pdp_table_index].bDefined = TRUE;
	                    p_cInfo[pdp_table_index].cid= MtPdpCtxActedInd->pdpCtx.cid;
	                    if (p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
	                    {
	                        reqHandle = p_cInfo[pdp_table_index].reqHandle;
	                    }
	                    ATRESP(reqHandle, 0, 0, atBuf);
	                }
	            }
				//[klockwork][issue id: 2278]
				//else if(MtPdpCtxActedInd->pdpCtx.cid < CI_PS_MAX_CID)
				else if((MtPdpCtxActedInd->pdpCtx.pdpBearType == CI_PS_DEFAULT_PDP)
				&& (MtPdpCtxActedInd->pdpCtx.cid < CI_PS_MAX_CID))
				{
	                if(MtPdpCtxActedInd->isMEInitiated == FALSE)
	                {
	                	if((*pPsActDetail == 7) || (*pPsActDetail == 9))
	                	{
	                		sprintf(atBuf, "+CGEV: EPS PDN ACT ");
	                	}
						else
						{
							sprintf(atBuf, "+CGEV: NW PDN ACT ");
						}

	                    sprintf(tmpBuf, "%d\r\n", MtPdpCtxActedInd->pdpCtx.cid + 1);
	                    strcat(atBuf, tmpBuf);
	                    p_cInfo[pdp_table_index].bDefined = TRUE;
						p_cInfo[pdp_table_index].cid = MtPdpCtxActedInd->pdpCtx.cid;
	                    if (p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
	                    {
	                        reqHandle = p_cInfo[pdp_table_index].reqHandle;
	                    }
#ifdef LWIP_IPNETBUF_SUPPORT
				mt_pdp = TRUE;
				//updateAttachPdpApnInfo(MtPdpCtxActedInd->pdpCtx.apn.valStr, MtPdpCtxActedInd->pdpCtx.type);
				updateAttachPdpApnInfoDS(reqHandle, MtPdpCtxActedInd->pdpCtx.apn.valStr, MtPdpCtxActedInd->pdpCtx.type);
#endif
	                    ATRESP(reqHandle, 0, 0, atBuf);
	                }
	                else
	                {

	                    sprintf(atBuf, "+CGEV: ME PDN ACT ");
						if((MtPdpCtxActedInd->pdpReason == CI_PS_PDP_SINGLE_ONLY_ALLOWED_SEC_SUCC)
						&& (MtPdpCtxActedInd->cid_other < CI_PS_MAX_CID))
						{
							sprintf(tmpBuf, "%d,%d,%d\r\n", MtPdpCtxActedInd->pdpCtx.cid + 1, MtPdpCtxActedInd->pdpReason, MtPdpCtxActedInd->cid_other + 1);
						}
						else
						{
							sprintf(tmpBuf, "%d,%d\r\n", MtPdpCtxActedInd->pdpCtx.cid + 1, MtPdpCtxActedInd->pdpReason);
						}
	                    strcat(atBuf, tmpBuf);
	                    p_cInfo[pdp_table_index].bDefined = TRUE;
						p_cInfo[pdp_table_index].cid= MtPdpCtxActedInd->pdpCtx.cid;
	                    if (p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
	                    {
	                        reqHandle = p_cInfo[pdp_table_index].reqHandle;
	                    }
	                    ATRESP(reqHandle, 0, 0, atBuf);
	                }
	            }
				else
				{
					break;
				}
	        }
        	else
	        {
	            /* PDP type number */
	         //   getPdpTypeStr ( MtPdpCtxActedInd->pdpCtx.type, tmpBuf );
				//[klockwork][issue id: 2279]
	           // if(MtPdpCtxActedInd->pdpCtx.cid < CI_PS_MAX_CID)
	           	if(((MtPdpCtxActedInd->pdpCtx.pdpBearType == CI_PS_PRIMARY_PDP)
					||(MtPdpCtxActedInd->pdpCtx.pdpBearType == CI_PS_SECONDARY_PDP))
					&& (MtPdpCtxActedInd->pdpCtx.cid < CI_PS_MAX_CID))
	            {
	                if(MtPdpCtxActedInd->isMEInitiated == FALSE)
	                {
#ifdef LWIP_IPNETBUF_SUPPORT
                        mt_pdp = TRUE;
#endif
						sprintf(atBuf, "+CGEV: NW PDN ACT %d\r\n", MtPdpCtxActedInd->pdpCtx.cid + 1);
	                }
	                else
	                {
						if((MtPdpCtxActedInd->pdpReason == CI_PS_PDP_SINGLE_ONLY_ALLOWED_SEC_SUCC)
						&& (MtPdpCtxActedInd->cid_other < CI_PS_MAX_CID))
						{

							sprintf(atBuf, "+CGEV: ME PDN ACT %d,%d,%d\r\n", MtPdpCtxActedInd->pdpCtx.cid + 1, MtPdpCtxActedInd->pdpReason, MtPdpCtxActedInd->cid_other + 1);
						}
						else
						{
							sprintf(atBuf, "+CGEV: ME PDN ACT %d,%d\r\n", MtPdpCtxActedInd->pdpCtx.cid + 1, MtPdpCtxActedInd->pdpReason);
						}
	                }

					p_cInfo[pdp_table_index].bDefined = TRUE;
					p_cInfo[pdp_table_index].cid= MtPdpCtxActedInd->pdpCtx.cid;

					if (p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
					{
						reqHandle = p_cInfo[pdp_table_index].reqHandle;
					}

					ATRESP(reqHandle, 0, 0, atBuf);

	            }
				else
				{
					break;
				}

			}
#ifdef LWIP_IPNETBUF_SUPPORT
			setMtPdp(MtPdpCtxActedInd->pdpCtx.cid, mt_pdp);
	#ifdef ATCMD_PDP_CONTEXT
			if (MtPdpCtxActedInd->pdpCtx.apnPresent)
			{
				MtPdpCtxActedInd->pdpCtx.apn.valStr[MtPdpCtxActedInd->pdpCtx.apn.len] = '\0';
				telUpdatePdpInfoListEpsApn(MtPdpCtxActedInd->pdpCtx.cid + 1, MtPdpCtxActedInd->pdpCtx.apn.valStr, MtPdpCtxActedInd->pdpCtx.type);
			}
	#endif
			mtDataLinkAllowCheck(reqHandle, MtPdpCtxActedInd->pdpCtx.cid, MtPdpCtxActedInd->pdpCtx.pdpBearType);
#endif

			break;
		}

		/* Added by Daniel for LTE PC AT command server 20120117, end */

        /* Added by Daniel for LTE PC AT command server 20120319, begin */
		case CI_PS_PRIM_MT_PDP_CTX_ACT_MODIFY_IND:
		{
			char atBuf[200]="\0";
			char tmpBuf[50]="\0";

			int i;
			MtPdpCtxActModifyInd = (CiPsPrimMtPdpCtxActModifyInd *)pParam;

			//[klockwork][issue id: 2280]
	        //if(MtPdpCtxActModifyInd->pdpCtx.cid < CI_PS_MAX_CID)
			if(((MtPdpCtxActModifyInd->pdpCtx.pdpBearType == CI_PS_DEFAULT_PDP)
				||(MtPdpCtxActModifyInd->pdpCtx.pdpBearType == CI_PS_DEDICATED_PDP))
				&& (MtPdpCtxActModifyInd->pdpCtx.cid< CI_PS_MAX_CID))
	        {
	        	pdp_table_index = getPdpIndexByCid(MtPdpCtxActModifyInd->pdpCtx.cid,p_cInfo);
				telPsPdpCtx *psPdpInfo =  telGetPdpCtx(MtPdpCtxActModifyInd->pdpCtx.cid);
                if(psPdpInfo != NULL)
				    psPdpInfo->activedStatus = 1;

	            if(MtPdpCtxActModifyInd->actionType == CI_PS_ACT_IND_ACTION)
	            {
	                sprintf( atBuf, "+CGEV: EPS ACT ");
	                sprintf(tmpBuf, "%d\r\n", MtPdpCtxActModifyInd->pdpCtx.cid + 1);
	                strcat(atBuf, tmpBuf );
#ifdef LWIP_IPNETBUF_SUPPORT
			        sendQueryCgdcont(reqHandle);
#endif
	            }
	            else if(MtPdpCtxActModifyInd->actionType == CI_PS_MODIFY_IND_ACTION)
	            {
	                sprintf( atBuf, "+CGEV: NW MODIFY ");

	                sprintf(tmpBuf, "%d,", MtPdpCtxActModifyInd->pdpCtx.cid + 1);
	                strcat(atBuf, tmpBuf );

	                sprintf( tmpBuf, "%d\r\n",MtPdpCtxActModifyInd->change_reason);
	                strcat( atBuf, tmpBuf );
#ifdef LWIP_IPNETBUF_SUPPORT
				    sendQueryCgdcont(reqHandle);
					  //query and update TFT
               		updateMTPdpTft(reqHandle, MtPdpCtxActModifyInd->change_reason);
#endif
	            }
				else
				{
					break;
				}
				if (pdp_table_index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM)
				{
    				/*Fix coverity[overrun-local]*/
    				if (p_cInfo[pdp_table_index].reqHandle != INVALID_REQ_HANDLE)
    				{
    					reqHandle = p_cInfo[pdp_table_index].reqHandle;
    				}
				}
	        }

			ATRESP(reqHandle, 0, 0, atBuf);
			extern void usbnet_set_mode_disable( int cid);
			usbnet_set_mode_disable(MtPdpCtxActModifyInd->pdpCtx.cid);
			break;
		}

#ifdef VOLTE_ENABLE
		/* Added by Daniel for LTE PC AT command server 20120319, end */
		case CI_PS_PRIM_IMS_REG_INFO_IND:
		{
			//IMS registration information +CIREGU: <reg_info>[,<ext_info>]
			char atBuf[200]="\0";
			BOOL oldRegState=FALSE;
			CiPsPrimSetImsRegStateReq *setImsRegStateReq = NULL;
			UINT32 atHandle=0;
			BOOL hasDetail = FALSE;
			BOOL vopsSupported = FALSE;
			BOOL smsOverImsSupported = FALSE;

			imsRegInfoInd = (CiPsPrimImsRegInfoInd *)pParam;

			DBGMSG("[%s]:line(%d), CI_PS_PRIM_IMS_REG_INFO_IND received, report state is %d \n", __FUNCTION__, __LINE__, imsRegInfoInd->reportState);

			oldRegState = gImsRegState;
			if (imsRegInfoInd->reportState == CI_PS_NW_REG_IND_ENABLE_STA_ONLY)
			{
				sprintf(atBuf, "+CIREGU: %d", imsRegInfoInd->newInfo.regInfo);
				ATRESP( reqHandle, 0, 0, atBuf);
			}
			else if (imsRegInfoInd->reportState == CI_PS_NW_REG_IND_ENABLE_DETAIL)
			{
				sprintf(atBuf, "+CIREGU: %d, %d", imsRegInfoInd->newInfo.regInfo, imsRegInfoInd->newInfo.extInfo);
				ATRESP( reqHandle, 0, 0, atBuf);
			}
			else
			{
				//do nothing
			}
			*pImsRegState = (imsRegInfoInd->newInfo.regInfo == 1) ? TRUE : FALSE;
			DBGMSG("[%s]:line(%d), gImsRegState is %d \n", __FUNCTION__, __LINE__, *pImsRegState);

			//if the register state change, tell the new state to CP,
			//if ims stack run in CP in the feature, don't do this step.
			if (oldRegState != *pImsRegState)
			{
				if(reqHandle == IND_REQ_HANDLE)
					atHandle = MAKE_AT_HANDLE(TEL_AT_CMD_ATP_7);
				else
					atHandle = MAKE_AT_HANDLE(TEL_AT_CMD_ATP_44);

				setImsRegStateReq = (CiPsPrimSetImsRegStateReq *)utlCalloc(1, sizeof(CiPsPrimSetImsRegStateReq));
				setImsRegStateReq->state = imsRegInfoInd->newInfo.regInfo;
				ciRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_IMS_REG_STATE_REQ,
					MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_SET_IMS_REG_STATE_REQ), (void*)setImsRegStateReq);
			}

			break;
		}
		case CI_PS_PRIM_UE_EVENT_TO_IMS_IND:
		{
			ueEventToImsInd = (CiPsPrimUeEventToImsInd *)pParam;
			CiPsPrimSetImsRegStateReq *setImsRegStateReq = NULL;
			UINT32 atHandle;

			DBGMSG("[%s]:line(%d), CI_PS_PRIM_UE_EVENT_TO_IMS_IND received, reason is %d, now ims stack is %d \n",
				__FUNCTION__, __LINE__, ueEventToImsInd->ueEvent, *pImsRegState);
			if(ueEventToImsInd->ueEvent == CIPS_TO_IMS_EVENT_REATTACH)
			{
				char atBuf[200]="\0";

				sprintf(atBuf, "+CGEV: NW REATTACH");
				ATRESP( reqHandle, 0, 0, atBuf);
			}
			else
			{

				//send de-register message to IMS stack.
				if (ueEventToImsInd->imsNeedDeReg == 1)
				{
					/*Fixed coverity[leaked_storage]*/
					#if 0
					atHandle = MAKE_AT_HANDLE(TEL_AT_CMD_ATP_UART);
					setImsRegStateReq = (CiPsPrimSetImsRegStateReq *)utlCalloc(1, sizeof(CiPsPrimSetImsRegStateReq));
					setImsRegStateReq->state = 0; //send de-register to IMS stack.
					#endif
					//ciImsRequest( gAtciSvgHandle[CI_SG_ID_PS], CI_PS_PRIM_SET_IMS_REG_STATE_REQ,
					//	MAKE_CI_REQ_HANDLE(atHandle, CI_PS_PRIM_SET_IMS_REG_STATE_REQ), (void*)setImsRegStateReq);
				}
			}
			break;
		}
#endif		
#ifndef LTEONLY_THIN
		case CI_PS_PRIM_SUSPEND_RESUME_IND:
		{
			CiPsPrimSuspendResumeInd *suspendresumeind=NULL;

			suspendresumeind = (CiPsPrimSuspendResumeInd *)pParam;
			char atBuf[200]="\0";
			sprintf(atBuf, "*DATASTATUS: %d, %d", suspendresumeind->suspended,suspendresumeind->suspendReason);
			ATRESP( reqHandle, 0, 0, atBuf);

			break;
		}
#endif	

#ifndef MORE_ATC_SPACE_OPT	
		case CI_PS_PRIM_APN_BACKOFF_TIMER_STATUS_REPORT_IND:
		{
			processApnBackoffTimerStatusReportInd(reqHandle,pParam);
			break;
		}
#endif
		default:
			break;
	}

	/* free up the indication memory */
	atciSvgFreeIndMem( svgId, primId, pParam );

	F_LEAVE();

}
#endif /*MIN_SYS*/
	return;
}

#ifndef SINGLE_SIM

//ICAT EXPORTED FUNCTION - HW_PLAT, utilities, dumpPsInfo
void dumpPsInfo(volatile void *simId)
{
	UINT8 sim_id = (*(UINT8*)(simId));
	AtciCurrentSetCntx *p_cInfo;
	UINT8 index;
	if(sim_id == 0)
		p_cInfo = gCIDList.cInfo;
	else
		p_cInfo = gCIDList.cInfo_1;

	DIAG_FILTER(HW_PLAT, utilities, dumpPsInfo_0, writeUINT16a)
	diagPrintf ("sim ID=%d",sim_id);
	for( index = 0; index < CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM; index++ )
	{
		DIAG_FILTER(HW_PLAT, utilities, dumpPsInfo_1, writeUINT16a)
		diagPrintf ("item[%d]: cid=%d, bDefined=%d,reqHandle=0x%lx, connectionType=%d,pdpType=%d",index,p_cInfo[index].cid,p_cInfo[index].bDefined,\
		p_cInfo[index].reqHandle,p_cInfo[index].connectionType,p_cInfo[index].pdpType);
	}


}
#endif


#ifdef PLATFORM_FOR_PS_LW
int getPSNwReg(void)
{
	if (gPsActDetail == 7) return 0;

	if (gCurrentPSRegStatus == CI_PS_NW_REG_STA_REG_HPLMN ||
		gCurrentPSRegStatus == CI_PS_NW_REG_STA_REG_ROAMING)
		return 1;
	return 0;
}
#else
int getPSNwReg(void)
{
	int simID = SIMInPS;
	int psActDetail,psActDetail_1;
	int currentPSRegStatus,currentPSRegStatus_1;
	int current4gPSRegStatus,current4gPSRegStatus_1;

#ifndef SINGLE_SIM
	
		if(simID == 0)
		{
			psActDetail = psActDetail_1= gPsActDetail;
			currentPSRegStatus = currentPSRegStatus_1 = gCurrentPSRegStatus;
			current4gPSRegStatus = current4gPSRegStatus_1 = g4gCurrentPSRegStatus;
		}
		else if(simID == 1)
		{
			psActDetail = psActDetail_1= gPsActDetail_1;
			currentPSRegStatus = currentPSRegStatus_1 = gCurrentPSRegStatus_1;
			current4gPSRegStatus = current4gPSRegStatus_1 = g4gCurrentPSRegStatus_1;
		}
		else
		{
			psActDetail = gPsActDetail;
			psActDetail_1 = gPsActDetail_1;
	
			currentPSRegStatus = gCurrentPSRegStatus;
			currentPSRegStatus_1 = gCurrentPSRegStatus_1;
	
			current4gPSRegStatus = g4gCurrentPSRegStatus;
			current4gPSRegStatus_1 = g4gCurrentPSRegStatus_1;
		}
	
	#if 0
		if (psActDetail == 7 || psActDetail_1 == 7) return 1;
	#endif
		if (currentPSRegStatus == CI_PS_NW_REG_STA_REG_HPLMN ||
			currentPSRegStatus == CI_PS_NW_REG_STA_REG_ROAMING ||
			currentPSRegStatus_1 == CI_PS_NW_REG_STA_REG_HPLMN ||
			currentPSRegStatus_1 == CI_PS_NW_REG_STA_REG_ROAMING||
			current4gPSRegStatus == CI_PS_NW_REG_STA_REG_HPLMN ||
			current4gPSRegStatus == CI_PS_NW_REG_STA_REG_ROAMING ||
			current4gPSRegStatus_1 == CI_PS_NW_REG_STA_REG_HPLMN ||
			current4gPSRegStatus_1 == CI_PS_NW_REG_STA_REG_ROAMING)
			return 1;
		return 0;
	
#else
	
			psActDetail = gPsActDetail;
	
			currentPSRegStatus = gCurrentPSRegStatus;
	
			current4gPSRegStatus = g4gCurrentPSRegStatus;
	
	
#if 0
		if (psActDetail == 7 || psActDetail_1 == 7) return 1;
#endif
		if (currentPSRegStatus == CI_PS_NW_REG_STA_REG_HPLMN ||
			currentPSRegStatus == CI_PS_NW_REG_STA_REG_ROAMING ||
			current4gPSRegStatus == CI_PS_NW_REG_STA_REG_HPLMN ||
			current4gPSRegStatus == CI_PS_NW_REG_STA_REG_ROAMING)		
			return 1;
		return 0;

#endif
}


#endif

CiReturnCode PS_InitRegOption (UINT32 atHandle)
{
#ifndef TEL_REG_OPTION_PERSIST
    return CIRC_SUCCESS;
#else
	CiReturnCode  ret = CIRC_SUCCESS;
	int option;
#ifndef MIN_SYS
    if(!IsMiniSystem())
    {
    	option = getRegOptionPersist(0);
        ret = MM_SetRegOption(atHandle, option);

        option = getRegOptionPersist(1);
    	ret = PS_SetGPRSRegStatus(atHandle, option);

        option = getRegOptionPersist(2);
    	ret = PS_Set4GRegOption(atHandle, option);
	}
#endif
	return ret;
	
#endif
}

void loadPSRegOptionSetting(void)
{
    char *str = NULL;

    CPUartLogPrintf("%s: enter",__FUNCTION__);

#ifndef LTEONLY_THIN
    //2G current option
    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "2G_curOption_sim0_IMS");
    if(str)
    {
        gCurrRegOption[0] = atoi(str);
        CPUartLogPrintf("%s: 2G gCurrRegOption[0] %s %d",__FUNCTION__, str, gCurrRegOption[0]);
        free(str);
    }

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "2G_curOption_sim0_None_IMS");
    if(str)
    {
        gCurrRegOption[1] = atoi(str);
        CPUartLogPrintf("%s: 2G gCurrRegOption[1] %s %d",__FUNCTION__, str, gCurrRegOption[1]);        
        free(str);
    }
	
#ifndef SINGLE_SIM

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "2G_curOption_sim1_IMS");
    if(str)
    {
        gCurrRegOption_1[0] = atoi(str);
        CPUartLogPrintf("%s: 2G gCurrRegOption_1[0] %s %d",__FUNCTION__, str, gCurrRegOption_1[0]);        
        free(str);
    }

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "2G_curOption_sim1_None_IMS");
    if(str)
    {
        gCurrRegOption_1[1] = atoi(str);
        CPUartLogPrintf("%s: 2G gCurrRegOption_1[1] %s %d",__FUNCTION__, str, gCurrRegOption_1[1]);          
        free(str);
    }
#endif

    //2G reg option
    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "2G_regOption_sim0_IMS");
    if(str)
    {
        gRequestedRegOption[0] = atoi(str);
        CPUartLogPrintf("%s: 2G gRequestedRegOption[0] %s %d",__FUNCTION__, str, gRequestedRegOption[0]);        
        free(str);
    }

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "2G_regOption_sim0_None_IMS");
    if(str)
    {
        gRequestedRegOption[1] = atoi(str);
        CPUartLogPrintf("%s: 2G gRequestedRegOption[1] %s %d",__FUNCTION__, str, gRequestedRegOption[1]);          
        free(str);
    }

#ifndef SINGLE_SIM

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "2G_regOption_sim1_IMS");
    if(str)
    {
        gRequestedRegOption_1[0] = atoi(str);
        CPUartLogPrintf("%s: 2G gRequestedRegOption_1[0] %s %d",__FUNCTION__, str, gRequestedRegOption_1[0]);         
        free(str);
    }

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "2G_regOption_sim1_None_IMS");
    if(str)
    {
        gRequestedRegOption_1[1] = atoi(str);
        CPUartLogPrintf("%s: 2G gRequestedRegOption_1[1] %s %d",__FUNCTION__, str, gRequestedRegOption_1[1]);           
        free(str);
    }    
#endif

    //3G current option
    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "3G_curOption_sim0_IMS");
    if(str)
    {
        gCurrentPSRegOption[0] = atoi(str);
        CPUartLogPrintf("%s: 3G gCurrentPSRegOption[0] %s %d",__FUNCTION__, str, gCurrentPSRegOption[0]);        
        free(str);
    }

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "3G_curOption_sim0_None_IMS");
    if(str)
    {
        gCurrentPSRegOption[1] = atoi(str);
        CPUartLogPrintf("%s: 3G gCurrentPSRegOption[1] %s %d",__FUNCTION__, str, gCurrentPSRegOption[1]);         
        free(str);
    }

#ifndef SINGLE_SIM

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "3G_curOption_sim1_IMS");
    if(str)
    {
        gCurrentPSRegOption_1[0] = atoi(str);
        CPUartLogPrintf("%s: 3G gCurrentPSRegOption_1[0] %s %d",__FUNCTION__, str, gCurrentPSRegOption_1[0]);         
        free(str);
    }

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "3G_curOption_sim1_None_IMS");
    if(str)
    {
        gCurrentPSRegOption_1[1] = atoi(str);
        CPUartLogPrintf("%s: 3G gCurrentPSRegOption_1[1] %s %d",__FUNCTION__, str, gCurrentPSRegOption_1[1]);         
        free(str);
    }
#endif

    //3G reg option
    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "3G_regOption_sim0_IMS");
    if(str)
    {
        gPSRequestedRegOption[0] = atoi(str);
        CPUartLogPrintf("%s: 3G gPSRequestedRegOption[0] %s %d",__FUNCTION__, str, gPSRequestedRegOption[0]);         
        free(str);
    }

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "3G_regOption_sim0_None_IMS");
    if(str)
    {
        gPSRequestedRegOption[1] = atoi(str);
        CPUartLogPrintf("%s: 3G gPSRequestedRegOption[1] %s %d",__FUNCTION__, str, gPSRequestedRegOption[1]);         
        free(str);
    }

#ifndef SINGLE_SIM

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "3G_regOption_sim1_IMS");
    if(str)
    {
        gPSRequestedRegOption_1[0] = atoi(str);
        CPUartLogPrintf("%s: 3G gPSRequestedRegOption_1[0] %s %d",__FUNCTION__, str, gPSRequestedRegOption_1[0]);         
        free(str);
    }

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "3G_regOption_sim1_None_IMS");
    if(str)
    {
        gPSRequestedRegOption_1[1] = atoi(str);
        CPUartLogPrintf("%s: 3G gPSRequestedRegOption_1[1] %s %d",__FUNCTION__, str, gPSRequestedRegOption_1[1]);          
        free(str);
    }
#endif
#endif	

    //4G current option
    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "4G_curOption_sim0_IMS");
    if(str)
    {
        g4gCurrentPSRegOption[0] = atoi(str);
        CPUartLogPrintf("%s: 4G g4gCurrentPSRegOption[0] %s %d",__FUNCTION__, str, g4gCurrentPSRegOption[0]);          
        free(str);
    }

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "4G_curOption_sim0_None_IMS");
    if(str)
    {
        g4gCurrentPSRegOption[1] = atoi(str);
        CPUartLogPrintf("%s: 4G g4gCurrentPSRegOption[1] %s %d",__FUNCTION__, str, g4gCurrentPSRegOption[1]);         
        free(str);
    }

#ifndef SINGLE_SIM

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "4G_curOption_sim1_IMS");
    if(str)
    {
        g4gCurrentPSRegOption_1[0] = atoi(str);
        CPUartLogPrintf("%s: 4G g4gCurrentPSRegOption_1[0] %s %d",__FUNCTION__, str, g4gCurrentPSRegOption_1[0]);         
        free(str);
    }

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "4G_curOption_sim1_None_IMS");
    if(str)
    {
        g4gCurrentPSRegOption_1[1] = atoi(str);
        CPUartLogPrintf("%s: 4G g4gCurrentPSRegOption_1[1] %s %d",__FUNCTION__, str, g4gCurrentPSRegOption_1[1]);         
        free(str);
    }
#endif

    //4G reg option
    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "4G_regOption_sim0_IMS");
    if(str)
    {
        g4gPSRequestedRegOption[0] = atoi(str);
        CPUartLogPrintf("%s: 4G g4gPSRequestedRegOption[0] %s %d",__FUNCTION__, str, g4gPSRequestedRegOption[0]);         
        free(str);
    }

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "4G_regOption_sim0_None_IMS");
    if(str)
    {
        g4gPSRequestedRegOption[1] = atoi(str);
        CPUartLogPrintf("%s: 4G g4gPSRequestedRegOption[1] %s %d",__FUNCTION__, str, g4gPSRequestedRegOption[1]);         
        free(str);
    }

#ifndef SINGLE_SIM

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "4G_regOption_sim1_IMS");
    if(str)
    {
        g4gPSRequestedRegOption_1[0] = atoi(str);
        CPUartLogPrintf("%s: 4G g4gPSRequestedRegOption_1[0] %s %d",__FUNCTION__, str, g4gPSRequestedRegOption_1[0]);        
        free(str);
    }

    str = psm_get_wrapper(PSM_MOD_LOCALE, NULL, "4G_regOption_sim1_None_IMS");
    if(str)
    {
        g4gPSRequestedRegOption_1[1] = atoi(str);
        CPUartLogPrintf("%s: 4G g4gPSRequestedRegOption_1[1] %s %d",__FUNCTION__, str, g4gPSRequestedRegOption_1[1]);         
        free(str);
    }
#endif

    str = NULL;
}
#ifdef GPS_SUPPORT
#define GPS_GET_CELLID (13)
extern char asr_gps_msgQ_send2(unsigned int event, void *arg);
extern bool check_gps_atcmd_task_and_msgQ(void);
void asr_gps_handle_cellID(void *regInd)
{
#ifndef MIN_SYS
    if(!IsMiniSystem())
    {
        CiPsPrim4GNwRegInd *nw4gRegInd = NULL;
        char *buffer = NULL;
        unsigned char ret = 0;
        if (regInd)
        {
            nw4gRegInd = (CiPsPrim4GNwRegInd *)regInd;
            CPUartLogPrintf("%s: get cellID is 0x%lx", __FUNCTION__, nw4gRegInd->nwRegInfo.cellId);
            if (check_gps_atcmd_task_and_msgQ())
            {
                buffer = (char *)malloc(16);
                if (buffer)
                {
                    memset(buffer, 0x00, 16);
                    snprintf(buffer, 16, "%u", nw4gRegInd->nwRegInfo.cellId);
                    ret = asr_gps_msgQ_send2(GPS_GET_CELLID, buffer);
                    CPUartLogPrintf("%s: send msgq ret[%d]", __FUNCTION__, ret);
                    if (0 != ret)
                    {
                        free(buffer);
                        buffer = NULL;
                    }
                }
                else
                {
                    CPUartLogPrintf("%s: malloc fialed.", __FUNCTION__);
                }
            }
        }
    }
#endif
    return;
}
#endif
