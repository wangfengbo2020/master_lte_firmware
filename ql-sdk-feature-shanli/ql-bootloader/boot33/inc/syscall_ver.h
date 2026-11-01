#ifndef __SYSCALL_VER_H__
#define __SYSCALL_VER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "syscall-arom.h"

/*---------------------------------------------------------------------------*/
const char *aboot_sys_getversion(void);
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __SYSCALL_VER_H__ */
