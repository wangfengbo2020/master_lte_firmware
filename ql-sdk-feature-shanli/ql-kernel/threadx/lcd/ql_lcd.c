#include "quec_cust_feature.h"

#ifdef QL_LCD

#include <stdio.h>
#include "ql_lcd.h"
#include "quec_lcd.h"



int ql_lcd_init(ql_lcd_data_t *lcd_data)
{
    if(lcd_data == NULL)
    {
        return -1;
    }
    return quec_lcd_init((quec_lcd_data_t*)lcd_data);
}

int ql_lcd_dinit(void)
{
    return quec_lcd_dinit();
}

int ql_lcd_write_sync(unsigned char *pbuffer, unsigned short start_x, unsigned short start_y, unsigned short end_x, unsigned short end_y)
{
    if(pbuffer == NULL)
    {
        return -1;
    }
    return quec_lcd_write_sync(pbuffer,start_x,start_y,end_x,end_y);
}

int ql_lcd_clear_screen(unsigned short bg_color)
{
    return quec_lcd_clear_screen(bg_color);
}

int ql_lcd_wakeup(unsigned int level)
{
   return quec_lcd_wakeup(level);
}

int ql_lcd_display_on(void)
{
    return quec_lcd_display_on();
}

int ql_lcd_display_off(void)
{
    return quec_lcd_display_off();
}

int ql_spi_lcd_write_cmd(unsigned char cmd)
{
    return quec_spi_lcd_write_cmd(cmd);
}

int ql_spi_lcd_write_data(unsigned char data)
{
    return quec_spi_lcd_write_data(data);
}

unsigned int ql_lcd_read_id(void)
{
    return quec_lcd_read_id();
}

int ql_lcd_updata_config(ql_lcd_data_t *lcd_data)
{
    if(lcd_data == NULL)
    {
        return -1;
    }
   return quec_lcd_updata_config((quec_lcd_data_t*)lcd_data);
}

#endif
