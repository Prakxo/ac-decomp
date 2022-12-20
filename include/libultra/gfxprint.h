#ifndef GFXPRINT_H
#define GFXPRINT_H

#include "types.h"

typedef struct gfxprint_obj  {
    s32 unk0;
    struct unknown_struct * unk4;
    s16 NewX;
    s16 NewY;
    u16 PrevX;
    u8 PrevY;
    u8 unkF;
    u8 R;
    u8 G;
    u8 B;
    u8 A; 
};

void gfxprint_locate(struct gfxprint_obj*, s32, s32); 

#endif
