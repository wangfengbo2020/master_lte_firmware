/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
INTEL CONFIDENTIAL
Copyright 2006 Intel Corporation All Rights Reserved.
The source code contained or described herein and all documents related to the source code ("Material") are owned
by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intel's prior express written permission.

No license under any patent, copyright, trade secret or other intellectual property right is granted to or
conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
Intel in writing.
-------------------------------------------------------------------------------------------------------------------*/

/***************************************************************************
*               MODULE IMPLEMENTATION FILE
****************************************************************************
*
* Filename: loadTable.h
*
* The OBM is responsible to copy image from flash to the DDR.
* It doesn't know about real image size and always copy the maximum 7MB.
* The problems:
*  - long time for copying (about 2 sec),
*  - all ERR/spy/debug buffers are overwriten.
*
* SOLUTION:
* Put the Image BEGIN and END address onto predefined area - offset_0x1C0 size 0x40
* Add the the text-signature to recognize are these addresses present in image or not.
* The signature is following the BEGIN/END and is next ":BEGIN:END:LOAD_TABLE_SIGNATURE"
* OBM should check signature in flash and if it is present MAY use the size=(END-BEGIN).
* If signature is invalid the default 7MB is used.
* The IMAGE_END region added into scatter file
*
******************************************************************************/

/*=======================================================================*/
/*        NOTE: This file may be used by OBM or WIN-CE                   */
/*=======================================================================*/

#ifndef _LOAD_TABLE_H_
#define _LOAD_TABLE_H_

#if defined (OSA_WINCE)
#include <windows.h>
#include <ceddk.h>
#include <Regext.h>
#include <Oal_memory.h>
#else
#include "global_types.h"
#endif
#include "bsp_config.h"
#include "hal_cfg.h"
#include "ptable.h"

#include "quec_cust_feature.h"// quectel add

//#if defined (_TAVOR_HARBELL_) || defined (_TAVOR_BOERNE_)
#if !defined (ADDR_CONVERT)    /* May be defined in EE_Postmortem.h or loadTable.h */
#ifndef PHS_SW_DEMO_TTC
#define TAVOR_ADDR_SELECT_MASK            0xFF000000
#define BOERNE_ADDR_EXEC_REGION_BASE      0xBF000000
#define HARBELL_ADDR_EXEC_REGION_BASE     0xD0000000
#endif
//#if defined (_TAVOR_HARBELL_) || defined(SILICON_PV2)
#if defined(SILICON_PV2)
#if defined(PHS_SW_DEMO_TTC)
#define ADDR_CONVERT(aDDR)    ((UINT8*)((UINT32)(aDDR) ))
#else
#define ADDR_CONVERT(aDDR)    ((UINT8*)((UINT32)(aDDR) &  ~TAVOR_ADDR_SELECT_MASK | HARBELL_ADDR_EXEC_REGION_BASE))
#endif
#else
#if defined (_TAVOR_BOERNE_)
#if defined(PHS_SW_DEMO_TTC)
#define ADDR_CONVERT(aDDR)    ((UINT8*)((UINT32)(aDDR)))
#else
#define ADDR_CONVERT(aDDR)    ((UINT8*)((UINT32)(aDDR) &  ~TAVOR_ADDR_SELECT_MASK | BOERNE_ADDR_EXEC_REGION_BASE))
#endif
#else
#define ADDR_CONVERT(aDDR)    ((UINT8*)((UINT32)(aDDR)))
#endif
#endif
#endif //ADDR_CONVERT

#ifdef QUEC_FOTA_SUPPORT
#define  QUECTEL_FOTA_PARAM_ADDR   0x80FDE000   // fota_param partition  use the addr fixed, not change when the fota function is out
#endif

//Offset of the LOAD_TABLE = 1C0 (in the First Flash-block)
#define LOAD_TABLE_OFFSET    0x1c0
#define LT_APP2COM_DATA_LEN     48

//++++++++++++++++++++++++++++++++++++++++++++++++++
//AREA_1: LOADTABLE_HEADER
#define LOADTABLE_HEADER_SIZE 28
typedef union{
	struct loadtable_init_routine{
		UINT32 b2init;                         /* branch to init routine */
		UINT32 init;                           /* image init routine */
	}init_routine;

	UINT8 filer[LOADTABLE_HEADER_SIZE];            /* max size*/
}LOADTABLE_AREA_HEADER;

//++++++++++++++++++++++++++++++++++++++++++++++++++
//AREA_2: VERSION & SIGNATURE
typedef enum {
    XIP,
    PSRAM
}CP_EXECUTE_MODE;

typedef enum {
    NBIOT,
    CATM,
    LTEONLY,
    LTEGSM
}PS_MODE;

#define LOADTABLE_VER_AREA_SIZE 96
typedef union{
	struct loadtable_version_info{
		char anti_rollback_version[16];   /* anti-roll back version , co-work with boot33 */
		char execute_mode[8];             /* XIP or PSRAM 		char execute_mode[8]
*/
		char ps_mode[8];                  /* LTEONLY/LG/CAT1/NBIOT */
		char image_info[50];              /* filled by external script ,default IMG_INFO as index*/
	}version_info;

	UINT8 filer[LOADTABLE_VER_AREA_SIZE];     /* max size*/
}LOADTABLE_AREA_VER_INFO;

//++++++++++++++++++++++++++++++++++++++++++++++++++
//AREA_3: RW COMPRESS REGION SYMBOL
#ifdef CRANE_MCU_DONGLE
#ifdef NO_MUTI_LOADTABLE_SUPPORT
#define EXTERNAL_RW_REGION_CPZ_NUM  5
#else
#define EXTERNAL_RW_REGION_CPZ_NUM  16
#endif
#else
#define EXTERNAL_RW_REGION_CPZ_NUM  5
#endif

#define EXTERNAL_RW_REGION_PRE_STRING "RW_CPZ_"
#define EXTERNAL_RW_REGION_COMPRESS_ADD_NULL 0x0
typedef struct
{
	char    RW_REGION_MARK[7];
	char    RW_REGION_MARK_NUM;
	char    RW_REGION_NAME[8];
	UINT32  RW_REGION_EXEC_ADDR;
	UINT32  RW_REGION_LOAD_ADDR;
	UINT32  RW_REGION_LENGTH;
	UINT32  RW_REGION_COMPRESSED_ADDR;
}rw_region_item;

#ifdef CRANE_MCU_DONGLE
#ifdef NO_MUTI_LOADTABLE_SUPPORT
#define LOADTABLE_RW_CPZ_SIZE 224
#else
#define LOADTABLE_RW_CPZ_SIZE 512
#endif
#else
#define LOADTABLE_RW_CPZ_SIZE 224
#endif

typedef union{
	rw_region_item compress_rw_region_list[EXTERNAL_RW_REGION_CPZ_NUM];

	UINT8 filer[LOADTABLE_RW_CPZ_SIZE];       /* max size*/
}LOADTABLE_AREA_RW_CPZ_INFO;

//++++++++++++++++++++++++++++++++++++++++++++++++++
//AREA_4: ARMLINKE SYMBOL LIST
typedef struct{
	char	name[12];
	UINT32	value;
}armlink_symbol_item;

#define LOADTABLE_ARMLINK_SYMBOL_SIZE 512
typedef union{
	struct loadtable_armlink_symbol_info{
		//cp.bin
		armlink_symbol_item cp_exec_addr;
		armlink_symbol_item cp_load_addr;
		armlink_symbol_item image_end;
		armlink_symbol_item binary_size;
		//dsp.bin
		armlink_symbol_item dsp_begin_addr;
		armlink_symbol_item dsp_end_addr;
		//rf.bin
		armlink_symbol_item rf_load_addr_z2;
		armlink_symbol_item rf_load_addr_a0;
		//rd.bin
		armlink_symbol_item rd_begin_addr;
		armlink_symbol_item rd_end_addr;
		//apn.bin
		armlink_symbol_item apn_begin_addr;
		armlink_symbol_item apn_end_addr;
		//fota_param
		armlink_symbol_item fota_param_start_address;
		armlink_symbol_item fota_param_end_address;
		//updater
		armlink_symbol_item updater_start_address;
		armlink_symbol_item updater_end_address;
		//fota_pkg
		armlink_symbol_item fota_pkg_start_address;
		armlink_symbol_item fota_pkg_end_address;
		//nvm
		armlink_symbol_item nvm_start_address;
		armlink_symbol_item nvm_end_address;
		//factory_a
		armlink_symbol_item factory_a_start_address;
		armlink_symbol_item factory_a_end_address;
		//factory_b
		armlink_symbol_item factory_b_start_address;
		armlink_symbol_item factory_b_end_address;
		#ifdef CRANE_MCU_DONGLE
		armlink_symbol_item ddr_ro_exec_address;
		armlink_symbol_item ddr_ro_exec_size_address;
		#else
		//mmipool
		armlink_symbol_item mmipool_start_address;
		armlink_symbol_item mmipool_size_address;
		#endif
	    //using heap to backup dsp
		armlink_symbol_item ddr_heap_guard_begin_addr;
		armlink_symbol_item ddr_heap_guard_end_addr;
		armlink_symbol_item dsp_bk_size;
	}armlink_symbol_info;

	UINT8 filer[LOADTABLE_ARMLINK_SYMBOL_SIZE];       /* max size*/
}LOADTABLE_AREA_ARMLINK_SYMBOL;


//++++++++++++++++++++++++++++++++++++++++++++++++++
//AREA_5: FUNCTIONAL VAL
typedef struct{
	char	name[12];
	UINT32	value;
}functional_item;

#define LOADTABLE_FUNC_VAL_SIZE 256
typedef union{
	struct loadtable_func_val{
		functional_item vergin;                    /* vergin mark */
		functional_item number_of_life;            /* number_of_life++ for each bootup,design for SIMPIN lock detect */
		functional_item uart_printf_enable;        /* enable uart printf after CP init*/
		functional_item fatal_printf_enable;       /* enable fatal printf after CP init*/
		functional_item default_core_freq;         /* TODO:further porting for def core freq*/
		functional_item default_core_voltage;      /* TODO:further porting for bootup core voltage*/
	}func_val;

	UINT8 filer[LOADTABLE_FUNC_VAL_SIZE];     /* max size*/
}LOADTABLE_AREA_FUNC_VAL;

typedef struct
{
	LOADTABLE_AREA_HEADER	      lt_area_header;
	LOADTABLE_AREA_VER_INFO       lt_area_ver_info;
	LOADTABLE_AREA_RW_CPZ_INFO    lt_area_rw_cpz_info;
	LOADTABLE_AREA_ARMLINK_SYMBOL lt_area_armlink_symbol;
	LOADTABLE_AREA_FUNC_VAL       lt_area_func_val;
	/* TODO: explore the vendor area for customer's usage
	LOADTABLE_AREA_vendor         lt_area_vendor;
	*/
}LoadTableType;

#define LOAD_TABLE_SIGNATURE_STR  "ASR_LT_SIGN_STR"  /*15 + zeroEnd */
#define INVALID_ADDRESS           0x4c4c554E //NULL

UINT32 get_quec_cfg_start_address(void);
UINT32 get_nvm_start_address(void);
UINT32 get_nvm_end_address(void);
UINT32 get_rd_begin_address(void);
UINT32 get_rd_end_address(void);
UINT32 get_apn_begin_address(void);
UINT32 get_apn_end_address(void);
UINT32 get_factory_a_start_address(void);
UINT32 get_factory_a_end_address(void);
UINT32 get_factory_b_start_address(void);
UINT32 get_factory_b_end_address(void);
UINT32 get_fota_param_start_address(void);
UINT32 get_fota_param_end_address(void);
UINT32 get_system_start_address(void);
UINT32 get_system_end_address(void);
UINT32 get_updater_start_address(void);
UINT32 get_updater_end_address(void);
UINT32 get_updater_backup_start_address(void);
UINT32 get_updater_backup_end_address(void);
UINT32 get_legabin_begin_address(void);
UINT32 get_legabin_end_address(void);


UINT32 get_updater_copy_size(void);
UINT32 get_cp_binary_size(void);
UINT32 get_dsp_copy_size(void);
UINT32 get_dsp_start_address(void);
UINT32 get_dsp_bin_size(void);
UINT32 get_dsp_partition_size(void);
UINT32 get_ps_mode(void);
UINT32 get_rf_start_address(void);
UINT32 get_rf_bin_size(void);
UINT32 get_rf_partition_size(void);
UINT32 get_rf_load_addr(void);
#ifdef OPENCPU_SUPPORT
UINT32 get_app_begin_address(void);
UINT32 get_app_end_address(void);
UINT32 get_app_bin_size(void);
UINT32 get_app_load_addr(void);
UINT32 get_app_area_length(void);
#endif
UINT32 get_btbin_begin_address(void);
UINT32 get_btbin_end_address(void);
UINT32 get_btbin_bin_size(void);
UINT32 get_btlst_begin_address(void);
UINT32 get_btlst_end_address(void);
UINT32 get_btlst_bin_size(void);
UINT32 get_apn_bin_size(void);
UINT32 get_nvm_bin_size(void);
UINT32 get_factory_a_bin_size(void);

UINT32 get_dsp_start_address_offset(void);
UINT32 get_reserved_end_address_offset(void);
#ifdef QUECTEL_OPEN_CPU
UINT32 get_flash_cache_end_address_offset(void);
#endif

UINT32  getCommImageBaseAddr(void);
void    getAppComShareMemAddr(UINT32* begin, UINT32* end);
void 	getAppCom_RDATA_MemAddr(UINT32* begin, UINT32* end);
void    getAppCom_RDATA_Bak_MemAddr(UINT32* begin, UINT32* end);
void    getAppCom_APRDATA_MemAddr(UINT32* begin, UINT32* end);

void commImageTableInit(void);
UINT32  getCommNumOfLife(void);
void    incrementCommNumOfLife(void);
BOOL    StrtupIsPowerup(void);
UINT32 get_mmipool_start_address(void);
UINT32 get_mmipool_end_address(void);
UINT32 get_rw_cpz_struct_addr(void);

UINT32 get_ddr_heap_size(void);
UINT32 get_dsp_backup_addr(void);
UINT32 get_dsp_backup_size(void);

BOOL is_partition_internal_flash(const char *name);

#ifndef _LOAD_TABLE_C_
extern LoadTableType  loadTable;   /* do NOT use "const" in EXTERN prototype */
#endif

extern LoadTableType  *pLoadTable;

#endif //_LOAD_TABLE_H_
