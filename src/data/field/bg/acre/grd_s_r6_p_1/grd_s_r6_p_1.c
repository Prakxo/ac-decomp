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

static Vtx grd_s_r6_p_1_v[] = {
#include "assets/field/bg/grd_s_r6_p_1_v.inc"
};

extern Gfx grd_s_r6_p_1_modelT[] = {
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
    gsSPVertex(&grd_s_r6_p_1_v[272], 31, 0),
    gsSPNTrianglesInit_5b(25,      // tri count
                          0, 1, 2, // tri0
                          1, 3, 2, // tri1
                          0, 4, 1  // tri2
                          ),
    gsSPNTriangles_5b(4, 5, 1, // tri0
                      5, 6, 1, // tri1
                      7, 8, 2, // tri2
                      8, 9, 2  // tri3
                      ),
    gsSPNTriangles_5b(8, 10, 9,  // tri0
                      8, 11, 10, // tri1
                      2, 12, 13, // tri2
                      2, 13, 0   // tri3
                      ),
    gsSPNTriangles_5b(2, 14, 12, // tri0
                      2, 15, 16, // tri1
                      17, 2, 18, // tri2
                      9, 18, 2   // tri3
                      ),
    gsSPNTriangles_5b(19, 2, 17,  // tri0
                      20, 21, 22, // tri1
                      20, 6, 21,  // tri2
                      1, 6, 20    // tri3
                      ),
    gsSPNTriangles_5b(2, 23, 24, // tri0
                      2, 25, 26, // tri1
                      2, 19, 27, // tri2
                      28, 11, 8  // tri3
                      ),
    gsSPNTriangles_5b(29, 30, 28, // tri0
                      30, 11, 28, // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPEndDisplayList(),
};

extern Gfx grd_s_r6_p_1_model[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, bridge_2_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(bridge_2_tex_dummy, G_IM_FMT_CI, 128, 32, 15, GX_CLAMP, GX_REPEAT, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_r6_p_1_v[228], 32, 0),
    gsSPNTrianglesInit_5b(22,      // tri count
                          0, 1, 2, // tri0
                          0, 2, 3, // tri1
                          1, 4, 5  // tri2
                          ),
    gsSPNTriangles_5b(1, 5, 2,   // tri0
                      6, 7, 8,   // tri1
                      6, 8, 9,   // tri2
                      10, 11, 12 // tri3
                      ),
    gsSPNTriangles_5b(10, 12, 13, // tri0
                      13, 12, 14, // tri1
                      13, 14, 15, // tri2
                      12, 16, 17  // tri3
                      ),
    gsSPNTriangles_5b(12, 17, 14, // tri0
                      18, 19, 20, // tri1
                      18, 20, 21, // tri2
                      22, 18, 21  // tri3
                      ),
    gsSPNTriangles_5b(22, 21, 23, // tri0
                      24, 25, 18, // tri1
                      24, 18, 22, // tri2
                      26, 27, 28  // tri3
                      ),
    gsSPNTriangles_5b(26, 28, 29, // tri0
                      29, 28, 30, // tri1
                      29, 30, 31, // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_r6_p_1_v[260], 12, 0),
    gsSPNTrianglesInit_5b(8,       // tri count
                          0, 1, 2, // tri0
                          0, 2, 3, // tri1
                          4, 5, 6  // tri2
                          ),
    gsSPNTriangles_5b(4, 6, 7,  // tri0
                      8, 4, 7,  // tri1
                      8, 7, 9,  // tri2
                      10, 11, 4 // tri3
                      ),
    gsSPNTriangles_5b(10, 4, 8, // tri0
                      0, 0, 0,  // tri1
                      0, 0, 0,  // tri2
                      0, 0, 0   // tri3
                      ),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPLoadTLUT_Dolphin(15, 16, 1, earth_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(grass_tex_dummy, G_IM_FMT_CI, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPVertex(&grd_s_r6_p_1_v[0], 32, 0),
    gsSPNTrianglesInit_5b(21,      // tri count
                          0, 1, 2, // tri0
                          3, 4, 5, // tri1
                          1, 0, 6  // tri2
                          ),
    gsSPNTriangles_5b(0, 2, 7, // tri0
                      0, 7, 8, // tri1
                      9, 8, 7, // tri2
                      10, 8, 9 // tri3
                      ),
    gsSPNTriangles_5b(4, 11, 5,   // tri0
                      12, 13, 14, // tri1
                      13, 15, 14, // tri2
                      14, 16, 12  // tri3
                      ),
    gsSPNTriangles_5b(14, 17, 16, // tri0
                      18, 19, 20, // tri1
                      19, 21, 20, // tri2
                      19, 22, 21  // tri3
                      ),
    gsSPNTriangles_5b(19, 23, 22, // tri0
                      19, 24, 25, // tri1
                      24, 26, 25, // tri2
                      24, 27, 26  // tri3
                      ),
    gsSPNTriangles_5b(24, 28, 27, // tri0
                      28, 29, 30, // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_r6_p_1_v[31], 32, 0),
    gsSPNTrianglesInit_5b(24,      // tri count
                          0, 1, 2, // tri0
                          1, 3, 4, // tri1
                          3, 5, 4  // tri2
                          ),
    gsSPNTriangles_5b(5, 6, 7,   // tri0
                      6, 8, 9,   // tri1
                      8, 10, 11, // tri2
                      12, 11, 10 // tri3
                      ),
    gsSPNTriangles_5b(13, 14, 12, // tri0
                      14, 15, 12, // tri1
                      15, 16, 12, // tri2
                      7, 4, 5     // tri3
                      ),
    gsSPNTriangles_5b(17, 7, 18, // tri0
                      18, 7, 19, // tri1
                      7, 6, 19,  // tri2
                      20, 19, 6  // tri3
                      ),
    gsSPNTriangles_5b(9, 20, 6,  // tri0
                      0, 2, 21,  // tri1
                      22, 0, 21, // tri2
                      23, 0, 22  // tri3
                      ),
    gsSPNTriangles_5b(24, 25, 23, // tri0
                      26, 25, 24, // tri1
                      27, 28, 29, // tri2
                      16, 30, 12  // tri3
                      ),
    gsSPNTriangles_5b(12, 30, 11, // tri0
                      0, 0, 0,    // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_r6_p_1_v[62], 5, 0),
    gsSPNTrianglesInit_5b(2,       // tri count
                          0, 1, 2, // tri0
                          2, 3, 4, // tri1
                          0, 0, 0  // tri2
                          ),
    gsDPLoadTextureBlock_4b_Dolphin(earth_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_r6_p_1_v[67], 32, 0),
    gsSPNTrianglesInit_5b(19,      // tri count
                          0, 1, 2, // tri0
                          1, 3, 2, // tri1
                          4, 5, 6  // tri2
                          ),
    gsSPNTriangles_5b(7, 8, 9,   // tri0
                      8, 4, 9,   // tri1
                      3, 10, 11, // tri2
                      10, 12, 11 // tri3
                      ),
    gsSPNTriangles_5b(12, 13, 14, // tri0
                      13, 7, 14,  // tri1
                      15, 16, 17, // tri2
                      16, 18, 17  // tri3
                      ),
    gsSPNTriangles_5b(17, 19, 20, // tri0
                      21, 22, 15, // tri1
                      23, 24, 21, // tri2
                      25, 26, 27  // tri3
                      ),
    gsSPNTriangles_5b(26, 23, 27, // tri0
                      25, 28, 26, // tri1
                      25, 29, 28, // tri2
                      29, 30, 28  // tri3
                      ),
    gsSPVertex(&grd_s_r6_p_1_v[98], 3, 0),
    gsSPNTrianglesInit_5b(1,       // tri count
                          0, 1, 2, // tri0
                          0, 0, 0, // tri1
                          0, 0, 0  // tri2
                          ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, cliff_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(river_tex_dummy, G_IM_FMT_CI, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_r6_p_1_v[101], 32, 0),
    gsSPNTrianglesInit_5b(30,      // tri count
                          0, 1, 2, // tri0
                          2, 3, 0, // tri1
                          2, 4, 3  // tri2
                          ),
    gsSPNTriangles_5b(4, 5, 3, // tri0
                      4, 6, 5, // tri1
                      4, 7, 6, // tri2
                      7, 8, 9  // tri3
                      ),
    gsSPNTriangles_5b(8, 10, 5,  // tri0
                      8, 5, 9,   // tri1
                      7, 11, 12, // tri2
                      7, 12, 13  // tri3
                      ),
    gsSPNTriangles_5b(12, 10, 13, // tri0
                      11, 14, 12, // tri1
                      14, 15, 10, // tri2
                      14, 10, 12  // tri3
                      ),
    gsSPNTriangles_5b(11, 16, 14, // tri0
                      16, 17, 15, // tri1
                      16, 15, 14, // tri2
                      11, 18, 16  // tri3
                      ),
    gsSPNTriangles_5b(18, 19, 17, // tri0
                      18, 17, 16, // tri1
                      20, 21, 22, // tri2
                      21, 23, 19  // tri3
                      ),
    gsSPNTriangles_5b(21, 19, 22, // tri0
                      24, 25, 26, // tri1
                      25, 27, 23, // tri2
                      25, 23, 26  // tri3
                      ),
    gsSPNTriangles_5b(28, 29, 30, // tri0
                      29, 31, 27, // tri1
                      29, 27, 30, // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_r6_p_1_v[133], 32, 0),
    gsSPNTrianglesInit_5b(31,      // tri count
                          0, 1, 2, // tri0
                          1, 3, 4, // tri1
                          1, 4, 2  // tri2
                          ),
    gsSPNTriangles_5b(5, 6, 7,  // tri0
                      6, 8, 3,  // tri1
                      6, 3, 7,  // tri2
                      9, 10, 11 // tri3
                      ),
    gsSPNTriangles_5b(10, 12, 8, // tri0
                      10, 8, 11, // tri1
                      9, 13, 10, // tri2
                      13, 14, 12 // tri3
                      ),
    gsSPNTriangles_5b(13, 12, 10, // tri0
                      9, 15, 16,  // tri1
                      9, 16, 13,  // tri2
                      16, 14, 13  // tri3
                      ),
    gsSPNTriangles_5b(15, 17, 16, // tri0
                      17, 18, 14, // tri1
                      17, 14, 16, // tri2
                      15, 19, 20  // tri3
                      ),
    gsSPNTriangles_5b(15, 20, 17, // tri0
                      20, 18, 17, // tri1
                      19, 21, 20, // tri2
                      21, 22, 18  // tri3
                      ),
    gsSPNTriangles_5b(21, 18, 20, // tri0
                      19, 23, 21, // tri1
                      23, 24, 22, // tri2
                      23, 22, 21  // tri3
                      ),
    gsSPNTriangles_5b(25, 26, 27, // tri0
                      26, 28, 24, // tri1
                      26, 24, 27, // tri2
                      29, 30, 31  // tri3
                      ),
    gsSPVertex(&grd_s_r6_p_1_v[165], 32, 0),
    gsSPNTrianglesInit_5b(29,      // tri count
                          0, 1, 2, // tri0
                          0, 2, 3, // tri1
                          4, 5, 6  // tri2
                          ),
    gsSPNTriangles_5b(5, 7, 1,  // tri0
                      5, 1, 6,  // tri1
                      8, 9, 10, // tri2
                      9, 11, 7  // tri3
                      ),
    gsSPNTriangles_5b(9, 7, 10,   // tri0
                      12, 13, 14, // tri1
                      13, 15, 11, // tri2
                      13, 11, 14  // tri3
                      ),
    gsSPNTriangles_5b(16, 17, 18, // tri0
                      17, 19, 15, // tri1
                      17, 15, 18, // tri2
                      16, 20, 17  // tri3
                      ),
    gsSPNTriangles_5b(20, 21, 19, // tri0
                      20, 19, 17, // tri1
                      16, 22, 23, // tri2
                      16, 23, 20  // tri3
                      ),
    gsSPNTriangles_5b(23, 21, 20, // tri0
                      22, 24, 23, // tri1
                      24, 25, 21, // tri2
                      24, 21, 23  // tri3
                      ),
    gsSPNTriangles_5b(22, 26, 24, // tri0
                      26, 25, 24, // tri1
                      26, 27, 25, // tri2
                      27, 28, 25  // tri3
                      ),
    gsSPNTriangles_5b(27, 29, 28, // tri0
                      27, 30, 29, // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_r6_p_1_v[196], 32, 0),
    gsSPNTrianglesInit_5b(39,      // tri count
                          0, 1, 2, // tri0
                          0, 3, 1, // tri1
                          3, 4, 1  // tri2
                          ),
    gsSPNTriangles_5b(4, 5, 2, // tri0
                      4, 2, 1, // tri1
                      6, 7, 8, // tri2
                      7, 9, 8  // tri3
                      ),
    gsSPNTriangles_5b(7, 10, 9, // tri0
                      7, 2, 10, // tri1
                      7, 0, 2,  // tri2
                      3, 11, 4  // tri3
                      ),
    gsSPNTriangles_5b(11, 12, 5, // tri0
                      11, 5, 4,  // tri1
                      3, 13, 14, // tri2
                      3, 14, 11  // tri3
                      ),
    gsSPNTriangles_5b(14, 12, 11, // tri0
                      13, 15, 16, // tri1
                      13, 16, 14, // tri2
                      16, 12, 14  // tri3
                      ),
    gsSPNTriangles_5b(15, 17, 16, // tri0
                      17, 18, 12, // tri1
                      17, 12, 16, // tri2
                      15, 19, 20  // tri3
                      ),
    gsSPNTriangles_5b(15, 20, 17, // tri0
                      20, 18, 17, // tri1
                      19, 21, 22, // tri2
                      19, 22, 20  // tri3
                      ),
    gsSPNTriangles_5b(22, 18, 20, // tri0
                      21, 23, 22, // tri1
                      23, 24, 18, // tri2
                      23, 18, 22  // tri3
                      ),
    gsSPNTriangles_5b(21, 25, 23, // tri0
                      25, 24, 23, // tri1
                      25, 26, 24, // tri2
                      25, 27, 26  // tri3
                      ),
    gsSPNTriangles_5b(25, 28, 27, // tri0
                      28, 29, 27, // tri1
                      28, 30, 29, // tri2
                      28, 31, 30  // tri3
                      ),
    gsSPEndDisplayList(),
};
