/**  @file
  quec_atcmd_production.h

  @brief
  This file is used to define the production at command handler for different Quectel Project.

*/

/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/
/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
11/09/2018        Jensen     Init version
=================================================================*/


#ifndef _QUEC_ATCMD_PRODUCTION_H
#define _QUEC_ATCMD_PRODUCTION_H

/*> include header files here*/

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined QUEC_AT_PRODUCTION

/*========================================================================
 *  Type Definition
 *========================================================================*/
#ifdef QUEC_USB_QWIFISCAN_SUPPORT
#define WIFISCAN_IND_BUFFER_LEN    (600 * 3)
typedef struct
{
    CHAR respTempBuffer[WIFISCAN_IND_BUFFER_LEN];
    BOOL bwifiscan_repeat_flag;
    UINT8 hot_Spot_Num;
    unsigned long long wifiscan_globle_rx_byte;
    unsigned long long wifiscan_globle_tx_byte;
}wifiScanCache_t;
#endif
/*========================================================================
 *  Enumeration Definition
 *========================================================================*/
typedef enum egmr_type_e
{
    DSAT_EGMR_BASEBAND_CHIPSET = 0,
	DSAT_EGMR_DSP_CODE = 1,
	DSAT_EGMR_DSP_PATCH = 2,
	DSAT_EGMR_MCU_SW = 3,
	DSAT_EGMR_MD_BOARD = 4,
    DSAT_EGMR_SN = 5,
    DSAT_EGMR_IMEI = 7,
  #ifdef QUECTEL_EGMR_MEID_GSN
    DSAT_EGMR_MEID_GSN = 8,
  #endif
    DSAT_EGMR_IMEISV_SVN = 9,
    DSAT_EGMR_IMEI_SVN = 10, //IMEI is the first 15 bytes of IMEI.
    DSAT_EGMR_SN2 = 20,
    DSAT_EGMR_MAX
}dsat_egmr_type_e;

#ifdef QUEC_PRODUCTION_CFG_SUPPORT

typedef enum 
{
    QUEC_SAW_VALUE_100M =100,
    QUEC_SAW_VALUE_120M =120,
    QUEC_SAW_VALUE_140M =140,
    QUEC_SAW_VALUE_160M =160,
}quec_saw_freq_e;

#define QUEC_SAW_CFG_NAME   "Qsawcfg.nvm"
typedef struct
{
    uint16 begin;
    uint16 end;
}quec_b41_freq_s;

typedef struct
{
    uint16 saw_bandwidth;
    quec_b41_freq_s freq;
}quec_saw_cfg_s;

#endif

/*========================================================================
 *  Macro Definition
 *========================================================================*/




/*========================================================================
 *  function declaration
 *========================================================================*/

/*===========================================================================

FUNCTION QUEC_EXEC_QGMR_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +QGMR command.
  This command returns revision information.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.
    utlFAILED :if there was any problem in executing the command.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T  quec_exec_qgmr_cmd
(
    const utlAtParameterOp_T        op,                  /* AT cmd type          */
    const char                     *command_name_p,      /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p,  /* AT cmd value         */	
    const size_t                    num_parameters,      /* AT cmd number        */
    const char                     *info_text_p,         /* AT cmd usage string  */
    unsigned int                   *xid_p,               /* AT cmd handle        */   
    void                           *arg_p                /* AT cmd parser number */
);

#ifdef QUECTEL_AT_AP_MODEM_NEW_VERSION
RETURNCODE_T  quec_exec_qapver_cmd
(
    const utlAtParameterOp_T        op,                  /* AT cmd type          */
    const char                     *command_name_p,      /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p,  /* AT cmd value         */
    const size_t                    num_parameters,      /* AT cmd number        */
    const char                     *info_text_p,         /* AT cmd usage string  */
    unsigned int                   *xid_p,               /* AT cmd handle        */
    void                           *arg_p                /* AT cmd parser number */
);

RETURNCODE_T  quec_exec_qsub_cmd
(
    const utlAtParameterOp_T        op,                  /* AT cmd type          */
    const char                     *command_name_p,      /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p,  /* AT cmd value         */
    const size_t                    num_parameters,      /* AT cmd number        */
    const char                     *info_text_p,         /* AT cmd usage string  */
    unsigned int                   *xid_p,               /* AT cmd handle        */
    void                           *arg_p                /* AT cmd parser number */
);

RETURNCODE_T  quec_exec_qapsub_cmd
(
    const utlAtParameterOp_T        op,                  /* AT cmd type          */
    const char                     *command_name_p,      /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p,  /* AT cmd value         */
    const size_t                    num_parameters,      /* AT cmd number        */
    const char                     *info_text_p,         /* AT cmd usage string  */
    unsigned int                   *xid_p,               /* AT cmd handle        */
    void                           *arg_p                /* AT cmd parser number */
);
#endif
/*===========================================================================

FUNCTION QUEC_EXEC_EGMR_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +EGMR command.
  This command set and get module information.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.
    utlFAILED :if there was any problem in executing the command.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T  quec_exec_egmr_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */	
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

/*===========================================================================

FUNCTION QUEC_EXEC_CVERSION_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes AT+CVERSION command.
  This command returns CVERSION infomation.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T  quec_exec_cversion_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
) ;

/*===========================================================================

FUNCTION QUEC_EXEC_CSUB_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes AT+CSUB command.
  This command returns  mob_sw_subrev information.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T  quec_exec_csub_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
/*===========================================================================

FUNCTION QUEC_EXEC_QINF_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes AT+QINF command.
  This command returns  mob_sw_qinfrev information.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T  quec_exec_qinf_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
    const char                    *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */    
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,       /* AT cmd usage string  */
    unsigned int                  *xid_p,             /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);    

RETURNCODE_T  quec_exec_qgpios_cmd(const utlAtParameterOp_T 	 op,
												const char					 *command_name_p,
												const utlAtParameterValue_P2c parameter_values_p,
												const size_t				  num_parameters,
												const char					 *info_text_p,
												unsigned int				 *xid_p,
												void						 *arg_p);

RETURNCODE_T  quec_exec_qgpior_cmd(const utlAtParameterOp_T 	 op,
												const char					 *command_name_p,
												const utlAtParameterValue_P2c parameter_values_p,
												const size_t				  num_parameters,
												const char					 *info_text_p,
												unsigned int				 *xid_p,
												void						 *arg_p);

RETURNCODE_T  quec_exec_qgpiow_cmd(const utlAtParameterOp_T 	 op,
												const char					 *command_name_p,
												const utlAtParameterValue_P2c parameter_values_p,
												const size_t				  num_parameters,
												const char					 *info_text_p,
												unsigned int				 *xid_p,
												void						 *arg_p);

RETURNCODE_T  quec_exec_qgpiocfg_cmd(const utlAtParameterOp_T    op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);

RETURNCODE_T  quec_exec_mrdbackup_cmd(			const utlAtParameterOp_T      op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);

RETURNCODE_T  quec_exec_qdumpcfg_cmd(const utlAtParameterOp_T 	 op,
												const char					 *command_name_p,
												const utlAtParameterValue_P2c parameter_values_p,
												const size_t				  num_parameters,
												const char					 *info_text_p,
												unsigned int				 *xid_p,
												void						 *arg_p);

RETURNCODE_T  quec_exec_qptablevstartaddress_cmd
(
	const utlAtParameterOp_T	   op,				  /* AT cmd type		  */
	const char					  *command_name_p,	  /* AT cmd name		  */
	const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value		  */	
	const size_t				   num_parameters,	  /* AT cmd number		  */
	const char					  *info_text_p, 	  /* AT cmd usage string  */
	unsigned int				  *xid_p,			  /* AT cmd handle		  */	
	void						  *arg_p			  /* AT cmd parser number */
);

//jensen.fang 20190109: added interface of flash, like erase, write, recovery cnt
RETURNCODE_T  quec_exec_qflash_cmd(const utlAtParameterOp_T 	 op,
												const char					 *command_name_p,
												const utlAtParameterValue_P2c parameter_values_p,
												const size_t				  num_parameters,
												const char					 *info_text_p,
												unsigned int				 *xid_p,
												void						 *arg_p);


//jensen.fang 20190226: added interface to set the voltage
RETURNCODE_T  quec_exec_qvolcfg_cmd(const utlAtParameterOp_T 	 op,
												const char					 *command_name_p,
												const utlAtParameterValue_P2c parameter_values_p,
												const size_t				  num_parameters,
												const char					 *info_text_p,
												unsigned int				 *xid_p,
												void						 *arg_p);

//jensen.fang 20190304: added interface to set the pmic
RETURNCODE_T  quec_exec_qpmiccfg_cmd(const utlAtParameterOp_T 	 op,
												const char					 *command_name_p,
												const utlAtParameterValue_P2c parameter_values_p,
												const size_t				  num_parameters,
												const char					 *info_text_p,
												unsigned int				 *xid_p,
												void						 *arg_p);

//fitz.xu 20190313: add interface to fota update
RETURNCODE_T  quec_exec_qfotaupdate_cmd(const utlAtParameterOp_T    op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);

                                                
#ifdef QUEC_FAT_TEST_SUPPORT
RETURNCODE_T  quec_exec_qfattest_cmd(const utlAtParameterOp_T    op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);
                                                
#endif

#ifdef QUEC_USB_REMOTEWAKEUP_SUPPORT
RETURNCODE_T  quec_exec_qusbwake_cmd(const utlAtParameterOp_T    op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);
#endif

#ifdef QUEC_USB_QWIFISCAN_SUPPORT
void quec_wifiscan_release(void);
RETURNCODE_T  quec_exec_qcwmode_cmd(const utlAtParameterOp_T	 op,
													const char					 *command_name_p,
													const utlAtParameterValue_P2c parameter_values_p,
													const size_t				  num_parameters,
													const char					 *info_text_p,
													unsigned int				 *xid_p,
													void						 *arg_p);

RETURNCODE_T  quec_exec_qcwlapopt_cmd(const utlAtParameterOp_T	 op,
												const char					 *command_name_p,
												const utlAtParameterValue_P2c parameter_values_p,
												const size_t				  num_parameters,
												const char					 *info_text_p,
												unsigned int				 *xid_p,
												void						 *arg_p);

RETURNCODE_T  quec_exec_qcwlap_cmd(const utlAtParameterOp_T	 op,
												const char					 *command_name_p,
												const utlAtParameterValue_P2c parameter_values_p,
												const size_t				  num_parameters,
												const char					 *info_text_p,
												unsigned int				 *xid_p,
												void						 *arg_p);

//OPENAPP 设置的wifiscan的回调类型
typedef void (*quec_wifiscan_callback) (unsigned char scan_count, const char *scan_info);

#endif


#ifdef QUEC_LED_NET_STATUS_CFG_SUPPORT
RETURNCODE_T  quec_exec_qledstat_cmd(const utlAtParameterOp_T    op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);
#endif

#if defined(QUEC_LED_TASK_SUPPORT)
RETURNCODE_T  quec_exec_qledcfg_cmd(const utlAtParameterOp_T    op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);
#endif

#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610
RETURNCODE_T  quec_exec_qpwmcfg_cmd(const utlAtParameterOp_T    op,
                                    const char                   *command_name_p,
                                    const utlAtParameterValue_P2c parameter_values_p,
                                    const size_t                  num_parameters,
                                    const char                   *info_text_p,
                                    unsigned int                 *xid_p,
                                    void                         *arg_p);
#endif                              

#ifdef QUEC_ADD_FALSH_TEST_SUPPORT
RETURNCODE_T  quec_exec_qfstest_cmd(const utlAtParameterOp_T    op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);
#endif
RETURNCODE_T  quec_exec_qftest_cmd(const utlAtParameterOp_T    op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);


#ifdef QUEC_ADC_SUPPORT
RETURNCODE_T  quec_exec_qadc_cmd(const utlAtParameterOp_T    op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);

RETURNCODE_T  quec_exec_qadcdet_cmd(const utlAtParameterOp_T    op,
const char                   *command_name_p,
const utlAtParameterValue_P2c parameter_values_p,
const size_t                  num_parameters,
const char                   *info_text_p,
unsigned int                 *xid_p,
void                         *arg_p); 

void quec_adcdet_period_start(void);
void quec_adcdet_period_end(void);
#endif

#ifdef QUEC_WSETMAC_SUPPORT
RETURNCODE_T  quec_exec_qwsetmac_cmd(const utlAtParameterOp_T    op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);
#endif

RETURNCODE_T  quec_exec_qtemp_cmd(const utlAtParameterOp_T    op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);



RETURNCODE_T  quec_exec_cbc_cmd
(
	const utlAtParameterOp_T		op, 				 /* AT cmd type 		 */
	const char					   *command_name_p, 	 /* AT cmd name 		 */
	const utlAtParameterValue_P2c	parameter_values_p,  /* AT cmd value		 */
	const size_t					num_parameters, 	 /* AT cmd number		 */
	const char					   *info_text_p,		 /* AT cmd usage string  */
	unsigned int				   *xid_p,				 /* AT cmd handle		 */
	void						   *arg_p				 /* AT cmd parser number */
);


#endif

#ifdef QUEC_PRODUCTION_CFG_SUPPORT
RETURNCODE_T  quec_sawcfg_cmd
(
	const utlAtParameterOp_T	   op,				  /* AT cmd type		  */
	const char					  *command_name_p,	  /* AT cmd name		  */
	const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value		  */	
	const size_t				   num_parameters,	  /* AT cmd number		  */
	const char					  *info_text_p, 	  /* AT cmd usage string  */
	unsigned int				  *xid_p,			  /* AT cmd handle		  */	
	void						  *arg_p			  /* AT cmd parser number */
);
#endif

RETURNCODE_T  quec_exec_customrearea_cmd
(
	const utlAtParameterOp_T	   op,				  /* AT cmd type		  */
	const char					  *command_name_p,	  /* AT cmd name		  */
	const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value		  */	
	const size_t				   num_parameters,	  /* AT cmd number		  */
	const char					  *info_text_p, 	  /* AT cmd usage string  */
	unsigned int				  *xid_p,			  /* AT cmd handle		  */	
	void						  *arg_p			  /* AT cmd parser number */
);

#ifdef __cplusplus
} /*"C" */
#endif

#endif




