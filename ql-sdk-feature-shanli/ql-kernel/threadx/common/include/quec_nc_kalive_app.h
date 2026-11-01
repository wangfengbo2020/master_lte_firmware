/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/


#ifndef QUEC_NC_KALIVE_APP_H
#define QUEC_NC_KALIVE_APP_H

#include "quec_apptcpip_msg.h"

typedef struct
{
	int 			keepalive_enable;
	int         	pdp_cid;
	uint32   		idle_time;
}qeuc_tcpip_nc_kalive_opt;

int  quec_get_nc_kalive(qeuc_tcpip_nc_kalive_opt         *opt_val);

int  quec_set_nc_kalive(qeuc_tcpip_nc_kalive_opt        *opt_val);

#ifdef QUEC_TCP_SERVER_NC_KALIVE_CTRL_ENABLE

typedef struct{
	int         	pdp_cid;
	int   			quec_sockfd;
	int             ai_family;
	bool            server_state;
	quec_task_t     keepalive_task;
}quec_tcpip_nc_kalive_ctx;


int quec_no_connection_keepalive_init(void);
#endif

#endif

