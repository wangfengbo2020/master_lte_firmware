#ifndef DEVICE_MANAGEMENT_APPLET_H
#define DEVICE_MANAGEMENT_APPLET_H
#include "saremo_RTC.h"

#define 	MAX_WLAN_CLINET 10

typedef enum DeviceAction
{
	DeviceNoAction,
	DeviceStop,
	DeviceBlock,
	DeviceUnblock,
	DeviceTrafficReset,
	DevicePause,
	DeviceResume,
	SetTimeLimit,
	SetDataLimit,
	SetBothLimit
}E_DeviceAction;

typedef enum DeviceStatus
{
	DeviceInit,
	DeviceRunning,
	DeviceBlocked
}E_DeviceStatus;

typedef enum LimitType
{
	BothOff,
	TimeLimit,
	DataLimit,
	BothLimit
}E_LimitType;
typedef enum
{
	ThisMonth,
	LastThreeDays
}E_DataDurationType;

typedef struct 
{
	UINT32 time;
}s_TimeLimit;

typedef struct 
{
	UINT32 data;
}s_DataLimit;


typedef struct DeviceNodeLimit
{
	E_LimitType type;
	s_TimeLimit time_limit;
	s_DataLimit data_limit;
}s_DeviceNodeLimit;


typedef struct WlanStatistics 
{
	unsigned long long tx_bytes;
	unsigned long long rx_bytes;
	unsigned long long tx_total_bytes;//from system first bootup or after data reset to last power off or psm save
	unsigned long long rx_total_bytes;//from system first bootup or after data reset to last power off or psm save
	unsigned long long tx_current_total_bytes;//from system first bootup or after data reset to last power off or psm save
	unsigned long long rx_current_total_bytes;//from system first bootup or after data reset to last power off or psm save
	unsigned long long current_total_bytes;// from power on data bytes to last psm save
	unsigned long long rx_last_month_bytes;//from system first bootup or after data reset to last month
	unsigned long long tx_last_month_bytes;//from system first bootup or after data reset to last month
	unsigned long long rx_last_3day_bytes;//from system first bootup or after data reset to last 3 days
	unsigned long long tx_last_3day_bytes;//from system first bootup or after data reset to last 3 days
	TIME first_connect_time_at;
	TIME current_connect_time_at;
	unsigned int connect_time_for;
	unsigned int connected_tick;
	unsigned int current_tick;
	char ip[4];
	char MAC[18];
	char name[32];
	E_DeviceStatus status;
	DeviceType type;
	struct WlanStatistics *next;
}s_WlanStatistics;

typedef enum {
	wlan_client_start,
	wlan_client_stop,
	wlan_client_inquery,
	wlan_client_save
}E_ConnectTimeEvent;

#ifndef IP_MAC_PAIR_STRUCT
#define IP_MAC_PAIR_STRUCT
typedef struct __ip_mac_pair_t {
    UINT32   ip_addr;
    char    mac_addr[6];
    char    macstr[20]; //format: %02x-%02x-%02x-%02x-%02x-%02x, for debug output    
    UINT16   ttl;
    UINT32   bytes_tx;
    UINT32   bytes_rx;
    UINT32   error_tx;
    UINT32   error_rx;
    struct __ip_mac_pair_t *next;
} ip_mac_pair;
#endif


typedef struct _block_wlan_client
{
	char mac[18];
	struct _block_wlan_client *next;
}s_block_device_list;

enum send_sq_type
{
	SEND_SQ_INTERVAL,
	SEND_SQ_NW_OUT,
	SEND_SW_NW_IN
};

enum nw_switch_type
{
	NW_STATE_NO_CHANGE,
	NW_STATE_OUT,
	NW_STATE_IN
};

typedef void (*wifi_event_cb_t)(char *iccid, char *mac);
extern void register_wifi_conn_cb(wifi_event_cb_t event_cb);
extern void register_wifi_disconn_cb(wifi_event_cb_t event_cb);


/**
*
*@brief   get main chip name 
*@param[out] string   - version buffer to store main chip name information
*@param[in] key   - version buffer len 
*@return  - -1: with psm error 0:version_buf length not enough to store the main chip name   else: the real length of  main chip name(bytes)
*/
extern int get_mainchip_name(char *version_buf, int version_buf_len);
/*API to send msgQ for detecting SIM again*/
void sim_check_wrong_msg(void );
/*API to send MsgQ to send AT+CIMI again*/
void sim_inserted_CIMI_msg(void );

#endif
