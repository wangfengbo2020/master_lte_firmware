#ifndef _CM_
#define _CM_

#include "Dialer_Task.h"

#define BYPASS_FLAG_MBIM_BIT 0
#define NO_MO_SECONDARY
#define SAC_SAVE_PDP_CONTEXT
#define MAX_PDP_NAME_LEN 64
#define CM_DUAL_SIM_SUPPORT
#define CM_UI_API
#define CM_SIM_HOTPLUG_SUPPORT

#ifdef CRANE_MCU_DONGLE
#ifdef SINGLE_SIM
#undef CM_DUAL_SIM_SUPPORT
#endif

#undef CM_UI_API
#undef WEBUI_SUPPORT
/* test only, MMI should set radio power on*/
#ifdef  CM_DUAL_SIM_SUPPORT
#define CM_FORCE_RADIO_POWER_ON
//#else
//#undef CM_DUAL_SIM_SUPPORT
#endif
#endif

#define CM_INVALID_CID				0xff
#define CM_LOG_DEBUG 3
#define CM_LOG_CRITIC 2
#define CM_LOG_ERROR 1

#ifdef LTEONLY_THIN
#define	CM_LOG_LEVEL 2
#else
#define CM_LOG_LEVEL 3
#endif

#define CM_Log(format,...) 	\
        {if(CM_LOG_LEVEL >= CM_LOG_DEBUG) CPUartLogPrintf(format, ##__VA_ARGS__);}

#define CM_Log_Critic(format,...) 	\
        {if(CM_LOG_LEVEL >= CM_LOG_CRITIC) CPUartLogPrintf(format, ##__VA_ARGS__);}

#define CM_Log_Error(format,...) 	\
        {if(CM_LOG_LEVEL >= CM_LOG_ERROR) CPUartLogPrintf(format, ##__VA_ARGS__);}


#ifndef NO_DIALER
typedef struct{
	char connection_type; //0-cullular, 1-WIFI
	char connection_num;
	char re_connect;     //first init as 0, for secondary link, if the according primary link hasn't dial successful, init as 1
	char pri_con_num;   //just for secondary, 0 for primary
	char PDP_name[MAX_PDP_NAME_LEN];
	bool cid_specified;
	PdpInfo * pdpinfo;
	PacketFilterInfo  * tftinfo;
} Connection_Setup_Context;

typedef struct{
	char DeleteAll;
	char CID;
	char IsDefaultConnection;  // 1 for default and 0 for else
	char IsPrimaryConnection;  // 1 for primary and 0 for secondary
	char ConnectionNum;
}DisconnectInfo;

typedef struct{
	UINT8 cid;
}DeleteContextMsg;

typedef struct{
	UINT8 serviceEnable;
}PSServiceOptionMsg;

typedef struct{
	UINT8 state;
}RadioPowerStateMsg;

typedef struct
{
	Connection_Setup_Context cm_pdp_conext;
	char enable;
} Duster_PDP_Setup_Context;

typedef struct _Connection_Setup_Context
{
	Duster_PDP_Setup_Context duster_pdp_conext;
	struct  _Connection_Setup_Context *next;
} Connection_Setup_Context_list;
#endif

typedef struct{
	char connect_status;
	char connection_num;
	char PDP_name[MAX_PDP_NAME_LEN];
	PdpInfo * pdpinfo;
	Ipv4Info * ip4info;
	Ipv6Info * ip6info;
	PacketFilterInfo *tftinfo;
	void * next;
} LinkStatus_Context;

typedef struct{
	char connect_status;
	char connection_num;
	char pri_con_num;
	char create_by;
	char IP_Type_my;
	char PDP_name[MAX_PDP_NAME_LEN];
	bool cid_specified;
	DialerReasonCode rescode;
	PdpInfo * pdpinfo;
	Ipv4Info * ip4info;
	Ipv6Info * ip6info;
	PacketFilterInfo *tftinfo;
	void * next;
}CM_Connection_Context;

enum cmCtxCreator
{
	CM_CTX_CREATOR_APP,
	CM_CTX_CREATOR_SELF,
	CM_CTX_CREATOR_AT,
	CM_CTX_CREATOR_NW,
	CM_CTX_CREATOR_MAX
};

enum cmConnState
{
	CM_CONNECT_INIT,
	CM_CONNECT_CONSUCCESS,
	CM_CONNECT_CONNING,
	CM_CONNECT_DISCON,
	CM_CONNECT_DISCONNING,
	CM_CONNECT_REDIAL,
	CM_CONNECT_ROAM,
	CM_CONNECT_DEACTIVED,
};

enum cmIpType
{
	CM_IPTYPE_IPV4V6,
	CM_IPTYPE_IP,
	CM_IPTYPE_IPV6,
};

typedef enum
{
    CM_DUAL_SIM_DUAL_STANDBY,
    CM_DUAL_SIM_SINGLE_STANDBY,
    CM_DUAL_SIM_SGIT,
    CM_DUAL_SIM_DUAL_STANDBY_FP,
}CMDualSimType;

typedef enum
{
	CM_SIM_0,
	CM_SIM_1,
	NUM_OF_CM_SIM
}CMSimID;

typedef enum
{
	SIM_REMORE_SIM_NO_CHANGE,
	SIM_REMORE_SIM1_TO_SIM2,
	SIM_REMORE_SIM2_TO_SIM1
}CMSimIDResetType;

typedef enum
{
	CM_SIM_SWITCH_INIT,
	CM_SIM_SWITCH_START,
	CM_SIM_SWITCH_PRESIM_PDP_DOWN,
	CM_SIM_SWITCH_PRESIM_IMS_DOWN,
	CM_SIM_SWITCH_PRESIM_PSDC_DOWN,
	CM_SIM_SWITCH_CURRSIM_PDP_UP,
#ifdef CRANE_DSS
	CM_SIM_SWITCH_CURRSIM_CFUN0,
#endif
    CM_SIM_SWITCH_PRESIM_IMS_UP,
	CM_SIM_SWITCH_CURRSIM_PSDC_UP,
	CM_SIM_SWITCH_ERROR
}CMSimSwitchState;
typedef void (*SwitchSimDoneCb)(UINT8);
typedef struct {
	CMSimID currSim;
	UINT8 state;
	UINT8 waitDone;
	SwitchSimDoneCb switchDone;
}SimSwitchCtx;

typedef struct {
	CHAR apn[MAX_APN_INFO_LEN];
	/* 1-15 */
	UINT8 cid;
	UINT8 ipType;
	/**
	* isDefault 1: will modify LTE attach APN when call CM_SetPdpState to active the PDP context,
	* the cid value should only set to 1, specify other value will return error
	* 0: will create a new PDP context with cid
	*/
	UINT8 isDefault;
} ApnInfo_s;

typedef struct {
	CHAR username[MAX_STRING_LEN];
	CHAR password[MAX_STRING_LEN];
	UINT8 cid;
	/* 0: NONE, 1: PAP, 2: CHAP*/
	UINT8 authType;
} AuthInfo_s;

typedef struct {
	UINT8 cid;
	BOOL state; /*0: deactive data call, 1: setup data call*/
} PdpState_s;

//interface for webUI
#ifndef NO_DIALER
void CM_Set_Connection_Type(int connection_type);
int CM_Create_Connection(Connection_Setup_Context *s_context);
void CM_Connection_free(Connection_Setup_Context *s_context);
int CM_Destroy_Connection(DisconnectInfo *dis_coninfo);
int CM_Destroy_Connection_free(DisconnectInfo *dis_coninfo);
void CM_Context_Struct_free(CM_Connection_Context * CM_Context);
int CM_SetupDefaultConnection(void);
#ifdef WEBUI_SUPPORT
int CM_Update_Tft(TftInfoList_webUI * plist);
//free tftlist for webUI module
void TFTlist_webUI_free(TftInfoList_webUI * list);
#endif
INT32 CM_DeactiveDataCallAll(void);
#endif
char is_4g_mode(void);
void setRemapFlag(UINT8 flag);
void setDefaultCidFlag(UINT8 flag);
void setOptimizeEtifFlag(UINT8 flag);
BOOL getOptimizeEtifFlag(void);
BOOL isImsRegistered(CMSimID simID);
void CM_clear_first_dial_flag(void);
void set_linkstas(UINT8 cid, BOOL link_ok);
char get_linkstas(char cid);
char OLED_get_dialer_linkstas(void);
void showConContext(CM_Connection_Context *Pdp);
void showPFInfo(PacketFilterInfo *PF_info);
UINT8 get_free_cid(void);
void hold_cid(char cid);
BOOL matchApn(char *eps_apn, char *apn);
void TFTinfo_free(PacketFilterInfo * src_pfinfo);
BOOL CM_allowSetNetif(void);
void CM_init(void);
void UIRefresh_Modem_Change(void);
#if QUECTEL_PROJECT_CUST
BOOL configureLwipNetif(UINT8 status, UINT8 cid, UINT8 rndis_type);
#else
void configureLwipNetif(UINT8 status, UINT8 cid, UINT8 rndis_type);
#endif
//free tft info list, called by TFT module
void TFTlist_free(TftInfoList_CM * list);
/*mode: 0 (CONNECT_MODE_AUTO), 1(CONNECT_MODE_MANUAL)*/
void initConnectMode(UINT8 mode);
const CHAR *convertCmConnStateToString(INT32 state);

#if defined(CM_UI_API) && !defined(NO_DIALER)
/**
* @return 0: configure parameters into CM OK, -1: ERROR
* please refer to telps.c->ciSetCmContext() for usage
*/
INT32 CM_ConfigApnInfo(ApnInfo_s *info);

/* @return 0: configure parameters into CM OK, -1: ERROR */
INT32 CM_ConfigAuthInfo(AuthInfo_s *info);

/* @return 0: set pdp state into CM OK, -1: ERROR
*  please refer to telps.c->ciCmPDPActivate() for usage
*/
INT32 CM_SetPdpState(PdpState_s *info);

/**
* register data call state change callback
* connect or disconnect a data call successfully or fail will be called
* please refer to telps.c->pdpOnStateChange() for callback usage
*/
INT32 CM_RegisterStateChangedCb(UINT8 cid, StateChangedCb cb);

INT32 CM_SetupDataCall(UINT8 cid);
INT32 CM_DeactiveDataCall(UINT8 cid);
#endif
/**
* changeable 0: enable data on roaming , 1: disable data on roaming
*/
void CM_Set_ConnectType_WEBUI(int changeable);

/**
* @input onOff 0: not allow to active data, deactive all data connections, 1: allow to active data, and setup default internet connection
* @return 0:OK, -1: ERROR
*/
INT32 CM_SetConnectionSwitch(BOOL onOff);

/**
* get allow data connection flag
* @return 0: not allow data connection, 1: allow data connection
*/
BOOL CM_GetConnectionSwitch(void);

/**
* get CM connection number with cid, the cid is matched with CI,  if connection is setuped using above CM_Config*
* cid should minus 1
*/
char CM_Get_ConnectionNum(UINT8 cid);

/**
* get LinkStatus_Context with specified connection number
* should call free_link_status(ctx) in caller
*/
LinkStatus_Context *CM_Get_LinkStatus(char connection_num);

/**
* free link context get by CM_Get_LinkStatus
*/
void free_link_status(LinkStatus_Context *link_status);

/**
* get default cid for auto connect
*/
UINT8 getDefaultCidNum(void);

/**
* Some applications will not config APN anyway
* Before using data, should check whether data is available
* @reurn 1: data is available 0: data isn't available
*/
BOOL CM_GetDefaultConnectStatus(void);

#ifndef NO_DIALER
#ifdef CM_DUAL_SIM_SUPPORT
/**
* switch sim to master, will deactive data connection for pre-sim
* For connect auto mode and apn auto mode , will setup data connection for current sim
* For other configuration, upper layer should invoke CM_Config* APIs to configure APN info for current sim
* Then active the data connection by CM_SetupDataCall
* @ input simID: sim will be configured as master sim,  cb: switch SIM done will be invoked
* @ return 0: simID is accepted and triggered switch process,  -1: simID is out of range or no need swtich
*/
INT32 CM_SetMasterSimID(CMSimID simID, SwitchSimDoneCb cb);
#endif

#ifdef CM_UI_API
/**
* get default connection APN name
* @ input name: buffer to get apn name string, name_len: buffer len of name
* @ return 0: get default name successfully -1: get default name failed
*/
int CM_GetDefaultApnName(char *name, int name_len);
#endif
#endif
INT32 setLwipNetifDns(UINT8 cid, CHAR *dns1, CHAR *dns2);
#ifdef QUECTEL_PROJECT_CUST
INT32 setLwipNetifIp6dns(UINT8 cid, CHAR *dns1, CHAR *dns2);
#endif
INT32 getLwipNetifDns(UINT8 cid, CHAR *dns1, CHAR *dns2);
#ifdef QUECTEL_PROJECT_CUST
INT32 getLwipNetifIp6dns(UINT8 cid, CHAR *dns1, CHAR *dns2);
#endif
INT32 lwipNetifExist(UINT8 cid);
INT32 getLwipNetifRef(UINT8 cid);
/**
* get master sim id
* @ return 0: SIM1 1: SIM2
*/
int getMasterSimID(void);
BOOL isMasterSim0(void);
void cmUpdateNwStatus(int simID, char status);
/* 
*@ return 0: dual sim dual standby 1: dual sim single standby 2: dual sim for SGIT
**/
int getDualSimType(void);
int setDualSimType(int type);

#ifndef MIN_SYS
#ifdef CM_DUAL_SIM_SUPPORT
int quec_get_dualSimType(void);
#endif
#endif
/* 
*@ return 0: non roamning 1: roaming for current sim
**/
UINT8 CM_GetRoamingStatus(CMSimID simID);

/* 
*@ dataOn 1: roamning data on 0: roaming data off
**/
void CM_SetDataOnRoaming(int dataOn);
int CM_GetDataOnRoaming(void);

/* 
* dataOn setting will be saved and take effect after reboot
**/
void CM_SetDataOnRoamingPersist(int dataOn);

int CM_Delete_Context(BOOL flag);


#endif
