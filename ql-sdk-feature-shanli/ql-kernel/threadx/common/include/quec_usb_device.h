/**  @file
  quec_usb_device.h

  @brief
  This file is used to define the definition of usb device for different Quectel Project.

*/

/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/
/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
11/16/2018        Chaim      add usb vid pid net_type
11/07/2018        Jensen     Init version
=================================================================*/
	
	
#ifndef _QUEC_USB_DEVICE_H
#define _QUEC_USB_DEVICE_H

#include "quec_common.h"
#include "quec_driver_common.h"
#include "diag_nvm.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined QUEC_USB_DEVICE_ENBALE

#define QUEC_USB_DEVICE_LOG_ENABLE


//read and write usb_pid_vid at mrd partition
typedef struct
{
    uint16 vid;
    uint16 pid;
}quec_usb_vid_pid_s;

#define QUEC_USB_MANUFACTURER_NVM    "usb_manufacturer_name"
#define MANUFACTURER_NAME_MAX_LEN 	 50

typedef struct
{
	char imanufacturer[MANUFACTURER_NAME_MAX_LEN/2];
	char iporduct[MANUFACTURER_NAME_MAX_LEN/2];
	
} quec_UsbManuInfo_S;

//usb vid pid name at mrd partition
#define QUEC_USB_VID_PID_NAME_MRD    "usb_vid_pid.bin"

#define QUEC_USB_VERSION_NVM         "usb_version"

/*-----------------------------------------------------------------------------------------
 * Function: Get usb vid from RAM.
 *
 * Parameter:
 *    <pid>: 	[IN] assignment the pid value to the pointer data.
 * 
 * Return:
 *    TRUE: the input parameter is not a null pointer.
 *    FALSE the input parameter is not a null pointer.
-----------------------------------------------------------------------------------------*/
extern BOOL quec_get_usb_device_vid(UINT16 *vid);


/*-----------------------------------------------------------------------------------------
 * Function: Get usb pid from RAM.
 *
 * Parameter:
 *    <pid>: 	[IN] assignment the pid value to the pointer data.
 * 
 * Return:
 *    TRUE: the input parameter is not a null pointer.
 *    FALSE the input parameter is not a null pointer.
-----------------------------------------------------------------------------------------*/
extern BOOL quec_get_usb_device_pid(UINT16 *pid);

/*-----------------------------------------------------------------------------------------
 * Function: set the usb vid and vid,save both to mrd partition.
 *
 * Parameter:
 *    <vid>: 	[IN] the vid value to set and save.
 *    <pid>: 	[IN] the pid value to set and save.
 * 
 * Return:
 *    QUEC_SUCCESS: set ram vid_pid success and save  success.
 *    kGeneralErr : set ram vid_pid or save fail.
-----------------------------------------------------------------------------------------*/
extern QuecOSStatus quec_set_usb_vid_pid(uint32 vid, uint32 pid);


/*-----------------------------------------------------------------------------------------
 * Function: quectel switch usb net type after systm init.
 *
 * Parameter:
 *    NONE.
 * 
 * Return:
 *    QUEC_SUCCESS: read net type at fat  and switch to it success
 *    kGeneralErr : read net type fail.
-----------------------------------------------------------------------------------------*/
extern QuecOSStatus quec_usb_net_type_init(void);

/*-----------------------------------------------------------------------------------------
 * Function: in asr usb init calling the function to read usb net type from fat and modify default usb config.
 *
 * Parameter:
 *    NONE.
 * 
 * Return:
 *    QUEC_SUCCESS: read net type at fat and the value is ok.
 *    kGeneralErr : read net type fail or the value is error.
-----------------------------------------------------------------------------------------*/
extern QuecOSStatus quec_asr_set_usb_net_type_init(void);

/*-----------------------------------------------------------------------------------------
 * Function: get usb net type.
 *
 * Parameter:
 *    <pusb_type>: 	[OUT] the pointer to get usb net type.
 * 
 * Return:
 *    QUEC_SUCCESS: get the usb net type is ok.
 *    kGeneralErr : get the usb net type is fail.
-----------------------------------------------------------------------------------------*/
extern QuecOSStatus quec_get_usb_net_type(quec_usb_net_type_e *pusb_type);

/*-----------------------------------------------------------------------------------------
 * Function: change usb net type.
 *
 * Parameter:
 *    <set_type>: 	[IN] change to the net type.
 * 
 * Return:
 *    QUEC_SUCCESS: the set_type value is ok and change success.
 *    kGeneralErr : change to the net type fail.
-----------------------------------------------------------------------------------------*/
extern QuecOSStatus quec_change_usb_net_type(quec_usb_net_type_e set_type);


/*-----------------------------------------------------------------------------------------
 * Function: save usb net type.
 *
 * Parameter:
 *    <save_type>: 	[IN]  the net type to save at fat.
 * 
 * Return:
 *    QUEC_SUCCESS: the save_type value is save success.
 *    kGeneralErr : the save_type value is save fail.
-----------------------------------------------------------------------------------------*/
extern QuecOSStatus quec_save_usb_net_type_fat(quec_usb_net_type_e save_type);


/*-----------------------------------------------------------------------------------------
 * Function:   usb vid pid init at start.
 *
 * Parameter:
 *    NONE.
 * 
 * Return:
 *    NONE
-----------------------------------------------------------------------------------------*/
extern void quec_usb_vid_pid_init(void);

extern uint8 quec_get_usbinfo_uart_debug_log(void);
extern QuecOSStatus quec_read_usbinfo_uart_debug_log(void);
extern QuecOSStatus quec_set_usbinfo_uart_debug_log(uint8 usbinfo_log_value);
#ifdef QUEC_USB_AUTO_SUPPORT
extern QuecOSStatus quec_save_usb_auto_fat(Usb_OS_detect_type os_detect);
extern QuecOSStatus quec_read_usb_net_auto(void);
#endif

extern BOOL quec_read_manufacturer_info(void);
extern BOOL quec_save_usb_manufacturer(const char* manu_sour,UINT8 len);
extern BOOL quec_save_usb_product(const char* prod_sour,UINT8 len);
extern int 	copyStrToUtf16(char *dst, char*src, int sizeOfStr);
extern BOOL quec_getUsbDescStrUTF16(const char* input, UINT16 input_size, char* out_buf, UINT16 out_buf_size);
extern void quec_usb_manufacturer_init(void);

extern BOOL quec_read_usb_version_is20(void);
extern BOOL quec_save_usb_version(UINT8 set_version);
extern void quec_usbversion_init(void);
#endif

#ifdef __cplusplus
} /*"C" */
#endif

#endif

