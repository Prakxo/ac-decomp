#ifndef LIBULTRA_H
#define LIBULTRA_H
#include "types.h"
#include "dolphin/OS/OSTime.h"
#include "dolphin/OS/OSCache.h"
int bcmp (void *v1, void *v2, u32 size);
void bcopy(void *dst, void *src, size_t n);
void bzero(void *ptr, size_t size);
void osSyncPrintf(const char* fmt, ...);
void osWritebackDCache(void* vaddr, u32 nbytes);
u32 osGetCount(void);
extern s32 osAppNMIBuffer[15]; 

extern void * memcpy(void * dst, const void * src, size_t n);
extern void * memset(void * dst, int val, size_t n);
extern void __fill_mem(void * dst, int val, unsigned long n);

#endif 