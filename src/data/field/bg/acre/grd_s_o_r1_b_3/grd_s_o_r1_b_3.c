#include "libforest/gbi_extensions.h"

extern u8 wave3_tex_dummy[];
extern u8 wave1_tex_dummy[];
extern u8 beach2_tex_dummy2[];

static Vtx grd_s_o_r1_b_3_v[] = {
#include "assets/field/bg/grd_s_o_r1_b_3_v.inc"
};

extern Gfx grd_s_o_r1_b_3_model[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED),
    gsDPSetPrimColor(0, 255, 32, 48, 144, 255),
    gsSPDisplayList(0x0C000000),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPLoadTextureBlock_4b_Dolphin(beach2_tex_dummy2, G_IM_FMT_I, 32, 16, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_o_r1_b_3_v[0], 15, 0),
    gsSPNTrianglesInit_5b(
        16, // tri count
        0, 1, 2, // tri0
        0, 3, 1, // tri1
        3, 4, 1 // tri2
    ),
    gsSPNTriangles_5b(
        4, 5, 1, // tri0
        4, 6, 5, // tri1
        4, 7, 6, // tri2
        8, 9, 6 // tri3
    ),
    gsSPNTriangles_5b(
        6, 7, 8, // tri0
        0, 10, 3, // tri1
        0, 11, 10, // tri2
        10, 4, 3 // tri3
    ),
    gsSPNTriangles_5b(
        10, 12, 4, // tri0
        12, 13, 4, // tri1
        13, 7, 4, // tri2
        13, 8, 7 // tri3
    ),
    gsSPNTriangles_5b(
        13, 14, 8, // tri0
        0, 0, 0, // tri1
        0, 0, 0, // tri2
        0, 0, 0 // tri3
    ),
    gsSPEndDisplayList(),
};

extern Gfx grd_s_o_r1_b_3_modelT[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetCombineLERP(TEXEL1, 0, TEXEL0, TEXEL0, TEXEL1, 0, TEXEL0, 0, PRIMITIVE, 0, SHADE, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetPrimColor(0, 255, 60, 120, 255, 255),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, wave1_tex_dummy),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 0, GX_REPEAT, GX_REPEAT, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, wave3_tex_dummy),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 1, 0, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPDisplayList(0x0D000000),
    gsSPVertex(&grd_s_o_r1_b_3_v[15], 15, 0),
    gsSPNTrianglesInit_5b(
        16, // tri count
        0, 1, 2, // tri0
        0, 3, 1, // tri1
        2, 1, 4 // tri2
    ),
    gsSPNTriangles_5b(
        1, 5, 4, // tri0
        4, 6, 7, // tri1
        4, 5, 6, // tri2
        7, 6, 8 // tri3
    ),
    gsSPNTriangles_5b(
        6, 9, 8, // tri0
        10, 8, 11, // tri1
        10, 7, 8, // tri2
        12, 4, 10 // tri3
    ),
    gsSPNTriangles_5b(
        4, 7, 10, // tri0
        13, 4, 12, // tri1
        13, 2, 4, // tri2
        14, 0, 13 // tri3
    ),
    gsSPNTriangles_5b(
        0, 2, 13, // tri0
        0, 0, 0, // tri1
        0, 0, 0, // tri2
        0, 0, 0 // tri3
    ),
    gsSPEndDisplayList(),
};
