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


#ifdef __cplusplus
extern "C" {
#endif


typedef enum
{
	QL_PWM_CLK_SRC_13M,
	QL_PWM_CLK_SRC_32K,
}QL_PWM_CLK_SRC_E;


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


typedef enum
{
	QUEC_PWM_DEVICE_0 = 0,
	QUEC_PWM_DEVICE_1,
	QUEC_PWM_DEVICE_2,
	QUEC_PWM_DEVICE_3,
	QUEC_PWM_MAX_DEVICE
} QUEC_PWM_DEVICE_NUM_E;

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
};

typedef struct
{
	QUEC_PWM_SD_E		 shutdown;					// Graceful(0) or Abruptly(1)
	unsigned long        clk_freq;					// The resolution is multiply of 203,125.  13,000,000 MHz is the maximum, minimum is 13000000/64 = 203,125 KHz.
	QLEC_PWM_OUT_E       pwm_out;
	unsigned short       high_one_cycle_duration;	//Time that PWM_OUT puls is high in term of "clk_freq" define above. This value is written to PWDUTY register.
	unsigned short       total_one_cycle_duration;	//One cycle of PWM_OUT puls (high and low) in term of "clk_freq" define above. This value is written to PERVAL register.
	QL_PWM_CLK_SRC_E   clk_src;

}QUEC_PWM_CONFIG_T;



typedef struct
{
	unsigned long 	   pwm_psc;						//(value:1~64)  example:choose 13 MHz,  maximum is 13000000/1=13 MHz, minimum is 13000000/64 = 203,125 KHz.
	unsigned short	   high_one_cycle_duration;		//Time that PWM_OUT puls is high in term of "clk_freq" define above. This value is written to PWDUTY register.
	unsigned short	   total_one_cycle_duration;	//(1<value< 1023) One cycle of PWM_OUT puls (high and low) in term of "clk_freq" define above. This value is written to PERVAL register.
	QL_PWM_CLK_SRC_E   clk_src; 					//The clock source,32KHz	and  13MHz
}QL_PWM_CONFIG_EX;

/*****************************************************************
* Function: ql_pwm_enable
*
* Description: 	
*此函数打开pwm功能
* 
* Parameters:
* 	gpio_num			[in] 	选择PWM的GPIO口。
*
* Return:
* 	0	             成功。
*	-1               失败。
*
*****************************************************************/
int ql_pwm_enable(unsigned int gpio_num);

/*****************************************************************
* Function: ql_pwm_disable
*
* Description: 	
*此函数关闭pwm功能
* 
* Parameters:
* 	gpio_num			[in] 	选择PWM的GPIO口。
*
* Return:
* 	0	             成功。
*	-1               失败。
*
*****************************************************************/
int ql_pwm_disable(unsigned int gpio_num);

/*****************************************************************
* Function: ql_pwm_config_plus_ex
*
* Description: 	2022-02-28
*此函数产生的pwm频率可根据用户选择时钟源、分频系数、重装值来自定义设置频率；选择高电平、重装值时间(整个周期时间)确定PWM占空比。 
* 
* Parameters:
* 	gpio_num			[in] 	选择PWM的GPIO口。
* 	pwm_parameter	  　[in] 	设置分频系数、高电平、重装值、时钟源等参数
*
* Return:
* 	0	             成功。
*	-1               失败。
*
*****************************************************************/
int ql_pwm_config_plus_ex(unsigned int gpio_num,QL_PWM_CONFIG_EX *pwm_parameter);

/*****************************************************************
* Function: ql_pwm_test
*
* Description: 	
*测试pwm功能，同时测试gpio10、11、32、117，占空比50%
* 
* Parameters:
*
*
* Return:
*  
*
*****************************************************************/
void ql_pwm_test(void);


#endif

#ifdef __cplusplus
} /*"C" */
#endif


