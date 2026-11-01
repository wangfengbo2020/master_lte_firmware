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
#include "bsp.h"
#include <ui_os_api.h>
#include "quec_spi_drv.h"
#include "plat_types.h"
#include "quec_ssp_lcd.h"

struct panel_spec *g_ppanel = NULL;
int g_lcd_status = LCD_STATUS_POWEROFF;

//Todo..........需要客户根据硬件设计自行实现

//LCD电源域控制
void quec_lcd_power_ctrl(bool onoff)
{
	LCDLOGD("quec_lcd_power_ctrl(%d) ++\r\n",onoff);
	
//2>电源VDD&IOVDD上电，供电
	if (PMIC_IS_PM803()) //ASR-1606-QUECTEL-ECxxxM系列
	{
		if(onoff)
		{
			//GuilinLite_Ldo_6_set_2_8();	
			//GuilinLite_Ldo_6_set(1);
		}
		else
		{
			//GuilinLite_Ldo_6_set(0);
		}
	} 
	LCDLOGD("quec_lcd_power_on --\r\n");	
}

//此延时函数，用于LCD-spi相关的延时
static __inline void uudelay(int us)
{
 volatile uint32_t i;
 for(i=0; i<us*100;i++)
  i = i+1;
}

static __inline void mdelay(int ms){
 volatile uint32_t i;
 for(i=0; i<ms;i++)
  uudelay(10);
}

//Panel初始化和SPI 初始化
static int quec_lcd_panel_spi_init(struct panel_spec *self, uint32_t sclk, int32_t work_mode)
{
	struct s_spi_ctx *spi_ctx = NULL;
	struct spi_info * spi = NULL;
	LCDLOGI("INFO: lcd_panel_spi_init, spi+++\r\n");
	if (NULL == self) 
	{
		LCDLOGE("ERROR: panel_interface_init, Invalid param\r\n");
		return -1;
	}
	spi = (struct spi_info *)self->info;
	
	quec_lcd_brightness_init(LCD_BACK_LIGHT);//背光初始化
	quec_lcd_rst_init(LCD_RST_PIN);//复位引脚初始化
	if(spi->line_num == 4)//如果是4线LCD，需要进行RS引脚初始化
	{
		quec_lcd_rs_init(LCD_SPI_RS);
	}

	spi_ctx = spi_init(sclk, spi, work_mode);
	if (NULL == spi_ctx){
		LCDLOGE("ERROR: panel_interface_init, spi init fail!\r\n");
		return -1;
	}
	self->panel_if = (void*)spi_ctx;
	quec_lcd_power_ctrl(1);
	g_lcd_status = LCD_STATUS_HWON;

	return 0;
}

int quec_lcd_panel_spi_uninit(struct panel_spec *self)
{
	struct s_spi_ctx *spi_ctx = NULL;

	LCDLOGD("DBG: lcd_panel_interface_uninit, spi+++\r\n");
    if(CHIP_IS_CRANEM)
    {
    	if(NULL == self){
    		LCDLOGE("ERROR: lcd_panel_interface_uninit, Invalid param\r\n");
    		return -1;
    	}

    	spi_ctx = (struct s_spi_ctx*)self->panel_if;
    	spi_uninit(spi_ctx);
    	self->panel_if = NULL;
    }
	
	quec_lcd_power_ctrl(0);
	g_lcd_status = LCD_STATUS_POWEROFF;
	LCDLOGD("DBG: lcd_panel_interface_uninit, spi---\r\n");

	return 0;
}

static int quec_lcd_panel_spi_update(struct panel_spec *self, int32_t work_mode)
{
	int ret=0;
	struct s_spi_ctx* spi_ctx = NULL;

	if (NULL == self || NULL == self->panel_if) {
		LCDLOGE("ERROR: lcd_panel_interface_update, Invalid param\r\n");
		return -1;
	}
	ret = spi_update((struct s_spi_ctx *)self->panel_if, work_mode);
	return ret;
}

//刷屏函数
void quec_lcd_panel_refresh(struct panel_spec *self,struct asrlcdd_framebuffer_window *frame_window,uint16_t startX, uint16_t startY)
{
	struct s_spi_ctx* spi_ctx = NULL;
	struct spi_info * spi = NULL;
    unsigned int size = 0;
    unsigned short *addr = NULL;
    struct asrlcdd_roi_info *src_roi_info = NULL;
    struct asrlcdd_framebuffer_info *src_frame_buffer = NULL;
	
    //LCDLOGD("++++++\r\n");
	
	if (NULL == self) {
		LCDLOGE("ERROR: panel_init, Invalid param\r\n");
		return;
	}
	
	if (NULL == self->panel_if)
	{
		LCDLOGE("ERROR: panel_init, mcu has not been inited!\r\n");
		return;
	}
	
	src_roi_info = &(frame_window->roi_info);
    src_frame_buffer = &(frame_window->frame_info);
	spi_ctx = (struct s_spi_ctx*)self->panel_if;
	spi = (struct spi_info *)self->info;
    size = (src_roi_info->height)*(src_roi_info->width);
	
    addr = (unsigned short *)src_frame_buffer->pbuffer;
	
    if(self->ops->panel_invalid) //pony add 2021-2-7 刷图位置，，设置LCD的起始坐标和结束坐标
    	self->ops->panel_invalid(self,startX,startY,src_roi_info->width+startX-1,src_roi_info->height+startY-1);
    else 
    	printf("panel_invalid not init\r\n");
	
	if(spi->line_num ==4)
	{
		quec_gpio_set_output(LCD_SPI_RS);
		quec_gpio_set_value(LCD_SPI_RS, 1);
	}
	spi_set_clk_rate(SPI_26M);
	
    quec_gpio_set_output(LCD_SPI_CS); //cs
    quec_gpio_set_value(LCD_SPI_CS, 0);
	
	ssp_write_data_to_LCD_Gram(addr,size,16,spi->line_num);//
	wait_ssp_write_data_to_LCD_complete();//等待spi tx fifo 为空
		
    quec_gpio_set_value(LCD_SPI_CS, 1);
	
    //LCDLOGD("------\r\n");
}
//读取ID
static unsigned int quec_lcd_panel_readid(struct panel_spec *self)
{
	struct s_spi_ctx* spi_ctx = NULL;
    uint32_t read_id = 0;

	if (NULL == self){
		LCDLOGE("ERROR: panel_readid, Invalid param\r\n");
		return 0;
	}

	if (NULL == self->panel_if) {
		LCDLOGE("ERROR: panel_readid, spi has not been inited!\r\n");
		//return 0;
	}

	spi_ctx = (struct s_spi_ctx*)self->panel_if;
	
     if(CHIP_IS_CRANEM || CHIP_IS_CRANEL)//ASR-1606&1603
     {
         quec_gpio_set_output(LCD_RST_PIN); //rst
         mdelay(20);
         quec_gpio_set_value(LCD_RST_PIN, 0);
         mdelay(20);
         quec_gpio_set_value(LCD_RST_PIN, 1);
         mdelay(120);
     }


	spi_read_data(spi_ctx, 0xDA, 8, &read_id, 8);

	LCDLOGI("INFO: panel_readid, read 0xDA receive 0x%x!\r\n",read_id);

	spi_read_data(spi_ctx, 0xDB, 8, &read_id, 8);

	LCDLOGI("INFO: panel_readid, read 0xDB receive 0x%x!\r\n",read_id);

	spi_read_data(spi_ctx, 0xDC, 8, &read_id, 8);
    
	LCDLOGI("INFO: panel_readid, read 0xDC receive 0x%x!\r\n",read_id);


	spi_read_data(spi_ctx, 0x04, 8, &read_id, 24);

	/*read status*/
	//spi_read_data(spi_ctx, 0x09, 8, &read_id, 32);
	//LCDLOGI("INFO: panel_readid, read 0x09 receive 0x%x!\r\n", read_id);

    return read_id;
}

static int quec_lcd_panel_display_on(struct panel_spec *self)
{
	struct s_spi_ctx* spi_ctx = NULL;
	LCDLOGI("INFO: lcd_panel_display_on +++\r\n");

	if (NULL == self ){
		LCDLOGE("ERROR: lcd_panel_display_on, Invalid param\r\n");
		return -1;
	}

	if (NULL == self->panel_if) {
		LCDLOGE("ERROR: lcd_panel_display_on, mcu has not been inited!\r\n");
		return -1;
	}

	spi_ctx = (struct s_spi_ctx*)self->panel_if;

	spi_write_cmd(spi_ctx, 0x11, 8);
	mdelay(120);
	spi_write_cmd(spi_ctx, 0x29, 8);
	mdelay(20);

    return 0;
}

static int quec_lcd_panel_display_off(struct panel_spec *self)
{
	struct s_spi_ctx* spi_ctx = NULL;
	LCDLOGI("INFO: lcd_panel_display_off +++\r\n");

	if (NULL == self ){
		LCDLOGE("ERROR: lcd_panel_display_off, Invalid param\r\n");
		return -1;
	}

	if (NULL == self->panel_if) {
		LCDLOGE("ERROR: lcd_panel_display_off, mcu has not been inited!\r\n");
		return -1;
	}

	spi_ctx = (struct s_spi_ctx*)self->panel_if;

	spi_write_cmd(spi_ctx, 0x28, 8);
	mdelay(20);
	spi_write_cmd(spi_ctx, 0x10, 8);
	mdelay(120);

    return 0;
}


static int quec_lcd_panel_invalid(struct panel_spec *self, uint32_t start_x,
	uint32_t start_y,  uint32_t end_x, uint32_t end_y)
{
	struct s_spi_ctx* spi_ctx = NULL;

	if (NULL == self){
		LCDLOGE("ERROR: panel_init, Invalid param\r\n");
		return -1;
	}

	if (NULL == self->panel_if){
		LCDLOGE("ERROR: panel_init, mcu has not been inited!\r\n");
		return -1;
	}
    
	spi_ctx = (struct s_spi_ctx*)self->panel_if;
	spi_write_cmd(spi_ctx, 0x2A, 8);
	spi_write_data(spi_ctx, ((start_x >> 8) & 0xFF), 8);
	spi_write_data(spi_ctx, (start_x & 0xFF), 8);
	spi_write_data(spi_ctx, ((end_x >> 8) & 0xFF), 8);
	spi_write_data(spi_ctx, (end_x & 0xFF), 8);

	spi_write_cmd(spi_ctx, 0x2B, 8);
	spi_write_data(spi_ctx, ((start_y >> 8) & 0xFF), 8);
	spi_write_data(spi_ctx, (start_y & 0xFF), 8);
	spi_write_data(spi_ctx, ((end_y >> 8) & 0xFF), 8);
	spi_write_data(spi_ctx, (end_y & 0xFF), 8);

	spi_write_cmd(spi_ctx, 0x2C, 8);

	return 0;
}

static struct panel_operations quec_spi_ops = {
	quec_lcd_panel_spi_init,
	quec_lcd_panel_spi_update,
	NULL,
	quec_lcd_panel_invalid,
	quec_lcd_panel_display_off,
	quec_lcd_panel_display_on,
	quec_lcd_panel_readid,
};


void lcd_7789v_lcd_panel_init(struct panel_spec *self)
{
	struct s_spi_ctx* spi_ctx = NULL;

	LCDLOGE("lcd_panel_init_for_7789v\r\n");
	if (NULL == self) {
		LCDLOGE("ERROR: panel_init, Invalid param\r\n");
		return -1;
	}

	if (NULL == self->panel_if) {
		LCDLOGE("ERROR: panel_init, mcu has not been inited!\r\n");
		return -1;
	}

	spi_ctx = (struct s_spi_ctx*)self->panel_if;
    //mdelay(120);                
	spi_write_cmd(spi_ctx, 0x11, 8);     
	mdelay(120);
    spi_write_cmd(spi_ctx,0x3A, 8);
    spi_write_data(spi_ctx,0x05, 8);	
    spi_write_cmd(spi_ctx,0x35, 8);
    spi_write_data(spi_ctx,0x00, 8);
    spi_write_cmd(spi_ctx,0x36, 8); //此处放的太靠前会导致横竖屏设置失败 pony add 2021-06-02 
#if 1  //横屏
	spi_write_data(spi_ctx,0xa0, 8); 
#else
    spi_write_data(spi_ctx,0x00, 8);
#endif
    spi_write_cmd(spi_ctx,0x44, 8);
    spi_write_data(spi_ctx,0x00, 8);
    spi_write_data(spi_ctx,0x1f, 8);	
    spi_write_cmd(spi_ctx,0xB2, 8);
    spi_write_data(spi_ctx,0x0c, 8);		
    spi_write_data(spi_ctx,0x0c, 8);		
    spi_write_data(spi_ctx,0x00, 8);		
    spi_write_data(spi_ctx,0x33, 8);		
    spi_write_data(spi_ctx,0x33, 8);			
    spi_write_cmd(spi_ctx,0xB7, 8);
    spi_write_data(spi_ctx,0x30, 8);		
    spi_write_cmd(spi_ctx,0xBB, 8);
    spi_write_data(spi_ctx,0x34, 8);			
    spi_write_cmd(spi_ctx,0xC0, 8);
    spi_write_data(spi_ctx,0x2C, 8);		
    spi_write_cmd(spi_ctx,0xC2, 8);
    spi_write_data(spi_ctx,0x01, 8);		
    spi_write_cmd(spi_ctx,0xC3, 8);
    spi_write_data(spi_ctx,0x17, 8);		
    spi_write_cmd(spi_ctx,0xC4, 8);
    spi_write_data(spi_ctx,0x20, 8);
    spi_write_cmd(spi_ctx,0xC6, 8);
    //spi_write_data(spi_ctx,0x18, 8);
    spi_write_data(spi_ctx,0x0F, 8);
    spi_write_cmd(spi_ctx,0xD0, 8);
    spi_write_data(spi_ctx,0xA4, 8);
    spi_write_data(spi_ctx,0xA1, 8);
    spi_write_cmd(spi_ctx,0xE9, 8);
    spi_write_data(spi_ctx,0x0E, 8);
    spi_write_data(spi_ctx,0x0E, 8);
    spi_write_data(spi_ctx,0x04, 8);
    spi_write_cmd(spi_ctx,0xE0, 8);
    spi_write_data(spi_ctx,0xD0, 8);
    spi_write_data(spi_ctx,0x01, 8);
    spi_write_data(spi_ctx,0x09, 8);	
    spi_write_data(spi_ctx,0x10, 8);
    spi_write_data(spi_ctx,0x11, 8);
    spi_write_data(spi_ctx,0x0B, 8);		
    spi_write_data(spi_ctx,0x39, 8);
    spi_write_data(spi_ctx,0x54, 8);		
    spi_write_data(spi_ctx,0x47, 8);
    spi_write_data(spi_ctx,0x3A, 8);		
    spi_write_data(spi_ctx,0x17, 8);
    spi_write_data(spi_ctx,0x11, 8);			
    spi_write_data(spi_ctx,0x20, 8);
    spi_write_data(spi_ctx,0x23, 8);		
    spi_write_cmd(spi_ctx,0xE1, 8);
    spi_write_data(spi_ctx,0xD0, 8);
    spi_write_data(spi_ctx,0x01, 8);
    spi_write_data(spi_ctx,0x04, 8);	
    spi_write_data(spi_ctx,0x0B, 8);
    spi_write_data(spi_ctx,0x0D, 8);
    spi_write_data(spi_ctx,0x18, 8);		
    spi_write_data(spi_ctx,0x35, 8);
    spi_write_data(spi_ctx,0x44, 8);		
    spi_write_data(spi_ctx,0x49, 8);
    spi_write_data(spi_ctx,0x2B, 8);		
    spi_write_data(spi_ctx,0x15, 8);
    spi_write_data(spi_ctx,0x19, 8);			
    spi_write_data(spi_ctx,0x14, 8);
    spi_write_data(spi_ctx,0x17, 8);		
    spi_write_cmd(spi_ctx,0xE2, 8);
    spi_write_data(spi_ctx,0x00, 8);
    spi_write_data(spi_ctx,0x04, 8);
    spi_write_data(spi_ctx,0x08, 8);	
    spi_write_data(spi_ctx,0x0C, 8);
    spi_write_data(spi_ctx,0x10, 8);
    spi_write_data(spi_ctx,0x14, 8);		
    spi_write_data(spi_ctx,0x18, 8);
    spi_write_data(spi_ctx,0x1C, 8);		
    spi_write_data(spi_ctx,0x20, 8);
    spi_write_data(spi_ctx,0x24, 8);		
    spi_write_data(spi_ctx,0x28, 8);
    spi_write_data(spi_ctx,0x2C, 8);			
    spi_write_data(spi_ctx,0x30, 8);
    spi_write_data(spi_ctx,0x34, 8);	
    spi_write_data(spi_ctx,0x38, 8);	
    spi_write_data(spi_ctx,0x3C, 8);
    spi_write_data(spi_ctx,0x40, 8);
    spi_write_data(spi_ctx,0x44, 8);		
    spi_write_data(spi_ctx,0x48, 8);
    spi_write_data(spi_ctx,0x4C, 8);		
    spi_write_data(spi_ctx,0x50, 8);
    spi_write_data(spi_ctx,0x54, 8);		
    spi_write_data(spi_ctx,0x58, 8);
    spi_write_data(spi_ctx,0x5C, 8);			
    spi_write_data(spi_ctx,0x60, 8);
    spi_write_data(spi_ctx,0x64, 8);	
    spi_write_data(spi_ctx,0x68, 8);	
    spi_write_data(spi_ctx,0x6C, 8);
    spi_write_data(spi_ctx,0x70, 8);
    spi_write_data(spi_ctx,0x74, 8);	
    spi_write_data(spi_ctx,0x78, 8);	
    spi_write_data(spi_ctx,0x7C, 8);
    spi_write_data(spi_ctx,0x80, 8);
    spi_write_data(spi_ctx,0x84, 8);		
    spi_write_data(spi_ctx,0x88, 8);
    spi_write_data(spi_ctx,0x8C, 8);		
    spi_write_data(spi_ctx,0x90, 8);
    spi_write_data(spi_ctx,0x94, 8);		
    spi_write_data(spi_ctx,0x98, 8);
    spi_write_data(spi_ctx,0x9C, 8);			
    spi_write_data(spi_ctx,0xA0, 8);
    spi_write_data(spi_ctx,0xA4, 8);	
    spi_write_data(spi_ctx,0xA8, 8);	
    spi_write_data(spi_ctx,0xAC, 8);	
    spi_write_data(spi_ctx,0xB0, 8);
    spi_write_data(spi_ctx,0xB4, 8);	
    spi_write_data(spi_ctx,0xB8, 8);	
    spi_write_data(spi_ctx,0xBC, 8);
    spi_write_data(spi_ctx,0xC0, 8);
    spi_write_data(spi_ctx,0xC4, 8);	
    spi_write_data(spi_ctx,0xC8, 8);	
    spi_write_data(spi_ctx,0xCC, 8);
    spi_write_data(spi_ctx,0xD0, 8);
    spi_write_data(spi_ctx,0xD4, 8);		
    spi_write_data(spi_ctx,0xD8, 8);
    spi_write_data(spi_ctx,0xDC, 8);		
    spi_write_data(spi_ctx,0xE0, 8);
    spi_write_data(spi_ctx,0xE4, 8);		
    spi_write_data(spi_ctx,0xE8, 8);
    spi_write_data(spi_ctx,0xEC, 8);			
    spi_write_data(spi_ctx,0xF0, 8);
    spi_write_data(spi_ctx,0xF4, 8);	
    spi_write_data(spi_ctx,0xF8, 8);	
    spi_write_data(spi_ctx,0xFC, 8);	
    spi_write_cmd(spi_ctx,0xE3, 8);
    spi_write_data(spi_ctx,0x00, 8);
    spi_write_data(spi_ctx,0x04, 8);
    spi_write_data(spi_ctx,0x07, 8);	
    spi_write_data(spi_ctx,0x0A, 8);
    spi_write_data(spi_ctx,0x0E, 8);
    spi_write_data(spi_ctx,0x12, 8);		
    spi_write_data(spi_ctx,0x16, 8);
    spi_write_data(spi_ctx,0x19, 8);		
    spi_write_data(spi_ctx,0x1C, 8);
    spi_write_data(spi_ctx,0x1F, 8);		
    spi_write_data(spi_ctx,0x23, 8);
    spi_write_data(spi_ctx,0x27, 8);			
    spi_write_data(spi_ctx,0x2A, 8);
    spi_write_data(spi_ctx,0x2C, 8);	
    spi_write_data(spi_ctx,0x30, 8);	
    spi_write_data(spi_ctx,0x34, 8);
    spi_write_data(spi_ctx,0x38, 8);
    spi_write_data(spi_ctx,0x3C, 8);		
    spi_write_data(spi_ctx,0x40, 8);
    spi_write_data(spi_ctx,0x44, 8);		
    spi_write_data(spi_ctx,0x48, 8);
    spi_write_data(spi_ctx,0x4B, 8);		
    spi_write_data(spi_ctx,0x4E, 8);		
    spi_write_data(spi_ctx,0x51, 8);
    spi_write_data(spi_ctx,0x54, 8);	
    spi_write_data(spi_ctx,0x58, 8);	
    spi_write_data(spi_ctx,0x5C, 8);
    spi_write_data(spi_ctx,0x60, 8);
    spi_write_data(spi_ctx,0x64, 8);	
    spi_write_data(spi_ctx,0x68, 8);	
    spi_write_data(spi_ctx,0x6C, 8);
    spi_write_data(spi_ctx,0x70, 8);
    spi_write_data(spi_ctx,0x74, 8);	
    spi_write_data(spi_ctx,0x78, 8);	
    spi_write_data(spi_ctx,0x7C, 8);	
    spi_write_data(spi_ctx,0x80, 8);
    spi_write_data(spi_ctx,0x84, 8);		
    spi_write_data(spi_ctx,0x88, 8);
    spi_write_data(spi_ctx,0x8C, 8);		
    spi_write_data(spi_ctx,0x91, 8);
    spi_write_data(spi_ctx,0x96, 8);		
    spi_write_data(spi_ctx,0x9B, 8);	
    spi_write_data(spi_ctx,0xA0, 8);
    spi_write_data(spi_ctx,0xA4, 8);	
    spi_write_data(spi_ctx,0xA8, 8);	
    spi_write_data(spi_ctx,0xAC, 8);	
    spi_write_data(spi_ctx,0xB0, 8);
    spi_write_data(spi_ctx,0xB4, 8);	
    spi_write_data(spi_ctx,0xB8, 8);	
    spi_write_data(spi_ctx,0xBC, 8);
    spi_write_data(spi_ctx,0xC0, 8);
    spi_write_data(spi_ctx,0xC4, 8);	
    spi_write_data(spi_ctx,0xC8, 8);	
    spi_write_data(spi_ctx,0xCC, 8);
    spi_write_data(spi_ctx,0xD0, 8);
    spi_write_data(spi_ctx,0xD4, 8);		
    spi_write_data(spi_ctx,0xDA, 8);		
    spi_write_data(spi_ctx,0xE0, 8);
    spi_write_data(spi_ctx,0xE6, 8);		
    spi_write_data(spi_ctx,0xEA, 8);		
    spi_write_data(spi_ctx,0xF0, 8);
    spi_write_data(spi_ctx,0xF4, 8);	
    spi_write_data(spi_ctx,0xF8, 8);	
    spi_write_data(spi_ctx,0xFC, 8);		
    spi_write_cmd(spi_ctx,0xBA, 8);
    spi_write_data(spi_ctx,0x04, 8);	
    spi_write_cmd(spi_ctx,0x3A, 8);    // 65k mode
    spi_write_data(spi_ctx,0x55, 8);
    spi_write_cmd(spi_ctx,0x2C, 8);
    spi_write_cmd(spi_ctx,0x29, 8);    // display on

	return 0;
}
void ST7735s_lcd_panel_init(struct panel_spec *self)
{
	struct s_spi_ctx* spi_ctx = NULL;

	LCDLOGE("lcd_panel_init_for_BOARD_CRANE_EVB ++\r\n");
	if (NULL == self) {
		LCDLOGE("ERROR: panel_init, Invalid param\r\n");
		return -1;
	}

	if (NULL == self->panel_if) {
		LCDLOGE("ERROR: panel_init, mcu has not been inited!\r\n");
		return -1;
	}

	spi_ctx = (struct s_spi_ctx*)self->panel_if;
    
    spi_write_cmd(spi_ctx,  0x11, 8); 
    mdelay(120);
    spi_write_cmd(spi_ctx,  0xB1, 8); 
    spi_write_data(spi_ctx, 0x01, 8); 
    spi_write_data(spi_ctx, 0x08, 8); 
    spi_write_data(spi_ctx, 0x05, 8); 

    spi_write_cmd(spi_ctx,  0xB2, 8); 
    spi_write_data(spi_ctx, 0x05, 8); 
    spi_write_data(spi_ctx, 0x3C, 8); 
    spi_write_data(spi_ctx, 0x3C, 8); 

    spi_write_cmd(spi_ctx,  0xB3, 8); 
    spi_write_data(spi_ctx, 0x05, 8); 
    spi_write_data(spi_ctx, 0x3C, 8); 
    spi_write_data(spi_ctx, 0x3C, 8); 
    spi_write_data(spi_ctx, 0x05, 8); 
    spi_write_data(spi_ctx, 0x3C, 8); 
    spi_write_data(spi_ctx, 0x3C, 8); 

    spi_write_cmd(spi_ctx,  0xB4, 8); 
    spi_write_data(spi_ctx, 0x03, 8); 

    spi_write_cmd(spi_ctx,  0xC0, 8); 
    spi_write_data(spi_ctx, 0x28, 8); 
    spi_write_data(spi_ctx, 0x08, 8); 
    spi_write_data(spi_ctx, 0x04, 8); 

    spi_write_cmd(spi_ctx,  0xC1, 8); 
    spi_write_data(spi_ctx, 0xC0, 8); 

    spi_write_cmd(spi_ctx,  0xC2, 8); 
    spi_write_data(spi_ctx, 0x0D, 8); 
    spi_write_data(spi_ctx, 0x00, 8); 

    spi_write_cmd(spi_ctx,  0xC3, 8); 
    spi_write_data(spi_ctx, 0x8D, 8); 
    spi_write_data(spi_ctx, 0x2A, 8); 

    spi_write_cmd(spi_ctx,  0xC4, 8); 
    spi_write_data(spi_ctx, 0x8D, 8); 
    spi_write_data(spi_ctx, 0xEE, 8); 

    spi_write_cmd(spi_ctx,  0xC5, 8); 
    spi_write_data(spi_ctx, 0x12, 8); 
    
    spi_write_cmd(spi_ctx,  0x36, 8); 
    spi_write_data(spi_ctx, 0x00, 8); 
    mdelay(120);
    spi_write_cmd(spi_ctx,  0xE0, 8); 
    spi_write_data(spi_ctx, 0x04, 8); 
    spi_write_data(spi_ctx, 0x22, 8); 
    spi_write_data(spi_ctx, 0x07, 8); 
    spi_write_data(spi_ctx, 0x0A, 8); 
    spi_write_data(spi_ctx, 0x2E, 8); 
    spi_write_data(spi_ctx, 0x30, 8); 
    spi_write_data(spi_ctx, 0x25, 8); 
    spi_write_data(spi_ctx, 0x2A, 8); 
    spi_write_data(spi_ctx, 0x28, 8); 
    spi_write_data(spi_ctx, 0x26, 8); 
    spi_write_data(spi_ctx, 0x2E, 8); 
    spi_write_data(spi_ctx, 0x3A, 8); 
    spi_write_data(spi_ctx, 0x00, 8); 
    spi_write_data(spi_ctx, 0x01, 8); 
    spi_write_data(spi_ctx, 0x03, 8); 
    spi_write_data(spi_ctx, 0x13, 8); 

    spi_write_cmd(spi_ctx,  0xE1, 8); 
    spi_write_data(spi_ctx, 0x04, 8); 
    spi_write_data(spi_ctx, 0x16, 8); 
    spi_write_data(spi_ctx, 0x06, 8); 
    spi_write_data(spi_ctx, 0x0D, 8); 
    spi_write_data(spi_ctx, 0x2D, 8); 
    spi_write_data(spi_ctx, 0x26, 8); 
    spi_write_data(spi_ctx, 0x23, 8); 
    spi_write_data(spi_ctx, 0x27, 8); 
    spi_write_data(spi_ctx, 0x27, 8); 
    spi_write_data(spi_ctx, 0x25, 8); 
    spi_write_data(spi_ctx, 0x2D, 8); 
    spi_write_data(spi_ctx, 0x3B, 8); 
    spi_write_data(spi_ctx, 0x00, 8); 
    spi_write_data(spi_ctx, 0x01, 8); 
    spi_write_data(spi_ctx, 0x04, 8); 
    spi_write_data(spi_ctx, 0x13, 8); 

    spi_write_cmd(spi_ctx,  0x3A, 8); 
    spi_write_data(spi_ctx, 0x05, 8);  /* Format is RGB565, if for RGB666, 0x05 -> 0x06 */

    spi_write_cmd (spi_ctx, 0x35, 8);
    spi_write_data(spi_ctx, 0x00, 8);
    spi_write_cmd (spi_ctx, 0x29, 8);  //display on
    spi_write_cmd (spi_ctx, 0x2C, 8);

        //mdelay(120);
    LCDLOGE("lcd_panel_init, spi has been inited!\r\n");

	return 0;
}

static int st7735_lcd_panel_init(struct panel_spec *self)
{
	struct s_spi_ctx* spi_ctx = NULL;
	struct spi_info * spi = NULL;

	if (NULL == self) {
		LCDLOGE("ERROR: panel_init, Invalid param\r\n");
		return -1;
	}

	if (NULL == self->panel_if) {
		LCDLOGE("ERROR: panel_init, mcu has not been inited!\r\n");
		return -1;
	}

	spi_ctx = (struct s_spi_ctx*)self->panel_if;
	spi = (struct spi_info *)self->info;

    spi_write_cmd(spi_ctx,  0x11, 8); 
	mdelay(120);
    spi_write_cmd(spi_ctx,  0xB1, 8); 
    spi_write_data(spi_ctx, 0x05, 8); 
    spi_write_data(spi_ctx, 0x3A, 8); 
    spi_write_data(spi_ctx, 0x3A, 8); 

    spi_write_cmd(spi_ctx,  0xB2, 8); 
    spi_write_data(spi_ctx, 0x05, 8); 
    spi_write_data(spi_ctx, 0x3A, 8); 
    spi_write_data(spi_ctx, 0x3A, 8); 

    spi_write_cmd(spi_ctx,  0xB3, 8); 
    spi_write_data(spi_ctx, 0x05, 8); 
    spi_write_data(spi_ctx, 0x3A, 8); 
    spi_write_data(spi_ctx, 0x3A, 8); 
    spi_write_data(spi_ctx, 0x05, 8); 
    spi_write_data(spi_ctx, 0x3A, 8); 
    spi_write_data(spi_ctx, 0x3A, 8); 

    spi_write_cmd(spi_ctx,  0xB4, 8); 
    spi_write_data(spi_ctx, 0x03, 8); 

    spi_write_cmd(spi_ctx,  0xC0, 8); 
    spi_write_data(spi_ctx, 0x62, 8); 
    spi_write_data(spi_ctx, 0x02, 8); 
    spi_write_data(spi_ctx, 0x04, 8); 

    spi_write_cmd(spi_ctx,  0xC1, 8); 
    spi_write_data(spi_ctx, 0xC0, 8); 

    spi_write_cmd(spi_ctx,  0xC2, 8); 
    spi_write_data(spi_ctx, 0x0D, 8); 
    spi_write_data(spi_ctx, 0x00, 8); 

    spi_write_cmd(spi_ctx,  0xC3, 8); 
    spi_write_data(spi_ctx, 0x8D, 8); 
    spi_write_data(spi_ctx, 0x6A, 8); 

    spi_write_cmd(spi_ctx,  0xC4, 8); 
    spi_write_data(spi_ctx, 0x8D, 8); 
    spi_write_data(spi_ctx, 0xEE, 8); 

    spi_write_cmd(spi_ctx,  0xC5, 8); 
    spi_write_data(spi_ctx, 0x12, 8); 
    
    spi_write_cmd(spi_ctx,  0x36, 8); 
    spi_write_data(spi_ctx, 0xC8, 8); 
    mdelay(120);
    spi_write_cmd(spi_ctx,  0xE0, 8); 
    spi_write_data(spi_ctx, 0x03, 8); 
    spi_write_data(spi_ctx, 0x1B, 8); 
    spi_write_data(spi_ctx, 0x12, 8); 
    spi_write_data(spi_ctx, 0x11, 8); 
    spi_write_data(spi_ctx, 0x3F, 8); 
    spi_write_data(spi_ctx, 0x3A, 8); 
    spi_write_data(spi_ctx, 0x32, 8); 
    spi_write_data(spi_ctx, 0x34, 8); 
    spi_write_data(spi_ctx, 0x2F, 8); 
    spi_write_data(spi_ctx, 0x2B, 8); 
    spi_write_data(spi_ctx, 0x30, 8); 
    spi_write_data(spi_ctx, 0x3A, 8); 
    spi_write_data(spi_ctx, 0x00, 8); 
    spi_write_data(spi_ctx, 0x01, 8); 
    spi_write_data(spi_ctx, 0x02, 8); 
    spi_write_data(spi_ctx, 0x05, 8); 

    spi_write_cmd(spi_ctx,  0xE1, 8); 
    spi_write_data(spi_ctx, 0x03, 8); 
    spi_write_data(spi_ctx, 0x1B, 8); 
    spi_write_data(spi_ctx, 0x12, 8); 
    spi_write_data(spi_ctx, 0x11, 8); 
    spi_write_data(spi_ctx, 0x32, 8); 
    spi_write_data(spi_ctx, 0x2F, 8); 
    spi_write_data(spi_ctx, 0x2A, 8); 
    spi_write_data(spi_ctx, 0x2F, 8); 
    spi_write_data(spi_ctx, 0x2E, 8); 
    spi_write_data(spi_ctx, 0x2C, 8); 
    spi_write_data(spi_ctx, 0x35, 8); 
    spi_write_data(spi_ctx, 0x3F, 8); 
    spi_write_data(spi_ctx, 0x00, 8); 
    spi_write_data(spi_ctx, 0x00, 8); 
    spi_write_data(spi_ctx, 0x01, 8); 
    spi_write_data(spi_ctx, 0x05, 8); 

    spi_write_cmd(spi_ctx,  0x3A, 8); 
    spi_write_data(spi_ctx, 0x05, 8);  /* Format is RGB565, if for RGB666, 0x05 -> 0x06 */
#if 0
    spi_write_cmd (spi_ctx, 0x35, 8);
	spi_write_data(spi_ctx, 0x00, 8);
	spi_write_cmd (spi_ctx, 0x29, 8);  //display on
	//spi_write_cmd (spi_ctx, 0x2C, 8);
	mdelay(120);
	
	spi_write_cmd(spi_ctx, 0x2A, 8);
		spi_write_data(spi_ctx, 0, 8);
		spi_write_data(spi_ctx, 2, 8);
		spi_write_data(spi_ctx, 0, 8);
		spi_write_data(spi_ctx, 129, 8);
	
		spi_write_cmd(spi_ctx, 0x2B, 8);
		spi_write_data(spi_ctx, 0, 8);
		spi_write_data(spi_ctx, 3, 8);
		spi_write_data(spi_ctx, 0, 8);
		spi_write_data(spi_ctx, 130, 8);
#endif
    spi_write_cmd(spi_ctx,  0x29, 8); 
	//mdelay(120);
	LCDLOGE("lcd_panel_init, spi has been inited!\r\n");

	return 0;
}


/* Note: this timing is not used in CraneM */
static struct timing_spi quec_spi_timing = {
	13000, /*kHz wclk*/
	5000, /*kHz rckl*/
};
//note:choose 3_line or4_line 
static struct spi_info quec_lcd_info = {
	LCD_SPI_CONTROLLER_LINE, //
	1, 
	LCD_SPI_CONTROLLER_DATA_LINE, //数据线的个数
	SPI_FORMAT_RGB565,
	0,
	SPI_EDGE_RISING,
	0,
	SPI_ENDIAN_MSB,
	0,
	&quec_spi_timing,
};

struct panel_spec quec_st7735_lcd_spec = {
	"st7735_spi_3w_1l_1i",
	0x7c89f0,
	LCD_CAP_NOTE,
	128,
	128,
	LCD_MODE_SPI,
	LCD_POLARITY_POS,
	(&quec_lcd_info),
	NULL,
	&quec_spi_ops,
};
    
struct panel_spec quec_st7735S_lcd_spec = {
    "st7735S_spi_4w_1l_1i",
	0x7c89f0,
	LCD_CAP_NOTE,
	128,
	160,
	LCD_MODE_SPI,
	LCD_POLARITY_POS,
	(&quec_lcd_info),
	NULL,
	&quec_spi_ops,
};
    
struct panel_spec quec_st7789v_lcd_spec = {
    "st7789v_spi_4w_1l_1i",
	0x858552,
	LCD_CAP_NOTE,
	320,
	240,
	LCD_MODE_SPI,
	LCD_POLARITY_POS,
	(&quec_lcd_info),
	NULL,
	&quec_spi_ops,
}; 
    
//驱动实例st7735     128*128 
struct quec_lcd_driver quec_st7735_lcd_driver ={
    &quec_st7735_lcd_spec,
    st7735_lcd_panel_init,
};
    
//驱动实例st7735S 128*160  
struct quec_lcd_driver quec_st7735S_lcd_driver ={
    &quec_st7735S_lcd_spec,
    ST7735s_lcd_panel_init,
};
    
//驱动实例st7789v    
struct quec_lcd_driver quec_st7789v_lcd_driver ={
    &quec_st7789v_lcd_spec,
    lcd_7789v_lcd_panel_init,
};
    
//新建驱动请放入此数组
struct quec_lcd_driver *quec_panel_list[]={
    //&quec_st7735_lcd_driver,
    &quec_st7789v_lcd_driver,  
    //&quec_st7735S_lcd_driver,
};

struct panel_spec *quec_detect_lcd(void)
{ 
    int i=0;
    unsigned int lcd_id = 0;
    struct panel_spec *panel=NULL;
        
    LCDLOGI("quec_detect_lcd +++\r\n");
    for(i=0;i<(sizeof(quec_panel_list)/sizeof(quec_panel_list[0]));i++)
	{
		//初始化LCD的SPI和相关Pin
        quec_lcd_panel_spi_init(quec_panel_list[i]->quec_panel_spec ,LCD_SCLK_FREQ,LCD_WORK_MODE_POLLING);
		
        lcd_id =quec_lcd_panel_readid(quec_panel_list[i]->quec_panel_spec);
        LCDLOGI("+++++++read_lcd_id=%x,lcd_real_id=%x+++++++ line_num=%d\r\n",lcd_id,quec_panel_list[i]->quec_panel_spec->panel_id,quec_panel_list[i]->quec_panel_spec->info->line_num);
	    if(quec_panel_list[i]->quec_panel_spec->panel_id == lcd_id)
	    {
            panel = quec_panel_list[i]->quec_panel_spec;

			quec_gpio_set_value(LCD_RST_PIN,1);
			mdelay(120);
			quec_gpio_set_value(LCD_RST_PIN,0);
			mdelay(120);
			quec_gpio_set_value(LCD_RST_PIN,1);
			mdelay(120);
			
            quec_panel_list[i]->lcd_panel_init(panel);//初始化外挂的LCD
            LCDLOGI("=================lcd_id=%x===================\r\n",lcd_id);
            return panel;
        };
	}
    LCDLOGE("do not support this lcd\r\n");
    return NULL;
}

int quec_lcd_close(void)
{
	int i = 0;

	LCDLOGE("quec_lcd_close +++!\r\n");
    if(CHIP_IS_CRANE)//ASR 1601&3601
    {
		//ToDo...
    }
	else //ASR 1603&1606 
    {
        quec_gpio_set_output(LCD_SPI_CS); //cs
        quec_gpio_set_value(LCD_SPI_CS, 1);//cs默认拉高
        
        g_lcd_status = LCD_STATUS_POWEROFF;
	}


	LCDLOGI("quec_lcd_close---\n");
	return 0;
}

//LCD初始化接口
int quec_lcd_init(void)
{
	int ret = -1;
	unsigned int lcd_id = 0;
	struct panel_spec *panel = NULL;
	
	LCDLOGI("Info: quec_lcd_init +++\r\n");
    
   if((g_lcd_status != LCD_STATUS_POWEROFF) && (g_lcd_status != LCD_STATUS_HWON))
    {
		LCDLOGE("Info: quec_lcd_init: asrlcd has been opened!\r\n");
		return 0;
	}
   	
    panel=quec_detect_lcd();//查找驱动初始化lcd
    if(panel == NULL)
    {
        quec_lcd_close();
        LCDLOGE("lcd init failed");
        ret = -1;
        return ret;
    }
    g_ppanel = panel;
    
	LCDLOGI("Info: quec_lcd_init ---\r\n");
    return 0;
}
//
//buffer:要写入到LCD的数据的起始地址
void quec_lcd_block_write_sync(UINT16* buffer, UINT16 startx,UINT16 starty,UINT16 endx,UINT16 endy)
{
	struct asrlcdd_framebuffer_window frameBufferWin;
	UINT32 attempts = 0;
	LCDLOGI("quec_lcd_block_write_Sync +++\r\n");
	unsigned short height = endy - starty + 1;//
	unsigned short width = endx - startx + 1;//
	
	frameBufferWin.frame_info.pbuffer = buffer;
	frameBufferWin.frame_info.stride =  width*2;//
	frameBufferWin.frame_info.height = height;
	frameBufferWin.frame_info.bitdepth = 16;//RGB565
    /*pony 2021-01-06注1：此处是画布大小应定义为屏幕大小所以图层刷图的起始地址是x，y而非0，0此处区别kernel侧*/
    /*pony 2021-01-06注2：部分客户需求显示logo同时刷背景色，故此处画布大小在ASRLCDD_Logo_Blit16_sync调整为整屏大小，图层起始地址是相对画布而言的*/
	frameBufferWin.roi_info.startX   = 0;
	frameBufferWin.roi_info.startY   = 0;
	frameBufferWin.roi_info.width    = width;
	frameBufferWin.roi_info.height   = height;
	CacheCleanMemory( (void *)buffer, width*height*2);//cache
	LCDLOGI("quec_lcd_block_write_Sync %d %d %d %d\r\n",startx, starty, endx, endy);
		
	if(CHIP_IS_CRANEM || CHIP_IS_CRANEL)
	{
      frameBufferWin.roi_info.startX   = 0;
	  frameBufferWin.roi_info.startY   = 0;
      quec_lcd_panel_refresh(g_ppanel,&frameBufferWin,startx,starty); 
	  
	  LCDLOGI("quec_lcd_block_write_Sync ---\r\n");
      return ;
    }
}

//清屏接口
//RGB565 --#define   RED       0xF800        //  红色   
//                              R G B
int quec_lcd_clear_screen(unsigned int bg_color)
{
	unsigned char *pbuffer = NULL;
	int i, j;
#if 1   
	pbuffer = malloc(g_ppanel->width*g_ppanel->height*2);
	if (NULL == pbuffer) {
		uart_printf("malloc pbuffer failed! \n");
		return -1;
	}
#else //temp@20220427 logo阶段,直接使用mem,好危险
	//pbuffer = (unsigned char *) (0x7E0E0010);//最大320*240*2=150Kb   不用这里,这里仅仅测试
#endif

	memset(pbuffer, 0, g_ppanel->width*g_ppanel->height*2);
	for(j=0; j<g_ppanel->height; j++)
	{
		for(i=0; i<g_ppanel->width; i++) 
		{
			*((UINT16*)(pbuffer+i*2+j*g_ppanel->width*2)) = bg_color;
		}
	}
	quec_lcd_block_write_sync((unsigned short *)pbuffer, 0, 0, g_ppanel->width-1, g_ppanel->height-1);
	free(pbuffer);

	return 0;
}
 int quec_lcd_brightness_init(GPIO_PIN_NUMBER_E gpio_pin)
 {
	 if(CHIP_IS_CRANEM || CHIP_IS_CRANEL)
	 {
		 quec_gpio_set_output(gpio_pin);
		 LCDLOGI("quec_lcd_brightness_init GPIO(%d)\r\n",gpio_pin);
		 return 0;
	 }
 
	 //使用PWM的方式控制背光
	 //ToDo
 }
 int quec_lcd_rst_init(GPIO_PIN_NUMBER_E gpio_pin)
 {
	 
	 if(CHIP_IS_CRANEM || CHIP_IS_CRANEL)
	 {
		 ql_gpio_init(gpio_pin,PIN_DIRECTION_OUT,PIN_PULL_DISABLE,PIN_LEVEL_HIGH); //rst--默认状态为高
		 LCDLOGI("quec_lcd_rst_init GPIO(%d)\r\n",gpio_pin);
		 return 0;
	 }
	 
	 //使用LCD控制器控制rst引脚
	 //ToDo
 }
 
 //命令&数据选择引脚，4line的LCD支持此引脚
 int quec_lcd_rs_init(GPIO_PIN_NUMBER_E gpio_pin)
 {
	 if(CHIP_IS_CRANEM || CHIP_IS_CRANEL)
	 {
		 ql_gpio_init(gpio_pin,PIN_DIRECTION_OUT,PIN_PULL_DISABLE,PIN_LEVEL_HIGH); //rs--默认状态为高
		 LCDLOGI("quec_lcd_rst_init GPIO(%d)\r\n",gpio_pin);
		 return 0;
	 }
 }

 /***********************************************************************
 *
 * Name:       
 *
 * Description: 设置LCD背光等级
 *
 * Parameters:level:0-5
 *
 * Returns:
 *
 * Notes:
 * 如果使用GPIO作为背光引脚,那么只有关闭和打开;
 * 只有使用PWM方式才可以设置等级
 ***********************************************************************/
int ql_lcd_set_brightness(unsigned int level)
{
	//GPIO的方式
	if(level == 0)
	{
		quec_gpio_set_value(LCD_BACK_LIGHT, 0);
	}
	else
	{
		quec_gpio_set_value(LCD_BACK_LIGHT, 1);
	}
	//PWM的方式
	//ToDo

	return 0;
}


void ql_lcd_set_rts(unsigned int level)
{
	quec_gpio_set_value(LCD_RST_PIN, level);

	//通过LCD的控制器控制
}



