/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/* ============================================================================
File        : IPC_gbl_config.h
Description : Global configuration file for testing the hal/IPC package.

Notes       :

\Copyright 2001, Intel Corporation, All rights reserved.
============================================================================ */

#if !defined(_IPC_GBL_CONFIG_H_)
#define _IPC_GBL_CONFIG_H_


/********* Compilation Flags ***********************

There are 2 different sets of compilation flags for the IPC package:
 1) WCDMA - HERMON PROTO
 2) _HERMON_ (chip)

Note: Only one set at a time should be defined.

***************************************************/

/*** WCDMA - HERMON PROTO ***/
//#define HERMON_PROTO
#if !defined(SILICON_PV2)
#define IPC_DEBUG
#endif
#if NO_APLP
#define IPC_AAAP_MODE
#define IPC_AAAP_USE_MALLOC
#endif
#define SPY_CMD
#define IPC_SEND_WITH_INTERRUPTS_DISABLED
#define IPC_FILTERS                   // Beware: current filter solution costs about 400K of RAM
/******************************/

#define IPC_DATA_SEND_WITH_INTERRUPTS_DISABLED
#define IPC_DATA_TX_COPY_IN_HISR

// OVERRIDE the configuration parameters defined in WS_IPCCommConfig.h
#undef  MAX_NUM_OF_REGISTERS
#define MAX_NUM_OF_REGISTERS    5       // FOR QT; memory waste by IPC is unbelievable - revise

#endif /* _IPC_GBL_CONFIG_H_ */

/*                      end of IPC_gbl_config.h
--------------------------------------------------------------------------- */
