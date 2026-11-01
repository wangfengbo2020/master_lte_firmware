/*============================================================================
Copyright (c) 2020 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
Quectel Wireless Solution Proprietary and Confidential.
=============================================================================*/

#ifndef _QUEC_CAMERA_H_
#define _QUEC_CAMERA_H_

#include "quec_qr_code.h"


#define CAMERA_STA_CLOSE		0
#define CAMERA_STA_OPEN			1
#define CAMERA_STA_PREVIEW	 	2

#define CAMERA_ERROR			1
#define CAMERA_SUCCESS			0
#define CAMERA_ERROR_NONE		0

#define DECODER_INITIAL_FAILED  0
#define DECODER_INITIAL  		1

#define DECODER_ERROR			0
#define DECODER_SUCCESS			1
#define DECODER_ERROR_NONE		1

#define CAM_SUPPORT_MAX_DECODE_LEN 2500

typedef enum
{
   CAM_DECODE_SUCESS    = 0,
   CAM_DECODE_FAIL      = -1,
   CAM_DECODE_INIT_FAIL = -2,
   CAM_DECODE_NOT_OPEN  = -3,
} ENUM_CAM_DECODE_RESULT;


typedef void (*Callback_preview)(P_CAL_IDENTITY_RESULT_STRUCT outdata);


typedef struct

{
	unsigned short         camwidth;     
	unsigned short         camheight;
	unsigned char          dectaskprio;  
	unsigned char          decbufcnt;    
	unsigned int  *        decbufaddr;  
	Callback_preview       decodecb;    
	unsigned char 		   preview;      
	unsigned char          pretaskprio;  
	unsigned char          prebufcnt;   
	unsigned int *         prebufaddr;  
	unsigned char  *       lcdmemeryaddr;
	unsigned short         lcdprewidth;  
	unsigned short         lcdpreheight; 
} CAM_DECODE_CONFIG_CTX;





int quec_camera_close(void);
int quec_camera_open(void);

int quec_camera_full_stream_start(int camera_height,int camera_width,Callback_preview cb);
int quec_camera_full_stream_stop(void);


#endif	// _CAMERA_TEST_H_



