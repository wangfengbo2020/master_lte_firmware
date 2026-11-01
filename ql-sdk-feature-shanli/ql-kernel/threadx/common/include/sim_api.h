/******************************************************************************
*(C) Copyright 2008 Marvell International Ltd.
* All Rights Reserved
******************************************************************************/
/*--------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  Filename: sim_api.h
 *
 *  Description: API interface for SIM service
 *
 *  History:
 *   Oct 16, 2008 - Qiang XU Creation of file
 *
 *  Notes:
 *
 ******************************************************************************/


#ifndef __SIM_API_H__
#define __SIM_API_H__

#include "ci_sim.h"
#include "telsim.h"

/* Enum value of STK cmd type and STK ind msg type */
typedef enum StkCmdTypeTag
{
    STK_CMD_ENABLE_SIMAT = 0,
    STK_CMD_DOWNLOAD_PROFILE = 1,
    STK_CMD_GET_CAP_INFO = 2,
    STK_CMD_GET_PROFILE = 3,
    STK_CMD_SEND_ENVELOPE = 4,

    STK_CMD_PROACTIVE  = 11,
    STK_CMD_SETUP_CALL = 12,
    STK_CMD_DISPLAY_INFO = 13,
    STK_CMD_END_SESSION = 14,
	STK_CMD_SETUP_CALL_REQ_STATUS,    //  ----- CI_SIM_PRIM_SIMAT_CC_STATUS_IND
	STK_CMD_SETUP_CALL_RESULT,   // CI_SIM_PRIM_SIMAT_SEND_CALL_SETUP_RSP_IND
	STK_CMD_PROACTIVE_REFRESH,
	STK_CMD_PROACTIVE_SEND_SM_REQ_STATUS,  //  ----- CI_SIM_PRIM_SIMAT_SM_STATUS_IND
	STK_CMD_PROACTIVE_SEND_SM_RESULT,  //  ----- CI_SIM_PRIM_SIMAT_SEND_SM_RSP_IND
	STK_CMD_PROACTIVE_SEND_USSD_RESULT,  //  ----- CI_SIM_PRIM_SIMAT_SEND_SS_USSD_RSP_IND
	STK_CMD_SEND_SS_REQ_STATUS,       //  ----- CI_SIM_PRIM_SIMAT_CC_STATUS_IND
	STK_CMD_SEND_USSD_REQ_STATUS,     //  ----- CI_SIM_PRIM_SIMAT_CC_STATUS_IND
	STK_TYPE_INVALID,
	STK_TYPE_MAX,
	STK_TYPE_MAX_LAST= 0x7FFFFFFF
} StkCmdType;

CiReturnCode SIM_SetCommand(UINT32 atHandle, int cmdLen, CHAR *cmdStr);
CiReturnCode SIM_GetImsi(UINT32 atHandle);
CiReturnCode SIM_GetPinState(UINT32 atHandle, int cpinCmdType);
CiReturnCode SIM_EnterPin(UINT32 atHandle, UINT8 no, UINT8 oper,CHAR* oldPasswd, CHAR* newPasswd);
CiReturnCode SIM_GetSIMInserted(UINT32 atHandle, UINT32 simSlot);
CiReturnCode SIM_SetLockFacility(UINT32 atHandle, int mode, int facType, CHAR* passwd, int passwdStrLen, BOOL pinRequired);
CiReturnCode SIM_RestrictedAccess(UINT32 atHandle, int cmd, int iFileId, char *valStr,  int p1, int p2, int p3, char *data, int dataLen, int sessionId);
CiReturnCode SIM_GenericAccess(UINT32 atHandle, int cmdLen, char *cmdStr, int sessionId);
CiReturnCode SIM_GenericAccessCGLA(UINT32 atHandle, int cmdLen, char *cmdStr, int sessionId);
CiReturnCode SIM_CCHO(UINT32 atHandle, char *dfname);
CiReturnCode SIM_CCHC(UINT32 atHandle, UINT16 sessionid);
CiBoolean SIM_ConvertCrsmAtReply(UINT32 atHandle, CiPrimitiveID primId, const void *paras);
CiReturnCode SIM_GetSpn(UINT32 atHandle, int typeVal);

CiReturnCode STK_EnableProactiveCmdIndConfig(UINT32 atHandle, UINT8 enable);
CiReturnCode STK_GetSimProfile(UINT32 atHandle);
CiReturnCode STK_DownloadMeProfile(UINT32 atHandle, char *data, int dataLen);
CiReturnCode STK_SendEnvelopeCmd(UINT32 atHandle, char *data, int dataLen);
CiReturnCode STK_RespProactiveCmd(UINT32 atHandle, char *data, int dataLen);
CiReturnCode STK_RespSetupCall(UINT32 atHandle, UINT8 accept);
CiReturnCode STK_GetSimCapInfo(UINT32 atHandle);
CiReturnCode VSIM_GetVSim(UINT32 atHandle);
CiReturnCode VSIM_SetVSim(UINT32 atHandle);

CiReturnCode SIM_RunGSMAlgorithm(UINT32 atHandle, char *data, int dataLen);
CiReturnCode SIM_RunTContextAuth(UINT32 atHandle, char *rand, int randLen, char *autn, int autnLen, int sessionid);
CiReturnCode SIM_GetATR(UINT32 atHandle);
CiReturnCode SIM_GetApppin_Req(UINT32 atHandle);
CiReturnCode SIM_GetEccList(UINT32 atHandle);
CiReturnCode SIM_GetIsimAid(UINT32 atHandle);
CiReturnCode SIM_GetICCID(UINT32 atHandle);
CiReturnCode SIM_GetSimPoll(UINT32 atHandle);
CiReturnCode SIM_SetSimPoll(UINT32 atHandle, int modVal, int pollCfgVal, int stkPoll, int interval);

#ifdef PLATFORM_FOR_PS_LW
CiReturnCode SIM_BtSapConnect(UINT32 atHandle, UINT16 maxMsgSize);
CiReturnCode SIM_BtSapDisConnect(UINT32 atHandle);
CiReturnCode SIM_BtSapTransferAPDU(UINT32 atHandle, UINT8 apduType, char* apduCommand, int apduCommandLen);
CiReturnCode SIM_BtSapGetATR(UINT32 atHandle);
CiReturnCode SIM_BtSapSimControl(UINT32 atHandle, UINT8 control);
CiReturnCode SIM_BtSapGetCardStatus(UINT32 atHandle);
CiReturnCode SIM_BtSapSetTransportProtocol(UINT32 atHandle, UINT8 protocol);

#endif
CiReturnCode SIM_writesimget(UINT32 atHandle);

void simCnf(CiSgOpaqueHandle opSgCnfHandle,	CiServiceGroupID svgId, CiPrimitiveID primId, CiRequestHandle  reqHandle, void* paras);
void simInd(CiSgOpaqueHandle opSgOpaqueHandle, CiServiceGroupID svgId, CiPrimitiveID primId,CiIndicationHandle  indHandle,void* pParam);
void resetSimParas(void);
void parseICCIDData(char *dst, char *data);
void libConvertNumToHex(char *inData, int inLen, char *outData);
int libConvertHexToNum(char *inData, int inLen, char *outData);
CiReturnCode SIM_GetAppNum(UINT32 atHandle, UINT8 op);
CiReturnCode SIM_GetAppInfo(UINT32 atHandle, UINT8 idx); 

enum
{
	CMD_TYPE_CPIN,
	CMD_TYPE_EPIN,
	CMD_TYPE_DETECT,
	CMD_TYPE_MEPEPIN,
	CMD_TYPE_CPINR,
	CMD_TYPE_MEP,
	CMD_TYPE_PINCNT,
	CMD_TYPE_ZSEC,
	CMD_TYPE_ZNCK,
};

/* Run GSM Algorithm, 3gpp 51.011*/
#define RGA_RAND_LEN       16
#define RGA_AUTN_LEN       16
#define RGA_SRES_LEN       4
#define RGA_CK_LEN         8
typedef enum OPER_NEEDCISIMCHV_TAG {
	RESET_ACM = 1,
	SET_ACM_MAX,
	SET_CPUC,
	SET_CLCK_SC,
} _NeedSimChvOper;

#define SIM_CARD_TYPE_USIM_BIT 0
#define SIM_CARD_TYPE_TEST_BIT 1
typedef enum AT_SIM_CARD_TYPE
{
	AT_SIM_CARD_TYPE_SIM = 0,
	AT_SIM_CARD_TYPE_USIM,
	AT_SIM_CARD_TYPE_TEST_SIM,
	AT_SIM_CARD_TYPE_TEST_USIM,
	AT_SIM_CARD_TYPE_UNKNOWN,
}AtSimCardType;


/*add for AT*ISIMAID*/
typedef struct {
	char isim_aid[UICC_AID_MAX_SIZE * 2 + 1];
	//pthread_mutex_t sim_mutex;
} GetIsimAid;

typedef struct {
	short eccNum;
	char eccs[CI_SIM_ECC_LIST_MAX_SIZE * 20]; //strlen("<serviceCategory1>, <number1>,") < 20
} eccList;

typedef struct RespHandle_tag
{
    UINT32 respHandle;
    UINT16 bWaiting;
} RespHandle;

/************************************************************************************
 *
 * SIM related const and global variables
 *
 *************************************************************************************/

#define SIM_SELECT         164
#define READ_BINARY        176
#define READ_RECORD        178
#define GET_RESPONSE        192
#define UPDATE_BINARY        214
#define UPDATE_RECORD        220
#define STATUS			242
#define RETRIEVE_DATA       203
#define SET_DATA        219
#define LAST_RECORD        25
#define FIRST_RECORD        25
#define INVALID_INDEX	-1
#define EMPTY		0xFF

#define SIM_CARD_UNKNOWN -1
#define SIM_CARD_ABSENT  0
#define SIM_CARD_PRESENT 1
#define SIM_SLOT_1 1
#define SIM_SLOT_2 2
/* Define some private primitives for SIM service */
#define CI_SIM_PRIM_GENERIC_CMD_ERGA_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 1)
#define CI_SIM_PRIM_GENERIC_CMD_ERTCA_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 2)
#define CI_SIM_PRIM_MEP_READ_STATUS_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 3) // for AT+CLCK="xx",2
#define CI_SIM_PRIM_MEP_READ_STATUS_EXT_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 4) // for AT*CLCK="xx",2
#define CI_SIM_PRIM_MEP_SET_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 5) // for AT+CLCK="xx",0/1 and AT*CLCK="xx",0/1
#define CI_SIM_PRIM_CHV_OPER_CPIN_VERIFY_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 6)
#define CI_SIM_PRIM_CHV_OPER_CPIN_UNBLOCK_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 7)
#define CI_SIM_PRIM_CHV_OPER_CPIN_CHANGE_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 8)
#define CI_SIM_PRIM_RESET_ACM_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 9)
#define CI_SIM_PRIM_SET_ACM_MAX_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 10)
#define CI_SIM_PRIM_SET_CPUC_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 11)
#define CI_SIM_PRIM_GET_EPIN_STATE_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 12)
#define CI_SIM_PRIM_GET_SIM_DETECT_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 13)
#define CI_SIM_PRIM_CSIM_OPEN_CHANNEL_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 14)// AT+CSIM to CCHO
#define CI_SIM_PRIM_CSIM_CLOSE_CHANNEL_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 15)// AT+CSIM to CCHC
#define CI_SIM_PRIM_GET_MEPEPIN_STATE_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 16)//AT*EPIN
#define CI_SIM_PRIM_CSIM_CGLA_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 17)	/* AT+CSIM to CGLA */
#if QUEC_SIM_PINCNT_SUPPORT
#define CI_SIM_PRIM_GET_PINCNT_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 19)	/* for *PINCNT */
#endif
#define CI_SIM_PRIM_REMAIN_PIN_RETRIES_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 18)//AT+CPINR
#define CI_SIM_PRIM_CLCK_SC_REQ (CI_SIM_PRIM_LAST_COMMON_PRIM + 20)



#define MAX_AID_LENGTH     16
#ifndef AT_PARSE_REFRESH
#define AT_PARSE_REFRESH
#endif
#define TEL_PROCESS_STK_IND_DIRECT


SimFileDir libGetDirFromEFFileID(const SimEfFileId FileIndex, UINT32 atHandle);
BOOL libCheckIsMasterFile(SimEfFileId *EFFileID, SimFileDir *SIMFileDir);
void libGetSIMEfFilePath( UINT16 root, UINT16 FileDir, UINT16 EFFileID, CiSimFilePath* pEfFilePath);
void libConvert2UsimResp(UINT32 len, UINT8 *pData, UINT8 *pUSIMResponse, UINT32 USIMSize);
CiReturnCode ciRequest_Transfer(CiServiceHandle svchandle,
								CiPrimitiveID primId,
								CiRequestHandle crsm_reqHandle,
								void* paras);


void simInd_2(CiSgOpaqueHandle    opSgIndHandle,
		CiServiceGroupID    svgId,
		CiPrimitiveID       primId,
		CiIndicationHandle  indHandle,
		void*               pParam);

void simCnf_2(CiSgOpaqueHandle  opSgCnfHandle,
		CiServiceGroupID  svgId,
		CiPrimitiveID     primId,
		CiRequestHandle   reqHandle,
		void*             paras);
void libDisplaySimRc (CiRequestHandle atHandle, CiSimRc rc);

CiReturnCode SIM_GetCustomServiceProfileReq(UINT32 atHandle);

#endif

