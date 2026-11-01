/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/


#ifndef QUEC_ATCMD_TCPIP_H
#define QUEC_ATCMD_TCPIP_H

#ifdef QUEC_APPTCPIP_SUPPORT
#ifdef QUEC_USB_QWIFISCAN_SUPPORT
void quec_wifiscan_ping(UINT32 atHandle);
#endif

RETURNCODE_T  quec_tcpip_qicsgp_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);

RETURNCODE_T  quec_tcpip_qiact_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);

RETURNCODE_T  quec_tcpip_qiactex_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);

RETURNCODE_T  quec_tcpip_qideact_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);

RETURNCODE_T  quec_tcpip_qideactex_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);

RETURNCODE_T  quec_tcpip_qidnscfg_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);


RETURNCODE_T  quec_tcpip_qidnsgip_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);


RETURNCODE_T  quec_tcpip_qicfg_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
#ifdef QUEC_TCPIP_QIACCEPT_SUPPORT
RETURNCODE_T  quec_tcpip_qiaccept_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
#endif

#ifdef QUEC_TCPIP_SWITCH_MULTIPLE_MODE_FEATURE
RETURNCODE_T  quec_tcpip_qiswcmd_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
#endif
RETURNCODE_T  quec_tcpip_qiopen_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);


RETURNCODE_T  quec_tcpip_qird_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);

RETURNCODE_T  quec_tcpip_qisend_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);

RETURNCODE_T  quec_tcpip_qisendex_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);

RETURNCODE_T  quec_tcpip_qiswtmd_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);

RETURNCODE_T  quec_tcpip_qistate_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);

RETURNCODE_T  quec_tcpip_qiclose_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);

RETURNCODE_T  quec_tcpip_qisde_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);

#ifdef QUEC_IPV6_CONFIG
RETURNCODE_T  quec_ipv6_config_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
    const char                    *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,       /* AT cmd usage string  */
    unsigned int                  *xid_p,             /* AT cmd handle        */
    void                          *arg_p			  /* AT cmd parser number */
);
#endif

RETURNCODE_T  quec_tcpip_qping_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
    const char                    *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,       /* AT cmd usage string  */
    unsigned int                  *xid_p,             /* AT cmd handle        */
    void                          *arg_p			  /* AT cmd parser number */
);

#ifdef QUEC_NTP_SUPPORT

RETURNCODE_T quec_tcpip_qntp_cmd
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

RETURNCODE_T  quec_tcpip_qigeterror_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
#ifdef QUEC_STAR_CHARGE_CUSTOM_WANBANGDH_FEATURE /*Project macro compilation, XXCD exit*/
RETURNCODE_T  quec_xxcd_tcpinit_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
RETURNCODE_T  quec_xxcd_ftpinit_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
RETURNCODE_T  quec_xxcd_getip_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
RETURNCODE_T  quec_xxcd_setip_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
RETURNCODE_T  quec_xxcd_tcpsend_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
RETURNCODE_T  quec_xxcd_tcpclose_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
#endif /*endof QUEC_STAR_CHARGE_CUSTOM_WANBANGDH_FEATURE*/

#ifdef QUEC_TCPIP_SEND_DIRECT_PUSH_DATA_FEATURE
RETURNCODE_T  quec_tcpip_qisendx_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
#endif /*endof QUEC_TCPIP_SEND_DIRECT_PUSH_DATA_FEATURE*/

#ifdef QUEC_TCPIP_SENDCRC_SUPPORT
RETURNCODE_T  quec_tcpip_qisendcrc_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
#endif

#ifdef  QUECTEL_CTWing_SUPPORT
RETURNCODE_T quec_tcpip_qictwcfg_cmd 
(
	const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
#endif

#ifdef QUEC_CIP_TCP_SUPPORT
RETURNCODE_T quec_tcp_cipmux_cmd 
(
	const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
RETURNCODE_T quec_tcp_cipstart_cmd 
(
	const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
RETURNCODE_T quec_tcp_cipsend_cmd 
(
	const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
RETURNCODE_T quec_tcp_ciprxget_cmd 
(
	const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);
RETURNCODE_T quec_tcp_cipclose_cmd 
(
	const utlAtParameterOp_T	   op,				  /* AT cmd type		  */
	const char					  *command_name_p,	  /* AT cmd name		  */
	const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value		  */	
	const size_t				   num_parameters,	  /* AT cmd number		  */
	const char					  *info_text_p, 	  /* AT cmd usage string  */
	unsigned int				  *xid_p,			  /* AT cmd handle		  */	
	void						  *arg_p			  /* AT cmd parser number */
);
RETURNCODE_T quec_tcp_cipstatus_cmd 
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

#endif
