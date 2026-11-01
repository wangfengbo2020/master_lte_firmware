#ifndef _PANEL_DRV_H_
#define _PANEL_DRV_H_

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

enum{
	LCD_CAP_NORMAL = 0,
	LCD_CAP_FAKE = 1, /*virtal panel*/
	LCD_CAP_POWERON = 2,
	LCD_CAP_NOTE = 4, /*has no te signal*/
	LCD_CAP_LIMIT
};

enum{
	LCD_INTERFACE_MCU = 0,
	LCD_INTERFACE_SPI = 1,
	LCD_INTERFACE_MIPI = 2,
	LCD_MODE_LIMIT
};

enum{
	LCD_TYPE_RGB = 0,
	LCD_TYPE_FSTN = 1,
	LCD_TYPE_LIMIT
};

enum{
	LCD_POLARITY_POS = 0,
	LCD_POLARITY_NEG,
	LCD_POLARITY_LIMIT
};
    
enum{
	LCD_WORK_MODE_POLLING,
	LCD_WORK_MODE_DMA,
	LCD_WORK_MODE_LIMIT
};
    
enum{
	LCD_ID_MAIN = 0,
	LCD_ID_SUB,
	LCD_ID_LIMIT
};

enum{
	PANEL_MODE_NORMAL,
	PANEL_MODE_ASSERT,
	PANEL_MODE_LIMIT
};

enum{
	PANEL_STATUS_POWEROFF,
	PANEL_STATUS_POWERON,
	PANEL_STATUS_LIMIT
};
enum 
{ 
   PANEL_CS_SET_LOW,
   PANEL_CS_SET_HIGH,
   PANEL_CS_SET_LIMIT
};
enum{
	LCM_INTERFACE_SPI_3W_1L_1IF,
	LCM_INTERFACE_SPI_3W_2L_1IF,
	LCM_INTERFACE_SPI_3W_1L_2IF,
	LCM_INTERFACE_SPI_3W_2L_2IF,
	LCM_INTERFACE_SPI_4W_1L_1IF,
	LCM_INTERFACE_SPI_4W_1L_2IF,
	LCM_INTERFACE_MCU,
	LCM_INTERFACE_MIPI,
	LCM_INTERFACE_LIMIT
};

enum{
	LCM_POWER_OFF,
	LCM_POWER_ON,
	LCM_POWER_LIMIT
};

struct panel_spec;

/* LCD operations */
struct panel_operations {
	int (*panel_interface_init)(struct panel_spec *self, unsigned int sclk, int work_mode); /*spi驱动初始化*/
	int (*panel_interface_reset)(struct panel_spec *self);                                  /*spi驱动复位*/
	int (*panel_interface_uninit)(struct panel_spec *self);                                 /*spi驱动去初始化*/
	int (*panel_interface_update)(struct panel_spec *self, int work_mode);         /*spi更新polling模式或者dma模式*/
	int (*panel_init)(struct panel_spec *self);                                             /*用于设置lcd横竖屏，等一些参数，预留接口*/
	int (*panel_invalid)(struct panel_spec *self, unsigned int start_x,             
						unsigned int start_y,  unsigned int end_x, unsigned int end_y);                 /*指定画图区域大小*/
	int (*panel_suspend)(struct panel_spec *self);                                          /*关闭lcd显示*/
	int (*panel_resume)(struct panel_spec *self);                                           /*打开lcd显示*/
	unsigned int (*panel_readid)(struct panel_spec *self);                                  /*读取lcd厂商id*/
	void (*panel_refresh)(struct panel_spec *self,
        struct asrlcdd_framebuffer_window *frame_window,unsigned short startX, unsigned short startY);  /*指定区域刷图*/ 
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
	unsigned short te_pol;             //unsigned short
	void *info;
	void *panel_if;
	struct panel_operations *ops;
};
struct panel_spec* lcd_get_panel(void);
void lcm_pin_cfg(struct panel_spec* panel);
int panel_sleep(struct panel_spec* panel);
int panel_wakeup(struct panel_spec* panel);
int panel_reset(struct panel_spec* panel);
unsigned int panel_read_id(struct panel_spec* panel);
int panel_refresh_lcd(struct panel_spec* panel,struct asrlcdd_framebuffer_window *frame_window,unsigned short startX, unsigned short startY);
void panel_uninit(struct panel_spec *panel, int lcd_id);
void panel_delay(int ms);
void panel_cs_control(unsigned char val);
int panel_init(struct panel_spec* panel, unsigned int sclk, int work_mode, int panel_is_ready, int lcd_id);
int panel_pin_cfg(void);
int panel_write_cmd(struct panel_spec *self, unsigned int cmd, unsigned int bits);
int panel_write_data(struct panel_spec *self, unsigned int data, unsigned int bits);
void panel_delay(int ms);


#endif /*_PANEL_DRV_H_*/

