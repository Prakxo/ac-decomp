#ifndef PPCARCH_H
#define PPCARCH_H
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

u32 PPCMfmsr(void);
void PPCMtmsr(u32);

u32 PPCMfhid0(void);
void PPCMthid0(u32);

u32 PPCMfl2cr(void);
void PPCMtl2cr(u32);

void PPCMtdec(u32);

void PPCSync(void);
void PPCHalt(void);

u32 PPCMfhid2(void);
void PPCMthid2(u32);


void PPCMtwpar(u32);

void PPCDisableSpeculation(void);
void PPCSetFpNonIEEEMode(void);


#ifdef __cplusplus
}
#endif
#endif
