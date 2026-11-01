/*============================================================================
  Copyright (c) 2022 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
 =============================================================================*/

#ifndef _QUEC_BT_ADAPTIVE_H
#define _QUEC_BT_ADAPTIVE_H

#include "quec_common.h"
#include "quec_cust_feature.h"
#include "bt_api.h"
#include "bt_api_le.h"
#include "bt_api_a2dp.h"
#include "bt_uart_api.h"
#include "bt_device.h"
#include "bt_api_hfp.h"


#ifdef __cplusplus
extern "C" {
#endif

extern struct bt_user_cfg *quec_get_bt_cfg(void);

#define QUEC_GPIO_BT_POWER   77
#if defined (__QUECTEL_PROJECT_EC800MCN_GA__)
#define QUEC_GPIO_BT_RESET   25
#define QUEC_GPIO_BT_LDO_EN  26
#define QUEC_GPIO_BT_WAKEUP_HOST 22
#define QUEC_GPIO_HOST_WAKEUP_BT 21
#else
#define QUEC_GPIO_BT_RESET   126
#define QUEC_GPIO_BT_LDO_EN  37
#define QUEC_GPIO_BT_WAKEUP_HOST 117
#define QUEC_GPIO_HOST_WAKEUP_BT 118
#endif

struct le_uuid {
    unsigned char type;
};
struct gatt_attr {
    struct le_uuid *uuid;
    void *value;
    int size;
    unsigned short handle;
    unsigned char permission;
    int (*write_cb)(void *arg);
    int (*read_cb)(void *arg);
};

int quec_bt_open(bt_event_handle_t handler, struct bt_user_init_cfg *init_cfg, struct bt_user_cfg *cfg_confg);
int quec_bt_inquiry(unsigned char inquiry_length, unsigned char num_responses);
int quec_bt_inquiry_cancel(void);
int quec_bt_set_visiable(int visiable);
int quec_bt_close(void);
void quec_get_bt_open_studio(quec_cb_bt_open_status cb);
void quec_bt_get_bt_address(struct bt_addr* addr);
void quec_get_scan_bt_status(quec_cb_bt_scan_status cb);
void quec_get_bt_connect_status(quec_cb_bt_connect_status cb);
int quec_bt_connect_headset(struct bt_addr addr, int call_status);
int quec_bt_le_set_gap_name(char *gap_name, int name_len);
int quec_bt_le_create_adv_data(int gap, unsigned char *buffer, int buffer_size,unsigned char *data, int size);
int quec_bt_le_set_adv_parameters(struct bt_task_le_adv_parameters *para);
int quec_bt_le_set_adv_data(unsigned char *data, unsigned char length);
int quec_le_set_scan_response_data(unsigned char *data, unsigned char length);
int quec_bt_le_set_adv_enable(int enable);
int quec_bt_le_register_service(struct gatt_attr *service, int count);
int quec_le_update_attribute(struct gatt_attr *attribute);
void quec_le_send_service_change(unsigned short conn_handle);

int quec_le_set_random_address(struct bt_addr addr);
void quec_set_bt_gpio(int pin_index,struct bt_user_cfg * quec_bt_cfg);

int quec_bt_le_disconnect(unsigned short con_handle);
int quec_bt_acl_connect(struct bt_addr addr);
int quec_bt_cancel_acl_connect(struct bt_addr addr);
int quec_bt_acl_disconnect(unsigned short int handle);
int quec_bt_bonding(struct bt_addr addr);
int quec_bt_unbond(struct bt_addr addr);
int quec_bt_pin_negative_reply(struct bt_addr addr);
int quec_bt_spp_connect(struct bt_addr addr);
int quec_bt_obex_send_response(int tid, unsigned char response_code);
int quec_bt_obex_send_file(struct bt_task_obex_file_send *file);
int quec_bt_obex_connect(struct bt_addr addr);
int quec_bt_avrcp_disconnect(void);
int quec_bt_avrcp_connect(struct bt_addr addr);
int quec_bt_switch_voice_to_headset(void);
int quec_bt_switch_voice_to_phone(void);
int quec_bt_sco_disconnect(unsigned short int handle);
int quec_bt_hfp_send_AT_rawdata(const char *data, int length);
int quec_bt_hfp_set_speaker_gain(int gain);
int quec_bt_hfp_voice_recogonition(int enable);
int quec_bt_hfp_callhold(int reject);
int quec_bt_hfp_update_callhold(int status);
int quec_bt_hfp_update_phone_number(const char *num, int type);
int quec_bt_hfp_update_callstatus(enum ciev_index index, int value, int delay);

int quec_bt_hfp_reject_connection(struct bt_addr addr);
int quec_bt_hfp_disconnect(void);
int quec_bt_a2dp_SBC_test_send_message(unsigned int msg_id);
int quec_bt_hfp_connect(struct bt_addr addr, int call_status);
int quec_bt_a2dp_disconnect(void);
int quec_bt_a2dp_send_sbc_data(unsigned int length, unsigned char* data,
                                    unsigned int timestamp, unsigned short int seq_num,
                                    unsigned char payload_type,
                                    unsigned char frames);
int quec_bt_bt_dut(void);
int quec_bt_change_local_name(const char *name);
int quec_bt_disconnect_headset(struct bt_addr *addr);
int quec_bt_get_open_status(void);
int quec_bt_a2dp_connect(struct bt_addr addr);
int quec_bt_hfp_set_microphone_gain(int gain);
int quec_bt_hfp_accept_connection(int call_status, struct bt_addr addr);
void quec_bt_update_device_record(void);
int quec_get_device_records(struct bt_device_record **record);


int quec_le_get_pair_info(int index);
int quec_le_remove_pair_info(int index);
int quec_le_custom_connection_parameter_update_request(unsigned short conn_handle, unsigned short conn_interval, unsigned short slave_latency, unsigned short supervision_timeout);
void quec_le_set_adv_mode(uint8_t le_adv_mode);
	




#ifdef __cplusplus
} /*"C" */
#endif

#endif




