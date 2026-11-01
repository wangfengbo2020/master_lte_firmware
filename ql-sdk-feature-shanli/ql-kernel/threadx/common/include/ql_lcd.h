#ifndef _QL_LCD_H_
#define _QL_LCD_H_

typedef struct ql_spi_lcd_write_struct {
	unsigned char type;		/* SPI_WRITE_CMD / SPI_WRITE_DATA / SPI_WRITE_DELAY */
	unsigned char value;
	unsigned char data_length;	/* Only for SPI_WRITE_CMD */
}ql_spi_lcd_write_t;

typedef struct ql_lcd_data_struct 
{
    ql_spi_lcd_write_t* init_para;
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
}ql_lcd_data_t;

enum
{
    QL_LCD_SLEEP,
    QL_LCD_WAKE_UP,
};
    
int ql_lcd_init(ql_lcd_data_t *lcd_data);
int ql_lcd_clear_screen(unsigned short bg_color);  
int ql_lcd_wakeup(unsigned int level);
int ql_lcd_display_on(void);
int ql_lcd_display_off(void);
int ql_spi_lcd_write_cmd(unsigned char cmd);
int ql_spi_lcd_write_data(unsigned char data);
int ql_lcd_updata_config(ql_lcd_data_t *lcd_data);
int ql_lcd_write_sync(unsigned char *pbuffer, unsigned short start_x, unsigned short start_y, unsigned short end_x, unsigned short end_y);
unsigned int ql_lcd_read_id(void);

#endif
