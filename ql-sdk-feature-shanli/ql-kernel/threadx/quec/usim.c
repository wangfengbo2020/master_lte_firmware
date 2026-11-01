/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*****************************************************************************
 *               MODULE IMPLEMENTATION FILE
 ******************************************************************************
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
 * Title: USIM implementation file
 *
 * Filename: usim.c
 *
 * Author: Eilam Ben-Dror
 *   Leonid Krasnopolsky
 *
 * Description: This file implements the main UICC Driver API functions.
 *
 * Last Updated: 19-Jan-2006
 *
 * Copyright (c) 2005, Intel Corporation, All rights reserved.
 *****************************************************************************/

/*----------- External include files ----------------------------------------*/
#include "osa.h"
#include "usim_config.h"
#include "bsp_hisr.h"
#include "bsp.h"

#include "csw_memory.h"

#include <string.h>
#include "utils.h"
#include "intc.h"
#ifdef  USIM_TAVOR_DMA_ENABLE
#include "dma.h"
#endif

#if defined(PERIPHERAL_CLOCKS_VIA_PRM_API)
#include "prm.h"
#else
//#include "pmu.h"
#endif
#if 1 //_TAVOR_HARBELL_
#include "commpm.h"
#endif

/*----------- Local include files -------------------------------------------*/
#include "usim.h"

#define _USIM_DB_NO_EXTERN_
#include "usim_db.h"
#undef _USIM_DB_NO_EXTERN_

#include "usim_detect.h"
#include "usim_hw.h"
#include "usim_dl.h"
#include "usim_transport.h"

#if defined USIM_USE_TRACE
#include "diag.h"
#include "timer.h"
#include "platform_nvm.h"
#endif /* USIM_USE_TRACE */

#include "SysDynSilicon.h"
#include "cgpio.h"
#include "UART.h"
#include "quec_cust_feature.h" // quectel add
#include "quec_gpio.h"
#include "quec_urc.h"
#include "quec_power_manager.h"
#include "quec_include.h"
#include "gpio_config.h"
#include "quec_uart_at.h"
#include "gpio.h"

/*----------- Local defines -------------------------------------------------*/
// ATR Definitions:
// masks:
#define USIM_RECEIVED_BYTE_MASK					0xFFL
#define USIM_PARITY_ERROR_MASK					0x100L
#define USIM_HISTORIC_LEN_MASK					0x0F
#define USIM_TA_MASK							0x10
#define USIM_TB_MASK							0x20
#define USIM_TC_MASK							0x40
#define USIM_TD_MASK							0x80
#define USIM_CHANGEABILITY_MASK					0x80
#define USIM_SPECIFIC_MODE_PARAM_INDICATOR_MASK	0x10

#define USIM_ATR_MAX_LEN				33
#define USIM_ATR_MIN_LEN				2
#define USIM_GLOBAL_INTERFACE_BYTES		15
#define USIM_EQUAL_TX_EXTRA_GUARD_TIME	255

// Number of bytes to write to the TX FIFO at once
#define USIM_TX_BLOCK_SIZE 8

/* Clock resume delay in usec: */
#define USIM_CLOCK_RESUME_DELAY_CYCLES 744  // clock cycles
#define USIM_CLOCK_STOP_DELAY_CYCLES 1860  // clock cycles

/* Delay after deactivation, before reactivation: */
#define USIM_REACTIVATE_DELAY_CYCLES      ((10/OSA_TICK_FREQ_IN_MILLISEC)+1)
#ifdef  QUECTEL_PROJECT_CUST
#define USIM_INS_REMOVE_GUARD_TIME_TICK    (2000/5)     //KEVIN.WANG 20200727 modify it from 6000 to  2000
#else
#define USIM_INS_REMOVE_GUARD_TIME_TICK    (6000/5)
#endif
// PPS definitions:
typedef enum
{
	USIM_PPSS = 0,
	USIM_PPS0,
	USIM_PPS1,
	USIM_PCK,

	USIM_PPS_LENGTH
}USIM_PPSfield;


/*----------- Local macro definitions ---------------------------------------*/

#define USIM_CHECK_CARD_VALID(card) if (((int)card)<0 || ((int)card)>=((int)USIM_CARDS_AMOUNT)) \
											return USIM_RC_INVALID_CARD

#define USIM_GET_HIGH_END_FROM_BYTE(returned,byte)						\
		((returned) = (((byte) & 0xF0) >> 4))
#define USIM_GET_LOW_END_FROM_BYTE(returned,byte) ((returned) = ((byte) & 0x0F))

// is this the end of the ATR?
#define USIM_CHECK_END_ATR	if(currByteNum>=atrLen)							\
								return USIMendATR(globalInterface, N, card);\
							currByte = atrBuffer[++currByteNum];


// convert USIM_Class to its corresponding USIM_ControlStatus:
#define USIM_CLASS_TO_CTRL_IND(v) (((v) == USIM_CLASS_C)?					\
									USIM_CARD_ACTIVE_CLASS_C :				\
									USIM_CARD_ACTIVE_CLASS_B)

// Convert clock frequency to ratio:
#define USIM_CLOCK_TO_RATIO(f) ((USIM_IN_CLK * 5) / (f))

/*----------- Local type definitions ----------------------------------------*/

/*----------- Global constant definitions -----------------------------------*/

/*----------- Local constant definitions ------------------------------------*/
extern BOOL   GLFeatureFlag;

UINT32 usim_swap_flag=0;


// card interrupt sources:

INTC_InterruptSources _USIMinterruptSources[2] = {INTC_SRC_USIM1,INTC_SRC_USIM2 };

/*----------- Local variable definitions ------------------------------------*/
//--- SW only related -------

OSATimerRef _USIMtimerRefs [USIM_CARDS_AMOUNT];
OS_HISR     _USIMhisrRefs  [USIM_CARDS_AMOUNT];
UINT32 _USIMinterruptStatus[USIM_CARDS_AMOUNT];
BOOL   _USIMOsActive       [USIM_CARDS_AMOUNT];


//--- SW/HW related
BOOL        _USIMclockStopped    [USIM_CARDS_AMOUNT];
BOOL        _USIMisClockStopUsed [USIM_CARDS_AMOUNT];
USIM_Class  _USIMuseVoltageLevel [USIM_CARDS_AMOUNT];
BOOL        _USIM_hwRemoveProgress[USIM_CARDS_AMOUNT];

BOOL        _USIM_FastRemoveOnDetectContext = FALSE; //FALSE sends only notification to PS

extern USIM_Class _USIMcurrentVoltageClass[USIM_CARDS_AMOUNT];

#if defined USIM_USE_TRACE
#define     USIM_TRACE_BWT_TIMERS_MAX               16
static UINT32 _USIMBWTTimers[USIM_CARDS_AMOUNT][USIM_TRACE_BWT_TIMERS_MAX];
#ifdef USIM_DSDS_DKB
static UINT32 _USIMBWTTimersIndex[USIM_CARDS_AMOUNT] = {0,0};
#else
static UINT32 _USIMBWTTimersIndex[USIM_CARDS_AMOUNT] = {0};
#endif
#endif /* USIM_USE_TRACE */

/*----------- Local function definition -------------------------------------*/

void USIMControlIndication (USIM_Card card, USIM_ControlStatus status);
static void USIMATRInfoInit(USIM_Card card);
void USIMSetResponseReadFlag(UINT8 card, UINT32 responsereadFlag);

//static void USIMmalfunction_Remove(USIM_Card card);

/*----------begin--------------------TAVOR Stuff-----------------------------------*/
#ifdef  USIM_TAVOR_DMA_ENABLE
void USIMDmaSetup ( USIM_Card 	 card );
void USIMD2rmD2Register(void);
#endif
/*-----------end---------------------TAVOR Stuff-----------------------------------*/

extern int getMasterSimID(void);

#ifndef UPGRADE_LTE_ONLY
extern void SimSendGLSwapFlag(unsigned int val);
#endif

USIM_ReturnCode USIManswerToReset(USIM_Card card, UINT8 atrLen);
extern void usim_state_init(USIM_Card card);

//
// Enable original USIM clock management (Hermon)
// The other option uses USIMRMManage in different placed, which is wrong. Specifically, it shuts down the USIM clock
// without proper shutdown sequence, e.g. in USIMConfigure(), which results in Harbell hang.
//




typedef struct
{
	UINT32 len;
	USIM_Class voltage;
	UINT32 flag;
}usim_boot_atr_info_t;


usim_boot_atr_info_t usim_boot_atr_info[2];



int get_sim_swap_flag(void)
{
	return GLFeatureFlag;
}


UINT32 usim_1_op_flag=0;

void usim_1_op_enter(void)
{


}


void usim_1_op_exit(void)
{
}

UINT32 usim_1_get_op_flag(void)
{

	return usim_1_op_flag;
}


UINT32 usim_2_op_flag=0;

void usim_2_op_enter(void)
{

}


void usim_2_op_exit(void)
{

}

UINT32 usim_2_get_op_flag(void)
{

	return usim_2_op_flag;
}





#ifdef PHS_SW_DEMO_TTC
void usimClockSwitch_ttc(USIM_Card card,BOOL onOff)
{

#ifdef USIM_DSDS_DKB

	if (onOff)
	{
		if(usim_swap_flag==0)
		{
			if(card == USIM_BANKING_CARD)
				*(UINT32*)0xd403b024 = 0x3;
			else
				*(UINT32*)0xd403b020 = 0x3;
		}
		else
		{
			if(card == USIM_BANKING_CARD)
				*(UINT32*)0xd403b020 = 0x3;
			else
				*(UINT32*)0xd403b024 = 0x3;
		}
	}
	else
	{
		if(usim_swap_flag==0)
		{
			if(card == USIM_BANKING_CARD)
				*(UINT32*)0xd403b024 = 0x0; 
			else
				*(UINT32*)0xd403b020 = 0x0;
		}
		else
		{
			if(card == USIM_BANKING_CARD)
				*(UINT32*)0xd403b020 = 0x0; 
			else
				*(UINT32*)0xd403b024 = 0x0;
		}

	}


#else


	if (onOff)
	{
		if(usim_swap_flag==0)
		{
            *(UINT32*)0xd403b020 = 0x3;
		}
		else
		{
            *(UINT32*)0xd403b024 = 0x3;
		}
	}
	else
	{
		if(usim_swap_flag==0)
		{
            *(UINT32*)0xd403b020 = 0x0;
		}
		else
		{
			*(UINT32*)0xd403b024 = 0x0;
		}

	}

#endif

}
#endif
#define PMU_ENABLE

#if defined (PMU_ENABLE)
void USIM_PmuClockSwitch(USIM_Card card,BOOL onOff)
{

#ifdef USIM_DSDS_DKB

	if(usim_swap_flag == 1)
	{
		if(card == USIM_BANKING_CARD)
			PRMManage(PRM_SRVC_USIM,(onOff)?PRM_RSRC_ALLOC:PRM_RSRC_FREE);
		else
			PRMManage(PRM_SRVC_USIM2,(onOff)?PRM_RSRC_ALLOC:PRM_RSRC_FREE);
	}
	else
	{
		if(card == USIM_BANKING_CARD)
			PRMManage(PRM_SRVC_USIM2,(onOff)?PRM_RSRC_ALLOC:PRM_RSRC_FREE);
		else
			PRMManage(PRM_SRVC_USIM,(onOff)?PRM_RSRC_ALLOC:PRM_RSRC_FREE);
	}

#else

	if(usim_swap_flag == 1)
	{
		PRMManage(PRM_SRVC_USIM2,(onOff)?PRM_RSRC_ALLOC:PRM_RSRC_FREE);
	}
	else
	{
		PRMManage(PRM_SRVC_USIM,(onOff)?PRM_RSRC_ALLOC:PRM_RSRC_FREE);
	}

#endif

}
//#define USIM_PmuClockSwitch(onOff) PRMManage(PRM_SRVC_USIM,(onOff)?PRM_RSRC_ALLOC:PRM_RSRC_FREE)
#else
#define USIM_PmuClockSwitch(onOff)
#endif


#if defined (USIM_USE_SW_WDT_TIMER)
 void USIM_wdtExpired(UINT32 tmrId)
 {
    if (_USIMtimerWDTactive[tmrId])
    {
		usim_record_event(tmrId, USIM_EVT_USIM_wdtExpired);
        OSAFlagSet(_USIMflagsRefs[tmrId], USIM_WDT_TIMER_FLAG, OSA_FLAG_OR);
        _USIMtimerWDTactive[tmrId] = FALSE;
    }
 }
#endif



void usim_send_quit_event(UINT32 card)
{
	extern UINT32 get_usim_busy_flag(UINT32 card);
	
	if(get_usim_busy_flag(card)==1)
		OSAFlagSet(_USIMflagsRefs[card], USIM_WDT_TIMER_FLAG, OSA_FLAG_OR);
}



void TestUsimGetStatus(USIM_Card card)
{

}


UINT32 sim_removed_status = 0;


/******************************************************************************
* Function     :	USIM_DetectFoundByHW
*******************************************************************************
*
* Description  : This procedure should be called
*                when the SIM Remove or Insert event & new-stable-state discovered.
*                All issues of recognising and deboucing are out of it's scope -
*                 when it is called the the state is definitelly correct and stable.
*                Should NOT be called on a LISR context but may be called on HISR.
*
* Parameters   : inserted=TRUE  - New state SIM is inside
*                inserted=FALSE - New state SIM is outside
*
* Return value :	None
******************************************************************************/
void USIM_DetectFoundByHW(BOOL inserted)
{
    USIM_Card   card = USIM_COM_CARD;
	UINT32 cpsr;

	DIAG_FILTER(USIMLOG,USIM_DetectFoundByHW,LOG001,DIAG_INFORMATION)
	diagPrintf("USIM_DetectFoundByHW %x", inserted); 
	
    if(inserted)
    {/*--------------------- I N S E R T  -------------------------------------*/

		DIAG_FILTER(USIMLOG,USIM_DetectFoundByHW,LOG002,DIAG_INFORMATION)
		diagPrintf("inserted _USIMstates=%lx, _USIM_hwRemoveProgress=%lx", _USIMstates[card], _USIM_hwRemoveProgress[card]); 


	
        if( (_USIMstates[card] == USIM_REMOVED) || (_USIMstates[card] == USIM_INACTIVE))
        {
            if(_USIM_hwRemoveProgress[card])
            {
                //"Remove" is in progress, giv the time to finish it
                OSATaskSleep(USIM_INS_REMOVE_GUARD_TIME_TICK);
            }

			 cpsr = disableInterrupts();
            _USIMstates[card] = USIM_INACTIVE;
			restoreInterrupts(cpsr);

            //-- Notify the PS SIM driver manager (hadHandleUSIMControlIndication)
            USIMControlIndication(USIM_COM_CARD, USIM_CARD_INSERTED);
        }
    }
    else
    {   /*--------------------- R E M O V E -------------------------------------*/

		DIAG_FILTER(USIMLOG,USIM_DetectFoundByHW,LOG003,DIAG_INFORMATION)
		diagPrintf("remove _USIMstates=%lx, _USIM_hwRemoveProgress=%lx", _USIMstates[card], _USIM_hwRemoveProgress[card]); 	
	
        if((_USIMstates[card] != USIM_REMOVED) && (_USIMstates[card] != USIM_INACTIVE) && !_USIM_hwRemoveProgress[card])
        {

            USIMControlIndication(USIM_COM_CARD, USIM_CARD_REMOVED);

            cpsr = disableInterrupts();
            _USIMstates[card] = USIM_REMOVED;
            restoreInterrupts(cpsr);

        }

    }
}/*USIM_DetectFoundByHW*/




/*********************************************************************************
*
**********************************************************************************/
void USIMRxFIFO_Clear(USIM_Card card)
{
/*		UINT32 len, parityLen;
		UINT8  totalLen;
		// Get the number of erronuous bytes in the RX FIFO:
		USIM_PERR_NUM_GET(card, parityLen);
             // get the number of bytes still in the RX FIFO:
             USIM_RX_LENGTH_GET(card, len);

		totalLen = (UINT8)(parityLen+len);
		USIM_HW_RXRead_Dummy(card,totalLen);
*/
		UINT32 len;
              // get the number of bytes still in the RX FIFO:
              USIM_RX_LENGTH_GET(card, len);
		if (len)
			USIM_HW_RXRead_Dummy(card,len);
}


BOOL USIMhandleBWTInterrupt (USIM_Card card)
{
	UINT8  txFifoLen;
	UINT32 wt;
	USIM_Protocol protocol = _USIMatrInfos[card].protocol;
	BOOL bwtExpired = FALSE;

    if(_USIMstates[card] == USIM_ATR)
	{ // ATR was not received yet, BWT expired
		bwtExpired = TRUE;

	}

	else
	{
//--------------------------------------------------------------
		if( protocol == USIM_T1)
		{  //checking of rase condition when CWT occurs before any charachters has been send

			//ve.rify that the TX-FIFO is not empty:
			USIM_TX_LENGTH_GET(card, txFifoLen);
			if (txFifoLen > 0)
			{


				 USIM_DL_BWTSet(card);

				// Do we have more data to send
         		if (_USIMtxBufferSize[card] > 0 )
				{                               //impossible condition
             	// enable interrupts for "send" state:
             	USIM_ENABLE_MASK(card, USIM_SEND_ENABLE_MASK);
				}
				else
				{
             	// enable interrupts for "wait for response" state:
             	USIM_ENABLE_MASK(card, USIM_W4RESPONSE_ENABLE_MASK);
				}

				return bwtExpired;
			}
		}
//--------------------------------------------------------------
		USIM_BLOCK_WAIT_TIME_GET(card,protocol,wt);
		if(_USIMWTCnt[card] -= wt)
		{   // WWT has not expired, reset the counter:
			if(_USIMWTCnt[card] > USIM_MAX_WWT_REG_VALUE)
				USIM_BLOCK_WAIT_TIME_SET(card, protocol, USIM_MAX_WWT_REG_VALUE);
			else
				USIM_BLOCK_WAIT_TIME_SET(card, protocol, _USIMWTCnt[card]);


				// enable interrupts:
			USIM_ENABLE_MASK(card, USIM_W4RESPONSE_ENABLE_MASK);

			//Trigger the counters:
		    USIM_DIVISOR_SET(card, USIM_DIVISOR_GET(card));

			USIM_INTERRUPT_CLEAR_ALL(card);
		}
		else
		{  // WWT expired:
			bwtExpired = TRUE;
		}
	}

	// clear BWT interrupt:
	USIM_INTERRUPT_CLEAR(card, USIM_BWT);
#if 0	
#if defined USIM_USE_TRACE
	USIM_TRACING_ON_DEMAND
	{
		_USIMBWTTimers[card][_USIMBWTTimersIndex[card]++] = timerCountRead((TCR_NUMBER)0);
        if (_USIMBWTTimersIndex[card] > USIM_TRACE_BWT_TIMERS_MAX)
            _USIMBWTTimersIndex[card] = 0;        
	}
#endif /* USIM_USE_TRACE */
#endif
	return bwtExpired;
}



BOOL USIMhandleCWTInterrupt (USIM_Card card)
{
	UINT32 wt;
	UINT8 txFifoLen;
	BOOL cwtExpired = FALSE;

	if(_USIMatrInfos[card].protocol == USIM_T1)
	{  //checking of rase condition when CWT occurs before any charachters has been send

		//ve.rify that the TX-FIFO is not empty:
		USIM_TX_LENGTH_GET(card, txFifoLen);
		if (txFifoLen > 0)
		{

			USIM_CHAR_WAIT_TIME_SET(card, USIM_T1, (_USIMatrInfos[card].charWaitingTime+USIM_ADJUST_CWT_GCF));
			//Trigger the counters:
		    USIM_DIVISOR_SET(card, USIM_DIVISOR_GET(card));

			// Do we have more data to send
    		if (_USIMtxBufferSize[card] > 0 )
			{                               //impossible condition
    			// enable interrupts for "send" state:
    			USIM_ENABLE_MASK(card, USIM_SEND_ENABLE_MASK);
			}
			else
			{
    			// enable interrupts for "wait for response" state:
    			USIM_ENABLE_MASK(card, USIM_W4RESPONSE_ENABLE_MASK);
			}
		}
		else
		{

		 	 // In T=1 CWT < FFFF
			cwtExpired = TRUE;
		}
	}
	else
	{ // T=0 protocol
		USIM_CHAR_WAIT_TIME_GET(card,USIM_T0,wt);
		if(_USIMWTCnt[card] -= wt)
		{   // WWT has not expired, reset the counter:
			if(_USIMWTCnt[card] > USIM_MAX_WWT_REG_VALUE)
				USIM_CHAR_WAIT_TIME_SET(card, USIM_T0, USIM_MAX_WWT_REG_VALUE);
			else
				USIM_CHAR_WAIT_TIME_SET(card, USIM_T0, _USIMWTCnt[card]);

			//Trigger the counters:
		    	USIM_DIVISOR_SET(card, USIM_DIVISOR_GET(card));

			// clear all pending interrupts:
			//USIM_CLEAR_ALL(card);
			USIM_INTERRUPT_CLEAR_ALL(card);

            // enable interrupts for "receive" state:
            USIM_ENABLE_MASK(card, USIM_RECEIVE_ENABLE_MASK);
		}
		else
		{  // WWT expired:
			cwtExpired = TRUE;
		}
	}
	return cwtExpired;
}



/*******************************************************************************
* Functions:     USIMbuffersAllocate / USIMbuffersFree
*  The USIM_COM_CARD is always used => the buffers are always should be present,
*  so use static alloc instead dynamic for the USIM_COM_CARD.
*  Right now, there is no other cards, but keep code generic...
********************************************************************************
* Parameters:   card
********************************************************************************
*/
static UINT8  _USIMrxBuf[2][USIM_BUFFER_SIZE];
static UINT8  _USIMtxBuf[2][USIM_BUFFER_SIZE];
static UINT8  _USIMdataBuf[2][USIM_BUFFER_SIZE];



/*******************************************************************************
* Function:     USIMbuffersFree
*******************************************************************************/
static void USIMbuffersFree(USIM_Card card)
{
#if 0
  if(card != USIM_COM_CARD)
  { //Should be done only if not NULL, but never called...
    Free(_USIMrxBuffers[card]);     _USIMrxBuffers[card]  = NULL;
    Free(_USIMtxBuffers[card]);     _USIMtxBuffers[card]  = NULL;
    Free(_USIMdataBuffers[card]);   _USIMdataBuffers[card]= NULL;
  }
#endif

}

/*******************************************************************************
* Function:     USIMbuffersAllocate
*******************************************************************************/
static USIM_ReturnCode USIMbuffersAllocate(USIM_Card card)
{

#if 0

  if(card == USIM_COM_CARD)
  {
    _USIMrxBuffers[card]  = _USIMrxBuf;
    _USIMtxBuffers[card]  = _USIMtxBuf;
    _USIMdataBuffers[card]= _USIMdataBuf;
  }
  else
  {
    _USIMrxBuffers[card]  = alignMalloc(USIM_BUFFER_SIZE);  ASSERT(_USIMrxBuffers[card]!=NULL);   //return USIM_RC_OSA_ERROR;
    _USIMtxBuffers[card]  = alignMalloc(USIM_BUFFER_SIZE);  ASSERT(_USIMtxBuffers[card]!=NULL);   //return USIM_RC_OSA_ERROR;
    _USIMdataBuffers[card]= alignMalloc(USIM_BUFFER_SIZE);  ASSERT(_USIMdataBuffers[card]!=NULL); //return USIM_RC_OSA_ERROR;
  }
#endif  
  return USIM_RC_OK;
}


/*******************************************************************************
* Function: USIMdelayHandler
********************************************************************************
* Description: This is called when the dealy is over.
*
* Parameters: card
*
* Return value: None
*
* Notes:
*******************************************************************************/
static void USIMdelayHandler(USIM_Card card)
{

    // clear all pending interrupts:
    USIM_CLEAR_ALL(card);
    USIM_DISABLE_ALL(card);

    // set the USIM_CLOCK_STOP_FLAG:
    OSAFlagSet(_USIMflagsRefs[card], USIM_CLOCK_STOP_FLAG, OSA_FLAG_OR);
}


/*******************************************************************************
* Function:		USIMwriteHandler
********************************************************************************
* Description:	Handles the USIM interrupts for USIM_SEND state.
*
* Parameters:	card - the USIM card
*
* Return value: None.
*
* Notes: called by interruptHandler
*******************************************************************************/

static void USIMwriteHandler(USIM_Card card)
{
	UINT32 dataLen;		// the number of bytes to send
    UINT32 status = _USIMinterruptStatus[card];
	UINT8 txFifoLen;

	usim_record_event(card, USIM_EVT_USIMwriteHandler_001);

    if (status & USIM_T0_ERR_MASK)
    {



	
        // clear T0 error indication:
        USIM_T0_ERR_CLEAR(card);

        // clear all other pending interrupts:
        USIM_CLEAR_ALL(card);


        _USIMErrorStat[card] = USIM_T0_ERR;

#ifdef USIM_TAVOR_DMA_ENABLE
        if ( USIMRxTxModeGet(card) == USIM_DMA_MODE )
        {
        	USIM_DISABLE_TX_DMA_MODE(card);
#ifdef PHS_SW_DEMO_TTC
		DMAChannelStop ( USIM1_TRANSMIT_DMA_CHANNEL , TRUE );
#else
            	DMAChannelStop ( USIM_DMA_WRITE_CHAN , TRUE );
#endif
        }
#endif
        USIM_WDT_TIMER_STOP(card);
		
		usim_record_event(card, USIM_EVT_USIMwriteHandler_002);

        OSAFlagSet(_USIMflagsRefs[card], USIM_DEACTIVATE_FLAG, OSA_FLAG_OR);
    }
	else
	{// Transmitter data refill

		
		
		//verify that the TX-FIFO has enough space for the next block:
		USIM_TX_LENGTH_GET(card, txFifoLen);

		usim_record_event_one_data(card, USIM_EVT_USIMwriteHandler_003, txFifoLen);
		
		if(txFifoLen > USIM_TX_BLOCK_SIZE)
		{
            // TX FIFO is still too full, trace in ICAT and wait for the next interrupt

            // enable interrupts for "send" state:
            USIM_ENABLE_MASK(card, USIM_SEND_ENABLE_MASK);
            return;
		}


		// how many bytes are left to be written:
		dataLen = _USIMtxBufferSize[card];

		usim_record_event_one_data(card, USIM_EVT_USIMwriteHandler_004, dataLen);

        if (dataLen > USIM_TX_BLOCK_SIZE)
		{
			// write a block:
			USIM_HW_TXWrite(card, USIM_TX_BLOCK_SIZE, _USIMtxBufferPtrs[card]);

			// update pointer:
			_USIMtxBufferPtrs[card] += USIM_TX_BLOCK_SIZE;

			// update size:
			_USIMtxBufferSize[card] -= USIM_TX_BLOCK_SIZE;
            USIM_WDT_TIMER_START(card, 2000);

            // enable interrupts for "send" state:
            USIM_ENABLE_MASK(card, USIM_SEND_ENABLE_MASK);
		}

		else
		{
			// less than block to be written:
			USIM_HW_TXWrite(card, dataLen, _USIMtxBufferPtrs[card]);

#if defined USIM_USE_TRACE
#if 0
			_USIMBWTTimersIndex = 0;
			USIM_TRACING_ON_DEMAND
			{
				_USIMBWTTimers[card][_USIMBWTTimersIndex[card]++] = timerCountRead((TCR_NUMBER)0);
			}
#endif			
#endif /* USIM_USE_TRACE */


			// FINISHED SENDING:

            // change DL state:
            _USIMDLstates[card] = USIM_WAIT_FOR_RESPONSE;
            USIM_WDT_TIMER_START(card, 2000);
            // enable interrupts for "wait for response" state:
            USIM_ENABLE_MASK(card, USIM_W4RESPONSE_ENABLE_MASK);


		}
	}
} /* End of USIMwriteHandler */



/*******************************************************************************
* Function:     USIMT1ExpectedLenGet
********************************************************************************
* Description:  Retrieves the LEN field of a T=1 response, and updates the
*               expected length accordingly.
*
* Parameters:	card - the USIM card
*
* Return value: TRUE iff the expected len is updated
*
* Notes: called by readHandler
*******************************************************************************/
static BOOL USIMT1ExpectedLenGet(USIM_Card card)
{
    UINT8 prologue[USIM_T1_PROLOGUE_SIZE];

    // read the prologue:
    USIM_HW_RXRead(card, USIM_T1_PROLOGUE_SIZE, prologue);

    // update the expected bytes number. LEN=field coudn't be equal to 0xFF (Reserved),
    _USIMexpectedLen[card] = ((prologue[USIM_T1_PROLOGUE_SIZE-1] ==0xFF)?0xFF:(prologue[USIM_T1_PROLOGUE_SIZE-1]+1));

    // set the rx trigger level according to expected len
    USIMrxLevelSet(card, _USIMexpectedLen[card]);


    // write the prologue in the rx buffer:
    memcpy(_USIMrxBufferPtrs[card], prologue, USIM_T1_PROLOGUE_SIZE);

    // update pointer:
    _USIMrxBufferPtrs[card] += USIM_T1_PROLOGUE_SIZE;

   return TRUE;
} /* End of USIMT1ExpectedLenGet */


/*******************************************************************************
* Function:		USIMdecodeProcedureByte
********************************************************************************
* Description:	Decodes the first byte of the response
*
* Parameters:	card - the USIM card
*
* Return value: FALSE iff the procedure byte was !ins or NULL byte
*
* Notes: called by readHandler
*******************************************************************************/
static BOOL USIMdecodeProcedureByte(USIM_Card card)
{
	UINT32 dataLen = 0;
	UINT8 procByte;
	UINT8 ins = (_USIMcommandHeaders[card]).instructionCode;
	BOOL readRest = FALSE;

	// read the procedure byte:
	USIM_HW_RXRead(card, 1, &procByte);

	usim_record_event_one_data(card, USIM_EVT_USIMdecodeProcedureByte_001, procByte);

    if(procByte == USIM_NULL_BYTE)
    {
        return readRest;
    }

	// if case 3:
	if(_USIMexpectedLen[card] == 1)
	{
            // write the byte in the rx buffer:
		*(_USIMrxBufferPtrs[card]) = procByte;

		// update pointer:
		_USIMrxBufferPtrs[card] += 1;

             if( (procByte== ins) || (procByte == USIM_BYTEWISE_NOT(ins)))                       //(CHECK_FOR_ACK(ins, procByte))
		{
			// update the expected bytes number:
			_USIMexpectedLen[card] = 0;
		}
			 
		usim_record_event_one_data(card, USIM_EVT_USIMdecodeProcedureByte_002, ins);
		
		readRest = TRUE;
	}
	else
	{// case 2:
		if((procByte == USIM_BYTEWISE_NOT(ins)) && (procByte != 0x6F) && (procByte != 0x90))
		{
			usim_record_event_one_data(card, USIM_EVT_USIMdecodeProcedureByte_003, USIM_BYTEWISE_NOT(ins));

		   while (dataLen == 0)
            {
            	// get the number of bytes received:
            	USIM_RX_LENGTH_GET(card, dataLen);
            }
            // read 1 data byte:
            USIM_HW_RXRead(card, 1, _USIMrxBufferPtrs[card]);

			usim_record_event_one_data(card, USIM_EVT_USIMdecodeProcedureByte_004, *(_USIMrxBufferPtrs[card]));

                // update pointer:
            _USIMrxBufferPtrs[card] += 1;

            // update the expected bytes number:
            _USIMexpectedLen[card] -= 1;
		}
		else
		{
			

			readRest = TRUE;

    		if((procByte != ins)||(procByte == 0x90))// == 6C / 61 / 6X / 9X  i.e. we got SW1
    		{
                        // write the byte in the rx buffer:
    			*(_USIMrxBufferPtrs[card]) = procByte;

    			// update pointer:
    			_USIMrxBufferPtrs[card] += 1;

    			// update the expected bytes number:
    			_USIMexpectedLen[card] = 1;
    		}
		}
	}

	return readRest;
}/*		End of USIMdecodeProcedureByte	*/



/*******************************************************************************
* Function:		USIMreadHandler
********************************************************************************
* Description:	Handles the USIM interrupts for USIM_WAIT_FOR_RESPONSE and
*				USIM_RECEIVE states.
*
* Parameters:	card - the USIM card
*				dlState - the Data Link state
*
* Return value: None.
*
* Notes: called by interruptHandler
*******************************************************************************/
static void USIMreadHandler(USIM_Card card, USIM_State dlState)
{
	UINT32 dataLen = 0;		// the number of bytes received from the card

#ifdef USIM_DSDS_DKB	
	static BOOL readRest[USIM_CARDS_AMOUNT] = {FALSE,FALSE};	// true iff ins byte was sent
#else
	static BOOL readRest[USIM_CARDS_AMOUNT] = {FALSE};
#endif
	UINT32 status = _USIMinterruptStatus[card];
	BOOL wwtExpired = FALSE;
	USIM_Protocol protocol = _USIMatrInfos[card].protocol;
	UINT32  parityLen = 0;
	UINT8   parityTri = 0; 

	USIM_WDT_TIMER_STOP(card);



	usim_record_event(card, USIM_EVT_READ_USIMreadHandler_001);


	
	if  (status & USIM_PARITY_ERR_MASK)
	{
#ifdef  SS_FEATURE		
		USIM_PERR_NUM_GET(card, parityLen); //check Parity Error FIFO
		parityLen = 0;
		parityTri = 0xff & ((USIMHWRegisters[card]->ECR) > 0x3);
#endif		
		_USIMParityErrorCnt[card]++;
		usim_record_event_four_data(card, USIM_EVT_READ_USIMreadHandler_002, _USIMParityErrorCnt[card]);



	}

	if((dlState == USIM_WAIT_FOR_RESPONSE)&&(status & USIM_BWT_MASK))
	{
		wwtExpired = USIMhandleBWTInterrupt(card);
		usim_record_event_one_data(card, USIM_EVT_READ_USIMreadHandler_003, wwtExpired);
		if(wwtExpired == FALSE)
		{ // since WWT > 0xFFFF, more iterations are required, so ignore this interrupt
			return;
		}
	}

	if( (wwtExpired==TRUE)||
	( (status & ( USIM_PARITY_ERR_MASK | USIM_FRAMING_ERR_MASK))  && (protocol == USIM_T0)) ||
	( (status & USIM_RX_OVERRUN_MASK) && (protocol != USIM_T0)) ||
	( (dlState == USIM_WAIT_FOR_RESPONSE) && (status & USIM_T0_ERR_MASK)))
	{

		_USIMErrorStat[card] = status;

		// clear all pending interrupts:
		USIM_CLEAR_ALL(card);
		USIM_WDT_TIMER_STOP(card);
		// set the deactivate flag:
			usim_record_event(card, USIM_EVT_READ_USIMreadHandler_004);
		OSAFlagSet(_USIMflagsRefs[card], USIM_DEACTIVATE_FLAG, OSA_FLAG_OR);
		return;
	}

	if(status & USIM_CWT_MASK)
	{
	
	
		wwtExpired = USIMhandleCWTInterrupt(card);
				usim_record_event_one_data(card, USIM_EVT_READ_USIMreadHandler_005, wwtExpired);
		if(wwtExpired == FALSE)
		{ // since WWT > 0xFFFF, more iterations are required, so ignore this interrupt
			
			return;
		}
	}
	else
	{  // USIM_RX_DATA_READY_MASK || USIM_RX_TIMEOUT_MASK
		if (dlState == USIM_WAIT_FOR_RESPONSE)
		{

	
			
			// change DL state to receive:
			_USIMDLstates[card] = dlState = USIM_RECEIVE;

					usim_record_event(card, USIM_EVT_READ_USIMreadHandler_006);
			// enable Character Waiting Time:
			USIM_ENABLE(card, USIM_CWT);
			USIM_INTERRUPT_CLEAR(card,USIM_CWT);
		}
	}
	
	if (wwtExpired == FALSE)
	{
		USIM_RX_LENGTH_GET(card, dataLen);
		USIM_PERR_NUM_GET(card, parityLen); //check Parity Error FIFO

			usim_record_event_one_data(card, USIM_EVT_READ_USIMreadHandler_007, dataLen);
			usim_record_event_one_data(card, USIM_EVT_READ_USIMreadHandler_008, parityLen);




		
		if (parityLen)
		{
			_USIMParityErrorCnt[card]++;
				usim_record_event_four_data(card, USIM_EVT_READ_USIMreadHandler_009, _USIMParityErrorCnt[card]);
		}

		if(_USIMstates[card] == USIM_SPECIFIC)
		{
			while((readRest[card]==FALSE) && dataLen && (_USIMParityErrorCnt[card] == 0) )
			{
				if(protocol == USIM_T0)  // if ins was not sent yet - decode procedure byte: 
				{   //character was received, so WWT counting should be reset:
					USIM_DL_WWTSet(card);
								usim_record_event_one_data(card, USIM_EVT_READ_USIMreadHandler_010, dataLen);
					readRest[card] = USIMdecodeProcedureByte(card);


					
				}
				else
				{//T=1 used:
					if (( dataLen >= USIM_T1_PROLOGUE_SIZE) && ( _USIMParityErrorCnt[card] ==0))
						readRest[card] = USIMT1ExpectedLenGet(card);
					else if (_USIMParityErrorCnt[card])
					{
						_USIMDLstates[card] =  USIM_RECEIVE;
						USIM_RX_CLEAR(card);
					}
				}
				// get the number of bytes received:
				USIM_RX_LENGTH_GET(card, dataLen);
				USIM_PERR_NUM_GET(card, parityLen); //check Parity Error FIFO

							usim_record_event_one_data(card, USIM_EVT_READ_USIMreadHandler_011, dataLen);
							usim_record_event_one_data(card, USIM_EVT_READ_USIMreadHandler_012, parityLen);


				
				if (parityLen)
				{
					_USIMParityErrorCnt[card]++;
								usim_record_event_four_data(card, USIM_EVT_READ_USIMreadHandler_013, _USIMParityErrorCnt[card]);
				}
			}// end of while(readRest==FALSE && dataLen) && (_USIMParityErrorCnt[card] == 0)
		}

		while (dataLen)
		{
			if (_USIMParityErrorCnt[card]==0)
			{



			
				if ( _USIMexpectedLen[card] < dataLen)		// changened for VIBO USIM issue
					dataLen =  _USIMexpectedLen[card];    	// -lk-

				
				USIM_HW_RXRead(card, dataLen, _USIMrxBufferPtrs[card]);
				_USIMrxBufferPtrs[card] += dataLen;
				_USIMexpectedLen[card] -= dataLen;

				

				/* VIBO USIM Issue. Check if instead of SW1  there is 'NULL' procedure bytes */
				if ( (protocol == USIM_T0) && (_USIMstates[card] == USIM_SPECIFIC) && (dlState == USIM_RECEIVE)&& (_USIMexpectedLen[card] <= 1) )
				{
					UINT8* pSW1SW2 = _USIMrxBufferPtrs[card] - 2 + _USIMexpectedLen[card] ;

					usim_record_event_one_data(card, USIM_EVT_READ_USIMreadHandler_014, pSW1SW2[0]);
					//check SW1 - second byte starting from the end of the buffer  [data|data|data....data][SW1][SW2]
					if ( pSW1SW2[0] == USIM_NULL_BYTE)
					{




					
						if ( _USIMexpectedLen[card] == 0)
						{
							// All data has been read, so remove  'USIM_NULL_BYTE' and move SW2 into the SW1
							pSW1SW2[0] = pSW1SW2[1];
							//Correct expected len according the new value SW1(old SW2) ('NULL'?)
							_USIMexpectedLen[card] = ( pSW1SW2[0] == USIM_NULL_BYTE)?2:1;
							
							usim_record_event_one_data(card, USIM_EVT_READ_USIMreadHandler_015, _USIMexpectedLen[card]);
						}
						else
        				{
        				 	_USIMexpectedLen[card] = 2;
							usim_record_event(card, USIM_EVT_READ_USIMreadHandler_016);
        				}

						// Update pointer according to found number (1 - 2) of 'USIM_NULL_BYTE' bytes
						_USIMrxBufferPtrs[card] =  pSW1SW2 + 2 - _USIMexpectedLen[card];
					}
				} //  if ((protocol == USIM_T0) && (_USIMstates[card] == USIM_SPECIFIC) &&...
			}//_USIMParityErrorCnt[card] ==0
			if (_USIMParityErrorCnt[card])
			{
                	usim_record_event_four_data(card, USIM_EVT_READ_USIMreadHandler_017, _USIMParityErrorCnt[card]);


			
				if ( protocol == USIM_T0)
				{  // In Case of Parity Error AND T=0 - not necessary to read rest of data
					_USIMexpectedLen[card] = 0;
					break;
				}
				else
					USIM_RX_CLEAR(card);

			}
			if (_USIMexpectedLen[card] == 0 )
                {
                	usim_record_event(card, USIM_EVT_READ_USIMreadHandler_018);
					break;
                }
			// get the number of bytes received:
			USIM_RX_LENGTH_GET(card, dataLen);
			USIM_PERR_NUM_GET(card, parityLen); //check Parity Error FIFO
                usim_record_event_one_data(card, USIM_EVT_READ_USIMreadHandler_018, dataLen);
				usim_record_event_one_data(card, USIM_EVT_READ_USIMreadHandler_019, parityLen);
			if (parityLen)
			{
				_USIMParityErrorCnt[card]++;
			usim_record_event_four_data(card, USIM_EVT_READ_USIMreadHandler_020, _USIMParityErrorCnt[card]);
			}



			
		} // while (dataLen)
	} //if (wwtExpired == FALSE)

	if ((dlState == USIM_RECEIVE) && ((_USIMexpectedLen[card] == 0) || (wwtExpired == TRUE)))
	{


	
		// change DL state to "process"
		_USIMDLstates[card] = USIM_PROCESS;

		readRest[card] = FALSE;

		// clear all pending interrupts:
		USIM_CLEAR_ALL(card);

		/* Disable all interrupts */
		USIM_DISABLE_ALL(card);

		USIM_WDT_TIMER_STOP(card);

			usim_record_event(card, USIM_EVT_READ_USIMreadHandler_021);
		// set the data read flag:
		OSAFlagSet(_USIMflagsRefs[card], USIM_DATA_READ_FLAG, OSA_FLAG_OR);
	}
	else /* Continue receiving data */
	{
		if((status & USIM_RX_OVERRUN_MASK) && (protocol == USIM_T0))
		{ // Overrun error in T=0, character was retransmitted, clear interrupt
			USIM_INTERRUPT_CLEAR(card, USIM_RX_OVERRUN);
				usim_record_event(card, USIM_EVT_READ_USIMreadHandler_022);
		}

		if(protocol == USIM_T0)			// -lk--
			_USIMWTCnt[card] = _USIMatrInfos[card].workWaitingTime;  // Instead of this: USIM_DL_WWTSet(card);




		
		if(readRest[card] == TRUE)
		{
			// set the Data Ready level according to the expected length:
			USIMrxLevelSet(card, _USIMexpectedLen[card]);
		}
		USIM_WDT_TIMER_START(card,2000);                
			usim_record_event_four_data(card, USIM_EVT_READ_USIMreadHandler_023, USIM_WDT_CLK_VAL_READONLY(card, USIMCompRxFifoLevel(_USIMexpectedLen[card])));
		// enable interrupts for "receive" state:
		USIM_ENABLE_MASK(card, USIM_RECEIVE_ENABLE_MASK);
	}

} /* End of USIMreadHandler */



/*******************************************************************************
* Function:		USIMsisrBankingCard
********************************************************************************
* Description:	second level ISR for the USIM_BANKING_CARD
*
* Parameters: None
*
* Return value: None.
*
* Notes:
*******************************************************************************/


static void usim_lisr(USIM_Card card)
{

    if(_USIMisDelaySet[card] && (_USIMinterruptStatus[card] & USIM_CWT_MASK))
    {
        _USIMisDelaySet[card] = FALSE;
		usim_record_event(card, USIM_EVT_USIMsisrComCard_002);
        USIMdelayHandler(card);
    }
    else
    {
    	usim_record_event_two_data(card, USIM_EVT_USIMsisrComCard_003, _USIMDLstates[card]);
		
        switch(_USIMDLstates[card])
        {
        case USIM_WAIT_FOR_RESPONSE:
            USIMreadHandler(card, USIM_WAIT_FOR_RESPONSE);
            break;

        case USIM_RECEIVE:
            USIMreadHandler(card, USIM_RECEIVE);
            break;

        case USIM_SEND:
            USIMwriteHandler(card);
            break;

        default:
            return;
        }// end switch
    }


}


#ifdef USIM_DSDS_DKB

static void USIMsisrBankingCard(void)
{
	usim_lisr(USIM_BANKING_CARD);

}

#endif


/*******************************************************************************
* Function:		USIMsisrComCard
********************************************************************************
* Description:	second level ISR for the USIM_COM_CARD
*
* Parameters: None
*
* Return value: None.
*
* Notes:
*******************************************************************************/
static void USIMsisrComCard(void)
{
	usim_lisr(USIM_COM_CARD);


}/*	End of USIMsisrComCard	*/




/*******************************************************************************
* Function:		USIMhandler
********************************************************************************
* Description:	handles the USIM interrupts
*
* Parameters: value - returned by INTC
*
* Return value: None.
*
* Notes:
*******************************************************************************/
#ifndef PHS_SW_DEMO_TTC
static void USIMhandler(UINT32 value)
#else
void USIMhandler(UINT32 value)
#endif
{
    UINT32 dummy,enabled_ints,status_ints,rxdata,txdata;
    //UINT32 pinStateMask = 0x80000000;   // indicates the pin's state within value

	USIM_Card card = (USIM_Card)value;

    //if((value & ~pinStateMask) != _USIMinterruptSources[USIM_COM_CARD])
    //{
    //    card++;
    //}

    // read the interrupt identification register:
       USIM_INTERRUPT_STATUS_GET(card,status_ints );

	/* Clear all interrupts indications */
	USIM_INTERRUPT_CLEAR_ALL(card);

	/* Dummy read, to verify that the interrupt clear has completed */
	USIM_INTERRUPT_STATUS_GET(card,dummy);

       enabled_ints = USIM_GET_IER(card);

        /* Disable all interrupts */
        USIM_DISABLE_ALL(card);

		usim_record_event_two_data(card, USIM_EVT_USIMhandler_001, (UINT16)status_ints);


        if  ((status_ints & USIM_IIR_ALL_BITS_MASK )==0)
        { //abnormal case
                USIM_RX_LENGTH_GET(card, rxdata);
                USIM_TX_LENGTH_GET(card, txdata);

				usim_record_event_one_data(card, USIM_EVT_USIMhandler_002, txdata);
				usim_record_event_one_data(card, USIM_EVT_USIMhandler_003, rxdata);
				
                if ((enabled_ints & USIM_TX_DATA_REFILL_MASK) && txdata)
                {
                    status_ints  |= USIM_TX_DATA_REFILL_MASK;
                }
                if ((enabled_ints & USIM_RX_DATA_READY_MASK) && rxdata)
                {
                    status_ints |= USIM_RX_DATA_READY_MASK;
                }
                if ((enabled_ints & USIM_IIR_ALL_BITS_MASK)==0)
                {
                     USIM_ENABLE_MASK(card, enabled_ints);
    	    	     USIM_DIVISOR_SET(card, USIM_DIVISOR_GET(card));
                     return;
                }
                if(dummy) dummy =0;  //Only to avoid the compile Warning
       }
		

	{
		if(status_ints&USIM_RX_OVERRUN_MASK)
			ASSERT(0);
	}

    _USIMinterruptStatus[card]= status_ints;



	ASSERT(OS_Activate_HISR(&_USIMhisrRefs[card]) == OS_SUCCESS);

} /* End of USIMhandler */


static void USIMhandler_1(UINT32 v)
{
	USIMhandler(USIM_COM_CARD);
}

#ifdef USIM_DSDS_DKB
static void USIMhandler_2(UINT32 v)
{
	USIMhandler(USIM_BANKING_CARD);
}

#endif



/*----------- ATR Related Local Functions -----------------------------------*/


/*******************************************************************************
* Function:		USIMextraGuardTimeSet
********************************************************************************
* Description:	Sets the extra guard time parameter, N
*
* Parameters:	N - the extra guard time parameter, received at ATR
*				card - the USIM card
*
* Return value:	None
*
* Notes:
*******************************************************************************/
static void USIMextraGuardTimeSet(UINT8 N, USIM_Card card)
{
	UINT32 exGuardTime = 0;
	USIM_ATRInfo * atrInfo = _USIMatrInfos + card;

	// check if 0 < N < 255
	if (N != USIM_EQUAL_TX_EXTRA_GUARD_TIME)
	{
        exGuardTime = N;

		// check which protocol is in use:
		if(atrInfo->protocol == USIM_T1)
		{
			exGuardTime++;	// beacause in T=1 HW adds 11 etu to the
							// exGuardTime, instead of the required 12 etu.
		}
	}
	// if using high baud rate - add 4 etu to extra guard time, due to errors seen on some cards
	if(	(atrInfo->conversionFactor != USIM_DEFAULT_CONVERSION_FACTOR) ||
		(atrInfo->adjustmentFactor != USIM_DEFAULT_ADJUSTMENT_FACTOR))
	{
		exGuardTime += USIM_HIGH_BAUD_RATE_EXTRA_GUARD_TIME_ADJUST;
	}

	// verify that exGuardTime <= 255
	if(exGuardTime > 0xFF)
		exGuardTime = 0xFF;

    if(atrInfo->extraGuardTime != (UINT8)exGuardTime)
    {
        // set the value in the HW register:
        USIM_EXTRA_GUARD_TIME_SET(card, exGuardTime);

        // set the value in _ATRInfo struct:
        atrInfo->extraGuardTime = (UINT8)exGuardTime;
    }

	return;
} /* End of USIMextraGuardTimeSet */



#ifndef USIM_NO_ATR_PPS_DECODING


/*******************************************************************************
* Function:		USIMconventionSet
********************************************************************************
* Description:	Decodes the initial character and sets the used coding convention
*
* Parameters:	convention - the received initial byte
*				card - the required card
*
* Return value: USIM_RC_OK
*				USIM_RC_ATR_ERROR
*
* Notes:
*******************************************************************************/
static USIM_ReturnCode USIMconventionSet(UINT8 convention, USIM_Card card)
{
	switch(convention)
	{
    case USIM_DIRECT:       _USIMatrInfos[card].convention = USIM_DIRECT;
							break;

    case USIM_INVERSE:      _USIMatrInfos[card].convention = USIM_INVERSE;
							break;

	default:				return USIM_RC_ATR_ERROR;
	}

	return USIM_RC_OK;
} /* End of USIMconventionSet */




/*******************************************************************************
* Function:		USIMdecodeTA1
********************************************************************************
* Description:	Decodes the TA1 character of the ATR, setting the indicated
*				factor and divisor values.
*
* Parameters:	ta1 - the received byte
*				card - the USIM card
*
* Return value:None
*
* Notes:
*******************************************************************************/
static void USIMdecodeTA1(UINT8 ta1, USIM_Card card)
{
	UINT8 FI, DI;

	// get the indicated clock rate conversion factor, FI:
	USIM_GET_HIGH_END_FROM_BYTE(FI, ta1);

	// set its value according to lookup table:
	_USIMatrInfos[card].indConversionFactor = USIM_CONVERSION_FACTOR_TABLE[FI];

	// set the max card clock frequency, f:
	_USIMatrInfos[card].indCardClock = USIM_MAX_FREQ_TABLE[FI];

	// get the indicated baud rate adjustment factor, DI:
	USIM_GET_LOW_END_FROM_BYTE(DI, ta1);

	// set its value according to lookup table:
	_USIMatrInfos[card].indAdjustmentFactor= USIM_ADJUSTMENT_FACTOR_TABLE[DI];
	return;

} /* End of USIMdecodeTA1 */







/*******************************************************************************
* Function:		USIMdecodeTA2
********************************************************************************
* Description:	Decodes the TA2 character of the ATR: the specific mode byte
*
* Parameters:	ta2 - the received byte
*				card - the USIM card
*
* Return value:	None
*
* Notes:
*******************************************************************************/
static void USIMdecodeTA2(UINT8 ta2, USIM_Card card)
{
	USIM_ATRInfo * atrInfo = _USIMatrInfos + card;

	// check card's ability to change mode
	if (USIM_CHANGEABILITY_MASK & ta2)
	{
		atrInfo->modeChangeable = FALSE;
	}
	else
	{
		atrInfo->modeChangeable = TRUE;
	}

	// check which parameters would be used: indicated or default
	if (USIM_SPECIFIC_MODE_PARAM_INDICATOR_MASK & ta2)
	{ // use default values
		atrInfo->conversionFactor = USIM_DEFAULT_CONVERSION_FACTOR;
		atrInfo->adjustmentFactor = USIM_DEFAULT_ADJUSTMENT_FACTOR;
	}
	else
	{ // use indicated values:
		atrInfo->conversionFactor = atrInfo->indConversionFactor;
		atrInfo->adjustmentFactor = atrInfo->indAdjustmentFactor;
	}

	return;
} /* End of USIMdecodeTA2 */





/*******************************************************************************
* Function:		USIMdecodeClockStopAndClass
********************************************************************************
* Description:	Decodes the ATR character, which contains the clock stop and the
*				class indicators.
*
* Parameters:	receivedByte - the received byte
*				card - the USIM card
*
* Return value:	None
*
* Notes:
*******************************************************************************/
static void USIMdecodeClockStopAndClass(UINT8 receivedByte, USIM_Card card)
{
	UINT8 mask = 0x3F;

    USIM_HW_checkClock(card);

	// set the clock stop state:
	_USIMatrInfos[card].stopState = (~mask & receivedByte)>>6;

    if(_USIMatrInfos[card].stopState == USIM_CLK_STOP_LOW)
    {
        USIM_CARD_CLOCK_STOP_LEVEL_LOW(card);
    }
    else
    {
        USIM_CARD_CLOCK_STOP_LEVEL_HIGH(card);
    }
    
	// set the card classes supported:
	_USIMatrInfos[card].cardClasses = mask & receivedByte;

	return;
} /* End of USIMdecodeClockStopAndClass */



/*******************************************************************************
* Function:		USIMgetHistoricalBytes
********************************************************************************
* Description:	Copies the historical bytes from the ATR buffer to the ATRInfo
*
* Parameters:	card - the USIM card
*
* Return value:	None
*
* Notes:
*******************************************************************************/
static void USIMgetHistoricalBytes(USIM_Card card)
{
	USIM_ATRInfo * atrInfo = _USIMatrInfos + card;
	memcpy( atrInfo->historicBytes,
			_USIMatrBuffers[card] + (atrInfo->length - atrInfo->historicBytesNumber - 1),
			atrInfo->historicBytesNumber);
} /* End of USIMgetHistoricalBytes */



/*******************************************************************************
* Function:		USIMcheckATR
********************************************************************************
* Description:	checks the ATR: the result of XORing all bytes should be 0
*
* Parameters:	card - the USIM card
*
* Return value:	USIM_RC_OK
*				USIM_RC_ATR_CHECK_FAILED
*
* Notes:
*******************************************************************************/
static USIM_ReturnCode USIMcheckATR(USIM_Card card)
{
	UINT8 count;
	UINT8 result=0;
	UINT8 * atrBuffer = _USIMatrBuffers[card];

	for (count = 1; count < _USIMatrInfos[card].length; count++)
	{
		result ^= atrBuffer[count];
	}

	if (result)
	{
		return USIM_RC_ATR_CHECK_FAILED;
	}

	return USIM_RC_OK;
} /* End of USIMcheckATR */








 /******************************************************************************
 * Function     :	USIMendATR
 *******************************************************************************
 *
 * Description  :	performs the end of the ATR decoding
 *
 * Parameters   :	globalInterface - indicator for global interface bytes.
 *					N - extra guard time parameter
 *					card - the USIM card
 *
 * Return value :	USIM_RC_OK
 *					USIM_RC_ATR_ERROR
 *					USIM_RC_ATR_CHECK_FAILED
 *
 * Notes:
 ******************************************************************************/
USIM_ReturnCode USIMendATR(BOOL globalInterface, UINT8 N, USIM_Card card)
{
	USIM_ATRInfo * atrInfo = _USIMatrInfos+card;
	USIM_Protocol protocol = atrInfo->protocol;
    USIM_ReturnCode rc;

	// copy historical bytes from buffer to _ATRInfo struct:
	if (atrInfo->historicBytesNumber)
	{
		USIMgetHistoricalBytes(card);
	}

	// Check Byte:
	if ((protocol != USIM_T0) || (globalInterface))
	{
		// Check byte TCK is present:
        rc = USIMcheckATR(card);
        if ( rc != USIM_RC_OK)
        {
            return rc;
        }
    }


	// set the extra guard time HW register:
    USIMextraGuardTimeSet(N, card);

    if(_USIMstates[card] == USIM_ATR)
    {
        // set protocol:
        USIM_PROTOCOL_SET(card, protocol);

        // set the Character Waiting Time register:
        USIM_CHAR_WAIT_TIME_SET(card, protocol, (atrInfo->charWaitingTime+USIM_ADJUST_CWT_GCF));

        // set the Block Waiting Time register:
        USIM_BLOCK_WAIT_TIME_SET(card, protocol, (atrInfo->blockWaitingTime+USIM_ADJUST_BWT_GCF));

        // set the Block Guard Time Register:
        USIM_BLOCK_GUARD_TIME_SET(card, protocol);
    }
	else
	{
		if(	(protocol == USIM_T0) &&
			((atrInfo->indAdjustmentFactor == 0) || (atrInfo->indAdjustmentFactor == 1)) &&
			((atrInfo->indConversionFactor == 0) || (atrInfo->indConversionFactor == 1)))
		{
		 	   _USIMstates[card] = USIM_SPECIFIC;
		}
	}
	// set divisor last for resetting all waiting times:
	USIM_DIVISOR_SET(card, (USIM_DIVISOR_GET(card)));

	return USIM_RC_OK;
} /* end of endATR */





 /******************************************************************************
 * Function     :	USIMprotocolParametersSelect
 *******************************************************************************
 *
 * Description  :   Changes the protocol and the baud rate according to ATR.
 *
 * Parameters   :	card - the required card
 *
 * Output Param :	None
 *
 * Return value :	USIM_RC_OK
 *					USIM_RC_PPS_ERROR
 *
 * Notes:
 ******************************************************************************/
static USIM_ReturnCode USIMprotocolParametersSelect(USIM_Card card)
{
    UINT8 ppsMessage[USIM_PPS_LENGTH];          // The PPS message buffer
//USe global RX instead    UINT8 ppsResponse[USIM_PPS_LENGTH];         // The PPS response buffer
    UINT8 *ppsResponse = _USIMrxBuffers[card];         // The PPS response buffer
	USIM_ATRInfo * info = _USIMatrInfos + card;
	USIM_BaudRate baudRate;
	UINT8 FI = 0;
	UINT8 DI = 1;
	UINT8 pck = 0;
	UINT32 ppsResponseLen, ppsLen = 3; // PPSS, PPS0 and PCK
	UINT32 i, atrWwt, adjustmentFactor, conversionFactor;

    // save the  Work Waiting Time indicated in the ATR:
	atrWwt = info->workWaitingTime;
       info->workWaitingTime = USIM_DEFAULT_WORK_WAIT_TIME+ USIM_ADJUST_WWT_GCF;

	//set the PPSS byte to 0xFF
    ppsMessage[USIM_PPSS] = 0xFF;

	//set the PPS0 byte according to protocol:
    ppsMessage[USIM_PPS0] = info->protocol;
	// set T=0 protocol for the PPS negociation:
	info->protocol = USIM_T0;

	//check whether baud rate should be negotiated:
	if((info->indAdjustmentFactor)&&(info->indConversionFactor))
	{
		//set the PPS1 byte to be TA1 of the ATR
        ppsMessage[USIM_PPS1] = _USIMatrBuffers[card][USIM_PPS1];

		//indicate the presence of PPS1 in PPS0:
        ppsMessage[USIM_PPS0] |= 0x10;

		//increment the PPS length
		ppsLen++;
	}

	// set PCK:
	for (i=0; i<ppsLen-1; i++)
	{
		pck ^= ppsMessage[i];
	}
	ppsMessage[ppsLen-1] = pck;


    // send the PPS message to the card and read the card's response:
    ppsResponseLen = USIM_DL_writeRead(card, ppsLen, ppsMessage, ppsLen, NULL);

     /* Check for HW remove detected */
    if (_USIMstates[card] == USIM_REMOVED)
        return USIM_RC_CARD_REMOVED;

    if(ppsResponseLen == ppsLen)
	{
		// compare response to message:
		for(i=0; i<ppsLen; i++)
		{
			if (ppsResponse[i] != ppsMessage[i])
			{
				return USIM_RC_PPS_ERROR;
			}
		}

	    if((info->indAdjustmentFactor)&&(info->indConversionFactor))
		{
	        USIM_GET_HIGH_END_FROM_BYTE(FI, ppsMessage[USIM_PPS1]);
	        USIM_GET_LOW_END_FROM_BYTE(DI, ppsMessage[USIM_PPS1]);
		}

		// get the desired baud rate from the baud rate table:
		baudRate = _USIMbaudRateTable[DI][FI];

        if (USIM_HW_checkClock(card))
        { /* abnormal */
            return USIM_RC_GPIO_ERROR;
        }

        USIM_CARD_CLOCK_SET_RATIO(card, baudRate.ratio);
        
		USIM_FACTOR_SET(card, baudRate.factor);

		USIM_DIVISOR_SET(card, baudRate.divisor);
    }


	else if((ppsResponseLen != ppsLen - 1) ||
            (ppsResponse[USIM_PPSS]!=ppsMessage[USIM_PPSS]) ||
            ((ppsResponse[USIM_PPS0]&0x0F) != (ppsMessage[USIM_PPS0]&0x0F)) ||
            (ppsResponse[USIM_PPS0] & 0x10) ||
            (ppsResponse[ppsResponseLen-1]!=
             ppsResponse[USIM_PPSS]^ppsResponse[USIM_PPS0]))
		{
			return USIM_RC_PPS_ERROR;
		}

	// set protocol:
	info->protocol = (ppsResponse[USIM_PPS0] & 0x0F);
	USIM_PROTOCOL_SET(card, info->protocol);

	conversionFactor = USIM_CONVERSION_FACTOR_TABLE[FI];
	adjustmentFactor = USIM_ADJUSTMENT_FACTOR_TABLE[DI];

    if(info->protocol == USIM_T0)
	{
		// set the Work Waiting Time:
		info->workWaitingTime = atrWwt * adjustmentFactor+USIM_ADJUST_WWT_GCF;
	}
	else
	{
		// set the Block Waiting Time:
    	 info->blockWaitingTime = (info->blockWaitingTime * adjustmentFactor
		 						   * USIM_DEFAULT_CONVERSION_FACTOR)
								   / conversionFactor;
	}

    USIM_BLOCK_GUARD_TIME_SET(card, info->protocol);

	USIMextraGuardTimeSet(info->extraGuardTime, card);

	// set divisor last for resetting all waiting times:
	USIM_DIVISOR_SET(card, (USIM_DIVISOR_GET(card)));

	return USIM_RC_OK;
} /* end of USIMprotocolParametersSelect */





 /******************************************************************************
 * Function     :	USIManswerToReset
 *******************************************************************************
 *
 * Description  :	decodes the ATR information sent by the card upon reset
 *
 * Parameters   :	card - the required card
 *					atrLen - length of received ATR (2 - 33)
 *
 * Output Param :	None
 *
 * Return value :	USIM_RC_OK
 *					USIM_RC_ATR_ERROR
 *					USIM_RC_ATR_CHECK_FAILED
 *
 * Notes:
 ******************************************************************************/
static USIM_ReturnCode USIManswerToReset(USIM_Card card, UINT8 atrLen)
{
	UINT8 TD;					// the value of TD(i), according to protocol
	UINT8 N = 0;					// extra guard time parameter N
	UINT8 WI = USIM_DEFAULT_WI;	// work waiting time parameter WI, for T=0.
	UINT8 CWI = USIM_DEFAULT_CWI;// Character waiting time parameter CWI, for T=1.
	UINT8 BWI = USIM_DEFAULT_BWI;// Block waiting time parameter BWI, for T=1.
	UINT8 currByte; 				// the ATR byte currently looked at
	UINT8 currByteNum = 0;		// and its number
	BOOL globalInterface=FALSE;	// indicator for global interface bytes.
	USIM_ATRInfo * atrInfo = _USIMatrInfos+card;
	UINT8 * atrBuffer = _USIMatrBuffers[card];


    // change state:
    _USIMstates[card] = USIM_NEGOTIABLE;

	// update the length field in the _ATRInfo structure:
	atrInfo->length = atrLen;

	// check initial character
	currByte = atrBuffer[currByteNum];

	USIMconventionSet(currByte, card);

	USIM_CHECK_END_ATR;

    /*#35520, delete second 0x3B byte when head two byte report 0x3B */
	if(USIM_DIRECT == currByte || USIM_INVERSE == currByte)
	{
		USIM_CHECK_END_ATR;
	}
	
	// get the Format Byte:
	TD = atrBuffer[currByteNum];
	atrInfo->historicBytesNumber = TD & USIM_HISTORIC_LEN_MASK;

	USIM_CHECK_END_ATR;

	// Interface Bytes:

	// TA1:
	if (USIM_TA_MASK & TD)	//TA1 is present
	{
		USIMdecodeTA1(currByte, card);
		USIM_CHECK_END_ATR;
	}

	// TB1:
	if (USIM_TB_MASK & TD)	// TB1 is present: Vpp, Ipp - irrelevant
	{
		USIM_CHECK_END_ATR;
	}

	// TC1:
	if (USIM_TC_MASK & TD)	// TC1 is present - extra guard time
	{
		// Set the extra guard time parameter N:
		N = currByte;
		USIM_CHECK_END_ATR
	}

	// TD1:
	if (USIM_TD_MASK & TD)	// TD1 is present
	{
		TD = currByte;

		// get the transmission protocol:
		USIM_GET_LOW_END_FROM_BYTE(currByte, TD);

		if (currByte == USIM_GLOBAL_INTERFACE_BYTES)
		{
 			return 	USIM_RC_ATR_ERROR; //globalInterface = TRUE;
		}
		else
		{
			atrInfo->protocol = currByte;
		}

		USIM_CHECK_END_ATR
	}
	else
	{
		return USIMendATR(globalInterface,N, card);
	}

	// TA2
	if (USIM_TA_MASK & TD)	// TA2 is present - specific mode byte
	{
		USIMdecodeTA2(currByte, card);
        // change state:
        _USIMstates[card] = USIM_SPECIFIC;
		USIM_CHECK_END_ATR
	}

	// TB2
	if (USIM_TB_MASK & TD)	// TB2 is present - alternative voltage, irrelevant
	{
		USIM_CHECK_END_ATR
	}

	// TC2
	if (USIM_TC_MASK & TD)	// TC2 is present - Work Waiting Time
	{
		WI = currByte;
		USIM_CHECK_END_ATR
	}


	// TD2:
	if (USIM_TD_MASK & TD)	// TD2 is present
	{
		TD = currByte;

		// get the transmission protocol:
		USIM_GET_LOW_END_FROM_BYTE(currByte, TD);

		if (currByte == USIM_GLOBAL_INTERFACE_BYTES)
		{
			globalInterface = TRUE;
		}
		else
		{
			atrInfo->protocol = currByte;
		}

		USIM_CHECK_END_ATR
	}
	else
	{
		return USIMendATR(globalInterface,N, card);
	}

	// TA3:
	if (USIM_TA_MASK & TD)	// TA3 is present
	{
		if (globalInterface)
		{
			// the byte contains the clock stop and the card class info:
			USIMdecodeClockStopAndClass(currByte, card);
		}
		else
		{
			// the byte refers to the card's information field size:
			atrInfo->infoFieldSize = currByte;
		}
		USIM_CHECK_END_ATR
	}

	//TB3:
	if (USIM_TB_MASK & TD)	// TB3 is present - CWT and BWT
	{
		if (! globalInterface)
		{
			// the byte contains the CWT and the BWT:
			USIM_GET_LOW_END_FROM_BYTE(CWI, currByte);
			USIM_GET_HIGH_END_FROM_BYTE(BWI, currByte);
		}
		USIM_CHECK_END_ATR
	}


	// set the character and block waiting times:
	if (atrInfo->protocol == USIM_T0)
	{
		/* set work waiting time: */
		atrInfo->workWaitingTime = (960*WI*USIM_DEFAULT_ADJUSTMENT_FACTOR) + USIM_ADJUST_WWT_GCF;   // after PPS the adjustment factor may change.
	}

	else
	{// T1 is used:
		atrInfo->charWaitingTime =  T1_ADJUST + (0x01 << CWI);
        atrInfo->blockWaitingTime = T1_ADJUST + (0x01 << BWI) * 960 * USIM_DEFAULT_ADJUSTMENT_FACTOR;   // after PPS the adjustment factor may change.;
	}


	//TC3:
	if (USIM_TC_MASK & TD)	// TC3 is present
	{
		if (! globalInterface)
		{
			// the byte contains the error detection code:
			atrInfo->errorCode = currByte;
		}
		USIM_CHECK_END_ATR
	}


	// TD3:
	if (USIM_TD_MASK & TD)	// TD3 is present
	{
		TD = currByte;

		// get the global interface bytes indication:
		USIM_GET_LOW_END_FROM_BYTE(currByte, TD);

		if (currByte == USIM_GLOBAL_INTERFACE_BYTES)
		{
			globalInterface = TRUE;
		}

		USIM_CHECK_END_ATR
	}
	else
	{
		return USIMendATR(globalInterface,N, card);
	}

	// TA4:
	if (USIM_TA_MASK & TD)	// TA4 is present
	{
		if (globalInterface)
		{
			// the byte contains the clock stop and the card class info:
			USIMdecodeClockStopAndClass(currByte, card);
		}
		USIM_CHECK_END_ATR
	}

	// perform end of ATR decoding:
	return USIMendATR(globalInterface,N, card);

}/* End of USIManswerToReset */


#endif /* USIM_NO_ATR_PPS_DECODING */


/******************************************************************************
* Function:		USIMcardClockStart
*******************************************************************************
* Description:	Starts the card's clock
*
* Parameters:	card - the card whose clock is started
*
* Return value:	TRUE - I/O HW error
*
* Notes:
******************************************************************************/
static BOOL USIMcardClockStart(UINT32 card)
{
  if(_USIMclockStopped[card] == TRUE)
  {
    _USIMclockStopped[card] = FALSE;

    USIM_PmuClockSwitch((USIM_Card)card,TRUE); 	    /* Turn clock on */
    usim_hw_clk_onoff((USIM_Card)card, USIM_HW_CLOCK_START_REQ);

    if (USIM_HW_cardClockRequest((USIM_Card)card, USIM_HW_CLOCK_START_REQ))
    {
        _USIMclockStopped[card] = TRUE;
        return TRUE;
    }

	// wait for 744 clock cycles before sending the command:
	return (USIM_HW_Delay((USIM_Card)card, USIM_CLOCK_RESUME_DELAY_CYCLES, 1)); //INTmode doesn't work properly in D2
   }
   return FALSE ;
 }

/******************************************************************************
* Function:		USIMcardClockStop
*******************************************************************************
* Description:	Stops the card's clock
*
* Parameters:	card - the card whose clock is stopped
*
* Return value:	TRUE - I/O HW error
*
* Notes:
******************************************************************************/
static BOOL USIMcardClockStop(UINT32 card)
{
	// wait for 1860 clock cycles before stopping the clock:
    BOOL rc = USIM_HW_Delay((USIM_Card)card, USIM_CLOCK_STOP_DELAY_CYCLES, 0);

	// change the clock stopped indicator:
	_USIMclockStopped[card] =  TRUE;

	// stop the clock:
    if (USIM_HW_cardClockRequest((USIM_Card)card, USIM_HW_CLOCK_STOP_REQ))
    {
        rc = TRUE;
    }
    usim_hw_clk_onoff((USIM_Card)card, USIM_HW_CLOCK_STOP_REQ);
    if (rc)
    { /* in false case, force diag printing */
        TestUsimGetStatus((USIM_Card)card);            
    }
    return (rc);
} /* End of USIMcardClockStop */

UINT8 GetUSIMDDRLock(void)
{
	if((_USIMclockStopped[0] == FALSE) || (_USIMclockStopped[1] == FALSE))
		return 1;
	else
		return 0;
}
/******************************************************************************
* Function:		USIMcardReset
*******************************************************************************
* Description:	Resets the card
*
* Parameters:	card - the required card
*
* Return value: USIM_RC_OK
*				USIM_RC_ATR_ERROR
*				USIM_RC_PPS_ERROR
*
* Notes:
******************************************************************************/
static USIM_ReturnCode USIMcardReset(USIM_Card card)
{

	UINT8 trial;	// the number of consecutive reset trials
	UINT8 atrLen=0;	// the length of the ATR
	USIM_ReturnCode rc = USIM_RC_ATR_ERROR;
	USIM_Class voltage = _USIMuseVoltageLevel[card];
	USIM_BaudRate defaultBaudRate = _USIMbaudRateTable[1][0];



	_USIMclockStopped[card] = FALSE;
	usimClockSwitch_ttc(card,TRUE);
	USIM_PmuClockSwitch(card,TRUE);
	usim_hw_clk_onoff((USIM_Card)card, USIM_HW_CLOCK_START_REQ);
	// set protocol to be T=0:
	USIM_PROTOCOL_SET(card, USIM_DEFAULT_PROTOCOL);
	_USIMatrInfos[card].protocol = USIM_DEFAULT_PROTOCOL;
	// initialize T=1 sequence numbers:
	_USIMcardSequence[card] = 0x01;
	_USIMdeviceSequence[card] = 0x01;
	// set extra guard time:
	USIM_EXTRA_GUARD_TIME_SET(card, USIM_DEFAULT_EXTRA_GUARD_TIME);
	_USIMatrInfos[card].extraGuardTime = USIM_DEFAULT_EXTRA_GUARD_TIME;
	// set block guard time:
	USIM_BLOCK_GUARD_TIME_SET(card, USIM_T0);
	// wait for the clock register to be changed:
	USIM_HW_checkClock(card);
	// set the card clock frequency:
	USIM_CARD_CLOCK_SET_RATIO(card, defaultBaudRate.ratio);    
	// set factor:
	USIM_FACTOR_SET(card, defaultBaudRate.factor);
	// wait for the clock register to be changed:
	USIM_HW_checkClock(card);

	while((voltage != USIM_CLASS_A) && (rc != USIM_RC_OK))
	{

		for (trial=0; (trial < USIM_RESET_REPEATS) && (rc != USIM_RC_OK); trial++)
		{
		
			// init the ATR database:
			USIMATRInfoInit(card);
			// clear all interrupts:
			USIM_CLEAR_ALL(card);
			// disable all interrupts:
			USIM_DISABLE_ALL(card);
			// Reset parity error count to detect the card's coding convention
			_USIMParityErrorCnt[card] = 0;
			_USIMWTCnt[card] = USIM_DEFAULT_WORK_WAIT_TIME;
			// set ATR CWT:
			USIM_CHAR_WAIT_TIME_SET(card, USIM_T0, USIM_DEFAULT_WORK_WAIT_TIME);
			//set ATR BWT:
			USIM_BLOCK_WAIT_TIME_SET(card, USIM_T0, USIM_ATR_BWT);
			// set divisor last for resetting all waiting times:
			USIM_DIVISOR_SET(card, defaultBaudRate.divisor);
#ifdef  SS_FEATURE
			USIMHWRegisters[card]->FCR |= 0x08;
			// set the parity error trigger level:
			USIM_PARITY_ERR_LEVEL_SET(card, USIM_PARITY_ERROR_INTERRUPT_TRIGGER);
#endif
			// reset the card:
			DIAG_FILTER(USIMLOG, USIMcardReset, LOG002, DIAG_INFORMATION)
			diagPrintf("USIMcardReset %lu, trial=%lx, rc=%d, voltage=%lx", card, trial, rc, voltage); 

			USIM_HW_cardReset(card, voltage);

			// change state:
			_USIMstates[card] = USIM_ATR;
			USIM_WDT_TIMER_START(card,300);
			// Read the received ATR from the Receive FIFO into the ATR Buffer:
			atrLen = (UINT8)USIM_DL_read(card, USIM_ATR_MAX_LEN, _USIMatrBuffers[card]);

			if (_USIMstates[card] == USIM_REMOVED)
			{
				return USIM_RC_CARD_REMOVED;
			}

			if (atrLen >= USIM_ATR_MIN_LEN)
			{

				DIAG_FILTER(USIMLOG, USIMcardReset, LOG003, DIAG_INFORMATION)
				diagPrintf("USIMcardReset %lu, atrLen=%lx", card, atrLen); 


				DIAG_FILTER(USIMLOG, USIMcardReset, LOG004, DIAG_INFORMATION)
				diagStructPrintf("ATR Data:", _USIMatrBuffers[card], atrLen);
#ifdef USIM_NO_ATR_PPS_DECODING
				rc = USIM_RC_OK;
#else
				// decode ATR:
				rc = USIManswerToReset(card, atrLen);
				if(rc == USIM_RC_OK)
				{
					// compare card class
					if (voltage != (_USIMatrInfos[card].cardClasses & voltage))
					{
						rc = USIM_RC_ATR_ERROR;
						/* Try the next voltage level */
						trial = USIM_RESET_REPEATS;
						/* we can try the next voltage only if the current is
						* 1.8V and 3V is supported by the card */
						if(!((voltage == USIM_CLASS_C) &&((_USIMatrInfos[card].cardClasses & USIM_CLASS_B ) != 0 )))
							break; //exit the while loop, deactivate the card
					}
				}

#endif /* USIM_NO_ATR_PPS_DECODING */
			}
			else
			{
#ifdef  SS_FEATURE

				if ((_USIMParityErrorCnt[card] > 0 ) || (_USIMstates[card] == USIM_WDT_TIMER_EXPIRED))
				{	/* Parity error may be a result of the wrong coding convention convetion */
					UINT8  parityLen = 0;
					UINT8  eprLen = 0;
					USIM_PERR_NUM_GET(card, parityLen); //check Parity Error FIFO
					eprLen = (USIMHWRegisters[card]->LCR)&0x04L;
					// try changing the convention:
					USIM_CONVENTION_TOGGLE(card);

				}
				else
				{
					if(_USIMstates[card] != USIM_WDT_TIMER_EXPIRED)
						trial = USIM_RESET_REPEATS;
					rc = USIM_RC_ATR_ERROR;
				}

#else


				if (_USIMParityErrorCnt[card] > 0 || (_USIMErrorStat[card] & USIM_FRAMING_ERR_MASK))
				{
					DIAG_FILTER(USIMLOG, USIMcardReset, LOG005, DIAG_INFORMATION)
					diagPrintf("USIMcardReset %lu, _USIMParityErrorCnt=%lx, _USIMErrorStat[card]=%lx", card, _USIMParityErrorCnt[card], _USIMErrorStat[card]); 
					USIM_CONVENTION_TOGGLE(card);
				}
				else
				{
					DIAG_FILTER(USIMLOG, USIMcardReset, LOG006, DIAG_INFORMATION)
					diagPrintf("USIMcardReset %lu, try next voltage", card); 
					trial = USIM_RESET_REPEATS;
					rc = USIM_RC_ATR_ERROR;
				}
#endif				
			}

			if(rc != USIM_RC_OK)
			{
				DIAG_FILTER(USIMLOG, USIMcardReset, LOG007, DIAG_INFORMATION)
				diagPrintf("USIMcardReset %lu, fail, USIM_HW_deactivate", card); 				
				USIM_HW_deactivate(card, FALSE);
				/* wait for 10ms delay before reactivating: */
				OSATaskSleep(USIM_REACTIVATE_DELAY_CYCLES);
			}
		}// end for trial

		if(rc != USIM_RC_OK)
		{
			voltage >>= 1;
		}

	}//end while voltage



	if(rc != USIM_RC_OK)
	{
		
		DIAG_FILTER(USIMLOG, USIMcardReset, LOG008, DIAG_INFORMATION)
		diagPrintf("USIMcardReset %lu, fail, rc=%d", card, rc);	
		return rc;
	}



#ifdef USIM_NO_ATR_PPS_DECODING
	DIAG_FILTER(USIMLOG, USIMcardReset, LOG009, DIAG_INFORMATION)
	diagPrintf("USIMcardReset %lu, USIMControlIndication=%lx, USIMResponseNotify", card, (USIM_CLASS_TO_CTRL_IND(voltage))); 
	_USIMstates[card] = USIM_SPECIFIC;
	USIMControlIndication(card, (USIM_CLASS_TO_CTRL_IND(voltage)));
	USIMResponseNotify(card, NULL, atrLen, _USIMatrBuffers[card]);
#else

	if(_USIMstates[card] == USIM_NEGOTIABLE)
	{
		rc = USIMprotocolParametersSelect(card);
		if(rc != USIM_RC_OK)
		{
//			USIMClockStop(card);
			return rc;
		}
	}

	_USIMstates[card] = USIM_SPECIFIC;
	if(_USIMatrInfos[card].protocol == USIM_T1)
	{
		rc = USIM_DL_T1Initiate(card);
	}

#endif

	return rc;
} /* End of USIMcardReset */

static USIM_ReturnCode USIMcardReset_boot(USIM_Card card)
{

	UINT8 trial;	// the number of consecutive reset trials
	UINT8 atrLen=0;	// the length of the ATR
	USIM_ReturnCode rc = USIM_RC_ATR_ERROR;
	USIM_Class voltage = _USIMuseVoltageLevel[card];
	USIM_BaudRate defaultBaudRate = _USIMbaudRateTable[1][0];



	_USIMclockStopped[card] = FALSE;
	usimClockSwitch_ttc(card,TRUE);
	USIM_PmuClockSwitch(card,TRUE);
	usim_hw_clk_onoff((USIM_Card)card, USIM_HW_CLOCK_START_REQ);
	// set protocol to be T=0:
	USIM_PROTOCOL_SET(card, USIM_DEFAULT_PROTOCOL);
	_USIMatrInfos[card].protocol = USIM_DEFAULT_PROTOCOL;
	// initialize T=1 sequence numbers:
	_USIMcardSequence[card] = 0x01;
	_USIMdeviceSequence[card] = 0x01;
	// set extra guard time:
	USIM_EXTRA_GUARD_TIME_SET(card, USIM_DEFAULT_EXTRA_GUARD_TIME);
	_USIMatrInfos[card].extraGuardTime = USIM_DEFAULT_EXTRA_GUARD_TIME;
	// set block guard time:
	USIM_BLOCK_GUARD_TIME_SET(card, USIM_T0);
	// wait for the clock register to be changed:
	USIM_HW_checkClock(card);
	// set the card clock frequency:
	USIM_CARD_CLOCK_SET_RATIO(card, defaultBaudRate.ratio);    
	// set factor:
	USIM_FACTOR_SET(card, defaultBaudRate.factor);
	// wait for the clock register to be changed:
	USIM_HW_checkClock(card);

	while((voltage != USIM_CLASS_A) && (rc != USIM_RC_OK))
	{
		for (trial=0; (trial < USIM_RESET_REPEATS) && (rc != USIM_RC_OK); trial++)
		{
		
			// init the ATR database:
			USIMATRInfoInit(card);
			// clear all interrupts:
			USIM_CLEAR_ALL(card);
			// disable all interrupts:
			USIM_DISABLE_ALL(card);
			// Reset parity error count to detect the card's coding convention
			_USIMParityErrorCnt[card] = 0;
			_USIMWTCnt[card] = USIM_DEFAULT_WORK_WAIT_TIME;
			// set ATR CWT:
			USIM_CHAR_WAIT_TIME_SET(card, USIM_T0, USIM_DEFAULT_WORK_WAIT_TIME);
			//set ATR BWT:
			USIM_BLOCK_WAIT_TIME_SET(card, USIM_T0, USIM_ATR_BWT);
			// set divisor last for resetting all waiting times:
			USIM_DIVISOR_SET(card, defaultBaudRate.divisor);



			
			USIM_HW_cardReset(card, voltage);

			// change state:
			_USIMstates[card] = USIM_ATR;
			USIM_WDT_TIMER_START(card,300);
			// Read the received ATR from the Receive FIFO into the ATR Buffer:

			atrLen = (UINT8)USIM_DL_read(card, USIM_ATR_MAX_LEN, _USIMatrBuffers[card]);


			if (_USIMstates[card] == USIM_REMOVED)
			{
				return USIM_RC_CARD_REMOVED;
			}

			if (atrLen >= USIM_ATR_MIN_LEN)
			{
#ifdef USIM_NO_ATR_PPS_DECODING
				rc = USIM_RC_OK;
#else
				// decode ATR:
				rc = USIManswerToReset(card, atrLen);
				if(rc == USIM_RC_OK)
				{
					// compare card class
					if (voltage != (_USIMatrInfos[card].cardClasses & voltage))
					{
						rc = USIM_RC_ATR_ERROR;
						/* Try the next voltage level */
						trial = USIM_RESET_REPEATS;
						/* we can try the next voltage only if the current is
						* 1.8V and 3V is supported by the card */
						if(!((voltage == USIM_CLASS_C) &&((_USIMatrInfos[card].cardClasses & USIM_CLASS_B ) != 0 )))
							break; //exit the while loop, deactivate the card
					}
				}
				
#endif /* USIM_NO_ATR_PPS_DECODING */
			}
			else
			{
				if (_USIMParityErrorCnt[card] > 0 || (_USIMErrorStat[card] & USIM_FRAMING_ERR_MASK))
				{

					USIM_CONVENTION_TOGGLE(card);
				}
				else
				{

					trial = USIM_RESET_REPEATS;
					rc = USIM_RC_ATR_ERROR;
				}
			
			}

			if(rc != USIM_RC_OK)
			{
			
				USIM_HW_deactivate(card, FALSE);
				/* wait for 10ms delay before reactivating: */
				OSATaskSleep(USIM_REACTIVATE_DELAY_CYCLES);
			}
		}// end for trial

		if(rc != USIM_RC_OK)
		{
			voltage >>= 1;
		}

	}//end while voltage
	

	usim_boot_atr_info[card].voltage=voltage;
	usim_boot_atr_info[card].len=atrLen;
	usim_boot_atr_info[card].flag=1;


	if(rc != USIM_RC_OK)
	{
		
		DIAG_FILTER(USIMLOG, USIMcardReset, LOG008, DIAG_INFORMATION)
		diagPrintf("USIMcardReset %lu, fail, rc=%d", card, rc);	
		return rc;
	}

	_USIMstates[card] = USIM_SPECIFIC;

	return rc;
} /* End of USIMcardReset */


/******************************************************************************
* Function: USIMregistersInit
*******************************************************************************
* Description:	Initializes the USIM I/F registers
*
* Parameters:	card - the required card
*
* Return value: None
*
* Notes: called by USIMPhase1Init
******************************************************************************/
static void USIMregistersInit(USIM_Card card)
{
	USIM_BaudRate defaultBaudRate = _USIMbaudRateTable[1][0];

    USIM_PmuClockSwitch(card,TRUE); 	    /* Turn clock on */
    
	_USIMclockStopped[card] = FALSE;

 
    usim_hw_clk_onoff((USIM_Card)card, USIM_HW_CLOCK_START_REQ);

	// clear FIFOs:
	USIM_RX_CLEAR(card);
	USIM_TX_CLEAR(card);

	// disable all interrupts:
	USIM_DISABLE_ALL(card);
#ifdef  SS_FEATURE
	USIMHWRegisters[card]->FCR |= 0x08;
#endif

	// set the parity error trigger level:
	USIM_PARITY_ERR_LEVEL_SET(card, USIM_PARITY_ERROR_INTERRUPT_TRIGGER);

	// set the T=0 error trigger level:
	USIM_T0_ERR_LEVEL_SET(card, USIM_ERROR_REPEAT);

	// set protocol to be T=0:
	USIM_PROTOCOL_SET(card, USIM_DEFAULT_PROTOCOL);

	// set the coding convention:
	USIM_CONVENTION_SET(card, USIM_DEFAULT_CONVENTION);

	// set extra guard time:
	USIM_EXTRA_GUARD_TIME_SET(card, USIM_DEFAULT_EXTRA_GUARD_TIME);

	// set block guard time:
    USIM_BLOCK_GUARD_TIME_SET(card, USIM_T0);

	// set character waiting time:
	USIM_CHAR_WAIT_TIME_SET(card, USIM_T0, USIM_DEFAULT_WORK_WAIT_TIME);

	// set block waiting time:
    USIM_BLOCK_WAIT_TIME_SET(card, USIM_T0, USIM_DEFAULT_WORK_WAIT_TIME);

    USIM_HW_checkClock(card);

	// set the card clock frequency:
    USIM_CARD_CLOCK_SET_RATIO(card, defaultBaudRate.ratio);

	// set factor:
	USIM_FACTOR_SET(card, (defaultBaudRate.factor));

	// set divisor:
	USIM_DIVISOR_SET(card, (defaultBaudRate.divisor));

    // set the TX block size:
    USIM_TX_BLOCK_SET(card);

    USIM_PmuClockSwitch(card,FALSE); 	    /* Turn clock off */
    
	_USIMclockStopped[card] = TRUE;

} /* End of USIMregistersInit */




/******************************************************************************
* Function: USIMATRInfoInit
*******************************************************************************
* Description: Initializes the ATR Info structure
*
* Parameters:	card - the required card
*
* Return value: None
*
* Notes: called by USIMPhase1Init
******************************************************************************/
static void USIMATRInfoInit(USIM_Card card)
{
	USIM_ATRInfo * info = _USIMatrInfos + card;

	info->cardClock			  = (USIM_Frequency)(240 / ((_USIMbaudRateTable[1][0]).ratio));
	info->indCardClock		  = (USIM_Frequency)0;
	info->conversionFactor	  = USIM_DEFAULT_CONVERSION_FACTOR;
	info->indConversionFactor = 0;
	info->adjustmentFactor	  = USIM_DEFAULT_ADJUSTMENT_FACTOR;
	info->indAdjustmentFactor = 0;
    info->extraGuardTime      = USIM_DEFAULT_EXTRA_GUARD_TIME;
	info->modeChangeable	  = FALSE;
	info->protocol			  = USIM_DEFAULT_PROTOCOL;
	info->stopState			  = USIM_CLK_STOP_NOT_SUPPORTED;
	info->cardClasses		  = (USIM_Class)USIM_DEFAULT_AVAILABLE_CLASSES;
	info->convention		  = USIM_DEFAULT_CONVENTION;
	info->historicBytesNumber = 0;
	info->length			  = 0;
	info->infoFieldSize		  = USIM_DEFAULT_INFO_FIELD_SIZE;
	info->workWaitingTime	  = USIM_DEFAULT_WORK_WAIT_TIME + USIM_ADJUST_WWT_GCF;
	info->charWaitingTime	  = USIM_DEFAULT_CHAR_WAIT_TIME;
	info->blockWaitingTime	  = USIM_DEFAULT_BLOCK_WAIT_TIME;
	info->errorCode			  = USIM_LRC;
//    info->wdtTime             = (info->workWaitingTime * 260 + 2610) * USIM_DEFAULT_CONVERSION_FACTOR * 10 / (info->cardClock * USIM_DEFAULT_ADJUSTMENT_FACTOR)

} /* End of USIMATRInfoInit */



/******************************************************************************
* Function     :	USIMControlIndication
*******************************************************************************
*
* Description  :	Sends the control indication to the USIM Manager
*
* Parameters   :	card - the card indicated.
*					status - the card's status
*
* Return value :	None
*
* Notes:
******************************************************************************/
void USIMControlIndication (USIM_Card card, USIM_ControlStatus status)
{

	if (_USIMcontrolIndications[card] == NULL)
	{
		DIAG_FILTER(USIMLOG, USIMControlIndication, LOG001, DIAG_INFORMATION)
		diagPrintf("USIMControlIndication %u %lx, null",card, status);
		USIMClose(card); //No PS, do it here
	}
	else
	{
		DIAG_FILTER(USIMLOG, USIMControlIndication, LOG002, DIAG_INFORMATION)
		diagPrintf("USIMControlIndication %u %lx",card, status);
		(_USIMcontrolIndications[card])(status);
	}
}


/******************************************************************************
* Function     :	USIMResponseNotify
*******************************************************************************
*
* Description  :	Sends the card's response to the USIM Manager
*
* Parameters   :	card - the card which sent the data.
*					header - a pointer to the response header
* 					dataLength - length in bytes of the returned data
*					data - a pointer to the buffer which contains the data
*
* Return value :	None
*
* Notes:
******************************************************************************/
void USIMResponseNotify(USIM_Card card, USIM_ResponseHeader * header,
                                        UINT16 dataLength, UINT8 * data)
{


	if (_USIMresponseNotifies[card] != NULL)
	{

		(_USIMresponseNotifies[card])(header, dataLength, data);
	}
}/* End of USIMResponseNotify */




/*----------- Global function definition ------------------------------------*/



/******************************************************************************
* Function:		USIMClockStop
*******************************************************************************
* Description:	Stops the card's clock
*
* Parameters:	card - the card whose clock is stopped
*
* Return value:	USIM_RC_OK
*				USIM_RC_INVALID_CARD
*
* Notes:
******************************************************************************/
USIM_ReturnCode USIMClockStop(USIM_Card card)
{
	USIM_CHECK_CARD_VALID(card);
    USIM_ReturnCode rc = USIM_RC_OK;


	if((_USIMclockStopped[card] == FALSE) && (_USIMatrInfos[card].stopState != USIM_CLK_STOP_NOT_SUPPORTED))
	{
		/* stop the clock: */
        BOOL rs;
        USIM_WDT_TIMER_START(card, USIM_WDT_CLK_STOP_VAL);
            
		/* stop the clock: */
        rs = USIMcardClockStop(card);
       
        USIM_WDT_TIMER_STOP(card);
        
        USIM_PmuClockSwitch(card,FALSE); 	    /* Turn clock off */        
            
        if (rs)
            rc = USIM_RC_GPIO_ERROR;

        
	}

	return (rc);

} /* End of USIMClockStop */




#ifdef USIM_NO_ATR_PPS_DECODING

/*CQ00076401, lkrasnop, 23/11/2014, Warm Reset, begin*/
/******************************************************************************
* Function:		USIMWarmReset
*******************************************************************************
* Description:	Make warm Resets of the card
*
* Parameters:	card - the required card
*				voltageClass - the voltage to be applied to the card
*
* Return value: USIM_RC_OK
*				USIM_RC_INVALID_CARD
*				USIM_RC_ATR_ERROR
*				USIM_RC_CARD_REMOVED
*				USIM_RC_CARD_CLOSED
*
* Notes:
******************************************************************************/
USIM_ReturnCode USIMWarmReset(USIM_Card card)
{
	if (USIMcardClockStart(card))
    {
      	TestUsimGetStatus(card /*, USIM_RC_GPIO_ERROR*/);
        return USIM_RC_GPIO_ERROR;
    }

	USIM_HW_cardReset(card,  _USIMcurrentVoltageClass[card]);
	return USIM_RC_OK;
}

/*CQ00076401, lkrasnop, 23/11/2014, Warm Reset, end*/

/******************************************************************************
* Function:		USIMReset
*******************************************************************************
* Description:	Resets the card
*
* Parameters:	card - the required card
*				voltageClass - the voltage to be applied to the card
*
* Return value: USIM_RC_OK
*				USIM_RC_INVALID_CARD
*				USIM_RC_ATR_ERROR
*				USIM_RC_CARD_REMOVED
*				USIM_RC_CARD_CLOSED
*
* Notes:
******************************************************************************/
USIM_ReturnCode USIMReset(USIM_Card card, USIM_Class voltageClass)
{
    USIM_ReturnCode rc = USIM_RC_OK;
	USIM_CHECK_CARD_VALID(card);
	extern USIM_Class _USIMcurrentVoltageClass[USIM_CARDS_AMOUNT];	/*CQ00076401, lkrasnop, 23/11/2014, Warm Reset*/



	DIAG_FILTER(USIMLOG, USIMReset, LOG001, DIAG_INFORMATION)
	diagPrintf("USIMReset %u, voltageClass=%lu",card, voltageClass);

    if( _USIM_hwRemoveProgress[card]) 
    {

		DIAG_FILTER(USIMLOG, USIMReset, LOG002, DIAG_INFORMATION)
		diagPrintf("USIMReset %u, USIMClose", card);




        USIMClose(card);
        return USIM_RC_CARD_REMOVED;
    }

    // verify that registration of return functions took place:
    if (_USIMresponseNotifies[card] == NULL)
    {
		DIAG_FILTER(USIMLOG, USIMReset, LOG003, DIAG_INFORMATION)
		diagPrintf("USIMReset %u, _USIMresponseNotifies null", card);

    	return USIM_RC_NOT_REGISTERED;
    }
  
	// init the ATR database:
	USIMATRInfoInit(card);

	/*CQ00076401, lkrasnop, 23/11/2014, Warm Reset, begin*/
	if (voltageClass != USIM_CLASS_NULL)
	{	/* normal reset case */

		DIAG_FILTER(USIMLOG, USIMReset, LOG004, DIAG_INFORMATION)
		diagPrintf("USIMReset %u, Warm Reset", card);

		
    	_USIMuseVoltageLevel[card] = voltageClass;
	}
	else  /* WARM RESET request: voltageClass == USIM_CLASS_NULL */
	{	/* warm reset case ! */
        /* send USIM_CARD_DEACTIVATED to cause SIG_L1SI_CARD_REMOVED_IND send to Sim Mgr*/
		DIAG_FILTER(USIMLOG, USIMReset, LOG005, DIAG_INFORMATION)
		diagPrintf("USIMReset %u, USIMControlIndication", card);
//        USIMControlIndication(card, USIM_CARD_DEACTIVATED); //warm reset don't send remove ind

		_USIMuseVoltageLevel[card] = _USIMcurrentVoltageClass[card];

		if (_USIMuseVoltageLevel[card] == USIM_CLASS_NULL)
		{
			DIAG_FILTER(USIMLOG, USIMReset, LOG006, DIAG_INFORMATION)
			diagPrintf("USIMReset %u, _USIMuseVoltageLevel=%lu", card, _USIMuseVoltageLevel[card]);
			/* trying to use WARM reset, when we can't use it, so move to cold reset with Default Class */
			_USIMuseVoltageLevel[card] = USIM_DEFAULT_CLASS;
			voltageClass = USIM_DEFAULT_CLASS;
		}
	}
    /*CQ00076401, lkrasnop, 23/11/2014, Warm Reset, end*/
	
    if((_USIMstates[card] != USIM_SPECIFIC) && (_USIMstates[card] != USIM_WDT_TIMER_EXPIRED))
    {   /* card is closed: */
		DIAG_FILTER(USIMLOG, USIMReset, LOG007, DIAG_INFORMATION)
		diagPrintf("USIMReset %u, _USIMstates=%lx, _USIMstates=%lx", card, _USIMstates[card], _USIMstates[card]);
        rc = USIMOpen(card);
    }
    else
    {

		/*CQ00076401, lkrasnop, 23/11/2014, Warm Reset, begin*/	
		if (voltageClass != USIM_CLASS_NULL)		
		{ /* normal reset case */
		
			DIAG_FILTER(USIMLOG, USIMReset, LOG008, DIAG_INFORMATION)
			diagPrintf("USIMReset %u,voltageClass=%lx, USIM_HW_deactivate", card, voltageClass);

		
		/*CQ00076401, lkrasnop, 23/11/2014, Warm Reset, single line below was prior of change*/
        	USIM_HW_deactivate(card, FALSE); // Deactivate SIM card before any reset, in case voltage changes afterwards
		}
		/*CQ00076401, lkrasnop, 23/11/2014, Warm Reset, end*/
        OSATaskSleep(USIM_REACTIVATE_DELAY_CYCLES);
        rc = USIMcardReset(card);

		DIAG_FILTER(USIMLOG, USIMReset, LOG009, DIAG_INFORMATION)
		diagPrintf("USIMReset %u, USIMcardReset rc=%d", card, rc);


        if ( rc != USIM_RC_OK )
        {
			DIAG_FILTER(USIMLOG, USIMReset, LOG010, DIAG_INFORMATION)
			diagPrintf("USIMReset %u, USIMClose", card);
		
            USIMClose(card);
            //return rc;
        }
    }

    _USIMuseVoltageLevel[card] = USIM_DEFAULT_CLASS;

    return rc;
} /* End of USIMReset */





/******************************************************************************
* Function:		USIMPPSSend
*******************************************************************************
* Description:	Sends a PPS request to the card
*
* Parameters:	card - the required card
*				length - the number of bytes in the PPS request
*				data - the PPS request buffer
*
* Return value: USIM_RC_OK
*				USIM_RC_INVALID_CARD
*				USIM_RC_CARD_REMOVED
*				USIM_RC_CARD_CLOSED
*				USIM_RC_NULL_POINTER
*				USIM_RC_PPS_ERROR
*
* Notes:
******************************************************************************/
USIM_ReturnCode USIMPPSSend(USIM_Card card, UINT8 length, UINT8 * data)
{
	UINT32 returnedLength = 0;
    USIM_ReturnCode rc = USIM_RC_OK;

    if( (_USIM_hwRemoveProgress[card]) || (_USIMstates[card] == USIM_REMOVED))
    {
        USIMClose(card);
        return USIM_RC_CARD_REMOVED;
    }

    if (_USIMstates[card] != USIM_SPECIFIC)
    {
        return USIM_RC_CARD_CLOSED;
    }

    if (data == NULL)
    {
    	return USIM_RC_NULL_POINTER;
    }


    // change state to negotiable:
    _USIMstates[card] = USIM_NEGOTIABLE;

	/* Turn clock on */
    if (! USIMcardClockStart(card))
    {
    	/* Send the PPS request and receive the response: */
    	returnedLength = USIM_DL_writeRead (card, (UINT32)length, data,
    										(UINT32)length,
    										_USIMdataBuffers[card]);
    }
    else
    {
        rc = USIM_RC_GPIO_ERROR;
    }

     /* Check for HW remove detected */
    if ((rc == USIM_RC_OK) && (_USIMstates[card] == USIM_REMOVED))
        rc = USIM_RC_CARD_REMOVED;

    if (rc == USIM_RC_OK)
    {
        // change state to specific:
        _USIMstates[card] = USIM_SPECIFIC;

    	if(returnedLength)
    	{
    		// send the PPS response to the USIM Manager:
    		USIMResponseNotify(card, NULL, returnedLength, _USIMdataBuffers[card]);
    	}
    	else
    	{
    		rc = USIM_RC_PPS_ERROR;
    	}

            	 // give small delay for slow cards
        	OSATaskSleep(3);   //We using the task sleep instead of timerDelay to avoid stucking of the GPB bus by the timerDelay
                DIAG_FILTER(HAL, USIM,api_USIMPPSSend1, DIAG_INFORMATION)
        	diagStructPrintf("USIM API USIMPPSSend exit : ",  _USIMdataBuffers[card], returnedLength);
    }
	return rc;

} /* End of USIMPPSSend */




/******************************************************************************
* Function:		USIMConfigure
*******************************************************************************
* Description:	Configures the physical transmission parameters
*
* Parameters:	card - the required card
*				config - pointer to the configuration structure
*
* Return value: USIM_RC_OK
*				USIM_RC_INVALID_CARD
*				USIM_RC_NULL_POINTER
*
* Notes:
******************************************************************************/
#ifdef EDEN_1928
unsigned long USIM_pin_clock_status[2] = {1,1};
#endif
USIM_ReturnCode USIMConfigure(USIM_Card card, USIM_Configuration * config)
{
	USIM_ATRInfo * atrInfo = &_USIMatrInfos[card];
	USIM_BaudRate baudRate;
	UINT8 FI, DI;
	BOOL T1Init = FALSE;
    USIM_ReturnCode rc = USIM_RC_OK ;



	DIAG_FILTER(USIMLOG,USIMConfigure,LOG001,DIAG_INFORMATION)
	diagPrintf("USIMConfigure %u", card);   
	if(config == NULL)
	{
		DIAG_FILTER(USIMLOG,USIMConfigure,LOG002,DIAG_INFORMATION)
		diagPrintf("USIMConfigure %u, config null", card);	
		return USIM_RC_NULL_POINTER;
	}

    if(_USIM_hwRemoveProgress[card])
    {
		DIAG_FILTER(USIMLOG,USIMConfigure,LOG003,DIAG_INFORMATION)
		diagPrintf("USIMConfigure %u, _USIM_hwRemoveProgress, USIMClose", card);	
        USIMClose(card);
        return USIM_RC_CARD_REMOVED;
    }

	if (USIMcardClockStart(card))
	{
		DIAG_FILTER(USIMLOG,USIMConfigure,LOG004,DIAG_INFORMATION)
		diagPrintf("USIMConfigure %u, USIMcardClockStart error", card);	
        return USIM_RC_GPIO_ERROR;
	}

	/* Baud Rate parameters: */

	FI = config->clockRateFactorRef;
	DI = config->baudRateFactorRef;

	/* get the desired baud rate from the baud rate table: */
	baudRate = _USIMbaudRateTable[DI][FI];

    if ( USIM_CARD_CLOCK_GET_DIVISOR(card) != baudRate.ratio)
    {
        if (USIM_HW_checkClock(card))
        { /* abnormal */
			DIAG_FILTER(USIMLOG,USIMConfigure,LOG005,DIAG_INFORMATION)
			diagPrintf("USIMConfigure %u, USIM_HW_checkClock error", card);	
            return USIM_RC_GPIO_ERROR;
        }
        USIM_CARD_CLOCK_SET_RATIO(card, baudRate.ratio);
    }

    if(USIM_FACTOR_GET(card) != baudRate.factor)
    {
        USIM_FACTOR_SET(card, baudRate.factor);
    }

	atrInfo->cardClock =  (USIM_Frequency)(240 / ((int)baudRate.ratio));
	atrInfo->conversionFactor = USIM_CONVERSION_FACTOR_TABLE[FI];
	atrInfo->adjustmentFactor = USIM_ADJUSTMENT_FACTOR_TABLE[DI];

	/* set transmission protocol: */
	if(config->protocol == USIM_T0)
	{
        if(atrInfo->protocol != USIM_T0)
        {
            USIM_PROTOCOL_SET(card, USIM_T0);
            atrInfo->protocol = USIM_T0;
        }

    		/* set work waiting time: */
    		_USIMWTCnt[card] = config->workWaitingTime+ USIM_ADJUST_WWT_GCF;
    		atrInfo->workWaitingTime = config->workWaitingTime+ USIM_ADJUST_WWT_GCF;

            /*
             *MS->SIM max:  255 max data + 5 bytes APDU = 261 bytes 
             * SIM->MS max:  255 bytes + 2 SW1/SW2 = 258 bytes
             *
             * + BWT + 258 *CWT  ==  259*WWT  (for T=0)
             * 261*10etu */
            //atrInfo->wdtTime = ((atrInfo->workWaitingTime * 260 + 2610) * FI * 10 ) / (atrInfo->cardClock * DI);

	}

	else
	{ /* T1 used: */
        if(atrInfo->protocol != USIM_T1)
        {
            USIM_PROTOCOL_SET(card, USIM_T1);
            atrInfo->protocol = USIM_T1;
			T1Init = TRUE;
        }

            if((atrInfo->charWaitingTime+ USIM_ADJUST_CWT_GCF) != config->charWaitingTime)
            {
                /* set the Character Waiting Time register: */
                USIM_CHAR_WAIT_TIME_SET(card, USIM_T1, (config->charWaitingTime + USIM_ADJUST_CWT_GCF));
                atrInfo->charWaitingTime = config->charWaitingTime+ USIM_ADJUST_CWT_GCF;
            }

		 // Save the BWT:
    	       _USIMWTCnt[card]        = config->blockWaitingTime+ USIM_ADJUST_BWT_GCF;
             atrInfo->blockWaitingTime = config->blockWaitingTime+ USIM_ADJUST_BWT_GCF;

		/* Set the card's Information Field Size: */
		atrInfo->infoFieldSize = config->infoFieldSize;
       
        //atrInfo->wdtTime = ((atrInfo->blockWaitingTime + atrInfo->charWaitingTime * 260 + 2610) * FI * 10 ) / (atrInfo->cardClock * DI);

	}

    // set the Block Guard Time Register:
    USIM_BLOCK_GUARD_TIME_SET(card, atrInfo->protocol);


	/* set the Extra Guard Time Register: */
    USIMextraGuardTimeSet(config->extraGuardTime, card);

    if(atrInfo->stopState != config->stopState)
    {
        if (USIM_HW_checkClock(card))
        { /* abnormal */
			DIAG_FILTER(USIMLOG,USIMConfigure,LOG006,DIAG_INFORMATION)
			diagPrintf("USIMConfigure %u, USIM_HW_checkClock error", card);	
            rc = USIM_RC_GPIO_ERROR;
        }
    
        /* Set the clock stop level: */
        if(config->stopState == USIM_CLK_STOP_HIGH)
        {
#ifdef EDEN_1928
            USIM_pin_clock_status[card] = 1;
#endif        
            USIM_CARD_CLOCK_STOP_LEVEL_HIGH(card);
        }
        else
        {
#ifdef EDEN_1928
            USIM_pin_clock_status[card] = 0;
#endif        
            USIM_CARD_CLOCK_STOP_LEVEL_LOW(card);
        }
        
        atrInfo->stopState = config->stopState;
    }

	USIM_DIVISOR_SET(card, baudRate.divisor);

	if ((rc == USIM_RC_OK) && ( T1Init))
	{
	     rc = USIM_DL_T1Initiate(card);


	     if (rc != USIM_RC_OK)
	     {
            USIMClose(card);
            return rc;
	     }

        	 // give small delay for slow cards
    	OSATaskSleep(3);   //We using the task sleep instead of timerDelay to avoid stucking of the GPB bus by the timerDelay
	}
    return rc;

} /* End of USIMConfigure */


#endif /* USIM_NO_ATR_PPS_DECODING */


 /*****************************************************************************
 * Function     :	USIMATRGet    Moved to the end of file
 *                    to resolve an optimisation *.axf problem in JTAG debugger
 ******************************************************************************/

 /*****************************************************************************
 * Function     :	USIMStatusGet
 ******************************************************************************
 *
 * Description  :	Retrieves the card's status
 *
 * Parameters   :	card - the required USIM card
 *
 * Output Param :	 status - a pointer to the retrieved status structure
 *
 *
 * Return value :	USIM_RC_OK
 *					USIM_RC_INVALID_CARD
 *					USIM_RC_NULL_POINTER
 *
 * Notes:
 *****************************************************************************/
USIM_ReturnCode USIMStatusGet (USIM_Card card, USIM_Status *status )
{
 	USIM_CHECK_CARD_VALID(card);

	if(status==NULL)
	{
		return USIM_RC_NULL_POINTER;
	}

    switch ( _USIMstates[card])
    {
        case USIM_REMOVED :
            status->controlStatus = USIM_CARD_REMOVED;
            break;

        case USIM_INACTIVE :
            status->controlStatus = USIM_CARD_DEACTIVATED;
            break;

        default :
            status->controlStatus = USIM_CARD_ACTIVATED;
    }

	USIMcardClockStart(card);


	if(USIM_IS_RX_ACTIVE(card))
	{
		status->activeReceiver = TRUE;
	}
	else
	{
		status->activeReceiver = FALSE;
	}

	if(USIM_IS_TX_ACTIVE(card))
	{
		status->activeTransmitter = TRUE;
	}
	else
	{
		status->activeTransmitter = FALSE;
	}

	return USIM_RC_OK;

}/* End of USIMStatusGet */



 /*****************************************************************************
 * Function     :	USIMCommandSend
 ******************************************************************************
 *
 * Description  :	Sends commands (C-APDU) from the USIM Manager to the card
 *
 * Parameters   :	card - the required USIM card
 *					header - a command header structure, as defined above
 *					data - a pointer to the data sent, or NULL if no data
 *
 * Output Param :	None
 *
 * Return value :	USIM_RC_OK
 *					USIM_RC_INVALID_CARD
 *                  USIM_RC_CARD_REMOVED
 *                  USIM_RC_CARD_CLOSED
 *                  USIM_RC_CARD_BUSY
 *					USIM_RC_NULL_POINTER
 *                  USIM_RC_INVALID_DATA_LENGTH
 *
 * Notes:           This service is blocking! It returns after the card's
 *                  response has been received.
 *****************************************************************************/


USIM_ReturnCode USIMCommandSend (USIM_Card card, USIM_CommandHeader * header,
								 UINT8 * data)
{
    USIM_ReturnCode rc=USIM_RC_OK;

		DIAG_FILTER(USIMLOG, USIMCommandSend, LOG001, DIAG_INFORMATION)
        diagStructPrintf("USIMCommandSend: %S{USIM_CommandHeader} ", header, sizeof(USIM_CommandHeader));


    if(( _USIM_hwRemoveProgress[card]) ||  (_USIMstates[card] == USIM_REMOVED))
    {

		DIAG_FILTER(USIMLOG,USIMCommandSend,LOG003,DIAG_INFORMATION)
		diagPrintf("USIMCommandSend %u, _USIM_hwRemoveProgress=%lx, _USIMstates=%lx", card, _USIM_hwRemoveProgress[card], _USIMstates[card]);   
        rc = USIM_RC_CARD_REMOVED;
    }
    else if (_USIMstates[card] != USIM_SPECIFIC)
    { /* if we are here race conditions happened  */
        
        /* send USIM_CARD_DEACTIVATED to cause SIG_L1SI_CARD_REMOVED_IND send to Sim Mgr*/
		//CQ00006140
        //USIMControlIndication(card, USIM_CARD_DEACTIVATED);           
        if (USIM_DL_CheckFlagSetState( card, 0) )
        {  

			/*coverity[returned_value]*/
            rc = USIM_DL_Check_States(card);
        }
		DIAG_FILTER(USIMLOG,USIMCommandSend,LOG004,DIAG_INFORMATION)
		diagPrintf("USIMCommandSend %u, rc=%d", card, rc);   
        rc = USIM_RC_CARD_CLOSED;
    }    
    else if (_USIMDLstates[card] != USIM_IDLE)
    {
		DIAG_FILTER(USIMLOG,USIMCommandSend,LOG005,DIAG_INFORMATION)
		diagPrintf("USIMCommandSend %u, _USIMDLstates=%lx", card, _USIMDLstates[card]);   
        rc = USIM_RC_CARD_BUSY;
    }

    else if(header == NULL)
	{
		DIAG_FILTER(USIMLOG,USIMCommandSend,LOG006,DIAG_INFORMATION)
		diagPrintf("USIMCommandSend %u, header null", card);   
		rc =USIM_RC_NULL_POINTER;
	}

    else if ((header->dataLength > 255) || (header->expectDataLength > 256))
    {

		DIAG_FILTER(USIMLOG,USIMCommandSend,LOG007,DIAG_INFORMATION)
		diagPrintf("USIMCommandSend %u, dataLength=%lu, expectDataLength=%lu", card, header->dataLength, header->expectDataLength);  
		
        rc = USIM_RC_INVALID_DATA_LENGTH;
    }


    if (rc != USIM_RC_OK)
    {
		DIAG_FILTER(USIMLOG,USIMCommandSend,LOG008,DIAG_INFORMATION)
		diagPrintf("USIMCommandSend %u, rc=%d", card, rc);  
      	TestUsimGetStatus(card);
        return (rc);
    }

    // set the data buffer size to 0:
    _USIMdataBufferSize[card] = 0; 
    _USIMresponseHeaders[card].status1 = 0;
    _USIMresponseHeaders[card].status2 = 0;

	// copy header to header buffer:
	_USIMcommandHeaders[card] = *header;

	if (header->dataLength)
	{
		// copy data to data buffer:
		memcpy(_USIMdataBuffers[card], data, header->dataLength);
	}


#ifdef USIM_USE_CLOCK_STOP_TIMER

    if(_USIMisClockStopUsed[card] == TRUE)
    {
        OSATimerStop(_USIMtimerRefs[card]);
    }
#endif /* USIM_USE_CLOCK_STOP_TIMER */

    /* we don't need WDT below, since USIM HW interface is not used for TimerDelay HERE
    USIM_WDT_TIMER_START(card, USIM_WDT_CLK_START_VAL);
    */

	if (USIMcardClockStart(card))
    {   
      	TestUsimGetStatus(card);
        //USIM_WDT_TIMER_STOP(card);
		DIAG_FILTER(USIMLOG,USIMCommandSend,LOG009,DIAG_INFORMATION)
		diagPrintf("USIMCommandSend %u, USIMcardClockStart fail", card); 
        return USIM_RC_GPIO_ERROR;
    }
    //USIM_WDT_TIMER_STOP(card);
    
    // check which protocol is used, and send command:
    if(_USIMatrInfos[card].protocol == USIM_T0)
    {



        rc = USIMTransportT0CommandSend(card);
    }
    else
    {
        rc = USIMTransportT1CommandSend(card);
    }

    if(rc == USIM_RC_OK)
    {
    	
        if(_USIMdataBufferSize[card])
        {

			DIAG_FILTER(USIMLOG,USIMCommandSend,LOG010,DIAG_INFORMATION)
			diagPrintf("USIMCommandSend %u, _USIMdataBufferSize=%lu", card,  _USIMdataBufferSize[card]); 

			USIMResponseNotify(card, &(_USIMresponseHeaders[card]), _USIMdataBufferSize[card], _USIMdataBuffers[card]);
        }
        else
        {
			DIAG_FILTER(USIMLOG,USIMCommandSend,LOG011,DIAG_INFORMATION)
			diagPrintf("USIMCommandSend %u, _USIMdataBufferSize=%lu", card,  _USIMdataBufferSize[card]); 


			USIMResponseNotify(card, &(_USIMresponseHeaders[card]), 0, NULL);
        }



    }
   else
   {
	   DIAG_FILTER(USIMLOG,USIMCommandSend,LOG012,DIAG_INFORMATION)
	   diagPrintf("USIMCommandSend %u, rc=%d", card, rc); 

		
      	TestUsimGetStatus(card);
	    /* CQ00065401 tc TC 7.2.1 c-3 */
        // USIM is removed or not answer - this is abnormal
		//CQ00006140
	    //USIMClose (card);
		USIM_HW_deactivate(card, TRUE);
		
        return rc;  
    }


    _USIMdataBufferSize[card] = 0;

#ifdef USIM_USE_CLOCK_STOP_TIMER
    if(_USIMisClockStopUsed[card] == TRUE)
    {
      OSATimerStart(_USIMtimerRefs[card], USIM_CLK_STOP_INTERVAL, 0, USIMClockStop, (UINT32)card);
    }
#endif /* USIM_USE_CLOCK_STOP_TIMER */

#if defined USIM_STOP_CLOCK_AFTER_EVERY_COMMAND

    USIM_WDT_TIMER_START(card, USIM_WDT_CLK_STOP_VAL);
	/* stop the clock: */
	if (USIMcardClockStop(card))
        rc = USIM_RC_GPIO_ERROR;
    USIM_WDT_TIMER_STOP(card);
    USIM_PmuClockSwitch(card,FALSE); 	    /* Turn clock off */    
    if (rc != USIM_RC_OK)
    {
        TestUsimGetStatus(card);
    }
#endif /* USIM_STOP_CLOCK_AFTER_EVERY_COMMAND */

    return (rc);

}/* End of USIMCommandSend */






/******************************************************************************
* Function: USIMClose
*******************************************************************************
* Description: Deactivates a card (see the opposite USIMOpen)
*
* Parameters: card - the card to be closed.
*
* Return value: USIM_RC_OK
*				USIM_RC_INVALID_CARD
*
* Notes: Refer also USIMClose, USIMOsDeactivate
******************************************************************************/


UINT32 usim_close_ind_flag[2]={1,1};

void enable_usim_close_ind(USIM_Card card)
{
	usim_close_ind_flag[card]=1;
}


void disable_usim_close_ind(USIM_Card card)
{
	usim_close_ind_flag[card]=0;
}




USIM_ReturnCode USIMClose(USIM_Card card)
{
	UINT32 cpsr;



	DIAG_FILTER(USIMLOG,USIMClose,LOG001,DIAG_INFORMATION)
	diagPrintf("USIMClose %u, _USIM_hwRemoveProgress=%lx, _USIMstates=%lx, _USIMDLstates=%lx", card, _USIM_hwRemoveProgress[card], _USIMstates[card], _USIMDLstates[card]);   


	USIM_CHECK_CARD_VALID(card);


	INTCDisable(_USIMinterruptSources[card]);

	cpsr = disableInterrupts();

	if((!_USIM_hwRemoveProgress[card])  &&(_USIMstates[card] != USIM_INACTIVE) && (_USIMDLstates[card] != USIM_REMOVED))
	{
		_USIM_hwRemoveProgress[card] = TRUE;

		_USIMDLstates[card] = USIM_REMOVED; /* this will protect aginst several USIMClose */

		if (_USIMstates[card] != USIM_REMOVED)
			_USIMstates[card] = USIM_INACTIVE; 
		restoreInterrupts(cpsr);

		if(_USIMclockStopped[card] == TRUE)
		{
			USIM_PmuClockSwitch(card,TRUE);
			usim_hw_clk_onoff((USIM_Card)card, USIM_HW_CLOCK_START_REQ);               
		}
		USIM_HW_deactivate(card, TRUE);
		USIM_PmuClockSwitch(card,FALSE); 	    /* Turn clock off */
		_USIMclockStopped[card] = TRUE;

		if(usim_close_ind_flag[card]==1)
		{
			DIAG_FILTER(USIMLOG, USIMClose, LOG002, DIAG_INFORMATION)
			diagPrintf("USIMClose %lu send USIM_CARD_DEACTIVATED ind",card);	
		
			USIMControlIndication(card, USIM_CARD_DEACTIVATED);
		}
		else
		{
			DIAG_FILTER(USIMLOG, USIMClose, LOG003, DIAG_INFORMATION)
			diagPrintf("USIMClose %lu not send USIM_CARD_DEACTIVATED ind",card);	

		}
		
		_USIM_hwRemoveProgress[card] = FALSE;

	}
	else
	{
		restoreInterrupts(cpsr);
		USIM_DL_CheckFlagSetState( card, 0); /* USIM_INACTIVE  --> USIM_REMOVED */
	}

	USIM_WDT_TIMER_STOP(card);
	return USIM_RC_OK;
} /* End of USIMClose   */


USIM_ReturnCode USIMClose_boot(USIM_Card card)
{
	UINT32 cpsr;


	INTCDisable(_USIMinterruptSources[card]);

	cpsr = disableInterrupts();

	if((!_USIM_hwRemoveProgress[card])  &&(_USIMstates[card] != USIM_INACTIVE) && (_USIMDLstates[card] != USIM_REMOVED))
	{
		_USIM_hwRemoveProgress[card] = TRUE;

		_USIMDLstates[card] = USIM_REMOVED; /* this will protect aginst several USIMClose */

		if (_USIMstates[card] != USIM_REMOVED)
			_USIMstates[card] = USIM_INACTIVE; 
		restoreInterrupts(cpsr);

		if(_USIMclockStopped[card] == TRUE)
		{
			USIM_PmuClockSwitch(card,TRUE);
			usim_hw_clk_onoff((USIM_Card)card, USIM_HW_CLOCK_START_REQ);               
		}
		USIM_HW_deactivate(card, TRUE);
		USIM_PmuClockSwitch(card,FALSE); 	    /* Turn clock off */
		_USIMclockStopped[card] = TRUE;

		
		_USIM_hwRemoveProgress[card] = FALSE;

	}
	else
	{
		restoreInterrupts(cpsr);
		USIM_DL_CheckFlagSetState( card, 0); /* USIM_INACTIVE  --> USIM_REMOVED */
	}

	USIM_WDT_TIMER_STOP(card);
	return USIM_RC_OK;
} /* End of USIMClose   */





/******************************************************************************
* Function: USIMOpen
*******************************************************************************
* Description:	Opens a card for usage.
*
* Parameters:	card - the card to be opened
*
* Return value:	USIM_RC_OK
*				USIM_RC_INVALID_CARD
*				USIM_RC_NOT_REGISTERED
*				USIM_RC_CARD_REMOVED
*				USIM_RC_CARD_ALREADY_OPEN
*				USIM_RC_ATR_ERROR
*				USIM_RC_PPS_ERROR
*				USIM_RC_OSA_ERROR
*
* Notes:
******************************************************************************/
USIM_ReturnCode USIMOpen(USIM_Card card)
{
	UINT32 flags;
	USIM_ReturnCode rc=USIM_RC_OK;



	DIAG_FILTER(USIMLOG, USIMOpen, LOG001, DIAG_INFORMATION)
	diagPrintf("USIMOpen %lu", card);

#ifdef USIM_OP_FOR_SGIT

	if(getMasterSimID()!=card)
	{
		USIMControlIndication(card, USIM_CARD_DEACTIVATED);
		rc=USIM_RC_ATR_ERROR;
		return rc;

	}

#endif
	
	if((_USIMstates[card] != USIM_INACTIVE) && (_USIMstates[card] != USIM_REMOVED))
	{
		DIAG_FILTER(USIMLOG, USIMOpen, LOG004, DIAG_INFORMATION)
		diagPrintf("USIMOpen %lu, _USIMstates=%lx", card, _USIMstates[card]);	
		ASSERT(0);
	}

	_USIMstates[card] = USIM_INACTIVE;
	USIMSetResponseReadFlag(card, 1);/* default value: 1  SIM DRIVER supports get response */

	INTCEnable(_USIMinterruptSources[card]);


	rc = USIMcardReset(card);

		DIAG_FILTER(USIMLOG, USIMOpen, LOG006, DIAG_INFORMATION)
		diagPrintf("USIMOpen %lu, USIMcardReset=%d", card, rc);		


	if (rc == USIM_RC_OK) 
	{



	
#ifdef USIM_USE_CLOCK_STOP_TIMER
		if ( ((_USIMatrInfos[card]).stopState == USIM_CLK_STOP_NOT_SUPPORTED) || (OSATimerStart(_USIMtimerRefs[card], USIM_CLK_STOP_INTERVAL, 0, USIMClockStop, (UINT32)card) != OS_SUCCESS))
		{
			_USIMisClockStopUsed[card] = FALSE;
		}
		else
		{
			_USIMisClockStopUsed[card] = TRUE;
		}

#endif
	}
	else
	{

		DIAG_FILTER(USIMLOG, USIMOpen, LOG007, DIAG_INFORMATION)
		diagPrintf("USIMOpen %lu, fail, rc=%d", card, rc);	
	
		USIMClose(card);        
	}
	return rc;
} /* End of USIMOpen   */

USIM_ReturnCode USIMOpen_boot(USIM_Card card)
{
	UINT32 flags;
	USIM_ReturnCode rc=USIM_RC_OK;

	USIMSetResponseReadFlag(card, 1);/* default value: 1  SIM DRIVER supports get response */

	_USIMstates[card] = USIM_INACTIVE;

	INTCEnable(_USIMinterruptSources[card]);

	rc = USIMcardReset_boot(card);

	if (rc == USIM_RC_OK) 
	{
	
#ifdef USIM_USE_CLOCK_STOP_TIMER
		if ( ((_USIMatrInfos[card]).stopState == USIM_CLK_STOP_NOT_SUPPORTED) || (OSATimerStart(_USIMtimerRefs[card], USIM_CLK_STOP_INTERVAL, 0, USIMClockStop, (UINT32)card) != OS_SUCCESS))
		{
			_USIMisClockStopUsed[card] = FALSE;
		}
		else
		{
			_USIMisClockStopUsed[card] = TRUE;
		}

#endif
	}
	else
	{
		USIMClose_boot(card); 
	}
	return rc;
} /* End of USIMOpen   */


USIM_ReturnCode USIMOpen_first(USIM_Card card)
{
	UINT32 flags;
	USIM_ReturnCode rc=USIM_RC_OK;


#ifdef USIM_OP_FOR_SGIT

	if(getMasterSimID()!=card)
	{
		USIMControlIndication(card, USIM_CARD_DEACTIVATED);
		rc=USIM_RC_ATR_ERROR;
		return rc;

	}

#endif
	

	while(usim_boot_atr_info[card].flag==0)
		OSATaskSleep(1);


	if(usim_boot_atr_info[card].len==0)
	{
		
		rc=USIM_RC_ATR_ERROR;
		USIMControlIndication(card, USIM_CARD_DEACTIVATED);
	}
	else
	{
		

		rc=USIM_RC_OK;
		USIMControlIndication(card, (USIM_CLASS_TO_CTRL_IND(usim_boot_atr_info[card].voltage)));
		USIMResponseNotify(card, NULL, usim_boot_atr_info[card].len, _USIMatrBuffers[card]);

	}

	return rc;
} /* End of USIMOpen   */


/******************************************************************************
* Function: USIMUnRegister
*******************************************************************************
* Description:	Unbinds the return functions associated with the card.
*
* Parameters:	card - the card from which the functions would be unbound.
*
* Return value:	USIM_RC_OK
*				USIM_RC_INVALID_CARD
*
* Notes:
******************************************************************************/
USIM_ReturnCode USIMUnRegister (USIM_Card card)
{
    _USIMstates[card] = USIM_INACTIVE;

	return USIM_RC_OK;

} /* End of USIMUnRegister   */





/******************************************************************************
* Function: USIMRegister
*******************************************************************************
* Description:	Binds the given functions: responseFunc would be called when
*				the card returns a response for a command; ctrlFunc is called
*				for indicaing that the card's state has changed.
*
* Parameters:	card - the card to which the functions would be registered.
*				responseFunc - a pointer to a return function, which notifies
*							   the USIM Manager of the card's response to a
*							   command.
*				ctrlFunc - a pointer to a return function, which indicates card
*						   state changes.
*
* Return value:	USIM_RC_OK
*				USIM_RC_INVALID_CARD
*				USIM_RC_NULL_POINTER
*				USIM_RC_ALREADY_BOUND
*
* Notes:
******************************************************************************/
USIM_ReturnCode USIMRegister(USIM_Card card,
							 USIM_CardResponseNotify responseFunc,
							 USIM_ControlIndication ctrlFunc)
{




	_USIMresponseNotifies[card] = responseFunc;
	_USIMcontrolIndications[card] = ctrlFunc;

	return USIM_RC_OK;

} /* End of USIMRegister  */


extern void usim_bind_callback (void);

//20230612 sim hot plug open for M2 falsh.
#if QUEC_ASR_SIM_HOT_PLUG_SUPPORT
//evin 20210616 fix EC600N hot plug pin error.
UINT32 usim_1_detect_gpio = QUEC_USIM_DET_PIN;
static UINT32 usim_1_detect_gpio_insert_level = 0;
UINT32 usim_1_debounce_time = 100;

//evin 20210616 fix EC600N sim2 not support hot plug.
//#elif QUEC_USIM2_EC200N_DET_SUPPORT
UINT32 usim_2_detect_gpio = QUEC_USIM2_DET_PIN;
UINT32 usim_2_detect_gpio_insert_level = 0;
UINT32 usim_2_debounce_time = 100;

//To optimize +CPIN: NOT READY report. 0-default, 1-set cfun0 when insert, 2-set cfun0 when remove
static char cfun0_flag = 0;
void quec_set_cfun0_flag(char flag)
{
	cfun0_flag = flag;
}
char quec_get_cfun0_flag(void)
{
	return cfun0_flag;
}

#else

UINT32 usim_1_detect_gpio=GPIO_MAX_AMOUNT_OF_PINS;
UINT32 usim_1_detect_gpio_insert_level=1;
UINT32 usim_1_debounce_time=100;

UINT32 usim_2_detect_gpio=GPIO_MAX_AMOUNT_OF_PINS;
UINT32 usim_2_detect_gpio_insert_level=1;
UINT32 usim_2_debounce_time=100;


#endif

void USIMResourceInit(void)
{
	USIM_Card card;
#ifdef QUEC_OEM_VER_SIMB //usim2相关引脚初始化成gpio,并且关闭所在的ldo8电压域,防止后续继续操作引起跳变
	extern void GuilinLite_Ldo_8_set(BOOL OnOff);
	GuilinLite_Ldo_8_set(0);
	*(volatile unsigned long *)0xD401E260 |= 0x1;
	*(volatile unsigned long *)0xD401E264 |= 0x1;
	*(volatile unsigned long *)0xD401E268 |= 0x1;
#endif
	OS_Create_HISR(&_USIMhisrRefs[0], "USIMsisrComCard", USIMsisrComCard, HISR_PRIORITY_0);

	ASSERT(OSAFlagCreate(&_USIMflagsRefs[USIM_COM_CARD]) == OS_SUCCESS);

#ifdef USIM_USE_CLOCK_STOP_TIMER
	ASSERT(OSATimerCreate(&_USIMtimerRefs[USIM_COM_CARD]) != OS_SUCCESS);
#endif

#ifdef USIM_USE_SW_WDT_TIMER
	ASSERT(OSATimerCreate(&_USIMtimerRefsWdt[USIM_COM_CARD]) == OS_SUCCESS);
#endif

#ifdef USIM_DSDS_DKB

	OS_Create_HISR(&_USIMhisrRefs[1], "USIMsisrBankingCard", USIMsisrBankingCard, HISR_PRIORITY_0);

	ASSERT(OSAFlagCreate(&_USIMflagsRefs[USIM_BANKING_CARD]) == OS_SUCCESS);

#ifdef USIM_USE_CLOCK_STOP_TIMER
	ASSERT(OSATimerCreate(&_USIMtimerRefs[USIM_BANKING_CARD]) != OS_SUCCESS);
#endif

#ifdef USIM_USE_SW_WDT_TIMER
	ASSERT(OSATimerCreate(&_USIMtimerRefsWdt[USIM_BANKING_CARD]) == OS_SUCCESS);
#endif

#endif

	usim_bind_callback();

}


/******************************************************************************
* Function: USIMPhase2Init
*******************************************************************************
* Description: Initializes database
*
* Parameters:
*
* Return value: USIM_RC_OK
*				USIM_RC_INTC_ERROR
*
* Notes:
******************************************************************************/
extern void USIMD2rmD2Register(void);
extern void Set_R13_EEH(UINT32 ptr);

void eeh_set_stack(void)
{

	UINT8* ptr;

	extern UINT8 IpNetNodePool[];

	ptr=(UINT8*)IpNetNodePool;
	memset(ptr,0xAA,4096);
	Set_R13_EEH(((UINT32)ptr)+4096);
}

void usim_disable_io_drive_up(void)
{

	UINT32 addr;
	UINT32 reg;


	if (CHIP_IS_CRANEG || CHIP_IS_CRANEM || CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR)
	{

		addr=USIM_0_HW_ADDRESS+0x48;
		reg=*(volatile UINT32*)addr;
		reg|=0x1;
		*(volatile UINT32*)addr=reg;
		

		addr=USIM_1_HW_ADDRESS+0x48;
		reg=*(volatile UINT32*)addr;
		reg|=0x1;
		*(volatile UINT32*)addr=reg;
		
	}

	
	
}


void usim_boot_init (USIM_Card card)
{
    USIM_ReturnCode result;

    usim_state_init(card);

    result = USIMOpen_boot (card);

}


UINT8* usim_0_fast_boot_task_stack;
UINT8* usim_1_fast_boot_task_stack;

OSATaskRef	usim_0_fast_boot_task_ref=NULL;
OSATaskRef	usim_1_fast_boot_task_ref=NULL;


VOID usim_0_fast_boot_task(VOID *argv)
{
	usim_boot_init(USIM_COM_CARD);
}

#ifdef USIM_DSDS_DKB
VOID usim_1_fast_boot_task(VOID *argv)
{
	usim_boot_init(USIM_BANKING_CARD);
}
#endif

void usim_fast_boot_task_init(void)
{

	OS_STATUS   status;

	memset(usim_boot_atr_info, 0, sizeof(usim_boot_atr_info));

	usim_0_fast_boot_task_stack=(UINT8*)malloc(2048);
	status = OSATaskCreate(&usim_0_fast_boot_task_ref, usim_0_fast_boot_task_stack, 2048, 39, "Usim0FaT", usim_0_fast_boot_task, NULL);
	ASSERT(status == OS_SUCCESS);
#ifdef USIM_DSDS_DKB

	usim_1_fast_boot_task_stack=(UINT8*)malloc(2048);
	status = OSATaskCreate(&usim_1_fast_boot_task_ref, usim_1_fast_boot_task_stack, 2048, 39, "Usim1FaT", usim_1_fast_boot_task, NULL);
	ASSERT(status == OS_SUCCESS);
#endif
}


void usim_fast_boot_task_del(void)
{
	OS_STATUS   status;
		
#ifdef USIM_DSDS_DKB
	while((usim_boot_atr_info[0].flag==0)||(usim_boot_atr_info[1].flag==0))
#else		
	while(usim_boot_atr_info[0].flag==0)
#endif		
		OSATaskSleep(1);

	status = OSATaskDelete(usim_0_fast_boot_task_ref);
	ASSERT(status == OS_SUCCESS);
	free(usim_0_fast_boot_task_stack);

#ifdef USIM_DSDS_DKB
	status = OSATaskDelete(usim_1_fast_boot_task_ref);
	ASSERT(status == OS_SUCCESS);
	free(usim_1_fast_boot_task_stack);
#endif
}



USIM_ReturnCode USIMPhase2Init(void)
{
    USIM_Card card;

	static UINT8 usim_fast_boot_init_flag=0;
	static UINT8 usim_int_init_flag=0;
	extern UINT32 read_usim_swap_flag(void);

	usim_swap_flag=read_usim_swap_flag();

	RTI_LOG("USIMPhase2Init %d\r\n", usim_swap_flag);

	for (card = (USIM_Card)0; card < USIM_CARDS_AMOUNT; card++)
	{

		USIMATRInfoInit(card);

		_USIMrxBuffers[card]  = _USIMrxBuf[card];
		_USIMtxBuffers[card]  = _USIMtxBuf[card];
		_USIMdataBuffers[card]= _USIMdataBuf[card];


        // set the rx buffer pointers to the beginning of the buffer:
        _USIMrxBufferPtrs[card] = _USIMrxBuffers[card];

        // Reset the number of bytes expected from card:
        _USIMexpectedLen[card] = 0;

        // set the tx buffer pointers to the beginning of the buffer:
        _USIMtxBufferPtrs[card] = _USIMtxBuffers[card];

        // reset the size of tx buffers:
        _USIMtxBufferSize[card] = 0;

        // reset the data buffer valid bytes number:
        _USIMdataBufferSize[card] = 0;

        // initialize clock stop indicators:
        _USIMclockStopped[card] = TRUE;

        // initialize DL states:
        _USIMDLstates[card] = USIM_IDLE;

		_USIMstates[card] = USIM_REMOVED;
        // initialize T=1 sequence numbers:
        _USIMcardSequence[card] = 0x01;
        _USIMdeviceSequence[card] = 0x01;

        _USIMisClockStopUsed[card] = FALSE;

        _USIMuseVoltageLevel[card] = USIM_DEFAULT_CLASS;
        _USIMisDelaySet[card] = FALSE;

        _USIMParityErrorCnt[card] = 0;

        _USIMWTCnt[card] = USIM_DEFAULT_WORK_WAIT_TIME;


#if defined(USIM_PMC_LDO_ENABLED_ON_BOOT)
         _SIMFirstTimePowered[card] = TRUE;
#endif
         _USIM_hwRemoveProgress[card] = FALSE;


//         _USIMtimerRefs[card] = NULL;
         
#if defined (USIM_USE_SW_WDT_TIMER)
//         _USIMtimerRefsWdt[card] = NULL;
         _USIMtimerWDTactive[card] = FALSE;
         _USIMtimerWDTval[card] = 0xFFFFFFF;
#endif

         //_USIMhisrRefs[currCard] = NULL;
         _USIMinterruptStatus[card] = 0;



		_USIMcurrentVoltageClass[card] = USIM_CLASS_NULL;

    }



	if(usim_int_init_flag==1)
	{
		INTCDisable(_USIMinterruptSources[USIM_COM_CARD]);
		ASSERT(INTCUnbind (_USIMinterruptSources[USIM_COM_CARD]) == INTC_RC_OK);

#ifdef USIM_DSDS_DKB
		INTCDisable(_USIMinterruptSources[USIM_BANKING_CARD]);
		ASSERT(INTCUnbind (_USIMinterruptSources[USIM_BANKING_CARD]) == INTC_RC_OK);
#endif		
	}

	usim_int_init_flag=1;

	if(usim_swap_flag == 0)
	{
		USIMHWRegisters[0] = (volatile struct USIMController *)USIM_0_HW_ADDRESS;
		_USIMinterruptSources[0] = INTC_SRC_USIM1;


		USIMHWRegisters[1] = (volatile struct USIMController *)USIM_1_HW_ADDRESS;
		_USIMinterruptSources[1] = INTC_SRC_USIM2;


	}
	else
	{

		USIMHWRegisters[0] = (volatile struct USIMController *)USIM_1_HW_ADDRESS;
		_USIMinterruptSources[0] = INTC_SRC_USIM2;
		
		USIMHWRegisters[1] = (volatile struct USIMController *)USIM_0_HW_ADDRESS;
		_USIMinterruptSources[1] = INTC_SRC_USIM1;

	}

	USIMregistersInit((USIM_Card)0);
	ASSERT(INTCConfigure(_USIMinterruptSources[0], INTC_IRQ, INTC_HIGH_LEVEL) == INTC_RC_OK);
	ASSERT(INTCBind(_USIMinterruptSources[0], USIMhandler_1) == INTC_RC_OK);
	USIMregistersInit((USIM_Card)1);

#ifdef USIM_DSDS_DKB
	ASSERT(INTCConfigure(_USIMinterruptSources[1], INTC_IRQ, INTC_HIGH_LEVEL) == INTC_RC_OK);
	ASSERT(INTCBind(_USIMinterruptSources[1], USIMhandler_2) == INTC_RC_OK)	;
#endif

	USIMD2rmD2Register() ;

	usim_disable_io_drive_up();


	if(usim_fast_boot_init_flag==0)
	{
		usim_fast_boot_task_init();
		usim_fast_boot_init_flag=1;
	}

    return USIM_RC_OK;

} /* End of USIMPhase2Init   */


void set_usim_swap_flag(UINT32 val)
{
	extern void save_usim_swap_flag(UINT32 val);
	save_usim_swap_flag(val);
	USIMPhase2Init();
}

UINT32 get_usim_swap_flag(void)
{	
	uart_printf("get_usim_swap_flag %d\r\n", usim_swap_flag);
	
	return usim_swap_flag;
}


void disable_usim_swap(void)
{
	RTI_LOG("disable_usim_swap\r\n");
	set_usim_swap_flag(0);
}



void enable_usim_swap(void)
{
	RTI_LOG("enable_usim_swap\r\n");
	set_usim_swap_flag(1);
}


extern BOOL   GLFeatureFlag;

char _USIMDLstates_string[][32]=
{
	"USIM_REMOVED",
	"USIM_INACTIVE",
	"USIM_ATR"
	"USIM_NEGOTIABLE",
	"USIM_SPECIFIC",

	"USIM_IDLE",
	"USIM_SEND",
	"USIM_WAIT_FOR_RESPONSE",
	"USIM_RECEIVE",
	"USIM_PROCESS",

	"USIM_WDT_TIMER_EXPIRED"
};

char *get__USIMDLstates_string(unsigned int val)
{
	if(val==USIM_REMOVED)
		return _USIMDLstates_string[0];
	else if(val==USIM_INACTIVE)
		return _USIMDLstates_string[1];
	else if(val==USIM_ATR)
		return _USIMDLstates_string[2];
	else if(val==USIM_NEGOTIABLE)
		return _USIMDLstates_string[3];
	else if(val==USIM_SPECIFIC)
		return _USIMDLstates_string[4];
	else if(val==USIM_IDLE)
		return _USIMDLstates_string[5];
	else if(val==USIM_SEND)
		return _USIMDLstates_string[6];
	else if(val==USIM_WAIT_FOR_RESPONSE)
		return _USIMDLstates_string[7];
	else if(val==USIM_RECEIVE)
		return _USIMDLstates_string[8];	
	else if(val==USIM_PROCESS)
		return _USIMDLstates_string[9];	
	else if(val==USIM_WDT_TIMER_EXPIRED)
		return _USIMDLstates_string[10];	

	return NULL;
}





#ifndef UPGRADE_LTE_ONLY
void set_glfeatureflag(BOOL val)
{
	unsigned int flag;




	if((_USIMDLstates[0] != USIM_REMOVED)||(_USIMDLstates[1] != USIM_REMOVED)||(_USIMstates[0] != USIM_INACTIVE)||(_USIMstates[1] != USIM_INACTIVE))
	{

		ASSERT(0);
	}

	INTCDisable(_USIMinterruptSources[0]);
	INTCDisable(_USIMinterruptSources[1]);
	ASSERT(INTCUnbind (_USIMinterruptSources[0]) == INTC_RC_OK);
	ASSERT(INTCUnbind (_USIMinterruptSources[1]) == INTC_RC_OK);


#ifdef USIM_USE_CLOCK_STOP_TIMER
	OSATimerStop(_USIMtimerRefs[0]);
	OSATimerStop(_USIMtimerRefs[1]);
#endif



#ifdef USIM_USE_SW_WDT_TIMER
	OSATimerStop(_USIMtimerRefsWdt[0]);
	OSATimerStop(_USIMtimerRefsWdt[1]);

#endif

	flag=(unsigned int)val;


	SimSendGLSwapFlag(flag);

	
}


void change_glfeatureflag(unsigned int val)
{
	GLFeatureFlag=val;
	USIMPhase2Init();	
}



BOOL get_glfeatureflag(void)
{
	return GLFeatureFlag;
}
#else

#if defined(LTEONLY_8M8M) || defined(DM_LTEONLY_16MPSRAM) || defined(LTEONLY_THIN)
void change_glfeatureflag(unsigned int val)
{
	GLFeatureFlag=val;
	USIMPhase2Init();
}
#endif

#endif


/******************************************************************************
* Function: USIMPhase1Init
*******************************************************************************
* Description: Initializes database
*
* Parameters:
*
* Return value: USIM_RC_OK
*
* Notes:
******************************************************************************/
USIM_ReturnCode USIMPhase1Init(void)
{

  /* Init trace pointer: */
	return USIM_RC_OK;

} /* End of USIMPhase1Init   */




/******************************************************************************
* Function: USIMVersionGet()
*******************************************************************************
* Description: Get the current version of the Package
*
* Parameters:
*
* Return value:
*
* Notes:
******************************************************************************/
SwVersion USIMVersionGet(void)
{
    SwVersion usimVersion = "USIM Driver, version 2.50";

#if defined (USIM_USE_TRACE)
	USIM_TRACING_ON_DEMAND
	{
		DIAG_FILTER(HAL, USIM, USIMVersionGet, DIAG_INFORMATION)
    	diagPrintf("%s", usimVersion);
	}
#endif /* USIM_USE_TRACE */
    return usimVersion;
}/* End of USIMVersionGet   */



 /*****************************************************************************
 * Function     :	USIMATRGet
 ******************************************************************************
 *
 * Description  :	Retrieves the latest Answer To Reset information.
 *
 * Parameters   :	card - the required USIM card
 *
 * Output Param :	 info - pointer to the retrieved ATR information structure
 *
 *
 * Return value :	USIM_RC_OK
 *					USIM_RC_INVALID_CARD
 *					USIM_RC_NULL_POINTER
 *					USIM_RC_CARD_CLOSED
 *					USIM_RC_CARD_REMOVED
 *
 * Notes:  Compile-optimization makes problem with this proceddure in JTAG-debug-view
 *         So polace this procedure last...
 *****************************************************************************/
USIM_ReturnCode USIMATRGet (USIM_Card card, USIM_ATRInfo *  info)
{
 	USIM_CHECK_CARD_VALID(card);

	if(info==NULL)
	{
		return USIM_RC_NULL_POINTER;
	}

    if((_USIM_hwRemoveProgress[card]) ||
        (_USIMstates[card] == USIM_REMOVED))
    {
        USIMClose(card);
        return USIM_RC_CARD_REMOVED;
    }

    if (_USIMstates[card] == USIM_INACTIVE)
    {
        return USIM_RC_CARD_CLOSED;
    }

	// copy the atr information struct:

	info->cardClock = _USIMatrInfos[card].cardClock;
	info->indCardClock = _USIMatrInfos[card].indCardClock;
	info->conversionFactor = _USIMatrInfos[card].conversionFactor;
	info->indConversionFactor = _USIMatrInfos[card].indConversionFactor;
	info->adjustmentFactor = _USIMatrInfos[card].adjustmentFactor;
	info->indAdjustmentFactor = _USIMatrInfos[card].indAdjustmentFactor;
	info->extraGuardTime = _USIMatrInfos[card].extraGuardTime;
	info->modeChangeable = _USIMatrInfos[card].modeChangeable;
	info->protocol = _USIMatrInfos[card].protocol;
	info->stopState = _USIMatrInfos[card].stopState;
	info->cardClasses = _USIMatrInfos[card].cardClasses;
	info->convention = _USIMatrInfos[card].convention;

	info->length = _USIMatrInfos[card].length;
	info->workWaitingTime = _USIMatrInfos[card].workWaitingTime;
	info->charWaitingTime = _USIMatrInfos[card].charWaitingTime;
	info->blockWaitingTime = _USIMatrInfos[card].blockWaitingTime;

	info->infoFieldSize = _USIMatrInfos[card].infoFieldSize;
	info->errorCode = _USIMatrInfos[card].errorCode;

	info->historicBytesNumber = _USIMatrInfos[card].historicBytesNumber;
	memcpy(info->historicBytes, _USIMatrInfos[card].historicBytes,
		   (UINT32)(info->historicBytesNumber));

	return USIM_RC_OK;
}




/*-------------------------------------USIM Hotplug-------------------------------------*/
//20230612 use asr sim detect.
#if QUEC_ASR_SIM_HOT_PLUG_SUPPORT

UINT32 USIMHotPlugFlag[USIM_CARDS_AMOUNT];

OS_HISR 	usim_1_detect_hisr_ref;
OSATimerRef usim_1_detect_timer_ref = NULL;
OSFlagRef  usim_1_detect_flag_ref=NULL;
OSATaskRef usim_1_detect_task_ref=NULL;
char usim_1_detect_task_stack[2048]={0};


OS_HISR 	usim_2_detect_hisr_ref;
OSATimerRef usim_2_detect_timer_ref = NULL;
OSFlagRef  usim_2_detect_flag_ref=NULL;
OSATaskRef usim_2_detect_task_ref=NULL;
char usim_2_detect_task_stack[2048]={0};


//获取USIM1 是否插入了
//return 1//代表SIM卡插入，0//代表SIM卡拔出
UINT32 get_usim_1_insert_status(void)
{
    UINT32 value;

	value=GpioGetLevel(usim_1_detect_gpio);

	if(value==usim_1_detect_gpio_insert_level)
		return 1;
	else
		return 0;

}


UINT32 get_usim_2_insert_status(void)
{
    UINT32 value;

	value=GpioGetLevel(usim_2_detect_gpio);

	if(value==usim_2_detect_gpio_insert_level)
		return 1;
	else
		return 0;

}


void usim_1_det_lisr (void)
{
	STATUS status;


	GpioDisableEdgeDetectionBit(usim_1_detect_gpio, GPIO_TWO_EDGE);
	
	status = OS_Activate_HISR(&usim_1_detect_hisr_ref);
	ASSERT(status == OS_SUCCESS);
}


void usim_2_det_lisr (void)
{
	STATUS status;

	
	GpioDisableEdgeDetectionBit(usim_2_detect_gpio, GPIO_TWO_EDGE);
	
	status = OS_Activate_HISR(&usim_2_detect_hisr_ref);
	ASSERT(status == OS_SUCCESS);
}



#define USIM_HOT_PLUG_BIT		0x100


void usim_1_hotplug_trigger(void)
{
    OSAFlagSet(usim_1_detect_flag_ref, USIM_HOT_PLUG_BIT, OSA_FLAG_OR);
}

void usim_2_hotplug_trigger(void)
{
    OSAFlagSet(usim_2_detect_flag_ref, USIM_HOT_PLUG_BIT, OSA_FLAG_OR);
}

extern void ATRecv(int AtpIndex, void* data, UINT32 length);

void usim_1_det_task_entry(void *ptr)
{
	GPIO_ReturnCode ret;
	UINT32 value;
	OSA_STATUS status = OS_SUCCESS;
	UINT32 flag_value = 0;
	UINT32 flag_mask=USIM_HOT_PLUG_BIT;
	UINT32 insert_status;
	UINT32 wait_cnt=0;

	char *cfun0 = "AT+CFUN=0\r\n";
	char *cfun5 = "AT+CFUN=5\r\n";
	char *cfun1 = "AT+CFUN=1\r\n";
    char  AtRspBuf[32]={0};

	extern UINT32 flush_cfun4_at_ch;
	extern UINT32 flush_cfun4_at_ch_sim2;

	extern UINT32 flush_cfun4_rsp_flag;
	extern UINT32 flush_cfun4_rsp_flag_sim2;


	while(1)
	{

		status = OSAFlagWait( usim_1_detect_flag_ref, flag_mask, OSA_FLAG_OR_CLEAR, &flag_value, OSA_SUSPEND);
		
		#if QUEC_ASR_SIM_HOT_PLUG_SUPPORT
		#ifndef MIN_SYS
			if(!IsMiniSystem())
			{
				//Fitz.xu 20210707: if hot-plug functiopn not enable, do not process hot-plug.
				//Fix FAE-17500, STASR1601-4110
				if (g_usim_det_stat.sim_det_enable == 0)
				{
					CPUartLogPrintf("%s,%d, sim hot plug not enable", __func__, __LINE__);
					continue;
				}
			}
		#endif
		#endif

		if(flag_value & USIM_HOT_PLUG_BIT)
		{
			insert_status=get_usim_1_insert_status();

			DIAG_FILTER(USIMLOG, usim_1_det_task_entry, LOG001, DIAG_INFORMATION)
			diagPrintf("SIM_1_DET_TASK insert_status = %d", insert_status);	
			
			#ifndef MIN_SYS
			if(!IsMiniSystem())
			{
	            if(1 == g_usim_det_stat.sim_report_enable)
	            {
	                sprintf(AtRspBuf, "+QSIMSTAT: %d,%d", g_usim_det_stat.sim_report_enable, insert_status);
	                (void)at_urc_send(NUM_OF_TEL_ATP,(uint8 *) AtRspBuf, strlen(AtRspBuf), FALSE, URC_OUT_METHOD_UNICAST, NULL);
	            }
			}
			#endif
			
			if(insert_status==0)//SIM卡拔出
			{
				usim_send_quit_event(0);

				flush_cfun4_rsp_flag=0;
				wait_cnt=0;
				ATRecv(flush_cfun4_at_ch, cfun5, strlen(cfun5));
				USIMHotPlugFlag[0] = TRUE;
				
				#if QUEC_ASR_SIM_HOT_PLUG_SUPPORT
				quec_set_cfun0_flag(2);
				#endif
			
				#if 0
				while(flush_cfun4_rsp_flag==0)
				{
					OSATaskSleep(50);
					wait_cnt++;
					DIAG_FILTER(USIMLOG, usim_1_det_task_entry, LOG002, DIAG_INFORMATION)
					diagPrintf("SIM_1_DET_TASK wait cfun5 %lu", wait_cnt);					
				}
				#endif

                
				#ifdef QUECTEL_OPEN_CPU
    				//执行QuecOpen注册的回调
					#ifndef MIN_SYS
	    			extern void quec_kernel_call_sim_detect_calback(unsigned int pinlevel);
	    			if (!IsMiniSystem())
	    			{
	    				quec_kernel_call_sim_detect_calback(!usim_1_detect_gpio_insert_level);
	    			}
					#endif
				#endif


				OSATaskSleep(200*1);

				DIAG_FILTER(USIMLOG, usim_1_det_task_entry, LOG003, DIAG_INFORMATION)
				diagPrintf("SIM_1_DET_TASK end cfun5");
			}
			else
			{
				usim_send_quit_event(0);
				
				flush_cfun4_rsp_flag=0;
				wait_cnt=0;
				ATRecv(flush_cfun4_at_ch, cfun0, strlen(cfun0));

				#if 0				
				while(flush_cfun4_rsp_flag==0)
				{
					OSATaskSleep(50);
					wait_cnt++;
					DIAG_FILTER(USIMLOG, usim_1_det_task_entry, LOG004, DIAG_INFORMATION)
					diagPrintf("SIM_1_DET_TASK wait cfun0 %lu", wait_cnt);					
				}				
				#endif		

				OSATaskSleep(200*1);

				DIAG_FILTER(USIMLOG, usim_1_det_task_entry, LOG005, DIAG_INFORMATION)
				diagPrintf("SIM_1_DET_TASK end cfun0");


				flag_value=0;

				status = OSAFlagWait( usim_1_detect_flag_ref, flag_mask, OSA_FLAG_OR_CLEAR, &flag_value, OSA_NO_SUSPEND);

#ifdef QUECTEL_OPEN_CPU
				//执行QuecOpen注册的回调
#ifndef MIN_SYS
				extern void quec_kernel_call_sim_detect_calback(unsigned int pinlevel);
				if (!IsMiniSystem())
				{
					quec_kernel_call_sim_detect_calback(usim_1_detect_gpio_insert_level);
				}
#endif
#endif

				if(flag_value & USIM_HOT_PLUG_BIT)
				{

					insert_status=get_usim_1_insert_status();
					
					DIAG_FILTER(USIMLOG, usim_1_det_task_entry, LOG006, DIAG_INFORMATION)
					diagPrintf("SIM_1_DET_TASK again insert_status = %d", insert_status);			
					
					if(insert_status==0)
					{
					
						usim_send_quit_event(0);
						
						flush_cfun4_rsp_flag=0;
						wait_cnt=0;
						ATRecv(flush_cfun4_at_ch, cfun5, strlen(cfun5));
						USIMHotPlugFlag[0] = TRUE;

						#if 0						
						while(flush_cfun4_rsp_flag==0)
						{
							OSATaskSleep(50);
							wait_cnt++;
							DIAG_FILTER(USIMLOG, usim_1_det_task_entry, LOG007, DIAG_INFORMATION)
							diagPrintf("SIM_1_DET_TASK wait cfun5 %lu", wait_cnt);					
						}
						#endif						
					
						OSATaskSleep(200*1);
						
						DIAG_FILTER(USIMLOG, usim_1_det_task_entry, LOG008, DIAG_INFORMATION)
						diagPrintf("SIM_1_DET_TASK end cfun5");


					}
					else
					{
	
						flush_cfun4_rsp_flag=0;
						wait_cnt=0;
						ATRecv(flush_cfun4_at_ch, cfun1, strlen(cfun1));
						USIMHotPlugFlag[0] = FALSE;

						#if 0						
						while(flush_cfun4_rsp_flag==0)
						{
							OSATaskSleep(50);
							wait_cnt++;
							
							DIAG_FILTER(USIMLOG, usim_1_det_task_entry, LOG009, DIAG_INFORMATION)
							diagPrintf("SIM_1_DET_TASK wait cfun1 %lu", wait_cnt);	
						}	
						#endif

						OSATaskSleep(200*2);

						DIAG_FILTER(USIMLOG, usim_1_det_task_entry, LOG010, DIAG_INFORMATION)
						diagPrintf("SIM_1_DET_TASK end cfun1");
					}

				}
				else
				{

					flush_cfun4_rsp_flag=0;
					wait_cnt=0;
					ATRecv(flush_cfun4_at_ch, cfun1, strlen(cfun1));
					USIMHotPlugFlag[0] = FALSE;

					#if 0					
					while(flush_cfun4_rsp_flag==0)
					{
						OSATaskSleep(50);
						wait_cnt++;
						DIAG_FILTER(USIMLOG, usim_1_det_task_entry, LOG011, DIAG_INFORMATION)
						diagPrintf("SIM_1_DET_TASK wait cfun1 %lu", wait_cnt);	
					}	
					#endif					
					
					OSATaskSleep(200*2);
					
					DIAG_FILTER(USIMLOG, usim_1_det_task_entry, LOG012, DIAG_INFORMATION)
					diagPrintf("SIM_1_DET_TASK end cfun1");


				}	
				
			}



		}


	}

}



void usim_2_det_task_entry(void *ptr)
{
	GPIO_ReturnCode ret;
	UINT32 value;
	OSA_STATUS status = OS_SUCCESS;
	UINT32 flag_value = 0;
	UINT32 flag_mask=USIM_HOT_PLUG_BIT;
	UINT32 insert_status;
	UINT32 wait_cnt=0;

	char *cfun0 = "AT+CFUN=0\r\n";
	char *cfun5 = "AT+CFUN=5\r\n";
	char *cfun1 = "AT+CFUN=1\r\n";

	extern UINT32 flush_cfun4_at_ch;
	extern UINT32 flush_cfun4_at_ch_sim2;

	extern UINT32 flush_cfun4_rsp_flag;
	extern UINT32 flush_cfun4_rsp_flag_sim2;


	while(1)
	{

		status = OSAFlagWait( usim_2_detect_flag_ref, flag_mask, OSA_FLAG_OR_CLEAR, &flag_value, OSA_SUSPEND);

#ifndef MIN_SYS
		if(!IsMiniSystem())
		{
			//Fitz.xu 20210707: if hot-plug functiopn not enable, do not process hot-plug.
			//Fix FAE-17500, STASR1601-4110
			if (g_usim_det_stat.sim_det_enable == 0)
			{
				CPUartLogPrintf("%s,%d, sim hot plug not enable", __func__, __LINE__);
				continue;
			}
		}
#endif
	
		if(flag_value & USIM_HOT_PLUG_BIT)
		{
			insert_status=get_usim_2_insert_status();

			DIAG_FILTER(USIMLOG, usim_2_det_task_entry, LOG001, DIAG_INFORMATION)
			diagPrintf("SIM_2_DET_TASK insert_status = %d", insert_status);			

			if(insert_status==0)
			{
			
				usim_send_quit_event(1);

				flush_cfun4_rsp_flag_sim2=0;
				wait_cnt=0;
				ATRecv(flush_cfun4_at_ch_sim2, cfun5, strlen(cfun5));
				USIMHotPlugFlag[1] = TRUE;

#if 0				
				while(flush_cfun4_rsp_flag_sim2==0)
				{
					OSATaskSleep(50);
					wait_cnt++;
					DIAG_FILTER(USIMLOG, usim_2_det_task_entry, LOG002, DIAG_INFORMATION)
					diagPrintf("SIM_2_DET_TASK wait cfun5 %lu", wait_cnt);					
				}
#endif

				OSATaskSleep(200*1);

				DIAG_FILTER(USIMLOG, usim_2_det_task_entry, LOG003, DIAG_INFORMATION)
				diagPrintf("SIM_2_DET_TASK end cfun5");

				

			}
			else
			{

			
				usim_send_quit_event(0);
				
				flush_cfun4_rsp_flag_sim2=0;
				wait_cnt=0;
				ATRecv(flush_cfun4_at_ch_sim2, cfun0, strlen(cfun0));

#if 0				
				while(flush_cfun4_rsp_flag_sim2==0)
				{
					OSATaskSleep(50);
					wait_cnt++;
					DIAG_FILTER(USIMLOG, usim_2_det_task_entry, LOG004, DIAG_INFORMATION)
					diagPrintf("SIM_2_DET_TASK wait cfun0 %lu", wait_cnt);					
				}				
#endif		

				OSATaskSleep(200*1);

				DIAG_FILTER(USIMLOG, usim_2_det_task_entry, LOG005, DIAG_INFORMATION)
				diagPrintf("SIM_1_DET_TASK end cfun0");


				flag_value=0;

				status = OSAFlagWait( usim_2_detect_flag_ref, flag_mask, OSA_FLAG_OR_CLEAR, &flag_value, OSA_NO_SUSPEND);

				if(flag_value & USIM_HOT_PLUG_BIT)
				{

					insert_status=get_usim_2_insert_status();
					
					DIAG_FILTER(USIMLOG, usim_2_det_task_entry, LOG006, DIAG_INFORMATION)
					diagPrintf("SIM_2_DET_TASK again insert_status = %d", insert_status);			
					
					if(insert_status==0)
					{
					
						usim_send_quit_event(1);
						
						flush_cfun4_rsp_flag_sim2=0;
						wait_cnt=0;
						ATRecv(flush_cfun4_at_ch_sim2, cfun5, strlen(cfun5));
						USIMHotPlugFlag[1] = TRUE;

#if 0						
						while(flush_cfun4_rsp_flag_sim2==0)
						{
							OSATaskSleep(50);
							wait_cnt++;
							DIAG_FILTER(USIMLOG, usim_2_det_task_entry, LOG007, DIAG_INFORMATION)
							diagPrintf("SIM_2_DET_TASK wait cfun5 %lu", wait_cnt);					
						}
#endif						
					
						OSATaskSleep(200*1);
						
						DIAG_FILTER(USIMLOG, usim_2_det_task_entry, LOG008, DIAG_INFORMATION)
						diagPrintf("SIM_2_DET_TASK end cfun5");


					}
					else
					{
	
						flush_cfun4_rsp_flag_sim2=0;
						wait_cnt=0;
						ATRecv(flush_cfun4_at_ch_sim2, cfun1, strlen(cfun1));
						USIMHotPlugFlag[1] = FALSE;

#if 0						
						while(flush_cfun4_rsp_flag_sim2==0)
						{
							OSATaskSleep(50);
							wait_cnt++;
							
							DIAG_FILTER(USIMLOG, usim_2_det_task_entry, LOG009, DIAG_INFORMATION)
							diagPrintf("SIM_2_DET_TASK wait cfun1 %lu", wait_cnt);	
						}	
#endif

						OSATaskSleep(200*2);

						DIAG_FILTER(USIMLOG, usim_2_det_task_entry, LOG010, DIAG_INFORMATION)
						diagPrintf("SIM_2_DET_TASK end cfun1");


					}

					

				}
				else
				{

					flush_cfun4_rsp_flag_sim2=0;
					wait_cnt=0;
					ATRecv(flush_cfun4_at_ch_sim2, cfun1, strlen(cfun1));
					USIMHotPlugFlag[1] = FALSE;

#if 0					
					while(flush_cfun4_rsp_flag_sim2==0)
					{
						OSATaskSleep(50);
						wait_cnt++;
						DIAG_FILTER(USIMLOG, usim_2_det_task_entry, LOG011, DIAG_INFORMATION)
						diagPrintf("SIM_2_DET_TASK wait cfun1 %lu", wait_cnt);	
					}	
#endif					
					
					OSATaskSleep(200*2);
					
					DIAG_FILTER(USIMLOG, usim_2_det_task_entry, LOG012, DIAG_INFORMATION)
					diagPrintf("SIM_2_DET_TASK end cfun1");


				}	
				
			}



		}


	}

}



void usim_1_det_timer_handler(UINT32 arg)
{
	OS_STATUS os_status;
	UINT32 insert_status;

	insert_status=get_usim_1_insert_status();

	DIAG_FILTER(USIMLOG,usim_1_det_timer_handler,LOG001,DIAG_INFORMATION)
	diagPrintf("SIM_1_DET_TIMER = %u", insert_status);
	
	GpioEnableEdgeDetectionBit(usim_1_detect_gpio, GPIO_TWO_EDGE);

	usim_1_hotplug_trigger();

}


void usim_2_det_timer_handler(UINT32 arg)
{
	OS_STATUS os_status;
	UINT32 insert_status;

	insert_status=get_usim_2_insert_status();

	DIAG_FILTER(USIMLOG,usim_2_det_timer_handler,LOG001,DIAG_INFORMATION)
	diagPrintf("SIM_2_DET_TIMER = %u", insert_status);
	
	GpioEnableEdgeDetectionBit(usim_2_detect_gpio, GPIO_TWO_EDGE);

	usim_2_hotplug_trigger();

}


static void usim_1_det_hisr(void)
{
	UINT32 timeout;
	
	OS_STATUS status;
	
	OSATimerStop(usim_1_detect_timer_ref);

	timeout=usim_1_debounce_time/5;

	if(timeout==0)
		timeout=1;

	DIAG_FILTER(USIMLOG,usim_1_det_hisr,LOG001,DIAG_INFORMATION)
	diagPrintf("SIM_1_DET_HISR %lu 0x%lx, insert_status=%u", timeout, get_current_TStimer_tick(), get_usim_1_insert_status());

	status = OSATimerStart(usim_1_detect_timer_ref,
                             timeout,
                             0,
                             usim_1_det_timer_handler,
                             0);

}


static void usim_2_det_hisr(void)
{
	UINT32 timeout;
	
	OS_STATUS status;
	
	OSATimerStop(usim_2_detect_timer_ref);

	timeout=usim_2_debounce_time/5;

	if(timeout==0)
		timeout=1;

	DIAG_FILTER(USIMLOG,usim_2_det_hisr,LOG001,DIAG_INFORMATION)
	diagPrintf("SIM_2_DET_HISR %lu 0x%lx, insert_status=%u", timeout, get_current_TStimer_tick(), get_usim_2_insert_status());

	status = OSATimerStart(usim_2_detect_timer_ref,
                             timeout,
                             0,
                             usim_2_det_timer_handler,
                             0);

}


void usim_1_detect_init(void)
{
	static UINT32 usim_1_detect_init_flag=0;

	GPIOConfiguration config;

	if(usim_1_detect_init_flag==1)
		return;
	else
		usim_1_detect_init_flag=1;

	CPUartLogPrint("usim_1_detect_init",FALSE);

    OSATimerCreate(&usim_1_detect_timer_ref);
    OSAFlagCreate( &usim_1_detect_flag_ref);  
    Os_Create_HISR(&usim_1_detect_hisr_ref, "SIM1DETH", usim_1_det_hisr, 2);
    OSATaskCreate(&usim_1_detect_task_ref, usim_1_detect_task_stack, 2048, 60, "SIM1DETT", usim_1_det_task_entry, NULL);


#if  QUEC_ASR_SIM_HOT_PLUG_SUPPORT
	if(usim_1_detect_gpio != GPIO_MAX_AMOUNT_OF_PINS)
	{
		*(volatile unsigned long *)(GPIO_MFPR_ADDR(usim_1_detect_gpio)) = (0x1080 | QUEC_USIM_DET_PIN_AF); // set AF as gpio function
		config.pinDir = GPIO_IN_PIN;
		config.pinEd = GPIO_TWO_EDGE;
		config.pinPull = GPIO_PULLUP_ENABLE;
		config.isr = usim_1_det_lisr;
		GpioInitConfiguration(usim_1_detect_gpio,config);
	}
#else
	if(usim_1_detect_gpio != 0)
	{
		*(volatile unsigned long *)(GPIO_MFPR_ADDR(usim_1_detect_gpio))=0x1080;
		config.pinDir = GPIO_IN_PIN;
		config.pinEd = GPIO_TWO_EDGE;
		config.pinPull = GPIO_PULLUP_ENABLE;
		config.isr = usim_1_det_lisr;
		GpioInitConfiguration(usim_1_detect_gpio,config);
	}
#endif
}


void usim_2_detect_init(void)
{
	static UINT32 usim_2_detect_init_flag=0;

	GPIOConfiguration config;

	if(usim_2_detect_init_flag==1)
		return;
	else
		usim_2_detect_init_flag=1;


    OSATimerCreate(&usim_2_detect_timer_ref);
    OSAFlagCreate( &usim_2_detect_flag_ref);  
    Os_Create_HISR(&usim_2_detect_hisr_ref, "SIM2DETH", usim_2_det_hisr, 2);
    OSATaskCreate(&usim_2_detect_task_ref, usim_2_detect_task_stack, 2048, 60,"SIM2DETT", usim_2_det_task_entry, NULL);

#if  QUEC_ASR_SIM_HOT_PLUG_SUPPORT
    if(usim_2_detect_gpio != GPIO_MAX_AMOUNT_OF_PINS)
#else
	if(usim_2_detect_gpio != 0)
#endif
	{
	
		*(volatile unsigned long *)(GPIO_MFPR_ADDR(usim_2_detect_gpio))=0x1080;
		config.pinDir = GPIO_IN_PIN;
		config.pinEd = GPIO_TWO_EDGE;
		config.pinPull = GPIO_PULLUP_ENABLE;
		config.isr = usim_2_det_lisr;
		GpioInitConfiguration(usim_2_detect_gpio,config);
	}
}


void usim_init_hook(USIM_Card card)
{
	//Fitz.xu 2021071: do not support hot-plug in mini system
#ifndef MIN_SYS
	extern BOOL IsMiniSystem(void);
	if (IsMiniSystem())
	{	
		return;
	}
#endif

	if(card==USIM_COM_CARD)
		usim_1_detect_init();

#ifdef USIM_DSDS_DKB
	if(card==USIM_BANKING_CARD)
		usim_2_detect_init();

#endif
}

#if QUEC_ASR_SIM_HOT_PLUG_SUPPORT

void quec_usim_1_detect_pin_deinit(void)
{
	UINT32 detect_gpio = usim_1_detect_gpio;
	
	if(detect_gpio == 0){
		return ;
	}
	//disable interrupt config
	GpioDisableEdgeDetection(detect_gpio, GPIO_TWO_EDGE);
	GpioClearEdgeDetection(detect_gpio);
}

typedef enum
{
	SIM_PIN_HIGH_DET_WAKE_EN = 0,
	SIM_PIN_HIGH_DET_WAKE_DIS,
	SIM_PIN_LOW_DET_WAKE_EN,
	SIM_PIN_LOW_DET_WAKE_DIS,
	
	SIM_PIN_ENUM_MAX,
}quec_sim_pin_em;
	
static unsigned long sim_pin_mfpr[SIM_PIN_ENUM_MAX] =
{
	(QUEC_USIM_DET_PIN_AF|QUEC_PULL_UP_C|QUEC_DRV_SLOW_C|(1 << 4)|(1 << 5) |QUEC_RESERVED_C),
	(QUEC_USIM_DET_PIN_AF|QUEC_PULL_UP_C|QUEC_DRV_SLOW_C|QUEC_RESERVED_C),
	(QUEC_USIM_DET_PIN_AF|QUEC_DRV_SLOW_C|(1 << 4)|(1 << 5) |QUEC_RESERVED_C),
	(QUEC_USIM_DET_PIN_AF|QUEC_DRV_SLOW_C|QUEC_RESERVED_C)
};
 extern uint8  quec_get_usim_presence_sclk_cfg(void);
extern  uint8 quec_get_simdet_state(void);
extern UINT8 quec_sim_get_insert_level(void);
extern void quec_sim_read_simdet_config(void);
extern QuecOSStatus quec_read_usim_presence_sclk_cfg(void);

void quec_usim_1_detect_pin_reconfig(void)
{
#ifndef MIN_SYS
        extern BOOL IsMiniSystem(void);
   if (!IsMiniSystem()){   
	GPIOConfiguration config;
	UINT32 detect_gpio = usim_1_detect_gpio;
	UINT32 insert_status = 0;
	quec_sim_pin_em pin_index = SIM_PIN_HIGH_DET_WAKE_DIS;
	
	if(detect_gpio == 0){
		return ;
	}
	// clear pin state 
	quec_usim_1_detect_pin_deinit();
	
	if(quec_get_simdet_state() == 1)
	{
		memset(&config, 0, sizeof(GPIOConfiguration));

		config.pinDir  = GPIO_IN_PIN;
		config.pinEd   = GPIO_TWO_EDGE;
		config.isr     = usim_1_det_lisr;
		
		if(quec_sim_get_insert_level() == 1){
			// if config detect high level
			if(quec_get_usim_presence_sclk_cfg()){
				pin_index = SIM_PIN_HIGH_DET_WAKE_EN;
			}else{
				pin_index = SIM_PIN_HIGH_DET_WAKE_DIS;
			}
			config.pinPull = GPIO_PULL_DISABLE;
			config.initLv  = GPIO_INITIAL_VALUE_LOW;
		}else{	
			// detect low level
			if(quec_get_usim_presence_sclk_cfg()){
				pin_index = SIM_PIN_LOW_DET_WAKE_EN;
			}else{
				pin_index = SIM_PIN_LOW_DET_WAKE_DIS;
			}
			config.pinPull = GPIO_PULLUP_ENABLE;
			config.initLv  = GPIO_INITIAL_VALUE_HIGH;
		}
		
		
		//set mfpr
		*(volatile unsigned long *)(GPIO_MFPR_ADDR(detect_gpio)) = sim_pin_mfpr[pin_index];
		//set config
		GpioInitConfiguration(detect_gpio, config);
		}
    }
#endif
}



void quec_sim_hot_plug_init(void)
{
#ifndef MIN_SYS
	extern BOOL IsMiniSystem(void);
	if (!IsMiniSystem()){	
		CPUartLogPrintf("%s,%d", __func__, __LINE__);
		CPUartLogPrint("quec_sim_hot_plug_init",FALSE);
		quec_sim_read_simdet_config();// read form NV
		quec_read_usim_presence_sclk_cfg();
		usim_1_detect_gpio_insert_level = quec_sim_get_insert_level();
		usim_2_detect_gpio_insert_level = quec_sim_get_insert_level();
		usim_init_hook(USIM_COM_CARD);       // init sim1 hot detect;
		quec_usim_1_detect_pin_reconfig();
		//usim_init_hook(USIM_BANKING_CARD); // init sim2 hot detect;	
	}
#endif
}

//用户设置SIM卡插入时,检测Pin的level
void quec_sim_set_insert_level(UINT8 insert_level)
{
	usim_1_detect_gpio_insert_level = insert_level;
	usim_2_detect_gpio_insert_level = insert_level;
}

#endif

//ICAT EXPORTED FUNCTION - USIM,HotplugTest,HotplugTestGPIOInit
void HotplugTestGPIOInit(void)
{
#if 1

	*(volatile unsigned int*)0xD401E160=0xD0C0;
	GpioSetDirection(33,GPIO_OUT_PIN);
	GpioSetLevel(33, 0);

#endif
	
	
#if 0
		
	*(volatile unsigned int*)0xD401E168=0xD0C0;
	GpioSetDirection(35,GPIO_OUT_PIN);
	GpioSetLevel(35, 0);
		
#endif

}

//ICAT EXPORTED FUNCTION - USIM,HotplugTest,GPIO33High
void GPIO33High(void)
{
	GpioSetLevel(33, 1);
}

//ICAT EXPORTED FUNCTION - USIM,HotplugTest,GPIO33Low
void GPIO33Low(void)
{
	GpioSetLevel(33, 0);
}

//ICAT EXPORTED FUNCTION - USIM,HotplugTest,GPIO35High
void GPIO35High(void)
{
	GpioSetLevel(35, 1);
}

//ICAT EXPORTED FUNCTION - USIM,HotplugTest,GPIO35Low
void GPIO35Low(void)
{
	GpioSetLevel(35, 0);
}

UINT32 usim_get_hotplug_flag(UINT32 card)
{	
	DIAG_FILTER(USIMLOG, usim_get_hotplug_flag, LOG001, DIAG_INFORMATION)
	diagPrintf("hotplugflag %lu, SIM card status:%lu", card, USIMHotPlugFlag[card]);					
	return USIMHotPlugFlag[card];
}

/*-------------------------------------USIM Hotplug End-------------------------------------*/

#else //!SUPPORT_USIM_HW_HOT_PLUG

void usim_init_hook(USIM_Card card)
{
	return;
}
UINT32 usim_get_hotplug_flag(UINT32 card)
{	
	return FALSE;
}


#endif

