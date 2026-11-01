/*--------------------------------------------------------------------------------------------------------------------
(C) Copyright 2011 Marvell DSPC Ltd. All Rights Reserved.
-------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
INTEL CONFIDENTIAL
Copyright 2011 Marvell All Rights Reserved.
The source code contained or described herein and all documents related to the source code (“Material? are owned
by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intel’s prior express written permission.

No license under any patent, copyright, trade secret or other intellectual property right is granted to or
conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
Intel in writing.
-------------------------------------------------------------------------------------------------------------------*/

/*********************************************************************
*                      M O D U L E     B O D Y                       *
**********************************************************************
* Title: USBNET                                                       *
*                                                                    *
* Filename: usb_net.h                                        *
*                                                                    *
* Target, platform: Common Platform, SW platform                     *
*                                                                    *
* Authors:                                                           *
*                                                                    *
* Description:   
*                                                                    *
* Notes:                                                             *
*                                                                    *
*                                                                    *
*                                                                    *
*                                                                    *
************** General include definitions ***************************/

#ifndef USB_NET_H
#define USB_NET_H
typedef void (*UsbNetRxDoneCallbackFunc)(void *rxPtr, UINT32 length);

UINT32  usb_net_init(UsbNetRxDoneCallbackFunc Func);

UINT32  usb_net_rx(void *rxPtr, UINT32 maxSize);
UINT32 usb_net_rx_enable(UINT8 *rxPtr, UINT32 maxSize);

UINT32  usb_net_tx(UINT32 *txPtr, UINT32 length);

/*the following function is only used by platform driver*/
void usb_net_rx_done(void *rxPtr, UINT32 length);
void usb_net_tx_done(void);

void usbnet_putmem(const unsigned char* data_ptr);
UINT8* usbnet_allocmem(UINT32 size, UINT32 cid, UINT8 newblock);
void usbnet_downlink(const unsigned char* data_ptr, size_t size);
void usbnet_tx_done(void);

#define IP_NET_BUFF

#define IPNET_BLOCK_SIZE	(16 * 1024)
#define IPNET_BLOCK_NM		5



#endif

