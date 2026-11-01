
/**  @file
  quec_atcmd_camera.h

  @brief
  This file is used to define the camera at command handler for different Quectel Project.

*/

/*================================================================
  Copyright (c) 2020 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/
/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
10/16/2020        evan     Init version
=================================================================*/


#ifndef _QUEC_ATCMD_CAMERA_H
#define _QUEC_ATCMD_CAMERA_H

/*========================================================================
 * include files
 ========================================================================*/
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifdef QUEC_CAMMERA_DECODE_AUTHORIZATION
RETURNCODE_T quectel_qauthcode_cmd
(
	const utlAtParameterOp_T		op, 				/* AT cmd type			*/
	const char					   *command_name_p, 	/* AT cmd name			*/
	const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/
	const size_t					num_parameters, 	/* AT cmd number		*/
	const char					   *info_text_p,		/* AT cmd usage string	*/
	unsigned int				   *xid_p,				/* AT cmd handle		*/
	void						   *arg_p				/* AT cmd parser number */
);

RETURNCODE_T quectel_get_uid_cmd
(
	const utlAtParameterOp_T		op, 				/* AT cmd type			*/
	const char					   *command_name_p, 	/* AT cmd name			*/
	const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/
	const size_t					num_parameters, 	/* AT cmd number		*/
	const char					   *info_text_p,		/* AT cmd usage string	*/
	unsigned int				   *xid_p,				/* AT cmd handle		*/
	void						   *arg_p				/* AT cmd parser number */
);
#endif

#if defined QUEC_AT_CMD_CAMERA_SUPPORT


/*========================================================================
 *  Macro Definition
 *========================================================================*/


/*========================================================================
 *  enum/struct definition
 *========================================================================*/
	typedef enum
	{
		QUEC_CAM_UNKNOWN_ERROR		   = 7100,
		QUEC_CAM_OPEN_ERROR		   = 7300,
		QUEC_CAM_IDFY_ERROR    = 7400,

		DSAT_CME_CAM_MAX			   = 7500,
	} quec_atcmd_camera_error_e_type;



/*===========================================================================
 * Global/static Variable
 ===========================================================================*/


/*===========================================================================
 * Extern
 ===========================================================================*/

/*===========================================================================
 * Function
 ===========================================================================*/
	RETURNCODE_T  quec_exec_qcamopen_cmd
	(
		const utlAtParameterOp_T	   op,				  /* AT cmd type		  */
		const char					  *command_name_p,	  /* AT cmd name		  */
		const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value		  */	
		const size_t				   num_parameters,	  /* AT cmd number		  */
		const char					  *info_text_p, 	  /* AT cmd usage string  */
		unsigned int				  *xid_p,			  /* AT cmd handle		  */	
		void						  *arg_p			  /* AT cmd parser number */
	);
	RETURNCODE_T  quec_exec_qcamiic_cmd
	(
		const utlAtParameterOp_T	   op,				  /* AT cmd type		  */
		const char					  *command_name_p,	  /* AT cmd name		  */
		const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value		  */	
		const size_t				   num_parameters,	  /* AT cmd number		  */
		const char					  *info_text_p, 	  /* AT cmd usage string  */
		unsigned int				  *xid_p,			  /* AT cmd handle		  */	
		void						  *arg_p			  /* AT cmd parser number */
	);

	
	RETURNCODE_T  quec_exec_qcamclose_cmd
	(
		const utlAtParameterOp_T	   op,				  /* AT cmd type		  */
		const char					  *command_name_p,	  /* AT cmd name		  */
		const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value		  */	
		const size_t				   num_parameters,	  /* AT cmd number		  */
		const char					  *info_text_p, 	  /* AT cmd usage string  */
		unsigned int				  *xid_p,			  /* AT cmd handle		  */	
		void						  *arg_p			  /* AT cmd parser number */
	);
	
	RETURNCODE_T  quec_exec_qgpio_cmd
	(
		const utlAtParameterOp_T	   op,				  /* AT cmd type		  */
		const char					  *command_name_p,	  /* AT cmd name		  */
		const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value		  */	
		const size_t				   num_parameters,	  /* AT cmd number		  */
		const char					  *info_text_p, 	  /* AT cmd usage string  */
		unsigned int				  *xid_p,			  /* AT cmd handle		  */	
		void						  *arg_p			  /* AT cmd parser number */
	);
	
	RETURNCODE_T  quec_exec_qcamidfy_cmd
	(
		const utlAtParameterOp_T	   op,				  /* AT cmd type		  */
		const char					  *command_name_p,	  /* AT cmd name		  */
		const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value		  */	
		const size_t				   num_parameters,	  /* AT cmd number		  */
		const char					  *info_text_p, 	  /* AT cmd usage string  */
		unsigned int				  *xid_p,			  /* AT cmd handle		  */	
		void						  *arg_p			  /* AT cmd parser number */
	);

	RETURNCODE_T  quec_exec_qcamcfg_cmd
	(
		const utlAtParameterOp_T	   op,				  /* AT cmd type		  */
		const char					  *command_name_p,	  /* AT cmd name		  */
		const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value		  */	
		const size_t				   num_parameters,	  /* AT cmd number		  */
		const char					  *info_text_p, 	  /* AT cmd usage string  */
		unsigned int				  *xid_p,			  /* AT cmd handle		  */	
		void						  *arg_p			  /* AT cmd parser number */
	);

	RETURNCODE_T  quec_exec_qcamappver_cmd
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



#endif























































