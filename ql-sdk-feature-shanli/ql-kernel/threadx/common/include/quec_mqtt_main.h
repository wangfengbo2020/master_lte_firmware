/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/





void quec_mqtt_worker_thread(void * argv);
void quec_mqtt_at_thread(void *argv);
int  quec_mqtt_main(void);
int  quec_mqtt_client_work_request(int msg_id, void* msg_data_ptr);
void  quec_mqtt_at_response(int msg_id, void* msg_data_ptr);
void quec_mqtt_set_timer_Semaphore_release(void);
#ifdef QUECT_ALIOT_FEATURE_SUPPORT
int  quec_aliot_mqtt_client_work_request(int msg_id, void* msg_data_ptr);
void  quec_aliot_at_response(int msg_id, void* msg_data_ptr);
#endif

#ifdef QUEC_TCIOT_SUPPORT
int  quec_tciot_mqtt_client_work_request(int msg_id, void* msg_data_ptr);
void  quec_tciot_at_response(int msg_id, void* msg_data_ptr);
#endif
#ifdef QUEC_MQTT_UNIFY_SUPPORT
void  quec_unify_at_response(int msg_id, void* msg_data_ptr);
void  quec_cuiot_at_response(int msg_id, void* msg_data_ptr);

#endif


