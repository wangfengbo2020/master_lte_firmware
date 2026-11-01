/**  @file
  quec_led_task.c

  @brief
  This file is used to process led status.

*/

/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/

/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     --------------------------------------------------
14/11/2019        Fitz   	 Init version
=================================================================*/


/*===========================================================================
 * include files
 ===========================================================================*/
#include "quec_led_task.h"
#include "quec_led_cfg_tbl.h"
#include "quec_led_status.h"
#include "quec_pwm.h"
#include "quec_gpio.h"
#include "quec_cust_feature.h"
#ifdef QUEC_PRODUCTION_CFG_SUPPORT
#include "quec_production_cfg.h"
#endif



#ifndef MIN_SYS


#if defined(QUEC_LED_TASK_SUPPORT)

/*===========================================================================
 * Macro Definition
 ===========================================================================*/
#ifdef QUEC_ATCMD_LOG
#define quec_led_log(msg, ...)  //custom_log("QUEC_LED_TASK", msg, ##__VA_ARGS__)
#else
#define quec_led_log(msg, ...)
#endif

#define QUEC_LED_TASK_STACK_SIZE        (8192)
#define QUEC_LED_TASK_PRIORITY          (QUEC_APP_TASK_PRIORITY)
#define QUEC_LED_STATUS_UPDATE_TIMEOUT  (500) /*isaac-20200723 ¦Ì¡Â???a500ms,¨®D¨ºy?Y¨º¡À¨º1??¦Ì?¨¦¨¢??*/

/* led task flag value */
#define QUEC_LED_TASK_PROCESS_CMD   (0x01)
#define QUEC_LED_TASK_SLEEP_CMD     (0x02)
#define QUEC_LED_TASK_WAKEUP_CMD    (0x04)

#if defined(__QUEC_OEM_VER_LT__) 
#define QUEC_LT_CHECK_AT_TIMEOUT    (2000) //2S
#define QUEC_LT_1S_ONOFF_TIMEOUT	(1000) //1S
#define QUEC_LT_200MS_ONOFF_TIMEOUT (200)  //200ms
#endif

#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610
#define QUEC_NETMODE_TASK_STACK_SIZE	(4096)
#define QUEC_NETMODE_TASK_PRIORITY 		(QUEC_APP_TASK_PRIORITY)
#define QUEC_QPWMCFG_NVM   "quec_pwmcfg_nvm"
#endif

/*===========================================================================
 * struct,enum definition
 ===========================================================================*/
/* LED NET_MODE onoff definition */
typedef enum
{
    QUEC_LED_NET_MODE_OFF = 0,
    QUEC_LED_NET_MODE_ON = 1,
}quec_led_net_mode_status_e;


#if defined(QUEC_LED_NET_MODE_SUPPORT)
/* save ledmode */
#define QUEC_NV_LED_MODE_CFG  "quec_nv_led_mode_cfg"

/* ledmode type */
typedef enum
{
    QUEC_LEDMODE_MODEM = 0,
    QUEC_LEDMODE_RESERVED = 1,
    QUEC_LEDMODE_MINIPCIE = 2,
}quec_led_mode_e;

#if defined(__QUEC_OEM_VER_LT__)
enum QUEC_LT_RIGHT_LED_STATUS
{
	RIGHT_LED_POWER_ON = 0x08,	
	RIGHT_LED_SEND_RDY = 0x09,
	RIGHT_LED_RECV_AT  = 0x0A,
	RIGHT_LED_WAIT_AT_TIMEOUT = 0x0B,
	RIGHT_LED_DATA_TRANSMIT = 0x0C,
	RIGHT_LED_IDLE = 0x0D
};

static bool quec_is_lt_recv_at = FALSE;
#endif

#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610
enum quec_netmode_type
{
	NET_MODE_NORMAL = 0x00,
	NET_MODE_COMPATIBLE = 0x02,
};

enum quec_netmode_L610_status
{
	NET_MODE_STATUS_600MS_H_600MS_L = 0x01,
	NET_MODE_STATUS_75MS_H_3000MS_L = 0x02,
	NET_MODE_STATUS_75MS_H_75MS_L = 0x03,
	NET_MODE_STATUS_H = 0x04,
	NET_MODE_STATUS_L = 0x05,
};
#endif


/* save current ledmode */
static uint8 cur_ledmode = QUEC_LEDMODE_MODEM;
#endif

static uint8 led_task_state = QUEC_LED_TASK_PROCESS_CMD-1; //Chaim 2020.0208 record led task current state

/*===========================================================================
 * Global Variable
 ===========================================================================*/
static quec_task_t p_quec_led_task = NULL;
static quec_flag_t quec_led_task_flag = NULL;
static quec_timer_t quec_led_task_timer = NULL;

static quec_module_status quec_last_led_status = NET_LED_STATUS_MAX;

#if defined(__QUEC_OEM_VER_LT__)
static quec_timer_t quec_LT_check_at_timer = NULL;
static quec_timer_t quec_LT_1s_onoff_timer = NULL;
static quec_timer_t quec_LT_200ms_onoff_timer = NULL;
static bool quec_LT_1s_onoff_flag = FALSE;
#endif

#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610
static quec_task_t p_quec_netmode_task = NULL;
static quec_timer_t p_quec_led_task_timer = NULL;
static quec_queue_t  quec_netmode_queue = NULL;
static quec_timer_t quec_netmode_timer = NULL;
char g_qpwmcfg = 0; //save netmode cfg
static char g_quec_netmode = 0; //save current netmode status
#endif

//Fitz.xu 20210724: To indicate if data transmit on uart1
#if defined(__QUEC_OEM_VER_LT__)
static bool b_data_transmit = FALSE;
#endif

#if defined(__QUEC_OEM_VER_ALLIED__)
static quec_task_t p_quec_allied_netmode_task = NULL;
static quec_timer_t p_quec_allied_led_task_timer = NULL;
static quec_queue_t  quec_allied_netmode_queue = NULL;
static quec_timer_t quec_allied_netmode_timer = NULL;
static char g_allied_quec_netmode = 0; //save current netmode status
static bool b_is_recv_at_within_10s = TRUE;
static uint8 quec_single_cycle_cnt = 0; //save single cycle cnt
static bool b_is_recv_at_after_10s = FALSE;
#endif


/*===========================================================================
 * extern
 ===========================================================================*/
#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610
char quec_read_qpwmcfg_mode(void);
void quec_set_qpwmcfg_mode(char mode);
static QuecOSStatus quec_netmode_queue_release(uint8 *p_netmode_msg);
void quec_netmode_init(void);
static QuecOSStatus quec_net_mode_task_init(void);
static void quec_netmode_task(void);
static QuecOSStatus quec_netmode_timer_creat(void);
static void quec_netmode_timer_callback(void);
static void quec_netmode_timer_3000ms_callback(void);
static void quec_netmode_timer_75ms_callback(void);
#endif

#if defined(__QUEC_OEM_VER_LT__)
extern void quec_LT_200ms_on_timeout_cb(void);
#endif

/*===========================================================================

FUNCTION quec_led_task_flag_init

DESCRIPTION
  create led task flag.

DEPENDENCIES
  None

RETURN VALUE
  result err code

SIDE EFFECTS
  None
===========================================================================*/
static QuecOSStatus quec_led_task_flag_init(void)
{
    QuecOSStatus err = kNoErr;

    err = quec_rtos_flag_create(&quec_led_task_flag);
    require_noerr_string(err, exit, "quec_led_task_flag_init failed");

exit:
    return err;
}

/*===========================================================================

FUNCTION quec_led_task_flag_wait

DESCRIPTION
  wait led task flag.

DEPENDENCIES
  None

RETURN VALUE
  result err code

SIDE EFFECTS
  None
===========================================================================*/
static QuecOSStatus quec_led_task_flag_wait(uint32 *flag_value)
{
    QuecOSStatus err = kNoErr;

#if defined(__QUEC_OEM_VER_LT__)
    err = quec_rtos_flag_wait(quec_led_task_flag, QUEC_LED_TASK_PROCESS_CMD|QUEC_LED_TASK_SLEEP_CMD|QUEC_LED_TASK_WAKEUP_CMD|RIGHT_LED_POWER_ON|\
		RIGHT_LED_SEND_RDY|RIGHT_LED_RECV_AT|RIGHT_LED_WAIT_AT_TIMEOUT|RIGHT_LED_DATA_TRANSMIT|RIGHT_LED_IDLE, \
		QUEC_FLAG_OR_CLEAR, flag_value, QUEC_WAIT_FOREVER);                                
#else
	err = quec_rtos_flag_wait(quec_led_task_flag, QUEC_LED_TASK_PROCESS_CMD|QUEC_LED_TASK_SLEEP_CMD|QUEC_LED_TASK_WAKEUP_CMD, \
		QUEC_FLAG_OR_CLEAR, flag_value, QUEC_WAIT_FOREVER);
#endif
    require_noerr_string(err, exit, "quec_rtos_flag_release failed");

    quec_led_log("flag_value=%d", *flag_value);
    //quec_debug_print_uart("quec_led_task_flag_wait success, value=%d", *flag_value);

exit:
    return err;
}

/*===========================================================================

FUNCTION quec_led_task_flag_release

DESCRIPTION
  release led task flag.

DEPENDENCIES
  None

RETURN VALUE
  result err code

SIDE EFFECTS
  None
===========================================================================*/
QuecOSStatus quec_led_task_flag_release(uint32 flag_value)
{
    QuecOSStatus err = kNoErr;

    if (quec_led_task_flag != NULL)
    {
        err = quec_rtos_flag_release(quec_led_task_flag, flag_value, QUEC_FLAG_OR);
        require_noerr_string(err, exit, "quec_led_task_flag_release failed");

        quec_led_log("flag_value=%d", flag_value);
        //quec_debug_print_uart("quec_rtos_flag_release success, flag_value=%d", flag_value);
    }
    else
    {
        err = kGeneralErr;
    }
        
exit:
    return err;
}

/*===========================================================================

FUNCTION quec_led_task_flag_delete

DESCRIPTION
  delete led task flag.

DEPENDENCIES
  None

RETURN VALUE
  result err code

SIDE EFFECTS
  None
===========================================================================*/
static QuecOSStatus quec_led_task_flag_delete(void)
{
    QuecOSStatus err = kNoErr;

    if (quec_led_task_flag)
    {
        err = quec_rtos_flag_delete(quec_led_task_flag);
        require_noerr_string(err, exit, "quec_fota_feed_flag_delete failed");
        quec_led_task_flag = NULL;
    }
exit:
    return err;
}

/*===========================================================================

FUNCTION quec_led_timer_callback

DESCRIPTION
  led task timer callback.

DEPENDENCIES
  None

RETURN VALUE
  result err code

SIDE EFFECTS
  None
===========================================================================*/
static void quec_led_timer_callback(void)
{
    quec_led_task_flag_release(QUEC_LED_TASK_PROCESS_CMD);
}



//Chaim 2020.0208 for stop led task
void quec_led_task_stop(void)
{   
	//quec_debug_print_uart("stop led_task_state=%d", led_task_state);
    
	if((QUEC_LED_TASK_PROCESS_CMD == led_task_state) || (QUEC_LED_TASK_WAKEUP_CMD == led_task_state))
	{
	    quec_led_task_flag_release(QUEC_LED_TASK_SLEEP_CMD);
	}
}

//Chaim 2020.0208 for run led task
void quec_led_task_run(void)
{
	//quec_debug_print_uart("run led_task_state=%d", led_task_state);
    
	if(QUEC_LED_TASK_SLEEP_CMD == led_task_state)
	{
    	quec_led_task_flag_release(QUEC_LED_TASK_WAKEUP_CMD);
	}
}


/*===========================================================================

FUNCTION quec_led_timer_creat

DESCRIPTION
  create led task timer.

DEPENDENCIES
  None

RETURN VALUE
  result err code

SIDE EFFECTS
  None
===========================================================================*/
static QuecOSStatus quec_led_timer_creat(void)
{
    QuecOSStatus err = kNoErr;

    if (quec_led_task_timer != NULL)
    {
        quec_led_log("led task timer already start");
        return kAlreadyInitializedErr;
    }

	err = quec_rtos_timer_create(&quec_led_task_timer);
    if (err != kNoErr)
    {
        quec_led_log("quec_led_timer_creat failed");
        return err;
    }

	return err;
}

/*===========================================================================

FUNCTION quec_led_timer_start

DESCRIPTION
  start led task timer.

DEPENDENCIES
  None

RETURN VALUE
  result err code

SIDE EFFECTS
  None
===========================================================================*/
static QuecOSStatus quec_led_timer_start(uint32 init_time, bool cyclical_enable, void(* callback_routine)(void), uint32 timer_argc)
{
    QuecOSStatus err = kNoErr;

    if (quec_led_task_timer == NULL)
    {
        quec_led_log("quec_led_task_timer not init");
        return kNotInitializedErr;
    }

    /* start timer */
	err = quec_rtos_timer_start(quec_led_task_timer, init_time, cyclical_enable, callback_routine, timer_argc);
    if (err != kNoErr)
    {
        quec_led_log("quec_led_timer_start failed");
    }

	return err;
}

/*===========================================================================

FUNCTION quec_led_timer_stop

DESCRIPTION
  stop led task timer.

DEPENDENCIES
  None

RETURN VALUE
  result err code

SIDE EFFECTS
  None
===========================================================================*/
static QuecOSStatus quec_led_timer_stop(void)
{
    QuecOSStatus err = kNoErr;

    if (quec_led_task_timer == NULL)
    {
        quec_led_log("quec_led_timer not init");
        return kNotInitializedErr;
    }

	err = quec_rtos_timer_stop(quec_led_task_timer);
    if (err != kNoErr)
    {
        quec_led_log("quec_led_timer_stop failed");
    }

    //quec_debug_print_uart("quec_led_timer_stop, err=%d", err);
    
	return err;
}

/*===========================================================================

FUNCTION quec_led_timer_delete

DESCRIPTION
  delete led task timer.

DEPENDENCIES
  None

RETURN VALUE
  result err code

SIDE EFFECTS
  None
===========================================================================*/
static QuecOSStatus quec_led_timer_delete(void)
{
    QuecOSStatus err = kNoErr;

    if (quec_led_task_timer == NULL)
    {
        quec_led_log("quec_led_timer not init");
        return kNotInitializedErr;
    }

    err = quec_rtos_timer_delete(quec_led_task_timer);
    if (err != kNoErr)
    {
        quec_led_log("quec_led_timer_delete failed");
        return err;
    }

    quec_led_task_timer = NULL;

    return err;
}


#if defined(QUEC_LED_NET_STATUS_CFG_SUPPORT) 
QuecOSStatus quec_net_status_cfg_set(uint8 net_status, uint32 cycle, uint8 ratio)
{
    int ret = 0;

    /* to in compatible with AT+QLEDSTAT */
    switch (net_status)
    {
        case 0:
            ret = quec_led_cfg_tbl_set(SEARCHING, quec_led_cfg_tbl[SEARCHING].gpio_num, quec_led_cfg_tbl[SEARCHING].pwm_num, quec_led_cfg_tbl[SEARCHING].priority, 0, cycle, ratio);
        break;

        case 1:
            ret = quec_led_cfg_tbl_set(DIALING, quec_led_cfg_tbl[DIALING].gpio_num, quec_led_cfg_tbl[DIALING].pwm_num, quec_led_cfg_tbl[DIALING].priority, 0, cycle, ratio);
        break;

        case 2:
            ret = quec_led_cfg_tbl_set(DATA_TRANSMIT, quec_led_cfg_tbl[DATA_TRANSMIT].gpio_num, quec_led_cfg_tbl[DATA_TRANSMIT].pwm_num, quec_led_cfg_tbl[DATA_TRANSMIT].priority, 0, cycle, ratio);
        break;

        case 3:
            ret = quec_led_cfg_tbl_set(STANDBY, quec_led_cfg_tbl[STANDBY].gpio_num, quec_led_cfg_tbl[STANDBY].pwm_num, quec_led_cfg_tbl[STANDBY].priority, 0, cycle, ratio);
        break;

        default:
        break;
    }

    return ret;
}
#endif


#if defined(QUEC_LED_NET_MODE_SUPPORT)
/*===========================================================================

FUNCTION quec_led_netstatus_on

DESCRIPTION
  Set MET_STATUS led to high level.

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
void quec_led_netstatus_on(void)
{
    quec_pwm_set(quec_net_status_pwm, PWM_OUT_SET_BY_DCYCLE, 2000, 2000);
}

/*===========================================================================

FUNCTION quec_led_netstatus_off

DESCRIPTION
  Set MET_STATUS led to low level.

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
void quec_led_netstatus_off(void)
{
    quec_pwm_set(quec_net_status_pwm, PWM_OUT_SET_BY_DCYCLE, 0, 2000);
}

/*===========================================================================

FUNCTION quec_ledmode_set

DESCRIPTION
  Set MET_STATUS led work mode.

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  Err code
===========================================================================*/
int quec_ledmode_set(uint8 mode)
{
    int fat_ret = 0;
    
    cur_ledmode = mode;
#if QUEC_PRODUCTION_CFG_SUPPORT
    ST_quecCfgCustFeatureParams ST_CustFeatureParams = {0};
    /* relaod params */
	if(QUEC_SUCCESS != Quec_SysItemPara_Item_get(QUEC_CUST_FEATURE_CFG, &ST_CustFeatureParams, sizeof(ST_quecCfgCustFeatureParams)))
	{
		quec_led_log("Failed:Quec_SysItemPara_Item_get QUEC_CUST_FEATURE_CFG"); 
	}
	/* save params */
	ST_CustFeatureParams.netLedMode = cur_ledmode;
	fat_ret = Quec_SysItemPara_Item_set(QUEC_CUST_FEATURE_CFG, &ST_CustFeatureParams, sizeof(ST_quecCfgCustFeatureParams));
#else	
    fat_ret = quectel_nv_fat_write(QUEC_NV_LED_MODE_CFG, &cur_ledmode, sizeof(cur_ledmode));
#endif
    if (QUEC_FAT_SUCCESS != fat_ret)
    {
        quec_led_log("quec_ledmode_get err=%d", fat_ret);    
    }

    return fat_ret;
}

/*===========================================================================

FUNCTION quec_ledmode_get

DESCRIPTION
  Get MET_STATUS led work mode.

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  Err code
===========================================================================*/
int quec_ledmode_get(uint8 *p_mode)
{
    int ret = 0;
#if QUEC_PRODUCTION_CFG_SUPPORT
    ST_quecCfgCustFeatureParams ST_CustFeatureParams = {0};
	ret = Quec_SysItemPara_Item_get(QUEC_CUST_FEATURE_CFG, &ST_CustFeatureParams, sizeof(ST_quecCfgCustFeatureParams));
	if(ret == QUEC_SUCCESS){
		*p_mode = ST_CustFeatureParams.netLedMode;
	}
#else	
    ret = quectel_nv_fat_read(QUEC_NV_LED_MODE_CFG, p_mode, 1);
#endif
    if (QUEC_FAT_SUCCESS != ret)
    {
        quec_led_log("quec_ledmode_get err=%d", ret);      
    } 

    return ret;
}
#endif

/*===========================================================================

FUNCTION quec_led_pwm_set

DESCRIPTION
  MET_STATUS led pwm set.

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
void quec_led_pwm_set(quec_module_status netstatus, PWM_DEVICE_NUM pwm_num, uint8 ratio, uint16 cycle)
{    
    quec_led_log("netstatus=%d, pwm_dev=%d, ratio=%d, cycle=%d", netstatus, pwm_num, ratio, cycle);    
    
    #if defined(QUEC_LED_NET_MODE_SUPPORT)
    quec_led_log("cur_ledmode=%d", cur_ledmode);
    if (QUEC_LEDMODE_MINIPCIE == cur_ledmode)
    {
        if (quec_led_get_registered_status() != NOT_REGISTERED)
        {
            quec_led_netstatus_on();
        }
        else
        {
            quec_led_netstatus_off();
        }

        return;
    }
    #endif

    quec_pwm_set(pwm_num, PWM_OUT_SET_BY_DCYCLE, cycle*ratio/100, cycle);
}

/*===========================================================================

FUNCTION quec_led_netmode_set

DESCRIPTION
  NET_MODE led on/off set.

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
static void quec_led_netmode_set(quec_led_net_mode_status_e led_status)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    quec_pin_level_value_e set_level =QUEC_PIN_LEVEL_HIGH;

    if (led_status == QUEC_LED_NET_MODE_ON)
    {
        set_level = QUEC_PIN_LEVEL_HIGH;
    }
    else
    {
        set_level = QUEC_PIN_LEVEL_LOW;
    }

    ret = quec_set_gpio_level(QUEC_NET_MODE_GPIO, set_level);
    if(ret != QUEC_SUCCESS)
    {
        quec_led_log("quec_set_gpio_level fail");
        return kGeneralErr;
    }
    
    return QUEC_SUCCESS;    
}


#ifdef QUEC_LED_GPIO_TO_PWM 
static quec_task_t gpio_pwm_taskref = NULL;
static unsigned int p_ratio = 0;
static unsigned int p_cycle = 0;

void gpio_pwm_func(void)			//Realize gpio simulation task, the duty cycle is changed by quec_led_gpio_pwm
{
	GPIO_PinConfiguration pin_config = {QUEC_NET_STATUS_GPIO,1,0,0,0,0};
	while(1)
	{
		//RTI_LOG("pwm_num:%d,ratio:%d,cycle:%d \n",QUEC_NET_STATUS_GPIO,p_ratio,p_cycle);
		quec_gpio_config_set(&pin_config);
		quec_set_gpio_level(QUEC_NET_STATUS_GPIO, 1);
		quec_rtos_task_sleep_ms(p_ratio*p_cycle/100);
		quec_set_gpio_level(QUEC_NET_STATUS_GPIO, 0);
		quec_rtos_task_sleep_ms(p_cycle - (p_ratio*p_cycle/100));
	}
}
#endif
/*===========================================================================

FUNCTION quec_led_status_process

DESCRIPTION
  process NET_STATUS led.

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
void quec_led_status_process(void)
{
    uint8 network_type = 0;
#ifdef QUEC_LED_GPIO_TO_PWM 
    static char pwm_flag = 1;
	quec_pin_config_s pin_config = {0};
#endif	
    network_type = quec_led_get_registered_status();

#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610
	if (quec_read_qpwmcfg_mode() != NET_MODE_COMPATIBLE)
#endif
	{
		//Fitz.xu 20210421: Add for FAE-10441
		#ifndef __QUEC_OEM_VER_ALLIED__
	    /* Process NET_MODE led */
		#if !QUEC_LTE_SUPPORT
		    if (REGOSTERED_ON_3G == network_type)
		    {
		        quec_led_netmode_set(QUEC_LED_NET_MODE_ON);         
		    }
		    else
		    {
		        quec_led_netmode_set(QUEC_LED_NET_MODE_OFF);     
		    }
		#else
		    if (REGOSTERED_ON_4G == network_type)
		    {
		        quec_led_netmode_set(QUEC_LED_NET_MODE_ON);     
		    }
		    else
		    {
		        quec_led_netmode_set(QUEC_LED_NET_MODE_OFF);    
		    }
		#endif
		#endif
	}

    if ((network_type > NOT_REGISTERED) && (network_type <= REGOSTERED_ON_4G))
    {
        /* check dialing status */
        if (quec_led_get_call_status())
        {
            if (DIALING != quec_last_led_status)
            {
                quec_led_log("led status, last=%d, current=DIALING", quec_last_led_status);
			#ifdef QUEC_LED_GPIO_TO_PWM 
				p_ratio = quec_led_cfg_tbl[DIALING].net_type[network_type].ratio;
				p_cycle = quec_led_cfg_tbl[DIALING].net_type[network_type].cycle;
			#else	
                quec_led_pwm_set(DIALING, quec_led_cfg_tbl[DIALING].pwm_num, quec_led_cfg_tbl[DIALING].net_type[network_type].ratio, quec_led_cfg_tbl[DIALING].net_type[network_type].cycle);         
			#endif
				quec_last_led_status = DIALING;

			#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
				if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
				{
					g_quec_netmode = NET_MODE_STATUS_L;
					quec_netmode_queue_release(&g_quec_netmode);	
				}
			#endif
            }
        } 
        /* PDP activated and netif bind */
        else if (quec_led_get_pdp_status())
        {
            /* Fitz.xu 20201221: Check if netif bind. */
            if (quec_led_get_netif_status())
            {
                /* use PPP */
                if (quec_led_get_ppp_status())
                {
            	#if defined(QUEC_GW_NET_LIGHT_SUPPORT)
                    if (TRUE == quec_gw_sock_led_state_get_ex())
					{
                    	quec_led_log("led status, last=%d, current=DATA_TRANSMIT", quec_last_led_status);
					#ifdef QUEC_LED_GPIO_TO_PWM 
						p_ratio = quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].ratio;
						p_cycle = quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].cycle;
					#else	
                    	quec_led_pwm_set(DATA_TRANSMIT, quec_led_cfg_tbl[DATA_TRANSMIT].pwm_num, quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].ratio, quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].cycle);            
					#endif
						quec_last_led_status = DATA_TRANSMIT;
                	}
                	else if (PDP_ACTIVED != quec_last_led_status)
                	{
	                    quec_led_log("led status, last=%d, current=PDP_ACTIVED", quec_last_led_status);
					#ifdef QUEC_LED_GPIO_TO_PWM 
						p_ratio = quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].ratio;
						p_cycle = quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].cycle;
					#else	
	                    quec_led_pwm_set(PDP_ACTIVED, quec_led_cfg_tbl[PDP_ACTIVED].pwm_num, quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].ratio, quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].cycle);            
					#endif
						quec_last_led_status = PDP_ACTIVED;
                	}            
                #else
                    if (quec_led_get_data_transmit_status())
                    {
                        if (DATA_TRANSMIT != quec_last_led_status)
                        {
                            quec_led_log("led status, last=%d, current=DATA_TRANSMIT", quec_last_led_status);
						#ifdef QUEC_LED_GPIO_TO_PWM 
							p_ratio = quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].ratio;
							p_cycle = quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].cycle;
						#else	
                            quec_led_pwm_set(DATA_TRANSMIT, (PWM_DEVICE_NUM)quec_led_cfg_tbl[DATA_TRANSMIT].pwm_num, quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].ratio, quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].cycle);            
						#endif
							quec_last_led_status = DATA_TRANSMIT;

						#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
							if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
							{
								g_quec_netmode = NET_MODE_STATUS_75MS_H_75MS_L;
								quec_netmode_queue_release(&g_quec_netmode);	
							}
						#endif
                        } 	
                    }
                    /* PPP is set up, but no data transmit */
                    else
                    {
                        if (PDP_ACTIVED != quec_last_led_status)
                        {
                            quec_led_log("led status, last=%d, current=PDP_ACTIVED", quec_last_led_status);
						#ifdef QUEC_LED_GPIO_TO_PWM 
							p_ratio = quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].ratio;
							p_cycle = quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].cycle;
						#else	
                            quec_led_pwm_set(PDP_ACTIVED, (PWM_DEVICE_NUM)quec_led_cfg_tbl[PDP_ACTIVED].pwm_num, quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].ratio, quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].cycle);            
						#endif
							quec_last_led_status = PDP_ACTIVED;

						#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
							if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
							{
								g_quec_netmode = NET_MODE_STATUS_75MS_H_75MS_L;
								quec_netmode_queue_release(&g_quec_netmode);	
							}
						#endif	
                        }
                    }
                #endif
                }    
                /* use internal stack */
                else if (quec_led_get_socket_create_status())
                {
                    if (quec_led_get_socket_connect_status() && quec_led_get_data_transmit_status())
                    {
                        if (DATA_TRANSMIT != quec_last_led_status)
                        {
                            quec_led_log("led status, last=%d, current=DATA_TRANSMIT", quec_last_led_status);
						#ifdef QUEC_LED_GPIO_TO_PWM 
							p_ratio = quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].ratio;
							p_cycle = quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].cycle;
						#else	
                            quec_led_pwm_set(DATA_TRANSMIT, (PWM_DEVICE_NUM)quec_led_cfg_tbl[DATA_TRANSMIT].pwm_num, quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].ratio, quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].cycle);            
						#endif
							quec_last_led_status = DATA_TRANSMIT;

						#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
							if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
							{
								g_quec_netmode = NET_MODE_STATUS_75MS_H_75MS_L;
								quec_netmode_queue_release(&g_quec_netmode);	
							}
						#endif
                        } 
                    }
                    /* socket had set up, but no data transmit */
                    else if (quec_led_get_socket_connect_status())
                    {
                        if (SOCKET_SET_UP != quec_last_led_status)
                        {
                            quec_led_log("led status, last=%d, current=SOCKET_SET_UP", quec_last_led_status);
						#ifdef QUEC_LED_GPIO_TO_PWM 
							p_ratio = quec_led_cfg_tbl[SOCKET_SET_UP].net_type[network_type].ratio;
							p_cycle = quec_led_cfg_tbl[SOCKET_SET_UP].net_type[network_type].cycle;
						#else	
                            quec_led_pwm_set(SOCKET_SET_UP, (PWM_DEVICE_NUM)quec_led_cfg_tbl[SOCKET_SET_UP].pwm_num, quec_led_cfg_tbl[SOCKET_SET_UP].net_type[network_type].ratio, quec_led_cfg_tbl[SOCKET_SET_UP].net_type[network_type].cycle);            
						#endif
							quec_last_led_status = SOCKET_SET_UP;

						#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
							if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
							{
								g_quec_netmode = NET_MODE_STATUS_75MS_H_75MS_L;
								quec_netmode_queue_release(&g_quec_netmode);	
							}
						#endif	

						//Fitz.xu 20210819: Add for FAE-20035
						#if defined(__QUEC_OEM_VER_ALLIED__)
							quec_allied_netmode_queue_release(QUEC_ALLIED_NET_MODE_STATUS_NORMAL_HIGH);
						#endif
                        }
                    }
                    else
                    {
                        //only socket create, no socket set up, no data transmit
                        if (PDP_ACTIVED != quec_last_led_status)
                        {
                            quec_led_log("led status, last=%d, current=PDP_ACTIVED", quec_last_led_status);
						#ifdef QUEC_LED_GPIO_TO_PWM 
							p_ratio = quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].ratio;
							p_cycle = quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].cycle;
						#else	
                            quec_led_pwm_set(PDP_ACTIVED, (PWM_DEVICE_NUM)quec_led_cfg_tbl[PDP_ACTIVED].pwm_num, quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].ratio, quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].cycle);            
						#endif
							quec_last_led_status = PDP_ACTIVED;

						#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
							if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
							{
								g_quec_netmode = NET_MODE_STATUS_75MS_H_75MS_L;
								quec_netmode_queue_release(&g_quec_netmode);	
							}
						#endif	

						//Fitz.xu 20210819: Add for FAE-20035
						#if defined(__QUEC_OEM_VER_ALLIED__)
							quec_allied_netmode_queue_release(QUEC_ALLIED_NET_MODE_STATUS_NORMAL_HIGH);
						#endif
                        }
                    }
                }
                /* use RNDIS or ECM */
                else if (quec_led_get_netdev_status())
                {
                    if(quec_led_get_data_transmit_status())
                    {
                        if (DATA_TRANSMIT != quec_last_led_status)
                        {
                            quec_led_log("led status, last=%d, current=DATA_TRANSMIT", quec_last_led_status);
						#ifdef QUEC_LED_GPIO_TO_PWM 
							p_ratio = quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].ratio;
							p_cycle = quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].cycle;
						#else	
                            quec_led_pwm_set(DATA_TRANSMIT, (PWM_DEVICE_NUM)quec_led_cfg_tbl[DATA_TRANSMIT].pwm_num, quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].ratio, quec_led_cfg_tbl[DATA_TRANSMIT].net_type[network_type].cycle);            
						#endif
							quec_last_led_status = DATA_TRANSMIT;

						#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
							if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
							{
								g_quec_netmode = NET_MODE_STATUS_75MS_H_75MS_L;
								quec_netmode_queue_release(&g_quec_netmode);	
							}
						#endif	
                        } 
                    }
                    /* socket netdev bind success, but no data transmit */
                    else
                    {
                        if (PDP_ACTIVED != quec_last_led_status)
                        {
                            quec_led_log("led status, last=%d, current=PDP_ACTIVED", quec_last_led_status);
						#ifdef QUEC_LED_GPIO_TO_PWM 
							p_ratio = quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].ratio;
							p_cycle = quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].cycle;
						#else	
                            quec_led_pwm_set(PDP_ACTIVED, (PWM_DEVICE_NUM)quec_led_cfg_tbl[PDP_ACTIVED].pwm_num, quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].ratio, quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].cycle);            
						#endif
							quec_last_led_status = PDP_ACTIVED;

						#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
							if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
							{
								g_quec_netmode = NET_MODE_STATUS_75MS_H_75MS_L;
								quec_netmode_queue_release(&g_quec_netmode);	
							}
						#endif	
                        }
                    }
                }  
                /* no link, no data transmit */
                else
                {
                    if (PDP_ACTIVED != quec_last_led_status)
                    {
                        quec_led_log("led status, last=%d, current=PDP_ACTIVED, netif bind", quec_last_led_status);
					#ifdef QUEC_LED_GPIO_TO_PWM 
						p_ratio = quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].ratio;
						p_cycle = quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].cycle;
					#else	
                        quec_led_pwm_set(PDP_ACTIVED, quec_led_cfg_tbl[PDP_ACTIVED].pwm_num, quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].ratio, quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].cycle);            
					#endif
						quec_last_led_status = PDP_ACTIVED;

					#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
						if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
						{
							g_quec_netmode = NET_MODE_STATUS_75MS_H_75MS_L;
							quec_netmode_queue_release(&g_quec_netmode);	
						}
					#endif	
                    }
                }
            }
            /* Fitz.xu 20201221: PDP actived, netif not bind */
            else
            {
                if (PDP_ACTIVED != quec_last_led_status)
                {
                    quec_led_log("led status, last=%d, current=PDP_ACTIVED", quec_last_led_status);
				#ifdef QUEC_LED_GPIO_TO_PWM 
					p_ratio = quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].ratio;
					p_cycle = quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].cycle;
				#else	
                    quec_led_pwm_set(PDP_ACTIVED, quec_led_cfg_tbl[PDP_ACTIVED].pwm_num, quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].ratio, quec_led_cfg_tbl[PDP_ACTIVED].net_type[network_type].cycle);            
				#endif
					quec_last_led_status = PDP_ACTIVED;

				#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
					if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
					{
						g_quec_netmode = NET_MODE_STATUS_75MS_H_75MS_L;
						quec_netmode_queue_release(&g_quec_netmode);	
					}
				#endif
                }
            }
        }
        else
        { 
            if (STANDBY != quec_last_led_status)
            {
                quec_led_log("led status, last=%d, current=STANDBY", quec_last_led_status);
			#ifdef QUEC_LED_GPIO_TO_PWM 
				p_ratio = quec_led_cfg_tbl[STANDBY].net_type[network_type].ratio;
				p_cycle = quec_led_cfg_tbl[STANDBY].net_type[network_type].cycle;
			#else	
                quec_led_pwm_set(STANDBY, quec_led_cfg_tbl[STANDBY].pwm_num, quec_led_cfg_tbl[STANDBY].net_type[network_type].ratio, quec_led_cfg_tbl[STANDBY].net_type[network_type].cycle);                 
			#endif
				quec_last_led_status = STANDBY;

				
			#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
				if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
				{
					g_quec_netmode = NET_MODE_STATUS_75MS_H_3000MS_L;
					quec_netmode_queue_release(&g_quec_netmode);	
				}
			#endif
            }
        }
    }
    else
    {
        /* check if sim is inserted */
        if (FALSE == quec_led_get_sim_insert_status())
        {
            if (SIM_NOT_INSERT != quec_last_led_status)
            {
                quec_led_log("led status, last=%d, current=SIM_NOT_INSERT", quec_last_led_status);
			#ifdef QUEC_LED_GPIO_TO_PWM 
				p_ratio = quec_led_cfg_tbl[SIM_NOT_INSERT].net_type[network_type].ratio;
				p_cycle = quec_led_cfg_tbl[SIM_NOT_INSERT].net_type[network_type].cycle;
			#else	
                quec_led_pwm_set(SIM_NOT_INSERT, quec_led_cfg_tbl[SIM_NOT_INSERT].pwm_num, quec_led_cfg_tbl[SIM_NOT_INSERT].net_type[network_type].ratio, quec_led_cfg_tbl[SIM_NOT_INSERT].net_type[network_type].cycle);            
			#endif
				quec_last_led_status = SIM_NOT_INSERT;

			#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
				if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
				{
					g_quec_netmode = NET_MODE_STATUS_600MS_H_600MS_L;
					quec_netmode_queue_release(&g_quec_netmode);	
				}
			#endif
            }    
        }
        /* check if sim is initializing */
        else if (quec_led_get_sim_initializing_status())
        {
            if (SIM_INITIALIZING != quec_last_led_status)
            {
                quec_led_log("led status, last=%d, current=SIM_INITIALIZING", quec_last_led_status);
			#ifdef QUEC_LED_GPIO_TO_PWM 
				p_ratio = quec_led_cfg_tbl[SIM_INITIALIZING].net_type[network_type].ratio;
				p_cycle = quec_led_cfg_tbl[SIM_INITIALIZING].net_type[network_type].cycle;
			#else	
                quec_led_pwm_set(SIM_INITIALIZING, quec_led_cfg_tbl[SIM_INITIALIZING].pwm_num, quec_led_cfg_tbl[SIM_INITIALIZING].net_type[network_type].ratio, quec_led_cfg_tbl[SIM_INITIALIZING].net_type[network_type].cycle);            
			#endif
				quec_last_led_status = SIM_INITIALIZING;
            }
        }
        /* check if pin lock */
        else if (quec_led_get_pin_lock_status())
        {
            if (SIM_PIN_LOCK != quec_last_led_status)
            {
                quec_led_log("led status, last=%d, current=SIM_PIN_LOCK", quec_last_led_status);
			#ifdef QUEC_LED_GPIO_TO_PWM 
				p_ratio = quec_led_cfg_tbl[SIM_PIN_LOCK].net_type[network_type].ratio;
				p_cycle = quec_led_cfg_tbl[SIM_PIN_LOCK].net_type[network_type].cycle;
			#else	
                quec_led_pwm_set(SIM_PIN_LOCK, quec_led_cfg_tbl[SIM_PIN_LOCK].pwm_num, quec_led_cfg_tbl[SIM_PIN_LOCK].net_type[network_type].ratio, quec_led_cfg_tbl[SIM_PIN_LOCK].net_type[network_type].cycle);            
			#endif
				quec_last_led_status = SIM_PIN_LOCK;

				
			#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
				if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
				{
					g_quec_netmode = NET_MODE_STATUS_600MS_H_600MS_L;
					quec_netmode_queue_release(&g_quec_netmode);	
				}
			#endif
            }
        }
        /* check if cpin is ready */
        else if (quec_led_get_cpin_ready_status())
        {
            /* check if module is searching */
            if (quec_led_get_searching_status())
            {
                if (SEARCHING != quec_last_led_status)
                {
                    quec_led_log("led status, last=%d, current=SEARCHING", quec_last_led_status);
				#ifdef QUEC_LED_GPIO_TO_PWM 
					p_ratio = quec_led_cfg_tbl[SEARCHING].net_type[network_type].ratio;
					p_cycle = quec_led_cfg_tbl[SEARCHING].net_type[network_type].cycle;
				#else	
                    quec_led_pwm_set(SEARCHING, quec_led_cfg_tbl[SEARCHING].pwm_num, quec_led_cfg_tbl[SEARCHING].net_type[network_type].ratio, quec_led_cfg_tbl[SEARCHING].net_type[network_type].cycle);            
				#endif
					quec_last_led_status = SEARCHING;

					
				#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
					if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
					{
						g_quec_netmode = NET_MODE_STATUS_600MS_H_600MS_L;
						quec_netmode_queue_release(&g_quec_netmode);	
					}
				#endif
                }
            }
            /* check if module camp on cell */
            else if (quec_led_get_camp_on_cell_status())
            {
                if (CAMP_ON_CELL != quec_last_led_status)
                {
                    quec_led_log("led status, last=%d, current=CAMP_ON_CELL", quec_last_led_status);
				#ifdef QUEC_LED_GPIO_TO_PWM 
					p_ratio = quec_led_cfg_tbl[CAMP_ON_CELL].net_type[network_type].ratio;
					p_cycle = quec_led_cfg_tbl[CAMP_ON_CELL].net_type[network_type].cycle;
				#else	
                    quec_led_pwm_set(CAMP_ON_CELL, quec_led_cfg_tbl[CAMP_ON_CELL].pwm_num, quec_led_cfg_tbl[CAMP_ON_CELL].net_type[network_type].ratio, quec_led_cfg_tbl[CAMP_ON_CELL].net_type[network_type].cycle);            
				#endif
					quec_last_led_status = CAMP_ON_CELL;

					
				#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
					if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
					{
						g_quec_netmode = NET_MODE_STATUS_600MS_H_600MS_L;
						quec_netmode_queue_release(&g_quec_netmode);	
					}
				#endif
                }
            }
            /* check if module is registering */
            else if (quec_led_get_registering_status())
            {
                if (REGISTERING != quec_last_led_status)
                {
                    quec_led_log("led status, last=%d, current=REGISTERING", quec_last_led_status);
				#ifdef QUEC_LED_GPIO_TO_PWM 
					p_ratio = quec_led_cfg_tbl[REGISTERING].net_type[network_type].ratio;
					p_cycle = quec_led_cfg_tbl[REGISTERING].net_type[network_type].cycle;
				#else	
                    quec_led_pwm_set(REGISTERING, quec_led_cfg_tbl[REGISTERING].pwm_num, quec_led_cfg_tbl[REGISTERING].net_type[network_type].ratio, quec_led_cfg_tbl[REGISTERING].net_type[network_type].cycle);            
				#endif
					quec_last_led_status = REGISTERING;

					
				#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
					if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
					{
						g_quec_netmode = NET_MODE_STATUS_600MS_H_600MS_L;
						quec_netmode_queue_release(&g_quec_netmode);	
					}
				#endif
                }
            }
            else
            {
                if (SIM_CPIN_READY != quec_last_led_status)
                {
                    quec_led_log("led status, last=%d, current=SIM_CPIN_READY", quec_last_led_status);
				#ifdef QUEC_LED_GPIO_TO_PWM 
					p_ratio = quec_led_cfg_tbl[SIM_CPIN_READY].net_type[network_type].ratio;
					p_cycle = quec_led_cfg_tbl[SIM_CPIN_READY].net_type[network_type].cycle;
				#else	
                    quec_led_pwm_set(SIM_CPIN_READY, quec_led_cfg_tbl[SIM_CPIN_READY].pwm_num, quec_led_cfg_tbl[SIM_CPIN_READY].net_type[network_type].ratio, quec_led_cfg_tbl[SIM_CPIN_READY].net_type[network_type].cycle);            
				#endif
					quec_last_led_status = SIM_CPIN_READY;
                }
            }            
        }  
    }

#ifdef QUEC_LED_GPIO_TO_PWM 
	if(pwm_flag){			//Create a task gpio_pwm_func that implements gpio simulation
		pin_config.config.pinNumber = QUEC_NET_STATUS_GPIO;
		pin_config.config.direction = GPIO_OUT_PIN;
		pin_config.config.initialValue = 0;
		pin_config.config.pullUpDown = GPIO_INITIAL_VALUE_LOW;
		pin_config.mfprReg_data = QUEC_NET_STATUS_GPIO_AF |QUEC_PULL_UP_C |QUEC_DRV_FAST_C |QUEC_RESERVED_C;
		quec_gpio_init(&pin_config);
		quec_rtos_task_create(&gpio_pwm_taskref, 1024, 100, "gpio_pwm_func", gpio_pwm_func, NULL);
		pwm_flag = 0;
	}		
#endif
}


/*===========================================================================

FUNCTION quec_led_task

DESCRIPTION
  led task entry.

DEPENDENCIES
  None

RETURN VALUE
  result err code

SIDE EFFECTS
  None
===========================================================================*/
static void quec_led_task(void)
{
    QuecOSStatus err = kNoErr;
    uint32 flag_value = 0;  
#ifdef QUEC_LED_GPIO_TO_PWM 
	GPIO_PinConfiguration pin_config = {0};
	pin_config.pinNumber = QUEC_NET_STATUS_GPIO;
#endif
    err = quec_led_task_flag_init();
    require_noerr_string(err, exit, "quec_led_task_flag_init failed");

    err = quec_led_timer_creat();
    require_noerr_string(err, exit2, "quec_led_timer_creat failed");
    
    quec_led_cfg_tbl_initialize();

    #if defined(QUEC_LED_NET_MODE_SUPPORT)
    quec_ledmode_get(&cur_ledmode);
    quec_led_log("cur_ledmode=%d", cur_ledmode);
    #endif

    #if defined(QUEC_LED_NET_STATUS_CFG_SUPPORT) 
    quec_led_cfg_tbl_get();
    #endif

    err = quec_led_timer_start(QUEC_LED_STATUS_UPDATE_TIMEOUT, TRUE, quec_led_timer_callback, 0);
    require_noerr_string(err, exit2, "quec_led_timer_creat failed");

    while (1)
    {
        err = quec_led_task_flag_wait(&flag_value);
        require_noerr_string(err, exit2, "quec_led_task_flag_wait failed");
       
        switch (flag_value)
        {
            case QUEC_LED_TASK_SLEEP_CMD:
            {
                /* when sleep, stop timer, do not release flag */   
			    led_task_state = flag_value;
                //quec_led_timer_stop();
                quec_led_timer_delete(); 
                /*isaac-20200723 1. ¨¨?¨®D¨ºy?Y¡ä?¨º?¡ê??¨´¡ä?¨¦¨¢??(¨¦?¡ä?¡Á¡ä¨¬?2?¨ª?2??¨¢¨¦¨¨??,1¨º?3?¦Ì??¨¨??¦Ì)
                 * 2. ??¨¨?DY??¡ê?net sta ¦Ì?1?¡À?
                 */
                quec_last_led_status = NET_LED_STATUS_MAX; 
				#ifdef QUEC_LED_GPIO_TO_PWM 
					quec_rtos_task_suspend(gpio_pwm_taskref);
					quec_gpio_config_set(&pin_config);
				#else
					pwmDisable(quec_net_status_pwm);
				#endif
			
				#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610	
					if (quec_read_qpwmcfg_mode() == NET_MODE_COMPATIBLE)
					{
						g_quec_netmode = NET_MODE_STATUS_H;
						quec_netmode_queue_release(&g_quec_netmode);	
					}
				#endif
				break;
            }
			
            case QUEC_LED_TASK_WAKEUP_CMD:
            {
				led_task_state = flag_value;
                quec_led_timer_creat();
                quec_led_timer_start(QUEC_LED_STATUS_UPDATE_TIMEOUT, TRUE, quec_led_timer_callback, 0);
			#ifdef QUEC_LED_GPIO_TO_PWM
				quec_rtos_task_resume(gpio_pwm_taskref);
			#endif
				break;
            }
			
            case QUEC_LED_TASK_PROCESS_CMD: 
            {
                if (quec_led_task_timer != NULL)
                {
                    led_task_state = flag_value;
                }
                quec_led_status_process();

				break;
            }

		#if defined(__QUEC_OEM_VER_LT__) 
			case RIGHT_LED_POWER_ON:
			case RIGHT_LED_SEND_RDY:
			{
				quec_LT_right_led_on();
				break;
			}
			
			case RIGHT_LED_RECV_AT:
			{
				quec_is_lt_recv_at = TRUE;
				quec_LT_right_led_on();
				quec_LT_1s_onoff_timer_delete();
				quec_LT_check_at_timer_delete();
				break;
			}

			case RIGHT_LED_WAIT_AT_TIMEOUT:
			{
				quec_LT_1s_onoff_timer_start();
				break;
			}  	

			case RIGHT_LED_DATA_TRANSMIT:
			{
				if (quec_is_lt_recv_at)
				{
					quec_LT_1s_onoff_timer_delete();
					quec_LT_200ms_on_timer_start();
				}

				b_data_transmit = false;
				
				break;
			}

			case RIGHT_LED_IDLE:
			{
				break;
			}
		#endif
			
            default:
            break;
        }  
		//led_task_state = flag_value;  //Chaim 2020.0208 record led task state
		//quec_debug_print_uart("task led_task_state=%d",led_task_state);
    }    

exit2:
    quec_led_timer_delete();
exit:
    quec_led_task_flag_delete();
}

/*===========================================================================

FUNCTION quec_led_task_init

DESCRIPTION
  create led task.

DEPENDENCIES
  None

RETURN VALUE
  result err code

SIDE EFFECTS
  None
===========================================================================*/
QuecOSStatus quec_led_task_init(void)
{
    QuecOSStatus err = kNoErr;    

    if (NULL != p_quec_led_task)
    {
        quec_led_log("p_quec_led_task is not NULL");
        return kGeneralErr;
    }

    /* create led task */
    err = quec_rtos_task_create(&p_quec_led_task, QUEC_LED_TASK_STACK_SIZE, QUEC_LED_TASK_PRIORITY, quec_task_name[QUEC_TASK_NAME_LED], quec_led_task, NULL);
    if (kNoErr != err)
    {
    	p_quec_led_task = NULL;
        quec_led_log("quec_led_task init failed");
        return err;
    }

    quec_led_log("quec_led_task init done");
    
    return err;
}

/*===========================================================================

FUNCTION quec_led_reset_status

DESCRIPTION
  invoke by quec_led_cfg_tbl_set(...) to make pwm settting take effect immediately.

DEPENDENCIES
  None

RETURN VALUE
  result err code

SIDE EFFECTS
  None
===========================================================================*/
void quec_led_reset_status(void) 
{
    quec_last_led_status = NET_LED_STATUS_MAX;
}

#endif

#if defined(__QUEC_OEM_VER_LT__) 
//wait "AT" 2S timeout callback
void quec_LT_check_at_timeout_cb(void)
{
	quec_led_task_flag_release(RIGHT_LED_WAIT_AT_TIMEOUT);	
}

//Start wait "AT" 2S timer after sent RDY
void quec_LT_check_at_timeout_start(void)
{
	quec_rtos_timer_create(&quec_LT_check_at_timer);
	quec_rtos_timer_start(quec_LT_check_at_timer, QUEC_LT_CHECK_AT_TIMEOUT, FALSE, quec_LT_check_at_timeout_cb, 0);
}

//Delete wait "AT" 2S timer
void quec_LT_check_at_timer_delete(void)
{
	if (quec_LT_check_at_timer != NULL)
	{
		quec_rtos_timer_delete(quec_LT_check_at_timer);
		quec_LT_check_at_timer = NULL;
	}
}

//wait "AT" timeout callback
void quec_LT_1s_onoff_timeout_cb(void)
{
	if (quec_LT_1s_onoff_flag)
	{
		quec_LT_right_led_off();
		quec_LT_1s_onoff_flag = FALSE;
	}
	else
	{
		quec_LT_right_led_on();	
		quec_LT_1s_onoff_flag = TRUE;
	}
}

//Start wait "AT" timeout timer
void quec_LT_1s_onoff_timer_start(void)
{
	quec_LT_check_at_timer_delete();
	
	quec_LT_right_led_on();
	quec_LT_1s_onoff_flag = TRUE;
	quec_rtos_timer_create(&quec_LT_1s_onoff_timer);
	quec_rtos_timer_start(quec_LT_1s_onoff_timer, QUEC_LT_1S_ONOFF_TIMEOUT, TRUE, quec_LT_1s_onoff_timeout_cb, 0);
}

//Delete 1S timer
void quec_LT_1s_onoff_timer_delete(void)
{
	if (quec_LT_1s_onoff_timer != NULL)
	{
		quec_rtos_timer_delete(quec_LT_1s_onoff_timer);
		quec_LT_1s_onoff_timer = NULL;
	}
}

//callback of 200ms onoff timer
void quec_LT_200ms_onoff_timeout_cb(void)
{
	quec_LT_right_led_on();
	
	if (quec_LT_200ms_onoff_timer != NULL)
	{
		quec_rtos_timer_delete(quec_LT_200ms_onoff_timer);
		quec_LT_200ms_onoff_timer = NULL;
	}
}

//Start 200ms onoff timer
void quec_LT_200ms_onoff_timer_start(void)
{
	if (quec_LT_200ms_onoff_timer == NULL)
	{
		quec_LT_right_led_off();
		quec_rtos_timer_create(&quec_LT_200ms_onoff_timer);
		quec_rtos_timer_start(quec_LT_200ms_onoff_timer, QUEC_LT_200MS_ONOFF_TIMEOUT, FALSE, quec_LT_200ms_onoff_timeout_cb, 0);
	}
}

//Fitz.xu 20210724: Fix FAE-18535.
void quec_ALLIED_200ms_end(void)
{
	quec_LT_right_led_on();

	if (quec_LT_200ms_onoff_timer != NULL)
	{
		quec_rtos_timer_delete(quec_LT_200ms_onoff_timer);
		quec_LT_200ms_onoff_timer = NULL;
	}		
}

void quec_LT_200ms_off_timeout_cb(void)
{
	quec_LT_right_led_off();

	if (b_data_transmit)
	{
		if (quec_LT_200ms_onoff_timer != NULL)
		{
			quec_rtos_timer_start(quec_LT_200ms_onoff_timer, QUEC_LT_200MS_ONOFF_TIMEOUT, FALSE, quec_LT_200ms_on_timeout_cb, 0);
		}
	}
	else
	{
		if (quec_LT_200ms_onoff_timer != NULL)
		{
			quec_rtos_timer_start(quec_LT_200ms_onoff_timer, QUEC_LT_200MS_ONOFF_TIMEOUT, FALSE, quec_ALLIED_200ms_end, 0);
		}
	}
}

void quec_LT_200ms_on_timeout_cb(void)
{
	quec_LT_right_led_on();
	
	if (quec_LT_200ms_onoff_timer != NULL)
	{
		quec_rtos_timer_start(quec_LT_200ms_onoff_timer, QUEC_LT_200MS_ONOFF_TIMEOUT, FALSE, quec_LT_200ms_off_timeout_cb, 0);
	}
}

void quec_LT_200ms_on_timer_start(void)
{
	if (quec_LT_200ms_onoff_timer == NULL)
	{
		quec_LT_right_led_off();
		quec_rtos_timer_create(&quec_LT_200ms_onoff_timer);
		quec_rtos_timer_start(quec_LT_200ms_onoff_timer, QUEC_LT_200MS_ONOFF_TIMEOUT, FALSE, quec_LT_200ms_on_timeout_cb, 0);
	}
}

void quec_LT_200ms_off_timer_start(void)
{
	if (quec_LT_200ms_onoff_timer == NULL)
	{
		quec_LT_right_led_off();
		quec_rtos_timer_create(&quec_LT_200ms_onoff_timer);
		quec_rtos_timer_start(quec_LT_200ms_onoff_timer, QUEC_LT_200MS_ONOFF_TIMEOUT, FALSE, quec_LT_200ms_off_timeout_cb, 0);
	}
}

//Trigger to start wait AT timer
void quec_LT_send_rdy(void)
{
	quec_led_task_flag_release(RIGHT_LED_SEND_RDY);
}

//Trigger to RIGHT_LED_RECV_AT
void quec_LT_recv_at(void)
{
	quec_led_log("LT: recv AT");
	quec_led_task_flag_release(RIGHT_LED_RECV_AT);
}

//Trigger to RIGHT_LED_DATA_TRANSMIT
void quec_LT_data_transmit(void)
{
	b_data_transmit = TRUE;
	quec_led_task_flag_release(RIGHT_LED_DATA_TRANSMIT);	
}

//Check if module received "AT"
bool quec_LT_is_recv_at(void)
{
	return quec_is_lt_recv_at;
}

#endif

//Fitz.xu 20210819: add for india allied led_mode
#if defined(__QUEC_OEM_VER_ALLIED__)
static void quec_netmode_timer_10s_callback(void)
{
	b_is_recv_at_within_10s = FALSE;
	quec_allied_netmode_queue_release(QUEC_ALLIED_NET_MODE_STATUS_NOT_RECV_AT_AFTER_10S);
}

static void quec_netmode_timer_1s_callback(void)
{
	quec_pin_level_value_e pin_level;
	
#if 1
        quec_get_gpio_level(QUEC_NET_MODE_GPIO, &pin_level);
#else
        pin_level=QUEC_PIN_LEVEL_LOW;
#endif
	if(pin_level == QUEC_PIN_LEVEL_HIGH)
	{
		quec_led_netmode_set(QUEC_LED_NET_MODE_OFF);	
	}
	else
	{
		quec_led_netmode_set(QUEC_LED_NET_MODE_ON);	
	}
}

static void quec_netmode_timer_200ms_callback(void)
{
	quec_pin_level_value_e pin_level;
	
#if 1
        quec_get_gpio_level(QUEC_NET_MODE_GPIO, &pin_level);
#else
        pin_level=QUEC_PIN_LEVEL_LOW;
#endif
	if(pin_level == QUEC_PIN_LEVEL_HIGH)
	{
		quec_led_netmode_set(QUEC_LED_NET_MODE_OFF);	
	}
	else
	{
		quec_led_netmode_set(QUEC_LED_NET_MODE_ON);	
	}

	quec_single_cycle_cnt++;
	if (quec_single_cycle_cnt == 3)
	{
		quec_single_cycle_cnt = 0;
		quec_rtos_timer_stop(quec_allied_netmode_timer);	
	}
}

static QuecOSStatus quec_allied_netmode_timer_creat(void)
{
    QuecOSStatus err = kNoErr;

    if (quec_allied_netmode_timer != NULL)
    {
        quec_led_log("quec_allied_netmode_timer already start");
        return kAlreadyInitializedErr;
    }

	err = quec_rtos_timer_create(&quec_allied_netmode_timer);
    if (err != kNoErr)
    {
        quec_led_log("quec_allied_netmode_timer failed");
        return err;
    }

	return err;
}

QuecOSStatus quec_allied_netmode_queue_release(uint8 netmode_msg)
{
	QuecOSStatus ret = kNoErr;
	uint8 *p_netmode_msg = &netmode_msg;
	
	ret = quec_rtos_queue_release(quec_allied_netmode_queue, sizeof(char), p_netmode_msg, QUEC_NO_WAIT);
    if(ret != kNoErr)
    {
        quec_led_log("release quec_allied_netmode_queue failed"); 
    }

	return ret;
}

static void quec_allied_netmode_task(void)
{
	QuecOSStatus ret = kNoErr;
	uint8 status = 0;

	quec_allied_netmode_timer_creat();
	
	while(1)
	{
		ret = quec_rtos_queue_wait(quec_allied_netmode_queue, (uint8 *)&status, sizeof(status), QUEC_WAIT_FOREVER);
		if (kNoErr != ret)
		{
   			quec_led_log("netmode task wait queue failed");
			break;
		}

		switch (status)
		{
			case QUEC_ALLIED_NET_MODE_STATUS_PWR_ON:
			{
				quec_rtos_timer_stop(quec_allied_netmode_timer);
				quec_led_netmode_set(QUEC_LED_NET_MODE_ON);
				quec_rtos_timer_start(quec_allied_netmode_timer, 10000, FALSE, quec_netmode_timer_10s_callback, 0);
				break;
			}
			
			case QUEC_ALLIED_NET_MODE_STATUS_RECV_AT_WITHIN_10S:
			{
				if (b_is_recv_at_within_10s)
				{
					quec_rtos_timer_stop(quec_allied_netmode_timer);
					quec_led_netmode_set(QUEC_LED_NET_MODE_ON);
				}
				else
				{
					//Fitz.xu 20210825: if recv AT after 10s, do not process
					//Fitz.xu 20210909: FAE-21634, new requirement

					if (!b_is_recv_at_after_10s)
					{
						b_is_recv_at_after_10s = TRUE;
						quec_rtos_timer_stop(quec_allied_netmode_timer);
						quec_led_netmode_set(QUEC_LED_NET_MODE_ON);
					}
					else
					{
						// only process once
					}
				}
				
				break;
			}

			case QUEC_ALLIED_NET_MODE_STATUS_NOT_RECV_AT_AFTER_10S:
			{
				quec_rtos_timer_stop(quec_allied_netmode_timer);
				quec_led_netmode_set(QUEC_LED_NET_MODE_OFF);
				quec_rtos_timer_start(quec_allied_netmode_timer, 1000, TRUE, quec_netmode_timer_1s_callback, 0);
				break;
			}

			case QUEC_ALLIED_NET_MODE_STATUS_TCP_FTP_TRANSMIT:
			{
				if ((b_is_recv_at_within_10s || b_is_recv_at_after_10s) && !quec_single_cycle_cnt)
				{
					quec_rtos_timer_stop(quec_allied_netmode_timer);
					quec_led_netmode_set(QUEC_LED_NET_MODE_OFF);
					quec_rtos_timer_start(quec_allied_netmode_timer, 200, TRUE, quec_netmode_timer_200ms_callback, 0);
				}
				break;
			}

			case QUEC_ALLIED_NET_MODE_STATUS_NORMAL_HIGH:
			{
				if (b_is_recv_at_within_10s || b_is_recv_at_after_10s)
				{
					quec_rtos_timer_stop(quec_allied_netmode_timer);
					quec_led_netmode_set(QUEC_LED_NET_MODE_ON);
				}
				break;
			}	

			default:
			break;
		}
	}
}

QuecOSStatus quec_allied_net_mode_task_init(void)
{
    QuecOSStatus err = kNoErr;    

    if (NULL != p_quec_allied_netmode_task)
    {
        quec_led_log("p_quec_allied_ledmode_task is not NULL");
        return kGeneralErr;
    }

	err = quec_rtos_queue_create(&quec_allied_netmode_queue, sizeof(char), 32);
    if (kNoErr != err)
	{
		quec_led_log("quec_allied_netmode_queue init failed");
	}

    err = quec_rtos_task_create(&p_quec_allied_netmode_task, QUEC_NETMODE_TASK_STACK_SIZE, QUEC_NETMODE_TASK_PRIORITY, quec_task_name[QUEC_TASK_NAME_ALLIED_NETMODE], quec_allied_netmode_task, NULL);
    if (kNoErr != err)
    {
    	p_quec_allied_netmode_task = NULL;
        quec_led_log("p_quec_allied_netmode_task init failed");
		quec_rtos_queue_delete(quec_allied_netmode_queue);
        return err;
    }

	quec_allied_netmode_queue_release(QUEC_ALLIED_NET_MODE_STATUS_PWR_ON);

    quec_led_log("quec_allied_netmode_task init done");
    
    return err;
}
#endif

#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610
char quec_read_qpwmcfg_mode(void)
{
	return g_qpwmcfg;
}

void quec_set_qpwmcfg_mode(char mode)
{
	g_qpwmcfg = mode;

	if (quectel_nv_fat_write(QUEC_QPWMCFG_NVM, &g_qpwmcfg, sizeof(g_qpwmcfg)))
	{
		quec_led_log("quec_set_qpwmcfg_mode write failed");
	}

	if (g_qpwmcfg == NET_MODE_COMPATIBLE)
	{
		quec_net_mode_task_init();		
	}
	else
	{
		if (quec_netmode_timer != NULL)
		{
			quec_rtos_timer_stop(quec_netmode_timer);
			quec_netmode_timer = NULL;
		}

		if (quec_netmode_queue != NULL)
		{
			quec_rtos_queue_delete(quec_netmode_queue);
		}

		if (p_quec_netmode_task != NULL)
		{
			quec_rtos_task_delete(p_quec_netmode_task);
			p_quec_netmode_task = NULL;
		}

		//qpwmcfg changed, so reset quec_last_led_status to trigger new status
        quec_led_reset_status();     
	}
}

static QuecOSStatus quec_netmode_queue_release(uint8 *p_netmode_msg)
{
	QuecOSStatus ret = kNoErr;
	
	ret = quec_rtos_queue_release(quec_netmode_queue, sizeof(char), p_netmode_msg, QUEC_NO_WAIT);
    if(ret != kNoErr)
    {
        quec_led_log("release quec_netmode_queue failed"); 
    }

	return ret;
}

static QuecOSStatus quec_netmode_timer_creat(void)
{
    QuecOSStatus err = kNoErr;

    if (quec_netmode_timer != NULL)
    {
        quec_led_log("quec_netmode_timer already start");
        return kAlreadyInitializedErr;
    }

	err = quec_rtos_timer_create(&quec_netmode_timer);
    if (err != kNoErr)
    {
        quec_led_log("quec_netmode_timer failed");
        return err;
    }

	return err;
}

static void quec_netmode_timer_callback(void)
{
	quec_pin_level_value_e pin_level;
	
#if 1
        quec_get_gpio_level(QUEC_NET_MODE_GPIO, &pin_level);
#else
        pin_level=QUEC_PIN_LEVEL_LOW;
#endif
	if(pin_level == QUEC_PIN_LEVEL_HIGH)
	{
		quec_led_netmode_set(QUEC_LED_NET_MODE_OFF);	
	}
	else
	{
		quec_led_netmode_set(QUEC_LED_NET_MODE_ON);	
	}
}

static void quec_netmode_timer_3000ms_callback(void)
{
	quec_pin_level_value_e pin_level;
//evin 20210728 fix EG912Y compile error
#if 1
	quec_get_gpio_level(QUEC_NET_MODE_GPIO, &pin_level);
#else
    pin_level=QUEC_PIN_LEVEL_LOW;
#endif
	if(pin_level == QUEC_PIN_LEVEL_HIGH)
	{
		quec_led_netmode_set(QUEC_LED_NET_MODE_OFF);	
	}
	else
	{
		quec_led_netmode_set(QUEC_LED_NET_MODE_ON);	
	}

	quec_rtos_timer_start(quec_netmode_timer, 75, FALSE, quec_netmode_timer_75ms_callback, 0);
}

static void quec_netmode_timer_75ms_callback(void)
{
	quec_pin_level_value_e pin_level;
#if 1
	quec_get_gpio_level(QUEC_NET_MODE_GPIO, &pin_level);
#else
    pin_level=QUEC_PIN_LEVEL_LOW;
#endif	
	if(pin_level == QUEC_PIN_LEVEL_HIGH)
	{
		quec_led_netmode_set(QUEC_LED_NET_MODE_OFF);	
	}
	else
	{
		quec_led_netmode_set(QUEC_LED_NET_MODE_ON);	
	}

	quec_rtos_timer_start(quec_netmode_timer, 3000, FALSE, quec_netmode_timer_3000ms_callback, 0);
}


void quec_netmode_init(void)
{
	char temp = 0;
	
	if (quectel_nv_fat_read(QUEC_QPWMCFG_NVM, &temp, sizeof(g_qpwmcfg)))
	{
		quec_led_log("read qpwmcfg failed");
	}

	g_qpwmcfg = temp;
	if (g_qpwmcfg == NET_MODE_COMPATIBLE)
	{
		quec_net_mode_task_init();	
	}
	else
	{
		//do nothing
	}	
}

static QuecOSStatus quec_net_mode_task_init(void)
{
    QuecOSStatus err = kNoErr;    

    if (NULL != p_quec_netmode_task)
    {
        quec_led_log("p_quec_led_task is not NULL");
        return kGeneralErr;
    }

	err = quec_rtos_queue_create(&quec_netmode_queue, sizeof(char), 32);
    if (kNoErr != err)
	{
		quec_led_log("quec_netmode_queue init failed");
	}

    err = quec_rtos_task_create(&p_quec_netmode_task, QUEC_NETMODE_TASK_STACK_SIZE, QUEC_NETMODE_TASK_PRIORITY, quec_task_name[QUEC_TASK_NAME_NETMODE], quec_netmode_task, NULL);
    if (kNoErr != err)
    {
    	p_quec_netmode_task = NULL;
        quec_led_log("quec_netmdoe_task init failed");
		quec_rtos_queue_delete(quec_netmode_queue);
        return err;
    }

    quec_led_log("quec_netmode_task init done");
    
    return err;
}

static void quec_netmode_task(void)
{
	QuecOSStatus ret = kNoErr;
	uint8 status = 0;

	quec_netmode_timer_creat();
	
	while(1)
	{
		ret = quec_rtos_queue_wait(quec_netmode_queue, (uint8 *)&status, sizeof(status), QUEC_WAIT_FOREVER);
		if (kNoErr != ret)
		{
   			quec_led_log("netmode task wait queue failed");
			break;
		}

		switch (status)
		{
			case NET_MODE_STATUS_600MS_H_600MS_L:
			{
				quec_rtos_timer_stop(quec_netmode_timer);
				quec_led_netmode_set(QUEC_LED_NET_MODE_ON);
				quec_rtos_timer_start(quec_netmode_timer, 600, TRUE, quec_netmode_timer_callback, 0);
				break;
			}

			case NET_MODE_STATUS_75MS_H_3000MS_L:
			{
				quec_rtos_timer_stop(quec_netmode_timer);
				quec_led_netmode_set(QUEC_LED_NET_MODE_OFF);
				quec_rtos_timer_start(quec_netmode_timer, 75, FALSE, quec_netmode_timer_75ms_callback, 0);
				break;
			}

			case NET_MODE_STATUS_75MS_H_75MS_L:
			{
				quec_rtos_timer_stop(quec_netmode_timer);
				quec_led_netmode_set(QUEC_LED_NET_MODE_OFF);
				quec_rtos_timer_start(quec_netmode_timer, 75, TRUE, quec_netmode_timer_callback, 0);
				break;
			}

			case NET_MODE_STATUS_H:
			{
				quec_rtos_timer_stop(quec_netmode_timer);
				quec_led_netmode_set(QUEC_LED_NET_MODE_ON);
				break;
			}

			case NET_MODE_STATUS_L:
			{
				quec_rtos_timer_stop(quec_netmode_timer);
				quec_led_netmode_set(QUEC_LED_NET_MODE_OFF);
				break;
			}

			default:
			break;
		}
	}
}
#endif

#endif /*MIN_SYS*/

