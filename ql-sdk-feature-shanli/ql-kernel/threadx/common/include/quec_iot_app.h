/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/


#include "cjson.h"
#ifdef QUECTEL_IOT_RPT_SUPPORT

#ifdef QUEC_ATCMD_LOG
	#define cert_printf(msg, ...)  custom_log("iot", msg, ##__VA_ARGS__)
#else
	#define cert_printf(msg, ...)
#endif

#define SEND_BUFFER_SIZE 1024
#define CTX_DATA_BUFFER_SIZE 512 

typedef enum
{
	QUECTEL_IOT_IDLE = 0,
	QUECTEL_IOT_PDP_ACTIVING,
	QUECTEL_IOT_DNS_QUERY,
	QUECTEL_IOT_CONNECTING,
	QUECTEL_IOT_CONNECTED,
	QUECTEL_IOT_LOGINED,
	QUECTEL_IOT_CLOSING,
	QUECTEL_IOT_CLOSED = QUECTEL_IOT_IDLE,
}quectel_iot_state;

typedef enum
{
	QUECTEL_IOT_OPEN_EVENT = 0,
	QUECTEL_IOT_CLOSE_EVENT,
	QUECTEL_IOT_TIMEOUT_EVENT,
}quectel_iot_event_enum;

typedef struct
{
	INT32  result_code;
	void   *info_ptr;
}quectel_iot_event_info_type;

typedef enum
{
	APP_IOT_OK				= 0,
	APP_IOT_ERR_FAIL		= -1,
	APP_IOT_WOULDBLOCK      = -2,
	APP_IOT_BUSY            = -3,
	APP_IOT_ERROR_DNS       = -4,
	APP_IOT_ERROR_NETWORK   = -5,
	APP_IOT_ERROR_TIMEOUT   = -9,
	APP_IOT_INVALID_PARAM   = -10,
	APP_IOT_DATA_FAILED     = -15,
	APP_IOT_OVER_MEMORY     = -19,

	APP_IOT_PDP_ACT			= 0,
	APP_IOT_PDP_ACTED_SUCC	= 1,
	APP_IOT_PDP_ACTED_FAIL	= 2,
	APP_IOT_BEGIN_DNS		= 3,
	APP_IOT_DNS_PARSE_SUCC	= 4,
	APP_IOT_DNS_PARSE_FAIL	= 5,
	APP_IOT_BEGIN_SEND_DATA	= 6,
	APP_IOT_SEND_DATA_SUCC	= 7,
	APP_IOT_SEND_DATA_FAIL	= 8,
	APP_IOT_PS_REGI_SUCC	= 9,
	APP_IOT_PS_REGI_FAIL	= 10,
	APP_IOT_PS_REGI_ALREADY	= 11,
	APP_IOT_CONN_CLOSE      = 12,
}quectel_iot_error_code;

typedef enum
{
	IOT_DECODE_BEGIN		= 0,
	IOT_DECODE_SUCC			= 1,
	IOT_DECODE_RETRY		= 2,
	IOT_DECODE_FAIL			= 3,
}quectel_iot_decode_state;

typedef enum
{
	IOT_REGISTER_MODE_AT	= 0,
	IOT_REGISTER_MODE_AUTO	= 2,
}quectel_iot_register_mode;

typedef void (*quectel_iot_event_cb)(quectel_iot_event_enum event, quectel_iot_event_info_type *event_ptr);


typedef struct
{
	quectel_iot_state				iot_state;
	UINT16							pdp_cid;
	char							server_addr_str[255];
	char							local_addr_str[255];
	quec_ip_addr					server_ip;
	quec_ip_addr					local_ip;
	UINT16							server_port;
	UINT16							local_port;
	int								quec_ip_vsn;
	int								sockfd;
	BOOL							iot_logined;
	char							*send_buffer;
	int								send_buffer_len;
	cJSON							*send_json_ctx_ptr;
	cJSON							*recv_json_ctx_ptr;
	char							resultDesc[50];
	quectel_iot_event_cb			iot_event_cb;
	quec_sem_t	                    pdp_nic_bind_sem;
	int                             atpindex;
}quectel_iot_context;

typedef struct
{
	char							imei1[16];  //AT+GSN
	char							iccid[32];  //AT+QCCID
	char							imsi[32];  //AT+CIMI
	char							cellid[16];  //AT+CGREG
	char							time_str[32];  //AT+CCLK
}quectel_iot_data_context;

extern int quec_tcpip_is_valid_ip46_address(char *ip_string);
void quec_iot_init(void);
void quectel_iot_event_urc_report(int result_code);
void quec_iot_check_creg_timer(unsigned int ctx);
void quec_iot_reg_retry_timer(unsigned int ctx);
#endif
