#include "libultra/gfxprint.h"

void gfxprint_locate8x8(struct gfxprint_obj* arg0, s32 arg1, s32 arg2) {
    s32 x = arg1 << 3;
    s32 y = arg2 << 3;
    gfxprint_locate(arg0, x, y);
}