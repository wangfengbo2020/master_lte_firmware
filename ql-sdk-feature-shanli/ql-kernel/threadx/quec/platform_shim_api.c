#ifdef LWIP_IPNETBUF_SUPPORT
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                PLATFORM_SHIM_API.c


GENERAL DESCRIPTION

    This file is for platform shim api.

EXTERNALIZED FUNCTIONS

INITIALIZATION AND SEQUENCING REQUIREMENTS

   Copyright (c) 2011 by Marvell, Incorporated.  All Rights Reserved.
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when         who        what, where, why
--------   ------     ----------------------------------------------------------
12/26/12   zhoujin    Created module
===========================================================================*/


/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/

#include "global_types.h"
#include "wan_applet.h"
#include "saremo_RTC.h"
#include "FlashPartition.h"
#include "usb_net.h"
#include "pbuf.h"
#include "netif.h"
#include "FDI_TYPE.h"
#include "lwipopts.h"
#include "cmux.h"
#include "MrvXML.h"
#include "csw_mem.h"
#include "sdio.h"
#include "mp3dec_api.h"
#include "modem_controller.h"
#include "diag_comm_SD.h"
#include "qspi_nor.h"
#include "platform.h"
#include "ningbo.h"
#include "quec_cust_feature.h"
#include "quec_atcmd_general.h"

typedef enum
{
    BOOT_FLASH			= 0,
    SAVE_STATE_FLASH	= 1
} FlashBootType_T;

#ifndef CSDAPI_SUPPORT
typedef struct VgFifo8Tag
{
  INT8  *pipe;
  volatile INT16  inptr;
  volatile INT16  outptr;
  INT16 mask;
  INT16 lwm;
  INT16 hwm;
  INT16 byteCount;
} VgFifo8;
#endif

char IMSI[16]={0};
char IMSI_1[16]={0};
const WORD UnitGranularity = 128;

#ifdef CRANE_SD_NOT_SUPPORT
int sdcard_dma_status_for_dma = 0;
unsigned int fat_debug_0;
unsigned int fat_debug_1;
#endif

#ifndef CMUX_ENABLE
/* Mux Mode Type */
cmux_mode_type CmuxMode = CMUX_DISABLE;
#endif

/* Flash Layout Parameters */
FlashLayoutConfInfo FlashLayoutInfo;


/*===========================================================================

            EXTERN DEFINITIONS AND DECLARATIONS FOR MODULE

===========================================================================*/

extern UINT32 SD_BLK_NUM;

/*===========================================================================

                          EXTERN FUNCTION DEFINITIONS

===========================================================================*/
void SulogInit2(void);
void sulog_start_ipc_internal(UINT16 msgOpcode);
void ee_sulog_handler_internal(void);
void SulogOffControlForUsbRemoveInternal(void);
void SulogUsbInitInternal(void);
void BipCmdTaskInitInternal (void);
void get_ntp_time_internal(void);
void cmux_init_internal(void);
void NTP_Init_Internal(void);
void init_atnet_internal(void);
void init_sgLed_internal(void);
void e20_set_timer_flag_internal(void);
void set_sg_led_status_internal(int status);
int test_CameraPreviewInternal(void);
int test_CameraRecordInternal(void);
int test_CameraCaputreInternal(void);
void test_LcdShowImageInternal(UINT8 *isSync);
void test_Logo_LcdShowImageInternal(void);
void test_ASS_LCD_DisplayTextInternal(char * text, int len);
err_t ppp_rx_comm_cb_internal(u8_t *payload, int len);
int cmux_write_internal(int dlci, char *packet, int length);
int atnet_context_is_transport_channel_internal(int channel);
int cmuxGetSvcIdByConnectIdInternal(UINT8 ConnectID);
int SocketRead_timeout_internal(int s, unsigned char* buffer, int len, int timeout_ms);
int SocketWrite_timeout_internal(int s, unsigned char* buffer, int len, int timeout_ms);
extern void _initMESmsInfo(void);

extern int get_pp_flag(void);
extern void set_fix_pp(unsigned char pp);
#ifdef WIFI_FUNCTION_SUPPORT
extern int lega_wlan_get_mac_address(uint8_t *mac_addr);
#endif

/*===========================================================================

                          INTERNAL FUNCTION DEFINITIONS

===========================================================================*/


#ifdef  NO_PAHO_MQTT //Chaim 010.008 for lwip
int mqtt_sample1(void)
{
	return 0;
}

#endif


UINT32 getFixedIP(char *MAC)
{
    return 0;
}


int checkFixedIP(UINT32 IP)
{
    return 0;
}

int SaveCalDataFromMfg(const void *buffer,int element_size, const char *file)
{
    return 0;
}

int woal_uap_do_ioctl(UINT32 cmd, UINT8 *cmd_buf)
{
    return 0;
}

BOOL IsGsmRatForMIFI(void  )
{
	return FALSE;
}

#ifndef ENABLE_CAT1_LG
BOOL IsGsmRatPowerOn(void)
{
	return FALSE;
}
#endif

int ipv4_address_change_trigger(void)
{
	return 0;
}

#ifndef MBIM_FUNCTION
UINT8 IsMbimEnabled(void)
{
    return 0;
}
#endif


void LteConstructSnDataNodeEForMifi(unsigned char cid, unsigned char  *dataAddr, unsigned short dataLen)
{
    return;
}

void UIRefresh_Throughput_Change(void)
{
	return;
}

int embms_data_input(void * data)
{
	return 0;
}

void lte_lwip_free(void* ptr, int size)
{
    return;
}

#ifndef LWIP_NETIF_LTE
void* lte_lwip_malloc(int size, BOOL isQosPacket)
{
    return NULL;
}
#endif


#ifndef YMODEM_EEH_DUMP
int YmodemCfgSet(int type)
{
    return -1;
}
#endif

#ifdef SULOG_DISABLE
unsigned int sulog_file_handle_g = 0;
#endif

#ifdef MIN_SYS
#ifdef REMOVE_MBEDTLS

#define MBEDTLS_DES_KEY_SIZE    8

void mbedtls_md5_finish( void *ctx,
                         unsigned char output[16] )
{
    return;
}

void mbedtls_md5_starts( void *ctx )
{
   return;
}

void mbedtls_md5_update( void *ctx,
                         const unsigned char *input,
                         size_t ilen )
{
    return;
}

void mbedtls_ctr_drbg_free( void *ctx )
{
    return;
}

void mbedtls_ctr_drbg_init( void *ctx )
{
    return;
}

int mbedtls_ctr_drbg_random( void *p_rng,
                     unsigned char *output, unsigned int output_len )
{
    return -1;
}

int mbedtls_ctr_drbg_seed( void *ctx,
                   int (*f_entropy)(void *, unsigned char *, unsigned int),
                   void *p_entropy,
                   const unsigned char *custom,
                   unsigned int len )
{
    return -1;
}

void mbedtls_entropy_free( void *ctx )
{
    return;
}

int mbedtls_entropy_func( void *data, unsigned char *output, unsigned int len )
{
    return -1;
}

void mbedtls_entropy_init( void *ctx )
{
    return;
}

int mbedtls_ssl_close_notify( void *ssl )
{
    return -1;
}

void mbedtls_ssl_conf_authmode( void *conf, int authmode )
{
    return;
}

void mbedtls_ssl_conf_dbg( void *conf,
                  void (*f_dbg)(void *, int, const char *, int, const char *),
                  void  *p_dbg )
{
    return;
}

void mbedtls_ssl_conf_rng( void *conf,
                  int (*f_rng)(void *, unsigned char *, size_t),
                  void *p_rng )
{
    return;
}

int mbedtls_ssl_config_defaults( void *conf,
                                 int endpoint, int transport, int preset )
{
    return -1;
}

void mbedtls_ssl_config_free( void *conf )
{
    return;
}

void mbedtls_ssl_init( void *ssl )
{
    return;
}

int mbedtls_ssl_read( void *ssl, unsigned char *buf, unsigned int len )
{
    return -1;
}

void mbedtls_ssl_set_bio( void *ssl,
        void *p_bio,
        void *f_send,
        void *f_recv,
        void *f_recv_timeout )
{
    return;
}

int mbedtls_ssl_setup( void *ssl,
                       const void *conf )
{
    return -1;
}

int mbedtls_ssl_write( void *ssl, const unsigned char *buf, unsigned int len )
{
    return -1;
}

void mbedtls_ssl_config_init( void *conf )
{
    return;
}

void mbedtls_ssl_free( void *ssl )
{
    return;
}

int md_hmac( const void *md_info,
                     const unsigned char *key, unsigned int keylen,
                     const unsigned char *input, unsigned int ilen,
                     unsigned char *output )
{
    return -1;
}

const void *md_info_from_type( int md_type )
{
    return NULL;
}

unsigned int mpi_msb( const void *X )
{
    return 0;
}

int mpi_read_binary( void *X, const unsigned char *buf, unsigned int buflen )
{
    return 0;
}

void sha1_starts( void *ctx )
{
    return ;
}

void sha1_update( void *ctx,
                          const unsigned char *input,
                          unsigned int ilen )
{
    return ;
}

void mbedtls_debug_set_threshold( int threshold )
{
    return;
}

int mbedtls_aes_crypt_cbc( void *ctx,
                    int mode,
                    unsigned int length,
                    unsigned char iv[16],
                    const unsigned char *input,
                    unsigned char *output )
{
    return -1;
}

int mbedtls_aes_setkey_dec( void *ctx, const unsigned char *key,
                    unsigned int keybits )
{
    return -1;
}

int mbedtls_aes_setkey_enc( void *ctx, const unsigned char *key,
                    unsigned int keybits )
{
    return -1;
}

int mbedtls_des3_crypt_cbc( void *ctx,
                     int mode,
                     unsigned int length,
                     unsigned char iv[8],
                     const unsigned char *input,
                     unsigned char *output )
{
    return -1;
}

int mbedtls_des3_set3key_dec( void *ctx,
                      const unsigned char key[MBEDTLS_DES_KEY_SIZE * 3] )
{
    return 0;
}

int mbedtls_des3_set3key_enc( void *ctx,
                      const unsigned char key[MBEDTLS_DES_KEY_SIZE * 3] )
{
    return 0;
}

void mbedtls_sha1_finish( void *ctx,
                          unsigned char output[20] )
{
    return;
}

void mbedtls_sha1_starts( void *ctx )
{
    return;
}

void mbedtls_sha1_update( void *ctx,
                          const unsigned char *input,
                          unsigned int ilen )
{
    return;
}
#endif
#endif
#ifdef NO_DIALER
int get_auto_apn_mtu(int simID)
{
    return -1;
}

int get_in_dialer_mt_proc(void)
{
    return 0;
}

void set_in_dialer_mt_proc(int flag)
{
    return;
}

void dialer_task_init(void)
{
    return;
}
 BOOL get_cgdf_save_mode(void)
{
	return FALSE;
}

 void set_imsi_changed_flag(UINT32 reqHandle, UINT8 changed)
 {
 	return;
 }


#endif

#ifndef BT_TEST_SUPPORT
void asrbt_main(void)
{
    return;
}
#endif

#ifndef BT_SUPPORT
int bt_wakelock_status(void)
{
    return 0;
}

void appbt_bt_enter_sleep(void)
{
}

void appbt_bt_exit_sleep(void)
{
}

UINT8 GetBTPmLock(void)
{
//Those three funcs are dir operation for framework build ok
	return 0;
}

#endif










void td_send_packet(UINT8 *data, UINT32 len,int cid)
{
    return;
}

#if 0
void mvUsbNetSendPacket(UINT8* data, UINT32 len)
{
    return;
}
#endif

#ifndef WIFI_FUNCTION_SUPPORT
int get_wifi_mac(u8_t *wifi_mac)
{
    return 1; /*0: ok; 1: failed.*/
}
#else
int get_wifi_mac(u8_t *wifi_mac)
{
    return lega_wlan_get_mac_address(wifi_mac);
}
#endif

void try_wakeup_host(void)
{
    return;
}

int GetWiFiType(void)
{
	return 0;
}

UINT8 GetWifiStatus(void)
{
    return 0;
}

void OLED_WIFITransferStatusChange(void)
{
    return;
}

int WIFI_Sendto_Wapi(UINT8 *data, UINT32 len){
    return 0;
}

signed long WIFI_Sendto_Wps(UINT8 bss_type, UINT8 *data, UINT32 len){
    return 0;
}

#ifndef WIFI_FUNCTION_SUPPORT
signed long netif_send_to_wifi_uap_nocpy(UINT8 *data, UINT32 len)
{
    return 0;
}
UINT8 sdio_work(void)
{
    return 0;
}
#endif

int uap_packet_free(char *buf)
{
	return 0;
}

UINT32 EraseFlash(UINT32 flash_addr, UINT32 size, FlashBootType_T fbt)
{
	fatal_printf("EraseFlash 0x%x 0x%x\r\n", flash_addr, size);

	spi_nor_do_erase(flash_addr, size, 0);

    return 0;
}

UINT32 ReadFlash(UINT32 flash_addr, UINT32 buffer, UINT32 total_size, FlashBootType_T fbt)
{
	fatal_printf("ReadFlash 0x%x 0x%x\r\n", flash_addr, total_size);

	spi_nor_do_read(flash_addr, buffer, total_size, 0);


    return 0;
}

UINT32 WriteFlash(UINT32 flash_addr, UINT32 buffer, UINT32 total_size, FlashBootType_T fbt)
{
	fatal_printf("WriteFlash 0x%x 0x%x\r\n", flash_addr, total_size);

	spi_nor_do_write(flash_addr, buffer,total_size, 0);

    return 0;
}

FlashLayoutConfInfo *GetFlashLayoutConfig(void)
{
    return &FlashLayoutInfo;
}

void Giga_Enable4BytesMode(void)
{
    return;
}

void Giga_Disable4BytesMode(void)
{
    return;
}

void Rdisk_FlashRead(unsigned int flashaddress, unsigned char *buffer, unsigned int size)
{
    return;
}
#if 0
void SetCfunValue(int value)
{
    return;
}
#endif
void UIRefresh_Operator_Change(void)
{
    return;
}


void watchdog_reset(void)
{
    return;
}

#if 0
UINT8 *mvUsbNetGetMacAddress(void)
{
    return UsbNetMacAddress;
}
#endif

#ifndef PSM_ENABLE

int psm_commit__(void)
{
    return 0;
}

char *psm_get_wrapper(char *mod_name, char *subspace, char *variable)
{
    return NULL;
}

int psm_set_wrapper(char *mod_name, char *subspace, char *variable, char *value)
{
    return 0;
}

#endif

#ifndef CRANE_MCU_DONGLE
signed long dialerResponseToCmux(void *rsp)
{
    return 0;
}

signed long dialerReportNokToCmux(signed long conNum)
{
    return 0;
}
#endif

#ifdef CRANE_SD_NOT_SUPPORT
#include "FDI_ERR.h"
#include "crossPlatformSW.h"

int FAT_fclose(unsigned int stream)
{
    return 0;
}

unsigned int FAT_fopen(const char *filename_ptr, const char *mode)
{
    return 0;
}

size_t FAT_fread(void *buffer_ptr, size_t element_size, size_t count, unsigned int stream)
{
    return 0;
}

unsigned int FAT_fwrite(const void *buffer_ptr,size_t element_size,size_t count,unsigned int stream)
{
    return 0;
}

int FAT_remove(const char *filename_ptr)
{
    return -1;
}

int get_log_sd_unused(void)
{
    return -1;
}

//Those three funcs are dir operation
int FAT_MakeDir(char *dir_name, unsigned int mode)
{
	return -1;
}

BOOL FAT_findfileclose(unsigned int handle)
{
	return FALSE;
}

unsigned int FAT_findfirst(const char *filename_ptr, LPFAT32FILEINFO fileinfo_ptr)
{
    return 0;
}


int FAT_findnext(unsigned int handle, LPFAT32FILEINFO fileinfo_ptr)
{
    return -1;
}


void sdcard_need_format(void)
{
    return;
}

void sdcard_not_need_format(void)
{
    return;
}

ERR_CODE FAT_Format(char *vol)
{
    return 0;
}
int FAT_GetCurrentDir(char *dir_name, unsigned int max_len)
{
    return 0;
}
/*
typedef struct _FS_INFO
{
    long long iToTalSize;
	long long iUsedSize;
}FS_INFO;
*/
int FAT_GetFSInfo(char *pszDevName, FS_INFO* psFSInfo)
{
    return 0;
}

unsigned int FAT_GetFileSize(unsigned int stream)
{
    return 0;
}

BOOL FAT_IsFormatted(char *vol)
{
    return 0;
}


int FAT_MakeDir_M(char *dir_name, unsigned int mode)
{
    return 0;
}

UINT32 FAT_Getfree(char *path)
{
    return 0;
}


int FAT_RemoveDir(char *dir_name)
{
    return 0;
}

int FAT_SetCurrentDir(char *dir_name)
{
    return 0;
}

int FAT_eof(unsigned int stream)
{
    return 0;
}

int FAT_fseek(unsigned int stream, long offset, int wherefrom)
{
    return 0;
}

int FAT_rename(const char *oldname_ptr, const char *newname_ptr)
{
    return 0;
}


#ifndef ADAPT_FRAMEWORK_BUILD
void set_sdcard_power_gpio(UINT8 num)
{
    return;
}
#endif


#endif

#ifndef MP3_DECODE
int mp3Start(const char *file_name)
{
    return -1;
}
#endif

#ifdef NO_OPENSSL

int ssl_read( void *ssl, unsigned char *buf, int len )
{
    return -1;
}

int ssl_write( void *ssl, const unsigned char *buf, int len )
{
    return -1;
}

void md5_finish( void *ctx, unsigned char output[16] )
{
    return;
}

void md5_starts( void *ctx )
{
    return;
}

void md5_update( void *ctx, const unsigned char *input, int ilen )
{
    return;
}

int entropy_func( void *data, unsigned char *output, int len )
{
    return -1;
}


int ssl_close_notify( void *ssl )
{
    return -1;
}

int ssl_init( void *ssl )
{
    return -1;
}

void ssl_free( void *ssl )
{
    return;
}

void entropy_init( void *ctx )
{
    return;
}

int ctr_drbg_init( void *ctx,
                   int (*f_entropy)(void *, unsigned char *, int),
                   void *p_entropy,
                   const unsigned char *custom,
                   int len )
{
    return -1;
}

int ctr_drbg_random( void *p_rng, unsigned char *output, int output_len )
{
    return -1;
}

void ssl_set_rng( void *ssl,
                  int (*f_rng)(void *, unsigned char *, size_t),
                  void *p_rng )
{
    return;
}

void ssl_set_dbg( void *ssl,
                  void (*f_dbg)(void *, int, const char *),
                  void  *p_dbg )
{
    return;
}


void ssl_set_bio( void *ssl,
            int (*f_recv)(void *, unsigned char *, size_t), void *p_recv,
            int (*f_send)(void *, const unsigned char *, size_t), void *p_send )
{
    return;
}

void ssl_set_endpoint( void *ssl, int endpoint )
{
    return;
}


void ssl_set_authmode( void *ssl, int authmode )
{
    return;
}
#endif

#ifdef NO_MRD
int  AtMrdMips(void *reqSig,void *pCnfParas)
{
    return 0;
}

int  AtMrdImei(void *reqSig,void *pCnfParas)
{
    return 0;
}

int  AtMrdCdf(void *reqSig,void *pCnfParas)
{
   return 0;
}

void set_mrd_production_mode(UINT32 val)
{
	return;
}

void set_calib_production_mode(UINT32 val)
{
    return;
}

UINT32 InProduction_Mode(void)
{
    return 0;
}

void BtIDInit(unsigned long *ddrBuffaddr)
{
    return;
}
#endif

#ifdef ENABLE_WIFI_SCAN
extern void _processWifiHotspotInfoInd(const void *paras);

void processWifiHotspotInfoInd(const void *paras)
{

#ifndef MIN_SYS
    if(!IsMiniSystem()) {
        _processWifiHotspotInfoInd(paras);
    }
#endif

	return;
}
#else
//解决不支持wifiscan功能的版本编译报错
void processWifiHotspotInfoInd(const void *paras)
{

}

#endif


#ifdef NO_AUDIO
typedef void (*audioGsmStartVoicePath_t)(void);
typedef void (*audioGsmStopVoicePath_t)(void);
//#ifdef MACRO_FOR_LWG
typedef void (*audioGsmGetVocoderTypeRate_t)(unsigned short *vocoderType, unsigned short *vocoderRate);
//#endif
typedef BOOL  (*audioGsmGetDtxSupport_t)(void);
typedef void* (*audioGsmGetTxBuffer_t)(void);
typedef void  (*audioGsmSetAmrToc_t)(unsigned short);
typedef void  (*audioGsmSetAmrSidTypeInd_t)(unsigned short);
typedef void  (*audioGsmSetEncoderFlags_t)(unsigned short);
typedef void  (*audioGsmSetDecoderSidInd_t)(unsigned short);

#if 0
void audioPhase1Init(void)
{
    return;
}
#endif 

void audioBindGsmGetDtxSupport(audioGsmGetDtxSupport_t audioGsmGetDtxSupport)
{
    return;
}

void audioBindGsmGetTxBuffer(audioGsmGetTxBuffer_t audioGsmGetTxBuffer)
{
    return;
}

void audioBindGsmGetVocoderTypeRate(audioGsmGetVocoderTypeRate_t audioGsmGetVocoderTypeRate)
{
    return;
}

void audioBindGsmSetAmrSidTypeInd(audioGsmSetAmrSidTypeInd_t audioGsmSetAmrSidTypeInd)
{
    return;
}

void audioBindGsmSetAmrToc(audioGsmSetAmrToc_t audioGsmSetAmrToc)
{
    return;
}

void audioBindGsmSetDecoderSidInd(audioGsmSetDecoderSidInd_t audioGsmSetDecoderSidInd)
{
    return;
}

void audioBindGsmSetEncoderFlags(audioGsmSetEncoderFlags_t audioGsmSetEncoderFlags)
{
    return;
}

void audioBindGsmStartVoicePath(audioGsmStartVoicePath_t audioGsmStartVoicePath)
{
    return;
}

void audioBindGsmStopVoicePath(audioGsmStopVoicePath_t audioGsmStopVoicePath)
{
    return;
}

int AudioHAL_AifDrain(void)
{
    return 0;
}

int AudioHAL_AifPlayStream(void *playedStream)
{
    return 0;
}

void AudioHAL_AifStopPlay(void)
{
    return;
}

int AudioHAL_SetResBufCnt(unsigned int bufCnt)
{
    return 0;
}

int AudioHAL_AifPause(BOOL pause)
{
    return 0;
}

BOOL CraneCodecADCOnOff(BOOL OnOff)
{
    return FALSE;
}

typedef void (*AUDIOHAL_HeadsetReport_T) (UINT32 plug, UINT32 type, UINT32 event);

void AudioHAL_AifBindHeadsetDetectionCB(AUDIOHAL_HeadsetReport_T cb)
{
    return;
}

void AudioHAL_AifGetHeadsetInfo(UINT32* plug, UINT32* type)
{
    return;
}

UINT32 AudioHAL_AifGetVolume(void)
{
    return 0;
}

void AudioHAL_AifHeadsetDetection(BOOL onoff)
{
    return;
}

void AudioHAL_set_close_delay(unsigned int cnt)
{
    return;
}




#endif

UINT8 Is_dedicateAPN(char cid)
{
	if( cid > 8)
		return 1;
	else
		return 0;
}

BOOL psNvmCheckAPNInfo(char *input_apn,	UINT8 ip_type)
{
	return FALSE;
}

int get_hwver_type(void)
{
	return 0;
}

UINT8 get_atcmdsrv_cfun4_flag(void)
{
	return 0;
}

UINT8 clear_atcmdsrv_cfun4_flag(void)
{
    return 0;
}

unsigned char Update_RTC_Time(void)
{
    return 0;
}

void UIRefresh_PDPState_Change(void)
{
    return;
}

void UIRefresh_Modem_Change(void)
{
    return;
}

void Get_backtime_frompsm(void)
{
    return;
}

#ifndef QUECTEL_PROJECT_CUST 
void GetCurrentCompTime(TIME *con_time)
{
    return;
}
#endif

#if QUEC_BIP_SUPPORT
extern BOOL quec_bip_state(void);
#endif
BOOL GetBIPEnableFlag(void)
{
#ifdef BIP_FUNC_SUPPORT
#if QUEC_BIP_SUPPORT
#ifndef MIN_SYS
    if(!IsMiniSystem())
    {
    return quec_bip_state();
	}
	else
	return TRUE;
#else
	return TRUE;
#endif
#else
	return TRUE;
#endif
#else
	return FALSE;
#endif
}
UINT32 usb_net_tx(UINT32 *txPtr, UINT32 length)
{
    return 0;
}
// dummy function for dongle compile
UINT32 usb_net_rx(void *rxPtr, UINT32 maxSize)
{
    return 0;
}

#if 0
int getPSNwReg(void)
{
    return 0;
}
#endif

#if 0
int usbnet_enter_directip(int *ipaddr, int *subnet_mask, int *gwaddr, int *dns1_addr, int *dns2_addr)
{
    return 0;
}
#endif

UINT32 usb_net_init(UsbNetRxDoneCallbackFunc Func)
{
	return 1;
}


BOOL CheckIf32MNOR( void )
{
    return FALSE;
}

BOOL PlatformSpiNorEnable(void)
{
    return FALSE;
}

BOOL isAutoApn(void)
{
	return FALSE;
}

#ifndef CRANE_MCU_DONGLE
int is_E20_module_type(void)
{
	return FALSE;
}
#endif

#ifndef QUECTEL_PROJECT_CUST 
struct tm GetLocalTime()
{
	struct tm time = {0};

	return time;
}
#endif


int get_download_flag_for_tigx(void)
{
	return 0;
}

char get_network_mode(void)
{
	return 5; //CI_DEV_NW_LTE_MODE;
}

int get_uart2_baudrate_for_tigx(void)
{
	return -1;
}

int set_download_flag_for_tigx(int flag)
{
	return 0;
}

int set_uart2_baudrate_for_tigx(unsigned int rate)
{
	return 0;
}

void set_uart_selfadapt(void)
{
	return;
}


#ifdef CRANE_MCU_DONGLE
UINT32 FdvBlockSize = 128*1024; /*block size*/
UINT16 FdvBlockCount= 10; /*numbers of block*/


ERR_CODE FDI_SizeAvailable (WORD frag_size, DWORD_PTR total_size)
{
	*total_size = 0x20000;
	return ERR_NONE;
}

ERR_CODE FDI_SpaceUsed(WORD identifier, BYTE type, DWORD_PTR spaceused)
{
	*spaceused = 0;
	return ERR_NONE;
}

VOID FDI_TaskDelayTicks(UNSIGNED numTicks)
{
	return;
}

#endif

#ifndef WEBUI_SUPPORT
void wan_add_device(DeviceNode *device, int deviceType)
{
    if(device)
        free(device);
	return;
}

void wan_delete_device(DeviceNode *device, int deviceType)
{
    if(device)
        free(device);
	return;
}

int is_aes_cipher()
{
	return 0;
}
#endif

#ifdef CRANE_MCU_DONGLE

#if defined(FOTA_RS_FEATURE) || defined(FOTA_GS_FEATURE)
int NVMFileNameMatch(const char *src, const char *dest)
{
    return 0;
}
#else
UINT32 flush_time_check(UINT32 val)
{
    return 0;
}

void nvm_cache_flush_all(void)
{
    return;
}
void nvm_flush_ps_idle_cnf(BOOL flag)
{
    return;
}

void nvm_flush_ps_resume_ind(void)
{
    return;
}

void RamBlockSyncOpWriteTrigger(UINT32 type, UINT32 current, UINT32 len)
{
    return;
}

UINT32 get_d2_nvm_flush(void)
{
    return 0;
}

void disable_d2_nvm_flush(void)
{
    return;
}

void enable_d2_nvm_flush(void)
{
    return;
}

void qspi_flush_in_time(UINT32 time)
{
    return;
}
void record_flush_write(UINT32 start, UINT32 len)
{
    return;
}

#endif
#endif


void SulogInit(void)
{
#ifndef SULOG_DISABLE
#ifndef MIN_SYS
    if(!IsMiniSystem())
    {
        SulogInit2();
    }
#endif
#endif
}

void sulog_start_ipc(UINT16 msgOpcode)
{
#ifndef SULOG_DISABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        sulog_start_ipc_internal(msgOpcode);
    }
#endif
#endif
}

void ee_sulog_handler(void)
{
#ifndef SULOG_DISABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        ee_sulog_handler_internal();
    }
#endif

#endif

    return;
}

void SulogOffControlForUsbRemove(void)
{
#ifndef SULOG_DISABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        SulogOffControlForUsbRemoveInternal();
    }
#endif
#endif

    return;
}

void SulogUsbInit(void)
{
#ifndef SULOG_DISABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        #ifdef QUEC_USB_CDC_SUPPORT
        extern unsigned char quec_sulog_get_status(void);
        if(quec_sulog_get_status()==1)
        #elif defined(QUEC_AT_QCFG_USB_NEMA)
        #define QUEC_NEMA_ENABLE (1)
        extern int32 quec_get_usb_nema_ec20(void);
        if (QUEC_NEMA_ENABLE != quec_get_usb_nema_ec20()) //ec20配置端点和SULOG端点有个别冲突
        #endif
        SulogUsbInitInternal();
    }
#endif
#endif

    return;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      cmux_init                                                        */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function intializes cmux related variables and task.         */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
void cmux_init(void)
{
#ifdef CMUX_ENABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        cmux_init_internal();
    }
#endif
#endif
}

int cmux_write(int dlci, char *packet, int length)
{
#ifdef CMUX_ENABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return cmux_write_internal(dlci, packet, length);
    }
#endif
#endif
    return -1;
}

void cmux_startup(muxparameter * par)
{
#ifdef CMUX_ENABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        cmux_startup_internal(par);
    }
#endif
#endif
    return;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      modem_init                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function intializes modem route.                             */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
//#ifndef QUECTEL_PROJECT_CUST
void modem_init(void)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS
     if(!IsMiniSystem())
     {
        modem_init_internal();
     }
#endif
#endif
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      send_data_to_modem_router                                        */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function send data to modem router.                          */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
void send_data_to_modem_router(char *data, int len, int atp_index, int from)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS
     if(!IsMiniSystem())
     {
        send_data_to_modem_router_internal(data, len, atp_index, from);
     }
#endif
#endif
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      ppp_enable                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function get PPP enable flag.                                */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
BOOL ppp_enable(void)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS
    if(!IsMiniSystem())
    {
        return TRUE;
    }
#endif
#endif
    return FALSE;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      ppp_rx_comm_cb                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function is cb for comm to send data.                        */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
err_t ppp_rx_comm_cb(UINT8 *payload, int len)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS
    if(!IsMiniSystem())
    {
        return ppp_rx_comm_cb_internal(payload, len);
    }
#endif
#endif

    return 0;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      get_ppp_cid                                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function get ppp cid.                                        */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
UINT8 get_ppp_cid(void)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS
    if(!IsMiniSystem())
    {
        return get_ppp_cid_internal();
    }
#endif
#endif
	return 0xFF;
}

int process_ppp_atd(int atp_index, char *dial_string)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return process_ppp_atd_internal(atp_index, dial_string);
    }
#endif
#endif
	return -1;
}

void modem_update_reg_option( int atp_index, int option)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        modem_update_reg_option_internal(atp_index, option);
    }
#endif
#endif

    return;
}

BOOL ppp_get_connect_flag(UINT8 cid)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return ppp_get_connect_flag_internal(cid);
    }
#endif
#endif
    return 0;
}

void ppp_process_data_nok(UINT8 cid, BOOL force)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        ppp_process_data_nok_internal(cid, force);
    }
#endif
#endif

    return;
}

void handle_dial(int atp_index)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        handle_dial_internal(atp_index);
    }
#endif
#endif
    return;
}

int get_cgreg_status_rsp(int atp_index, char *rsp_buf, int type)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return get_cgreg_status_rsp_internal(atp_index, rsp_buf, type);
    }
#endif
#endif
    return -1;
}

void ppp_clear_use_eps_apn(UINT32 atp_index)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        ppp_clear_use_eps_apn_internal(atp_index);
    }
#endif
#endif

    return;
}

void ppp_store_configure_params(int atp_index, int cid, char *apn,  int ip_type)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        ppp_store_configure_params_internal(atp_index, cid, apn, ip_type);
    }
#endif
#endif

    return;
}

BOOL need_ppp_process_at_response(int atp_index)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return need_ppp_process_at_response_internal(atp_index);
    }
#endif
#endif
	return 0;
}

void modem_channel_buffer_reset(void)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        modem_channel_buffer_reset_internal();
    }
#endif
#endif
    return;
}

BOOL need_ppp_process_ato_request(int atp_index)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return need_ppp_process_ato_request_internal(atp_index);
    }
#endif
#endif
    return 0;
}

int process_ppp_ato(int atp_index)
{
#ifdef PPP_ENABLE
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return process_ppp_ato_internal(atp_index);
    }
#endif
#endif
    return 0;
}


void BipCmdTaskInit (void)
{
#ifdef BIP_FUNC_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        #if QUEC_BIP_SUPPORT
        extern  void quec_bip_config_init(void);
        quec_bip_config_init();
        if(GetBIPEnableFlag()==TRUE)
        #endif
        BipCmdTaskInitInternal();
    }
#endif
#endif
    return;
}

void get_ntp_time(void)
{
#ifdef NTP
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        #ifndef QUECTEL_PROJECT_CUST /*关闭默认的系统ntp同步*/
        get_ntp_time_internal();
        #endif
    }
#endif
#endif

    return;
}

void NTP_Init(void)
{
#ifdef NTP
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        #ifdef QUEC_GNSS_NTP
        NTP_Init_Internal();
        #endif
    }
#endif
#endif

    return;
}


void init_atnet(void)
{
#ifndef NO_AT_NET
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        init_atnet_internal();
    }
#endif
#endif
    return;
}

void init_sgLed(void)
{
#ifndef NO_AT_NET
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        init_sgLed_internal();
    }
#endif
#endif

    return;
}

int atnet_context_is_transport_channel(int channel)
{
#ifndef NO_AT_NET
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return atnet_context_is_transport_channel_internal(channel);
    }
#endif
#endif
    return 0;
}

int cmuxGetSvcIdByConnectId(UINT8 ConnectID)
{
#ifndef NO_AT_NET
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return cmuxGetSvcIdByConnectIdInternal(ConnectID);
    }
#endif
#endif
	return 6;
}

void e20_set_timer_flag(void)
{
#ifndef NO_AT_NET
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        e20_set_timer_flag_internal();
    }
#endif
#endif

    return;
}

void set_sg_led_status(int status)
{
#ifndef NO_AT_NET
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        set_sg_led_status_internal(status);
    }
#endif
#endif

    return;
}

#if 0
int SocketRead_timeout(int s, unsigned char* buffer, int len, int timeout_ms)
{
#ifndef NO_PAHO_MQTT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return SocketRead_timeout_internal(s, buffer, len, timeout_ms);
    }
#endif
#endif

    return -1;
}

int SocketWrite_timeout(int s, unsigned char* buffer, int len, int timeout_ms)
{
#ifndef NO_PAHO_MQTT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return SocketWrite_timeout_internal(s, buffer, len, timeout_ms);
    }
#endif
#endif
    return -1;
}
#endif

void MrvDeleteAttribute(MrvXMLAttribute *pEntry)
{
#ifndef NO_XML
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        MrvDeleteAttributeInternal(pEntry);
    }
#endif
#endif
    return;
}

MrvXMLElement * MrvEnumElements(MrvXMLElement *pEntry, int *pnIndex)
{
#ifndef NO_XML
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return MrvEnumElementsInternal(pEntry, pnIndex);
    }
#endif
#endif
    return NULL;
}

void MrvDeleteRoot(MrvXMLElement * pElement)
{
#ifndef NO_XML
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        MrvDeleteRootInternal(pElement);
    }
#endif
#endif

    return;
}

MrvXMLElement * MrvFindElement(MrvXMLElement *pEntry, MRV_LPCTSTR lpszPath)
{
#ifndef NO_XML
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return MrvFindElementInternal(pEntry, lpszPath);
    }
#endif
#endif

    return NULL;
}

MrvXMLText *MrvFindOnlyText(MrvXMLElement * pEntry)
{
#ifndef NO_XML
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return MrvFindOnlyTextInternal(pEntry);
    }
#endif
#endif

    return NULL;
}

MrvXMLElement * MrvParseXML(MRV_LPCTSTR lpszXML, MrvXMLResults *pResults)
{
#ifndef NO_XML
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return MrvParseXMLInternal(lpszXML, pResults);
    }
#endif
#endif
    return NULL;
}

MrvXMLNode * MrvEnumNodes(MrvXMLElement *pEntry, int *pnIndex)
{
#ifndef NO_XML
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return MrvEnumNodesInternal(pEntry, pnIndex);
    }
#endif
#endif

    return NULL;
}

MrvXMLAttribute * MrvFindAttribute(MrvXMLElement *pEntry, MRV_LPCTSTR lpszAttrib)
{
#ifndef NO_XML
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return MrvFindAttributeInternal(pEntry, lpszAttrib);
    }
#endif
#endif

    return NULL;
}

/**
 *  @brief: This function initialize SDIO bus driver.
 *
 *  @return MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
int sdcard_init(void)
{
#ifndef CRANE_SD_NOT_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return sdcard_init_internal();
    }
#endif
#endif
    return 0;
}

#pragma arm section code="SDCARD_READY"
BOOL sdcard_is_ready(void)
{
#ifndef CRANE_SD_NOT_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return sdcard_is_ready_internal();
    }
#endif
#endif
    return FALSE;
}
#pragma arm section code

int eeSDDump_status_get(void)
{
#ifndef CRANE_SD_NOT_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return eeSDDump_status_get_internal();
    }
#endif
#endif

    return 0;
}

void eeSDDumpPrepare(void)
{
#ifndef CRANE_SD_NOT_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        eeSDDumpPrepareInternal();
    }
#endif
#endif

    return;
}

BOOL sdcard_transmit_status(void)
{
#ifndef CRANE_SD_NOT_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return sdcard_transmit_status_internal();
    }
#endif
#endif
    return FALSE;
}

UINT32 sdcard_get_blknum(void)
{
#ifndef CRANE_SD_NOT_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return SD_BLK_NUM;
    }
#endif
#endif

	return 0;
}


UINT32 sdcard_read_multiblks(UINT32 base, UINT32 buffer, UINT32 loop, UINT32 blk_cnt)
{
#ifndef CRANE_SD_NOT_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return sdcard_read_multiblks_internal(base, buffer, loop, blk_cnt);
    }
#endif
#endif
    return 0;
}

UINT32 sdcard_read_singleblk(UINT32 base, UINT32 buffer, UINT32 loop)
{
#ifndef CRANE_SD_NOT_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return sdcard_read_singleblk_internal(base, buffer, loop);
    }
#endif
#endif
    return 0;
}

UINT32 sdcard_write_multiblks(UINT32 base, UINT32 buffer, UINT32 loop, UINT32 blk_cnt)
{
#ifndef CRANE_SD_NOT_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return sdcard_write_multiblks_internal(base, buffer, loop, blk_cnt);
    }
#endif
#endif
    return 0;
}

UINT32 sdcard_write_singleblk(UINT32 base, UINT32 buffer, UINT32 loop)
{
#ifndef CRANE_SD_NOT_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return sdcard_write_singleblk_internal(base, buffer, loop);
    }
#endif
#endif
    return 0;
}

BOOL SDWork(void)
{
#ifndef CRANE_SD_NOT_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        if(TRUE == diagCommSdLogEnable())
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
#endif
#endif
    return FALSE;
}

void SulogSDMakeDir(void)
{
#ifndef CRANE_SD_NOT_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        SulogSDMakeDirInternal();
    }
#endif
#endif
    return;
}

int sdcard_fat_is_ok(void)
{
#ifndef CRANE_SD_NOT_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
        return sdcard_fat_is_ok_internal();
#endif
#endif
    return 0;
}


int is_ims_cid(int simid, int cid,char *apn)
{
#ifdef VOLTE_ENABLE
    extern int _is_ims_cid(int simid, int cid,char *apn);
#ifndef MIN_SYS
    if(!IsMiniSystem())
    {
        return _is_ims_cid(simid, cid,apn);
    }
#endif
#endif
    return 0;
}

int get_ims_at_channel(int sim_id)
{
#ifdef VOLTE_ENABLE
    extern int ims_get_at_channel(int sim_id);
#ifndef MIN_SYS
    if(!IsMiniSystem())
    {
        return ims_get_at_channel(sim_id);
    }
#endif
#endif
    return 0;
}
/*
void keypad_init(void)
{
#ifdef CRANE_KEYPAD_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        keypad_init_internal();
    }
#endif
#endif
}

int test_CameraPreview(void)
{
#ifdef CRANE_CAMERA_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return test_CameraPreviewInternal();
    }
#endif
#endif
    return 0;
}

int test_CameraRecord(void)
{
#ifdef CRANE_CAMERA_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return test_CameraRecordInternal();
    }
#endif
#endif
    return 0;
}

int test_CameraCaputre(void)
{
#ifdef CRANE_CAMERA_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return test_CameraCaputreInternal();
    }
#endif
#endif
    return 0;
}

void test_LcdShowImage(UINT8 *isSync)
{
#ifdef CRANE_LCD_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return test_LcdShowImageInternal(isSync);
    }
#endif
#endif
    return;

}

void test_Logo_LcdShowImage(void)
{
#ifdef CRANE_LCD_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return test_Logo_LcdShowImageInternal();
    }
#endif
#endif
    return;

}

void test_ASS_LCD_DisplayText(char * text, int len)
{
#ifdef CRANE_LCD_SUPPORT
#ifndef MIN_SYS

    if(!IsMiniSystem())
    {
        return test_ASS_LCD_DisplayTextInternal(text,len);
    }
#endif
#endif
    return;

}
*/

void initMESmsInfo(void)
{
#ifndef MIN_SYS
#ifndef REMOVE_SMS
    if(!IsMiniSystem())
    {
        _initMESmsInfo();
    }
#endif
#endif

    return;

}

void set_pp_for_test(void)
{
#ifndef MIN_SYS
    if(!IsMiniSystem()) {
        if (get_pp_flag())
           set_fix_pp(5);
    }
#endif       
}


#ifdef ADAPT_FRAMEWORK_BUILD
void setUartDevType(UART_DEV_TYPE type)
{

}

//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,UARTTOUART
void set_uart_dev_uart(void)
{
	//setUartDevType(UART_DEV_UART);
}

//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,UARTTODIAG
void set_uart_dev_diag(void)
{
	//setUartDevType(UART_DEV_DIAG);
}


BOOL is_uart_to_uart(void)
{
	//if(uart_output_dev==UART_DEV_UART)
		return TRUE;
	//else
	//	return FALSE;
}


BOOL getUSBConnectStatus(void)
{
    if(*(volatile unsigned long*)0xD428287C & 1 << 15)
        return TRUE;
    else
        return FALSE;
}


//ICAT EXPORTED FUNCTION - SW_PLAT,NVM,FDI_Factory_Reset
void FDI_Factory_Reset(void)
{
}
#define MAX_FILTER_FILE_NUM	4

#ifdef MMI_INTERFACE
const char filename_filter[MAX_FILTER_FILE_NUM][64]={"vdisk.bin",'\0','\0','\0'};
#else
const char filename_filter[MAX_FILTER_FILE_NUM][64]={'\0','\0','\0','\0'};
#endif



BOOL BacklightStatusBeforeSilentReset = FALSE; //Used to inform to UI whether the backlight was on before silent reset.


BOOL GetBacklightStatusBeforeReset(void)
{
    return BacklightStatusBeforeSilentReset;
}

void set_platform_version(char * version)
{
    return;
}

void __attribute__((weak)) set_sdcard_power_gpio(UINT8 num)
{
    return;
}



#endif

#if defined(NOT_SUPPORT_PM813)
#include "pmic_battery.h"
#include "ningbo.h"
#include "pmic_charger.h"

void Ningbo_PowerSave_Config(void)
{
    return;
}

int NingboRead( Ningbo_Reg_Type ningbo_reg_type, unsigned char reg, unsigned char *value )
{
    return 0;
}

int NingboWrite( Ningbo_Reg_Type ningbo_reg_type, unsigned char reg, unsigned char value )
{
    return 0;
}

void Ningbo_INT_CALLBACK_REGISTER(NINGBO_INTC intc, PmicCallback isr)
{
    return;
}

void Ningbo_INT_ENABLE(NINGBO_INTC intc)
{
    return;
}


void NingboKeypadBackLightDisable(void)
{
    return;
}

void NingboKeypadBackLightEnable(void)
{
    return;
}

void NingboLcdBackLightCtrl(UINT8 level) 
{
    return;
}


void NingboLcdBackLightDisable(void)
{
    return;
}


void NingboLcdBackLightEnable(void)
{
    return;
}


void NingboTorchBackLightCtrl(UINT8 level)
{
    return;
}


void NingboTorchLightDisable(void)
{
    return;
}


void NingboTorchLightEnable(void)
{
    return;
}


void NingboVibratorCtrl(UINT8 level)
{
    return;
}


void NingboVibratorDisable(void)
{
    return;
}

void NingboVibratorEnable(void)
{
    return;
}

void Ningbo_ENABLE_BATID_MEAS(void)
{
    return;
}

void Ningbo_ENABLE_BATTEMP_MEAS(void)
{
    return;
}

UINT32 Ningbo_Get_Meas_Factor(NINGBO_MEAS_EN meas_en)
{
    return 0;
}

int Ningbo_LDO_Set_Enable(unsigned char reg, unsigned char enable)
{
    return 0;
}

int Ningbo_LDO_Set_VOUT(unsigned char reg, unsigned char value)
{
    return 0;
}

void Ningbo_Ldo_11_set(BOOL OnOff)
{
    return;
}

void Ningbo_Ldo_11_set_1_2(void)
{
    return;
}

void Ningbo_Ldo_12_set(BOOL OnOff)
{
    return;
}

void Ningbo_Ldo_12_set_1_8(void)
{
    return;
}

void Ningbo_Ldo_12_set_2_8(void)
{
    return;
}


void Ningbo_Ldo_1_set(BOOL OnOff)
{
    return;
}

void Ningbo_Ldo_1_set_2_8(void)
{
    return;
}

BAT_STATUS PM812_BATTERY_STATUS()
{
    return 0;
}

void pm813_cc_current_set(CC_CHG_CURRENT value)
{
    return;
}

void pm813_cccv_timer_set(UINT8 value)
{
    return;
}

void pm813_charge_termination_current_set(UINT8 value)
{
    return;
}

BOOL pm813_charger_is_usb(void)
{
    return 0;
}

void pm813_charger_switch(BOOL OnOff)
{
    return;
}

void pm813_fault_clear(void)
{
    return;
}

UINT32 pm813_get_Icharge_meas_cur_mA(void)
{
    return 0;
}

UINT32 pm813_get_Vcharge_meas_vol_mv(void)
{
    return 0;
}

UINT32 pm813_get_batid_meas_vol_mv(void)
{
    return 0;
}

UINT32 pm813_get_battemp_meas_vol_mv(void)
{
    return 0;
}

BOOL pm813_get_battery_status(void)
{
    return 0;
}

UINT32 pm813_get_battery_voltage_withoutCharger(void)
{
    return 0;
}

CHGFSM_OUT pm813_get_charger_FSM_state(void)
{
    return 0;
}

BOOL pm813_if_charge_full(void)
{
    return 0;
}

BOOL pm813_if_charge_in_cv_mode(void)
{
    return 0;
}

BOOL pm813_keypadbacklight_status_get(void)
{
    return 0;
}

BOOL pm813_lcdbacklight_status_get(void)
{
    return 0;
}

BOOL pm813_measured_current_means_charging(void)
{
    return 0;
}

void pm813_precharge_current_set(UINT8 value)
{
    return;
}

void pm813_precharge_timer_set(UINT8 value)
{
    return;
}

BOOL pm813_set_max_cc_current(UINT32 limit)
{
    return 0;
}

BOOL pm813_torchlight_status_get(void)
{
    return 0;
}

void pm813_trickle_timer_set(UINT8 value)
{
    return;
}

void pm813_vbat_set(VBAT_VOLTAGE value)
{
    return;
}

BOOL pm813_vibrator_status_get(void)
{
    return 0;
}


void PM812_BATTERY_BIND_INTC(BatIntCallback callback)
{
    return;
}

void PM812_BATTERY_INTC_ENABLE(BOOL onoff)
{
    return;
}

void PM812_CHARGER_BIND_INTC(ChgIntCallback callback)
{
    return;
}

void PM812_CHARGER_INTC_ENABLE(BOOL onoff)
{
    return;
}

void PM812_ENABLE_BAT_DET(BOOL onoff)
{
    return;
}

void pm813s_mppt_restart(void)
{
    return;
}



#endif

#if defined(NOT_SUPPORT_PMIC_ONKEY)
#include "pmic.h"
#include "pmic_onkey.h"

void PM812_LONKEY_EN(LONGKEY_COUNT num,BOOL enable)
{
    return;
}

void PM812_LONKEY_PRESS_TIME_SET(UINT8 sec)
{
    return;
}
ONKEY_STATUS PM812_GET_ONKEY_STATUS(void)
{
    return 0;
}
void PM812_ONKEY_BIND_INTC(OnkeyIntCallback callback)
{
    return;
}
void PM812_ONKEY_INTC_ENABLE(BOOL onoff)
{
    return;
}

#endif


#ifdef GPS_SUPPORT
extern int asr_gnss_open(void *);
extern void asr_gps_clear_packinfo(void);
int asr_gnss_open_stub(void)
{
#ifndef MIN_SYS
		if(!IsMiniSystem()) {
            asr_gps_clear_packinfo();
			asr_gnss_open(NULL);
		}
#endif
	return 0;
}
extern unsigned char get_gps_pm_lock(void);
unsigned char get_gps_pm_lock_stub(void)
{
#ifndef MIN_SYS
    if(!IsMiniSystem())
    {
        return get_gps_pm_lock();
    }
#endif
    return 0;
}
#endif
#ifndef NTP
int GetNTPStatus(void) //return 1 if there is platform ntp success
{
	return 0;
}
#endif

#ifndef CSDAPI_SUPPORT
VgFifo8 vgDataStackDsFifo;
VgFifo8 vgDsDataStackFifo;

void CsdQueryTestStatus(void)
{
    return;
}

void CsdTurnOffTest(void)
{
    return;
}

void CsdTurnOnTest(void)
{
    return;
}

void vgRlpSetRlpInitiateXidNeg(BOOL val)
{
    return;
}

void VgRtfdpTask (void)
{
    return;
}

void VgUfdpTask (void)
{
    return;
}
#endif

#ifdef MV_USB2_NO_USBNET
void Rndis_eh_indicate_disconnect_msg(void)
{
	return;
}

void EcmParamInit(void)
{
	return;
}
void Ecm_getstrECMMACADDR(UINT8 * strMac, UINT32 len)
{
	return;
}

int mvUsbGetTxNetQCnt(void)
{
	return 0;
}

void mvUsbNetIndicateStatus(BOOL connected)
{
	return;
}

void mvUsbNetSendPacket(UINT8* data, UINT32 len)
{
	return;
}


#endif

#if defined(NOT_SUPPORT_PM803)
#include "guilin_lite.h"

void GuilinLite_Ldo_3_set(BOOL OnOff)
{
    return;
}
void GuilinLite_Ldo_3_set_1_8(void)
{
    return;
}
void GuilinLite_Ldo_3_set_3_0(void)
{
    return;
}

void GuilinLite_Ldo_8_set(BOOL OnOff)
{
    return;
}
void GuilinLite_Ldo_8_set_1_8(void)
{
    return;
}

void GuilinLite_Ldo_8_set_3_0(void)
{
    return;
}

void GuilinLite_PowerSave_Config(void)
{
    return;
}


#endif

#if defined(NOT_SUPPORT_PM802)
#include "guilin.h"

void Guilin_Ldo_3_set(BOOL OnOff)
{
    return;
}

void Guilin_Ldo_3_set_1_8(void)
{
    return;
}   
void Guilin_Ldo_3_set_3_0(void)
{
    return;
}   
void Guilin_Ldo_4_set(BOOL OnOff) 
{
    return;
}

void Guilin_Ldo_4_set_1_8(void)
{
    return;
}

void Guilin_Ldo_4_set_3_0(void)
{
    return;
}

void Guilin_PowerSave_Config(void)
{

}


#endif

#if defined(NOT_SUPPORT_PM803L)
#include "guilin_lite2.h"

void GuilinLite2_Ldo_3_set(BOOL OnOff)
{
    return;
}

void GuilinLite2_Ldo_3_set_3_0(void)
{
    return;
}

void GuilinLite2_Ldo_3_set_1_8(void)
{
    return;
}

void GuilinLite2_PowerSave_Config(void)
{
    return;
}


#endif

#ifndef LZMA_SUPPORT
unsigned int LzmaUncompressLen(const unsigned char *src)
{
    unsigned int len = 0;
    int ii = 0;
    unsigned char *temp = NULL;

    temp = (unsigned char *)src + 5;
    for (ii = 0; ii < 4; ii++)
    {
        unsigned char b;
        b = *temp;
        temp++;
        len += (unsigned int)(b) << (ii * 8);
    }
    return len;
}
#endif
#endif
