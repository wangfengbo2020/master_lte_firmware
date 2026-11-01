/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/



typedef enum
{
	QUEC_IOT_PDP_ACTIVE_REQ, //0
	QUEC_IOT_OPEN_REQ,
	QUEC_IOT_CLOSE_REQ,
	QUEC_IOT_PUT_DATA_REQ,
	QUEC_IOT_DECODE_DATA_REQ,

	QUEC_IOT_PDP_ACTIVE_CNF, //5
	QUEC_IOT_PDP_DEACTIVE_CNF,
	QUEC_IOT_OPEN_CNF,
	
	QUEC_IOT_TIMER_CREG_CHECK_CB_HANDER,
	QUEC_IOT_TIMER_REG_RETRY_CB_HANDER,

	QUEC_IOT_MAX_MSG
}quec_iot_msg_id;


typedef struct
{
	int32			result;
	uint32          iot_stat;
	uint8           sio_port;
}quectel_ds_iot_event_info;

typedef struct {
	quec_iot_msg_id  msg_id;
	void             *data_ptr;
}quec_iot_msg;

