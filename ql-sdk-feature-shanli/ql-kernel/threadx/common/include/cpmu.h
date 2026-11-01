/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/************************************************************************/
/*  COPYRIGHT (C) 2002 Intel Corporation.                               */
/*                                                                      */
/*  This file and the software in it is furnished under                 */
/*  license and may only be used or copied in accordance with the terms */
/*  of the license. The information in this file is furnished for       */
/*  informational use only, is subject to change without notice, and    */
/*  should not be construed as a commitment by Intel Corporation.       */
/*  Intel Corporation assumes no responsibility or liability for any    */
/*  errors or inaccuracies that may appear in this document or any      */
/*  software that may be provided in association with this document.    */
/*  Except as permitted by such license, no part of this document may   */
/*  be reproduced, stored in a retrieval system, or transmitted in any  */
/*  form or by any means without the express written consent of Intel   */
/*  Corporation.                                                        */
/*                                                                      */
/* Title: Communication Subsystem Power Management Unit Header File     */
/*                                                                      */
/* Filename: cpmu.h                                                     */
/*                                                                      */
/* Author: Olga Fomenko		                                            */
/*                                                                      */
/* Project, Target, subsystem: Tavor, Arbel, HOP     					*/
/*																		*/
/* Remarks: -                                                           */
/*    													                */
/* Created: 20/04/2005                                                  */
/*                                                                      */
/* Modified:                                                            */
/************************************************************************/


#ifndef _CPMU_H_
#define _CPMU_H_

#include "commccu.h"      //including commccu because we must use CommCCU_SystemPLLFreqE enum to update CPCR

typedef enum
{// this type describes banks of L2 memory
	// to assemble a combination of any banks use
	// bitwise "or" operator for example:
	// CPMU_L2BANK_2|CPMU_L2BANK_10|CPMU_L2BANK_14

	// enum numeration matches to mask of status bits in appropriate register
	CPMU_L2BANK_0 = 1<<0,
	CPMU_L2BANK_1 = 1<<1,
	CPMU_L2BANK_2 = 1<<2,
	CPMU_L2BANK_3 = 1<<3,
	CPMU_L2BANK_4 = 1<<4,
	CPMU_L2BANK_5 = 1<<5,
	CPMU_L2BANK_6 = 1<<6,
	CPMU_L2BANK_7 = 1<<7,
	CPMU_L2BANK_8 = 1<<8,
	CPMU_L2BANK_9 = 1<<9,
	CPMU_L2BANK_10 = 1<<10,
	CPMU_L2BANK_11 = 1<<11,
	CPMU_L2BANK_12 = 1<<12,
	CPMU_L2BANK_13 = 1<<13,
	CPMU_L2BANK_14 = 1<<14,
	CPMU_L2BANK_15 = 1<<15,
	CPMU_L2ALLBANKS = 0xFFFF
}CPMU_L2BankE;

typedef enum
{
	CPMU_L2BS_RETAIN_D0_D2 = 0,
	CPMU_L2BS_RETAIN_D0_NOT_D2,
	CPMU_L2BS_NOT_RETAIN_D0_D2
}CPMU_L2BankStateE;

typedef enum
{
	// the bits control thi functionality are in 2 different registers, so
	// serial numeration is accidental
	// for a fact numeration matches shifting to control bits in appropriate
	// registers
	CPMU_RD2R_VCC_SRAM = 16,   //CPCR
	CPMU_RD2R_VCC_COMM = 8,   //CPCR
	CPMU_RD2R_VCTCXO = 4,     // CPCR
	CPMU_RD2R_MEM_ARBEL = 2, // ITCM, DTCM/AHB DSRAM - CL1CR
	CPMU_RD2R_MEM_GB_L1= 1  // CL1CR
}CPMU_RetainInD2ResourceE;

typedef enum
{// to assemble a combination of any peripherals use logical "or" operator
	// enum numeration matches to appropriate control bits mask
	CPMU_PERIPHERAL_USIM	= 3<<0,
	//CPMU_PERIPHERAL_USB	= 3<<2, // this oeripheral isn't available
	CPMU_PERIPHERAL_GSSP2	= 3<<4, // ASSP
	CPMU_PERIPHERAL_GSSP1	= 3<<6, // SSP
	CPMU_PERIPHERAL_MSL		= 3<<8,
	CPMU_PERIPHERAL_I2C		= 3<<10,
	CPMU_ALL_2_RESET_ASSERTION_PER = 0xFF3,
	CPMU_PERIPHERAL_SELECT_0= 1<<12, // 6
	CPMU_PERIPHERAL_SELECT_1= 1<<13,
	CPMU_PERIPHERAL_SELECT_2= 1<<14,
	CPMU_PERIPHERAL_SELECT_3= 1<<15,
	CPMU_PERIPHERAL_SELECT_4= 1<<16,
	CPMU_PERIPHERAL_SELECT_5= 1<<17,
	CPMU_PERIPHERAL_SELECT_6= 1<<18,
	CPMU_PERIPHERAL_SELECT_7= 1<<19,
	//CPMU_PERIPHERAL_MODEMS= 1<<20  // this oeripheral isn't available
	CPMU_ALL_COMMON_RESET_ASSERTION_PER = 0xFF000,
	CPMU_ALL_REGULAR_PER = 0xFFF
}CPMU_PeripheralE;

typedef enum
{ // enum eumeration matches field value for suitable control bits
	// no power mode change
	//CPMU_PM_NO_CHANGE = 0,
	CPMU_PM_D0 = 0,
	// enter D2 state after both cores enter C1
	CPMU_PM_ENTER_D2_AFTER_BOTH_CORES_IN_C1,
	// enter D2 state after both cores enter C1 AND
	// the modem slow clock has bb_d2_entry_ok signal is asserted
	CPMU_PM_ENTER_D2_AFTER_BOTH_CORES_IN_C1_AND_MODEM_SIGNAL,
	// enter D4 state after both cores enter C1
	CPMU_PM_ENTER_D4_AFTER_BOTH_CORES_IN_C1
}CPMU_PowerModeE;

typedef enum
{
	CWESR_WAKE_UP_EN =1,
	CWESR_RST_STICKY ,
	SW_BIT_BOTH
} PmD2Swbits ;

// due to compiler warnings on enum with value of 0xffffffff - it is now a define.
#define 	CPMU_ENABLE		0xFFFFFFFF
#define		CPMU_DISABLE	0x00000000 

typedef UINT32	CPMU_State;

typedef enum
{// to assemble a combination of any events use
	// bitwise "or" operator
	CPMU_WAKEUP_UART_EVENT_0 = 1,      // reset bit WRST_WR/RD[5] 
	CPMU_WAKEUP_CGPIO_EVENT_1 = 1<<1,  // reset bit WRST_WR/RD[6]
	//CPMU_WAKEUP_GP_EVENT_2 = 1<<2,
	CPMU_WAKEUP_WBCDM_EVENT = 1<<2,
	//CPMU_WAKEUP_GP_EVENT_3 = 1<<3,
	CPMU_WAKEUP_GSSP1_EVENT = 1<<3,     // reset bit WRST_WR/RD[2]
	CPMU_WAKEUP_ACIPC_EVENT_4 = 1<<4,		// AC IPC from APPS
	//CPMU_WAKEUP_GP_EVENT_5 = 1<<5,
	CPMU_WAKEUP_GSSP2_EVENT = 1<<5,     // reset bit WRST_WR/RD[3]
	CPMU_WAKEUP_GP_EVENT_6 = 1<<6,
	//CPMU_WAKEUP_GP_EVENT_7 = 1<<7,
	CPMU_WAKEUP_USIM_EVENT = 1<<7,      // reset bit WRST_WR/RD[1]
	CPMU_WAKEUP_GP_EVENT_8 = 1<<8,      // not connected for A0
	CPMU_WAKEUP_GP_EVENT_9 = 1<<9,      // not connected for A0
	//CPMU_WAKEUP_GP_EVENT_10 = 1<<10,
	CPMU_WAKEUP_I2C_EVENT = 1<<10,     // common I2C for A0;   reset bit WRST_WR/RD[0]
	CPMU_WAKEUP_GP_EVENT_11 = 1<<11,    // not connected for A0
	CPMU_WAKEUP_GP_EVENT_12 = 1<<12,    // not connected for A0
	//CPMU_WAKEUP_GP_EVENT_13 = 1<<13,
	CPMU_WAKEUP_PMIC_EVENT = 1<<13,     // reset bit WRST_WR/RD[4]
	CPMU_WAKEUP_GP_EVENT_14 = 1<<14,
	CPMU_WAKEUP_GP_EVENT_15 = 1<<15,
	CPMU_WAKEUP_MSL_EVENT = 1<<16,      // reserved for A0
	CPMU_WAKEUP_TIMER_EVENT = 1<<17,
	CPMU_WAKEUP_WDT_EVENT = 1<<18,
	CPMU_WAKEUP_MODEM_SCK_EVENT = 1<<19,
	CPMU_WAKEUP_ALL_GP = 0xFFFF,
	CPMU_WAKEUP_ALL_ENABLE_DISABLE = 0x3FFFF,
#ifdef PHS_SW_DEMO_TTC_PM
	CPMU_NUMBER_OF_WAKEUP_SOURCES = 32
#else
	CPMU_NUMBER_OF_WAKEUP_SOURCES = 20
#endif
}CPMU_WakeUpEventE;


typedef enum
{// enum eumeration matches field value for suitable control bits
	CPMU_INTERRUPT_FREQUENCY_CHANGE		= 1,
	CPMU_INTERRUPT_PMIC					= 2,
	CPMU_INTERRUPT_DETECT_MODULE_CHANGE = 4
}CPMU_InterruptE;

typedef enum
{
	CPMU_EDGE_RISING = 0,     // positive
	CPMU_EDGE_FALLING,        // negative
	CPMU_EDGE_DONT_CARE
}CPMU_EdgeE;

typedef enum
{
	CPMU_RESET_BUS			= 2,
	CPMU_RESET_FUNCTIONAL	= 1,
	CPMU_RESET_BOTH			= 3,
	CPMU_RESET_DONT_CARE
}CPMU_ResetTypeE;

typedef enum
{
	CPMU_ET_WAKEUP_EVENT,
	CPMU_ET_INTERRUPT
}CPMU_EventTypeE;

typedef enum
{
	CPMU_RC_WRONG_PARAMETER,
	CPMU_RC_INTC_ERROR,
	CPMU_RC_OK
}CPMU_ReturnCodeE;

typedef enum
{
	// enum numeration matches numbers of appropriate bits in status register
	CPMU_EDR_WDT_ACTIVATION = 27,
	CPMU_EDR_WCDMA_MODEM = 5,
	CPMU_EDR_DDR = 4,
	CPMU_EDR_READ_DISABLE_HOLD = 3
}CPMU_EnableDisableResourcesE;

// TBD - Yohai
typedef enum
{
	// the enum numeration matches to a value of suitable control bits
	CPMU_PMIC_COMMAND_SET_0 = 0,
	CPMU_PMIC_COMMAND_SET_1,
	CPMU_PMIC_COMMAND_SET_2,
	CPMU_PMIC_COMMAND_SET_3
}CPMU_PMICCommandSetE;

// Reasons of Last Reset -
// TEMPORARY DEFINITION from previous version of module
typedef enum
{
	CPMU_LRR_COMM_SUBSYTEM_RESET = 0,
	CPMU_LRR_WATCHDOG_TIMEOUT_RESET,
	CPMU_LRR_D2_EXIT_RESET,
	CPMU_LRR_ERROR
}CPMU_LastResetReasonE;

typedef enum	
{
    CPMU_BIT_DISABLE = 0,
    CPMU_BIT_ENABLE,
   
}CPMU_Bit_StatusE;

// On A0 some bits PM related where added in different registres set at the top (not specific HW macro),
// add control to them ...
typedef enum	
{   //GPBMCSR(bit0) - 0
    CPMU_WB_GSM_TCU_CE_SEL = 0,  //TCU_CE_SEL (bit 0)
	//MVT_CTL (bit 0, 2, 3) - 1,2,3,4
	CPMU_WB_GSM_SLP_TIMER_SEL,            //SGW (bit 0)
	CPMU_GSM_STKY_RST,					  //GWE_STKY_RST (bit 2)
	CPMU_WB_SLEEP_MODULE_POLARITY_FIX,    //(not documented yet) (bit 3)
	//GPBMCSR (bit 1,2) - 6,7
	CPMU_UART_CLK_EN,					  //HUCE (bit1)
    CPMU_USIM_NMOS_DISENGAGE,             //UPEND (bit2)	
	CPMU_NUM_OF_CONROL_BITS			
}CPMU_Control_BitsE;
// TBD - adjust these definition with Raviv
typedef void (*CPMUL2PowerChangeNotifyFn)   (void);
typedef void (*CPMUPMICCOmmandSetNotifyFn)  (void);
typedef void (*CPMUFrequencyChangeNotifyFn) (void);


typedef         UINT32     CPMU_EventStatus;

typedef         UINT32     CPMU_L2Status;

typedef			UINT32     CPMU_WakeupEventCombination;

#define         CPMU_IS_THIS_EVENT_DETECTED(status, event)    (status & event)


//primary definition of CPMU API

// events
CPMU_EventStatus	CPMUEventDetect        (CPMU_EventTypeE				eventType);


void                CPMUEventStatusClear   (CPMU_EventTypeE             eventType,
													UINT32                      mask);

//CPCR
void                CPMUWCDMAPowerStateSet         (CPMU_State                 enableDisable);

void                CPMURetainResourceInD2StateSet
													(UINT32					    resource,
													CPMU_State                 enableDisable);

void                CPMUPowerModeSet               (CPMU_PowerModeE             mode);

// CPSR status
// pay attention this bit is only SW, without HW implication
void				CPMUEventTrackingFieldSet		(UINT8          			event  /*0-0xF*/);
UINT8               CPMUEventTrackingFieldGet       (void);

void 				CPMU_set_GPB_Users_Counter		(INT32	*pUserCount);

void				CPMUWDTControlBitSet            (CPMU_State				enableDisable);

CPMU_State         CPMUStateGet                    (CPMU_EnableDisableResourcesE  res);

//CPMU_State 		CPMUWDTControlBitGet            (void);
// end of SW bits

//CPMU_State         CPMUWCDMAPowerStateGet          (void);

//CPMU_State         CPMUDDRStateGet                 (void);

//CPMU_State         CPMUGPIOReadHoldStateGet        (void);

void                CPMUGPIOReadHoldStateClear      (void);

//CPR
BOOL                CPMUPMICIsCommandBeingRequested (void);

void                CPMUPMICCommandStatusClear      (void);

void                CPMUPMICCommandSetDetermine     (CPMU_PMICCommandSetE   set);

void                CPMUPMICCOmmandInD2StateSet     (CPMU_State              enableDisable);

// CWER
void                CPMUWakeupEventStateSet	        (CPMU_WakeupEventCombination			wakeupEvent,
													 CPMU_EdgeE					edge,
													 CPMU_State				enableDisable);

CPMU_State			CPMUWakeupEventStateGet			(CPMU_WakeUpEventE			wakeupEvent);
//CRAR
CPMU_ReturnCodeE	CPMUPeripheralHeldInResetStateSet
													(UINT32						peripheral,
													CPMU_ResetTypeE             reset,
													CPMU_State                 enableDisable);

//CIER
CPMU_ReturnCodeE   CPMUInterruptStateSet			(UINT32	interrupt,
													 CPMU_State enableDisable);

void			   CPMURegister 					(CPMUL2PowerChangeNotifyFn    l2PowerChangeNotifyFn,
													 CPMUPMICCOmmandSetNotifyFn   pmicCommnadSetNotifyFn,
													 CPMUFrequencyChangeNotifyFn  freqChangeNotifyFn);
void			   CPMUPhase1Init					(void);

CPMU_ReturnCodeE   CPMUPhase2Init					(void);

void               CPMUD1AutoEntyStateSet           (CPMU_State enableDisable);
void               CPMUExternalWakeUpControl        (CPMU_WakeUpEventE event, CPMU_State enableDisable);


//CGRAR, CCRAR
void               CPMUD2AddressSet                 (void* armD2ResetAddress,
                                                     void* gbD2ResetAddress);

void	CPMUControlBitSet (CPMU_Control_BitsE controlBit ,CPMU_Bit_StatusE enableDisable); //rafiagiv 27.12
CPMU_Bit_StatusE CPMUControlBitGet (CPMU_Control_BitsE controlBit);

void 	CPMUChangeCPCRVoltageLevelValue(CommCCU_SystemPLLFreqE FreqValue, UINT32 VoltageLevel);

void 	CPMUCwesrSwBitSet (PmD2Swbits Bit_num);

BOOL	CPMUUsimNmosEngageInUse(void);

void 	CpmuGetSysCOMMcapabilities (void);

void	CpmuWaitAndClearFreqChangeInt(void);


/**************************************************************************
*****************	Internal API used by COMM PM SW		*******************
**************************************************************************/
CPMU_ReturnCodeE CPMUGetLastResetReason(CPMU_LastResetReasonE *retVal);
CPMU_ReturnCodeE CPMUClearLastResetReason(void);
void CpmuSetD2FreqWithPP3VoltageLevel(void);
void commccuSetVoltageChangeInHW(CommCCU_SystemPLLFreqE Freq);

#endif //_CPMU_H_




