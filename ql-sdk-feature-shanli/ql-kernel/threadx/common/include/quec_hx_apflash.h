/*============================================================================================
	Copyright(c) 2018 Quectel Wierless Solution,Co.,Ltd. All Rights Reserved.
	Quectel Wireless Solution Proprietary and Confidential.
============================================================================*/
#ifndef _QUEC_HX_APFLASH_H_
#define _QUEC_HX_APFLASH_H_

#include "quec_rtos.h"
#define APFLASH_NAME  "gnss_apflsh.bin"
#define GNSS_AP_DATAFLASH_SIZE (10*1024)
typedef struct quec_gnss_apflash_struct
{
    char en ;          /*apflash打开标志*/          
    char request_flag;          /*请求标志，发起请求后此标志位被置起*/
	quec_timer_t  recv_timer;   /*apflash数据接收定时器，防止接收超时*/
    quec_timer_t timer;
	int tmout_flag;
	char *buf;
    int buf_len;
    char data_start;
    char cnt;
}quec_gnss_apflash_struct_t;

typedef struct{
     unsigned int header;
     unsigned int len;
     unsigned int megtype;
}MEASURE_STRUCT;
quec_gnss_apflash_struct_t *get_hx_apflash_req_status(void);
int quec_apflash_data_save(void);
void quec_apflsh_req_statue_clear(void);
void quec_apflash_timer_init(void);
void quec_apflash_timer_deinit(void);
int quec_apflsh_data_need_update(void);
int quec_gnss_apflash_data_request(void);
int quec_gnss_apflash_recv(void);

#endif