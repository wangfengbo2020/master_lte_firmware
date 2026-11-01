/* ############################################################################
###  Intel Confidential
###  Copyright (C) Intel Corporation 1994-2002
###  All Rights Reserved.
###  -------------------------------------------------------------------------
###  Project: Flash Data Integrator
###
###  Module: FDI_CUST.H - This module is used, by FDI development, for inserting
###                       custom test macros into the FDI source code.  The
###                       customer may use this file for including other
###                       information or may just delete the inclusion of this
###                       file from fdi_type.h.
###
###  $Archive: /FDI/SRC/INCLUDE/fdi_cust.h $
###  $Revision: 43 $
###  $Date: 1/18/05 2:18p $
###  $Author: Pcmcgint $
###  
###  $NoKeywords $
###
############################################################################ */

/*
 *****************************************************************
 * NOTICE OF LICENSE AGREEMENT
 *
 * This code is provided by Intel Corp., and the use is governed
 * under the terms of a license agreement. See license agreement
 * for complete terms of license.
 *
 * YOU MAY ONLY USE THE SOFTWARE WITH INTEL FLASH PRODUCTS.  YOUR
 * USE OF THE SOFTWARE WITH ANY OTHER FLASH PRODUCTS IS EXPRESSLY
 * PROHIBITED UNLESS AND UNTIL YOU APPLY FOR, AND ARE GRANTED IN
 * INTEL'S SOLE DISCRETION, A SEPARATE WRITTEN SOFTWARE LICENSE
 * FROM INTEL LICENSING ANY SUCH USE.
 *****************************************************************
 */

#ifndef FDI_CUST_H
#define FDI_CUST_H

#include "nucleus.h"
#include "global_types.h"
/* Compiler specific marco for unaligned pointers (obsolete) */
#define FDI_PACKED(a) (a)

/* 
 * General compile option for all performance test code. TRUE enables all 
 * performance test code, FALSE is diabled.  
 */
#define PERF_TEST   FALSE

/* Power Loss Recovery (PLR) macros */
#define TEST_PLR  0
#define BKGD_MLC  0
#define DAV_MLC   0
#define MMM_MLC   0

#define CPU32 0
#define ARM7TDMI 1
#define CPU 2

#if !defined(_FDI_VER_71_)
/* Power Loss Recovery (PLR) macros */
#define mDEBUG_CHECK_ERRCODE(a)
#define mDEBUG_DAV_PCKT_CHECK_ERRCODE(a)
#define mDEBUG_PLR_SIMULATION(a)
#define mDEBUG_FM_PLR_RETURN_ERROR()
#define mDEBUG_FM_PLR_RETURN_VALUE(ret_val)
#define mDEBUG_FM_PLR_CHECK_RECL_ERROR()
#define mDEBUG_BKGD_CONTINUE()
#define mDEBUG_BKGD_PLR_RETURN_ERROR()
#define mDEBUG_RESET_WRITE()
#define mDEBUG_RESET_ERASE()
#define mDEBUG_PCKT_PLR_RETURN_ERROR()
#define mDEBUG_PLR_SIMULATION_MLC_STATUS()
#endif
#endif
