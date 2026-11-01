#include "panel_drv.h"
#include "lcd_log.h"
#include "spi_drv.h"
#include "quec_lcd.h"

int g_panel_mode = PANEL_MODE_NORMAL;
#define MAX_PANEL_COUNT 1
int g_panel_status[MAX_PANEL_COUNT] = {
	PANEL_STATUS_POWEROFF
};
	
extern quec_mutex_t   g_cramem_mutex;
static int quec_lcd_panel_interface_init(struct panel_spec *self, unsigned int sclk, int work_mode);
static int quec_lcd_panel_interface_update(struct panel_spec *self, int work_mode);
static int quec_lcd_panel_init(struct panel_spec *self);
static int quec_lcd_panel_invalid(struct panel_spec *self, unsigned int start_x, unsigned int start_y, unsigned int end_x, unsigned int end_y);
static unsigned int quec_lcd_panel_readid(struct panel_spec *self);
static int quec_lcd_panel_display_on(struct panel_spec *self);
static int quec_lcd_panel_display_off(struct panel_spec *self);
static void quec_lcd_panel_refresh(struct panel_spec *self,struct asrlcdd_framebuffer_window *frame_window,unsigned short startX, unsigned short startY);
static int lcd_panel_spi_uninit(struct panel_spec *self);
static int lcd_panel_spi_reset(struct panel_spec *self);

/********************lcd设备描述***************************/
const static struct panel_operations lcd_spi_ops = {
	quec_lcd_panel_interface_init,
    lcd_panel_spi_reset,
	lcd_panel_spi_uninit,
	quec_lcd_panel_interface_update,
	quec_lcd_panel_init,
	quec_lcd_panel_invalid,
	quec_lcd_panel_display_off,
	quec_lcd_panel_display_on,
	quec_lcd_panel_readid,
	quec_lcd_panel_refresh
};

static struct timing_spi lcd_spi_timing = {
	SPI_6_5M,//62500, //31200, //26000, // /*kHz*/
	SPI_3_25M, /*kHz*/
};

static struct spi_info lcd_spi_info_customer = {
    4,
    1,
    1,
    SPI_FORMAT_RGB565,
    1,
    SPI_EDGE_RISING,
    0,
    SPI_ENDIAN_MSB,
    0,
    (struct timing_spi*)&lcd_spi_timing,
};

struct panel_spec lcd_spi_spec_customer = {
	"quec_Lcd",
	0x7c89f0,
	QUEC_LCD_CAP_NOTE,
	128,
	128,
	LCD_INTERFACE_SPI,
	LCD_TYPE_RGB,
	LCD_POLARITY_POS,
	(void*)&lcd_spi_info_customer,
	NULL,
	(struct panel_operations*)&lcd_spi_ops,
};

struct panel_spec* lcd_get_panel(void)
{
    return &lcd_spi_spec_customer;
}
void lcd_msleep(unsigned int ms)
{
	quec_rtos_task_sleep_ms(ms);
}

void lcd_udelay(int us)
{
	volatile unsigned int i;
	for(i=0; i<us*100;i++)
		i = i+1;
}

void lcd_mdelay(unsigned int ms)
{
	volatile unsigned int i;
	for(i=0; i<ms;i++)
		lcd_udelay(100);
}

void lcd_pin_cfg(struct panel_spec* panel)
{
	struct spi_info	*spi = NULL;

	if(panel->interf == LCD_INTERFACE_SPI){
		spi = (struct spi_info*)panel->info;
		if(spi->line_num == 3){
			if(spi->data_lane_num == 1){
				if(spi->interface_id == 1){
					LCD_Pinmuxcfg(LCM_INTERFACE_SPI_3W_1L_1IF);
				} else{
					LCD_Pinmuxcfg(LCM_INTERFACE_SPI_3W_1L_2IF);
				}
			} else{
				if(spi->interface_id == 1){
					LCD_Pinmuxcfg(LCM_INTERFACE_SPI_3W_2L_1IF);
				} else{
					LCD_Pinmuxcfg(LCM_INTERFACE_SPI_3W_2L_2IF);
				}
			}
		} else { /*4 wire spi*/
			if(spi->interface_id == 1){
				LCD_Pinmuxcfg(LCM_INTERFACE_SPI_4W_1L_1IF);
			} else{
				LCD_Pinmuxcfg(LCM_INTERFACE_SPI_4W_1L_2IF);
			}
		}
	} 
}

int panel_pin_cfg(void)
{
    struct panel_spec* panel=lcd_get_panel();
    if (panel == NULL)
	{
		LCDLOGE("quec_lcd_init failed, para invalid!!! \r\n");
		return -1;
	}
    lcd_pin_cfg(panel);
    return 0;
}
int panel_sleep(struct panel_spec* panel)
{
	LCDLOGD("+++");
	if(panel->ops->panel_suspend){
		return panel->ops->panel_suspend(panel);
	}
	LCDLOGD("---");
	return -1;
}

int panel_wakeup(struct panel_spec* panel)
{
	LCDLOGD("+++");

	if(panel->ops->panel_resume){
		return panel->ops->panel_resume(panel);
	}
	LCDLOGD("---");
	return -1;
}

int panel_reset(struct panel_spec* panel)
{
	if(NULL != panel->ops->panel_interface_reset){
		panel->ops->panel_interface_reset(panel);
	}
	return -1;
}
int panel_write_cmd(struct panel_spec *self, unsigned int cmd, unsigned int bits)
{
    struct s_spi_ctx* spi_ctx = self->panel_if;

    return spi_write_cmd(spi_ctx, cmd, bits);
    
}

int panel_write_data(struct panel_spec *self, unsigned int data, unsigned int bits)
{
    struct s_spi_ctx* spi_ctx = self->panel_if;

    return spi_write_data(spi_ctx, data, bits);
    
}
unsigned int panel_read_id(struct panel_spec* panel)
{
    if(NULL != panel->ops->panel_readid){
		return panel->ops->panel_readid(panel);
	}
    return 0;
}

int panel_refresh_lcd(struct panel_spec* panel,struct asrlcdd_framebuffer_window *frame_window,unsigned short startX, unsigned short startY)
{
    if(NULL != panel->ops->panel_refresh){
		 panel->ops->panel_refresh(panel,frame_window,startX,startY);
         return 0;
	}
    return -1;  
}
void panel_uninit(struct panel_spec *panel, int lcd_id)
{
	int* p_panel_status;

	if(NULL == panel){
		LCDLOGE("Invalid param");
		return;
	}

	if(lcd_id >= MAX_PANEL_COUNT){
		LCDLOGE("Invalid lcd_id (%d)", lcd_id);
		return;
	}

	if (NULL != panel->ops->panel_interface_uninit){
		if (panel->ops->panel_interface_uninit(panel) != 0){
			LCDLOGE("ERROR: panel_uninit: lcd interface uninit fail\r\n");
		}
	}

	p_panel_status = &g_panel_status[lcd_id];
	*p_panel_status = PANEL_STATUS_POWEROFF;
}

void panel_delay(int ms)
{
	if(PANEL_MODE_ASSERT == g_panel_mode)
		lcd_mdelay(ms);
	else
		lcd_msleep(ms);
}
void panel_cs_control(unsigned char val)
{
    if(val == PANEL_CS_SET_HIGH)
        spi_set_cs_high();
    else
        spi_set_cs_low();
}
int panel_init(struct panel_spec* panel, unsigned int sclk, int32_t work_mode, int panel_is_ready, int lcd_id)
{
	//extern struct s_lcd_ctx *g_plcd;
	int* p_panel_status;
    int ret = 0;
	LCDLOGD("INFO: panel_init (ready: %d) +++\r\n", panel_is_ready);

	if(NULL == panel){
		LCDLOGE("ERROR: panel_init, Invalid param\r\n");
		return -1;
	}

	if(lcd_id >= MAX_PANEL_COUNT){
		LCDLOGE("ERROR: panel_init, Invalid lcd_id (%d)\r\n", lcd_id);
		return -1;
	}

	if(LCD_WORK_MODE_POLLING == work_mode)
		g_panel_mode = PANEL_MODE_ASSERT;
	else
		g_panel_mode = PANEL_MODE_NORMAL;

	p_panel_status = &g_panel_status[lcd_id]; 

	if(*p_panel_status == PANEL_STATUS_POWERON){
		if(NULL != panel->ops->panel_interface_update){
			panel->ops->panel_interface_update(panel, work_mode);
		}
        else
		return -1;
	}

	if(NULL != panel->ops->panel_interface_init){
		panel->ops->panel_interface_init(panel, sclk, work_mode);
	}
    else
        return -1;

	if(NULL != panel->ops->panel_init){
		panel->ops->panel_init(panel);
	}
    else
        return -1;
    
	*p_panel_status = PANEL_STATUS_POWERON;
	LCDLOGD("INFO: panel_init ---\r\n");
	return 0;
}

/***********************************************************************
 *
 * Name:  quec_lcd_panel_interface_init     
 *
 * Description: 1601的lcd控制器或者1603的spi总线初始化
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/

static int quec_lcd_panel_interface_init(struct panel_spec *self, unsigned int sclk, int work_mode)
{
	struct s_spi_ctx *spi_ctx = NULL;
	struct spi_info * spi = NULL;

	LCDLOGD(" panel_interface_init, spi+++\r\n");

	if(NULL == self){
		LCDLOGD(" panel_interface_init, Invalid param\r\n");
		return -1;
	}

	spi = (struct spi_info *)self->info;
	spi_ctx = spi_init(sclk, spi, work_mode);
	if(NULL == spi_ctx){
		LCDLOGD(" panel_interface_init, spi init fail!\r\n");
		return -1;
	}
	self->panel_if = (void*)spi_ctx;
	return 0;
}
/***********************************************************************
 *
 * Name:    quec_lcd_panel_interface_update   
 *
 * Description: 切换lcd的工作模式
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
static int quec_lcd_panel_interface_update(struct panel_spec *self, int work_mode)
{
	int ret;

	if(NULL == self || NULL == self->panel_if){
		LCDLOGD("ERROR: lcd_panel_interface_update, Invalid param\r\n");
		return -1;
	}
	
	ret = spi_update((struct s_spi_ctx *)self->panel_if, work_mode);
	return ret;
}

/***********************************************************************
 *
 * Name:   quec_lcd_panel_init    
 *
 * Description: 预留接口，可以设置lcd角度
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
static int quec_lcd_panel_init(struct panel_spec *self)
{
	if(NULL == self){
		LCDLOGD("ERROR: panel_init, Invalid param\r\n");
		return -1;
	}

	if(NULL == self->panel_if){
		LCDLOGD("ERROR: panel_init, mcu has not been inited!\r\n");
		return -1;
	}

	return 0;
}
/***********************************************************************
 *
 * Name:      quec_lcd_panel_invalid 
 *
 * Description: 向lcd发送显示范围指令
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
static int quec_lcd_panel_invalid(struct panel_spec *self, unsigned int start_x, unsigned int start_y, unsigned int end_x, unsigned int end_y)
{
	struct s_spi_ctx* spi_ctx = NULL;

	if(NULL == self){
		LCDLOGD("ERROR: lcd_panel_invalid, Invalid param\r\n");
		return -1;
	}

	if(NULL == self->panel_if){
		LCDLOGD("ERROR: lcd_panel_invalid, mcu has not been inited!\r\n");
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
/***********************************************************************
 *
 * Name: quec_lcd_panel_readid      
 *
 * Description: 获取lcd的id号
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
static unsigned int quec_lcd_panel_readid(struct panel_spec *self)
{
	struct s_spi_ctx* spi_ctx = NULL;
    unsigned int read_id = 0;

	if(NULL == self){
		LCDLOGD("ERROR: panel_readid, Invalid param\r\n");
		return 0;
	}

	if(NULL == self->panel_if){
		LCDLOGD("ERROR: panel_readid, spi has not been inited!\r\n");
		return 0;
	}

	spi_ctx = (struct s_spi_ctx*)self->panel_if;
    
	spi_read_data(spi_ctx, 0xDA, 8, &read_id, 8);	
	LCDLOGD("INFO: panel_readid, read 0xDA receive 0x%x!\r\n",read_id);
	
	spi_read_data(spi_ctx, 0xDB, 8, &read_id, 8);
	LCDLOGD("INFO: panel_readid, read 0xDB receive 0x%x!\r\n",read_id);

	spi_read_data(spi_ctx, 0xDC, 8, &read_id, 8);
	LCDLOGD("INFO: panel_readid, read 0xDC receive 0x%x!\r\n",read_id);

	spi_read_data(spi_ctx, 0x04, 8, &read_id, 24);
	LCDLOGD("INFO: panel_readid, read 0x04 receive 0x%x!\r\n",read_id);

    return read_id;
}
/***********************************************************************
 *
 * Name:       
 *
 * Description: 
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
static int quec_lcd_panel_display_on(struct panel_spec *self)
{
	struct s_spi_ctx* spi_ctx = NULL;

	if(NULL == self){
		LCDLOGD("ERROR: lcd_panel_display_on, Invalid param\r\n");
		return -1;
	}

	if(NULL == self->panel_if){
		LCDLOGD("ERROR: lcd_panel_display_on, mcu has not been inited!\r\n");
		return -1;
	}

	spi_ctx = (struct s_spi_ctx*)self->panel_if;
	quec_rtos_mutex_lock(g_cramem_mutex,QUEC_WAIT_FOREVER);
	spi_write_cmd(spi_ctx, 0x11, 8);
	panel_delay(120);
	spi_write_cmd(spi_ctx, 0x29, 8);
	panel_delay(20);
	quec_rtos_mutex_unlock(g_cramem_mutex);
    return 0;
}
/***********************************************************************
 *
 * Name:       
 *
 * Description: 
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
static int quec_lcd_panel_display_off(struct panel_spec *self)
{
	struct s_spi_ctx* spi_ctx = NULL;

	if(NULL == self){
		LCDLOGD("ERROR: lcd_panel_display_off, Invalid param\r\n");
		return -1;
	}

	if(NULL == self->panel_if){
		LCDLOGD("ERROR: lcd_panel_display_off, mcu has not been inited!\r\n");
		return -1;
	}

	spi_ctx = (struct s_spi_ctx*)self->panel_if;
	quec_rtos_mutex_lock(g_cramem_mutex,QUEC_WAIT_FOREVER);
	spi_write_cmd(spi_ctx, 0x28, 8);
	panel_delay(20);
	spi_write_cmd(spi_ctx, 0x10, 8);
	panel_delay(120);
	quec_rtos_mutex_unlock(g_cramem_mutex);
    return 0;
}

/***********************************************************************
 *
 * Name:       
 *
 * Description: 
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
static void quec_lcd_panel_refresh(struct panel_spec *self,struct asrlcdd_framebuffer_window *frame_window,unsigned short startX, unsigned short startY)
{
    struct s_spi_ctx* panel_if = (struct s_spi_ctx *)self->panel_if;
	struct spi_info * spi = &(panel_if->info);
    unsigned int size = 0;
    unsigned short *addr = NULL;
    struct asrlcdd_roi_info *src_roi_info = NULL;
    struct asrlcdd_framebuffer_info *src_frame_buffer = NULL;
    LCDLOGD("++++++\r\n");
	if (NULL == self) {
		LCDLOGE("ERROR: panel_init, Invalid param\r\n");
		return;
	}
	
	if (NULL == panel_if) {
		LCDLOGE("ERROR: panel_init, mcu has not been inited!\r\n");
		return;
	}
	src_roi_info = &(frame_window->roi_info);
    src_frame_buffer = &(frame_window->frame_info);
    size = (src_roi_info->height)*(src_roi_info->width);
    addr = (unsigned short *)src_frame_buffer->pbuffer;
    if(self->ops->panel_invalid) //Set up LCD area pony add 2021-2-7
    self->ops->panel_invalid(self,startX,startY,src_roi_info->width+startX-1,src_roi_info->height+startY-1);
    else 
    LCDLOGE("panel_invalid not init\r\n");
	if(spi->line_num ==4)
	{
        lcd_spi_set_data_mode();
	}
	
	spi_set_clk_rate(spi->timing->wclk);
	
    panel_cs_control(PANEL_CS_SET_LOW);
    if(spi->line_num==4)//只有4线lcd才支持dma pony add 2021-06-23
    {
        if(panel_if->work_mode == SPI_WORK_MODE_DMA)
        {
            CacheCleanMemory((void *)addr, src_roi_info->height*src_roi_info->width*2);
            spi_write_data_dma(addr,size*2,16,spi->line_num);
        }
        else
    	ssp_write_data_to_LCD_Gram(addr,size,16,spi->line_num);//ssp_write_data_to_LCD_Gram(image,128*128,16,spi->line_num);
    }
    else 
    {
        ssp_write_data_to_LCD_Gram(addr,size,16,spi->line_num);
    }
	wait_ssp_write_data_to_LCD_complete();

	
    panel_cs_control(PANEL_CS_SET_HIGH);
	
}

static int lcd_panel_spi_uninit(struct panel_spec *self)
{
	struct s_spi_ctx *spi_ctx = NULL;

	LCDLOGD("+++");

	if(NULL == self){
		LCDLOGE("Invalid param");
		return -1;
	}

	spi_ctx = (struct s_spi_ctx*)self->panel_if;
	spi_uninit(spi_ctx); /*此接口未实现*/
	self->panel_if = NULL;
	LCDLOGD("---");
	return 0;
}

static int lcd_panel_spi_reset(struct panel_spec *self)
{
	struct s_spi_ctx *spi_ctx = NULL;

	LCDLOGD("spi+++");

	if(NULL == self){
		LCDLOGE("Invalid param");
		return -1;
	}

	spi_ctx = (struct s_spi_ctx*)self->panel_if;
	spi_reset(spi_ctx);/*此接口未实现*/
	LCDLOGD("spi---");
	return 0;
}