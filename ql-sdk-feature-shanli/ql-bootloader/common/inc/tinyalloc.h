//#include <stdbool.h>
//#include <stddef.h>
#include "common.h"

int ta_init(unsigned int ta_base, unsigned int length);
void *ta_alloc(size_t num);
void *ta_calloc(size_t num, size_t size);
int ta_free(void *ptr);

size_t ta_num_free(void);
size_t ta_num_used(void);
size_t ta_num_fresh(void);
int ta_check(void);
void *tiny_malloc(size_t num);
int tiny_free(void *free);



