/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/


/************************************************************************/
/*                                                                      */
/* Title: IPC Comm. pacakge header file                                 */
/*                                                                      */
/* Filename:  IPCComm.h                                                 */
/*                                                                      */
/* Authors: Adi Dayan                                                   */
/*                                                                      */
/* Target, subsystem: Common Platform, HAL                              */
/************************************************************************/
#ifndef _WS_IPCComm_H_

  #define _WS_IPCComm_H_

/*----------------------------------------------------------------------*/

#include "global_types.h"
#include "WS_IPCCommConfig.h"
#include "prm.h"
#include "UART.h"
/*----------------------------------------------------------------------*/

#define ASSEMBLE_16BIT_OPCODE(Opcode16Bit,SubOpcode,SetID,DataBit,UrgentBit)  CREATE_OPCODE_FIELD(Opcode16Bit,SubOpcode,SetID,DataBit,UrgentBit)
/*  "Opcode16Bit"  -  output parameter. The full 16 bit opcode.
   "SubOpcode,SetID,DataBit,UrgentBit" - input parameters from which the 16 bit opcode is assembled */

#define DISASSEMBLE_16BIT_OPCODE(Opcode16Bit,SubOpcode,SetID,DataBit,UrgentBit)  FRAGMENT_OPCODE_FIELD(Opcode16Bit,SubOpcode,SetID,DataBit,UrgentBit)
/*  "Opcode16Bit"  -  input parameter. The full 16 bit opcode.
   "SubOpcode,SetID,DataBit,UrgentBit" - output parameters to which the 16 bit opcode is fragmented */


/*----------------------------------------------------------------------*/

/* Command Parameters */
typedef struct
{
	UINT8	setID;
	UINT8	subOpCode;
	BOOL	data;
	BOOL	urgent;
    UINT16  length; // in BYTES !!! (8bits)
    UINT8  *pipe;
} IPC_NewCmdMsgParams;

typedef struct
{
    UINT16  opCode;
    UINT16  length; // in BYTES !!! (8bits)
    UINT8  *pipe;
} IPC_CmdMsgParams;

/* Op-Code Registration Parameters */
typedef struct
{
    UINT16 setID;
	UINT16 subOpCode;
	BOOL   allSubOpCodes;
} OpCodeParams;

/*----------------------------------------------------------------------*/

/* Spy command + data parameters */

#ifdef SPY_CMD
typedef struct
{
    UINT16 dataLength;
    UINT32 *data;
} SpyCmdData;
#endif

/*----------------------------------------------------------------------*/

/* Configuration Parameters */
typedef enum
{
    IPC_WM_NOTIFICATION,
    IPC_WM_POLLING
} IPC_RxWorkMode;

typedef struct
{
    IPC_RxWorkMode msgWorkMode;
} IPC_Config;


/*----------------------------------------------------------------------*/

/* Data Parameters */
typedef enum
{
    IPC_DCN_DATA_CHANNEL_0,
    IPC_DCN_DATA_CHANNEL_1,
    IPC_DCN_DATA_CHANNEL_2,
    IPC_DCN_DATA_CHANNEL_3,
    IPC_DCN_DATA_CHANNEL_4,
    IPC_DCN_DATA_CHANNEL_5,
    IPC_DCN_DATA_CHANNEL_6,
	IPC_DCN_DATA_CHANNEL_7,
	/////////////////////// TX (Seagull to DSP) /////////////////////////
	IPC_TX_DCN_DATA_CHANNEL_0 = 0,					// WBCDMA_DCH_DATA_TX_CHAN = 0
	IPC_TX_DCN_DATA_CHANNEL_1,						// PLE_DATA_CHANNEL_CPHY_PRS_ASSISTANCE_REQ  
	IPC_TX_DCN_DATA_CHANNEL_2,						// DIG_RF_POWER_UP_DATA_CHAN
	IPC_TX_DCN_DATA_CHANNEL_3,						// WBCDMA_GSM_MEAS_DATA_CHAN
	IPC_TX_DCN_DATA_CHANNEL_4,						// PLE_DATA_CHANNEL_CPHY_RR_DED_CFG_REQ
	IPC_TX_DCN_DATA_CHANNEL_5,						// PLE_DATA_CHANNEL_CPHY_CONN_MEAS_REQ		  
	IPC_TX_DCN_DATA_CHANNEL_6,						// WBCDMA_RX_TFCS_TABLE_CHAN
	IPC_TX_DCN_DATA_CHANNEL_7						// WBCDMA_SET_UL_TFCS_CHAN

} IPC_DataChannelNumber;

#define PL_MS_ENG_REP_DATA_CHANNEL_GS88				IPC_DCN_DATA_CHANNEL_6
#define PL_MS_ENG_REP_DATA_CHANNEL_RF63				IPC_DCN_DATA_CHANNEL_7

#define PL_TCC_DATA_CHANNEL_DL_TFCS					IPC_TX_DCN_DATA_CHANNEL_6

typedef enum
{
    IPC_CT_NO_COPY,
    IPC_CT_COPY_TO_KNOWN_DESTINATION,
    IPC_CT_COPY_TO_UNKNOWN_DESTINATION
}IPC_CopyType;

typedef struct
{
    IPC_DataChannelNumber   dataChannelID;
    IPC_CopyType            copyMode;
    UINT16                  dataSize;
    UINT32                  *dataSrcPtr;
    UINT32                  *dataDestPtr;
    //UINT8                   *dataSrcPtr;
    //UINT8                   *dataDestPtr;
} IPC_DataStructToSend;

typedef struct
{
    UINT32                  *dataPtr;
    UINT16                  dataSize;
    IPC_DataChannelNumber   dataChannelID;
} IPC_DataStructReceived;


/*----------------------------------------------------------------------*/

/* Controlling Parameters */
typedef enum
{
    IPC_CTRL_PAUSE_CPU2DSP_COMMUNICATION,
    IPC_CTRL_RESUME_CPU2DSP_COMMUNICATION
} IPC_ControlOperation;

/*----------------------------------------------------------------------*/

/* Status Parameters */

typedef enum
{
    IPC_OS_INIT,
    IPC_OS_NOT_ACTIVE,
    IPC_OS_ACTIVE,
    IPC_OS_COMM_PAUSED
} IPC_OperationState;


typedef struct
{
    BOOL                msgsToPoll;
    IPC_OperationState  activeOperationState;
    BOOL                CPU2DSPCommPaused;
} IPC_Status;

/*----------------------------------------------------------------------*/


/* Return Code */
typedef enum
{
    IPC_RC_AVAILABLE =0,
    IPC_RC_UNAVAILABLE,
    IPC_RC_TIMEOUT,
    IPC_RC_INVALID_SIZE_OF_RX_DATA_PACKET,
    IPC_RC_INVALID_APPLICATION_ID,
    IPC_RC_INVALID_COMMAND_PARAMS,
    IPC_RC_DATA_CHANNEL_UNAVAILABLE,
    IPC_RC_DATA_CHANNEL_ALREADY_OPEN,
    IPC_RC_NO_MESSAGE_TO_READ,
    IPC_RC_CPU2DSP_COMM_ALREADY_PAUSED,
    IPC_RC_CPU2DSP_COMM_NOT_PAUSED,
    IPC_RC_INVALID_REGISTRATION_PARAMS,
    IPC_RC_TOO_MANY_REGISTERS = 12
} IPC_ReturnCode;


/*----------------------------------------------------------------------*/

IPC_ReturnCode IPCCommLegacyCommandSend(IPC_CmdMsgParams *cmdToSend, ApplicationID sourceID);
#define IPCCommCommandSend IPCCommLegacyCommandSend // default NULL-wrapper (for Hermon competability to Thelon-IPC legacy)

IPC_ReturnCode IPCCommNewOpcodeCommandSend(IPC_NewCmdMsgParams *cmdToSend, ApplicationID sourceID);


IPC_ReturnCode IPCCommMessageRead(UINT16 *msgLength, UINT8 *msg);

//void IPCCommNotifyMessageReceived(UINT16 msgOpCode, UINT16 msgLength, UINT8 *msgData);
typedef void (*IPCCommNotifyMessageReceived)(UINT16, UINT16, UINT8 *);

//void IPCCommNotifyDataReceived(IPC_DataStructReceived *dataParams, IPC_CmdMsgParams *msgAttachedToData);
typedef void (*IPCCommNotifyDataReceived)(IPC_DataStructReceived *, IPC_CmdMsgParams *);

//void IPCCommNotifyDataBufferFree(UINT8 *data, IPC_DataChannelNumber chanID);
typedef void (*IPCCommNotifyDataBufferFree)(UINT32 *, IPC_DataChannelNumber);

//void IPCCommNotifyDataChannelFree(IPC_DataChannelNumber chanID);
typedef void (*IPCCommNotifyDataChannelFree)(IPC_DataChannelNumber);

//IPC_ReturnCode IPCCommGetDataPointer(UINT8 **dataLocationPtr, UINT16 dataSize, IPC_DataChannelNumber chanID,
//                                     IPC_CmdMsgParams* msg);
typedef IPC_ReturnCode (*IPCCommGetDataPointer)(UINT32 **, UINT16, IPC_DataChannelNumber,IPC_CmdMsgParams*);

typedef void (*IPCCommNotifySelfEventReceived) (UINT32 MessageParam);

IPC_ReturnCode IPCCommDataSend(IPC_DataStructToSend *dataParams, IPC_CmdMsgParams *cmdToAttachData, ApplicationID appID);
IPC_ReturnCode IPCCommNewOpcodeDataSend(IPC_DataStructToSend *dataParams, IPC_NewCmdMsgParams *cmdToAttachData, ApplicationID appID);

IPC_ReturnCode IPCCommFreeDataChannel(IPC_DataChannelNumber dataChannelID, ApplicationID appID);



/*----------------------------------------------------------------------*/

/* Common Services - Call-In Functions */

IPC_ReturnCode IPCCommPhase1Init(IPC_Config *initConfig);
IPC_ReturnCode IPCCommPhase2Init(void);
IPC_ReturnCode IPCCommConfig(IPC_Config *newConfig);
IPC_ReturnCode IPCCommOpen(void);
IPC_ReturnCode IPCCommClose(void);

IPC_ReturnCode IPCCommControl(IPC_ControlOperation controlAction);

IPC_Status *IPCCommStatus(void);
void	IPC_EEHandlerRegistration(void);

SwVersion IPCCommGetVersion(void);
void IPCCommGetConfigure(IPC_Config *currentConfig);

IPC_ReturnCode IPCCommRegister(ApplicationID registeredAppID,
                               IPCCommNotifyMessageReceived callbackNotifyMessageReceived,
                               UINT16 *notifyOnMessage, UINT8 msgArrayLength,
                               IPCCommNotifyDataBufferFree callbackNotifyDataBufferFree,
                               IPC_DataChannelNumber *notifyOnDataBuff, UINT8 dataBuffArrayLength,
                               IPCCommNotifyDataChannelFree callbackNotifyDataChannelFree,
                               IPC_DataChannelNumber *notifyOnDataChan, UINT8 dataChanArrayLength,
                               IPCCommNotifyDataReceived callbackNotifyDataReceived,
                               IPC_DataChannelNumber *notifyOnDataReceived, UINT8 dataReceivedArrayLength,
                               IPCCommGetDataPointer callbackGetDataPointer,
                               IPC_DataChannelNumber *getDataPtr, UINT8 getDataPtrArrayLength);

IPC_ReturnCode IPCCommUnRegister(ApplicationID unbindApplicationID);
void IPCCommSendSelfEvent (IPCCommNotifySelfEventReceived callbackNotifyotifyOnSelfEventReceived,UINT32 MessageParam);

/*----------------------------------------------------------------------*/
#ifdef SPY_CMD

/* Spy Command + Data */

// void IPCCommSpyCommandNotification(UINT16 cmdOpCode, UINT16 cmdLength, UINT8 *cmdPipe, SpyCmdData *data);
typedef void (*IPCCommSpyCommandNotification)(UINT16, UINT16, UINT8*, SpyCmdData*);

// register to commands to be spied
IPC_ReturnCode IPCCommSpyCmd(ApplicationID registeredAppID,
                             IPCCommSpyCommandNotification callbackNotifySpyCommand,
                             UINT16 *notifyOnCmd, UINT8 cmdArrayLength);

// unregister
IPC_ReturnCode IPCCommUnSpyCmd(ApplicationID unbindApplicationID);

#endif

extern Bool ipcNoPlpMode;
void ipcDispatchMsg (UINT16* buffer);
/*----------------------------------------------------------------------*/


/* System Services */
ApplicationID IPCCommApplicationIDGet(void);
void IPCCommApplicationIDReturn(ApplicationID appID);
void IPCCommWriteToMSAGpRegister(void);
void IPCinitCyclicBuffersParams(void);
void clearIPCRegisters(void);
void IPCD2Recover( PM_PowerStatesE stateexited, BOOL b_DDR_ready, BOOL b_RegsRetainedState);
IPC_ReturnCode IPCCommPhase3Init(void);
typedef enum
{
	IPC_ERROR_INDICATION_POINTER_REQUEST_FAIL,
	IPC_ERROR_INDICATION_POINTER_REQUEST_NULL

} IPC_ERROR_INDICATION_TYPE;


typedef struct
{
   IPC_ERROR_INDICATION_TYPE        error_type;
   UINT8  							channelID;
} IPC_ERROR_INDICATION;




typedef void (*IPCErrorIndicationCallBack)( IPC_ERROR_INDICATION * );

void IPCErrorIndicationCallBackBind ( IPCErrorIndicationCallBack    callBackPtr );

#if IPC_UART_DEBUG
#define IPC_UART uart_printf
#else
#define IPC_UART(...) ((void)0)
#endif

#endif  /* _WS_IPCComm_H_ */



