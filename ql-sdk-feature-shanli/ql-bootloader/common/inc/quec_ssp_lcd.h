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
2022/04/26       Fias.fan    此文件用于LCD的主要驱动文件，---客户可根据硬件设计更改此文件的部分引脚
==========================================================================================================================*/
#ifndef __QUEC_SSP_LCD_H__
#define __QUEC_SSP_LCD_H__

#include "quec_startup_gpio.h"
#include "quec_lcd_application.h"

//客户需要根据硬件电路设计自行配置如下参数
//配置LCD
#define _QUEC_LCD_SSP2_ //请咨询AE/FAE

//LCD的接口类型
#define LCD_SPI_CONTROLLER_LINE       (4)
//LCD的数据线个数
#define LCD_SPI_CONTROLLER_DATA_LINE  (1)
//LCD的写时钟
#define LCD_SCLK_FREQ           (SPI_52M)
//lCD的读时钟
#define LCD_SCLK_READ_FREQ      (SPI_812_5k)

//600MCN_LA
#if defined (__QUECTEL_PROJECT_EC600MCN_LA__)|| defined (__QUECTEL_PROJECT_EC600MCN_LE__)\
	|| defined (__QUECTEL_PROJECT_EC600NCN_AC__)
//lcd-spi的clk Pin
#define LCD_SPI_CLK             (GPIO_PIN_NO_12)
//LCD的片选Pin,OutPot
#define LCD_SPI_CS              (GPIO_PIN_NO_13)
//LCD的数据和命令选择Pin,OutPut,拉低为发送Cmd,拉高为发送Data[只有接口类型为4线时,才有此Pin功能]
#define LCD_SPI_RS              (GPIO_PIN_NO_14)
//LCD的数据Pin(双向pin)，用于数据输出和输入
#define LCD_SPI_DOUT            (GPIO_PIN_NO_15)
//LCD的复位引脚，OutPut
#define LCD_RST_PIN             (GPIO_PIN_NO_50)
//LCD的帧中断Pin,IntPut(中断)
#define LCD_TE_PIN              (GPIO_PIN_NO_28)
//LCD的背光引脚(PWM or GPIO)
#define LCD_BACK_LIGHT          (GPIO_PIN_NO_7)

//800MCN_XX
#elif defined (__QUECTEL_PROJECT_EC800MCN_XX__)	||defined (__QUECTEL_PROJECT_EG810MCN_GA__)\
	|| defined (__QUECTEL_PROJECT_EG810MCN_LA__) || defined (__QUECTEL_PROJECT_EG810MEU_LA__)\
	|| defined (__QUECTEL_PROJECT_EG810MCN_GB__) || defined (__QUECTEL_PROJECT_EG810MEU_LC__)\
	|| defined (__QUECTEL_PROJECT_EG810MLA_LC__)
//lcd-spi的clk Pin
#define LCD_SPI_CLK             (GPIO_PIN_NO_33)
//LCD的片选Pin,OutPot
#define LCD_SPI_CS              (GPIO_PIN_NO_34)
//LCD的数据和命令选择Pin,OutPut,拉低为发送Cmd,拉高为发送Data[只有接口类型为4线时,才有此Pin功能]
#define LCD_SPI_RS              (GPIO_PIN_NO_35)
//LCD的数据Pin(双向pin)，用于数据输出和输入
#define LCD_SPI_DOUT            (GPIO_PIN_NO_36)
//LCD的复位引脚，OutPut
#define LCD_RST_PIN             (GPIO_PIN_NO_32)
//LCD的帧中断Pin,IntPut(中断)
#define LCD_TE_PIN              (GPIO_PIN_NO_7)
//LCD的背光引脚(PWM or GPIO)
#define LCD_BACK_LIGHT          (GPIO_PIN_NO_8)
#else


#endif

#define LCDLOGE CP_LOGW
#define LCDLOGW CP_LOGW
#define LCDLOGI CP_LOGW
#define LCDLOGD CP_LOGW

enum
{
	LCD_CAP_NORMAL = 0,
	LCD_CAP_FAKE = 1, /*virtal panel*/
	LCD_CAP_POWERON = 2,
	LCD_CAP_NOTE = 4, /*has no te signal*/
	LCD_CAP_LIMIT
};

enum
{
	LCD_MODE_MCU = 0,
	LCD_MODE_SPI = 1,
	LCD_MODE_LIMIT
};

enum
{
	LCD_POLARITY_POS = 0,
	LCD_POLARITY_NEG,
	LCD_POLARITY_LIMIT
};


//LCD控制器的状态
enum
{
	LCD_STATUS_POWEROFF,
	LCD_STATUS_POWERON,
	LCD_STATUS_HWON,
	LCD_STATUS_ASSERTON,
	LCD_STATUS_SLEEP,
	LCD_STATUS_LIMIT
};

//LCD控制器SPI的工作模式
enum
{
	LCD_WORK_MODE_POLLING,
	LCD_WORK_MODE_ASS_POLLING,
	LCD_WORK_MODE_INTERRUPT,
	LCD_WORK_MODE_LIMIT
};




/* LCD operations */
struct panel_operations {
	int (*panel_interface_init)(struct panel_spec *self, uint32_t sclk, int32_t work_mode);
	int (*panel_interface_update)(struct panel_spec *self, int32_t work_mode);
	int (*panel_init)(struct panel_spec *self);
	int (*panel_invalid)(struct panel_spec *self, uint32_t start_x,
						uint32_t start_y,  uint32_t end_x, uint32_t end_y);
	int (*panel_suspend)(struct panel_spec *self);
	int (*panel_resume)(struct panel_spec *self);
	unsigned int (*panel_readid)(struct panel_spec *self);
};


/* LCD abstraction */
struct panel_spec {
	char name[32];
	unsigned int panel_id;
	unsigned int cap;
	unsigned short width;  //short
	unsigned short height; // short
	unsigned short interf; /*mcu, spi, mipi*/ //short
	unsigned short type; /*rgb, fstn*/
	struct spi_info *info;
	void *panel_if;
	struct panel_operations *ops;
};

struct asrlcdd_framebuffer_info{
	void* pbuffer;
	unsigned int height;
	unsigned int stride;
	unsigned int bitdepth;
};

struct asrlcdd_roi_info{
	int startX;
	int startY;
	unsigned short width;
	unsigned short height;
};

struct asrlcdd_framebuffer_window{
	struct asrlcdd_framebuffer_info frame_info;
	struct asrlcdd_roi_info roi_info;
};


struct quec_lcd_driver{
    struct panel_spec *quec_panel_spec;
    int (*lcd_panel_init)(struct panel_spec *self);
};

#endif

