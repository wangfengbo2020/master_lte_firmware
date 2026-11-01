/**
 ******************************************************************************
 * @file    quec_gpio.h
 * @author  Chavis.Chen
 * @version V1.0.0
 * @date    26-Sep-2018
 * @brief   This file contains the common definitions, macros and functions to
 *          be shared throughout the project.
 ******************************************************************************
 *
 *  The MIT License
 *  Copyright (c) 2014 QUECTEL Inc.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is furnished
 *  to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ******************************************************************************
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
10/11/2018		  Chaim	     Init version
04/16/2022        Sharon.li  整理不同项目需要配置的引脚
=================================================================*/


#ifndef _QUEC_GPIO_H
#define _QUEC_GPIO_H

#include "mfpr_api.h"
#include "gpio.h"
#include "cgpio.h"
#include "gpio_config.h"
#include "Gpio_Hw.h"
#include "cgpio_HW.h"
#include "quec_include.h"
#include "quec_board_common.h"
#include "quec_include.h"
#include "quec_board_common.h"
#include "quec_msg_process.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO_TOTAL_INTERRUPT_REG  (0XD4282000+55*4)

//Chaim 2018.11.22 mfpr register edge_clear bit
#define QUEC_MFPR_REG_EDGE_CLEAR_SHIFT    6

//chaim 2018.10.24 gpio log enable
//#define QUEC_GPIO_LOG_ENABLE


#ifdef QUEC_CUSTOM_LAST_GASP_FEATURE
#define QUEC_LAST_GASP_TRIGGER_GPIO                 (GPIO_PIN_36)  // trigger
#endif

#if QUEC_AT_QGPIOEXT_SUPPORT
typedef enum quec_gpio_function
{
	GPIO_FUNC_NONE = 0,       //default function
	GPIO_FUNC_PA_CTL = 1,     //support for PA control
	GPIO_FUNC_OPTIONAL = 2,   //for further using
	GPIO_FUNC_MAX = 3         //the max function num
}quec_gpio_func_t;
#endif

typedef enum 
{
	QUEC_GPIO_DISABLED = QUEC_DISABLE,
	QUEC_GPIO_ENABLED = QUEC_ENABLE
} quec_gpio_state;

typedef enum 
{
	QUEC_GPIO_DRV_LEVEL_VERY_SLOW = 0,	//DRV_VERY_SLOW_C
	QUEC_GPIO_DRV_LEVEL_SLOW ,	//DRV_SLOW_C
	QUEC_GPIO_DRV_LEVEL_MED,		//DRV_MED_C
	QUEC_GPIO_DRV_LEVEL_FAST		//DRV_FAST_C
} quec_gpio_drv_level;


#define QUEC_GENUS_DEBOUNCE_INTERVAL_MS  200
#define QUEC_GENUS_DEBOUNCE_INTERVAL_COUNT  5

#ifdef QUEC_SLEEP_AP_READY
#define QUEC_GPIO_APREADY_DEBOUNCE_INTERVAL_MS   10
#define QUEC_GPIO_APREADY_DEBOUNCE_INTERVAL_COUNT   2
#endif

#define QUEC_GPIO_DEBOUNCE_INTERVAL_MS   10
#define QUEC_GPIO_DEBOUNCE_INTERVAL_COUNT   2


typedef struct
{
    GPIO_PinNumbers pin_num;
    quec_timer_t timerRef;
    uint16 interval_time;   //ms        //每次消抖的时间
    uint8 interval_count;               //需要消抖的次数
    quec_pin_level_value_e last_level;  //last level ，
    quec_pin_level_value_e interrupt_level;//记录产生中断时的电平状态
    quec_pin_level_value_e interrupt_happen_count;//记录中断发生的次数
    void  (*callBackTimerHandler)(void);
}quec_gpio_debounce_s;

#ifndef QUEC_AIR_PLANE_CTRL_ENABLE
    #ifdef QUEC_SLEEP_AP_READY
	    #define QUEC_DEBOUNCE_GPIO_NUM    4
	#else
        #define QUEC_DEBOUNCE_GPIO_NUM    3
	#endif
#else
    #ifdef QUEC_SLEEP_AP_READY
	    #define QUEC_DEBOUNCE_GPIO_NUM    5
	#else
        #define QUEC_DEBOUNCE_GPIO_NUM    4
	#endif
#endif

typedef enum 
{
    USIM_DEBOUNCE =0,
    DTR_DEBOUNCE,
    CTS_DEBOUNCE,
    AIR_PLAN_DEBOUNCE,
#ifdef QUEC_SLEEP_AP_READY
    APREADY_DEBOUNCE,
#endif
    WAKEUP_IN_DEBOUNCE,
    MAX_DEBOUNCE
}quec_pin_debounce_e;

#define QUEC_DEBOUNCE_TIME_OUT_MIN  5 
#define QUEC_DEBOUNCE_TIME_OUT_MAX  65535 

#define QUEC_DEBOUNCE_COUNT_MIN  0 
#define QUEC_DEBOUNCE_COUNT_MAX  255 

#ifdef QUEC_SLEEP_AP_READY
#define  APREADY_DISABLE_FLAG         0
#define  APREADY_ENABLE_FLAG          1
#define  APREADY_LEVEL_LOW_ACTION     3
#define  APREADY_LEVEL_HIGH_ACTION    4
#endif

typedef struct
{
    uint16 time_out;
    uint16 count;
}quec_debounce_param_s;
typedef struct
{
    quec_pin_debounce_e  pin_usage;    
    quec_debounce_param_s debounce_param;
}quec_gpio_debounce_param_s;


typedef struct
{
   GPIO_PinConfiguration config;  
   unsigned long mfprReg_data;
    void (*GPIOCallback)(void);
}quec_pin_config_s;


extern  GPIO_PinConfiguration gpio_output_dvl;

#ifdef QUEC_AIR_PLANE_CTRL_ENABLE
extern OS_HISR air_plane_pin_hisr;
#endif

extern uint8 g_inter_log;

#define interrupt_log(msg,...)   if(TRUE == g_inter_log)                            \
                                 {                                                  \
                                     custom_log("DEBOUNCE",msg,##__VA_ARGS__);     \
                                 }                                                  \

extern QuecOSStatus quec_set_interrupt_log(bool en);
extern bool quec_get_interrupt_log(void);

extern QuecOSStatus quec_set_gpio_mfprReg(GPIO_PinNumbers pin_num,unsigned long mfprReg_data );

extern QuecOSStatus quec_gpio_get_mfprReg(GPIO_PinNumbers pin_num, unsigned long *p_mfprReg_data);

extern QuecOSStatus quec_gpio_init(quec_pin_config_s *pin_config);
extern QuecOSStatus quec_set_gpio_level(GPIO_PinNumbers pin_num,quec_pin_level_value_e pin_level);

extern QuecOSStatus quec_get_gpio_level(GPIO_PinNumbers pin_num,quec_pin_level_value_e *p_level);

extern QuecOSStatus quec_gpio_cust_init(void);

extern QuecOSStatus quec_gpio_config_set(GPIO_PinConfiguration pin_config[]);

extern QuecOSStatus quec_gpio_get_GPIOReg(GPIO_PinNumbers pin_num, GPIORegisters * gpioRegister);

//extern QuecOSStatus quec_usim_presence_level_process(quec_pin_level_value_e *plevel);
extern QuecOSStatus quec_usim_presence_interrupt_pin_init(void);
extern QuecOSStatus quec_get_usim_level(quec_pin_level_value_e *p_level);

extern QuecOSStatus quec_gpio_debounce_init(quec_gpio_debounce_s *pregister_debounce);
extern QuecOSStatus quec_gpio_interrupt_debounce_handler(quec_gpio_debounce_s *pregister_debounce);
extern QuecOSStatus quec_gpio_debounce_timer_handler(quec_gpio_debounce_s *pregister_debounce);

#if (QUEC_ASR_SIM_HOT_PLUG_SUPPORT ==1)

typedef struct
{
    uint8 sim_det_enable;    //0--disable,1--enable       //保存用户配置的是否使能检测
    uint8 sim_insert_level;   //0--low level,1--high level//保存用户设置的插入电平
    uint8 sim_report_enable;  // sim report enable /disable//保存用户配置的是否状态上报URC
}quec_usim_det_stat_s;
extern quec_usim_det_stat_s   g_usim_det_stat;

extern QuecOSStatus quec_usim_plug_handle(quec_msg_process_s *pmsg_set);
#endif

#ifdef QUEC_AIR_PLANE_CTRL_ENABLE
QuecOSStatus quec_air_plane_pin_process(quec_msg_process_s *pmsg_set);
QuecOSStatus quec_air_plane_pin_init(void);
QuecOSStatus quec_air_plane_pin_level_get(quec_pin_level_value_e *p_level);
#endif

extern int quec_get_lcc_index(int lcc_num);
extern QuecOSStatus quec_reconfig_gpio(int llc_num, int pin_num);

extern QuecOSStatus quec_debounce_timer_read(void);
extern QuecOSStatus quec_debounce_timer_get(quec_gpio_debounce_param_s *p_debounce);
extern QuecOSStatus quec_debounce_timer_set(quec_gpio_debounce_param_s *p_debounce);
extern QuecOSStatus quec_write_usim_presence_sclk_cfg(uint8 set_value);
extern uint8  quec_get_usim_presence_sclk_cfg(void);
extern QuecOSStatus quec_gpio_cust_config(void);

//destin 2020.09.24 add for "AT+QCFG="csqgpiodisp"
#ifdef QUEC_CSQ_GPIO_DISPLAY_ENABLE
extern QuecOSStatus quec_csq_gpio_display_deinit(void);
extern void quec_csq_gpio_display_state(void);
#endif

#if QUEC_QSLEEP_IND_CTL
extern void quec_sleep_ind_light(void);
extern void quec_sleep_ind_dark(void);
#endif

#ifdef QUEC_SLEEP_AP_READY
void quec_apready_init(void);
#endif

typedef struct{
uint8  detction_level;
uint8  enbale_flag;
uint8  urc_enable;
}quec_wakeup_in_cfg_t;
void quec_wakeup_in_init(void);
BOOL quec_wakeupin_pin_is_trig(void);
extern quec_wakeup_in_cfg_t wakeup_in_cfg;
void quec_ri_pin_init(void);

#if defined(__QUEC_OEM_VER_WUS__)
BOOL quec_wussrc4_pin_is_trig(void);
#endif

#ifdef __cplusplus
} /*"C" */ 
#endif

#endif

