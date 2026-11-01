/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

typedef enum
{
	//PWR Mode entry & exit messages
	PWR_MODE_ENTRY_C0 				= 0x8400,
	PWR_MODE_ENTRY_C1 				= 0x8401,
	PWR_MODE_ENTRY_D2_WO_VCXO_SD 	= 0x8402,
	PWR_MODE_ENTRY_D2		 		= 0x8403,
	PWM_MODE_D2_INTERRUPTED			= 0x8404,
	PWR_MODE_ENTRY_C1_GATED			= 0x8405,
 	// Product Point in use messages
	PP_D0CS_IN_USE 					= 0x8410,
	PP_1_IN_USE 					= 0x8411,
	PP_2_IN_USE 					= 0x8412,
	PP_3_IN_USE 					= 0x8413,
	PP_4_IN_USE 					= 0x8414,
	PP_D0CS_NOT_IN_USE 				= 0x8415,
 	//Comm (AC-IPC) messaging
	DDR_REQUEST 					= 0x8420,
	DDR_REQ_ACK 		   			= 0x8421,
	DDR_RELINQUISH 		   			= 0x8422,
	DDR_HF_REQUEST 					= 0x8423,
	DDR_HF_REQ_ACK 					= 0x8424,
	DDR_HF_RELINQUISH 				= 0x8425,
	DDR_HF_REL_ACK		 			= 0x8426,
	//for mips_ram
	WATCHDOG_EVENT_KICK             = 0x8430,
	// messages with wakeup src data
	WAKEUP_SOURCE   				= 0x8540,	//this message requires data to be sent as well in 6 LS bits
	D2_WAKEUP_ENABLE				= 0x8580,   // this message requires data to be sent as well in 6 LS bits
	D2_WAKEUP_DISABLE				= 0x85C0,   // this message requires data to be sent as well in 6 LS bits
	// messages with clk data
	CLOCK_ENABLE	   				= 0x8640,	// this message requires data to be sent as well in 6 LS bits
	CLOCK_DISABLE  					= 0x8680,	// this message requires data to be sent as well in 6 LS bits
}CT_P_pm_traces_t;

#define		CTP_BOERNE_WAKEUP_ID_OFFSET	20
#define		D2_WAKEUP_SOURCE			WAKEUP_SOURCE
