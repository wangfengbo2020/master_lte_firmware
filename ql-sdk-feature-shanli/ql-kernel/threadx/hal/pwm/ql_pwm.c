/*================================================================
  Copyright (c) 2022, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/

#include <string.h>
#include "ql_pwm.h"
#include "quec_pwm.h"
#include "ql_gpio.h"



int ql_pwm_enable(unsigned int     gpio_num)
{
	QUEC_PWM_Enable(gpio_num);
	return 0;
}

int ql_pwm_disable(unsigned int     gpio_num)
{
	QUEC_PWM_Disable(gpio_num);
	return 0;
}

int ql_pwm_config_plus_ex(unsigned int gpio_num,QL_PWM_CONFIG_EX *pwm_parameter)
{
	int ret = 0;
	int pwm_num = 0;

	QUEC_PWM_CONFIG_T pwm_config ;
	memset(&pwm_config,0,sizeof(QUEC_PWM_CONFIG_T));
	
	//Although the register has a full duty cycle output of 1, it will show a little duty cycle from the oscilloscope, so it is replaced by a gpio output high and low level
	if(pwm_parameter->high_one_cycle_duration==0 || pwm_parameter->total_one_cycle_duration==0)
	{ 
		ql_gpio_init( (GPIO_PIN_NUMBER_E)gpio_num,PIN_DIRECTION_OUT, PIN_PULL_PD,PIN_LEVEL_LOW);
		return 0;
	}
	if(pwm_parameter->high_one_cycle_duration==pwm_parameter->total_one_cycle_duration)
	{
		ql_gpio_init( (GPIO_PIN_NUMBER_E)gpio_num,PIN_DIRECTION_OUT, PIN_PULL_PU,PIN_LEVEL_HIGH );
		return 0;
	}

	ret = QUEC_PWM_PINMUX_Configure(gpio_num);
	if(ret != 0)
	{
		//pwm_log("gpio number =%d is invalid.\n",gpio_num); 
		return -1;
	}
	
	pwm_config.shutdown = QUEC_PWM_SHUTDOWN_ABRUPTLY;	
	pwm_config.pwm_out = QUEC_PWM_OUT_SET_BY_DCYCLE;	
	pwm_config.clk_src = pwm_parameter->clk_src;
	pwm_config.clk_freq =pwm_parameter->pwm_psc;
	pwm_config.high_one_cycle_duration =  pwm_parameter->high_one_cycle_duration;
	pwm_config.total_one_cycle_duration = pwm_parameter->total_one_cycle_duration ;

//	printf("PWM=%d\n %d\n %ld\n %d\n %d\n",gpio_num,pwm_parameter->clk_src,pwm_parameter->pwm_psc,pwm_parameter->high_one_cycle_duration,pwm_parameter->total_one_cycle_duration); 

	if(pwm_config.total_one_cycle_duration>1024)
	{
		return -1;
	}
	pwm_num = QUEC_GPIO_MAPTO_PWM_Device_Num(gpio_num);
	
	if( pwm_num >= QUEC_PWM_MAX_DEVICE )
		return -1;

	ret = (QUEC_PWM_RETURN_CODE_E)QUEC_PWM_Configure((QUEC_PWM_DEVICE_NUM_E)pwm_num,&pwm_config);

	if(ret != QUEC_PWM_RC_OK)
	{
		return -1;
	}
	return 0; 

}






