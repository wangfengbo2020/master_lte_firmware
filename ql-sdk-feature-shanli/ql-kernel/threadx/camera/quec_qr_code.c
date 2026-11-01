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

=============================================================================**

******************************************************************************/

#include "timer.h"
#include "quec_qr_code.h"
#include "quec_camera.h"
#include "camera_common_log.h"
#include "quec_cust_feature.h"

/*===========================================================================

            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains local definitions for constants, macros, types,
variables and other items needed by this module.

===========================================================================*/

#define DECODE_VER_LEN 36

/****************************解码库相关的函数*******************************/
#ifdef __QUEC_QR_CODE__

//初始化解码库
extern unsigned int Initial_Decoder(void);
//灰度数据解码
//img_buffer[in]:灰度数据
//width：图像的宽
//height：图像的高
//解码成功，返回解码结果的长度，单位字节。解码失败返回0
extern int Decoding_Image(unsigned char* img_buffer, int width, int height);
//获取解码的结果
//result[out]：解码的内容
extern int GetDecoderResult(unsigned char * result);
//获取本次解码的结果的长度
extern unsigned int GetResultLength(void);
//设置解码的类型：QR/C128/C39
extern int SetDecoderType(int type, int value);
//获取解码库版本号
//version[out]:解码库的版本信息
extern void Get_Decoder_Version(unsigned char * version);
extern int GetVeriStatus(void);
extern void SetMirror(int tag);

/*****************************************************************
函数：Ql_APP_Version
描述：用于存放解码库版本信息
参数：version[int]:存放解码库版本信息的buffer
      len[out] :   可以存放解码库的信息的最大字节数(36个字节)
*****************************************************************/
int Ql_Cam_Decode_Version(unsigned char* version,unsigned char ver_len)
{
    unsigned int err = 1;
    char decode_ver[DECODE_VER_LEN] = {0};
    Get_Decoder_Version(decode_ver);
   // printf("decode_ver = %s\r\n",decode_ver);
    if(version == NULL||ver_len==0)
    {
        err = 0;
    }
    if(err)
    {
        if(strlen(decode_ver)<ver_len)
        {
           memcpy(version,decode_ver,strlen(decode_ver)+1);
        }
        else
        {
           memcpy(version,decode_ver,ver_len);
           version[ver_len-1]='\0';
        }
    }
    return err;
}
/*****************************************************************
函数：ql_set_decoder_type
描述：用于设置解码模式三种模式
参数：qr code c128 c39
*****************************************************************/

int ql_set_decoder_type(QL_CAM_DECODE_TYPE type,QL_CAM_DECODE_TYPE_ABLE value)
{
    int err = 0;
    err = SetDecoderType((int)type, (int)value);
    return err;
}

static unsigned char cma_start_decoder = 0;//是否开始解码的Flag
/*****************************************************************
函数：Ql_Cam_Identify
描述：是否解码
参数：
*****************************************************************/

void Ql_Cam_Identify(unsigned char op)
{
    cma_start_decoder = op;
}

static int g_intial_decoder =0;

int Ql_Camera_SYIdentifyCode(unsigned char *InBuf,char* Image_Buffer,P_CAL_IDENTITY_RESULT_STRUCT OutBuf, int OutLen, int width, int height)
{
    int code_type = 0;
	int len = 0;
	unsigned char code_buf[CAM_SUPPORT_MAX_DECODE_LEN]={0};
	int Decode_len = 0;
	
	memset(OutBuf,0,sizeof(CAL_IDENTITY_RESULT_STRUCT));	
	
	if(cma_start_decoder)
	{
		if (g_intial_decoder == 0)
		{
			g_intial_decoder = Initial_Decoder();
	        if(0 == g_intial_decoder)
	        {
	          return CAM_DECODE_INIT_FAIL;
	        }
			else
				CAMLOGE("Initial_Decoder Fail");
		}
		
		if (InBuf)
		{
			Decode_len = Decoding_Image(InBuf, width, height);
			if ((Decode_len>0)&&(Decode_len<CAM_SUPPORT_MAX_DECODE_LEN))
			{
				len = GetResultLength();
				GetDecoderResult(code_buf);
				memcpy(OutBuf->DataBuf, code_buf, len);
				OutBuf->DataBuf[len]='\0';
				OutBuf->Type =code_type;
				OutBuf->DecodeLen=len;
				return CAM_DECODE_SUCESS;
			}
			else
			{
				return CAM_DECODE_FAIL;
			}

		}
	}
	else
	{
		return CAM_DECODE_NOT_OPEN;
	}

	return 0;
}

int ql_get_decode_statue(void)
{
    int err=0;
	if (g_intial_decoder == 0)
	{    
		g_intial_decoder = Initial_Decoder();
        if(0 == g_intial_decoder)
        {
			err = CAM_DECODE_INIT_FAIL;
		}
	}
    if(0 != g_intial_decoder)
    {
        err = GetVeriStatus();
    }
    return err;
}

void ql_set_decode_mirror(QL_CAM_DECODE_MODE mode)
{
    SetMirror((int)mode);
}
#else
int Ql_Cam_Decode_Version(unsigned char* version,unsigned char ver_len)
{
    return 0;
}
int ql_set_decoder_type(QL_CAM_DECODE_TYPE type,QL_CAM_DECODE_TYPE_ABLE value)
{
    return 0;
}
void Ql_Cam_Identify(unsigned char op)
{
    return;
}
int Ql_Camera_SYIdentifyCode(unsigned char *InBuf,char* Image_Buffer,P_CAL_IDENTITY_RESULT_STRUCT OutBuf, int OutLen, int width, int height)
{
    return 0;
}
int ql_get_decode_statue(void)
{
    return 0;
}
void ql_set_decode_mirror(QL_CAM_DECODE_MODE mode)
{
    return;
}

#endif //__QUEC_QR_CODE__ end_line______________/



