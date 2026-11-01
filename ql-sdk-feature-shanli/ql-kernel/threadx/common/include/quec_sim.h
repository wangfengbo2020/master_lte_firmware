/*==========================================================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
===========================================================================================================*/

/*==========================================================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
26/06/2023        Sharon.li  此文件是操作内部SIM相关的功能接口

===========================================================================================================*/


#ifndef _QUEC_SIM_H
#define _QUEC_SIM_H





//获取用户设置的插入电平。并不代表此时的实际电平值
UINT8 quec_sim_get_insert_level(void);

//获取SIM检测的状态URC是否上报,0-不上报;1-上报
uint8 quec_get_simdet_report_state(void);

//获取SIM检测功能是否使能,0-不使能;1-开启此功能
uint8 quec_get_simdet_state(void);

//获取此时SIM检测脚实际的电平值
QuecOSStatus quec_get_usim_level(quec_pin_level_value_e *p_level);

//从NV获取用户配置的SIM卡检测相关的配置，
//1、先获取SIM检测是否使能
//2、获取SIM卡插入时Pin的状态
//3、获取是否使能SIM卡检测状态上报
void quec_sim_read_simdet_config(void);

QuecOSStatus quec_simdet_report(void);


#endif

