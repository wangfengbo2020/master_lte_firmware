/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

#ifndef _USB2_DEVICE_H_
#define _USB2_DEVICE_H_

#include "usb_cable.h"


USBCDevice_ReturnCodeE USB2DeviceEndpointReceive(USBDevice_EndpointE endpoint, UINT8 *pRxBuffer, UINT32 length, BOOL expect_zlp);
void USB2DeviceVendorClassResponse(UINT8 *pBuffer, UINT16  bufferLength);
USBCDevice_ReturnCodeE USB2DeviceEndpointTransmit(USBDevice_EndpointE endpoint,  UINT8 *pTxBuffer, UINT32 txLength, BOOL autoZLP);
USBCDevice_ReturnCodeE USB2DeviceEndpointMultiTransmit(USBDevice_EndpointE endpoint, UINT32 numOfBuffers, USBDevice_MultiTransmitListS *multiList);
USBCDevice_ReturnCodeE USB2DeviceEndpointReceiveCompleted(USBDevice_EndpointE  endpoint);
USBCDevice_ReturnCodeE USB2DeviceEndpointReceiveCompletedExt(USBDevice_EndpointE   endpoint, UINT8  *pRxBuffer,UINT32 next_packet_expected_length,BOOL expect_zlp);
USBCDevice_ReturnCodeE USB2DeviceEndpointClose(USBDevice_EndpointE endpoint);
USBCDevice_ReturnCodeE USB2DeviceEndpointOpen(USBDevice_EndpointE  endpoint, USBDevice_UsageTypeE usageType, UINT8  dmaChannel, UINT8 *pBuffer, UINT16  bufferLength, USBDeviceTransactionCompletedNotifyFn  transactionCompletedNotifyFn);

USBCDevice_ReturnCodeE USB2DeviceEndpointAbort(USBDevice_EndpointE endpoint);
USBCDevice_ReturnCodeE  USB2DeviceEndpointStall(USBDevice_EndpointE endpoint);
void USB2DeviceCableDetectionNotify(USBCable_StatusE cableStatus);

BOOL USB2DeviceIsControllerEnabled (void);

void USB2DevicePhase1Init(void);
BOOL USB2DevicePhase2Init(void);
void hsic_poll_tx_done(UINT8 direction, UINT8* buffer, UINT32 length);
void hsic_poll_rx_done(UINT8 direction, UINT8* buffer, UINT32 length);
void usbDeviceEndpoint_init(void);
#endif /*_USB2_DEVICE_H_*/

