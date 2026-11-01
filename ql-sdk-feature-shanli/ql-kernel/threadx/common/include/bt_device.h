/*
 * this file is for bt device and bt host interal use.
 */

#ifndef BT_DEVICE_H
#define BT_DEVICE_H

#include "bt_api.h"
#include "bt_uart_api.h"
#include "bt_debug.h"
#include "bt_api_le.h"

enum{
    BT_RESET_PIN = 0,
    BT_PWDN_PIN,
    BT_WAKEUP_HOST_PIN,
    BT_HOST_WAKEUP_BT_PIN,
    BT_PIN_MAX,
};

struct bt_gpio_def_cfg{
    unsigned int mfprx;
    unsigned int dir;
    unsigned int level;
};

struct bt_hardware_cfg {
    int baudrate; // 115200, 921600, 3000000
#ifndef UART_NEW_VERSION
    bt_uart_cfg *uart_cfg;
#else
	uartdrv_cfg *uart_cfg;
#endif
    int reset_pin; // -1: not reset BT chip through reset PIN
    int pwdn_pin; // -1: no PWDN pin -- BT_LDO_EN
    int bt_wakeup_host_pin; // -1: not use wakeup PIN
    int host_wakeup_bt_pin; // -1: not use wakeup PIN
    unsigned int clock32;
    struct bt_gpio_def_cfg bt_pin_def_cfg[BT_PIN_MAX]; //0:reset pin 1:pwdn pin 2:bt wakeup host pin 3:host wakeup bt pin
};

struct bt_hid_att_t{
    unsigned short int          hid_device_subclass;
    unsigned char               hid_country_code;
    unsigned char               hid_virtual_cable;
    unsigned char               hid_remote_wake;
    unsigned char               hid_reconnect_initiate;
    int                         hid_normally_connectable;
    int                         hid_boot_device;
    unsigned short int          hid_ssr_host_max_latency;
    unsigned short int          hid_ssr_host_min_timeout;
    unsigned short int          hid_supervision_timeout;
    const unsigned char *       hid_descriptor;
    unsigned char               hid_descriptor_size;
};

struct bt_br_common_cfg {
    char name[MAX_BT_NAME];
    unsigned char addr[6];
    unsigned char discoverable; // 0: cannot be searched by other device; 1: can be searched
    unsigned char connectable; // 0: non-connectable; 1: connectable
    unsigned char io_capability; // 0: DisplayOnly; 1: DisplayYesNo; 2: KeyboardOnly; 3: NoInputNoOutput
    unsigned short int inquiry_scan_interval;
    unsigned short int inquiry_scan_window;
    unsigned short int page_scan_interval;
    unsigned short int page_scan_window;
    unsigned char is_absolute_volume_enable; //0:a2dp use relatively volume 1:a2dp enable absolute volume
    unsigned int cod; //class of device
    struct bt_hid_att_t* hid_att; ///hid device cfg
    uint16_t sniff_min_interval;
    uint16_t sniff_max_interval;
    uint16_t sniff_attempt;
    uint16_t sniff_timeout;
    uint8_t comm_cfg; //bit 0 for ssp configure
    unsigned char reserved[6]; //add reserved buffer here
};

struct bt_le_common_cfg {
    unsigned char random_address[6];
    unsigned char smp_io_capability; // 0: DisplayOnly; 1: DisplayYesNo; 2: KeyboardOnly; 3: NoInputNoOutput
    unsigned char smp_secure_connection;
};

struct bt_profile_cfg {
    unsigned int prf;
    unsigned char reserved[4]; //add reserved buffer here
};

typedef struct _ble_device_info_record{
    unsigned char valid;
    unsigned char address[6];
    unsigned char addr_type;
    unsigned short deviceState;
    unsigned char ltk[16];
    unsigned char keyType;
    unsigned short ediv;
    unsigned char rand[8];
    unsigned char enc_size;
    unsigned char csrk[16];
    unsigned char peer_csrk[16];
    unsigned char signCounter;
    unsigned char irk[16];
    unsigned char peer_irk[16];
}__attribute__((packed)) ble_device_info_record;

struct bt_user_cfg {
    struct bt_hardware_cfg hw;
    struct bt_br_common_cfg br_common;
    struct bt_le_common_cfg le_common;
    struct bt_profile_cfg profile;
    struct bt_device_record *record;
    int firmware_where; // 0: SD; 1: flash; 2: memory
    unsigned char *bt_firmware;
    int bt_firmware_size;
    unsigned char *bt_nvm_lst;
    int bt_nvm_lst_size;
    int h4_h5; // 0: h4; 1: h5.
    int bt_mode; // 0: br only; 1: br + le; 2: le only
    int bt_chip_id; // 5801, 5803
    int xip;
	ble_device_info_record *ble_rec;
};

/* BT internal used */
#define BTTASK_FLAG_UART_RX             (1 << 0)
#define BTTASK_FLAG_INTERNEL_MSG        (1 << 1)
#define BTTASK_FLAG_USER_MSG            (1 << 2)
#define BTTASK_FLAG_SHUTDOWN_REQUEST    (1 << 3) // user shutdown through this
#define BTTASK_FLAG_SHUTDOWN_COMPLETE   (1 << 4) // statck internal use
#define BTTASK_FLAG_BT_WAKEUP           (1 << 5) // statck internal use
#define BTTASK_FLAG_BT_H5_ACTIVE        (1 << 6) // statck internal use
#define BTTASK_FLAG_SET_ADDR_COMPLETE   (1 << 7) // statck internal use
#define BTTASK_FLAG_INTERNAL_TIMER      (1 << 8) // statck internal use
#define BTTASK_FLAG_TX_DONE             (1 << 9) // stack transport sent
#define BTTASK_FLAG_ALL                 0xffffffff

//bt device internal use
void bt_update_device_record(void);
void appbt_clearup(void);
void asrbt_clearup(void);
int send_bttask_command(struct bt_task_command * command);
unsigned char bt_get_chip_id(unsigned int *id);
int appbt_le_dtm_in_open(void);
void app_bt_dump_data(char* desc, uint8_t* data, uint16_t size);
int copy_data_to_bt(char *src, uint32 len);
int appbt_check_connect_prf_valid(unsigned int prf);

#endif
