/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/


/*=================================================================

						EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN			  WHO		  WHAT, WHERE, WHY
------------	 -------	 --------------------------------------------------
06/19/2020		  Harold	 mod cache linklist_push ,but previous linklist_pop pointer not released, cause dump

=================================================================*/

#include "quec_ds_iot.h"
#include "cjson.h"
#include "ci_ps.h"

#ifndef MIN_SYS


#ifdef QUECTEL_IOT_RPT_SUPPORT
#include "quec_atcmd_cert.h"
extern char mob_sw_rev[];
extern quectel_iot_mgr quec_iot_mgr;
extern CiPs4GNwRegInfo quec_cereg_info;

#define RPT_HEADER_LINE_LEN      128
quectel_iot_data_context iot_data = {0};
const char base_val[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

extern bool quectel_egmr_get_imei(char *imei_info);

static void  quectel_iot_open_cmd_handler
(
void *user_data_ptr
);

static void quectel_iot_pdp_active_cmd_handler
(
void *user_data_ptr
);

static void quectel_iot_put_data_cmd_handler
(
void *user_data_ptr
);

static void quectel_iot_decode_data_cmd_handler
(
void *user_data_ptr
);

static int quectel_iot_open_event_proc
(
void *user_data_ptr
);

#define MIN_VAL(a,b)   (a > b)?b:a

static int quectel_iot_pdp_active_event_proc
(
void *user_data_ptr
);

static int  quectel_iot_timer_creg_check_cb_hander
(
void *user_data_ptr
);

static int  quectel_iot_timer_reg_retry_cb_hander
(
void *user_data_ptr
);


quectel_iot_context *  quectel_iot_ctx_init
(
quectel_iot_event_cb  iot_event_cb
)
{
	quectel_iot_context *ctx_ptr = malloc(sizeof(quectel_iot_context));

	if(ctx_ptr == NULL)
		return NULL;
	
	memset(ctx_ptr, 0, sizeof(quectel_iot_context));

	ctx_ptr->iot_event_cb = iot_event_cb;
	ctx_ptr->iot_state = QUECTEL_IOT_IDLE;
	ctx_ptr->sockfd = -1;
	ctx_ptr->send_buffer = NULL;
	ctx_ptr->send_buffer_len = 0;

	return ctx_ptr;
}

void quectel_iot_event_urc_report(int result_code)
{
	quectel_iot_event_info_type   event_info = {0};
	quectel_iot_context  *ctx_ptr = (quectel_iot_context  *)quec_iot_mgr.iot_ctx;
	
	event_info.info_ptr = NULL;
	event_info.result_code = result_code;
	ctx_ptr->iot_event_cb(QUECTEL_IOT_OPEN_EVENT, &event_info);	
}

static void quectel_iot_deinit_data_wm()
{
	cert_printf("Mark for linklist_deinit....\n");

	if(quec_iot_mgr.wm_have_init)
	{
		linklist_deinit(&(quec_iot_mgr.trans_wm_ptr.u.tcp_session.rx_q));
		linklist_deinit(&(quec_iot_mgr.trans_wm_ptr.u.tcp_session.tx_q));
		memset(&quec_iot_mgr.trans_wm_ptr,0,sizeof(quec_iot_mgr.trans_wm_ptr));
		quec_iot_mgr.wm_have_init = FALSE;
	}
	return ;
}

static void quectel_iot_init_data_wm()
{
	cert_printf("Mark for linklist_init....\n");
	memset(&quec_iot_mgr.trans_wm_ptr,0,sizeof(quec_iot_mgr.trans_wm_ptr));

	linklist_init(&(quec_iot_mgr.trans_wm_ptr.u.tcp_session.rx_q));
	linklist_init(&(quec_iot_mgr.trans_wm_ptr.u.tcp_session.tx_q));

	quec_iot_mgr.wm_have_init = TRUE;
	return ;
}

static void quec_iot_store_send_data(quec_tcpip_transfer_session *sess_ptr, uint8 *data, UINT32 len)
{
	quec_tcpip_data *tcp_data = NULL;
	QuecOSStatus ret;

	if(data == NULL || len== 0)
		return;
	
	cert_printf("store_data_len = %d",len);
	
	tcp_data = (quec_tcpip_data *)quec_tcpip_new_data_2(data,len);

	cert_printf("data_ptr :%p, len=%d\r",tcp_data ,len);

	require(tcp_data != NULL,exit);

	memcpy(tcp_data->data_ptr, data, len);

	tcp_data->used += len;

	ret=linklist_push(&(sess_ptr->u.tcp_session.tx_q), DIR_FIFO, (data_t *)(tcp_data), sizeof(quec_tcpip_data));

	cert_printf("ret= %d\r",ret);

	free(tcp_data);
exit:
    return;
}

static void quec_iot_get_send_data(quec_tcpip_transfer_session *sess_ptr,uint8 *data, UINT32 *len)
{
	UINT32  want_read = *len;
	UINT32  data_len = 0;
	UINT32  read_len = 0;
	QuecOSStatus ret;
	*len = 0;

	cert_printf("want_read_len = %d",want_read);
	
	if(sess_ptr == NULL || data == NULL ||want_read == 0)
		return;
	
	do
	{
		if(sess_ptr->u.tcp_session.current_tx_data_ptr == NULL)
		{
			ret= linklist_pop(&(sess_ptr->u.tcp_session.tx_q), &(sess_ptr->u.tcp_session.current_tx_data_ptr), &data_len);
			cert_printf("current_tx_data_ptr=%p,ret= %d\r",sess_ptr->u.tcp_session.current_tx_data_ptr,ret);
		}
		cert_printf("data:%p,used=%d,len:%d\r",sess_ptr->u.tcp_session.current_tx_data_ptr,sess_ptr->u.tcp_session.current_tx_data_ptr->used,data_len);
		if(sess_ptr->u.tcp_session.current_tx_data_ptr == NULL)
			break;

		read_len = MIN_VAL(want_read, sess_ptr->u.tcp_session.current_tx_data_ptr->used);
		cert_printf("read_len = %d\r\n",read_len);

		memcpy(data+(*len), sess_ptr->u.tcp_session.current_tx_data_ptr->data_ptr, read_len);
		sess_ptr->u.tcp_session.current_tx_data_ptr->data_ptr += read_len;
		sess_ptr->u.tcp_session.current_tx_data_ptr->used -= read_len;
		want_read -= read_len;
		*len += read_len;
		
		if(sess_ptr->u.tcp_session.current_tx_data_ptr->used == 0)
		{
			quec_tcpip_free_data(sess_ptr->u.tcp_session.current_tx_data_ptr);
			sess_ptr->u.tcp_session.current_tx_data_ptr = NULL;
		}
	}while(want_read > 0);
		
	cert_printf("total:%d,read:%d, data_len=%d\r",sess_ptr->total_tx_size, sess_ptr->write_tx_size, *len);
	
}

static void quec_iot_store_recv_data(quec_tcpip_transfer_session *sess_ptr, uint8 *data, UINT32 len)
{
	quec_tcpip_data *tcp_data = NULL;
	QuecOSStatus ret;

	if(data == NULL || len== 0)
		return;
	
	cert_printf("store_data_len = %d",len);
	
	tcp_data = (quec_tcpip_data *)quec_tcpip_new_data_2(data,len);

	cert_printf("data_ptr :%p, len=%d\r",tcp_data ,len);

	require(tcp_data != NULL,exit);

	memcpy(tcp_data->data_ptr, data, len);

	tcp_data->used += len;

	ret=linklist_push(&(sess_ptr->u.tcp_session.rx_q), DIR_FIFO, (data_t *)(tcp_data), sizeof(quec_tcpip_data));

	cert_printf("ret= %d\r",ret);

	free(tcp_data);
exit:
    return;
}

static void quec_iot_get_read_data(quec_tcpip_transfer_session *sess_ptr,uint8 *data, UINT32 *len)
{
	UINT32  want_read = *len;
	UINT32  data_len = 0;
	UINT32  read_len = 0;
	QuecOSStatus ret;
	*len = 0;

	cert_printf("want_read_len = %d",want_read);
	
	if(sess_ptr == NULL || data == NULL ||want_read == 0)
		return;
	
	do
	{
		if(sess_ptr->u.tcp_session.current_rx_data_ptr == NULL)
		{
			ret= linklist_pop(&(sess_ptr->u.tcp_session.rx_q), &(sess_ptr->u.tcp_session.current_rx_data_ptr), &data_len);
			cert_printf("current_rx_data_ptr=%p,ret= %d\r",sess_ptr->u.tcp_session.current_rx_data_ptr,ret);
		}
		cert_printf("data:%p,used=%d,len:%d\r",sess_ptr->u.tcp_session.current_rx_data_ptr,sess_ptr->u.tcp_session.current_rx_data_ptr->used,data_len);
		if(sess_ptr->u.tcp_session.current_rx_data_ptr == NULL)
			break;

		read_len = MIN_VAL(want_read, sess_ptr->u.tcp_session.current_rx_data_ptr->used);
		cert_printf("read_len = %d\r\n",read_len);

		memcpy(data+(*len), sess_ptr->u.tcp_session.current_rx_data_ptr->data_ptr, read_len);
		sess_ptr->u.tcp_session.current_rx_data_ptr->data_ptr += read_len;
		sess_ptr->u.tcp_session.current_rx_data_ptr->used -= read_len;
		want_read -= read_len;
		*len += read_len;
		
		if(sess_ptr->u.tcp_session.current_rx_data_ptr->used == 0)
		{
			quec_tcpip_free_data(sess_ptr->u.tcp_session.current_rx_data_ptr);
			sess_ptr->u.tcp_session.current_rx_data_ptr = NULL;
		}
	}while(want_read > 0);
		
	cert_printf("total:%d,read:%d, data_len=%d\r",sess_ptr->total_rx_size, sess_ptr->read_rx_size, *len);
	
}

static int  quectel_iot_rpt_decode(char *read_val)
{
    char	*rsp_info_ptr = read_val;
    int		rsp_info_len = NULL;
    cJSON	*result_code_obj = NULL;
    cJSON	*result_desc_obj = NULL;
    int		result_code = -1;
	
    char	*rsp_json_bdy_ptr = NULL;
	quectel_iot_context  *ctx_ptr = (quectel_iot_context *)quec_iot_mgr.iot_ctx;

	cert_printf("%s",rsp_info_ptr);
    rsp_json_bdy_ptr = (char*)strchr((char*)rsp_info_ptr,'{');
    if(NULL == rsp_json_bdy_ptr)
    {
        cert_printf("Not json type,parse fail");
        return APP_IOT_PS_REGI_FAIL;
    }
	else
	{
	}

    ctx_ptr->recv_json_ctx_ptr = cJSON_Parse((const char *)rsp_json_bdy_ptr);

	if (ctx_ptr->recv_json_ctx_ptr->type != cJSON_Object)
	{
		cJSON_Delete(ctx_ptr->recv_json_ctx_ptr);
		ctx_ptr->recv_json_ctx_ptr = NULL;
		return APP_IOT_PS_REGI_FAIL;
	}
	
    result_code_obj = cJSON_GetObjectItem(ctx_ptr->recv_json_ctx_ptr, "resultCode");

	if (result_code_obj != NULL)
	{
    	result_code = apptcpip_atoi(result_code_obj->valuestring);
	}

    result_desc_obj = cJSON_GetObjectItem(ctx_ptr->recv_json_ctx_ptr, "resultDesc");

	if (result_desc_obj != NULL)
	{
    	memcpy(ctx_ptr->resultDesc, result_desc_obj->valuestring, strlen(result_desc_obj->valuestring));
	}

    cJSON_Delete(ctx_ptr->recv_json_ctx_ptr);
	if (result_code == 1)
	{
		if (strcmp((const char*)ctx_ptr->resultDesc, "Success") == 0)
		{
			result_code = APP_IOT_PS_REGI_SUCC;
		}
		else if (strcmp((const char*)ctx_ptr->resultDesc, "Decode error") == 0)
		{
			result_code = APP_IOT_PS_REGI_FAIL;
		}
		else if (strcmp((const char*)ctx_ptr->resultDesc, "Check error") == 0)
		{
			result_code = APP_IOT_PS_REGI_FAIL;
		}
	}
	else if(result_code == 0)
	{
		result_code = APP_IOT_PS_REGI_SUCC;
	}

    return result_code;
}

extern char IMSI[];
extern char ICCID[];
void quectel_iot_get_data(quectel_iot_data_context * iot_data)
{	
	char imei_info[32] = {0};
	TIME end_time = {0};
	char iccid[32] = {0};
	char imsi[32] = {0};
	UINT8 low_nibble, high_nibble;
	char *pBuf = iot_data->iccid;
	int i,idx = 0;;
	
	quectel_egmr_get_imei(imei_info);
	memcpy(iot_data->imei1,imei_info,strlen((char *)imei_info));
	
	memcpy(iccid,ICCID,10);
	
	for (i = 0; i < 10; i++) 
	{
		low_nibble = iccid[i] & 0x0f;
		high_nibble = (iccid[i] & 0xf0) >> 4;
        if(low_nibble > 15)
        {
            pBuf[i] = 0;
			break;
        }
		else if (high_nibble > 15)
		{
		    pBuf[idx++] = low_nibble < 10 ? low_nibble + '0' : low_nibble - 10 + 'A';
			pBuf[i] = 0;
		}
		else
		{
		    pBuf[idx++] = low_nibble < 10 ? low_nibble + '0' : low_nibble - 10 + 'A';
			pBuf[idx++] = high_nibble < 10 ? high_nibble + '0' : high_nibble - 10 + 'A';
		}
	}
	
	memcpy(iot_data->imsi,IMSI,strlen(IMSI));

	sprintf(iot_data->cellid,"%X",quec_cereg_info.cellId);

	GetCurrentCompTime(&end_time);
	snprintf((char *)iot_data->time_str,64,"%04d-%02d-%02d %02d:%02d:%02d",end_time.year,
										end_time.month,end_time.day,end_time.hour,end_time.min,end_time.sec);
	return ;
}

extern char mob_sw_rev[];
extern char mob_model_id[];

static void quectel_iot_rpt_ctx_data_prepare_v5_0()
{
	quectel_iot_context  *ctx_ptr = (quectel_iot_context  *)quec_iot_mgr.iot_ctx;
	char  ctx_data[128] = {0};
	INT16 buf_len =0;
    INT16 model_len = 0;
    char model_id[64] = {0};
#ifdef QUECTEL_CTWing_SUPPORT	
	char mode_str[32] = {0};
    int32 ret = 0;
	int i = 0;
#endif	

	if(ctx_ptr->send_json_ctx_ptr == NULL)
	{
		ctx_ptr->send_json_ctx_ptr = cJSON_CreateObject();
	}
    if((mob_sw_rev != NULL)&&(mob_model_id != NULL))
    {
#ifdef QUECTEL_CTWing_SUPPORT
		ret = quectel_nv_fat_read(QUEC_CTWING_CFG, mode_str, sizeof(mode_str)+1);
		if(ret != QUEC_FAT_SUCCESS)
		{
			cert_printf("quectel_nv_fat_read get quec_ctwing_cfg fail");
			 memcpy(model_id,mob_model_id,strlen(mob_model_id));
		}
		else 
		{
			for(i = 0; i < strlen(mode_str); i++)
			{
				if(mode_str[i] == '-')
					mode_str[i] = ' ';
			}
			#ifndef __QUECTEL_PROJECT_EC800KCN_CC__
			buf_len = snprintf(model_id+buf_len, 50-buf_len, "QWS-%s ", mode_str);
			#else
			buf_len = snprintf(model_id+buf_len, 50-buf_len, "CTW-%s ", mode_str);
			#endif
	        cert_printf("model_id = %s",(char*)model_id);
		}
#else		
        model_len = strlen((char*)mob_model_id);
        memset((char*)model_id,0,sizeof((char*)model_id));
        cert_printf("model_len = %d",model_len);
		#ifndef __QUECTEL_PROJECT_EC800KCN_CC__
        strcpy(model_id,"QWS-");
		#else
		strcpy(model_id,"CTW-");
		#endif
        strcat(model_id,(char*)mob_model_id);
        strcat(model_id," ");
        memcpy(model_id+model_len+5,mob_sw_rev+model_len,2);
#endif		
        cert_printf("model_id = %s",(char*)model_id);
        cert_printf("mob_sw_rev = %s",(char*)mob_sw_rev);
    }
	
	cJSON_AddStringToObject(ctx_ptr->send_json_ctx_ptr,(char*)"REGVER", (char*)"5.0");
	cJSON_AddStringToObject(ctx_ptr->send_json_ctx_ptr,(char*)"MEID", (char*)""); 
    cJSON_AddStringToObject(ctx_ptr->send_json_ctx_ptr,(char*)"MODEL", (char*)model_id); 
	cJSON_AddStringToObject(ctx_ptr->send_json_ctx_ptr,(char*)"SWVER", (char*)mob_sw_rev);
	cJSON_AddStringToObject(ctx_ptr->send_json_ctx_ptr,(char*)"IMEI1", (char*)iot_data.imei1);
	cJSON_AddStringToObject(ctx_ptr->send_json_ctx_ptr,(char*)"SIM1CDMAIMSI", (char*)"");
	cJSON_AddStringToObject(ctx_ptr->send_json_ctx_ptr,(char*)"SIM1ICCID", (char*)iot_data.iccid);
	cJSON_AddStringToObject(ctx_ptr->send_json_ctx_ptr,(char*)"SIM1LTEIMSI", (char*)iot_data.imsi);
	cJSON_AddStringToObject(ctx_ptr->send_json_ctx_ptr,(char*)"SIM1CELLID", (char*)iot_data.cellid);
	cJSON_AddStringToObject(ctx_ptr->send_json_ctx_ptr,(char*)"REGDATE", (char*)iot_data.time_str);
	
	return ;
}

static char *quectel_iot_rpt_base64_encode(const char* data, int data_len)   
{   
    int prepare = 0;   
    int ret_len;   
    int temp = 0;   
    char *ret = NULL;   
    char *f = NULL;   
    int tmp = 0;   
    char changed[4];   
    int i = 0;   
    ret_len = data_len / 3;   
    temp = data_len % 3;   
    if (temp > 0)   
    {   
        ret_len += 1;   
    }   
    ret_len = ret_len*4 + 1;   
    ret = (char *)malloc(ret_len);   
        
    require(ret != NULL,exit);
		
    memset(ret, 0, ret_len);   
    f = ret;   
    while (tmp < data_len)   
    {   
        temp = 0;   
        prepare = 0;   
        memset(changed, '\0', 4);   
        while (temp < 3)   
        {   
            if (tmp >= data_len)   
            {   
                break;   
            }   
            prepare = ((prepare << 8) | (data[tmp] & 0xFF));   
            tmp++;   
            temp++;   
        }   
        prepare = (prepare<<((3-temp)*8));   
        for (i = 0; i < 4 ;i++ )   
        {   
            if (temp < i)   
            {   
                changed[i] = 0x40;   
            }   
            else   
            {   
                changed[i] = (prepare>>((3-i)*6)) & 0x3F;   
            }   
            *f = base_val[changed[i]];   
            f++;   
        }   
    }   
    *f = '\0';   
        
    return ret;           
exit:
    return NULL;
}

static void quectel_iot_rpt_encode()
{
	quectel_iot_context  *ctx_ptr = (quectel_iot_context  *)quec_iot_mgr.iot_ctx;
	quec_tcpip_transfer_session *trans_wm_ptr = &quec_iot_mgr.trans_wm_ptr;
	char  rpt_header_line[RPT_HEADER_LINE_LEN] = {0};
	INT16 buf_len =0;
	char *json_data = NULL;
	char *base64_rpt_data = NULL;

	quectel_iot_rpt_ctx_data_prepare_v5_0();
	json_data = (char*)cJSON_Print(ctx_ptr->send_json_ctx_ptr);
    cJSON_Delete(ctx_ptr->send_json_ctx_ptr);
	ctx_ptr->send_json_ctx_ptr = NULL;
	
	cert_printf("quec_iot_mgr.encrypt = %d",quec_iot_mgr.encrypt);
	if(quec_iot_mgr.encrypt == TRUE)
	{
		base64_rpt_data = (char*)quectel_iot_rpt_base64_encode((const char*)json_data,  strlen((char *)json_data));;
	}
	else
	{
		base64_rpt_data = json_data;
	}
	
	ctx_ptr->send_buffer = malloc(SEND_BUFFER_SIZE);
	if(ctx_ptr->send_buffer == NULL) return;
	
	memset(rpt_header_line, 0, RPT_HEADER_LINE_LEN);
	snprintf((char *)rpt_header_line, RPT_HEADER_LINE_LEN,"%s\r\n","POST / HTTP/1.1");
	buf_len += snprintf(ctx_ptr->send_buffer+buf_len, SEND_BUFFER_SIZE-buf_len, rpt_header_line);

	memset(rpt_header_line, 0, RPT_HEADER_LINE_LEN);
	snprintf((char *)rpt_header_line, RPT_HEADER_LINE_LEN,"Accept: %s\r\n","*/*");
	buf_len += snprintf(ctx_ptr->send_buffer+buf_len, SEND_BUFFER_SIZE-buf_len, rpt_header_line);

	memset(rpt_header_line, 0, RPT_HEADER_LINE_LEN);
	snprintf((char *)rpt_header_line, RPT_HEADER_LINE_LEN,"Host: %s:%d\r\n", ctx_ptr->server_addr_str, ctx_ptr->server_port);
	buf_len += snprintf(ctx_ptr->send_buffer+buf_len, SEND_BUFFER_SIZE-buf_len, rpt_header_line);

	memset(rpt_header_line, 0, RPT_HEADER_LINE_LEN);
	snprintf((char *)rpt_header_line, RPT_HEADER_LINE_LEN,"Content-Type: %s\r\n", "application/encrypted-json");
	buf_len += snprintf(ctx_ptr->send_buffer+buf_len, SEND_BUFFER_SIZE-buf_len, rpt_header_line);

	memset(rpt_header_line, 0, RPT_HEADER_LINE_LEN);
	snprintf((char *)rpt_header_line, RPT_HEADER_LINE_LEN,"Content-Length: %d\r\n", strlen((char *)base64_rpt_data));
	buf_len += snprintf(ctx_ptr->send_buffer+buf_len, SEND_BUFFER_SIZE-buf_len, rpt_header_line);

	memset(rpt_header_line, 0, RPT_HEADER_LINE_LEN);
	snprintf((char *)rpt_header_line, RPT_HEADER_LINE_LEN,"User-Agent: %s\r\n", "Quectel-Module");
	buf_len += snprintf(ctx_ptr->send_buffer+buf_len, SEND_BUFFER_SIZE-buf_len, rpt_header_line);

	memset(rpt_header_line, 0, RPT_HEADER_LINE_LEN);
	snprintf((char *)rpt_header_line, RPT_HEADER_LINE_LEN,"Connection: %s\r\n","keep-alive");
	buf_len += snprintf(ctx_ptr->send_buffer+buf_len, SEND_BUFFER_SIZE-buf_len, rpt_header_line);

	memset(rpt_header_line, 0, RPT_HEADER_LINE_LEN);
	snprintf((char *)rpt_header_line, RPT_HEADER_LINE_LEN,"\r\n");
	buf_len += snprintf(ctx_ptr->send_buffer+buf_len, SEND_BUFFER_SIZE-buf_len, rpt_header_line);
	
	cert_printf("Header_len = %d",buf_len);

	quec_iot_store_send_data(trans_wm_ptr, ctx_ptr->send_buffer, buf_len);
	quec_iot_store_send_data(trans_wm_ptr, base64_rpt_data, strlen((char *)base64_rpt_data));

	buf_len += strlen((char *)base64_rpt_data);
	cert_printf("Totle_len = %d",buf_len);
	ctx_ptr->send_buffer_len = buf_len;
	return ;
}

static void quectel_iot_process_read_event()
{
	char* read_buf = NULL;
	INT32 read_len;
	quec_tcpip_transfer_session *trans_wm_ptr = &quec_iot_mgr.trans_wm_ptr;

	quectel_iot_context  *ctx_ptr = (quectel_iot_context  *)quec_iot_mgr.iot_ctx;
	read_buf = malloc(512);
	
	memset(read_buf,0,512);
	read_len = quec_soc_recv(ctx_ptr->sockfd, read_buf, 512);

	if(read_len <= 0)
		return;
	
	cert_printf("read_len = %d",read_len);

	quec_iot_store_recv_data(trans_wm_ptr, read_buf, read_len);

	quec_iot_msgsnd(QUEC_IOT_DECODE_DATA_REQ, NULL);
}

void quectel_iot_process_close_event()
{
	struct linger  linger_opt;
	UINT32  param_size;
	int timeout = 1; 
	
	quectel_iot_context  *ctx_ptr = (quectel_iot_context  *)quec_iot_mgr.iot_ctx;

	quec_iot_mgr.iot_opened = FALSE;
	ctx_ptr->iot_state = QUECTEL_IOT_IDLE;
	quectel_iot_deinit_data_wm();

	if(ctx_ptr->sockfd >= 0)
	{
		param_size = sizeof(struct linger);
		memset(&linger_opt, 0, sizeof(linger_opt));
		quec_soc_getopt(ctx_ptr->sockfd, QUEC_SOC_LINGER, (void *) &linger_opt, &param_size);
		quec_soc_setopt(ctx_ptr->sockfd, QUEC_SOC_TCP_CLOSE_TIMEROUT, &timeout, sizeof(timeout));
		
		cert_printf("linger_opt.l_onoff =%d",linger_opt.l_onoff );

		if(linger_opt.l_onoff == FALSE)
		{
			linger_opt.l_onoff = TRUE;
			linger_opt.l_linger = 0;

			quec_soc_setopt(ctx_ptr->sockfd, QUEC_SOC_LINGER, (void *)&linger_opt, param_size);
		}
	
		quec_soc_close(ctx_ptr->sockfd);
		ctx_ptr->sockfd = -1;
	}
	
	//quectel_iot_event_urc_report(APP_IOT_CONN_CLOSE);
}

static void quectel_iot_socket_event_cb
(
int	    sockfd,
uint32  event_mask,
int     err_no, 
void *  user_data
)
{
	quectel_iot_context  *ctx_ptr = (quectel_iot_context  *)quec_iot_mgr.iot_ctx;
	
	if(event_mask & QUEC_SOC_CONNECT_EVENT)
	{
		cert_printf("QUEC_SOC_CONNECT_EVENT ");
		event_mask &= ~QUEC_SOC_CONNECT_EVENT;
		if(err_no == QUEC_SOC_OK)
		{
			quectel_iot_event_urc_report(APP_IOT_BEGIN_SEND_DATA);
			
			ctx_ptr->iot_state = QUECTEL_IOT_CONNECTED;
			quec_iot_mgr.iot_opened = TRUE;
			
			quectel_iot_init_data_wm();
			quectel_iot_rpt_encode();

			quec_iot_msgsnd(QUEC_IOT_PUT_DATA_REQ, NULL);
		}
		else
		{
			quectel_iot_process_close_event();

			quectel_iot_event_urc_report(APP_IOT_SEND_DATA_FAIL);
		}
		cert_printf("ftp_state = %d",ctx_ptr->iot_state);
	}
	else if(event_mask & QUEC_SOC_READ_EVENT)
	{
		cert_printf("QUEC_SOC_READ_EVENT");

		quectel_iot_process_read_event();
	}
	else if(event_mask & QUEC_SOC_WRITE_EVENT)
	{
		cert_printf("QUEC_SOC_WRITE_EVENT ");
		event_mask &= ~QUEC_SOC_WRITE_EVENT;

		quec_iot_msgsnd(QUEC_IOT_PUT_DATA_REQ, NULL);
	}
	else if(event_mask & QUEC_SOC_CLOSE_EVENT)
	{
		cert_printf("QUEC_SOC_CLOSE_EVENT ");
		event_mask &= ~QUEC_SOC_CLOSE_EVENT;

		quectel_iot_process_close_event();
	}
	else if(event_mask & QUEC_SOC_NET_DOWN_EVENT)
	{
		cert_printf("QUEC_SOC_NET_DOWN_EVENT ");
		event_mask &= ~QUEC_SOC_NET_DOWN_EVENT;
		quectel_iot_process_close_event();
	} 

	return ;

}

static INT32 quectel_iot_connect_to_server
(
quectel_iot_context  *ctx_ptr
)
{
	INT32 ret;
	INT32  select_event;

	cert_printf("ctx_ptr = %d",ctx_ptr);
	
	ctx_ptr->sockfd = quec_soc_create(QUEC_AF_INET,QUEC_SOC_TCP,QUEC_TCP_PROTOCOL, ctx_ptr->pdp_cid);

	cert_printf("sockfd = %d,server_port = %d,local_port = %d",ctx_ptr->sockfd,ctx_ptr->server_port,ctx_ptr->local_port);

	quec_soc_bind(ctx_ptr->sockfd, &ctx_ptr->local_ip, ctx_ptr->local_port);
	
	if(ctx_ptr->sockfd < 0)
	{
		ctx_ptr->iot_state = QUECTEL_IOT_IDLE;

		quectel_iot_event_urc_report(APP_IOT_OVER_MEMORY);
		return APP_IOT_ERR_FAIL;
	}

	select_event = QUEC_SOC_CONNECT_EVENT|QUEC_SOC_READ_EVENT|QUEC_SOC_WRITE_EVENT|QUEC_SOC_CLOSE_EVENT|QUEC_SOC_NET_DOWN_EVENT;

	if(quec_soc_select(ctx_ptr->sockfd,select_event,quectel_iot_socket_event_cb, NULL) < 0)
	{
		;
	}
	
	ret = quec_soc_connect(ctx_ptr->sockfd, &ctx_ptr->server_ip, ctx_ptr->server_port);

	cert_printf("quec_soc_connect,ret=%d", ret);

	if(ret == QUEC_SOC_ERR_WODBLOCK)
	{
		ctx_ptr->iot_state = QUECTEL_IOT_CONNECTING;
		ret = APP_IOT_WOULDBLOCK;
	}
	else if(ret == QUEC_SOC_OK)
	{
		ctx_ptr->iot_state = QUECTEL_IOT_CONNECTED;
		ret = APP_IOT_OK;
	}
	else
	{		
		quec_soc_close(ctx_ptr->sockfd);
		ctx_ptr->sockfd= -1;

		ctx_ptr->iot_state = QUECTEL_IOT_IDLE;

		quectel_iot_event_urc_report(APP_IOT_ERROR_NETWORK);
	}
	return ret;
}


void quec_iot_request_handler(quec_iot_msg *api_msg)
{
	cert_printf("msg_id = %d",api_msg->msg_id);
	switch(api_msg->msg_id)
	{
		case QUEC_IOT_PDP_ACTIVE_REQ:
			quectel_iot_pdp_active_cmd_handler(api_msg->data_ptr);
			break;
		case QUEC_IOT_OPEN_REQ:
			quectel_iot_open_cmd_handler(api_msg->data_ptr);
			break;
		case QUEC_IOT_PUT_DATA_REQ:
			quectel_iot_put_data_cmd_handler(api_msg->data_ptr);
			break;
		case QUEC_IOT_DECODE_DATA_REQ:
			quectel_iot_decode_data_cmd_handler(api_msg->data_ptr);
			break;
		default:
			break;
	}
}


void quec_iot_cnf_handler(quec_iot_msg *api_msg)
{
	cert_printf("msg_id=%d",api_msg->msg_id);
	switch(api_msg->msg_id)
	{
		case QUEC_IOT_PDP_ACTIVE_CNF:
			quectel_iot_pdp_active_event_proc(api_msg->data_ptr);
			break;
		case QUEC_IOT_PDP_DEACTIVE_CNF:
			quectel_iot_pdp_deactive_event_proc(api_msg->data_ptr);
			break;
		case QUEC_IOT_OPEN_CNF:
			quectel_iot_open_event_proc(api_msg->data_ptr);
			break;
		default:
			break;
	}
}

void quec_iot_timer_handler(quec_iot_msg *api_msg)
{
	cert_printf("msg_id=%d",api_msg->msg_id);

	switch(api_msg->msg_id)
	{
		case QUEC_IOT_TIMER_CREG_CHECK_CB_HANDER:
			quectel_iot_timer_creg_check_cb_hander(api_msg->data_ptr);
			break;
		case QUEC_IOT_TIMER_REG_RETRY_CB_HANDER:
			quectel_iot_timer_reg_retry_cb_hander(api_msg->data_ptr);
			break;
		default:
			break;
	}
}

INT32  quectel_iot_open
(
quectel_iot_context * iot_ctx,
UINT16  pdp_cid,
CHAR   *server_addr,
UINT16 server_port,
UINT32  atpindex
)
{
	quectel_iot_context  *ctx_ptr = (quectel_iot_context *)iot_ctx;
	
	cert_printf("iot_ctx :%d", ctx_ptr);
	
	if(ctx_ptr == NULL)
		return APP_IOT_INVALID_PARAM;

    ctx_ptr->pdp_cid = pdp_cid;
	ctx_ptr->iot_state = QUECTEL_IOT_IDLE;
	ctx_ptr->send_json_ctx_ptr = NULL;
	ctx_ptr->recv_json_ctx_ptr = NULL;
	ctx_ptr->sockfd = -1;
	ctx_ptr->send_buffer = NULL;
	ctx_ptr->send_buffer_len = 0;
	ctx_ptr->atpindex = atpindex;
	
    /*若默认值为空，则设置连接默认服务器，保持和高通一致*/
	cert_printf("server_addr :%s,server_port=%d", server_addr,server_port);
	memset(ctx_ptr->server_addr_str, 0, 255);
    if(0 == server_port)
    {
        ctx_ptr->server_port = 9999;
        memcpy(ctx_ptr->server_addr_str,"zzhc.vnet.cn",strlen((char *)"zzhc.vnet.cn"));
    }
    else
    {
 	    ctx_ptr->server_port = server_port;
	    memcpy(ctx_ptr->server_addr_str, server_addr, strlen((char *)server_addr));
    }
	cert_printf("ctx_ptr->server_addr_str :%s", ctx_ptr->server_addr_str);

	
	quec_iot_mgr.wm_have_init = FALSE;
	quec_iot_mgr.encrypt == TRUE;

	quec_iot_msgsnd(QUEC_IOT_OPEN_REQ, NULL);
	return APP_IOT_OK;
}

static void  quectel_iot_pdp_active_cmd_handler
(
void *user_data_ptr
)
{
	quectel_iot_context  *ctx_ptr = (quectel_iot_context *)quec_iot_mgr.iot_ctx;

	quec_apptcpip_pdp_active_req  *active_msg = NULL;

	cert_printf("pdp_cid:%d",ctx_ptr->pdp_cid);

	active_msg = malloc(sizeof(quec_apptcpip_pdp_active_req));

	if(active_msg == NULL)
	{
		quectel_iot_event_urc_report(APP_IOT_ERR_FAIL);
		return ;
	}
	active_msg->atHandle = 0XFFFFFFFE;
	active_msg->pdp_cid = ctx_ptr->pdp_cid;

	return quec_apptcpip_requst(QUEC_APPTCPIP_PDP_ACTIVE_REQ, active_msg);
}

static int quectel_iot_pdp_act_cb(void * user_argv, void * argv)
{
	quectel_iot_context  *ctx_ptr = (quectel_iot_context *)quec_iot_mgr.iot_ctx;
	cert_printf("client_ptr=%p",ctx_ptr);
	
	pdp_act_status_t * pdp_act_status = (pdp_act_status_t *)argv;

	if(pdp_act_status->op == PDP_OP_ACT)
	{
		if(pdp_act_status->pdp_cid == ctx_ptr->pdp_cid)
		{
			if(quec_pdp_get_act_status(pdp_act_status->pdp_cid) == 1)
				quec_netif_bind_service_start(pdp_act_status->pdp_cid, 1000, 20);
			else
			{
			    if(ctx_ptr->pdp_nic_bind_sem != NULL)
				    quec_rtos_semaphore_release(ctx_ptr->pdp_nic_bind_sem);
		    }
		}
	}
	
	return 0;
}

static int quectel_iot_nic_bind_cb(void * user_argv, void * argv)
{
	quectel_iot_context  *ctx_ptr = (quectel_iot_context *)quec_iot_mgr.iot_ctx;
	cert_printf("client_ptr=%p",ctx_ptr);

	netif_bind_status_t * netif_bind_status = (netif_bind_status_t *)argv;

	if(netif_bind_status->op == NETIF_OP_BIND)
	{
		if(netif_bind_status->pdp_cid == ctx_ptr->pdp_cid)
		{
		    if(ctx_ptr->pdp_nic_bind_sem != NULL)
			    quec_rtos_semaphore_release(ctx_ptr->pdp_nic_bind_sem);
		}
	}

	return 0;
}

static QuecOSStatus quectel_iot_pdp_handler(quectel_iot_context  *ctx_ptr)
{
    QuecOSStatus     err    = kNoErr;

    err = quec_rtos_semaphore_create(&ctx_ptr->pdp_nic_bind_sem, 0);
	require_noerr(err, exit);

	if(quec_pdp_get_act_status(ctx_ptr->pdp_cid) == 0)
	{
		err = quec_event_notify_register(EVENT_NET_PDP_ACT, quectel_iot_pdp_act_cb, (void*)ctx_ptr);
		require_noerr(err, exit);

		err = quec_event_notify_register(EVENT_NET_NIC_BIND, quectel_iot_nic_bind_cb, (void*)ctx_ptr);
		require_noerr(err, exit3);

		err = quec_pdp_act_service_start(ctx_ptr->pdp_cid, ctx_ptr->atpindex, quec_get_pdp_act_retrytimes());
		require_noerr(err, exit2);

		cert_printf("wait for netif bind result");
		
		err = quec_rtos_semaphore_wait(ctx_ptr->pdp_nic_bind_sem, QUEC_WAIT_FOREVER);
		require_noerr(err, exit2);

		cert_printf("netif bind result comes out");

		err = quec_event_notify_unregister(EVENT_NET_PDP_ACT, quectel_iot_pdp_act_cb);
		require_noerr(err, exit1);

		err = quec_event_notify_unregister(EVENT_NET_NIC_BIND, quectel_iot_nic_bind_cb);
		require_noerr(err, exit);

        require_action(quec_pdp_get_act_status(ctx_ptr->pdp_cid), exit, err = kGeneralErr);
		require_action(quec_netif_get_bind_status(ctx_ptr->pdp_cid), exit, err = kGeneralErr);
	}
	else if(quec_netif_get_bind_status(ctx_ptr->pdp_cid) == 0)
	{
		err = quec_event_notify_register(EVENT_NET_NIC_BIND, quectel_iot_nic_bind_cb, (void*)ctx_ptr);
		require_noerr(err, exit);

		err = quec_netif_bind_service_start(ctx_ptr->pdp_cid, 1000, 20);
        require_noerr(err, exit1);

		cert_printf("wait for netif bind result");
		
		err = quec_rtos_semaphore_wait(ctx_ptr->pdp_nic_bind_sem, QUEC_WAIT_FOREVER);
		require_noerr(err, exit1);

		cert_printf("netif bind result comes out");

		err = quec_event_notify_unregister(EVENT_NET_NIC_BIND, quectel_iot_nic_bind_cb);
		require_noerr(err, exit);

		require_action(quec_netif_get_bind_status(ctx_ptr->pdp_cid), exit, err = kGeneralErr);
	}

    err = quec_rtos_semaphore_delete(ctx_ptr->pdp_nic_bind_sem);
    return err;
    
exit3:
    quec_event_notify_unregister(EVENT_NET_PDP_ACT, quectel_iot_pdp_act_cb);
    quec_rtos_semaphore_delete(ctx_ptr->pdp_nic_bind_sem);
    return err;
exit2:
    quec_event_notify_unregister(EVENT_NET_PDP_ACT, quectel_iot_pdp_act_cb);    
exit1:
    quec_event_notify_unregister(EVENT_NET_NIC_BIND, quectel_iot_nic_bind_cb);
exit:
    quec_rtos_semaphore_delete(ctx_ptr->pdp_nic_bind_sem);
    return err;
}


static void  quectel_iot_open_cmd_handler
(
void *user_data_ptr
)
{
	quectel_iot_context  *ctx_ptr = (quectel_iot_context *)quec_iot_mgr.iot_ctx;
	INT32  ret = -1;

	quec_pdp_info pdp_info;
	quec_ip_addr  remote_addr;
	quec_ip_addr  local_addr;
	
    cert_printf("ctx_ptr = %d",ctx_ptr);

    if(quectel_iot_pdp_handler(ctx_ptr) != kNoErr)
    {
        cert_printf("pdp active error!!!");
        quectel_iot_event_urc_report(APP_IOT_PDP_ACTED_FAIL);
        return ;
    }

	if(quec_net_get_pdp_state(ctx_ptr->pdp_cid) == QUEC_PDP_STATE_NONE)
	{
		cert_printf("QUEC_PDP_STATE_NONE");

		quectel_iot_event_urc_report(APP_IOT_PDP_ACT);
		quec_iot_msgsnd(QUEC_IOT_PDP_ACTIVE_REQ, NULL);
		return ;
	}
	else
	{
		cert_printf("QUEC_PDP_STATE_PDP_ACTIVED");

		quectel_iot_event_urc_report(APP_IOT_PDP_ACTED_SUCC);
		
		memset(&remote_addr, 0, sizeof(quec_ip_addr));
		memset(&local_addr, 0, sizeof(quec_ip_addr));
		memset(&pdp_info, 0, sizeof(quec_pdp_info));

		quectel_iot_event_urc_report(APP_IOT_BEGIN_DNS);
		quec_net_get_pdp_info(ctx_ptr->pdp_cid, &pdp_info);

#ifdef QUEC_PDP_IPV4V6_SUPPORT

        ctx_ptr->quec_ip_vsn = QUEC_PDP_IPV4;
        ctx_ptr->local_port = quec_tcpip_generate_local_port();
    
        ret =  quec_tcpip_is_valid_ip46_address(ctx_ptr->server_addr_str);
        cert_printf("0: DNS 1:IPV4 2:IPV6 ret = %d",ret);
    
        if(ret > 0)
        {
            
            if(ret == 1 
               && (pdp_info.pdp_ip_type == QUEC_PDP_IPV4 || pdp_info.pdp_ip_type == QUEC_PDP_IPV4V6))
            {
                quectel_iot_event_urc_report(APP_IOT_DNS_PARSE_SUCC);
                
                struct sockaddr_in addr_inet;
                struct sockaddr_in ip4;

                memset(&ip4, 0, sizeof(struct sockaddr_in));
                memcpy(&local_addr, &pdp_info.ip_addr_v4,sizeof(quec_ip_addr));
                memcpy(&(ctx_ptr->local_ip), &local_addr, sizeof(quec_ip_addr));
                ip4.sin_addr.s_addr = htonl(local_addr.quec_ipv4_addr.ip_addr);
                strcpy(ctx_ptr->local_addr_str,inet_ntoa(ip4.sin_addr));
                cert_printf("local_addr:%s\r",ctx_ptr->local_addr_str);

                memset(&addr_inet, 0, sizeof(struct sockaddr_in));
                inet_aton(ctx_ptr->server_addr_str, &addr_inet.sin_addr);
                remote_addr.ip_vsn = QUEC_PDP_IPV4;
                remote_addr.quec_ipv4_addr.ip_addr = ntohl(addr_inet.sin_addr.s_addr);
                memcpy(&(ctx_ptr->server_ip), &remote_addr, sizeof(quec_ip_addr));
            }
            else if(ret == 2
                   && (pdp_info.pdp_ip_type == QUEC_PDP_IPV6 || pdp_info.pdp_ip_type == QUEC_PDP_IPV4V6))
            {
                cert_printf("Not support IPV6 for now,Not necessary");
                quectel_iot_event_urc_report(APP_IOT_DNS_PARSE_FAIL);
            }
            else
            {
                quectel_iot_event_urc_report(APP_IOT_ERR_FAIL);
                return ;
            }
        }
        else
        {
            struct addrinfo * pres = NULL;
            ret = getaddrinfo_with_pcid(ctx_ptr->server_addr_str, NULL, NULL, &pres, ctx_ptr->pdp_cid);
            cert_printf("getaddrinfo ret:%d, pres:%p\r",ret,pres);
            if(ret < 0 || pres == NULL)
            {
                quectel_iot_event_urc_report(APP_IOT_DNS_PARSE_FAIL);
                return ;
            }
            
            if (pres->ai_family == AF_INET 
                && (pdp_info.pdp_ip_type == QUEC_PDP_IPV4 || pdp_info.pdp_ip_type == QUEC_PDP_IPV4V6)) 
            {
                quectel_iot_event_urc_report(APP_IOT_DNS_PARSE_SUCC);
                
                struct sockaddr_in * sin_res = (struct sockaddr_in *)pres->ai_addr;
                struct sockaddr_in ip4;

                memset(&ip4, 0, sizeof(struct sockaddr_in));
                memcpy(&local_addr, &pdp_info.ip_addr_v4,sizeof(quec_ip_addr));
                memcpy(&(ctx_ptr->local_ip), &local_addr, sizeof(quec_ip_addr));
                ip4.sin_addr.s_addr = htonl(local_addr.quec_ipv4_addr.ip_addr);
                strcpy(ctx_ptr->local_addr_str,inet_ntoa(ip4.sin_addr));
                cert_printf("local_addr:%s\r",ctx_ptr->local_addr_str);
                
                remote_addr.ip_vsn = QUEC_PDP_IPV4;
                remote_addr.quec_ipv4_addr.ip_addr = ntohl(sin_res->sin_addr.s_addr);
                cert_printf("remote_addr:%s\r",inet_ntoa(sin_res->sin_addr));
                memcpy(&(ctx_ptr->server_ip), &remote_addr, sizeof(quec_ip_addr));
            }
            else if(pres->ai_family == AF_INET6 
                    && (pdp_info.pdp_ip_type == QUEC_PDP_IPV6 || pdp_info.pdp_ip_type == QUEC_PDP_IPV4V6))
            {
                quectel_iot_event_urc_report(APP_IOT_DNS_PARSE_FAIL);
            }
            else
            {
                quectel_iot_event_urc_report(APP_IOT_DNS_PARSE_FAIL);
                freeaddrinfo(pres);
                return ;
            }
            freeaddrinfo(pres);
        }

#else		
		ctx_ptr->quec_ip_vsn = QUEC_PDP_IPV4;
		ctx_ptr->local_port = quec_tcpip_generate_local_port();
		
		if(pdp_info.ip_addr_v4.ip_vsn != QUEC_PDP_INVALID && ctx_ptr->quec_ip_vsn == QUEC_PDP_IPV4)
		{
			struct sockaddr_in ip4;
			memset(&ip4, 0, sizeof(struct sockaddr_in));

			memcpy(&local_addr, &pdp_info.ip_addr_v4,sizeof(quec_ip_addr));
			memcpy(&(ctx_ptr->local_ip), &local_addr, sizeof(quec_ip_addr));
			ip4.sin_addr.s_addr = htonl(local_addr.quec_ipv4_addr.ip_addr);
			strcpy(ctx_ptr->local_addr_str,inet_ntoa(ip4.sin_addr));
			cert_printf("local_addr:%s\r",ctx_ptr->local_addr_str);
		}
		else if(pdp_info.ip_addr_v6.ip_vsn !=  QUEC_PDP_INVALID && ctx_ptr->quec_ip_vsn == QUEC_PDP_IPV6)
		{
			quectel_iot_event_urc_report(APP_IOT_DNS_PARSE_FAIL);
		}
		else
		{
			quectel_iot_event_urc_report(APP_IOT_DNS_PARSE_FAIL);
			return ;
		}

		ret =  quec_tcpip_is_valid_ip46_address(ctx_ptr->server_addr_str);
		cert_printf("0: DNS 1:IPV4 2:IPV6 ret = %d",ret);
		
		if(ret > 0)
		{
			quectel_iot_event_urc_report(APP_IOT_DNS_PARSE_SUCC);
			
			if(ret == 1 && local_addr.ip_vsn == QUEC_PDP_IPV4)
			{

				struct sockaddr_in addr_inet;

				memset(&addr_inet, 0, sizeof(struct sockaddr_in));

				inet_aton(ctx_ptr->server_addr_str, &addr_inet.sin_addr);

				remote_addr.ip_vsn = QUEC_PDP_IPV4;
				remote_addr.quec_ipv4_addr.ip_addr = ntohl(addr_inet.sin_addr.s_addr);
				memcpy(&(ctx_ptr->server_ip), &remote_addr, sizeof(quec_ip_addr));
			}
			else if(ret == 2&& local_addr.ip_vsn == QUEC_PDP_IPV6)
			{
				cert_printf("Not support IPV6 for now,Not necessary");
			}
			else
			{
				quectel_iot_event_urc_report(APP_IOT_ERR_FAIL);
				return ;
			}
		}
		else
		{
			struct addrinfo * pres = NULL;
			ret = getaddrinfo_with_pcid(ctx_ptr->server_addr_str, NULL, NULL, &pres, ctx_ptr->pdp_cid);
			cert_printf("getaddrinfo ret:%d, pres:%p\r",ret,pres);
			if(ret < 0 || pres == NULL)
			{
				quectel_iot_event_urc_report(APP_IOT_DNS_PARSE_FAIL);
				return ;
			}
			
			if (pres->ai_family == AF_INET && local_addr.ip_vsn == QUEC_PDP_IPV4) 
			{
				quectel_iot_event_urc_report(APP_IOT_DNS_PARSE_SUCC);
				
				struct sockaddr_in * sin_res = (struct sockaddr_in *)pres->ai_addr;

				remote_addr.ip_vsn = QUEC_PDP_IPV4;

				remote_addr.quec_ipv4_addr.ip_addr = ntohl(sin_res->sin_addr.s_addr);
				cert_printf("remote_addr:%s\r",inet_ntoa(sin_res->sin_addr));
				memcpy(&(ctx_ptr->server_ip), &remote_addr, sizeof(quec_ip_addr));
			}
			else if(pres->ai_family == AF_INET6 && local_addr.ip_vsn == QUEC_PDP_IPV6)
			{
				quectel_iot_event_urc_report(APP_IOT_DNS_PARSE_FAIL);
			}
			else
			{
				quectel_iot_event_urc_report(APP_IOT_DNS_PARSE_FAIL);
				freeaddrinfo(pres);
				return ;
			}
			freeaddrinfo(pres);
		}
		
#endif
		
		ret = quectel_iot_connect_to_server(ctx_ptr);
		
	}

	cert_printf("open_cmd:ret=%d", ret);
	if(!(ret == APP_IOT_OK||ret == APP_IOT_WOULDBLOCK))
	{
		quectel_iot_event_urc_report(ret);
		ctx_ptr->iot_state = QUECTEL_IOT_IDLE;
	}
	else
	{
		//We also need to start timer to ....
		//OSATimerStart(ctx_ptr->ftp_ctrl_timer, ctx_ptr->ftp_timeout*QUEC_RTOS_TICKS_PER_SEC, 0, quectel_ftp_ctrl_timer_cb_fcn, 0);
	}
}

static void quectel_iot_put_data_cmd_handler
(
void *user_data_ptr
)
{
	INT32   ret;
	char * put_data_buf =NULL;
	INT32 send_len = SEND_BUFFER_SIZE;
	quectel_iot_context  *ctx_ptr = (quectel_iot_context *)quec_iot_mgr.iot_ctx;
	quec_tcpip_transfer_session *trans_wm_ptr = &quec_iot_mgr.trans_wm_ptr;

	put_data_buf = (char *)malloc(SEND_BUFFER_SIZE);
	if(put_data_buf == NULL)
		return;

	quec_iot_get_send_data(trans_wm_ptr,put_data_buf, &send_len);
	cert_printf("quec_iot_get_send_data->want:%d ,read_len:%d",SEND_BUFFER_SIZE,send_len);

	if(send_len == 0)
    {
        if(put_data_buf != NULL)
            free(put_data_buf);
        return;
    }
	
	ret = quec_soc_send(ctx_ptr->sockfd, put_data_buf, send_len);
	cert_printf("quec_soc_send ret=%d",ret);
	

	if(ret == QUEC_SOC_ERR_WODBLOCK || (ret > 0 && (ret < send_len)))
	{
        quec_tcpip_data *iot_data = NULL;
        
        if(ret == QUEC_SOC_ERR_WODBLOCK)
        {
            ret = 0;
        }
        
        if(trans_wm_ptr->u.tcp_session.current_tx_data_ptr != NULL)
        {
            linklist_push(&(trans_wm_ptr->u.tcp_session.tx_q), DIR_LIFO, (data_t *)(trans_wm_ptr->u.tcp_session.current_tx_data_ptr), sizeof(quec_tcpip_data));
			free(trans_wm_ptr->u.tcp_session.current_tx_data_ptr);
			trans_wm_ptr->u.tcp_session.current_tx_data_ptr = NULL;
        }
        else
    	{
	        iot_data = (quec_tcpip_data *)quec_tcpip_new_data((send_len - ret));
	        memcpy(iot_data->data_ptr,put_data_buf + ret,(send_len - ret));
	        iot_data->used += (send_len - ret);
	        
	        trans_wm_ptr->u.tcp_session.current_tx_data_ptr = iot_data;
    	}
        
        if(ret > 0 && (ret < send_len))
        {
            quec_iot_msgsnd(QUEC_IOT_PUT_DATA_REQ, NULL);
        }
        
        if(put_data_buf != NULL)
        {
            free(put_data_buf);
            put_data_buf = NULL;
        }
        return ;   //here return;
	}
	else if(ret < 0)
	{
		//call close 
	}
	
	return ;
}

static void quectel_iot_decode_data_cmd_handler
(
void *user_data_ptr
)
{
	char* read_buf = NULL;
	int read_len = 512;
	int	result_code;
	
	quectel_iot_context  *ctx_ptr = (quectel_iot_context *)quec_iot_mgr.iot_ctx;
	quec_tcpip_transfer_session *trans_wm_ptr = &quec_iot_mgr.trans_wm_ptr;

	cert_printf("ftp_ctx = %d,ftp_state = %d",ctx_ptr,ctx_ptr->iot_state);
	
	read_buf = malloc(512);
	if(read_buf == NULL)
	{
		return ;
	}

	memset(read_buf,0,512);
	quec_iot_get_read_data(trans_wm_ptr,read_buf, &read_len);
	cert_printf("quec_iot_get_send_data->want:%d ,read_len:%d",512,read_len);

	result_code = quectel_iot_rpt_decode(read_buf);

	if(quec_iot_mgr.call_close == TRUE)   //don't report more than once
		return ;
	
	if(result_code == APP_IOT_PS_REGI_SUCC)
	{
		OSATimerStatus  timer_status;
		if(quec_iot_mgr.ps_reg_timer)
		{
			OSATimerGetStatus(quec_iot_mgr.ps_reg_timer, &timer_status);
			if(timer_status.status == OS_TIMER_ACTIVE)
				OSATimerStop(quec_iot_mgr.ps_reg_timer);
			OSATimerDelete(quec_iot_mgr.ps_reg_timer);
		}
		quec_iot_mgr.ps_reg_timer = NULL;

		quec_iot_mgr.decode_state = IOT_DECODE_SUCC;
		memcpy(quec_iot_mgr.ueiccid,iot_data.iccid, sizeof(iot_data.iccid));
		quectel_nv_fat_write(QUEC_IOTRPT_UEICCID_CONFIG_CONTEXT, iot_data.iccid, sizeof(iot_data.iccid));
	}
	else
	{
		quec_iot_mgr.call_close = TRUE;
		//quectel_iot_process_close_event();
	}

	quectel_iot_event_urc_report(result_code);
	
	if(read_buf != NULL)
	{
		free(read_buf) ;
	}

	
}

static int  quectel_iot_pdp_active_event_proc
(
void *user_data_ptr
)
{
	quectel_ds_iot_event_info *event_info = (quectel_ds_iot_event_info *)user_data_ptr;
	quectel_iot_context  *ctx_ptr = (quectel_iot_context *)quec_iot_mgr.iot_ctx;

	if(event_info->result == APP_IOT_OK)
	{
		quectel_iot_open_cmd_handler(NULL);
		return 0;
	}
	else
	{
		quectel_iot_event_urc_report(APP_IOT_PDP_ACTED_FAIL);
	}
	return 0;
}


static int  quectel_iot_open_event_proc
(
void *user_data_ptr
)
{
	quectel_ds_iot_event_info *event_info = (quectel_ds_iot_event_info *)user_data_ptr;
	char ind_buf[100] = {0};
	int result = event_info->result;
	quectel_iot_context  *ctx_ptr = (quectel_iot_context *)quec_iot_mgr.iot_ctx;
	
	cert_printf("ftp_ctx = %d,ftp_state = %d",ctx_ptr,ctx_ptr->iot_state);

	if(event_info->result == APP_IOT_OK)
	{
		quec_iot_mgr.iot_opened = TRUE;
	}
	else
	{
	    quec_iot_mgr.iot_opened = FALSE;
	}

	cert_printf("OPEN result=%d\r", event_info->result);

    snprintf(ind_buf, 100, "+QIOTRPT: %d", event_info->result);

    #ifdef QUEC_AT_URC_SUPPORT
	if(quec_iot_mgr.is_send_urc)
	{
        at_urc_send(quec_iot_mgr.sio_port, ind_buf, strlen(ind_buf),FALSE, URC_OUT_METHOD_UNICAST, NULL);
	}
	else
	{
	}
    #endif
	
	return 0;
}

static int  quectel_iot_pdp_deactive_event_proc
(
void *user_data_ptr
)
{
	quectel_ds_iot_event_info *event_info = (quectel_ds_iot_event_info *)user_data_ptr;
	quectel_iot_context  *ctx_ptr = (quectel_iot_context *)quec_iot_mgr.iot_ctx;
	UINT16 pdp_cid = event_info->result;
	
	cert_printf("ctx_ptr->pdp_cid:%d,pdp_cid = %d",ctx_ptr->pdp_cid,pdp_cid);

	if(ctx_ptr->pdp_cid == pdp_cid)
	{
		quectel_iot_process_close_event();
	}
	return 0;
}

void quec_iot_auto_register()
{
	cert_printf();
	quectel_iot_context *  iot_ctx;

	if(quec_iot_mgr.iot_ctx == NULL)
	{
		iot_ctx = quectel_iot_ctx_init(ds_iot_event_cb);

		if(iot_ctx == NULL)
		{
			cert_printf("iot_ctx :%d", iot_ctx );
		}
		quec_iot_mgr.iot_ctx = iot_ctx;
	}
	if(quec_iot_check_iccid_is_register() == TRUE)
	{
		quectel_iot_event_urc_report(APP_IOT_PS_REGI_ALREADY);

		OSATimerStatus  timer_status;
		if(quec_iot_mgr.ps_reg_timer)
		{
			OSATimerGetStatus(quec_iot_mgr.ps_reg_timer, &timer_status);
			if(timer_status.status == OS_TIMER_ACTIVE)
				OSATimerStop(quec_iot_mgr.ps_reg_timer);
			OSATimerDelete(quec_iot_mgr.ps_reg_timer);
			quec_iot_mgr.ps_reg_timer = NULL;
		}
		return ;
	}

	if(quec_iot_mgr.iot_ctx->sockfd >= 0)
	{
		quectel_iot_process_close_event();
	}
	
	if(quectel_iot_open(quec_iot_mgr.iot_ctx, quec_iot_mgr.pdp_cid, (char *)quec_iot_mgr.server_addr_str, 
	        quec_iot_mgr.server_port,GET_ATP_INDEX(quec_iot_mgr.atHandle)) == APP_IOT_OK)
	{
		quec_iot_mgr.decode_state = IOT_DECODE_BEGIN;
		quec_iot_mgr.call_close  = FALSE;
		quec_iot_mgr.current_cnt = quec_iot_mgr.retry;
		quec_iot_mgr.register_mode  = IOT_REGISTER_MODE_AUTO;
	}
}

void quec_iot_check_creg_timer(unsigned int ctx)
{
	cert_printf();
	quec_iot_msgsnd(QUEC_IOT_TIMER_CREG_CHECK_CB_HANDER, NULL);
	
	return ;
}

static int  quectel_iot_timer_creg_check_cb_hander
(
void *user_data_ptr
)
{
	cert_printf();
	if(quec_iot_check_net_status() == 1)
	{
		if(quec_iot_mgr.creg_timer)
		{
			OSATimerStatus  timer_status;

			OSATimerGetStatus(quec_iot_mgr.creg_timer, &timer_status);
			if(timer_status.status == OS_TIMER_ACTIVE)
				OSATimerStop(quec_iot_mgr.creg_timer);
			OSATimerDelete(quec_iot_mgr.creg_timer);
			quec_iot_mgr.creg_timer = NULL;
		}
		
		quectel_iot_get_data(&iot_data);
		quec_iot_auto_register();
		if(quec_iot_mgr.ps_reg_timer)
		{
			OSATimerStart(quec_iot_mgr.ps_reg_timer, quec_iot_mgr.rsp_timeout*QUEC_RTOS_TICKS_PER_SEC, 0, quec_iot_reg_retry_timer, 0);
		}
	}
	else
	{
		if(quec_iot_mgr.creg_retry > 0)
		{
			quec_iot_mgr.creg_retry--;
			
			if(quec_iot_mgr.creg_timer)
			{
				OSATimerStart(quec_iot_mgr.creg_timer, quec_iot_mgr.creg_rsp_timeout*QUEC_RTOS_TICKS_PER_SEC, 0, quec_iot_check_creg_timer, 0);
			}
		}
		else
		{
			cert_printf("Creg check timeout!!");
		}
	}
	
	return 0;
}

void quec_iot_reg_retry_timer(unsigned int ctx)
{
	cert_printf();
	quec_iot_msgsnd(QUEC_IOT_TIMER_REG_RETRY_CB_HANDER, NULL);
	
	return ;
}

static int  quectel_iot_timer_reg_retry_cb_hander
(
void *user_data_ptr
)
{
	if(quec_iot_mgr.current_cnt > 0 && quec_iot_mgr.uEnable)
	{
		quec_iot_mgr.current_cnt--;

		if(quec_iot_mgr.ps_reg_timer)
		{
			quec_iot_auto_register();
			OSATimerStatus  timer_status;
			OSATimerGetStatus(quec_iot_mgr.ps_reg_timer, &timer_status);
			if(timer_status.status == OS_TIMER_ACTIVE)
				OSATimerStop(quec_iot_mgr.ps_reg_timer);
			OSATimerStart(quec_iot_mgr.ps_reg_timer, quec_iot_mgr.rsp_timeout*QUEC_RTOS_TICKS_PER_SEC, 0, quec_iot_reg_retry_timer, 0);
		}
	}
	else
	{
		OSATimerStatus  timer_status;
		if(quec_iot_mgr.ps_reg_timer)
		{
			OSATimerGetStatus(quec_iot_mgr.ps_reg_timer, &timer_status);
			if(timer_status.status == OS_TIMER_ACTIVE)
				OSATimerStop(quec_iot_mgr.ps_reg_timer);
			OSATimerDelete(quec_iot_mgr.ps_reg_timer);
			quec_iot_mgr.ps_reg_timer = NULL;
		}
		
		cert_printf("Ps register timeout!!");
	}
	
	return 0;
}
#endif

#endif /*MIN_SYS*/
