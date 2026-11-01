/*---------------------------------------------------------------------------
Copyright (c) 2020 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
Quectel Wireless Solution Proprietary and Confidential.
---------------------------------------------------------------------------*/

#include "quec_cust_feature.h"
#ifdef QL_CAMERA

#include "ql_camera.h"
#include "quec_camera.h"




extern ENUM_CAM_DECODE_RESULT quec_qr_camera_open(CAM_DECODE_CONFIG_CTX * camconfig);


ENUM_CAM_DECODE_RESULT ql_qr_camera_open(CAM_DECODE_CONFIG_CTX * camconfig)
{
	return quec_qr_camera_open(camconfig);
}



ENUM_CAM_DECODE_RESULT ql_qr_camera_close (void)
{
	quec_camera_full_stream_stop();
	return (ENUM_CAM_DECODE_RESULT)quec_camera_close();
}




#endif











