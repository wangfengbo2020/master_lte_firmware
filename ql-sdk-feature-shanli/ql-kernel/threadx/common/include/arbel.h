/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*****************************************************************************
 *                                     	*                                    *
 *  File name:   Arbel.h                *       Intel PTK                    *
 *  Programmer:  Gil Semo               *    (C) COPYRIGHT  2004             *
 *                                      *                                    *
 *****************************************************************************
 *                                                                           *
 *  Date:       10/03/2004                                                   *
 *                                                                           *
 *     Arbel Globl HW Definitions                                            *
 *                                                                           *
 *****************************************************************************/
#ifndef _ARBEL_H
 #define    _ARBEL_H


/************************************************************************************/
/*                        Testbench address                                         */
/************************************************************************************/
#define END_TEST_ADDR 							(volatile unsigned  long *) 0xD0FFFF00
#define WRITE_END_TEST(val)     				(*END_TEST_ADDR = val)


/************************************************************************************/
/*                     Global base address                                         */
/************************************************************************************/
#define ITCM_BASE_ADDR                          0x00000000
#define DTCM_BASE_ADDR                          0xD2000000
#define EXTERNAL_AHB_BASE_ADDR                  0xD2100000
//#define AHB_SRAM_BASE_ADDR                      0xD2000000
#define DDR_BASE_ADDR                           0xD0000000
#define GB_PERIPHERALS_BASE_ADDR                0xF0000000
#define GB_Shared_SRAM_BASE_ADDR                0xD1E00000

/************************************************************************************/
/*                     APB base address                                         */
/************************************************************************************/
#define EXTERNAL_APB_BASE_ADDR                  0xD3000000
#define APBT_BASE_ADDR                          0xD4000000
#define ACCU_BASE_ADDR                          0xD4020000
#define ICU_BASE_ADDR                           0xD4040000
#define ARBEL_BASE_ADDR                         0xD4060000


/************************************************************************************/
/*                        Registers address                                         */
/************************************************************************************/

#define ARBEL_RC                       ((volatile unsigned  long *) (ARBEL_BASE_ADDR + 0x0000))
#define ARBEL_APM                      ((volatile unsigned  long *) (ARBEL_BASE_ADDR + 0x0100))
#define ARBEL_ACC                      ((volatile unsigned  long *) (ARBEL_BASE_ADDR + 0x0104))
#define ARBEL_MSEL                     ((volatile unsigned  long *) (ARBEL_BASE_ADDR + 0x0200))
#define ARBEL_GMS                      ((volatile unsigned  long *) (ARBEL_BASE_ADDR + 0x0204))
#define ARBEL_AGPOS                    ((volatile unsigned  long *) (ARBEL_BASE_ADDR + 0x0208))
#define ARBEL_AGPOR                    ((volatile unsigned  long *) (ARBEL_BASE_ADDR + 0x020C))


/*******************************************************************************/
/*  Macros Definitions                                                         */
/*******************************************************************************/
#define WRITE_ARBEL_RC(val)       (*ARBEL_RC = val)
#define READ_ARBEL_RC(val)        (val = *ARBEL_RC)
#define WRITE_ARBEL_APM(val)      (*ARBEL_APM = val)
#define READ_ARBEL_APM(val)       (val = *ARBEL_APM)
#define WRITE_ARBEL_ACC(val)      (*ARBEL_ACC = val)
#define READ_ARBEL_ACC(val)       (val = *ARBEL_ACC)
#define WRITE_ARBEL_MSEL(val)     (*ARBEL_MSEL = val)
#define READ_ARBEL_MSEL(val)      (val = *ARBEL_MSEL)
#define WRITE_ARBEL_GMS(val)      (*ARBEL_GMS = val)
#define READ_ARBEL_GMS(val)       (val = *ARBEL_GMS)
#define WRITE_ARBEL_AGPOS(val)    (*ARBEL_AGPOS = val)
#define READ_ARBEL_AGPOS(val)     (val = *ARBEL_AGPOS)
#define WRITE_ARBEL_AGPOR(val)    (*ARBEL_AGPOR = val)
#define READ_ARBEL_AGPOR(val)     (val = *ARBEL_AGPOR)


#define WRITE32(addr, val)		( *((volatile unsigned  long *) (addr)) = val )
#define READ32(addr, val)		( val = *((volatile unsigned  long *) (addr)) )
#define WRITE16(addr, val)		( *((volatile unsigned  short *) (addr)) = val )
#define READ16(addr, val)		( val = *((volatile unsigned  short *) (addr)) )
#define WRITE8(addr, val)		( *((volatile unsigned  char *) (addr)) = val )
#define READ8(addr, val)		( val = *((volatile unsigned  char *) (addr)) )

#endif      /* _ARBEL_H */

