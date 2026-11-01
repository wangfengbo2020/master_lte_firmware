#ifndef __QL_DENOISE_H__
#define __QL_DENOISE_H__

#ifdef __cplusplus
extern "C" {
#endif

#define SPEECH_TO_TEXT_SIZE 40
typedef void   (*app_event_result_process_handler_t)(void* event_data); 
typedef void   (*app_kws_task_destroy_cb_t)(void);
typedef void   (*app_kws_variable_delete_cb_t)(void);
    
/*save from app appkey/secret and do cb when the result recived from ser */
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
/* lvl：降噪等级，可调范围：0.2~4.0，1.0为基础，1.0以下减小降噪效果，1.0以上增大降噪效果 */
/* drc_post_gain：DRC Gain,算法内未做限制，觉得声音小就往上调整 */
/***************************************************/
void *ql_kws_init(void);


/***************************************************/
/* 算法处理，只支持8ms一帧                          */
/***************************************************/
int ql_kws_process(void* inst,short* mic_in,int len);


/***************************************************/
/* 算法注销                                        */
/***************************************************/
void ql_kws_cleanup(void *inst);


#ifdef __cplusplus
}
#endif

#endif
