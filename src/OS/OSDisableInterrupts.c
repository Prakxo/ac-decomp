#include "dolphin/os.h"

asm BOOL OSDisableInterrupts(void){

    nofralloc

    mfmsr r3
    rlwinm r4, r3, 0, 17, 15
    mtmsr r4
    rlwinm r3, r3, 17, 31, 31
    blr
}