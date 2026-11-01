/******************************************************************************
*(C) Copyright 2017 ASR Ltd.
* All Rights Reserved
******************************************************************************/
/*--------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  Filename: mi_api.h
 *
 *  Description: Holds the defination of the MI Data types file 
 *
 *  History: 
 *   Sep 4, 2017 - Rong Jin Creation of file    
 *
 *  Notes:
 *
 ******************************************************************************/


#ifndef __MI_API_H__
#define __MI_API_H__

#include "teldef.h"
#include "telatparamdef.h"

#define FTP_MAX_STRING_LEN   (128 * 2)
#define MAX_IPFILER_NUM 5
#define RESPONSE_BUFFER_LEN 512
#define DATA_BUFFER_LEN 2048

#define FTP_CFG_BIT_ACCOUNT         0x01
#define FTP_CFG_BIT_FILETYPE        0x02
#define FTP_CFG_BIT_TRANSMODE       0x04
#define FTP_CFG_BIT_CONTEXTID       0x08
#define FTP_CFG_BIT_RSPTIMEOUT      0x10
#define FTP_CFG_BIT_SSLTYPE         0x20
#define FTP_CFG_BIT_SSLCTXID        0x40

typedef enum MIRC {
    MIRC_SUCCESS = 0,
    MIRC_PDP_REJECT = 900,
    MIRC_PDP_UNACTIVE,
    MIRC_PDP_ALREADY_ACTIVE,
    MIRC_TCP_CONN_REJECT=910,
    MIRC_TCP_CONN_TIMEOUT,
    MIRC_SOCKET_EXIST,
    MIRC_SOCKET_NOT_EXIST,
    MIRC_SEND_BUF_FULL,
    MIRC_SEND_TIMEOUT,
    MIRC_DOMAIN_NOT_EXIST,
    MIRC_DOMAIN_TIMEOUT,
    MIRC_DOMAIN_UNKNOWN,
    MIRC_PARAM_INVALID=980,
    MIRC_FAIL = 981,
    MIRC_NUM_RESCODES
} MiReturnCode;

typedef enum IOTRC {
    IOTRC_SUCCESS = 0,
	IOTRC_PING_NO_RESPONSE = 1,
	IOTRC_PING_Failed_Send = 2,
    IOTRC_OPERATION_NOT_ALLOWED = 3,
    IOTRC_OPERATION_NOT_SUPPORTED,
    IOTRC_MEMORY_FAILURE=23,
    IOTRC_FLOW_CONTROL = 32,
    IOTRC_INCORRECT_PARAMETERS=50,
    IOTRC_UPLINK_BUSY=159,
    IOTRC_PARAMETER_NOT_CONFIGURED=256,
} IOTReturnCode;


typedef enum E20RC {
    E20_SUCCESS = 0,
    E20_UNKNOWN = 550,
    E20_OPERATION_BLOCKED,
    E20_INVALID_PARAMETERS,
    E20_MEMORY_NOT_ENOUGH,
    E20_CREATE_SOCKET_FAILED,
    E20_OPERATION_NOT_SUPPORTED= 555,
    E20_SOCKET_BIND_FAILED,
    E20_SOCKET_LISTEN_FAILED,
    E20_SOCKET_WRITE_FAILED,
    E20_SOCKET_READ_FAILED,
    E20_SOCKET_ACCEPT_FAILED = 560,
    E20_OPEN_PDP_CONTEXT_FAILED,
    E20_CLOSE_PDP_CONTEXT_FAILED,
    E20_SOCKET_IDENTITY_HAS_BEEN_USED,
    E20_DNS_BUSY,
    E20_DNS_PARSE_FAILED= 565,
    E20_SOCKET_CONNECT_FAILED,
    E20_SOCKET_HAS_BEEN_CLOSED,
    E20_OPERATION_BUSY,
    E20_OPERATION_TIMEOUT,
    E20_PDP_CONTEXT_BROKEN_DOWN= 570,
    E20_CANCEL_SEND,
    E20_OPERATION_NOT_ALLOWED,
    E20_APN_NOT_CONFIGURED,
    E20_PORT_BUSY
} E20ReturnCode;


typedef enum E20CFG {
    QI_CFG_TRANSPKTSIZE = 0,
    QI_CFG_TRANSWAITTM,
    QI_CFG_DATAFORMAT,
    QI_CFG_VIEWMODE,
    QI_CFG_TCP_RETRANSCFG,
    QI_CFG_DNS_CACHE,
    QI_CFG_QISEND_TIMEOUT,
    QI_CFG_PASSIVE_CLOSED
} E20ConfigCode;


enum MI_PRIM
{
	MI_DIALER_SET_PDP_USER_PARAM_REQ,
	MI_DIALER_SET_PDP_USER_PARAM_CNF,
	MI_DIALER_SET_PDP_APN_PARAM_REQ,
	MI_DIALER_SET_PDP_APN_PARAM_CNF,
	MI_DIALER_SET_PDP_AUTH_PARAM_REQ,
	MI_DIALER_SET_PDP_AUTH_PARAM_CNF,
	MI_DIALER_SET_PDP_STATE_REQ,
	MI_DIALER_SET_PDP_STATE_CNF,
	MI_DIALER_GET_PDP_STATE_REQ,
	MI_DIALER_GET_PDP_STATE_CNF,
	MI_DIALER_SET_CTX_CONFIG_REQ,
	MI_DIALER_SET_CTX_CONFIG_CNF,
	MI_DIALER_GET_CTX_CONFIG_REQ,
	MI_DIALER_GET_CTX_CONFIG_CNF,
	MI_NET_SET_URC_REQ,
	MI_NET_SET_URC_CNF,
	MI_NET_GET_URC_REQ,
	MI_NET_GET_URC_CNF,
	MI_NET_SET_CFGT_REQ,
	MI_NET_SET_CFGT_CNF,
	MI_NET_SET_CFGP_REQ,
	MI_NET_SET_CFGP_CNF,
	MI_NET_SET_IP_FILTER_REQ,
	MI_NET_SET_IP_FILTER_CNF,
	MI_NET_GET_IP_FILTER_REQ,
	MI_NET_GET_IP_FILTER_CNF,
	MI_NET_SET_SERVICE_PARAM_REQ,
	MI_NET_SET_SERVICE_PARAM_CNF,
	MI_NET_GET_SERVICE_PARAM_REQ,
	MI_NET_GET_SERVICE_PARAM_CNF,
	MI_NET_SET_SOCKET_OPEN_REQ,
	MI_NET_SET_SOCKET_OPEN_CNF,
	MI_NET_GET_SOCKET_OPEN_REQ,
	MI_NET_GET_SOCKET_OPEN_CNF,
	MI_NET_SET_SOCKET_READ_REQ,
	MI_NET_SET_SOCKET_READ_CNF,
	MI_NET_SET_SOCKET_WRITE_REQ,
	MI_NET_SET_SOCKET_WRITE_CNF,
	MI_NET_SET_SOCKET_WRITE_DATA_REQ,
	MI_NET_SET_SOCKET_WRITE_DATA_CNF,
	MI_NET_SET_SOCKET_TRANS_WRITE_DATA_REQ,
	MI_NET_SET_SOCKET_TRANS_READ_DATA_CNF,
	MI_NET_SET_SOCKET_CLOSE_REQ,
	MI_NET_SET_SOCKET_CLOSE_CNF,
	MI_NET_SET_SOCKET_ACK_REQ,
	MI_NET_SET_SOCKET_ACK_CNF,
	MI_NET_SET_SOCKET_ACCEPT_REQ,
	MI_NET_SET_SOCKET_ACCEPT_CNF,
	MI_NET_SET_CREATE_REQ,
	MI_NET_SET_CREATE_CNF,
	MI_FTP_SET_CONFIG_REQ,
   	MI_FTP_SET_CONFIG_CNF,
   	MI_FTP_GET_CONFIG_REQ,
   	MI_FTP_GET_CONFIG_CNF,
	MI_FTP_SET_OPEN_REQ,        /* request ftp thread to open a ftp connection */
	MI_FTP_SET_OPEN_CNF,
	MI_FTP_GET_OPEN_REQ,        /* require ftp thread ftp connection status */
	MI_FTP_GET_OPEN_CNF,
	MI_FTP_SET_CLOSE_REQ,       /* request ftp thread to close a ftp connection */
	MI_FTP_SET_CLOSE_CNF,
    MI_FTP_SET_STATUS_REQ,       /* request to query ftp status */
    MI_FTP_SET_STATUS_CNF,
	MI_FTP_SET_SIZE_REQ,        /* request ftp thread to query a file size */
	MI_FTP_SET_SIZE_CNF,
	MI_FTP_SET_FILE_GET_REQ,
	MI_FTP_SET_FILE_GET_CNF,
    MI_FTP_SET_FILE_PUT_REQ,
    MI_FTP_SET_FILE_PUT_CNF,
	MI_FTP_SET_CWD_REQ,
	MI_FTP_SET_CWD_CNF,
	MI_FTP_SET_PWD_REQ,
	MI_FTP_SET_PWD_CNF,
    MI_FTP_SET_DEL_REQ,
    MI_FTP_SET_DEL_CNF,
    MI_FTP_SET_MKDIR_REQ,
    MI_FTP_SET_MKDIR_CNF,
    MI_FTP_SET_RMDIR_REQ,
    MI_FTP_SET_RMDIR_CNF,
    MI_FTP_SET_MDTM_REQ,
    MI_FTP_SET_MDTM_CNF,
    MI_FTP_SET_RENAME_REQ,
    MI_FTP_SET_RENAME_CNF,
    MI_FTP_SET_LIST_REQ,
    MI_FTP_SET_LIST_CNF,
    MI_FTP_SET_LEN_REQ,
    MI_FTP_SET_LEN_CNF,
	MI_NET_SOCKET_LED_REQ,
	MI_NET_SOCKET_LED_CNF,
	MI_FOTA_SET_OPEN_REQ,
	MI_FOTA_SET_OPEN_CNF,
	MI_FOTA_GET_PRO_REQ,
	MI_FOTA_GET_PRO_CNF,
	MI_NET_SET_CTX_CONFIG_REQ,
	MI_NET_SET_CTX_CONFIG_CNF,
	MI_NET_SET_ASR_SOCKET_OPEN_REQ,
	MI_NET_SET_ASR_SOCKET_OPEN_CNF,
	MI_NET_SET_ASR_SOCKET_STATE_REQ,
	MI_NET_SET_ASR_SOCKET_STATE_CNF,
	MI_NET_SET_ASR_SOCKET_SEND_REQ,
	MI_NET_SET_ASR_QUERY_SEND_DATA_CNF,
	MI_NET_SET_ASR_QUERY_READ_DATA_REQ,
	MI_NET_SET_ASR_QUERY_READ_DATA_CNF,
	MI_NET_SET_ASR_SOCKET_SEND_HEX_REQ,
	MI_NET_SET_ASR_SOCKET_SEND_HEX_CNF,
	MI_NET_SET_ASR_SWT_MODE_REQ,
	MI_NET_SET_ASR_SWT_MODE_CNF,
	MI_NET_SET_ASR_GET_ERROR_REQ,
	MI_NET_SET_ASR_GET_ERROR_CNF,
	MI_NET_SET_ASR_ECHO_SEND_DATA_CNF,

	/*roy add for transport req */
	MI_NET_TRANSPORT_OPEN_REQ,
	MI_NET_TRANSPORT_UDP_BACKUP_SEND_REQ,
	MI_NET_SYS_RESET_REQ,
	MI_NET_DEACTIVE_CLOSE_SOCKET_REQ,
	MI_NET_DETACH_CLOSE_SOCKET_REQ,
	
	MI_UCR_DATA_IND,
	MI_UCR_CLOSE_IND,
	MI_UCR_ACT_IND,
	MI_UCR_CLIENT_IND,
	MI_UCR_FTP_CLOSE_IND,
	MI_UCR_FOTA_IND,
	MI_UCR_SYS_INFO_IND,
	MI_UCR_DATA_PUSH_IND,
    MI_UCR_FTP_GET_DATA_IND,
    MI_UCR_FTP_PUT_DATA_IND,
    MI_UCR_FTP_LIST_DATA_IND,

	/*for SSL Net*/
	MI_NET_GET_ALL_SSL_CFG_REQ,
	MI_NET_GET_ALL_SSL_CFG_CNF,
	MI_NET_GET_SSL_CFG_REQ,
	MI_NET_GET_SSL_CFG_CNF,
	MI_NET_SET_SSL_CFG_REQ,
	MI_NET_SET_SSL_CFG_CNF,

	
	MI_UCR_SSL_DATA_IND,
	MI_UCR_SSL_DATA_PUSH_IND,
	MI_UCR_SSL_CLOSE_IND,

	MI_UCR_SEND_DATA_TIMEOUT_IND,
	MI_UCR_SEND_DATA_INTER_IND,
#ifdef QUEC_MINISYS_PROJECT_CUST
	MI_FOTA_MSG_IND_REQ,
#endif		
	MI_PRIM_DEFINE_END
};

enum NI_PRIM
{
	AT_NBIOT_NSOCR_REQ = MI_PRIM_DEFINE_END + 1,
	AT_NBIOT_NSOCR_CNF,
	AT_NBIOT_NSOST_REQ,
	AT_NBIOT_NSOST_CNF,
	AT_NBIOT_NSORF_REQ,
	AT_NBIOT_NSORF_CNF,
	AT_NBIOT_NSOCL_REQ,
	AT_NBIOT_NSOCL_CNF,
	AT_NBIOT_NPING_REQ,
	AT_NBIOT_NPING_CNF,
	AT_NBIOT_COAP_NMGR_REQ,
	AT_NBIOT_COAP_NMGR_CNF,
	AT_NBIOT_COAP_NNMI_REQ,
	AT_NBIOT_COAP_NSMI_REQ,

	AT_NBIOT_NSONMI_IND,
	AT_NBIOT_NSMI_COAP_IND,
	AT_NBIOT_NNMI_COAP_IND,

};

/*QFTP configure parameter type*/
enum eQFtpType
{
	FTP_CFG_TYPE_ACCOUNT = 1,
	FTP_CFG_TYPE_FILETYPE,
	FTP_CFG_TYPE_TRANSMODE,
	FTP_CFG_TYPE_CONTEXTID,
	FTP_CFG_TYPE_RSPTIMEOUT,
	FTP_CFG_TYPE_SSLTYPE,
	FTP_CFG_TYPE_SSLCTXID,
	FTP_CFG_TYPE_MAX
};

struct setSocketLEDReq
{
	UINT8 onOff;
};

struct netSetUrcReq
{
	UINT8 onOff;
};

struct netGetUrcCnf
{
	INT32 result;
	UINT8 onOff;
};

struct pdpUserPswd
{
	CHAR user[MAX_STRING_LEN];
	CHAR pswd[MAX_STRING_LEN];
};

union pdpSetParamReq
{
	struct pdpUserPswd userPswd;
	CHAR apn[MAX_STRING_LEN];
	CHAR ip_type[MAX_STRING_LEN];
	INT32 auth;
	INT32 cfgp;
	INT32 cfgt;
};

struct pdpSetParam
{
	union pdpSetParamReq param;
	UINT8 channel;
};

struct setGenericCnf
{
	INT32 result;
};

struct pdpGetParamCnf
{
	INT32 result;
	UINT8 channel;
	CHAR type[MAX_STRING_LEN];
	CHAR typeName[MAX_STRING_LEN];
	
};

struct pdpActiveStateReq
{
	INT32 state;
	UINT8 channel;
};

struct pdpGetActiveStateCnf
{
	INT32 result;
	UINT8 status;
	UINT8 channel;
	CHAR ipStr[MAX_STRING_LEN];
};

struct pdpActiveStateInd
{
	UINT8 status;
	UINT8 channel;
	CHAR ipStr[MAX_STRING_LEN];
};

struct netSetIpfilterReq
{
	CHAR ipStr[MAX_STRING_LEN];
	CHAR netMask[MAX_STRING_LEN];
	UINT8 action;
	UINT8 id;
};

struct netGetIpfilter
{
	CHAR ipStr[MAX_STRING_LEN];
	CHAR netMask[MAX_STRING_LEN];
	UINT8 id;
};

struct netGetIpfilterCnf
{
	INT32 result;
	struct netGetIpfilter ipFilter[MAX_IPFILER_NUM];
};

struct netSetServiceReq
{
	CHAR ipPortStr[MAX_STRING_LEN];
	UINT8 channel;
	UINT8 socketID;
	UINT8 viewMode;
	UINT8 netType;
};

struct netGetServiceInfo
{	
	CHAR ipPortStr[MAX_STRING_LEN];
	INT32 channel;
	UINT8 socketID;
	UINT8 viewMode;
	UINT8 netType;
};

struct netGetServiceCnf
{	
	INT32 result;
	UINT8 num;
	struct netGetServiceInfo serviceinfo[6];
};


struct netSetSocketOpenReq
{
	UINT8 socketID;
};

struct netSetSocketOpenCnf
{
	INT32 result;
	UINT8 socketID;
	UINT16 remoteMSS;
	UINT8 transportMode;
};

struct netGetSocketOpenInfo
{
	CHAR localIPStr[MAX_STRING_LEN];
	CHAR gateStr[MAX_STRING_LEN];
	CHAR DNS1[MAX_STRING_LEN];
	CHAR DNS2[MAX_STRING_LEN];
	CHAR dstIPStr[MAX_STRING_LEN];
	UINT16 localPort;
	UINT16 dstPort;
	UINT8 socketID;
	UINT8 netType;
};


struct netGetSocketOpenCnf
{
	INT32 result;
	INT32 num;
	struct netGetSocketOpenInfo info[6];
};

struct netSocketReadReq
{
	UINT8 socketID;
	UINT32 dataLen;
};

struct netSocketReadCnf
{
	INT32 result;
	UINT32 dataLen;
	CHAR *data;
	UINT8 contextID;
	UINT8 socketID;
	UINT8 viewMode;
	UINT16 remote_port;
	CHAR  remote_IPStr[MAX_STRING_LEN];
	UINT8 ssl_enable;
};

struct netSocketWriteReq
{
	UINT8 socketID;
	UINT32 dataLen;
};

struct netSocketWriteCnf
{
	INT32 result;
	UINT32 dataLen;
	UINT8 socketID;
	UINT8 viewMode;
};

struct netSocketWriteDataReq
{
	UINT8 socketID;
	CHAR *data;
	UINT32 dataLen;
};

struct netSocketWriteDataCnf
{
	INT32 result;
};

struct netSocketCloseReq
{
	UINT8 socketID;
};

struct netSocketCloseCnf
{
	INT32 result;
	UINT8 socketID;
};

struct netSocketAckReq
{
	UINT8 socketID;
};

struct netSocketAckCnf
{
	INT32 result;
	UINT32 unAckedDataLen;
	UINT32 restBufferLen;
	UINT8 socketID;
};

struct netSocketAcceptReq
{
	UINT8 socketID;
	UINT8 action;
	UINT8 transMode;
};

struct netSocketAcceptCnf
{	
	INT32 result;
	UINT8 action;
	UINT8 transMode;
	UINT8 socketId;
};

struct netCreateReq
{
	UINT8 channel;
	UINT8 socketID;
	UINT8 mode;
	CHAR dstIP[MAX_STRING_LEN];
	UINT16 dstPort;
	UINT16 srcPort;
};

struct netCreateCnf
{
	INT32 result;
	UINT8 mode;
	UINT8 socketID;
};

struct ftpSetGenericReq
{
	CHAR cfg_str[FTP_MAX_STRING_LEN]; /*maby hostname, filename, foldername*/
};

/*note: need keep part sync to setGenericCnf, for some position use setGenericCnf to turn the data*/
struct ftpSetGenericCnf
{
	INT32 result;       /*process result for request msg*/
    CHAR ret_str[FTP_MAX_STRING_LEN]; /*maybe protol error string, or filename, filesize*/
};

/*note: need keep part sync to setGenericCnf, for some position use setGenericCnf to turn the data*/
struct ftpSetGenericCnfMax
{
	INT32 result;       /*process result for request msg*/
    CHAR ret_str[FTP_MAX_STRING_LEN * 3]; /*use to deal query account*/
};

struct ftpSetOpenReq
{
	CHAR host[FTP_MAX_STRING_LEN]; /*xx.xx.xx.xx:port, or URL*/
	CHAR username[FTP_MAX_STRING_LEN]; /*note: qijun require 256, need turn*/
	CHAR password[FTP_MAX_STRING_LEN];
	UINT8 cfgType;
	UINT8 contextID;
	UINT8 mode; /*0: active mode, 1: passtive mode*/
	UINT8 timeout; /*5-180s, default 30s*/
	UINT8 ftpType; /*0: binary mode, 1: text mode*/
	UINT8 sslType; /*0: FTP client, 1:FTPS client*/
	UINT8 sslCtxID; /*0-5*/
	UINT8 connetStatus;
};

struct ftpGetConfigReq
{
	UINT8 cfgType;
};

struct fotaSetOpenReq
{
	CHAR host[FTP_MAX_STRING_LEN]; /*xx.xx.xx.xx:port, or URL*/
	CHAR username[FTP_MAX_STRING_LEN];
	CHAR password[FTP_MAX_STRING_LEN];
	UINT8 mode; /*0: ftp, 1: http*/
	int  download_urc_cnt;
	int  download_urc_num;
	UINT8	down_fail_stop_open;
	UINT8	dl_first_pkg_suc;
};

struct qmini_fotaupl_param
{
	char              path_name[256];
    UINT8             dl_urc_num;     //max number of urc when downloading
    UINT8             dl_urc_cnt;
	UINT8			  down_fail_stop_open;
	UINT8			  dl_first_pkg_suc;
};

struct fotaGetProCnf
{
	INT32 result;
	INT32 progress;
};

struct ftpGetOpenCnf
{
	INT32 result;
	UINT8 connetStatus;
};

struct ftpSetListReq
{
	CHAR dirName[FTP_MAX_STRING_LEN];
    CHAR localName[FTP_MAX_STRING_LEN];
	CHAR *data;
    INT32 listCmd; /*0: LIST , 1: NLST , 2: MLSD */
};

/*note: need keep part sync to ftpSetGenericCnf, for some position use ftpSetGenericCnf to turn the data*/
struct ftpSetListCnf
{
	INT32 result;       /*process result for request msg*/
    CHAR ret_str[FTP_MAX_STRING_LEN]; /*maybe protol error string*/
    INT32 dataMode;
    INT32 listCmd; /*0: LIST , 1: NLST , 2: MLSD */
};

struct ftpListDataInd
{
	INT32 result;       /*process result for request msg*/
    CHAR ret_str[FTP_MAX_STRING_LEN]; /*protol error*/
	CHAR *data;         /*record from ftpSetFileGetReq*/
    INT32 dataLen;
    INT32 dataMode; /*1: com port; 2: MEM buffer; 3: ram file; 4: test debug*/
    INT32 listCmd; /*0: LIST , 1: NLST , 2: MLSD */
};

struct ftpSetFileGetReq
{
	CHAR fileName[FTP_MAX_STRING_LEN];
    CHAR localName[FTP_MAX_STRING_LEN];
	CHAR *data;
	INT32 dataOffset;
	INT32 dataLen;
};

/*note: need keep part sync to ftpSetGenericCnf, for some position use ftpSetGenericCnf to turn the data*/
struct ftpSetFileGetCnf
{
	INT32 result;       /*process result for request msg*/
    CHAR ret_str[FTP_MAX_STRING_LEN]; /*maybe protol error string*/
	CHAR *data;         /*record from ftpSetFileGetReq*/
    INT32 dataLen;
};

struct ftpSetFilePutReq
{
	CHAR fileName[FTP_MAX_STRING_LEN];
    CHAR localName[FTP_MAX_STRING_LEN];
	CHAR *data;
	INT32 dataOffset;
	INT32 dataLen;
};

/*note: need keep part sync to ftpSetGenericCnf, for some position use ftpSetGenericCnf to turn the data*/
struct ftpSetFilePutCnf
{
	INT32 result;       /*process result for request msg*/
    CHAR ret_str[FTP_MAX_STRING_LEN]; /*protol error*/
	CHAR *data;         /*record from ftpSetFileGetReq*/
    INT32 dataLen;
};

struct ftpSetGetPutReq
{
	CHAR fileName[FTP_MAX_STRING_LEN];
    CHAR localName[FTP_MAX_STRING_LEN];
	CHAR *data;
	INT32 dataOffset;
	INT32 dataLen;
};

/*note: need keep part sync to ftpSetGenericCnf, for some position use ftpSetGenericCnf to turn the data*/
struct ftpSetGetPutCnf
{
	INT32 result;       /*process result for request msg*/
    CHAR ret_str[FTP_MAX_STRING_LEN]; /*maybe protol error string*/
    INT32 dataMode;     /*1: com port; 2: MEM buffer; 3: ram file; 4: test debug*/
    INT32 dataLen;      /*not use already*/
};

/*note: need keep part sync to ftpSetGenericCnf, for some position use ftpSetGenericCnf to turn the data*/
struct ftpGetPutDataInd
{
	INT32 result;       /*process result for request msg*/
    CHAR ret_str[FTP_MAX_STRING_LEN]; /*protol error*/
	CHAR *data;         /*record from ftpSetFileGetReq*/
    INT32 dataLen;
    INT32 dataMode; /*1: com port; 2: MEM buffer; 3: ram file; 4: test debug*/
};

struct ftpSetFilePutConnReq
{
	CHAR fileName[FTP_MAX_STRING_LEN]; 
	INT32 dataLen; /* 1 - 3072*/
};

struct ftpSetFilePutConnCnf
{
	INT32 result;
	INT32 dataLen; 
};

struct ftpSetFilePutDataReq
{
	CHAR *data; 
	INT32 dataLen; /* 1 - 3072*/
};

struct ftpSetFilePutDataCnf
{
	INT32 result;
};

struct urcDataInd
{
	UINT8 socketID;
};

struct urcDataPushInd
{
	UINT8 socketID;
	INT16 len;
	char *buf;
	UINT16 remote_port;
	CHAR remote_ipStr[MAX_STRING_LEN];
};


struct urcCloseInd
{
	UINT8 socketID;
};

struct urcIncomingClientInd
{
	UINT8 channel;
	UINT8 socketID;
	int skfd;
	UINT8 viewMode;
};


struct urcActInd
{
	CHAR ipStr[MAX_STRING_LEN];
	UINT8 type;
	UINT8 channel;
};

struct urcClientInd
{
	CHAR ipStr[MAX_STRING_LEN];
	UINT16 port;
	UINT8 socketID;
};

struct urcFtpCloseInd
{
	UINT8 status; /*0: FTP command close, 1: FTP data close*/
};


struct urcfotaInd
{
	INT32 result;
};

struct getMyGmrCnf
{
	CHAR manufacture[16];
	CHAR model[16];
	CHAR software[16];
	CHAR softwareDate[16];
	CHAR hardware[16];
	CHAR hardwareDate[16];
};

struct netRegStatusInd
{
	UINT8 status;
	UINT8 act;
	UINT16 NetworkCode;
};

struct UrcSysInfoInd
{
	UINT8 netmode;
	UINT16 NetworkCode;
};

struct asrCtxConfigReq
{
    UINT8   ContextID;
    INT32 ipType;
    struct pdpUserPswd userPswd;
    CHAR apn[MAX_STRING_LEN];
    INT32 authType;
};

struct asrGetCtxConfigCnf
{
    INT32   result;
    UINT8   ContextID;
    INT32 ipType;
    struct pdpUserPswd userPswd;
    CHAR apn[MAX_STRING_LEN];
    INT32 authType;
};

struct asrOpenReq
{
    UINT8   ContextID;
    UINT8   ConnectID;
    UINT8   service_type;
    UINT16  remote_port;
    UINT16  local_port;
    UINT8   access_mode;
    CHAR    ip_address[MAX_STRING_LEN];
    UINT8   ssl_enable;
    UINT8   ssl_ctxid;
};

struct asrOpenCnf
{
    INT32   result;
    UINT8   ConnectID;
    UINT8   service_type;
    UINT8   access_mode;
    UINT8   ssl_enable;
};


struct asrStateReq
{
    UINT8   QueryType;
    UINT8   ConID;

};

struct asrStateInfo
{
    UINT8   ConnectID;
    UINT8   service_type;
    UINT16  remote_port;
    UINT16  local_port;
    UINT8   socket_state;
    UINT8   ContextID;
    UINT8   serverID;
    UINT8   access_mode;
    UINT8   at_port;
    CHAR    ip_address[MAX_STRING_LEN];
    UINT8   ssl_enable;
    UINT8   ssl_ctx_id;

};


struct asrStateCnf
{
    UINT8   count;
    struct asrStateInfo info[6];
};



struct asrSocketSendReq
{
	UINT8   socketID;
	UINT32  dataLen;
	UINT16  remote_port;
	CHAR    remoteIP[MAX_STRING_LEN];
	
};
struct asrSocketQuerySendDataCnf
{
	UINT32  total_send_len;
	UINT32  acked_bytes;
	UINT32  unacked_bytes;

	
};
struct asrSocketReadReq
{
	UINT8   socketID;
	UINT32  dataLen;	
};
struct asrSocketQueryReadDataCnf
{
	UINT32  total_read_len;
	UINT32  have_read_len;
	UINT32  unread_len;

	
};
struct asrSendHexReq
{
	UINT8   socketID;
	UINT16  data_len;
	CHAR    data[TEL_AT_ASRSEND_SEND_HEX_MAX_LEN + 1];
};

struct asrSwTmdReq
{
	UINT8 socketID;
	UINT8 access_mode;
};

struct asrSwTmdCnf
{
    UINT32 result;
	UINT8 socketID;
	UINT8 access_mode;
};


struct asrSetCfg
{
	UINT16  transpktsize;
	UINT8   transwaittm;
	UINT8   send_data_format;       //0---text;1----HEX
	UINT8   recv_data_format;       //0---text;1----HEX
	UINT8   view_mode;
	UINT8   max_backoffs;
	UINT16  max_rto;
	UINT8   dns_cache;
	UINT16  timeout;
	UINT8   closed;
};

struct iotNSOCRMsg
{
	UINT8 typename[32];
	UINT8 protocol;
	UINT8 recv_control;
	UINT16 listen_port;
};

struct iotNSOCRCnf
{
	UINT32 result;
	UINT8 socket;
};


struct iotNSOSTMsg
{
	UINT8 socket;
	UINT8 remote_addr[128];
	UINT16 remote_port;
	UINT16 length;
	UINT8 data[1025];
};

struct iotNSOSTCnf
{
	UINT32 result;
	UINT8 socket;
	UINT16 length;
};


struct iotNSORFMsg
{
	UINT8 socket;
	UINT16 length;
};

struct iotNSORFCnf
{
	UINT32 result;
	UINT8 socket;
	UINT8 ip_addr[32];
	UINT8 hex_notSupport;
	UINT16 port;
	UINT16 length;
	UINT16 remaining_length;
	UINT8 *data;
};


struct iotNSOCLMsg
{
	UINT8 socket;
};

struct iotNSOCLCnf
{
	UINT32 result;
};

struct iotNPINGCnf
{
	UINT32 result;
	UINT8 retrynum;
	UINT8 remote_addr[128];
	UINT16 ttl;
	UINT16 rtt;
};

struct iotCoapNCDPReq
{
	UINT8 remote_addr[128];
	UINT16 port;
};


struct iotCoapNMGRCnf
{
	UINT32 result;
	UINT16 length;
	UINT8 *data;
};


struct iotNSONMIInd
{
	UINT32 reqHandle;
	UINT8 socket;
	UINT16 length;
};

struct iotCoapNSMIInd
{
	UINT32 result;
	UINT32 reqHandle;
};

struct iotCoapNnMIInd
{
	UINT32 reqHandle;
	UINT16 length;
	UINT8 *buf;
};


void miResponse(UINT32 srcSvcID, UINT32 dstSvcID, UINT32 primID, UINT32 reqHandle, void *param);
void  miInd(UINT32 srcSvcID, UINT32 dstSvcID, UINT32 primID, UINT32 reqHandle, void *param);

#endif

