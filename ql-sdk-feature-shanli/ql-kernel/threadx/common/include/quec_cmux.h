/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/





#ifndef QUEC_CMUX_H
#define QUEC_CMUX_H

#include "quec_cust_feature.h"
#include "quec_common.h"
#include "quec_debug.h"
#include "cmux_def.h"
#include "cmux.h"
#include "quec_uart_at.h"

#ifdef QUEC_CMUX_ENABLE
	#define cmux_log(msg, ...)  custom_log("CMUX", msg, ##__VA_ARGS__)
#else
	#define cmux_log(msg, ...)
#endif

extern uint8 g_cmux_channel;
#define QUEC_CMUX_MALLOC		malloc
#define QUEC_CMUX_FREE(ptr)     free(ptr)

//Min num 0xf9 to ack
#define QUEC_CMUX_FH_MIN_ACK_NUM   3  
//brent add --modify QUEC_CMUX_FH_DEFAULT_ACK_NUM to avoid  dlc[QUEC_CMUX_FH_DEFAULT_ACK_NUM] array dump
#define QUEC_CMUX_FH_DEFAULT_ACK_NUM   5 

#define QUEC_CMUX_SYNC_BYTE_COUNT   4  //add by wayne for fix STASR1802S-1490 bug,resolve linux cmux dcli1 open fail .

#define QUEC_CMUX_CHANNEL_MIN   0
#define QUEC_CMUX_CHANNEL_MAX   4

#define QUEC_CMUX_RX_READ_DATA_LEN_MAX   200
#define QUEC_CMUX_TX_DATA_LEN_MAX 120  //for variable

#define QUEC_CMUX_CHANNEL_CTS_BIT  0x08  // dlc flow control

#define QUEC_CMUX_CHANNEL_DTR_BIT  0x04  // dlc flow control

#define QUEC_CMUX_FLOW_BIT          0x02  // all dlc channel flow control

#define QUEC_CMUX_MAX_PARAM_NUM      9   //Chaim 2019.0730 AT+CMUX=X,X,X..  max number

#define QUEC_CMUX_MAX_FRAME_SIZE         2048

#define QUEC_CMUX_BUFF_BACK_POSE     0

#define QUEC_CMUX_FLAG_NUM           2

typedef enum 
{
    CMUX_BAUD_INDEX1_9600 =1,
    CMUX_BAUD_INDEX2_19200,
    CMUX_BAUD_INDEX3_38400,
    CMUX_BAUD_INDEX4_57600,
    CMUX_BAUD_INDEX5_115200,
    CMUX_BAUD_INDEX6_230400,
    CMUX_BAUD_INDEX7_460800,
    CMUX_BAUD_INDEX8_921600,
}quec_cmux_baud_index_e;

typedef enum 
{
    QUEC_CMUX_RSP =0,  //cmux responder
    QUEC_CMUX_SENDER,  //cmux initor
       
}quec_cmux_initor_e;
typedef enum 
{ 
	QUEC_CMUX_URC_ALL=0,
    QUEC_CMUX_URC_CHANNEL1 =1,
    QUEC_CMUX_URC_CHANNEL2,
    QUEC_CMUX_URC_CHANNEL3,
    QUEC_CMUX_URC_CHANNEL4,
    QUEC_CMUX_URC_UART,
    QUEC_CMUX_URC_MAX,      
}quec_cmux_urc_config_e;

typedef enum 
{
    QUEC_CMUX_MSG_NONE =0,
    QUEC_MS_SEND_SYNC_BYTES,   //cmux_start send 0x f9 f9 f9 f9 
    QUEC_MS_RECEIVE_ORIGIN_DATA,
    QUEC_CMUX_MSG_TIME_OUT,
    QUEC_MS_DATA_PACKAGE,
    QUEC_MS_DATA_PACKAGE_NEED_SLICE
    //QUEC_MS_PARSE_DATA,
   
}quec_cmux_msg_type_e;

typedef struct
{
    quec_cmux_msg_type_e msg_type;
    TelAtParserID atp_index;
    uint32 data_len;
    uint8 *pdata;
    
}quec_cmux_msg_s;

typedef struct
{
    //uint8 msg_type;
    uint8 data_len;
    uint8 *pdata_value;
}quec_cmux_mcc_data_s;


typedef enum 
{
    QUEC_CMUX_UI   =  MUX_UI,
    QUEC_CMUX_DM   =  MUX_DM,
    QUEC_CMUX_SABM =  MUX_SABM,
    QUEC_CMUX_DISC =  MUX_DISC,
    QUEC_CMUX_UA   =  MUX_UA,
    QUEC_CMUX_UIH  =  MUX_UIH,   //uih frame  P/F is 0
}quec_cmux_frame_type;

typedef enum 
{
    QUEC_CMUX_TST   = TEST,
    QUEC_CMUX_PSC   = 0X10,
    QUEC_CMUX_FCOFF = FCOFF,
    QUEC_CMUX_FCON  = FCON,
    QUEC_CMUX_CLD   = 0X30,
    QUEC_CMUX_MSC   = MSC, 
}quec_cmux_mcc_type;

typedef struct
{
    uint8 dcd;
    uint8 dtr;
    uint8 rts;
    uint8 cts;
    uint8 ri;
}quec_cmux_virtual_pin_s;

typedef enum 
{
    QUEC_CMUX_SYNC_BYTES_MATCH_NONE =0,
    QUEC_CMUX_SYNC_BYTES_MATCH_STOP,
    QUEC_CMUX_SYNC_BYTES_MATCH_CONTINUE,   
}quec_cmux_sync_bytes_match_state_e;


typedef enum 
{
    QUEC_CMUX_FH_FLAG_NONE =0,
    QUEC_CMUX_FH_FLAG_CRC,
    QUEC_CMUX_FH_FLAG_WAITE,
    QUEC_CMUX_FH_FLAG_CLEAR,
    QUEC_CMUX_FH_FLAG_STOP,   
}quec_cmux_fh_flag_state_e;
 
typedef enum
{
    QUEC_CMUX_FRAME_PF_0 =0,
    QUEC_CMUX_FRAME_PF_1 =1,    
}quec_cmux_pf_bit_e;

typedef struct
{
    uint16 data_len;
    uint16 data_pos;   //data parse position 
    uint8 *pdata;
}quec_cmux_rx_data_s;

typedef struct cmux_node
{
    quec_cmux_rx_data_s rx_data;
    struct cmux_node *next;
}quec_cmux_rx_data_node_t;

typedef enum 
{
    QUEC_DLC_CLOSE =0,
    QUEC_DLC_OPEN,
    QUEC_DLC_FLOW_ON,    
    QUEC_DLC_MAX
}quec_dlc_state_e;

typedef enum 
{
    QUEC_MCC_CMD =0,
    QUEC_MCC_RSP   //response
}quec_cmux_mcc_cmd_resp_type_e;

typedef enum
{
   FC_SHIFT_BIT  =1,
   RTC_SHIFT_BIT =2,
   RTR_SHIFT_BIT =3,
   IC_SHIFT_BIT =6,
   DV_SHIFT_BIT =7, 
} quec_cmux_v24signals_shift_bit_e;
   

typedef struct
{
    uint8 cmd;
    uint8 length;
    uint8 dlci;
    uint8 v24_sigs;
    uint8 break_sigs;
}quec_cmux_msc_s;

//dlc param
typedef struct
{
    quec_dlc_state_e state;
    quec_cmux_virtual_pin_s g_cmux_pin;
    
}quec_dlc_info_s;

//cmux whole param
typedef struct
{
    quec_dlc_info_s dlc[QUEC_CMUX_FH_DEFAULT_ACK_NUM];
    uint8 initiator;
     
}quec_mux_info_s;

typedef enum 
{
    CMUX_MODE_MIN =0,
    CMUX_MODE_DEFAULT =0,
    CMUX_MODE_MAX =1,
}quec_cmux_mode_e;


typedef enum 
{
    CMUX_SUBSET_MIN =0,
    CMUX_SUBSET_DEFAULT =0,
    CMUX_SUBSET_MAX =2,
}quec_cmux_subset_e;
    

typedef enum 
{
    CMUX_BAUDRATE_MIN = CMUX_BAUD_INDEX1_9600,
    CMUX_BAUDRATE_DEFAULT = CMUX_BAUD_INDEX5_115200,
    CMUX_BAUDRATE_MAX = CMUX_BAUD_INDEX8_921600,
}quec_cmux_baudrate_e;
    

typedef enum 
{
    CMUX_FRAME_SIZE_MIN =1,
    CMUX_FRAME_SIZE_DEFAULT =127,  //Chaim 20190806 protocol is 31,quectel default is 127
    CMUX_FRAME_SIZE_MAX =QUEC_CMUX_MAX_FRAME_SIZE,     //Chaim 20190806 protocol is 32768,quectel max is 127
}quec_cmux_fram_size_e;

typedef enum 
{
    CMUX_T1_ACK_TIME_MIN = 1,
    CMUX_T1_ACK_TIME_DEFAULT =10,
    CMUX_T1_ACK_TIME_MAX =255,
}quec_cmux_t1_ack_time_e;


typedef enum 
{
    CMUX_RETRY_NUM_MIN = 0,
    CMUX_RETRY_NUM_DEFALUT =3,
    CMUX_RETRY_NUM_MAX =100,
}quec_cmux_retry_num_e;

typedef enum 
{
    CMUX_T2_CONTROL_RESPONSE_TIME_MIN = 2,
    CMUX_T2_CONTROL_RESPONSE_TIME_DEFAULT =30,
    CMUX_T2_CONTROL_RESPONSE_TIME_MAX =255,
}quec_cmux_t2_response_time_e;


typedef enum 
{
    CMUX_T3_WAKEUP_TIME_MIN = 1,
    CMUX_T3_WAKEUP_TIME_DEFAULT =10,
    CMUX_T3_WAKEUP_TIME_MAX =255,
}quec_cmux_t3_wakeup_time_e;

typedef enum 
{
    CMUX_SERIAL_SIZE_MIN = 1,
    CMUX_SERIAL_SIZE_DEFAULT =2,
    CMUX_SERIAL_SIZE_MAX =7,
}quec_cmux_serial_size_e;


#define CMUX_T1_T2_UNIT_MS  10
typedef struct
{
    uint8 mode;
    uint8 subset;
    uint32 port_speed;
    uint16 max_frame_size;
    uint16 ack_time;
    uint8 max_retry_num;
    uint16 control_response_time;
    uint8 wakeup_response_time;
    uint8 serial_size;
}quec_muxparameter;

typedef struct 
{
    uint8  min_value;
    uint16 max_value;
    uint16 default_value;
}quec_cmux_get_at_value_s;

extern quec_cmux_get_at_value_s cmux_at_value[QUEC_CMUX_MAX_PARAM_NUM];
extern quec_muxparameter  mux_param;
extern QuecOSStatus quec_cmux_send_msg(quec_cmux_msg_type_e msg_type,TelAtParserID atp_index,uint8 *pdata, uint32 data_length);

extern void quec_cmux_sync_bytes_count(uint8 *pbuf, uint16 *position,uint16 buf_len);

extern  QuecOSStatus quec_cmux_ioctl(TelAtParserID atp_index, quec_ioctl_cmd_type_e cmd, quec_ioctl_param *param);
extern uint8 quec_cmux_get_channel_num(void);
extern  QuecOSStatus quec_cmux_set_channel_num(uint8 dlc_num);
extern void quec_cmux_data_debug_level(char *p_add_log_flag,quec_cmux_log_level_e min_level, uint8 *pbuf,uint16 data_len);
extern QuecOSStatus quec_cmux_urc_config(quec_cmux_urc_config_e urc_config,bool en);
extern QuecOSStatus quec_cmux_open(uint32 *pcmux_param,uint8 num_param);
extern cmux_mode_type quec_cmux_get_state(void);
extern quec_cmux_urc_config_e quec_cmux_get_urc_port(void);
extern QuecOSStatus quec_cmux_init(void);

#endif



