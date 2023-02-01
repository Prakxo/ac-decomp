#include "libultra/libultra.h"

void bcopy(void* __src, void* __dst, size_t __n) {
    memmove(__dst, __src, __n);
}


int bcmp(void* __s1, void* __s2, size_t __n) {
    return memcmp(__s1, __s2, __n);
}

void bzero(void* __s, size_t __n) {
    memset(__s, 0, __n);
}

void osWritebackDCache(void* buf, u32 len){
	 DCStoreRange(buf, len);
}

/* s32 osGetCount(void){
	return OSGetTick();
}
 */