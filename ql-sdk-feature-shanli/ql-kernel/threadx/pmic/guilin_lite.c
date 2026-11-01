/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                GuilinLite.c


GENERAL DESCRIPTION

    This file is for ASR I2C package.

EXTERNALIZED FUNCTIONS

INITIALIZATION AND SEQUENCING REQUIREMENTS

   Copyright (c) 2017 by ASR, Incorporated.  All Rights Reserved.
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when         who        what, where, why
--------   ------     ----------------------------------------------------------
03/07/2018   Qianying    Created module
===========================================================================*/

/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/

#include "guilin_lite.h"
#include "pmic.h"
#include "UART.h"
#include "diag.h"
#include "ripc.h"
#include "bsp.h"

/*===========================================================================

            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains local definitions for constants, macros, types,
variables and other items needed by this module.

===========================================================================*/
Pmic_Int_Handler mGuilinLiteIntHandler [GUILIN_LITE_INTC_MAX+1];

/*===========================================================================

            EXTERN DEFINITIONS AND DECLARATIONS FOR MODULE

===========================================================================*/

/*===========================================================================

                          INTERNAL FUNCTION DEFINITIONS

===========================================================================*/

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      GuilinLiteRead                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function Read GuilinLite by PI2C interface.                      */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
int GuilinLiteRead( GuilinLite_Reg_Type guilin_lite_reg_type, unsigned char reg, unsigned char *value )
{
    int res = 0;
	INT32	result;

	result = Get_RIPC_ustica(3,200);
	if (result == RIPC_FAILURE)
		ASSERT(0);

    switch( guilin_lite_reg_type )
    {
        case GUILIN_LITE_BASE_Reg:
        {
            res = USTICAI2CReadDi_base(reg);
            GUILIN_LITE_UART_DEBUG( "[%s] SLAVE=[BASE], REG=[0x%.2x] , VAL=[0x%.2x]", __FUNCTION__,reg,res);
            break;
        }

        case GUILIN_LITE_POWER_Reg:
        {
            res = USTICAI2CReadDi_power(reg);
            GUILIN_LITE_UART_DEBUG( "[%s] SLAVE=[POWER], REG=[0x%.2x] , VAL=[0x%.2x]", __FUNCTION__,reg,res);
            break;
        }

        default:
        {
            GUILIN_LITE_UART_DEBUG( "[%s] UNKNOW TARGET REG", __FUNCTION__);
            break;
        }
    }

	Release_RIPC_ustica(3);

    *value = res;

    return 0;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      GuilinLiteWrite                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function Write GuilinLite by PI2C interface.                     */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
int GuilinLiteWrite( GuilinLite_Reg_Type guilin_lite_reg_type, unsigned char reg, unsigned char value )
{
	INT32	result;

	result = Get_RIPC_ustica(3,200);
	if (result == RIPC_FAILURE)
		ASSERT(0);

    switch( guilin_lite_reg_type )
    {
        case GUILIN_LITE_BASE_Reg:
        {
			USTICAI2CWriteDi_base(reg, value);
            GUILIN_LITE_UART_DEBUG( "[%s] SLAVE=[BASE ], REG=[0x%.2x] , VAL=[0x%.2x]", __FUNCTION__,reg,value);
            break;
        }
        case GUILIN_LITE_POWER_Reg:
        {
            USTICAI2CWriteDi_power(reg, value);
            GUILIN_LITE_UART_DEBUG( "[%s] SLAVE=[POWER] , REG=[0x%.2x] , VAL=[0x%.2x]", __FUNCTION__,reg,value);
            break;
        }
        default:
        {
            GUILIN_LITE_UART_DEBUG( "[%s] UNKNOW TARGET REG", __FUNCTION__);
            break;
        }
    }

	Release_RIPC_ustica(3);

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//enable/disable the  INT report to master processer
static void GuilinLite_INT_TO_HOST_ENABLE(GUILIN_LITE_INTC intc)
{
	UINT8 reg_addr = GUILIN_LITE_INTC_TO_ENABLE_REG(intc);
	UINT8 tmp = PMIC_READ_REG_BASE(reg_addr);
	tmp |= GUILIN_LITE_INTC_TO_ENABLE_BIT(intc);
	PMIC_WRITE_REG_BASE(reg_addr,tmp);
}
static void GuilinLite_INT_TO_HOST_DISABLE(GUILIN_LITE_INTC intc)
{
	UINT8 reg_addr = GUILIN_LITE_INTC_TO_ENABLE_REG(intc);
	UINT8 tmp = PMIC_READ_REG_BASE(reg_addr);
	tmp &= (~(GUILIN_LITE_INTC_TO_ENABLE_BIT(intc)));
	PMIC_WRITE_REG_BASE(reg_addr,tmp);
}

void GuilinLite_INT_DISABLE(GUILIN_LITE_INTC intc)
{
	uart_printf("[%s] intc=[%d]\r\n",__func__,intc);
	mGuilinLiteIntHandler[intc].pmic_intc_enabled = FALSE;
	GuilinLite_INT_TO_HOST_DISABLE(intc);
}

void GuilinLite_INT_ENABLE(GUILIN_LITE_INTC intc)
{
	uart_printf("[%s]  intc=[%d]\r\n",__func__,intc);
	mGuilinLiteIntHandler[intc].pmic_intc_enabled = TRUE;
	GuilinLite_INT_TO_HOST_ENABLE(intc);
}

void GuilinLite_INT_CALLBACK_REGISTER(GUILIN_LITE_INTC intc,PmicCallback isr)
{
	uart_printf("[%s] intc=[%d] , isr=[%x]\r\n",__func__,intc,isr);
	mGuilinLiteIntHandler[intc].pmic_isr = isr;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      GuilinLiteDisableWDT                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function Disable Watchdog of Ustia.                          */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      meas_val                            The 12bit ADC value          */
/*                                                                       */
/*************************************************************************/
//BIT_0 = 0	:	WD_ENABLE
//BIT_0 = 1	:	WD_DISABLE
void GuilinLiteDisableWDT( void )
{
    unsigned char var = 0;

    GuilinLiteRead( GUILIN_LITE_BASE_Reg, GUILIN_LITE_WD_REG, &var );

    /* Disable Watchdog functoin.       */
    var |= GUILIN_LITE_WD_DIS;

    GuilinLiteWrite( GUILIN_LITE_BASE_Reg, GUILIN_LITE_WD_REG, var );
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      GuilinLiteClkInit                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function initialize the Ustia clock.                         */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      meas_val                            The 12bit ADC value          */
/*                                                                       */
/*************************************************************************/
void GuilinLiteClkInit( void )
{

}
void GuilinLite_VBUCK1_Set_FPWM( void )
{
    unsigned char var = 0;

	//set fpwm mode for buck1, power page, @0x25[3]=1
    GuilinLiteRead( GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_FSM_REG4, &var );
	var |= 0x1<<3;
	GuilinLiteWrite( GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_FSM_REG4, var );
}

//VBUCK FUNC
int GuilinLite_VBUCK_Set_DVC_Enable(unsigned char reg, unsigned char enable){
		unsigned char tmp;

		//keep the ENABLE_BIT[6:0] as previous
		if(GUILIN_LITE_CONTAIN_VBUCK_DVC_EN_BIT(reg))
		{
			GuilinLiteRead( GUILIN_LITE_POWER_Reg, reg, &tmp );
			if(enable){
				tmp |= GUILIN_LITE_VBUCK_ENABLE_DVC_MASK;
			}else{
				tmp &= ~GUILIN_LITE_VBUCK_ENABLE_DVC_MASK;
			}
			return GuilinLiteWrite( GUILIN_LITE_POWER_Reg, reg, tmp );
		}
		else
		{
			GUILIN_LITE_UART_DEBUG("[%s] ERROR REG=[0x%.2x]",__FUNCTION__,reg);
			return 1;
		}

}



//VBUCK FUNC
int GuilinLite_VBUCK_Set_Enable(unsigned char reg, unsigned char enable){
		unsigned char tmp;

		//keep the ENABLE_BIT[6:0] as previous
		if(GUILIN_LITE_CONTAIN_VBUCK_EN_BIT(reg))
		{
			GuilinLiteRead( GUILIN_LITE_POWER_Reg, reg, &tmp );
			if(enable){
				tmp |= GUILIN_LITE_VBUCK_ENABLE_MASK;
			}else{
				tmp &= ~GUILIN_LITE_VBUCK_ENABLE_MASK;
			}
			return GuilinLiteWrite( GUILIN_LITE_POWER_Reg, reg, tmp );
		}
		else
		{
			GUILIN_LITE_UART_DEBUG("[%s] ERROR REG=[0x%.2x]",__FUNCTION__,reg);
			return 1;
		}

}

int GuilinLite_VBUCK_Set_Slpmode(unsigned char reg, unsigned char mode){
		unsigned char tmp;
		//keep other expect SLP_BIT[4:3]
		if(GUILIN_LITE_CONTAIN_VBUCK_SLEEP_MODE_BIT(reg))
		{
			GuilinLiteRead( GUILIN_LITE_POWER_Reg, reg, &tmp );
			tmp &= ~GUILIN_LITE_VBUCK_SLEEP_MODE_MASK;
			tmp |= (mode & GUILIN_LITE_VBUCK_SLEEP_MODE_MASK);
			return GuilinLiteWrite( GUILIN_LITE_POWER_Reg, reg, tmp );
		}
		else
		{
			GUILIN_LITE_UART_DEBUG("[%s] ERROR REG=[0x%.2x]",__FUNCTION__,reg);
			return 1;
		}
}


int GuilinLite_VBUCK_Set_VOUT(unsigned char reg, unsigned char value){
		unsigned char tmp;

		// keep the ENABLE_BIT as previous
		if(GUILIN_LITE_CONTAIN_VBUCK_ACTIVE_VOUT_BIT(reg))
		{
			GuilinLiteRead( GUILIN_LITE_POWER_Reg, reg, &tmp );
			tmp &= ~GUILIN_LITE_CONTAIN_VBUCK_ACTIVE_VOUT_MASK;
			tmp |= (value & GUILIN_LITE_CONTAIN_VBUCK_ACTIVE_VOUT_MASK);
		}
		//keep the DVC_ENABLE_BIT bit as previous
		else if(GUILIN_LITE_CONTAIN_VBUCK_SLEEP_VOUT_BIT(reg))
		{
			GuilinLiteRead( GUILIN_LITE_POWER_Reg, reg, &tmp );
			tmp &= ~GUILIN_LITE_CONTAIN_VBUCK_SLEEP_VOUT_MASK;
			tmp |= (value & GUILIN_LITE_CONTAIN_VBUCK_SLEEP_VOUT_MASK);
		}
		else if(GUILIN_LITE_CONTAIN_VBUCK_DVC_VOUT_BIT(reg))
		{
			GuilinLiteRead( GUILIN_LITE_POWER_Reg, reg, &tmp );
			tmp &= ~GUILIN_LITE_CONTAIN_VBUCK_DVC_VOUT_MASK;
			tmp |= (value & GUILIN_LITE_CONTAIN_VBUCK_DVC_VOUT_MASK);
		}else{
			GUILIN_LITE_UART_DEBUG("[%s] ERROR REG=[0x%.2x]",__FUNCTION__,reg);
			return 1;
		}
		return GuilinLiteWrite( GUILIN_LITE_POWER_Reg, reg, tmp );
}

//LDO FUNC
int GuilinLite_LDO_Set_Enable(unsigned char reg, unsigned char enable){
		unsigned char tmp;

		//keep the ENABLE_BIT[5:0] as previous
		if(GUILIN_LITE_CONTAIN_LDO_EN_BIT(reg))
		{
			GuilinLiteRead( GUILIN_LITE_POWER_Reg, reg, &tmp );
			if(enable){
				tmp |= GUILIN_LITE_LDO_ENABLE_MASK;
			}else{
				tmp &= ~GUILIN_LITE_LDO_ENABLE_MASK;
			}
			return GuilinLiteWrite( GUILIN_LITE_POWER_Reg, reg, tmp );
		}
		else
		{
			GUILIN_LITE_UART_DEBUG("[%s] ERROR REG=[0x%.2x]",__FUNCTION__,reg);
			return 1;
		}
}

int GuilinLite_LDO_Set_Slpmode(unsigned char reg, unsigned char mode){
		unsigned char tmp;

		//keep the SLP_MODE[3:0]
		if(GUILIN_LITE_CONTAIN_LDO_SLEEP_MODE_BIT(reg))
		{
			GuilinLiteRead( GUILIN_LITE_POWER_Reg, reg, &tmp );
			mode &= GUILIN_LITE_LDO_SLEEP_MODE_MASK;
			tmp &= ~GUILIN_LITE_LDO_SLEEP_MODE_MASK;
			tmp |= mode;
			return GuilinLiteWrite( GUILIN_LITE_POWER_Reg, reg, tmp );
		}
		else
		{
			GUILIN_LITE_UART_DEBUG("[%s] ERROR REG=[0x%.2x]",__FUNCTION__,reg);
			return 1;
		}
}

int GuilinLite_LDO_Set_VOUT(unsigned char reg, unsigned char value){
		unsigned char tmp;

		if(GUILIN_LITE_CONTAIN_LDO_ACTIVE_VOUT_BIT(reg))
		{
			GuilinLiteRead( GUILIN_LITE_POWER_Reg, reg, &tmp );
			tmp &= ~GUILIN_LITE_LDO_ACTIVE_VOUT_MASK;
			tmp |= (value & GUILIN_LITE_LDO_ACTIVE_VOUT_MASK);
		}
		else if(GUILIN_LITE_CONTAIN_LDO_SLEEP_VOUT_BIT(reg))
		{
			GuilinLiteRead( GUILIN_LITE_POWER_Reg, reg, &tmp );
			tmp &= ~GUILIN_LITE_LDO_SLEEP_VOUT_MASK;
			tmp |= (value & GUILIN_LITE_LDO_SLEEP_VOUT_MASK);
		}else{
			GUILIN_LITE_UART_DEBUG("[%s] ERROR REG=[0x%.2x]",__FUNCTION__,reg);
			return 1;
		}
		return GuilinLiteWrite( GUILIN_LITE_POWER_Reg, reg, tmp );
}

//ICAT EXPORTED FUNCTION - PMIC,GUILIN_LITE,SW_reset
int GuilinLite_SW_Reset(void){
	unsigned char tmp;

	//set discharge_time to 0
	GuilinLiteRead( GUILIN_LITE_BASE_Reg,  GUILIN_LITE_RESET_DISCHARGE_REG , &tmp);
	tmp &= ~GUILIN_LITE_RESET_DISCHARGE_MASK;
	GuilinLiteWrite( GUILIN_LITE_BASE_Reg, GUILIN_LITE_RESET_DISCHARGE_REG, tmp);

	//set fault_wu_en then set fault_wu
	GuilinLiteRead(  GUILIN_LITE_BASE_Reg, GUILIN_LITE_FAULT_WU_REG, &tmp);
	GuilinLiteWrite( GUILIN_LITE_BASE_Reg, GUILIN_LITE_FAULT_WU_REG, (tmp|GUILIN_LITE_FAULT_WU_ENABLE_BIT));
	GuilinLiteRead(  GUILIN_LITE_BASE_Reg, GUILIN_LITE_FAULT_WU_REG, &tmp);
	GuilinLiteWrite( GUILIN_LITE_BASE_Reg, GUILIN_LITE_FAULT_WU_REG, (tmp|GUILIN_LITE_FAULT_WU_BIT));

	//force a software powerdown
	GUILIN_LITE_UART_DEBUG( "PMIC Reset......");
	GuilinLiteRead(  GUILIN_LITE_BASE_Reg, GUILIN_LITE_RESET_REG ,&tmp );
	GuilinLiteWrite( GUILIN_LITE_BASE_Reg, GUILIN_LITE_RESET_REG ,(tmp | GUILIN_LITE_SW_PDOWN_BIT));

    return 0;
}

//ICAT EXPORTED FUNCTION - PMIC,GUILIN_LITE,Dump_REG
void GuilinLite_Dump_PMIC_Register(void)
{
    unsigned char var,count;

    GUILIN_LITE_UART_DEBUG( "====================================GUILIN_LITE BASE PAGE============================");
	for(count=0x01; count<=0xf7; count++){GuilinLiteRead( GUILIN_LITE_BASE_Reg, count, &var );GUILIN_LITE_UART_DEBUG( "[BASE	]ADDR=[0x%.2x] VAL=[0x%.2x]",count,var); }
    GUILIN_LITE_UART_DEBUG( "====================================GUILIN_LITE POWER PAGE============================");
	for(count=0x01; count<=0xf7; count++){GuilinLiteRead( GUILIN_LITE_POWER_Reg, count, &var );GUILIN_LITE_UART_DEBUG( "[POWER	]ADDR=[0x%.2x] VAL=[0x%.2x]",count,var); }
}

extern unsigned char CRN_SVC_FP[];

void GuilinLite_Aditional_Workaround(void)
{
/* [1] set pwr_hold bit
   PAGE	: BASE_PAGE
   ADDR	: 0x0D
   VAL	: BIT_7 = 1	*/

   unsigned char var;
   GuilinLiteRead(GUILIN_LITE_BASE_Reg, GUILIN_LITE_PWR_HOLD_REG, &var);
   GuilinLiteWrite(GUILIN_LITE_BASE_Reg, GUILIN_LITE_PWR_HOLD_REG, (var|GUILIN_LITE_PWR_HOLD_BIT));

    GuilinLiteRead(GUILIN_LITE_BASE_Reg, GUILIN_LITE_RTC_CTRL_REG, &var);
    GuilinLiteWrite(GUILIN_LITE_BASE_Reg, GUILIN_LITE_RTC_CTRL_REG, (var|(GUILIN_LITE_RTC_DIS_ALARM_PULLDOWN_BIT
                                                                        |GUILIN_LITE_RTC_OTP_RELOAD_DISABLE_BIT)));


   /** change switch freq to improve rf performance **/
   GuilinLiteRead(GUILIN_LITE_BASE_Reg, 0xEC, &var);
   GuilinLiteWrite(GUILIN_LITE_BASE_Reg, 0xEC, (var | 0x02));

#if 1
    GuilinLite_VBUCK1_Set_Skip_Mode(1); //set buck1 to skip mode for better power ripple
#else
    GuilinLiteRead(GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_FSM_REG3, &var);
    var |= (0x1<<4); //enable external fpwm
    GuilinLiteWrite(GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_FSM_REG3, var);
#endif
    GuilinLiteWrite( GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_DVC_VOUT_REG_SET0, CRN_SVC_FP[0] );//416
    GuilinLiteWrite( GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_DVC_VOUT_REG_SET1, CRN_SVC_FP[1] );//499
    GuilinLiteWrite( GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_DVC_VOUT_REG_SET2, CRN_SVC_FP[2] );//624
    GuilinLiteWrite( GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_DVC_VOUT_REG_SET3, CRN_SVC_FP[3] );//832

    GuilinLiteRead( GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_SLEEP_VOUT_REG, &var );
    GuilinLiteWrite( GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_SLEEP_VOUT_REG, (var|(0x1<<7))); //enable DVC_buck1

#if 1 //to disable LDO5 under pmic power down
	/*
	*	config switch of ldo5/ldo5x :
	*	10: switch to ldo5	关机RTC无供电
	*	11: switch to ldo5x 关机RTC有供电
	*	0*: ldo5/ldo5x switch is controlled by hardware  此种模式关机默认ldo5x,关机rtc供电
	*	default 使用LDO5，关机不供电
	*/
		GuilinLiteRead(GUILIN_LITE_BASE_Reg, 0xF1, &var);
		GuilinLiteWrite(GUILIN_LITE_BASE_Reg, 0xF1, (var|(0x02<<6)));
#endif

}

void GuilinLite_VBUCK1_CFG(UINT8 value)
{
    if ((value < GUILIN_LITE_VBUCK_0V8000)||(value > GUILIN_LITE_VBUCK_1V2000))
    {
        fatal_printf("Wrong buck1 value input!\r\n");
        return;
    }
    GuilinLite_VBUCK_Set_VOUT(GUILIN_LITE_VBUCK1_ACTIVE_VOUT_REG,value);
}

//ICAT EXPORTED FUNCTION - SW_PLAT, PM803, Vcore0V90
void PM803_Buck1_Config0V90(void)
{
    GuilinLite_VBUCK1_CFG(GUILIN_LITE_VBUCK_0V9000);
    #if GUILIN_LITE_DEBUG
	DIAG_FILTER(SW_PLAT, PM803, PM803_Buck1_Config0V90, DIAG_INFORMATION)
	diagPrintf ("buck1 set val 0.90V.");
	#endif
}

//ICAT EXPORTED FUNCTION - SW_PLAT, PM803, Vcore0V95
void PM803_Buck1_Config0V95(void)
{
    GuilinLite_VBUCK1_CFG(GUILIN_LITE_VBUCK_0V9500);
    #if GUILIN_LITE_DEBUG
	DIAG_FILTER(SW_PLAT, PM803, PM803_Buck1_Config0V95, DIAG_INFORMATION)
	diagPrintf ("buck1 set val 0.95V.");
	#endif
}

//ICAT EXPORTED FUNCTION - SW_PLAT, PM803, Vcore1V00
void PM803_Buck1_Config1V00(void)
{
    GuilinLite_VBUCK1_CFG(GUILIN_LITE_VBUCK_1V0000);
    #if GUILIN_LITE_DEBUG
	DIAG_FILTER(SW_PLAT, PM803, PM803_Buck1_Config1V00, DIAG_INFORMATION)
	diagPrintf ("buck1 set val 1.00V.");
	#endif
}

//ICAT EXPORTED FUNCTION - SW_PLAT, PM803, Vcore1V05
void PM803_Buck1_Config1V05(void)
{
    GuilinLite_VBUCK1_CFG(GUILIN_LITE_VBUCK_1V0500);
    #if GUILIN_LITE_DEBUG
	DIAG_FILTER(SW_PLAT, PM803, PM803_Buck1_Config1V05, DIAG_INFORMATION)
	diagPrintf ("buck1 set val 1.05V.");
	#endif
}

//ICAT EXPORTED FUNCTION - SW_PLAT, PM803, Vcore1V10
void PM803_Buck1_Config1V10(void)
{
    GuilinLite_VBUCK1_CFG(GUILIN_LITE_VBUCK_1V1000);
    #if GUILIN_LITE_DEBUG
	DIAG_FILTER(SW_PLAT, PM803, PM803_Buck1_Config1V10, DIAG_INFORMATION)
	diagPrintf ("buck1 set val 1.10V.");
	#endif
}

//ICAT EXPORTED FUNCTION - SW_PLAT, PM803, Vcore1V15
void PM803_Buck1_Config1V15(void)
{
    GuilinLite_VBUCK1_CFG(GUILIN_LITE_VBUCK_1V1500);
    #if GUILIN_LITE_DEBUG
	DIAG_FILTER(SW_PLAT, PM803, PM803_Buck1_Config1V15, DIAG_INFORMATION)
	diagPrintf ("buck1 set val 1.15V.");
	#endif
}

//ICAT EXPORTED FUNCTION - SW_PLAT, PM803, Vcore1V20
void PM803_Buck1_Config1V20(void)
{
    GuilinLite_VBUCK1_CFG(GUILIN_LITE_VBUCK_1V2000);
    #if GUILIN_LITE_DEBUG
	DIAG_FILTER(SW_PLAT, PM803, PM803_Buck1_Config1V20, DIAG_INFORMATION)
	diagPrintf ("buck1 set val 1.20V.");
	#endif
}

void GuilinLite_Ldo_6_set_2_8(void)
{
    GuilinLite_LDO_Set_VOUT(GUILIN_LITE_LDO6_ACTIVE_VOUT_REG, GUILIN_LITE_LDO6_ACTIVE_2V80);
    #if GUILIN_LITE_DEBUG
    DIAG_FILTER(HAL, PM803, PM803_LDO6_2V8, DIAG_INFORMATION)
    diagPrintf("GuilinLite_Ldo_6_set_2_8");
    #endif
}

void GuilinLite_Ldo_6_set(BOOL OnOff)
{
	GuilinLite_LDO_Set_Enable(GUILIN_LITE_LDO6_ENABLE_REG,OnOff);
}

void GuilinLite_Ldo_7_set_3_3(void)
{
    GuilinLite_LDO_Set_VOUT(GUILIN_LITE_LDO7_ACTIVE_VOUT_REG, GUILIN_LITE_LDO7_ACTIVE_3V30);
    #if GUILIN_LITE_DEBUG
    DIAG_FILTER(HAL, PM803, PM803_LDO7_3V3, DIAG_INFORMATION)
    diagPrintf("GuilinLite_Ldo_7_set_3_3");
    #endif
}
void GuilinLite_Ldo_7_set_2_8(void)
{
    GuilinLite_LDO_Set_VOUT(GUILIN_LITE_LDO7_ACTIVE_VOUT_REG, GUILIN_LITE_LDO7_ACTIVE_2V80);
    #if GUILIN_LITE_DEBUG
    DIAG_FILTER(HAL, PM803, PM803_LDO7_2V8, DIAG_INFORMATION)
    diagPrintf("GuilinLite_Ldo_7_set_2_8");
    #endif
}

void GuilinLite_Ldo_7_set_1_8(void)
{
    GuilinLite_LDO_Set_VOUT(GUILIN_LITE_LDO7_ACTIVE_VOUT_REG, GUILIN_LITE_LDO7_ACTIVE_1V80);
    #if GUILIN_LITE_DEBUG
    DIAG_FILTER(HAL, PM803, PM803_LDO7_1V8, DIAG_INFORMATION)
    diagPrintf("GuilinLite_Ldo_7_set_1_8");
    #endif
}

void GuilinLite_Ldo_7_set_1_2(void)
{
    GuilinLite_LDO_Set_VOUT(GUILIN_LITE_LDO7_ACTIVE_VOUT_REG, GUILIN_LITE_LDO7_ACTIVE_1V20);
    #if GUILIN_LITE_DEBUG
    DIAG_FILTER(HAL, PM803, PM803_LDO7_1V2, DIAG_INFORMATION)
    diagPrintf("GuilinLite_Ldo_7_set_1_28");
    #endif
}


void GuilinLite_Ldo_7_set(BOOL OnOff)
{
	GuilinLite_LDO_Set_Enable(GUILIN_LITE_LDO7_ENABLE_REG,OnOff);
}

void GuilinLite_Ldo_3_set_1_8(void)
{
	GuilinLite_LDO_Set_VOUT(GUILIN_LITE_LDO3_ACTIVE_VOUT_REG,GUILIN_LITE_LDO3_ACTIVE_1V80);
	#if GUILIN_LITE_DEBUG
	DIAG_FILTER(HAL, PM803, PM803_LDO3_1V8, DIAG_INFORMATION)
	diagPrintf("GuilinLite_Ldo_3_set_1_8");
	#endif
}

void GuilinLite_Ldo_3_set_3_0(void)
{
    GuilinLite_LDO_Set_VOUT(GUILIN_LITE_LDO3_ACTIVE_VOUT_REG, GUILIN_LITE_LDO3_ACTIVE_3V00);
    #if GUILIN_LITE_DEBUG
    DIAG_FILTER(HAL, PM803, PM803_LDO3_3V0, DIAG_INFORMATION)
    diagPrintf("GuilinLite_Ldo_3_set_3_0");
    #endif
}

void GuilinLite_Ldo_3_set(BOOL OnOff)
{
	GuilinLite_LDO_Set_Enable(GUILIN_LITE_LDO3_ENABLE_REG,OnOff);
}

void GuilinLite_Ldo_8_set_1_8(void)
{
	GuilinLite_LDO_Set_VOUT(GUILIN_LITE_LDO8_ACTIVE_VOUT_REG,GUILIN_LITE_LDO8_ACTIVE_1V80);
	#if GUILIN_LITE_DEBUG
	DIAG_FILTER(HAL, PM803, PM803_LDO8_1V8, DIAG_INFORMATION)
	diagPrintf("GuilinLite_Ldo_8_set_1_8");
	#endif
}

void GuilinLite_Ldo_8_set_3_0(void)
{
    GuilinLite_LDO_Set_VOUT(GUILIN_LITE_LDO8_ACTIVE_VOUT_REG, GUILIN_LITE_LDO8_ACTIVE_3V00);
    #if GUILIN_LITE_DEBUG
    DIAG_FILTER(HAL, PM803, PM803_LDO8_3V0, DIAG_INFORMATION)
    diagPrintf("GuilinLite_Ldo_8_set_3_0");
    #endif
}
#if 1
void GuilinLite_Ldo_8_set_3_3(void)
{
    GuilinLite_LDO_Set_VOUT(GUILIN_LITE_LDO8_ACTIVE_VOUT_REG, GUILIN_LITE_LDO8_ACTIVE_3V30);
    #if GUILIN_LITE_DEBUG
    DIAG_FILTER(HAL, PM803, PM803_LDO8_3V3, DIAG_INFORMATION)
    diagPrintf("GuilinLite_Ldo_8_set_3_3");
    #endif
}
#endif
void GuilinLite_Ldo_8_set_2_8(void)
{
    GuilinLite_LDO_Set_VOUT(GUILIN_LITE_LDO8_ACTIVE_VOUT_REG, GUILIN_LITE_LDO8_ACTIVE_2V80);
    DIAG_FILTER(HAL, PM803, PM803_LDO8_3V0, DIAG_INFORMATION)
    diagPrintf("GuilinLite_Ldo_8_set_2_8");
}

void GuilinLite_Ldo_8_set(BOOL OnOff)
{
	GuilinLite_LDO_Set_Enable(GUILIN_LITE_LDO8_ENABLE_REG,OnOff);
}

void GuilinLite_Ldo_11_set_1_2(void)
{
	GuilinLite_LDO_Set_VOUT(GUILIN_LITE_LDO11_ACTIVE_VOUT_REG,GUILIN_LITE_LDO2_ACTIVE_1V20);
}

void GuilinLite_Ldo_11_set(BOOL OnOff)
{
	GuilinLite_LDO_Set_Enable(GUILIN_LITE_LDO11_ACTIVE_VOUT_REG,OnOff);
}
void GuilinLite_PowerSave_Config(void)
{
	volatile unsigned char val;

	// VBUCK1 sleep voltage
	GuilinLiteRead(GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_SLEEP_MODE_REG, (unsigned char *)(&val));
	val &= ~(0x3 << 3);
	val |= (0x2 << 3);
	GuilinLiteWrite(GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_SLEEP_MODE_REG, val);

	GuilinLiteRead(GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_SLEEP_VOUT_REG, (unsigned char *)(&val));
	val &= ~0x7F;
    if (IsChipCraneLS() || IsChipCrane()) {
        val |= CHIP_IS_CRANE? GUILIN_LITE_VBUCK_0V7000: GUILIN_LITE_VBUCK_0V6000;
    } else {
        val |= CHIP_IS_CRANE? GUILIN_LITE_VBUCK_0V7000: GUILIN_LITE_VBUCK_0V6500;
    }
	GuilinLiteWrite(GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_SLEEP_VOUT_REG, val);

    GuilinLite_LDO_Set_Slpmode(GUILIN_LITE_LDO1_SLEEP_MODE_REG, GUILIN_LITE_LDO_SLEEP);
    GuilinLite_LDO_Set_VOUT(GUILIN_LITE_LDO1_SLEEP_VOUT_REG, GUILIN_LITE_LDO1_SLEEP_1V80); //set ldo1(rf_switch) sleep mode to save power.
}

void GuilinLite_VBUCK1_Set_Skip_Mode(unsigned char OnOff)
{
    unsigned char tmp;

    GuilinLiteRead(GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_FSM_REG1, &tmp);
    if (OnOff)
        GuilinLiteWrite(GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_FSM_REG1, (tmp|GUILIN_LITE_VBUCK_SKIP_MODE));
    else
        GuilinLiteWrite(GUILIN_LITE_POWER_Reg, GUILIN_LITE_VBUCK1_FSM_REG1, (tmp&~GUILIN_LITE_VBUCK_SKIP_MODE));
}

static UINT8 guilinLiteLcdLightEnabled = FALSE;

static UINT8 guilinLiteLcdLightLevel = 0xFF;


UINT8 PM803_LcdBacklight_Level_Get(void)
{
    return guilinLiteLcdLightLevel;
}

UINT8 PM803_LcdBacklight_Status_Get(void)
{
    return guilinLiteLcdLightEnabled;
}


