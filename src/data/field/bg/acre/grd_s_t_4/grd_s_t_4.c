#include "libforest/gbi_extensions.h"

extern u8 rail_pal_dummy[];
extern u8 bush_pal_dummy[];
extern u8 cliff_pal_dummy[];
extern u8 earth_pal_dummy[];
extern u8 water_2_tex_dummy[];
extern u8 water_1_tex_dummy[];
extern u8 river_tex_dummy[];
extern u8 rail_tex_dummy[];
extern u8 grass_tex_dummy[];
extern u8 bush_b_tex_dummy[];
extern u8 bush_a_tex_dummy[];
extern u8 earth_tex_dummy[];

static Vtx grd_s_t_4_v[] = {
#include "assets/field/bg/grd_s_t_4_v.inc"
};

extern Gfx grd_s_t_4_modelT[] = {
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
    gsSPVertex(&grd_s_t_4_v[230], 4, 0),
    gsSPNTrianglesInit_5b(2,       // tri count
                          0, 1, 2, // tri0
                          0, 2, 3, // tri1
                          0, 0, 0  // tri2
                          ),
    gsSPEndDisplayList(),
};

extern Gfx grd_s_t_4_model[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, bush_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(bush_a_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_t_4_v[208], 22, 0),
    gsSPNTrianglesInit_5b(10,      // tri count
                          0, 1, 2, // tri0
                          3, 0, 4, // tri1
                          5, 3, 6  // tri2
                          ),
    gsSPNTriangles_5b(7, 5, 8,    // tri0
                      9, 7, 10,   // tri1
                      11, 12, 13, // tri2
                      14, 11, 15  // tri3
                      ),
    gsSPNTriangles_5b(16, 14, 17, // tri0
                      18, 16, 19, // tri1
                      20, 18, 21, // tri2
                      0, 0, 0     // tri3
                      ),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPLoadTLUT_Dolphin(15, 16, 1, earth_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(grass_tex_dummy, G_IM_FMT_CI, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPVertex(&grd_s_t_4_v[0], 32, 0),
    gsSPNTrianglesInit_5b(21,      // tri count
                          0, 1, 2, // tri0
                          1, 3, 2, // tri1
                          4, 5, 6  // tri2
                          ),
    gsSPNTriangles_5b(6, 7, 8,    // tri0
                      8, 9, 10,   // tri1
                      10, 11, 12, // tri2
                      13, 14, 15  // tri3
                      ),
    gsSPNTriangles_5b(14, 16, 17, // tri0
                      16, 18, 19, // tri1
                      16, 20, 18, // tri2
                      2, 21, 0    // tri3
                      ),
    gsSPNTriangles_5b(21, 22, 23, // tri0
                      24, 25, 26, // tri1
                      25, 27, 26, // tri2
                      23, 22, 28  // tri3
                      ),
    gsSPNTriangles_5b(5, 7, 6,   // tri0
                      7, 9, 8,   // tri1
                      9, 11, 10, // tri2
                      11, 29, 12 // tri3
                      ),
    gsSPNTriangles_5b(30, 31, 24, // tri0
                      24, 26, 30, // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_t_4_v[32], 32, 0),
    gsSPNTrianglesInit_5b(17,      // tri count
                          0, 1, 2, // tri0
                          3, 4, 5, // tri1
                          6, 7, 8  // tri2
                          ),
    gsSPNTriangles_5b(9, 10, 11,  // tri0
                      12, 13, 14, // tri1
                      15, 16, 17, // tri2
                      16, 18, 17  // tri3
                      ),
    gsSPNTriangles_5b(19, 20, 21, // tri0
                      15, 20, 16, // tri1
                      22, 21, 20, // tri2
                      22, 20, 15  // tri3
                      ),
    gsSPNTriangles_5b(23, 24, 25, // tri0
                      25, 26, 27, // tri1
                      28, 27, 26, // tri2
                      21, 22, 29  // tri3
                      ),
    gsSPNTriangles_5b(30, 29, 22, // tri0
                      30, 28, 29, // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_t_4_v[63], 16, 0),
    gsSPNTrianglesInit_5b(10,      // tri count
                          0, 1, 2, // tri0
                          0, 3, 1, // tri1
                          3, 0, 4  // tri2
                          ),
    gsSPNTriangles_5b(5, 4, 0,  // tri0
                      6, 7, 8,  // tri1
                      9, 6, 10, // tri2
                      7, 6, 11  // tri3
                      ),
    gsSPNTriangles_5b(6, 9, 11,   // tri0
                      12, 13, 14, // tri1
                      15, 11, 9,  // tri2
                      0, 0, 0     // tri3
                      ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, rail_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(rail_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_t_4_v[79], 20, 0),
    gsSPNTrianglesInit_5b(24,      // tri count
                          0, 1, 2, // tri0
                          0, 2, 3, // tri1
                          3, 2, 4  // tri2
                          ),
    gsSPNTriangles_5b(3, 4, 5, // tri0
                      5, 4, 6, // tri1
                      5, 6, 7, // tri2
                      7, 6, 8  // tri3
                      ),
    gsSPNTriangles_5b(7, 8, 9,   // tri0
                      1, 10, 11, // tri1
                      1, 11, 2,  // tri2
                      2, 11, 12  // tri3
                      ),
    gsSPNTriangles_5b(2, 12, 4,  // tri0
                      4, 12, 13, // tri1
                      4, 13, 6,  // tri2
                      6, 13, 14  // tri3
                      ),
    gsSPNTriangles_5b(6, 14, 8,   // tri0
                      10, 15, 16, // tri1
                      10, 16, 11, // tri2
                      11, 16, 17  // tri3
                      ),
    gsSPNTriangles_5b(11, 17, 12, // tri0
                      12, 17, 18, // tri1
                      12, 18, 13, // tri2
                      13, 18, 19  // tri3
                      ),
    gsSPNTriangles_5b(13, 19, 14, // tri0
                      0, 0, 0,    // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, earth_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(earth_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_t_4_v[99], 32, 0),
    gsSPNTrianglesInit_5b(17,      // tri count
                          0, 1, 2, // tri0
                          3, 4, 5, // tri1
                          6, 7, 8  // tri2
                          ),
    gsSPNTriangles_5b(7, 9, 8,    // tri0
                      8, 10, 11,  // tri1
                      12, 13, 14, // tri2
                      12, 15, 13  // tri3
                      ),
    gsSPNTriangles_5b(15, 16, 13, // tri0
                      16, 17, 18, // tri1
                      19, 20, 21, // tri2
                      12, 14, 22  // tri3
                      ),
    gsSPNTriangles_5b(14, 23, 22, // tri0
                      14, 19, 23, // tri1
                      21, 24, 6,  // tri2
                      25, 2, 26   // tri3
                      ),
    gsSPNTriangles_5b(3, 27, 28, // tri0
                      0, 5, 29,  // tri1
                      0, 0, 0,   // tri2
                      0, 0, 0    // tri3
                      ),
    gsSPVertex(&grd_s_t_4_v[129], 32, 0),
    gsSPNTrianglesInit_5b(20,      // tri count
                          0, 1, 2, // tri0
                          3, 0, 4, // tri1
                          5, 6, 7  // tri2
                          ),
    gsSPNTriangles_5b(5, 7, 8,    // tri0
                      6, 3, 9,    // tri1
                      10, 11, 12, // tri2
                      13, 14, 15  // tri3
                      ),
    gsSPNTriangles_5b(16, 17, 14, // tri0
                      18, 19, 20, // tri1
                      18, 21, 19, // tri2
                      21, 22, 23  // tri3
                      ),
    gsSPNTriangles_5b(22, 8, 23,  // tri0
                      24, 25, 26, // tri1
                      25, 27, 28, // tri2
                      27, 18, 20  // tri3
                      ),
    gsSPNTriangles_5b(16, 29, 17, // tri0
                      29, 24, 17, // tri1
                      30, 31, 15, // tri2
                      10, 30, 11  // tri3
                      ),
    gsSPNTriangles_5b(31, 13, 15, // tri0
                      0, 0, 0,    // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, cliff_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(river_tex_dummy, G_IM_FMT_CI, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_t_4_v[161], 25, 0),
    gsSPNTrianglesInit_5b(17,      // tri count
                          0, 1, 2, // tri0
                          1, 3, 2, // tri1
                          3, 4, 2  // tri2
                          ),
    gsSPNTriangles_5b(3, 5, 4, // tri0
                      6, 7, 5, // tri1
                      6, 8, 7, // tri2
                      9, 10, 8 // tri3
                      ),
    gsSPNTriangles_5b(9, 11, 10,  // tri0
                      12, 13, 11, // tri1
                      12, 14, 13, // tri2
                      14, 15, 13  // tri3
                      ),
    gsSPNTriangles_5b(16, 17, 15, // tri0
                      16, 18, 17, // tri1
                      19, 20, 18, // tri2
                      21, 22, 20  // tri3
                      ),
    gsSPNTriangles_5b(21, 23, 22, // tri0
                      21, 24, 23, // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, bush_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(bush_b_tex_dummy, G_IM_FMT_CI, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_t_4_v[186], 22, 0),
    gsSPNTrianglesInit_5b(10,      // tri count
                          0, 1, 2, // tri0
                          3, 4, 5, // tri1
                          4, 6, 7  // tri2
                          ),
    gsSPNTriangles_5b(1, 8, 9,    // tri0
                      8, 3, 10,   // tri1
                      11, 12, 13, // tri2
                      14, 11, 15  // tri3
                      ),
    gsSPNTriangles_5b(16, 17, 18, // tri0
                      12, 16, 19, // tri1
                      20, 14, 21, // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPEndDisplayList(),
};
