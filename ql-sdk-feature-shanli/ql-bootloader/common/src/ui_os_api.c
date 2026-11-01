#include "ui_os_api.h"
#include "stdlib.h"


void UOS_Sleep(UINT32 ticks)
{
    //OSATaskSleep(ticks);
    mdelay(ticks*5);
}

void UOS_SleepMs(UINT32 ms)
{
    //UINT32 tick=((ms) / OSA_TICK_FREQ_IN_MILLISEC ? (ms) / OSA_TICK_FREQ_IN_MILLISEC : 1);
    //OSATaskSleep(tick);
    mdelay(ms);
}


OSAFlagRef UOS_CreateFlag(void)
{
    //OSA_STATUS osa_status;
    //OSAFlagRef osa_flag;
    //osa_status = OSAFlagCreate(&osa_flag);
    //LCD_ASSERT(osa_status == OS_SUCCESS);
    //raw_uart_log("%s,osa_flag[%08x]",__func__,osa_flag);
    //return osa_flag;
    return NULL;
}

void UOS_DeleteFlag(OSAFlagRef osa_flag)
{
    //raw_uart_log("%s,osa_flag[%08x]",__func__,osa_flag);
    //OSAFlagDelete(osa_flag);
}

int UOS_WaitFlag(OSAFlagRef flagRef, uint32_t mask, uint32_t operation, uint32_t* flags, uint32_t timeout)
{
    //OSA_STATUS ret;
    //raw_uart_log("%s,flagRef[%08x] flags[%08x]",__func__,flagRef,*flags);
    
    //ret = OSAFlagWait(flagRef, mask, operation, (UINT32*)flags, timeout);
    //raw_uart_log("%s,ret[%d] flags[%08x]",__func__,ret,*flags);

    //return ret;

}

int UOS_SetFlag(OSAFlagRef  flagRef, uint32_t mask, uint32_t operation)
{
    //OSA_STATUS  osaStatus; 
    //raw_uart_log("%s,flagRef[%08x]",__func__,flagRef);
    //osaStatus = OSAFlagSet(flagRef, mask, operation);
    //LCD_ASSERT(osaStatus == OS_SUCCESS);
    return 0;

}



u8 UOS_get_FunctionTimer(void)
{
    return 0;
}

void UOS_StartFunctionTimer_single(u8 timeId,UINT32 ticks,lcdTimeHandler handle,char *str1,char *str2)
{
    return;
}

int UOS_NewMutex(char *Mutex_Name)
{
    //OSA_STATUS osaStatus;
    //OSMutexRef Mutex;
	//osaStatus = OSAMutexCreate((OSMutexRef *)&Mutex, OS_PRIORITY);
	//LCD_ASSERT(osaStatus == OS_SUCCESS);
	return 0;
}
void UOS_FreeMutex(int Mutex)
{
    //OSAMutexDelete((OSAMutexRef)Mutex);
}


void UOS_TakeMutex(int Mutex)
{
    //OSAMutexLock((OSAMutexRef)Mutex, OSA_SUSPEND);
}

void UOS_ReleaseMutex(int Mutex)
{
    //OSAMutexUnlock((OSAMutexRef)Mutex);
}

OSAMsgQRef UOS_NewMessageQueue(char * name,UINT32 msgQSize)
{
    //OSA_STATUS osaStatus;
    //OSMsgQRef msgQ;
//#if defined(OSA_QUEUE_NAMES)
//    osaStatus = OSAMsgQCreate(&msgQ, name, msgQSize, TASK_MSGQ_SIZE_64, OS_FIFO);
//#else
//    osaStatus = OSAMsgQCreate(&msgQ, msgQSize, TASK_MSGQ_SIZE_64, OS_FIFO);
//#endif
 //   return msgQ;
 	return NULL;

}

void UOS_SendMsg(void *msg, OSAMsgQRef msgQid, int type)
{
    //OSA_STATUS osa_status;
    //osa_status = OSAMsgQSend(msgQid, TASK_DEFAULT_MSGQ_SIZE, (UINT8*)msg, OS_NO_SUSPEND);
    //LCD_ASSERT(osa_status == OS_SUCCESS);
}

void UOS_WaitMsg(void *msg, OSAMsgQRef msgQid, UINT32 timeout)
{
    //OSA_STATUS osaStatus;
    //osaStatus = OSAMsgQRecv(msgQid,(UINT8*) msg, TASK_DEFAULT_MSGQ_SIZE, timeout);
    //LCD_ASSERT(osaStatus == OS_SUCCESS);

}

UINT32 UOS_MsgQEnqueued(OSAMsgQRef msgQid)
{
    //OSA_STATUS osaStatus;
    //UINT32 msgs_in_queue;
    //osaStatus = OSAMsgQPoll(msgQid, &msgs_in_queue);
    //LCD_ASSERT(osaStatus == OS_SUCCESS);
    //return msgs_in_queue;
    return 0;

}


void UOS_FreeMessageQueue(OSAMsgQRef msgQid)
{
    //OSAMsgQDelete(msgQid);
}
struct uos_task
{
    OSTaskRef task_ref;
    uint8_t *task_stack;
    
};

#define UOS_MAX_TASK_NUM 2
static struct uos_task lcd_task[UOS_MAX_TASK_NUM]={{0,NULL},{0,NULL}};



OSTaskRef UOS_CreateTask(void  (*taskStart)(void*),void *argv, int msgQ,
                    UINT32 stackSize, UINT8 priority, char *name)
{
/*
    OSTaskRef task_ref;
    OSA_STATUS osaStatus;
    uint8_t *task_stack=NULL;
    int i ;
    struct uos_task * temp=NULL;
    
    for(i=0;i<UOS_MAX_TASK_NUM;i++){
        if(lcd_task[i].task_ref==0 && lcd_task[i].task_stack==NULL){
             temp = &lcd_task[i];
             break;
        }
    }
    LCD_ASSERT(temp != NULL);

    
    task_stack = (uint8_t *)malloc(stackSize);
    memset(task_stack,0,stackSize);

    
    osaStatus = OSATaskCreate(&task_ref, 
                    (void *)task_stack, 
                    stackSize, 
                    priority, 
                    name, 
                    taskStart, 
                    argv);
    LCD_ASSERT(osaStatus == OS_SUCCESS);
    
    temp->task_ref = task_ref;
    temp->task_stack = task_stack;

    
    return task_ref;
    */
    return NULL;
}

void UOS_DeleteTask(void * task_ref)
{
	/*
    int i ;
    struct uos_task * temp=NULL;
    
    for(i=0;i<UOS_MAX_TASK_NUM;i++){
        if(lcd_task[i].task_ref==task_ref){
             temp = &lcd_task[i];
             break;
        }
    }
    LCD_ASSERT(temp != NULL);
    
    OSATaskDelete((OSATaskRef)task_ref);
    free(temp->task_stack);
    temp->task_ref = 0;
    temp->task_stack = NULL;
    */
}




u32 UOS_GetUpTime(void)
{
    return 0;
}

