#ifndef _STATIC_MALLOC_H_
#define _STATIC_MALLOC_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

void* e_malloc(size_t size);
void e_free(void* ptr);

void e_print_info();

#ifdef __cplusplus
}
#endif
#endif
