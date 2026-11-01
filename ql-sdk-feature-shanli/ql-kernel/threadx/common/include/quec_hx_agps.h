/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/


#ifndef _QUEC_ATCMD_GNSS_H
#define _QUEC_ATCMD_GNSS_H


#include "quec_include.h"
#include "httpc.h"




#define EPH_GP 0x01
#define EPH_BD (0x01 << 1)
#define EPH_GL (0x01 << 2)
#define EPH_GA (0x01 << 3)
#define EPH_QZ (0x01 << 4)

#define QUEC_TCPIP_PDP_ID_MIN	        1
#define QUEC_TCPIP_PDP_ID_MAX	        15
#define QUEC_TCPIP_PDP_ID_DEFAULT       1

#define QUEC_GNSS_TOKEN_NVM   "UFS_gnss.txt"
#define QUEC_AGPS_DATA_LENGTH       10*1024

typedef struct {
    int              pdp_cid;
	char             gnss_host[128];
    char             gnss_cid[50];
    char             gnss_mid[25];
    char             gnss_did[50];
    char             gnss_pw[50];
    char             gnss_mask[15];
    char             gnss_lat[15];
    char             gnss_lon[15];
    bool             gnss_flag;  /*是否启用概略位置功能*/
    uint32           agps_type;
    char             agps_en;
	uint32			 recv_len;
	char *           recv_data;
    char             agps_state;  /*AGPS同步状态,至少保证每次开机会同步一次agps文件*/
}quec_agps_ref_t;

typedef struct {
	int    data_ptr_len;
	void  *data_ptr;
}quec_gnss_data_msg_s;

int get_gnss_http_post_buf(char *content, char type);
quec_gnss_data_msg_s* quec_gnss_http_post_packag(void);
int quec_gnss_dynreg_http_parse(char* buff, int len);
extern int quec_aliot_http_get_chr(char* dtr, int dtr_len, char* str, int str_len, char* out_buff);
extern int apptcpip_search_chr_offset(char *dts, char *str);
static int quec_gnss_param_stricmpl( char* str1, char* str2, int maxlength);
int quec_gnss_recv_cnf(int client_id, void* argv);
void quec_gnss_worker_thread(void * argv);
void quec_gnss_close_proc(int connect_id);
int quec_gnss_open_cnf(int client_id, void* argv);
void quec_gnss_open_proc(int client_id);
void  quec_gnss_listener(int msg_id, void* msg_data_ptr);
void quec_agps_init(void);
void quec_agps_deinit(void);
void quec_agps_file_set_to_gps(void);
quec_agps_ref_t *quec_agps_ref_get(void);
int quec_send_agps_data(char *data,int len);
void quec_agps_init(void);
int quec_agps_file_check_or_update(char* data,unsigned int *len);
char quec_get_agps_status(void);
void quec_set_agps_status(char state);




#endif

