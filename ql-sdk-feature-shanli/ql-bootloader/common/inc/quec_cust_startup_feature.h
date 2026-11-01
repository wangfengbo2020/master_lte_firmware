/*========================================================================================================================
  Copyright (c) 2022 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
========================================================================================================================*/
/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
2022/04/26       Sharon.li   此文件用于控制启动阶段(boot阶段,logo阶段)一些功能的开启与关闭
==========================================================================================================================*/


#ifndef __QUEC_CUST_STARTIP_FEATURE_H__
#define __QUEC_CUST_STARTIP_FEATURE_H__


#define QUEC_NO_USE_ASR_CODE


#ifdef QUECTEL_OPEN_CPU

#define QUEC_LCD_USR_FOR_LOGO     //是否在logo中加入LCD的代码编译







#else //标准项目编译需要的功能

//#define QUEC_STARTUP_OPTIMIZATION //开机加速,缩短开机时间







#endif /*QUECTEL_OPEN_CPU*/
#endif

