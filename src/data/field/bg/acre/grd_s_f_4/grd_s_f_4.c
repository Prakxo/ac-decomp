#include "libforest/gbi_extensions.h"

extern u8 bush_pal_dummy[];
extern u8 cliff_pal_dummy[];
extern u8 earth_pal_dummy[];
extern u8 water_2_tex_dummy[];
extern u8 water_1_tex_dummy[];
extern u8 river_tex_dummy[];
extern u8 grass_tex_dummy[];
extern u8 bush_b_tex_dummy[];
extern u8 bush_a_tex_dummy[];
extern u8 earth_tex_dummy[];

static Vtx grd_s_f_4_v[] = {
#include "assets/field/bg/grd_s_f_4_v.inc"
};

extern Gfx grd_s_f_4_modelT[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 1, 0, TEXEL0, TEXEL1, COMBINED, 0, SHADE, TEXEL0,
                       COMBINED, 0, PRIM_LOD_FRAC, PRIMITIVE),
    gsDPSetPrimColor(0, 50, 255, 255, 255, 50),
    gsDPSetEnvColor(0x00, 0x3C, 0xFF, 0xFF),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_ZB_XLU_SURF2),
    gsDPLoadTextureBlock_4b_Dolphin(water_1_tex_dummy, G_IM_FMT_I, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsDPLoadMultiBlock_4b_Dolphin(water_2_tex_dummy, 1, G_IM_FMT_I, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPDisplayList(0x08000000),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_f_4_v[177], 6, 0),
    gsSPNTrianglesInit_5b(4,       // tri count
                          0, 1, 2, // tri0
                          0, 3, 1, // tri1
                          0, 4, 3  // tri2
                          ),
    gsSPNTriangles_5b(4, 5, 3, // tri0
                      0, 0, 0, // tri1
                      0, 0, 0, // tri2
                      0, 0, 0  // tri3
                      ),
    gsSPEndDisplayList(),
};

extern Gfx grd_s_f_4_model[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, bush_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(bush_a_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_f_4_v[164], 13, 0),
    gsSPNTrianglesInit_5b(6,       // tri count
                          0, 1, 2, // tri0
                          3, 4, 5, // tri1
                          6, 3, 7  // tri2
                          ),
    gsSPNTriangles_5b(8, 6, 9,   // tri0
                      10, 8, 11, // tri1
                      1, 10, 12, // tri2
                      0, 0, 0    // tri3
                      ),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPLoadTLUT_Dolphin(15, 16, 1, earth_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(grass_tex_dummy, G_IM_FMT_CI, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPVertex(&grd_s_f_4_v[0], 32, 0),
    gsSPNTrianglesInit_5b(25,      // tri count
                          0, 1, 2, // tri0
                          1, 3, 2, // tri1
                          3, 4, 2  // tri2
                          ),
    gsSPNTriangles_5b(3, 5, 4,   // tri0
                      6, 7, 8,   // tri1
                      9, 10, 11, // tri2
                      10, 8, 11  // tri3
                      ),
    gsSPNTriangles_5b(9, 12, 10,  // tri0
                      9, 11, 13,  // tri1
                      14, 13, 11, // tri2
                      15, 13, 16  // tri3
                      ),
    gsSPNTriangles_5b(14, 17, 13, // tri0
                      16, 13, 17, // tri1
                      0, 18, 19,  // tri2
                      20, 18, 0   // tri3
                      ),
    gsSPNTriangles_5b(21, 14, 18, // tri0
                      18, 20, 21, // tri1
                      17, 14, 21, // tri2
                      4, 5, 22    // tri3
                      ),
    gsSPNTriangles_5b(23, 22, 5,  // tri0
                      23, 24, 25, // tri1
                      24, 26, 25, // tri2
                      27, 26, 28  // tri3
                      ),
    gsSPNTriangles_5b(27, 25, 26, // tri0
                      29, 26, 30, // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_f_4_v[31], 32, 0),
    gsSPNTrianglesInit_5b(23,      // tri count
                          0, 1, 2, // tri0
                          2, 1, 3, // tri1
                          4, 1, 0  // tri2
                          ),
    gsSPNTriangles_5b(5, 6, 4,   // tri0
                      7, 8, 6,   // tri1
                      9, 10, 11, // tri2
                      10, 12, 11 // tri3
                      ),
    gsSPNTriangles_5b(13, 10, 14, // tri0
                      10, 9, 14,  // tri1
                      15, 16, 17, // tri2
                      18, 19, 16  // tri3
                      ),
    gsSPNTriangles_5b(20, 14, 21, // tri0
                      12, 22, 11, // tri1
                      23, 24, 22, // tri2
                      24, 25, 22  // tri3
                      ),
    gsSPNTriangles_5b(8, 7, 26,  // tri0
                      7, 25, 26, // tri1
                      6, 27, 7,  // tri2
                      6, 5, 27   // tri3
                      ),
    gsSPNTriangles_5b(4, 0, 5,   // tri0
                      2, 28, 0,  // tri1
                      28, 29, 0, // tri2
                      30, 17, 31 // tri3
                      ),
    gsSPVertex(&grd_s_f_4_v[63], 7, 0),
    gsSPNTrianglesInit_5b(4,       // tri count
                          0, 1, 2, // tri0
                          2, 3, 0, // tri1
                          1, 4, 2  // tri2
                          ),
    gsSPNTriangles_5b(3, 5, 6, // tri0
                      0, 0, 0, // tri1
                      0, 0, 0, // tri2
                      0, 0, 0  // tri3
                      ),
    gsDPLoadTextureBlock_4b_Dolphin(earth_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_f_4_v[70], 32, 0),
    gsSPNTrianglesInit_5b(14,      // tri count
                          0, 1, 2, // tri0
                          3, 4, 5, // tri1
                          6, 3, 7  // tri2
                          ),
    gsSPNTriangles_5b(1, 8, 9,    // tri0
                      8, 6, 10,   // tri1
                      11, 12, 13, // tri2
                      14, 11, 15  // tri3
                      ),
    gsSPNTriangles_5b(12, 16, 17, // tri0
                      16, 18, 19, // tri1
                      20, 21, 22, // tri2
                      21, 14, 23  // tri3
                      ),
    gsSPNTriangles_5b(24, 25, 26, // tri0
                      25, 27, 28, // tri1
                      24, 26, 29, // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_f_4_v[100], 27, 0),
    gsSPNTrianglesInit_5b(16,      // tri count
                          0, 1, 2, // tri0
                          3, 4, 5, // tri1
                          6, 7, 8  // tri2
                          ),
    gsSPNTriangles_5b(4, 9, 10, // tri0
                      9, 6, 10, // tri1
                      6, 8, 10, // tri2
                      3, 5, 1   // tri3
                      ),
    gsSPNTriangles_5b(0, 3, 1,    // tri0
                      11, 0, 2,   // tri1
                      12, 13, 14, // tri2
                      15, 16, 17  // tri3
                      ),
    gsSPNTriangles_5b(18, 19, 20, // tri0
                      19, 11, 21, // tri1
                      22, 12, 14, // tri2
                      7, 23, 24   // tri3
                      ),
    gsSPNTriangles_5b(23, 25, 26, // tri0
                      0, 0, 0,    // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, cliff_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(river_tex_dummy, G_IM_FMT_CI, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_f_4_v[127], 24, 0),
    gsSPNTrianglesInit_5b(16,      // tri count
                          0, 1, 2, // tri0
                          1, 3, 2, // tri1
                          4, 5, 6  // tri2
                          ),
    gsSPNTriangles_5b(7, 8, 5,   // tri0
                      7, 9, 8,   // tri1
                      10, 11, 9, // tri2
                      10, 12, 11 // tri3
                      ),
    gsSPNTriangles_5b(13, 14, 12, // tri0
                      14, 13, 15, // tri1
                      15, 16, 14, // tri2
                      15, 17, 16  // tri3
                      ),
    gsSPNTriangles_5b(18, 19, 17, // tri0
                      18, 20, 19, // tri1
                      21, 22, 20, // tri2
                      21, 23, 22  // tri3
                      ),
    gsSPNTriangles_5b(0, 2, 23, // tri0
                      0, 0, 0,  // tri1
                      0, 0, 0,  // tri2
                      0, 0, 0   // tri3
                      ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, bush_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(bush_b_tex_dummy, G_IM_FMT_CI, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_f_4_v[151], 13, 0),
    gsSPNTrianglesInit_5b(6,       // tri count
                          0, 1, 2, // tri0
                          3, 0, 4, // tri1
                          5, 6, 7  // tri2
                          ),
    gsSPNTriangles_5b(1, 5, 8,   // tri0
                      9, 10, 11, // tri1
                      10, 3, 12, // tri2
                      0, 0, 0    // tri3
                      ),
    gsSPEndDisplayList(),
};
