/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*******************************************************************************
 *                      M O D U L E     B O D Y
 *******************************************************************************
 *  COPYRIGHT (C) 2003, 2004 Intel Corporation.
 *
 *  This software as well as the software described in it is furnished under
 *  license and may only be used or copied in accordance with the terms of the
 *  license. The information in this file is furnished for informational use
 *  only, is subject to change without notice, and should not be construed as
 *  a commitment by Intel Corporation. Intel Corporation assumes no
 *  responsibility or liability for any errors or inaccuracies that may appear
 *  in this document or any software that may be provided in association with
 *  this document.
 *  Except as permitted by such license, no part of this document may be
 *  reproduced, stored in a retrieval system, or transmitted in any form or by
 *  any means without the express written consent of Intel Corporation.
 *
 *******************************************************************************
 *
 * Title:        USB DEVICE - USB Device API header file
 *
 * Filename:     usb_device_types.h
 *
 * Author:       Yossi Gabay
 *
 * Description:  This file contains structures/enums/types that needed by
 *               the USB Device module
 *
 * Notes:
 ******************************************************************************/

#if !defined(_USB_DEVICE_TYPES_H_)
#define      _USB_DEVICE_TYPES_H_

//#include "global_types.h"
#include "usb_device.h"

#include "udc_driver.h"
#include "udc_hw.h"

/*******************************************************************************
 *                      T Y P E S
 ******************************************************************************/

/* Usb Net maxmium queue count  */
#define  USBNREQ_MSG_Q_MAX	                            48

/* Usb Net request queue size */
#define  USBNREQ_MSG_Q_SIZE	                            4

//#ifdef MV_USB_MBIM
/* Usb Net request task stack size */
#define  USBNREQ_TASK_STACK_SIZE                        1024*8
//#else
//#define  USBNREQ_TASK_STACK_SIZE                        1024
//#endif
/* Usb Net request task priority */
#define  USBNREQ_TASK_PRIORITY                          68

/* Usb Net indicate message length */
#define  USBNET_IND_LEN                                 4

/* Usb Net indicate message ID */
#define  USBNET_IND_ID                                  0xBABEFC00

/* Usb Net message ID */
#define  USBNET_REQ_MSG_ID                              0xBEDBEDBB

/* Usb Net response queue ID */
#define  USBNET_QUEQUE_ID                               0xABBACDDC

/* Usb Net response queue guard */
#define  USBNET_QUEQUE_GUARD                            0x68686868

/* Usb Net response unlink ID */
#define  USBNET_QUNLINK_ID                              0xABBA0000

/* Usb Net response unlink guard */
#define  USBNET_QUNLINK_GUARD                           0x68680000

/*Non-setup data Req reserve flag */
#define REQ_RCV_COMM_FEATURE_DATA		                0xABCD0001
#define REQ_RCV_LINE_CODING_DATA                        0xABCD0002
#define REQ_RCV_ENCAPSULATED_DATA                       0xABCD0003
#define REQ_RCV_BOT_MSC_RESET_DATA                      0xABCD0004

/* Usb Net packet msg reserve flag */
#define USBNET_PACKET_MSG_DATA		                    0xABCD0005

/* Usb Net Req msg reserve flag */
#define USBNET_RNDIS_REQ_MSG		                    0xABCD0006
#define USBNET_MBIM_REQ_MSG		                        0xABCD0007
#define USBNET_ECM_REQ_MSG	                            0xABCD0008

/* Usb Net Rsp msg reserve flag */
#define USBNET_RNDIS_RSP_MSG		                    0xABCD0009
#define USBNET_MBIM_RSP_MSG                             0xABCD000A

/* Usb Net IND msg reserve flag */
#define USBNET_RNDIS_IND_MSG		                    0xABCD000B
#define USBNET_RNDIS_EEH_IND_MSG		                0xABCD000C

#ifdef CRANE_MCU_DONGLE
#define USB_DEVICE_TOTAL_STRINGS                        (17)
#else
#define USB_DEVICE_TOTAL_STRINGS                        (5)
#endif

/* Usb net request message */
typedef struct mvUsbNetQ
{
	UINT32  id;
	UINT8  *data;
	UINT32  len;
    struct mvUsbNetQ *next;
    struct mvUsbNetQ *prev;
    int     cnt;
    UINT32  resv;
    UINT32  guard;
} mvUsbNetQ;

/*typedef enum
{
    USB_DEVICE_TRANSFER_STATE_NOT_BUSY = 0,
    USB_DEVICE_TRANSFER_STATE_TX_STARTED,
    USB_DEVICE_TRANSFER_STATE_MULTI_TX_STARTED,
    USB_DEVICE_TRANSFER_STATE_RX_STARTED,
    USB_DEVICE_TRANSFER_STATE_RX_COMPLETED,
    USB_DEVICE_TRANSFER_STATE_ABORTED
}USBDevice_TransferStateE;*/

/* Device status */
typedef enum
{
    USB_DEVICE_ST_CHANGE_CABLE_OUT = 0,
    USB_DEVICE_ST_CHANGE_CABLE_IN,
    USB_DEVICE_ST_CHANGE_RESET,
    USB_DEVICE_ST_CHANGE_GET_DEVICE_DESC,
    USB_DEVICE_ST_CHANGE_SET_CONFIGURATION,
    USB_DEVICE_ST_CHANGE_SUSPEND,
    USB_DEVICE_ST_CHANGE_RESUME,
    USB_DEVICE_ST_CHANGE_CONFIG_CHANGE
}USBDevice_StatusChangeE;


typedef enum
{
    USB_DEVICE_EP0_STATE_IDLE = 0,
    USB_DEVICE_EP0_STATE_SETUP,
    USB_DEVICE_EP0_STATE_DATA_OUT,     /* RX */
    USB_DEVICE_EP0_STATE_DATA_IN,      /* RT */
    USB_DEVICE_EP0_STATE_DATA_END,     /* Transaction ends */
#ifdef CRANE_MCU_DONGLE
    USB_DEVICE_EP0_SET_COMM_FEA,
    USB_DEVICE_EP0_SET_LINE_CODE,
#endif
    USB_DEVICE_EP0_STATE_STATUS
}USBDevice_EP0StateE;

typedef enum
{
    USB_DEVICE_EP0_NO_OPERATION = 0,
    USB_DEVICE_EP0_RECEIVED_SETUP_PACKET,
    USB_DEVICE_EP0_RECEIVED_DATA_PACKET,
    USB_DEVICE_EP0_RECEIVED_LAST_DATA_PACKET,
    USB_DEVICE_EP0_RECEIVED_GET_DESCRIPTOR_PACKET,
    USB_DEVICE_EP0_TRANSMITTED_DATA_PACKET,
    USB_DEVICE_EP0_TRANSMITTED_LAST_DATA_PACKET,
    USB_DEVICE_EP0_TRANSMITTED_LAST_DATA_PACKET_NOTIFY
}USBDevice_EP0OperationE;



typedef enum
{
    USB_DEVICE_EP_BUFFER_EMPTY_STATE,
    USB_DEVICE_EP_SHORT_PACKET_LOADED_STATE,
    USB_DEVICE_EP_FULL_PACKET_LOADED_STATE,
    USB_DEVICE_EP_PACKET_TRANSMITTED
}USBDevice_EPBufferStateE;
typedef volatile struct
{
    UINT8               *pDeviceDescriptor;
    UINT8               deviceDescriptorLength;
    UINT8               *pConfigDescriptor;
#ifdef CRANE_MCU_DONGLE
    UINT16               configDescriptorLength;
#else
    UINT8               configDescriptorLength;
#endif
	UINT8				*pQualifDescriptor;
	UINT8				qualifDescriptorLength;
	UINT8				*pOtherSpeedDescriptor;
	UINT8				otherSpeedDescriptorLength;
    UINT8               *pStringDescriptor[USB_DEVICE_TOTAL_STRINGS];
    UINT8               stringDescriptorTotal;
}USBDevice_DescriptorsS;

typedef volatile struct
{
    BOOL                                    endpointOpen;
    BOOL                                    endpointBusy;
    UDC_EndpointE                           udcEndpoint;
    //YG - currently not in use: USBDevice_TransferStateE                transferState;//YG abortTransfer - can be used instead of Busy !!!;
    USBDeviceTransactionCompletedNotifyFn   transactionCompletedNotifyFn;

/* USB2.0 Additions Begin */
   UINT8*                                   pRxBuffer;                // points to rx buffer    - relevent for rx endpoint only
   UINT32                                   pRxBuffSize;              // rx buffer size         - relevent for rx endpoint only
   BOOL                                     zlp;                      // indicates wether ZLP is needed when tansaction size = max packet size
/* USB2.0 Additions End */
}USBDevice_EndpointDataS;

typedef struct
{
    USBDevice_EP0StateE                     state;
    USBDevice_EP0OperationE                 operation;
    BOOL                                    isTransmitNeedNotify;
    UINT8                                   *ctrl_setup_buff;

    //dbg statistics
    UINT16                                    crtl_trasnfers_cnt; //for statistics
    UINT16                                    ep0_int_cnt;
    UINT16                                    ep0_IN_cnt;
    UINT16                                    ep0_OUT_cnt;

    //for data OUT stage in Control Transfer
    UINT8                                   *ctrl_out_data_stage_buff;//to store data received from host during data stage of control transfer
    UINT16                                  ctrl_out_data_stage_total_length; // total length if OUT t-fer
    UINT16                                  ctrl_out_data_stage_current_length; // total length if OUT t-fer

    //for data IN stage in Control Transfer
    UINT8                                   *ctrl_in_data_stage_buff;//to store data sent by device during data stage of control transfer
    UINT16                                  ctrl_in_data_stage_total_length; // total length if IN t-fer
    UINT16                                  ctrl_in_data_stage_current_length; // total length if IN t-fer
}USBDevice_EP0DataS;


typedef volatile struct
{
    USBDevice_StatusE						status;
    USBDevice_EP0DataS                      ep0;
    USBDeviceStatusNotifyFn                 statusNotifyFn;
    USBDeviceVendorClassRequestNotifyFn     vendorClassRequestNotifyFn;
    USBDeviceEndpointZeroNotifyFn           endpointZeroNotifyFn;
}USBDevice_DatabaseS;

#if defined(USB_DEVICE_DEBUG)
#endif /*USB_DEVICE_DEBUG*/


/*******************************************************************************
 *                      G L O B A L S
 ******************************************************************************/
#if defined(_USB_DEVICE_TYPES_)
    #define EXTRN
#else
    #define EXTRN      extern
#endif /*_USB_DEVICE_TYPES_*/


EXTRN   USBDevice_DescriptorsS      _usbDeviceDescriptors;
EXTRN   USBDevice_DatabaseS         _usbDeviceDatabase;
EXTRN   USBDevice_EndpointDataS     _usbDeviceEndpoint[USB_DEVICE_TOTAL_ENDPOINTS];

#undef EXTRN

#if defined  MV_USB_TRACE_PRINT
void UsbDeviceSetupUARTforDebug(void);
#endif

#endif /*_USB_DEVICE_TYPES_H_*/
