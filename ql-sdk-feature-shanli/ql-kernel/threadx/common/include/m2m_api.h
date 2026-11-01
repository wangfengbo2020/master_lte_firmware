/*--------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  Filename: cmux_api.h
 *
 *  Description: API interface prototypes for cmux
 *
 *  History:
 *  Sep 4, 2017 - Rong Jin Creation of file
 *
 *  Notes:
 *
 ******************************************************************************/


#ifndef __M2M_API_H__
#define __M2M_API_H__

#include "osa.h"
#include "teldef.h"
#include "mi_api.h"
#include "uart.h"

#ifndef M2M_DISABLE
//#define M2M_EXTEND_AT
#else
#undef M2M_EXTEND_AT
#endif

#define M2MDBG(fmt,args...)     CPUartLogPrintf(fmt, ##args)


enum miplRequestMsg
{
	MIPL_REQUEST_MSG,
	MIPL_RESPONSE_MSG,
};

typedef enum MIPLRC {
    MIPLRC_SUCCESS = 0,
    MIPLRC_FAIL = 100,
    MIPLRC_PARAM_INVALID = 601,
    MIPLRC_STATE_FAIL = 602   
} MiplReturnCode;

typedef enum MIPLRS {
    MIPLRS_205_CONTENT=1,
    MIPLRS_204_CHANGED=2,
    MIPLRS_400_BAD_REQUEST = 11,
    MIPLRS_401_UNAUTHORIZED = 12,
    MIPLRS_404_NOT_FOUND = 13,
    MIPLRS_405_METHOD_NOT_ALLOWED = 14,
    MIPLRS_406_NOT_ACCEPTABLE = 15
} MiplResultCode;



enum MIPL_PRIM
{
    MIPL_GET_M2M_VERSION_REQ,
	MIPL_GET_M2M_VERSION_CNF,
	MIPL_SET_M2M_DEFAULT_CONFIG_REQ,
	MIPL_SET_M2M_CONFIG_REQ,
	MIPL_SET_M2M_CONFIG_CNF,
	MIPL_DEL_M2M_CONFIG_REQ,
	MIPL_DEL_M2M_CONFIG_CNF,
	MIPL_ADD_M2M_OBJ_REQ,
	MIPL_ADD_M2M_OBJ_CNF,
    MIPL_DEL_M2M_OBJ_REQ,
	MIPL_DEL_M2M_OBJ_CNF=10,
	MIPL_OPEN_M2M_REG_REQ,
	MIPL_OPEN_M2M_REG_CNF,
	MIPL_CLOSE_M2M_REG_REQ,
	MIPL_CLOSE_M2M_REG_CNF,
	MIPL_UPDATE_M2M_REG_REQ,
	MIPL_UPDATE_M2M_REG_CNF,
	MIPL_DISCOVER_M2M_RSP_REQ,
	MIPL_DISCOVER_M2M_RSP_CNF,
	MIPL_READ_M2M_RSP_REQ,
	MIPL_READ_M2M_RSP_CNF=20,
	MIPL_WRITE_M2M_RSP_REQ,
	MIPL_WRITE_M2M_RSP_CNF,
	MIPL_EXEC_M2M_RSP_REQ,
	MIPL_EXEC_M2M_RSP_CNF,
	MIPL_PARAM_M2M_RSP_REQ,
	MIPL_PARAM_M2M_RSP_CNF,
    MIPL_OBSERVE_M2M_RSP_REQ,
	MIPL_OBSERVE_M2M_RSP_CNF,
	MIPL_NOTIFY_M2M_RSP_REQ,
	MIPL_NOTIFY_M2M_RSP_CNF=30,
	MIPL_TRIGGER_M2M_HANDLE_PACKET_REQ,

	MIPL_READ_M2M_IND,
	MIPL_WRITE_M2M_IND,
	MIPL_EXEC_M2M_IND,
	MIPL_PARAM_M2M_IND,
	MIPL_EVENT_M2M_IND,
	MIPL_OBSERVE_M2M_IND,
	MIPL_DISCOVER_M2M_IND,
};

struct miplContext
{
	UINT8   ref;
	UINT8   register_flag;
	UINT8   config_flag;
	UINT16  config_size;
	CHAR    *config;
	INT32   g_lifetime_last;
	INT32   g_lifetime;
	INT32   g_dm_lifetime_last;
	INT32   g_dm_lifetime;
	UINT8   dm_status;//0--not init,1---init 
};

struct miplGetversionCnf
{
    CHAR    version[TEL_AT_M2M_VERSION_MAX_LEN];

};

struct miplSetconfigReq
{
	UINT16  totalsize;
	UINT8   index;
	UINT16  currentsize;
	UINT8   flag;
	CHAR    config[TEL_AT_M2M_CREATE_CONFIG_MAX_LEN];
};

struct miplSetconfigCnf
{
    INT32   result;
    UINT8   ref;
};

struct miplDelconfigReq
{
    UINT8   ref;
};

struct miplGenCnf
{
    INT32   result;
};

struct miplAddObjReq
{
    UINT8   ref;
    UINT16  objectid;
    UINT16  instancecount;
    UINT16  attributecount;
    UINT16  actioncount;
    CHAR    instancebitmap[TEL_AT_M2M_INSTANCE_BIT_MAP_MAX_LEN];
};

struct miplDelObjReq
{
    UINT8   ref;
    UINT16  objectid;
};

struct miplOpenReq
{
    UINT8   ref;
    UINT32  lifetime;
    UINT32  timeout;
};

struct miplCloseReq
{
    UINT8   ref;
};

struct miplUpdateReq
{
    UINT8   ref;
    UINT32  lifetime;
    UINT8   withobjectflag;
};

struct miplDiscoverRspReq
{
    UINT8   ref;
    UINT32  msgid;
    UINT32  result;
    UINT16  length;
    CHAR    value[TEL_AT_M2M_DISCOVER_VALUE_MAX_LEN];
};

struct miplReadRspReq
{
    UINT8   ref;
    UINT32  msgid;
    UINT32  result;
    UINT32  objectid;
    UINT32  instanceid;
    UINT32  resourceid;
    UINT8   valuetype;
    UINT8   index;
    UINT8   flag;
    UINT16  length;
    CHAR    value[TEL_AT_M2M_READ_VALUE_MAX_LEN];
};

struct miplWriteRspReq
{
    UINT8    ref;
    UINT32   msgid;
    UINT32   result;
};

struct miplExecRspReq
{
    UINT8   ref;
    UINT32  msgid;
    UINT32   result;
};

struct miplParamRspReq
{
    UINT8   ref;
    UINT32  msgid;
    UINT32   result;
};

struct miplObserveRspReq
{
    UINT8   ref;
    UINT32  msgid;
    UINT32   result;
};

struct miplNotifyRspReq
{
    UINT8   ref;
    UINT32  msgid;
    INT32   objectid;
    INT32   instanceid;
    INT32   resourceid;
    UINT8   valuetype;
    UINT8   index;
    UINT8   flag;
    UINT16  ackid;
    UINT16  length;
    CHAR    value[TEL_AT_M2M_READ_VALUE_MAX_LEN];

};


struct urcMiplReadInd
{
    UINT8   ref;
    UINT32  msgid;
    INT32  objectid;
    INT32  instanceid;
    INT32  resourceid;
};

struct urcMiplWriteInd
{
    UINT8   ref;
    UINT32  msgid;
    INT32   objectid;
    INT32   instanceid;
    INT32   resourceid;
    UINT8   valuetype;
    UINT8   index;
    UINT8   flag;
    UINT16  length;
    CHAR    value[TEL_AT_M2M_READ_VALUE_MAX_LEN];
};


struct urcMiplExecInd
{
    UINT8   ref;
    UINT32  msgid;
    INT32   objectid;
    INT32   instanceid;
    INT32   resourceid;
    UINT16  length;
    CHAR    value[TEL_AT_M2M_READ_VALUE_MAX_LEN];
};
struct urcMiplParameterInd
{
    UINT8   ref;
    UINT32  msgid;
    INT32   objectid;
    INT32   instanceid;
    INT32   resourceid;
    UINT16  length;
    CHAR    value[TEL_AT_M2M_READ_VALUE_MAX_LEN];
};

struct urcMiplEventInd
{
    UINT8   ref;
    INT32   eventid;
    INT32   ackid;
};

struct urcMiplObserveInd
{
    UINT8   ref;
    UINT32  msgid;
    UINT8   flag;
    INT32   objectid;
    INT32   instanceid;
    INT32   resourceid;
};

struct urcMiplDiscoverInd
{
    UINT8   ref;
    UINT32  msgid;
    INT32   objectid;
};


void init_mipl_msgq(OSAMsgQRef MsgQRef);
void miplResponse(UINT32 primID, UINT32 reqHandle, void *param);
INT32 m2mSetAtpIndex(UINT32 sAtpIndex);
void m2m_str_to_hex(char *src,char *dst,int size);

MiplReturnCode setM2mConfigReq(UINT32 atHandle, struct miplSetconfigReq *reqParas);
MiplReturnCode delM2mConfigReq(UINT32 atHandle, struct miplDelconfigReq *reqParas);
MiplReturnCode addM2mObjectReq(UINT32 atHandle, struct miplAddObjReq *reqParas);
MiplReturnCode delM2mObjectReq(UINT32 atHandle, struct miplDelObjReq *reqParas);
MiplReturnCode openM2mRegReq(UINT32 atHandle, struct miplOpenReq *reqParas);
MiplReturnCode closeM2mRegReq(UINT32 atHandle, struct miplCloseReq *reqParas);
MiplReturnCode updateM2mRegReq(UINT32 atHandle, struct miplUpdateReq *reqParas);
MiplReturnCode discoverM2mRspReq(UINT32 atHandle, struct miplDiscoverRspReq *reqParas);
MiplReturnCode readM2mRspReq(UINT32 atHandle, struct miplReadRspReq *reqParas);
MiplReturnCode writeM2mRspReq(UINT32 atHandle, struct miplWriteRspReq *reqParas);
MiplReturnCode execM2mRspReq(UINT32 atHandle, struct miplExecRspReq *reqParas);
MiplReturnCode paramM2mRspReq(UINT32 atHandle, struct miplParamRspReq *reqParas);
MiplReturnCode observeM2mRspReq(UINT32 atHandle, struct miplObserveRspReq *reqParas);
MiplReturnCode notifyM2mRspReq(UINT32 atHandle, struct miplNotifyRspReq *reqParas);
MiplReturnCode M2mNoParamReq(UINT32 primID,UINT32 atHandle);
MiplReturnCode M2mDmNoParamReq(UINT32 primID,UINT32 atHandle);



#endif
