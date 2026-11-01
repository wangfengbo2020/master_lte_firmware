/*================================================================
  Copyright (c) 2022, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/

/*=================================================================

						EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN			  WHO		  WHAT, WHERE, WHY
------------	 -------	 -------------------------------------------------------------------------------
19/04/2022		  Fias.fan	 Added PWM interface
=================================================================*/



#ifndef _QUEC_PWM_H
#define _QUEC_PWM_H

#include "pwm.h"
#include "quec_common.h"
//#include "quec_memory.h"
#include "quec_debug.h"
#include "quec_cust_feature.h"


#ifdef __cplusplus
extern "C" {
#endif

#if defined QUEC_PWM_ENBALE

#define QUEC_PWM_LOG_ENABLE
#define QUEC_PWM_CLK_FREQ_DEFAULT 203125
#define QUEC_DATA_TRANSFOR_POLLING_TIMR 5000 //5s

//#define QUEC_NET_STATUS_PWM PWM_DEVICE_2

typedef struct lwip_data_tx_rx_struct
{	
	unsigned long long rx_all;
	unsigned long long tx_all;
}Lwip_data_tx_rx;

extern UINT8 quec_pwm_datatransfor_flag;
extern unsigned long long quec_globle_rx_byte_all;
extern unsigned long long quec_globle_tx_byte_all;
extern unsigned char quec_net_status_pwm;

extern QuecOSStatus quec_pwm_init(void);

extern QuecOSStatus quec_net_datatransfor_polling_timer_start(void);

extern void quec_net_datatransfor_polling_timer_cb(void);





typedef enum
{
	QUEC_PWM_CLK_SRC_13M,
	QUEC_PWM_CLK_SRC_32K,
}QUEC_PWM_CLK_SRC_E;

typedef struct
{
	unsigned long 	   pwm_psc;						//(value:1~64)  example:choose 13 MHz,  maximum is 13000000/1=13 MHz, minimum is 13000000/64 = 203,125 KHz.
	unsigned short	   high_one_cycle_duration;		//Time that PWM_OUT puls is high in term of "clk_freq" define above. This value is written to PWDUTY register.
	unsigned short	   total_one_cycle_duration;	//(1<value< 1023) One cycle of PWM_OUT puls (high and low) in term of "clk_freq" define above. This value is written to PERVAL register.
	QUEC_PWM_CLK_SRC_E   clk_src; 					//The clock source,32KHz	and  13MHz
}QUEC_PWM_CONFIG_EX;

typedef enum
{
	QUEC_PWM_SHUTDOWN_GRACEFULLY,
	QUEC_PWM_SHUTDOWN_ABRUPTLY
} QUEC_PWM_SD_E;

typedef enum
{
	QUEC_PWM_OUT_SET_BY_DCYCLE,
	QUEC_PWM_OUT_SET_FOR_FULL_PERIOD
} QLEC_PWM_OUT_E;
	
typedef enum
{
	QUEC_PWM_RC_OK,
	QUEC_PWM_RC_ERROR,
	QUEC_PWM_RC_ILLEGALL_FREQUENCY,
	QUEC_PWM_RC_ILLEGALL_DUTY_CYCLE,
	QUEC_PWM_RC_ILLEGALL_DEVICE_NUMBER
}  QUEC_PWM_RETURN_CODE_E;

typedef struct
{
	unsigned long      control;
	unsigned long      duty_cycle;
	unsigned long      period_val;
} QUEC_PWM_REGISTERED_T;

struct QUEC_PWM_MAP_GPIO_S
{
	unsigned int  gpio_num;
	unsigned int  pwm_num;
	unsigned int  gpio_fun;
};

typedef struct
{
	QUEC_PWM_SD_E		 shutdown;					// Graceful(0) or Abruptly(1)
	unsigned long        clk_freq;					// The resolution is multiply of 203,125.  13,000,000 MHz is the maximum, minimum is 13000000/64 = 203,125 KHz.
	QLEC_PWM_OUT_E       pwm_out;
	unsigned short       high_one_cycle_duration;	//Time that PWM_OUT puls is high in term of "clk_freq" define above. This value is written to PWDUTY register.
	unsigned short       total_one_cycle_duration;	//One cycle of PWM_OUT puls (high and low) in term of "clk_freq" define above. This value is written to PERVAL register.
	QUEC_PWM_CLK_SRC_E   clk_src;

}QUEC_PWM_CONFIG_T;



typedef enum
{
	QUEC_PWM_DEVICE_0 = 0,
	QUEC_PWM_DEVICE_1,
	QUEC_PWM_DEVICE_2,
	QUEC_PWM_DEVICE_3,
	QUEC_PWM_MAX_DEVICE
} QUEC_PWM_DEVICE_NUM_E;


void QUEC_PWM_APB_BUS_CLK_Enable(QUEC_PWM_DEVICE_NUM_E	pwm_num);
int  QUEC_GPIO_MAPTO_PWM_Device_Num(unsigned int		 gpio_num);
void QUEC_PWM_APB_BUS_CLK_Disable(QUEC_PWM_DEVICE_NUM_E 		pwm_num);
int QUEC_PWM_Enable(unsigned int	 gpio_num);
int QUEC_PWM_Disable(unsigned int	  gpio_num);
int QUEC_PWM_PINMUX_Configure(unsigned int gpio_num);
QUEC_PWM_RETURN_CODE_E QUEC_PWM_Configure( QUEC_PWM_DEVICE_NUM_E  pwm_num , QUEC_PWM_CONFIG_T  *configuration );

#endif

#ifdef __cplusplus
} /*"C" */
#endif

#endif

