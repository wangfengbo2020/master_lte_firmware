/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/******************************************************************************
*                USIM CONFIGURABLE HEADER FILE
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
*  Title: USIM
*
*  Filename: USIM_config.h
*
*  Author:  Eilam Ben-Dror
*
*  Description:  USIM configurable header file.
*
*  Last Modified: 14-Dec-2005
*
******************************************************************************/
#ifndef _USIM_CONFIG_H_
#define _USIM_CONFIG_H_
#ifdef UPGRADE_DSDS
//used Dual SIM DKB version
#define USIM_DSDS_DKB
#endif
// USIM Card Numbers
typedef enum
{
    USIM_COM_CARD = 0,
    USIM_BANKING_CARD,

	USIM_CARDS_AMOUNT
}USIM_Card;


// For ATR and PPS decoding within the USIM Driver, comment this line:
#define USIM_NO_ATR_PPS_DECODING

// Define the following to enable ICAT tracing of USIM data on demand only
// Trace can be enabled/disabled via ProductDebugLevel qeual to "debug extended" value in Platfrom.nvm file
#define USIM_USE_TRACE_ON_DEMAND_ONLY

// Define the following to enable ICAT tracing of USIM data
//Disabled by Default, enabled in Tavor from 15/07/07
#define USIM_USE_TRACE

//-------------Tracing for Hermon-------------------------
#if defined(_HERMON_B0_SILICON_) && !defined(INTEL_2CHIP_PLAT_BVD)
//Disable trace for Hermon. Comment line below to enable trace on Hermon and define USIM_USE_TRACE above
#undef 	USIM_USE_TRACE
//Enable all tracing for Hermon, if defined USIM_USE_TRACE
#define USIM_TRACING_ON_DEMAND
//-------------Tracing for Tavor--------------------------
#else
//Extened tracing for Tavor on Deband
#ifdef   USIM_USE_TRACE_ON_DEMAND_ONLY
#ifndef  USIM_USE_TRACE
#define  USIM_USE_TRACE
#endif
// Enable traces in ACAT only when ProductDebugLevel is "Extended Debug" defined of in com\platform.nvm file
//TEMPORARY-lk-#define  USIM_TRACING_ON_DEMAND if(p_PlatformNvm->USIM.DebugLevel == DEBUG_EXTEND)
#define  USIM_TRACING_ON_DEMAND if(0)

//-------------Tracing #endif  ----------------------------
#endif /* USIM_USE_TRACE_ON_DEMAND_ONLY */
#endif /* _HERMON_B0_SILICON_ */

// Card detection pins: if not defined - no detection is used
// #define USIM_DETECT_PIN              GPIO_PIN_3

// Card detection interrupt: if not defined - no detection is used
// #define USIM_DETECT_INTERRUPT_SRC     INTC_SRC_GPIO_3

/* 	When defined, the USIM Driver will stop the clock after every command.
	Otherwise, clock can be stopped by calling the USIMClockStop service. */
//Disable(remove/undefine) following in case of DMA is used
//#define USIM_STOP_CLOCK_AFTER_EVERY_COMMAND

// For using a timer for stoping the card's clock:
//#define USIM_USE_CLOCK_STOP_TIMER

// BAUD RATE Parameters:

// Definition of the internal clock frequency, in MHz.
#define USIM_IN_CLK 48 //[MHz]

// Defines the available maximal card clock frequencies:
#define USIM_MAX_3_MHz		30
#define USIM_MAX_3_4_MHz	34
#define USIM_MAX_4_MHz		40
#define USIM_MAX_4_8_MHz	48

// Defines the maximal card clock frequency to be used:
#define USIM_MAX_CARD_CLK USIM_MAX_3_4_MHz

// Define the default value for the clock rate conversion factor, Fd:
#define USIM_DEFAULT_CONVERSION_FACTOR 372

// Define the default value for the baud rate adjustment factor, Dd:
#define USIM_DEFAULT_ADJUSTMENT_FACTOR 1



// Define the number of OS timer ticks after which the card clock would be stopped:
#define USIM_CLK_STOP_INTERVAL  2000



// Define the card's default class:
#define USIM_DEFAULT_CLASS USIM_CLASS_C

#define USIM_DEFAULT_AVAILABLE_CLASSES (USIM_CLASS_C | USIM_CLASS_B)


// Define the number of times a byte would be resent in T=0 error.
#define USIM_ERROR_REPEAT 4

/* Define the number of consecutive parity errors which will trigger the parity
 * error interrupt:
 * 0 - a single parity error triggers the interrupt
 * 3 - reception of 4 consecutive parity errors triggers the interrupt */
#ifdef  SS_FEATURE
#define USIM_PARITY_ERROR_INTERRUPT_TRIGGER 3

#else
#define USIM_PARITY_ERROR_INTERRUPT_TRIGGER 1

#endif


// Define the max number of consecutive reset trials:
#define USIM_RESET_REPEATS 3

// Define the default protocol to be used:
#define USIM_DEFAULT_PROTOCOL USIM_T0

// Define the default coding convention:
#define USIM_DEFAULT_CONVENTION USIM_DIRECT

// Define the default extra guard time:
#define USIM_DEFAULT_EXTRA_GUARD_TIME 0

// Define the default block guard time:
#define USIM_DEFAULT_BLOCK_GUARD_TIME 16

// Default Work Waiting Time parameter, for T=0:
#define USIM_DEFAULT_WI 10

// Default Character Waiting Time parameter, for T=1:
#define USIM_DEFAULT_CWI 5

// Default Block Waiting Time parameter, for T=1:
#define USIM_DEFAULT_BWI 4

// Define the default work waiting time:
#ifdef  SS_FEATURE
#define USIM_DEFAULT_WORK_WAIT_TIME 11520

#else
#define USIM_DEFAULT_WORK_WAIT_TIME 9600

#endif


// Define the default character waiting time for T=1 protocol:
#define USIM_DEFAULT_CHAR_WAIT_TIME 43

// Define the default block waiting time for T=1 protocol:
#define USIM_DEFAULT_BLOCK_WAIT_TIME 15371

// Define the default information field size for T=1 protocol:
#define USIM_DEFAULT_INFO_FIELD_SIZE 32

#define USIM_ATR_BWT 120    // = 40,000 clock cycles

// Define the line below to enable Watchdog software timer, to watch for lack issue, which was found during "drop tests"

#define USIM_USE_SW_WDT_TIMER 

//Define for PMC Micco for series, which enables LDO4/LDO7 (Vcc) with 1.8Volt during 1st hardware reset(power up)
#define USIM_PMC_LDO_ENABLED_ON_BOOT

/*-------------------Tavor specific functions -----------------------------*/
#if 1 //def _TAVOR_HARBELL_
//Define following to enable DMA (Tx or RX) working on Tavor
//removed by -leonidk- 15/07/07
#ifndef PHS_SW_DEMO_TTC
#define USIM_TAVOR_DMA_ENABLE
#endif
#ifdef USIM_TAVOR_DMA_ENABLE
//Define following to enable DMA Rx (Currently doesn't supported on TAVOR)!!
//!!!!! #define USIM_TAVOR_READ_WITH_DMA

//Define following to enable DMA Tx (Write) on Tavor
#define USIM_TAVOR_WRITE_WITH_DMA

#endif

// Enable USIM NMOS control via CPMU - Tavor only (actually, Tavor P only: controlled by Sys_CommpmUsimNmosEngageInUse)
#define USIM_NMOS_CONTROL
#endif

#if 1 //defined (_TAVOR_HARBELL_)
// Not all targets may be compiled with the USIM_DETECT. Use enable/disable
// USIM detect is currently coupled with Harbell specific CGPIO interface: use on Harbell only
#define USIM_DETECT_ENABLE
#endif  // _TAVOR_HARBELL_

#endif	/* _USIM_CONFIG_H_ */
