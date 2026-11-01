/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/


#ifndef QUEC_APPTCPIP_MAIN_H
#define QUEC_APPTCPIP_MAIN_H

#ifdef QUEC_APPTCPIP_SUPPORT
int  quec_apptcpip_main(void);

int  quec_apptcpip_requst(int msg_id, void* msg_data_ptr);

int  quec_apptcpip_cnf(int msg_id, void *msg_data_ptr);

int  quec_apptcpip_ind(int msg_id, void *msg_data_ptr);

void quec_apptcpip_send_atcmd_to_modem(char *line, int line_len);

int quec_apptcpip_get_atcmd_result(void);

int quec_apptcpip_get_netif_info(int pdp_cid, quec_pdp_info *pdp_info);
#ifdef QUEC_TCPIP_TRANSPARENT_PRIORTIY_FLOW_FEATURE
UINT32  quec_apptcpip_get_msg_size(void);
#endif /*endof QUEC_TCPIP_TRANSPARENT_PRIORTIY_FLOW_FEATURE*/
#endif
#endif
