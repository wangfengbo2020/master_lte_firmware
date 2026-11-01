/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/******************************************************************************
*               MODULE HEADER FILE
*******************************************************************************
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
* Title: USIM hardware header file
*
* Filename: usim_hw.h
*
* Author: Eilam Ben-Dror
*
* Description: This is the header file for the USIM hardware interface (UICC I/F).
*
* Last Updated: 14-Dec-2005
*
******************************************************************************/
#ifndef _USIM_HW_H_
#define _USIM_HW_H_

#include "global_types.h"
#include "usim_config.h"
#include "usim_db.h"
#ifdef USIM_TAVOR_DMA_ENABLE
#include "dma.h"
#endif
#include "quec_cust_patch.h"
#ifndef PHS_SW_DEMO_TTC
#if defined(_HERMON_B0_SILICON_)
//            Hermon
#define USIM_0_HW_ADDRESS       0x41600000L
//#elif defined(_TAVOR_HARBELL_) || defined(SILICON_PV2)
#elif defined(SILICON_PV2)
//            Tavor
#define USIM_0_HW_ADDRESS	    0xF0080000L
#elif defined(SILICON_TTC)
//             TTC
#define USIM_0_HW_ADDRESS	    0xD4032000L /*USIM1*/
//#define USIM_1_HW_ADDRESS	    0xD4033000L /*USIM2*/
#else
#error Unsupported platform
#endif
#else






#define USIM_0_HW_ADDRESS	    0xD4032000L
#define USIM_1_HW_ADDRESS	    0xD4033000L



#endif
#define ALL_HW_BITS                         0xFFFFFFFFL


struct USIMController
    {
    UINT32       RBR ;		//  Receive Buffer					Read only
    UINT32       THR ;		//  Transmit Holding				Write only
    UINT32       IER ;		//  Interrupt Enable				Read / Write
    UINT32       IIR ;		//  Interrupt Identification		Read / Write *
    UINT32       FCR ;		//  FIFO Control					Read / Write
    UINT32       FSR ;		//  FIFO Status						Read only
    UINT32       ECR ;		//  Error Control					Read / Write
    UINT32       LCR ;		//  Line Control					Read / Write
    UINT32       CCR ;		//  Card Control					Read / Write
    UINT32       LSR ;		//  Line Status						Read only
    UINT32       EGTR;		//  Extra Guard Time				Read / Write
    UINT32       BGTR;		//  Block Guard Time				Read / Write
    UINT32       TOR ;		//  Time Out						Read / Write
    UINT32       CLKR;		//  Clock							Read / Write
    UINT32       DLR ;		//  Divisor Latch					Read / Write
    UINT32       FLR ;		//  Factor Latch					Read / Write
    UINT32       CWTR;		//  Character Waiting Time			Read / Write
    UINT32       BWTR;		//  Block Waiting Time				Read / Write
    } ;

//#define     USIMHWRegisters    (* (volatile struct USIMController *) USIM_0_HW_ADDRESS)

/*----------- Extern definition ----------------------------------------------*/
#ifndef _USIM_HW_NO_EXTERN_
  #define EXTERN extern
#else
  #define EXTERN
#endif /* _USIM_HW_NO_EXTERN_ */

EXTERN volatile struct USIMController * USIMHWRegisters [2];

// Clock request types:
typedef enum
{
	USIM_HW_CLOCK_STOP_REQ = 0,
	USIM_HW_CLOCK_START_REQ
}USIM_HW_ClockReqType;


// RX Data Ready levels:
typedef enum
{
	USIM_HW_1B = 0,	// 1 byte received would cause an interrupt
	USIM_HW_4B,		// 4 bytes received would cause an interrupt
	USIM_HW_8B,		// 8 bytes received would cause an interrupt
	USIM_HW_12B		// 12 bytes received would cause an interrupt
}USIM_HW_RDRLevel;


#ifdef USIM_TAVOR_DMA_ENABLE
#define DATA_LIMIT_FOR_DMA			5
#define USIM_DMA_WRITE_CHAN         DMA_CHANNEL_19			// DMA C3 -- channel 3
#define USIM_DMA_READ_CHAN          DMA_CHANNEL_18          // DMA C3 -- channel 2
#endif
/*----------- Global macro definitions ----------------------------------------*/
#ifdef USIM_TAVOR_DMA_ENABLE
/*---------------------- T a v o r ---------------------------------------------*/
#define USIM_DISABLE_TX_DMA_MODE(c)  (USIMHWRegisters[c]->IER &= 0xFFFF7FFF)			// Disable the DMA transmit request

#define USIM_ENABLE_TX_DMA_MODE(c)	 (USIMHWRegisters[c]->IER |= 0x00008000)            // Enable DMA transmit request

#define USIM_SET_TX_THRESHOLD_TO_8_BYTE(c)  (USIMHWRegisters[card]->FCR != 0x100L)     // Set DMA threshold to 8 byte for tx.
#ifdef  USIM_TAVOR_READ_WITH_DMA
 // Set DMA threshold to 8 byte rx fifo
#define USIM_SET_RX_THRESHOLD_TO_8_BYTE(c)  USIMHWRegisters[card]->FCR &= 0x0C0L    \
                                                 USIMHWRegisters[card]->FCR |= 0x080L
#endif                                                 
#endif
/*------------------------------------------------------------------------------*/
//#define DUMMY_DELAY \
//	{               \
//	int cntr_delay_o01=0; \
//	for (;++cntr_delay_o01 < 0x3F;)\
//	;\
//	}

#define USIM_ENABLE(c,source) (USIMHWRegisters[c]->IER |= (0x1L << (source)))

#define USIM_ENABLE_MASK(c, mask) (USIMHWRegisters[c]->IER = (mask))

#define USIM_DISABLE(c,source) (USIMHWRegisters[c]->IER &= (~(0x1L<<(source))))

#define USIM_DISABLE_ALL(c) USIMHWRegisters[c]->IER = 0

#define USIM_GET_IER(c) (USIMHWRegisters[c]->IER)

#define USIM_INTERRUPT_STATUS_GET(c,i) ((i) = (USIMHWRegisters[c]->IIR & 0x137FL))

#define USIM_INTERRUPT_CLEAR(c,source) (USIMHWRegisters[c]->IIR = (0x1L << (source)))

#define USIM_INTERRUPT_CLEAR_ALL(c) (USIMHWRegisters[c]->IIR =  USIMHWRegisters[c]->IIR & USIM_CLEARABLE_INTERRUPT_SOURCES_MASK)

#define USIM_PARITY_ERR_LEVEL_SET(c,level)									\
        (USIMHWRegisters[c]->ECR = (level<<3) + (USIMHWRegisters[c]->ECR & 0x03L))

#define USIM_T0_ERR_LEVEL_SET(c,level)										\
        (USIMHWRegisters[c]->ECR = (level-1) + (USIMHWRegisters[c]->ECR & 0x18L))

#define USIM_T0_ERR_CLEAR(c) (USIMHWRegisters[c]->ECR |= 0x40L)

#define USIM_TX_BLOCK_SET(c) (USIMHWRegisters[c]->FCR |= 0x100L)

#define USIM_TX_CLEAR(c)	USIMHWRegisters[c]->FCR |= 0x02

#define USIM_GET_FCR(c) (USIMHWRegisters[c]->FCR )

#define USIM_PERR_NUM_GET(c,len)   ((len) = (UINT8)((USIMHWRegisters[c]->ECR & 0xFF00) >> 8))

#define USIM_TX_LENGTH_GET(c,len)   ((len) = (UINT8)((USIMHWRegisters[c]->FSR & 0x1E00) >> 9))

#define USIM_RX_LENGTH_GET(c,len) ((len) = (USIMHWRegisters[c]->FSR & 0xFF))

#define USIM_RX_CLEAR(c) USIMHWRegisters[c]->FCR |= 0x01

#define USIM_CLEAR_ALL(c) USIMHWRegisters[c]->FCR |= 0x03;                    \
                          USIMHWRegisters[c]->IIR = USIM_CLEARABLE_INTERRUPT_SOURCES_MASK


#define USIM_EXTRA_GUARD_TIME_SET(c,egtm)                                     \
         USIMHWRegisters[c]->EGTR = (egtm);                                  \
         USIMHWRegisters[c]->TOR = ((egtm)<4)? ((egtm+T0_ADJUST)*USIM_TIMEOUT_CHARS) : 255

#define USIM_BLOCK_GUARD_TIME_SET(c,protocol)                               \
			if(protocol==USIM_T0)											\
                (USIMHWRegisters[c]->BGTR = 4);                   \
			else															\
                (USIMHWRegisters[c]->BGTR = 11)

#define USIM_CHAR_WAIT_TIME_SET(c,protocol,cwt)								\
			if(protocol==USIM_T0)											\
				(USIMHWRegisters[c]->CWTR = (cwt-T0_ADJUST));				\
			else															\
				(USIMHWRegisters[c]->CWTR = (cwt-T1_ADJUST))

#define USIM_BLOCK_WAIT_TIME_SET(c,protocol,bwt)                            \
			if(protocol==USIM_T0)											\
				(USIMHWRegisters[c]->BWTR = (bwt==USIM_MAX_WWT_REG_VALUE)?(bwt-T0_ADJUST):(bwt-T0_ADJUST)); \
			else															\
				(USIMHWRegisters[c]->BWTR = (bwt==USIM_MAX_WWT_REG_VALUE)?(bwt-T1_ADJUST):(bwt-T1_ADJUST))

#define USIM_CHAR_WAIT_TIME_GET(c,protocol,cwt)								\
			if(protocol==USIM_T0)											\
				(cwt=(USIMHWRegisters[c]->CWTR+T0_ADJUST));				\
			else															\
				(cwt=(USIMHWRegisters[c]->CWTR+T1_ADJUST))

#define USIM_BLOCK_WAIT_TIME_GET(c,protocol,bwt)                            \
			if(protocol==USIM_T0)											\
				(bwt=(USIMHWRegisters[c]->BWTR==(USIM_MAX_WWT_REG_VALUE-T0_ADJUST))?(USIMHWRegisters[c]->BWTR+T0_ADJUST):(USIMHWRegisters[c]->BWTR+T0_ADJUST)); \
			else															\
				(bwt=(USIMHWRegisters[c]->BWTR==(USIM_MAX_WWT_REG_VALUE-T1_ADJUST))?(USIMHWRegisters[c]->BWTR+T1_ADJUST):(USIMHWRegisters[c]->BWTR+T1_ADJUST))

#define USIM_TIME_OUT_SET(c,time) (USIMHWRegisters[c]->TOR = (time))

#define USIM_PROTOCOL_SET(c,protocol)  if((protocol) == USIM_T0)				\
										USIMHWRegisters[c]->LCR &= 0x07L;		\
									 else									\
										USIMHWRegisters[c]->LCR |= 0x18L

#define USIM_CONVENTION_SET(c,convention)                                       \
        if((convention) == USIM_DIRECT)                                         \
        {                                                                       \
            USIMHWRegisters[c]->LCR |= 0x04L;                                   \
            USIMHWRegisters[c]->LCR &= 0x1CL;                                   \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            USIMHWRegisters[c]->LCR &= 0x1BL;                                   \
            USIMHWRegisters[c]->LCR |= 0x03L;                                   \
        }

#define USIM_PARITY_TOGGLE(c) if((USIMHWRegisters[c]->LCR)&0x04L)               \
                                    USIMHWRegisters[c]->LCR &= 0x1BL;           \
                              else                                              \
                                    USIMHWRegisters[c]->LCR |= 0x04L

#define USIM_CONVENTION_TOGGLE(c)                                               \
        if((USIMHWRegisters[c]->LCR)&0x04L)                                     \
        {                                                                       \
            USIMHWRegisters[c]->LCR &= 0x1BL;                                   \
            USIMHWRegisters[c]->LCR |= 0x03L;                                   \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            USIMHWRegisters[c]->LCR |= 0x04L;                                   \
            USIMHWRegisters[c]->LCR &= 0x1CL;                                   \
        }


#define USIM_DIVISOR_SET(c,divisor) (USIMHWRegisters[c]->DLR = (divisor))

#define USIM_DIVISOR_GET(c)     (USIMHWRegisters[c]->DLR & 0xFFFF)

#define USIM_FACTOR_SET(c,factor) (USIMHWRegisters[c]->FLR = (factor) - 1)

#define USIM_FACTOR_GET(c)      ((USIMHWRegisters[c]->FLR & 0xFF) + 1)

//#define USIM_WAIT_CLKR_CHANGED(c) {\
//	int cycl_cntr_o001 = 0xFF; \
//	for (; (cycl_cntr_o001>0) && (USIMHWRegisters[c]->CLKR & 0x1000); --cycl_cntr_o001)\
//			 DUMMY_DELAY;\
//	_USIMClockRequestCounter[card]=(cycl_cntr_o001==0)?0:0xDEAD; \
//	}

//#define USIM_CARD_CLOCK_SET(c,ratio)                                             \
//        USIMHWRegisters[c]->CLKR = (USIMHWRegisters[c]->CLKR & 0x6000) + (ratio);\
//        USIM_WAIT_CLKR_CHANGED(c)

/*see manual CLCK can be wrriten only to this bits*/
#define USIM_CARD_CLOCK_WR_MASK 0xF0FFL

#define USIM_CARD_CLOCK_GET(c)  (USIMHWRegisters[c]->CLKR & USIM_CARD_CLOCK_WR_MASK)

/* required to check RQST bit for == 0 after writting to this register */
#define USIM_CARD_CLOCK_SET_RATIO(c,ratio)    \
    (USIMHWRegisters[c]->CLKR = (USIM_CARD_CLOCK_GET(c) & 0xE000) | (ratio & 0xFF ) )

#define USIM_CARD_CLOCK_GET_DIVISOR(c)     (USIMHWRegisters[c]->CLKR & 0xFF)

#define USIM_CARD_CLOCK_STOP_GET(c)        (USIMHWRegisters[c]->CLKR & 0x2000)

#define USIM_CARD_CLOCK_CHANGE_GET(c)      (USIMHWRegisters[c]->CLKR & 0x1000)

#define USIM_CARD_CLOCK_STOP_LEVEL_GET(c) (USIMHWRegisters[c]->CLKR & 0x4000)

#define USIM_CARD_CLOCK_STOP_LEVEL_HIGH(c) USIMHWRegisters[c]->CLKR = 0x4000L | USIM_CARD_CLOCK_GET(c)

#define USIM_CARD_CLOCK_STOP_LEVEL_LOW(c) USIMHWRegisters[c]->CLKR =(((~0x4000L) & USIM_CARD_CLOCK_GET(c)) & USIM_CARD_CLOCK_WR_MASK)

#define USIM_CARD_CLOCK_START_REQ(c)   USIMHWRegisters[c]->CLKR = ((( ~0x2000L) & USIM_CARD_CLOCK_GET(c)) & USIM_CARD_CLOCK_WR_MASK)

#define USIM_CARD_CLOCK_STOP_REQ(c) USIMHWRegisters[c]->CLKR = 0x2000L | USIM_CARD_CLOCK_GET(c)

#define USIM_CARD_CLOCK_STOP_CLCK_USIM(c) USIMHWRegisters[c]->CLKR = 0x8000L | USIM_CARD_CLOCK_GET(c)

#define USIM_CARD_CLOCK_START_CLCK_USIM(c)  USIMHWRegisters[c]->CLKR=(((  ~0x8000L) & USIM_CARD_CLOCK_GET(c)) & USIM_CARD_CLOCK_WR_MASK)

#define USIM_CARD_CLOCK_STOP_CLCK_USIM_GET(c) USIMHWRegisters[c]->CLKR = (USIMHWRegisters[c]->CLKR & 0x8000)


// card control definitions:
#define USIM_CARD_RESET(c) USIMHWRegisters[c]->CCR &= 0x016L

#define USIM_CARD_UNRESET(c) USIMHWRegisters[c]->CCR |= 0x01L

#define USIM_VOLTAGE_SET(c,v) /* USIMHWRegisters[c]->CCR = ((((v)%3) << 1) + 0x10L) */

#define USIM_TXD_FORCE_SET(c) USIMHWRegisters[c]->CCR |= 0x10L

#define USIM_TXD_FORCE_CLEAR(c) USIMHWRegisters[c]->CCR &= 0x07L

#define USIM_IS_RX_ACTIVE(c) (USIMHWRegisters[c]->LSR & 0x04000L)

#define USIM_IS_TX_ACTIVE(c) (USIMHWRegisters[c]->LSR & 0x02000L)

#define USIM_IS_PARITY_ERROR(c) (USIMHWRegisters[c]->LSR & 0x02L)

#define USIM_IS_RX_NOT_EMPTY(c) (USIMHWRegisters[c]->LSR & 0x01000)

#define USIM_GET_LSR(c) (USIMHWRegisters[c]->LSR)

#define USIM_DUMMY_READ(c) {volatile UINT8 dummy =(UINT8)USIMHWRegisters[c]->IIR;}


#define T0_ADJUST 12
#define T1_ADJUST 11

#define USIM_ADJUST_CWT_GCF 3
#define USIM_ADJUST_BWT_GCF 3
/* Adjusting values for GCF - TC 7.2.1 c-3 (TS 102 230). 
 * In test case(and spec) is written that required 960etu, 
 * while Comprion IT3 test passes only  after >1000etu */
#define USIM_ADJUST_WWT_GCF 45

#define USIM_HIGH_BAUD_RATE_EXTRA_GUARD_TIME_ADJUST (4)

// Interrupt enable masks according to state:

#define USIM_SEND_ENABLE_MASK           0x0204L

#define USIM_W4RESPONSE_ENABLE_MASK     0x015FL

#define USIM_RECEIVE_ENABLE_MASK        0x013BL

#define USIM_DMA_SEND_ENABLE_MASK       0x8004L

#define USIM_DMA_W4RESPONSE_ENABLE_MASK 0x405FL

#define USIM_DMA_RECEIVE_ENABLE_MASK    0x403BL

#define USIM_MAX_WWT_REG_VALUE			0xFFFFL

#define USIM_CLEARABLE_INTERRUPT_SOURCES_MASK (0x106BL)
/*----------- Global function prototypes -------------------------------------*/

void USIM_HW_RXRead(USIM_Card card, UINT32 length, UINT8 * buffer);
void USIM_HW_RXRead_Dummy(USIM_Card card, UINT32 length);
void USIM_HW_TXWrite(USIM_Card card,UINT32 length, UINT8 * buffer);
void USIM_HW_RXLevelSet(USIM_Card card, USIM_HW_RDRLevel level);
void USIM_HW_deactivate(USIM_Card card, BOOL shutDown);
void USIM_HW_cardReset(USIM_Card card, USIM_Class voltageClass);
 BOOL  USIM_HW_Delay(USIM_Card card, UINT32 clockCycles, UINT32 mode);
BOOL USIM_HW_checkClock(USIM_Card card);
BOOL USIM_HW_cardClockRequest(USIM_Card card, USIM_HW_ClockReqType reqType);
void  usim_hw_clk_onoff(USIM_Card card, USIM_HW_ClockReqType reqType);

void AIB_USIM1_IO_Set_3_3V(void);
void AIB_USIM2_IO_Set_3_3V(void);

#undef EXTERN


#endif /* _USIM_HW_H_ */
