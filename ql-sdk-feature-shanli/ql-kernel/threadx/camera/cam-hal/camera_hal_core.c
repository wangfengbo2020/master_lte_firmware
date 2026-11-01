#include "quec_cust_feature.h"
#include "quec_rtos.h"
//#include "ui_os_api.h"
#include "camera_hal_core.h"
#include "quec_qr_code.h"
#include "quec_camera.h"
#include "bsp.h"
#include "cam_sensor.h"
//#include "ui_os_flag.h"
//#include "ui_os_task.h"


u8 camCoreInit = 0;
CCCoreHandle camCoreHandle;

CAL_IDENTITY_RESULT_STRUCT outdata;
extern CAM_DECODE_CONFIG_CTX g_cam_decode_config_ctx;

//fullsize stream call this function to release buffer for us.
int CCReleaseFullSizeBufferToCamera(void *useData, void* pBufIndex)
{
    CCError error = CRANE_CAMERA_ERROR_NONE;
    CCBufferQueue *pBufferQue = NULL;
    CCCameraDevice *pCamDevice = camCoreHandle.pCamDevice;
    quec_queue_t   msgQRef = NULL;
    struct isp_buf_msg *enqueueMsg = NULL;
    int bufIndex = -1;

    if (!useData || !pCamDevice || !pBufIndex) {
        CAMLOGE("invalid pointer");
        return CRANE_CAMERA_ERROR_BADPOINTER;
    }

    bufIndex = *((int*)pBufIndex);
    pBufferQue = (CCBufferQueue*)useData;

    if (bufIndex < 0 || bufIndex > pBufferQue->bufCnt) {
        CAMLOGE("the index %d is invalid!", bufIndex);
        return CRANE_CAMERA_ERROR_BADARGUMENT;
    }

    setBufferStatus(pBufferQue, bufIndex, CC_BUFFER_STATUS_IDLE);
	

    if (PIPELINE_ID_CAP == pBufferQue->pipeId)
        msgQRef = pCamDevice->fullSizeStreamMsgQRef;


    enqueueMsg = (struct isp_buf_msg *)malloc(sizeof(struct isp_buf_msg));
    if (!enqueueMsg) {
        CAMLOGE("UOS_MALLOC for enqueueMsg failed!");
        return CRANE_CAMERA_ERROR_OUTOFMEMORY;
    }
    enqueueMsg->msg_type = ISP_MSG_TYPE_HAL_EQUEUE;
    enqueueMsg->u.data_eof.buf_idx = bufIndex;
    enqueueMsg->u.data_eof.pipe_id = pBufferQue->pipeId;
	quec_rtos_queue_release( msgQRef,sizeof(enqueueMsg), &enqueueMsg, OS_NO_SUSPEND);


    return error;
}

//打印buffer的状态
CCError _CCDumpBufferStatus(CCBufferQueue *pBufferQue)
{
    CCError error = CRANE_CAMERA_ERROR_NONE;
    int_32 i = 0, bufCnt = 0;

    //txchk_cur_task_stack_print();

    if (!pBufferQue) {
        return CRANE_CAMERA_ERROR_BADPOINTER;
    }

    bufCnt = pBufferQue->bufCnt;
    for (i = 0; i < bufCnt; i++) {
        CAMLOGI("the %dth buffer status(0x%x) !", i, pBufferQue->bufPack[i].bufStatus);
    }

    return error;
}

CCError allocBuffers(CCBufferQueue *pBufferQue, uint_32 width, uint_32 height, PIPELINE_ID pipeId)
{
	CCError error = CRANE_CAMERA_ERROR_NONE;
	uint_32 totalSize = 0, unitSize = 0, extraSize = 0,allocHeight = 0;
	uint_8 bufCnt = 0;
	int remainder = 0;
	uint_8 i = 0;

	if (!pBufferQue)
		return CRANE_CAMERA_ERROR_BADPOINTER;

	allocHeight = height + pBufferQue->jpeg_head;
	//check buffer align
	if (pipeId == PIPELINE_ID_PREV || pipeId == PIPELINE_ID_VIDEO) {
		remainder = width % CC_CAM_ALIGN_TO_4;
		if (remainder > 0) {
			CAMLOGE("the width must align to 4!", __func__);
			return CRANE_CAMERA_ERROR_BADARGUMENT;
		}
	} else if (pipeId == PIPELINE_ID_CAP) {
		//   remainder = width % CC_CAM_ALIGN_TO_16;
		if (remainder > 0) {
			CAMLOGE("the width must align to 16!", __func__);
			return CRANE_CAMERA_ERROR_BADARGUMENT;
		}
	}

	bufCnt = pBufferQue->bufCnt;

	switch (pBufferQue->bufFormat) {
		case PIPE_OUT_FMT_YUV420_NV12:
		case PIPE_OUT_FMT_YUV420_NV21:
			unitSize = width * allocHeight * 3 / 2;
			break;
		case PIPE_OUT_FMT_YUV422_YUYV:
		case PIPE_OUT_FMT_YUV422_YVYU:
		case PIPE_OUT_FMT_YUV422_UYVY:
		case PIPE_OUT_FMT_YUV422_VYUY:
			unitSize = width * allocHeight * 2;
			break;
		case PIPE_OUT_FMT_RAW8:
        case PIPE_OUT_FMT_ONLY_Y:
			unitSize = width * allocHeight;
			break;
		case PIPE_OUT_FMT_JPEG:
			unitSize = width * allocHeight * 3 / 2;
			//for more than 2M(1600x1200) case, jpeg buffer size use 1/4*(NV12 Size), otherwise 1/3*(NV12 Size)
			if(width >= 1600) {
				unitSize = unitSize / 4;
			} else {
				unitSize = unitSize / 3;
			}
			break;
		default:
			CAMLOGE("unsupported format 0x%x!", pBufferQue->bufFormat);
			return CRANE_CAMERA_ERROR_BADARGUMENT;
	}

	totalSize = bufCnt * unitSize + extraSize;
	CAMLOGV("malloc 0x%x size!", totalSize);

	//use UI_MALLOC(CP) to make sure the addr is 32bytes aligned,UOS_MALLOC is 4 bytes aligned.
	if (pipeId == PIPELINE_ID_CAP) 
	{
		//the input addr for hardware jpeg encoder must not be 4 bytes aligned,otherwise it could cause image disorder.
		#ifdef __QUEC_CAMERA__ //shaohua@20201023 使用客户通过API 传入的buffer
		if(g_cam_decode_config_ctx.decbufaddr)
		{
			pBufferQue->jpeg_addr = (g_cam_decode_config_ctx.decbufaddr);			
		}
		else
		#endif
        {
		    pBufferQue->jpeg_addr = (void*)malloc(totalSize); 
        }
	} 
	else if(pipeId == PIPELINE_ID_PREV)
	{
		#ifdef __QUEC_CAMERA__
		if(g_cam_decode_config_ctx.prebufaddr)//如果客户不传入buffer则malloc
		{
		   pBufferQue->jpeg_addr = (g_cam_decode_config_ctx.prebufaddr);
		}
		else
		#endif
		{
			pBufferQue->jpeg_addr = (void*)malloc(totalSize);
		}
	}

 	if (!pBufferQue->jpeg_addr) {
		CAMLOGE("UI_MALLOC 0x%x sizes for BufferQue falied!", totalSize);
		return CRANE_CAMERA_ERROR_OUTOFMEMORY;
 	}
	pBufferQue->addr = (void*)((uint_32)(pBufferQue->jpeg_addr) + (pBufferQue->jpeg_head * width * 3 /2));
	CacheCleanAndInvalidateMemory((void *)(pBufferQue->jpeg_addr), totalSize);

	CAMLOGV("allocBuffers %d sizes for BufferQue(0x%p) successful!", totalSize, pBufferQue->jpeg_addr);
	pBufferQue->totalSize = totalSize;
	pBufferQue->unitSize = unitSize;
	pBufferQue->width = width;
	pBufferQue->height = height;
	pBufferQue->pipeId = pipeId;
	fillIspOnlineBuffer(pBufferQue);
	for ( i = 0; i < bufCnt; i++) {
		setBufferStatus(pBufferQue, i, CC_BUFFER_STATUS_IDLE);
	}

	return error;
}
CCError freeBuffers(CCBufferQueue *pBufferQue)
{
	CCError error = CRANE_CAMERA_ERROR_NONE;

	if (!pBufferQue)
		return CRANE_CAMERA_ERROR_BADPOINTER;

	if (!pBufferQue->jpeg_addr)
		return CRANE_CAMERA_ERROR_BADPOINTER;

	CAMLOGV("freeBuffers %d sizes for BufferQue(0x%p) successful!", pBufferQue->totalSize, pBufferQue->jpeg_addr);

	if (PIPELINE_ID_CAP == pBufferQue->pipeId)
	{
#ifdef __QUEC_CAMERA__//shaohua@20201023使用客户通过API 传入的buffer
		if(g_cam_decode_config_ctx.decbufaddr != NULL&&pBufferQue->jpeg_addr)
        {
            pBufferQue->jpeg_addr=NULL;//pony 2021-01-21客户传入的buffer，此处不进行释放
        }
		else
#endif
        {
            if(pBufferQue->jpeg_addr)
            {
    		    free(pBufferQue->jpeg_addr);
                pBufferQue->jpeg_addr = NULL;
            }
        }
	}
	else if(pBufferQue->pipeId == PIPELINE_ID_PREV)
	{
#ifdef __QUEC_CAMERA__//shaohua@20201023 使用客户通过API 传入的buffer
        if(g_cam_decode_config_ctx.prebufaddr!=NULL&&pBufferQue->jpeg_addr)
        {
            pBufferQue->jpeg_addr=NULL;//pony 2021-01-21预览camera buf不释放
        }
        else
#endif
         {
            if(pBufferQue->jpeg_addr)
            {   
    		    free(pBufferQue->jpeg_addr);
                pBufferQue->jpeg_addr = NULL;
            }
         }
	}

	return error;
}

void CCCamFullSizeStreamThread(void* argv)
{
	CCCameraDevice *pCamDevice = NULL;
	OSA_STATUS osaStatus = 0;
	uint_32   actual_flags = 0;
	quec_queue_t   msgQRef = NULL;

	struct isp_buf_msg *ispMsg = NULL;
	CCBufferQueue *pBufferQue = NULL;
	uint_8 pipe_id = 0, buf_idx = 0;
	CCError error = CRANE_CAMERA_ERROR_NONE;
	uint_32 frameId = 0;
	uint_32 onlineWaitTime = ONLINE_TIME_OUT;
	CCIspPipeSwitch ispPipeSwitch;

	pCamDevice = (CCCameraDevice *)argv;

	if (!pCamDevice) {
		CAMLOGE("the argument pCamDevice is NULL!");
		return;
	}
	onlineWaitTime = 1000 / pCamDevice->minFps * TIMEOUT_FRAME;
	CAMLOGI("CCCamFullSizeStreamThread timeout=%dms",onlineWaitTime);

	msgQRef = pCamDevice->fullSizeStreamMsgQRef;
	pBufferQue = &pCamDevice->fullSizeStreamBufQue;

	//wait start work event.
	while(1)
	{
		osaStatus = quec_rtos_flag_wait(pCamDevice->threadSyncFlagRef, FULLSIZE_READYWORK, OSA_FLAG_OR_CLEAR, &actual_flags, OS_SUSPEND);

		if (osaStatus == OS_SUCCESS && (actual_flags & FULLSIZE_READYWORK))
		{
		    //CAMLOGD("PERPARE  WAIT EOF");
			break;
		}
	}
	
	do 
	{
		OSAMsgQRecv(msgQRef,&ispMsg,4, onlineWaitTime / TICK_PER_MS);

		
		if (!ispMsg)
		{
			CAMLOGW("receive camera drv buffer timeout, continue!");
			_CCDumpBufferStatus(pBufferQue);
			continue;
		}

		switch (ispMsg->msg_type) 
		{
			case ISP_MSG_TYPE_EOF:
				/* some buffer ready,we ready to dequeue. */
				pipe_id = ispMsg->u.data_eof.pipe_id;
				buf_idx = ispMsg->u.data_eof.buf_idx;
				error = dequeueBuffer(pBufferQue, buf_idx, pipe_id);//出队
				if (error != CRANE_CAMERA_ERROR_NONE)
				{
					CAMLOGE("dequeueBuffer the %d buffer failed for 0x%x!", buf_idx, error);
					free((void*)ispMsg);
					ispMsg = NULL;
					continue;
				}

			#ifdef __QUEC_CAMERA__
				setBufferStatus(pBufferQue, buf_idx, CC_BUFFER_STATUS_FULLSIZE);
				quec_debug_print_uart("-------[CAM]FRAME- end-------%d \n",buf_idx);
				{
					uint_8* jpegbuffer = (uint_8 *)(pBufferQue->bufPack[buf_idx].ispBuffer.buffer.planes[0].addr);//获取Y数据
					CacheInvalidateMemory((void *)(jpegbuffer), pBufferQue->width*pBufferQue->height);
					/*解码*/
					outdata.result = Ql_Camera_SYIdentifyCode((uint_8*)jpegbuffer,NULL,&outdata,CAM_SUPPORT_MAX_DECODE_LEN,pBufferQue->width,pBufferQue->height); 
					if(CAM_DECODE_SUCESS == outdata.result)
					{
						if(g_cam_decode_config_ctx.decodecb)
							g_cam_decode_config_ctx.decodecb(&outdata);
						else
							CAMLOGI("[CAM][Decode result:%s] Spend:ms\r\n",outdata.DataBuf);
					}
					else
					{
							CAMLOGI("[CAM] Decode Fail result(%d)\r\n",outdata.result);
					}
                    /*处理用户回调*/
                    //ql_cam_get_cust_cb(jpegbuffer,pBufferQue->width,pBufferQue->height);	

					#ifdef __QUEC_CAMERA_DEBUG__ //若需要将NV12数据输出到usbcdc请将此处打开 pony add 2021-06-01
						__QlUsbCdcDumpCameraData(1,jpegbuffer,pBufferQue->width,pBufferQue->height,0);
					#endif		
				}
				#ifdef QUEC_LCD_SUPPORT
				#ifdef QL_LCD
                if(g_cam_decode_config_ctx.preview==1)
                {
    				quec_send_buff_to_prev(ispMsg);//将isp数据转发给预览进行预览 pony 2021-03-01add		
                }
                else
				#endif
				#endif
                {//上面使用完buffer后，需要将buffer状态置位空闲，同时放入队列
    				setBufferStatus(pBufferQue, buf_idx, CC_BUFFER_STATUS_IDLE);
    				enqueueBuffer(pBufferQue, buf_idx, pBufferQue->pipeId);//入队
                }	
				
			#endif
				break;
			case ISP_MSG_TYPE_ERR_DROP_NO_BUF:
				frameId = ispMsg->u.data_drop_no_buf.frame_id;
				CAMLOGW("the %d buffer lose!", frameId);
				break;
			case ISP_MSG_TYPE_HAL_EQUEUE:
				buf_idx = ispMsg->u.data_eof.buf_idx;
				CAMLOGV("enqueue the %d buffer to video port!", buf_idx);
				enqueueBuffer(pBufferQue, buf_idx, pBufferQue->pipeId);
				break;
			case ISP_MSG_TYPE_HAL_FLUSH:
				if (!pCamDevice->previewVideoSamePipe) {
				        memset(&ispPipeSwitch, 0, sizeof(CCIspPipeSwitch));
				        ispPipeSwitch.snapshotSwitch= 1;
				        error = flushBuffer(pBufferQue, &ispPipeSwitch);
				        if (error != CRANE_CAMERA_ERROR_NONE) {
				            CAMLOGE("flushBuffer for video falied, %d!", error);
				        }
				}
				//flush video buffer
				pCamDevice->flushFullSizeStreamBuffers();
				CAMLOGI("flushBuffer for fullsize stream buffer done!");

				free((void*)ispMsg);
				//set event to the main thread
				quec_rtos_flag_release(pCamDevice->threadSyncFlagRef,FULLSIZE_STOPWORK, OSA_FLAG_OR);

				return;
			default:
				break;
		}

		free((void*)ispMsg);
		ispMsg = NULL;

	}while (1);
}


CCError CCStartFullSizeStream(CamRecordParmeters *pVideoRecordParam, uint_32 format)
{
	CCError error = CRANE_CAMERA_ERROR_NONE;
	struct isp_pipe_cfg pipeCfg;
	CCBufferQueue *pBufferQue = NULL;
	CCCameraDevice *pCamDevice = NULL;
	OSA_STATUS osaStatus = 0;
	int_32 i;
	CCIspPipeSwitch ispPipeSwitch;
	xbool sendWorkFlag = false;
	struct isp_output_size ispResInfo = {0};
	struct isp_sensor_cfg sensorCfg;

	if (!camCoreHandle.pCamDevice)
	{
		CAMLOGE("the argument pCamDevice is NULL, camera has not been opend!");
		return CRANE_CAMERA_ERROR_BADPOINTER;
	} else {
		pCamDevice = camCoreHandle.pCamDevice;
		sensorCfg.sensor_id = pCamDevice->sensorId;
		sensorCfg.skip_frame_n = 1;
	}
	quec_rtos_mutex_lock(camCoreHandle.CamDeviceMutex,QUEC_WAIT_FOREVER);
	if (!pVideoRecordParam || !pVideoRecordParam->enqueueCamRecordBuffer
		|| !pVideoRecordParam->flushCamRecordBuffers) 
	{
		CAMLOGE("the videoRecordParam is invalid handle=0x%p!", pVideoRecordParam);
		quec_rtos_mutex_unlock(camCoreHandle.CamDeviceMutex);
        	return CRANE_CAMERA_ERROR_BADARGUMENT;
	}
	if (!pCamDevice) {
		CAMLOGE("FullSizeStream must open camera");
		quec_rtos_mutex_unlock(camCoreHandle.CamDeviceMutex);
		return CRANE_CAMERA_ERROR_INVALIDOPERATION;
	}

	if (pCamDevice->camStatus & CAMERA_STATUS_FULLSIZE_STREAM) {
		CAMLOGE("FullSizeStream is in progress!");
		quec_rtos_mutex_unlock(camCoreHandle.CamDeviceMutex);
		return CRANE_CAMERA_ERROR_INVALIDOPERATION;
	}

	pCamDevice->minFps = 5;
	pCamDevice->maxFps = 30;

	if(!pCamDevice->alreadyCfgSensor)
	{
		error = configCamera(&sensorCfg, NULL);
		pCamDevice->alreadyCfgSensor = true;
	}
	if (error != CRANE_CAMERA_ERROR_NONE) {
		CAMLOGE("configCamera for camera fullsize failed!");
		goto Error_exit;
	}
	// get sensor size(isp p2 output size)
	error = getIspRes(&ispResInfo);
	if (error != CRANE_CAMERA_ERROR_NONE) {
		CAMLOGE("getIspRes failed, %d!", error);
		goto Error_exit;
	}
	CAMLOGI("getIspRes wxh [%dx%d]", ispResInfo.width,ispResInfo.height);

	pCamDevice->sensorWidth = ispResInfo.width;
	pCamDevice->sensorHeight = ispResInfo.height;

	//1.prepare for fullsize stream thread and msgqueue with drv.

	pCamDevice->fullSizeStreamMsgQRef = NULL;
	//quec_rtos_queue_create(&(pCamDevice->fullSizeStreamMsgQRef), sizeof(unsigned int), TASK_DEFAULT_MSGQ_SIZE);
	OSAMsgQCreate(&(pCamDevice->fullSizeStreamMsgQRef), "CamFullQ", 4, 64, OS_FIFO);
	quec_rtos_task_create
	(
		&(pCamDevice->fullSizeStreamTaskRef),				/* OS task reference						*/
		CAMERA_VIDEO_TASK_SIZE+CAMERA_DECODE_TASK_SIZE,			/* number of bytes in task stack area		*/
		g_cam_decode_config_ctx.dectaskprio, 			/* task priority 0 - 31 					*/
		"uiCamFull", 			/* task name								*/
		CCCamFullSizeStreamThread,	/* pointer to task entry point				*/
		(void *)pCamDevice
	);


	if (pCamDevice->fullSizeStreamTaskRef == NULL) 
	{
		CAMLOGE("UOS_CreateTask for camera fullsize failed, error code = %d!", osaStatus);
		error = CRANE_CAMERA_ERROR_FATALERROR;
		goto Error_exit;
	}
	
	//通过Sensor输出的格式的配置来设置isp输出的格式
	int sensor_fmt = quec_get_cursensor_out_format();
	if(sensor_fmt == SENSOR_FMT_RAW8)
	{
		format = PIPE_OUT_FMT_RAW8;
	}
	else if(SENSOR_FMT_YUV422 == sensor_fmt)
	{
		format = PIPE_OUT_FMT_YUV420_NV12;
	}
	else if(SENSOR_FMT_ONLY_Y == sensor_fmt )
	{
		format = PIPE_OUT_FMT_ONLY_Y;
	}
	else 
	{
		CAMLOGE("Invaid Senor_Format (%d) ", sensor_fmt);
		error = CRANE_CAMERA_ERROR_FATALERROR;
		goto Error_exit;
	}
	
	//2.config isp : enable capture port.
	pipeCfg.pipe_id = PIPELINE_ID_CAP;
	pipeCfg.pipe_enable = 1;
	pipeCfg.data_range = 0;
	pipeCfg.zoom = pCamDevice->currentZoomLevel;
	pipeCfg.output_format = (PIPE_OUT_FMT)format;//PIPE_OUT_FMT_YUV420_NV12; //PIPE_OUT_FMT_RAW8;
	pipeCfg.pipe_outw = pCamDevice->sensorWidth;
	pipeCfg.pipe_outh = pCamDevice->sensorHeight;

	error = configCamera(/* paramter, */NULL, &pipeCfg);
	if (error != CRANE_CAMERA_ERROR_NONE) 
	{
		CAMLOGE("configpipe for  fullsize failed!");
		goto Error_exit;
	}

	//3.request buffers.
	pBufferQue = &(pCamDevice->fullSizeStreamBufQue);
	error = requestBuffers(pBufferQue, g_cam_decode_config_ctx.decbufcnt, PIPELINE_ID_CAP, pCamDevice->fullSizeStreamMsgQRef);
	if (error != CRANE_CAMERA_ERROR_NONE) 
	{
		CAMLOGE("requestBuffers for camera fullsize failed!");
		goto Error_exit;
	}

	//alloc buffer for fullsize
	pBufferQue->bufQueMutexRef = NULL;
	quec_rtos_mutex_create(&pBufferQue->bufQueMutexRef);

	pBufferQue->bufFormat = (PIPE_OUT_FMT)format;//PIPE_OUT_FMT_YUV420_NV12; //PIPE_OUT_FMT_RAW8;
	
#ifdef __QUEC_CAMERA__
	if(g_cam_decode_config_ctx.decbufcnt>0)
	{
		pBufferQue->bufCnt = g_cam_decode_config_ctx.decbufcnt;
	}
	else
#endif
	pBufferQue->bufCnt = PREVIEW_BUFFER_NUM;

	error = allocBuffers(pBufferQue, pCamDevice->sensorWidth, pCamDevice->sensorHeight, PIPELINE_ID_CAP);
	if (error != CRANE_CAMERA_ERROR_NONE) {
		CAMLOGE("allocBuffers for fullsize failed, %d!", error);
		error = CRANE_CAMERA_ERROR_OUTOFMEMORY;
		goto Error_exit;
	}

	//4.enqueue all fullsize buffer
	for(i = 0; i < pBufferQue->bufCnt; i++) {
		error = enqueueBuffer(pBufferQue, i, PIPELINE_ID_CAP);
		if (error != CRANE_CAMERA_ERROR_NONE) {
			CAMLOGE("enqueue the %d Buffer for fullsize falied, %d!", i, error);
			goto Error_exit;
		}
	}

	//set paramters for video encoder
	pVideoRecordParam->setReleaseBufferCallBack(CCReleaseFullSizeBufferToCamera, (void*)(&pCamDevice->fullSizeStreamBufQue));

	pCamDevice->qBufForFullSizeStream = pVideoRecordParam->enqueueCamRecordBuffer;
	pCamDevice->flushFullSizeStreamBuffers = pVideoRecordParam->flushCamRecordBuffers;

	//5.notify the thread ready to work	
	osaStatus = quec_rtos_flag_release(pCamDevice->threadSyncFlagRef,FULLSIZE_READYWORK, OSA_FLAG_OR);

	if (osaStatus != OS_SUCCESS) {
		CAMLOGE("OSAFlagSet workflag for camera fullsize thread, error code = %d!", osaStatus);
		error = CRANE_CAMERA_ERROR_FATALERROR;
		goto Error_exit;
	} else
		sendWorkFlag = true;

	//6.stream on
	memset(&ispPipeSwitch, 0, sizeof(CCIspPipeSwitch));
	ispPipeSwitch.snapshotSwitch= 1;
	error = streamOnPipe(&ispPipeSwitch);
	if (error != CRANE_CAMERA_ERROR_NONE) {
		CAMLOGE("streamOnPipe for fullsize falied, %d!", error);
		goto Error_exit;
	} else {
		pCamDevice->camStatus |= CAMERA_STATUS_FULLSIZE_STREAM;
	}

	if(pCamDevice->uiParam.nightMode)
		setCameraFPS(pCamDevice->uiParam.nightModeFps, pCamDevice->maxFps, BANDING_50HZ);
	else
		setCameraFPS(pCamDevice->minFps, pCamDevice->maxFps, BANDING_50HZ);
	quec_rtos_mutex_unlock(camCoreHandle.CamDeviceMutex);

	CAMLOGD("start fullsize stream successful!");
	return error;

Error_exit:
	if (sendWorkFlag)
	{
		quec_rtos_task_suspend(pCamDevice->fullSizeStreamTaskRef);
	}

	if (pCamDevice->fullSizeStreamTaskRef) 
	{
		quec_rtos_task_delete(pCamDevice->fullSizeStreamTaskRef);

		pCamDevice->fullSizeStreamTaskRef = NULL;
	}

	if (pBufferQue) 
	{
		if (pBufferQue->totalSize > 0) {
			freeBuffers(pBufferQue);
		}
		if (NULL != pBufferQue->bufQueMutexRef) 
		{
			quec_rtos_mutex_delete(pBufferQue->bufQueMutexRef);
			pBufferQue->bufQueMutexRef = NULL;
		}

	}
	
	if (NULL != pCamDevice->fullSizeStreamMsgQRef)
	{
		quec_rtos_queue_delete(pCamDevice->fullSizeStreamMsgQRef);
		pCamDevice->fullSizeStreamMsgQRef = NULL;
	}
	quec_rtos_mutex_unlock(camCoreHandle.CamDeviceMutex);

	return error;
}


CCError CCStopFullSizeStream(void)
{
	CCError error = CRANE_CAMERA_ERROR_NONE;
	struct isp_buf_msg *ispMsg = NULL;
	CCCameraDevice *pCamDevice = NULL;
	uint_32   actual_flags = 0;
	CCIspPipeSwitch ispPipeSwitch;
	OSA_STATUS osaStatus = OS_SUCCESS;
	xbool sendFlushMsg = false;
	
	quec_queue_t tempRef = 0;


	if (!camCoreHandle.pCamDevice) {
		CAMLOGE("the argument pCamDevice is NULL, camera has not been opend!");
		return CRANE_CAMERA_ERROR_BADPOINTER;
	} else {
		pCamDevice = camCoreHandle.pCamDevice;
	}
	quec_rtos_mutex_lock(camCoreHandle.CamDeviceMutex,QUEC_WAIT_FOREVER);

	if (!(pCamDevice->camStatus & CAMERA_STATUS_FULLSIZE_STREAM)) {
		CAMLOGE("must start fullsize stream first!");
		quec_rtos_mutex_unlock(camCoreHandle.CamDeviceMutex);

		return CRANE_CAMERA_ERROR_INVALIDOPERATION;
	}

	//1.stream off
	memset(&ispPipeSwitch, 0, sizeof(CCIspPipeSwitch));
	ispPipeSwitch.snapshotSwitch= 1;
	error = streamOffPipe(&ispPipeSwitch, false);
	if (error != CRANE_CAMERA_ERROR_NONE) {
		CAMLOGE("streamOffPipe for fullsize stream falied, %d!", error);
	}

	//2.send flush buffers msg.
	ispMsg = (struct isp_buf_msg*)malloc(sizeof(struct isp_buf_msg));
	if (!ispMsg) {
		CAMLOGE("Uos malloc for isp_buf_msg failed!");		
		quec_rtos_task_suspend(pCamDevice->fullSizeStreamTaskRef);

		goto err_out;
	}
	memset(ispMsg, 0, sizeof(struct isp_buf_msg));
	ispMsg->msg_type = ISP_MSG_TYPE_HAL_FLUSH;
	quec_rtos_queue_release(pCamDevice->fullSizeStreamMsgQRef, sizeof(ispMsg),
		&ispMsg, OS_NO_SUSPEND);
	
	if (osaStatus != OS_SUCCESS) 
	{
		CAMLOGE("OSAMsgQSend flush message to fullsize stream thread falied, errcode %d!", osaStatus);
		quec_rtos_task_suspend(pCamDevice->fullSizeStreamTaskRef);

	} else
		sendFlushMsg = true;

	//3.wait thread flush buffer done.
	while (sendFlushMsg)
	{
		osaStatus = quec_rtos_flag_wait(pCamDevice->threadSyncFlagRef, FULLSIZE_STOPWORK, OSA_FLAG_OR_CLEAR, &actual_flags, OS_SUSPEND);

		if (osaStatus == OS_SUCCESS && (actual_flags & FULLSIZE_STOPWORK))
			break;
	}

err_out:
	//4. destory msgqueue and thred
		quec_rtos_task_delete(pCamDevice->fullSizeStreamTaskRef);


	//5.free all buffer
	freeBuffers(&pCamDevice->fullSizeStreamBufQue);
	
	quec_rtos_mutex_delete(pCamDevice->fullSizeStreamBufQue.bufQueMutexRef);

	//memset(&pCamDevice->fullSizeStreamBufQue, 0, sizeof(CCBufferQueue));


	pCamDevice->camStatus &= (~CAMERA_STATUS_FULLSIZE_STREAM);
	
	tempRef = pCamDevice->fullSizeStreamMsgQRef;
	pCamDevice->fullSizeStreamMsgQRef = NULL;
	quec_rtos_queue_delete(tempRef);


	pCamDevice->qBufForFullSizeStream= NULL;
	pCamDevice->flushFullSizeStreamBuffers= NULL;

	CAMLOGD("stop fullsize stream successfull!");
	
	quec_rtos_mutex_unlock(camCoreHandle.CamDeviceMutex);

	return error;
}

//目前仅仅创建一个锁
void _CamCoreInit()
{
	quec_rtos_mutex_create(&camCoreHandle.CamDeviceMutex);

}

CCError ataOpenCamera(int sensor_id)
{
    CCError error = CRANE_CAMERA_ERROR_NONE;
    CCCameraDevice *pCamDevice = NULL;
    int cameraCnt = -1;
    void *pMem = NULL;
    struct isp_sensor_cfg sensorCfg;

    CAMLOGI("ataOpenCamera start!");

    if (!camCoreInit)
	{
        _CamCoreInit();
        cam_hw_version_init();//CAM控制器硬件版本初始化
        camCoreInit= 1;
    }
	quec_rtos_mutex_lock(camCoreHandle.CamDeviceMutex,QUEC_WAIT_FOREVER);

    if (camCoreHandle.pCamDevice)
	{
        CAMLOGE("the camera has been opened\n!");
		
		quec_rtos_mutex_unlock(camCoreHandle.CamDeviceMutex);

        return CRANE_CAMERA_ERROR_DEVICEWASOPENED;
    }

	//1.检测Camera,读取Camera sensor 的id
    getSensorCapability(&camCoreHandle, &cameraCnt, 2, camCoreHandle.ispSensorInfo);

    pMem = (void *)malloc(sizeof(CCCameraDevice));
    if (!pMem) {
        CAMLOGE("malloc for CameraDevice failed!");
        error = CRANE_CAMERA_ERROR_OUTOFMEMORY;
        goto Error_exit;
    }

    pCamDevice = (CCCameraDevice*)pMem;
    memset(pCamDevice, 0, sizeof(CCCameraDevice));
    camCoreHandle.pCamDevice = pCamDevice;
	
    /* create event for thred sync. */
    pCamDevice->threadSyncFlagRef = NULL;
	quec_rtos_flag_create(&pCamDevice->threadSyncFlagRef);


    error = cameraDrvInit((SENSOR_ID)sensor_id);
    if (error != CRANE_CAMERA_ERROR_NONE)
	{
        CAMLOGE("camera diver init failed for %d!", error);
        error = CRANE_CAMERA_ERROR_FATALERROR;
        goto Error_exit;
    }
	
    pCamDevice->sensorId = (SENSOR_ID)sensor_id;
    pCamDevice->currentZoomLevel = 0x100;
    pCamDevice->minFps = 5;
    pCamDevice->maxFps = 30;
    pCamDevice->previewRotationDegree = ROT_90_DEG;

    sensorCfg.sensor_id = pCamDevice->sensorId;
    sensorCfg.skip_frame_n = 0;
    error = configCamera(&sensorCfg, NULL);
    pCamDevice->alreadyCfgSensor = true;
    if (error != CRANE_CAMERA_ERROR_NONE) 
	{
        CAMLOGE("configCamera failed, %d!", error);
        goto Error_exit;
    }
    setCameraFPS(pCamDevice->minFps, pCamDevice->maxFps, BANDING_50HZ);

	
    //not allow to enter d2----打开Camera,不允许休眠
    //uiSetSuspendFlag(LP_ID_CAMERA, 0);
    //uiC1CallbackRegister(LP_ID_CAMERA, _CCCameraEnterC1Handler, _CCCameraExitC1Handler);

	quec_rtos_mutex_unlock(camCoreHandle.CamDeviceMutex);


    CAMLOGD("ataopen the %d camera successful!", sensor_id);
    return error;

Error_exit:
    if (pCamDevice) 
	{
        /* destory thread sync mutex. */
	
	quec_rtos_flag_delete(pCamDevice->threadSyncFlagRef);

        free((void*)pCamDevice);
        camCoreHandle.pCamDevice = NULL;
    }
	quec_rtos_mutex_unlock(camCoreHandle.CamDeviceMutex);

    return error;
}

CCError ataCloseCamera(int sensor_id)
{
	CCError error = CRANE_CAMERA_ERROR_NONE;
	CCCameraDevice *pCamDevice = camCoreHandle.pCamDevice;

	CAMLOGI("ataCloseCamera");
	
	quec_rtos_mutex_lock(camCoreHandle.CamDeviceMutex,QUEC_WAIT_FOREVER);


	if (!pCamDevice) {
		CAMLOGE("the camera need open first!");
		
		quec_rtos_mutex_unlock(camCoreHandle.CamDeviceMutex);
			

		return CRANE_CAMERA_ERROR_INVALIDOPERATION;
	}

	cameraDrvDeinit(sensor_id);

	if (pCamDevice) {
		/* destory thread sync mutex. */
		quec_rtos_flag_delete(pCamDevice->threadSyncFlagRef);


		free((void*)pCamDevice);
	    camCoreHandle.pCamDevice = NULL;
	}
	//allow to enter d2
	//uiSetSuspendFlag(LP_ID_CAMERA, 1);
	//SleepFlag_CAM_DMA_Set(0);//设置flag，允许open camera后，进入sleep
	//uiC1CallbackunRegister(LP_ID_CAMERA);
	quec_rtos_mutex_unlock(camCoreHandle.CamDeviceMutex);
		

	CAMLOGI("ataclose the %d camera successful!", sensor_id);

	return error;
}

#ifdef QUEC_LCD_SUPPORT
#ifdef QL_LCD

int quec_send_buff_to_prev(struct isp_buf_msg *ispMsg)
{
    struct isp_buf_msg *FullSizeMsg = NULL;
    CCCameraDevice *pCamDevice = camCoreHandle.pCamDevice;
    CCBufferQueue *pBufferQue = NULL;
	
    quec_queue_t   msgQRef = NULL;
	
    uint_8 pipe_id = 0, buf_idx = 0;
    CCError error = CRANE_CAMERA_ERROR_NONE;
	if (CAMERA_STATUS_PREVIEW & pCamDevice->camStatus) 
	{
		FullSizeMsg = (struct isp_buf_msg *)malloc(sizeof(struct isp_buf_msg));
		memcpy(FullSizeMsg,ispMsg,sizeof(struct isp_buf_msg));
		
	    pBufferQue = &pCamDevice->fullSizeStreamBufQue;
	    msgQRef = pCamDevice->previewMsgQRef;
	    pipe_id = FullSizeMsg->u.data_eof.pipe_id;
		buf_idx = FullSizeMsg->u.data_eof.buf_idx;
	    FullSizeMsg->msg_type = ISP_MSG_TYPE_EOF;
	    
	    error = setBufferStatus(pBufferQue, buf_idx, CC_BUFFER_STATUS_DISPLAY); //这里使用DISPLAY作为EC600N pbuffer的预览状态
	    if(error != CRANE_CAMERA_ERROR_NONE)
	    {
	        CAMLOGE("quec_send_buff_to_prev setBufferStatus err=%d",error);
	    }
		
	    if(msgQRef!= NULL)
	    {
			quec_rtos_queue_release(msgQRef, sizeof(FullSizeMsg), &FullSizeMsg, OS_NO_SUSPEND);

	    }
		else
		{
			setBufferStatus(pBufferQue, buf_idx, CC_BUFFER_STATUS_IDLE);//
			enqueueBuffer(pBufferQue, buf_idx, pBufferQue->pipeId);// 
		}	
	}
	else 
	{
		setBufferStatus(pBufferQue, buf_idx, CC_BUFFER_STATUS_IDLE);//
		enqueueBuffer(pBufferQue, buf_idx, pBufferQue->pipeId);// 
	}
    return error;
}

#define RGB565 (1)
#define BINARY (0)
extern SENSOR_CTRL_T *g_CurSensorCtrl;
extern void quec_uv_table_init(void);
void quec_cranem_preview_thread(void* argv) ;
uint_8 * rotate_buf = NULL;//YUV旋转buff
uint_8 * rgb_buf = NULL;
int quec_cranem_start_preview(CCStartPreviewStruct *data) //
{
    CCError error = CRANE_CAMERA_ERROR_NONE;
	unsigned int width =0;
    unsigned int hight =0;
    int ret = 0;
    CCCameraDevice *pCamDevice = camCoreHandle.pCamDevice;
	
   // struct asrlcdd_screen_info lcdInfo;
    uint_32 totalSize = 0;
	
    uint_32 rotateSize = 0;
    struct isp_output_size ispResInfo = {0};
    uint_32 previewWidth = 0, previewHeight = 0;
    pCamDevice->previewMsgQRef = NULL;
    if(!pCamDevice)
    {
      	//CAMLOGE("must open camera first!");
		return CRANE_CAMERA_ERROR_INVALIDOPERATION;  
    }

    if (CAMERA_STATUS_PREVIEW & pCamDevice->camStatus) 
    {
		//CAMLOGW("the camera preview has been started!");
		return error;
	}

	width=g_CurSensorCtrl->sensor_data->res[g_CurSensorCtrl->sensor_data->cur_res_index].width;
	hight=g_CurSensorCtrl->sensor_data->res[g_CurSensorCtrl->sensor_data->cur_res_index].height;
	if(width<hight)//横屏自动旋转 add by pony 2020-13-29
	{
		data->image_width = (unsigned int)(g_cam_decode_config_ctx.lcdpreheight);
		data->image_height = (unsigned int)(g_cam_decode_config_ctx.lcdprewidth);
	}
	else 
	{
		data->image_width = (unsigned int)(g_cam_decode_config_ctx.lcdprewidth);
		data->image_height = (unsigned int)(g_cam_decode_config_ctx.lcdpreheight);
	}
	
   	previewWidth = data->image_width;
	previewHeight = data->image_height;
   if (previewWidth >= previewHeight)
   	{
		pCamDevice->previewRotationDegree = ROT_0_DEG;
	} 
	else 
	{
		pCamDevice->previewRotationDegree = ROT_90_DEG;
	}
	
    error = getIspRes(&ispResInfo);
	if (error != CRANE_CAMERA_ERROR_NONE) 
	{
		CAMLOGE("getIspRes failed, %d!", error);
		goto Error_exit;
	}

	pCamDevice->sensorWidth = ispResInfo.width;
	pCamDevice->sensorHeight = ispResInfo.height;
	
#if 1
	//获取LCD的相关参数
	//struct panel_spec *quecpanel =lcd_get_panel();
	

    pCamDevice->lcdWidth = g_cam_decode_config_ctx.lcdprewidth ; //320
	pCamDevice->lcdHeight= g_cam_decode_config_ctx.lcdpreheight  ;
    totalSize = (pCamDevice->lcdWidth * pCamDevice->lcdHeight) * 2;
#endif	
    //yuv to rgb rgb_buffer
    //这里我们使用LCD的显存 作为 display rotation
    if(g_cam_decode_config_ctx.lcdmemeryaddr)
    {
        rotate_buf = (uint_8 *)(g_cam_decode_config_ctx.lcdmemeryaddr);
    }
    else
    {
	    rotate_buf = (uint_8 *)malloc(totalSize);
    }
	if (!rotate_buf)
    {
       //raw_uart_log("%s:malloc %d fail!\n", __func__, totalSize);
       error = CRANE_CAMERA_ERROR_OUTOFMEMORY;
       goto Error_exit;
    }
	
	memset(rotate_buf, 0x00, totalSize);
    
    if(pCamDevice->previewRotationDegree == ROT_90_DEG)
    {
        rgb_buf = (uint_8*)malloc(totalSize);
        if (!rgb_buf)
        {
           //raw_uart_log("%s:malloc %d fail!\n", __func__, totalSize);
           error = CRANE_CAMERA_ERROR_OUTOFMEMORY;
           goto Error_exit;
        }
        memset(rgb_buf, 0x00, totalSize);
    }
	
    quec_uv_table_init();//初始化uv表ponyadd 2021-02-19


	//创建预览的线程

	quec_rtos_queue_create(&(pCamDevice->previewMsgQRef), 
	 sizeof(struct isp_buf_msg), 64);
	
	quec_rtos_task_create(&(pCamDevice->previewTaskRef), 
		CAMERA_PREVIEW_TASK_SIZE, 
		g_cam_decode_config_ctx.pretaskprio,
		"qlCAMPreview", 
		quec_cranem_preview_thread, 
		(void *)pCamDevice);
	
	if (pCamDevice->previewTaskRef == NULL) {
		CAMLOGE("UOS_CreateTask for camera preview failed, error code = %d!");
		error = CRANE_CAMERA_ERROR_FATALERROR;
		goto Error_exit;
	}

    pCamDevice->camStatus |= CAMERA_STATUS_PREVIEW;//预览初始化完成标志
    return error;
    
Error_exit:
	CAMLOGE("start preview failed !");

    if(pCamDevice->previewTaskRef )
    {
		quec_rtos_task_delete(pCamDevice->previewTaskRef);

        pCamDevice->previewTaskRef = NULL;
    }
	if(pCamDevice->previewMsgQRef != NULL)
	{
		quec_rtos_queue_delete(pCamDevice->previewMsgQRef);
		pCamDevice->previewMsgQRef = NULL;
	}
 
    //这里使用LCD的显存 作为 display rotation pony add 2021-03-18
    if(g_cam_decode_config_ctx.lcdmemeryaddr)
    {
        rotate_buf = NULL;
    }
    else
    {
        if(rotate_buf)
        {
            free(rotate_buf);
            rotate_buf = NULL;    
        }
    }
    if(rgb_buf)
    {
        free(rgb_buf);
        rgb_buf = NULL;    
    }

	return error;
}

int quec_cranem_stop_preview(void)
{
    CCError error = CRANE_CAMERA_ERROR_NONE;
    CCCameraDevice *pCamDevice = camCoreHandle.pCamDevice;
	
    uint_32   actual_flags = 0;
	OSA_STATUS osaStatus = 0;
	quec_queue_t   msgQRef = 0;
	struct isp_buf_msg *FullSizeMsg = NULL;

    if (!pCamDevice) {
		CAMLOGE("the camera has not been opend!");
		return CRANE_CAMERA_ERROR_INVALIDOPERATION;
	}

	if (!(pCamDevice->camStatus & CAMERA_STATUS_PREVIEW)) {
		CAMLOGE("must start preview first!");
		return CRANE_CAMERA_ERROR_INVALIDOPERATION;
	}
	
	pCamDevice->camStatus &= (~CAMERA_STATUS_PREVIEW);
	
	FullSizeMsg = (struct isp_buf_msg *)malloc(sizeof(struct isp_buf_msg));
	FullSizeMsg->msg_type = ISP_MSG_TYPE_HAL_FLUSH;
	msgQRef = pCamDevice->previewMsgQRef;
	quec_rtos_queue_release(msgQRef, sizeof(FullSizeMsg),&FullSizeMsg, OS_NO_SUSPEND);

	
	osaStatus = quec_rtos_flag_wait(pCamDevice->threadSyncFlagRef, PREVIEW_STOPWORK, OSA_FLAG_OR_CLEAR, &actual_flags, OS_SUSPEND);
	printf("quec_cranem_stop_preview = %d \r\n",osaStatus);
	
    if(pCamDevice->previewTaskRef )
    {		
		quec_rtos_task_delete(pCamDevice->previewTaskRef);
		
        pCamDevice->previewTaskRef = NULL;
    }

    if(pCamDevice->previewMsgQRef != NULL)
    {
        quec_rtos_queue_delete(pCamDevice->previewMsgQRef);
        pCamDevice->previewMsgQRef = NULL;
    }

#ifdef __QUEC_CAMERA__
    //这里我们使用LCD的显存 作为 display rotation
    if(g_cam_decode_config_ctx.lcdmemeryaddr)
    {
        rotate_buf = NULL;
    }
    else
#endif
    {
        if(rotate_buf)
        {
            free(rotate_buf);
            rotate_buf = NULL;    
        } 
    }
    if(rgb_buf)
    {
        free(rgb_buf);
        rgb_buf = NULL;    
    }
    return error;
}

extern int quec_merge_CamBuffer(void *pBuf, int bufIndex,uint_8 *rgb565_ptr,uint_32 sensorWidth,uint_32 sensorHeight,uint_32 img_w,uint_32 img_h,uint_8 format);
void quec_cranem_preview_thread(void* argv) //EC600N预览
{
    struct isp_buf_msg *FullSizeMsg = NULL;
    CCCameraDevice *pCamDevice = NULL;
    quec_queue_t   msgQRef = 0;
    uint_32 onlineWaitTime = ONLINE_TIME_OUT;
    CCBufferQueue *pBufferQue = NULL;
    uint_8 pipe_id = 0,buf_idx = 0;
    char *pBuf = NULL;
    OSA_STATUS osaStatus = 0;
    struct isp_output_size ispResInfo;
    
    pCamDevice = (CCCameraDevice *)argv;
    pBufferQue = &pCamDevice->fullSizeStreamBufQue;
    msgQRef = pCamDevice->previewMsgQRef;
    
    onlineWaitTime = 1000 / pCamDevice->minFps * TIMEOUT_FRAME;
    do
	{
		
		quec_rtos_queue_wait(msgQRef, &FullSizeMsg, sizeof(FullSizeMsg),QUEC_WAIT_FOREVER);
		
          if (!FullSizeMsg) 
		  {
               CAMLOGW("receive camera drv buffer timeout, continue!");
              _CCDumpBufferStatus(pBufferQue);
              continue;
          }

          switch(FullSizeMsg->msg_type) 
		  {
		  	case ISP_MSG_TYPE_EOF:        
                    pipe_id = FullSizeMsg->u.data_eof.pipe_id;
                    buf_idx = FullSizeMsg->u.data_eof.buf_idx;
                    //uart_printf("ready to merge CamBuffer buf_idx=%d,pipe_id = %d,&pBufferQue = %p\r\n",buf_idx,pipe_id,pBufferQue);
                    pBuf = (char*)(pBufferQue->bufPack[buf_idx].ispBuffer.buffer.planes[0].addr);
                    quec_merge_CamBuffer(pBuf, buf_idx,rotate_buf ,pCamDevice->sensorWidth,pCamDevice->sensorHeight,pCamDevice->lcdWidth ,pCamDevice->lcdHeight,RGB565);//此处预览
                    setBufferStatus(pBufferQue, buf_idx, CC_BUFFER_STATUS_IDLE);//
			        enqueueBuffer(pBufferQue, buf_idx, pBufferQue->pipeId);// 
			        
			        break;
			  case ISP_MSG_TYPE_HAL_FLUSH:
			  		quec_rtos_flag_release(pCamDevice->threadSyncFlagRef,PREVIEW_STOPWORK, OSA_FLAG_OR);
					break;
              default:
				    break;
          }
		  
        	free(FullSizeMsg);	//释放在stop preview申请的内存
			FullSizeMsg = NULL;
      }while(1);
}
#endif
#endif

