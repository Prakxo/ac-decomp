#ifndef LIBULTRA_H
#define LIBULTRA_H
#include "types.h"

void bcmp (const void *v1, const void *v2, u32 size);
void bcopy(const void *dst, void *src, size_t n);
void bzero(void *ptr, size_t size);
extern s32 osAppNMIBuffer[15]; 

#endif 