#ifndef LIBULTRA_H
#define LIBULTRA_H
#include "types.h"

void bcmp (const void *v1, const void *v2, u32 size);
void bcopy(const void *dst, void *src, size_t n);
void bzero(void *ptr, size_t size);
extern s32 osAppNMIBuffer[16]; //?? It's most likely an u8 with 64 instead of s32 of 16, so the function that uses this is probably a fakematch.

#endif 