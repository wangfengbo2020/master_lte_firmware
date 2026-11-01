/*===================================================================================================================
  Copyright (c) 2022 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
========================================================================================================================*/
/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
2022/04/26       Sharon.li   此文件用于实现boot侧/logo侧的ADC读取，(Vbatt ADC 和 对外ADC)
2022/04/06       Sharon.li   仅仅实现 ASR-1606-QUECTEL-ECxxxxM 平台
==========================================================================================================================*/


#include "quec_cust_startup_feature.h"
#include "ql_boot_adc.h"
#include "ningbo.h"
#include "guilin.h"

#ifdef QUECTEL_OPEN_CPU


#if 0
	//#define uart_dbg_log(msg,...)   custom_log("GPIO",msg,##__VA_ARGS__)
#else
	#define ql_adc_log(fmt, args...)	uart_printf("[%s][%d]"fmt, __FUNCTION__, __LINE__, ##args)
#endif


/******************************************************************
*	 Global Variable
******************************************************************/


/******************************************************************
*	 Functions
******************************************************************/










/*===========================================================================

FUNCTION ql_adc_init

DESCRIPTION
  ADC driver init. 

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
int ql_adc_init(void)
{
	//Todo...
	
}


/*===========================================================================

FUNCTION ql_adc_read

DESCRIPTION
  Read ADC channel voltage. 

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/

int ql_adc_read(uint8_t adc_channel, uint16_t *p_batvol)//for QuecOpen
{
    unsigned short meas_val;
    unsigned short vol_GPADC, vol_cali;
    unsigned short vbat_base;
	unsigned short i=0,j=0,min=0,max=0,val_all=0;

    if (p_batvol == NULL)
    {
        ql_adc_log("p_batvol == NULL", adc_channel);
        return ADC_READ_FAIL;    
    }
	if (PMIC_IS_PM803())//ASR 1603、1606平台，移远ECxxxN/M系列采用PM803
	{
		// ASR 1603 平台使用 PM803 ADC需要采用板级校准，并且仅支持通道0     ECxxxN系列   
		#ifdef ASR_PLATFORM_CRANEM
	        if (adc_channel == ADC_CHANNEL_ADC0)
			{
	            *p_batvol = GetPm803VrtpAdc();
	            return ADC_READ_SUCCESS;    
	        }
			else
			{
	            *p_batvol = 0;
	            ql_adc_log("PM803 only support adc0\n");
	            return ADC_READ_FAIL;
	        }
		#else
			// ASR 1606 平台采用高精度ADC，ECxxxM系列
			if(adc_channel == 0)
			{
				*p_batvol = (unsigned short)get_cranel_adc0();
			}
			else
			{
				*p_batvol = (unsigned short)get_cranel_adc1();
			}
		#endif
	}
    return ADC_READ_SUCCESS;
}




#endif
