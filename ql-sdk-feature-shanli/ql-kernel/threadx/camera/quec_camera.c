/*---------------------------------------------------------------------------
Copyright (c) 2020 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
Quectel Wireless Solution Proprietary and Confidential.
---------------------------------------------------------------------------

**===========================================================================


						EDIT HISTORY FOR MODULE
This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.



WHEN        WHO       	WHAT, WHERE, WHY
----------  ------ 		----------------------------------------------------

18/03/2020	Davison    	Create.
2022/05/01  Pony.ma     重新实现此文件，此文件为Camera的应用层代码

=============================================================================**

******************************************************************************/
#include "quec_cust_feature.h"
#include "camera_hal_core.h"
#include "string.h"
#include "string_utils.h"
#include "quec_camera.h"
#include "bsp.h"
#include "cam_sensor.h"
#include "teldef.h"
#include "quec_power_manager.h"			// sleep is not allowed  when the camera is turned on

#define CAM_CLOSE_STA 0
#define CAM_OPEN_STA 1

#ifdef QUEC_LCD_SUPPORT
#ifdef QL_LCD
extern int quec_cranem_start_preview(CCStartPreviewStruct *data) ;
#endif
#endif

extern quec_queue_t  g_quec_sleep_queue ;		//for prevent into sleep

static int camera_status =  CAM_CLOSE_STA;
static int sensor_id = 0;
ReleaseBufferCallback callbk = NULL;
void  *bufq = NULL;
Callback_preview  preview_buf_ptr = NULL;//保存解码成功后执行的回调函数
extern SENSOR_CTRL_T *g_CurSensorCtrl;

#define CAMERA_DECODE_TASK_PRIORITY		220


CAM_DECODE_CONFIG_CTX g_cam_decode_config_ctx=
{
	.camwidth      =640,     
	.camheight     =480,
	.dectaskprio   =CAMERA_DECODE_TASK_PRIORITY,//解码任务的优先级
#ifdef QUEC_4MRAM_DECODE
	.decbufcnt     =2,    
#else
	.decbufcnt     =1,    
#endif
	.decbufaddr    =NULL,   
	.decodecb      =NULL,     
	.preview       =0,      
	.pretaskprio   =CAMERA_PREVIEW_TASK_PRIORITY,//预览任务的优先级
	.prebufcnt     =0,    
	.prebufaddr    =NULL,   
	.lcdmemeryaddr =NULL,
	.lcdprewidth   =0,
	.lcdpreheight  =0,

};

void QlFlushCamBuffers()
{
    //raw_uart_log("FlushCamBuffers \n");
}
void QlEnqueueCamBuffer(void *pBuf, int bufIndex)
{
    //raw_uart_log("EnqueueCamBuffer \n");
}
void QlsetReleaseBufferCb(ReleaseBufferCallback cb, void *userData)
{
    //raw_uart_log("setSourceCallBack \n");
}

int quec_camera_full_stream_stop(void)
{
	Ql_Cam_Identify(0);
	CCStopFullSizeStream();
	return 0;

}

extern void SleepFlag_CAM_DMA_Set(UINT8 flag); 
int quec_camera_close(void)
{
	int ret=0;
	quec_sleep_msg_s sleep_msg={0};//20220307 after close camera，allow sleep
	//Start Fias.fan 20220307  after close camera，allow sleep
	SleepFlag_CAM_DMA_Set(0);

	ataCloseCamera(0);

	camera_status = CAM_CLOSE_STA;

	return 0;
}



//此函数检查sensor,打开Camera,但是此时没有接收外部sensor的数据
//此函数为STD项目设计
int quec_camera_open(void)
{
	int sensor_id = SENSOR_ID_BACK;//默认检测后置摄像头
	CCError error;
	int ret=0;
	quec_sleep_msg_s sleep_msg={0};//20220307防止open camera后，进入sleep
	
	//ui_main();//ui_os 初始化，临时配置@20220503

	//Start Fias.fan 20220307防止open camera后，进入sleep
	SleepFlag_CAM_DMA_Set(1);

	error = ataOpenCamera(sensor_id);

	if (error != CRANE_CAMERA_ERROR_NONE)
	{
		CAMLOGI("%s : CCOpenCamera the %d sensor failed for %d!", __func__, sensor_id, error);
		return error;
	}

	return 0;
}

//开启isp的full size通道,接收外部sensor传送过来的数据
int quec_camera_full_stream_start(int camera_height,int camera_width,Callback_preview cb)
{
	int sensor_id = 0;
	CCError error = CRANE_CAMERA_ERROR_NONE;
	CCStartPreviewStruct data={0};
	CamRecordParmeters record_parms= {0x0};

	g_cam_decode_config_ctx.decodecb = cb;
	
	if(g_cam_decode_config_ctx.preview)
	{
		if(CHIP_IS_CRANEM || CHIP_IS_CRANEL)
        {
			#ifdef QUEC_LCD_SUPPORT
			#ifdef QL_LCD
				error = quec_cranem_start_preview(&data);	
			#endif
			#endif
        }
		
		if (error != CRANE_CAMERA_ERROR_NONE) 
		{
			CAMLOGI("%s : CCStartPreview the %d sensor failed for %d!\r\n", __func__, sensor_id, error);
			goto Error_exit;
		}
	}

	record_parms.recordWidth = 640;
	record_parms.recordHeight = 480;
	record_parms.enqueueCamRecordBuffer = QlEnqueueCamBuffer;
	record_parms.setReleaseBufferCallBack = QlsetReleaseBufferCb;
	record_parms.flushCamRecordBuffers = QlFlushCamBuffers;

	error = CCStartFullSizeStream(&record_parms, PIPE_OUT_FMT_YUV420_NV12);
	if (error != CRANE_CAMERA_ERROR_NONE) 
	{
		CAMLOGI("CCStartFullSizeStream the %d sensor failed for %d!\r\n", sensor_id, error);
		goto Error_exit;
	}
	Ql_Cam_Identify(1);

	return error;
	
Error_exit:
    CCStopFullSizeStream();
    if(CHIP_IS_CRANEM || CHIP_IS_CRANEL)
    {
	    ataCloseCamera(sensor_id);
    }
   
	CAMLOGI("%s : close the %d camera successful!\r\n", __func__, sensor_id);
	return error;
}



/***********************************************************************
 *
 * Name:    quec_qr_camera_open   
 *
 * Description: [in]cambuf:camera的原始数据存入此buffer，OCPU 传入
 *		           目前采用双buffer解码，NV12的格式，VGA 
 *   	           buffer size：640*480*3/2 *2 =  900Kb
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes:
 * 此接口为OPEN 设计
 ***********************************************************************/
ENUM_CAM_DECODE_RESULT quec_qr_camera_open(CAM_DECODE_CONFIG_CTX * camconfig)
{
	CCError error = CAMERA_ERROR_NONE;
	ENUM_CAM_DECODE_RESULT err = CAM_DECODE_SUCESS;
    CAMLOGI("+++++++++++++open camera+++++++++++++++\r\n");
	
	//ui_main();//ui_os 初始化，临时配置@20220503
	
	if (CAM_CLOSE_STA == camera_status)
	{
		if(camconfig != NULL)
		{
			memcpy((void*)&g_cam_decode_config_ctx,(void*)camconfig,sizeof(CAM_DECODE_CONFIG_CTX));
            if(g_cam_decode_config_ctx.dectaskprio==0)//采用默认的优先级
            {
                g_cam_decode_config_ctx.dectaskprio = CAMERA_DECODE_TASK_PRIORITY; 
            }
            if(g_cam_decode_config_ctx.pretaskprio==0)
            {
                g_cam_decode_config_ctx.pretaskprio = CAMERA_PREVIEW_TASK_PRIORITY; 
            }

			error = quec_camera_open();
			if (error != CRANE_CAMERA_ERROR_NONE)
			{
				quec_camera_close();
				goto exit;
			}
		}
		
        error =  quec_camera_full_stream_start(g_cam_decode_config_ctx.camheight,g_cam_decode_config_ctx.camwidth,
                 g_cam_decode_config_ctx.decodecb);
		
		if (error != CRANE_CAMERA_ERROR_NONE)
		{
			quec_camera_full_stream_stop();
			goto exit;
		}
	}
	else
	{
		return CAM_DECODE_INIT_FAIL;
	}

exit:		
    if(error == CAMERA_ERROR_NONE)
    {
		camera_status = CAM_OPEN_STA;
        err = CAM_DECODE_SUCESS;
    }
    else 
    {
        err = CAM_DECODE_INIT_FAIL;
    }
	
	return  err;
}


int ql_cam_i2c_write(unsigned int reg, unsigned int val)
{
    int err = 0;
    if(g_CurSensorCtrl!=NULL)
    {
        err=crane_i2c_write_single(&g_CurSensorCtrl->sensor_data->i2c_attr[g_CurSensorCtrl->sensor_data->cur_i2c_index], reg,val);
        if(err==!0)
        {
            CAMLOGI("ql_cam_i2c_write failed,i2c_attr=%d\r\n",g_CurSensorCtrl->sensor_data->i2c_attr[g_CurSensorCtrl->sensor_data->cur_i2c_index].addr);
        }
    }
    else 
    {
        CAMLOGI("g_CurSensorCtrl is not init!!!");
        err=-1;
    }
    return err;
}

int ql_cam_i2c_read( unsigned int reg, unsigned int *val)
{
    int err = 0;
	
    if(g_CurSensorCtrl!=NULL)
    {
        err=crane_i2c_read(&g_CurSensorCtrl->sensor_data->i2c_attr[g_CurSensorCtrl->sensor_data->cur_i2c_index],reg,val);
        if(err==!0)
        {
            CAMLOGI("ql_cam_i2c_read failed,i2c_attr=%d\r\n",g_CurSensorCtrl->sensor_data->i2c_attr[g_CurSensorCtrl->sensor_data->cur_i2c_index].addr);
        }		
    }
    else 
    {
        CAMLOGI("g_CurSensorCtrl is not init!!!");
        err=-1;
    }
    return err;
}



#ifdef __QUEC_CAMERA_DEBUG__     
typedef struct
{
   unsigned char onoff;
   unsigned int dump_frame_time;
   unsigned char dump_always;
   unsigned char format;
} DUMP_FRAME_REF;


#define DUMP_Y_FORMAT    1
#define DUMP_NV12_FORMAT 2
#define DUMP_JPEG_FORMAT 3
#define RGB_565 4
#define SEND_UTIL (1*1024)
DUMP_FRAME_REF dump_frame = {
 .onoff=0,//默认关闭输出
 .dump_frame_time=0xFFFFFFFF,
 .dump_always=0,
 .format=1
};


extern QuecOSStatus quec_siolib_transmit_to_atp(TelAtParserID atp_index, uint8 *buf, uint32 len, uint32 * pActualTransLen);

void kernel_usb_at_send_data(unsigned char *buffer, unsigned int len)
{
	quec_siolib_transmit_to_atp(TEL_AT_CMD_ATP_20, buffer, len, NULL);//通过USB AT口输出

}

void __QlUsbCdcDumpCameraData(unsigned char format,unsigned char *srcdata,unsigned short w,unsigned short h,unsigned char dump_id)
{   
	static unsigned char cnt = 0;
	unsigned int i;
    unsigned int len = 0;
    unsigned int loop = 0; 
	unsigned int left = 0;
	
	char start[] = "QUECTEL";  //QUECTEL+长和宽的信息，PC端工具识别此字段方便显示
	unsigned short size_f[2];

	format = dump_frame.format;//根绝AT设置的格式

	if((format == DUMP_Y_FORMAT)||(format == 11))
		len = w*h;
	else if(format == DUMP_NV12_FORMAT)
		len = w*h*3/2;
	else if(format == DUMP_JPEG_FORMAT)
		len = w*h;
    else if(format == RGB_565)
        len = w*h*2;
	
	size_f[0] = w;
	size_f[1] = h;  
	
    loop = len/SEND_UTIL;
    left = len%SEND_UTIL;
	
	if(dump_frame.onoff == 1)
	{
		if((dump_frame.dump_frame_time != 0)||(dump_frame.dump_always == 1))
		{
			CAMLOGI("[dump Y] --------buffer w(%d) h(%d) len(%d) loop(%d) left(%d) dump_format[%d]----------\r\n",w,h,len,loop,left,dump_id,dump_frame.format);
			if(format != 11)
			{//先发送QUECTEL+长和宽的信息，PC端工具识别此字段方便显示
				kernel_usb_at_send_data(start,7);
				kernel_usb_at_send_data((unsigned char*)size_f,4);
			}
			
			for(i=0;i<loop;i++)
			{	
				while((_usb_device_get_dtd_cnt(0x04, 1, NULL) > 20))
				{
					OSATaskSleep(1);
				}
				kernel_usb_at_send_data(srcdata, SEND_UTIL);
				OSATaskSleep(1);
				srcdata += SEND_UTIL;
			}
			if(left)
				kernel_usb_at_send_data(srcdata, left);  
			
			if(dump_frame.dump_always == 0)//非连续输出
			{
				dump_frame.dump_frame_time-- ;	
				if(dump_frame.dump_frame_time == 0)
					dump_frame.onoff = 0;//关闭dump
			}
		}
	}

}
/********************************************************************/
/*** 2021-02-08 pony add 
/*** 入参：format:需要dump 图片的格式; 
		   1,Y格式[buffer头部带有长和宽信息];2：NV12格式[buffer头部带有长和宽信息];11,Y格式[buffer头部没有长和宽信息]
/***       time:dump图片的帧数，若设置为0关闭输出，0xFFFFFFFF 为持续输出
/*** 返回值：dump图片实体的ref
/********************************************************************/
unsigned char dump_camera_data_init(unsigned int time,unsigned char format)
{
    unsigned char id=0;
	
    if(time==0)//关闭输出
    {
		dump_frame.onoff = 0;
        dump_frame.dump_always = 0;
        dump_frame.dump_frame_time = 0;
    }
    else if(time == 0xFFFFFFFF)//连续输出
    {
		dump_frame.onoff = 1;
        dump_frame.dump_frame_time = 0;
        dump_frame.dump_always = 1;
    }
	else//指定输出的次数
	{
		dump_frame.onoff = 1;
        dump_frame.dump_frame_time = time;
        dump_frame.dump_always = 0;
	}
	
	dump_frame.format = format;

	CAMLOGI("onoff(%d) dump_always(%d) dump_frame_time(%d) format(%d)\r\n",dump_frame.onoff,dump_frame.dump_always,
		dump_frame.dump_frame_time,dump_frame.format);

    return id;
}

#endif/*******__QUEC_CAMERA_DEBUG__ endline____********/


