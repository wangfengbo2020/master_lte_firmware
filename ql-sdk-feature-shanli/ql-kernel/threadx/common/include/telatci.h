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
*  Filename: telatci.h
*
*  Description:  Telephony AT2CI utilities header file
*
*  History: 
*   May 19, 2006 - Creation of file    
*
*  Notes:
*
******************************************************************************/

/*------------ External include files ---------------------------------------*/
/*------------ Local include definitions ------------------------------------*/
/*--------- Local defines ---------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*-------- Local macro definitions ------------------------------------------*/
/*-------- Local type definitions -------------------------------------------*/
/*--------- Global constants definitions ------------------------------------*/
/*--------- Local constants definitions -------------------------------------*/
/*--------- Global variables declarations ------------------------------------*/
/*-- local function prototypes   --------------------------------------------*/


#ifndef __TELATCIUTL_H__
#define __TELATCIUTL_H__

/* General includes */

//#include "gbl_types.h"
#include "ci_cc.h"
#include "ci_ps.h"
#include "ci_ss.h"
#include "ci_dat.h"
#include "osa.h"
#include "teldef.h"
#include "stub.h"
#include "quec_cust_feature.h"

#define CI_PS_MAX_CID		16
#define CI_PS_3G_ENUM_LOOKUP_END_ELEMENT   	(0xFF) //vcy: due to INT16, old value: (0xFFFF)
#define ERROR_RATIO_STRING_LEN    			(10)
#define SUBSCRIBED_VALUE          			(0)
#define MAX_BITRATE               			(8640)
#define MAX_SDU_SIZE              			(1520)
#define MAX_TRANSFER_DELAY        			(4000)
#define MCC_DIGIT_LENGTH     				(3)
#define MNC_DIGIT_LENGTH_MIN 				(2)
#define MNC_DIGIT_LENGTH_MAX 				(3)
#define DEFAULT_TGSEND_DATA_SIZE 			(1500)

#define TEL_GPRS_MIN_DIAL_STRING_SIZE   		(3)
#define NUM_GPRS_SC_DIGITS          		(2)
#define TEL_GPRS_SC_DIG_1               		('9')
#define TEL_GPRS_SC_DIG_2               		TEL_GPRS_SC_DIG_1

#define TEL_GSM_SC_DIG_1               		  ('8')
#define TEL_GSM_SC_DIG_2               	  	GSM_SC_DIG_1


#define NUM_ENTRIES(X) (sizeof(X)/sizeof(X[0]))

#define ATCI_DEFAULT_PARAM_VALUE      255

#define ATCI_IP_MTU                   1500 /* Maximum Transmission Unit over GPRS */
#define ATCI_IP_LEN                   20   /* IP  header Length */
#define ATCI_UDP_LEN                  8    /* UDP header Length */
#define ATCI_TCP_LEN                  20   /* TCP header Length */

#define ATCI_FIRST_CID                0
#define ATCI_DEFAULT_CID              ATCI_FIRST_CID

#define ATCI_MAX_PACKET_SIZE          10000             
#define ATCI_MAX_PDU_SIZE             ATCI_IP_MTU - ATCI_IP_LEN - ATCI_UDP_LEN
#define ATCI_DEFAULT_PDU_SIZE         ATCI_MAX_PDU_SIZE
#define ATCI_DEFAULT_PDU_COUNT        20
#define ATCI_DEFAULT_UDP_PORT         9
#define ATCI_PS_ADDRESS_SIZE          40
#define ATCI_MAX_PPP_FRAME_SIZE       180
#define ATCI_MAX_FRAME_SIZE           180


#if !defined (min)
# define min(a,b)    (((a) < (b)) ? (a) : (b))
#endif

#define ATCI_MAX_CMDSTR_LENGTH       40  /* maximum characters per AT command line */

#define ATCI_MAX_CISCC_PARAMETER_LENGTH		150

#define ATCI_NULL_TERMINATOR_LENGTH   1
#define ATCI_FACILITY_STR_LENGTH      2

/* PDP data compression, only applicable to SNDCP */
typedef enum  ATCI_PSDCOMP
{
  ATCI_PS_DCOMP_OFF = 0,  /* off, default */
  ATCI_PS_DCOMP_ON,       /* on, manufacturer preferred compression */
  ATCI_PS_DCOMP_V42bis,   /* V.42 bis */

  ATCI_PS_DCOMP_DCOMPS
} _ATCIPsDcomp;

/* PDP header compression */
typedef enum ATCIPSHCOMP
{
  ATCI_PS_HCOMP_OFF=0,  /* off, default */
  ATCI_PS_HCOMP_TCPIP,  /* RFC 1144 */// ON(1)  mode in Spec doesn't supported by CI definition.
  ATCI_PS_HCOMP_IP,     /* RFC 2507 */

  ATCI_PS_NUM_HCOMPS
} _ATCiPsHcomp;
/*
<h_comp>: a numeric parameter that controls PDP header compression (refer 3GPP TS 04.65 [59])
0 ? off (default if value is omitted)
1 ? on (manufacturer preferred compression)
2 ? RFC1144
3 ? RFC2507
Other values are reserved.
*/
#if 0 
#define ATCI_PS_DCOMP_OFF             0
#define ATCI_PS_DCOMP_ON              1
#define ATCI_PS_DCOMP_V42bis        2 // CI_PS_DCOMP_V42bis

#define ATCI_PS_HCOMP_OFF             0
#define ATCI_PS_HCOMP_TCPIP           1
#define ATCI_PS_HCOMP_IP              2
#endif

#define ATCI_PB_STORAGE_STR_LENGTH    4
#define ATCI_MSG_STORAGE_STR_LENGTH   2
#define ATCI_PB_INVALID_INDEX 0 //-1  [Jerry] 0 is invalid PBK ID
/* Max long name length is 16 according to 3GPP 27.007 */
#define ATCI_PLMN_LONG_NAME_LENGTH 16
#define ATCI_PLMN_SHORT_NAME_LENGTH 8

#define ATCI_MAX_INDV_LIST_SIZE             20
#define ATCI_MAX_CI_NUMERIC_RANGE_LIST_SIZE 20

#define ATCI_MAX_QUEUE_SIZE             10

#define ATCI_MAX_SMS_TDPU_SIZE            (232)

#define ATCI_SMS_DELIVER_MTI           ( (UINT8) 0x00 )
#define ATCI_SMS_SUBMIT_MTI            ( (UINT8) 0x01 )
#define ATCI_SMS_COMMAND_MTI           ( (UINT8) 0x02 )
#define ATCI_SMS_STATUS_REPORT_MTI     ( (UINT8) 0x02 )

#define ATCI_SMS_TP_RP       0x80  /* TP-RP, reply path */
#define ATCI_SMS_TP_UDHI     0x40  /* TP User Data Header Indicator  */
#define ATCI_SMS_TP_SRI      0x20  /* TP Status Report Indication */
#define ATCI_SMS_TP_SRR      0x20  /* TP Status Report Request */
#define ATCI_SMS_TP_SRQ      0x20  /* TP Status Report Qualifier */
#define ATCI_SMS_TP_VPF      0x18  /* TP Validity Period Format */
#define ATCI_SMS_TP_MMS      0x04  /* TP More Messages to Send */
#define ATCI_SMS_TP_RD       0x04  /* TP Reject Duplicates */

#define ATCI_TP_MTI_MASK     0x03 /* SMS Message-Type Indicator mask */
#define ATCI_BCD_LOW_MASK  0x0F
#define ATCI_BCD_HIGH_MASK 0xF0
#define ATCI_BCD_FILLER    0x0F
#define ATCI_SMS_BCD_POS   2
//mengliang add 20120511
#define ATCI_SMS_VP_PRESENT  0x10
#define ATCI_SMS_MAX_MSG_LEN             160


#define ATCI_MSG_SUBMIT_FO_DEFAULT  ((UINT8)0x21)  /* Default first octet for SMS-SUBMIT PDU, status report required */ /* NOTE: Voyager cod suggests 17, but17 is NOT SMS-SUBMIT (?) */
#define ATCI_MSG_VP_DEFAULT         ((UINT8)167) /* 24 hours - see 3GPP TS 23.040 */
#define ATCI_MSG_PID_DEFAULT          ((UINT8)0) /* see 3GPP TS 23.040 */
#define ATCI_MSG_DCS_DEFAULT          ((UINT8)0) /* should be 246 (0xF6), but SAC does not support 8-bit alphabet */
#define ATCI_MSG_REF_DEFAULT          ((UINT8)0) /* Reference=0 means that msg ref is set in SAC */
#define ATCI_MSG_UDH_PRESENT          ((UINT8)1)
#define ATCI_MSG_UDH_NOT_PRESENT      ((UINT8)0)

enum _AtciFacilityTypeTag
{
  ATCI_SS_FAC_MIN = 0,
  ATCI_SS_FAC_CS = ATCI_SS_FAC_MIN,
  ATCI_SS_FAC_PS,
  ATCI_SS_FAC_PF,
  ATCI_SS_FAC_SC,
  
  ATCI_SS_FAC_AO,
  ATCI_SS_FAC_OI,
  ATCI_SS_FAC_OX,
  ATCI_SS_FAC_AI,

  ATCI_SS_FAC_IR,
  ATCI_SS_FAC_AB,
  ATCI_SS_FAC_AG,
  ATCI_SS_FAC_AC,

  ATCI_SS_FAC_FD,

  ATCI_SS_FAC_NT,
  ATCI_SS_FAC_NM,
  ATCI_SS_FAC_NS,
  ATCI_SS_FAC_NA,

  ATCI_SS_FAC_PN,
  ATCI_SS_FAC_PU,
  ATCI_SS_FAC_PP,
  ATCI_SS_FAC_PC,

  /* Pin2 must ALWAYS be last! */
  ATCI_SS_FAC_P2,

  ATCI_SS_FAC_MAX

};
typedef UINT8 AtciFacilityType;


typedef struct _AtciFacilityDescriptorStruct
{
  AtciFacilityType   facTypeId;
  CHAR               facTypeStr[ATCI_FACILITY_STR_LENGTH + ATCI_NULL_TERMINATOR_LENGTH];
  INT8               pswdLen;
} AtciFacilityDescriptor;

/*Michal Buaki - Modify this Struct for MEP&UDP support. Facility will divided to 3 logic group: CB, MEP, and all other*/
typedef struct _AtciFacTypeStruct
{
  UINT8           facLogicGroup;
  UINT8           facId;
} AtciFacType;


/* Modes for call forwarding (+CCFC) */
typedef enum ATCI_SS_CCFC_MODE {
  ATCI_SS_MODE_DISABLE = 0,
  ATCI_SS_MODE_ENABLE,
  ATCI_SS_MODE_QUERY_STATUS,
  ATCI_SS_MODE_REGISTER,
  ATCI_SS_MODE_ERASE,
  ATCI_SS_NUM_MODES
} _AtciSsCcfcMode;
typedef UINT8 AtciSsCcfcMode;
/*Michal Buaki - Add this enum for MEP&UDP support. Facility will divided to 3 logic group: CB, MEP, and all other*/
typedef enum ATCI_FAC_LOGIC_GROUP{
	ATCI_FAC_MEP = 0,
	ATCI_FAC_CB,

	ATCI_FAC_OTHER
}_AtciFacilityLogicGroup;
typedef UINT8 AtciFacilityLogicGroup;

/*Michal Buaki - Add this enum for MEP&UDP support*/
typedef enum ATCI_MEP_MODE {
    ATCI_MEP_MODE_ACTIVATE = 0,  
    ATCI_MEP_MODE_DEACTIVATE, 	
    ATCI_MEP_MODE_DISABLE,    		
	ATCI_MEP_MODE_READ,  	
    ATCI_MEP_MODE_UNBLOCK,    
    ATCI_MEP_MODE_NUM_OPERS
} _AtciMEPMode;
typedef UINT8 AtciMEPMode;

/*Michal Buaki - Add this enum for MEP&UDP support*/
typedef enum ATCI_UDP_MODE {
    ATCI_UDP_MODE_ACTIVATE = 0,  
    ATCI_UDP_MODE_DEACTIVATE, 	
	ATCI_UDP_MODE_READ, 
	ATCI_UDP_MODE_NUM_OPERS 	
} _AtciUDPMode;
typedef UINT8 AtciUDPMode;

/*Michal Buaki - Add this enum for MEP&UDP support*/
typedef enum ATCI_UDP_CAT {
    ATCI_UDP_CAT_UNAUTHERIZED_SIM_DETECTION = 0,				  	
    ATCI_UDP_CAT_INVALID_SIM_DETECTION,			 	
	ATCI_UDP_NUM_CATS
} _AtciUDPCat;
typedef UINT8 AtciUDPCat;


#define ATCI_SS_BS_EXT_ALL_SERVICES           0xFF


#define ATCI_CBST_DEFAULT_SPEED  6
#define ATCI_CBST_DEFAULT_NAME   0
#define ATCI_CBST_DEFAULT_CE     1

/* current USSD operation states */
typedef enum ATCI_USSD_STATE {
  ATCI_USSD_IDLE = 0,
  ATCI_USSD_MO_WAIT_NW_RSP,
  ATCI_USSD_MT_WAIT_TE_RSP,
  ATCI_USSD_MT_TE_RSP_SENT,
  ATCI_USSD_ABORT_SENT,
  ATCI_USSD_NUM_STATES
} _AtciUssdState;
typedef UINT8 AtciUssdState;

/* current USSD operation states */
typedef enum ATCI_DATA_MODE_TYPE {
  ATCI_WAIT_PS_DEFINE_CTX,
  ATCI_WAIT_PS_DEFAULT_CTX,
  ATCI_WAIT_PS_ENTER_DATA,
  ATCI_WAIT_PS_DATA_OK,
  ATCI_WAIT_PS_DEACTIVATE,
  ATCI_PS_CTX_DEFINED,
  ATCI_PS_DATA,
  ATCI_PS_PPP_DATA,
  ATCI_PS_SINK_DATA,

  ATCI_WAIT_CS_DATA_CONN,
  ATCI_WAIT_CS_DATA_OK,
  ATCI_CS_DATA,
  ATCI_CS_PPP_DATA,
  ATCI_CS_SINK_DATA,

  ATCI_WAIT_CS_VOICE,
  ATCI_CS_VOICE,

  ATCI_NUMS_DATA
} _AtciDataConnType;
typedef UINT8 AtciDataConnType;

/* current USSD operation states */
typedef enum ATCI_PPP_STATE {
  ATCI_PPP_OFF = 0,
  ATCI_PPP_REQUESTED,
  ATCI_PPP_ON
} _AtciPppState;
typedef UINT8 AtciPppState;

/* current CSCS character set enum */
typedef enum ATCI_CHARACTER_SET {
	ATCI_CHSET_GSM = 0,
	ATCI_CHSET_HEX,
	ATCI_CHSET_IRA,
	ATCI_CHSET_PCDN,
	ATCI_CHSET_UCS2,
	ATCI_CHSET_8859_N,
	ATCI_CHSET_8859_C,
	ATCI_CHSET_8859_A,
	ATCI_CHSET_8859_G,
	ATCI_CHSET_8859_H,
} _AtciCharacterSet;
typedef UINT8 AtciCharacterSet;
/*************************************************
**  Data Structures
*/

typedef struct AtciSSCntx_Struct
{
	UINT8 queryCallClassStatus;
	UINT8 ussdMode;
	AtciUssdState currentUssdState;
	UINT8 localCwOption;
	UINT8 localClipPresent;
}AtciSSCntx;

typedef struct ErrorRatioLookupTag
{
  const INT16 mantissa;
  const INT16 exponent;
  const INT32 enumValue;
} ErrorRatioLookup;

typedef struct EnumParamLookupTag
{
  const INT32 atParam;
  const INT32 bgParam;
} EnumParamLookup;

typedef struct cgSend_struct{
  UINT16  dataSize;
  BOOL    isUnackRlc;
  UINT8   sapi;
  UINT8   peakThroughput;
  UINT8   radioPriorityLevel;
}CgSend;

typedef struct AtciQosQuery_Struct{
  BOOL    inProgress;
  BOOL    qosType;
  UINT8   cid;
}AtciQosQuery;


typedef enum ATCIQOSTYPE
{
  ATCI_QOSTYPE_MIN = 0,   /* Minimum QoS */
  ATCI_QOSTYPE_REQ,       /* Requested QoS */
  ATCI_QOSTYPE_NEG,       /* Negotiated QoS */

  ATCI_QOSTYPE_NUMTYPES
} _AtciQosType;

typedef struct AtciCurrentSetCntx_Struct{
  BOOL	bDefined;
  UINT8 cid;
  CiPsPdpType    pdpType;
  UINT8          pdpAddress[ CI_PS_PDP_IP_V6_SIZE ];
  _AtciConnectionType	 connectionType;
  CiRequestHandle	   reqHandle;		  /* CiRequestHanlde that the call is originated from */
} AtciCurrentSetCntx;

typedef struct AtciCurrentPsCntx_Struct{
  UINT8		currCid;
  void *reqMsg;
}AtciCurrentCntx;

typedef struct AtciCurrentPsCntxList_Struct{
  AtciCurrentCntx	currCntx[NUM_OF_TEL_ATP];
  AtciCurrentSetCntx cInfo[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];
#ifndef SINGLE_SIM 
  AtciCurrentSetCntx cInfo_1[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];
#endif
}AtciCurrentPsCntxList;


/* Call Information structure */
typedef struct AtCiCcCallInfo_struct {
    CiCcCallId           CallId;            /* Unique Call Identifier               */
    CiBoolean            IsEmergency;       /* Is this an Emergency Call?           */
    CiBoolean            IsMPTY;            /* Is this part of a Multiparty Call?   */
    CiCcCallDirection    ReleaseDirection;  /* Release Direction (MT/MO) Indicator  */
    CiCcCallDirection    CallDirection;     /* Call Direction (MT/MO) Indicator     */
    CiCcCurrentCState    OldState;          /* Previous Call State                  */
    CiCcCurrentCState    State;             /* Current Call State                   */
    CiCcCurrentCMode     OldMode;           /* Previous Call Mode                   */
    CiCcCurrentCMode     Mode;              /* Current Call Mode                    */
    UINT8                Digits[ CI_MAX_ADDRESS_LENGTH + ATCI_NULL_TERMINATOR_LENGTH ];  /* Number Digits */
	UINT8  				 DigitsLength;		
	CiAddressType AddrType;                                                                 /* Address Type */
	CiOptNameInfo Name;                                                                     /* Name Information */
	CiBoolean SsNumberInfoReceived;                                                         /* Have received SS number indication or not, such as +CLIP/+COLP */
	CiBoolean SsNameInfoReceived;                                                           /* Have received SS name indication or not, such as +CNAP */
	CiRequestHandle reqHandle;                                                              /* CiRequestHanlde that the call is originated from */
	CiCcCliValidity CliValidity;															/* CLI Validity indicator*/
} AtCiCcCallInfo;

typedef struct AtciCurrentCall_Struct{
	CiCcBasicCMode    currBasicMode;				/* Current Basic Call Mode           */
    CiCcCallId        currCallId;           /* Unique Call Identifier               */
	CiRequestHandle	  currHandle;			/* CiRequestHanlde that the call is originated from */
}AtciCurrentCall;

typedef struct AtciCurrentCallsList_Struct{
	AtciCurrentCall	  currCall[ NUM_OF_TEL_ATP ];
    UINT8             NumCalls;
    AtCiCcCallInfo    callInfo[ CICC_MAX_CURRENT_CALLS ];
} AtciCurrentCallsList;

typedef struct _AtciFrameData
{
  UINT8  dataLength;
  CHAR   data[ATCI_MAX_FRAME_SIZE];
} AtciFrameData;

typedef struct _AtciFramesQueue
{
  UINT8               currentEntries;
  UINT8               readIdx;
  UINT8               writeIdx;
  AtciFrameData       frames[ATCI_MAX_QUEUE_SIZE];
} AtciFramesQueue;

typedef struct _AtciMsgInfo
{
  UINT8   fo;  /* First octet */
  UINT8   vp;  /* Validity Period */
  UINT8   pid; /* Protocol Identifier */
  UINT8   dcs; /* Data coding scheme */
  UINT8   msgRef;
  UINT8   udhPresent; /* User Data Header Present */ 

  UINT8   addrType;
  UINT8   addrPlan;
  UINT16   maxMsgLen;
	UINT8 stat;    /* Message status, mainly used in +CMGW */
  UINT8   destAddr[ CI_MAX_ADDRESS_LENGTH + ATCI_NULL_TERMINATOR_LENGTH ];
} AtciMsgInfo;

/*************************************************
**  State Machine Enums
*/
typedef enum ATCI_CALL_STATE
{
	CALL_IDLE,
	CALL_IN_PROGRESS,
	CALL_CONNECTED,
	CALL_DISCONNECTED

} _AtciCallState;
typedef UINT8 AtciCallState;

typedef enum  ATCI_GPRS_STATE
{
	ATCI_GPRS_DETACH_REQ = 0,
	ATCI_GPRS_ATTACH_REQ = 1

} _AtciGprsState;
typedef UINT8 AtciGprsState;

typedef enum ATCI_DIAL_NUMBER_TYPE
{
  /* Number format as described in GSM 04.08 section 10.5.4.7 */
  ATCI_DIAL_NUMBER_UNKNOWN       = 129,   /* Unknown type, IDSN format number */
  ATCI_DIAL_NUMBER_RESTRICTED    = 128,   /* Unknown type, unknown number format */
  ATCI_DIAL_NUMBER_NATIONAL      = 161,   /* National number type, IDSN format */
  ATCI_DIAL_NUMBER_INTERNATIONAL = 145,   /* International number type, ISDN format */
  ATCI_DIAL_NUMBER_NET_SPECIFIC  = 177,   /* Network specific number, ISDN format */

    /* Added by Michal Bukai*/
  ATCI_DIAL_NUMBER_DEDICATED	 = 193,
  ATCI_DIAL_NUMBER_EXTENSION	 = 241,

  ATCI_DIAL_NUMBER_INVALID                /* Added by EGOR for +CPBW command */
} _AtciDialNumberType;

typedef UINT8 AtciDialNumberType;

typedef enum ATCI_SMS_FORMAT_MODE
{
  ATCI_SMS_FORMAT_PDU_MODE = 0,  /* pdu mode - default */
  ATCI_SMS_FORMAT_TXT_MODE = 1,  /* text mode */

  ATCI_SMS_FORMAT_NUM_MODE,		 /* invalid mode */

  ATCI_SMS_FORMAT_MODE_MASK           = 0x0F,
  ATCI_SMS_FORMAT_TXT_MODE_SHOW       = 0x10, /* text mode extended. This  parameter is to keep show text mode for implementation AT+CSDH */
  ATCI_SMS_FORMAT_TXT_MODE_SHOW_MASK  = 0xF0
} _AtciSmsFormatMode;

typedef UINT8 AtciSmsFormatMode;


typedef enum ATCI_COPS_MODE
{
  ATCI_AUTOMATIC_MODE = 0,
  ATCI_MANUAL_OPERATOR_SELECTION,
  ATCI_MANUAL_DEREGISTER,
  ATCI_SET_FORMAT,
  ATCI_MANUAL_THEN_AUTOMATIC,
  ATCI_EXTENDED_NETWORK_SEARCH,
  
  ATCI_MODE_NUMS
} _AtciCopsMode;

typedef UINT8 AtciCopsMode;

typedef enum ATCI_COPS_MODE_FORMAT
{
  ATCI_OP_FORMAT_LONG = 0,
  ATCI_OP_FORMAT_SHORT,
  ATCI_OP_FORMAT_NUM,
  
  ATCI_OP_FORMAT_NUMS
} _AtciCopsModeFormat;

typedef UINT8 AtciCopsModeFormat;

/*Added by Michal Bukai - at support for AccTchMode parameter*/
typedef enum ATCI_CPOL_ACT
{
	ATCI_ACT_GSM  = 0,
	ATCI_ACT_GSM_COMPACT,
	ATCI_ACT_UTRAN,
	ACT_GSM_EGPRS,		  /**< GSM w/EGPRS */
	ACT_UTRAN_HSDPA,		  /**< UTRAN w/HSDPA */
	ACT_UTRAN_HSUPA,		  /**< UTRAN w/HSUPA */
	ACT_UTRAN_HSPA,		  /**< UTRAN w/HSDPA and HSUPA */
	ATCI_ACT_EUTRAN,//mengliang add for at+clop e_utran_act2011120412
	#ifdef QUEC_CPOL_MODE_SUPPORT_12201
	ATCI_ACT_UTRAN_HSPA_PLUS,    /**< UTRAN w/HSPA+ */
  
  	ATCI_ACT_EUTRAN_PLUS,  /*E-UTRAN CA*/
	#endif
	ATCI_ACT_NUMS
} _AtciCpolAct;

typedef UINT8 AtciCpolAct;

 //need to map this value to ATCI_CFUN_OP_DISABLE_SIM
#define ATCI_PLUS_CFUN_OP_DISABLE_SIM 5    //+CFUN=5
#define ATCI_PLUS_CFUN_OP_FULL_SECONDARY_RX_OFF 6//+CFUN=6


typedef enum ATCI_CFUN_OP_TYPE
{
  ATCI_CFUN_OP_MIN_FUNC = 0,  /* Minimum functionality */
  ATCI_CFUN_OP_FULL_FUNC,     /* Full functionality */
  ATCI_CFUN_OP_DISABLE_RF_TX,
  ATCI_CFUN_OP_DISABLE_RF_RX,
  ATCI_CFUN_OP_DISABLE_RF_RXTX,
  ATCI_CFUN_OP_UPDATE_NVM_MIN_FUNC,  /* Minimum functionality */
  ATCI_CFUN_OP_UPDATE_NVM_FULL_FUNC,     /* Full functionality */
	ATCI_CFUN_OP_MIN_FUNC_NO_IMSI_DETACH,   /* Minimum functionality but without IMSI detach */
	ATCI_CFUN_OP_DISABLE_SIM,                 /*disable SIM*/
  ATCI_CFUN_OP_UPDATE_NVM_DISABLE_RF_RXTX = 9,
  ATCI_CFUN_OP_FULL_SECONDARY_RX_OFF = 10,

  ATCI_CFUN_OP_INIT_RF_3G,          /**< Init 3G RF setting. Only used for 3G */
  ATCI_CFUN_OP_PRI_ONLY_RF_3G,      /**< Enable only primary RF (Pri TX + Pri RX). Only used for 3G */
  ATCI_CFUN_OP_SEC_ONLY_RF_3G,      /**< Enable only secondary RF (Pri TX + Sec RX). Only used for 3G */
  ATCI_CFUN_OP_PRI_SEC_RF_3G,       /**< Enable both primary and secondary RF (Pri TX + Pri RX + Sec RX). Only used for 3G */
  ATCI_CFUN_NUM_OP
} _AtciCfunOpType;
typedef UINT8 AtciCfunOpType;

typedef enum ATCI_CHOLD_MODE_TYPE
{
  ATCI_CHLD_MODE_0 = 0,
  ATCI_CHLD_MODE_1,
  ATCI_CHLD_MODE_2,
  ATCI_CHLD_MODE_3,
  ATCI_CHLD_MODE_4,
  ATCI_CHLD_MODE_1X = 10,
  ATCI_CHLD_MODE_2X = 20,
  ATCI_CHLD_MODE_NUMS
} _AtciChldModeTypes;
typedef UINT8 AtciChldModeTypes;

/* Registration Mode indicators - as required */
typedef enum ATCI_REGMODE {
    ATCI_REGMODE_AUTOMATIC = 0,   /* Automatic Registration Request */
    ATCI_REGMODE_MANUAL,          /* Manual Registration Request */
    ATCI_REGMODE_DEREGISTER,      /* Deregistration Request */
    ATCI_REGMODE_SETONLY, 
    ATCI_REGMODE_MANUAL_AUTO      /* Manual Request, fallback to Automatic */
} _AtciRegMode;
typedef UINT8 AtciRegMode;

typedef enum ATCI_AOC_MODE {
  ATCI_AOC_MODE_QUERY = 0,
  ATCI_AOC_MODE_DEACTIVATE,
  ATCI_AOC_MODE_ACTIVATE,
  
  ATCI_AOC_NUM_MODES
} _AtciAocMode;

typedef UINT8 AtciAocMode;

typedef enum ATCI_CB_MODES {
  ATCI_CB_MSG_ACCEPT = 0,
  ATCI_CB_MSG_REJECT,
  
  ATCI_CB_NUM_MODES
} _AtciCbMode;

typedef UINT8 AtciCbMode;

/* New message indication processing */
typedef enum ATCI_NMI_PROCESSING_MODES {
  ATCI_NMI_BUFFER = 0,  /*  Buffer unsolicited result codes in the TA.    */
                        /* If TA result code buffer is full, indications  */
                        /* can be buffered in some other place or the     */
                        /* oldest indications may be discarded and        */
                        /* replaced with the new received indications     */
  ATCI_NMI_DISCARD_FWD, /*  Discard indication and reject new received    */
                        /* message unsolicited result codes when TA-TE    */
                        /* link is reserved (e.g. in on-line data mode).  */
                        /* Otherwise forward them directly to the TE      */
  ATCI_NMI_BUFFER_FWD,  /*  Buffer unsolicited result codes in the TA     */
                        /* when TA-TE link is reserved (e.g. in on-line   */
                        /* data mode) and flush them to the TE after      */
                        /* reservation. Otherwise forward them directly   */
                        /* to the TE                                      */
  ATCI_NMI_FORWARD,     /*  Forward unsolicited result codes directly to  */
                        /* the TE. TA-TE link specific inband technique   */
                        /* used to embed result codes and data when TA is */
                        /* in on-line data mode                           */
  
  ATCI_NMI_PROCESSING_NUM_MODES
} _AtciNmiProcessingMode;

typedef UINT8 AtciNmiProcessingMode;

/* New message indication routing */
typedef enum ATCI_NMI_MODES {
  ATCI_NMI_DISABLE = 0,   /*  Store received message at cellular side,    */
                          /* disable indication of new message received   */
  ATCI_NMI_INDEX,         /*  Store received message at cellular side,    */
                          /* indicate memory storage and memory location  */
  ATCI_NMI_MSG,           /*  Store received message at cellular side,    */
                          /* forward message to application side directly */
  ATCI_NMI_CLASS3_MSG,    /*  Store CLASS 3 message (SM/CBM) at           */
                          /* cellular side  - forward the message to      */
                          /* application side directly                    */
  
  ATCI_NMI_NUM_MODES
} _AtciNmiMode;  

typedef UINT8 AtciNmiMode;

/* New message indicatio buffer behaviour */
typedef enum ATCI_NMI_BFR {
  ATCI_NMI_BFR_FLUSH = 0, /*  TA buffer of unsolicited result codes defined   */
                          /* within this command is flushed to the TE when    */
                          /* <mode> 1...3 is entered (OK response shall be    */
                          /* given before flushing the codes)                 */
  ATCI_NMI_BFR_CLEAR,     /*  TA buffer of unsolicited result codes defined   */
                          /* within this command is cleared when <mode>       */
                          /* 1...3 is entered                                 */
  
  ATCI_NMI_BFR_NUM_MODES
} _AtciNmiBfr;

typedef UINT8 AtciNmiBfr;

typedef enum ATCI_CLIR_MODES {
  ATCI_CLIR_SUBSCRIPTION = 0,
  ATCI_CLIR_INVOKE,
  ATCI_CLIR_SUPPRESS,
  
  ATCI_CLIR_NUM_MODES
} _AtciClirMode;

typedef UINT8 AtciClirMode; 

typedef enum ATCI_SMS_CUR_CMD {
  ATCI_SMS_CMD_NONE = 0,
  ATCI_SMS_CMD_CMGS,
  ATCI_SMS_CMD_CMGW,
  ATCI_SMS_CMD_CMGC,

  ATCI_SMS_NUM_CMD
} AtciSmsCurCmd;

typedef enum ATCI_SMS_DELETE_MODE {
  ATCI_SMS_DEL_MODE_DEFAULT = 0,
  ATCI_SMS_DEL_INDEX = 0,       /* Delete only one message indicated by the index */
  ATCI_SMS_DEL_RECV_READ,       /* Delete all received read messages */
  ATCI_SMS_DEL_RECV_READ_SENT,  /* Delete all received read messages as well as sent MO messages */
  ATCI_SMS_DEL_RECV_READ_MO,    /* Delete received read messages and all MO messages - sent and unsent */
  ATCI_SMS_DEL_ALL,
  
  ATCI_SMS_NUM_DEL_MODES
} _AtciSmsDelMode;

#define CME_ERROR_CODE_MARVELL_PROPRIETARY 1000
#define CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY    CME_ERROR_CODE_MARVELL_PROPRIETARY

#ifdef QUEC_AT_GPS_ENABLE
typedef enum
{
	QUEC_CME_GNSS_INVALID_PARA     = 501,  /*Invalid parameter*/
    QUEC_CME_GNSS_OPER_NOT_SUPPORT = 502,  /*Operation not supported*/
    QUEC_CME_GNSS_GNSS_SUB_BUSY    = 503,  /*GNSS subsystem busy.*/
    QUEC_CME_GNSS_SE_IS_ONGOING    = 504,   /*Session is ongoing*/
    QUEC_CME_GNSS_SE_NOT_ACT       = 505,  /*Session not activity*/
    QUEC_CME_GNSS_OPER_TIME_OUT    = 506,  /*Operation timeout*/
    QUEC_CME_GNSS_FUNC_NOT_EN      = 507,  /* Function not enable */
    QUEC_CME_GNSS_TIME_INFO_ERR    = 508,  /*Time info error*/
    QUEC_CME_GNSS_XTRA_NOT_ENABLE  = 509,  /*   XTRA not enable*/
    QUEC_CME_GNSS_XTRA_FILE_OPEN_ERR = 510,/*XTRA file open failed.*/
    QUEC_CME_GNSS_XTRA_BAD_CRC     = 511,  /*Bad CRC for XTRA data file*/
    QUEC_CME_GNSS_XTRA_TIME_OUT_RANGE = 512,/*Validity time is out of range*/
    QUEC_CME_GNSS_XTRA_INT_RES_ERR = 513,   /*Internal resource error*/
    QUEC_CME_GNSS_GPS_LOCKED       = 514,   /*GNSS locked*/
    QUEC_CME_GNSS_END_E911         = 515,  /*End by E911*/
    QUEC_CME_GNSS_NOT_FIXED_NOW    = 516,  /*Not fixed now*/
    QUEC_CME_GNSS_CMUX_NOT_OPEN    = 517,  /*CMUX port not open*/
    QUEC_CME_GNSS_UNKNOWN_ERR      = 549,/*  Unknown*/
} quec_atcmd_gps_error_e_type;
#define CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 2000
#endif

typedef enum ATCI_CME_ERROR
{
	CME_PHONE_FAILURE         = 0,                          //phone failure
	CME_NO_CONNECTION         = 1,                          //no connection to phone
	CME_PHONE_ADP_LINK_RSVD         = 2,                    //phone adaptor link reserved
	CME_OPERATION_NOT_ALLOWED         = 3,                  //operation not allowed
	CME_OPERATION_NOT_SUPPORTED     = 4,                    //operation not supported
	CME_PH_SIM_PIN_REQUIRED         = 5,                    //PH SIM PIN required
	CME_PH_FSIM_PIN_REQUIRED         = 6,                   //PH-FSIM PIN required
	CME_PH_FSIM_PUK_REQUIRED         = 7,                   //PH-FSIM PUK required
	CME_NO_SIM         = 10,                                //SIM not inserted
	CME_SIM_PIN_REQUIRED     = 11,                          //SIM PIN required
	CME_SIM_PUK_REQUIRED     = 12,                          //SIM PUK required
	CME_SIM_FAILURE         = 13,                           //SIM failure
	CME_SIM_BUSY     = 14,                                  //SIM busy
	CME_SIM_WRONG     = 15,                                 //SIM wrong
	CME_INCORRECT_PASSWD     = 16,                          //incorrect password
	CME_SIM_PIN2_REQUIRED     = 17,                         //SIM PIN2 required
	CME_SIM_PUK2_REQUIRED     = 18,                         //SIM PUK2 required
	CME_MEMORY_FULL         = 20,                           //memory full
	CME_INVALID_INDEX         = 21,                         //invalid index
	CME_NOT_FOUND     = 22,                                 //not found
	CME_MEMORY_FAILURE         = 23,                        //memory failure
	CME_TEXT_STRING_TOO_LONG         = 24,                  //text string too long
	CME_INVALID_CHAR_IN_STRING         = 25,                //invalid characters in text string
	CME_DAIL_STRING_TOO_LONG         = 26,                  //dial string too long
	CME_INVALID_CHAR_IN_DIAL_STRING         = 27,           //invalid characters in dial string
	CME_NO_NW_SERVICE         = 30,                         //no network service
	CME_NW_TIMEOUT     = 31,                                //network timeout
	CME_NW_NOT_ALLOWED         = 32,                        //network not allowed - emergency calls only
	CME_NW_PIN_REQUIRED     = 40,                           //network personalization PIN required
	CME_NW_PUK_REQUIRED     = 41,                           //network personalization PUK required
	CME_NW_SUB_PIN_REQUIRED         = 42,                   //network subset personalization PIN required
	CME_NW_SUB_PUK_REQUIRED         = 43,                   //network subset personalization PUK required
	CME_SP_PIN_REQUIRED     = 44,                           //service provider personalization PIN required
	CME_SP_PUK_REQUIRED     = 45,                           //service provider personalization PUK required
	CME_CP_PIN_REQUIRED     = 46,                           //corporate personalization PIN required
	CME_CP_PUK_REQUIRED     = 47,                           //corporate personalization PUK required
	CME_HD_KEY_REQUIRED     = 48,                           //hidden key required
	CME_INVALID_PARAM               = 50,                   //Invalid Param
	CME_FDN_FAILURE	= 51,               			//FDN check failure
#ifdef YS_GNSS_SUPPORT
	CME_YS_CCID_ERROR = 53 ,
#endif
	CME_UNKNOWN     = 100,                                  //unknown
	CME_ILLEGAL_MS     = 103,                               //Illegal MS (#3)
	CME_ILLEGAL_ME     = 106,                               //Illegal ME (#6)
	CME_GPRS_NOT_ALLOWED     = 107,                         //GPRS services not allowed (#7)
	CME_PLMN_NOT_ALLOWED     = 111,                         //PLMN not allowed (#11)
	CME_LA_NOT_ALLOWED         = 112,                       //Location area not allowed (#12)
	CME_ROAMING_NOT_ALLOWED         = 113,                  //Roaming not allowed in this location area (#13)
	CME_SERVICE_OP_NOT_SUPPORTED     = 132,                 //service option not supported (#32)
	CME_SERVICE_OP_NOT_SUBSCRIBED     = 133,                //requested service option not subscribed (#33)
	CME_SERVICE_OP_OUT_OF_ORDER     = 134,                  //service option temporarily out of order (#34)
	CME_PDP_AUTH_FAILURE     = 149,                         //PDP authentication failure
	CME_INVALID_MOBILE_CLASS         = 150,                 //invalid mobile class
	CME_UNSPECIFIED_GPRS_ERR        = 148,                  //unspecified GPRS error
	CME_COMMMAND_TIMEOUT_ERR        = 151,                 //AT command timeout
	CME_IMS_SRV_FAILURE		= 170,							//IMSSRV failure
	CME_IMS_SRV_CAUSE_TERMINATE  = 171,
	CME_IMS_SRV_CAUSE_REDIAL = 172,
	CME_IMS_SRV_CAUSE_WAIT_FOR_RESUMECNF = 173,
	CMS_ME_FAILURE = 300,                                   //ME failure
	CMS_SMS_SERVICE_RESV = 301,                             //SMS service of ME reserved
	CMS_OPERATION_NOT_ALLOWED = 302,                        //operation not allowed
	CMS_OPERATION_NOT_SUPPORTED = 303,                      //operation not supported
	CMS_INVALID_PDU_MODE_PARA = 304,                        //invalid PDU mode parameter
	CMS_INVALID_TEXT_MODE_PARA = 305,                       //invalid text mode parameter
	CMS_NO_SIM = 310,                                       //(U)SIM not inserted
	CMS_SIM_PIN_REQUIRED = 311,                             //(U)SIM PIN required
	CMS_PH_SIM_PIN_REQUIRED = 312,                          //PH-(U)SIM PIN required
	CMS_SIM_FAILURE = 313,                                  //(U)SIM failure
	CMS_SIM_BUSY = 314,                                     //(U)SIM busy
	CMS_SIM_WRONG = 315,                                    //(U)SIM wrong
	CMS_SIM_PUK_REQUIRED = 316,                             //(U)SIM PUK required
	CMS_SIM_PIN2_REQUIRED = 317,                            //(U)SIM PIN2 required
	CMS_SIM_PUK2_REQUIRED = 318,                            //(U)SIM PUK2 required
	CMS_MEMORY_FAILURE = 320,                               //memory failure
	CMS_INVALID_MEMORY_INDEX = 321,                         //invalid memory index
	CMS_MEMORY_FULL = 322,                                  //memory full
	CMS_SMSC_ADDR_UNKNOWN = 330,                            //SMSC address unknown
	CMS_NO_NW_SERVICE = 331,                                //no network service
	CMS_NW_TIMEOUT = 332,                                   //network timeout
	CMS_NO_CNMA_ACK_EXPECTED = 340,                         //no +CNMA acknowledgement expected

	CME_FILE_INVALID_INPUT_VALUE =                        400,  //no +CNMA acknowledgement expected")
    CME_FILE_LARGER_THAN_FILESIZE =                       401,  //large than file size")
    CME_FILE_READ_ZERO =                                  402,  //read zero byte")
    CME_FILE_DRIVE_FULL =                                 403,  //drive full")
    CME_FILE_MOV_ERROR =                                  404,  //move error")
    CME_FILE_FILE_NOT_FOUND =                             405,  //file not found")
    CME_FILE_INVALID_FILE_NAME =                          406,  //invalidate file name")
    CME_FILE_FILE_ALREADY_EXISTED =                       407,  //file already exist")
    CME_FILE_FAILED_TO_CREATE_FILE =                      408,  //failed to create file")
    CME_FILE_FAILED_TO_WRITE_FILE =                       409,  //failed to write file")
    CME_FILE_FAILED_TO_OPEN_FILE =                        410,  //failed to open file")
    CME_FILE_FAILED_TO_READ_FILE =                        411,  //failed to read file")
    CME_FILE_EXCEED_MAX_LENGTH =                          412,  //exceed max length")
    CME_FILE_REACH_MAX_OPENFILE_NUM =                     413,  //reach max opened file num")
    CME_FILE_IS_READONLY =                                414,  //file is the read-only")
    CME_FILE_GET_SIZE_FAIL =                              415,  //get file size failed")
    CME_FILE_INVALID_FILE_DESCRIPTOR =                    416,  //description invalidate")
    CME_FILE_LIST_FILE_FAIL =                             417,  //failed to list file")
    CME_FILE_DELETE_FILE_FAIL =                           418,  //failed to delete file")
    CME_FILE_GET_DISK_INFO_FAIL =                         419,  //failed to get disk info")
    CME_FILE_NO_SPACE =                                   420,  //disk no space")
    CME_FILE_TIME_OUT =                                   421,  //time out")
    CME_FILE_FILE_NOT_FOUND_2 =                           422,  //file not found")
    CME_FILE_FILE_TOO_LARGE =                             423,  //file too large")
    CME_FILE_FILE_ALREADY_EXIST =                         424,  //file already exist")
    CME_FILE_INVALID_PARAMETER =                          425,  //invalidate parameter")
    CME_FILE_ALREADY_OPERATION =                          426,  //file already open")
    CME_FILE_ERROR_GENERAL =                              427,  //file general error")
    CMS_UNKNOWN_ERROR =500,	//unknown error
    CME_WIFI_RETURN_ERROR=                                501,    //"WIFI labtool return error")
	CME_BT_RETURN_ERROR=                                  502,    //"BT labtool return error")
	CME_FM_RETURN_ERROR=                                  503,    //"FM labtool return error")
	CME_FILE_EXIST_ERROR=                                 504,     //"MRD file already exist")
	CME_FILE_WITH_SAME_VERSION_EXIST_ERROR=               505,     //"MRD file with same version already exist")
	CME_FILE_WITH_NEWER_VERSION_EXIST_ERROR=              506,     //"MRD file with newer version already exist")
	CME_AUTHORIZATION_FAILURE=                            507,     //"MRD authorization failure")
	CME_SIM_PUK_BLOCKED=                                  508,     //"(U)SIM PUK blocked")
	CME_VENDOR_NOT_SUPPORTED_ERROR=                       509,     //"Vendor not supported")
	CME_NVM_PATH_NOT_EXIST_ERROR=                         510,     //"NVM path not exist")
	CME_NVM_FILE_COMCFG_ERROR=                            511,     //"NVM file comcfg error")
	CME_PROTOCOL_STACK_BUSY=                              535,     //"PROTOCOL stack busy")
	CME_SIM_BTSAP_CARD_NOT_ACC=                           600,     //"BTSAP card not accessible")
	CME_SIM_BTSAP_CARD_POWERED_OFF=                       601,     //"BTSAP card powered off")
	CME_SIM_BTSAP_CARD_REMOVED=                           602,     //"BTSAP card removed")
	CME_SIM_BTSAP_CARD_POWERED_ON=                        603,     //"BTSAP card powered on")
	CME_SIM_BTSAP_DATA_NOT_AVAILABLE=                     604,     //"BTSAP data not available")
	CME_SIM_BTSAP_NOT_SUPPORTED=                          605,     //"BTSAP not supported")
	CME_NON_PRODUCTION_MODE=                              606,     //"Non-Production mode")
	CME_HTTP_UNKNOWN_ERR=			                      701,     //"HTTP(S) unknown error")
	CME_HTTP_TIMEOUT=				                      702,     //"HTTP(S) timeout")
	CME_HTTP_BUSY=				                          703,     //"HTTP(S) busy")
	CME_HTTP_UART_BUSY=			                          704,     //"HTTP(S) UART busy")
	CME_HTTP_NO_REQ_MTD=			                      705,     //"HTTP(S) no GET/POST requests")
	CME_HTTP_NW_BUSY=				                      706,     //"HTTP(S) network busy")
	CME_HTTP_NW_OPEN_FAIL=		                          707,     //"HTTP(S) network open failed")
	CME_HTTP_NW_NO_CFG=			                          708,     //"HTTP(S) network no configuration")
	CME_HTTP_NW_DEACT=			                          709,     //"HTTP(S) network deactivated")
	CME_HTTP_NW_ERR=		           		              710,     //"HTTP(S) network error")
	CME_HTTP_URL_ERR=		           		              711,     //"HTTP(S) URL error")
	CME_HTTP_EMPTY_URL=		           	                  712,     //"HTTP(S) empty URL")
	CME_HTTP_IP_ADDR_ERR=			                      713,     //"HTTP(S) IP address error")
	CME_HTTP_DNS_ERR=				                      714,     //"HTTP(S) DNS error")
	CME_HTTP_SOCK_CREATE_ERR=		                      715,     //"HTTP(S) socket create error")
	CME_HTTP_SOCK_CONN_ERR=		                          716,     //"HTTP(S) socket connect error")
	CME_HTTP_SOCK_READ_ERR=		                          717,     //"HTTP(S) socket read error")
	CME_HTTP_SOCK_WRITE_ERR=		                      718,     //"HTTP(S) socket write error")
	CME_HTTP_SOCK_CLOSE_ERR=		                      719,     //"HTTP(S) socket closed")
	CME_HTTP_DATA_ENCODE_ERR=		                      720,     //"HTTP(S) data encode error")
	CME_HTTP_DATA_DECODE_ERR=		                      721,     //"HTTP(S) data decode error")
	CME_HTTP_READ_TIMEOUT=		                          722,     //"HTTP(S) read timeout")
	CME_HTTP_RSP_FAIL=			                          723,     //"HTTP(S) response failed")
	CME_HTTP_INCOM_CALL_BUSY=		                      724,     //"Incoming call busy")
	CME_HTTP_VOICE_CALL_BUSY=		                      725,     //"Voice call busy")
	CME_HTTP_INPUT_TIMEOUT=		                          726,     //"Input timeout")
	CME_HTTP_WAIT_DATA_TIMEOUT=	                          727,     //"Wait data timeout")
	CME_HTTP_RSP_TIMEOUT=			                      728,     //"Wait HTTP(S) response timeout")
	CME_HTTP_MALLOC_FAIL=			                      729,     //"Memory allocation failed")
	CME_HTTP_INVALID_PARAM=		                          730,     //"Invalid parameter")
	CME_AUDIO_UNKNOWN_ERROR=	                          901,     //"AUDIO unknown error")
	CME_AUDIO_INVALID_PARAM=	                          902,     //"AUDIO Invalid parameter")
	CME_AUDIO_OPER_NOT_SUPPORTED=                         903,     //"AUDIO not supported")
	CME_AUDIO_DEVICE_BUSY=	                              904,     //"AUDIO device busy")
    
    
	CME_UNKNOWN_SUBSCRIBER=        CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_UNKNOWN_SUBSCRIBER,//      "unknown subscriber")
	CME_ILLEGAL_SUBSCRIBER=        CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_ILLEGAL_SUBSCRIBER,//      "illegal subscriber")
	CME_BRERSERV_NOT_PROV=         CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_BRERSERV_NOT_PROV,//       "brerserv not provider")
	CME_TELESERV_NOT_PROV=         CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_TELESERV_NOT_PROV,//       "tepeserv not provider")
	CME_ILLEGAL_EQUIPMENT=         CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_ILLEGAL_EQUIPMENT,//       "iligal equipment")
	CME_CALL_BARRED=               CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_CALL_BARRED,//             "call barred")
	CME_ILLEGAL_OPERATION=         CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_ILLEGAL_OPERATION,//       "ilegal operation")
	CME_ERROR_STATUS=              CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_ERROR_STATUS,//            "error status")
	CME_NOT_AVAILABLE=             CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_NOT_AVAILABLE,//           "not available")
	CME_SUBS_VIOLATION=            CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_SUBS_VIOLATION,//          "subscription violation")
	CME_INCOMPATIBILITY=           CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_INCOMPATIBILITY,//         "incompatibility")
	CME_FACILITY_NOT_SUPPORTED=    CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_FACILITY_NOT_SUPPORTED,//  "facility not supported")
	CME_ABSENT_SUBSCRIBER=         CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_ABSENT_SUBSCRIBER,//       "absent subscriber")
	CME_SYSTEM_FAILURE=            CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_SYSTEM_FAILURE,//          "system failure")
	CME_DATA_MISSING=              CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_DATA_MISSING,//            "data missing")
	CME_UNEXPECTED_DATA_VALUE=     CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_UNEXPECTED_DATA_VALUE,//   "unexpected data value")
	CME_PWD_REGISTRATION_FAILURE=  CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_PWD_REGISTRATION_FAILURE,//"power registration failure")
	CME_NEGATIVE_PWD_CHECK=        CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_NEGATIVE_PWD_CHECK,//      "negative power check")
	CME_NUMOF_PWD_ATTEMPT_VIOL=    CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_NUMOF_PWD_ATTEMPT_VIOL,//  "numof pwd attempt violation")
	CME_POSITION_METHOD_FAILURE=   CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_POSITION_METHOD_FAILURE,// "position method failure")
	CME_UNKNOWN_ALPHABET=          CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_UNKNOWN_ALPHABET,//        "unknown alphabet")
	CME_USSD_BUSY=                 CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_USSD_BUSY,//               "ussd busy")
	CME_MAXMPTY_CALLS_EXCEEDED=    CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_MAXMPTY_CALLS_EXCEEDED,//  "maxmpty calls exceeded")
	CME_RESOURCES_NOT_AVAILABLE=   CMEE_ERROR_CODE_CISS_BASE_MARVELL_PROPRIETARY + CiSS_RESOURCES_NOT_AVAILABLE,// "resources not available")

   	//yang.liu add gnss return errcode
   	#ifdef QUEC_AT_GPS_ENABLE
	DSAT_CME_GNSS_INVALID_PARA     = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_INVALID_PARA,  /*Invalid parameter*/
    DSAT_CME_GNSS_OPER_NOT_SUPPORT = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_OPER_NOT_SUPPORT,  /*Operation not supported*/
    DSAT_CME_GNSS_GNSS_SUB_BUSY    = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_GNSS_SUB_BUSY,  /*GNSS subsystem busy.*/
    DSAT_CME_GNSS_SE_IS_ONGOING    = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_SE_IS_ONGOING,   /*Session is ongoing*/
    DSAT_CME_GNSS_SE_NOT_ACT       = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_SE_NOT_ACT,  /*Session not activity*/
    DSAT_CME_GNSS_OPER_TIME_OUT    = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_OPER_TIME_OUT,  /*Operation timeout*/
    DSAT_CME_GNSS_FUNC_NOT_EN      = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_FUNC_NOT_EN,  /* Function not enable */
    DSAT_CME_GNSS_TIME_INFO_ERR    = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_TIME_INFO_ERR,  /*Time info error*/
    DSAT_CME_GNSS_XTRA_NOT_ENABLE  = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_XTRA_NOT_ENABLE,  /*   XTRA not enable*/
    DSAT_CME_GNSS_XTRA_FILE_OPEN_ERR = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_XTRA_FILE_OPEN_ERR,/*XTRA file open failed.*/
    DSAT_CME_GNSS_XTRA_BAD_CRC     = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_XTRA_BAD_CRC,  /*Bad CRC for XTRA data file*/
    DSAT_CME_GNSS_XTRA_TIME_OUT_RANGE = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_XTRA_TIME_OUT_RANGE,/*Validity time is out of range*/
    DSAT_CME_GNSS_XTRA_INT_RES_ERR = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_XTRA_INT_RES_ERR,   /*Internal resource error*/
    DSAT_CME_GNSS_GPS_LOCKED       = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_GPS_LOCKED,   /*GNSS locked*/
    DSAT_CME_GNSS_END_E911         = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_END_E911,  /*End by E911*/
    DSAT_CME_GNSS_NOT_FIXED_NOW    = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_NOT_FIXED_NOW,  /*Not fixed now*/
    DSAT_CME_GNSS_CMUX_NOT_OPEN    = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_CMUX_NOT_OPEN,  /*CMUX port not open*/
    DSAT_CME_GNSS_UNKNOWN_ERR      = CME_ERROR_CODE_QUECCTEL_GNSS_PROPRIETARY 	+ QUEC_CME_GNSS_UNKNOWN_ERR,/*  Unknown*/
    #endif	
}_AtciCmeError;
typedef UINT16 AtciCmeError;

#ifdef LWIP_IPNETBUF_SUPPORT
typedef enum ATCI_SYSINFO_SYSTEM_SUBMODE
{
	ATCI_SYSINFO_SYSTEMO_SUBMODE_NO_SERVICE = 0,
	ATCI_SYSINFO_SYSTEMO_SUBMODE_GSM = 1,
	ATCI_SYSINFO_SYSTEMO_SUBMODE_GSM_EGPRS = 3,
	ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN_HSDPA = 5,
	ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN_HSUPA = 6,
	ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN_HSPA = 7,
	ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN = 8,
	ATCI_SYSINFO_SYSTEMO_SUBMODE_EUTRAN = 17,
}_AtciSysinfoSystemSubMode;
#endif

typedef enum ATCI_RESULT_CODE
{
	ATCI_RESULT_CODE_NULL, //Timer will not stop
	ATCI_RESULT_CODE_OK,   //Timer will stop, OK will be sent
	ATCI_RESULT_CODE_ERROR, //Timer will stop, ERROR will be sent
	ATCI_RESULT_CODE_CME_ERROR, //Timer will Stop, CME ERROR will be sent
	ATCI_RESULT_CODE_CMS_ERROR, //Timer will Stop, CMS ERROR will be sent
	ATCI_RESULT_CODE_SUPPRESS,       //Timer will Stop, End of AT response without OK or ERROR string
#ifdef LWIP_IPNETBUF_SUPPORT
	ATCI_RESULT_CODE_CME_ERROR_PROXY,
	ATCI_RESULT_CODE_CMS_ERROR_PROXY,
	ATCI_RESULT_CODE_CMUX_ERROR,
    ATCI_RESULT_CODE_M2M_ERROR,
	ATCI_RESULT_CODE_MAX
#endif
}_AtciResultCode;

typedef UINT8 AtciResultCode;

/*  AT*CSG */
typedef enum ATCI_CSG_MODE
{
  ATCI_CSG_MODE_AUTO = 0,
  ATCI_CSG_MODE_MANUAL,
  ATCI_CSG_MODE_REGISTER,
  ATCI_CSG_MODE_CANCELL,
  ATCI_NUM_CSG_MODE
} _AtciCsgMode;
typedef UINT8 AtciCsgMode;
/* telephony controller struct */
typedef struct telCurCallIdReqhandle_struct
{
    CiCcCallId           CallId;            /* Unique Call Identifier               */
	CiRequestHandle		 reqHandle;			/* CiRequestHanlde that the call is originated from */	
}telCurCallIdReqhandle_t;

typedef enum {
   MODEM_DATA_MODE,
   MODEM_CONTROL_MODE
} MODEM_STATE;

enum 
{
  ATCI_CRTDCP_IND_DISABLE=0,  /* off, default */
  ATCI_CRTDCP_IND_ENABLE
};
void atciSvgFreeCnfMem ( CiServiceGroupID svgId, CiPrimitiveID primId, void* paras );

void atciSvgFreeIndMem ( CiServiceGroupID svgId, CiPrimitiveID primId, void* paras );

void ciRegisterClientApp(CiServiceGroupID  dummy); 
int handle_CMEE_code(UINT32 reqHandle, UINT16 errCode);
int handle_CMSE_code(UINT32 reqHandle, UINT16 errCode);
CiReturnCode MM_SetCellLOCK(UINT32 atHandle, UINT8 mode, UINT8 act, UINT8 band, INT32 freq, INT16 cellId);
int atRespStr_NW_REG(UINT32 reqHandle, int IMS_Flag, char *respString);



#endif /*AT_CICONV_H*/

