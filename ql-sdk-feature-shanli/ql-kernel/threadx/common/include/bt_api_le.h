#ifndef BT_API_LE_H
#define BT_API_LE_H

#include "bt_api_types.h"
#include "bt_api_le_demo.h"

#define LE_ERR_OK                       0x00
#define LE_ERR_INVALID_HANDLE           0x01
#define LE_ERR_READ_NOT_PERMITTED       0x02
#define LE_ERR_WRITE_NOT_PERMITTED      0x03
#define LE_ERR_INVALID_PDU              0x04
#define LE_ERR_INSUFFICIENT_AUTHEN      0x05
#define LE_ERR_REQUEST_NOT_SUPPORT      0x06
#define LE_ERR_INVALID_OFFSET           0x07
#define LE_ERR_INSUFFICIENT_AUTHOR      0x08
#define LE_ERR_PREPARE_QUEUE_FULL       0x09
#define LE_ERR_ATTRIBUTE_NOT_FOUND      0x0A
#define LE_ERR_ATTRIBUTE_NOT_LONG       0x0B
#define LE_ERR_INSUFFICIENT_ENCRY_KEY   0x0C
#define LE_ERR_INVALID_ATTRIBUTE_VALUE  0x0D
#define LE_ERR_UNLIKELY_ERROR           0x0E
#define LE_ERR_INSUFFICIENT_ENCRY       0x0F
#define LE_ERR_UNSUPPORTED_GTOUP_TYPE   0x10
#define LE_ERR_INSUFFICIENT_RESOURCES   0x11

#define LE_DEVICE_TYPE_CLASSIC          1
#define LE_DEVICE_TYPE_DUAL             3
#define LE_DEVICE_TYPE_LE               2
#define LE_DEVICE_TYPE_UNKNOWN          0

#define LE_ADV_TYPE_IND                 0x00
#define LE_ADV_TYPE_DIRECT_IND          0x01
#define LE_ADV_TYPE_SCAN_IND            0x02
#define LE_ADV_TYPE_NONCONN_IND         0x03
#define LE_ADV_TYPE_DIRECT_IND_LOW_DUTY 0x04

#define LE_PDU_TYPE_IND                 0x00
#define LE_PDU_TYPE_DIRECT_IND          0x01
#define LE_PDU_TYPE_NONCONN_IND         0x02
#define LE_PDU_TYPE_SCAN_REQ            0x03
#define LE_PDU_TYPE_SCAN_RESP           0x04

#define LE_EXT_ADV_PROPERTIES_BIT_CONNECTABLE   0
#define LE_EXT_ADV_PROPERTIES_BIT_SCANNABLE     1
#define LE_EXT_ADV_PROPERTIES_BIT_DIRECTED      2
#define LE_EXT_ADV_PROPERTIES_BIT_HIGH_DUTY_DIRECTED_CONNECTABLE  3
#define LE_EXT_ADV_PROPERTIES_BIT_LEGACY        4
#define LE_EXT_ADV_PROPERTIES_BIT_OMIT          5
#define LE_EXT_ADV_PROPERTIES_BIT_TXPOWER       6

#define LE_ADDRESS_TYPE_PUBLIC          0x00
#define LE_ADDRESS_TYPE_RANDOM          0x01

#define LE_GAP_TYPE_FLAGS                       0x01
#define LE_GAP_TYPE_INCOMPLETE_SERVICE_16BIT_LIST       0x02
#define LE_GAP_TYPE_COMPLETE_SERVICE_LIST       0x03
#define LE_GAP_TYPE_SHORT_NAME                  0x08
#define LE_GAP_TYPE_COMPLETE_NAME               0x09
#define LE_GAP_TYPE_TX_POWER                    0x0A
#define LE_GAP_TYPE_SERVICE_DATA                0x16
#define LE_GAP_TYPE_APPEARANCE                  0x19
#define LE_GAP_TYPE_SPECIFIC_DATA               0xFF

#define LE_PASSIVE_SCAN                 0x00
#define LE_ACTIVE_SCAN                  0x01

#define LE_ATT_MASTER                   0
#define LE_ATT_SLAVE                    1

#define LE_CCC_BIT_INDICATED            0x02
#define LE_CCC_BIT_NOTIFIED             0x01

#define LE_ATT_CHARC_PROP_READ          0x02
#define LE_ATT_CHARC_PROP_WWP           0x04
#define LE_ATT_CHARC_PROP_WRITE         0x08
#define LE_ATT_CHARC_PROP_NOTIFY        0x10
#define LE_ATT_CHARC_PROP_INDICATE      0x20

#define LE_ATT_PM_READABLE              0x0001
#define LE_ATT_PM_WRITEABLE             0x0002
#define LE_ATT_PM_AUTHENT_REQUIRED      0x0004
#define LE_ATT_PM_AUTHORIZE_REQUIRED    0x0008
#define LE_ATT_PM_ENCRYPTION_REQUIRED   0x0010
#define LE_ATT_PM_AUTHENT_MITM_REQUERED 0x0020

#define LE_ATT_UUID_PRIMARY             0x2800
#define LE_ATT_UUID_CHARC               0x2803

// standard GATT descriptors
#define LE_ATT_UUID_CLIENT_CHARC_CONFIG 0x2902
#define LE_ATT_UUID_CHAR_PRESENT_FORMAT 0x2904
#define LE_ATT_UUID_EXTERNAL_REF        0x2907
#define LE_ATT_UUID_REPORT_REF          0x2908

#define LE_ATT_UUID_GENERIC_ASSCES      0x1800
#define LE_ATT_UUID_IMMEDIATE_ALERT     0x1802
#define LE_ATT_UUID_DEVICE_INFO         0x180A
#define LE_ATT_UUID_BATTERY_SERVICE     0x180F
#define LE_ATT_UUID_HID                 0x1812
#define LE_ATT_UUID_MESH_PRO_SERVICE    0x1827
#define LE_ATT_UUID_MESH_PROXY_SERVICE  0x1828

#define LE_ATT_UUID_GAP_DEVICE_NAME     0x2A00
#define LE_ATT_UUID_ALERT_LEVEL         0x2A06
#define LE_ATT_UUID_BATTERY             0x2A19
#define LE_ATT_UUID_HIDBOOT_KB_INPUT    0x2A22
#define LE_ATT_UUID_HIDBOOT_KB_OUTPUT   0x2A32
#define LE_UUID_HIDBOOT_MOUSE_INPUT     0x2A33

#define LE_ATT_UUID_HIDINFO             0x2A4A
#define LE_ATT_UUID_HIDREPORT_MAP       0x2A4B

#define LE_ATT_UUID_HIDCONTROLPOINT     0x2A4C
#define LE_ATT_UUID_PROTOCOL            0x2A4E

#define LE_ATT_UUID_HIDREPORT           0x2A4D
#define LE_ATT_UUID_ALERT_LEVEL         0x2A06

#define LE_ATT_UUID_SYSTEM_ID           0x2A23
#define LE_ATT_UUID_MODEL_NUMBER        0x2A24
#define LE_ATT_UUID_SERIAL_NUMBER       0x2A25
#define LE_ATT_UUID_FIRMWARE_VERSION    0x2A26
#define LE_ATT_UUID_HARDWARE_VERSION    0x2A27
#define LE_ATT_UUID_SOFTWARE_VERSION    0x2A28
#define LE_ATT_UUID_MANUFACTURER_NAME   0x2A29
#define LE_ATT_UUID_IEEE_LIST           0x2A2A
#define LE_ATT_UUID_PNP_ID              0x2A50

#define LE_ATT_UUID_MESH_PRO_DATA_IN    0x2ADB
#define LE_ATT_UUID_MESH_PRO_DATA_OUT   0x2ADC
#define LE_ATT_UUID_MESH_PROXY_DATA_IN  0x2ADD
#define LE_ATT_UUID_MESH_PROXY_DATA_OUT 0x2ADE

#define BLE_DEMO_HCI_CON_HANDLE_INVALID 0xffff

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// demo define
// #define BLE_DEMO_LOOP_SEND_TEST
#ifdef BLE_DEMO_LOOP_SEND_TEST
extern volatile unsigned char ble_demo_loop_test_buf[256];
extern volatile unsigned short ble_demo_loop_test_ccc;
extern volatile unsigned short ble_demo_loop_test_handle;
#endif

/* ------------------------------- appbt_le_* interface start ---------------------------*/

// local used
int appbt_le_create_adv_data(int gap, unsigned char *buffer, int buffer_size, unsigned char *data, int size);

int appbt_le_parse_device_type(unsigned char *data, int total_size);

// custom command for requirements
/**
 * @param set_enable: set enable passkey set, 0: disable, 1: enable
 * @param passkey: passkey for user input(from 0 ~ 999999)
 * @param callback: register callback to monitor pair result
 */
int appbt_le_set_passkey_from_local(unsigned char set_enable, unsigned int passkey, pair_result_callback callback);

int appbt_le_set_pair_enable(unsigned char set_enable);

int appbt_le_input_passkey(unsigned char connection_handle, unsigned int passkey);

// communicate with btstack
int appbt_le_set_random_address(struct bt_addr addr);

int appbt_le_set_adv_parameters(struct bt_task_le_adv_parameters *para);

int appbt_le_set_adv_data(unsigned char *data, unsigned char length);

int appbt_le_set_scan_response_data(unsigned char *data, unsigned char length);

int appbt_le_set_adv_enable(int enable);

int appbt_le_set_ext_adv_parameters(struct bt_task_le_ext_adv_parameters *para);

int appbt_le_set_adv_set_random_address(unsigned char handle, struct bt_addr addr);

int appbt_le_set_ext_adv_data(unsigned char *data, unsigned char length, unsigned char handle, unsigned char operation, unsigned char fragment);

int appbt_le_set_ext_scan_response(unsigned char *data, unsigned char length, unsigned char handle, unsigned char operation, unsigned char fragment);

int appbt_le_set_ext_adv_enable(unsigned char enable, unsigned char number, unsigned char handle[], unsigned short duration[], unsigned char max_event[]);

int appbt_le_read_adv_phy_txpower(void);

int appbt_le_notify(unsigned short conn_handle, unsigned short att_handle, unsigned char *data, int size);

int appbt_le_indicate(unsigned short conn_handle, unsigned short att_handle, unsigned char *data, int size);

int appbt_le_scan(unsigned char type, unsigned short int interval, unsigned short int window, unsigned char own_address_type, le_scan_event_handle_t handle);

int appbt_le_scan_with_filter(unsigned char type, unsigned short int interval, unsigned short int window, unsigned char own_address_type, unsigned char filter, le_scan_event_handle_t handle);

/**
 * custom scan will not auto notify all scan result to BT_Device, btlib will filter duplicate scan result.
 * @param rssi: scan result rssi < configured rssi: will be ignored. (for example: -80 < -60 will be ignored, -50 > -60 will be valid.)
 * @param notify_size: when scan result count == notify_size, btlib will notify all scan result to BT_Device. (in case BTTASK_IND_LE_CUSTOM_SCAN_EVENT)
 * @param max_size: max size is dynamicly configured, and make sure notify_size < max_size.
 */
int appbt_le_custom_scan_start(unsigned char type, unsigned short int interval, unsigned short int window, unsigned char own_address_type,
                              signed char rssi, unsigned char max_size, unsigned char notify_size, le_scan_event_handle_t handle);
/**
 * get scan result can be used when custom scan started.
 * @param clean_flag: 0: will not clean scan result list. 1: will clean list after get scan result.
 */
int appbt_le_custom_get_scan_result(unsigned char clean_flag);

int appbt_le_scan_stop(void);

int appbt_le_connect(struct bt_addr addr, int type);

int appbt_le_cancel_connect(void);

int appbt_le_disconnect(unsigned short con_handle);

int appbt_le_clear_white_list(void);

int appbt_le_set_white_list(struct bt_addr addr, unsigned char type);

int appbt_le_remove_white_list(struct bt_addr addr, unsigned char type);

int appbt_le_register_att_server(unsigned char *profile_data, unsigned short profile_data_len, att_read_callback_t read_callback, att_write_callback_t write_callback);

int appbt_le_register_user_event_handle(le_user_event_handle_t handle);

int appbt_le_security_request(unsigned short con_handle);

/**
 * @param index:  -1 : get all info, 0 <= index < max_count : get valid info, index >= max_count : invalid index
 */
int appbt_le_get_pair_info(int index);

int appbt_le_remove_pair_info(int index);

int appbt_le_custom_write_command(unsigned short conn_handle, unsigned short att_handle, unsigned char *data, unsigned short size);

int appbt_le_custom_write_request(unsigned short conn_handle, unsigned short att_handle, unsigned char *data, unsigned short size);

int appbt_le_custom_read_request(unsigned short conn_handle, unsigned short att_handle);

int appbt_le_custom_mtu_request(unsigned short conn_handle, unsigned short mtu);

int appbt_le_custom_gatt_scan_start(unsigned short conn_handle);

int appbt_le_custom_gatt_scan_subscribe_default(unsigned char enable); // default enable

int appbt_le_custom_connection_parameter_update_request(unsigned short conn_handle, unsigned short conn_interval, unsigned short slave_latency, unsigned short supervision_timeout);

int appbt_le_set_default_phy(unsigned char all_phys, unsigned char tx_phys, unsigned char rx_phys);

void appbt_le_init_config(struct bt_addr addr);

/* ------------------------------- appbt_le_* interface end ---------------------------*/
#ifdef __cplusplus
}
#endif // __cplusplus

#endif

