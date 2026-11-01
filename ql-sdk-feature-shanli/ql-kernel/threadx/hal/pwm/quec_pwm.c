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


#include "quec_pwm.h"
#include "utlTimer.h"
#include "quec_atcmd_network.h"
#include "quec_rtos.h"
#include "quec_gpio.h"
#include "quec_msg_process.h"
#include "gpio.h"

#if defined QUEC_PWM_ENBALE

#ifndef MIN_SYS


#if defined QUEC_PWM_LOG_ENABLE
	#define pwm_log(msg, ...)   custom_log("PWM", msg, ##__VA_ARGS__)
#else
	#define pwm_log(msg, ...)
#endif



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
	{117,	0, 	2},
	{32, 	1, 	2},
	{10, 	2, 	3},
	{11, 	3,	3},
	{6,  	2,	3},
	#ifdef __QUECTEL_PROJECT_EG800PCN_LA__
	{8,  	2,	1},
	#else
	{8,  	0,	1},
	#endif
	{7,  	3,	3},
	{69,  	0,	1},
	{70,  	1,	1},
	{89,  	2,	2},
	{29,  	0,	1},
	{56,  	1,	2},
	{58,  	3,	2},
};

extern void Delay(unsigned long uSec);

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

//获取GPIO复用为pwm功能的pwm号
int QUEC_GPIO_MAPTO_PWM_Device_Num(unsigned int gpio_num)
{
	unsigned int i;
	 for(i = 0; i < (sizeof(gpio_map_pwm_table)/sizeof(gpio_map_pwm_table[0])); i++)
	 {
		 if(gpio_map_pwm_table[i].gpio_num == gpio_num)
		 {
			 return gpio_map_pwm_table[i].pwm_num;
		 }
	 }	 
	 return QUEC_PWM_MAX_DEVICE;
}
 
//获取GPIO复用为pwm功能的fun号
int QUEC_PWM_GET_GPIO_FUNCTION(unsigned int gpio_num)
{
   unsigned int i;
	for(i = 0; i < (sizeof(gpio_map_pwm_table)/sizeof(gpio_map_pwm_table[0])); i++)
	{
		if(gpio_map_pwm_table[i].gpio_num == gpio_num)
		{
			return gpio_map_pwm_table[i].gpio_fun;
		}
	}	
	return -1;
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
	
	pwm_num = (QUEC_PWM_DEVICE_NUM_E)QUEC_GPIO_MAPTO_PWM_Device_Num(gpio_num);
    if( pwm_num >= QUEC_PWM_MAX_DEVICE )
	{
		return -1;
	}
	//barry 解决宝蓝低功耗，pwm无法关闭
	pwm_reg_bit_clr(pwm_apb_register[pwm_num],PWM_RST_BIT);

	QUEC_PWM_APB_BUS_CLK_Enable((QUEC_PWM_DEVICE_NUM_E)pwm_num);
	Delay(1*1000);
    pwm_reg_bit_set(pwm_apb_register[pwm_num],PWM_FUNC_CLK_EN_BIT);
	//pwm_log("%s, addr=%x,,reg=%x",__func__,pwm_apb_register[pwm_num],pwm_reg_read(pwm_apb_register[pwm_num]));
	return 0;
}

int QUEC_PWM_Disable(unsigned int     gpio_num)
{
 	int pwm_num = 0;
	
	pwm_num = QUEC_GPIO_MAPTO_PWM_Device_Num(gpio_num);
    if ( pwm_num >= QUEC_PWM_MAX_DEVICE )
        return -1;

	/* Warning !!!   Using of a Graceful shutdown should be done with a care */
	/*               Writing 0 to the SD bit, needs a little delay before turn the clock to off */  
	
	pwm_reg_bit_clr(pwm_apb_register[pwm_num],PWM_FUNC_CLK_EN_BIT);
	Delay(100*1000);
	QUEC_PWM_APB_BUS_CLK_Disable((QUEC_PWM_DEVICE_NUM_E)pwm_num);
	//pwm_log("%s, addr=%x,reg=%x",__func__,pwm_apb_register[pwm_num],pwm_reg_read(pwm_apb_register[pwm_num]));

    return 0;

    
}

int QUEC_PWM_PINMUX_Configure(unsigned int gpio_num)
{

	int fun = QUEC_PWM_GET_GPIO_FUNCTION(gpio_num);
	if(fun != -1)
	{
		(*(volatile unsigned long *)(GPIO_MFPR_ADDR(gpio_num))) = (0x10c0 | fun);
		
		return 0;
	}
	return -1;	
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


// Only standard

extern bool get_pwm_enable_flag(PWM_DEVICE_NUM       pwm_num);

UINT8 quec_pwm_datatransfor_flag=0;
unsigned long long quec_globle_rx_byte_all=0;
unsigned long long quec_globle_tx_byte_all=0;
OSATimerRef quec_data_transfor_timer_ref = NULL;

#if defined (__QUECTEL_PROJECT_EC600MCN_LA__) || defined (__QUECTEL_PROJECT_EC600MCN_CC__)|| defined (__QUECTEL_PROJECT_EC600MCN_GC__)|| defined (__QUECTEL_PROJECT_EC600MCN_LC__) || defined (__QUECTEL_PROJECT_EC600MCN_MC__)|| defined (__QUECTEL_PROJECT_EC600MCN_LF__)|| defined (__QUECTEL_PROJECT_EC600MCN_LE__) || defined (__QUECTEL_PROJECT_EC100MCN_LA__)\
	|| defined (__QUECTEL_PROJECT_EC600NCN_AC__) || defined (__QUECTEL_PROJECT_EC600MCN_NC__)\
	|| defined (__QUECTEL_PROJECT_EC600MEU_LA__) || defined (__QUECTEL_PROJECT_EC600MLA_LA__)
	unsigned char quec_net_status_pwm = PWM_DEVICE_1;
#elif defined ( __QUECTEL_PROJECT_EC800MCN_LA__ ) || defined (__QUECTEL_PROJECT_EC800MCN_LE__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_LC__) || defined (__QUECTEL_PROJECT_EC800MCN_LF__)\
	|| defined (__QUECTEL_PROJECT_EC800MCN_GA__) || defined (__QUECTEL_PROJECT_EC800MCN_MC__)\
	 || defined (__QUECTEL_PROJECT_EC800MCN_GC__) || defined (__QUECTEL_PROJECT_EC200MCN_LA__) \
	 || defined (__QUECTEL_PROJECT_EC200MCN_LC__) || defined (__QUECTEL_PROJECT_EC200MCN_GB__)\
	 || defined (__QUECTEL_PROJECT_EC800MCN_GM__) || defined (__QUECTEL_PROJECT_EG810MCN_GA__) \
	 || defined (__QUECTEL_PROJECT_EC800MCN_CC__) || defined (__QUECTEL_PROJECT_EC800MCN_NC__)\
	 || defined (__QUECTEL_PROJECT_EC800MCN_GD__) || defined (__QUECTEL_PROJECT_EG810MCN_LA__)\
	 || defined (__QUECTEL_PROJECT_EC200MCN_LE__) || defined (__QUECTEL_PROJECT_EC200MCN_LF__) \
	 || defined (__QUECTEL_PROJECT_EC800MCN_GB__) || defined (__QUECTEL_PROJECT_EG810MEU_LA__)\
	 || defined (__QUECTEL_PROJECT_EG810MCN_GB__) || defined (__QUECTEL_PROJECT_EG810MCN_LC__)\
	 || defined (__QUECTEL_PROJECT_EG810MEU_LC__) || defined (__QUECTEL_PROJECT_EG810MLA_LC__)
	unsigned char quec_net_status_pwm = PWM_DEVICE_2;

#elif defined (__QUECTEL_PROJECT_EC600KCN_CC__) || defined (__QUECTEL_PROJECT_EC600KCN_LC__) \
	|| defined (__QUECTEL_PROJECT_EC600KCN_CK__) || defined (__QUECTEL_PROJECT_EC600KCN_LK__)\
	|| defined (__QUECTEL_PROJECT_EC600KCN_MC__) 

	//ToDo,1602的NET_STATUS 需要GPIO 模拟，此处为了编译
	unsigned char quec_net_status_pwm = PWM_DEVICE_1;
#elif defined (__QUECTEL_PROJECT_EC800KCN_CC__) || defined (__QUECTEL_PROJECT_EG800KCN_GC__) \
	|| defined (__QUECTEL_PROJECT_EG800KEU_CC__)|| defined (__QUECTEL_PROJECT_EC800KCN_CZ__) \
	|| defined (__QUECTEL_PROJECT_EC800KCN_LC__)|| defined (__QUECTEL_PROJECT_EG800PCN_00LA__)\
	|| defined (__QUECTEL_PROJECT_EC800KCN_MC__)|| defined (__QUECTEL_PROJECT_EG800KLA_CC__)\
	|| defined (__QUECTEL_PROJECT_EC800KCN_MD__)|| defined (__QUECTEL_PROJECT_EG800KLA_LC__)\
	|| defined (__QUECTEL_PROJECT_EC800KCN_CK__) || defined (__QUECTEL_PROJECT_EC800KCN_LK__)\
	|| defined (__QUECTEL_PROJECT_EG800KEU_LC__)
	unsigned char quec_net_status_pwm = PWM_DEVICE_1;
#else
	#error "Please configure the project"
#endif


static QuecOSStatus quec_pwm_get(PWM_DEVICE_NUM pwm_device,PWM_CONFIGURE *p_pwm_config,bool *enable)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    
    if((p_pwm_config == NULL) ||(enable == NULL))
    {
        pwm_log("pwm_config or enable is a null pointer");
        return kGeneralErr;
    }

    if( pwm_device >= PWM_MAX_DEVICE )
    {
        pwm_log("pwm_device=%d is invalid",pwm_device);
        return kGeneralErr;
    }
     
    if (PWM_RC_OK != pwmConfigureGet(pwm_device, p_pwm_config))
	{
        pwm_log("pwm_device=%d get configur fail",pwm_device);
		return kGeneralErr;
	}
    
    *enable = get_pwm_enable_flag(pwm_device);

    return QUEC_SUCCESS;

    
}

QuecOSStatus quec_pwm_set(PWM_DEVICE_NUM pwm_device, PWM_OUT out, uint16 high_time, uint16 cycle_time)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    PWM_CONFIGURE pwm_config = {0};
    PWM_CONFIGURE get_pwm_config={0};
    bool enable = FALSE;
    
    if( pwm_device >= PWM_MAX_DEVICE )
    {
        pwm_log("pwm_device=%d is invalid",pwm_device);
        return kGeneralErr;
    }

    if((out != PWM_OUT_SET_BY_DCYCLE)&&(out != PWM_OUT_SET_FOR_FULL_PERIOD ))
    {
        pwm_log("pwm_out=%d is invalid",out);
        return kGeneralErr;
    }
	//pwmDisableb(pwm_device) may cause switch fail
	//  pwmDisable(pwm_device); AT+QFLST
    memset(&pwm_config,0,sizeof(PWM_CONFIGURE));
    
    pwm_config.shutdown = PWM_SHUTDOWN_ABRUPTLY;
    pwm_config.clk_freq = PWM_CLK_SRC_32K/64;                     
    pwm_config.pwm_out = out;
    pwm_config.high_one_cycle_duration = high_time/2;   
    pwm_config.total_one_cycle_duration = (cycle_time)/2;  
    pwm_config.clk_src = PWM_CLK_SRC_32K;

    ret = quec_pwm_get(pwm_device, &get_pwm_config, &enable);
    if(ret != QUEC_SUCCESS)
    {
        pwm_log("quec_pwm_get get fail");
    }
    else
    {
        ret = memcmp(&get_pwm_config, &pwm_config,sizeof(PWM_CONFIGURE));
        if((ret == 0) && enable)  //same and clock is already enable
        {
            pwm_log("pwm_device=%d is same with current config,not need set",pwm_device); 
            return QUEC_SUCCESS;  
        }
    }

    ret = pwmConfigure(pwm_device,&pwm_config);
    if(ret != PWM_RC_OK)
    {
       pwm_log("pwm_device=%d pwmConfigure fail",pwm_device); 
       return kGeneralErr;
    }

    pwmEnable(pwm_device);
    return QUEC_SUCCESS;   
}

//standard:only  pwm enable can set and may latest config effect
static QuecOSStatus quec_pwm_net_light_on(void)
{
    QuecOSStatus ret = kGeneralErr;
    
    ret = pwmEnable(quec_net_status_pwm);
    
    if(ret != PWM_RC_OK)
    {  
        pwm_log("pwmEnable fail"); 
        return kGeneralErr;
    }

    return QUEC_SUCCESS;
}

// standard:disable means low level
static QuecOSStatus quec_pwm_net_light_off(void)
{
	QuecOSStatus ret = kGeneralErr;

	pwmDisable(quec_net_status_pwm);

	if(ret != PWM_RC_OK)
	{
		pwm_log("pwmDisable fail"); 
		return kGeneralErr;
	}

	return QUEC_SUCCESS;
}


//standard: data transfer status polling timer cb
void quec_net_datatransfor_polling_timer_cb(void)
{
    pwm_log("datatransfor msg send"); 
    quec_send_msg_to_handle_task(QUEC_DATATRANSFORM_POLLING_MSG,NULL,QUEC_MSG_LEN_NONE); //Chaim 20190621 use message to handle
}


QuecOSStatus quec_net_datatransfor_polling_timer_start(void)
{
    QuecOSStatus status = QUEC_SUCCESS;
	quec_timer_status_t timer_status={0};
    if (quec_data_transfor_timer_ref != NULL)
    {
        status = quec_rtos_timer_get_status(quec_data_transfor_timer_ref,&timer_status);
        if((status==kNoErr)&&(timer_status.status==QUEC_TMR_STA_ENABLED))
        {
           pwm_log("timer is running");
           return status;
        }
		pwm_log("quec_net_datatransfor_polling_timer_start");
        status = quec_rtos_timer_start(quec_data_transfor_timer_ref,
                                 QUEC_DATA_TRANSFOR_POLLING_TIMR,
                                 0,
                                 quec_net_datatransfor_polling_timer_cb,
                                 0);

        //ASSERT(status == OS_SUCCESS);
        if(status != OS_SUCCESS)
        {
            status = kGeneralErr;
        }
    }
    else
    {
         status = kGeneralErr;
    }

    return status;
}

QuecOSStatus quec_net_datatransfor_polling_timer_stop(void)
{
    QuecOSStatus status = QUEC_SUCCESS;

    if (quec_data_transfor_timer_ref != NULL)
    {

        status = OSATimerStop(quec_data_transfor_timer_ref);
        ASSERT(status == OS_SUCCESS);
        if(status != OS_SUCCESS)
        {
            status = kGeneralErr;
        }
    }
    else
    {
         status = kGeneralErr;
    }

    return status;
}

void quec_net_datatransfor_polling_handle(void)
{
    unsigned long long rx_byte_all=get_rx_byte_all();
	unsigned long long tx_byte_all=get_tx_byte_all();
	
	pwm_log("quec_globle_rx_byte_all=%llu,quec_globle_tx_byte_all=%llu,rx_all=%llu,tx_all=%llu",quec_globle_rx_byte_all,quec_globle_tx_byte_all,rx_byte_all,tx_byte_all);
	if((quec_globle_rx_byte_all == rx_byte_all) && (quec_globle_tx_byte_all == tx_byte_all))
	{
		quec_pwm_datatransfor_flag=0;
		quec_globle_rx_byte_all=0;
		quec_globle_tx_byte_all=0;
	}
	else
	{
		quec_globle_rx_byte_all=rx_byte_all;
		quec_globle_tx_byte_all=tx_byte_all;
		if (quec_net_datatransfor_polling_timer_start() != QUEC_SUCCESS)
		{
			pwm_log("utlStartTimer ERROR"); 
		}
	}
}

QuecOSStatus quec_net_datatransfor_polling_timer_init(void)
{
    QuecOSStatus status = QUEC_SUCCESS;

    if (quec_data_transfor_timer_ref == NULL)
    {
        status = OSATimerCreate(&quec_data_transfor_timer_ref);
        if(status != OS_SUCCESS)
    	{
            pwm_log("OSATimerCreate status=%d error", status);
    		status = kGeneralErr;
    	}
    }
    return status;
}

//standard: init custom pwm
QuecOSStatus quec_pwm_init(void)
{
	quec_net_datatransfor_polling_timer_init();
    QuecOSStatus ret = kNoErr;

	return ret;	
}


#endif /*MIN_SYS*/

#endif

