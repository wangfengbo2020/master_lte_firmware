#include "plat_types.h"
#include "ql_updater_usr_func.h"
#include <stdio.h>

void cp_uart2_init(void);
extern int uart_printf(const char *fmt, ...);
int uart2_printf(const char *fmt, ...);
extern void panel_delay(int ms);

static unsigned char tmp_buf[60*60*2]={0}; /*color can change by yourself*/

/*
 *func: ql_updater_usr_func_init
 *desc: Initialize before upgrading
 *para: NA
 *return: NA
 */
extern int quec_lcd_init(void);
extern int quec_lcd_brightness_init(UINT8 level);
extern int quec_lcd_clear_screen(unsigned int bg_color);
extern void quec_lcd_block_write_sync(UINT16* buffer, UINT16 startx,UINT16 starty,UINT16 endx,UINT16 endy);
void ql_updater_usr_func_init(void)
{
    uart_printf("FOTA updater init!!\r\n");
#ifdef QL_UPDATER_LCD_SUPPORT
	quec_lcd_init();
	ql_lcd_set_brightness(3);
	quec_lcd_clear_screen((unsigned short)0x0000);//Clear the LCD color to black
	memset(tmp_buf, 0xFF, sizeof(tmp_buf));//White progress bar Buffer
#endif
    return;
}

/*
 *func: ql_upgrade_percent_callback
 *desc: Escalation progress report callback
 *para: 
 *      percent: Percentage of Upgrade progress
 *return: NA
 */
void ql_upgrade_percent_callback(unsigned int percent)
{
	
	if(QL_Error_base == (percent&QL_Error_base))
	{
		unsigned int errorcode = percent;
		uart_printf("FOTA updater occured error:%08x!!\r\n",errorcode);
	}
	else
    {
		uart_printf("FOTA updater percent = %d!!\r\n",percent);
#ifdef QL_UPDATER_LCD_SUPPORT
		/*change the tmp_buf[] as the percent, before you write*/
		quec_lcd_block_write_sync(tmp_buf, 16+percent, 60, 16+percent+1, 60+12);
#endif
	}
    
    return;
}

/******************************************
port:
0: gpio16~19
1/2: gpio33~36
3: gpio 12~15

clk:
#define _APBC_SSP_FNCLKSEL_6_5MHZ	(0x00)
#define _APBC_SSP_FNCLKSEL_13MHZ	(0x01)
#define _APBC_SSP_FNCLKSEL_26MHZ	(0x02)
#define _APBC_SSP_FNCLKSEL_52MHZ	(0x03)
#define _APBC_SSP_FNCLKSEL_3_25MHZ	(0x04)
#define _APBC_SSP_FNCLKSEL_1_625MHZ	(0x05)
#define _APBC_SSP_FNCLKSEL_812_5KHZ	(0x06)
******************************************/
void ql_set_external_fs_info(int *port, int *clk, unsigned int *start_addr, unsigned int *size)
{
	if(port)
		*port = 1;
	
	if(clk)
		*clk = 0x02;
	
	if(start_addr)
		*start_addr = 0;
	
	if(size)
		*size = 0x100000;
}

