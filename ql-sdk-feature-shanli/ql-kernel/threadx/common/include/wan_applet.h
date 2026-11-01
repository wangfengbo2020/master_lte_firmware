#ifndef WAN_APPLET_H
#define WAN_APPLET_H
#include "saremo_RTC.h"

#define IP_LEN                          16      //contain '\0'
#define MAC_LEN                         18      //contain '\0'
#define CLIENT_IP_FILE                  "/tmp/local/ip"
#define PLMN_Num                        10

#define PDP_DISCONNECTED                0
#define PDP_CONNECTED                   1
#define PDP_CONNECTING                  2
#define MAX_MT_PDP_NUMBER               6
#define MAX_MO_PDP_NUMBER               6

#define MAX_AUTH_KEY_LEN                32
#define MAX_NAME_SIZE 					32
//#define SN_PASSWORD_SUPPORT

/* Mode address */
#define PLATFORM_MODE_ADDRESS           0x07D7F010

#if 1
/* 3Mode LTG */
#define PLATFORM_3MODE_LTG_VER          0x334C5447

/* 3Mode LWG */
#define PLATFORM_3MODE_LWG_VER          0x334C5747
#else
/* 3Mode LTG */
#define PLATFORM_3MODE_LTG_VER          0x13243546

/* 3Mode LWG */
#define PLATFORM_3MODE_LWG_VER          0x89674523
#endif

/* 5Mode LTG */
#define PLATFORM_5MODE_LTG_VER          0x354C5447

/* 5Mode LWG */
#define PLATFORM_5MODE_LWG_VER          0x354C5747

#define DUSTER_USSD_SUPPORT
#define DEFAULT_MTU 1440

/* Wan */
typedef struct
{
    char*   wan_link_status;    /* WAN link: (Connected,Disconnected)                        */
    char*   wan_conn_type;      /* {disabled,dhcp,pppoe,static}                              */
    char*   wan_conn_status;    /* Status(connected,disconnected,in progreess, auth failure) */
    char*   ip_address;         /* WAN IP                        */
    char*   gateway;            /* WAN gateway                   */
    char*   dns1;               /* First WAN static dns                 */
    char*   dns2;               /* Second WAN static dns                */
    char*  mask;
} wan_info_t;

typedef struct
{
    UINT32 allowFlag;
    UINT32 Act;
    char     name[20];
    char     PLMN[8];
}PLMN_Record;

typedef struct S_DeviceNode
{
	UINT32 Reg_Tick;
	char name[40];
	char MAC[6];
	char IP[4];
	char name_type;
}DeviceNode;

typedef enum E_DeviceType{
	DeviceType_PC,
	DeviceType_WlanClient
}DeviceType;

typedef enum E_ConvertType{
	ConvertType_IP,
	ConvertType_MAC
}ConvertType;

typedef struct
{
	char 	*oper_name;
	char	*apn;
	char	*usrname;
	char	*paswd;
	char	*authtype;
	UINT8	 nwtype;
	UINT8	 iptype; /*for IPTYPE, 0--IPV4V6, 1--IPV4, 2 -- IPV6 */
	UINT8	 fail_num;/*updated for several APN*/
	UINT8	 lte_fail_num;
	INT32 	 mtu;
	void	*next;
} Apn_Info;
typedef struct
{
	char *mcc;
	char *mnc;
	UINT8	num;
	Apn_Info *apn_info_list;
	BOOL	all_try_fail;
	UINT8	try_num_ESM_false;
} Mnc_Apn;
#define MAX_TRY_NUM_ESM_FALSE	5

#define MAX_RETRY_TIME_COMMON	1
#define	MAX_RETRY_TIME_23G		1
#define MAX_RETRY_TIME_LTE		1

typedef struct {
    unsigned int  local_ip6[4];
    unsigned int  global_ip6[4];
	unsigned int  gateway_ip6[4];
} lte_ipv6_addr;

typedef struct _switch_image_ctx
{
	int last_switch_tick;
	int allow_switch;
	int auto_switch;
} s_switch_image_ctx;

void wan_free_MncApn(Mnc_Apn **ptr);
void wan_add_device(DeviceNode *device, int deviceType);
void wan_delete_device(DeviceNode *device, int deviceType);
void  DisconncectTimeCB(TIME *ptime, char cid);
char GetWlanClientNum(void);
int GetConnectMode(void);
unsigned long long get_rx_byte(void);
unsigned long long get_tx_byte(void);
unsigned long long get_rx_byte_all(void);
unsigned long long get_tx_byte_all(void);
UINT32 get_rssi(void);


// store the ssid string in globle array char ssid_ui[128] ;
char *get_wifi_ssid_ui(void);

//will store the password string contain '\0' in allocated buffer password, password_len should not shorter than MAX_AUTH_KEY_LEN
// 0: success; -1 failed
int get_wifi_auth_password(char *password, int password_len);

/* UTC time year+1900; mon+1*/
struct tm GetLocalTime(void);
/*Real local time*/
void GetCurrentCompTime(TIME *con_time);
/**RTC time without zone, store in Glabal struct TIME Current_Time*/
int RTCTimeGet(void);
/**
*
*@brief   RTC time with zone(if NTP Enabled)
*@return  - get seconds from 1970/1/1 to Now
*/
time_t GetRTCTime(void);

/**
*
*@brief   RTC time without zone
*@return  - get GMT seconds from 1970/1/1 to Now
*/
time_t GetGMTTimeSecond(void);


/**
*
*@brief    set RTC time
*@param[in] set_time   - set_time.year, set_time.month, set_time.day, set_time.hour, set_time.min, set_time.sec
*@return  - NULL
*/
void set_rtc_time(TIME *set_time);

/**
*
*@brief   get hardware version
*@param[out] string   - version buffer to store hardware version information
*@param[in] key   - version buffer len
*@return  - -1: with psm error  0:version_buf length not enough to store the software version else: the real length of hardware version(bytes)
*/
int get_hardware_version(char *version_buf, int version_buf_len);

/**
*
*@brief   get software version
*@param[out] string   - version buffer to store software version information
*@param[in] key   - version buffer len
*@return  - -1: with psm error 0:version_buf length not enough to store the software version  else: the real length of software version(bytes)
*/
int get_software_version(char *version_buf, int version_buf_len);

/**
*
*@brief   get model name
*@param[out] string   - version buffer to store model name information
*@param[in] key   - version buffer len
*@return  - -1: with psm error 0:version_buf length not enough to store the model name  else: the real length of model name(bytes)
*/
int get_model_name(char *version_buf, int version_buf_len);

/**
*
*@brief   get main chip name
*@param[out] string   - version buffer to store main chip name information
*@param[in] key   - version buffer len
*@return  - -1: with psm error 0:version_buf length not enough to store the main chip name   else: the real length of  main chip name(bytes)
*/
int get_mainchip_name(char *version_buf, int version_buf_len);

/**
*
*@brief   get bootloader version
*@param[out] string   - version buffer to store bootloader version information
*@param[in]    - version buffer len
*@return  - -1: with psm error 0:version_buf length not enough to store the bootloader version  else: the real length of  bootloader version(bytes)
*/
int get_bootloader_version(char *version_buf, int version_buf_len);

/**
*
*@brief   get lte version
*@return  lte_version
*/
int get_lte_version(void);

/*Add API to turn ON/OFF data connect start*/
void wan_cellular_data_off(void);
void wan_cellular_data_on(void);
/*Add API to turn ON/OFF data connect end*/
#endif
