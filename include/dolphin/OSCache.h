#ifndef OS_CACHE_H
#define OS_CACHE_H
#include "types.h"
#include "dolphin/OSContext.h"
#ifdef __cplusplus
extern "C" {
#endif

asm void DCEnable(void);
asm void DCInvalidateRange(void* buf, u32 len);
asm void DCFlushRange(void* buf, u32 len);
asm void DCStoreRange(void* buf, u32 len);
asm void DCFlushRangeNoSync(void* buf, u32 len);
asm void DCStoreRangeNoSync(void* buf, u32 len);
asm void DCZeroRange(void* buf, u32 len);
asm void DCTouchRange(void* buf, u32 len);
asm void ICInvalidateRange(void* buf, u32 len);
asm void ICFlashInvalidate(void);
asm void ICEnable(void);
asm void LCDisable(void);

void L2GlobalInvalidate(void);

void DMAErrorHandler(u8, OSContext*, u32, u32, ...);

void __OSCacheInit(void);

#ifdef __cplusplus
}
#endif
#endif