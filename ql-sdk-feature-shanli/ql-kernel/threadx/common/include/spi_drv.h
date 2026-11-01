#ifndef _SPI_DRV_H_
#define _SPI_DRV_H_
#include "QuecPrjName.h"

#include "mfpr_api.h"

#if defined (__QUECTEL_PROJECT_EC600MCN_LA__) || defined (__QUECTEL_PROJECT_EC600MCN_LE__) \
	|| defined (__QUECTEL_PROJECT_EC600NCN_AC__) || defined (__QUECTEL_PROJECT_EC600MEU_LA__)\
	|| defined (__QUECTEL_PROJECT_EC600MLA_LA__)
#define QUEC_LCD_SPI_DCX_NUM    GPIO_14
#define QUEC_LCD_SPI_CS_NUM     GPIO_13
#define QUEC_LCD_SPI_RST_NUM    GPIO_50
#define QUEC_LCD_SPI_SCLK_NUM   GPIO_12
#define QUEC_LCD_SPI_SDA_NUM    GPIO_15

#define QUEC_LCD_SPI_DCX_AF     MFP_AF0
#define QUEC_LCD_SPI_CS_AF      MFP_AF0
#define QUEC_LCD_SPI_RST_AF     MFP_AF0
#define QUEC_LCD_SPI_SCLK_AF    MFP_AF1
#define QUEC_LCD_SPI_SDA_AF     MFP_AF1

#define SPI_LCD_CS              13
#define SPI_LCD_RST             50
#define SPI_LCD_DCX             14
#elif defined (__QUECTEL_PROJECT_EC800MCN_GA__) || defined (__QUECTEL_PROJECT_EC800MCN_LA__) \
||defined (__QUECTEL_PROJECT_EG810MCN_GA__) || defined (__QUECTEL_PROJECT_EC800MCN_CC__) \
|| defined (__QUECTEL_PROJECT_EC800MCN_NC__)|| defined (__QUECTEL_PROJECT_EC800MCN_MC__) \
||defined (__QUECTEL_PROJECT_EC800MCN_GD__) || defined (__QUECTEL_PROJECT_EG810MCN_LA__) \
||defined (__QUECTEL_PROJECT_EC800MCN_LE__) || defined (__QUECTEL_PROJECT_EC800MCN_GB__) \
|| defined (__QUECTEL_PROJECT_EG810MEU_LA__)|| defined (__QUECTEL_PROJECT_EG810MCN_GB__)\
|| defined (__QUECTEL_PROJECT_EG810MCN_LC__) || defined (__QUECTEL_PROJECT_EG810MEU_LC__)\
|| defined (__QUECTEL_PROJECT_EG810MLA_LC__)




#define QUEC_LCD_SPI_DCX_NUM    GPIO_35
#define QUEC_LCD_SPI_CS_NUM     GPIO_34
#define QUEC_LCD_SPI_RST_NUM    GPIO_32
#define QUEC_LCD_SPI_SCLK_NUM   GPIO_33
#define QUEC_LCD_SPI_SDA_NUM    GPIO_36

#define QUEC_LCD_SPI_DCX_AF     MFP_AF0
#define QUEC_LCD_SPI_CS_AF      MFP_AF0
#define QUEC_LCD_SPI_RST_AF     MFP_AF0
#define QUEC_LCD_SPI_SCLK_AF    MFP_AF2
#define QUEC_LCD_SPI_SDA_AF     MFP_AF2

#define SPI_LCD_CS              34
#define SPI_LCD_RST             32
#define SPI_LCD_DCX             35

#elif defined (__QUECTEL_PROJECT_EC100MCN_LA__) || defined (__QUECTEL_PROJECT_EC200MCN_GB__)
#define QUEC_LCD_SPI_DCX_NUM    GPIO_18
#define QUEC_LCD_SPI_CS_NUM     GPIO_17
#define QUEC_LCD_SPI_RST_NUM    GPIO_37
#define QUEC_LCD_SPI_SCLK_NUM   GPIO_16
#define QUEC_LCD_SPI_SDA_NUM    GPIO_19

#define QUEC_LCD_SPI_DCX_AF     MFP_AF0
#define QUEC_LCD_SPI_CS_AF      MFP_AF0
#define QUEC_LCD_SPI_RST_AF     MFP_AF0
#define QUEC_LCD_SPI_SCLK_AF    MFP_AF2
#define QUEC_LCD_SPI_SDA_AF     MFP_AF2

#define SPI_LCD_CS              17
#define SPI_LCD_RST             37
#define SPI_LCD_DCX             18

#elif defined(__QUECTEL_PROJECT_EC200MCN_LA__) ||defined(__QUECTEL_PROJECT_EC200MCN_LE__)

#define QUEC_LCD_SPI_DCX_NUM    GPIO_35
#define QUEC_LCD_SPI_CS_NUM     GPIO_34
#define QUEC_LCD_SPI_RST_NUM    GPIO_12
#define QUEC_LCD_SPI_SCLK_NUM   GPIO_33
#define QUEC_LCD_SPI_SDA_NUM    GPIO_36

#define QUEC_LCD_SPI_DCX_AF     MFP_AF0
#define QUEC_LCD_SPI_CS_AF      MFP_AF0
#define QUEC_LCD_SPI_RST_AF     MFP_AF0
#define QUEC_LCD_SPI_SCLK_AF    MFP_AF2
#define QUEC_LCD_SPI_SDA_AF     MFP_AF2

#define SPI_LCD_CS              34
#define SPI_LCD_RST             12
#define SPI_LCD_DCX             35

#else

#error "Please configure the project"

#endif


#define SPI_SCLK_FREQ 10000

enum{
	SPI_EDGE_RISING = 0,
	SPI_EDGE_FALLING = 1,
	SPI_EDGE_LIMIT
};
    
enum{
	SPI_INTER_FLAG_FRAMEDONE = 0x1,
	SPI_INTER_FLAG_LIMIT,
};

enum{
	SPI_ENDIAN_LSB = 0,
	SPI_ENDIAN_MSB = 1,
	SPI_ENDIAN_LIMIT
};

enum{
	SPI_PATH_IMAGE = 0,
	SPI_PATH_REGISTER = 1,
	SPI_PATH_LIMIT
};

enum{
	SPI_FORMAT_RGB565 = 0,
	SPI_FORMAT_RGB666 = 1,
	SPI_FORMAT_RGB666_2_3 = 2,
	SPI_FORMAT_RGB888 = 3,
	SPI_FORMAT_RGB888_2_3 = 4,
	SPI_FORMAT_LIMIT
};

enum{
	SPI_STATUS_UNINIT = 0,
	SPI_STATUS_INIT = 1,
	SPI_STATUS_LIMIT
};
    
enum{
	SPI_CONETROLER_0 = 0,
	SPI_CONETROLER_1 = 1,
	SPI_CONETROLER_LIMIT
};  
    
enum{
	SPI_WORK_MODE_POLLING,
	SPI_WORK_MODE_DMA,
	SPI_WORK_MODE_LIMIT
};

enum{
	SPI_6_5M = 0,
	SPI_13M = 1,
	SPI_26M,
	SPI_52M,
	SPI_3_25M,
	SPI_1_625M,
	SPI_812_5k,
	SPI_CLK_LIMIT
};
    
typedef enum 
{
	spi_rx = 0,
	spi_tx,
	max_dir,
}spidir;

struct timing_spi {
	unsigned int wclk; /*KHz*/
	unsigned int rclk; /*KHz*/
};

struct spi_info{
	unsigned short line_num; /*3 or 4*/
	unsigned short interface_id; /*1 or 2*/
	unsigned short data_lane_num; /*1 or 2*/
	unsigned short format;
	unsigned short device_id; /*0 or 1*/
	unsigned short sample_edge;
	unsigned short force_cs; /*0-disable, 1-enable*/
	unsigned short endian;
	unsigned short reserved;
	struct timing_spi *timing;
};

struct s_spi_base_ctx{
	unsigned int base_addr;
	unsigned int sclk; /*KHz*/
	unsigned char cur_path;
	unsigned char cur_cs;
	unsigned char work_mode;
	unsigned char reserved;
};

struct s_spi_ctx{
	unsigned int base_addr;
	unsigned int sclk; /*KHz*/
	unsigned short cur_path;
	unsigned short cur_cs;
	unsigned short status;
	unsigned char work_mode;
	unsigned char reserved;
	struct spi_info info;
};


struct s_spi_ctx* spi_init(unsigned int sclk, struct spi_info *info, int work_mode);
int spi_write_cmd(struct s_spi_ctx *spi_ctx, unsigned int cmd, unsigned int bits);
int spi_write_data(struct s_spi_ctx *spi_ctx, unsigned int data, unsigned int bits);
int spi_read_data(struct s_spi_ctx *spi_ctx, unsigned int cmd, unsigned int cmd_bits,
	unsigned int *data,  unsigned int data_bits);
int spi_lcd_init(unsigned char controler);
void spi_set_clk_rate(unsigned int clk_dev);
void ssp_write_cmd_data_to_LCD(unsigned int cmd, unsigned int data,unsigned int data_bits,unsigned short line_num);
void ssp_write_data_to_LCD_Gram(unsigned short* data,unsigned int sum_pixel,unsigned int data_bits,unsigned short line_num);
void spi_dma_init(void);
void ssp_read_data_from_LCD(unsigned int *data,  unsigned int data_bits);
void wait_ssp_write_data_to_LCD_complete(void);
void spi_set_cs_high(void);
void spi_set_cs_low(void);
void LCD_Pinmuxcfg(unsigned int interface);
int spi_update(struct s_spi_ctx *spi_ctx, int work_mode);
void lcd_spi_set_data_mode(void);
void spi_write_data_dma(unsigned short* data,unsigned int sum_pixel,unsigned int data_bits,unsigned short line_num);
void lcd_spi_set_cmd_mode(void);
void spi_uninit(struct s_spi_ctx *spi_ctx);
void spi_reset(struct s_spi_ctx *spi_ctx);


#endif /*_SPI_DRV_H_*/
