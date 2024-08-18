#include "libforest/gbi_extensions.h"

extern u8 cliff_pal_dummy[];
extern u8 earth_pal_dummy[];
extern u8 bridge_2_pal_dummy[];
extern u8 bridge_2_tex_dummy[];
extern u8 water_2_tex_dummy[];
extern u8 water_1_tex_dummy[];
extern u8 river_tex_dummy[];
extern u8 grass_tex_dummy[];
extern u8 earth_tex_dummy[];

static Vtx grd_s_r4_p_1_v[] = {
#include "assets/field/bg/grd_s_r4_p_1_v.inc"
};

extern Gfx grd_s_r4_p_1_modelT[] = {
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
    gsSPVertex(&grd_s_r4_p_1_v[265], 19, 0),
    gsSPNTrianglesInit_5b(20,      // tri count
                          0, 1, 2, // tri0
                          1, 3, 2, // tri1
                          4, 5, 6  // tri2
                          ),
    gsSPNTriangles_5b(5, 7, 6, // tri0
                      5, 8, 7, // tri1
                      4, 9, 5, // tri2
                      9, 10, 5 // tri3
                      ),
    gsSPNTriangles_5b(10, 8, 5, // tri0
                      4, 2, 3,  // tri1
                      0, 11, 1, // tri2
                      12, 1, 13 // tri3
                      ),
    gsSPNTriangles_5b(12, 14, 1, // tri0
                      1, 11, 13, // tri1
                      12, 4, 14, // tri2
                      12, 9, 4   // tri3
                      ),
    gsSPNTriangles_5b(2, 4, 6,   // tri0
                      15, 16, 0, // tri1
                      16, 11, 0, // tri2
                      7, 17, 18  // tri3
                      ),
    gsSPNTriangles_5b(7, 8, 17, // tri0
                      0, 0, 0,  // tri1
                      0, 0, 0,  // tri2
                      0, 0, 0   // tri3
                      ),
    gsSPEndDisplayList(),
};

extern Gfx grd_s_r4_p_1_model[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, bridge_2_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(bridge_2_tex_dummy, G_IM_FMT_CI, 128, 32, 15, GX_CLAMP, GX_REPEAT, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_r4_p_1_v[223], 32, 0),
    gsSPNTrianglesInit_5b(24,      // tri count
                          0, 1, 2, // tri0
                          0, 2, 3, // tri1
                          4, 5, 1  // tri2
                          ),
    gsSPNTriangles_5b(4, 1, 0, // tri0
                      5, 6, 7, // tri1
                      5, 7, 1, // tri2
                      8, 9, 10 // tri3
                      ),
    gsSPNTriangles_5b(8, 10, 11,  // tri0
                      12, 8, 11,  // tri1
                      12, 11, 13, // tri2
                      13, 11, 14  // tri3
                      ),
    gsSPNTriangles_5b(13, 14, 15, // tri0
                      16, 17, 18, // tri1
                      16, 18, 19, // tri2
                      20, 21, 17  // tri3
                      ),
    gsSPNTriangles_5b(20, 17, 16, // tri0
                      21, 22, 23, // tri1
                      21, 23, 17, // tri2
                      24, 25, 26  // tri3
                      ),
    gsSPNTriangles_5b(24, 26, 27, // tri0
                      28, 24, 27, // tri1
                      28, 27, 29, // tri2
                      29, 27, 30  // tri3
                      ),
    gsSPNTriangles_5b(29, 30, 31, // tri0
                      0, 0, 0,    // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_r4_p_1_v[255], 10, 0),
    gsSPNTrianglesInit_5b(6,       // tri count
                          0, 1, 2, // tri0
                          0, 2, 3, // tri1
                          4, 5, 6  // tri2
                          ),
    gsSPNTriangles_5b(4, 6, 7, // tri0
                      8, 4, 7, // tri1
                      8, 7, 9, // tri2
                      0, 0, 0  // tri3
                      ),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPLoadTLUT_Dolphin(15, 16, 1, earth_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(grass_tex_dummy, G_IM_FMT_CI, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPVertex(&grd_s_r4_p_1_v[0], 32, 0),
    gsSPNTrianglesInit_5b(21,      // tri count
                          0, 1, 2, // tri0
                          3, 4, 5, // tri1
                          4, 6, 5  // tri2
                          ),
    gsSPNTriangles_5b(2, 1, 6,  // tri0
                      5, 6, 1,  // tri1
                      7, 8, 9,  // tri2
                      9, 10, 11 // tri3
                      ),
    gsSPNTriangles_5b(11, 7, 9,   // tri0
                      11, 12, 7,  // tri1
                      13, 14, 15, // tri2
                      16, 17, 18  // tri3
                      ),
    gsSPNTriangles_5b(18, 17, 19, // tri0
                      20, 19, 17, // tri1
                      17, 21, 20, // tri2
                      17, 22, 21  // tri3
                      ),
    gsSPNTriangles_5b(0, 23, 24,  // tri0
                      23, 25, 24, // tri1
                      23, 26, 25, // tri2
                      27, 28, 29  // tri3
                      ),
    gsSPNTriangles_5b(29, 30, 27, // tri0
                      29, 31, 30, // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_r4_p_1_v[32], 32, 0),
    gsSPNTrianglesInit_5b(22,      // tri count
                          0, 1, 2, // tri0
                          3, 4, 5, // tri1
                          6, 7, 4  // tri2
                          ),
    gsSPNTriangles_5b(1, 8, 9,    // tri0
                      6, 10, 7,   // tri1
                      11, 12, 13, // tri2
                      12, 14, 13  // tri3
                      ),
    gsSPNTriangles_5b(12, 15, 14, // tri0
                      15, 16, 17, // tri1
                      16, 18, 19, // tri2
                      18, 20, 19  // tri3
                      ),
    gsSPNTriangles_5b(20, 21, 19, // tri0
                      20, 22, 21, // tri1
                      22, 23, 24, // tri2
                      14, 15, 25  // tri3
                      ),
    gsSPNTriangles_5b(15, 17, 25, // tri0
                      25, 26, 27, // tri1
                      26, 17, 28, // tri2
                      26, 25, 17  // tri3
                      ),
    gsSPNTriangles_5b(29, 2, 1, // tri0
                      1, 9, 29, // tri1
                      8, 30, 9, // tri2
                      0, 0, 0   // tri3
                      ),
    gsSPVertex(&grd_s_r4_p_1_v[63], 3, 0),
    gsSPNTrianglesInit_5b(1,       // tri count
                          0, 1, 2, // tri0
                          0, 0, 0, // tri1
                          0, 0, 0  // tri2
                          ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, cliff_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(river_tex_dummy, G_IM_FMT_CI, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_r4_p_1_v[66], 32, 0),
    gsSPNTrianglesInit_5b(33,      // tri count
                          0, 1, 2, // tri0
                          1, 3, 2, // tri1
                          0, 4, 1  // tri2
                          ),
    gsSPNTriangles_5b(0, 5, 4, // tri0
                      5, 6, 4, // tri1
                      6, 7, 4, // tri2
                      5, 8, 9  // tri3
                      ),
    gsSPNTriangles_5b(5, 9, 6,   // tri0
                      9, 7, 6,   // tri1
                      8, 10, 11, // tri2
                      8, 11, 9   // tri3
                      ),
    gsSPNTriangles_5b(11, 7, 9,   // tri0
                      10, 12, 13, // tri1
                      10, 13, 11, // tri2
                      13, 7, 11   // tri3
                      ),
    gsSPNTriangles_5b(12, 14, 15, // tri0
                      12, 15, 16, // tri1
                      15, 17, 16, // tri2
                      14, 18, 19  // tri3
                      ),
    gsSPNTriangles_5b(14, 19, 15, // tri0
                      19, 17, 15, // tri1
                      18, 20, 21, // tri2
                      18, 21, 22  // tri3
                      ),
    gsSPNTriangles_5b(21, 23, 22, // tri0
                      20, 24, 21, // tri1
                      24, 25, 23, // tri2
                      24, 23, 21  // tri3
                      ),
    gsSPNTriangles_5b(20, 26, 27, // tri0
                      20, 27, 24, // tri1
                      27, 25, 24, // tri2
                      26, 28, 29  // tri3
                      ),
    gsSPNTriangles_5b(26, 29, 30, // tri0
                      29, 31, 30, // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_r4_p_1_v[98], 32, 0),
    gsSPNTrianglesInit_5b(40,      // tri count
                          0, 1, 2, // tri0
                          0, 2, 3, // tri1
                          2, 4, 3  // tri2
                          ),
    gsSPNTriangles_5b(1, 5, 6, // tri0
                      1, 6, 2, // tri1
                      6, 4, 2, // tri2
                      5, 7, 6  // tri3
                      ),
    gsSPNTriangles_5b(7, 8, 4,  // tri0
                      7, 4, 6,  // tri1
                      5, 9, 10, // tri2
                      5, 10, 7  // tri3
                      ),
    gsSPNTriangles_5b(10, 8, 7,  // tri0
                      9, 11, 12, // tri1
                      9, 12, 10, // tri2
                      12, 8, 10  // tri3
                      ),
    gsSPNTriangles_5b(11, 13, 14, // tri0
                      11, 14, 12, // tri1
                      14, 8, 12,  // tri2
                      13, 15, 14  // tri3
                      ),
    gsSPNTriangles_5b(15, 16, 8,  // tri0
                      15, 8, 14,  // tri1
                      13, 17, 18, // tri2
                      13, 18, 15  // tri3
                      ),
    gsSPNTriangles_5b(18, 16, 15, // tri0
                      17, 19, 20, // tri1
                      17, 20, 18, // tri2
                      20, 16, 18  // tri3
                      ),
    gsSPNTriangles_5b(19, 21, 20, // tri0
                      21, 22, 16, // tri1
                      21, 16, 20, // tri2
                      19, 23, 24  // tri3
                      ),
    gsSPNTriangles_5b(19, 24, 21, // tri0
                      24, 22, 21, // tri1
                      23, 25, 24, // tri2
                      25, 22, 24  // tri3
                      ),
    gsSPNTriangles_5b(23, 26, 25, // tri0
                      26, 27, 25, // tri1
                      27, 28, 25, // tri2
                      27, 29, 28  // tri3
                      ),
    gsSPNTriangles_5b(29, 30, 28, // tri0
                      0, 0, 0,    // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_r4_p_1_v[129], 32, 0),
    gsSPNTrianglesInit_5b(38,      // tri count
                          0, 1, 2, // tri0
                          1, 3, 2, // tri1
                          4, 5, 6  // tri2
                          ),
    gsSPNTriangles_5b(5, 7, 6, // tri0
                      8, 7, 9, // tri1
                      8, 6, 7, // tri2
                      4, 10, 5 // tri3
                      ),
    gsSPNTriangles_5b(4, 11, 10,  // tri0
                      12, 13, 14, // tri1
                      13, 15, 5,  // tri2
                      13, 5, 14   // tri3
                      ),
    gsSPNTriangles_5b(11, 12, 14, // tri0
                      11, 14, 10, // tri1
                      14, 5, 10,  // tri2
                      12, 16, 13  // tri3
                      ),
    gsSPNTriangles_5b(16, 17, 15, // tri0
                      16, 15, 13, // tri1
                      12, 18, 19, // tri2
                      12, 19, 16  // tri3
                      ),
    gsSPNTriangles_5b(19, 17, 16, // tri0
                      18, 20, 19, // tri1
                      20, 21, 17, // tri2
                      20, 17, 19  // tri3
                      ),
    gsSPNTriangles_5b(18, 22, 20, // tri0
                      22, 23, 21, // tri1
                      22, 21, 20, // tri2
                      18, 24, 25  // tri3
                      ),
    gsSPNTriangles_5b(18, 25, 22, // tri0
                      25, 23, 22, // tri1
                      24, 26, 25, // tri2
                      26, 27, 23  // tri3
                      ),
    gsSPNTriangles_5b(26, 23, 25, // tri0
                      24, 28, 29, // tri1
                      24, 29, 26, // tri2
                      29, 27, 26  // tri3
                      ),
    gsSPNTriangles_5b(28, 30, 29, // tri0
                      30, 27, 29, // tri1
                      30, 31, 27, // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_r4_p_1_v[161], 5, 0),
    gsSPNTrianglesInit_5b(3,       // tri count
                          0, 1, 2, // tri0
                          0, 3, 1, // tri1
                          3, 4, 1  // tri2
                          ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, earth_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(earth_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_r4_p_1_v[166], 32, 0),
    gsSPNTrianglesInit_5b(18,      // tri count
                          0, 1, 2, // tri0
                          2, 3, 4, // tri1
                          4, 5, 6  // tri2
                          ),
    gsSPNTriangles_5b(6, 7, 8,    // tri0
                      8, 9, 10,   // tri1
                      10, 11, 12, // tri2
                      12, 13, 14  // tri3
                      ),
    gsSPNTriangles_5b(15, 16, 17, // tri0
                      15, 18, 16, // tri1
                      19, 20, 21, // tri2
                      19, 22, 23  // tri3
                      ),
    gsSPNTriangles_5b(22, 24, 23, // tri0
                      25, 23, 24, // tri1
                      26, 25, 27, // tri2
                      25, 24, 27  // tri3
                      ),
    gsSPNTriangles_5b(28, 29, 30, // tri0
                      29, 26, 30, // tri1
                      17, 31, 28, // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_r4_p_1_v[198], 25, 0),
    gsSPNTrianglesInit_5b(16,      // tri count
                          0, 1, 2, // tri0
                          3, 4, 5, // tri1
                          3, 6, 4  // tri2
                          ),
    gsSPNTriangles_5b(7, 4, 8,    // tri0
                      9, 10, 11,  // tri1
                      12, 13, 14, // tri2
                      9, 15, 10   // tri3
                      ),
    gsSPNTriangles_5b(15, 12, 10, // tri0
                      16, 17, 11, // tri1
                      17, 18, 11, // tri2
                      16, 19, 17  // tri3
                      ),
    gsSPNTriangles_5b(18, 9, 11,  // tri0
                      20, 21, 22, // tri1
                      21, 19, 23, // tri2
                      5, 20, 24   // tri3
                      ),
    gsSPNTriangles_5b(5, 24, 3, // tri0
                      0, 0, 0,  // tri1
                      0, 0, 0,  // tri2
                      0, 0, 0   // tri3
                      ),
    gsSPEndDisplayList(),
};