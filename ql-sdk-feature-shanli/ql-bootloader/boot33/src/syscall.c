#include <assert.h>
#include <stddef.h>
#include "syscall-arom.h"

#define SVC_GET_FUNC_PTR 0
static void **syscall_tables;

__svc(SVC_GET_FUNC_PTR) void svc_get_func_ptr(syscall_t index,void **p);

void sv_call_get_handler(syscall_t index, void **p)
{
    (void)index;
    (void)p;
    svc_get_func_ptr(index,p);
}

__attribute__ ((noinline)) void *__syscall_get_handler(syscall_t index)
{
    void *func_ptr = NULL;

    sv_call_get_handler(index, &func_ptr);

    return func_ptr;
}

void *syscall_get_handler(syscall_t index)
{
	//uart_printf("[%s][%d]syscall_tables[%d]=[%x]\r\n",__func__,__LINE__,index,syscall_tables[index]);
    return syscall_tables[index];
}

void syscall_init(void)
{
    void *(*handler)(void);

    handler = __syscall_get_handler(SYSCALL_74_GET_SYSCALL_TABLE);
    if (handler) {
        syscall_tables = handler();
    }
}
