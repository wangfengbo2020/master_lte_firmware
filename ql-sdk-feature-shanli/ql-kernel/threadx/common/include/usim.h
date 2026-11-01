/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*******************************************************************************
*               MODULE HEADER FILE
********************************************************************************
* Title: USIM header file
*
*  This file and the software in it is furnished under
*  license and may only be used or copied in accordance with the terms of the
*  license. The information in this file is furnished for informational use
*  only, is subject to change without notice, and should not be construed as
*  a commitment by Intel Corporation. Intel Corporation assumes no
*  responsibility or liability for any errors or inaccuracies that may appear
*  in this document or any software that may be provided in association with
*  this document.
*  Except as permitted by such license, no part of this document may be
*  reproduced, stored in a retrieval system, or transmitted in any form or by
*  any means without the express written consent of Intel Corporation.
*
* Title: USIM header file
*
* Filename: usim.h
*
* Target, platform: Common Platform, HAL platform
*
* Authors: Eilam Ben-Dror
*
* Description: This file is the USIM Driver header file.
*
* Last Updated:
*
* Notes:
*******************************************************************************/

#ifndef _USIM_H_
#define _USIM_H_

#include "global_types.h"
#include "usim_config.h"


/*----------- Global defines -------------------------------------------------*/

//
#define USIM_ALL_AVAILABLE_DATA 256   // 256 Bytes is the max length

/*----------- Global macro definitions ---------------------------------------*/
// Bitwise not for a byte:
#define USIM_BYTEWISE_NOT(b) (0xFF-(b))

//#define USIM_OP_FOR_SGIT	1

/*----------- Global type definitions ----------------------------------------*/
// Return Code definitions:
typedef enum
{
  USIM_RC_OK = 1,

  USIM_RC_INVALID_CARD          = -100,
  USIM_RC_GPIO_ERROR            = -99,
  USIM_RC_INTC_ERROR            = -98,
  USIM_RC_OSA_ERROR             = -97,
  USIM_RC_NULL_POINTER          = -96,
  USIM_RC_CARD_REMOVED          = -95,
  USIM_RC_CARD_CLOSED           = -94,
  USIM_RC_NOT_REGISTERED        = -93,
  USIM_RC_CARD_ALREADY_OPEN     = -92,
  USIM_RC_ATR_ERROR             = -91,
  USIM_RC_ATR_CHECK_FAILED      = -90,
  USIM_RC_PPS_ERROR             = -89,
  USIM_RC_ALREADY_BOUND         = -88,
  USIM_RC_SEND_ERROR            = -87,
  USIM_RC_RECEIVE_ERROR         = -86,
  USIM_RC_CARD_BUSY             = -85,
  USIM_RC_INVALID_DATA_LENGTH   = -84,
  USIM_RC_DMA_ERROR             = -83

}USIM_ReturnCode;


// Command header:
//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8 instructionClass;	//	Class of instruction
	UINT8 instructionCode;	//	Instruction code
	UINT8 param1;			//	Instruction parameter 1
	UINT8 param2;			//	Instruction parameter 2
    UINT16 dataLength;      //  Number of bytes in the command data (0 - 255)
    UINT16 expectDataLength;//  Max number of data bytes expected in response (0 - 255).

}USIM_CommandHeader;


// Response Header:
//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8 status1;			//	Status byte 1
	UINT8 status2;			//	Status byte 2
}USIM_ResponseHeader;


// Coding Convention
typedef enum
{
	USIM_DIRECT = 0x3B,
	USIM_INVERSE = 0x3F
}USIM_Coding;

// Transport Layer Protocol
//ICAT EXPORTED ENUM
typedef enum
{
	USIM_T0 = 0x00,
	USIM_T1 = 0x01
}USIM_Protocol;


// Card clock frequencies.
// Note: In order to avoid float type, the values are 10 times bigger than the
// used frequency.
typedef enum
{
	USIM_2_4_MHz = 24,		// used frequency
	USIM_3_MHz	 = 30,		// used frequency
	USIM_3_4_MHz = 34,		// used frequency
	USIM_4_MHz	 = 40,		// used frequency and indicated maximal frequency
	USIM_4_8_MHz = 48,		// used frequency
	USIM_5_MHz	 = 50,		// indicated maximal frequency
	USIM_6_MHz	 = 60,		// used frequency and indicated maximal frequency
	USIM_7_5_MHz = 75,		// indicated maximal frequency
	USIM_8_MHz	 = 80,		// used frequency and indicated maximal frequency
	USIM_10_MHz	 = 100,		// indicated maximal frequency
	USIM_12_MHz	 = 120,		// used frequency and indicated maximal frequency
	USIM_15_MHz	 = 150,		// indicated maximal frequency
	USIM_16_MHz	 = 160,		// indicated maximal frequency
	USIM_20_MHz	 = 200		// indicated maximal frequency
}USIM_Frequency;



// Clock Stop States:
//ICAT EXPORTED ENUM
typedef enum
{
	USIM_CLK_STOP_NOT_SUPPORTED = 0,	//	clock stop not supported
	USIM_CLK_STOP_LOW,					//	preferred state for clock stop is low
	USIM_CLK_STOP_HIGH,					//	preferred state for clock stop is high
	USIM_CLK_STOP_ANY					//	no preference for stop state

}USIM_ClockState;



// Class of operating conditions:
//ICAT EXPORTED ENUM
typedef enum
{
    USIM_CLASS_NULL = 0 ,
    USIM_CLASS_A = 1,       //  class A supported, 5V
	USIM_CLASS_B = 2,		//	class B supported, 3V
    USIM_CLASS_C = 4        //  class C supported, 1.8V
}USIM_Class;


// Error detection code:
typedef enum
{
	USIM_LRC = 0,
	USIM_CRC = 1
}USIM_ErrorCode;



typedef enum
{
	USIM_CPU_MODE = 0,
	USIM_DMA_MODE = 1
}USIM_MODE;


// ATR Information:
typedef struct
{
	USIM_Frequency cardClock;	//  the used card's clock frequency * 10,in MHz
	USIM_Frequency indCardClock;//	max card clk frequency, as indicated in ATR
	UINT16 conversionFactor;	//	clock rate conversion factor, F.
	UINT16 indConversionFactor;	//	factor value indicated by the card, Fi.
	UINT8 adjustmentFactor;		//	baud rate adjustment factor, D = {1,2,4,8,12,16,20,32}
	UINT8 indAdjustmentFactor;	//	factor value indicated by the card, Di.
	UINT8 extraGuardTime;		//	Extra guardtime parameter N = [0 - 255]
	BOOL modeChangeable;		//	0 - card can't change mode, 1 - card can change mode
	USIM_Protocol protocol;		//	protocol to be used in specific mode
	USIM_ClockState stopState;	//	clock stop state
	USIM_Class cardClasses;		//	classes of operating conditions accepted by the card
	USIM_Coding convention;		//	coding convention
	UINT8 historicBytesNumber;	//	number of historical bytes (0 - 15)
	UINT8 historicBytes [15];	//	the historical bytes
	UINT8 length;				//	the length of the ATR (in bytes)
	// Information regarding only T=0 protocol:
	UINT32 workWaitingTime;		//	work waiting time
	// Information regarding only T=1 protocol:
	UINT16 charWaitingTime;		//	character waiting time
	UINT32 blockWaitingTime;	//	block waiting time
	UINT8 infoFieldSize;		//	num of info bytes that the card can receive in a block
	USIM_ErrorCode errorCode;	//	error detection code : LRC or CRC
    UINT32      wdtTime;        //  time in uSec of maximum of timeout
}USIM_ATRInfo;



// Configuration structure definition:

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT8			clockRateFactorRef;	//	reference to a clock rate conversion factor, FI = {0,1,2,3,4,5,6, 9,10,11,12,13}
	UINT8			baudRateFactorRef;	//	reference to a baud rate adjustment factor, DI = {1,2,3,4,5,6, 8,9}
	UINT8			extraGuardTime;		//	Extra guardtime parameter N = [0 - 255]
	USIM_Protocol	protocol;			//	protocol to be used in specific mode
	USIM_ClockState stopState;			//	clock stop state

	// Information regarding only T=0 protocol:
	UINT32			workWaitingTime;	//	work waiting time

	// Information regarding only T=1 protocol:
	UINT16			charWaitingTime;	//	character waiting time
	UINT32			blockWaitingTime;	//	block waiting time
	UINT8			infoFieldSize;		//	num of info bytes that the card can receive in a block

}USIM_Configuration;




// Card Control Status:
//ICAT EXPORTED ENUM
typedef enum
{
	USIM_CARD_REMOVED = 0,
    USIM_CARD_INSERTED,
	USIM_CARD_ACTIVATED,
	USIM_CARD_DEACTIVATED,

	// additional definitions for indicating voltage class:
	USIM_CARD_ACTIVE_CLASS_A,	// 5V
	USIM_CARD_ACTIVE_CLASS_B,	// 3V
	USIM_CARD_ACTIVE_CLASS_C	// 1.8V

}USIM_ControlStatus;


// Card Status:
typedef struct
{
USIM_ControlStatus controlStatus;
BOOL activeReceiver;
BOOL activeTransmitter;
}USIM_Status;


// call back function for sending a response from the USIM Driver to the Manager:
typedef void (*USIM_CardResponseNotify)(USIM_ResponseHeader * header,
                                        UINT16 dataLength, UINT8 * data);


// call back function for notifying the Manager that the card's status has changed:
typedef void (*USIM_ControlIndication)(USIM_ControlStatus status);

/*----------- Extern definition ----------------------------------------------*/

/*----------- Global variable declarations -----------------------------------*/

/*----------- Global constant definitions ------------------------------------*/

/*----------- Global function prototypes -------------------------------------*/
USIM_ReturnCode USIMCommandSend
				(USIM_Card card, USIM_CommandHeader * header, UINT8 * data);

USIM_ReturnCode USIMATRGet (USIM_Card card, USIM_ATRInfo *  info);

USIM_ReturnCode USIMPhase1Init(void);

USIM_ReturnCode USIMPhase2Init(void);

SwVersion USIMVersionGet (void);

USIM_ReturnCode USIMOpen       (USIM_Card card);
USIM_ReturnCode USIMClose      (USIM_Card card);

USIM_ReturnCode USIMRegister (USIM_Card card,
							  USIM_CardResponseNotify responseFunc,
							  USIM_ControlIndication ctrlFunc);

USIM_ReturnCode USIMUnRegister (USIM_Card card);

USIM_ReturnCode USIMStatusGet (USIM_Card card, USIM_Status *status);

USIM_ReturnCode USIMClockStop	(USIM_Card card);

void USIMRxTxModeSet ( USIM_Card 	 card , USIM_MODE    mode );
USIM_MODE USIMRxTxModeGet ( USIM_Card 	 card );

void                USIMRemove(USIM_Card card);
USIM_ReturnCode USIM_HwContReset(USIM_Card card);  
#ifdef USIM_NO_ATR_PPS_DECODING

USIM_ReturnCode USIMConfigure	(USIM_Card card, USIM_Configuration *  config);

USIM_ReturnCode USIMReset		(USIM_Card card, USIM_Class voltageClass);

USIM_ReturnCode USIMPPSSend		(USIM_Card card, UINT8 length, UINT8 * data);

#endif /* USIM_NO_ATR_PPS_DECODING */
void USIM_DetectFoundByHW(BOOL inserted);

#ifndef _TAVOR_BOERNE_
//typedef UINT32 FmCallFuncType(Bool powerUpSim, Bool powerUpProtoStack);
//void USIMFlightModeReqBind(FmCallFuncType Func);
#endif
#endif  /* _USIM_H_ */
