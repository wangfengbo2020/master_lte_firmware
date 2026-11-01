/*================================================================
  Copyright (c) 2022, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
#include "quec_cust_feature.h"
#ifdef QUEC_BT_SUPPORT
#include <stdio.h>
#include <stdlib.h>
#include "ql_bt.h"





int ql_bt_le_set_pair_enable(unsigned char set_enable)
{
	return quec_bt_le_set_pair_enable(set_enable);
}

void ql_le_send_service_change(unsigned short conn_handle)
{
 quec_le_send_service_change(conn_handle);
}

int ql_le_update_attribute(struct gatt_attr *attribute)
{
//	return appbt_le_update_attribute(attribute);
	return 0;
}

int ql_bt_le_register_service(struct gatt_attr *service, int count)
{
	return quec_bt_le_register_service(service, count);
}

int ql_bt_le_register_att_service(unsigned char *profile_data, unsigned short profile_data_len, att_read_callback_t read_callback, att_write_callback_t write_callback)
{
	return quec_bt_le_register_att_server(profile_data,profile_data_len,read_callback,write_callback);
}

int ql_bt_le_unregister_service(void)
{
	return quec_bt_le_unregister_service();
}

int ql_appbt_le_notify(unsigned short conn_handle,unsigned short att_handle, unsigned char *data, int size)
{
	return quec_appbt_le_notify(conn_handle,att_handle,data,size);
}

int ql_bt_le_set_adv_enable(int enable)
{
	return quec_bt_le_set_adv_enable(enable);
}

int ql_le_set_scan_response_data(unsigned char *data, unsigned char length)
{
	return quec_le_set_scan_response_data(data, length);
}


int ql_bt_le_set_adv_parameters(struct bt_task_le_adv_parameters *para)
{
	return quec_bt_le_set_adv_parameters(para);
}


int ql_bt_le_set_adv_data(unsigned char *data, unsigned char length)
{
	return quec_bt_le_set_adv_data(data, length);
}

int ql_bt_le_create_adv_data(int gap, 
                                       unsigned char *buffer, int buffer_size,
                                       unsigned char *data, int size)
{
	return quec_bt_le_create_adv_data(gap, buffer, buffer_size, data, size);
}

int ql_bt_le_set_ext_adv_parameters(struct bt_task_le_ext_adv_parameters *para)
{
	return quec_bt_le_set_ext_adv_parameters(para);
}

int ql_bt_le_set_adv_set_random_address(unsigned char handle, struct bt_addr addr)
{
	return quec_bt_le_set_adv_set_random_address(handle,addr);
}

int ql_bt_le_set_ext_adv_data(unsigned char *data, unsigned char length,unsigned char handle, unsigned char operation, unsigned char fragment)
{
	return quec_bt_le_set_ext_adv_data(data,length,handle,operation,fragment);
}

int ql_bt_le_set_ext_scan_response(unsigned char *data, unsigned char length,unsigned char handle, unsigned char operation, unsigned char fragment)
{
	return quec_bt_le_set_ext_scan_response(data,length,handle,operation,fragment);
}

int ql_bt_le_set_ext_adv_enable(unsigned char enable, unsigned char number,unsigned char handle[], unsigned short duration[], unsigned char max_event[])
{
	return quec_bt_le_set_ext_adv_enable(enable,number,handle,duration,max_event);
}

int ql_bt_le_set_gap_name(char *gap_name, int name_len)
{
	return quec_bt_le_set_gap_name(gap_name, name_len);
}

int ql_bt_le_set_random_address(struct bt_addr addr)
{
	return quec_le_set_random_address(addr);
}


int ql_bt_le_disconnect(unsigned short con_handle )
{
	return quec_bt_le_disconnect(con_handle);
}

int ql_bt_le_read_by_group_type_request(unsigned short start, unsigned short end, unsigned short uuid)
{
	return quec_bt_le_read_by_group_type_request(start, end, uuid);
}

int ql_bt_le_get_device_records(ble_device_info_record **bleInfo)
{
	return quec_get_ble_device_records(bleInfo);
}

int ql_le_find_information_request    (unsigned short start, unsigned short end)
{
	return quec_le_find_information_request(start,end);
}

int ql_bt_le_connect(struct bt_addr addr, int type)
{
	return quec_bt_le_connect(addr, type);
}

int ql_le_custom_gatt_scan_start(unsigned short conn_handle)
{
	return quec_le_custom_gatt_scan_start(conn_handle);
}

int ql_le_custom_write_command(unsigned short conn_handle, unsigned short att_handle, unsigned char *data, unsigned short size)
{
	return quec_le_custom_write_command(conn_handle,att_handle,data,size);
}

int ql_le_custom_write_request(unsigned short conn_handle, unsigned short att_handle, unsigned char *data, unsigned short size)
{
	return quec_le_custom_write_request(conn_handle,att_handle,data,size);
}

int ql_le_custom_read_request(unsigned short conn_handle, unsigned short att_handle)
{
	return quec_le_custom_read_request(conn_handle,att_handle);
}

int ql_le_custom_mtu_request(unsigned short conn_handle, unsigned short mtu)
{
	return quec_le_custom_mtu_request(conn_handle,mtu);
}

int ql_le_disconnect_with_handle(uint16_t con_handle)
{
	return quec_le_disconnect_with_handle();
}


void ql_ble_update_device_record(void)
{
	quec_ble_update_device_record();
}

int ql_bt_le_read_by_type_request(unsigned short start, unsigned short end, unsigned short uuid)
{
	return quec_bt_le_read_by_type_request(start, end, uuid);
}

int ql_bt_le_mtu_request(unsigned short acl_handle)
{
	return quec_bt_le_mtu_request(acl_handle);
}

int ql_bt_le_scan(unsigned char type, 
                        unsigned short int interval,
                        unsigned short int window,
                        unsigned char own_address_type,
                        le_scan_event_handle_t handle)
{
	return quec_bt_le_scan(type, interval, window, own_address_type, handle);
}

int ql_bt_le_scan_stop(void)
{
	return quec_bt_le_scan_stop();
}

int ql_le_get_pair_info(int index)
{
	return quec_le_get_pair_info(index);
}

int ql_le_remove_pair_info(int index)
{
	return quec_le_remove_pair_info(index);
}

void ql_le_set_adv_mode(uint8_t le_adv_mode)
{
	 quec_le_set_adv_mode(le_adv_mode);
}

int ql_le_custom_connection_parameter_update_request(unsigned short conn_handle, unsigned short conn_interval, unsigned short slave_latency, unsigned short supervision_timeout)
{
	return quec_le_custom_connection_parameter_update_request(conn_handle,conn_interval,slave_latency,supervision_timeout);
}


/****************************************BT*********************************************/
int ql_bt_connect_headset(struct bt_addr addr, int call_status)
{
	return quec_bt_connect_headset(addr, call_status);
}

void ql_get_bt_connect_status(quec_cb_bt_connect_status cb)
{
	quec_get_bt_connect_status(cb);
}

void ql_get_scan_bt_status(quec_cb_bt_scan_status cb)
{
	quec_get_scan_bt_status(cb);
}

void ql_bt_get_bt_address(struct bt_addr* addr)
{
	quec_bt_get_bt_address(addr);
}

void ql_bt_set_bt_address(struct bt_addr* addr)
{
	quec_bt_set_bt_address(addr);
}

int ql_bt_set_visiable(int visiable)
{
	return quec_bt_set_visiable(visiable);
}

int ql_bt_inquiry_cancel(void)
{
	return quec_bt_inquiry_cancel();
}

int ql_read_rssi(unsigned short handle)
{
	return quec_read_rssi(handle);
}

int ql_bt_inquiry(unsigned char inquiry_length, unsigned char num_responses)
{
	return quec_bt_inquiry(inquiry_length, num_responses);
}

void ql_get_bt_open_status(quec_cb_bt_open_status cb)
{
	quec_get_bt_open_studio(cb);
}

int ql_bt_close(void)
{
	return quec_bt_close();
}
int ql_bt_open(bt_event_handle_t handler, struct bt_user_init_cfg *init_cfg, struct bt_user_cfg *cfg_confg)
{
	return quec_bt_open(handler, init_cfg, cfg_confg);
}

int ql_bt_send_bttask_command(struct bt_task_command * command)
{
	return quec_bt_send_bttask_command(command);
}

int ql_bt_accept_bonding(struct bt_addr addr, int accept_reject)
{
	return quec_bt_accept_bonding(addr, accept_reject);
}

int ql_bt_bonding(struct bt_addr addr)
{
	return quec_bt_bonding(addr);
}

void ql_bt_sort_device_record(struct bt_addr addr)
{
	quec_get_bt_sort_device_record(addr);
}

void ql_bt_a2dp_connected_handler(unsigned char *addr)
{
	quec_bt_a2dp_connected_handler(addr);
}

int ql_bt_hfp_accept_connection(int call_status, struct bt_addr addr)
{
	return quec_bt_hfp_accept_connection(call_status, addr);
}

void ql_bt_mgr_handler(struct bt_task_event * msg)
{
	quec_bt_mgr_handler(msg);
}

void ql_bt_a2dp_disconnected_handler(void)
{
	quec_bt_a2dp_disconnected_handler();
}

void ql_bt_add_device_record(struct bt_device_record *device)
{
	quec_add_device_record(device);
}

int ql_bt_sco_connect(struct bt_addr addr)
{
	return quec_bt_sco_connect(addr);
}

int ql_bt_obex_disconnect(int tid)
{
	return quec_bt_obex_disconnect(tid);
}

int ql_bt_spp_disconnect(unsigned short spp_port)
{
	return quec_bt_spp_disconnect(spp_port);
}
int ql_bt_unbond(struct bt_addr addr)
{
	return quec_bt_unbond(addr);
}
int ql_bt_pin_negative_reply(struct bt_addr addr)
{
	return quec_bt_pin_negative_reply(addr);
}

int ql_bt_pin_reply(struct bt_addr addr, char *pin)
{
	return quec_bt_pin_reply(addr, pin);
}

void ql_bt_a2dp_start_handler(void)
{
	quec_bt_a2dp_start_handler();
}

void ql_bt_close_set(void)
{
	bt_close_set();
}

void ql_bt_a2dp_remote_sbc_capabilities_handler(unsigned int a2dp_capabilites)
{
	quec_bt_a2dp_remote_sbc_capabilities_handler(a2dp_capabilites);
}

int ql_bt_a2dp_send_start(struct appbt_a2dp *a2dp)
{
	return quec_bt_a2dp_send_start(a2dp);
}

int ql_bt_acl_connect(struct bt_addr addr)
{
	return quec_bt_acl_connect(addr);

}
int ql_bt_cancel_acl_connect(struct bt_addr addr)
{
	return quec_bt_cancel_acl_connect(addr);

}
int ql_bt_acl_disconnect(unsigned short int handle)
{
	return quec_bt_acl_disconnect(handle);
}
int ql_bt_bt_dut(void)
{
	return quec_bt_bt_dut();
}
int ql_bt_change_local_name(const char *name)
{
	return quec_bt_change_local_name(name);
}
int ql_bt_disconnect_headset(struct bt_addr *addr)
{
	return quec_bt_disconnect_headset(addr);
}
int ql_bt_get_open_status(void)
{
	return quec_bt_get_open_status();
}
int ql_bt_a2dp_connect(struct bt_addr addr)
{
	return quec_bt_a2dp_connect(addr);
}
int ql_bt_a2dp_disconnect(void)
{
	return quec_bt_a2dp_disconnect();
}

int ql_bt_a2dp_send_sbc_data(unsigned int length, unsigned char* data,
                                    unsigned int timestamp, unsigned short int seq_num,
                                    unsigned char payload_type,
                                    unsigned char frames)
{
	return quec_bt_a2dp_send_sbc_data(length, data, timestamp, seq_num, payload_type, frames);
}
int ql_bt_a2dp_SBC_test_send_message(unsigned int msg_id)
{
	return quec_bt_a2dp_SBC_test_send_message(msg_id);
}

int ql_bt_hfp_connect(struct bt_addr addr, int call_status)
{
	return quec_bt_hfp_connect(addr, call_status);
}
int ql_bt_hfp_disconnect(void)
{
	return quec_bt_hfp_disconnect();
}
int ql_bt_hfp_reject_connection(struct bt_addr addr)
{
	return quec_bt_hfp_reject_connection(addr);
}
int ql_bt_hfp_update_callstatus(enum ciev_index index, int value, int delay)
{
	return quec_bt_hfp_update_callstatus(index, value, delay);
}
int ql_bt_hfp_update_phone_number(const char *num, int type)
{
	return quec_bt_hfp_update_phone_number(num, type);
}
int ql_bt_hfp_update_callhold(int status)
{
	return quec_bt_hfp_update_callhold(status);
}
int ql_bt_hfp_callhold(int reject)
{
	return quec_bt_hfp_callhold(reject);
}
int ql_bt_hfp_voice_recogonition(int enable)
{
	return quec_bt_hfp_voice_recogonition(enable);
}
int ql_bt_hfp_set_speaker_gain(int gain)
{
	return quec_bt_hfp_set_speaker_gain(gain);
}
int ql_bt_hfp_send_AT_rawdata(const char *data, int length)
{
	return quec_bt_hfp_send_AT_rawdata(data, length);
}
void ql_bt_hfp_atchld(struct bt_task_event * msg)
{
	 quec_bt_hfp_atchld(msg);
}

int ql_bt_sco_disconnect(unsigned short int handle)
{
	return quec_bt_sco_disconnect(handle);
}
int ql_bt_switch_voice_to_phone(void)
{
	return quec_bt_switch_voice_to_phone();
}
int ql_bt_switch_voice_to_headset(void)
{
	return quec_bt_switch_voice_to_headset();
}
int ql_bt_avrcp_connect(struct bt_addr addr)
{
	return quec_bt_avrcp_connect(addr);
}


int ql_bt_avrcp_disconnect(void)
{
	return quec_bt_avrcp_disconnect();
}
int ql_bt_obex_connect(struct bt_addr addr)
{
	return quec_bt_obex_connect(addr);
}
int ql_bt_obex_send_file(struct bt_task_obex_file_send *file)
{
	return quec_bt_obex_send_file(file);
}
int ql_bt_obex_send_response(int tid, unsigned char response_code)
{
	return quec_bt_obex_send_response(tid, response_code);
}

int ql_bt_spp_connect(struct bt_addr addr)
{
	return quec_bt_spp_connect(addr);
}

int ql_bt_spp_send_data(unsigned char* data, unsigned short length, unsigned short spp_port)
{
	return quec_bt_spp_send_data(data, length, spp_port);
}

int ql_bt_a2dp_send_suspend(void)
{
	return quec_bt_a2dp_send_suspend();
}
int ql_bt_hfp_set_microphone_gain(int gain)
{
	return quec_bt_hfp_set_microphone_gain(gain);
}

int ql_bt_a2dp_send_pcm_data(unsigned char *data, int length)
{
	return quec_bt_a2dp_send_pcm_data(data, length);
}

int ql_bt_get_device_records(struct bt_device_record **info)
{

	int ret =  quec_get_device_records(info);
	
	return ret;	
}
void ql_bt_update_device_record(void)
{
	quec_bt_update_device_record();
}

void ql_bt_free(void *p)
{
	free(p);
}

#endif
