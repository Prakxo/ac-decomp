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

static Vtx grd_s_r3_4_v[] = {
#include "assets/field/bg/grd_s_r3_4_v.inc"
};

extern Gfx grd_s_r3_4_modelT[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 1, 0, TEXEL0, TEXEL1, COMBINED, 0, SHADE, TEXEL0,
                       COMBINED, 0, PRIM_LOD_FRAC, PRIMITIVE),
    gsDPSetPrimColor(0, 50, 255, 255, 255, 50),
    gsDPSetEnvColor(0x00, 0x64, 0xFF, 0xFF),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_ZB_XLU_SURF2),
    gsDPLoadTextureBlock_4b_Dolphin(water_1_tex_dummy, G_IM_FMT_I, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsDPLoadMultiBlock_4b_Dolphin(water_2_tex_dummy, 1, G_IM_FMT_I, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPDisplayList(0x08000000),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_r3_4_v[173], 16, 0),
    gsSPNTrianglesInit_5b(14,      // tri count
                          0, 1, 2, // tri0
                          3, 0, 2, // tri1
                          4, 3, 2  // tri2
                          ),
    gsSPNTriangles_5b(4, 2, 5,   // tri0
                      6, 7, 8,   // tri1
                      9, 6, 8,   // tri2
                      10, 11, 12 // tri3
                      ),
    gsSPNTriangles_5b(10, 12, 13, // tri0
                      14, 15, 10, // tri1
                      14, 10, 13, // tri2
                      5, 7, 6     // tri3
                      ),
    gsSPNTriangles_5b(4, 5, 6,   // tri0
                      11, 9, 8,  // tri1
                      11, 8, 12, // tri2
                      0, 0, 0    // tri3
                      ),
    gsSPEndDisplayList(),
};

extern Gfx grd_s_r3_4_model[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, bush_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(bush_a_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_r3_4_v[160], 13, 0),
    gsSPNTrianglesInit_5b(6,       // tri count
                          0, 1, 2, // tri0
                          3, 0, 4, // tri1
                          5, 3, 6  // tri2
                          ),
    gsSPNTriangles_5b(7, 5, 8,   // tri0
                      9, 7, 10,  // tri1
                      11, 9, 12, // tri2
                      0, 0, 0    // tri3
                      ),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPLoadTLUT_Dolphin(15, 16, 1, earth_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(grass_tex_dummy, G_IM_FMT_CI, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPVertex(&grd_s_r3_4_v[0], 32, 0),
    gsSPNTrianglesInit_5b(24,      // tri count
                          0, 1, 2, // tri0
                          1, 3, 2, // tri1
                          3, 4, 2  // tri2
                          ),
    gsSPNTriangles_5b(5, 4, 6, // tri0
                      4, 3, 6, // tri1
                      1, 7, 3, // tri2
                      1, 8, 7  // tri3
                      ),
    gsSPNTriangles_5b(9, 10, 11, // tri0
                      12, 9, 11, // tri1
                      7, 13, 3,  // tri2
                      13, 14, 3  // tri3
                      ),
    gsSPNTriangles_5b(15, 16, 12, // tri0
                      17, 18, 19, // tri1
                      18, 20, 19, // tri2
                      18, 21, 20  // tri3
                      ),
    gsSPNTriangles_5b(21, 22, 20, // tri0
                      21, 23, 22, // tri1
                      21, 24, 23, // tri2
                      25, 26, 24  // tri3
                      ),
    gsSPNTriangles_5b(25, 27, 26, // tri0
                      25, 28, 27, // tri1
                      28, 29, 27, // tri2
                      29, 30, 27  // tri3
                      ),
    gsSPNTriangles_5b(30, 31, 27, // tri0
                      0, 0, 0,    // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_r3_4_v[32], 26, 0),
    gsSPNTrianglesInit_5b(16,      // tri count
                          0, 1, 2, // tri0
                          3, 4, 5, // tri1
                          4, 6, 5  // tri2
                          ),
    gsSPNTriangles_5b(7, 8, 9,   // tri0
                      8, 10, 9,  // tri1
                      8, 11, 10, // tri2
                      12, 13, 11 // tri3
                      ),
    gsSPNTriangles_5b(11, 14, 10, // tri0
                      8, 12, 11,  // tri1
                      7, 15, 16,  // tri2
                      9, 15, 7    // tri3
                      ),
    gsSPNTriangles_5b(17, 18, 13, // tri0
                      19, 20, 21, // tri1
                      20, 22, 21, // tri2
                      20, 23, 22  // tri3
                      ),
    gsSPNTriangles_5b(24, 25, 23, // tri0
                      0, 0, 0,    // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsDPLoadTextureBlock_4b_Dolphin(earth_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_r3_4_v[58], 32, 0),
    gsSPNTrianglesInit_5b(16,      // tri count
                          0, 1, 2, // tri0
                          3, 4, 5, // tri1
                          6, 3, 7  // tri2
                          ),
    gsSPNTriangles_5b(1, 8, 9,    // tri0
                      8, 6, 10,   // tri1
                      11, 12, 13, // tri2
                      11, 14, 15  // tri3
                      ),
    gsSPNTriangles_5b(16, 15, 14, // tri0
                      17, 16, 14, // tri1
                      18, 19, 17, // tri2
                      20, 21, 18  // tri3
                      ),
    gsSPNTriangles_5b(22, 23, 20, // tri0
                      22, 24, 23, // tri1
                      22, 25, 24, // tri2
                      25, 26, 27  // tri3
                      ),
    gsSPNTriangles_5b(28, 29, 30, // tri0
                      0, 0, 0,    // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_r3_4_v[89], 17, 0),
    gsSPNTrianglesInit_5b(9,       // tri count
                          0, 1, 2, // tri0
                          3, 4, 0, // tri1
                          5, 6, 3  // tri2
                          ),
    gsSPNTriangles_5b(7, 8, 9,    // tri0
                      10, 11, 12, // tri1
                      13, 12, 11, // tri2
                      5, 7, 14    // tri3
                      ),
    gsSPNTriangles_5b(5, 14, 6,   // tri0
                      13, 15, 16, // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, bush_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(bush_b_tex_dummy, G_IM_FMT_CI, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_r3_4_v[106], 13, 0),
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
    gsDPLoadTLUT_Dolphin(15, 16, 1, cliff_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(river_tex_dummy, G_IM_FMT_CI, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_r3_4_v[119], 32, 0),
    gsSPNTrianglesInit_5b(28,      // tri count
                          0, 1, 2, // tri0
                          0, 3, 1, // tri1
                          4, 5, 6  // tri2
                          ),
    gsSPNTriangles_5b(7, 4, 6, // tri0
                      8, 7, 6, // tri1
                      8, 6, 9, // tri2
                      8, 9, 10 // tri3
                      ),
    gsSPNTriangles_5b(11, 8, 10,  // tri0
                      11, 10, 12, // tri1
                      11, 12, 13, // tri2
                      14, 11, 13  // tri3
                      ),
    gsSPNTriangles_5b(14, 13, 15, // tri0
                      14, 15, 16, // tri1
                      17, 14, 16, // tri2
                      17, 16, 18  // tri3
                      ),
    gsSPNTriangles_5b(19, 17, 18, // tri0
                      19, 18, 20, // tri1
                      21, 22, 19, // tri2
                      21, 19, 20  // tri3
                      ),
    gsSPNTriangles_5b(23, 24, 0, // tri0
                      25, 23, 0, // tri1
                      2, 25, 0,  // tri2
                      26, 1, 3   // tri3
                      ),
    gsSPNTriangles_5b(26, 3, 27,  // tri0
                      28, 26, 27, // tri1
                      29, 28, 27, // tri2
                      29, 27, 30  // tri3
                      ),
    gsSPNTriangles_5b(31, 29, 30, // tri0
                      0, 0, 0,    // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_r3_4_v[151], 9, 0),
    gsSPNTrianglesInit_5b(7,       // tri count
                          0, 1, 2, // tri0
                          0, 2, 3, // tri1
                          4, 0, 3  // tri2
                          ),
    gsSPNTriangles_5b(4, 3, 5, // tri0
                      6, 4, 5, // tri1
                      7, 6, 5, // tri2
                      8, 7, 5  // tri3
                      ),
    gsSPEndDisplayList(),
};