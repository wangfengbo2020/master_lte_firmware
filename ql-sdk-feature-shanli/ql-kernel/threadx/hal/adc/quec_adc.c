/*================================================================
  Copyright (c) 2019 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/

/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
06/05/2019        Fitz        Init version
=================================================================*/

#include "quec_adc.h"
#include "quec_include.h"
#include "quec_debug.h"
#include "quec_urc.h"
#include "guilin.h"


#ifndef MIN_SYS

#if defined QUEC_ADC_SUPPORT

/*========================================================================
*  Macro Definition
*========================================================================*/
#ifdef QUEC_ATCMD_LOG
#define quec_adc_log(msg, ...)  custom_log("QUEC_ADC", msg, ##__VA_ARGS__)
#else
#define quec_adc_log(msg, ...)
#endif

/*===========================================================================

FUNCTION quec_adc_init

DESCRIPTION
  ADC driver init. 

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
static unsigned char adc_init_flg = 0;//标记adc 是否被初始化
int quec_adc_init(void)
{
	int ret = -1;
	if(0 == adc_init_flg)
	{
		#ifndef NOT_SUPPORT_PM802
			if(PMIC_IS_PM802())
			{
			    UINT8  val     = 0;
				UINT16 vbat_mv = 0;  

			    /* GPADC VINLDO channel enable */
			    val = GUILIN_VINLDO_MEAS_EN;
				GuilinWrite( GUILIN_GPADC_Reg, GUILIN_GPADC_MEAS_EN_REG2, val );

			    /* GPADC ADCo,ADC1 channel enable*/
			    val = GUILIN_GPADC0_MEAS_EN | GUILIN_GPADC1_MEAS_EN;
			    GuilinWrite( GUILIN_GPADC_Reg, GUILIN_GPADC_MEAS_EN_REG1, val );

			    /* GPADC mode control */
			    GuilinRead( GUILIN_GPADC_Reg, GUILIN_GPADC_MISC_CONFIG_REG2, &val );
				val |= GUILIN_NON_STOP | GUILIN_GPADC_EN;
				GuilinWrite( GUILIN_GPADC_Reg, GUILIN_GPADC_MISC_CONFIG_REG2, val );

			    /* GPADC bais config */
			    //val = (0x3 << 4);
			    //GuilinWrite( GUILIN_GPADC_Reg, GUILIN_GPADC_BIAS_REG, val );

			    //val = GUILIN_GPADC0_BIAS_OUT | GUILIN_GPADC1_BIAS_OUT ;
			    //GuilinWrite( GUILIN_GPADC_Reg, GUILIN_GPADC_BIAS_ENABLE, val );
				adc_init_flg =1;
				ret =  0;
			}
			else
		#endif
    	#ifndef NOT_SUPPORT_PM813
			if (PMIC_IS_PM813())
			{
				unsigned char val = 0;
				unsigned char  gpadc_en = 0;
				unsigned char gpadc_control = 0;
				
			    /* ADC BAT_ID and BAT_TEMP channel enable */
			    val = NINGBO_RTC_ALARM_STATUS_BIT | NINGBO_VBUS_STATUS_BIT;
			    NingboWrite( NINGBO_GPADC_Reg, NINGBO_GPADC_MEAS_EN_REG1, val);
			  	NingboRead( NINGBO_GPADC_Reg, NINGBO_GPADC_MEAS_EN_REG1, &gpadc_en);
				if(val != gpadc_en)
				{
					quec_adc_log("Set BAT_ID & BAT_TEMP reg failed.\n");
					ret =  -1;
				}

			    /* GPADC mode control */
			    //NingboRead( NINGBO_GPADC_Reg, NINGBO_GPADC_MODE_CONTROL_REG, &val );
			    //val = NINGBO_RTC_ALARM_STATUS_BIT;
			    val =NINGBO_GPADC_EN;
			    NingboWrite( NINGBO_GPADC_Reg, NINGBO_GPADC_MODE_CONTROL_REG, val);
				NingboRead( NINGBO_GPADC_Reg, NINGBO_GPADC_MODE_CONTROL_REG, &gpadc_control);
				if(val != gpadc_control)
				{
					quec_adc_log("Set GPADC mode control reg failed.\n");
					ret= -1;
				}

				quec_adc_log("Init GPADC register SUCCESS!!!\n");
				adc_init_flg = 1;
			    ret =  0;
			}
			else
		#endif
				ret =  0;
	}
	return ret;
}

#if !defined(NOT_SUPPORT_PM802)
void quec_adc_onff(bool status)
{
	UINT8  val     = 0;
	if(PMIC_IS_PM802())//ASR 1601 平台，采用PM802 移远ECxxxS系列
	{
		if(TRUE == status)
		{
			/* GPADC VINLDO channel enable */
	//	    val = GUILIN_VINLDO_MEAS_EN;
	//		GuilinWrite( GUILIN_GPADC_Reg, GUILIN_GPADC_MEAS_EN_REG2, val );

		    /* GPADC ADCo,ADC1 channel enable*/
		    val = GUILIN_GPADC0_MEAS_EN | GUILIN_GPADC1_MEAS_EN;
		    GuilinWrite( GUILIN_GPADC_Reg, GUILIN_GPADC_MEAS_EN_REG1, val );

		    /* GPADC mode control */
		    GuilinRead( GUILIN_GPADC_Reg, GUILIN_GPADC_MISC_CONFIG_REG2, &val );
			val |= GUILIN_NON_STOP | GUILIN_GPADC_EN;
			GuilinWrite( GUILIN_GPADC_Reg, GUILIN_GPADC_MISC_CONFIG_REG2, val );
		}
		else
		{
			/* GPADC VINLDO channel disable */
	//		GuilinRead( GUILIN_GPADC_Reg, GUILIN_GPADC_MEAS_EN_REG2, &val );		
	//	    val &= ~GUILIN_VINLDO_MEAS_EN;
	//		GuilinWrite( GUILIN_GPADC_Reg, GUILIN_GPADC_MEAS_EN_REG2, val );

			/* GPADC ADCo,ADC1 channel disable*/
			GuilinRead( GUILIN_GPADC_Reg, GUILIN_GPADC_MEAS_EN_REG1, &val );
		    val &= ~(GUILIN_GPADC0_MEAS_EN | GUILIN_GPADC1_MEAS_EN);
		    GuilinWrite( GUILIN_GPADC_Reg, GUILIN_GPADC_MEAS_EN_REG1, val );

		    /* GPADC mode control */
		    GuilinRead( GUILIN_GPADC_Reg, GUILIN_GPADC_MISC_CONFIG_REG2, &val );
			val &= ~(GUILIN_NON_STOP | GUILIN_GPADC_EN);
			GuilinWrite( GUILIN_GPADC_Reg, GUILIN_GPADC_MISC_CONFIG_REG2, val );
		}
	}
}
#endif

/*===========================================================================

FUNCTION quec_vbat_adc_read

DESCRIPTION
  Read vbat ADC channel voltage. 

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
int quec_vbat_adc_read(uint16 *p_batvol)
{
	uint16 meas_val;
	uint16 vol_GPADC;

#if !defined(NOT_SUPPORT_PM802)
	if(PMIC_IS_PM802())//ASR 1601 平台，采用PM802 移远ECxxxS系列
	{
		meas_val = guilin_read_volt_meas_val(0x62); 
		vol_GPADC = (uint16) ((meas_val * 1300 * 5) / 4096);
		*p_batvol = vol_GPADC;
	}
	else
#endif
#if !defined(NOT_SUPPORT_PM813)
	if(PMIC_IS_PM813())//EC100Y
	{
		*p_batvol = (unsigned short)pm813_get_battery_voltage_withoutCharger();
	}
	else
#endif
	if(PMIC_IS_PM803()||PMIC_IS_PM803L())//EC600N
	{
		// ASR 1603 平台使用 PM803 ADC需要采用板级校准，并且仅支持通道0     ECxxxN系列   
		#ifdef ASR_PLATFORM_CRANEM
			*p_batvol = GetRfAdcForVbat();
		#else
            *p_batvol = (UINT16)get_cranel_vbat();
		#endif
	}

	quec_adc_log("Get vbat batvol=%d",vol_GPADC);
	return 0;
}

/*===========================================================================

FUNCTION quec_adc_read

DESCRIPTION
  Read ADC channel voltage. 

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
/************************************************************
Due to the voltage drop of ADC port during voltage acquisition, 
the acquisition voltage is not accurate, 
so the ADC acquisition function is turned off after collecting voltage, 
and then the value is read and the average value is offset	
*************************************************************/

#define QUEC_ADC_SAMPLE_MAX 10

int quec_adc_read(uint8 adc_channel, uint16 *p_batvol)
{
    uint16 meas_val;
    uint16 vol_GPADC, vol_cali;
    uint16 vbat_base;
	uint16 i=0,j=0,min=0,max=0,val_all=0,times = QUEC_ADC_SAMPLE_MAX;
	uint16 batvol_sample[QUEC_ADC_SAMPLE_MAX]={0};

    if (p_batvol == NULL)
    {
        quec_adc_log("p_batvol == NULL", adc_channel);
        return ADC_READ_FAIL;    
    }
#if !defined(NOT_SUPPORT_PM802)
	if(PMIC_IS_PM802())//ASR 1601 平台，采用PM802 移远ECxxxS系列
	{
		while(times--)
		{
			quec_adc_onff(TRUE);
			quec_rtos_task_sleep_ms(5);
			quec_adc_onff(FALSE);
		    if (adc_channel == ADC_CHANNEL_ADC0)
		    {
		        meas_val = guilin_read_volt_meas_val(GUILIN_VGPADC0);    
		    }
		    else if (adc_channel == ADC_CHANNEL_ADC1)
		    {
		        meas_val = guilin_read_volt_meas_val(GUILIN_VGPADC1);
		    }
		    else 
		    {
		        quec_adc_log("channel=%d err", adc_channel);
		        return ADC_READ_FAIL;
		    }

			vol_GPADC = (uint16) ((meas_val * 1300) / 4096);
			
		#if defined (__QUECTEL_PROJECT_EC600SCN_AA__) || defined (__QUECTEL_PROJECT_EC600SCN_LA__) || defined (__QUECTEL_PROJECT_EC600SCN_LB__) || defined (__QUECTEL_PROJECT_EC600SCN_AC__) \
	    	|| defined (__QUECTEL_PROJECT_EC600SCN_LC__) || defined (__QUECTEL_PROJECT_EC600SCN_LD__)
	    

			batvol_sample[i]=vol_GPADC;

		#else
			vbat_base = 1300;
			if (vol_GPADC >= vbat_base)
			{
				vol_cali = (uint16)(1300 + (vol_GPADC-vbat_base));
			}
			else
			{
				vol_cali = (uint16)(1300 - (vbat_base-vol_GPADC));
			}

			/* (1) 100K, 47K resistance position is wrong.
			   before modify the circuit: *p_batvol = vol_cali*147/100;
			   after  modify the circuit: *p_batvol = vol_cali*147/47;

			   (2) HW change 100K,47K to 100K,39K
			   100K,47K can detect 0-4.0V
			   100K,39K can detect 0-4.6V

			   (3) HW change 100K,39K to 1000K,390K
			   100K,39K can detect 0-4.6V
			   1000K,390K can detect 0-4.6V
			*/
			batvol_sample[i]=vol_cali*139/39;

		#endif

			quec_adc_log("time=%d, channel=%d, meas_val=%d, vbat_base=%d, vol_cali=%d, batvol=%d", i, adc_channel, meas_val, vbat_base, vol_cali, batvol_sample[i]);
			i++;
		}
		{
			uint16 temp=0;
			uint16 batvol_sample_temp[QUEC_ADC_SAMPLE_MAX]={0};
			memcpy(batvol_sample_temp,batvol_sample,sizeof(batvol_sample_temp));
			for(i=0;i<QUEC_ADC_SAMPLE_MAX-1;i++)
			{
				for(j=i+1;j<QUEC_ADC_SAMPLE_MAX;j++)
				{
					if(batvol_sample_temp[i]>batvol_sample_temp[j])
					{
						temp=batvol_sample_temp[i];
						batvol_sample_temp[i]=batvol_sample_temp[j];
						batvol_sample_temp[j]=temp;
					}
				}
			}
			for(i=0;i<QUEC_ADC_SAMPLE_MAX;i++)
			{
				quec_adc_log("adc_val_all=%d",batvol_sample_temp[i]);
			}
			for(i=1;i<9;i++)
			{
				val_all += batvol_sample_temp[i];
			}
			*p_batvol =val_all/8;

			if(PMIC_IS_PM802())
			{
				if((*p_batvol >= 1000)&&(*p_batvol <= 2000))
				{
					*p_batvol -= 10;
				}
				else if((*p_batvol > 2000)&&(*p_batvol <= 3000))
				{
					*p_batvol -= 15;
				}
				else if((*p_batvol > 3000)&&(*p_batvol <= 4000))
				{
					*p_batvol -= 25;
				}
				else if(*p_batvol > 4000)
				{
					*p_batvol -= 30;
				}
			}
		}
	}
	else
#endif
	if (PMIC_IS_PM803() || PMIC_IS_PM803L())//ASR 1603、1606平台，移远ECxxxN/M系列采用PM803
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
	            quec_adc_log("PM803 only support adc0\n");
	            return ADC_READ_FAIL;
	        }
		#else
			// ASR 1606 平台采用高精度ADC，ECxxxM系列
			uint16 a = 0;
			if(adc_channel == 0)
			{
                #if defined (__QUECTEL_PROJECT_EC200MCN_LA__) || defined (__QUECTEL_PROJECT_EC200MCN_GB__) || defined (__QUECTEL_PROJECT_EC200MCN_LE__)
                a = (uint16)get_cranel_adc0();
				*p_batvol = a+(a*390/120);
                #else 
                *p_batvol = (uint16)get_cranel_adc0();
                #endif
			}
			else if(adc_channel == 1)
			{
                #if defined (__QUECTEL_PROJECT_EC200MCN_LA__) || defined (__QUECTEL_PROJECT_EC200MCN_GB__)|| defined (__QUECTEL_PROJECT_EC200MCN_LE__)
                a = (uint16)get_cranel_adc1();
				*p_batvol = a+(a*390/120);
                #else 
                *p_batvol = (uint16)get_cranel_adc1();
                #endif
			}
			else if(adc_channel == QUEC_ADC_CH_VBAT)
			{
                quec_vbat_adc_read(p_batvol);
			}
		#endif
	}
	#ifndef NOT_SUPPORT_PM813 //ASR 3601 平台，移远ECxxxY系列采用PM813
    else if (PMIC_IS_PM813()) //pm813 adc0、adc1
	{
	    unsigned short meas_val;
	    unsigned short vol_GPADC, vol_cali;
	    unsigned short vbat_base;
		unsigned char val = 0;
		unsigned char  gpadc_en = 0;
		unsigned char gpadc_control = 0;
		val = NINGBO_RTC_ALARM_STATUS_BIT | NINGBO_VBUS_STATUS_BIT;

		NingboRead( NINGBO_GPADC_Reg, NINGBO_GPADC_MEAS_EN_REG1, &gpadc_en);
		if(val != gpadc_en)
		{
			NingboWrite( NINGBO_GPADC_Reg, NINGBO_GPADC_MEAS_EN_REG1, val);
			//ql_adc_log("Get BAT_ID & BAT_TEMP reg FAILED reset BAT_ID & BAT_TEMP.\n");
			
		}

		val =NINGBO_GPADC_EN;
		NingboRead( NINGBO_GPADC_Reg, NINGBO_GPADC_MODE_CONTROL_REG, &gpadc_control);
		if(val != gpadc_control)
		{
			NingboWrite( NINGBO_GPADC_Reg, NINGBO_GPADC_MODE_CONTROL_REG, val);
			//ql_adc_log("Get GPADC mode control reg FAILED reset NINGBO_GPADC_EN.\n");
			
		}

	    if (p_batvol == NULL)
	    {
	        quec_adc_log("p_batvol == NULL\n");
	        return ADC_READ_FAIL;    
	    }

	    if (adc_channel == ADC_CHANNEL_ADC0)
	    {
	        meas_val = ningbo_read_volt_meas_val(NINGBO_GPADC_MEAS_VBATID_1_REG);
			
	    }
	    else if (adc_channel == ADC_CHANNEL_ADC1)
	    {
	        meas_val = ningbo_read_volt_meas_val(NINGBO_GPADC_MEAS_VBATTEMP_1_REG);
	    }
	    else 
	    {
	        quec_adc_log("channel=%d err", adc_channel);
	    }

	    vol_GPADC = (uint16) ((meas_val * 1300) / 4096);

	    vbat_base = 1300;
	    if (vol_GPADC >= vbat_base)
	    {
	        vol_cali = (uint16)(1300 + (vol_GPADC-vbat_base));
	    }
	    else
	    {
	        vol_cali = (uint16)(1300 - (vbat_base-vol_GPADC));
	    }
		

	    /* (1) 100K, 47K resistance position is wrong.
	       before modify the circuit: *p_batvol = vol_cali*147/100;
	       after  modify the circuit: *p_batvol = vol_cali*147/47;

	       (2) HW change 100K,47K to 100K,39K
	       100K,47K can detect 0-4.0V
	       100K,39K can detect 0-4.6V
	    */
	    *p_batvol = vol_cali*139/39;
		
	    //ql_adc_log("channel=%d, meas_val=%d, vbat_base=%d, vol_cali=%d, batvol=%d\n", adc_channel, meas_val, vbat_base, vol_cali, *p_batvol);

	}
	#endif
    return ADC_READ_SUCCESS;
}
#endif

#endif /*MIN_SYS*/

