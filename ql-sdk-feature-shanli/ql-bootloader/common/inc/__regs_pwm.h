/*
 * Copyright (C) 2016 ASR MICROELECTRONICS Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 *************************************************
 * Automatically generated C header: do not edit *
 *************************************************
 */

#define APBC_PWM0_CLK_RST (0xd401500C)
enum{
	PWM_13M = 0,
	PWM_32K,
	PWM_CLK_LIMIT
};


#define REGS_PWM0_BASE (0xd401a000)
#define REGS_PWM1_BASE (0xd401a400)
#define REGS_PWM2_BASE (0xd401a800)
#define REGS_PWM3_BASE (0xd401ac00)
#ifndef __H_REGS_PWM0PWM1PWM2PWM3_HEADFILE_H__
#define __H_REGS_PWM0PWM1PWM2PWM3_HEADFILE_H__ __FILE__

#define	REGS_PWM0
#define ASR_ADDR(_BASE_, _OFFSET_) (unsigned int)((_BASE_) + (_OFFSET_))
/* registers definitions for PWM0PWM1PWM2PWM3 */
#define REG_PWM0_PWM_CRx                                  ASR_ADDR(REGS_PWM0_BASE, 0X00)/*PWM Control Registers*/
#define REG_PWM1_PWM_CRx                                  ASR_ADDR(REGS_PWM1_BASE, 0X00)/*PWM Control Registers*/
#define REG_PWM2_PWM_CRx                                  ASR_ADDR(REGS_PWM2_BASE, 0X00)/*PWM Control Registers*/
#define REG_PWM3_PWM_CRx                                  ASR_ADDR(REGS_PWM3_BASE, 0X00)/*PWM Control Registers*/
#define REG_PWM0_PWM_DCR                                  ASR_ADDR(REGS_PWM0_BASE, 0X04)/*PWM Duty Cycle Registers*/
#define REG_PWM1_PWM_DCR                                  ASR_ADDR(REGS_PWM1_BASE, 0X04)/*PWM Duty Cycle Registers*/
#define REG_PWM2_PWM_DCR                                  ASR_ADDR(REGS_PWM2_BASE, 0X04)/*PWM Duty Cycle Registers*/
#define REG_PWM3_PWM_DCR                                  ASR_ADDR(REGS_PWM3_BASE, 0X04)/*PWM Duty Cycle Registers*/
#define REG_PWM0_PWM_PCR                                  ASR_ADDR(REGS_PWM0_BASE, 0X08)/*PWM Period Control Registers*/
#define REG_PWM1_PWM_PCR                                  ASR_ADDR(REGS_PWM1_BASE, 0X08)/*PWM Period Control Registers*/
#define REG_PWM2_PWM_PCR                                  ASR_ADDR(REGS_PWM2_BASE, 0X08)/*PWM Period Control Registers*/
#define REG_PWM3_PWM_PCR                                  ASR_ADDR(REGS_PWM3_BASE, 0X08)/*PWM Period Control Registers*/



/* bits definitions for register REG_PWM3_PWM_CRx */
#define BIT_SD                                            ( BIT(6) )
#define BITS_PWM0_PRESCALE25(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_PWM3_PWM_DCR */
#define BIT_FD                                            ( BIT(10) )
#define BITS_DCYCLE(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_PWM3_PWM_PCR */
#define BITS_PV(_X_)                                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* added by schan 2021-01-28 */

#define write64(addr, val)                          (*(volatile unsigned long long *)(addr) = (val))
#define read64(addr)                                (*(volatile unsigned long long *)(addr))

#define write32(addr, val)                          (*(volatile unsigned int *)(addr) = (val))
#define read32(addr)                                (*(volatile unsigned int *)(addr))

#define write16(addr, val)                          (*(volatile uint16 *)(addr) = (val))
#define read16(addr)                                (*(volatile uint16 *)(addr))

#define  ARR_SIZE( _a )  ( sizeof( (_a) ) / sizeof( (_a[0]) ) )

#define CHIP_REG_OR(reg_addr, value)    (*(volatile uint32_t *)(reg_addr) |= (uint32_t)(value))
#define CHIP_REG_AND(reg_addr, value)   (*(volatile uint32_t *)(reg_addr) &= (uint32_t)(value))
#define CHIP_REG_GET(reg_addr)          (*(volatile uint32_t *)(reg_addr))
#define CHIP_REG_SET(reg_addr, value)   (*(volatile uint32_t *)(reg_addr)  = (uint32_t)(value))
#endif
