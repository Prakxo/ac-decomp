#ifndef _DOLPHIN_OS
#define _DOLPHIN_OS

#include "types.h"
#include "dolphin/OS/OSContext.h"
#ifdef __cplusplus
extern "C" {
#endif

void OSReport(const char*, ...);

asm BOOL OSDisableInterrupts(void);
asm BOOL OSEnableInterrupts(void);
asm BOOL OSRestoreInterrupts(BOOL level);


void __RAS_OSDisableInterrupts_begin(void);
void __RAS_OSDisableInterrupts_end(void);

typedef void (*OSExceptionHandler)(u8, OSContext*);
OSExceptionHandler __OSSetExceptionHandler(u8, OSExceptionHandler);

#ifdef __cplusplus
};
#endif
#endif
