#ifndef __mvUsbCh9_h__
#define __mvUsbCh9_h__
/*******************************************************************************
** File          : $HeadURL$
** Author        : $Author$
** Project       : HSCTRL
** Instances     :
** Creation date :
********************************************************************************
********************************************************************************
** ChipIdea Microelectronica - IPCS
** TECMAIA, Rua Eng. Frederico Ulrich, n 2650
** 4470-920 MOREIRA MAIA
** Portugal
** Tel: +351 229471010
** Fax: +351 229471011
** e_mail: chipidea.com
********************************************************************************
** ISO 9001:2000 - Certified Company
** (C) 2005 Copyright Chipidea(R)
** Chipidea(R) - Microelectronica, S.A. reserves the right to make changes to
** the information contained herein without notice. No liability shall be
** incurred as a result of its use or application.
********************************************************************************
** Modification history:
** $Date$
** $Revision$
*******************************************************************************
*** Description:
***   This file contains definitions for standard device requests,
***
**************************************************************************
**END*********************************************************/

#include "udc2_hw.h"
/*----------------------------------------------------------------**
** Chapter 9.4 Standard Device Requests -- all devices            **
** See Table 9-3 p. 250 of USB 2.0 spec for combinations          **
**   of request type bitfields with requests, WVALUE, WINDEX etc. **
**----------------------------------------------------------------*/
#define REQ_RECIP_MASK          0x1f
#define REQ_RECIP_DEVICE        0x00
#define REQ_RECIP_INTERFACE     0x01
#define REQ_RECIP_ENDPOINT      0x02
#define REQ_RECIP_OTHER         0x03

/* Also for class requests set the following bit */
#define REQ_TYPE_OFFSET         5
#define REQ_TYPE_MASK			(0x03 << 5)
#define REQ_TYPE_STANDARD		(0x00 << 5)
#define REQ_TYPE_CLASS			(0x01 << 5)
#define REQ_TYPE_VENDOR			(0x02 << 5)
#define REQ_TYPE_RESERVED		(0x03 << 5)

/* Combine one of the 3 above with one of the following 2 */
#define REQ_DIR_OFFSET         7
#define REQ_DIR_IN             (1 << REQ_DIR_OFFSET)
#define REQ_DIR_OUT            (0 << REQ_DIR_OFFSET)

/* Standard USB requests, see Chapter 9 */
#define REQ_GET_STATUS          0
#define REQ_CLEAR_FEATURE       1
#define REQ_SET_FEATURE         3
#define REQ_SET_ADDRESS         5
#define REQ_GET_DESCRIPTOR      6
#define REQ_SET_DESCRIPTOR      7
#define REQ_GET_CONFIGURATION   8
#define REQ_SET_CONFIGURATION   9
#define REQ_GET_INTERFACE       10
#define REQ_SET_INTERFACE       11
#define REQ_SYNCH_FRAME         12

#define DESC_TYPE_OFFSET         16
#define DESC_TYPE_MASK           0xFF
#define DESC_TYPE_DEVICE         0x01
#define DESC_TYPE_CONFIG         0x02
#define DESC_TYPE_STRING         0x03
#define DESC_TYPE_INTERFACE      0x04
#define DESC_TYPE_ENDPOINT       0x05
#define DESC_TYPE_QUALIFIER      0x06
#define DESC_TYPE_OTHER_SPEED    0x07
#define DESC_TYPE_INTF_POWER     0x08
#define DESC_TYPE_OTG            0x09


/*******************************************************************
**
** Values specific to CLEAR FEATURE commands (must go to common.h later)
*/

#define  ENDPOINT_HALT          0
#define  DEVICE_SELF_POWERED    0
#define  DEVICE_REMOTE_WAKEUP   1
#define  DEVICE_TEST_MODE       2


/* States of device instances on the device list */

/* initial device state */
#define  DEVSTATE_INITIAL        0x00

/* device descriptor [0..7]*/
#define  DEVSTATE_DEVDESC8       0x01

/* address set */
#define  DEVSTATE_ADDR_SET       0x02

/* full device descriptor */
#define  DEVSTATE_DEV_DESC       0x03

/* config descriptor [0..7] */
#define  DEVSTATE_GET_CFG9       0x04

/* config set */
#define  DEVSTATE_SET_CFG        0x05

/* full config desc. read in */
#define  DEVSTATE_CFG_READ       0x06

/* application callbacks */
#define  DEVSTATE_APP_CALL       0x07

/* Select interface done */
#define  DEVSTATE_SET_INTF       0x08

#define  DEVSTATE_ENUM_OK        0x09

#define  DEVSTATE_CHK_OTG        0x0A

/* Event codes for attach/detach etc. callback */
#define  USB_ATTACH_EVENT        1   /* device attach */
#define  USB_DETACH_EVENT        2   /* device detach */
#define  USB_CONFIG_EVENT        3   /* device reconfigured */
#define  USB_INTF_EVENT          4   /* device interface selected */

/*Class Req*/
#define REQ_SET_COMM_FEATURE							0x02
#define REQ_GET_COMM_FEATURE							0x03
#define REQ_CLEAR_COMM_FEATURE						    0x04
#define REQ_SET_AUX_LINE_STATE						    0x10
#define REQ_SET_HOOK_STATE								0x11
#define REQ_PULSE_SETUP							        0x12
#define REQ_SEND_PULSE						            0x13
#define REQ_SET_PULSE_TIME								0x14
#define REQ_RING_AUX_JACK				                0x15
#define REQ_SET_LINE_CODING								0x20
#define REQ_GET_LINE_CODING								0x21
#define REQ_SET_CONTROL_LINE_STATE				        0x22
#define REQ_SEND_BREAK						            0x23
#define REQ_SET_RINGER_PARMS							0x30
#define REQ_GET_RINGER_PARMS							0x31
#define REQ_SET_OPERATION_PARMS						    0x32
#define REQ_GET_OPERATION_PARMS						    0x33
#define REQ_SET_LINE_PARMS								0x34
#define REQ_GET_MAX_LUN								    0xfe
#define REQ_BOT_MSC_RESET								0xFF

/*Class Req                             */
#define REQ_SEND_ENCAPSULATED_COMMAND                   0x00
#define REQ_GET_ENCAPSULATED_RESPONSE                   0x01
#define REQ_SET_COMM_FEATURE				            0x02
#define REQ_GET_COMM_FEATURE				            0x03
#define REQ_CLEAR_COMM_FEATURE				            0x04
#define REQ_CLASS_SPECIFIC_RESERVED_5		            0x05
#define REQ_SET_AUX_LINE_STATE				            0x10
#define REQ_SET_HOOK_STATE					            0x11
#define REQ_PULSE_SETUP						            0x12
#define REQ_SEND_PULSE						            0x13
#define REQ_SET_PULSE_TIME					            0x14
#define REQ_RING_AUX_JACK					            0x15
#define REQ_SET_LINE_CODING					            0x20
#define REQ_GET_LINE_CODING					            0x21
#define REQ_SET_CONTROL_LINE_STATE			            0x22
#define REQ_SEND_BREAK						            0x23
#define REQ_SET_RINGER_PARMS				            0x30
#define REQ_GET_RINGER_PARMS				            0x31
#define REQ_SET_OPERATION_PARMS				            0x32
#define REQ_GET_OPERATION_PARMS				            0x33
#define REQ_SET_LINE_PARMS					            0x34
#define REQ_GET_MAX_LUN						            0xfe

/* Class-Specific Control Requests (6.2) */
#define REQ_SET_ETHERNET_MULTICAST_FILTERS	            0x40
#define REQ_SET_ETHERNET_PM_PATTERN_FILTER	            0x41
#define REQ_GET_ETHERNET_PM_PATTERN_FILTER	            0x42
#define REQ_SET_ETHERNET_PACKET_FILTER	                0x43
#define REQ_GET_ETHERNET_STATISTIC		                0x44
#define REQ_GET_NTB_PARAMETERS		                    0x80
#define REQ_GET_NET_ADDRESS			                    0x81
#define REQ_SET_NET_ADDRESS			                    0x82
#define REQ_GET_NTB_FORMAT			                    0x83
#define REQ_SET_NTB_FORMAT			                    0x84
#define REQ_GET_NTB_INPUT_SIZE		                    0x85
#define REQ_SET_NTB_INPUT_SIZE		                    0x86
#define REQ_GET_MAX_DATAGRAM_SIZE		                0x87
#define REQ_SET_MAX_DATAGRAM_SIZE		                0x88
#define REQ_GET_CRC_MODE			                    0x89
#define REQ_SET_CRC_MODE			                    0x8a


/* Standard USB requests, see Chapter 9 */

#endif /* __mvUsbCh9_h__ */

/* EOF */
