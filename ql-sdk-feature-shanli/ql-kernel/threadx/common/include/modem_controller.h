/*
 * modem_controller.h -- modem_controller.c header
 *
 * (C) Copyright [2006-2008] Marvell International Ltd.
 * All Rights Reserved
 *
 */

#ifndef _PPP_MAIN_H_
#define _PPP_MAIN_H_

#if defined __cplusplus
extern "C" {
#endif	/* __cplusplus */
#include "modem_platform.h"
#include "quec_cust_feature.h"

#ifdef QUEC_MODEM_ROUTERE_NO_STORE_OPTIMIZE
#define MODEM_ROUTER_STACK_SIZE 1024 * 3
#else
#define MODEM_ROUTER_STACK_SIZE 1024 * 4
#endif

#ifndef QUEC_SIO_MODULE_ENABLE
#define MODEM_ROUTER_PRIORITY 80
#else
#define MODEM_ROUTER_PRIORITY 78
#endif

#define MODEM_MSGQ_NUM 600

struct data_channel
{
	U_CHAR at_buffer[AT_CMD_BUF_SIZE];
	U_CHAR *at_buffer_head; /* point to the first written space or at_buffer */
	U_CHAR *at_buffer_tail; /* point to the first empty space */
	int cur_line_len;
	int atp_index;
	void (*process_cb)(struct data_channel *);
};

#ifdef QUEC_MODEM_ROUTERE_NO_STORE_OPTIMIZE

#define QUEC_INTERNAL_AT_RESP_BUF	512

typedef struct 
{
	U_CHAR at_buffer[QUEC_INTERNAL_AT_RESP_BUF];
	U_CHAR *at_buffer_head; /* point to the first written space or at_buffer */
	U_CHAR *at_buffer_tail; /* point to the first empty space */
	int cur_line_len;
	int atp_index;
}quec_internal_channel_s;

#endif

/************************************************************************/
/* APIs                                                                 */
/************************************************************************/
void modem_init_internal(void);
void modem_deinit(void);
UINT8 get_ppp_cid_internal(void);
void handle_dial_internal(int atp_index);
void ppp_clear_use_eps_apn_internal(UINT32 atp_index);
void modem_update_reg_option_internal( int atp_index, int option);
void ppp_store_configure_params(int atp_index, int cid, char *apn,  int ip_type);
void send_data_to_modem_router(char *data, int len, int atp_index, int from);
void modem_channel_buffer_reset(void);
int process_ppp_ato_internal(int atp_index);
void modem_channel_buffer_reset_internal(void);
BOOL ppp_get_connect_flag_internal(UINT8 cid);
void ppp_process_data_nok_internal(UINT8 cid, BOOL force);
int process_ppp_atd_internal(int atp_index, char *dial_string);
int get_cgreg_status_rsp_internal(int atp_index, char *rsp_buf, int type);
bool need_ppp_process_at_response_internal(int atp_index);
bool need_ppp_process_ato_request_internal(int atp_index);
void send_data_to_modem_router_internal(char *data, int len, int atp_index, int from);
void ppp_store_configure_params_internal(int atp_index, int cid, char *apn,  int ip_type);
int get_cgreg_status_rsp(int atp_index, char *rsp_buf, int type);
BOOL need_ppp_process_ato_request(int atp_index);
int process_ppp_ato(int atp_index);
extern BOOL isPPPConnected(void);

#ifdef QUEC_DUAL_SIM_SUPPORT
extern UINT32 quec_get_modem_atp(void);
#endif

#if defined __cplusplus 
}
#endif	/* __cplusplus */
#endif
