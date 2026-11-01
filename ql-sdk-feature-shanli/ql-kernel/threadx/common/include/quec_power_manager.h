/**  @file
  quec_power_manager.h

  @brief
  This file is used to define at command parameter for different Quectel Project.

*/

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
11/19/2018		  Chaim	 Init version
=================================================================*/

#ifndef __QUEC_POWER_MANAGER_H__

#define __QUEC_POWER_MANAGER_H__

#include "quec_cust_feature.h"
#include "quec_common.h"
#include "teldef.h"
#include "quec_rtos.h"

#ifdef QUEC_POWER_MANAGER_ENABLE

#define  QUEC_POWER_MANAGER_LOG_ENABLE 

typedef enum
{
    QUEC_SLEEP_ACTIVE_TASK_BIT = -1,
    QUEC_SLEEP_PM_BIT = 0,              //PMEnableSleep
    QUEC_SLEEP_ASR_PLATFORM_BIT,
    QUEC_SLEEP_DTR_BIT,
    QUEC_SLEEP_QSCLK_BIT,               //3
    QUEC_SLEEP_MAJORUART_RX_BIT,
    QUEC_SLEEP_MAJORUART_TX_BIT,
    QUEC_SLEEP_USB_BUSY_BIT,     //6 add asr pm_usb_busy 
    #ifdef __QUEC_OEM_VER_NL__
        QUEC_SLEEP_MINORUART_RX_BIT,
        QUEC_SLEEP_MINORUART_TX_BIT,
    #endif
	QUEC_SLEEP_CAMERA_BUSY_BIT,
	QUEC_SLEEP_RI_BUSY_BIT,
    QUEC_SLEEP_WAKEUP_IN_BIT,
    #if defined(__QUEC_OEM_VER_WUS__)
    QUEC_SLEEP_WUS_GPIO_BIT,
    #endif 
    QUEC_SLEEP_MAX_BIT, //not exceed (unsigned short)16 bit 
}quec_sleep_bit_flag_e;

typedef enum 
{
    QUEC_CUSTOMER_FLAG_ALLOW_SLEEP =0,
    QUEC_CUSTOMER_FLAG_NOT_SLEEP=1,  
}quec_platform_sleep_flag_e;
    

typedef struct
{
    quec_sleep_bit_flag_e bit_type;
    uint32 tick_value;
    uint32 compare_tick_value;
}quec_record_tick_s;

typedef enum 
{
    QUEC_SLEEP_USB_ACTIVE = 0,
    QUEC_SLEEP_UART_DATA_TRANSMITING_ACTIVE,
    QUEC_SLEEP_USIM_ACTIVE,
    QUEC_ATS_CMD_ACTIVE,
}quec_sleep_active_flag_e;

typedef union
{
    quec_platform_sleep_flag_e  sleep_flag;
    quec_sleep_active_flag_e    active_flag;   // distinguish which active sleep_task 
    uint32 time_tick;
}quec_sleep_condition_u;

typedef struct
{
    //TelAtParserID atp_index;
    quec_sleep_bit_flag_e sleep_bit;
    quec_sleep_condition_u value;
}quec_sleep_msg_s;

typedef enum
{
    QUEC_SLEEP_INFO_TO_USB = 0,
    QUEC_SLEEP_INFO_TO_UART,
    QUEC_SLEEP_DEBUG_TASK_ENABLE,
    //QUEC_SLEEP_DEBUG_D2_INFO,
    QUEC_SLEEP_DEBUG_MAX,
}quec_sleep_log_type_e;

#define QUEC_QSCLK_SAVE_FLAG "qsclk_save_flag.cfg"

#ifdef QUEC_SLEEP_ENABLE
/*isaac-20200722 ?Têy?Y?ì2aê±??óé3sμ÷???a1s*/
#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
	#define DATATRANSMIT_DELAY_MS_TO_SLEEP   0  //Chaim 20190927 NL and XGD not need wait,ats24 can set similar value
#else
#define DATATRANSMIT_DELAY_MS_TO_SLEEP   0  //默认值(1000)一直没起作用，直接改为0与其他平台保持一致
#define DATATRANSMIT_DELAY_S_TO_SLEEP   (20) //isaac 20201127 新大陆默认20s
#endif
#endif

#ifdef QUECTEL_QSCLK2_SUPPORT
typedef enum
{
    QUEC_QSCLK_0 = 0,
    QUEC_QSCLK_1,
    QUEC_QSCLK_2,
}quec_qsclk_cmd_enum;

typedef struct{
    UINT8  sclk_cmd;    //from 0 to 2. and the default value is 0 
    UINT32 sclk_time;   //from 1 to 255, and the default value is 5 
    UINT8  sclk_dtr_flag;   //from 0 to 1, 0:enbale dtr 1:disable dtr
}quec_qsclk2_param;

typedef struct 
{
  uint8  at_param_index;
  uint8  at_param_min;
  uint32 at_param_max;
  uint8  at_param_default;
}quec_qsclk_cmd_param_s;

QuecOSStatus quec_qsclk2_cmd_msg_send(quec_qsclk2_param qsclk2_para);
void quec_qsclk_disable_rx_wakeup_reg(void);
void quec_qsclk_enable_rx_wakeup_reg(void);
#endif

#ifdef QUEC_QSCLKEX_ENABLE
#define QUEC_RRC_RELEASE_FASTER_FUNC_DISABLE   0
#define QUEC_RRC_RELEASE_FASTER_FUNC_ENABLE		1  

#define QUEC_QSCLK_EX_NO_DATA_MIN	1
#define QUEC_QSCLK_EX_NO_DATA_MAX	50
#define QUEC_QSCLK_EX_NO_DATA_DEFAULT	3

#define QUEC_QSCLK_EX_RETRY_TIME_MIN		0
#define QUEC_QSCLK_EX_RETRY_TIME_DEFAULT	30    //Chaim 20200411 unit:min
#define QUEC_QSCLK_EX_RETRY_TIME_MAX		600    //Chaim 20200411 unit:min   

#define QUEC_QSCLK_EX_CMD_PARAM_NUM_MAX  3
#define QUEC_RRC_RELEASE_FASTER_MEDCR_POSITION 34
#define QSLKEX_PUNISH_TIME_UNIT    60  //Chaim 20200822  min -->second

#define QSCLKEX_RELEASE_TIME_DISABLE   ((uint8)0)
typedef struct 
{
	bool en;
	uint8 no_data_time;
	uint16 punish_time;//如果因为异常情况的出现,快速释放RRC的功能暂停一段时间
	uint16 punish_remain_time;
	bool usb_busy_allow;
	//bool ta_ignor_allow;
	//bool w_valid;
	//bool l_valid;   //LTE qsclkex enable ?
	//bool ta_valid;
	uint8 w_release_time;
	uint8 l_release_time;
}quec_qsclk_ex_s;
	
typedef struct 
{
  uint8 at_param_index;
  uint16 at_param_min;
  uint16 at_param_max;
  uint16 at_param_default;
}quec_qsclk_ex_cmd_param_s;

typedef enum{
    QSCLKEX_EN=0,
    QSCLKEX_NO_DATA_TIME,
    QSCLKEX_PUNISH_TIME,
}quec_qsclk_param_name;

extern quec_qsclk_ex_s qsclkex_cfg;
extern quec_qsclk_ex_cmd_param_s qsclkex_cmd_param[QUEC_QSCLK_EX_CMD_PARAM_NUM_MAX];
//extern quec_qsclk_ex_s qsclkex_cfg_ci_temp;
extern QuecOSStatus quec_qsclkex_update_atcmd_param(void);
//extern QuecOSStatus quec_clear_lw_rrc_release(void);
extern UINT16 quec_qsclkex_punishtime_get(void);
extern int quec_qsclkex_punishtime_set(uint16 punish_time);
extern void quec_qsclkex_clear_punish_timer(void);
#endif





extern QuecOSStatus quec_pm_task_init(void);
extern QuecOSStatus quec_send_sleep_msg(quec_sleep_msg_s *psleep_msg);
extern QuecOSStatus quec_get_sleep_flag_bit(uint8 bit,bool *value);
extern void quec_sleep_com_port_recordtick(quec_sleep_bit_flag_e tick_flag);
extern QuecOSStatus quec_msg_queue_check(quec_queue_t queue, uint16 creat_num);
extern QuecOSStatus quec_set_sleepinfo_uart_log(uint8 value);
extern quec_sleep_log_type_e quec_get_sleepinfo_uart_log(void);
extern void quec_sleep_active_sleep_task(quec_sleep_active_flag_e active_flage);

extern void QuecPowerControlEntrance(UINT8 urc_cnt, char * p_normal_urc, UINT8 reset);
extern void quec_sleep_not_allown_sleep(void);
extern void quec_cfun_reset_wait_maxtime(void);
extern QuecOSStatus quec_qsclk_cmd_msg_send(quec_platform_sleep_flag_e sleep_flag);

#ifdef QUEC_USB_REMOTEWAKEUP_SUPPORT
QuecOSStatus quec_get_remotewakeup_flag(void);
QuecOSStatus quec_set_remotewakeup_flag(uint8 setvalue);

#endif

extern QuecOSStatus at_urc_ri_sleep_timer_start(UINT32 sleep_timeout);
extern QuecOSStatus at_urc_ri_not_allow_sleep(void);

#endif
#endif

