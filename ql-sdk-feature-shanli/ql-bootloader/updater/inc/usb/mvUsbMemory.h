#ifndef _MVUSBMEMORY_H
#define _MVUSBMEMORY_H
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                mvUsbMemory.h


GENERAL DESCRIPTION

    This file contains the core routines for USB Partition Memory Management
    component.

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
07/06/2013   zhoujin    Created module
===========================================================================*/


/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/
//#include "platform.h"

/*===========================================================================

                       LOCAL MACRO FOR MODULE
===========================================================================*/

/* dynamic pool magic and mask */
#define RTDM_USED_MEMORY		        0x44455355
#define RTDM_FREE_MEMORY		        0x4D454D46

#define RTDM_ALIGN(size)		        ((size + sizeof(UINT32) - 1) & ~(sizeof(UINT32) - 1))
#define RTDM_OVERHEAD			        RTDM_ALIGN(sizeof(struct rtdm_header))

#define RTDM_BLOCK_IS_FREE(h)	        (h->magic == RTDM_FREE_MEMORY)

/* The maximum usb pool name. */
#define  USB_MAX_NAME                   8

/* The maximum usb pool name. */
#define  USB_PARTITON_SIZE              1024

/* Usb memory Pool Free mask. */
#define  USB_POOL_FREE                  0xBEAD0000

/* Usb memory Pool Used mask. */
#define  USB_POOL_USED                  0xBEADBEAD

/* Usb memory Pool guard.  */
#define  USB_POOL_GUARD                 0xBEEFBEEF

/* Usb aligned size.  */
#define  USB_ALIGN_SIZE                 8

/* Usb pool size.  */
#define  USB_POOL_SIZE                  (8*1024)

/* Usb Net receive buffer size */
#define  USBNET_RX_BUF_SIZE		        2048

/* The maximum Usb Net Rx count */
#ifdef CRANE_MCU_DONGLE
#define  USBNET_MAX_RX_CNT		        15
#else
#define  USBNET_MAX_RX_CNT		        256 /*for 1802\1802S*/
#endif

/* The maximum Usb Net TX count */
#define  USBNET_MAX_TX_CNT              128

/* Usb pool size. */
#define  USBNET_POOL_SIZE		    	(4 * USB_PARTITON_SIZE) //(16 * USB_PARTITON_SIZE)

/* Usb reserve pool size. */
#define  USBNET_RESERVE_SIZE		    (2 * USB_PARTITON_SIZE)

/* Usb Net receive buffer size */
#define  USBNET_RX_MAX_SIZE             (USBNET_RX_BUF_SIZE * USBNET_MAX_RX_CNT)

/* Usb maximum pool size. */
#define  USBNET_MAX_POOL_SIZE	        (USBNET_POOL_SIZE + USBNET_RESERVE_SIZE)

/* Usb align.  */
#define  USB_ALIGN(size)                ((size + USB_ALIGN_SIZE - 1) & ~(USB_ALIGN_SIZE - 1))

/* Usb min allocation memory size.  */
#define  USB_MIN_ALLOCATION_SIZE        (0x4UL)

/* Usb memory Pool overhead.  */
#define  USB_POOL_OVERHEAD              USB_ALIGN(sizeof(mvUsbPoolHdr))

/* Usb error trace.  */
#define  UsbErrTrace(fmt,args...)       uart_printf(fmt"\r\n", ##args)

/* Usb normal information trace. */
#define  UsbInfoTrace(fmt,args...)      uart_printf(fmt"\r\n", ##args)

/* RTDM trace.  */
#define  RTDM_TRACE

/*
 * Macros.
 */
#define     USB_ALLOC_MEM_STATUS(point)                             \
    {                                                                  \
        if ( point == NULL )                                           \
        {                                                              \
            return;                                                    \
        }                                                              \
    }

/*===========================================================================

                     Type definition FOR MODULE.

===========================================================================*/

typedef enum
{
	RT_STATUS_OK,
	RT_STATUS_ERROR
}rt_status_t;

/* Define the Partition Pool Control Block data type.  */
typedef struct mvUsbPCB
{
    unsigned int            pool_id;                    /* Internal Pool ID       */
    void                   *pool_start_address;         /* Starting pool address  */
    unsigned int            pool_size;                  /* Size of pool           */
    unsigned int            partition_size;             /* Size of each partition */
    unsigned int            pool_available;             /* Available partitions   */
    unsigned int            pool_allocated;             /* Allocated partitions   */
    struct mvUsbPoolHdr    *pool_available_list;        /* Available list         */
    unsigned int            pool_guard;                  /* Internal Pool ID       */

} mvUsbPCB;

/* The header structure before each memory partition.  */
typedef struct mvUsbPoolHdr
{
    unsigned int            pool_id;                 /* Internal Pool ID       */
    struct mvUsbPoolHdr    *next_available;          /* Next available partition */
    mvUsbPCB               *partition_pool;          /* Partition pool pointer */
    unsigned int            pool_guard;              /* Internal Pool ID       */
} mvUsbPoolHdr;

struct rtdm_header
{
	UINT32 magic;
	struct rtdm_header *next_memory, *prev_memory;
	struct rtdm_header *next_free_memory, *prev_free_memory;

	struct rtdm_pcb* rtdm_memory_pool;
};

/* RT dynamic pool control block */
struct rtdm_pcb
{
	/* pool start address and size */
	void *rtdm_start_address;
	UINT32 rtdm_pool_size;

	/* the minimum allocation size and the available size in pool */
	UINT32 rtdm_mini_allocation;
	UINT32 rtdm_available;

	/* used block list */
	struct rtdm_header* rtdm_block_list;

	/* free block list and free block list header */
	struct rtdm_header* rtdm_free_list;
	struct rtdm_header  rtdm_free_header;
};

/*===========================================================================

                        EXTERN FUNCTION DECLARATIONS

===========================================================================*/

/*===========================================================================

                          INTERNAL FUNCTION DECLARATIONS

===========================================================================*/

/*===========================================================================

FUNCTION mvUsbAllocatePartition

DESCRIPTION
  This function performs error checking on the parameters supplied to the
  usb allocate partition function.

DEPENDENCIES
  none

RETURN VALUE
  BOOL status

SIDE EFFECTS
  none

===========================================================================*/
void *mvUsbAllocatePartition(mvUsbPCB *pool_ptr, UINT8 direction);

/*===========================================================================

FUNCTION mvUsbDeallocatePartition

DESCRIPTION
  This function performs error checking on the parameters supplied to the
  usb deallocate partition function.

DEPENDENCIES
  none

RETURN VALUE
  BOOL status

SIDE EFFECTS
  none

===========================================================================*/
void mvUsbDeallocatePartition(void *partition);

/*===========================================================================

FUNCTION mvUsbAllocateReserveAdress

DESCRIPTION
  This function performs error checking on the parameters supplied to the
  usb allocate memory from reserve buffer.

DEPENDENCIES
  none

RETURN VALUE
  BOOL status

SIDE EFFECTS
  none

===========================================================================*/
void *mvUsbAllocateReserveAdress(UINT8 direction);

/*===========================================================================

FUNCTION mvUsbMemPoolInit

DESCRIPTION
  This function performs error checking on the parameters supplied to the
  create partition pool function.

DEPENDENCIES
  none

RETURN VALUE
  BOOL status

SIDE EFFECTS
  none

===========================================================================*/
void mvUsbMemPoolInit(void);

/*===========================================================================

FUNCTION mvUsbAllocate

DESCRIPTION
  This function performs error checking on the parameters supplied to the
  usb allocate memory function.

DEPENDENCIES
  none

RETURN VALUE
  BOOL status

SIDE EFFECTS
  none

===========================================================================*/
void *mvUsbAllocate(UINT8 direction);

/*===========================================================================

FUNCTION mvUsbDeallocate

DESCRIPTION
  This function performs error checking on the parameters supplied to the
  usb deallocate memory function.

DEPENDENCIES
  none

RETURN VALUE
  none

SIDE EFFECTS
  none

===========================================================================*/
void mvUsbDeallocate(void *partition);

/*===========================================================================

FUNCTION mvUsbCheckMemPoolValidity

DESCRIPTION
  This function Check whether usb pool is valid or not.

DEPENDENCIES
  none

RETURN VALUE
  BOOL status

SIDE EFFECTS
  none

===========================================================================*/
BOOL mvUsbCheckMemPoolValidity(mvUsbPCB *pool_ptr);

/*===========================================================================

FUNCTION mvUsbCheckPartitionValidity

DESCRIPTION
  This function Check whether usb partition is valid or not.

DEPENDENCIES
  none

RETURN VALUE
  BOOL status

SIDE EFFECTS
  none

===========================================================================*/
BOOL mvUsbCheckPartitionValidity(mvUsbPoolHdr *Partition);

/*===========================================================================

FUNCTION mvUsbCheckPoolAddressValidity

DESCRIPTION
  This function Check whether it is in usb pool range or not.

DEPENDENCIES
  none

RETURN VALUE
  BOOL status

SIDE EFFECTS
  none

===========================================================================*/
BOOL mvUsbCheckPoolAddressValidity(unsigned int address);

/*===========================================================================

FUNCTION mvUsbCheckReserveAddress

DESCRIPTION
  This function Check whether it is reserve address or not.

DEPENDENCIES
  none

RETURN VALUE
  BOOL status

SIDE EFFECTS
  none

===========================================================================*/
BOOL mvUsbCheckReserveAddress(unsigned int address);

/*===========================================================================

FUNCTION mvUsbCreatePartitionPool

DESCRIPTION
  This function performs error checking on the parameters supplied to the
  usb created partition pool function.

DEPENDENCIES
  none

RETURN VALUE
  BOOL status

SIDE EFFECTS
  none

===========================================================================*/
BOOL  mvUsbCreatePartitionPool(mvUsbPCB *pool_ptr, void *start_address,
                                unsigned int pool_size, unsigned int partition_size);

/*===========================================================================

FUNCTION mvUsbAvailableMemoryCnt

DESCRIPTION
  This function get the avaliable memory count.

DEPENDENCIES
  none

RETURN VALUE
  memory count

SIDE EFFECTS
  none

===========================================================================*/
unsigned int mvUsbAvailableMemoryCnt(void);

#endif /*_MVUSBMEMORY_H*/
