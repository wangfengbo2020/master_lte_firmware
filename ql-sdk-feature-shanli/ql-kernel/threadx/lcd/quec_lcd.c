#include "quec_cust_feature.h"

#ifdef QL_LCD

#include <stdio.h>
#include "quec_lcd.h"
#include "panel_drv.h"
#include "lcd_log.h"
#include "spi_drv.h"
#include "quec_rtos.h"

/*******************************************************************
                        global variable
******************************************************************/
static unsigned char    visit_flag = 0;
quec_mutex_t                    g_cramem_mutex = 0;
unsigned char           g_quec_lcd_status;

static int quec_asr_lcd_open(struct panel_spec *panel, unsigned int worke_mode);
static int quec_asr_lcd_close(void);

/***********************************************************************
 *
 * Name:   quec_lcd_write_function    
 *
 * Description:  将客户传入的lcd驱动数组写入lcd寄存器
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
static int quec_lcd_write_function(quec_spi_lcd_write_t *init_data, unsigned int length)
{
	unsigned int i = 0;
    unsigned char data_idx = 0;
    unsigned char data_length = 0;
    quec_spi_lcd_write_t *pdata = init_data;
    struct panel_spec* lcd_panel=lcd_get_panel();
    
    if (pdata == NULL || length == 0) {
        LCDLOGE(" param is error!! \n");
        return -1;
    }

    for (i = 0; i < length;) {
        i++;
        if (pdata->type == QUEC_LCD_CMD) {
            panel_write_cmd(lcd_panel, pdata->value, 8);
            if (pdata->data_length > 0) {
                data_length = pdata->data_length;
                pdata++;
                for (data_idx = 0; (data_idx < data_length) && (i < length); data_idx++, i++) {
                    if (pdata->type != QUEC_LCD_DATA) {
                        LCDLOGE(" SPI data is error[%u, %u], please check!!!!!!!! \n", i, data_idx);
                        return -1;
                    }
                    else {
                        panel_write_data(lcd_panel, pdata->value, 8);
                        pdata++;
                    }
                }
            }
            else {
                pdata++;
            }
        }
        else if (pdata->type == QUEC_LCD_DELAY) {
            panel_delay(pdata->value);
            pdata++;
        }
        else {
            LCDLOGE("SPI data is error[%u, %u], please check!!!!!!!! \n",i, pdata->type);
            return -1;
        }
    }
    return 0;
}

int quec_lcd_init(quec_lcd_data_t *lcd_data)
{
    struct panel_spec* lcd_panel = lcd_get_panel();
    struct spi_info* lcd_spi_info = lcd_panel->info ;
    struct timing_spi* spi_clk = lcd_spi_info->timing;
    
    QuecOSStatus os_status = 0;
	if (!visit_flag) 
	{
		LCDLOGD("quec_lcd_init!!! \n");
		if ( NULL==lcd_data) 
		{
			LCDLOGE("quec_lcd_init failed, para invalid!!! \r\n");
            return -1;
		}
		visit_flag = 1;
		/* update spi lcd transfer clk */
		if (lcd_data->spi_wclk>=QUEC_SPI_CLK_LIMIT) 
		{
			lcd_spi_info->timing->wclk = QUEC_SPI_LCD_CLK_6_5M;
		}
		else 
		{
			lcd_spi_info->timing->wclk = lcd_data->spi_wclk;
		}
        /* update spi lcd transfer clk */
		if (lcd_data->spi_rclk>=QUEC_SPI_CLK_LIMIT) 
		{
			lcd_spi_info->timing->rclk = QUEC_SPI_LCD_CLK_6_5M;
		}
		else 
		{
			lcd_spi_info->timing->rclk = lcd_data->spi_rclk;
		}

		if (3 == lcd_data->line_num) 
		{
			lcd_spi_info->line_num = 3;
		}
		else 
		{
			lcd_spi_info->line_num = 4;
		}
		lcd_spi_info->data_lane_num = lcd_data->data_line;
		lcd_spi_info->format = lcd_data->format;
		lcd_spi_info->sample_edge = lcd_data->sample_edge;
		lcd_spi_info->endian = lcd_data->endian;
		lcd_panel->type = lcd_data->type;
		lcd_panel->width = lcd_data->width;
		lcd_panel->height = lcd_data->height;
		lcd_panel->panel_id = lcd_data->lcd_id;
		lcd_panel->cap = lcd_data->te_signal;
        
        os_status = quec_rtos_mutex_create(&g_cramem_mutex);
        if(os_status != 0)
        {
            LCDLOGE("quec_lcd_init failed, mutex create failed\r\n");
            return -1;
        }
		quec_asr_lcd_open(lcd_panel,lcd_data->work_mode);
		
		ql_gpio_set_level(QUEC_LCD_SPI_RST_NUM,1);
 		ql_rtos_task_sleep_ms(120);
  		ql_gpio_set_level(QUEC_LCD_SPI_RST_NUM,0);
  		ql_rtos_task_sleep_ms(120);
  		ql_gpio_set_level(QUEC_LCD_SPI_RST_NUM,1);
  		ql_rtos_task_sleep_ms(120);
  		LCDLOGE("LCD RST OK\r\n");
		
        if((NULL!=lcd_data->init_para) && (lcd_data->init_para_len>0))
        {
            quec_lcd_write_function(lcd_data->init_para, lcd_data->init_para_len);
        }
	}

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
int quec_lcd_dinit(void)
{
    int ret = -1;
    QuecOSStatus os_status = 0;
    if(visit_flag)
    {
        quec_rtos_mutex_delete(g_cramem_mutex);
        if(os_status != 0)
        {
            LCDLOGE("quec_lcd_init failed, mutex create failed\r\n");
            return -1;
        }
        ret = quec_asr_lcd_close();
        visit_flag=0;
    }
    return ret;
}

/***********************************************************************
 *
 * Name:  quec_spi_lcd_write_sync     
 *
 * Description: 600N同步刷屏接口 pony add 2021-03-19
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
 static int quec_spi_lcd_write_sync(struct asrlcdd_framebuffer_window *frame_window,
	uint16_t startX, uint16_t startY)
{
    struct panel_spec* lcd_panel=lcd_get_panel();
	if(NULL == lcd_panel){
		LCDLOGE("panel has not been inited!\r\n");
		return -1;
	}
		if(NULL == g_cramem_mutex)
	{
		LCDLOGE("g_cramem_mutex has not been inited!\r\n");
		return -1;
	}
    quec_rtos_mutex_lock(g_cramem_mutex,QUEC_WAIT_FOREVER);
	panel_refresh_lcd(lcd_panel,frame_window,startX,startY);
    quec_rtos_mutex_unlock(g_cramem_mutex);
	return 0;
}
    
/***********************************************************************
 *
 * Name:       
 *
 * Description: LCD同步刷新的接口，此接口会在LCD一次DMA发送完成后返回               8
 *              此接口等待LCD DMA发送数据完成，但是并不影响更低优先级的任务得到调度
 *              此接口刷图出错会立即返回
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
int quec_lcd_write_sync(unsigned char *pbuffer, unsigned short start_x, unsigned short start_y, unsigned short end_x, unsigned short end_y)
{
	struct asrlcdd_framebuffer_window fb_win;
	unsigned short height = end_y - start_y +1;
	unsigned short width  = end_x - start_x +1;

	if (NULL == pbuffer) 
	{
		LCDLOGE("quec_lcd_write failed, pbuffer is null! \n");
		return -1;
	}

	fb_win.frame_info.pbuffer   = pbuffer;
	fb_win.frame_info.stride    = width * 2;//width*2 //这里代表要刷新的图片一行的字节数，仅支持RGB565的格式
	fb_win.frame_info.height    = height;
	
	fb_win.roi_info.startX      = 0; 
	fb_win.roi_info.startY      = 0;
	fb_win.roi_info.width       = width;
	fb_win.roi_info.height      = height;	
    
    if(0 != quec_spi_lcd_write_sync(&fb_win, start_x, start_y)) //同步刷新---立即开启DMA传送
	{
		LCDLOGE("quec_lcd_write_sync failed:\n");
		return -1;
	}
	return 0;
}

/***********************************************************************
 *
 * Name: quec_lcd_clear_screen      
 *
 * Description: Clear screen function
 *
 * Parameters: bg_color (rgb565)
 *
 * Returns: 0:success
 			other:fail
 *
 * Notes:
 *
 ***********************************************************************/
int quec_lcd_clear_screen(unsigned short bg_color)
{
    int i,j = 0;
    static unsigned char *clear_buf = NULL;
    struct panel_spec* lcd_panel=lcd_get_panel();
    
    clear_buf = (unsigned char *)malloc(lcd_panel->width*lcd_panel->height*2);
    if(clear_buf == NULL){
        return -1;
    }
    memset(clear_buf, 0 , lcd_panel->width*lcd_panel->height*2);
    for(i = 0; i < lcd_panel->height; i++){
        for(j = 0; j < lcd_panel->width; j++){
        *((unsigned short*)(clear_buf+j*2+lcd_panel->width*i*2)) = bg_color;
        }
    }
    quec_lcd_write_sync(clear_buf, 0, 0, lcd_panel->width-1, lcd_panel->height-1);
    if(clear_buf) 
        free(clear_buf);
    return 0; 
}

 /***********************************************************************
 *
 * Name:       
 *
 * Description: 600nlcd保持唤醒接口/休眠 
 *
 * Parameters:level:0-31
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
int quec_lcd_wakeup(unsigned int level)
{
	return 0;
}

/***********************************************************************
 *
 * Name:       
 *
 * Description: 开始lcd显示
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
int quec_lcd_display_on(void)
{
	 struct panel_spec* lcd_panel=lcd_get_panel();
    int ret = 0;
	if(NULL == lcd_panel) {
		LCDLOGE(" lcd_panel_display_on, mcu has not been inited!\r\n");
		return -1;
	}
    ret = panel_wakeup(lcd_panel);
    return ret;

}

/***********************************************************************
 *
 * Name:       
 *
 * Description: 停止lcd显示
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
int quec_lcd_display_off(void)
{
	struct panel_spec* lcd_panel=lcd_get_panel();
    int ret = 0;
	if(NULL == lcd_panel){
		LCDLOGE("lcd_panel_display_off, mcu has not been inited!\r\n");
		return -1;
	}
    ret = panel_sleep(lcd_panel);
    return ret;
}
/***********************************************************************
 *
 * Name:       
 *
 * Description: lcd 写指令
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
int quec_spi_lcd_write_cmd(unsigned char cmd)
{
	struct panel_spec* lcd_panel=lcd_get_panel();
    int ret = 0;
	if(NULL ==lcd_panel){
		LCDLOGE("lcd_panel_display_off, mcu has not been inited!\r\n");
		return -1;
	}
	quec_rtos_mutex_lock(g_cramem_mutex,QUEC_WAIT_FOREVER);
	ret = panel_write_cmd(lcd_panel, cmd, 8);
	quec_rtos_mutex_unlock(g_cramem_mutex);

	return ret;
}
/***********************************************************************
 *
 * Name:       
 *
 * Description: lcd 写数据
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
int quec_spi_lcd_write_data(unsigned char data)
{
	struct panel_spec* lcd_panel=lcd_get_panel();
    int ret = 0;
	if(NULL == lcd_panel){
		LCDLOGE("lcd_panel_display_off, mcu has not been inited!\r\n");
		return -1;
	}
	quec_rtos_mutex_lock(g_cramem_mutex,QUEC_WAIT_FOREVER);
	ret = panel_write_data(lcd_panel, data, 8);
	quec_rtos_mutex_unlock(g_cramem_mutex);
	
	return ret;
}

/***********************************************************************
 *
 * Name:  quec_lcd_updata_config     
 *
 * Description: 更新lcd驱动
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
int quec_lcd_updata_config(quec_lcd_data_t *lcd_data)
{
	int ret = 0;
    unsigned int worke_mode = 0;
    struct panel_spec* self=lcd_get_panel();
	if (NULL==lcd_data|| self==NULL)
	{
		LCDLOGE("quec_lcd_init failed, para invalid!!! \r\n");
		return -1;
	}
	struct spi_info* spi_ctx = self->info;
	
	spi_ctx->timing->wclk = lcd_data->spi_wclk;
	spi_ctx->line_num = lcd_data->line_num;
	spi_ctx->data_lane_num = lcd_data->data_line;
	spi_ctx->format = lcd_data->format;
	spi_ctx->sample_edge = lcd_data->sample_edge;
	spi_ctx->endian = lcd_data->endian;
	self->width = lcd_data->width;
	self->height = lcd_data->height;
	self->panel_id = lcd_data->lcd_id;
	self->cap = lcd_data->te_signal;
    worke_mode = lcd_data->work_mode;

	quec_rtos_mutex_lock(g_cramem_mutex,QUEC_WAIT_FOREVER);
	ret = panel_init(self, SPI_SCLK_FREQ, worke_mode,0, LCD_ID_MAIN);
	quec_rtos_mutex_unlock(g_cramem_mutex);

	return ret;
}

/***********************************************************************
 *
 * Name:       
 *
 * Description: 读lcd的id
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 *
 ***********************************************************************/
unsigned int quec_lcd_read_id(void)
{
    unsigned int read_id = 0;
	struct panel_spec* self=lcd_get_panel();
    if( self==NULL)
	{
		LCDLOGE("quec_lcd_init failed, para invalid!!! \r\n");
		return 0;
	}
	quec_rtos_mutex_lock(g_cramem_mutex,QUEC_WAIT_FOREVER);
    read_id = panel_read_id(self);
	quec_rtos_mutex_unlock(g_cramem_mutex);
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
static int quec_asr_lcd_open(struct panel_spec *panel, unsigned int worke_mode)
{
	struct s_lcd_ctx *lcd = NULL;
	int ret = -1;

	LCDLOGI("quec_asr_lcd_open+++");

	if(g_quec_lcd_status != LCD_STATUS_POWEROFF){
		LCDLOGW("asrlcd has been opened!");
		return 0;
	}
    
    struct spi_info *spi_ctx = (struct spi_info *)panel->info;
    LCDLOGD("spi_ctx->line_num = %d",spi_ctx->line_num);
    ret = panel_pin_cfg();
    if(ret !=0)
    {
       LCDLOGE(" panel_init,pin cfg failed"); 
       return ret;
    }
    panel_cs_control(PANEL_CS_SET_HIGH);
	ret = panel_init(panel, SPI_SCLK_FREQ, worke_mode,0, LCD_ID_MAIN);
	if(0 != ret){
		LCDLOGE("ERR: quec_asr_lcd_open: panel_init fail");
		return -1;
	} 
    //panel_read_id(panel);
    g_quec_lcd_status = LCD_STATUS_POWERON;
	LCDLOGI(" quec_asr_lcd_open END");
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
static int quec_asr_lcd_close(void)
{
    return 0;
}




#ifdef __QUEC_CAMERA__

/******EC600N preview code add by pony 2021-03-01******/
#define CAM_SW_ROTATE_0    (0)
#define CAM_SW_ROTATE_90   (1)
#define CAM_SW_ROTATE_180  (2)
#define CAM_SW_ROTATE_270  (3)
#define RGB565 (1)
#define BINARY (0)
/*****************************************
**pony 2021-02-19新增查表法提高预览的速率
**说明：u取值范围0-255v，取值范围0-255
*****************************************/
int R_V[256];
int G_V[256],G_U[256];
int B_U[256];
void quec_uv_table_init(void)//初始化uv表
{
    int i;
    for(i=0;i<256;i++)
    {   
       R_V[i] = (1.402 * (i - 128));
       G_V[i] = (0.71414*(i - 128));
       G_U[i] = (0.34413*(i - 128));
       B_U[i] = (1.772*(i - 128));   
    }
}

//灰度图转二值黑白 pony add 2021-03-18
void Quec_CAM_Y_TO_Binary(uint_16 * des,uint_32 Bwidth,uint_32 Bheigth,uint_8 *pYuvData,uint_32 Ywidth,uint_32 Yheigth)//将灰度图表转换为二值图
{
    static uint_32 t = 0;
    static uint_32 nyuvWidth=0,nyuvHeight=0;
    static uint_32 nBWidth=0,nBHeight=0;
    static float zoom_out_val_w_f = 0.0;
    static float zoom_out_val_h_f = 0.0;
    unsigned char *pYdata = pYuvData;
    uint_32 stepY = Ywidth;
    int i = 0,j=0,k=0;
    uint_32 yuv_i = 0;
    uint_32 yuv_j = 0;         
    int indexY;
    uint_8 Y;
    if(nyuvWidth!=Ywidth||nyuvHeight!=Yheigth||nBWidth!=Bwidth||nBHeight!=Bheigth)
    {
        
        zoom_out_val_w_f = (float)((float)Ywidth / (float)Bwidth);
        zoom_out_val_h_f = (float)((float)Yheigth / (float)Bheigth);
        nyuvWidth = Ywidth;
        nyuvHeight = Yheigth;
        nBWidth = Bwidth;
        nBHeight = Bheigth;
        t = 255/2; 
    }

     for (i = 0; i < Bheigth; i++)
    {
        for (j = 0; j < Bwidth; j++)
        {
            yuv_i = (uint_32)(i * zoom_out_val_h_f);
            yuv_j = (uint_32)(j * zoom_out_val_w_f);

            indexY = yuv_i * stepY + yuv_j;
            Y = pYdata[indexY];
            
            if(Y>t)
            {
               des[k]=0xffff;
               k++;
            }
            else 
            {
               des[k]=0x0000;
               k++;
            }
        }
     }
}

int Quec_CamSWRgb565Rotate(uint_8 *des, uint_8 *src, uint_32 srcWidth, uint_32 srcHeight, uint_8 rotate)
{
    int n = 0;
    int bitDepth = 2;
    int i,j;
    int pix = srcWidth*srcHeight;

    if ( (!des) || (!src) || (pix <= 0) || (rotate > CAM_SW_ROTATE_270) )
    {
        return -1;
    }

    if (CAM_SW_ROTATE_90 == rotate)
    {
        for (j=0; j<srcWidth; j++)
        {
            for (i=srcHeight; i>0; i--)
            {
                memcpy(&des[n], &src[(srcWidth*(i-1) + j/* - 1*/)*bitDepth], bitDepth);
                n += bitDepth;
            }
        }
    }
    else if (CAM_SW_ROTATE_180 == rotate)
    {
        for (i=0; i<pix; i++)
        {
            memcpy(&des[n], &src[(pix - i)*bitDepth], bitDepth);
            n += bitDepth;
        }
    }
    else if (CAM_SW_ROTATE_270 == rotate)
    {
        for (j=srcWidth; j>0; j--)
        {
            for (i=0; i<srcHeight; i++)
            {
                memcpy(&des[n], &src[(srcWidth*i + j - 1)*bitDepth], bitDepth);
                n += bitDepth;
            }
        }
    }
    else /* if (CAM_SW_ROTATE_0 == rotate) */
    {
        memcpy(&des[0], &src[0], srcWidth*srcHeight*bitDepth);
    }

    return 0;
}

//裁剪+yuvtorgb算法
static int quec_yuv420_nv12_to_rgb565_zoom_out(uint_16 *pRgbData, uint_32 rgbWidth, uint_32 rgbHeight, uint_8 *pYuvData, uint_32 yuvWidth, uint_32 yuvHeight)
{
    uint_32 i, j;
    int r, g, b;
    uint_8 nr, ng, nb;
    uint_16 color_value = 0;
    static uint_32 nyuvWidth=0,nyuvHeight=0;
    static uint_32 nrgbWidth=0,nrgbHeight=0;
    uint_32 stepY = yuvWidth;
    uint_32 stepUV = yuvWidth;
    unsigned char *pYdata = pYuvData;
    unsigned char *pUVdata = pYuvData + yuvWidth * yuvHeight;
    uint_32 yuv_i,yuv_j;
    static float zoom_out_val_w_f = 0.0;
    static float zoom_out_val_h_f = 0.0;

    if ( (!pRgbData) || (!pYuvData) )
    {
        //raw_uart_log("yuv420_nv12_to_rgb565_zoom_out, data is null, pRgbData:0x%x, pSrcRgbData:0x%x\n", pRgbData, pYuvData);
        return -1;
    }

    if ( (yuvWidth < rgbWidth) || (yuvHeight < rgbWidth) )
    {
        //raw_uart_log("yuv420_nv12_to_rgb565_zoom_out, size error, rgb(WxH=%dx%d), yuv(WxH=%dx%d)\n", rgbWidth, rgbWidth, yuvWidth, yuvHeight);
        return -1;
    }
    if(nyuvWidth!=yuvWidth||nyuvHeight!=yuvHeight||nrgbWidth!=rgbWidth||nrgbHeight!=rgbHeight)
    {
        
        zoom_out_val_w_f = (float)((float)yuvWidth / (float)rgbWidth);
        zoom_out_val_h_f = (float)((float)yuvHeight / (float)rgbHeight);
        nyuvWidth = yuvWidth;
        nyuvHeight = yuvHeight;
        nrgbWidth = rgbWidth;
        nrgbHeight = rgbHeight;
    }

    for (i = 0; i < rgbHeight; i++)
    {
        for (j = 0; j < rgbWidth; j++)
        {
            int indexY, indexU, indexV;
            uint_8 Y, U, V;

            /* YUV -> RGB */
            yuv_i = (uint_32)(i * zoom_out_val_h_f);
            yuv_j = (uint_32)(j * zoom_out_val_w_f);

            indexY = yuv_i * stepY + yuv_j;
            Y = pYdata[indexY];

            if (yuv_j % 2 == 0)//奇偶行数共用一行uv分量
            {
                indexU = yuv_i / 2 * stepUV + yuv_j;
                indexV = yuv_i / 2 * stepUV + yuv_j + 1;
                U = pUVdata[indexU];
                V = pUVdata[indexV];
            }
            else if (yuv_j % 2 == 1)
            {
                indexV = yuv_i / 2 * stepUV + yuv_j;
                indexU = yuv_i / 2 * stepUV + yuv_j - 1;
                U = pUVdata[indexU];
                V = pUVdata[indexV];
            }
            /*pony 2021-02-19修改此处通过查表获取值而不是计算*/
            r = (Y + R_V[V]);
            g = (Y - G_U[U] - G_V[V]);
            b = (Y + B_U[U]);
            /*防止数据溢出*/
            r = r > 255?255:(r < 0?0:r);
			g = g > 255?255:(g < 0?0:g);
			b = b > 255?255:(b < 0?0:b);
            /* RGB -> RGB565 */
            nr = (uint_8)(r * 31 / 255);
            ng = (uint_8)(g * 63 / 255);
            nb = (uint_8)(b * 31 / 255);
            
            color_value = (uint_16)(((nr & 0x1F)<< 11) | ((ng & 0x3F) << 5) | (nb & 0x1F));
            pRgbData[(i*rgbWidth + j)] = color_value;
        }
    }
    return 0;
}

//初始化预览刷图位置和大小pony add 2021-02-19
int to_quec_framewindow(UINT16* buffer, UINT16 startx,UINT16 starty,UINT16 endx,UINT16 endy,
								struct asrlcdd_framebuffer_window *frameBufferWin, char* name, int lcd_id)
{
    struct panel_spec *quecpanel =lcd_get_panel();

	
    //raw_uart_log("%s: %d %d %d %d\r\n",name, startx, starty, endx, endy);
    frameBufferWin->frame_info.pbuffer = buffer;
    frameBufferWin->frame_info.stride = (endx-startx+1)*2;//g_mciLcdScreenInfo.width * 2;//(endx-startx+1) * 2;//
    frameBufferWin->frame_info.height = endy-starty+1;//g_mciLcdScreenInfo.height;//endy-starty+1;//
	frameBufferWin->frame_info.bitdepth = 16;

    frameBufferWin->roi_info.startX=startx;
    frameBufferWin->roi_info.startY=starty;
    frameBufferWin->roi_info.width=endx-startx+1;
    frameBufferWin->roi_info.height=endy-starty+1;

//		raw_uart_log("%s1: (%d,%d,%d,%d)\r\n",name, frameBufferWin->roi_info.startX, frameBufferWin->roi_info.startY,
//			frameBufferWin->roi_info.width, frameBufferWin->roi_info.height);

    frameBufferWin->roi_info.startX = (frameBufferWin->roi_info.startX >> 3) << 3;
    frameBufferWin->roi_info.startY = (frameBufferWin->roi_info.startY >> 2) << 2;

    frameBufferWin->roi_info.width = endx - frameBufferWin->roi_info.startX + 1;
    frameBufferWin->roi_info.height = endy - frameBufferWin->roi_info.startY + 1;
    frameBufferWin->roi_info.width = (frameBufferWin->roi_info.width + 7)/8*8;
    frameBufferWin->roi_info.height = (frameBufferWin->roi_info.height + 3)/4*4;

//		raw_uart_log("%s2: (%d,%d,%d,%d)\r\n",name, frameBufferWin->roi_info.startX, frameBufferWin->roi_info.startY,
//			frameBufferWin->roi_info.width, frameBufferWin->roi_info.height);

	if(frameBufferWin->roi_info.startX >= quecpanel->width){
		//raw_uart_log("%s: Invalid refresh area (startx = %d, width = %d)\r\n",name, frameBufferWin->roi_info.startX, quecpanel->width);
		return -1;
	}

	if(frameBufferWin->roi_info.startY >= quecpanel->height){
		//raw_uart_log("%s: Invalid refresh area (startY = %d, height = %d)\r\n",name, frameBufferWin->roi_info.startY, quecpanel->height);
		return -1;
	}

    if(frameBufferWin->roi_info.width > (quecpanel->width - frameBufferWin->roi_info.startX)){
            frameBufferWin->roi_info.width = quecpanel->width -frameBufferWin->roi_info.startX;
    }

    if(frameBufferWin->roi_info.height > (quecpanel->height - frameBufferWin->roi_info.startY)){
            frameBufferWin->roi_info.height = quecpanel->height - frameBufferWin->roi_info.startY;
    }
	return 0;
}
extern uint_8 * rgb_buf;
int quec_merge_CamBuffer(void *pBuf, int bufIndex,uint_8 *rgb565_ptr,uint_32 sensorWidth,uint_32 sensorHeight,uint_32 img_w,uint_32 img_h,uint_8 format)
{
    if (rgb565_ptr && pBuf)
    {
        struct asrlcdd_framebuffer_window frameBufferWin;
        if(sensorWidth<sensorHeight) //此处旋转是基于横屏基础
        {
            if(format == RGB565)
            {
                quec_yuv420_nv12_to_rgb565_zoom_out((uint_16*)rgb565_ptr,img_h,img_w,(unsigned char *)pBuf,sensorWidth,sensorHeight);
            }
            else 
            {
                Quec_CAM_Y_TO_Binary((uint_16*)rgb565_ptr,img_h,img_w,(unsigned char *)pBuf,sensorWidth,sensorHeight);//二值黑白
            }
            Quec_CamSWRgb565Rotate(rgb_buf,(uint_8*)rgb565_ptr, img_h, img_w, CAM_SW_ROTATE_90);
       		to_quec_framewindow((uint_16*)rgb_buf, 0, 0, img_w-1,img_h-1 , &frameBufferWin, "to_quec_framewindow", LCD_ID_MAIN);//移远lcd预览前初始化 
        }
        else
        {
            if(format == RGB565)
            {
                quec_yuv420_nv12_to_rgb565_zoom_out((uint_16*)rgb565_ptr,img_w,img_h,(unsigned char *)pBuf,sensorWidth,sensorHeight);
            }
            else 
            {
                Quec_CAM_Y_TO_Binary((uint_16*)rgb565_ptr,img_w,img_h,(unsigned char *)pBuf,sensorWidth,sensorHeight);//二值黑白
            }
       		to_quec_framewindow((uint_16*)rgb565_ptr, 0, 0, img_w-1,img_h-1 , &frameBufferWin, "to_quec_framewindow", LCD_ID_MAIN);//移远lcd预览前初始化 
        }
       if(quec_spi_lcd_write_sync(&frameBufferWin,frameBufferWin.roi_info.startX,frameBufferWin.roi_info.startY)!=0)
        {
            //raw_uart_log("quec_merge_CamBuffer:lcd_sync_failed :%d!\r\n");
			return -1;
        }
   }
    else
    {
          //raw_uart_log("quec_merge_CamBuffer is not ready\r\n");  
          return -1;
    }
    return 0;
}
/******EC600N preview code add by pony 2021-03-01 endline******/

#endif 
#endif 

