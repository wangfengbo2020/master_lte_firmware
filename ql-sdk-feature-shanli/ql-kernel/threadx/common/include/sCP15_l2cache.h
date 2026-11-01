/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

#if !defined (SCP15_L2CACHE_H)
#define SCP15_L2CACHE_H
#include "xscale_types.h"

//L2 cache configuration register definitions
#define L2_CACHE_ENABLE             (0x00400000) // L2 cache enable
#define l2_CACHE_ECC_ON             (0x00800000) // L2 ECC on
#define l2_CACHE_PREFETCH_DISABLE   (0x01000000) // L2 prefetch disable

#define l2_CACHE_CONFIGURATION_REG_MASK   (0x01c00000) // configuration mask



//L2 cache lockdown register definitions
#define L2_CACHE_WAY_0_LOCK             (0x01000000) // L2 lock way 0
#define L2_CACHE_WAY_1_LOCK             (0x02000000) // L2 lock way 1
#define L2_CACHE_WAY_2_LOCK             (0x04000000)  //L2 lock way 2
#define L2_CACHE_WAY_3_LOCK             (0x08000000) // L2 lock way 3
#define L2_CACHE_WAY_4_LOCK             (0x10000000) // L2 lock way 4
#define L2_CACHE_WAY_5_LOCK             (0x20000000)  //L2 lock way 5
#define L2_CACHE_WAY_6_LOCK             (0x40000000)  //L2 lock way 6
#define L2_CACHE_WAY_7_LOCK             (0x80000000)  //L2 lock way 7

 //L2 cache lockdown register mask
#define L2_CACHE_WAY_LOCK_MASK           (0xff000000)  //L2 lock way mask



// Function prototypes

//General functions
void CPUL2Cache_configure_set(UINT32);
void CPUL2Cache_configure_clear(UINT32);
UINT32 CPUL2Cache_configure_get(void);
void CPUL2Cache_lockdown_set(UINT32);
void CPUL2Cache_lockdown_clear(UINT32);
UINT32 asm_CPUL2Cache_configure_read(void);
UINT32 asm_CPUL2Cache_lockdown_read(void);
void asm_CPUL2Cache_configure_write(UINT32);
void asm_CPUL2Cache_lockdown_write(UINT32);

#endif //ARM946E_SCP15_H
