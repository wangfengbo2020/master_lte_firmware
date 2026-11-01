/*============================================================================
Copyright (c) 2020 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
Quectel Wireless Solution Proprietary and Confidential.
=============================================================================*/

/*===========================================================================


						EDIT HISTORY FOR MODULE
						
This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order



WHEN        WHO       	WHAT, WHERE, WHY
----------  ------ 		----------------------------------------------------

18/03/2020	Davison    	Create.

=============================================================================*/

#ifndef _CAMERA_QR_H_
#define _CAMERA_QR_H_

#define IMG_WIDTH 				320		//640
#define IMG_HEIGHT 				240		//480
#define CAM_SUPPORT_MAX_DECODE_LEN 2500


typedef enum 
{
    QR_DECODE ,
    A_CODE,
    B_CODE,
}QL_CAM_DECODE_TYPE;
typedef enum 
{
    DISABLE,
    ENABLE,
}QL_CAM_DECODE_TYPE_ABLE;
typedef enum
{
   DEFULT_MODE,
   MIRROR_MODE,
   AUTO_MODE,
}QL_CAM_DECODE_MODE;

typedef struct
{
	unsigned char  Type;
	int            DecodeLen;
	int            result;
	unsigned char  DataBuf[CAM_SUPPORT_MAX_DECODE_LEN];
} CAL_IDENTITY_RESULT_STRUCT,*P_CAL_IDENTITY_RESULT_STRUCT;


int Ql_Camera_SYIdentifyCode(unsigned char *InBuf,char* Image_Buffer,P_CAL_IDENTITY_RESULT_STRUCT OutBuf, int OutLen, int width, int height);
/*****************************************************************
函数：Ql_Cam_Decode_Version
描述：用于存放解码库版本信息
参数：version[int]:存放解码库版本信息的buffer
      len[out] :   可以存放解码库的信息的最大字节数(240个字节)
Ret：void
*****************************************************************/
int Ql_Cam_Decode_Version(unsigned char* version,unsigned char ver_len);
/*****************************************************************
函数：Ql_Cam_Identify
描述：是否开启解码
参数：op[in]: 1,开启解码；0,关闭解码
Ret：void
NOTE: ql_qr_camera_open()函数里默认开启解码
*****************************************************************/
void Ql_Cam_Identify(unsigned char op);
int ql_set_decoder_type(QL_CAM_DECODE_TYPE type,QL_CAM_DECODE_TYPE_ABLE value);


int ql_get_decode_statue(void);
void ql_set_decode_mirror(QL_CAM_DECODE_MODE mode);


#endif	// _CAMERA_TEST_H_

