/**  @file
  quec_atcmd_sim.h

  @brief
  This file is used to define the sim at command handler for different Quectel Project.

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
03/28/2019		  Tery	     aad airplanecontrol function
01/21/2019		  Tery	     add at+qoem="landipin" function
12/18/2018		  Tery	     add quec_exec_qsimdet_cmd and quec_exec_qsimstat_cmd function define
12/10/2018		  Tery	     add quec_exec_qpinc_cmd function define
12/05/2018		  Tery	     add QUSIM URC function define
11/29/2018		  Tery	     add quec_exec_qinistat_cmd functiondefine
11/27/2018		  Tery	     add quec_exec_iccid_cmd function define
11/09/2018        Jensen     Init version
=================================================================*/


#ifndef _QUEC_ATCMD_SIM_H
#define _QUEC_ATCMD_SIM_H

/*> include header files here*/

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "quec_vsim_include.h"

#ifdef __cplusplus
extern "C" {
#endif

/*Tery 20190328 aad airplanecontrol function*/
#include "quec_driver_common.h"

#ifdef QUEC_AT_ICCID_SUPPORT

/*========================================================================
 *  Type Definition
 *========================================================================*/

#define __QUEC_AT_QSIMDET_VALUE "quec_at_qsimdet.value"
#define __QUEC_AT_QSIMSTAT_VALUE "quec_at_qsimstat.value"


typedef enum
{
    QUEC_QCCID = 0x00,
	QUEC_CCID,
	QUEC_ICCID,
}quectel_sim_ccid;

#ifdef QUEC_STARTREPORT_OPTIMIZE
typedef enum {
	NONE_URC_ON = 0,	
	CFUN_URC_ON,		
	CPIN_URC_ON,
	USIM_URC_ON,
	ALL_URC_ON  	// CPIN->USIM->CFUN  CFUN report delay
}	QUEC_StartupReportStatus;
#endif

/*========================================================================
 *  Enumeration Definition
 *========================================================================*/
typedef enum
{
    QUEC_SIM_QPINC_QUERY_NO = 0x00,
    QUEC_SIM_QPINC_QUERY_ALL,
	QUEC_SIM_QPINC_QUERY_SC,
	QUEC_SIM_QPINC_QUERY_P2,
}quectel_sim_qpinc;

/*========================================================================
 *  Macro Definition
 *========================================================================*/


void quec_set_sim_ccid_cmd(UINT8 mode);
UINT8 quec_get_sim_ccid_cmd(void);



/*===========================================================================
	
	FUNCTION QUEC_EXEC_ICCID_CMD
	
	DESCRIPTION
	  This function takes the result from the command line parser
	  and executes it. It executes +ICCID command.
	  This command returns iccid information.
	
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
RETURNCODE_T  quec_exec_iccid_cmd
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
#ifdef QUEC_ASR_SIM_ENBALE
/*Tery.shi 2018/11/29 <SIM> add QINISTAT command*/
/*===========================================================================
	
FUNCTION QUEC_EXEC_QINISTAT_CMD
		
DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +QINISTAT command.
  This command can query initialization status of SIM/USIM card,like phonebook and SMS initialization is done or not.

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
RETURNCODE_T  quec_exec_qinistat_cmd
(
	const utlAtParameterOp_T		op, 				 /* AT cmd type 		 */
	const char					   *command_name_p, 	 /* AT cmd name 		 */
	const utlAtParameterValue_P2c	parameter_values_p,  /* AT cmd value		 */
	const size_t					num_parameters, 	 /* AT cmd number		 */
	const char					   *info_text_p,		 /* AT cmd usage string  */
	unsigned int				   *xid_p,				 /* AT cmd handle		 */
	void						   *arg_p				 /* AT cmd parser number */
);

#if QUEC_DUAL_SIM_SUPPORT
void quec_sim_type_urc(UINT32 indHandle);
#else
void quec_sim_type_urc(void);
#endif

/*Tery.shi 2018/11/29 <SIM> add QPINC command*/
/*===========================================================================
FUNCTION quec_exec_qpinc_cmd
		
DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +QPINC command.
  This command can the number of attempts left to enter the password of SIM PIN/PUK.
	
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
RETURNCODE_T  quec_exec_qpinc_cmd
(
	const utlAtParameterOp_T		op, 				 /* AT cmd type 		 */
	const char					   *command_name_p, 	 /* AT cmd name 		 */
	const utlAtParameterValue_P2c	parameter_values_p,  /* AT cmd value		 */
	const size_t					num_parameters, 	 /* AT cmd number		 */
	const char					   *info_text_p,		 /* AT cmd usage string  */
	unsigned int				   *xid_p,				 /* AT cmd handle		 */
	void						   *arg_p				 /* AT cmd parser number */
);

UINT8 quec_get_qpinc_oper(void);
void quec_set_qpinc_oper(UINT8 oper);

void quec_sim_hot_plug_handle(quec_pin_level_value_e level);

/*Tery 20190328 aad airplanecontrol function*/
QuecOSStatus quec_airplane_report(quec_pin_level_value_e level);

RETURNCODE_T  quec_exec_qsimstat_cmd
(
	const utlAtParameterOp_T		op, 				 /* AT cmd type 		 */
	const char					   *command_name_p, 	 /* AT cmd name 		 */
	const utlAtParameterValue_P2c	parameter_values_p,  /* AT cmd value		 */
	const size_t					num_parameters, 	 /* AT cmd number		 */
	const char					   *info_text_p,		 /* AT cmd usage string  */
	unsigned int				   *xid_p,				 /* AT cmd handle		 */
	void						   *arg_p				 /* AT cmd parser number */
);

RETURNCODE_T  quec_exec_qsimdet_cmd
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


#ifdef __QUEC_OEM_VER_LD__
  /*Tery.shi 20190121 add at+qoem="landipin" function*/
bool quec_get_sim_landipin_status(uint8* status);
bool quec_set_sim_landipin_status(uint8 value);
#endif

#if QUEC_VSIM_ENABLE
RETURNCODE_T  quec_exec_qvsim_cmd
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

#ifdef QUEC_CDMA_IMSI_SUPPORT
#define CDMA_IMSI_MAX 50 
typedef struct 
{
     bool flag;
     uint8 data_len;                                 //data[CDMA_IMSI_MAX] len
     char data[CDMA_IMSI_MAX]; 
     char imsi[20];                         //max is 15
}cdma_imsi_s;
#endif

#if QUEC_DUAL_SIM_SUPPORT
//Switch sim
#ifndef __QUECTEL_PROJECT_EG912YEM_AA__ 
RETURNCODE_T  quec_exec_qdsim_cmd(const utlAtParameterOp_T op,
		const char						*command_name_p,
		const utlAtParameterValue_P2c	parameter_values_p,
		const size_t					num_parameters,
		const char						*info_text_p,
		unsigned int					*xid_p,
		void							*arg_p);
#endif
//Set DSSS or DSDS
RETURNCODE_T  quec_exec_qdstype_cmd(const utlAtParameterOp_T op,
		const char						*command_name_p,
		const utlAtParameterValue_P2c	parameter_values_p,
		const size_t					num_parameters,
		const char						*info_text_p,
		unsigned int					*xid_p,
		void							*arg_p);
//Bind atp_index to SIM1 or SIM2
RETURNCODE_T  quec_exec_qdsbind_cmd(const utlAtParameterOp_T op,
		const char						*command_name_p,
		const utlAtParameterValue_P2c	parameter_values_p,
		const size_t					num_parameters,
		const char						*info_text_p,
		unsigned int					*xid_p,
		void							*arg_p);

RETURNCODE_T quec_exec_qdsimi_cmd
(
	const utlAtParameterOp_T		op, 				/* AT cmd type			*/
	const char					   *command_name_p, 	/* AT cmd name			*/
	const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/
	const size_t					num_parameters, 	/* AT cmd number		*/
	const char					   *info_text_p,		/* AT cmd usage string	*/
	unsigned int				   *xid_p,				/* AT cmd handle		*/ 
	void						   *arg_p				/* AT cmd parser number */
);

RETURNCODE_T quec_exec_qdsccid_cmd
(
	const utlAtParameterOp_T		op, 				/* AT cmd type			*/
	const char					   *command_name_p, 	/* AT cmd name			*/
	const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/
	const size_t					num_parameters, 	/* AT cmd number		*/
	const char					   *info_text_p,		/* AT cmd usage string	*/
	unsigned int				   *xid_p,				/* AT cmd handle		*/ 
	void						   *arg_p				/* AT cmd parser number */
);

RETURNCODE_T quec_exec_qdspin_cmd
(
	const utlAtParameterOp_T		op, 				/* AT cmd type			*/
	const char					   *command_name_p, 	/* AT cmd name			*/
	const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/
	const size_t					num_parameters, 	/* AT cmd number		*/
	const char					   *info_text_p,		/* AT cmd usage string	*/
	unsigned int				   *xid_p,				/* AT cmd handle		*/ 
	void						   *arg_p				/* AT cmd parser number */
);

RETURNCODE_T quec_exec_qdsreg_cmd
(
	const utlAtParameterOp_T		op, 				/* AT cmd type			*/
	const char					   *command_name_p, 	/* AT cmd name			*/
	const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/
	const size_t					num_parameters, 	/* AT cmd number		*/
	const char					   *info_text_p,		/* AT cmd usage string	*/
	unsigned int				   *xid_p,				/* AT cmd handle		*/ 
	void						   *arg_p				/* AT cmd parser number */
);

RETURNCODE_T quec_exec_qdsgreg_cmd
(
	const utlAtParameterOp_T		op, 				/* AT cmd type			*/
	const char					   *command_name_p, 	/* AT cmd name			*/
	const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/
	const size_t					num_parameters, 	/* AT cmd number		*/
	const char					   *info_text_p,		/* AT cmd usage string	*/
	unsigned int				   *xid_p,				/* AT cmd handle		*/ 
	void						   *arg_p				/* AT cmd parser number */
);

RETURNCODE_T quec_exec_qdsereg_cmd
(
	const utlAtParameterOp_T		op, 				/* AT cmd type			*/
	const char					   *command_name_p, 	/* AT cmd name			*/
	const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/
	const size_t					num_parameters, 	/* AT cmd number		*/
	const char					   *info_text_p,		/* AT cmd usage string	*/
	unsigned int				   *xid_p,				/* AT cmd handle		*/ 
	void						   *arg_p				/* AT cmd parser number */
);

RETURNCODE_T quec_exec_qdsq_cmd
(
	const utlAtParameterOp_T		op, 				/* AT cmd type			*/
	const char					   *command_name_p, 	/* AT cmd name			*/
	const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/
	const size_t					num_parameters, 	/* AT cmd number		*/
	const char					   *info_text_p,		/* AT cmd usage string	*/
	unsigned int				   *xid_p,				/* AT cmd handle		*/ 
	void						   *arg_p				/* AT cmd parser number */
);

RETURNCODE_T quec_exec_qdsops_cmd
(
	const utlAtParameterOp_T		op, 				/* AT cmd type			*/
	const char					   *command_name_p, 	/* AT cmd name			*/
	const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/
	const size_t					num_parameters, 	/* AT cmd number		*/
	const char					   *info_text_p,		/* AT cmd usage string	*/
	unsigned int				   *xid_p,				/* AT cmd handle		*/ 
	void						   *arg_p				/* AT cmd parser number */
);

RETURNCODE_T quec_exec_qdslock_cmd
(
	const utlAtParameterOp_T		op, 				/* AT cmd type			*/
	const char					   *command_name_p, 	/* AT cmd name			*/
	const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/
	const size_t					num_parameters, 	/* AT cmd number		*/
	const char					   *info_text_p,		/* AT cmd usage string	*/
	unsigned int				   *xid_p,				/* AT cmd handle		*/ 
	void						   *arg_p				/* AT cmd parser number */
);

RETURNCODE_T quec_exec_qdsrelease_cmd
(
	const utlAtParameterOp_T		op, 				/* AT cmd type			*/
	const char					   *command_name_p, 	/* AT cmd name			*/
	const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/
	const size_t					num_parameters, 	/* AT cmd number		*/
	const char					   *info_text_p,		/* AT cmd usage string	*/
	unsigned int				   *xid_p,				/* AT cmd handle		*/ 
	void						   *arg_p				/* AT cmd parser number */
);


extern bool quec_is_atp_bind_sim1(UINT32 atpIndex);
extern bool quec_is_atp_bind_sim2(UINT32 atpIndex);
#endif


#ifdef __cplusplus
} /*"C" */
#endif

#endif




