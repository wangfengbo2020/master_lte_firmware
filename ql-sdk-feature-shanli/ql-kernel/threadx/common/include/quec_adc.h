/*============================================================================
  Copyright (c) 2022 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
 =============================================================================*/

#ifndef _QUEC_ADC_H
#define _QUEC_ADC_H

#include "quec_common.h"
#include "quec_cust_feature.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined QUEC_ADC_SUPPORT

#define     GUILIN_VGPADC0                      0x4C

#define ADC_CHANNEL_ADC0  (0x00)
#define ADC_CHANNEL_ADC1  (0x01)
#define ADC_CHANNEL_VBAT  (0x2)

 typedef enum
{
	QUEC_ADC_CH0    = 0,
	QUEC_ADC_CH1     ,
	QUEC_ADC_CH_VBAT ,
	QUEC_ADC_CH_MAX,
}QUEC_ADC_CHANNEL_TYPE_E;


typedef enum
{
	ADC_READ_FAIL    = 0,
	ADC_READ_SUCCESS = 1,
}QUEC_ADC_READ_STATE_E;


extern int quec_adc_init(void);
extern int quec_adc_read(uint8 adc_channel, uint16 *p_batvol);
extern int quec_vbat_adc_read(uint16 *p_batvol);

#endif

#ifdef __cplusplus
} /*"C" */
#endif

#endif




