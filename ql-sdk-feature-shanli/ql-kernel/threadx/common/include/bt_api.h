#ifndef BT_API_H
#define BT_API_H

// The user should not modify this file, especially the stucture definition
// Beacuse these sturctue are already used in btstack.lib present by binary
#include "bt_api_types.h"

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

/* function declare */

// API: config BT chip default baudrate
// should be execute before appbt_open
int appbt_config_btchip(unsigned int id);

// API: config UART baudrate
// should be execute before appbt_open
int appbt_config_bt_uart(unsigned int baudrate);
// API: config BT mode
// BT_MODE_BR or BT_MODE_LE or BT_MODE_BR_LE
// should be execute before appbt_open
int appbt_config_bt_mode(int mode);
//API config bt profile
int appbt_config_bt_prf(unsigned int prf);
// API: config BT firmware store where
// should be execute before appbt_open
// bt_firmware: build_ram_only.bin also name as btbin.bin
// bt_nvm_lst: bt_update.lst also name as btlst.bin
int appbt_config_firmware(int firmware_where,
                                   unsigned char *bt_firmware, int bt_firmware_size,
                                   unsigned char *bt_nvm_lst, int bt_nvm_lst_size);
// API: config BT HCI mode
// should be execute before appbt_open
// mode: BT_HCI_MODE_H4 or BT_HCI_MODE_H5
int appbt_config_hci_mode(int mode);
// API: quiry which HCI mode is used
int appbt_config_get_hci_mode(void);
// API: BT power on request
// Parameters: if user want handle BT event by self, set this callback
//             if user want use default BT event handle, set this NULL
int appbt_open(bt_event_handle_t handle, struct bt_user_init_cfg *init);
// API: BT power off request
int appbt_close(void);
// API: setup ACL connection request to target device
int appbt_acl_connect(struct bt_addr addr);
int appbt_cancel_acl_connect(struct bt_addr addr);
// API: disconnect a ACL connection
int appbt_acl_disconnect(unsigned short int handle);
// API: HCI Reset request
int appbt_test_hci_reset(void);
// API: Read RSSI request
int appbt_test_read_rssi(unsigned short int handle);
// API: Set Coexist mode
int appbt_set_coexist_mode(unsigned short int coexist);
// API: make a pair to target device
// this API bonding device only, after bonding complete, will disconnect ACL automaticly
int appbt_bonding(struct bt_addr addr);
// API: accept bonding request
int appbt_accept_bonding(struct bt_addr addr, int accept_reject);
// API: unbond device. this API should be executed at disconnect status
// user can also disconnect and unbond device through appbt_disconnect_phone/appbt_disconnect_headset
// if user unbond device through appbt_disconnect_headset/appbt_disconnect_phone should fill in the address parameters
int appbt_unbond(struct bt_addr addr);
// API: reply PIN code to target device
int appbt_pin_reply(struct bt_addr addr, char *pin);
// API: negative reply PIN to target device
int appbt_pin_negative_reply(struct bt_addr addr);
// API: user passkey request reply to target device
int appbt_user_passkey_request_reply(struct bt_addr addr, unsigned int numeric_value);
// API: user passkey request negative reply to target device
int appbt_user_passkey_request_negative_reply(struct bt_addr addr);
// API: keypress notification to target device
int appbt_send_keypress_notification(struct bt_addr addr, unsigned char notification_type);

// API: search other device
//      search result will report through BTTASK_IND_INQUIRY_RESULT
// inquiry_length: range: 0x01~0x30
//                 time = N * 1.28s
// num_responses: 0x00 unlimited number of responses
//                0x01~0xff
int appbt_inquiry(unsigned char inquiry_length, unsigned char num_responses);
// API: cancel inquiry
int appbt_inquiry_cancel(void);
// API: set bluetooth visiable and connectable
// Parameters: 0 - not visiable
//             1 - visiable
int appbt_set_visiable(int visiable);
// API: set bluetooth visiable and connectable
// Parameters: 0 - not visiable and connectable
//             1 - visiable and connectable
int appbt_set_visisable_connectable(int visable_connectable);
// API: set bluetooth page scan type
// Parameters: 0 - standard scan
//             1 - interlaced scan
int appbt_set_page_scan_type(unsigned char page_scan_type);
// API: change bluetooth local name
int appbt_change_local_name(const char *name);

// API: stack report BT event through this API
//      user should implement this API(bt_event_handle_t), or use default
// Parameters: BT event. Memory allocated through bt_malloc(), this function should free memory if not use default code
int send_bt_event(struct bt_task_event *event);
// API: set some message to stack. generally used internally
int set_bttask_flag(unsigned int flag);

// system will call this API, if system enter sleep. user can ignore this
void appbt_bt_enter_sleep(void);
// system will call this API, if system exit sleep. user can ignore this
void appbt_bt_exit_sleep(void);

// API: test mode
int appbt_bt_dut(void);
// API: le clear device record
void appbt_le_clear_device_record(void);
// API: LE recv test mode
int appbt_test_le_enhanced_receiver
    (unsigned char channel, unsigned char PHY, unsigned char modulation_index);
// API: LE send test mode
int appbt_test_le_enhanced_transmiter
    (unsigned char channel, unsigned char length_of_test_data,
     unsigned char packet_payload, unsigned char PHY);
// API: LE test mode end
int appbt_test_le_end(void);
// API: BR test mode -- send tone
// start_stop: 0 - stop send; 1 - start send
// channel: BT channel. valid value 0-78
//          0: 2402 MHz
//          1: 2402 + 1 MHz
//          n: 2402 + n MHz
// power: RF power. valid value 0-4. each grade difference is 4db
// type: tone type. valid value 0-6
//       0: 100KHz
//       1: 250KHz
//       2: 500KHz
//       3: 800KHz
//       4: 1000KHz
//       5: 1300KHz
//       6: 2000KHz
int appbt_bt_test_txtone(unsigned char start_stop,
    unsigned char channel, unsigned char power, unsigned char type);
// API: BR test mode -- send packet
// start_stop: 0 - stop send; 1 - start send
// channel: BT channel. valid value 0-78
//          0: 2402 MHz
//          1: 2402 + 1 MHz
//          n: 2402 + n MHz
// modulation: 1 - BR@1M; 2 - EDR@2M; 3 - EDR@3M
// dh_type: 1 - xDH1; 3 - xDH3; 5 - xDH5
// data_pattern: 1: 0 pattern
//               2: 1 pattern
//               3: 1010 pattern
//               4: pseudorandom bit sequence(PRBS9)
//               5: 11110000 pattern
//               6: 00001111 pattern
int appbt_bt_test_txpacket(unsigned char start_stop,
    unsigned char channel, unsigned char power, unsigned char modulation,
    unsigned char dh_type, unsigned char data_pattern, struct bt_addr addr);
// API: BR test mode -- recv packet
// start_stop: 0 - stop send; 1 - start send
// channel: BT channel. valid value 0-78
//          0: 2402 MHz
//          1: 2402 + 1 MHz
//          n: 2402 + n MHz
// packet_type: 0 - BR; 1/2/3 - Mbs
// data_pattern: 1: 0 pattern
//               2: 1 pattern
//               3: 1010 pattern
//               4: pseudorandom bit sequence(PRBS9)
//               5: 11110000 pattern
//               6: 00001111 pattern
int appbt_bt_test_rxpacket(unsigned char start_stop,
    unsigned char channel, unsigned char packet_type, unsigned char data_pattern,
    struct bt_addr addr);
// enter DTM mode
int appbt_le_dtm(int baudrate);
// query DTM mode
int appbt_le_is_dtm_mode(void);

// send a raw vendor HCI to controller
int appbt_vendor_rawhci(struct bt_task_vendor_cmd *cmd);

// enable ipc log of btdm output to acat
int appbt_ipc_log_config(unsigned int enable);

int appbt_hci_cmd_send(unsigned char *pdu);

int appbt_temperature(int temperature);

void appbt_enable_hcidump(char enable);

// eat this message, skip upper layer process
void appbt_eat_message(struct bt_task_event * msg);

// API: user can inquiry bluetooth status through this API
struct bt_device_record *bt_find_device_record(struct bt_addr addr);
int appbt_get_open_status(void);
void bt_set_firmware_location(int location);
int appbt_set_check_controller_alive(unsigned char set_enable);
int appbt_set_sniff_mode(unsigned char enable);
unsigned long appbt_get_uart_id(void);
struct bt_task_command *alloc_bttask_command(int command_id, int payload_length);
struct bt_task_event * alloc_bt_event(unsigned short int event_type,
                                                  unsigned short int event_id,
                                                  int size);
unsigned char appbt_transport_is_ipc(void);
void bt_uart_dma_irq_preprocess(unsigned int DINT);
unsigned char GetBTPmLock(void);
void SetBTPmLock(unsigned char lock);
void ClearBTPmLock(unsigned char lock);
unsigned char appbt_chip_is_5803(void);
void bt_base_timer(unsigned int id);
int asr_bt_prepare_init(void* setting);
unsigned char GetWifiConfigFlag(void);
void appbt_set_atresp_enable(unsigned char enable);
void appbt_atresp(unsigned char resultCode, char *respString, unsigned char force);

//bt api handle
void bt_usr_handle_a2dp(struct bt_task_event * msg);
void bt_usr_handle_avrcp(struct bt_task_event * msg);
void bt_usr_handle_hfp(struct bt_task_event * msg);
void bt_usr_handle_sco(struct bt_task_event * msg);
void bt_usr_handle_obex(struct bt_task_event * msg);
void bt_usr_handle_le(struct bt_task_event * msg);
void bt_mgr_handler(struct bt_task_event * msg);
void bt_usr_handle_a2dp_sink(struct bt_task_event * msg);
void bt_usr_handle_pbap(struct bt_task_event * msg);
void bt_usr_handle_hfp_hf(struct bt_task_event * msg);
void bt_usr_handle_hid(struct bt_task_event * msg);
void bt_usr_handle_map(struct bt_task_event * msg);
void bt_usr_handle_ftp(struct bt_task_event * msg);


typedef void (*quec_cb_bt_open_status)(int result);
typedef void (*quec_cb_bt_scan_status)(struct bt_event_inquiry *inquiry,int result);
typedef void (*quec_cb_bt_connect_status)(int result);


#ifdef QUEC_BT_PRODUCIBILITY
extern quec_cb_bt_open_status quec_bt_open_status_get;
extern quec_cb_bt_scan_status quec_bt_scan_status_get;
extern quec_cb_bt_connect_status quec_bt_connect_status_get;
extern void quec_set_dma_callback_unbind(unsigned int channel);
int quec_ble_init_device_record(void);
void quec_bt_sort_device_record(struct bt_addr addr);
void quec_add_device_record(struct bt_device_record *device);
int bt_init_device_record(void);

extern struct bt_user_cfg cfg;

#endif

#ifdef __cplusplus
}
#endif // __cplusplus

#endif

