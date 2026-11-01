/*--------------------------------------------------------------------------------------------------------------------
(C) Copyright 2006, 2007 Marvell DSPC Ltd. All Rights Reserved.
-------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
*  INTEL CONFIDENTIAL
*  Copyright 2006 Intel Corporation All Rights Reserved.
*  The source code contained or described herein and all documents related to the source code (“Material? are owned
*  by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
*  its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
*  Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
*  treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
*  transmitted, distributed, or disclosed in any way without Intel’s prior express written permission.
*
*  No license under any patent, copyright, trade secret or other intellectual property right is granted to or
*  conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
*  estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
*  Intel in writing.
*  -------------------------------------------------------------------------------------------------------------------
*
*  Filename: teldef.h
*
*  Authors:  Vincent Yeung
*
*  Description: Macro used for telephony controller
*
*  History:
*   May 19, 2006 - Creation of file
*
*  Notes:
*
******************************************************************************/

#ifndef TELDEF_H
#define TELDEF_H

#include "at_gbl_types.h"
#include "stdio.h"
#include <utlAtParser.h>
#include "utlTrace.h"
#ifdef LWIP_IPNETBUF_SUPPORT
#include "tftdef.h"
#include "pdpdef.h"
#endif
#include "quec_cust_feature.h"
#include "quec_at_common.h"
#define RESULT_CODE_NULL utlFAILED
#define ResultCode_t utlReturnCode_T
#ifdef QUECTEL_NETWORK_SUPPORT
#define QUEC_MAX_CGDCONT_LEN    ( MAX_APN_INFO_LEN + 50 )
#define ciRequestExt ciRequest
#endif

//#define AT_CMD_UNUSED_ENABLE
/* MACRO to control dual sim single standby feature */
//#define CRANE_DSS

/******************************************************************************
*   AT Parser Number
******************************************************************************/

typedef enum
{
   TEL_AT_CMD_ATP_0,       //SIM1  indication
   TEL_AT_CMD_ATP_1,      // AT modem fpr SIM1
   TEL_AT_CMD_ATP_2,	//CC for SIM1
   TEL_AT_CMD_ATP_3,    //MM for SIM1
   TEL_AT_CMD_ATP_4,    //MSG for SIM1
   TEL_AT_CMD_ATP_5,    //SIM/PB  for SIM1
   TEL_AT_CMD_ATP_6,    //DEV for SIM1
   TEL_AT_CMD_ATP_7,	//PS for SIM1
   TEL_AT_CMD_ATP_8,	//SS for SIM1
   TEL_AT_CMD_ATP_9,
   TEL_AT_CMD_ATP_10,
   TEL_AT_CMD_ATP_11,
   TEL_AT_CMD_ATP_12,
   TEL_AT_CMD_ATP_13,
   TEL_AT_CMD_ATP_14,
   TEL_AT_CMD_ATP_15,
   TEL_AT_CMD_ATP_16,
   TEL_AT_CMD_ATP_17,
   TEL_AT_CMD_ATP_18,
   TEL_AT_CMD_ATP_19,
   TEL_AT_CMD_ATP_20,
   TEL_AT_CMD_ATP_21,	//for BIP
   TEL_AT_CMD_ATP_22,
   TEL_AT_CMD_ATP_23,
   TEL_AT_CMD_ATP_24,
   TEL_AT_CMD_ATP_25,

   TEL_AT_CMD_ATP_26,
   TEL_MODEM_AT_CMD_ATP,
   TEL_AT_CMD_ATP_28,
   TEL_AT_CMD_ATP_29,
   TEL_AT_CMD_ATP_30,
   TEL_AT_CMD_ATP_31,
   TEL_AT_CMD_ATP_32,
   TEL_AT_CMD_ATP_33,
   TEL_AT_CMD_ATP_34,
   TEL_AT_CMD_ATP_35,

   TEL_AT_CMD_ATP_36,		// SIM2  indication
   TEL_AT_CMD_ATP_37,		// AT modem fpr SIM2
   TEL_AT_CMD_ATP_38,		//CC for SIM2
   TEL_AT_CMD_ATP_39,		//MM for SIM2
   TEL_AT_CMD_ATP_40,		//MSG for SIM2
   TEL_AT_CMD_ATP_41,		//SIM/PB  for SIM2
   TEL_AT_CMD_ATP_42,		//DEV for SIM2
   TEL_AT_CMD_ATP_43,		//PS for SIM2
   TEL_AT_CMD_ATP_44,		//SS for SIM2
#ifndef SINGLE_SIM   
   TEL_AT_CMD_ATP_45,
   TEL_AT_CMD_ATP_46,
   TEL_AT_CMD_ATP_47,
   TEL_AT_CMD_ATP_48,
   TEL_AT_CMD_ATP_49,
   TEL_AT_CMD_ATP_50,
   TEL_AT_CMD_ATP_51,
   TEL_AT_CMD_ATP_52,
   TEL_AT_CMD_ATP_53,
   TEL_AT_CMD_ATP_54,
   TEL_AT_CMD_ATP_55,
   TEL_AT_CMD_ATP_56,
   TEL_AT_CMD_ATP_57,
   TEL_AT_CMD_ATP_58,
#ifdef QUEC_TTYUSB3_ENABLE
   TEL_AT_CMD_ATP_TTYUSB3,
#else
   TEL_AT_CMD_ATP_59,
#endif
   TEL_AT_CMD_ATP_60,
   TEL_AT_CMD_ATP_61,
   TEL_AT_CMD_ATP_62,
   TEL_MODEM_AT_CMD_ATP_1,

   TEL_AT_CMD_ATP_64,
   TEL_AT_CMD_ATP_65,
   TEL_AT_CMD_ATP_66,
   TEL_AT_CMD_ATP_67,
   TEL_AT_CMD_ATP_68,
   TEL_AT_CMD_ATP_69,
   TEL_AT_CMD_ATP_70,
   TEL_AT_CMD_ATP_71,
#endif
#ifdef QUEC_AT_QCFG_USB_NEMA
	TEL_AT_CMD_ATP_NEMA,
#endif
   NUM_OF_TEL_ATP
}

TelAtParserID;

#define MAT_IND_CHANNEL TEL_AT_CMD_ATP_0    	//Chaim20191107 mmi
#define MAT_IND_CHANNEL_1 TEL_AT_CMD_ATP_36  	//Chaim20191107sim2 mmi
#define AT_MODEM_CHANNLE TEL_AT_CMD_ATP_1		//Chaim20191107usb modem
#define AT_MODEM_CHANNLE_1 TEL_AT_CMD_ATP_37 	//Chaim20191107sim2 usb
#define TEL_AT_CMD_ATP_MODEM AT_MODEM_CHANNLE
#define TEL_AT_CMD_ATP_MODEM_1 AT_MODEM_CHANNLE_1

/* For UART dbg shell*/
#define AT_UART_CHANNEL TEL_AT_CMD_ATP_35
#define AT_MODEM_SPI_CHANNLE_1 TEL_AT_CMD_ATP_2

#if QUECTEL_PROJECT_CUST
#define NUM_OF_IMS_ATP 8
#else
#define NUM_OF_IMS_ATP 20
#endif

/*ATP definition for IMS type, start*/
#define DIALER_ATP_INDEX TEL_AT_CMD_ATP_9
#define DIALER_ATP_INDEX_1 (DIALER_ATP_INDEX + TEL_AT_CMD_ATP_36)

#define EVENT_HANDLER_ATP_INDEX (DIALER_ATP_INDEX + 1)
#define EVENT_HANDLER_ATP_INDEX_1 (EVENT_HANDLER_ATP_INDEX + TEL_AT_CMD_ATP_36)

/* TEL_AT_CMD_ATP_11 for volte*/
#define TEL_AT_CMD_ATP_ATNET (TEL_AT_CMD_ATP_12)
#define TEL_AT_CMD_ATP_ATNET_1 (TEL_AT_CMD_ATP_ATNET + TEL_AT_CMD_ATP_36)

#if QUECTEL_PROJECT_CUST
#define TEL_AT_CMD_ATP_UART  (TEL_AT_CMD_ATP_7)
#else
#define TEL_AT_CMD_ATP_UART  (TEL_AT_CMD_ATP_ATNET + 1) // 13
#endif
#define TEL_AT_CMD_ATP_UART_1  (TEL_AT_CMD_ATP_UART + TEL_AT_CMD_ATP_36)

//#define TEL_AT_CMD_ATP_MODEM AT_MODEM_CHANNLE
//#define TEL_AT_CMD_ATP_MODEM_1 AT_MODEM_CHANNLE_1
#ifdef QUECTEL_PROJECT_CUST
#define TEL_AT_CMD_ATP_CMUX_0  (QUEC_CMUX_CHANNEL_0 )  //TEL_AT_CMD_ATP_UART--brent
#define TEL_AT_CMD_ATP_CMUX_1  (QUEC_CMUX_CHANNEL_1 )
#define TEL_AT_CMD_ATP_CMUX_2  (QUEC_CMUX_CHANNEL_2 )
#define TEL_AT_CMD_ATP_CMUX_3  (QUEC_CMUX_CHANNEL_3 )
#define TEL_AT_CMD_ATP_CMUX_4  (QUEC_CMUX_CHANNEL_4 )
#define TEL_AT_CMD_ATP_CMUX_5  (QUEC_CMUX_CHANNEL_5 )
#else
#define TEL_AT_CMD_ATP_CMUX_0  (TEL_AT_CMD_ATP_UART + 1)
#define TEL_AT_CMD_ATP_CMUX_1  (TEL_AT_CMD_ATP_UART + 2)
#define TEL_AT_CMD_ATP_CMUX_2  (TEL_AT_CMD_ATP_UART + 3)
#define TEL_AT_CMD_ATP_CMUX_3  (TEL_AT_CMD_ATP_UART + 4)
#define TEL_AT_CMD_ATP_CMUX_4  (TEL_AT_CMD_ATP_UART + 5)
#define TEL_AT_CMD_ATP_CMUX_5  (TEL_AT_CMD_ATP_UART + 6) // 19
#endif

#ifdef CRANE_MCU_DONGLE
#define TEL_AT_CMD_ATP_CMUX_0_1  (TEL_AT_CMD_ATP_UART_1 + 1)
#define TEL_AT_CMD_ATP_CMUX_1_1  (TEL_AT_CMD_ATP_UART_1 + 2)
#define TEL_AT_CMD_ATP_CMUX_2_1  (TEL_AT_CMD_ATP_UART_1 + 3)
#define TEL_AT_CMD_ATP_CMUX_3_1  (TEL_AT_CMD_ATP_UART_1 + 4)
#define TEL_AT_CMD_ATP_CMUX_4_1  (TEL_AT_CMD_ATP_UART_1 + 5)
#define TEL_AT_CMD_ATP_CMUX_5_1  (TEL_AT_CMD_ATP_UART_1 + 6)
#endif

#if QUECTEL_PROJECT_CUST
#define TEL_BIP_AT_CMD_ATP  (TEL_AT_CMD_ATP_ATNET + 1)
#define AT_BT_CHANNLE     (TEL_BIP_AT_CMD_ATP + 1)
#define TEL_BIP_AT_CMD_ATP_1  (TEL_BIP_AT_CMD_ATP + TEL_AT_CMD_ATP_36) //for sim2
#else
#define TEL_BIP_AT_CMD_ATP  (TEL_AT_CMD_ATP_CMUX_5 + 1)
#define TEL_BIP_AT_CMD_ATP_1  (TEL_BIP_AT_CMD_ATP + TEL_AT_CMD_ATP_36) //for sim2
#define AT_BT_CHANNLE     (TEL_BIP_AT_CMD_ATP + 1) // 21
#endif
#define AT_DM_CHANNLE     (AT_BT_CHANNLE + 1)      //22
#define TEL_MBIM_AT_CHANNEL  (AT_DM_CHANNLE + 1)

/* define a new AT channel, should modify the define */
#define TEL_AT_CMD_IMS_TYPE_ATP_LAST (TEL_MBIM_AT_CHANNEL)
#define TEL_AT_CMD_IMS_TYPE_ATP_LAST_1 (TEL_AT_CMD_IMS_TYPE_ATP_LAST + TEL_AT_CMD_ATP_36)
/*ATP definition for IMS type, end*/

#if QUECTEL_PROJECT_CUST
#define EXT_AT_MODEM_CHANNLE (TEL_AT_CMD_ATP_20)
#else
#define EXT_AT_MODEM_CHANNLE    (TEL_AT_CMD_IMS_TYPE_ATP_LAST + 1)
#endif
#define TEL_EXT_AT_CMD_ATP_MODEM EXT_AT_MODEM_CHANNLE

#define AT_FOAT_CHANNEL (TEL_AT_CMD_ATP_24)
#define AT_FOAT_CHANNEL_1 (AT_FOAT_CHANNEL + TEL_AT_CMD_ATP_36)

#define AT_FLUSH_CHANNEL (TEL_AT_CMD_ATP_25)
#define AT_FLUSH_CHANNEL_1 (AT_FLUSH_CHANNEL + TEL_AT_CMD_ATP_36)

#define AT_ACAT_CHANNEL (TEL_AT_CMD_ATP_26)
#define AT_ACAT_CHANNEL_1 (AT_ACAT_CHANNEL + TEL_AT_CMD_ATP_36)

#define AT_AGPS_CHANNEL (TEL_AT_CMD_ATP_35)
#define AT_AGPS_CHANNEL_1 (AT_AGPS_CHANNEL + TEL_AT_CMD_ATP_36)

#define AT_CHANNEL_BIND_SIM

#define NONE_IMS_FLAG  0
#define IMS_FLAG  1

#define REQUEST_OPTION_FLAG  0
#define CURRENT_OPTION_FLAG  1

//ICAT EXPORTED ENUM
enum
{
	SIM_0,
	SIM_1,
	NUM_OF_SIM
};

//ICAT EXPORTED ENUM
typedef enum
{
	CHANNEL_MMI,
	CHANNEL_IMS,
	NUM_OF_CHANNEL_TYPE
}AT_CHANNEL_TYPE;


typedef struct
{
	UINT8 firstChnlId;
	UINT8 lastChnlId;
	UINT8 channlNum;
}TelAtChannelInfo;

enum TelAtParserCmd
{
	TEL_ATP_CMD_EXIT_CHAN,
	TEL_ATP_CMD_TRIGGER_PARSER,
#ifdef AT_PRODUCTION_CMNDS
	TEL_ATP_CMD_EXIT_CHAN_AND_START_DIAG,
#endif
	TEL_ATP_CMD_NUM
};

#ifdef LWIP_IPNETBUF_SUPPORT
typedef enum _AtpSimType
{
	SIM1_ONLY,
	SIM2_ONLY,
	DUAL_SIM,
	MASTER_SIM,
	INVALID_ATP_SIM_TYPE,
}AtpSimType;

typedef enum _SIMID
{
	SIM1,
	SIM2,
	SIMID_NUM
}SIMID;

typedef enum
{
	TEL_MSG_DATA_NONE,
	TEL_MSG_DATA_CMGS,
	TEL_MSG_DATA_CMGC,
	TEL_MSG_DATA_CNMA,
	TEL_MSG_DATA_CMGW,
	NUM_OF_TEL_MSG_DATA
}TelMsgDataMode;

typedef enum 
{
	CSD_STATUS_CONNECT_DATA,	
	CSD_STATUS_CONNECT_CONTROL,
	CSD_STATUS_DISCONNECTING,
	CSD_STATUS_DISCONNECTED
}TelCsdStatus;

typedef struct _TelAtpDesc
{
	TelAtParserID index;
	char *path;

	AtpSimType targetSim;

	/*Need receive indication from CP side*/
	BOOL needIndication;
	/*Need enable this channel when is a AP only product*/
	BOOL apOnly;
} TelAtpDesc;
#endif

#if QUECTEL_PROJECT_CUST
typedef struct _TelAtpDataEntry
{
#ifdef QUEC_APPTCPIP_SUPPORT
#ifdef QUEC_G510_SOCKET_SUPPORT
	UINT8  g510_tcpipDataEntryMode;
	UINT8  g510_sslfileUploadMode;
#endif
	UINT8  tcpipDataEntryMode;
#endif
#ifdef QUEC_MQTT_SUPPORT
    UINT8  mqttDataEntryMode;
#endif
#ifdef QUECT_ALIOT_FEATURE_SUPPORT
    UINT8  aliotmqttDataEntryMode;
#endif
#ifdef QUEC_TCIOT_SUPPORT
	UINT8 tciotDataEntryMode;		//tciot pub
	UINT8 tciotSslfileUploadMode;	//tciot add cert file
#endif
}Quec_TelAtpDataEntry;
#endif

//ICAT EXPORTED STRUCT
typedef struct _TelAtpCtrl
{
	void *taskRef;
	UINT32	 iFd;
	char *path;
	UINT32 index;
	TelMsgDataMode smsDataEntryMode;
	BOOL bEnable;
	BOOL bIsSinkMode;
#ifdef LWIP_IPNETBUF_SUPPORT
	TelAtpPdpCtx pdpCtx;
	TelAtpTftCtx tftCtx;
#endif
    UINT32 reqHandle;
	UINT32 cnmaReply;       /* used in +CNMA */
	UINT32 smsOverNas;
	UINT32 cnmaFlag;	   // 0 -- AT+CNMA, 1 -- AT*CNMA  
#if QUECTEL_PROJECT_CUST
	Quec_TelAtpDataEntry pTelAtpDataEntry;
    void (*cb)(void *obj, void* arg);
#endif
} TelAtpCtrl;

typedef struct
{
	UINT16 Rc;
	char*  RcStr;
} CircCodeMap;

extern TelAtpCtrl gAtpCtrl[];

extern utlAtParser_P aParser_p[ NUM_OF_TEL_ATP ];
extern const char* const gAtpName[ NUM_OF_TEL_ATP ];
extern unsigned short gusXid;
extern BOOL GLFeatureFlag;

extern char revisionId[128];

#define ATM_MANUFACTURER_ID "ASR"
#define ATM_MODEL_ID "LINUX"
#define ATM_REVISION_ID "1.0"
#define ATM_SERIAL_NUMBER "12333"

#define ATM_ID "Marvell"
#define ATM_OBJ_ID      "OBJ ID"
#define ATM_COUNTRY_CODE        "(20,3C,3D,42,50,58,00,61,FE,A9,B4,B5)"


#define PREFIX  "CRANE_CAT1_"
#define MODEL_NAME     getModelName()

#define SW_VER  "V1.0"
#define HW_VER  "EVB1.0"
//#define BASEBAND_VER  "CRANE_CAT1_"##SYSTEM_VERSION



#ifdef CRANE_MCU_DONGLE
#ifdef PSM_ENABLE
#ifdef QUEC_ASR_SMS_ENABLE
#define SMS_ME_SUPPORT
#endif
#endif
#endif

/******************************************************************************
*   OSA Task Priority
******************************************************************************/
#define ESP_TASK_PRIORITY 128
#define MODEM_TASK_PRIORITY 128
//#define AT_TASK_PRIORITY 128
#define AT_TASK_PRIORITY    70
#define OSA_STACK_SIZE		6144	//HYJFixMe:	2009-05-04		in order to fix the stack leakage the old value is 2048
#if defined QUECTEL_PROJECT_CUST
/*Need more than 16K*/
#define AT_STACK_SIZE		(8192 + 3*1024 + utlAT_MAX_LINE_LENGTH*5+14*1024)//Not too small, lwip dump,exp:MQTT dump-switch-out
#else
#define AT_STACK_SIZE		(16*1024)//(8192*4)	//HYJFixMe:	2009-05-04		in order to fix the stack leakage the old value is 2048
#endif

#ifdef SINGLE_SIM
#define AT_MESSAGE_Q_MAX	128
#else
#define AT_MESSAGE_Q_MAX	256
#endif
#define AT_MESSAGE_Q_SIZE	16

/******************************************************************************
*   Response (RESP) related Macro / inline functions
******************************************************************************/
extern int atRespStr(UINT32 reqHandle, UINT8 resultCode, UINT16 errCode, char *respString);
#if defined QUECTEL_PROJECT_CUST
extern int atRespStrEx(UINT32 reqHandle, UINT8 resultCode, UINT16 errCode, char *respString, BOOL padding);
#endif

#define IND_REQ_HANDLE 1
#define IND_REQ_HANDLE_1 2
#define INVALID_REQ_HANDLE 0xFFFFFFFF

#define SIMULATE_SIM1_REQ_HANDLE 0x0    //0x0 << 30
#define SIMULATE_SIM2_REQ_HANDLE 0x40000000    //0x1 << 30

#define ATRESP(REQHANDLE, RESULTCODE, ERRCODE, RESPSTRING) atRespStr( REQHANDLE, RESULTCODE, ERRCODE, RESPSTRING )
#if defined QUECTEL_PROJECT_CUST
#define ATRESPEX(REQHANDLE, RESULTCODE, ERRCODE, RESPSTRING, PADDING) atRespStrEx( REQHANDLE, RESULTCODE, ERRCODE, RESPSTRING, PADDING)
#endif

/******************************************************************************
*   AT Parser related Macro / inline functions
******************************************************************************/


/*--------- Making Compatible to Intel AT Parser--------____-----------------*/
#define RETURNCODE_T utlReturnCode_T

#define TEL_INVALID_EXT_CMD 	utlAT_PARAMETER_OP_UNKNOWN
#define TEL_EXT_EXEC_CMD 		utlAT_PARAMETER_OP_EXEC 	//AT+CGMI
#define TEL_EXT_GET_CMD 		utlAT_PARAMETER_OP_GET	   	//?
#define TEL_EXT_SET_CMD 		utlAT_PARAMETER_OP_SET	   	//=
#define TEL_EXT_ACTION_CMD 		utlAT_PARAMETER_OP_ACTION  	//AT+CPAS
#define TEL_EXT_TEST_CMD 		utlAT_PARAMETER_OP_SYNTAX	//=?


#define INITIAL_RETURN_CODE	utlFAILED
#define AT_RESV_HANDLE(sAtpIndex, xid) \
	(UINT32)(((sAtpIndex << 16) & 0x000F0000) \
		|((sAtpIndex & 0x10) << 26) \
		|(xid))


// CiRequestHandle == UINT32
#define MAKE_CI_REQ_HANDLE( atHandle, reqId )				    \
	(UINT32)(														\
		(												      \
			( (UINT32)reqId << 20)   & 0x3FF00000		       \
		)												      \
		|												      \
		(												      \
			atHandle  & 0x400FFFFF					     \
		)												      \
		)

/* use highest bit to mark whether this request is origined from +CRSM cmd */
#define MAKE_CRSM_CI_REQ_HANDLE( atHandle, reqId )				\
	(UINT32)(														\
		(												      \
			( (UINT32)reqId << 20)   & 0x3FF00000		       \
		)												      \
		|  0x80000000 |										      \
		(												      \
			atHandle  & 0x400FFFFF					     \
		)												      \
		)
#if defined NEZHA3_1826
#define MAKE_AT_HANDLE( sAtpIndex )								\
	(UINT32)(														\
		(												      \
			( (UINT32)sAtpIndex << 13)   & 0x000FE000	       \
		)												      \
		|														\
		(														\
			( (UINT32)sAtpIndex>35? 0x40000000:0x0)			\
		)														\
		|														\
		(													      \
			( (gusXid == 0x1fff)? gusXid=11 : ++gusXid)							\
		)													      \
		)


#define GET_ATP_INDEX( atHandle ) ( (atHandle >> 13 ) & 0x7F )
#else
#define MAKE_AT_HANDLE( sAtpIndex )								\
	(UINT32)(														\
		(												      \
			( (UINT32)sAtpIndex << 16)   & 0x000F0000	       \
		)												      \
		|													      \
		(													      \
			( (UINT32)sAtpIndex & 0x10) << 26 	       \
		)												      \
		|													      \
		(													      \
			( (gusXid == 0xffff)? gusXid=11 : ++gusXid)							\
		)													      \
		)

#define GET_ATP_INDEX( atHandle ) ( ((atHandle >> 16 ) & 0xF) | ((atHandle >> 26) & 0x10) )
#endif
#define GET_AT_HANDLE( reqHandle ) ( reqHandle & 0x400FFFFF )
#define GET_REQ_ID( reqHandle ) ( (reqHandle >> 20 ) & 0x3FF )
#define GET_CRSM_FLAG( reqHandle ) ( (reqHandle >> 31) & 0x1 )
#define GET_SIM1_FLAG( reqHandle ) ( (reqHandle >> 30) & 0x1 )

#ifdef CRANE_MCU_DONGLE
#define RECURESE_LEN 0xFFFFFF
#endif

extern RETURNCODE_T HANDLE_RETURN_VALUE(UINT32 ret);

/******************************************************************************
*   Audio Related Macro
******************************************************************************/


extern void enable_voicecall_audio(void);
extern void disable_voicecall_audio(void);
extern int tel_set_voicecall_mute(INT32 mute);
extern INT32 tel_get_voicecall_mute(void);
extern void tel_init_voicecall_mute(void);

extern INT32 tel_set_loopback_state(INT32 method, INT32 device);
extern INT32 tel_get_loopback_state(INT32 * method, INT32 * device);
#define MACRO_START_VOICE_CALL() //enable_voicecall_audio()

#define MACRO_END_VOICE_CALL() //disable_voicecall_audio()




void initCCContext(UINT32 atHandle);
void initPSContext(UINT32 atHandle);

/* Some global variables */
extern BOOL bLocalTest;


extern const utlAtCommand_T * const pshell_commands;
extern const unsigned int shell_commands_num;
extern ATCMD_TimeOut atcmd_timeout_table[];
#ifndef CRANE_MCU_DONGLE
extern const utlAtCommand_T * const pshell_commands_mmi;
extern const unsigned int shell_commands_num_mmi;
#endif
extern ATCMD_TimeOut atcmd_timeout_table_mmi[];

#ifdef LWIP_IPNETBUF_SUPPORT
BOOL getATRdyPhase1(void);
BOOL getATRdyPhase2(void);
#endif

#endif

/* END OF FILE */
