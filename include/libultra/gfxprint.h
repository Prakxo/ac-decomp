#ifndef GFXPRINT_H
#define GFXPRINT_H

#include "types.h"
typedef void* (*PrintCallback)(void*, const char*, size_t);
typedef struct gfxprint_obj  {
    PrintCallback callback;
    struct unknown_struct * unk4; // This is from GBI.h, from what I've seen
    s16 NewX;
    s16 NewY;
    u16 PrevX;
    u8 PrevY;
    u8 flags;
    u8 R;
	u8 B;
	u8 G;
	u8 A;
};

void gfxprint_locate(struct gfxprint_obj*, s32, s32); 

#endif
