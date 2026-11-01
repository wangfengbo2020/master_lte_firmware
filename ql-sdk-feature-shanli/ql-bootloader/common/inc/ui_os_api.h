#ifndef _UI_OS_API_H_
#define _UI_OS_API_H_
//#include "osa_old_api.h"
//#include "osa.h"

#include "plat_types.h"

#define UOS_SEND_EVT		(1 << 0)
#define UOS_SEND_MSG		0


#define TASK_WITHOUT_MSGQ	0
#define TASK_MSGQ_SIZE_16	16
#define TASK_MSGQ_SIZE_32	32
#define TASK_MSGQ_SIZE_64	64
#define TASK_MSGQ_SIZE_128	128
#define TASK_MSGQ_SIZE_256	256
#define TASK_MSGQ_SIZE_512	512


#define TASK_DEFAULT_MSGQ_SIZE	TASK_MSGQ_SIZE_16

#define LCD_TASK_SIZE					1024
#define LCD_TASK_PRIORITY				220
#define TASK_HANDLE         void

typedef void (*lcdTimeHandler)(void* argv);


void UOS_Sleep(UINT32 ticks);
void UOS_SleepMs(UINT32 ms);


OSAFlagRef UOS_CreateFlag(void);
int UOS_SetFlag(OSAFlagRef  flagRef, uint32_t mask, uint32_t operation);

int UOS_WaitFlag(OSAFlagRef flagRef, uint32_t mask, uint32_t operation, uint32_t* flags, uint32_t timeout);
void UOS_DeleteFlag(OSAFlagRef osa_flag);



void UOS_ReleaseMutex(int Mutex);
void UOS_TakeMutex(int Mutex);
void UOS_FreeMutex(int Mutex);
int UOS_NewMutex(char *Mutex_Name);

u8 UOS_get_FunctionTimer(void);
OSAMsgQRef UOS_NewMessageQueue(char * name,UINT32 msgQSize);
void UOS_SendMsg(void *msg, OSAMsgQRef msgQid, int type);
void UOS_WaitMsg(void *msg, OSAMsgQRef msgQid, UINT32 timeout);
UINT32 UOS_MsgQEnqueued(OSAMsgQRef msgQid);
void UOS_FreeMessageQueue(OSAMsgQRef msgQid);


OSTaskRef UOS_CreateTask(void  (*taskStart)(void*),void *argv, int msgQ,
                    UINT32 stackSize, UINT8 priority, char *name);

void UOS_DeleteTask(void * task_ref);
u32 UOS_GetUpTime(void);

void UOS_StartFunctionTimer_single(u8 timeId,UINT32 ticks,lcdTimeHandler handle,char *str1,char *str2);



#endif
