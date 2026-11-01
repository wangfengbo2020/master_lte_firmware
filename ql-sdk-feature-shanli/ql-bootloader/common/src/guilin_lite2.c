/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                guilin_lite2.c


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
#include "common.h"
#include "guilin_lite2.h"
#include "pmic.h"
//#include "UART.h"
//#include "bsp.h"

/*===========================================================================

            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains local definitions for constants, macros, types,
variables and other items needed by this module.

===========================================================================*/

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
/*      GuilinLite2Read                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function Read GuilinLite2 by PI2C interface.                      */
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
int GuilinLite2Read( GuilinLite2_Reg_Type guilin_lite2_reg_type, unsigned char reg, unsigned char *value )
{
    int res = 0;
	INT32	result;

    switch( guilin_lite2_reg_type )
    {
        case GUILIN_LITE2_BASE_Reg:
        {
            res = USTICAI2CReadDi_base(reg);
            GUILIN_LITE2_UART_DEBUG( "[%s] SLAVE=[BASE], REG=[0x%.2x] , VAL=[0x%.2x]", __FUNCTION__,reg,res);
            break;
        }

        case GUILIN_LITE2_POWER_Reg:
        {
            res = USTICAI2CReadDi_power(reg);
            GUILIN_LITE2_UART_DEBUG( "[%s] SLAVE=[POWER], REG=[0x%.2x] , VAL=[0x%.2x]", __FUNCTION__,reg,res);
            break;
        }

        default:
        {
            GUILIN_LITE2_UART_DEBUG( "[%s] UNKNOW TARGET REG", __FUNCTION__);
            break;
        }
    }

    *value = res;

    return 0;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      GuilinLite2Write                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function Write GuilinLite2 by PI2C interface.                     */
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
int GuilinLite2Write( GuilinLite2_Reg_Type guilin_lite2_reg_type, unsigned char reg, unsigned char value )
{
	INT32	result;

    switch( guilin_lite2_reg_type )
    {
        case GUILIN_LITE2_BASE_Reg:
        {
			USTICAI2CWriteDi_base(reg, value);
            GUILIN_LITE2_UART_DEBUG( "[%s] SLAVE=[BASE ], REG=[0x%.2x] , VAL=[0x%.2x]", __FUNCTION__,reg,value);
            break;
        }
        case GUILIN_LITE2_POWER_Reg:
        {
            USTICAI2CWriteDi_power(reg, value);
            GUILIN_LITE2_UART_DEBUG( "[%s] SLAVE=[POWER] , REG=[0x%.2x] , VAL=[0x%.2x]", __FUNCTION__,reg,value);
            break;
        }
        default:
        {
            GUILIN_LITE2_UART_DEBUG( "[%s] UNKNOW TARGET REG", __FUNCTION__);
            break;
        }
    }

    return 0;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      GuilinLite2ClkInit                                                    */
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
void GuilinLite2ClkInit( void )
{

}
void GuilinLite2_VBUCK1_Set_FPWM( void )
{
    unsigned char var = 0;

	//set fpwm mode for buck1, power page, @0x25[3]=1
    GuilinLite2Read( GUILIN_LITE2_POWER_Reg, GUILIN_LITE2_VBUCK1_FSM_REG4, &var );
	var |= 0x1<<3;
	GuilinLite2Write( GUILIN_LITE2_POWER_Reg, GUILIN_LITE2_VBUCK1_FSM_REG4, var );
}

//VBUCK FUNC
int GuilinLite2_VBUCK_Set_Enable(unsigned char reg, unsigned char enable){
		unsigned char tmp;

		//keep the ENABLE_BIT[6:0] as previous
		if(GUILIN_LITE2_CONTAIN_VBUCK_EN_BIT(reg))
		{
			GuilinLite2Read( GUILIN_LITE2_POWER_Reg, reg, &tmp );
			if(enable){
				tmp |= GUILIN_LITE2_VBUCK_ENABLE_MASK;
			}else{
				tmp &= ~GUILIN_LITE2_VBUCK_ENABLE_MASK;
			}
			return GuilinLite2Write( GUILIN_LITE2_POWER_Reg, reg, tmp );
		}
		else
		{
			GUILIN_LITE2_UART_DEBUG("[%s] ERROR REG=[0x%.2x]",__FUNCTION__,reg);
			return 1;
		}

}

int GuilinLite2_VBUCK_Set_Slpmode(unsigned char reg, unsigned char mode){
		unsigned char tmp;
		//keep other expect SLP_BIT[4:3]
		if(GUILIN_LITE2_CONTAIN_VBUCK_SLEEP_MODE_BIT(reg))
		{
			GuilinLite2Read( GUILIN_LITE2_POWER_Reg, reg, &tmp );
			tmp &= ~GUILIN_LITE2_VBUCK_SLEEP_MODE_MASK;
			tmp |= (mode & GUILIN_LITE2_VBUCK_SLEEP_MODE_MASK);
			return GuilinLite2Write( GUILIN_LITE2_POWER_Reg, reg, tmp );
		}
		else
		{
			GUILIN_LITE2_UART_DEBUG("[%s] ERROR REG=[0x%.2x]",__FUNCTION__,reg);
			return 1;
		}
}


int GuilinLite2_VBUCK_Set_VOUT(unsigned char reg, unsigned char value){
		unsigned char tmp;

		// keep the ENABLE_BIT as previous
		if(GUILIN_LITE2_CONTAIN_VBUCK_ACTIVE_VOUT_BIT(reg))
		{
			GuilinLite2Read( GUILIN_LITE2_POWER_Reg, reg, &tmp );
			tmp &= ~GUILIN_LITE2_CONTAIN_VBUCK_ACTIVE_VOUT_MASK;
			tmp |= (value & GUILIN_LITE2_CONTAIN_VBUCK_ACTIVE_VOUT_MASK);
		}
		//keep the DVC_ENABLE_BIT bit as previous
		else if(GUILIN_LITE2_CONTAIN_VBUCK_SLEEP_VOUT_BIT(reg))
		{
			GuilinLite2Read( GUILIN_LITE2_POWER_Reg, reg, &tmp );
			tmp &= ~GUILIN_LITE2_CONTAIN_VBUCK_SLEEP_VOUT_MASK;
			tmp |= (value & GUILIN_LITE2_CONTAIN_VBUCK_SLEEP_VOUT_MASK);
		}
		else{
			GUILIN_LITE2_UART_DEBUG("[%s] ERROR REG=[0x%.2x]",__FUNCTION__,reg);
			return 1;
		}
		return GuilinLite2Write( GUILIN_LITE2_POWER_Reg, reg, tmp );
}

//LDO FUNC
int GuilinLite2_LDO_Set_Enable(unsigned char reg, unsigned char enable){
		unsigned char tmp;

		//keep the ENABLE_BIT[5:0] as previous
		if(GUILIN_LITE2_CONTAIN_LDO_EN_BIT(reg))
		{
			GuilinLite2Read( GUILIN_LITE2_POWER_Reg, reg, &tmp );
			if(enable){
				tmp |= GUILIN_LITE2_LDO_ENABLE_MASK;
			}else{
				tmp &= ~GUILIN_LITE2_LDO_ENABLE_MASK;
			}
			return GuilinLite2Write( GUILIN_LITE2_POWER_Reg, reg, tmp );
		}
		else
		{
			GUILIN_LITE2_UART_DEBUG("[%s] ERROR REG=[0x%.2x]",__FUNCTION__,reg);
			return 1;
		}
}

int GuilinLite2_LDO_Set_Slpmode(unsigned char reg, unsigned char mode){
		unsigned char tmp;

		//keep the SLP_MODE[3:0]
		if(GUILIN_LITE2_CONTAIN_LDO_SLEEP_MODE_BIT(reg))
		{
			GuilinLite2Read( GUILIN_LITE2_POWER_Reg, reg, &tmp );
			mode &= GUILIN_LITE2_LDO_SLEEP_MODE_MASK;
			tmp &= ~GUILIN_LITE2_LDO_SLEEP_MODE_MASK;
			tmp |= mode;
			return GuilinLite2Write( GUILIN_LITE2_POWER_Reg, reg, tmp );
		}
		else
		{
			GUILIN_LITE2_UART_DEBUG("[%s] ERROR REG=[0x%.2x]",__FUNCTION__,reg);
			return 1;
		}
}

int GuilinLite2_LDO_Set_VOUT(unsigned char reg, unsigned char value){
		unsigned char tmp;

		if(GUILIN_LITE2_CONTAIN_LDO_ACTIVE_VOUT_BIT(reg))
		{
			GuilinLite2Read( GUILIN_LITE2_POWER_Reg, reg, &tmp );
			tmp &= ~GUILIN_LITE2_LDO_ACTIVE_VOUT_MASK;
			tmp |= (value & GUILIN_LITE2_LDO_ACTIVE_VOUT_MASK);
		}
		else if(GUILIN_LITE2_CONTAIN_LDO_SLEEP_VOUT_BIT(reg))
		{
			GuilinLite2Read( GUILIN_LITE2_POWER_Reg, reg, &tmp );
			tmp &= ~GUILIN_LITE2_LDO_SLEEP_VOUT_MASK;
			tmp |= (value & GUILIN_LITE2_LDO_SLEEP_VOUT_MASK);
		}else{
			GUILIN_LITE2_UART_DEBUG("[%s] ERROR REG=[0x%.2x]",__FUNCTION__,reg);
			return 1;
		}
		return GuilinLite2Write( GUILIN_LITE2_POWER_Reg, reg, tmp );
}

//ICAT EXPORTED FUNCTION - PMIC,GUILIN_LITE2,SW_reset
int GuilinLite2_SW_Reset(void){
	unsigned char tmp;

	//set discharge_time to 0
	GuilinLite2Read( GUILIN_LITE2_BASE_Reg,  GUILIN_LITE2_RESET_DISCHARGE_REG , &tmp);
	tmp &= ~GUILIN_LITE2_RESET_DISCHARGE_MASK;
	GuilinLite2Write( GUILIN_LITE2_BASE_Reg, GUILIN_LITE2_RESET_DISCHARGE_REG, tmp);

	//set fault_wu_en then set fault_wu
	GuilinLite2Read(  GUILIN_LITE2_BASE_Reg, GUILIN_LITE2_FAULT_WU_REG, &tmp);
	GuilinLite2Write( GUILIN_LITE2_BASE_Reg, GUILIN_LITE2_FAULT_WU_REG, (tmp|GUILIN_LITE2_FAULT_WU_ENABLE_BIT));
	GuilinLite2Read(  GUILIN_LITE2_BASE_Reg, GUILIN_LITE2_FAULT_WU_REG, &tmp);
	GuilinLite2Write( GUILIN_LITE2_BASE_Reg, GUILIN_LITE2_FAULT_WU_REG, (tmp|GUILIN_LITE2_FAULT_WU_BIT));

	//force a software powerdown
	GUILIN_LITE2_UART_DEBUG( "PMIC Reset......");
	GuilinLite2Read(  GUILIN_LITE2_BASE_Reg, GUILIN_LITE2_RESET_REG ,&tmp );
	GuilinLite2Write( GUILIN_LITE2_BASE_Reg, GUILIN_LITE2_RESET_REG ,(tmp | GUILIN_LITE2_SW_PDOWN_BIT));

    return 0;
}

void GuilinLite2_VBUCK1_CFG(UINT8 value)
{
    if ((value < GUILIN_LITE2_VBUCK_0V50)||(value > GUILIN_LITE2_VBUCK_1V20))
    {
        GUILIN_LITE2_UART_DEBUG("Wrong buck1 value input!\r\n");
        return;
    }
    GuilinLite2_VBUCK_Set_VOUT(GUILIN_LITE2_VBUCK1_ACTIVE_VOUT_REG,value);
}

void GuilinLite2_Ldo_6_set_2_8(void)
{
    GuilinLite2_LDO_Set_VOUT(GUILIN_LITE2_LDO6_ACTIVE_VOUT_REG, GUILIN_LITE2_LDO6_ACTIVE_2V80);
}

void GuilinLite2_Ldo_6_set(BOOL OnOff)
{
	GuilinLite2_LDO_Set_Enable(GUILIN_LITE2_LDO6_ENABLE_REG,OnOff);
}

void GuilinLite2_Ldo_3_set_1_8(void)
{
	GuilinLite2_LDO_Set_VOUT(GUILIN_LITE2_LDO3_ACTIVE_VOUT_REG,GUILIN_LITE2_LDO3_ACTIVE_1V80);
}

void GuilinLite2_Ldo_3_set_3_0(void)
{
    GuilinLite2_LDO_Set_VOUT(GUILIN_LITE2_LDO3_ACTIVE_VOUT_REG, GUILIN_LITE2_LDO3_ACTIVE_3V00);
}

void GuilinLite2_Ldo_3_set(BOOL OnOff)
{
	GuilinLite2_LDO_Set_Enable(GUILIN_LITE2_LDO3_ENABLE_REG,OnOff);
}


#define GUILIN_LITE2_EN_VINLDO_SNS_MASK 0x30
void SetRatioDivResTo803L(unsigned char ratio)
{
    unsigned char var;

    GuilinLite2Read(GUILIN_LITE2_BASE_Reg, 0x1D, &var);

    if (ratio == 0)
        var &= ~GUILIN_LITE2_EN_VINLDO_SNS_MASK;
    else
        var |= ratio;

    GuilinLite2Write(GUILIN_LITE2_BASE_Reg, 0x1D, var);
}
void SetRatioDivRes(unsigned char ratio)
{
    ratio = (ratio << 4) & GUILIN_LITE2_EN_VINLDO_SNS_MASK;
    SetRatioDivResTo803L(ratio);
}


