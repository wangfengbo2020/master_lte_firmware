/**
 ******************************************************************************
 * @file    quec_rtos.h
 * @author  Chavis.Chen
 * @version V1.0.0
 * @date    26-Sep-2018
 * @brief   This file contains the common definitions, macros and functions to
 *          be shared throughout the project.
 ******************************************************************************
 *
 *  The MIT License
 *  Copyright (c) 2018 QUECTEL Inc.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is furnished
 *  to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ******************************************************************************
 */


#ifndef _QUEC_RTOS_H
#define _QUEC_RTOS_H

#include "osa.h"
#include "osa_old_api.h"
#include "linklist.h"
#include "quec_rtos_config.h"
#include "quec_cust_feature.h"
#define QUEC_OS_TASK_PRIORITY	95
#define QUEC_APP_TASK_PRIORITY	100


typedef uint32 					quec_tcb_id_t;

typedef linklist_handler_t 		QuecTCBLinklist_t;

typedef OSTaskRef				quec_task_t;
typedef OSSemaRef				quec_sem_t;
typedef OSMutexRef		   		quec_mutex_t;
typedef OSMsgQRef		   		quec_queue_t;
typedef OSMailboxQRef	   		quec_mailbox_t;
typedef OSFlagRef		   		quec_flag_t;
typedef OSTimerRef		   		quec_timer_t;
typedef OSATimerStatus			quec_timer_status_t;


typedef struct
{
	quec_tcb_id_t id;
	quec_task_t   taskRef;
	void*         stackPtr;
	uint32        stackSize;
	uint8         priority;
	char        * taskName;
	void      ( * taskStart )( void * );
	void        * argv;
} quec_tcb_t;

typedef struct
{
	quec_task_t		taskRef;
	quec_queue_t	queueRef;
} task_delete_worker_t;

typedef struct
{
	bool		is_delete_itself;
	quec_task_t	taskRef;
} task_delete_obj_t;

typedef struct
{
	quec_task_t		taskRef;
	QuecOSStatus	result;
} task_delete_result_t;


typedef void (* task_delete_work_cb_t)(task_delete_result_t * task_delete_result);

#if QUECTEL_PROJECT_CUST
#define QUEC_WAIT_FOREVER  OS_SUSPEND
#define QUEC_NO_WAIT	   OS_NO_SUSPEND
#else
/*  Chaim compile error  enum is int type
typedef enum
{
	QUEC_WAIT_FOREVER = OS_SUSPEND,
	QUEC_NO_WAIT	  = OS_NO_SUSPEND
} quec_wait_e;
    */
#endif

typedef enum
{
	QUEC_FLAG_AND 		= OSA_FLAG_AND,
	QUEC_FLAG_AND_CLEAR = OSA_FLAG_AND_CLEAR,
	QUEC_FLAG_OR 		= OSA_FLAG_OR,
	QUEC_FLAG_OR_CLEAR	= OSA_FLAG_OR_CLEAR
} quec_flag_op_e;

typedef enum
{
	QUEC_TMR_STA_ENABLED  = OSA_ENABLED,
	QUEC_TMR_STA_DISABLED = OSA_DISABLED,
} quec_tmr_sta_e;

typedef enum
{
	QUEC_TASK_NAME_APP_START,
	QUEC_TASK_NAME_HTTP_SEND,
	QUEC_TASK_NAME_HTTP_RECV_PRE,
	QUEC_TASK_NAME_HTTP_RECV,
	QUEC_TASK_NAME_HTTP_DESTROY,
	QUEC_TASK_NAME_HTTP_TIMER_EVENT,
	QUEC_TASK_NAME_HTTP_SERVICE,
	QUEC_TASK_NAME_FILE,
	QUEC_TASK_NAME_FTP_FOTA,
	QUEC_TASK_NAME_FOTA_FEED,
	QUEC_TASK_NAME_FOTA_RECV,
	QUEC_TASK_NAME_FOTA_WRITE,
	QUEC_TASK_NAME_FOTA_UPDATE,
	QUEC_TASK_NAME_NETCARD,
	QUEC_TASK_NAME_NET_IF_BIND,
	QUEC_TASK_NAME_PDP_ACT,
	QUEC_TASK_NAME_SLEEP,
	QUEC_TASK_NAME_RECOVERY,
	QUEC_TASK_NAME_TASK_DELETE,
	QUEC_TASK_NAME_SIO_DDS,
	QUEC_TASK_NAME_URC_PRE,
	QUEC_TASK_NAME_URC,
	QUEC_TASK_NAME_RI,
	QUEC_TASK_NAME_TCP_WORK,
	QUEC_TASK_NAME_TCP_AT,
	QUEC_TASK_NAME_SOCKET_WORK,
	QUEC_TASK_NAME_FTP_WORK,
	QUEC_TASK_NAME_IOT_WORK,
	QUEC_TASK_NAME_AUDIO,
	QUEC_TASK_NAME_QIACT,
	QUEC_TASK_NAME_RX_CMUX,
	QUEC_TASK_NAME_TX_CMUX,
	QUEC_TASK_NAME_MQTTCNF,
	QUEC_TASK_NAME_MQTTAT,
	QUEC_TASK_NAME_MQTIME,
	QUEC_TASK_NAME_SLEEP_DEBUG,
	QUEC_TASK_NAME_POWERCTL,
	QUEC_TASK_NAME_NC_KALIVE,
	QUEC_TASK_NAME_KALIVE_SEND,
	QUEC_TASK_NAME_FTP_CNF_WORK,
	QUEC_TASK_NAME_LWM2MCNF,
	QUEC_TASK_NAME_LWM2MAT,
	QUEC_TASK_NAME_LWM2IME,
	QUEC_TASK_NAME_TEMP,
	QUEC_TASK_NAME_LOCATOR_WORK,
	QUEC_TASK_NAME_USIM_DETECT,
	QUEC_TASK_NAME_MSG_HANDLE,
	QUEC_TASK_NAME_LED,
    QUEC_TASK_NAME_MMSEND,
    QUEC_TASK_NAME_TCPUDPAPP,
    QUEC_TASK_NAME_ALBS,
    QUEC_TASK_NAME_ALDYNREG,
	QUEC_TASK_NAME_QUECTHING,
    QUEC_TASK_NAME_SMTP_WORK,
    QUEC_TASK_NAME_TC_IOT,
    QUEC_TASK_NAME_TC_IOT_HTTP,
    QUEC_TASK_NAME_TC_IOT_RECONNECT,
    QUEC_TASK_NAME_TC_IOT_RE_SUB,
    QUEC_TASK_NAME_AT_SOCKET,
	QUEC_TASK_NAME_QUECFOTA,
	QUEC_TASK_NAME_QLWIP,
    QUEC_TASK_NAME_IPCAPPCNF,
    QUEC_TASK_NAME_AT_IPCAPP,
	QUEC_TASK_NAME_NETMODE,
    QUEC_TASK_NAME_PG_KEEPALIVE,
	QUEC_TASK_NAME_ALLIED_NETMODE,
	QUEC_TASK_NAME_QHB,
	QUEC_TASK_NAME_QHBRECV,
	QUEC_TASK_NAME_QGPIOCTRL,
	QUEC_TASK_NAME_MECMGL,
    QUEC_OPEN_MAIN,    
#ifdef QUECTEL_CTWing_SUPPORT
	QUEC_TASK_NAME_AT_CTWING,
	QUEC_TASK_NAME_AT_CTWING_POST,
	QUEC_TASK_NAME_CTWING_AUTO,
#endif
#ifdef QUEC_ADC_SUPPORT
    QUEC_TASK_NAME_ADCDET,
#endif
#if QUEC_SMS_QCMGSP_SUPPORT
    QUEC_TASK_NAME_QCMGSP,
#endif
#ifdef QUEC_NETDUALCH_CFG
	QUEC_TASK_NAME_NETDUALCHCFG,
#endif
	QUEC_TASK_NAME_MAX,
}quec_task_name_e;


/*========================================================================
 *  Quectel Task Management
 *========================================================================*/
extern const char * const quec_task_name[QUEC_TASK_NAME_MAX];

extern QuecOSStatus quec_rtos_init( void );

QuecOSStatus quec_rtos_task_create
(
	quec_task_t * taskRef,				/* OS task reference					   	*/
	uint32		  stackSize,			/* number of bytes in task stack area	   	*/
	uint8	 	  priority,				/* task priority 0 - 31 				   	*/
	char	    * taskName,				/* task name							   	*/
	void	  ( * taskStart)(void*), 	/* pointer to task entry point 	   	   		*/
	void*	      argv,					/* task entry argument pointer			   	*/
	...
);

QuecOSStatus quec_rtos_task_create_ex
(
	quec_task_t * taskRef,				/* OS task reference					   	*/
	uint32		  stackSize,			/* number of bytes in task stack area	   	*/
	uint8	 	  priority,				/* task priority 0 - 31 				   	*/
	char	    * taskName,				/* task name							   	*/
	void	  ( * taskStart)(void*), 	/* pointer to task entry point 	   	   		*/
	void*	      argv,					/* task entry argument pointer			   	*/
	...
);


extern QuecOSStatus quec_rtos_task_delete
(
	quec_task_t taskRef		/* OS task reference	*/
);

extern QuecOSStatus quec_rtos_task_delete_worker_start(void);

extern QuecOSStatus quec_rtos_task_delete_ex
(
	quec_task_t taskRef		/* OS task reference	*/
);

extern QuecOSStatus quec_rtos_task_suspend
(
	quec_task_t taskRef		/* OS task reference	*/
);

extern QuecOSStatus quec_rtos_task_resume
(
	quec_task_t taskRef		/* OS task reference	*/
);

extern QuecOSStatus quec_rtos_task_change_priority
(
	quec_task_t taskRef,			/* OS task reference			*/
	uint8 		new_priority,		/* OS task new priority	for in	*/
	uint8 		*old_priority		/* OS task old priority	for out	*/
);

extern QuecOSStatus quec_rtos_task_get_priority
(
	quec_task_t taskRef,		/* OS task reference			*/
	uint8 * 	priority_ptr	/* OS task priority for out		*/
);

extern void 		quec_rtos_task_yield(void);

extern QuecOSStatus quec_rtos_task_get_current_ref
(
	quec_task_t * taskRef		/* OS task reference	*/
);

extern void 		quec_rtos_task_sleep_ms
(
	uint32 ms	/* OS task sleep time for ms	*/
);

extern void 		quec_rtos_task_sleep_s
(
	uint32 s	/* OS task sleep time for s		*/
);

extern QuecOSStatus quec_rtos_task_sched_lock(void);

extern QuecOSStatus quec_rtos_task_sched_unlock(void);

extern QuecOSStatus quec_rtos_hisr_get_priority
(
	quec_task_t taskRef,		/* OS task reference			*/
	uint8 		*priority_ptr	/* OS task priority for out		*/
);

extern QuecOSStatus quec_rtos_hisr_get_current_ref
(
	quec_task_t* taskRef		/* OS task reference	*/
);



/*========================================================================
 *  Quectel Semaphore Management
 *========================================================================*/

extern QuecOSStatus quec_rtos_semaphore_create
(
	quec_sem_t  *semaRef,       /* OS semaphore reference                     	*/
	uint32      initialCount    /* initial count of the semaphore             	*/
);

extern QuecOSStatus quec_rtos_semaphore_wait
(
	quec_sem_t  semaRef,       /* OS semaphore reference                     	*/
	uint32      timeout    	   /* QUEC_WAIT_FOREVER, QUEC_NO_WAIT, or timeout	*/
);

extern QuecOSStatus quec_rtos_semaphore_release
(
	quec_sem_t   semaRef        /* OS semaphore reference						*/
);

extern QuecOSStatus quec_rtos_semaphore_get_cnt
(
	quec_sem_t  semaRef,       /* OS semaphore reference           				*/
	uint32    * cnt_ptr    	   /* out-parm to save the cnt of semaphore      	*/
);

extern QuecOSStatus quec_rtos_semaphore_delete
(
	quec_sem_t   semaRef        /* OS semaphore reference                  		*/
);



/*========================================================================
 *  Quectel Mutex Management
 *========================================================================*/
 
extern QuecOSStatus quec_rtos_mutex_create
(
    quec_mutex_t  *mutexRef        /* OS mutex reference                         */
);

extern QuecOSStatus quec_rtos_mutex_lock
(
	quec_mutex_t  mutexRef,       /* OS mutex reference                         */
	uint32        timeout   	  /* mutex wait timeout		             		*/
);

extern QuecOSStatus quec_rtos_mutex_try_lock
(
	quec_mutex_t  mutexRef        /* OS mutex reference                         */
);

extern QuecOSStatus quec_rtos_mutex_unlock
(
	quec_mutex_t  mutexRef        /* OS mutex reference                         */
);

extern QuecOSStatus quec_rtos_mutex_delete
(
	quec_mutex_t  mutexRef        /* OS mutex reference                         */
);



/*========================================================================
 *  Quectel Queue Management
 *========================================================================*/

extern QuecOSStatus quec_rtos_queue_create
(
	quec_queue_t   *msgQRef,       		/* OS message queue reference              */
	uint32      	maxSize,        	/* max message size the queue supports     */
	uint32      	maxNumber	      	/* max # of messages in the queue          */
);

extern QuecOSStatus quec_rtos_queue_wait
(
	quec_queue_t   	msgQRef,		/* message queue reference                 		*/
	uint8	      	*recvMsg,       /* pointer to the message received         		*/
	uint32       	size, 			/* size of the message                     		*/
	uint32      	timeout         /* QUEC_WAIT_FOREVER, QUEC_NO_WAIT, or timeout  */
);

extern QuecOSStatus quec_rtos_queue_release
(
    quec_queue_t	msgQRef,        /* message queue reference                 			*/
    uint32      	size,           /* size of the message                     			*/
    uint8       	*msgPtr,        /* start address of the data to be sent    			*/
    uint32      	timeout         /* QUEC_WAIT_FOREVER, QUEC_NO_WAIT, or timeout   	*/
);

extern QuecOSStatus quec_rtos_queue_get_cnt
(
	quec_queue_t	msgQRef,        /* message queue reference                 		*/
	uint32    		*cnt_ptr    	/* out-parm to save the cnt of message queue	*/
);

extern QuecOSStatus quec_rtos_queue_delete
(
	quec_queue_t	msgQRef         /* message queue reference                 		*/
);



/*========================================================================
 *  Quectel Mailbox Management
 *========================================================================*/

extern QuecOSStatus quec_rtos_mailbox_create
(
    quec_mailbox_t	*mboxQRef,      /* OS mailbox queue reference              		*/
    uint32			maxNumber       /* max # of messages in the queue          		*/
);

extern QuecOSStatus quec_rtos_mailbox_wait
(
    quec_mailbox_t	mboxQRef,		/* OS mailbox queue reference              		*/
    void            **recvMsg,      /* pointer to the message received         		*/
    uint32			timeout         /* QUEC_WAIT_FOREVER, QUEC_NO_WAIT, or timeout  */
);

extern QuecOSStatus quec_rtos_mailbox_release
(
    quec_mailbox_t	mboxQRef,       /* OS mailbox queue reference                 		*/
    uint8       	*msgPtr,        /* start address of the data to be sent    			*/
    uint32      	timeout         /* QUEC_WAIT_FOREVER, QUEC_NO_WAIT, or timeout   	*/
);

extern QuecOSStatus quec_rtos_mailbox_get_cnt
(
	quec_mailbox_t  mboxQRef,       /* OS mailbox queue reference              		*/
	uint32    		*cnt_ptr    	/* out-parm to save the cnt of mailbox          */
);

extern QuecOSStatus quec_rtos_mailbox_delete
(
	quec_mailbox_t	mboxQRef         /* OS mailbox queue reference	*/
);



/*========================================================================
 *  Quectel Flag Management
 *========================================================================*/

extern QuecOSStatus quec_rtos_flag_create
(
    quec_flag_t	*flagRef       /* OS flag reference              		*/
);

extern QuecOSStatus quec_rtos_flag_wait
(
	quec_flag_t		flagRef,		/* OS flag reference 					   		*/
	uint32			mask,			/* flag mask to wait for				   		*/
	quec_flag_op_e	operation,		/* QUEC_FLAG_AND, QUEC_FLAG_AND_CLEAR,	   		*/
									/* QUEC_FLAG_OR, QUEC_FLAG_OR_CLEAR		   		*/
	uint32			*flags, 		/* Current value of all flags			   		*/
	uint32			timeout 		/* QUEC_WAIT_FOREVER, QUEC_NO_WAIT, or timeout  */
);

extern QuecOSStatus quec_rtos_flag_release
(
	quec_flag_t	flagRef,            /* OS flag reference 					   		*/
	uint32		mask,               /* flag mask to wait for				   		*/
	uint32		operation           /* QUEC_FLAG_AND, QUEC_FLAG_AND_CLEAR,	   		*/
									/* QUEC_FLAG_OR, QUEC_FLAG_OR_CLEAR		   		*/
);

extern QuecOSStatus quec_rtos_flag_delete
(
	quec_flag_t	flagRef         /* OS flag reference	*/
);



/*========================================================================
 *  Quectel Timer Management
 *========================================================================*/

extern QuecOSStatus quec_rtos_timer_create
(
	quec_timer_t * timerRef					/* OS supplied timer reference	*/
);

extern QuecOSStatus quec_rtos_timer_start
(
	quec_timer_t	timerRef,       			/* OS supplied timer reference             			*/
	uint32     	 	initialTime,    			/* initial expiration time in ms           			*/
	bool      		cyclicalEn, 				/* wether to enable the cyclical mode or not		*/
	void        	(*callBackRoutine)(UINT32), /* timer call-back routine     						*/
	uint32      	timerArgc       			/* argument to be passed to call-back on expiration */
);

extern QuecOSStatus quec_rtos_timer_stop
(
	quec_timer_t timerRef 				/* OS supplied timer reference	*/
);

extern QuecOSStatus quec_rtos_timer_get_status
(
	quec_timer_t 		timerRef, 				/* OS supplied timer reference										*/
	quec_timer_status_t	*timerStatus			/* OS timer status: QUEC_TMR_STA_ENABLED, QUEC_TMR_STA_DISABLED		*/
);

extern QuecOSStatus quec_rtos_timer_delete
(
	quec_timer_t timerRef 				/* OS supplied timer reference	*/
);

extern uint64 		quec_rtos_get_systime(void);
extern char *quec_get_current_task_name(void);


#define 			quec_rtos_running_time_measure_prepare()		uint64  quec_systime_start = 0

#define 			quec_rtos_running_time_measure_start()			do{quec_systime_start = quec_rtos_get_systime();}while(0)

#define 			quec_rtos_running_time_measure_stop(during)		do{during = (quec_rtos_get_systime() - quec_systime_start);}while(0)

#endif


