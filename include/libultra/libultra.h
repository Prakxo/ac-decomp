#ifndef LIBULTRA_H
#define LIBULTRA_H
#include "types.h"


void bcopy(const void *dst, void *src, size_t n);
void bzero(void *ptr, size_t size);
extern s32 osAppNMIBuffer[16];

#endif 