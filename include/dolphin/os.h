#ifndef _DOLPHIN_OS
#define _DOLPHIN_OS

#include "types.h"

void OSReport(const char*, ...);      

asm BOOL OSDisableInterrupts(void);
asm BOOL OSEnableInterrupts(void);
asm BOOL OSRestoreInterrupts(BOOL level);

#endif