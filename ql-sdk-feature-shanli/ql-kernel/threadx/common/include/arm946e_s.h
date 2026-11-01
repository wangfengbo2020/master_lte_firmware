/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*******************************************************************
 *    Copyright (C) 2004 Intel Corporation
 *
 *    DESCRIPTION:
 *
 *    AUTHOR:
 *
 *    HISTORY:
 *
 *******************************************************************/

#ifndef __ARM946E_S_H__
#define __ARM946E_S_H__

//define ARM946e working modes
#define ARM946E_USR_MODE     (0x10)
#define ARM946E_FIQ_MODE     (0x11)
#define ARM946E_IRQ_MODE     (0x12)
#define ARM946E_SVC_MODE     (0x13)
#define ARM946E_ABT_MODE     (0x17)
#define ARM946E_UND_MODE     (0x1B)
#define ARM946E_SYS_MODE     (0x1F)

#define ARM946E_IRQ_BIT		 (0x80) // when I bit is set, IRQ is disabled
#define ARM946E_FIQ_BIT		 (0x40) // when F bit is set, FIQ is disabled

#define ARM946E_MODE_MASK    (0x1F)


// User & System mode registers
#define ARM9_CORE_R0       (0x0)
#define ARM9_CORE_R1       (0x1)
#define ARM9_CORE_R2       (0x2)
#define ARM9_CORE_R3       (0x3)
#define ARM9_CORE_R4       (0x4)
#define ARM9_CORE_R5       (0x5)
#define ARM9_CORE_R6       (0x6)
#define ARM9_CORE_R7       (0x7)
#define ARM9_CORE_R8       (0x8)
#define ARM9_CORE_R9       (0x9)
#define ARM9_CORE_R10      (0xA)
#define ARM9_CORE_R11      (0xB)
#define ARM9_CORE_R12      (0xC)
#define ARM9_CORE_R13      (0xD)
#define ARM9_CORE_SP       (0xD)
#define ARM9_CORE_R14      (0xE)
#define ARM9_CORE_LR       (0xE)
#define ARM9_CORE_R15      (0xF)
#define ARM9_CORE_PC       (0xF)
#define ARM9_CORE_CPSR     (0x10)

#define ARM9_CORE_A1       (0x0)
#define ARM9_CORE_A2       (0x1)
#define ARM9_CORE_A3       (0x2)
#define ARM9_CORE_A4       (0x3)
#define ARM9_CORE_V1       (0x4)
#define ARM9_CORE_V2       (0x5)
#define ARM9_CORE_V3       (0x6)
#define ARM9_CORE_V4       (0x7)
#define ARM9_CORE_V5       (0x8)
#define ARM9_CORE_V6       (0x9)
#define ARM9_CORE_V7       (0xA)
#define ARM9_CORE_V8       (0xB)
#define ARM9_CORE_SB       (0x9)
#define ARM9_CORE_SL       (0xA)
#define ARM9_CORE_FP       (0xB)
#define ARM9_CORE_IP       (0xC)

// Supervisor mode additional registers
#define ARM9_CORE_R13_SVC  (0x1000000D)
#define ARM9_CORE_SP_SVC   (0x1000000D)
#define ARM9_CORE_R14_SVC  (0x1000000E)
#define ARM9_CORE_LR_SVC   (0x1000000E)
#define ARM9_CORE_SPSR_SVC (0x10000010)


// Abort mode additional registers
#define ARM9_CORE_R13_ABT  (0x2000000D)
#define ARM9_CORE_SP_ABT   (0x2000000D)
#define ARM9_CORE_R14_ABT  (0x2000000E)
#define ARM9_CORE_LR_ABT   (0x2000000E)
#define ARM9_CORE_SPSR_ABT (0x20000010)

// Undefined mode additional registers
#define ARM9_CORE_R13_UND  (0x3000000D)
#define ARM9_CORE_SP_UND   (0x3000000D)
#define ARM9_CORE_R14_UND  (0x3000000E)
#define ARM9_CORE_LR_UND   (0x3000000E)
#define ARM9_CORE_SPSR_UND (0x30000010)

// Interrupt mode additional registers
#define ARM9_CORE_R13_IRQ  (0x4000000D)
#define ARM9_CORE_SP_IRQ   (0x4000000D)
#define ARM9_CORE_R14_IRQ  (0x4000000E)
#define ARM9_CORE_LR_IRQ   (0x4000000E)
#define ARM9_CORE_SPSR_IRQ (0x40000010)

// Fast Interrupt mode additional registers
#define ARM9_CORE_R8_FIQ   (0x50000008)
#define ARM9_CORE_R9_FIQ   (0x50000009)
#define ARM9_CORE_R10_FIQ  (0x5000000A)
#define ARM9_CORE_R11_FIQ  (0x5000000B)
#define ARM9_CORE_R12_FIQ  (0x5000000C)
#define ARM9_CORE_R13_FIQ  (0x5000000D)
#define ARM9_CORE_SP_FIQ   (0x5000000D)
#define ARM9_CORE_R14_FIQ  (0x5000000E)
#define ARM9_CORE_LR_FIQ   (0x5000000E)
#define ARM9_CORE_SPSR_FIQ (0x50000010)



// Function prototypes
void Arm946eRestoreInterrupts(UINT32 ir);
UINT32 Arm946eDisableInterrupts(void);
UINT32 Arm946eEnableInterrupts(void);

/* External parameters used for memory initialization */
extern void asm_Arm9SetZeroInitialized(void);
/** external data **/
extern UINT32 TCT_System_Limit;

extern void asm_Arm946e_flush_caches(void);

#endif //__ARM946E_S_H__

