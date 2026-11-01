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
2022/04/26       Fias.fan    此文件用于LCD的应用层文件，客户可自行修改，通过调用LCD的驱动API，实现显示逻辑
==========================================================================================================================*/
#ifndef __QUEC_LCD_APP_H__
#define __QUEC_LCD_APP_H__

/**
 * Note: If battery value is not more than "BATTERY_LOW_THRESHOLD", not display logo.
 * Note: When battery value is less than 2900 mv, software can not run.
 */
#define BATTERY_LOW_THRESHOLD (3000)
#define BATTERY_HIGH_VALUE	  (3400)

/**
 * BackLight Brightness Level
 * Range [ 0 - 5]: 	0  --- off
 */
#define Normal_BackLight_Brightness_Level		(3)
#define LowerBattery_BackLight_Brightness_Level	(1)

#define   BLACK     0x0000       //   黑色    
#define   NAVY      0x000F      //    深蓝色  
#define   DGREEN    0x03E0        //  深绿色  
#define   DCYAN     0x03EF       //   深青色  
#define   MAROON    0x7800       //   深红色      
#define   PURPLE    0x780F       //   紫色  
#define   OLIVE     0x7BE0       //   橄榄绿      
#define   LGRAY     0xC618        //  灰白色
#define   DGRAY     0x7BEF        //  深灰色      
#define   BLUE      0x001F        //  蓝色    
#define   GREEN     0x07E0        //  绿色          
#define   CYAN      0x07FF        //  青色  
#define   RED       0xF800        //  红色       
#define   MAGENTA   0xF81F        //  品红    
#define   YELLOW    0xFFE0        //  黄色        
#define   WHITE     0xFFFF        //  白色  

/**
 * Note: LCD测试，需要打开下面QUEC_LCD_SHOWIMAGE_TEST宏
 * Note: 同时打开对应的项目宏
 */
//#define QUEC_LCD_SHOWIMAGE_TEST

//#define __QUECTEL_PROJECT_EC600MCN_LA__
#define __QUECTEL_PROJECT_EC800MCN_XX__

void POWER_ON_LCD_ShowImage(void);


#endif	// __QUEC_LCD_APP_H__

