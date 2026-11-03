#ifndef TEST_QL_RTOS_H
#define TEST_QL_RTOS_H
typedef void *ql_task_t;
int ql_rtos_task_create(ql_task_t *task, unsigned int stack, unsigned int priority,
                        const char *name, void (*entry)(void *), void *arg);
void ql_rtos_task_sleep_s(unsigned int seconds);
#endif
