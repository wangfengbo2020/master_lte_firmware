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

#include "quec_cust_startup_feature.h"

#ifdef QUECTEL_OPEN_CPU

#include "common.h"
#include "ql_boot_pwm.h"
#include "quec_startup_gpio.h"


#define pwm_log(msg, ...)   uart_printf("PWM", msg, ##__VA_ARGS__)

#define  PWM_PSCLK             (13000000)         // 13 MHz
#define  PWM_PSCLK_32K			 (32000)            //32KHz

#define  PWM_MAX_FREQ            (PWM_PSCLK)

#define  PWM_SD_POS              (6)
#define  PWM_FD_POS              (10)

#define  PWM_FREQ_MASK           (0x3f)
#define  PWM_DUTY_CYCLE_MASK     (0x3ff)
#define  PWM_PERIOD_MASK         (0x3ff)

#define  PWM_0_START_ADDRESS     (0xD401A000)
#define  PWM_1_START_ADDRESS     (0xD401A400)
#define  PWM_2_START_ADDRESS     (0xD401A800)
#define  PWM_3_START_ADDRESS     (0xD401AC00)

#define  APBC_PWM0_CLK_RST     (0xD401500C)
#define  APBC_PWM1_CLK_RST     (0xD4015010)
#define  APBC_PWM2_CLK_RST     (0xD4015014)
#define  APBC_PWM3_CLK_RST     (0xD4015018)

#define PWM_RST_BIT 0x4
#define PWM_FUNC_CLK_EN_BIT  0x2
#define PWM_APB_CLK_EN_BIT  0x1


#define pwm_reg_read(reg)						*(volatile unsigned int *)(reg)
#define pwm_reg_write(reg, val) 				*(volatile unsigned int *)(reg) = (val);
#define pwm_reg_bit_set(reg, val) 				*(volatile unsigned int *)(reg) |= (val); 
#define pwm_reg_bit_clr(reg, val) 				*(volatile unsigned int *)(reg) &= ~(val);

static volatile QUEC_PWM_REGISTERED_T *pwm_register[QUEC_PWM_MAX_DEVICE] =
                {
                    (volatile QUEC_PWM_REGISTERED_T *)(PWM_0_START_ADDRESS),
                    (volatile QUEC_PWM_REGISTERED_T *)(PWM_1_START_ADDRESS),
                    (volatile QUEC_PWM_REGISTERED_T *)(PWM_2_START_ADDRESS),
                    (volatile QUEC_PWM_REGISTERED_T *)(PWM_3_START_ADDRESS)
                };

static unsigned long pwm_apb_register[QUEC_PWM_MAX_DEVICE] =
				{
					(APBC_PWM0_CLK_RST),
					(APBC_PWM1_CLK_RST),
					(APBC_PWM2_CLK_RST),
					(APBC_PWM3_CLK_RST)
				};

struct QUEC_PWM_MAP_GPIO_S gpio_map_pwm_table[] = 
{
	{117, 0},
	{32, 1},
	{10, 2},
	{11, 3},
};

static void delay_ms(int time)
{    
   int i=0;  
   while(time-- > 0)
   {
      i=12000;  //自己定义
      while(i-- > 0) ;    
   }
}

void QUEC_PWM_APB_BUS_CLK_Enable(QUEC_PWM_DEVICE_NUM_E 	pwm_num)
{
	if(pwm_num  <= QUEC_PWM_DEVICE_1)
	{
		pwm_reg_bit_clr(pwm_apb_register[QUEC_PWM_DEVICE_0],PWM_RST_BIT);
		pwm_reg_bit_set(pwm_apb_register[QUEC_PWM_DEVICE_0],PWM_APB_CLK_EN_BIT);
		//pwm_log("%s,addr=%x,,reg=%x",__func__,pwm_apb_register[QUEC_PWM_DEVICE_0],pwm_reg_read(pwm_apb_register[QUEC_PWM_DEVICE_0]));
	}
	else
	{
		pwm_reg_bit_clr(pwm_apb_register[QUEC_PWM_DEVICE_2],PWM_RST_BIT);
		pwm_reg_bit_set(pwm_apb_register[QUEC_PWM_DEVICE_2],PWM_APB_CLK_EN_BIT);
		//pwm_log("%s,addr=%x,,reg=%x",__func__,pwm_apb_register[QUEC_PWM_DEVICE_2],pwm_reg_read(pwm_apb_register[QUEC_PWM_DEVICE_2]));
	}
}

 int  QUEC_GPIO_MAPTO_PWM_Device_Num(unsigned int		  gpio_num)
 {
	unsigned int i;
	 for(i = 0; i < 4; i++)
	 {
		 if(gpio_map_pwm_table[i].gpio_num == gpio_num)
		 {
			 return gpio_map_pwm_table[i].pwm_num;
		 }
	 }	 
	 return 0;
 }

void QUEC_PWM_APB_BUS_CLK_Disable(QUEC_PWM_DEVICE_NUM_E         pwm_num)
{
	if(pwm_num  <= QUEC_PWM_DEVICE_1)
	{
		pwm_reg_bit_clr(pwm_apb_register[QUEC_PWM_DEVICE_0],PWM_APB_CLK_EN_BIT);
	}
	else
	{
		pwm_reg_bit_clr(pwm_apb_register[QUEC_PWM_DEVICE_2],PWM_APB_CLK_EN_BIT);
	}
}

int QUEC_PWM_Enable(unsigned int     gpio_num)
{
	 
	int pwm_num = 0;
	
    if( gpio_num != 117 && gpio_num != 32 && gpio_num != 11 && gpio_num != 10)
    {
        //pwm_log("gpio_num = %d is invalid",gpio_num);
        return -1;
    }

	pwm_num = (QUEC_PWM_DEVICE_NUM_E)QUEC_GPIO_MAPTO_PWM_Device_Num(gpio_num);
    if( pwm_num >= QUEC_PWM_MAX_DEVICE )
	{
		return -1;
	}

	QUEC_PWM_APB_BUS_CLK_Disable((QUEC_PWM_DEVICE_NUM_E)pwm_num);
	delay_ms(1);
    pwm_reg_bit_set(pwm_apb_register[pwm_num],PWM_FUNC_CLK_EN_BIT);
	//pwm_log("%s, addr=%x,,reg=%x",__func__,pwm_apb_register[pwm_num],pwm_reg_read(pwm_apb_register[pwm_num]));
	return 0;

    
}

int QUEC_PWM_Disable(unsigned int     gpio_num)
{
 	int pwm_num = 0;
    if( gpio_num != 117 && gpio_num != 32 && gpio_num != 11 && gpio_num != 10)
    {
        //pwm_log("gpio_num = %d is invalid",gpio_num);
        return -1;
    }

	pwm_num = QUEC_GPIO_MAPTO_PWM_Device_Num(gpio_num);

    if ( pwm_num >= QUEC_PWM_MAX_DEVICE )
        return -1;

	/* Warning !!!   Using of a Graceful shutdown should be done with a care */
	/*               Writing 0 to the SD bit, needs a little delay before turn the clock to off */  
	
	pwm_reg_bit_clr(pwm_apb_register[pwm_num],PWM_FUNC_CLK_EN_BIT);
	delay_ms(100);
	QUEC_PWM_APB_BUS_CLK_Disable((QUEC_PWM_DEVICE_NUM_E)pwm_num);
	//pwm_log("%s, addr=%x,reg=%x",__func__,pwm_apb_register[pwm_num],pwm_reg_read(pwm_apb_register[pwm_num]));

    return 0;

    
}

int QUEC_PWM_PINMUX_Configure(unsigned int gpio_num)
{
	switch(gpio_num)
	{
		case GPIO_PIN_NO_117:
			(*(volatile unsigned long *)(0xD401E0B4)) = 0x10c2;
			break;
		case GPIO_PIN_NO_32:
			(*(volatile unsigned long *)(0xD401E15C)) = 0x10c2;
			break;
		case GPIO_PIN_NO_11:
			(*(volatile unsigned long *)(0xD401E108)) = 0x10c3;
			break;
		case GPIO_PIN_NO_10:
			(*(volatile unsigned long *)(0xD401E104)) = 0x10c3;
			break;
		default:
			//pwm_log("%s,unsupported PWM device:%d",__func__,gpio_num);
			break;
	}
	return 0;
		
}

QUEC_PWM_RETURN_CODE_E QUEC_PWM_Configure( QUEC_PWM_DEVICE_NUM_E  pwm_num , QUEC_PWM_CONFIG_T  *configuration )
{
	
	unsigned short total_cycle;
	unsigned char i;
	
    if ( pwm_num >= QUEC_PWM_MAX_DEVICE )
        return QUEC_PWM_RC_ILLEGALL_DEVICE_NUMBER;

		if( (PWM_PSCLK/configuration->clk_freq ) > PWM_MAX_FREQ ) 
        return QUEC_PWM_RC_ILLEGALL_FREQUENCY;

    if ( configuration->high_one_cycle_duration > configuration->total_one_cycle_duration )
        return QUEC_PWM_RC_ILLEGALL_DUTY_CYCLE;


	QUEC_PWM_APB_BUS_CLK_Enable(pwm_num);
	pwm_reg_bit_clr(pwm_apb_register[pwm_num],PWM_RST_BIT); //clear rst bit

	pwm_reg_bit_clr(pwm_apb_register[pwm_num], 1<< 4);       //clr clk src    
	pwm_reg_bit_set(pwm_apb_register[pwm_num],configuration->clk_src << 4); //set clk src 32K or 13M
	
	pwm_register[pwm_num]->control = (	( configuration->shutdown << PWM_SD_POS) | (( configuration->clk_freq  - 1 ) & PWM_FREQ_MASK ));
	
    pwm_register[pwm_num]->duty_cycle = (( configuration->pwm_out << PWM_FD_POS) | (configuration->high_one_cycle_duration & PWM_DUTY_CYCLE_MASK));

    pwm_register[pwm_num]->period_val = ( configuration->total_one_cycle_duration & PWM_PERIOD_MASK);

	//pwm_log("%s,control=%x,,duty_cycle=%x,, period_val=%x",__func__,pwm_register[pwm_num]->control,pwm_register[pwm_num]->duty_cycle,pwm_register[pwm_num]->period_val);

    return QUEC_PWM_RC_OK;

}


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
		
    if( gpio_num != 117 && gpio_num != 32 && gpio_num != 11 && gpio_num != 10)
	{
		//pwm_log("gpio_num = %d is invalid",gpio_num);
		return -1;
	}
	
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
	/**/
	pwm_num = QUEC_GPIO_MAPTO_PWM_Device_Num(gpio_num);
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

	ret = (QUEC_PWM_RETURN_CODE_E)QUEC_PWM_Configure((QUEC_PWM_DEVICE_NUM_E)pwm_num,&pwm_config);

	if(ret != QUEC_PWM_RC_OK)
	{
		return -1;
	}
	return 0; 

}


/*Function: quec_pwm_test1
/*13M 实际值 只有12.7998M左右，32K实际值为32787
*此案例产生的pwm频率可根据用户选择时钟源、分频系数、重装值来自定义设置频率；选择高电平、重装值时间(整个周期时间)确定PWM占空比:
 输出PWM的频率为： f = MCLK / ( (psc+1)(arr+1) ) ; 设置的arr为10位寄存器，因此重装值满足1=<value<1024。需要注意重装值的范围。
注意：此处psc+1,是为了防止用户输入0分频，不便于理解，在底层代码中已减去1；因此设置psc的值为多少，即多少分频。
*/
void ql_pwm_test(void)
{
    pwm_log("pwm test is running!!!\n");

	unsigned int gpio_num1 = 117;
	unsigned int gpio_num2 = 32;
	unsigned int gpio_num3 = 11;
	unsigned int gpio_num4 = 10;

	unsigned long pwm_psc = 1;


	QL_PWM_CONFIG_EX pwm_parameter1;
	QL_PWM_CONFIG_EX pwm_parameter2;
	QL_PWM_CONFIG_EX pwm_parameter3;
	QL_PWM_CONFIG_EX pwm_parameter4;
	//可以自己按公式计算得到想要的PWM，提高精确度

	pwm_log("pwm test QUEC_PWM_CLK_SRC_13M!!!\n");
	pwm_parameter1.pwm_psc = pwm_psc;   //(value:1~64)
	pwm_parameter1.high_one_cycle_duration = 195;
	pwm_parameter1.total_one_cycle_duration =389;  //(value: 1<value<1024)	 f=12.7998 MHz/(389+1)=32820 HZ
	pwm_parameter1.clk_src=QL_PWM_CLK_SRC_13M;	
	ql_pwm_config_plus_ex(gpio_num1,&pwm_parameter1);	//调用PWM函数接口
	ql_pwm_enable(gpio_num1);							//PWM使能

	pwm_log("pwm test QUEC_PWM_CLK_SRC_32K!!!\n");  
	pwm_parameter2.pwm_psc = 1;   		//(value:1~64)
	pwm_parameter2.high_one_cycle_duration = 164;
	pwm_parameter2.total_one_cycle_duration = 327;  //(value: 1<value<1024)	 f=32787/(327+1)=99.96 HZ
	pwm_parameter2.clk_src=QL_PWM_CLK_SRC_32K;
	
	//test_log("PWM=%d\n %d\n %ld\n %d\n %d\n",gpio_num2,pwm_parameter2.clk_src,pwm_parameter2.pwm_psc,pwm_parameter2.high_one_cycle_duration,pwm_parameter2.total_one_cycle_duration); 
	ql_pwm_config_plus_ex(gpio_num2,&pwm_parameter2);
	ql_pwm_enable(gpio_num2);

	pwm_parameter3.pwm_psc = 1;	//(value:1~64)
	pwm_parameter3.high_one_cycle_duration = 17;//17
	pwm_parameter3.total_one_cycle_duration = 33;	//(value: 1<value<1024)	 f=32787/(32+1)=964.32 HZ
	pwm_parameter3.clk_src=QL_PWM_CLK_SRC_32K;
	ql_pwm_config_plus_ex(gpio_num3,&pwm_parameter3);
	ql_pwm_enable(gpio_num3);

	pwm_parameter4.pwm_psc = 1;	//(value:1~64)
	pwm_parameter4.high_one_cycle_duration = 160;	
	pwm_parameter4.total_one_cycle_duration = 320;	//(value: 1<value<1024)	 f=32787/(320+1)=102.14 HZ
	pwm_parameter4.clk_src=QL_PWM_CLK_SRC_32K;
	ql_pwm_config_plus_ex(gpio_num4,&pwm_parameter4);
	ql_pwm_enable(gpio_num4);

	
}

#endif
