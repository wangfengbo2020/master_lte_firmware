/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/


#ifndef QUEC_PAGING_KALIVE_APP_H
#define QUEC_PAGING_KALIVE_APP_H

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "quec_cust_feature.h"
#include "quec_common.h"
#include "quec_atcmd_param.h"
#include "quec_at_common.h"


typedef enum
{
	PAGING_KEEP_SEND_PKT_TYPE_NONE = -1,
	PAGING_KEEP_SEND_UDP_PKT,
	PAGING_KEEP_SEND_PING_PKT,
	PAGING_KEEP_SEND_PKT_TYPE_MAX
} paging_keep_send_pkt_type_e;


typedef enum
{
	PAGING_KEEP_TYPE_NONE = -1,
	PAGING_KEEP_CELL_RESELECT_SEND,
	PAGING_KEEP_NORMAL_SEND,
	PAGING_KEEP_TYPE_MAX
} paging_keep_send_type_e;


typedef struct
{
    int          pdp_cid;
    paging_keep_send_type_e            keep_type;     // 0-小区重选后，发数据       
    paging_keep_send_pkt_type_e        keep_pkt_type;  // keep_type ==0,0-udp 1-ping
    uint32       keep_time;
    bool         paging_update_enable;
    bool         reg_ind_chg_enable_flag;
    bool         pkt_chg_flag;
    unsigned long long    pkt_send_times;
}quec_pg_keepalive_cfg;

typedef struct{
    int             pdp_cid;
    int             quec_sockfd;
    int             ai_family;
    bool            server_state;
    quec_task_t     keepalive_task;
}quec_tcpip_pg_kalive_ctx;

int quec_paging_keepalive_init(void);


#endif

