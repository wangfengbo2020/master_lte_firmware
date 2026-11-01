/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/
/*=================================================================

						EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN			  WHO		  WHAT, WHERE, WHY
------------	 -------	 -------------------------------------------------------------------------------
25/09/2020        Destin     Add gpio pin power led,show csq value
03/06/2019        Fitz       Add LCC gpio reconfig process.
11/02/2018		  Jensen	 added gpio access interface, added EC26C gpio config
10/15/2018		  Chaim 	 add gpio init function
=================================================================*/

/*===========================================================================
 * include files
 ===========================================================================*/
#include "quec_gpio.h"
#include "quec_cust_feature.h"
#include "quec_msg_process.h"
#include "quec_atcmd_sim.h"
#include "quec_board_common.h"
#include "psm_wrapper.h"
#include "quec_power_manager.h"
#include "pwm.h"
#include "quec_urc.h"
#include "quec_sio.h"

#ifdef QUEC_GPIO_ENABLE

/*===========================================================================
 * Macro Definition
 ===========================================================================*/
#ifdef QUEC_GPIO_LOG_ENABLE
	#define gpio_log(msg,...)   custom_log("GPIO",msg,##__VA_ARGS__)
#else
	#define gpio_log(msg,...)   
#endif



#define QUEC_GPIO_DEBOUNCE_NVM  "debounce_time_nv"
#define QUEC_SCLK_SIM_PIN_CFG   "usim_pin_cfg"

/*===========================================================================
 * extern
 ===========================================================================*/
extern quec_gpio_debounce_s dtr_debounce;
#ifdef QUEC_UART1_HARDWARE_FLOWERCTRL
extern quec_gpio_debounce_s cts_debounce;
#endif

void quec_usim_debounce_timer_handler(void);
#ifdef QUEC_AIR_PLANE_CTRL_ENABLE
void quec_air_plan_debounce_timer_handler(void);
#endif 
static void quec_lcc_reconfig_gpio(void);
static QuecOSStatus quec_lcc_config_check(void);
#ifdef QUEC_CUSTOM_LAST_GASP_FEATURE
void quec_last_gasp_debounce_timer_handler(void);
#endif 
#ifdef QUEC_SLEEP_AP_READY
void quec_apready_debounce_timer_handler(UINT32);
#endif

#ifdef __QUEC_OEM_VER_WUS__
void quec_wussrc4_debounce_timer_handler(UINT32);
#endif

void quec_wakeup_in_timer_handler(void);

/*===========================================================================
 * struct,enum definition
 ===========================================================================*/
typedef struct
{
	GPIO_PinNumbers pin_num;
	unsigned long reg_addr;
}quec_gpio_regaddr_s;


//jensen.fang 20181102: pin handle of each gpio
//GPIO_PortHandle quec_pin_handle[GPIO_MAX_AMOUNT_OF_PINS] = {0};

 GPIO_PinConfiguration gpio_output_dvl =
 {
     .pinNumber = GPIO_MAX_AMOUNT_OF_PINS,
     .debounce = GPIO_DEBOUNCE_DISABLE,
     .direction = GPIO_OUT_PIN,
     .pullUpDown = GPIO_PULL_DISABLE,
     .initialValue = GPIO_INITIAL_VALUE_LOW,
     .transitionType = GPIO_NO_EDGE,
 };



/*===========================================================================
 * Global Variable
 ===========================================================================*/
//fitz.xu 20190326: Add for air plane ctrl.
#ifdef QUEC_AIR_PLANE_CTRL_ENABLE
OS_HISR air_plane_pin_hisr = NULL;
static quec_pin_level_value_e airplane_pin_level = QUEC_PIN_LEVEL_HIGH;
#endif

uint8 g_inter_log = FALSE;
uint8 g_usim_wakeup_flag  = FALSE;  //Chaim 20190813 usim wakeup flag,default false
OS_HISR usim_presencehisr = NULL;

#if (QUEC_USIM_PRESENCE_INTERRUPT_ENABLE == 1)
quec_gpio_debounce_s usim_debounce = 
{
    QUEC_USIM_DET_PIN,
    NULL,
    QUEC_GPIO_DEBOUNCE_INTERVAL_MS,
    QUEC_GPIO_DEBOUNCE_INTERVAL_COUNT,
    0,
    0,
    0,
    quec_usim_debounce_timer_handler
};
#endif

#ifdef QUEC_AIR_PLANE_CTRL_ENABLE
quec_gpio_debounce_s air_plan_debounce = 
{
    QUEC_AIR_PLAN_CTRL_PIN, 
    NULL,
    QUEC_GPIO_DEBOUNCE_INTERVAL_MS,
    QUEC_GPIO_DEBOUNCE_INTERVAL_COUNT,
    0,
    0,
    0,
    quec_air_plan_debounce_timer_handler
};    
#endif
#ifdef QUEC_SLEEP_AP_READY
OS_HISR apready_pin_hisr = NULL;

quec_gpio_debounce_s apready_debounce = 
{
    QUEC_APREADY_DET_PIN,
    NULL,
    QUEC_GPIO_DEBOUNCE_INTERVAL_MS,
    QUEC_GPIO_DEBOUNCE_INTERVAL_COUNT,
    QUEC_PIN_LEVEL_LOW,
    QUEC_PIN_LEVEL_LOW,
    0,
    quec_apready_debounce_timer_handler
};
#endif

#if defined(__QUEC_OEM_VER_WUS__)
OS_HISR quec_wussrc4_hisr = NULL;
uint8 quec_wussrc4_det_level=0;
quec_gpio_debounce_s quec_wussrc4_debounce = 
{
    QUEC_WUS_WAKEUP_SRC4,
    NULL,
    QUEC_GPIO_DEBOUNCE_INTERVAL_MS,
    QUEC_GPIO_DEBOUNCE_INTERVAL_COUNT,
    QUEC_PIN_LEVEL_LOW,
    QUEC_PIN_LEVEL_LOW,
    0,
    quec_wussrc4_debounce_timer_handler
};

void quec_wussrc4_debounce_timer_handler(UINT32 val)
    {
        QuecOSStatus ret = kGeneralErr;
        quec_msg_io_conf_value_s dtr_s = {0};
        quec_sleep_msg_s  sleep_msg={0};
        ret = quec_gpio_debounce_timer_handler(&quec_wussrc4_debounce);
        ret+=quec_set_gpio_mfprReg(QUEC_WUS_WAKEUP_SRC4, (QUEC_WUSSRC4_GPIO_AF | QUEC_PULL_UP_C | QUEC_DRV_SLOW_C |QUEC_EDGE_FALL_EN|QUEC_EDGE_RISE_EN) & (~QUEC_EDGE_CLEAR));
        if(QUEC_SUCCESS == ret)
        {
            sleep_msg.sleep_bit =  QUEC_SLEEP_WUS_GPIO_BIT;
            if(quec_wussrc4_det_level == quec_wussrc4_debounce.last_level)
            {
                sleep_msg.value.sleep_flag = QUEC_CUSTOMER_FLAG_NOT_SLEEP;
                quec_sleep_not_allown_sleep();
            }
            else
            {
                sleep_msg.value.sleep_flag = QUEC_CUSTOMER_FLAG_ALLOW_SLEEP;
            }
            ret = quec_send_sleep_msg(&sleep_msg);
        }
    }
    
void quec_wussrc4_hisr_callback(void)
{
    quec_gpio_interrupt_debounce_handler(&quec_wussrc4_debounce);
}

void Quec_WusSrc4_GPIOCallback(void)
{		
        GPIOEdgeDetectionDisable(QUEC_WUS_WAKEUP_SRC4);
        if(quec_wussrc4_hisr != NULL)
        {
            OS_Activate_HISR(&quec_wussrc4_hisr); 
        }
}

void quec_wus_power_io_set(uint8 gpio_level)
{
    if((gpio_level!=TRUE && gpio_level !=FALSE))
    return;
/*    GpioClearEdgeDetection(QUEC_WUS_WAKEUP_SRC4); 
    if(gpio_level==FALSE)
    GPIOEdgeDetectionEnable(QUEC_WUS_WAKEUP_SRC4);
    else
    {(GpioGetLevel(QUEC_WUS_POWER_IO)==gpio_level)|| 
    GPIOEdgeDetectionDisable(QUEC_WUS_WAKEUP_SRC4);
    }*/
    if((gpio_level==FALSE)&&(quec_sleepinfo_is_empty()!=TRUE))
    {
       //USB_TRACE("SLEEP INFO UNCLEAR");
       return;
    }
    GpioSetLevel(QUEC_WUS_POWER_IO, gpio_level);
}

BOOL quec_wussrc4_pin_is_trig(void)
{
    BOOL ret=FALSE;
    if(GpioGetLevel(QUEC_WUS_WAKEUP_SRC4) == quec_wussrc4_det_level){
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }
    return ret;
}

QuecOSStatus quec_wus_gpio_init(void)
{
    QuecOSStatus ret = kGeneralErr;

    GPIO_PinConfiguration quec_wussrc4_cfg=                       
{                                              
        .pinNumber = QUEC_WUS_WAKEUP_SRC4,        
         .direction = GPIO_IN_PIN,          
         .transitionType = GPIO_TWO_EDGE,     
         .debounce = GPIO_DEBOUNCE_ENABLE,     
         .pullUpDown = GPIO_PULLUP_ENABLE,    
         .initialValue = GPIO_INITIAL_VALUE_HIGH
};
    //CPUartLogPrint("quec_apready_pin_init start ",TRUE);
    GPIO_PinConfiguration quec_wus_power_io_cfg=                       
{                                              
        .pinNumber = QUEC_WUS_POWER_IO,        
         .direction = GPIO_OUT_PIN,          
         .transitionType = GPIO_NO_EDGE,     
         .debounce = GPIO_DEBOUNCE_ENABLE,     
         .pullUpDown = GPIO_PULLUP_ENABLE,    
         .initialValue = GPIO_INITIAL_VALUE_HIGH
};
    ret=quec_set_gpio_mfprReg(quec_wus_power_io_cfg.pinNumber, (QUEC_WUS_POWER_IO_AF | QUEC_PULL_UP_C | QUEC_DRV_SLOW_C |QUEC_RESERVED_C));
    ret=GPIOConfigure_Ex(&quec_wus_power_io_cfg, NULL, NULL);

    if(quec_wussrc4_det_level==1)
    {
    quec_wussrc4_cfg.pullUpDown=GPIO_PULLDN_ENABLE;
    quec_wussrc4_cfg.initialValue=GPIO_INITIAL_VALUE_LOW;
    ret=quec_set_gpio_mfprReg(quec_wussrc4_cfg.pinNumber, (QUEC_WUSSRC4_GPIO_AF | QUEC_PULL_DN_C | QUEC_DRV_SLOW_C |QUEC_EDGE_FALL_EN|QUEC_EDGE_RISE_EN) & (~QUEC_EDGE_CLEAR));
    }
    else
    {
    quec_wussrc4_cfg.pullUpDown=GPIO_PULLUP_ENABLE;
    quec_wussrc4_cfg.initialValue=GPIO_INITIAL_VALUE_HIGH;
    ret=quec_set_gpio_mfprReg(quec_wussrc4_cfg.pinNumber, (QUEC_WUSSRC4_GPIO_AF | QUEC_PULL_UP_C | QUEC_DRV_SLOW_C |QUEC_EDGE_FALL_EN|QUEC_EDGE_RISE_EN) & (~QUEC_EDGE_CLEAR));
    }
    if(ret != QUEC_SUCCESS)
    {
        return ret;
    }
    if(quec_wussrc4_hisr!=NULL)
    return QUEC_SUCCESS;
    
    ret = GPIOConfigure_Ex(&quec_wussrc4_cfg, Quec_WusSrc4_GPIOCallback , NULL);
    if(ret != QUEC_SUCCESS)
    {
        return ret;
    }	
    //CPUartLogPrint("quec_apready_pin_init creat hisr ",TRUE);
    OS_Create_HISR(&quec_wussrc4_hisr, "wussrc4_hisr", quec_wussrc4_hisr_callback, HISR_PRIORITY_2);
    ret = GpioClearEdgeDetection(quec_wussrc4_cfg.pinNumber);
    if(quec_wussrc4_debounce.timerRef==NULL)
    ret += quec_gpio_debounce_init(&quec_wussrc4_debounce);
    ret += GpioEnableEdgeDetection(quec_wussrc4_cfg.pinNumber, quec_wussrc4_cfg.transitionType);
    
    return ret;

}
#endif

quec_gpio_debounce_s wakeup_in_debounce = {
                                  QUEC_WAKEUP_IN_GPIO,
                                  NULL,
                                  QUEC_GPIO_DEBOUNCE_INTERVAL_MS,
                                  QUEC_GPIO_DEBOUNCE_INTERVAL_COUNT,
                                  0,
                                  0,
                                  0,
                                  quec_wakeup_in_timer_handler};


quec_gpio_debounce_param_s  g_debounce_param[QUEC_DEBOUNCE_GPIO_NUM] = 
{
#if (QUEC_USIM_PRESENCE_INTERRUPT_ENABLE ==1)
#if defined __QUEC_OEM_VER_GENUS__ || defined __QUEC_OEM_VER_ALLIED__
    {USIM_DEBOUNCE, QUEC_GENUS_DEBOUNCE_INTERVAL_MS, QUEC_GENUS_DEBOUNCE_INTERVAL_COUNT},
#else
    {USIM_DEBOUNCE, QUEC_GPIO_DEBOUNCE_INTERVAL_MS, QUEC_GPIO_DEBOUNCE_INTERVAL_COUNT},
#endif
#endif
    {DTR_DEBOUNCE,  QUEC_GPIO_DEBOUNCE_INTERVAL_MS, QUEC_GPIO_DEBOUNCE_INTERVAL_COUNT},
#ifdef QUEC_UART1_HARDWARE_FLOWERCTRL
    {CTS_DEBOUNCE,  QUEC_GPIO_DEBOUNCE_INTERVAL_MS, QUEC_GPIO_DEBOUNCE_INTERVAL_COUNT},
#endif
#ifdef QUEC_AIR_PLANE_CTRL_ENABLE  
    {AIR_PLAN_DEBOUNCE,  QUEC_GPIO_DEBOUNCE_INTERVAL_MS, QUEC_GPIO_DEBOUNCE_INTERVAL_COUNT},
#endif    
#ifdef QUEC_SLEEP_AP_READY
    {APREADY_DEBOUNCE, QUEC_GPIO_DEBOUNCE_INTERVAL_MS, QUEC_GPIO_DEBOUNCE_INTERVAL_COUNT},
#endif

    {WAKEUP_IN_DEBOUNCE, QUEC_GPIO_DEBOUNCE_INTERVAL_MS, QUEC_GPIO_DEBOUNCE_INTERVAL_COUNT},
};

#ifdef QUEC_CUSTOM_LAST_GASP_FEATURE
OS_HISR last_gasp_pin_hisr = NULL;
static quec_pin_level_value_e lgasp_pin_level = QUEC_PIN_LEVEL_HIGH;
quec_gpio_debounce_s last_gasp_debounce = 
{
    QUEC_LAST_GASP_TRIGGER_GPIO,
    NULL,
    0,
    0,
    0,
    0,
    0,
    quec_last_gasp_debounce_timer_handler
};    
#endif


// destin 2020.09.23 gpio led show signal qulity modified by open group

#ifdef QUEC_CSQ_GPIO_DISPLAY_ENABLE
#include "mm_api.h"
static bool nw_led_init = 0;
extern volatile UINT8 csq_gpio_cfg_state;
#if QUEC_DUAL_SIM_SUPPORT
extern mmExtendedSignal_quec quec_netquality_info[2];
#else
extern mmExtendedSignal_quec quec_netquality_info;
#endif
extern void quec_cesq_2quec_csq(void * netquality_info,INT16 * rssi,INT16 * ber);

GPIO_PinConfiguration quec_gpio_nwled[] =
{
	{GPIO_PIN_25, GPIO_OUT_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULL_DISABLE, GPIO_INITIAL_VALUE_LOW},
	{GPIO_PIN_21, GPIO_OUT_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULL_DISABLE, GPIO_INITIAL_VALUE_LOW}, 
	{GPIO_PIN_26, GPIO_OUT_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULL_DISABLE, GPIO_INITIAL_VALUE_LOW},
	{GPIO_PIN_22, GPIO_OUT_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULL_DISABLE, GPIO_INITIAL_VALUE_LOW},	
};

const unsigned long mfpr_fun[] = 
{
	MFP_AF0,
	MFP_AF0,
	MFP_AF0, 
	MFP_AF0,
};
#endif



/*===========================================================================
 * Functions
 ===========================================================================*/

QuecOSStatus quec_read_usim_presence_sclk_cfg(void)
{
    QuecOSStatus ret = kGeneralErr;
	ret = quectel_nv_fat_read(QUEC_SCLK_SIM_PIN_CFG, &g_usim_wakeup_flag, sizeof(g_usim_wakeup_flag));
    if(ret != QUEC_SUCCESS)
    {
        quec_debug_print_uart("usim wakeup flag read fail,use default value=%d",g_usim_wakeup_flag);    
    }

    return ret;
}

uint8  quec_get_usim_presence_sclk_cfg(void)
{
    return g_usim_wakeup_flag;
}

QuecOSStatus quec_write_usim_presence_sclk_cfg(uint8 set_value)
{
    QuecOSStatus ret = kGeneralErr;

    if((TRUE != set_value)&&(FALSE != set_value))
    {
        gpio_log("set_value=%d is invalid",set_value);
		return ret;      
    }
    if(quec_get_usim_presence_sclk_cfg() == set_value)
    {
       gpio_log("set_value=%d is same with system value",set_value);
	   return ret; 
    }
    g_usim_wakeup_flag = set_value;
	ret = quectel_nv_fat_write(QUEC_SCLK_SIM_PIN_CFG, &g_usim_wakeup_flag, sizeof(g_usim_wakeup_flag));
    if(ret != QUEC_SUCCESS)
    {
        gpio_log("usim wakeup flag read fail,use default value=%d",g_usim_wakeup_flag);  
    }
    return ret;
}


QuecOSStatus quec_debounce_timer_read(void)
{
    QuecOSStatus ret = kGeneralErr;
	unsigned int feature_flag = 0;
    char res_in_buf[128] = {0};
    char res_out_buf[128] = {0};
    uint8 resp_len=0;
    uint8 i = 0;
	ret = quectel_nv_fat_read(QUEC_GPIO_DEBOUNCE_NVM, g_debounce_param, QUEC_DEBOUNCE_GPIO_NUM*sizeof(quec_gpio_debounce_param_s));

    if(ret != QUEC_SUCCESS)
    {
        quec_debug_print_uart("debounce timer read fail,use default value");
//genus default value
#if defined __QUEC_OEM_VER_GENUS__ || defined __QUEC_OEM_VER_ALLIED__
        quec_debug_print_uart("genus macro define");
#endif  
  
    }

    for(i =0; i<QUEC_DEBOUNCE_GPIO_NUM;i++)
    {
        switch(g_debounce_param[i].pin_usage)
        {
#if (QUEC_USIM_PRESENCE_INTERRUPT_ENABLE ==1)
            case USIM_DEBOUNCE:
                usim_debounce.interval_time = g_debounce_param[i].debounce_param.time_out;
                usim_debounce.interval_count = g_debounce_param[i].debounce_param.count;
            break;
#endif            
            case DTR_DEBOUNCE:

                dtr_debounce.interval_time = g_debounce_param[i].debounce_param.time_out;
                dtr_debounce.interval_count = g_debounce_param[i].debounce_param.count;
            break;
#ifdef QUEC_UART1_HARDWARE_FLOWERCTRL
            case CTS_DEBOUNCE:
                cts_debounce.interval_time = g_debounce_param[i].debounce_param.time_out;
                cts_debounce.interval_count = g_debounce_param[i].debounce_param.count;
            break;
#endif
#ifdef QUEC_AIR_PLANE_CTRL_ENABLE  
            case AIR_PLAN_DEBOUNCE:
                air_plan_debounce.interval_time = g_debounce_param[i].debounce_param.time_out;
                air_plan_debounce.interval_count = g_debounce_param[i].debounce_param.count;
            break;
#endif           
#ifdef QUEC_SLEEP_AP_READY
                case APREADY_DEBOUNCE:
                    apready_debounce.interval_time = g_debounce_param[i].debounce_param.time_out;
                    apready_debounce.interval_count = g_debounce_param[i].debounce_param.count;
                break;
#endif
            default:
                quec_debug_print_uart("pin_usage=%d is invalid", g_debounce_param[i].pin_usage);
            break;
        }
    }
    return ret;
}



QuecOSStatus quec_debounce_timer_get(quec_gpio_debounce_param_s *p_debounce)
{
    QuecOSStatus ret = kGeneralErr; 
    uint8 i = 0;

    if(NULL == p_debounce)
    {
         gpio_log("p_debounce is null pointer");
		 return ret;    
    }
    for(i = 0; i< QUEC_DEBOUNCE_GPIO_NUM; i++)
    {
        if(g_debounce_param[i].pin_usage == p_debounce->pin_usage)
        {
            
            gpio_log("get_timeout=%d, get_count=%d",g_debounce_param[i].debounce_param.time_out,g_debounce_param[i].debounce_param.count);            
            p_debounce->debounce_param.time_out =  g_debounce_param[i].debounce_param.time_out;
            p_debounce->debounce_param.count =  g_debounce_param[i].debounce_param.count;
            break; 
        }
    }

    if(QUEC_DEBOUNCE_GPIO_NUM ==  i)
    {
        gpio_log("not found debounce pin usage");
		return ret;       
    }
    
    return QUEC_SUCCESS;
    
}


QuecOSStatus quec_debounce_timer_set(quec_gpio_debounce_param_s *p_debounce)
{
    QuecOSStatus ret = kGeneralErr; 
    uint8 i = 0;
    //GPIO_PortHandle port_handle = 0;
    quec_timer_status_t timerStatus ={0}; 
    uint16 time_out_tmp =0;
    uint16 count_tmp = 0;
    
    if(NULL == p_debounce)
    {
         gpio_log("p_debounce is null pointer");
		 return ret;    
    }
    for(i = 0; i< QUEC_DEBOUNCE_GPIO_NUM; i++)
    {
        if(g_debounce_param[i].pin_usage == p_debounce->pin_usage)
        {
            
            gpio_log("pin_usage=%d,time_out=%d,set_timeout=%d,count=%d,set_count=%d",p_debounce->pin_usage,\
                g_debounce_param[i].debounce_param.time_out,p_debounce->debounce_param.time_out,\
                g_debounce_param[i].debounce_param.count,p_debounce->debounce_param.count); 
            
            if((g_debounce_param[i].debounce_param.time_out != p_debounce->debounce_param.time_out) ||
                (g_debounce_param[i].debounce_param.count != p_debounce->debounce_param.count))
            {
                time_out_tmp =  g_debounce_param[i].debounce_param.time_out;
                count_tmp =  g_debounce_param[i].debounce_param.count;

                g_debounce_param[i].debounce_param.time_out = p_debounce->debounce_param.time_out;
                g_debounce_param[i].debounce_param.count = p_debounce->debounce_param.count;

                gpio_log("pin_usage=%d,time_out=%d,set_timeout=%d,count=%d,set_count=%d",p_debounce->pin_usage,\
                g_debounce_param[i].debounce_param.time_out,p_debounce->debounce_param.time_out,\
                g_debounce_param[i].debounce_param.count,p_debounce->debounce_param.count);
                
                switch(p_debounce->pin_usage)
                {
#if (QUEC_USIM_PRESENCE_INTERRUPT_ENABLE ==1)
                    case USIM_DEBOUNCE:
                        GpioClearEdgeDetection(QUEC_USIM_DET_PIN); 
                        GPIOEdgeDetectionDisable(QUEC_USIM_DET_PIN);
                        ret = quec_rtos_timer_get_status(usim_debounce.timerRef,&timerStatus);
                        if ((ret == kNoErr)&&(QUEC_TMR_STA_ENABLED == timerStatus.status))
                        {
                            gpio_log("usim stop timer");
                            quec_rtos_timer_stop(usim_debounce.timerRef);
                        } 
                        else
                        {
                            gpio_log("usim ret=%d,timerStatus=%d",ret,timerStatus.status);    
                        }

                        ret = quectel_nv_fat_write(QUEC_GPIO_DEBOUNCE_NVM, g_debounce_param, QUEC_DEBOUNCE_GPIO_NUM*sizeof(quec_gpio_debounce_param_s));
                        if(QUEC_SUCCESS == ret)
                        {
                            usim_debounce.interval_time = g_debounce_param[i].debounce_param.time_out;
                            usim_debounce.interval_count = g_debounce_param[i].debounce_param.count; 
                        }
                        else
                        {
                            gpio_log("usim debounce write fail,resume timer");
                            g_debounce_param[i].debounce_param.time_out = time_out_tmp;
                            g_debounce_param[i].debounce_param.count = count_tmp;
                        }
                        
                       GPIOEdgeDetectionEnable(QUEC_USIM_DET_PIN);
                        
                    break;
#endif                    
                    case DTR_DEBOUNCE:

                        GpioClearEdgeDetection(UART_DTR_PIN_NUM);
                        GPIOEdgeDetectionDisable(UART_DTR_PIN_NUM);
                        ret = quec_rtos_timer_get_status(dtr_debounce.timerRef,&timerStatus);
                        if ((ret == kNoErr)&&(QUEC_TMR_STA_ENABLED == timerStatus.status))
                        {
                            gpio_log("dtr stop timer");
                            quec_rtos_timer_stop(dtr_debounce.timerRef);
                        } 
                        else
                        {
                            gpio_log("dtr ret=%d,timerStatus=%d",ret,timerStatus.status);    
                        }
                        ret = quectel_nv_fat_write(QUEC_GPIO_DEBOUNCE_NVM, g_debounce_param, QUEC_DEBOUNCE_GPIO_NUM*sizeof(quec_gpio_debounce_param_s));
                        if(QUEC_SUCCESS == ret)
                        {
                            dtr_debounce.interval_time = g_debounce_param[i].debounce_param.time_out;
                            dtr_debounce.interval_count = g_debounce_param[i].debounce_param.count;
                            gpio_log("dtr debounce set ok,interval_time=%d,interval_count=%d",dtr_debounce.interval_time,dtr_debounce.interval_count); 
                        }
                        else
                        {
                            
                            gpio_log("dtr debounce write fail,resume timer");
                            g_debounce_param[i].debounce_param.time_out = time_out_tmp;
                            g_debounce_param[i].debounce_param.count = count_tmp;
                        }                      
                        
                        GPIOEdgeDetectionEnable(UART_DTR_PIN_NUM);
                    break;
#ifdef QUEC_UART1_HARDWARE_FLOWERCTRL

                    case CTS_DEBOUNCE:

                       GpioClearEdgeDetection(UART_CTS_PIN_NUM); 
                       GPIOEdgeDetectionDisable(UART_CTS_PIN_NUM);
                        ret = quec_rtos_timer_get_status(cts_debounce.timerRef,&timerStatus);
                        if ((ret == kNoErr)&&(QUEC_TMR_STA_ENABLED == timerStatus.status))
                        {
                            gpio_log("cts stop timer");
                            quec_rtos_timer_stop(cts_debounce.timerRef);
                        } 
                        else
                        {
                            gpio_log("cts ret=%d,timerStatus=%d",ret,timerStatus.status);    
                        }
                       
                        ret = quectel_nv_fat_write(QUEC_GPIO_DEBOUNCE_NVM, g_debounce_param, QUEC_DEBOUNCE_GPIO_NUM*sizeof(quec_gpio_debounce_param_s));
                        if(QUEC_SUCCESS == ret)
                        {
                            cts_debounce.interval_time = g_debounce_param[i].debounce_param.time_out;
                            cts_debounce.interval_count = g_debounce_param[i].debounce_param.count;
                            gpio_log("cts debounce set ok,interval_time=%d,interval_count=%d",cts_debounce.interval_time,cts_debounce.interval_count); 
                        }
                        else
                        {
                            
                            gpio_log("cts debounce write fail,resume timer");
                            g_debounce_param[i].debounce_param.time_out = time_out_tmp;
                            g_debounce_param[i].debounce_param.count = count_tmp;
                        }

                        GPIOEdgeDetectionEnable(UART_CTS_PIN_NUM);
                        
                    break;
#endif
#ifdef QUEC_AIR_PLANE_CTRL_ENABLE                      
                    case AIR_PLAN_DEBOUNCE:
                        
                        gpio_log("set air_plan pin_num=%d",air_plan_debounce.pin_num); 
                        GpioClearEdgeDetection(air_plan_debounce.pin_num); 
                        GPIOEdgeDetectionDisable(air_plan_debounce.pin_num);
                        ret = quec_rtos_timer_get_status(air_plan_debounce.timerRef,&timerStatus);
                        if ((ret == kNoErr)&&(QUEC_TMR_STA_ENABLED == timerStatus.status))
                        {
                            gpio_log("cts stop timer");
                            quec_rtos_timer_stop(air_plan_debounce.timerRef);
                        } 
                        else
                        {
                            gpio_log("cts ret=%d,timerStatus=%d",ret,timerStatus.status);    
                        }

                        ret = quectel_nv_fat_write(QUEC_GPIO_DEBOUNCE_NVM, g_debounce_param, QUEC_DEBOUNCE_GPIO_NUM*sizeof(quec_gpio_debounce_param_s));
                        if(QUEC_SUCCESS == ret)
                        {
                            air_plan_debounce.interval_time = g_debounce_param[i].debounce_param.time_out;
                            air_plan_debounce.interval_count = g_debounce_param[i].debounce_param.count;
                            gpio_log("air_plan debounce set ok,interval_time=%d,interval_count=%d",air_plan_debounce.interval_time,air_plan_debounce.interval_count); 
                        }
                        else
                        {
                            
                            gpio_log("cts debounce write fail,resume timer");
                            g_debounce_param[i].debounce_param.time_out = time_out_tmp;
                            g_debounce_param[i].debounce_param.count = count_tmp;
                        }

                    GPIOEdgeDetectionEnable(air_plan_debounce.pin_num);

                    break;
#endif
#ifdef QUEC_SLEEP_AP_READY
                    case APREADY_DEBOUNCE:
                        CPUartLogPrint("quec_apready_pin_init APREADY_DEBOUNCE ",TRUE);
                        GpioClearEdgeDetection(QUEC_APREADY_DET_PIN);
                        GPIOEdgeDetectionDisable(QUEC_APREADY_DET_PIN);
                        ret = quec_rtos_timer_get_status(apready_debounce.timerRef,&timerStatus);
                        if ((ret == kNoErr)&&(QUEC_TMR_STA_ENABLED == timerStatus.status))
                        {
                            gpio_log("apready stop timer");
                            quec_rtos_timer_stop(apready_debounce.timerRef);
                        } 
                        else
                        {
                            gpio_log("apready ret=%d,timerStatus=%d",ret,timerStatus.status);    
                        }
                        ret = quectel_nv_fat_write(QUEC_GPIO_DEBOUNCE_NVM, g_debounce_param, QUEC_DEBOUNCE_GPIO_NUM*sizeof(quec_gpio_debounce_param_s));
                        if(QUEC_SUCCESS == ret)
                        {
                            apready_debounce.interval_time = g_debounce_param[i].debounce_param.time_out;
                            apready_debounce.interval_count = g_debounce_param[i].debounce_param.count;
                            gpio_log("apready debounce set ok,interval_time=%d,interval_count=%d",apready_debounce.interval_time,apready_debounce.interval_count); 
                        }
                        else
                        {
                            
                            gpio_log("apready debounce write fail,resume timer");
                            g_debounce_param[i].debounce_param.time_out = time_out_tmp;
                            g_debounce_param[i].debounce_param.count = count_tmp;
                        }                      
                        
                        GPIOEdgeDetectionEnable(QUEC_APREADY_DET_PIN);
                    break;
#endif

                    case WAKEUP_IN_DEBOUNCE:
                    
                   GpioClearEdgeDetection(QUEC_WAKEUP_IN_GPIO);
                   GPIOEdgeDetectionDisable(QUEC_WAKEUP_IN_GPIO);
                   ret = quec_rtos_timer_get_status(wakeup_in_debounce.timerRef,&timerStatus);
                   if ((ret == kNoErr)&&(QUEC_TMR_STA_ENABLED == timerStatus.status))
                   {
                       gpio_log("dtr stop timer");
                       quec_rtos_timer_stop(wakeup_in_debounce.timerRef);
                   } 
                   else
                   {
                       gpio_log("dtr ret=%d,timerStatus=%d",ret,timerStatus.status);    
                   }
                   ret = quectel_nv_fat_write(QUEC_GPIO_DEBOUNCE_NVM, g_debounce_param, QUEC_DEBOUNCE_GPIO_NUM*sizeof(quec_gpio_debounce_param_s));
                   if(QUEC_SUCCESS == ret)
                   {
                       dtr_debounce.interval_time = g_debounce_param[i].debounce_param.time_out;
                       dtr_debounce.interval_count = g_debounce_param[i].debounce_param.count;
                       gpio_log("dtr debounce set ok,interval_time=%d,interval_count=%d",dtr_debounce.interval_time,dtr_debounce.interval_count); 
                   }
                   else
                   {
                       
                       gpio_log("dtr debounce write fail,resume timer");
                       g_debounce_param[i].debounce_param.time_out = time_out_tmp;
                       g_debounce_param[i].debounce_param.count = count_tmp;
                   }                      
                   
                   GPIOEdgeDetectionEnable(UART_DTR_PIN_NUM);
               break;

                    default:
                        g_debounce_param[i].debounce_param.time_out = time_out_tmp;
                        g_debounce_param[i].debounce_param.count = count_tmp;
                        gpio_log("set pin_usage=%d is invalid", p_debounce->pin_usage);
                        
                    break;
                }
                break; //Chaim 20190705 break for cycle
            }
        }
    }

    if(QUEC_DEBOUNCE_GPIO_NUM ==  i)
    {
        gpio_log("not found debounce pin usage");
		return ret;       
    }
    return ret;
    
}


QuecOSStatus quec_set_interrupt_log(bool en)
{
    QuecOSStatus ret =kGeneralErr;
    g_inter_log =en;
    gpio_log("set  g_inter_log=%d",g_inter_log);
    return QUEC_SUCCESS;
}

bool quec_get_interrupt_log(void)
{
    return g_inter_log;
}


QuecOSStatus quec_gpio_debounce_init(quec_gpio_debounce_s *pregister_debounce)
{
    QuecOSStatus ret = kGeneralErr;
    unsigned int pin_status =0;
    quec_pin_level_value_e get_level=0;
    uint8 i=0;
    if(NULL ==  pregister_debounce)
	{
		 quec_debug_print_uart("pregister_debounce is null pointer");
		 return ret;
	} 
    if(NULL !=  pregister_debounce->timerRef)
    {
       quec_debug_print_uart("debounce  timerRef is inited");
	   return ret; 
    }

    ret = quec_rtos_timer_create(&pregister_debounce->timerRef);
    if(ret != OS_SUCCESS)
    {
        quec_debug_print_uart("debounce_TimerRef time creat fail");
        return ret;
    }
    //get power on gpio level

    pregister_debounce->last_level =  GpioGetLevel(pregister_debounce->pin_num);

    return QUEC_SUCCESS;
    
}

QuecOSStatus quec_gpio_interrupt_debounce_handler(quec_gpio_debounce_s *pregister_debounce)
{
    QuecOSStatus ret = kGeneralErr;
    quec_timer_status_t timerStatus ={0}; 
    bool cycle = FALSE;

    if(NULL == pregister_debounce)
    {
       gpio_log("pregister_debounce is null pointer");
	   return ret; 
    }
    interrupt_log("start debounce,pin=%d",pregister_debounce->pin_num);

	/*****use for debounce has no effect******/
	if((NULL==pregister_debounce->interval_count)||(NULL==pregister_debounce->interval_time))
	{
		interrupt_log("hisr is trigger with no debounce");
		pregister_debounce->callBackTimerHandler();
		return QUEC_SUCCESS;
	}
	
    ret = quec_rtos_timer_get_status(pregister_debounce->timerRef,&timerStatus);
    if (ret != kNoErr)
    {
        gpio_log("timer get status fail ret =%d",ret);
        return ret;
    } 
    if(QUEC_TMR_STA_ENABLED == timerStatus.status)  //Chaim 2019.06.03,if timer enable need disabled first
    {
        gpio_log("debounce timer start,return");
        return ret;
       // quec_rtos_timer_stop(pregister_debounce->timerRef); 
    }
    
    pregister_debounce->interrupt_happen_count = 0;   
    if(pregister_debounce->interval_count)
    {
        cycle= TRUE;
    }
	ret = quec_rtos_timer_start(pregister_debounce->timerRef, pregister_debounce->interval_time, cycle, pregister_debounce->callBackTimerHandler, 0);
    if (ret != kNoErr)
    {
        gpio_log("debounce time start fail");
        return ret;
    }
    interrupt_log("time=%d",pregister_debounce->interval_time);
    return QUEC_SUCCESS;
}

QuecOSStatus quec_gpio_debounce_timer_handler(quec_gpio_debounce_s *pregister_debounce)
{
    QuecOSStatus ret = kGeneralErr; 
     bool cycle = FALSE;
    if(NULL == pregister_debounce)
    {
       gpio_log("pregister_debounce is null pointer");
	   return ret; 
    }

	/*****use for debounce has no effect******/
	if((NULL==pregister_debounce->interval_count)||(NULL==pregister_debounce->interval_time))
	{
		pregister_debounce->interrupt_level = GpioGetLevel(pregister_debounce->pin_num);
		pregister_debounce->last_level = pregister_debounce->interrupt_level;
		GpioClearEdgeDetection(pregister_debounce->pin_num); 
    	GPIOEdgeDetectionEnable(pregister_debounce->pin_num); 
		interrupt_log("first origin_level=%d,interrupt_level=%d",
        pregister_debounce->last_level,
        pregister_debounce->interrupt_level);
		return QUEC_SUCCESS;
	}
	
    //Chaim 20190707 get level may same with interrupt before,in this case need check continue,because it may change any time
    if(0 == pregister_debounce->interrupt_happen_count)
    {
        pregister_debounce->interrupt_happen_count++;
        pregister_debounce->interrupt_level = GpioGetLevel(pregister_debounce->pin_num);
        interrupt_log("first origin_level=%d,interrupt_level=%d",
        pregister_debounce->last_level,
        pregister_debounce->interrupt_level);
        return kInProgressErr;
    }
   //Chaim 20190707 when interrutp level is not same with before,need restart
   if(pregister_debounce->interrupt_level != GpioGetLevel(pregister_debounce->pin_num)) 
   {
        gpio_log("INT level=%d,first INT level=%d", GpioGetLevel(pregister_debounce->pin_num),pregister_debounce->interrupt_level);
      
        quec_rtos_timer_stop(pregister_debounce->timerRef);
        pregister_debounce->interrupt_happen_count =0;
        if(pregister_debounce->interval_count)
        {
            cycle= TRUE;
        }
        //restart timer to check 
    	ret = quec_rtos_timer_start(pregister_debounce->timerRef, pregister_debounce->interval_time, cycle, pregister_debounce->callBackTimerHandler, 0);
        if (ret != kNoErr)
        {
            GpioClearEdgeDetection(pregister_debounce->pin_num); 
            GPIOEdgeDetectionEnable(pregister_debounce->pin_num); //enable for next interrupt
            gpio_log("debounce time start fail");
        }
        else
        {
            pregister_debounce->interrupt_happen_count = 0;  
            interrupt_log("restart interrupt timer");
        }
        return kInProgressErr;   
   }
   
    
    pregister_debounce->interrupt_happen_count++;
    interrupt_log("debounce_count=%d,origin_level=%d,interrupt_level=%d",
    pregister_debounce->interrupt_happen_count,
    pregister_debounce->last_level,
    pregister_debounce->interrupt_level);
    
    if(pregister_debounce->interrupt_happen_count >= pregister_debounce->interval_count)
    {
        quec_rtos_timer_stop(pregister_debounce->timerRef);
        pregister_debounce->interrupt_happen_count =0;
        if(pregister_debounce->last_level == pregister_debounce->interrupt_level)
        {
            gpio_log("gpio get level=%d is same",pregister_debounce->interrupt_level);  
            GpioClearEdgeDetection(pregister_debounce->pin_num); 
            GPIOEdgeDetectionEnable(pregister_debounce->pin_num); //Chaim 20190705 gpio interrupt enable
            return kInProgressErr;
        }
        pregister_debounce->last_level = pregister_debounce->interrupt_level;
        interrupt_log("update last_level=%d",pregister_debounce->last_level);
    } 
    else
    {
        return kInProgressErr;
    }
    GpioClearEdgeDetection(pregister_debounce->pin_num); 
    GPIOEdgeDetectionEnable(pregister_debounce->pin_num); //Chaim 20190705 gpio interrupt enable
    return QUEC_SUCCESS;   
}


//jensen.fang 20181102: to read mfpr register of gpio
QuecOSStatus quec_gpio_get_mfprReg(GPIO_PinNumbers pin_num, unsigned long *p_mfprReg_data)
{
	if (pin_num > GPIO_MAX_AMOUNT_OF_PINS)
	{
		gpio_log("pin_num=%d error", pin_num);
		return kParamErr;
	}
	if (NULL == p_mfprReg_data)
	{
		gpio_log("p_mfprReg_data is null");
		return kParamErr;
	}
	*p_mfprReg_data = *((volatile unsigned long *)(GPIO_MFPR_ADDR(pin_num)));
	return QUEC_SUCCESS;
}

QuecOSStatus quec_gpio_get_GPIOReg(GPIO_PinNumbers pin_num, GPIORegisters * gpioRegister)
{
	if (pin_num > GPIO_MAX_AMOUNT_OF_PINS)
	{
		gpio_log("pin_num=%d error", pin_num);
		return kParamErr;
	}
	if (NULL == gpioRegister)
	{
		gpio_log("gpioRegister is null");
		return kParamErr;
	}

	gpioRegister = (GPIORegisters *)GetGPIORegisterAddr(pin_num);
	return QUEC_SUCCESS;
}

//init single gpio pin,if init before,return direct
QuecOSStatus quec_gpio_init(quec_pin_config_s *pin_config)
{

	// Chaim compiled shield
    GPIO_ReturnCode        status = GPIORC_OK;
    GPIO_PinNumbers        pinNumber = GPIO_PIN_NOT_ASSIGNED;
    if(pin_config == NULL)
    {
        gpio_log("pin_config is a null pointer");
        return kParamErr;
    }

	//1、需要先config，
    pinNumber=pin_config->config.pinNumber;
    
    status = GPIOConfigure(&pin_config->config);
    if(GPIORC_OK != status)
    {
        quec_debug_print_uart("gpio_num=%d,gpio configure fail", pinNumber);
        return kGeneralErr;
    }
	
	//2、在设置复用功能寄存器
    status = quec_set_gpio_mfprReg(pinNumber, pin_config->mfprReg_data);
    if(status != QUEC_SUCCESS)
    {
        quec_debug_print_uart("gpio_num=%d,gpio set mfpreg fail", pinNumber);
        return status;
    }

    return QUEC_SUCCESS;
}
void quec_ri_pin_init(void)
{
	quec_pin_config_s gpio_init_structure={0};
	gpio_init_structure.config.pinNumber = UART1_RI_PIN_NUM;
	gpio_init_structure.config.direction = GPIO_OUT_PIN;
	gpio_init_structure.config.initialValue = GPIO_INITIAL_VALUE_HIGH;
	gpio_init_structure.config.pullUpDown = GPIO_PULLUP_ENABLE;
	gpio_init_structure.mfprReg_data = UART1_RI_PIN_NUM_AF |QUEC_PULL_UP_C |QUEC_DRV_FAST_C |QUEC_RESERVED_C;
	gpio_init_structure.GPIOCallback = NULL;
	quec_gpio_init(&gpio_init_structure);
}

 //set gpio level
 QuecOSStatus quec_set_gpio_level(GPIO_PinNumbers pin_num, quec_pin_level_value_e pin_level)
 {
 	if(pin_num < GPIO_MAX_AMOUNT_OF_PINS)
 	{
		 GPIO_ReturnCode status = GPIORC_OK;
		 status = GpioSetLevel(pin_num, pin_level);
		 if(status != GPIORC_OK)
		 {
			 gpio_log("port handle invalid or pin_num=%d m pin_level=%d, error=%d", pin_num, pin_level, status);
			 return kParamErr;
		 }
		 return QUEC_SUCCESS;
 	}
	else{
		return kGeneralErr;
	}
	
 }

 //get gpio level
 QuecOSStatus quec_get_gpio_level(GPIO_PinNumbers pin_num, quec_pin_level_value_e *p_level)
 {
 	GPIO_ReturnCode  status = GPIORC_OK;
     
	if(NULL== p_level)
	{
		 gpio_log("p_level is null pointer");
		 return kParamErr;
	}

	status = GpioGetLevel(pin_num);
	if(status < 0)
	{
		 gpio_log("GpioGetLevel fail");
		 return kGeneralErr;
	}
	*p_level = status;
	return QUEC_SUCCESS;
 }


//jensen.fang 20181103: to init STATUS gpio to indicate power state
QuecOSStatus quec_gpio_power_status_init(void)
{
	//Fitz.xu 20210415: do not output HIGH before RDY.
#ifndef __QUEC_OEM_VER_LT__
	if (QUEC_SUCCESS != quec_set_gpio_level(QUEC_POWER_STATUS_PIN, QUEC_PIN_LEVEL_HIGH))
	{
		gpio_log("error: set STATUS gpio to high level failed!");
		return kGeneralErr;
	}
#endif 

    return kNoErr;
}

//jensen.fang 20181103: to init custom gpio
QuecOSStatus quec_gpio_cust_init(void)
{
	QuecOSStatus err = kNoErr;
	err = quec_gpio_cust_config();
	require_noerr_string(err, exit, "quec_gpio_cust_config error");
	err = quec_gpio_power_status_init();
	require_noerr_string(err, exit, "quec_gpio_power_status_init error");

//Fitz.xu 20210819: add for india allied led_mode, FAE-20035
#if defined(__QUEC_OEM_VER_ALLIED__) && defined(EC200S_LCC05_NET_MODE_GPIO)
	quec_set_gpio_level(EC200S_LCC05_NET_MODE_GPIO, QUEC_PIN_LEVEL_HIGH);
#endif
#if defined(__QUEC_OEM_VER_WUS__)
    quec_wus_gpio_init();
#endif

exit:
	return err;
}

#ifdef __QUECTEL_PROJECT_EC800MCN_LE__

unsigned long  pa_mfpr=  0x148040 ;
GPIO_PinConfiguration  pa_config ={GPIO_PIN_37,GPIO_IN_PIN,GPIO_NO_EDGE,GPIO_DEBOUNCE_ENABLE,GPIO_PULLDN_ENABLE,GPIO_INITIAL_VALUE_NO_CHANGE};


int quec_pa_level_check(void)
{
	QuecOSStatus ret =kGeneralErr;
	quec_pin_level_value_e pa_gpio_level = 0;
	quec_pin_config_s pa_gpio_config = {pa_config,pa_mfpr,NULL};

	ret = quec_gpio_init(&pa_gpio_config);
	ret = quec_get_gpio_level(GPIO_PIN_37,&pa_gpio_level);
	RTI_LOG("pa gpio ret=%d,level=%d\r\n",ret,pa_gpio_level);

	return pa_gpio_level;
}
#endif

#ifdef QUEC_MULTI_PA_SUPPORT



#define QUEC_PA_GPIO1_PIN    GPIO_PIN_69
#define QUEC_PA_GPIO2_PIN    GPIO_PIN_70

GPIO_PinConfiguration  PA_gpio1_config ={QUEC_PA_GPIO1_PIN,GPIO_IN_PIN,GPIO_NO_EDGE,GPIO_DEBOUNCE_ENABLE,GPIO_PULLDN_ENABLE,GPIO_INITIAL_VALUE_NO_CHANGE};
unsigned long  PA_gpio1_mfpr=(QUEC_AF0_C | QUEC_PULL_DN_C | QUEC_DRV_SLOW_C |QUEC_RESERVED_C) ;

GPIO_PinConfiguration  PA_gpio2_config ={QUEC_PA_GPIO2_PIN,GPIO_IN_PIN,GPIO_NO_EDGE,GPIO_DEBOUNCE_ENABLE,GPIO_PULLDN_ENABLE,GPIO_INITIAL_VALUE_NO_CHANGE};
unsigned long  PA_gpio2_mfpr=(QUEC_AF0_C | QUEC_PULL_DN_C | QUEC_DRV_SLOW_C |QUEC_RESERVED_C) ;



QUEC_RF_INDEX_E quec_pa_identify_gpio_init(void)
{
     QuecOSStatus ret =kGeneralErr;
     quec_pin_level_value_e gpio1_level=0;
     quec_pin_level_value_e gpio2_level=0;
     quec_pin_config_s  gpio1_config ={PA_gpio1_config, PA_gpio1_mfpr, NULL};
      quec_pin_config_s  gpio2_config ={PA_gpio2_config, PA_gpio2_mfpr, NULL};
     ret = quec_gpio_init(&gpio1_config);
     gpio_log("ret1=%d",ret);
     ret = quec_gpio_init(&gpio2_config);
      gpio_log("ret2=%d",ret);
        
     ret = quec_get_gpio_level(QUEC_PA_GPIO1_PIN,&gpio1_level);
     gpio_log("ret2=%d,69_level=%d",ret,gpio1_level);
     
     ret = quec_get_gpio_level(QUEC_PA_GPIO2_PIN,&gpio2_level);
     gpio_log("ret2=%d,70_level=%d",ret,gpio2_level);

     if(((QUEC_PIN_LEVEL_LOW== gpio1_level)&&(QUEC_PIN_LEVEL_LOW == gpio2_level))||
        ((QUEC_PIN_LEVEL_HIGH== gpio1_level)&&(QUEC_PIN_LEVEL_LOW == gpio2_level)))
     {
             return RF_INDEX_2;
     }
     return RF_INDEX_1;
}

#endif

#if (QUEC_USIM_PRESENCE_INTERRUPT_ENABLE ==1)
QuecOSStatus quec_usim_presence_level_process(quec_pin_level_value_e level)
{
    QuecOSStatus ret = QUEC_SUCCESS;

    switch(level)
    {
        case QUEC_PIN_LEVEL_LOW:   
        case QUEC_PIN_LEVEL_HIGH:
            quec_sim_hot_plug_handle(level);
        break;
        
#ifndef QUEC_ASR_SIM_ENBALE     //Chaim 20190831  use interrupt level,not use get pin level,avoid joggle
        case QUEC_PIN_LEVEL_LOW:   //insert sim card
            gpio_log("usim low level=%d", level);      
            #ifdef QUEC_ASR_SIM_ENBALE /*Tery.shi 2018/12/18 <SIM> add sim card insert handle*/
			    quec_sim_hot_plug_handle();
            #endif
        break;

        case QUEC_PIN_LEVEL_HIGH:   //pull out sim
            gpio_log("usim highlevel=%d", level);  
            #ifdef QUEC_ASR_SIM_ENBALE /*Tery.shi 2018/12/18 <SIM> add sim card remove handle*/
			    quec_sim_hot_plug_handle();
            #endif
        break;
#endif  
        default:
            gpio_log("level=%d is invalid",level);
            ret = kGeneralErr;
        break;
    }

    return ret;

}

void quec_usim_debounce_timer_handler(void)
{
    QuecOSStatus ret = kGeneralErr;
  //  unsigned int pin_status;
   // quec_pin_level_value_e level = QUEC_PIN_LEVEL_HIGH;
    ret = quec_gpio_debounce_timer_handler(&usim_debounce);
    if(QUEC_SUCCESS == ret)
    {
		quec_send_msg_to_handle_task(QUEC_USIM_PRESENCE_MSG,&usim_debounce.last_level,sizeof(usim_debounce.last_level));
        if(TRUE == g_usim_wakeup_flag)
        {
            quec_sleep_not_allown_sleep();  //Chaim 20190820 for msg tranfer long time ,cp will sleep possibility
            quec_sleep_active_sleep_task(QUEC_SLEEP_USIM_ACTIVE);
        }
     /*   ret = quec_send_msg_to_modem_router(QUEC_USIM_PRESENCE_MSG, &usim_debounce.last_level, sizeof(usim_debounce.last_level));
        if(ret != QUEC_SUCCESS)
        {
            gpio_log("quec_send_msg_to_modem_router fail level=%d", usim_debounce.last_level);
        } */
        
        
    }
    
    return;
}

void quec_usim_presence_hisr(void)
{
    //quec_debug_print_uart("usim hisr");
    //GpioClearEdgeDetection(LGA_42_USIM_PRESENCE_DEFAULT_GPIO); 
    //interrupt_log("usim hisr");
    quec_gpio_interrupt_debounce_handler(&usim_debounce);
}

void usim_presence_GPIOCallback(void)
{
        GPIOEdgeDetectionDisable(QUEC_USIM_DET_PIN);
        if(usim_presencehisr != NULL)
        {
            OS_Activate_HISR(&usim_presencehisr); 
        }
}
QuecOSStatus quec_usim_presence_interrupt_pin_init(void)
{
    QuecOSStatus ret = kGeneralErr;

	
    unsigned char read_buf[2] = {0};
    unsigned char insert_level = 0;

    GPIO_PinConfiguration usim_config ={
         .pinNumber = QUEC_USIM_DET_PIN,          
         .direction = GPIO_IN_PIN,           
         .transitionType = GPIO_TWO_EDGE,      
         .debounce = GPIO_DEBOUNCE_ENABLE,      
         .pullUpDown = GPIO_PULLUP_ENABLE,     
         .initialValue = GPIO_INITIAL_VALUE_NO_CHANGE 
    };

    quec_read_usim_presence_sclk_cfg();   //read usim presence sclk cfg
    
    if(quectel_nv_fat_read(__QUEC_AT_QSIMSTAT_VALUE, &g_usim_det_stat.sim_report_enable, sizeof(UINT8))!=QUEC_FAT_SUCCESS)
	{
	    gpio_log("simstat value init error");
	}
    if(QUEC_FAT_SUCCESS == quectel_nv_fat_read(__QUEC_AT_QSIMDET_VALUE, read_buf, sizeof(read_buf)))
	{
        /* Read insert level setting from NV */
        insert_level = read_buf[1];	
        g_usim_det_stat.sim_det_enable = read_buf[0];
        g_usim_det_stat.sim_insert_level = insert_level;
	}
    else
	{
        /* Use defalut detect level */
        insert_level = 0;
        g_usim_det_stat.sim_det_enable = read_buf[0];
        g_usim_det_stat.sim_insert_level = insert_level;
    }


    if (insert_level == 0)
    {
        if(quec_get_usim_presence_sclk_cfg())
        {
            ret = quec_set_gpio_mfprReg(QUEC_USIM_DET_PIN, QUEC_AF0_C|QUEC_PULL_UP_C|QUEC_DRV_SLOW_C|(1 << 4)|(1 << 5) |QUEC_RESERVED_C);             
        }
        else
        {
            ret = quec_set_gpio_mfprReg(QUEC_USIM_DET_PIN, QUEC_AF0_C|QUEC_PULL_UP_C|QUEC_DRV_SLOW_C|QUEC_RESERVED_C);
               
        }
        //ret = quec_set_gpio_mfprReg(LGA_42_USIM_PRESENCE_DEFAULT_GPIO, QUEC_AF0_C|QUEC_PULL_UP_C|QUEC_DRV_SLOW_C|(1 << 4)|(1 << 5) |QUEC_RESERVED_C);
    }
    else if (insert_level == 1)
    {
        /* Use pull none instead of pull down */
        if(quec_get_usim_presence_sclk_cfg())
        {
            ret = quec_set_gpio_mfprReg(QUEC_USIM_DET_PIN, QUEC_AF0_C|QUEC_DRV_SLOW_C|(1 << 4)|(1 << 5) |QUEC_RESERVED_C);
        }
        else
        {
            ret = quec_set_gpio_mfprReg(QUEC_USIM_DET_PIN, QUEC_AF0_C|QUEC_DRV_SLOW_C|QUEC_RESERVED_C);
               
        }
        //ret = quec_set_gpio_mfprReg(LGA_42_USIM_PRESENCE_DEFAULT_GPIO, QUEC_AF0_C|QUEC_DRV_SLOW_C|(1 << 4)|(1 << 5) |QUEC_RESERVED_C);
        usim_config.pullUpDown = GPIO_PULL_DISABLE;
        usim_config.initialValue = GPIO_INITIAL_VALUE_LOW;
    }
    
    if(ret != QUEC_SUCCESS)
    {
       quec_debug_print_uart("gpio_num=%d,gpio set mfpreg fail", QUEC_USIM_DET_PIN);
       return ret;
    }

    ret = GPIOConfigure_Ex( &usim_config,   usim_presence_GPIOCallback, NULL );
    if(GPIORC_OK != ret)
    {
     quec_debug_print_uart("gpio_num=%d,gpio configure fail", usim_config.pinNumber);
     return kGeneralErr;
    }

    OS_Create_HISR(&usim_presencehisr,"usim", quec_usim_presence_hisr,HISR_PRIORITY_2);
    GpioClearEdgeDetection(usim_config.pinNumber);
    quec_gpio_debounce_init(&usim_debounce);
    GpioEnableEdgeDetection(usim_config.pinNumber, usim_config.transitionType);

    return QUEC_SUCCESS;  //use our owen return value
}

QuecOSStatus quec_get_usim_level(quec_pin_level_value_e *p_level)
{
    QuecOSStatus ret = kGeneralErr;
    
    ret = quec_get_gpio_level(QUEC_USIM_DET_PIN, p_level);
    if(ret != QUEC_SUCCESS)
    {
        gpio_log("pin_num=%d,get pin_level fail",QUEC_USIM_DET_PIN);
        return ret;
    }

    return QUEC_SUCCESS;
}

QuecOSStatus quec_usim_plug_handle(quec_msg_process_s *pmsg_set)
{
	QuecOSStatus ret = kGeneralErr;
	quec_pin_level_value_e getlevel = QUEC_PIN_LEVEL_LOW;

	if((pmsg_set == NULL) ||(NULL == pmsg_set->pdata)|| (pmsg_set->data_len != sizeof(quec_pin_level_value_e)))
	{
		gpio_log("pdata=%p,pmsg_set->pdata=%p,data_len=%d",pmsg_set,pmsg_set->pdata,pmsg_set->data_len);
		return kGeneralErr;	
	}

	getlevel = *(quec_pin_level_value_e *)pmsg_set->pdata;

	gpio_log("quec_usim,level=%d",getlevel);
	if(g_usim_interrupt_state.usim_int_first)
	{
		gpio_log("first quec_usim int,level=%d",getlevel);
		quec_usim_presence_level_process(getlevel);
		g_usim_interrupt_state.usim_int_first = FALSE;
		g_usim_interrupt_state.last_level = getlevel;
	}
	else
	{
		if(g_usim_interrupt_state.last_level == getlevel)	 
		{
			gpio_log("quec_usim interrupt level is same with last level=%d",getlevel);	
		}
		else
		{
			quec_usim_presence_level_process(getlevel); 
			g_usim_interrupt_state.last_level = getlevel;
		}
	}

	return QUEC_SUCCESS;
}

#endif


#ifdef QUEC_AIR_PLANE_CTRL_ENABLE
QuecOSStatus quec_set_airplane_level(quec_pin_level_value_e pin_level)
{
    if(pin_level!=QUEC_PIN_LEVEL_LOW && pin_level!=QUEC_PIN_LEVEL_HIGH)\
    return kGeneralErr;
    airplane_pin_level=pin_level;
    return QUEC_SUCCESS;   
}
QuecOSStatus quec_air_plane_pin_process(quec_msg_process_s *pmsg_set)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    quec_pin_level_value_e level = QUEC_PIN_LEVEL_HIGH;

    if((pmsg_set == NULL) ||(NULL == pmsg_set->pdata)|| (pmsg_set->data_len != sizeof(quec_pin_level_value_e)))
    {
        gpio_log("pdata=%p,pmsg_set->pdata=%p,data_len=%d",pmsg_set,pmsg_set->pdata,pmsg_set->data_len);
        return kGeneralErr;
    }
    
    level = *(quec_pin_level_value_e *)pmsg_set->pdata;

    if (airplane_pin_level != level)
    {
        airplane_pin_level = level;
        
        gpio_log("L: enter airplane mode, H:exit airplane mode, level=%d, ", level);
        quec_airplane_report(level);
    }
    else 
    {
        return ret;
    }
    
    return ret;
}


QuecOSStatus quec_air_plane_pin_level_get(quec_pin_level_value_e *p_level)
{
    QuecOSStatus ret = kGeneralErr;

    ret = quec_get_gpio_level(QUEC_AIR_PLAN_CTRL_PIN, p_level);
    if(ret != QUEC_SUCCESS)
    {
        gpio_log("pin_num=%d,get pin_level fail", QUEC_AIR_PLAN_CTRL_PIN);
        return ret;
    }

    return QUEC_SUCCESS;
}



void quec_air_plan_debounce_timer_handler(void)
{
    QuecOSStatus ret = kGeneralErr;

    ret = quec_gpio_debounce_timer_handler(&air_plan_debounce);
    if(QUEC_SUCCESS == ret)
    {
		ret = quec_send_msg_to_handle_task(QUEC_AIR_PLANE_CTRL_MSG, &air_plan_debounce.last_level, sizeof(air_plan_debounce.last_level));
		if(ret != QUEC_SUCCESS)
        {
            gpio_log("quec_send_msg_to_handle_task fail level=%d", air_plan_debounce.last_level);
        }      
    }

    return;
}

static void quec_air_plane_pin_hisr(void)
{

    //GpioClearEdgeDetection(air_plan_debounce.pin_num); 
    //GPIOEdgeDetectionDisable(air_plan_debounce.pin_num);
    interrupt_log("air_plan hisr");
    quec_gpio_interrupt_debounce_handler(&air_plan_debounce);
        
    return;
}

void quec_air_plane_GPIOCallback(void)
{
        GPIOEdgeDetectionDisable(QUEC_AIR_PLAN_CTRL_PIN);
        if(air_plane_pin_hisr != NULL)
        {
            OS_Activate_HISR(&air_plane_pin_hisr); 
        }
}
BOOL quec_get_air_plane_enable(void)
{
    QuecOSStatus ret = kGeneralErr;
    ST_quecCfgCustFeatureParams ST_CustFeatureParams = {0};
    ret = Quec_SysItemPara_Item_get(QUEC_CUST_FEATURE_CFG, &ST_CustFeatureParams, sizeof(ST_quecCfgCustFeatureParams));
    if(ret != QUEC_SUCCESS)
    {
        return FALSE;
    }
    if(ST_CustFeatureParams.airPlanePinEnable==1)
    return TRUE;
    else
    return FALSE;
}
QuecOSStatus quec_air_plane_pin_init(void)
{
    QuecOSStatus ret = kGeneralErr;
    ST_quecCfgCustFeatureParams ST_CustFeatureParams = {0};
    GPIO_PinConfiguration air_plane_pin_cfg =
    {
        .pinNumber = QUEC_AIR_PLAN_CTRL_PIN,          
        .direction = GPIO_IN_PIN,           
        .transitionType = GPIO_TWO_EDGE,      
        .debounce = GPIO_DEBOUNCE_ENABLE,      
        .pullUpDown = GPIO_PULLUP_ENABLE,
        .initialValue = GPIO_INITIAL_VALUE_NO_CHANGE 
    };
	
    //quec_read_air_plan_control_value(); //Chaim 20191011 read air plan control value,if not exist,is default 0
    air_plan_debounce.pin_num = QUEC_AIR_PLAN_CTRL_PIN;
    ret = Quec_SysItemPara_Item_get(QUEC_CUST_FEATURE_CFG, &ST_CustFeatureParams, sizeof(ST_quecCfgCustFeatureParams));
    if(ret != QUEC_SUCCESS)
    {
        return ret;
    }
    if(ST_CustFeatureParams.airPlanePinEnable==0)
    return QUEC_SUCCESS;
    ret=quec_set_gpio_mfprReg(air_plane_pin_cfg.pinNumber, QUEC_AIR_PLAN_CTRL_PIN_AF|QUEC_PULL_UP_C|QUEC_DRV_SLOW_C|QUEC_EDGE_FALL_EN|QUEC_RESERVED_C);
    if(ret != QUEC_SUCCESS)
    {
        gpio_log("gpio_num=%d,gpio set mfpreg fail", air_plane_pin_cfg.pinNumber);
        return ret;
    }
    ret = GPIOConfigure_Ex(&air_plane_pin_cfg, quec_air_plane_GPIOCallback , NULL);
    if(ret != QUEC_SUCCESS)
    {
        gpio_log("gpio_num=%d,gpio GPIOConfigure_Ex fail, ret=%d", air_plane_pin_cfg.pinNumber,ret);
        return ret;
    }	
    if(air_plane_pin_hisr==NULL)
    OS_Create_HISR(&air_plane_pin_hisr, "air_plane", quec_air_plane_pin_hisr, HISR_PRIORITY_2);
    GpioClearEdgeDetection(air_plane_pin_cfg.pinNumber);
    if(air_plan_debounce.timerRef==NULL)
    quec_gpio_debounce_init(&air_plan_debounce);
    GpioEnableEdgeDetection(air_plane_pin_cfg.pinNumber, air_plane_pin_cfg.transitionType);

    return QUEC_SUCCESS;
}

QuecOSStatus quec_air_plane_pin_deinit(void)
{
    if(air_plane_pin_hisr!=NULL)
    {
        GpioClearEdgeDetection(QUEC_AIR_PLAN_CTRL_PIN);
        GpioDisableEdgeDetection(QUEC_AIR_PLAN_CTRL_PIN, GPIO_TWO_EDGE);
        GpioClearEdgeDetection_wakeup(QUEC_AIR_PLAN_CTRL_PIN);
        GpioDisableEdgeDetection_wakeup(QUEC_AIR_PLAN_CTRL_PIN, GPIO_TWO_EDGE);
        Os_Delete_HISR(&air_plane_pin_hisr);
        air_plane_pin_hisr=NULL;
    }
   return QUEC_SUCCESS;
}
#endif

#ifdef QUEC_CUSTOM_LAST_GASP_FEATURE
#define QUEC_LAST_GASP_DEBOUNCING_MASK
extern int quec_gasp_task_init(void);
extern int quec_gasp_get_state_mode(int *timer);
QuecOSStatus quec_last_gasp_pin_process(quec_pin_level_value_e *plevel)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    quec_pin_level_value_e level = QUEC_PIN_LEVEL_HIGH;

    if(plevel ==  NULL)
    {
        gpio_log("last_gasp: plevel is null");
        return kGeneralErr;
    }

    level = *plevel;

    if (lgasp_pin_level != level)
    {
        lgasp_pin_level = level; 
        
        gpio_log("L: enter last_gasp mode, level=%d, ", level);   
        quec_gasp_task_init();
    }
    else 
    {
        return ret;
    }
    
    return ret;
}

QuecOSStatus quec_last_gasp_pin_level_get(quec_pin_level_value_e *p_level)
{
    QuecOSStatus ret = kGeneralErr;

    ret = quec_get_gpio_level(QUEC_LAST_GASP_TRIGGER_GPIO, p_level);
    if(ret != QUEC_SUCCESS)
    {
        gpio_log("pin_num=%d,get pin_level fail", QUEC_LAST_GASP_TRIGGER_GPIO);
        return ret;
    }

    return QUEC_SUCCESS;
}



void quec_last_gasp_debounce_timer_handler(void)
{
    QuecOSStatus ret = kGeneralErr;

    ret = quec_gpio_debounce_timer_handler(&last_gasp_debounce);
    if(QUEC_SUCCESS == ret)
    {
		ret = quec_send_msg_to_handle_task(QUEC_LAST_GASP_TIRGGER_MSG, &last_gasp_debounce.last_level, sizeof(last_gasp_debounce.last_level));
		if(ret != QUEC_SUCCESS)
        {
            gpio_log("quec_send_msg_to_handle_task fail level=%d", last_gasp_debounce.last_level);
        }      
    }

    return;
}

static void quec_last_gasp_pin_hisr(void)
{
	if(0 == quec_gasp_get_state_mode(&last_gasp_debounce.interval_time))
		return;
	
    interrupt_log("gasp hisr");
#ifdef QUEC_LAST_GASP_DEBOUNCING_MASK	
	if(last_gasp_debounce.interval_time != 0){
	   quec_gpio_interrupt_debounce_handler(&last_gasp_debounce);
	}
	else
#endif
	{
		quec_gasp_task_init();
	}

    return;
}

void quec_last_gasp_GPIOCallback(void)
{
        GPIOEdgeDetectionDisable(QUEC_LAST_GASP_TRIGGER_GPIO);
        if(last_gasp_pin_hisr != NULL)
        {
            OS_Activate_HISR(&last_gasp_pin_hisr); 
        }
}
QuecOSStatus quec_last_gasp_pin_init(void)
{
    QuecOSStatus ret = kGeneralErr;
    GPIO_PinConfiguration last_gasp_pin_cfg =
    {
        .pinNumber = QUEC_LAST_GASP_TRIGGER_GPIO,          
        .direction = GPIO_IN_PIN,           
        .transitionType = GPIO_FALL_EDGE,      
        .debounce = GPIO_DEBOUNCE_ENABLE,      
        .pullUpDown = GPIO_PULLUP_ENABLE,
        .initialValue = GPIO_INITIAL_VALUE_NO_CHANGE 
    };
	
    last_gasp_debounce.pin_num = QUEC_LAST_GASP_TRIGGER_GPIO;

    ret=quec_set_gpio_mfprReg(last_gasp_pin_cfg.pinNumber, QUEC_AF0_C|QUEC_PULL_UP_C|QUEC_DRV_SLOW_C|QUEC_EDGE_FALL_EN|QUEC_RESERVED_C);
    if(ret != QUEC_SUCCESS)
    {
        gpio_log("gpio_num=%d,gpio set mfpreg fail", last_gasp_pin_cfg.pinNumber);
        return ret;
    }
    ret = GPIOConfigure_Ex(&last_gasp_pin_cfg, quec_last_gasp_GPIOCallback , NULL);
    if(ret != QUEC_SUCCESS)
    {
        gpio_log("gpio_num=%d,gpio GPIOConfigure_Ex fail, ret=%d", last_gasp_pin_cfg.pinNumber,ret);
        return ret;
    }	

    OS_Create_HISR(&last_gasp_pin_hisr, "last_gasp", quec_last_gasp_pin_hisr, HISR_PRIORITY_2);
    GpioClearEdgeDetection(last_gasp_pin_cfg.pinNumber);
    quec_gpio_debounce_init(&last_gasp_debounce);
    GpioEnableEdgeDetection(last_gasp_pin_cfg.pinNumber, last_gasp_pin_cfg.transitionType);

    return QUEC_SUCCESS;
}
#endif

#ifdef QUEC_SLEEP_AP_READY
#define QUEC_APREADY_FLAG_FILE   "apready_flag"

extern urc_context_t urc_context;
extern quec_apready_cfg_t apready_cfg;

extern void quec_sio_flowctl_set_send_status(TelAtParserID atpIndex, bool enable);

QuecOSStatus quec_set_apready_enable_flag(UINT8          flag)
{
    QuecOSStatus status = QUEC_SUCCESS;
    UINT8 get_flag = 0;
    UINT8 set_flag = flag;

    if(set_flag > APREADY_LEVEL_HIGH_ACTION)
    {
        gpio_log("quec_set_apready_enable_flag set_type=%d invalid", set_flag);
        return kGeneralErr;
    }

    status = quectel_nv_fat_read(QUEC_APREADY_FLAG_FILE, &get_flag,sizeof(get_flag));
    if(status != QUEC_SUCCESS)
    {
        gpio_log("usb net read fail, default type=%d", get_flag);
    }

	if(set_flag == get_flag)
    {
        gpio_log("not need set,flag=%d", set_flag);
        return QUEC_SUCCESS;
    }
    status = quectel_nv_fat_write(QUEC_APREADY_FLAG_FILE, &set_flag, sizeof(set_flag));
    if(QUEC_FAT_SUCCESS != status)
    {
        gpio_log("net_type=%d write fail",set_flag);
		status = kGeneralErr;
    }

    return status;
}


QuecOSStatus quec_get_apready_enable_flag(UINT8 *flag)
{
    QuecOSStatus status = QUEC_SUCCESS;
    UINT8 get_flag = 0;
    
    if(flag == NULL)
    {
        gpio_log("flag is a null pointer");
        return kGeneralErr;
    }
    
    status = quectel_nv_fat_read(QUEC_APREADY_FLAG_FILE, &get_flag,sizeof(get_flag));
    if(status != QUEC_SUCCESS)
    {
        gpio_log("apready flag read fail");
    }
    else
    {
        *flag = get_flag;
    }
    
    return status;
}


void quec_apready_debounce_timer_handler(UINT32 val)
{

    QuecOSStatus ret = kGeneralErr;

    ret = quec_gpio_debounce_timer_handler(&apready_debounce);
    if(QUEC_SUCCESS == ret)
    {
        gpio_log("%s:%d, last_level=%d, action_level=%d, atpIndex=%d", __FUNCTION__,__LINE__,apready_debounce.last_level, apready_cfg.apready_action_level, urc_context.config.atpIndex);
        if((APREADY_ENABLE_FLAG == apready_cfg.apready_enbale_flag) && (TRUE == apready_cfg.b_apready_pin_init_flag))
        {
            if((QUEC_PIN_LEVEL_HIGH - apready_cfg.apready_action_level) == apready_debounce.last_level)
            {
                quec_sio_flowctl_set_send_status(urc_context.config.atpIndex, QUEC_DISABLE);
                //CPUartLogPrintf("quec_sio_flowctl_set_send_status  QUEC_PIN_LEVEL_HIGH");            
            }
            else
            {
                quec_sio_flowctl_set_send_status(urc_context.config.atpIndex, QUEC_ENABLE);
                //CPUartLogPrintf("quec_sio_flowctl_set_send_status  QUEC_PIN_LEVEL_LOW");
                quec_sio_wm_send_msg_to_dds(urc_context.config.atpIndex, SIO_TX, 0);
            }        
        }
    }

}

void quec_apready_GPIOCallback(void)
{
    //CPUartLogPrint("quec_apready_pin_init quec_apready_GPIOCallback ");
    GPIOEdgeDetectionDisable(QUEC_APREADY_DET_PIN);
    if(apready_pin_hisr != NULL)
    {
        OS_Activate_HISR(&apready_pin_hisr); 
    }
}

static void quec_apready_pin_hisr(void)
{
    uint8 ret = 0;
    //GpioClearEdgeDetection(air_plan_debounce.pin_num); 
    //GPIOEdgeDetectionDisable(air_plan_debounce.pin_num);
    //CPUartLogPrint("apready hisr");
    ret = quec_gpio_interrupt_debounce_handler(&apready_debounce);
        
    return;
}

extern QuecOSStatus quec_apready_timer_creat(void);
QuecOSStatus quec_apready_pin_init(void)
{
    QuecOSStatus ret = kGeneralErr;

    GPIO_PinConfiguration apready_pin_cfg =
    {
        .pinNumber = QUEC_APREADY_DET_PIN,          
        .direction = GPIO_IN_PIN,           
        .transitionType = GPIO_TWO_EDGE,      
        .debounce = GPIO_DEBOUNCE_ENABLE,      
        .pullUpDown = GPIO_PULLUP_ENABLE,
        .initialValue = GPIO_INITIAL_VALUE_NO_CHANGE 
    };

    apready_debounce.pin_num = QUEC_APREADY_DET_PIN;
    //CPUartLogPrint("quec_apready_pin_init start ",TRUE);
    ret=quec_set_gpio_mfprReg(apready_pin_cfg.pinNumber, (QUEC_APREADY_DET_PIN_AF | QUEC_PULL_UP_C | QUEC_DRV_SLOW_C |QUEC_EDGE_FALL_EN|QUEC_RESERVED_C) & (~QUEC_EDGE_CLEAR));
    if(ret != QUEC_SUCCESS)
    {
        gpio_log("gpio_num=%d,gpio set mfpreg fail", apready_pin_cfg.pinNumber);
        return ret;
    }
    ret = GPIOConfigure_Ex(&apready_pin_cfg, quec_apready_GPIOCallback , NULL);
    if(ret != QUEC_SUCCESS)
    {
        gpio_log("gpio_num=%d,gpio GPIOConfigure_Ex fail, ret=%d", apready_pin_cfg.pinNumber,ret);
        return ret;
    }	
    //CPUartLogPrint("quec_apready_pin_init creat hisr ",TRUE);
    OS_Create_HISR(&apready_pin_hisr, "apready", quec_apready_pin_hisr, HISR_PRIORITY_2);
    ret = GpioClearEdgeDetection(apready_pin_cfg.pinNumber);
    ret += quec_gpio_debounce_init(&apready_debounce);
    ret += GpioEnableEdgeDetection(apready_pin_cfg.pinNumber, apready_pin_cfg.transitionType);
    //CPUartLogPrint("quec_apready_pin_init creat hisr  end",TRUE);
    apready_cfg.b_apready_pin_init_flag = TRUE;
    
    return QUEC_SUCCESS;
}


void quec_apready_init(void)
{
    UINT8 apready_enable_flag = 0;
    UINT8 status = kNoErr;

    status = quec_get_apready_enable_flag(&apready_enable_flag);
    if(QUEC_SUCCESS == status)
    {
        if(APREADY_DISABLE_FLAG == apready_enable_flag)
        {
            apready_cfg.apready_action_level = QUEC_PIN_LEVEL_LOW;
            apready_cfg.apready_enbale_flag = APREADY_DISABLE_FLAG;
        }
        else
        {
            if(APREADY_LEVEL_LOW_ACTION == apready_enable_flag)
            {
                apready_cfg.apready_action_level = QUEC_PIN_LEVEL_LOW;
                apready_cfg.apready_enbale_flag = APREADY_ENABLE_FLAG;
            }
            if(APREADY_LEVEL_HIGH_ACTION == apready_enable_flag)
            {
                apready_cfg.apready_action_level = QUEC_PIN_LEVEL_HIGH;
                apready_cfg.apready_enbale_flag = APREADY_ENABLE_FLAG;
            }            
            //CPUartLogPrint("apready init",TRUE);
            quec_apready_pin_init();
        }
    }
    else
    {
        //CPUartLogPrint("apready init failed",TRUE);
    }
}
#endif



quec_wakeup_in_cfg_t wakeup_in_cfg = {0,FALSE,0};

OS_HISR   wakeupinHisr = NULL;

#define QUEC_WAKEUP_IN_FILE   "quec_wakeupin"

BOOL quec_wakeupin_pin_is_trig(void)
{
    BOOL ret=FALSE;
    if(GpioGetLevel(QUEC_WAKEUP_IN_GPIO) == wakeup_in_cfg.detction_level){
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }
    return ret;
}

void quec_wakeup_in_timer_handler(void)
{
    QuecOSStatus ret = kGeneralErr;
    quec_msg_io_conf_value_s dtr_s = {0};
    quec_sleep_msg_s  sleep_msg={0};
    UINT32 temp_mfpr=0;
    ret = quec_gpio_debounce_timer_handler(&wakeup_in_debounce);
    if(wakeup_in_cfg.detction_level==1)
    {
       temp_mfpr=(QUEC_APREADY_DET_PIN_AF | QUEC_PULL_DN_C | QUEC_DRV_SLOW_C |QUEC_EDGE_RISE_EN|QUEC_EDGE_FALL_EN) & (~QUEC_EDGE_CLEAR);
    }
    else
    {
       temp_mfpr=(QUEC_APREADY_DET_PIN_AF | QUEC_PULL_UP_C | QUEC_DRV_SLOW_C |QUEC_EDGE_RISE_EN|QUEC_EDGE_FALL_EN) & (~QUEC_EDGE_CLEAR);
    }
    ret+=quec_set_gpio_mfprReg(QUEC_WAKEUP_IN_GPIO,temp_mfpr);
    
    if(QUEC_SUCCESS == ret)
    {
        
#ifdef QUEC_POWER_MANAGER_ENABLE
        sleep_msg.sleep_bit =  QUEC_SLEEP_WAKEUP_IN_BIT;
        if(wakeup_in_cfg.detction_level == wakeup_in_debounce.last_level)
        {
            sleep_msg.value.sleep_flag = QUEC_CUSTOMER_FLAG_NOT_SLEEP;
            quec_sleep_not_allown_sleep();
        }
        else
        {
            sleep_msg.value.sleep_flag = QUEC_CUSTOMER_FLAG_ALLOW_SLEEP;
        }
        ret = quec_send_sleep_msg(&sleep_msg);
#endif
    }
}

void quec_wakeup_in_hisr(void)
{
    quec_gpio_interrupt_debounce_handler(&wakeup_in_debounce);
}

void Quec_WAKEUP_IN_GPIOCallback(void)
{		
        GPIOEdgeDetectionDisable(QUEC_WAKEUP_IN_GPIO);
        if(wakeupinHisr != NULL)
        {
            OS_Activate_HISR(&wakeupinHisr); 
        }
}

QuecOSStatus quec_wakeup_in_gpio_init(quec_wakeup_in_cfg_t *temp_cfg)
{
    QuecOSStatus ret = kGeneralErr;

    GPIO_PinConfiguration quec_wakeup_in_cfg=                       
{                                              
        .pinNumber = QUEC_WAKEUP_IN_GPIO,        
         .direction = GPIO_IN_PIN,          
         .transitionType = GPIO_TWO_EDGE,     
         .debounce = GPIO_DEBOUNCE_ENABLE,     
         .pullUpDown = GPIO_PULLUP_ENABLE,    
         .initialValue = GPIO_INITIAL_VALUE_NO_CHANGE
};
    //CPUartLogPrint("quec_apready_pin_init start ",TRUE);
    if(temp_cfg==NULL)
    return ret;
    if(temp_cfg->enbale_flag!=TRUE)
    return ret;

    if(temp_cfg->detction_level==1)
    {
    quec_wakeup_in_cfg.pullUpDown=GPIO_PULLDN_ENABLE;
    quec_wakeup_in_cfg.initialValue=GPIO_INITIAL_VALUE_LOW;
    ret=quec_set_gpio_mfprReg(quec_wakeup_in_cfg.pinNumber, (QUEC_APREADY_DET_PIN_AF | QUEC_PULL_DN_C | QUEC_DRV_SLOW_C |QUEC_EDGE_FALL_EN|QUEC_EDGE_RISE_EN) & (~QUEC_EDGE_CLEAR));
    }
    else
    {
    quec_wakeup_in_cfg.pullUpDown=GPIO_PULLUP_ENABLE;
    quec_wakeup_in_cfg.initialValue=GPIO_INITIAL_VALUE_HIGH;
    ret=quec_set_gpio_mfprReg(quec_wakeup_in_cfg.pinNumber, (QUEC_APREADY_DET_PIN_AF | QUEC_PULL_UP_C | QUEC_DRV_SLOW_C |QUEC_EDGE_RISE_EN|QUEC_EDGE_FALL_EN) & (~QUEC_EDGE_CLEAR));
    }
    if(ret != QUEC_SUCCESS)
    {
        return ret;
    }
    if(wakeupinHisr!=NULL)
    return QUEC_SUCCESS;
    
    ret = GPIOConfigure_Ex(&quec_wakeup_in_cfg, Quec_WAKEUP_IN_GPIOCallback , NULL);
    if(ret != QUEC_SUCCESS)
    {
        return ret;
    }	
    //CPUartLogPrint("quec_apready_pin_init creat hisr ",TRUE);
    OS_Create_HISR(&wakeupinHisr, "wakeup_in", quec_wakeup_in_hisr, HISR_PRIORITY_2);
    ret = GpioClearEdgeDetection(quec_wakeup_in_cfg.pinNumber);
    if(wakeup_in_debounce.timerRef==NULL)
    ret += quec_gpio_debounce_init(&wakeup_in_debounce);
    ret += GpioEnableEdgeDetection(quec_wakeup_in_cfg.pinNumber, quec_wakeup_in_cfg.transitionType);
    
    return ret;

}

void quec_wakeup_in_gpio_deinit(void)
{
    if(wakeupinHisr!=NULL)
    {
        GpioClearEdgeDetection(QUEC_WAKEUP_IN_GPIO);
        GpioDisableEdgeDetection(QUEC_WAKEUP_IN_GPIO, GPIO_TWO_EDGE);
        GpioClearEdgeDetection_wakeup(QUEC_WAKEUP_IN_GPIO);
        GpioDisableEdgeDetection_wakeup(QUEC_WAKEUP_IN_GPIO, GPIO_TWO_EDGE);
        Os_Delete_HISR(&wakeupinHisr);
        wakeupinHisr=NULL;
    }
}


QuecOSStatus quec_get_wankeup_in_config(void)
{
    QuecOSStatus status = QUEC_SUCCESS;
    status = quectel_nv_fat_read(QUEC_WAKEUP_IN_FILE, &wakeup_in_cfg,sizeof(quec_wakeup_in_cfg_t));
    if(status != QUEC_SUCCESS)
    {
        wakeup_in_cfg.enbale_flag=FALSE;
        wakeup_in_cfg.detction_level=0;
        wakeup_in_cfg.urc_enable=FALSE;
    }
    
    return status;
}

QuecOSStatus quec_set_wankeup_in_config(char* set_config)
{
    QuecOSStatus status = kGeneralErr;
    quec_wakeup_in_cfg_t *temp_config=(quec_wakeup_in_cfg_t*)set_config;
    if(temp_config==NULL)
    return status;
    if(temp_config->urc_enable>1 || temp_config->detction_level >1 ||temp_config->enbale_flag >1)
    return status;

    if(temp_config->enbale_flag!=TRUE)
    {
        quec_wakeup_in_gpio_deinit();
    }
    else
    {
        status=quec_wakeup_in_gpio_init(temp_config);
        CPUartLogPrintf("%s,%d,status=%d",__FUNCTION__,__LINE__,status);
        if(status!=kNoErr)
        return status;
    }
    status = quectel_nv_fat_write(QUEC_WAKEUP_IN_FILE, temp_config,sizeof(quec_wakeup_in_cfg_t));
    if(status != kNoErr)
    {
        wakeup_in_cfg.enbale_flag=FALSE;
        wakeup_in_cfg.detction_level=0;
        wakeup_in_cfg.urc_enable=FALSE;
    }
    else
    {
        wakeup_in_cfg.enbale_flag=temp_config->enbale_flag;
        wakeup_in_cfg.detction_level=temp_config->detction_level;
        wakeup_in_cfg.urc_enable=temp_config->urc_enable;
    }
    
    return status;
}

void quec_wakeup_in_init(void)
{
    quec_get_wankeup_in_config();
    quec_wakeup_in_gpio_init(&wakeup_in_cfg);
}


// destin 2020.09.23 gpio led show signal qulity modified by open group	
#ifdef QUEC_CSQ_GPIO_DISPLAY_ENABLE

typedef enum
{
    CSQ_LEVEL_0 = 5,
    CSQ_LEVEL_1 = 10,
    CSQ_LEVEL_2 = 18,
    CSQ_LEVEL_3 = 25,
    CSQ_LEVEL_4 = 31,
    CSQ_LEVEL_UNKNOW = 99
    
}CSQ_LEVEL;

typedef enum
{
    LED_GPIO_ON_0 = 0,
    LED_GPIO_ON_1,
    LED_GPIO_ON_2,
    LED_GPIO_ON_3,
    LED_GPIO_ON_4,
    
}LED_GPIO_ON;

QuecOSStatus ql_nw_led_open(void)
{
	INT16 csq_temp1 = CSQ_LEVEL_UNKNOW;
	INT16 csq_temp2 = CSQ_LEVEL_UNKNOW;
	int i=0, j=0, on=0;

	if (!nw_led_init)
	{
		for(i =0; i <  QUEC_ARR_SIZE(quec_gpio_nwled) ; i++)
		{
			quec_set_gpio_mfprReg(quec_gpio_nwled[i].pinNumber, mfpr_fun[i]);// set gpio function
			if (QUEC_SUCCESS != quec_gpio_config_set(&quec_gpio_nwled[i]))
			{
				quec_debug_print_uart("error: configure quectel custom gpio fail!");
				return kGeneralErr;
			}
		}
		nw_led_init = 1;
	}
#if QUEC_DUAL_SIM_SUPPORT
	quec_cesq_2quec_csq((mmExtendedSignal_quec *)(&quec_netquality_info[isMasterSim0() ? SIM1 : SIM2]),&csq_temp1,&csq_temp2);//get csq value
#else
	quec_cesq_2quec_csq((mmExtendedSignal_quec *)(&quec_netquality_info),&csq_temp1,&csq_temp2);//get csq value
#endif
	if (csq_temp1 <= CSQ_LEVEL_0)
		on = LED_GPIO_ON_0;
	else if (csq_temp1 <= CSQ_LEVEL_1)
		on = LED_GPIO_ON_1;
	else if (csq_temp1 <= CSQ_LEVEL_2)
		on = LED_GPIO_ON_2;
	else if (csq_temp1 <= CSQ_LEVEL_3)
		on = LED_GPIO_ON_3;
	else if (csq_temp1 <= CSQ_LEVEL_4)
		on = LED_GPIO_ON_4;
	else
		on = LED_GPIO_ON_0;

	for(i=0; i<on; i++)   //on
		quec_set_gpio_level(quec_gpio_nwled[i].pinNumber, (quec_pin_level_value_e) GPIO_INITIAL_VALUE_HIGH);

	for(j=on; j<4; j++)   //off
		quec_set_gpio_level(quec_gpio_nwled[j].pinNumber, (quec_pin_level_value_e) GPIO_INITIAL_VALUE_LOW);

	return QUEC_SUCCESS;
}

QuecOSStatus quec_csq_gpio_display_deinit(void)
{
    UINT i = 0;
    if(nw_led_init != 1)
    {
        return kGeneralErr;
    }
    // set all pin low
    for(i=0; i<4; i++)
    {   
        quec_set_gpio_level(quec_gpio_nwled[i].pinNumber, (quec_pin_level_value_e) GPIO_INITIAL_VALUE_LOW);
    }
    return QUEC_SUCCESS;
    
}

void quec_csq_gpio_display_state(void)
{
    if(csq_gpio_cfg_state == 1){
        ql_nw_led_open();
    }
}

#endif

/*destin  2020.03.09 ASR 1603 (EC600N) sleep indication */
#if QUEC_QSLEEP_IND_CTL
void quec_sleep_ind_light(void)
{
	quec_set_gpio_level(IPC_SLEEP_IND_NUM, QUEC_PIN_LEVEL_HIGH);
}
void quec_sleep_ind_dark(void)
{
	quec_set_gpio_level(IPC_SLEEP_IND_NUM, QUEC_PIN_LEVEL_LOW);
}
#endif

//Fitz.xu 20210207: Add for L&T right led
//Fitz.xu 20210311: According to customer's circuit, LCC61 HIGH --> LED2 off, LCC61 LOW --> LED2 on
//Fitz.xu 20210315: Customer change the schematic, so we need to change this
//Fitz.xu 20210421: Add for FAE-10441
#if defined(__QUEC_OEM_VER_LT__)
void quec_LT_right_led_on(void)
{
	quec_set_gpio_level(QUEC_POWER_STATUS_PIN, QUEC_PIN_LEVEL_HIGH);
}

void quec_LT_right_led_off(void)
{
	quec_set_gpio_level(QUEC_POWER_STATUS_PIN, QUEC_PIN_LEVEL_LOW);
}
#endif

#endif

