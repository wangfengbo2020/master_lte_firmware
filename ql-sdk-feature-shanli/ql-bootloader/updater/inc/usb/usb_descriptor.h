#ifndef _USB_DESCRIPTOR_H_
#define _USB_DESCRIPTOR_H_
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                usb_descriptor.h


GENERAL DESCRIPTION

    This file is for USB descriptor.

EXTERNALIZED FUNCTIONS

INITIALIZATION AND SEQUENCING REQUIREMENTS

   Copyright (c) 2018 by ASR, Incorporated.  All Rights Reserved.
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when         who        what, where, why
--------   ------     ----------------------------------------------------------
06/12/2018   zhoujin    Created module
===========================================================================*/


/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/
//#include "usb_init.h"
#include "usb_macro.h"

/*===========================================================================

                                LOCAL MACRO
===========================================================================*/

/* USB Modem control endpoint. */
#define MdmCtrlEP       (MODEM_CTRL_ENDPOINT | 0x80)

/* USB Diag control endpoint. */
#define DiagCtrlEP      (DIAG_CTRL_ENDPOINT | 0x80)

/* Usb Net control endpoint. */
#define NetCtrlEP       (USB_NET_CRTL_ENDPOINT | 0x80)

/* Usb Modem TX endpoint. */
#define MdmTxEP         (MODEM_TX_ENDPOINT | 0x80)

/* Usb Diag TX endpoint. */
#define DiagTxEP        (DIAG_TX_ENDPOINT | 0x80)

/* Usb Net TX endpoint. */
#define NetTxEP         (USB_NET_TX_ENDPOINT | 0x80)

/* Usb Mass Storage TX endpoint. */
#define MSCTxEP         (USB_MASS_STORAGE_TX_ENDPOINT | 0x80)

/* Usb Sulog TX endpoint. */
#define SulogTxEP       (SULOG_TX_ENDPOINT | 0x80)

/* Modem RX endpoint. */
#define MdmRxEP         (MODEM_RX_ENDPOINT)

/* Diag RX endpoint. */
#define DiagRxEP        (DIAG_RX_ENDPOINT)

/* Usb Net RX endpoint. */
#define NetRxEP         (USB_NET_RX_ENDPOINT)

/* Usb Mass Storage RX endpoint. */
#define MSCRxEP         (USB_MASS_STORAGE_RX_ENDPOINT)

/* Usb sulog RX endpoint. */
#define SulogRxEP       (SULOG_RX_ENDPOINT)

/* merger from 1802s as follows */
#ifdef EXT_AT_MODEM_SUPPORT
/* USB Modem 2rd control point*/
#define AtCtrlEP        (AT_CTRL_ENDPOINT | 0x80)
#endif

/* USB Modem 2rd TX point*/
#define AtTxEP          (AT_TX_ENDPOINT | 0x80)

/* USB Modem 2rd RX point*/
#define AtRxEP          (AT_RX_ENDPOINT)


/*===========================================================================

                          Struct definition.

===========================================================================*/

/* Type definition for USB Descriptor. */
typedef enum
{
	USB_GENERIC_MIFI_DESCRIPTOR     = 27,
    USB_MARVELL_MIFI_DESCRIPTOR     = 30,
    USB_RNDIS_ONLY_DESCRIPTOR	    = 33,
    USB_ASR_MIFI_DESCRIPTOR         = 34,
    USB_MARVELL_ECM_DESCRIPTOR      = 40,
    USB_MBIM_DESCRIPTOR				= 56,
    USB_MODEM_DIAG_DESCRIPTOR       = 57,
    USB_MODEM_ONLY_DESCRIPTOR       = 58,
	USB_CDROM_ONLY_DESCRIPTOR       = 66,
	USB_CDROM_DIAG_DESCRIPTOR       = 67,
	USB_DIAG_ONLY_DESCRIPTOR        = 68,
    USB_GENERIC_MOD_ECM_DESCRIPTOR  = 69,
	USB_GENERIC_MOD_DESCRIPTOR      = 70,
	USB_MAX_DESCRIPTOR_TYPE
}PlatformUsbDescType;


/*===========================================================================

            EXTERN DECLARATIONS FOR MODULE

===========================================================================*/

/*===========================================================================

                        EXTERN FUNCTION DECLARATIONS

===========================================================================*/

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      SetUsbMode                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function Set Usb Mode.                                      */
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
/*      size                                Memory size                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
extern void SetUsbMode(char mode);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      eeGetSystemAssertFlag                                            */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function get system assert flag.                            */
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
/*      size                                Memory size                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
extern BOOL eeGetSystemAssertFlag(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      _usb_dci_vusb20_stop_transter                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function stop usb transfer.                                 */
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
/*      size                                Memory size                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
extern void _usb_dci_vusb20_stop_transter(void);;

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      mvUsbStorageConfigure                                            */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function configurate the parameters of mass storage.         */
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
extern void mvUsbStorageConfigure(void);

/*===========================================================================

                          INTERNAL FUNCTION DECLARATIONS

===========================================================================*/
/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      USB2MgrUpdateDescriptor                                          */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function update the usb descriptor.                          */
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
void USB2MgrUpdateDescriptor(PlatformUsbDescType desc);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      USB2ReEnumerate                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function re-enumerate the usb device.                        */
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
void USB2ReEnumerate(PlatformUsbDescType Desc);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      USBIsConnected                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function check whether usb is connected or not.              */
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
char USBIsConnected(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      USB2ConfigureCdromDescriptor                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function configurae CDROM only descriptor.                   */
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
void USB2ConfigureCdromDescriptor(void);

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      USB2ProcessGetConfigDescRequest                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function process the get configuration descriptor request.   */
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
void USB2ProcessGetConfigDescRequest(UINT16 value);

#endif /* _USB_DESCRIPTOR_H_ */
