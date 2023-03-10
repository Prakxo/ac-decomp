#ifndef LIBULTRA_H
#define LIBULTRA_H

#include "types.h"
#include "dolphin/os/OSTime.h"
#include "dolphin/os/OSCache.h"

int bcmp (void *v1, void *v2, u32 size);
void bcopy(void *dst, void *src, size_t n);
void bzero(void *ptr, size_t size);
void osSyncPrintf(const char* fmt, ...);
void osWritebackDCache(void* vaddr, u32 nbytes);
u32 osGetCount(void);
OSTime osGetTime(void);

s32 osAppNMIBuffer[15]; 

#endif