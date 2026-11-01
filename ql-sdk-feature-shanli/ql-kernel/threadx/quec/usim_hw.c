/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/******************************************************************************
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
 * Title: USIM Hardware implementation file
 *
 * Filename: usim_hw.c
 *
 * Author: Eilam Ben-Dror
 *
 * Description: This file contains macros and functions which control the HW.
 *
 * Last Updated: 14-Dec-2005
 *
 *****************************************************************************/

/*----------- Local include files -------------------------------------------*/
#define _USIM_HW_NO_EXTERN_
#include "usim_hw.h"
#undef _USIM_HW_NO_EXTERN_

#include "bsp.h"
#include "usim.h"
#include "usim_dl.h"

#include "timer.h"
#include "diag.h"
#if defined USIM_USE_TRACE
#include "platform_nvm.h"
#endif /* USIM_USE_TRACE */
#if !defined(_HERMON_B0_SILICON_)
#include "miccoConfig.h"
#include "bsp_config.h"
#endif
#include "PMChip.h"
#if defined(_HERMON_B0_SILICON_)
#include "bsp_mux.h"
#endif
#include "utils.h"
#if 1 //def  _TAVOR_HARBELL_
#include "commpm.h"
#endif
#include "pmic.h"
#include "main.h"
#include "guilin.h"
#include "ningbo.h"
#include "guilin_lite.h"
#include "guilin_lite2.h"
#include "quec_cust_patch.h"
/*----------- Local defines -------------------------------------------------*/
// Define the resolution of the timer used in timerDelay:
#define USIM_TIMER_DELAY_RESOLUTION	64
// Length of reset delay time, in usec (or mksec or 10e-6):
#define USIM_RESET_DELAY_USEC(c) ((4000 / _USIMatrInfos[c].cardClock) + USIM_TIMER_DELAY_RESOLUTION)

// Deactivation delay in usec:
#define USIM_DEACTIVATE_DELAY_USEC(c) ((2000 / _USIMatrInfos[c].cardClock) + USIM_TIMER_DELAY_RESOLUTION)

#define USIM_HW_DELAY_USEC(card,cycles) ((cycles *10 / _USIMatrInfos[card].cardClock) + 2)

#define USIM_DUMMY_DELAY { volatile unsigned int i_temp;for (i_temp=0;i_temp<1000;i_temp++);}

/* CLKR of UICC interface can be updated only, when RQST Bit =0
 * we are waiting when this bit will be cleared. During read Dummy read executed
 * when MAX count reached, we assuming HW fail of UICC
 *
*/
#define USIM_CLOCK_REQ_MAX      200
#define USIM_CLOCK_REQ_PRINT    3

//#if defined (_TAVOR_HARBELL_) || defined(SILICON_PV2)
#if defined(SILICON_PV2)
#define timerDelay     timerDelayLite
#endif

extern void PM812_Ldo_4_set_1_8(void);
extern void PM812_Ldo_4_set_3_0(void);
extern void PM812_Ldo_4_set(BOOL OnOff);
extern void PM812_Ldo_10_set_1_8(void);
extern void PM812_Ldo_10_set_3_0(void);
extern void PM812_Ldo_10_set(BOOL OnOff);
extern void AIB_Secure_Write(unsigned int address, unsigned int value);
extern UINT32 AIB_Secure_Read(unsigned int address);
extern unsigned char pmic_id;

extern BOOL   GLFeatureFlag;
/*----------- Local variable definitions ------------------------------------*/

extern UINT32 usim_swap_flag;

// Currently used voltage class
USIM_Class _USIMcurrentVoltageClass[USIM_CARDS_AMOUNT];




void USIM_Power_set_one(BOOL onOff)
{
	switch (PMIC_ID_GET())
	{
	#if !defined(NOT_SUPPORT_PM813)
		case PMIC_813:
		case PMIC_813A3:
		case PMIC_813S:
			Ningbo_Ldo_3_set(onOff);
			break;
	#endif

	#if !defined(NOT_SUPPORT_PM802)
		case PMIC_802:
		case PMIC_802S:
			Guilin_Ldo_3_set(onOff);
			break;
	#endif
			
		case PMIC_803:
			GuilinLite_Ldo_3_set(onOff);
			break;
        case PMIC_803L:
            GuilinLite2_Ldo_3_set(onOff);
            break;
		default:
			ASSERT(0);
			break;
	}


	if(CHIP_IS_CRANEG || CHIP_IS_CRANEM || CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR)
	{
		if(onOff==FALSE)
		{
			AIB_USIM1_IO_Set_3_3V();
		}
	}


}


void USIM_Power_set_two(BOOL onOff)
{
	switch (PMIC_ID_GET())
	{
#if !defined(NOT_SUPPORT_PM813)
		case PMIC_813:
		case PMIC_813A3:
		case PMIC_813S:
			Ningbo_Ldo_8_set(onOff);
			break;
#endif
#if !defined(NOT_SUPPORT_PM802)
		case PMIC_802:
		case PMIC_802S:
			Guilin_Ldo_4_set(onOff);
			break;
#endif
		case PMIC_803:
			#if  !(defined (__QUECTEL_PROJECT_EC800MCN_GA__ ) || defined(__QUECTEL_PROJECT_EG810MCN_GA__) \
			|| defined (__QUECTEL_PROJECT_EC800MCN_GM__ )||defined (__QUECTEL_PROJECT_EC800MCN_GC__ )\
			||defined (__QUECTEL_PROJECT_EC800MCN_GD__ )|| defined (__QUECTEL_PROJECT_EC800MCN_GB__)\
			|| defined (__QUECTEL_PROJECT_EG810MCN_GB__))
			#ifndef QUEC_OEM_VER_SIMB
				GuilinLite_Ldo_8_set(onOff);
			#endif
			#endif
			break;
		default:
			ASSERT(0);
			break;
	}

	if(CHIP_IS_CRANEG || CHIP_IS_CRANEM || CHIP_IS_CRANEL || CHIP_IS_CRANELS)
	{
		if(onOff==FALSE)
		{
			AIB_USIM2_IO_Set_3_3V();
		}
	}



}


void USIM_Power_set(USIM_Card card, BOOL onOff)
{

	if(card==USIM_COM_CARD)
	{
		if(usim_swap_flag == 0)
			USIM_Power_set_one(onOff);
		else
			USIM_Power_set_two(onOff);
	}

#ifdef USIM_DSDS_DKB

	if(card==USIM_BANKING_CARD)
	{
		if(usim_swap_flag == 0)
			USIM_Power_set_two(onOff);
		else
			USIM_Power_set_one(onOff);
	}

#endif

}


void USIM_Power_set_Value_one(USIM_Class voltageClass)
{

	if(voltageClass == USIM_CLASS_B)
	{
        switch (PMIC_ID_GET())
        {
            #if !defined(NOT_SUPPORT_PM813)
            case PMIC_813:
            case PMIC_813A3:
            case PMIC_813S:
                Ningbo_Ldo_3_set_3_0();
                break;
            #endif

			#if !defined(NOT_SUPPORT_PM802)
            case PMIC_802:
            case PMIC_802S:
                Guilin_Ldo_3_set_3_0();
                break;
			#endif
				
            case PMIC_803:
                GuilinLite_Ldo_3_set_3_0();
                break;
            case PMIC_803L:
                GuilinLite2_Ldo_3_set_3_0();
                break;
            default:
                ASSERT(0);
                break;
        }
	}
	else
	{
        switch (PMIC_ID_GET())
        {
            #if !defined(NOT_SUPPORT_PM813)
            case PMIC_813:
            case PMIC_813A3:
            case PMIC_813S:
                Ningbo_Ldo_3_set_1_8();
                break;
            #endif

			#if !defined(NOT_SUPPORT_PM802)
            case PMIC_802:
            case PMIC_802S:
                Guilin_Ldo_3_set_1_8();
                break;
			#endif
			
            case PMIC_803:
                GuilinLite_Ldo_3_set_1_8();
                break;
            case PMIC_803L:
                GuilinLite2_Ldo_3_set_1_8();
                break;
            default:
                ASSERT(0);
                break;
        }
    }

}



void USIM_Power_set_Value_two(USIM_Class voltageClass)
{
	if(voltageClass == USIM_CLASS_B)
	{
        switch (PMIC_ID_GET())
        {
            #if !defined(NOT_SUPPORT_PM813)
            case PMIC_813:
            case PMIC_813A3:
            case PMIC_813S:
                Ningbo_Ldo_8_set_3_0();
                break;
            #endif

			#if !defined(NOT_SUPPORT_PM802)
            case PMIC_802:
            case PMIC_802S:
                Guilin_Ldo_4_set_3_0();
                break;
			#endif
			
            case PMIC_803:
				#if  !(defined (__QUECTEL_PROJECT_EC800MCN_GA__ ) || defined(__QUECTEL_PROJECT_EG810MCN_GA__) \
				|| defined (__QUECTEL_PROJECT_EC800MCN_GM__ )||defined (__QUECTEL_PROJECT_EC800MCN_GC__ )\
				||defined (__QUECTEL_PROJECT_EC800MCN_GD__ )|| defined (__QUECTEL_PROJECT_EC800MCN_GB__)\
				|| defined (__QUECTEL_PROJECT_EG810MCN_GB__))
				#ifndef QUEC_OEM_VER_SIMB
                	GuilinLite_Ldo_8_set_3_0();
				#endif
				#endif
                break;
            default:
                ASSERT(0);
                break;
        }
	}
	else
	{
        switch (PMIC_ID_GET())
        {
            #if !defined(NOT_SUPPORT_PM813)
            case PMIC_813:
            case PMIC_813A3:
            case PMIC_813S:
                Ningbo_Ldo_8_set_1_8();
                break;
            #endif

			#if !defined(NOT_SUPPORT_PM802)
            case PMIC_802:
            case PMIC_802S:
                Guilin_Ldo_4_set_1_8();
                break;
			#endif
			
            case PMIC_803:
				#if  !(defined (__QUECTEL_PROJECT_EC800MCN_GA__ ) || defined(__QUECTEL_PROJECT_EG810MCN_GA__) \
				|| defined (__QUECTEL_PROJECT_EC800MCN_GM__ )||defined (__QUECTEL_PROJECT_EC800MCN_GC__ )\
				||defined (__QUECTEL_PROJECT_EC800MCN_GD__ )|| defined (__QUECTEL_PROJECT_EC800MCN_GB__)\
				|| defined (__QUECTEL_PROJECT_EG810MCN_GB__))
				#ifndef QUEC_OEM_VER_SIMB
                	GuilinLite_Ldo_8_set_1_8();
				#endif
				#endif
                break;
            default:
                ASSERT(0);
                break;
        }
    }
	
}




void USIM_Power_set_Value(USIM_Card card,USIM_Class voltageClass)
{
	if(card==USIM_COM_CARD)
	{
		if(usim_swap_flag == 0)
			USIM_Power_set_Value_one(voltageClass);
		else
			USIM_Power_set_Value_two(voltageClass);
	}

#ifdef USIM_DSDS_DKB

	if(card==USIM_BANKING_CARD)
	{
		if(usim_swap_flag == 0)
			USIM_Power_set_Value_two(voltageClass);
		else
			USIM_Power_set_Value_one(voltageClass);
	}

#endif
		
}




 /*****************************************************************************
 * Function     :	USIM_HW_RXRead
 ******************************************************************************
 *
 * Description  :	Reads data received from the card.
 *
 * Parameters   :	length - the number of bytes to be read.
 *					buffer - a buffer in which the data will be written
 *					card - the required USIM card
 *
 * Output Param :	None
 *
 * Return value :	None
 *
 * Notes:
 *****************************************************************************/
void USIM_HW_RXRead(USIM_Card card, UINT32 length, UINT8 * buffer)
{
	usim_record_event(card, USIM_EVT_USIM_HW_RXRead_001);
	for(;length; length--, buffer++)
	{
		*buffer = (UINT8)USIMHWRegisters[card]->RBR;
		usim_record_one_data(card, *buffer);

	}
	return;
}

void USIM_HW_RXRead_Dummy(USIM_Card card, UINT32 length)
{

	for(;length; length--)
	{
		*(_USIMrxBufferPtrs[card]) = (UINT8)USIMHWRegisters[card]->RBR;
	}
	return;
}



 /*****************************************************************************
 * Function     :	USIM_HW_TXWrite
 ******************************************************************************
 *
 * Description  :	Writes data to the TX FIFO, to be transmitted to the card.
 *
 * Parameters   :	length - the number of bytes to be written.
 *					buffer - a buffer which contains the data to be written.
 *					card - the required USIM card
 *
 * Output Param :	None
 *
 * Return value :	None
 *
 * Notes:
 *****************************************************************************/
void USIM_HW_TXWrite(USIM_Card card, UINT32 length, UINT8 * buffer)
{
	usim_record_event(card, USIM_EVT_USIM_HW_TXWrite_001);
	for(;length; length--, buffer++)
	{
		USIMHWRegisters[card]->THR = (UINT32)*buffer;
		usim_record_one_data(card, *buffer);
	}
	return;
}



 /*****************************************************************************
 * Function     :	USIM_HW_RXLevelSet
 ******************************************************************************
 *
 * Description  :	Sets the level of the Data Ready interrupt.
 *
 * Parameters   :	level - the required level.
 *					card - the required USIM card
 *
 * Return value :	None
 *
 * Notes:
 *****************************************************************************/
void USIM_HW_RXLevelSet(USIM_Card card, USIM_HW_RDRLevel level)
{
	switch (level)
	{
	case USIM_HW_1B:	USIMHWRegisters[card]->FCR &= 0x010CL;
						break;

	case USIM_HW_4B:	USIMHWRegisters[card]->FCR &= 0x014CL;
						USIMHWRegisters[card]->FCR |= 0x040L;
						break;

	case USIM_HW_8B:	USIMHWRegisters[card]->FCR &= 0x018CL;
						USIMHWRegisters[card]->FCR |= 0x080L;
						break;

	case USIM_HW_12B:	USIMHWRegisters[card]->FCR |= 0x0C0L;
						break;

	default:			// like 1B
						USIMHWRegisters[card]->FCR &= 0x010CL;
						break;
	}

}



/******************************************************************************
* Function:		USIM_HW_deactivate
*******************************************************************************
* Description:	Deactivates the card.
*
* Parameters:	card - the required USIM card
*
* Return value: None
*
* Notes:
******************************************************************************/
void USIM_HW_deactivate(USIM_Card card, BOOL shutDown)
{

	DIAG_FILTER(USIMLOG,USIM_HW_deactivate,LOG001,DIAG_INFORMATION)
	diagPrintf("USIM_HW_deactivate %u, shutDown=%lx", card, shutDown);

	USIM_CARD_RESET(card);

    timerDelay(USIM_TIMER_DELAY_RESOLUTION); /* wait for the minimum delay */

    /* hypotetic scenario, abnormal case */
    /* USIM Clock Stopped on high(1) level, needs to start clocksl */
    if (USIM_CARD_CLOCK_STOP_LEVEL_GET(card) &&    USIM_CARD_CLOCK_STOP_GET(card)  )
    {
        if ((USIM_CARD_CLOCK_STOP_CLCK_USIM_GET(card)) != FALSE)
            usim_hw_clk_onoff(card, USIM_HW_CLOCK_START_REQ);
    	USIM_HW_cardClockRequest(card, USIM_HW_CLOCK_START_REQ);
    }

	if (USIM_CARD_CLOCK_STOP_GET(card) == 0)
	{
		USIM_CARD_CLOCK_STOP_LEVEL_LOW(card);

    	USIM_HW_cardClockRequest(card, USIM_HW_CLOCK_STOP_REQ);
	}
#if 0
	if(shutDown == FALSE)  // in shut down the LDO would be disabled by the phone
	{
		USIM_TXD_FORCE_SET(card);
	}
#endif
    // clear all interrupts:
    USIM_CLEAR_ALL(card);

    // disable USIM interrupts:
    USIM_DISABLE_ALL(card);

    usim_hw_clk_onoff(card, USIM_HW_CLOCK_STOP_REQ);

	// wait for the delay:
    timerDelay(USIM_DEACTIVATE_DELAY_USEC(card));
	USIM_TXD_FORCE_SET(card);
	timerDelay(USIM_DEACTIVATE_DELAY_USEC(card));

	USIM_VOLTAGE_SET(card, 0);

	if(shutDown == TRUE)  // in shut down the LDO would be disabled by the phone
	{
		USIM_Power_set(card,FALSE);
	}

	_USIMcurrentVoltageClass[card] = USIM_CLASS_NULL;

} /* End of USIM_HW_deactivate */


/******************************************************************************
* Function:		USIM_HW_cardReset
*******************************************************************************
* Description:	Activates the card.
*
* Parameters:	card - the required USIM card
*               voltageClass - the voltage class to be set
*
* Return value: None
*
* Notes:
******************************************************************************/

#define AIB_USIM_1_IO_REG_ADDR_CRANE    0xD401E81C
#define AIB_USIM_1_IO_REG_ADDR          0xD401E82C
#define AIB_USIM_2_IO_REG_ADDR 0xD401E804


void AIB_USIM1_IO_Set_1_8V(void)
{
    volatile unsigned int val = 0;

    if (CHIP_IS_CRANE)
    {
        val = AIB_Secure_Read(AIB_USIM_1_IO_REG_ADDR_CRANE); //AIB_USIM_1_IO_REG_CRANE
        val |= (0x4);
    	val &= ~(0x8);
        AIB_Secure_Write(AIB_USIM_1_IO_REG_ADDR_CRANE, val);
    }
    else
    {
        val = AIB_Secure_Read(AIB_USIM_1_IO_REG_ADDR); //AIB_USIM1_IO_REG
		if (CHIP_IS_CRANEG_Z1)
			val |= (0x8); //0--> 3.3V enable, 1-->1.8V enable
		else
			val |= (0x4); //0--> 3.3V enable, 1-->1.8V enable
        AIB_Secure_Write(AIB_USIM_1_IO_REG_ADDR, val);
    }
}


void AIB_USIM1_IO_Set_3_3V(void)
{
    volatile unsigned int val = 0;

    if (CHIP_IS_CRANE)
    {
        val = AIB_Secure_Read(AIB_USIM_1_IO_REG_ADDR_CRANE); //AIB_USIM_1_IO_REG_CRANE
        val &= ~(0x4);
        val &= ~(0x8);
        AIB_Secure_Write(AIB_USIM_1_IO_REG_ADDR_CRANE, val);
    }
    else
    {
        val = AIB_Secure_Read(AIB_USIM_1_IO_REG_ADDR); //AIB_USIM1_IO_REG
		if (CHIP_IS_CRANEG_Z1)
			val &= ~(0x8);	
		else
			val &= ~(0x4);
        AIB_Secure_Write(AIB_USIM_1_IO_REG_ADDR, val);
    }
}


void AIB_USIM2_IO_Set_1_8V(void)
{
    volatile unsigned int val = 0;

    val = AIB_Secure_Read(AIB_USIM_2_IO_REG_ADDR); //AIB_USIM1_IO_REG
	if (CHIP_IS_CRANEG_Z1)
	{
		val |= (0x8); //0--> 3.3V enable, 1-->1.8V enable
	}
	else
	{
	    val |= (0x4); 
		val &= ~(0x8);
	}
    AIB_Secure_Write(AIB_USIM_2_IO_REG_ADDR, val);
}


void AIB_USIM2_IO_Set_3_3V(void)
{
    volatile unsigned int val = 0;

    val = AIB_Secure_Read(AIB_USIM_2_IO_REG_ADDR); //AIB_USIM1_IO_REG
	
	if (CHIP_IS_CRANEG_Z1)
	{
		val &= ~(0x8);
	}
	else
	{	
	
	    val &= ~(0x4);
		val &= ~(0x8);
	}
    AIB_Secure_Write(AIB_USIM_2_IO_REG_ADDR, val);
}




void USIM_HW_cardReset(USIM_Card card, USIM_Class voltageClass)
{



#ifndef PLAT_AQUILAC
	*(volatile unsigned int*)0xD401E320=0xD8C0;
	*(volatile unsigned int*)0xD401E324=0xD8C0;
	*(volatile unsigned int*)0xD401E328=0xD8C0;
#endif

	DIAG_FILTER(USIMLOG, USIM_HW_cardReset, LOG001, DIAG_INFORMATION)
	diagPrintf("USIM_HW_cardReset %lu, voltageClass=%lx, _USIMcurrentVoltageClass=%lx", card, voltageClass, _USIMcurrentVoltageClass[card]);
	USIM_CARD_RESET(card);

	if(voltageClass != _USIMcurrentVoltageClass[card])
	{/* Cold Reset: */

		// set the card voltage:
		USIM_VOLTAGE_SET(card, voltageClass);
		/*------- Tavor ----------*/
		//bspUSIMPinNMOS ( USIM_NMOS_ENGAGE );
#if 0
#if defined(USIM_NMOS_CONTROL)
		CommpmUsimNmosEngageSet (COMMPM_NMOS_ENGAGE);
#endif
#endif

#if defined(USIM_PMC_LDO_ENABLED_ON_BOOT)

		if (_SIMFirstTimePowered[card])
		{
			DIAG_FILTER(USIMLOG, USIM_HW_cardReset, LOG002, DIAG_INFORMATION)
			diagPrintf("USIM_HW_cardReset %lu, PMIC_DisableUsimV, _SIMFirstTimePowered", card);
			_SIMFirstTimePowered[card] = FALSE;
		}
		else
#endif
		{
			USIM_Power_set(card,FALSE);
			OSATaskSleep (3);

			DIAG_FILTER(USIMLOG, USIM_HW_cardReset, LOG003, DIAG_INFORMATION)
			diagPrintf("USIM_HW_cardReset %lu, PMIC_DisableUsimV, Not _SIMFirstTimePowered", card);
		}

		USIM_Power_set_Value(card,voltageClass);



		if(voltageClass == USIM_CLASS_B)
		{
			if(usim_swap_flag == 0)
			{
				if(card==USIM_COM_CARD)
					AIB_USIM1_IO_Set_3_3V();
				else
					AIB_USIM2_IO_Set_3_3V();
			}
			else
			{
				if(card==USIM_COM_CARD)
					AIB_USIM2_IO_Set_3_3V();
				else
					AIB_USIM1_IO_Set_3_3V();
			}

		}
		else  //Class C
		{
			if(usim_swap_flag == 0)
			{
				if(card==USIM_COM_CARD)
					AIB_USIM1_IO_Set_1_8V();
				else
					AIB_USIM2_IO_Set_1_8V();
			}
			else
			{
				if(card==USIM_COM_CARD)
					AIB_USIM2_IO_Set_1_8V();
				else
					AIB_USIM1_IO_Set_1_8V();

			}
		}

		OSATaskSleep (40);

		USIM_Power_set(card,TRUE);

		DIAG_FILTER(USIMLOG, USIM_HW_cardReset, LOG004, DIAG_INFORMATION)
		diagPrintf("USIM_HW_cardReset %lu, PMIC_EnableUsimV", card);
#if 0
#if defined(USIM_NMOS_CONTROL)
		CommpmUsimNmosEngageSet (COMMPM_NMOS_DISENGAGE);
#endif
#endif

		OSATaskSleep(2);

		// allow I/O line to return to Vhigh:
		USIM_TXD_FORCE_CLEAR(card);

		OSATaskSleep(5);
		usim_hw_clk_onoff(card, USIM_HW_CLOCK_START_REQ);


		USIM_HW_cardClockRequest(card, USIM_HW_CLOCK_START_REQ);

		// update current voltage class:
		_USIMcurrentVoltageClass[card] = voltageClass;
	}

	// wait for the delay:
	timerDelay(USIM_RESET_DELAY_USEC(card));

	OSATaskSleep (40);
	
	// un-reset the card:
	USIM_CARD_UNRESET(card);


} /* End of USIM_HW_cardReset */






/******************************************************************************
* Function:		USIM_HW_init
*******************************************************************************
* Description:	Initializes the structure containing the register addresses
*
* Parameters:	None
*
* Return value: None
*
* Notes:
******************************************************************************/
void USIM_HW_init(void)
{

}


/******************************************************************************
* Function:     USIM_HW_Delay
*******************************************************************************
* Description:  Sets a BWT interrupt to occur after the given number of clock
*               cycles
*
* Parameters:   card
*               clockCycles - the required number of card clock cycles
*
* Return value: None
*
* Notes:
******************************************************************************/
BOOL USIM_HW_Delay(USIM_Card card, UINT32 clockCycles, UINT32 disIntMode)
{
    UINT32 F = (UINT32)(_USIMatrInfos[card].conversionFactor);
    UINT32 D = (UINT32)(_USIMatrInfos[card].adjustmentFactor);
    UINT32 flags = 0;
    UINT32 timeInETU = (((D * clockCycles) / F) & 0xFFFF) + 1;
	UINT32 cpsrReg;

    if((disIntMode == 1) /*|| (_USIMstates[card] == USIM_REMOVED)*/)
    {   //Use simple delay with blocking
        timerDelay(USIM_HW_DELAY_USEC(card,clockCycles));
        return FALSE;
    }

    OSAFlagWait(_USIMflagsRefs[card], 0xFFFFFFFF, OSA_FLAG_OR_CLEAR, &flags, OSA_NO_SUSPEND);


    if (USIM_DL_CheckFlagSetState(card, flags))
        return TRUE;

    // Set the required CWT:
    USIMHWRegisters[card]->CWTR = timeInETU;

    _USIMisDelaySet[card] = TRUE;

	cpsrReg = disableInterrupts(); //lock

	//Trigger the counting:
    USIM_DIVISOR_SET(card, USIM_DIVISOR_GET(card));

    //Enable the CWT interrupt:
    USIM_ENABLE_MASK(card,USIM_CWT_MASK);

	// Clear current CWT interrupt indication (if any)
	USIM_INTERRUPT_CLEAR(card, USIM_CWT);

	restoreInterrupts(cpsrReg); //unlock

	// Wait
    OSAFlagWait(_USIMflagsRefs[card],
                (USIM_CLOCK_STOP_FLAG | USIM_DEACTIVATE_FLAG | USIM_CARD_REMOVED_FLAG | USIM_WDT_TIMER_FLAG),
                OSA_FLAG_OR_CLEAR,
                &flags,
                OSA_SUSPEND);

    // Set the previous CWT:
    USIM_CHAR_WAIT_TIME_SET(card, _USIMatrInfos[card].protocol, _USIMatrInfos[card].charWaitingTime);


    return (USIM_DL_CheckFlagSetState(card, flags));
}

BOOL  USIM_HW_checkClock(USIM_Card card)
{
	UINT32 timeout=0;

	UINT32 flag=0;
	while(USIM_CARD_CLOCK_CHANGE_GET(card)!=0)
	{
		timeout++;
		//USIM_DUMMY_READ(card);
	    //timerDelay(USIM_TIMER_DELAY_RESOLUTION); /* wait for the minimum delay */

		if(timeout>10)
	{
			flag=1;
			USIM_TXD_FORCE_SET(card);

			DIAG_FILTER(USIMLOG, USIM_HW_checkClock, LOG001, DIAG_INFORMATION)
			diagPrintf("USIM_HW_checkClock Timeout %d", timeout); 
			OSATaskSleep(1);
		}
	}

	if(flag==1)
		USIM_TXD_FORCE_CLEAR(card);
	return 0;
}

BOOL USIM_HW_cardClockRequest(USIM_Card card, USIM_HW_ClockReqType reqType)
{
	BOOL rc = USIM_HW_checkClock(card);

	if(reqType == USIM_HW_CLOCK_STOP_REQ)
	{
        USIM_CARD_CLOCK_STOP_REQ(card);
	}
	else /* USIM_HW_CLOCK_START_REQ */
	{
        USIM_CARD_CLOCK_START_REQ(card);
	}
    return (/*USIM_HW_checkClock(card) ||*/rc);
}

/* Stop USIM HW Interface internal clocks(!) */
void usim_hw_clk_onoff(USIM_Card card, USIM_HW_ClockReqType reqType)
{
	USIM_HW_checkClock(card);

	if(reqType == USIM_HW_CLOCK_STOP_REQ)
	{
        USIM_CARD_CLOCK_STOP_CLCK_USIM(card);
	}
	else /* USIM_HW_CLOCK_START_REQ */
	{
        USIM_CARD_CLOCK_START_CLCK_USIM(card);
	}
    //USIM_HW_checkClock(card) ;
}
