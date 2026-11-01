/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
/**
 ******************************************************************************
 * @file    ql_gpio.c
 * @author  Juson.zhang
 * @version V1.0.0
 * @date    2019/12/17
 * @brief   This file contains the gpio functions's definitions
 ******************************************************************************
 */
#include <stdio.h>
#include "xscale_types.h"
#include "mfpr_api.h"
#include "cgpio.h"
#include "cgpio_HW.h"
#include "bsp_hisr.h"
#include "ql_gpio.h"
#include "quec_cust_feature.h"
#include "pmic.h"
#include "bsp.h"

#ifndef NULL
  #define NULL    (void*)0
#endif

#ifdef QUEC_GPIO_LOG_ENABLE
	#define gpio_log(fmt, args...)
#else
	#define gpio_log(fmt, args...)	
	//RTI_LOG("[%s][%d]"fmt, __FUNCTION__, __LINE__, ##args)
#endif

#define QUEC_RESERVED_MASK	0x00C0

#define write32(addr, val)                          (*(volatile unsigned int *)(addr) = (val))
#define read32(addr)                                (*(volatile unsigned int *)(addr))

static OS_HISR quec_gpio_hisr[GPIO_PIN_NO_MAX] = {NULL};
static OS_HISR quec_gpio_wu_hisr[GPIO_PIN_NO_MAX] = {NULL};
static OS_HISR quec_common_gpio_hisr = NULL;

static int quec_gpio_config_set(GPIO_PIN_NUMBER_E gpio_num, PIN_DIRECTION_E pin_dir, PIN_PULL_E pin_pull, PIN_LEVEL_E pin_level)
{
	GPIOConfiguration gpio_config_data = {
		.pinDir  = pin_dir,
		.pinPull = pin_pull,
		.initLv  = pin_level,
		.pinEd 	 = GPIO_NO_EDGE,
		.isr 	 = NULL,
		.wu 	 = NULL,
	};
	
	return GpioInitConfiguration((unsigned int)gpio_num, gpio_config_data);
}

int ql_gpio_init(GPIO_PIN_NUMBER_E gpio_num, PIN_DIRECTION_E pin_dir, PIN_PULL_E pin_pull, PIN_LEVEL_E pin_level)
{
	int ret = -1;
	unsigned long mfpr_data = MFP_DRIVE_MEDIUM | MFP_LPM_EDGE_NONE;
	
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_PIN_NO_MAX < gpio_num) {
		gpio_log("gpio number is invalid\n");
		return -1;
	}

	/*必须先config，再设置MFPR。*/
	
	/* step 1: set gpio reg */
	ret = quec_gpio_config_set(gpio_num, pin_dir, pin_pull, pin_level);
	if (ret) {
		gpio_log("config gpio reg failed, gpio_num:%d, ret = %d \n", gpio_num, ret);
		return -1;
	}

	if(GPIO_PIN_NO_126==gpio_num){
		*(volatile unsigned long *)(GPIO_MFPR_ADDR(gpio_num)) = MFP_AF2 | mfpr_data;
	} else if ((GPIO_PIN_NO_117==gpio_num) || ((GPIO_PIN_NO_45 <= gpio_num && gpio_num <= GPIO_PIN_NO_47)) || (GPIO_PIN_NO_77==gpio_num) || (GPIO_PIN_NO_118==gpio_num))  {	//MMC2 GPIOS
		*(volatile unsigned long *)(GPIO_MFPR_ADDR(gpio_num)) = MFP_AF1 | MFP_DRIVE_MEDIUM | mfpr_data;
	} else {
		*(volatile unsigned long *)(GPIO_MFPR_ADDR(gpio_num)) = MFP_AF0 | mfpr_data;
	}
	
	if(CHIP_IS_CRANELR)
	{
		if((GPIO_PIN_NO_84==gpio_num) || (GPIO_PIN_NO_85==gpio_num) || (GPIO_PIN_NO_87==gpio_num) || (GPIO_PIN_NO_88==gpio_num))
			*(volatile unsigned long *)(GPIO_MFPR_ADDR(gpio_num)) = MFP_AF1 | MFP_DRIVE_MEDIUM | mfpr_data;
	}


	//[START]2020-10-13 [nebula.li][add] 初始化时增加设置gpio上下拉操作，修复gpio设置为输入时，上下拉不生效
	ret = GpioSetPullControl(gpio_num, pin_pull);
	if (ret) {
		gpio_log("set gpio pin pull failed, ret = %d \n", ret);
		return -1;
	}
	//[END]2020-10-13 [nebula.li][add]



	return 0;
}

/*Fias 2022-4-29 gpio input 32Khz (32787Hz)*/
int ql_gpio_map_clock(GPIO_PIN_NUMBER_E gpio_num)
{
	unsigned long mfpr_data = MFP_DRIVE_MEDIUM | MFP_LPM_EDGE_NONE;

	if ((GPIO_PIN_NO_28 != gpio_num) && (GPIO_PIN_NO_20 != gpio_num ))
	{
		gpio_log("gpio number is invalid and not gpio_28 or GPIO_PIN_NO_20 \n");
		return -1;
	}
	
	if (GPIO_PIN_NO_28 == gpio_num )
	{
		*(volatile unsigned long *)(GPIO_MFPR_ADDR(gpio_num)) = MFP_AF3 | mfpr_data;
	}
	else if (GPIO_PIN_NO_20 == gpio_num )
	{
		*(volatile unsigned long *)(GPIO_MFPR_ADDR(gpio_num)) = MFP_AF6 | mfpr_data;
	}
	return 0;

}

int ql_gpio_deinit(GPIO_PIN_NUMBER_E gpio_num)
{
	GpioClearEdgeDetection(gpio_num);
	GpioDisableEdgeDetection(gpio_num, GPIO_TWO_EDGE);

	GpioClearEdgeDetection_wakeup(gpio_num);
	GpioDisableEdgeDetection_wakeup(gpio_num, GPIO_TWO_EDGE);
	return 0;
}

int ql_gpio_set_level(GPIO_PIN_NUMBER_E gpio_num, PIN_LEVEL_E pin_level)
{
	int ret = -1;
	
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_PIN_NO_MAX < gpio_num) {
		gpio_log("gpio number is invalid\n");
		return -1;
	}

	ret = GpioSetLevel(gpio_num, pin_level);
	if (ret) {
		gpio_log("set gpio pin level failed, gpio_num:%d, ret = %d \n", gpio_num, ret);
		return -1;
	}
	
	return 0;
}

int ql_gpio_get_level(GPIO_PIN_NUMBER_E gpio_num, PIN_LEVEL_E *p_pin_level)
{	
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_PIN_NO_MAX < gpio_num || NULL == p_pin_level) {
		gpio_log("para is invalid \n");
		return -1;
	}

	*p_pin_level = (PIN_LEVEL_E)GpioGetLevel(gpio_num);
	
	return 0;
}

int ql_gpio_set_direction(GPIO_PIN_NUMBER_E gpio_num, PIN_DIRECTION_E pin_dir)
{
	int ret = -1;

	if (GPIO_PIN_NO_0 > gpio_num || GPIO_PIN_NO_MAX < gpio_num) {
		gpio_log("gpio number is invalid\n");
		return -1;
	}

	ret = GpioSetDirection(gpio_num, pin_dir);
	if (ret) {
		gpio_log("set gpio pin direction failed, ret = %d \n", ret);
		return -1;
	}

	return 0;
}

int ql_gpio_get_direction(GPIO_PIN_NUMBER_E gpio_num, PIN_DIRECTION_E *p_pin_dir)
{
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_PIN_NO_MAX < gpio_num || NULL == p_pin_dir) {
		gpio_log("para is invalid \n");
		return -1;
	}

	*p_pin_dir = (PIN_DIRECTION_E)GpioGetDirection(gpio_num);

	return 0;
}

int ql_gpio_set_pull(GPIO_PIN_NUMBER_E gpio_num, PIN_PULL_E pin_pull)
{
	int ret = -1;

	if (GPIO_PIN_NO_0 > gpio_num || GPIO_PIN_NO_MAX < gpio_num) {
		gpio_log("gpio number is invalid\n");
		return -1;
	}

	ret = GpioSetPullControl(gpio_num, pin_pull);
	if (ret) {
		gpio_log("set gpio pin pull failed, ret = %d \n", ret);
		return -1;
	}
	
	return 0;
}

extern GPIOReturnCode GpioGetPullControl(UINT32 portHandle);

int ql_gpio_get_pull(GPIO_PIN_NUMBER_E gpio_num, PIN_PULL_E *p_pin_pull)
{
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_PIN_NO_MAX < gpio_num || NULL == p_pin_pull) {
		gpio_log("para is invalid \n");
		return -1;
	}

	*p_pin_pull = (PIN_PULL_E)GpioGetPullControl(gpio_num);

	return 0;
}

void quec_active_gpio_hisr(unsigned       int gpio_num)
{
	if(NULL != quec_gpio_hisr[gpio_num]) {
        OS_Activate_HISR(&quec_gpio_hisr[gpio_num]); 
    }
}

void quec_active_gpio_wu_hisr(unsigned        int gpio_num)
{
    if(NULL != quec_gpio_wu_hisr[gpio_num]) {
        OS_Activate_HISR(&quec_gpio_wu_hisr[gpio_num]); 
    }
}
/*如果注册了wakeup中断，优先使用wakeup中断*/
int ql_eint_register(GPIO_PIN_NUMBER_E gpio_num, PIN_EDGE_E pin_edge, PIN_PULL_E pin_pull, void *eint_cb, void *wakeup_eint_cb)
{
	int ret = -1;
	unsigned long mfpr_data = QUEC_RESERVED_MASK;
	GPIOConfiguration gpio_config_data = {
		.pinDir  = PIN_DIRECTION_IN,
		.pinPull = pin_pull,
		.initLv  = PIN_LEVEL_LOW,
		.pinEd 	 = pin_edge,
		.isr 	 = NULL,
		.wu 	 = NULL,
	};

	if (GPIO_PIN_NO_0 > gpio_num || GPIO_PIN_NO_MAX < gpio_num) {
		gpio_log("gpio number is invalid\n");
		return -1;
	}
    
    /*此处设置的是mfpr寄存器边沿检测，用于唤醒功能*/
	switch (pin_edge) {
		case PIN_NO_EDGE:
			mfpr_data |= MFP_LPM_EDGE_NONE;
			break;
		case PIN_RISING_EDGE:
			mfpr_data |= MFP_LPM_EDGE_RISE;
			break;
		case PIN_FALLING_EDGE:
			mfpr_data |= MFP_LPM_EDGE_FALL;
			break;
		case PIN_BOTH_EDGE:
			mfpr_data |= MFP_LPM_EDGE_BOTH;
			break;
		default:
			mfpr_data |= MFP_LPM_EDGE_NONE;
			break;
	}

	if (GPIO_PIN_NO_117==gpio_num) {	//MMC2 GPIOS
		*(volatile unsigned long *)(GPIO_MFPR_ADDR(gpio_num)) = MFP_AF1 | MFP_DRIVE_MEDIUM | mfpr_data;
	}
	else {
		*(volatile unsigned long *)(GPIO_MFPR_ADDR(gpio_num)) = MFP_AF0 | MFP_DRIVE_MEDIUM | mfpr_data;
	}

	if(CHIP_IS_CRANELR)
	{
		if((GPIO_PIN_NO_84<=gpio_num) && (GPIO_PIN_NO_88>=gpio_num))
			*(volatile unsigned long *)(GPIO_MFPR_ADDR(gpio_num)) = MFP_AF1 | MFP_DRIVE_MEDIUM | mfpr_data;
	}
    
	if (PIN_PULL_DISABLE == pin_pull || PIN_PULL_PD == pin_pull) {
		gpio_config_data.initLv = PIN_LEVEL_LOW;
	}
	else if (PIN_PULL_PU == pin_pull) {
		gpio_config_data.initLv = PIN_LEVEL_HIGH;
	}

	/* 两种中断都注册优先使用唤醒中断，*/
  
	if (eint_cb && !wakeup_eint_cb) {
		OS_Create_HISR(&quec_gpio_hisr[gpio_num], "gpio_irq", (void(*)(void))eint_cb, HISR_PRIORITY_2);
	}
    
	if (wakeup_eint_cb) {
		OS_Create_HISR(&quec_gpio_wu_hisr[gpio_num], "gpio_wu_irq", (void(*)(void))wakeup_eint_cb, HISR_PRIORITY_2);
	}
	/***************************************/
	
	ret = GpioInitConfiguration((unsigned int)gpio_num, gpio_config_data);
	if (0 != ret) {
		gpio_log("config gpio[%d] failed \n", gpio_num);
		return ret;
	}
       
	return 0;
}

int ql_eint_unregister(GPIO_PIN_NUMBER_E gpio_num)
{
	if (quec_gpio_hisr[gpio_num] != NULL) {
		Os_Delete_HISR(&quec_gpio_hisr[gpio_num]);
		quec_gpio_hisr[gpio_num] = NULL;
	}
	if (quec_gpio_wu_hisr[gpio_num] != NULL) {
    	Os_Delete_HISR(&quec_gpio_wu_hisr[gpio_num]);
    	quec_gpio_wu_hisr[gpio_num] = NULL;
    }
	GpioClearEdgeDetection(gpio_num);
	GpioDisableEdgeDetection(gpio_num,GPIO_TWO_EDGE);

	GpioClearEdgeDetection_wakeup(gpio_num);
	GpioDisableEdgeDetection_wakeup(gpio_num, GPIO_TWO_EDGE);
	
	return 0;
}

int ql_eint_enable(GPIO_PIN_NUMBER_E gpio_num, PIN_EDGE_E pin_edge)
{
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_PIN_NO_MAX < gpio_num) {
		gpio_log("gpio number is invalid\n");
		return -1;
	}
//add 20230530 将此标志置位提前,防止出现客户进入hisr,enable中断，在标志置起前刚好gpio干扰导致触发lisr,
//此时标志还未置起，导致无法激活hisr.后续quec_gpio_edge_statue[gpio_num]标志置起，也无法再触发lisr,使得中断失效

	GpioClearEdgeDetection(gpio_num);
	GpioEnableEdgeDetection(gpio_num, pin_edge);
	return 0;
}

int ql_eint_disable(GPIO_PIN_NUMBER_E gpio_num)
{
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_PIN_NO_MAX < gpio_num) {
		gpio_log("gpio number is invalid\n");
		return -1;
	}

	GpioClearEdgeDetection(gpio_num);
	GpioDisableEdgeDetection(gpio_num, GPIO_TWO_EDGE);
	return 0;
}

int ql_eint_enable_wakeup(GPIO_PIN_NUMBER_E gpio_num, PIN_EDGE_E pin_edge)
{
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_PIN_NO_MAX < gpio_num) {
		gpio_log("gpio number is invalid\n");
		return -1;
	}

	GpioClearEdgeDetection_wakeup(gpio_num);
	GpioEnableEdgeDetection_wakeup(gpio_num, pin_edge);
	return 0;
}

int ql_eint_disable_wakeup(GPIO_PIN_NUMBER_E gpio_num)
{
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_PIN_NO_MAX < gpio_num) {
		gpio_log("gpio number is invalid\n");
		return -1;
	}

	GpioClearEdgeDetection_wakeup(gpio_num);
	GpioDisableEdgeDetection_wakeup(gpio_num, GPIO_TWO_EDGE);
	return 0;
}

int ql_sfp_eint_register(GPIO_PIN_NUMBER_E gpio_num, void *wakeup_eint_cb)
{
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_PIN_NO_MAX < gpio_num) {
		gpio_log("gpio number is invalid\n");
		return -1;
	}

	if (wakeup_eint_cb) {
		OS_Create_HISR(&quec_gpio_wu_hisr[gpio_num], "gpio_wu_irq", (void(*)(void))wakeup_eint_cb, HISR_PRIORITY_2);
	}

	return 0;
}

int ql_sfp_eint_unregister(GPIO_PIN_NUMBER_E gpio_num)
{
	if (GPIO_PIN_NO_0 > gpio_num || GPIO_PIN_NO_MAX < gpio_num) {
		gpio_log("gpio number is invalid\n");
		return -1;
	}

    if (quec_gpio_wu_hisr[gpio_num] != NULL) {
    	Os_Delete_HISR(&quec_gpio_wu_hisr[gpio_num]);
    	quec_gpio_wu_hisr[gpio_num] = NULL;
    }

	return 0;
}

/*somer.zhang-2020/05/11-set pmic gpio out high level(1) or low level(0)*/
#include "pmic.h"
#include "ningbo.h"
int ql_set_pmic_gpio_level(QL_PIMC_GPIO_E PINx,unsigned       char level)
{
	if (level > 1) level=1;
	switch(PINx)
	{
		case PMIC_GPIO_PIN_210:/*keyboard led*/
		{
			unsigned char var;			
			NingboRead(NINGBO_BASE_Reg, 0x4C, &var);					
			NingboWrite(NINGBO_BASE_Reg, 0x40, 0x7f); /*set pwm duty (127+1)/128 */
			NingboWrite(NINGBO_BASE_Reg, 0x46, 1*6); /*31/5, register 0x46 has 5 bits*/			
			if (level == 0) //switch off
			{	
				NingboWrite(NINGBO_BASE_Reg, 0x4C, (var&~(0x1<<0))); //write 0 to 0x4Creg.bit0
				return 0;
			}else{ //switch on
				NingboWrite(NINGBO_BASE_Reg, 0x4C, (var|(0x1<<0))); //write 1 to 0x4Creg.bit0
				return 0; 
			}
			//break;
		}
		case PMIC_GPIO_PIN_217:/*torch led*/
		{
			unsigned char var;
			NingboRead(NINGBO_BASE_Reg, 0x4C, &var);						
			NingboWrite(NINGBO_BASE_Reg, 0x41, 0x7f); /*set pwm duty (127+1)/128 */
			NingboWrite(NINGBO_BASE_Reg, 0x47, 1*6); /*31/5, register 0x47 has 5 bits*/		
			if (level == 0) //switch off
			{	
				NingboWrite(NINGBO_BASE_Reg, 0x4C, (var&~(0x1<<1))); //write 0 to 0x4Creg.bit1
				return 0;
			}else{ //switch on
				NingboWrite(NINGBO_BASE_Reg, 0x4C, (var|(0x1<<1))); //write 1 to 0x4Creg.bit1
				return 0; 
			}
			//break;
		}
		case PMIC_GPIO_PIN_209:/*blacklight led*/
		{
			unsigned char var;
			//unsigned char reg45h;
			NingboRead(NINGBO_BASE_Reg, 0x4C, &var);	
			//NingboRead(NINGBO_BASE_Reg, 0x45, &reg45h);		
			//NingboWrite(NINGBO_BASE_Reg, 0x45, (reg45h|(0x07)));
			NingboWrite(NINGBO_BASE_Reg, 0x42, 0x7f); /*set pwm duty (127+1)/128 */
			NingboWrite(NINGBO_BASE_Reg, 0x48, 2*6); /*31/5, register 0x48 has 5 bits*/			
			if (level == 0) //switch off
			{	
				//if ((var&(0x1<<2))==0x02)
					NingboWrite(NINGBO_BASE_Reg, 0x4C, (var&~(0x1<<2))); //write 0 to 0x4Creg.bit2
				return 0;
			}else{ //switch on
				//if ((var&(0x1<<2))==0x00)
					NingboWrite(NINGBO_BASE_Reg, 0x4C, (var|(0x1<<2))); //write 1 to 0x4Creg.bit2
				return 0; 
			}
			//break;
		}
		default: break;
	}
return 0;
}

int ql_set_usim2_io_vol(char onoff, QL_USIM2_IO_E vol)
{
	switch (PMIC_ID_GET())
    {
        #if !defined(NOT_SUPPORT_PM802)
        case PMIC_802:
        case PMIC_802S:
            return 0;
        #endif
        #if !defined(NOT_SUPPORT_PM813)
        case PMIC_813:
        case PMIC_813A3:
        case PMIC_813S:
            return 0;
        #endif
        case PMIC_803:
			if(!onoff){
				GuilinLite_Ldo_8_set(onoff);
				return 0;
			}else{
				switch(vol)
				{
					case USIM2_IO_VOL_1_8V:
						GuilinLite_Ldo_8_set_1_8();
						AIB_USIM2_IO_Set_1_8V();
						GuilinLite_Ldo_8_set(onoff);
						return 0;

					case USIM2_IO_VOL_3_3V:
						GuilinLite_Ldo_8_set_3_3();
						AIB_USIM2_IO_Set_3_3V();
						GuilinLite_Ldo_8_set(onoff);
						return 0;
				}
			}
        default:
            return -1;
    }
	return -1;
}

void* quec_get_gpio_wu_hisr(int gpio_num)
{
    return quec_gpio_wu_hisr[gpio_num];
}

