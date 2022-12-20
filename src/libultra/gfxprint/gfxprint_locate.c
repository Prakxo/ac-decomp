#include "libultra/gfxprint.h"

void gfxprint_locate(struct gfxprint_obj* gfxprint, s32 x, s32 y) {
    gfxprint->NewX = (s16) (gfxprint->PrevX + (x * 4));
    gfxprint->NewY = (s16) (gfxprint->PrevY + (y * 4));
}