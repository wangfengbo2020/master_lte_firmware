/* -*- linux-c -*- */
/*******************************************************************************
*               Copyright 2009, Marvell Technology Group Ltd.
*
* THIS CODE CONTAINS CONFIDENTIAL INFORMATION OF MARVELL. NO RIGHTS ARE GRANTED
* HEREIN UNDER ANY PATENT, MASK WORK RIGHT OR COPYRIGHT OF MARVELL OR ANY THIRD
* PARTY. MARVELL RESERVES THE RIGHT AT ITS SOLE DISCRETION TO REQUEST THAT THIS
* CODE BE IMMEDIATELY RETURNED TO MARVELL. THIS CODE IS PROVIDED "AS IS".
* MARVELL MAKES NO WARRANTIES, EXPRESS, IMPLIED OR OTHERWISE, REGARDING ITS
* ACCURACY, COMPLETENESS OR PERFORMANCE. MARVELL COMPRISES MARVELL TECHNOLOGY
* GROUP LTD. (MTGL) AND ITS SUBSIDIARIES, MARVELL INTERNATIONAL LTD. (MIL),
* MARVELL TECHNOLOGY, INC. (MTI), MARVELL SEMICONDUCTOR, INC. (MSI), MARVELL
* ASIA PTE LTD. (MAPL), MARVELL JAPAN K.K. (MJKK), GALILEO TECHNOLOGY LTD. (GTL)
* GALILEO TECHNOLOGY, INC. (GTI) AND RADLAN Computer Communications, LTD.
********************************************************************************
*/
#ifndef __DUSTER_H__
#define __DUSTER_H__
//#include "csw_mrv_mem.h"
#include "osa.h"
#include "UART.h"


#define SUPPORT_SD_UPGRADE

#define DEFAULT_PDN_NAME "Default PDN"
#define DEFAULT_APN "cmnet"
#define DEFAULT_IPTYPE 1
#define DEFALT_PDPTYPE 1
#define PSM_TAG_AID "aid"
#define PSM_TAG_TAR "tar"
#define PSM_TAG_SQ_INTERVAL "interval"
#define SYSINFO_PSM_MODULE "tr069"
#define DEFAULT_AID "1073676974672E736763632E6578740001"
#define DEFAULT_SEND_SQ_INTERVAL "00000500"

#define dusterDebug(fmt,args...) CPUartLogPrintf(fmt, ##args)
#define dusterError(fmt,args...)  CPUartLogPrintf(fmt, ##args)

#ifndef duster_free
#define duster_free(p) free(p)
#endif

#ifndef duster_malloc
#define duster_malloc(p) malloc(p)
#endif


#ifndef PSM_MOD_WAN
#define PSM_MOD_WAN   "wan"
#endif

#ifndef SYSINFO_PSM_MODULE
#define SYSINFO_PSM_MODULE "sysinfo"
#endif

typedef enum _EventMsgType
{
	client_connected = 0,
	client_disconnected,
	lwip_add_PC,
	lwip_add_WLAN_client,
	lwip_delete_PC,
	lwip_delete_WLAN_client,
	msg_send_sq,
	SEND_AT,
	SEND_AT_1, /* msg for SIM1 */
	/* below MSG should with out data*/
	DM_REGISTER,
	CellularStart,
	searchNW,
	QUERY_CGDCONT,
	QUERY_CGDCONT_1,  /* msg for SIM1 */
	SIM_INIT,
	update_time_from_NITZ,
	qurey_time_from_NW,
	wan_start_after_provide_pin,
	CHECK_CURRENT_PLMN,
	tr069_helper_run,
	AutoSelectNW,
	/*check SIM card hotplug in  for one time*/
	SIM_HOTPLUG_IN,
	/*Send AT+CIMI because sim hot insert*/
	SIM_HOTPLUG_IN_CIMI,
	/*Reset ALL,SMS settings on inserted SMS CARD*/
	SIM_RESET_SMS_SETTING,
	/*ReDO some SMS settings on inserted SMS CARD*/
	SIM_REDO_THE_SMS_SETTING,
	WAN_INIT,
	WAN_INIT_1, /* for SIM1*/
	send_cgdont,
	send_cgdont_1,
	DOWNLOAD_PROFILE,
	DOWNLOAD_PROFILE_1,
    ENV_CFG,
} EventMsgType;

#ifdef QUECTEL_PROJECT_CUST
typedef EventMsgType _Wlan_Client_Status_Msg;

typedef struct S_WlanClientStatusMessage
{
    _Wlan_Client_Status_Msg MsgId; 
    CHAR *MsgData;
} WlanClientStatusMessage;
#endif

typedef struct _EventMsg
{
    EventMsgType id;
    CHAR *data;
} EventMsg;

typedef enum E_Fast_Event_Handler_Msg
{
    ResetPS = 0,
	SyncNITZ = 1
}_Fast_Event_Handler_Msg;
typedef struct S_FastEventHandlerMessage
{
    _Fast_Event_Handler_Msg MsgId; 
    CHAR *MsgData;
} FastEventHandlerMessage;
typedef enum E_Save_PSM_Msg
{
    start_save_psm = 0
} _Save_PSM_Msg;

typedef struct S_SavePSM
{
    _Save_PSM_Msg MsgId;
    void *MsgData;
} SavePSMMessage;

#define conTimeNum   30
#define MAC_BYTES 6

typedef struct S_conTime
{
    char connectTime[20];
    char disconnectTime[20];
    char MAC[MAC_BYTES];
    char rsv[2];
} conTime;

typedef struct S_CommandATMsg{
	char * atcmd;
	char* ok_fmt;
	char* err_fmt;
	UINT8 ok_flag;
	UINT16 ATCMD_TYPE;
	UINT8 (*callback_func)(UINT8 OK_flag,char *resp,UINT8 cmd_type);
	}CommandATMsg;

typedef struct _sd_firmware_flag {
	unsigned int header;
	unsigned int upgrade_flag;
	unsigned int fbf_flash_address;
	unsigned int fbf_file_size;
	unsigned int erase_psm;
	unsigned int erase_psm_address;
	unsigned int erase_psm_size;
	unsigned int erase_filesystem;
	unsigned int erase_filesystem_address;
	unsigned int erase_filesystem_size;
	unsigned int upgrade_method;// 0: TR069 2:SD 3: Web-UI 4: restricted system
	unsigned int webdata_lzma2; // 1: need unzip and rewrite
	unsigned int webdata_addrss;
	unsigned int webdata_len;
	unsigned int wifi_nocal_lzma2;
	unsigned int wifi_nocal_addrss;
	unsigned int wifi_nocal_len;
	unsigned int wifi_lzma2;
	unsigned int wifi_addrss;
	unsigned int wifi_len;
	unsigned int version_flag;
	char full_system_version[64];
}s_sd_firmware_flag;

typedef enum
{
	SEARCH_NETWORK_INIT,
	SEARCH_NETWORK_START,
	SEARCH_NETWORK_SELECT_START,
	SEARCH_NETWORK_SELECT_DONE
}eSearchNetworkFlag;

typedef enum
{
	CONNECT_MODE_AUTO = 0,
	CONNECT_MODE_MANUAL
}eConnectMode;

typedef enum
{
	APN_MODE_MANUAL = 0,
	APN_MODE_AUTO
}eApnMode;

typedef enum RESP_STATUS{
	RESP_OK = 0,
	RESP_CME_ERROR,
	RESP_INVALID_PARAM,
	RESP_TIME_OUT,
	RESP_SYS_ERROR,
}E_RESP_STATUS;

typedef struct
{
	UINT8 utYear;
	UINT8 utMonth;
	UINT8 utDay;
	UINT8 utHour;
	UINT8 utMinute;
	UINT8 utSecond;
	INT8  timeZoneInd;	
}nitz_time_s;
typedef int AT_RESP_STATUS;
void updateTimeFromNitz(UINT8 year, UINT8 month, UINT8 day, UINT8 hour, UINT8 min, UINT8 sec, int timezone);

/**
*@brief  enable/disable get time using NTP.
*@input  enable:1 force to get time using NTP
*/
void enableAutoTime(BOOL enable);

/**
*@brief  enable/disable get time zone using NITZ.
*
*/
void enableAutoTimeZone(BOOL enable);
int GetTimeZone(void);
BOOL isNTPEnabled(void);
void setConnectMode(UINT8 mode, BOOL persist);
UINT8 getConnectMode(void);
void initConnectMode(UINT8 mode);
void setAutoApn(UINT8 mode, BOOL persist);
UINT8 getAutoApn(void);
void initAutoApn(void);
int is_system_in_upgrade_status(void);
void get_ntp_time(void);
BOOL check_autoAPN(void);
void update_pdp_conn_time(void);
void sendEventToHandler(INT32 id, CHAR *data);
BOOL is_uicc_sim(UINT32 atp_index);
void resetMasterSimIDSimDetect(void);
void sendWanInitMsg(UINT32 reqHandle);
UINT8 getSimWaitInitilizationFlag(INT32 sim_id);
void setSimWaitInitilizationFlag(INT32 sim_id, UINT8 value);
void sendDownloadProfileMsg(int reqHandle, BOOL simWait);
void sendMedcrInitMsg(UINT32 reqHandle);
void sendGetRemapFlagMsg(UINT32 reqHandle);
void sendSetRemapFlagMsg(UINT8 value);
void sendGetDefaultCidMsg(UINT32 reqHandle);
void sendSetDefaultCidMsg(UINT32 reqHandle, UINT8 value);
void sendSetOptimizeRej15Msg_19(UINT32 reqHandle, UINT8 value);
void sendSetOptimizeEtifMsg(UINT32 reqHandle);
void sendSetOptimizeEtifMsg_42(UINT32 reqHandle);
int SendATCMDWaitResp(int sATPInd, char *inStr, int timeOut, char *okFmt, int okFlag, char *errFmt, char *outStr, int outLen);
int check_SIM_PIN(UINT32 AT_channel);
int check_SIM_PUK(UINT32 AT_channel);
void update_MBR_GBR(UINT32 AT_channel);
void setSearchNetworkFlag(UINT32 atHandle, eSearchNetworkFlag flag);
char *getImsiBuf(UINT32 reqHandle);
void sim_inserted_CIMI_msg(void );
void sim_reset_SMSSetting_msg(UINT8 type);
void updateMncLen(int mncLen);
#ifndef NO_EXTEND_MY_Q_AT
int get_sim_iccid(char *buf, int size);
#endif
INT32 get_china_sim_operator(void);
UINT8 getBindSimId(UINT32 atpIndex);
int setBindSimId(UINT32 atpIndex, UINT8 simId);
int setBindSimIdCheck(UINT32 atpIndex, UINT8 simId);
BOOL isAtpBindSim(UINT32 atpIndex);
void initBindSimId(void);
void sendUartDataToBindChannel(UINT32 sAtpIndex, char *sendData, UINT32 dataLen);
void sendCmuxDataToBindChannel(UINT32 sAtpIndex, char *sendData, UINT32 dataLen);
void setUsbModemBindChannel(UINT8 *atpIndex);
BOOL isDualUsbModem(void);
void setTimeZone(int timezone);
int parseEnvCfg(int type);
void free_imsi_apn(UINT32 reqHandle);
void set_imsi_changed_flag(UINT32 reqHandle, UINT8 changed);
UINT8 get_imsi_changed_flag(UINT32 reqHandle);
void setSimRefreshed(int reqHandle, BOOL refreshed);
BOOL isSimRefreshed(int reqHandle);
char *get_iccid(int sim_id);
char *get_imei(int sim_id);
char *get_imsi(int sim_id);
char *get_meid(void);
void syncNITZ(UINT8 year, UINT8 month, UINT8 day, UINT8 hour, UINT8 min, UINT8 sec, int timezone);

#endif /* ! __DUSTER_H__ */
