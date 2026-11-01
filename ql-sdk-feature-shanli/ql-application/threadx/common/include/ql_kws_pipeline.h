#ifndef __KWS_PROCESS_H__
#define __KWS_PROCESS_H__


#define SPEECH_TO_TEXT_SIZE 40
typedef void   (*app_event_result_process_handler_t)(void* event_data); 
typedef void   (*app_kws_task_destroy_cb_t)(void);
typedef void   (*app_kws_variable_delete_cb_t)(void);

typedef struct
{    
   app_event_result_process_handler_t      process_cb;
   app_kws_task_destroy_cb_t               task_destroy_cb;
   app_kws_variable_delete_cb_t            variable_delete_cb;
   char speech_to_text_appkey[SPEECH_TO_TEXT_SIZE];
   char speech_to_text_secret[SPEECH_TO_TEXT_SIZE];
}kws_app_info_t;


/***************************************************/
/* 获取算法所需的动态内存大小，已经在x86上计算过所 */
/* 需内存大小，存到了全局变量中                    */
/***************************************************/
unsigned int ql_kws_dsp_get_memory_needed(void);


/***************************************************/
/* 把申请到的内存首地址传递给算法，算法内部有整套独*/
/* 立的与平台无关的动态内存管理策略                */
/***************************************************/
void ql_kws_set_memory_base(void *base, unsigned int total);


/***************************************************/
/* 算法初始化                                     */
/***************************************************/
void *ql_kws_init(void);


/***************************************************/
/* 算法处理                         */
/***************************************************/
int ql_kws_process(void* inst,short* mic_in,int len);


/***************************************************/
/* 算法注销                                        */
/***************************************************/
void ql_kws_cleanup(void *inst);


/***************************************************/
/*注册websocket事件，为发送音频做准备 */
/***************************************************/
int hal_websocket_start(void);

/***************************************************/
/*向服务器发送start信号*/
/***************************************************/
void websocket_send_start_signal(void);

/***************************************************/
/*向服务器发送音频数据*/
/* */
/***************************************************/
void hal_ws_send_write_msg(void *Msg, unsigned int len);


/***************************************************/
/*向服务器发送end数据*/
/***************************************************/
void hal_ws_send_end_write_msg(void );

/***************************************************/
/*向底层传入数据，appkey/secret 处理结果的回调函数*/
/***************************************************/
int ql_set_kws_app_info(kws_app_info_t *kws_app_info);




#endif /* __KWS_PROCESS_H__ */

