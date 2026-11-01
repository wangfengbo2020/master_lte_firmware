#ifndef _QUEC_ATCMD_SLAS_H
#define _QUEC_ATCMD_SLAS_H
#include "quec_at_common.h"

#ifdef __cplusplus
extern "C" {
#endif
extern BOOL getExtString ( const utlAtParameterValue_P2c param_value_p,
		int index,
		CHAR *outString,
		INT16 maxStringLength,
		INT16 *outStringLength,
		CHAR *defaultString);

extern BOOL getExtValue( const utlAtParameterValue_P2c param_value_p,
		int index,
		int *value_p,
		int minValue,
		int maxValue,
		int DefaultValue);

RETURNCODE_T  quec_exec_qlicenseinfo_cmd
(
	const utlAtParameterOp_T	   op,				  /* AT cmd type		  */
	const char					  *command_name_p,	  /* AT cmd name		  */
	const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value		  */	
	const size_t				   num_parameters,	  /* AT cmd number		  */
	const char					  *info_text_p, 	  /* AT cmd usage string  */
	unsigned int				  *xid_p,			  /* AT cmd handle		  */	
	void						  *arg_p			  /* AT cmd parser number */
);

RETURNCODE_T  quec_exec_qlicense_cmd
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

