/**
 ******************************************************************************
 * @file    ql_lcd.h
 * @author  Juson.zhang
 * @version V1.0.0
 * @date    2019/12/08
 * @brief   This file contains the lcd functions's declaration
 ******************************************************************************
 */
#ifndef _QUEC_LCD_H_
#define _QUEC_LCD_H_
#include "quec_cust_feature.h"
#include "panel_drv.h"
#ifdef __cplusplus
	extern "C" {
#endif
typedef enum {
	MCI_LCD_ID_MAIN,
	MCI_LCD_ID_SUB,
}QUEC_MCI_LCD_ID_T;

typedef enum QUEC_SPI_LCD_CLK_ENUM {
	QUEC_SPI_LCD_CLK_6_5M = 0,
	QUEC_SPI_LCD_CLK_13M ,
	QUEC_SPI_LCD_CLK_26M ,
	QUEC_SPI_LCD_CLK_52M ,
	QUEC_SPI_LCD_CLK_3_25M, 
	QUEC_SPI_LCD_CLK_1_625M,
	QUEC_SPI_LCD_CLK_812_5k,
	QUEC_SPI_CLK_LIMIT
}QUEC_SPI_LCD_CLK_E;

enum{
	LCD_STATUS_POWEROFF = 0 ,
	LCD_STATUS_POWERON = 1,
};

enum {
    QUEC_LCD_CMD = 0,
    QUEC_LCD_DATA,
    QUEC_LCD_DELAY,
};

enum{
	QUEC_SPI_FORMAT_RGB565 = 0,
	QUEC_SPI_FORMAT_RGB666 = 1,
	QUEC_SPI_FORMAT_RGB666_2_3 = 2,
	QUEC_SPI_FORMAT_RGB888 = 3,
	QUEC_SPI_FORMAT_RGB888_2_3 = 4,
	QUEC_SPI_FORMAT_LIMIT
};

enum{
	QUEC_SPI_EDGE_RISING = 0,
	QUEC_SPI_EDGE_FALLING = 1,
	QUEC_SPI_EDGE_LIMIT
};

enum{
	QUEC_SPI_ENDIAN_LSB = 0,
	QUEC_SPI_ENDIAN_MSB = 1,
	QUEC_SPI_ENDIAN_LIMIT
};

enum{
	QUEC_LCD_CAP_NORMALE = 0,
	QUEC_LCD_CAP_FAKE = 1,
	QUEC_LCD_CAP_POWERON = 2,
	QUEC_LCD_CAP_NOTE = 4, /*has no te signal*/
	QUEC_LCD_CAP_LIMIT
};

typedef struct quec_spi_lcd_write_struct {
	unsigned char type;		/* SPI_WRITE_CMD / SPI_WRITE_DATA / SPI_WRITE_DELAY */
	unsigned char value;
	unsigned char data_length;	/* Only for SPI_WRITE_CMD */
}quec_spi_lcd_write_t;

typedef enum
{
    LCD_SLEEP,
    LCD_WAKE_UP,
} QUEC_LCD_SLEEP;


#define LCD_CMD_COL_ADDR_SET    0x2A
#define LCD_CMD_ROW_ADDR_SET    0x2B
#define LCD_CMD_FRAME_MEM_WR    0x2C

typedef struct quec_lcd_data_struct 
{
    quec_spi_lcd_write_t* init_para;
	unsigned int        init_para_len;
	unsigned short      width;
	unsigned short      height;
	unsigned char       lcd_cmd_col_set;
	unsigned char       lcd_cmd_row_set;
	unsigned char       lcd_cmd_mem_wr;
	unsigned int        te_signal;
	unsigned int 	    spi_wclk;//写时序的时钟
	unsigned int 	    spi_rclk;//读时序的时钟
	unsigned int 	    lcd_id;
	unsigned short      format;
    unsigned short      type;//rgb or 黑白屏
	unsigned short      sample_edge;
	unsigned short      endian;
	unsigned short      line_num;	//4 or 3
	unsigned short      data_line;	//1 or 2
	unsigned char       work_mode;
}quec_lcd_data_t;

int quec_lcd_init(quec_lcd_data_t *lcd_data);
unsigned int quec_lcd_read_id(void);
int quec_lcd_dinit(void);
int quec_lcd_write_sync(unsigned char *pbuffer, unsigned short start_x, unsigned short start_y, unsigned short end_x, unsigned short end_y);
int quec_lcd_clear_screen(unsigned short bg_color);
int quec_lcd_wakeup(unsigned int level);
int quec_lcd_display_on(void);
int quec_lcd_display_off(void);
int quec_spi_lcd_write_cmd(unsigned char cmd);
int quec_spi_lcd_write_data(unsigned char data);
int quec_lcd_updata_config(quec_lcd_data_t *lcd_data);
unsigned int quec_lcd_read_id(void);




#ifdef __cplusplus
	} /*"C" */
#endif

#endif /* _QUEC_LCD_H_ */


