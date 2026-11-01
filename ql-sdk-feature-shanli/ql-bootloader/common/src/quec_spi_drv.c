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
2022/04/26       Fias.fan    此文件用于LCD的SPI驱动,不建议客户改动,且要注意不同LCD的驱动时序有差别
==========================================================================================================================*/

#include "bsp.h"
#include "mfpr_api.h"
#include "quec_ssp_lcd.h"
#include "quec_spi_drv.h"
#include "quec_startup_gpio.h"

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

struct s_spi_ctx g_spi_ctx;


void spi_uninit(struct s_spi_ctx *spi_ctx)
{
	//ToDo...
}

struct s_spi_ctx* spi_init(uint32_t sclk, struct spi_info *info, int32_t work_mode)
{
	int dividor=0;
	struct s_spi_ctx *spi_ctx = &g_spi_ctx;
	int reg = 0;

	LCDLOGI("spi_init +++\r\n");

	if(info == NULL || info->timing == NULL){
		LCDLOGE("ERROR: spi_init, Invalid param!\r\n");
		return NULL;
	}

	if(LCD_WORK_MODE_INTERRUPT == work_mode)
	{
		LCDLOGW("WARNING: spi_init, no interrupt mode supported! change to polling mode!\r\n");
		work_mode = LCD_WORK_MODE_POLLING;
	}

	if((info->format != SPI_FORMAT_RGB565) &&
		(info->format != SPI_FORMAT_RGB666) && (info->data_lane_num == 1))
	{
		LCDLOGE("ERROR: spi_init, Format error!\r\n");
		return NULL;
	}

	spi_ctx->cur_path = 0;
	spi_ctx->cur_cs = 0;
	spi_ctx->sclk = sclk;
	spi_ctx->info.line_num = info->line_num;
	spi_ctx->info.interface_id = info->interface_id;
	spi_ctx->info.data_lane_num = info->data_lane_num;
	spi_ctx->info.format = info->format;
	spi_ctx->info.device_id = info->device_id;
	spi_ctx->info.sample_edge = info->sample_edge;
	spi_ctx->info.force_cs = info->force_cs;
	spi_ctx->info.endian = info->endian;
	spi_ctx->info.timing = info->timing;
	spi_ctx->work_mode = work_mode;


	spi_ctx->status = SPI_STATUS_INIT;
	spi_lcd_init();

	LCDLOGI("spi_init ----\r\n");
	return spi_ctx;
}

int spi_update(struct s_spi_ctx *spi_ctx, int32_t work_mode)
{

	LCDLOGI("spi_update +++\r\n");

	if(LCD_WORK_MODE_INTERRUPT == work_mode){
		LCDLOGW("WARNING: spi_init, no interrupt mode supported! change to polling mode!\r\n");
		work_mode = LCD_WORK_MODE_POLLING;
	}

	spi_ctx->work_mode = work_mode;
	LCDLOGI("spi_update ----\r\n");
	return 0;
}

int spi_write_cmd(struct s_spi_ctx *spi_ctx, uint32_t cmd, uint32_t bits)
{
	if(NULL == spi_ctx || bits > 32 || 0 == bits){
		LCDLOGE("ERROR: spi_write_cmd, Invalid param\r\n");
		return -1;
	}

	if(SPI_STATUS_INIT != spi_ctx->status){
		LCDLOGE("ERROR: spi_write_cmd, Invalid mcu status\r\n");
		return -1;
	}

	if((spi_ctx->info.force_cs == 1) && (spi_ctx->cur_cs == 0)){
		LCDLOGE("ERROR: spi_write_cmd, Invalid CS status\r\n");
		return -1;
	}


	if (4 == spi_ctx->info.line_num)
	{
		quec_gpio_set_value(LCD_SPI_RS, 0);
	}
	
	quec_gpio_set_value(LCD_SPI_CS, 0);
	ssp_write_cmd_data_to_LCD(0, cmd, bits, spi_ctx->info.line_num);
	mdelay(5);//20231026 Increase the delay ，slow down cs pull up speed to ensure successful LCD register initialization
	quec_gpio_set_value(LCD_SPI_CS, 1);
 

	return 0;
}

int spi_write_data(struct s_spi_ctx *spi_ctx, uint32_t data, uint32_t bits)
{
	if(NULL == spi_ctx || bits > 32 || 0 == bits){
		LCDLOGE("ERROR: spi_write_data, Invalid param\r\n");
		return -1;
	}

	if(SPI_STATUS_INIT != spi_ctx->status){
		LCDLOGE("ERROR: spi_write_data, Invalid mcu status\r\n");
		return -1;
	}

	if((spi_ctx->info.force_cs == 1) && (spi_ctx->cur_cs == 0)){
		LCDLOGE("ERROR: spi_write_data, Invalid CS status\r\n");
		return -1;
	}

	if (4 == spi_ctx->info.line_num)
	{
		quec_gpio_set_value(LCD_SPI_RS, 1);
	}
	
	quec_gpio_set_value(LCD_SPI_CS, 0);
	ssp_write_cmd_data_to_LCD(1, data, bits, spi_ctx->info.line_num);
	mdelay(5);//20231026 Increase the delay ，slow down cs pull up speed to ensure successful LCD register initialization
	quec_gpio_set_value(LCD_SPI_CS, 1);

	return 0;
}



int spi_read_data(struct s_spi_ctx *spi_ctx, uint32_t cmd, uint32_t cmd_bits,
	uint32_t *data,  uint32_t data_bits)
{
	uint32_t value_and = 0;

	value_and = (1 << data_bits) - 1;

	if(NULL == spi_ctx || cmd_bits > 32 || data_bits > 32){
		LCDLOGE("ERROR: spi_read_data, Invalid param\r\n");
		return -1;
	}

	if(SPI_STATUS_INIT != spi_ctx->status){
		LCDLOGE("ERROR: spi_read_data, Invalid mcu status\r\n");
		return -1;
	}

	if((spi_ctx->info.force_cs == 1) && (spi_ctx->cur_cs == 0)){
		LCDLOGE("ERROR: spi_read_data, Invalid CS status\r\n");
		return -1;
	}

	if (4 == spi_ctx->info.line_num)
	{
		quec_gpio_set_value(LCD_SPI_RS, 0);
	}
	
	quec_gpio_set_value(LCD_SPI_CS, 0);
	ssp_write_cmd_data_to_LCD(0, cmd, cmd_bits, spi_ctx->info.line_num);
	
	mdelay(10);//延时的时间的长短的依据是什么？
	
	ssp_read_data_from_LCD(data, data_bits);
	quec_gpio_set_value(LCD_SPI_CS, 1);

	return 0;
}
	

/* 2021-01-27 added for CraneM & CraneL*/
#define TX_FIFO_INT_EN		(0x1<<3)   //SSP_INT_EN[3]
#define RX_FIFO_INT_EN		(0x1<<2)   //SSP_INT_EN[2]
#define TIMEOUT_EN			(0x1<<1)   //SSP_INT_EN[1]
#define PERI_TRAIL_EN		(0x1<<0)   //SSP_INT_EN[0]
#define SSPSFRM_M			(0x0<<4)   //SSP_TOP_CTRL[4]
#define SSPSCLK_M			(0x0<<3)   //SSP_TOP_CTRL[3]
#define FRF_SPI				(0x0<<1)   //SSP_TOP_CTRL[2:1]
#define SSP_FORMAT			FRF_SPI
#define RX_AUTO_FULL_CTRL_EN (0x1<<17)  //SSP_FIFO_CTRL[17]
#define FIFO_UNPACKING		(0x0<<16)  //SSP_FIFO_CTRL[16]
#define RX_THRES_7			(0x7<<5)   //SSP_FIFO_CTRL[9:5]
#define TX_THRES_7			(0x7<<0)   //SSP_FIFO_CTRL[4:0]
#define SSE_EN				(0x1<<0)   //SSP_TOP_CTRL[0]

#define SSP0_BASE_ADDRESS	0xD401B000
#define APB_SSP0_CLK_RST	0xd401501c
#define SSP2_BASE_ADDRESS   0xD401C000 
#define APB_SSP2_CLK_RST    0xd401504c
#define DW_9BITS			(0x8 << 5)
#define SSP_DATAR			0x10 
#define SSP_STATUS			0x14

static __inline void reg_write(uint32_t reg, uint32_t val)
{
	(*(volatile unsigned long *)(reg)) = val;
}

static __inline void ssp0_reg_write(uint32_t reg, uint32_t val)
{
	reg_write(SSP0_BASE_ADDRESS + reg, val);
}

static __inline uint32_t ssp0_reg_read(uint32_t reg)
{
	return (*(volatile uint32_t *)(SSP0_BASE_ADDRESS + reg));
}

static __inline void ssp2_reg_write(uint32_t reg, uint32_t val)
{
	reg_write(SSP2_BASE_ADDRESS + reg, val);
}

static __inline uint32_t ssp2_reg_read(uint32_t reg)
{
	return (*(volatile uint32_t *)(SSP2_BASE_ADDRESS + reg));
}

void spi_dump(void)
{
	UINT32 i = 0;
#ifdef _QUEC_LCD_SSP0_  //打开宏则选用SSP0通道
	for ( i = 0; i < 12; i++) {
		LCDLOGE("---SSP0 start dump---\r\n");
		LCDLOGE("SSPI0 offset: 0x%x, value:0x%lx\r\n", i * 4, ssp0_reg_read(i * 4));
	}
	LCDLOGE("SPS0 offset: 0x54, value:0x%lx\r\n", ssp0_reg_read(0x54));
	LCDLOGE("---SSP0 dump end---\r\n");

#elif defined _QUEC_LCD_SSP2_		//默认选用SSP2通道
	for ( i = 0; i < 12; i++) {
		LCDLOGE("---SSP2 start dump---\r\n");
		LCDLOGE("SSPI2 offset: 0x%x, value:0x%lx\r\n", i * 4, ssp2_reg_read(i * 4));
	}
	LCDLOGE("SPS2 offset: 0x54, value:0x%lx\r\n", ssp2_reg_read(0x54));
	LCDLOGE("---SSP2 dump end---\r\n");
	
#endif
}

void spi_set_clk_rate(unsigned int clk_dev)
{
	if (clk_dev >= SPI_CLK_LIMIT) {
		LCDLOGE("[Error]: not supported spi clk\r\n");
		return;
	}
	
#ifdef _QUEC_LCD_SSP0_  //打开宏则选用SSP0通道
		reg_write(APB_SSP0_CLK_RST, 0x3 | (clk_dev << 4));	
#elif defined _QUEC_LCD_SSP2_		//默认选用SSP2通道
		reg_write(APB_SSP2_CLK_RST, 0x3 | (clk_dev << 4));
#endif
		
}


int quec_lcd_spi_cs_init(GPIO_PIN_NUMBER_E gpio_pin)
{
	
    if(CHIP_IS_CRANEM || CHIP_IS_CRANEL)
    {
		ql_gpio_init(gpio_pin,PIN_DIRECTION_OUT,PIN_PULL_DISABLE,PIN_LEVEL_HIGH); //CS--默认状态为高
        LCDLOGI("quec_lcd_spi_cs_init GPIO(%d)\r\n",gpio_pin);
        return 0;
    }
	
	//使用LCD-SPi控制器控制CS引脚
	//ToDo
}


void spi_lcd_init(void)
{
	uint32_t ssp_top_cfg=0,  ssp_fifo_cfg=0;
  	uint32_t ssp_int_en_cfg=0, ssp_to_cfg=0;


//ToDo----SPI pin的初始化 ?
	if(CHIP_IS_CRANEL)			//Fias 2022-04-25 EC600M GPIO配置
	{
	
		quec_lcd_spi_cs_init(LCD_SPI_CS);		//CS
		//600MCN_LA
		#if defined (__QUECTEL_PROJECT_EC600MCN_LA__)|| defined (__QUECTEL_PROJECT_EC600MCN_LE__)									
		quec_set_gpio_mfprReg(LCD_SPI_CLK,(MFP_PULL_HIGH|MFP_DRIVE_MEDIUM|MFP_AF1));	//CLK
		quec_set_gpio_mfprReg(LCD_SPI_DOUT,(MFP_PULL_HIGH|MFP_DRIVE_MEDIUM|MFP_AF1));	//TX
		//800MCN_XX
		#elif defined (__QUECTEL_PROJECT_EC800MCN_XX__)										
		quec_set_gpio_mfprReg(LCD_SPI_CLK,(MFP_PULL_HIGH|MFP_DRIVE_MEDIUM|MFP_AF2));	//CLK
		quec_set_gpio_mfprReg(LCD_SPI_DOUT,(MFP_PULL_HIGH|MFP_DRIVE_MEDIUM|MFP_AF2));	//TX
		#else
			LCDLOGI("Please configure the project\n");
		#endif
	}


#ifdef _QUEC_LCD_SSP0_
	reg_write(APB_SSP0_CLK_RST, 0x7);
#elif defined _QUEC_LCD_SSP2_		//默认选用SSP2通道
	reg_write(APB_SSP2_CLK_RST, 0x7);
#endif

	spi_set_clk_rate(LCD_SCLK_READ_FREQ);

	ssp_top_cfg	 = 0x4d00;
	ssp_to_cfg = 0x200;
	ssp_fifo_cfg = 0x200e7;
	ssp_int_en_cfg = 0xf;
	
#ifdef _QUEC_LCD_SSP0_		//打开宏则选用SSP0通道
	ssp0_reg_write(0, ssp_top_cfg);
	ssp0_reg_write(0x4, ssp_fifo_cfg);
	ssp0_reg_write(0x8, ssp_int_en_cfg);
	ssp0_reg_write(0xc, ssp_to_cfg);
	ssp0_reg_write(0, ssp_top_cfg | 0x1);

#elif defined _QUEC_LCD_SSP2_		//默认选用SSP2通道
	ssp2_reg_write(0, ssp_top_cfg);
	ssp2_reg_write(0x4, ssp_fifo_cfg);
	ssp2_reg_write(0x8, ssp_int_en_cfg);
	ssp2_reg_write(0xc, ssp_to_cfg);
	ssp2_reg_write(0, ssp_top_cfg | 0x1);
#endif

}

void ssp_write_cmd_data_to_LCD(uint32_t cmd, uint32_t data,uint32_t data_bits,uint16_t line_num)
{
	int reg=0;

	if ((data_bits < 1) || (data_bits > 31)) {
		LCDLOGE("[Error]: not supported spi data bits\r\n");
		return;
	}
#ifdef _QUEC_LCD_SSP0_		//打开宏则选用SSP0通道
	ssp0_reg_write(0x54, 0x5);
	reg = ssp0_reg_read(0) & ~(0x1f << 5);

	if (line_num == 3) {
		ssp0_reg_write(0, reg | (data_bits << 5));//9 bits
		if (!cmd)
			ssp0_reg_write(SSP_DATAR, data);
		else
			ssp0_reg_write(SSP_DATAR, (1 << data_bits) | data);
	} else if (line_num == 4) {
		ssp0_reg_write(0, reg | ((data_bits - 1) << 5));
		ssp0_reg_write(SSP_DATAR, data);
	} else
		{
			LCDLOGE("[ERROR]: not supported spi line number_ssp0_reg!\r\n");
		}
		mdelay(1);

#elif defined _QUEC_LCD_SSP2_		//默认选用SSP2通道
	ssp2_reg_write(0x54, 0x5);
	reg = ssp2_reg_read(0) & ~(0x1f << 5);

	if (line_num == 3) 
	{
		ssp2_reg_write(0, reg | (data_bits << 5));//9 bits
		if (!cmd)
			ssp2_reg_write(SSP_DATAR, data);
		else
			ssp2_reg_write(SSP_DATAR, (1 << data_bits) | data);
	} 
	else if (line_num == 4)
	{
		ssp2_reg_write(0, reg | ((data_bits - 1) << 5));
		ssp2_reg_write(SSP_DATAR, data);
	} 
	else
		LCDLOGE("[ERROR]: not supported spi line number!\r\n");
	
		mdelay(1);
#endif

}

void ssp_write_data_to_LCD_Gram(uint16_t* data, uint32_t sum_pixel,uint32_t data_bits, uint16_t line_num)
{
	int i=0, cnt=0, reg=0;

	if ((data_bits < 1) || (data_bits > 31)) {
		LCDLOGE("[Error]: not supported spi data bits\r\n");
		return;
	}
#ifdef _QUEC_LCD_SSP0_		//打开宏则选用SSP0通道

	ssp0_reg_write(0x54, 0x5);
	reg = ssp0_reg_read(0) & ~(0x1f << 5);

	if (line_num == 3) {
		ssp0_reg_write(0, reg | (8 << 5));
	} else if (line_num == 4) {
		ssp0_reg_write(0, reg | ((data_bits -1) << 5));
	}

	for (i = 0; i < sum_pixel; i++) 
	{
		cnt = 0;
		/* wait for TX not full *///只有当Tx fifo不为满状态才可以继续向Fifo里写数据
		while (!(ssp0_reg_read(SSP_STATUS) & (0x1 << 6))) {
			if (cnt ++ > 1000000) {
				LCDLOGE("ERROR: spi write byte error_ssp0_reg!\r\n");
				return;
			}
		}
		
		if (line_num == 3)
		{
			if ((data_bits == 16) || (data_bits == 8))
			{
				ssp0_reg_write(SSP_DATAR, (1 << 8) | (*(data + i) >> 8));
				cnt = 0;

				while (!(ssp0_reg_read(SSP_STATUS) & (0x1 << 6))) {
					if (cnt ++ > 1000000) {
						LCDLOGE("ERROR: spi write byte error_ssp0_reg!\r\n");
						return;
					}
				}
				ssp0_reg_write(SSP_DATAR, (0x1 << 8) | (*(data + i) & 0xff));
			} else
				LCDLOGE("spi write byte not support length_ssp0_reg!\r\n");
		}
		else if (line_num == 4) 
		{
			ssp0_reg_write(SSP_DATAR, *(data + i));
		}
		else 
		{
			LCDLOGE("ERROR: spi line number error_ssp0_reg!\r\n");
			return;
		}
	}
	
#elif defined _QUEC_LCD_SSP2_		//默认选用SSP2通道
	ssp2_reg_write(0x54, 0x5);
	reg = ssp2_reg_read(0) & ~(0x1f << 5);

	if (line_num == 3) {
		ssp2_reg_write(0, reg | (8 << 5));
	} else if (line_num == 4) {
		ssp2_reg_write(0, reg | ((data_bits -1) << 5));
	}

	for (i = 0; i < sum_pixel; i++) {
		cnt = 0;
		/* wait for TX not full */
		while (!(ssp2_reg_read(SSP_STATUS) & (0x1 << 6))) {
			if (cnt ++ > 1000000) {
				LCDLOGE("ERROR: spi write byte error!\r\n");
				return;
			}
		}
		if (line_num == 3) {
			if ((data_bits == 16) || (data_bits == 8)) {
				ssp2_reg_write(SSP_DATAR, (1 << 8) | (*(data + i) >> 8));
				cnt = 0;

				while (!(ssp2_reg_read(SSP_STATUS) & (0x1 << 6))) {
					if (cnt ++ > 1000000) {
						LCDLOGE("ERROR: spi write byte error!\r\n");
						return;
					}
				}
				ssp2_reg_write(SSP_DATAR, (0x1 << 8) | (*(data + i) & 0xff));
			} else
				LCDLOGE("spi write byte not support length!\r\n");
		} else if (line_num == 4) {
			ssp2_reg_write(SSP_DATAR, *(data + i));
		} else {
			LCDLOGE("ERROR: spi line number error!\r\n");
			return;
		}
	}
	
#endif

}

void ssp_read_data_from_LCD(uint32_t *data,  uint32_t data_bits)
{ 
	int reg = 0;
	int status = 0;
#ifdef _QUEC_LCD_SSP0_		//打开宏则选用SSP0通道

	reg = ssp0_reg_read(0) & ~(0x1f << 5);
	if ((data_bits < 1) || (data_bits > 31)) {
		LCDLOGE("[Error]: not supported spi data bits_ssp0_reg\r\n");
		return;
	}

	if (data_bits > 8)
		ssp0_reg_write(0, reg | (data_bits << 5));
	else
		ssp0_reg_write(0, reg | ((data_bits -1) << 5)); //8 bit

	ssp0_reg_write(0x54, 0x7);
	ssp0_reg_write(SSP_DATAR, 0x0);

    while (((status = ssp0_reg_read(SSP_STATUS)) & (0x1 << 14)) == 0);

	*data = ssp0_reg_read(SSP_DATAR);

#elif defined _QUEC_LCD_SSP2_		//默认选用SSP2通道

	reg = ssp2_reg_read(0) & ~(0x1f << 5);
	if ((data_bits < 1) || (data_bits > 31)) {
		LCDLOGE("[Error]: not supported spi data bits\r\n");
		return;
	}

	if (data_bits > 8)
		ssp2_reg_write(0, reg | (data_bits << 5));
	else
		ssp2_reg_write(0, reg | ((data_bits -1) << 5)); //8 bit

	ssp2_reg_write(0x54, 0x7);
	ssp2_reg_write(SSP_DATAR, 0x0);

    while (((status = ssp2_reg_read(SSP_STATUS)) & (0x1 << 14)) == 0);

	*data = ssp2_reg_read(SSP_DATAR);
	
#endif

}

void wait_ssp_write_data_to_LCD_complete(void)
{
	int cnt = 0;

#ifdef _QUEC_LCD_SSP0_		//打开宏则选用SSP0通道

	/* wait for TX empty */
	while ((ssp0_reg_read(SSP_STATUS) & 0xfc0) != 0x40) {
		if (cnt++ > 1000000) {
			uudelay(1);//20231026Improve the timeout detection time
			LCDLOGE("ERROR: spi write byte error_ssp0_reg!\r\n");
			return;
		}
	}

#elif defined _QUEC_LCD_SSP2_		//默认选用SSP2通道

	/* wait for TX empty */
	while ((ssp2_reg_read(SSP_STATUS) & 0xfc0) != 0x40) {
		if (cnt++ > 1000000) {
			uudelay(1);//20231026Improve the timeout detection time
			LCDLOGE("ERROR: spi write byte error!\r\n");
			return;
		}
	}
	
#endif
}


