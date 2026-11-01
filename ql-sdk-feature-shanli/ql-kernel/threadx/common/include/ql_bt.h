/*============================================================================
  Copyright (c) 2022 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
 =============================================================================*/


#ifndef _QL_BT_H
#define _QL_BT_H

#include "quec_bt_adaptive.h"

#ifdef __cplusplus
extern "C" {
#endif

int ql_bt_open(bt_event_handle_t handler, struct bt_user_init_cfg *init_cfg, struct bt_user_cfg *cfg_confg);
int ql_bt_close(void);
void ql_bt_get_bt_address(struct bt_addr* addr);
void ql_bt_set_bt_address(struct bt_addr* addr);
int ql_bt_inquiry(unsigned char inquiry_length, unsigned char num_responses);
int ql_bt_inquiry_cancel(void);
int ql_bt_connect_headset(struct bt_addr addr, int call_status);
int ql_bt_set_visiable(int visiable);
int ql_bt_send_bttask_command(struct bt_task_command * command);
int ql_bt_accept_bonding(struct bt_addr addr, int accept_reject);
void ql_bt_sort_device_record(struct bt_addr addr);
void ql_bt_a2dp_connected_handler(unsigned char *addr);
int ql_bt_hfp_accept_connection(int call_status, struct bt_addr addr);
void ql_bt_mgr_handler(struct bt_task_event * msg);
void ql_bt_a2dp_disconnected_handler(void);
void ql_bt_add_device_record(struct bt_device_record *device);
int ql_bt_sco_connect(struct bt_addr addr);

int ql_bt_obex_disconnect(int tid);
int ql_bt_spp_disconnect(unsigned short spp_port);
void ql_bt_a2dp_start_handler(void);
void ql_bt_close_set(void);
void ql_bt_a2dp_remote_sbc_capabilities_handler(unsigned int a2dp_capabilites);
int ql_bt_pin_reply(struct bt_addr addr, char *pin);
int ql_bt_a2dp_send_start(struct appbt_a2dp *a2dp);
int ql_bt_spp_send_data(unsigned char* data, unsigned short length, unsigned short spp_port);
int ql_bt_a2dp_send_suspend(void);
int ql_bt_a2dp_send_pcm_data(unsigned char *data, int length);
void ql_bt_free(void *p);
int ql_bt_acl_connect(struct bt_addr addr);
int ql_bt_cancel_acl_connect(struct bt_addr addr);
int ql_bt_acl_disconnect(unsigned short int handle);
int ql_bt_bonding(struct bt_addr addr);
int ql_bt_unbond(struct bt_addr addr);
int ql_bt_pin_negative_reply(struct bt_addr addr);
int ql_bt_spp_connect(struct bt_addr addr);
int ql_bt_obex_send_response(int tid, unsigned char response_code);
int ql_bt_obex_send_file(struct bt_task_obex_file_send *file);
int ql_bt_obex_connect(struct bt_addr addr);
int ql_bt_avrcp_disconnect(void);
int ql_bt_avrcp_connect(struct bt_addr addr);
int ql_bt_switch_voice_to_headset(void);
int ql_bt_switch_voice_to_phone(void);
int ql_bt_sco_disconnect(unsigned short int handle);
int ql_bt_hfp_send_AT_rawdata(const char *data, int length);
int ql_bt_hfp_set_speaker_gain(int gain);
int ql_bt_hfp_voice_recogonition(int enable);
int ql_bt_hfp_callhold(int reject);
int ql_bt_hfp_update_callhold(int status);
int ql_bt_hfp_update_phone_number(const char *num, int type);
int ql_bt_hfp_update_callstatus(enum ciev_index index, int value, int delay);
int ql_bt_hfp_reject_connection(struct bt_addr addr);
int ql_bt_hfp_disconnect(void);
int ql_bt_a2dp_SBC_test_send_message(unsigned int msg_id);
int ql_bt_hfp_connect(struct bt_addr addr, int call_status);
int ql_bt_a2dp_disconnect(void);
int ql_bt_a2dp_send_sbc_data(unsigned int length, unsigned char* data,
                                    unsigned int timestamp, unsigned short int seq_num,
                                    unsigned char payload_type,
                                    unsigned char frames);
int ql_bt_bt_dut(void);
int ql_bt_change_local_name(const char *name);
int ql_bt_disconnect_headset(struct bt_addr *addr);
int ql_bt_get_open_status(void);
int ql_bt_a2dp_connect(struct bt_addr addr);
int ql_bt_hfp_set_microphone_gain(int gain);
int quec_bt_hfp_accept_connection(int call_status, struct bt_addr addr);

void ql_bt_update_device_record(void);
int ql_bt_get_device_records(struct bt_device_record **info);

int ql_bt_le_register_att_service(unsigned char *profile_data, unsigned short profile_data_len, att_read_callback_t read_callback, att_write_callback_t write_callback);



int ql_bt_le_set_gap_name(char *gap_name, int name_len);
int ql_bt_le_create_adv_data(int gap, unsigned char *buffer, int buffer_size,unsigned char *data, int size);
int ql_bt_le_set_adv_data(unsigned char *data, unsigned char length);
int ql_le_set_scan_response_data(unsigned char *data, unsigned char length);
int ql_bt_le_set_adv_parameters(struct bt_task_le_adv_parameters *para);
int ql_bt_le_set_adv_enable(int enable);
int ql_bt_le_register_service(struct gatt_attr *service, int count);
int ql_bt_le_unregister_service(void);
void ql_get_bt_open_status(quec_cb_bt_open_status cb);
void ql_get_scan_bt_status(quec_cb_bt_scan_status cb);
void ql_get_bt_connect_status(quec_cb_bt_connect_status cb);
int ql_bt_le_set_random_address(struct bt_addr addr);
int ql_bt_le_set_ext_adv_parameters(struct bt_task_le_ext_adv_parameters *para);
int ql_bt_le_set_adv_set_random_address(unsigned char handle, struct bt_addr addr);
int ql_bt_le_set_ext_adv_data(unsigned char *data, unsigned char length, unsigned char handle, unsigned char operation, unsigned char fragment);
int ql_bt_le_set_ext_scan_response(unsigned char *data, unsigned char length, unsigned char handle, unsigned char operation, unsigned char fragment);
int ql_bt_le_set_ext_adv_enable(unsigned char enable, unsigned char number, unsigned char handle[], unsigned short duration[], unsigned char max_event[]);
int ql_appbt_le_notify(unsigned short conn_handle,unsigned short att_handle, unsigned char *data, int size);
int ql_read_rssi(unsigned short handle);
int ql_bt_le_set_pair_enable(unsigned char set_enable);
int ql_bt_le_disconnect(unsigned short con_handle);
int ql_bt_le_read_by_group_type_request(unsigned short start, unsigned short end, unsigned short uuid);
int ql_bt_le_get_device_records(ble_device_info_record **bleInfo);
int ql_le_find_information_request    (unsigned short start, unsigned short end);
int ql_bt_le_connect(struct bt_addr addr, int type);
int ql_le_custom_gatt_scan_start(unsigned short conn_handle);
int ql_le_custom_write_command(unsigned short conn_handle, unsigned short att_handle, unsigned char *data, unsigned short size);
int ql_le_custom_write_request(unsigned short conn_handle, unsigned short att_handle, unsigned char *data, unsigned short size);
int ql_le_custom_read_request(unsigned short conn_handle, unsigned short att_handle);
int ql_le_custom_mtu_request(unsigned short conn_handle, unsigned short mtu);
int ql_le_disconnect_with_handle(uint16_t con_handle);

void ql_ble_update_device_record(void);
int ql_bt_le_read_by_type_request(unsigned short start, unsigned short end, unsigned short uuid);
int ql_bt_le_mtu_request(unsigned short acl_handle);
int ql_bt_le_scan(unsigned char type, unsigned short int interval, unsigned short int window, unsigned char own_address_type, le_scan_event_handle_t handle);
int ql_bt_le_scan_stop(void);
int ql_le_get_pair_info(int index);
int ql_le_remove_pair_info(int index);
void ql_le_send_service_change(unsigned short conn_handle);

void ql_le_set_adv_mode(uint8_t le_adv_mode);
int ql_le_custom_connection_parameter_update_request(unsigned short conn_handle, unsigned short conn_interval, unsigned short slave_latency, unsigned short supervision_timeout);
void ql_bt_hfp_atchld(struct bt_task_event * msg);






#ifdef __cplusplus
} /*"C" */
#endif

#endif

