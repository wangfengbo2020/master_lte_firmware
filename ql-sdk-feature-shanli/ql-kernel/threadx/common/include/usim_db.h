/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*******************************************************************************
*               MODULE HEADER FILE
********************************************************************************
*  COPYRIGHT (C) 2005 Intel Corporation, All rights reserved..
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
* Title: USIM Batabase header file
*
* Filename: usim_db.h
*
* Author: Eilam Ben-Dror
*
* Description: This file contains the USIM Driver's database.
*
* Last Updated: 14-Dec-2005
*
*******************************************************************************/

#ifndef _USIM_DATABASE_H_
#define _USIM_DATABASE_H_


#include "osa.h"

#include "global_types.h"

#include "usim.h"
#include "usim_config.h"
#ifndef SILICON_PV2 //_TAVOR_HARBELL_
#include "gpio.h"
#endif
/*----------- Global defines -------------------------------------------------*/
// Baud Rate Table Size:
#define USIM_TABLE_SIZE 16

// Max number of bytes that an ATR message may contain:
#define USIM_ATR_MAX_LEN 33

// The number of bytes in the rx buffer:
#define USIM_BUFFER_SIZE 1024

// The number of bytes in the rx buffer:
#define USIM_TRACE_BUFFER_SIZE 1024

// Min number of bytes that an ATR message may contain:
#define USIM_ATR_MIN_LEN 2

// Number of characters after which the timeout interrupt occurs:
#define USIM_TIMEOUT_CHARS 16

// bytes in the Prologue field of T=1 protocol
#define USIM_T1_PROLOGUE_SIZE 3


// Flags Definitions:
#define USIM_DEACTIVATE_FLAG      0x01L   // Deactivate the card due to an error
#define USIM_DATA_READ_FLAG       0x02L   // All of the card's data was read
#define USIM_DATA_SENT_FLAG       0x04L   // All of the data was sent to the card
#define USIM_COMMAND_FLAG         0x08L   // CommandSend was called
#define USIM_CLOSE_FLAG           0x10L   // USIMClose was called
#define USIM_CLOCK_STOP_FLAG      0x20L   // Timer for clock stop has expired
#define USIM_REACTIVATE_FLAG      0x40L   // Reactivate the card after insertion
#define USIM_CARD_REMOVED_FLAG    0x80L   // Card is being removed.
#define USIM_WDT_TIMER_FLAG      0x100L  // software WDT timer expired

#define USIM_ALL_FLAGS			0xFFFL


// interrupt sources masks:
#define USIM_RX_OVERRUN_MASK        0x01L
#define USIM_PARITY_ERR_MASK        0x02L
#define USIM_T0_ERR_MASK            0x04L
#define USIM_FRAMING_ERR_MASK       0x08L
#define USIM_RX_TIMEOUT_MASK        0x10L
#define USIM_CWT_MASK               0x20L
#define USIM_BWT_MASK               0x40L
#define USIM_RX_DATA_READY_MASK     0x100L
#define USIM_TX_DATA_REFILL_MASK    0x200L
#define USIM_IIR_ALL_BITS_MASK 0x37FL

// Null Procedure Byte:
#define USIM_NULL_BYTE 0x60

/*----------- Global macro definitions ---------------------------------------*/
/* Trace Macro: */



/*----------- Global type definitions ----------------------------------------*/


// USIM interrupt sources:
//ICAT EXPORTED ENUM
typedef enum
{
	USIM_RX_OVERRUN = 0,		// Receiver data overrun
	USIM_PARITY_ERR,			// Parity error
	USIM_T0_ERR,				// T=0 error
	USIM_FRAMING_ERR,			// Framing error
	USIM_RX_TIMEOUT,			// Receiver timeout
	USIM_CWT,					// Character Waiting Time
	USIM_BWT,					// Block Waiting Time
	//bit 7 is reserved
	USIM_RX_DATA_READY = 8,	// Receiver Data Ready
	USIM_TX_DATA_REFILL,		// Transmitter data refill
	//bits 10-11 reserved
	USIM_DMA_END_OF_CHAIN = 12,	// DMA end of chain
	USIM_DMA_TIMEOUT,			// DMA receive request in timeout situation
	USIM_DMA_RX,				// DMA receive request
	USIM_DMA_TX,				// DMA transmit request

	USIM_INTERRUPTS_AMOUNT
}USIM_InterruptSource;



// USIM States of operation:
//ICAT EXPORTED ENUM
typedef enum
{
    USIM_REMOVED            = 0x00, // the card is removed
    USIM_INACTIVE           = 0x01, // the card is inactive
    USIM_ATR                = 0x02, // Answer To Reset mode
    USIM_NEGOTIABLE         = 0x03, // Negotiable mode
    USIM_SPECIFIC           = 0x04, // Specific mode

    USIM_IDLE               = 0x10, // waiting for the Manager to send a command.
    USIM_SEND               = 0x20, // sending a command to the card.
    USIM_WAIT_FOR_RESPONSE  = 0x30, // waiting for the card's response
    USIM_RECEIVE            = 0x40, // receiving a response from the card.
    USIM_PROCESS            = 0x50, // processing the received response

    USIM_WDT_TIMER_EXPIRED = 0x100 // Guar Timer Expired (HW Error/card removed)
    
//    USIM_CLOCK_STOP         = 0x10000000  // the card's clock was stopped.
}   USIM_State;

// Baud rate parameters structure:
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8   ratio;	// half of the ratio of the internal clock to the card clock.
	UINT8   factor;	// number of samples per bit - 1.
	UINT16  divisor;	// number of internal clock cycles between samples.
}   USIM_BaudRate;

 // order of bytes in header:
 //ICAT EXPORTED ENUM
typedef enum
{
	USIM_CLA = 0,
	USIM_INS,
	USIM_P1,
	USIM_P2,
	USIM_LEN
}   USIM_HeaderField;



/* For trace: */
typedef enum
{
    USIM_TR_T1_INITIATE = 0x81,		/* 0x81 */
    USIM_TR_SEND_BLOCK,        		/* 0x82 */
    USIM_TR_REQ_PREVIOUS_BLOCK,		/* 0x83 */
    USIM_TR_REQ_NEXT_BLOCK,    		/* 0x84 */
    USIM_TR_RESYNC,            		/* 0x85 */
    USIM_TR_CHECKSUM_ERROR,    		/* 0x86 */
    USIM_TR_I_BLOCK_RECEIVED,  		/* 0x87 */
    USIM_TR_R_BLOCK_RECEIVED,  		/* 0x88 */
    USIM_TR_S_BLOCK_RECEIVED,  		/* 0x89 */
    USIM_TR_T0_ERROR,          		/* 0x8a */
	USIM_TR_BWT,               		/* 0x8b */
	USIM_TR_CWT,               		/* 0x8c */
	USIM_TR_TX_FULL,              	/* 0x8d */
	USIM_TR_IIR,              		/* 0x8e */
	USIM_TR_PERR,              		/* 0x8f */
	USIM_TR_PERR_FIFO,        		/* 0x90 */
	USIM_TR_SPEC_DEBUG,        		/* 0x91 */
	
    USIM_TR_WRITE_START =           0xAA,
    USIM_TR_FINISHED_SENDING =      0xBB,
    USIM_TR_READ_END =              0xCC,
    USIM_TR_DEACTIVATE =            0xDD,
	USIM_TR_ESC =                   0xEE,
	USIM_TR_ESC_END =               0xEF,
	
	USIM_TR_GUARD_TIMER_EXPIRED     = 0x40,
    USIM_TR_REMOVED =               0x41,
}USIM_Trace;


/* For trace: */
typedef enum
{
	USIM_EVT_USIM_DL_writeRead_001=0x00,
		
	USIM_EVT_USIMhandler_001=0x01,
	USIM_EVT_USIMhandler_002=0x02,
	USIM_EVT_USIMhandler_003=0x03,

	USIM_EVT_USIMsisrComCard_001=0x04,
	USIM_EVT_USIMsisrComCard_002=0x05,
	USIM_EVT_USIMsisrComCard_003=0x06,

	
	USIM_EVT_READ_USIMreadHandler_001=0x07,
	USIM_EVT_READ_USIMreadHandler_002=0x08,
	USIM_EVT_READ_USIMreadHandler_003=0x09,
	USIM_EVT_READ_USIMreadHandler_004=0x0A,
	USIM_EVT_READ_USIMreadHandler_005=0x0B,
	USIM_EVT_READ_USIMreadHandler_006=0x0C,
	USIM_EVT_READ_USIMreadHandler_007=0x0D,
	USIM_EVT_READ_USIMreadHandler_008=0x0E,
	USIM_EVT_READ_USIMreadHandler_009=0x0F,
	USIM_EVT_READ_USIMreadHandler_010=0x10,
	USIM_EVT_READ_USIMreadHandler_011=0x11,
	USIM_EVT_READ_USIMreadHandler_012=0x12,
	USIM_EVT_READ_USIMreadHandler_013=0x13,
	USIM_EVT_READ_USIMreadHandler_014=0x14,
	USIM_EVT_READ_USIMreadHandler_015=0x15,
	USIM_EVT_READ_USIMreadHandler_016=0x16,
	USIM_EVT_READ_USIMreadHandler_017=0x17,
	USIM_EVT_READ_USIMreadHandler_018=0x18,
	USIM_EVT_READ_USIMreadHandler_019=0x19,
	USIM_EVT_READ_USIMreadHandler_020=0x20,
	USIM_EVT_READ_USIMreadHandler_021=0x21,
	USIM_EVT_READ_USIMreadHandler_022=0x22,
	USIM_EVT_READ_USIMreadHandler_023=0x23,

	
	USIM_EVT_USIMwriteHandler_001=0x24,
	USIM_EVT_USIMwriteHandler_002=0x25,
	USIM_EVT_USIMwriteHandler_003=0x26,
	USIM_EVT_USIMwriteHandler_004=0x27,

	
	USIM_EVT_USIM_HW_TXWrite_001=0x28,
	USIM_EVT_USIM_HW_RXRead_001=0x29,

	USIM_EVT_USIM_WDT_TIMER_START=0x2A,
	USIM_EVT_USIM_WDT_TIMER_STOP=0x2B,
	USIM_EVT_USIM_wdtExpired=0x2C,
	



	USIM_EVT_USIMdecodeProcedureByte_001=0x2D,
	USIM_EVT_USIMdecodeProcedureByte_002=0x2E,
	USIM_EVT_USIMdecodeProcedureByte_003=0x2F,
	USIM_EVT_USIMdecodeProcedureByte_004=0x30,

	

}USIM_DBG_EVENT;





#endif /* _USIM_DATABASE_H_ */


/*----------- Extern definition ----------------------------------------------*/
#ifndef _USIM_DB_NO_EXTERN_
  #define EXTERN extern
#else
  #define EXTERN
#endif /* _USIM_DB_NO_EXTERN_ */

/*----------- Global variable declarations -----------------------------------*/

#ifdef USIM_USE_TRACE


#endif /* USIM_USE_TRACE */
//moved to local
//EXTERN UINT32 _USIMClockRequestCounter[USIM_CARDS_AMOUNT];
EXTERN UINT32 _USIMResponseReadFlag[USIM_CARDS_AMOUNT];

EXTERN UINT8 _USIMatrBuffers[USIM_CARDS_AMOUNT][USIM_ATR_MAX_LEN];

// buffers for card messages:
EXTERN UINT8 * _USIMrxBuffers[USIM_CARDS_AMOUNT];
// pointers to these buffers:
EXTERN UINT8 * _USIMrxBufferPtrs[USIM_CARDS_AMOUNT];

// The number of bytes expected to be received from the card:
EXTERN UINT32 _USIMexpectedLen[USIM_CARDS_AMOUNT];


// Card block sequence numbers for T=1:
EXTERN UINT8 _USIMcardSequence[USIM_CARDS_AMOUNT];

// Device block sequence numbers for T=1:
EXTERN UINT8 _USIMdeviceSequence[USIM_CARDS_AMOUNT];

// Chaining indication for T=1:
EXTERN BOOL _USIMisChaining[USIM_CARDS_AMOUNT];

// buffers for sending messages to the card:
EXTERN UINT8 * _USIMtxBuffers[USIM_CARDS_AMOUNT];
// pointers to these buffers:
EXTERN UINT8 * _USIMtxBufferPtrs[USIM_CARDS_AMOUNT];
// number of valid bytes in the buffer:
EXTERN UINT32 _USIMtxBufferSize[USIM_CARDS_AMOUNT];


// command header buffers:
EXTERN USIM_CommandHeader _USIMcommandHeaders[USIM_CARDS_AMOUNT];

// data buffers:
EXTERN UINT8 * _USIMdataBuffers[USIM_CARDS_AMOUNT];
// number of valid bytes in the buffer:
EXTERN UINT32 _USIMdataBufferSize[USIM_CARDS_AMOUNT];

// response header buffers:
EXTERN USIM_ResponseHeader _USIMresponseHeaders[USIM_CARDS_AMOUNT];


// The following structure contains the most recent ATR information
EXTERN USIM_ATRInfo _USIMatrInfos[USIM_CARDS_AMOUNT];

// The current USIM state:
EXTERN USIM_State _USIMstates[USIM_CARDS_AMOUNT];

// The current USIM Data Link state:
EXTERN USIM_State _USIMDLstates[USIM_CARDS_AMOUNT];

// The Delay indicator:
EXTERN BOOL _USIMisDelaySet[USIM_CARDS_AMOUNT];

//Counter used for WWT iterations
EXTERN UINT32 _USIMWTCnt[USIM_CARDS_AMOUNT];

// Counter of Parity Errors during Rx from the SIM
EXTERN UINT32 _USIMParityErrorCnt[USIM_CARDS_AMOUNT];
EXTERN UINT16 _USIMErrorStat[USIM_CARDS_AMOUNT];

// The cards flag groups:
EXTERN OSAFlagRef _USIMflagsRefs[USIM_CARDS_AMOUNT];

#ifdef USIM_DETECT_PIN

// GPIO Port handle for the card detect pin:
EXTERN GPIO_PortHandle _USIMdetectPortHandles[USIM_CARDS_AMOUNT];

#endif /* USIM_DETECT_PIN */

// Card response notify return functions:
EXTERN USIM_CardResponseNotify _USIMresponseNotifies[USIM_CARDS_AMOUNT];

// Control indication return functions:
EXTERN USIM_ControlIndication _USIMcontrolIndications[USIM_CARDS_AMOUNT];

#if defined(USIM_PMC_LDO_ENABLED_ON_BOOT)
// First time powered USIM interface
EXTERN BOOL  _SIMFirstTimePowered[USIM_CARDS_AMOUNT];
#endif

#if defined (USIM_USE_SW_WDT_TIMER)
EXTERN OSATimerRef _USIMtimerRefsWdt[USIM_CARDS_AMOUNT];

EXTERN UINT32      _USIMtimerWDTval[USIM_CARDS_AMOUNT];

EXTERN BOOL        _USIMtimerWDTactive[USIM_CARDS_AMOUNT];
#endif


/*----------- Global constant definitions ------------------------------------*/
#ifdef _USIM_DB_NO_EXTERN_

// This lookup table holds the clock rate conversion factor (Fi), as indicated
// in ATR:
const UINT16 USIM_CONVERSION_FACTOR_TABLE [USIM_TABLE_SIZE] =                  \
{372,372,558,744,1116,1488,1860,0,0,512,768,1024,1536,2048,0,0};

// This lookup table holds the baud rate adjustment factor (Di), as indicated
// in ATR:
const UINT8 USIM_ADJUSTMENT_FACTOR_TABLE [USIM_TABLE_SIZE] =                   \
{0,1,2,4,8,16,32,64,12,20,0,0,0,0,0,0};

// Lookup table for the max card frequency, as indicated in ATR:
// NOTE: all frequencies are multiplied by 10, in order to avoid float type.
// {40,50,60,80,120,160,200,0,0,50,75,100,150,200,0,0}; updated due compiler warning
const USIM_Frequency USIM_MAX_FREQ_TABLE [USIM_TABLE_SIZE] =                   \
{USIM_4_MHz,USIM_5_MHz,USIM_6_MHz,USIM_8_MHz,USIM_12_MHz,USIM_16_MHz,USIM_20_MHz,(USIM_Frequency)0,\
(USIM_Frequency)0,USIM_5_MHz,USIM_7_5_MHz,USIM_10_MHz,USIM_15_MHz,USIM_20_MHz,(USIM_Frequency)0,(USIM_Frequency)0};

// The Baud Rate Table:
const USIM_BaudRate _USIMbaudRateTable [USIM_TABLE_SIZE] [USIM_TABLE_SIZE] =
{
// RFU:
	{
		{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
		{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
	},

#if !defined USIM_MAX_CARD_CLK
	#define USIM_MAX_CARD_CLK USIM_MAX_3_4_MHz
#endif

#if (USIM_MAX_CARD_CLK == USIM_MAX_3_MHz)

// D= 1 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {8,32,186},{8,32,186},{8,32,279},{8,32,372},{8,32,558},{8,32,744},{8,32,930},{0,0,0},
        {0,0,0},{8,32,256},{8,32,384},{8,32,512},{8,32,768},{8,32,1024},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 2 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {8,32,93},{8,32,93},{8,36,124},{8,32,186},{8,32,279},{8,32,372},{8,32,465},{0,0,0},
        {0,0,0},{8,32,128},{8,32,192},{8,32,256},{8,32,384},{8,32,512},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 4 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {8,16,93},{8,16,93},{8,12,186},{8,12,248},{8,12,372},{8,12,496},{8,12,620},{0,0,0},
        {0,0,0},{8,16,128},{8,16,192},{8,16,256},{8,16,384},{8,16,512},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 8 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {8,8,93},{8,8,93},{8,12,93},{8,8,186},{8,8,279},{8,8,372},{8,8,465},{0,0,0},
        {0,0,0},{8,8,128},{8,8,192},{8,8,256},{8,8,384},{8,8,512},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 16 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {8,12,31},{8,12,31},{8,9,62},{8,8,93},{8,12,93},{8,12,124},{8,12,155},{0,0,0},
        {0,0,0},{8,8,64},{8,8,96},{8,8,128},{8,8,192},{8,8,256},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 32 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {8,6,31},{8,6,31},{8,9,31},{8,12,31},{8,9,62},{8,12,62},{8,10,93},{0,0,0},
        {0,0,0},{8,8,32},{8,8,48},{8,8,64},{8,8,96},{8,8,128},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 64 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {8,31,3},{8,31,3},{16,9,31},{8,6,31},{8,9,31},{8,12,31},{8,15,31},{0,0,0},
        {0,0,0},{8,8,16},{8,8,24},{8,8,32},{8,8,48},{8,8,64},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 12 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {8,8,62},{8,8,62},{8,8,93},{8,8,124},{8,8,186},{8,8,248},{8,10,248},{0,0,0},
        {0,0,0},{9,12,64},{8,8,128},{9,8,192},{8,8,256},{9,8,384},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 20 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {10,6,62},{10,6,62},{10,6,93},{10,6,124},{10,6,186},{10,6,248},{10,6,310},{0,0,0},
        {0,0,0},{10,8,64},{10,8,96},{10,8,128},{10,8,192},{10,8,256},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

#elif (USIM_MAX_CARD_CLK == USIM_MAX_3_4_MHz)

// D= 1 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {7,8,651},{7,8,651},{7,12,651},{7,8,1302},{7,8,1953},{7,8,2604},{7,8,3255},{0,0,0},
        {0,0,0},{7,8,896},{7,8,1344},{7,8,1792},{7,8,2688},{7,8,3584},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 2 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {7,7,372},{7,7,372},{7,7,558},{7,7,744},{7,7,1116},{7,7,1488},{7,7,1860},{0,0,0},
        {0,0,0},{7,8,448},{7,8,672},{7,8,896},{7,8,1344},{7,8,1792},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 4 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {7,6,217},{7,6,217},{7,9,217},{7,12,217},{7,9,434},{7,12,434},{7,10,651},{0,0,0},
        {0,0,0},{7,8,224},{7,8,336},{7,8,448},{7,8,672},{7,8,896},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 8 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {7,7,93},{7,7,93},{8,12,93},{7,7,186},{7,7,279},{7,7,372},{7,7,465},{0,0,0},
        {0,0,0},{7,8,112},{7,8,168},{7,8,224},{7,8,336},{7,8,448},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 16 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {8,12,31},{8,12,31},{8,9,62},{8,12,62},{8,12,93},{7,7,186},{8,12,155},{0,0,0},
        {0,0,0},{7,8,56},{7,8,84},{7,8,112},{7,8,168},{7,8,224},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 32 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {8,6,31},{8,6,31},{8,9,31},{8,12,31},{8,9,62},{8,12,62},{8,10,93},{0,0,0},
        {0,0,0},{7,8,28},{7,8,42},{7,8,56},{7,8,84},{7,8,112},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 64 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {8,31,3},{8,31,3},{16,9,31},{8,6,31},{8,9,31},{8,12,31},{8,15,31},{0,0,0},
        {0,0,0},{7,8,14},{7,6,28},{7,7,32},{7,7,48},{7,7,64},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 12 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {7,7,62},{7,7,62},{7,7,93},{7,7,124},{7,7,186},{7,7,248},{7,10,217},{0,0,0},
        {0,0,0},{12,8,128},{7,8,112},{9,8,192},{7,8,224},{9,8,384},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 20 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {10,6,62},{10,6,62},{10,6,93},{10,12,62},{10,12,93},{10,12,124},{7,6,217},{0,0,0},
        {0,0,0},{10,8,64},{10,8,96},{10,8,128},{10,8,192},{10,8,256},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

#elif (USIM_MAX_CARD_CLK == USIM_MAX_4_MHz)

// D= 1 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {6,8,558},{6,8,558},{6,8,837},{6,8,1116},{6,8,1674},{6,8,2232},{6,8,2790},{0,0,0},
        {0,0,0},{6,8,768},{6,8,1152},{6,8,1536},{6,8,2304},{6,8,3072},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 2 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {6,9,248},{6,9,248},{6,9,372},{6,9,496},{6,9,744},{6,9,992},{6,9,1240},{0,0,0},
        {0,0,0},{6,8,384},{6,8,576},{6,8,768},{6,8,1152},{6,8,1536},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 4 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {6,12,93},{6,12,93},{6,9,186},{6,12,186},{6,9,372},{6,8,558},{6,9,620},{0,0,0},
        {0,0,0},{6,8,192},{6,8,288},{6,8,384},{6,8,576},{6,8,768},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 8 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {6,9,62},{6,9,62},{6,9,93},{6,9,124},{6,9,186},{6,9,248},{6,9,310},{0,0,0},
        {0,0,0},{6,8,96},{6,8,144},{6,8,192},{6,8,288},{6,8,384},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 16 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {6,9,31},{6,9,31},{8,9,62},{6,9,62},{6,9,93},{6,9,124},{6,9,155},{0,0,0},
        {0,0,0},{6,8,48},{6,8,72},{6,8,96},{6,8,144},{6,8,192},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 32 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {8,6,31},{8,6,31},{8,9,31},{6,9,31},{8,9,62},{6,9,62},{8,10,93},{0,0,0},
        {0,0,0},{6,8,24},{6,8,36},{6,8,48},{6,8,72},{6,8,96},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 64 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {8,31,3},{8,31,3},{16,9,31},{8,6,31},{8,9,31},{6,9,31},{8,15,31},{0,0,0},
        {0,0,0},{6,8,12},{6,8,18},{6,8,24},{6,8,36},{6,8,48},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 12 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {6,6,62},{6,6,62},{6,6,93},{6,6,124},{6,6,186},{6,6,248},{6,10,186},{0,0,0},
        {0,0,0},{6,8,64},{6,8,96},{6,8,128},{6,8,192},{6,8,256},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 20 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {10,6,62},{10,6,62},{10,6,93},{10,6,124},{10,6,186},{10,6,248},{6,6,186},{0,0,0},
        {0,0,0},{10,8,64},{10,8,96},{10,8,128},{10,8,192},{10,8,256},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

#else /* USIM_4_8_MHz */

// D= 1 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {6,8,558},{5,8,465},{5,10,558},{5,8,930},{5,8,1395},{5,8,1860},{5,8,2325},{0,0,0},
        {0,0,0},{5,8,640},{5,8,960},{5,8,1280},{5,8,1920},{5,8,2560},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 2 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {6,9,248},{5,10,186},{5,9,310},{5,10,372},{5,9,620},{5,8,930},{5,10,930},{0,0,0},
        {0,0,0},{5,8,320},{5,8,480},{5,8,640},{5,8,960},{5,8,1280},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 4 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {6,12,93},{5,10,93},{5,9,155},{5,12,155},{5,9,310},{5,8,465},{5,10,465},{0,0,0},
        {0,0,0},{5,8,160},{5,8,240},{5,8,320},{5,8,480},{5,8,640},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 8 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {6,9,62},{5,15,31},{6,9,93},{5,10,93},{5,9,155},{5,10,186},{5,15,155},{0,0,0},
        {0,0,0},{5,8,80},{5,8,120},{5,8,160},{5,8,240},{5,8,320},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 16 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {6,9,31},{6,9,31},{8,9,62},{5,15,31},{6,9,93},{5,10,93},{6,15,93},{0,0,0},
        {0,0,0},{5,8,40},{5,8,60},{5,8,80},{5,8,120},{5,8,160},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 32 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {8,6,31},{8,6,31},{8,9,31},{6,9,31},{8,9,62},{5,15,31},{8,10,93},{0,0,0},
        {0,0,0},{5,8,20},{5,8,30},{5,8,40},{5,8,60},{5,8,80},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 64 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {8,31,3},{8,31,3},{16,9,31},{8,6,31},{8,9,31},{8,12,31},{8,15,31},{0,0,0},
        {0,0,0},{5,8,10},{5,8,15},{5,8,20},{5,8,30},{5,8,40},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 12 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {6,6,62},{5,10,31},{5,15,31},{5,10,62},{5,10,93},{5,10,124},{5,10,155},{0,0,0},
        {0,0,0},{6,8,64},{5,8,80},{6,8,128},{5,8,160},{6,8,256},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

// D= 20 :
   {  // F= 372      372      558      744      1116      1488      1860      RFU
        {10,6,62},{5,6,31},{5,9,31},{5,6,62},{5,9,62},{5,8,93},{5,10,93},{0,0,0},
        {0,0,0},{5,8,32},{5,8,48},{5,8,64},{5,8,96},{5,8,128},{0,0,0},{0,0,0}
   }, // F= RFU    512      768      1024      1536      2048      RFU    RFU

#endif /* USIM_MAX_CARD_CLK */

// RFU:
	{
		{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
		{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
	},

// RFU:
	{
		{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
		{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
	},

// RFU:
	{
		{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
		{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
	},

// RFU:
	{
		{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
		{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
	},

// RFU:
	{
		{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
		{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
	},

// RFU:
	{
		{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
		{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
	}
};


#else

extern const UINT16 USIM_CONVERSION_FACTOR_TABLE [USIM_TABLE_SIZE];

extern const UINT8 USIM_ADJUSTMENT_FACTOR_TABLE [USIM_TABLE_SIZE];

extern const USIM_Frequency USIM_MAX_FREQ_TABLE [USIM_TABLE_SIZE];

extern const USIM_BaudRate _USIMbaudRateTable [USIM_TABLE_SIZE] [USIM_TABLE_SIZE];

#endif

/*----------- Global Macro definitions ------------------------------------*/


#if defined(USIM_USE_SW_WDT_TIMER)
/***********************************************************************88
*
*
*/
void USIM_wdtExpired(UINT32 tmrId) ; 

/*  
            (_USIMbaudRateTable[1][0].divisor * (_USIMbaudRateTable[1][0].factor+1))
  1 etu =  _______________________________________________________________
            ( _USIMatrInfos[c].cardClock *100,000)

  1 byte =  ~ 10 etu

  for 3Mhz Clock when  F/D = 1/372    
     1 etu = 124 uSecs = 0.124mSecs
  
_________________________________________________________________________________________
  1 Clck is in milliSes =  1UL /(_USIMatrInfos[c].cardClock * 100UL*OSA_TICK_FREQ_IN_MILLISEC)
*/
#define _USIM_DELAY_100CLKS_2_USEC(val) (((UINT32)val*100) /USIM_MAX_3_MHz )

#define USIM_WDT_CLK_STOP_VAL     (_USIM_DELAY_100CLKS_2_USEC(USIM_CLOCK_STOP_DELAY_CYCLES)/(100UL* OSA_TICK_FREQ_IN_MILLISEC)+2)
#define USIM_WDT_CLK_START_VAL    (_USIM_DELAY_100CLKS_2_USEC(USIM_CLOCK_RESUME_DELAY_CYCLES)/(100UL*OSA_TICK_FREQ_IN_MILLISEC)+2)

/*
 *          F   1
 *  1 etu =  -- x  --
 *          D   f(Hz)
 *
 *
 */
#define USIM_100ETU_IN_USEC(c) ((UINT32)((UINT32)((_USIMatrInfos[c].conversionFactor+1) *_USIMatrInfos[c].adjustmentFactor*100)/(UINT32) (_USIMatrInfos[c].cardClock)))
#define USIM_WDT_MAX_TIME_FOR_T0(c)   ((UINT32)((10UL*300*_USIMatrInfos[c].workWaitingTime +300*10L+_USIMatrInfos[c].workWaitingTime) *USIM_10ETU_IN_USEC(c))/(1000L))
#define USIM_WDT_MAX_TIME_FOR_T1(c)  ((UINT32)((10UL*400*_USIMatrInfos[c].charWaitingTime+_USIMatrInfos[c].blockWaitingTime) *USIM_10ETU_IN_USEC(c))/(1000L))

/* Delay required to send MAX (255 bytes) of data + wait for procedure byte + wait for additional data with known length */
#define USIM_WDT_SEND_TIME(c,len)   ((UINT32) (len*12UL * USIM_100ETU_IN_USEC(c))/100L+1)


#define USIM_WDT_PROC_TIME_FOR_T0(c)    ((UINT32)( _USIMatrInfos[c].workWaitingTime * USIM_100ETU_IN_USEC(c))/100L)

#define USIM_WFT_PROC_TIME_FOR_T1(c)    ((UINT32)( _USIMatrInfos[c].blockWaitingTime * USIM_100ETU_IN_USEC(c))/100L)

/* Delay required to wait ONLY for additional data with known length */

#define USIM_WDT_READ_TIME_FOR_T0(c,len)   ((UINT32)((len*10UL*_USIMatrInfos[c].workWaitingTime ) *USIM_100ETU_IN_USEC(c))/(100L))
#define USIM_WDT_READ_TIME_FOR_T1(c,len)   ((UINT32)((len*10UL*_USIMatrInfos[c].charWaitingTime) *USIM_100ETU_IN_USEC(c))/(100L))


/* the value of delay required to send Max Buffer of Data + wait for 1 Procedure byte + wait for additional Data */
/* the value of delay required to send Max Buffer of Data + wait for 1 Procedure byte + wait for additional Data */
#define USIM_WDT_CLK_VAL_SENDONLY(c,len)   ( USIM_WDT_SEND_TIME(c,len)/OSA_TICK_FREQ_IN_MILLISEC+1)


#define USIM_WDT_CLK_VAL_PROC(c)   ((\
                            (_USIMatrInfos[c].protocol == USIM_T1)?\
                            ( USIM_WFT_PROC_TIME_FOR_T1(c)):\
                            ( USIM_WDT_PROC_TIME_FOR_T0(c)))/OSA_TICK_FREQ_IN_MILLISEC+1)
                            

#define USIM_WDT_CLK_VAL_READONLY(c,len)   ((\
                            (_USIMatrInfos[c].protocol == USIM_T1)?\
                            ( USIM_WDT_READ_TIME_FOR_T1(c,len)):\
                            ( USIM_WDT_READ_TIME_FOR_T0(c,len)))/OSA_TICK_FREQ_IN_MILLISEC+1)



#else

#define _USIM_DELAY_IN_CLKS(c)

#define USIM_WDT_CLK_STOP_VAL
#define USIM_WDT_CLK_START_VAL
#define USIM_WDT_CLK_VAL_PROCREAD(c,len)
#define USIM_WDT_CLK_VAL_READONLY(c,len)


#endif


/*----------- Global function prototypes -------------------------------------*/
#undef EXTERN

