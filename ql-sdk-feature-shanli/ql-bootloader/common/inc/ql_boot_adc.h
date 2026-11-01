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

#ifndef _QL_BOOT_ADC_H
#define _QL_BOOT_ADC_H


#ifdef __cplusplus
extern "C" {
#endif

/*========================================================================
 *  Macro Definition
 *========================================================================*/
 typedef enum
{
	ADC_CHANNEL_ADC0    = 0,
	ADC_CHANNEL_ADC1    = 1,
	ADC_CHANNEL_VBAT    = 2,
}QUEC_ADC_CHANNEL_TYPE_E;


typedef enum
{
	ADC_READ_FAIL    = 0,
	ADC_READ_SUCCESS = 1,
}QUEC_ADC_READ_STATE_E;



/*****************************************************************
* Function: ql_adc_init
*
* Description:
* 	初始化ADC
* 
* Parameters:
* 	void	  			
*
* Return:
* 	0			成功。
*	-1 	失败。
*
*****************************************************************/
int ql_adc_init(void);

/*****************************************************************
* Function: ql_adc_read
*
* Description:
* 	读取ADC的值
* 
* Parameters:
* 	adc_channel  [in] ADC通道  ,参考	  	QUEC_ADC_CHANNEL_TYPE_E
*   p_batvol     [out] ADC的值
*
* Return:
* 	0			读取失败。
*	1 	        读取成功。
*   参考QUEC_ADC_READ_STATE_E
*
*****************************************************************/
int ql_adc_read(unsigned char adc_channel, unsigned short *p_batvol);


#ifdef __cplusplus
} /*"C" */
#endif

#endif


