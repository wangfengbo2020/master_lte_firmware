/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/

#ifndef __QL_USB_HID_H__
#define __QL_USB_HID_H__


typedef enum 
{
	QL_USB_HID_DEV_KEYBOARD = 0,
	QL_USB_HID_DEV_CUST_HID,
	QL_USB_HID_DEV_MAX,
	
}QL_USB_HID_DEV_ENUM;


typedef void (*ql_uhid_revc_cb)(unsigned char* buf, unsigned char len);
typedef int (*ql_uhid_send)(unsigned char* buf, unsigned char len);

typedef enum
{
    USB_DEVICE_RC_OK = 1,
    USB_DEVICE_RC_ERROR = -100,
    USB_DEVICE_RC_NOT_CONNECTED,
    USB_DEVICE_RC_ENDPOINT_IN_USE,
    USB_DEVICE_RC_ENDPOINT_NOT_OPENED,
    USB_DEVICE_RC_ENDPOINT_BUSY,
    USB_DEVICE_RC_ENDPOINT_STALLED,
    USB_DEVICE_RC_ENDPOINT_NOT_IN_CONFIG,
    USB_DEVICE_RC_TRANSFER_ABORTED,
    USB_DEVICE_RC_OPEN_ERROR,
    USB_DEVICE_RC_BUFFER_ERROR,
    USB_DEVICE_RC_DMA_ERROR
}USBCDevice_ReturnCodeE;


typedef struct
{
	char id;
	char name[20];
	ql_uhid_send send;
	ql_uhid_revc_cb recv_cb;
	
}ql_uhid_dev;

/*****************************************************************
* Function: ql_usb_hid_get_device
*
* Description:
* 	获取USB HID 接口设备 
* 
* Parameters:
* 	id				HID 接口设备ID
* Return:
* 	ql_uhid_dev*	HID接口设备
*
*****************************************************************/
ql_uhid_dev* ql_usb_hid_get_device(char id);

/*****************************************************************
* Function: ql_usb_hid_send_data
*
* Description:
* 	获取USB的类型。 
* 
* Parameters:
* 	dev				HID接口设备
*	buf				发送内容
*	len				发送长度
* Return:
* 	-1				发送异常
*	0				发送正常
*
*****************************************************************/
int ql_usb_hid_send_data(ql_uhid_dev* dev, char *buf, unsigned char len);

/*****************************************************************
* Function: ql_usb_get_type
*
* Description:
* 	获取USB的类型。 
* 
* Parameters:
* 	dev				HID接口设备
*	cb				接收内容回调接口
* Return:
* 	-1				未能正常设置
*	0				正常设置
*
*****************************************************************/
int ql_usb_hid_recv_set_cb(ql_uhid_dev* dev, ql_uhid_revc_cb cb);

/*****************************************************************
* Function: ql_usb_device_get_hid_dtd_cnt
*
* Description:
* 	获取对应ep上dtd数量。 
* 
* Parameters:
* 	dev_id			要获取dtd数的端点
*	
* Return:
* 	-1				dev_id异常
*	非负值				dtd值
*
*****************************************************************/
char ql_usb_device_get_hid_dtd_cnt(char dev_id);

/*****************************************************************
* Function: ql_usb_device_free_hid_dtd
*
* Description:
* 	释放对应ep上dtd。 
* 
* Parameters:
* 	dev_id			要释放dtd的端点
*	
* Return:
* 	-1				dev_id异常
*	0				正常释放
*
*****************************************************************/
char ql_usb_device_free_hid_dtd(char dev_id);


#endif

