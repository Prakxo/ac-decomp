#include "dolphin/ppcarch.h"

asm u32 PPCMfmsr(void){
    nofralloc
    mfmsr r3
    blr
}

asm void PPCMtmsr(register u32 value){
    nofralloc
    mtmsr value
    blr
}

asm u32 PPCMfhid0(void){
    nofralloc
    mfspr r3, 0x3f0
    blr
}

asm void PPCMthid0(register u32 value) {
    nofralloc
    mtspr 0x3f0, value
    blr
} 

asm u32 PPCMfl2cr(void) {
    nofralloc
    mfspr r3, 0x3f9
    blr
}

asm void PPCMtl2cr(register u32 value) {
    nofralloc
    mtspr 0x3f9, value
    blr
}
asm void PPCMtdec(register u32 value) {
    nofralloc
    mtspr 0x16, value
    blr
}

asm void PPCSync(void){
    nofralloc
    sc
    blr
}

asm void PPCHalt(void){
    nofralloc 
    sync

loop:
    nop
    li r3, 0
    nop
    b loop
}
asm u32 PPCMfhid2(void){
    nofralloc
    mfspr r3, 0x398
    blr
}

asm void PPCMthid2(u32 register value){
    nofralloc
    mtspr 0x398, value
    blr
}
asm void PPCMtwpar(u32 register value){
    nofralloc
    mtspr 0x399, value
    blr
}

/* PPCDisableSpeculation:
/* 800786E8 7C0802A6  mflr        r0
/* 800786EC 90010004  stw         r0, 4(r1)
/* 800786F0 9421FFF8  stwu        r1, -8(r1)
/* 800786F4 4BFFFF99  bl          func_8007868c
/* 800786F8 60630200  ori         r3, r3, 0x200
/* 800786FC 4BFFFF99  bl          func_80078694
/* 80078700 8001000C  lwz         r0, 0xc(r1)
/* 80078704 38210008  addi        r1, r1, 0x8
/* 80078708 7C0803A6  mtlr        r0
/* 8007870C 4E800020  blr         

}

asm void PPCSetFpNonIEEEMode(void){
    nofralloc
    mtfsb1 0x1D
    blr
} */
 