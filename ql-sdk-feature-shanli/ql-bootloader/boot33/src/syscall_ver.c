#include <stddef.h>
#include "syscall_ver.h"

const char *aboot_sys_getversion(void)
{
    char *(*handler)(void);
    char *ret = NULL;

    handler = syscall_get_handler(SYSCALL_73_ABOOT_SYS_GETVERSION);
    if (handler) {
        ret = handler();
    }
    return ret;
}
