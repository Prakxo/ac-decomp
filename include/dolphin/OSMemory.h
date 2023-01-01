#ifndef OS_MEMORY_H
#define OS_MEMORY_H

static asm void Config24MB();
static asm void Config48MB();
u32 OSGetConsoleSimulatedMemSize(void);
#endif