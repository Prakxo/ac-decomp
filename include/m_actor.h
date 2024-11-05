#ifndef M_ACTOR_H
#define M_ACTOR_H

#include "types.h"
#include "m_actor_type.h"
#include "game.h"
#include "m_lib.h"
#include "m_lights.h"
#include "m_collision_bg.h"
#include "m_collision_obj.h"
#include "m_actor_dlftbls.h"
#include "libforest/gbi_extensions.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*mActor_proc)(ACTOR*, GAME*);
#define NONE_ACTOR_PROC ((mActor_proc) & none_proc1)

#define mAc_MAX_ACTORS 200

#define ACTOR_STATE_NONE 0
#define ACTOR_STATE_0 (1 << 0)
#define ACTOR_STATE_2 (1 << 2)
#define ACTOR_STATE_NO_MOVE_WHILE_CULLED (1 << 4)
#define ACTOR_STATE_NO_DRAW_WHILE_CULLED (1 << 5)
#define ACTOR_STATE_NO_CULL (1 << 6)
#define ACTOR_STATE_INVISIBLE (1 << 7)
#define ACTOR_STATE_TA_SET (1 << 11)
#define ACTOR_STATE_LIGHTING (1 << 22) // does lighting NOT affect this actor?
#define ACTOR_STATE_24 (1 << 24)
#define ACTOR_STATE_25 (1 << 25)
#define ACTOR_STATE_26 (1 << 26)
#define ACTOR_STATE_27 (1 << 27)
#define ACTOR_STATE_28 (1 << 28)
#define ACTOR_STATE_CAN_MOVE_IN_DEMO_SCENES (1 << 29)
#define ACTOR_STATE_IN_DEMO (1 << 30)

// TODO: Name the unique ones for their correspondant actor

typedef enum bank_id {
    ACTOR_OBJ_BANK_NONE,
    ACTOR_OBJ_BANK_1,
    ACTOR_OBJ_BANK_2,
    ACTOR_OBJ_BANK_KEEP,
    ACTOR_OBJ_BANK_BGITEM,
    ACTOR_OBJ_BANK_ROOM_SUNSHINE,
    ACTOR_OBJ_BANK_6,
    ACTOR_OBJ_BANK_AIRPLANE,
    ACTOR_OBJ_BANK_8,
    ACTOR_OBJ_BANK_9,
    ACTOR_OBJ_BANK_10,
    ACTOR_OBJ_BANK_TRAINDOOR,
    ACTOR_OBJ_BANK_12,
    ACTOR_OBJ_BANK_13,
    ACTOR_OBJ_BANK_14,
    ACTOR_OBJ_BANK_15,
    ACTOR_OBJ_BANK_TOOLS,
    ACTOR_OBJ_BANK_17,
    ACTOR_OBJ_BANK_18,
    ACTOR_OBJ_BANK_19,
    ACTOR_OBJ_BANK_20,
    ACTOR_OBJ_BANK_21,
    ACTOR_OBJ_BANK_KAMAKURA_INDOOR,
    ACTOR_OBJ_BANK_23,
    ACTOR_OBJ_BANK_24,
    ACTOR_OBJ_BANK_PSNOWMAN,
    ACTOR_OBJ_BANK_26,
    ACTOR_OBJ_BANK_27,
    ACTOR_OBJ_BANK_UMBRELLA,
    ACTOR_OBJ_BANK_29,
    ACTOR_OBJ_BANK_SHOP_GOODS,
    ACTOR_OBJ_BANK_31,
    ACTOR_OBJ_BANK_32,
    ACTOR_OBJ_BANK_33,
    ACTOR_OBJ_BANK_34,
    ACTOR_OBJ_BANK_35,
    ACTOR_OBJ_BANK_BG_CHERRY_ITEM,
    ACTOR_OBJ_BANK_BG_WINTER_ITEM,
    ACTOR_OBJ_BANK_BG_XMAS_ITEM,
    ACTOR_OBJ_BANK_39,
    ACTOR_OBJ_BANK_40,
    ACTOR_OBJ_BANK_TRAINWINDOW,
    ACTOR_OBJ_BANK_42,
    ACTOR_OBJ_BANK_POSTHOUSE,
    ACTOR_OBJ_BANK_EF_POLICE,
    ACTOR_OBJ_BANK_KEITAI,
    ACTOR_OBJ_BANK_46,
    ACTOR_OBJ_BANK_47,
    ACTOR_OBJ_BANK_UKI,
    ACTOR_OBJ_BANK_49,
    ACTOR_OBJ_BANK_50,
    ACTOR_OBJ_BANK_51,
    ACTOR_OBJ_BANK_52,
    ACTOR_OBJ_BANK_HANABI,
    ACTOR_OBJ_BANK_54,
    ACTOR_OBJ_BANK_55,
    ACTOR_OBJ_BANK_56,
    ACTOR_OBJ_BANK_57,
    ACTOR_OBJ_BANK_58,
    ACTOR_OBJ_BANK_59,
    ACTOR_OBJ_BANK_60,
    ACTOR_OBJ_BANK_61,
    ACTOR_OBJ_BANK_62,
    ACTOR_OBJ_BANK_63,
    ACTOR_OBJ_BANK_64,
    ACTOR_OBJ_BANK_65,
    ACTOR_OBJ_BANK_66,
    ACTOR_OBJ_BANK_67,
    ACTOR_OBJ_BANK_68,
    ACTOR_OBJ_BANK_69,
    ACTOR_OBJ_BANK_70,
    ACTOR_OBJ_BANK_71,
    ACTOR_OBJ_BANK_72,
    ACTOR_OBJ_BANK_73,
    ACTOR_OBJ_BANK_74,
    ACTOR_OBJ_BANK_75,
    ACTOR_OBJ_BANK_76,
    ACTOR_OBJ_BANK_77,
    ACTOR_OBJ_BANK_78,
    ACTOR_OBJ_BANK_79,
    ACTOR_OBJ_BANK_80,
    ACTOR_OBJ_BANK_81,
    ACTOR_OBJ_BANK_82,
    ACTOR_OBJ_BANK_83,
    ACTOR_OBJ_BANK_84,
    ACTOR_OBJ_BANK_85,
    ACTOR_OBJ_BANK_86,
    ACTOR_OBJ_BANK_87,
    ACTOR_OBJ_BANK_88,
    ACTOR_OBJ_BANK_89,
    ACTOR_OBJ_BANK_90,
    ACTOR_OBJ_BANK_91,
    ACTOR_OBJ_BANK_92,
    ACTOR_OBJ_BANK_93,
    ACTOR_OBJ_BANK_94,
    ACTOR_OBJ_BANK_95,
    ACTOR_OBJ_BANK_96,
    ACTOR_OBJ_BANK_97,
    ACTOR_OBJ_BANK_98,
    ACTOR_OBJ_BANK_99,
    ACTOR_OBJ_BANK_100,
    ACTOR_OBJ_BANK_101,
    ACTOR_OBJ_BANK_102,
    ACTOR_OBJ_BANK_103,
    ACTOR_OBJ_BANK_104,
    ACTOR_OBJ_BANK_105,
    ACTOR_OBJ_BANK_106,
    ACTOR_OBJ_BANK_107,
    ACTOR_OBJ_BANK_108,
    ACTOR_OBJ_BANK_109,
    ACTOR_OBJ_BANK_110,
    ACTOR_OBJ_BANK_111,
    ACTOR_OBJ_BANK_112,
    ACTOR_OBJ_BANK_113,
    ACTOR_OBJ_BANK_114,
    ACTOR_OBJ_BANK_115,
    ACTOR_OBJ_BANK_116,
    ACTOR_OBJ_BANK_117,
    ACTOR_OBJ_BANK_118,
    ACTOR_OBJ_BANK_119,
    ACTOR_OBJ_BANK_120,
    ACTOR_OBJ_BANK_121,
    ACTOR_OBJ_BANK_122,
    ACTOR_OBJ_BANK_123,
    ACTOR_OBJ_BANK_124,
    ACTOR_OBJ_BANK_125,
    ACTOR_OBJ_BANK_126,
    ACTOR_OBJ_BANK_127,
    ACTOR_OBJ_BANK_128,
    ACTOR_OBJ_BANK_129,
    ACTOR_OBJ_BANK_130,
    ACTOR_OBJ_BANK_131,
    ACTOR_OBJ_BANK_132,
    ACTOR_OBJ_BANK_133,
    ACTOR_OBJ_BANK_134,
    ACTOR_OBJ_BANK_135,
    ACTOR_OBJ_BANK_136,
    ACTOR_OBJ_BANK_137,
    ACTOR_OBJ_BANK_138,
    ACTOR_OBJ_BANK_139,
    ACTOR_OBJ_BANK_140,
    ACTOR_OBJ_BANK_141,
    ACTOR_OBJ_BANK_142,
    ACTOR_OBJ_BANK_143,
    ACTOR_OBJ_BANK_144,
    ACTOR_OBJ_BANK_145,
    ACTOR_OBJ_BANK_146,
    ACTOR_OBJ_BANK_147,
    ACTOR_OBJ_BANK_148,
    ACTOR_OBJ_BANK_149,
    ACTOR_OBJ_BANK_150,
    ACTOR_OBJ_BANK_151,
    ACTOR_OBJ_BANK_152,
    ACTOR_OBJ_BANK_153,
    ACTOR_OBJ_BANK_154,
    ACTOR_OBJ_BANK_155,
    ACTOR_OBJ_BANK_156,
    ACTOR_OBJ_BANK_157,
    ACTOR_OBJ_BANK_158,
    ACTOR_OBJ_BANK_159,
    ACTOR_OBJ_BANK_160,
    ACTOR_OBJ_BANK_161,
    ACTOR_OBJ_BANK_162,
    ACTOR_OBJ_BANK_163,
    ACTOR_OBJ_BANK_164,
    ACTOR_OBJ_BANK_165,
    ACTOR_OBJ_BANK_166,
    ACTOR_OBJ_BANK_167,
    ACTOR_OBJ_BANK_168,
    ACTOR_OBJ_BANK_169,
    ACTOR_OBJ_BANK_170,
    ACTOR_OBJ_BANK_171,
    ACTOR_OBJ_BANK_172,
    ACTOR_OBJ_BANK_173,
    ACTOR_OBJ_BANK_174,
    ACTOR_OBJ_BANK_175,
    ACTOR_OBJ_BANK_176,
    ACTOR_OBJ_BANK_177,
    ACTOR_OBJ_BANK_178,
    ACTOR_OBJ_BANK_179,
    ACTOR_OBJ_BANK_180,
    ACTOR_OBJ_BANK_181,
    ACTOR_OBJ_BANK_182,
    ACTOR_OBJ_BANK_183,
    ACTOR_OBJ_BANK_184,
    ACTOR_OBJ_BANK_185,
    ACTOR_OBJ_BANK_186,
    ACTOR_OBJ_BANK_187,
    ACTOR_OBJ_BANK_188,
    ACTOR_OBJ_BANK_189,
    ACTOR_OBJ_BANK_190,
    ACTOR_OBJ_BANK_191,
    ACTOR_OBJ_BANK_192,
    ACTOR_OBJ_BANK_193,
    ACTOR_OBJ_BANK_194,
    ACTOR_OBJ_BANK_195,
    ACTOR_OBJ_BANK_196,
    ACTOR_OBJ_BANK_197,
    ACTOR_OBJ_BANK_198,
    ACTOR_OBJ_BANK_199,
    ACTOR_OBJ_BANK_200,
    ACTOR_OBJ_BANK_201,
    ACTOR_OBJ_BANK_202,
    ACTOR_OBJ_BANK_203,
    ACTOR_OBJ_BANK_204,
    ACTOR_OBJ_BANK_205,
    ACTOR_OBJ_BANK_206,
    ACTOR_OBJ_BANK_207,
    ACTOR_OBJ_BANK_208,
    ACTOR_OBJ_BANK_209,
    ACTOR_OBJ_BANK_210,
    ACTOR_OBJ_BANK_211,
    ACTOR_OBJ_BANK_212,
    ACTOR_OBJ_BANK_213,
    ACTOR_OBJ_BANK_214,
    ACTOR_OBJ_BANK_215,
    ACTOR_OBJ_BANK_216,
    ACTOR_OBJ_BANK_217,
    ACTOR_OBJ_BANK_218,
    ACTOR_OBJ_BANK_219,
    ACTOR_OBJ_BANK_220,
    ACTOR_OBJ_BANK_221,
    ACTOR_OBJ_BANK_222,
    ACTOR_OBJ_BANK_223,
    ACTOR_OBJ_BANK_224,
    ACTOR_OBJ_BANK_225,
    ACTOR_OBJ_BANK_226,
    ACTOR_OBJ_BANK_227,
    ACTOR_OBJ_BANK_228,
    ACTOR_OBJ_BANK_229,
    ACTOR_OBJ_BANK_230,
    ACTOR_OBJ_BANK_231,
    ACTOR_OBJ_BANK_232,
    ACTOR_OBJ_BANK_233,
    ACTOR_OBJ_BANK_234,
    ACTOR_OBJ_BANK_235,
    ACTOR_OBJ_BANK_236,
    ACTOR_OBJ_BANK_237,
    ACTOR_OBJ_BANK_238,
    ACTOR_OBJ_BANK_239,
    ACTOR_OBJ_BANK_240,
    ACTOR_OBJ_BANK_241,
    ACTOR_OBJ_BANK_242,
    ACTOR_OBJ_BANK_243,
    ACTOR_OBJ_BANK_244,
    ACTOR_OBJ_BANK_245,
    ACTOR_OBJ_BANK_246,
    ACTOR_OBJ_BANK_247,
    ACTOR_OBJ_BANK_248,
    ACTOR_OBJ_BANK_249,
    ACTOR_OBJ_BANK_250,
    ACTOR_OBJ_BANK_251,
    ACTOR_OBJ_BANK_252,
    ACTOR_OBJ_BANK_253,
    ACTOR_OBJ_BANK_254,
    ACTOR_OBJ_BANK_255,
    ACTOR_OBJ_BANK_256,
    ACTOR_OBJ_BANK_257,
    ACTOR_OBJ_BANK_258,
    ACTOR_OBJ_BANK_259,
    ACTOR_OBJ_BANK_260,
    ACTOR_OBJ_BANK_261,
    ACTOR_OBJ_BANK_262,
    ACTOR_OBJ_BANK_263,
    ACTOR_OBJ_BANK_264,
    ACTOR_OBJ_BANK_265,
    ACTOR_OBJ_BANK_266,
    ACTOR_OBJ_BANK_267,
    ACTOR_OBJ_BANK_268,
    ACTOR_OBJ_BANK_269,
    ACTOR_OBJ_BANK_270,
    ACTOR_OBJ_BANK_271,
    ACTOR_OBJ_BANK_272,
    ACTOR_OBJ_BANK_273,
    ACTOR_OBJ_BANK_274,
    ACTOR_OBJ_BANK_275,
    ACTOR_OBJ_BANK_276,
    ACTOR_OBJ_BANK_277,
    ACTOR_OBJ_BANK_278,
    ACTOR_OBJ_BANK_279,
    ACTOR_OBJ_BANK_280,
    ACTOR_OBJ_BANK_281,
    ACTOR_OBJ_BANK_282,
    ACTOR_OBJ_BANK_283,
    ACTOR_OBJ_BANK_284,
    ACTOR_OBJ_BANK_285,
    ACTOR_OBJ_BANK_286,
    ACTOR_OBJ_BANK_287,
    ACTOR_OBJ_BANK_288,
    ACTOR_OBJ_BANK_289,
    ACTOR_OBJ_BANK_290,
    ACTOR_OBJ_BANK_291,
    ACTOR_OBJ_BANK_292,
    ACTOR_OBJ_BANK_293,
    ACTOR_OBJ_BANK_294,
    ACTOR_OBJ_BANK_295,
    ACTOR_OBJ_BANK_296,
    ACTOR_OBJ_BANK_297,
    ACTOR_OBJ_BANK_298,
    ACTOR_OBJ_BANK_299,
    ACTOR_OBJ_BANK_300,
    ACTOR_OBJ_BANK_301,
    ACTOR_OBJ_BANK_302,
    ACTOR_OBJ_BANK_303,
    ACTOR_OBJ_BANK_304,
    ACTOR_OBJ_BANK_305,
    ACTOR_OBJ_BANK_306,
    ACTOR_OBJ_BANK_307,
    ACTOR_OBJ_BANK_308,
    ACTOR_OBJ_BANK_309,
    ACTOR_OBJ_BANK_310,
    ACTOR_OBJ_BANK_311,
    ACTOR_OBJ_BANK_312,
    ACTOR_OBJ_BANK_313,
    ACTOR_OBJ_BANK_314,
    ACTOR_OBJ_BANK_315,
    ACTOR_OBJ_BANK_316,
    ACTOR_OBJ_BANK_317,
    ACTOR_OBJ_BANK_318,
    ACTOR_OBJ_BANK_319,
    ACTOR_OBJ_BANK_320,
    ACTOR_OBJ_BANK_321,
    ACTOR_OBJ_BANK_322,
    ACTOR_OBJ_BANK_323,
    ACTOR_OBJ_BANK_324,
    ACTOR_OBJ_BANK_325,
    ACTOR_OBJ_BANK_326,
    ACTOR_OBJ_BANK_327,
    ACTOR_OBJ_BANK_328,
    ACTOR_OBJ_BANK_329,
    ACTOR_OBJ_BANK_330,
    ACTOR_OBJ_BANK_331,
    ACTOR_OBJ_BANK_332,
    ACTOR_OBJ_BANK_333,
    ACTOR_OBJ_BANK_334,
    ACTOR_OBJ_BANK_335,
    ACTOR_OBJ_BANK_336,
    ACTOR_OBJ_BANK_337,
    ACTOR_OBJ_BANK_338,
    ACTOR_OBJ_BANK_339,
    ACTOR_OBJ_BANK_340,
    ACTOR_OBJ_BANK_341,
    ACTOR_OBJ_BANK_342,
    ACTOR_OBJ_BANK_343,
    ACTOR_OBJ_BANK_344,
    ACTOR_OBJ_BANK_345,
    ACTOR_OBJ_BANK_346,
    ACTOR_OBJ_BANK_347,
    ACTOR_OBJ_BANK_348,
    ACTOR_OBJ_BANK_349,
    ACTOR_OBJ_BANK_350,
    ACTOR_OBJ_BANK_351,
    ACTOR_OBJ_BANK_352,
    ACTOR_OBJ_BANK_353,
    ACTOR_OBJ_BANK_354,
    ACTOR_OBJ_BANK_355,
    ACTOR_OBJ_BANK_356,
    ACTOR_OBJ_BANK_357,
    ACTOR_OBJ_BANK_358,
    ACTOR_OBJ_BANK_359,
    ACTOR_OBJ_BANK_360,
    ACTOR_OBJ_BANK_361,
    ACTOR_OBJ_BANK_362,
    ACTOR_OBJ_BANK_363,
    ACTOR_OBJ_BANK_364,
    ACTOR_OBJ_BANK_365,
    ACTOR_OBJ_BANK_366,
    ACTOR_OBJ_BANK_367,
    ACTOR_OBJ_BANK_368,
    ACTOR_OBJ_BANK_369,
    ACTOR_OBJ_BANK_NPC_SAO,
    ACTOR_OBJ_BANK_TUMBLER,
    ACTOR_OBJ_BANK_372,
    ACTOR_OBJ_BANK_373,
    ACTOR_OBJ_BANK_374,
    ACTOR_OBJ_BANK_375,
    ACTOR_OBJ_BANK_376,
    ACTOR_OBJ_BANK_377,
    ACTOR_OBJ_BANK_378,
    ACTOR_OBJ_BANK_379,
    ACTOR_OBJ_BANK_380,
    ACTOR_OBJ_BANK_381,
    ACTOR_OBJ_BANK_382,
    ACTOR_OBJ_BANK_383,
    ACTOR_OBJ_BANK_384,
    ACTOR_OBJ_BANK_385,
    ACTOR_OBJ_BANK_386,
    ACTOR_OBJ_BANK_387,
    ACTOR_OBJ_BANK_388,
    ACTOR_OBJ_BANK_389,
    ACTOR_OBJ_BANK_390,
    ACTOR_OBJ_BANK_TAMA,
    ACTOR_OBJ_BANK_392,
    ACTOR_OBJ_BANK_393,
    ACTOR_OBJ_BANK_ROPE,
    ACTOR_OBJ_BANK_CRACKER,
    ACTOR_OBJ_BANK_396,
    ACTOR_OBJ_BANK_397,
    ACTOR_OBJ_BANK_398,
    ACTOR_OBJ_BANK_399,
    ACTOR_OBJ_BANK_FUUSEN,
    ACTOR_OBJ_BANK_401,
    ACTOR_OBJ_BANK_402,
    ACTOR_OBJ_BANK_403,
    ACTOR_OBJ_BANK_404,
    ACTOR_OBJ_BANK_MUSEUM_PICTURE,
    ACTOR_OBJ_BANK_406,
    ACTOR_OBJ_BANK_407,
    ACTOR_OBJ_BANK_408,
    ACTOR_OBJ_BANK_EF_MUSEUM,
    ACTOR_OBJ_BANK_EF_MINSECT,
    ACTOR_OBJ_BANK_AC_SIGN,
    ACTOR_OBJ_BANK_MURAL,
    ACTOR_OBJ_BANK_413,
    ACTOR_OBJ_BANK_414,
    ACTOR_OBJ_BANK_415,
    ACTOR_OBJ_BANK_416,
    ACTOR_OBJ_BANK_417,
    ACTOR_OBJ_BANK_418,
    ACTOR_OBJ_BANK_419,
    ACTOR_OBJ_BANK_420,
    ACTOR_OBJ_BANK_421,
    ACTOR_OBJ_BANK_422,
    ACTOR_OBJ_BANK_423,
    ACTOR_OBJ_BANK_424,
    ACTOR_OBJ_BANK_425,
    ACTOR_OBJ_BANK_426,
    ACTOR_OBJ_BANK_427,
    ACTOR_OBJ_BANK_428,
    ACTOR_OBJ_BANK_429,
    ACTOR_OBJ_BANK_430,
    ACTOR_OBJ_BANK_431,
    ACTOR_OBJ_BANK_432,
    ACTOR_OBJ_BANK_433,
    ACTOR_OBJ_BANK_434,
    ACTOR_OBJ_BANK_435,
    ACTOR_OBJ_BANK_436,
    ACTOR_OBJ_BANK_437,
    ACTOR_OBJ_BANK_438,
    ACTOR_OBJ_BANK_439,
    ACTOR_OBJ_BANK_440,
    ACTOR_OBJ_BANK_441,
    ACTOR_OBJ_BANK_442,
    ACTOR_OBJ_BANK_443,
    ACTOR_OBJ_BANK_444,
    ACTOR_OBJ_BANK_445,
    ACTOR_OBJ_BANK_446,
    ACTOR_OBJ_BANK_447,
    ACTOR_OBJ_BANK_448,
    ACTOR_OBJ_BANK_449,
    ACTOR_OBJ_BANK_450,
    ACTOR_OBJ_BANK_451,
    ACTOR_OBJ_BANK_452,
    ACTOR_OBJ_BANK_453,
    ACTOR_OBJ_BANK_454,
    ACTOR_OBJ_BANK_455,
    ACTOR_OBJ_BANK_456,
    ACTOR_OBJ_BANK_457,
    ACTOR_OBJ_BANK_458,
    ACTOR_OBJ_BANK_459,
    ACTOR_OBJ_BANK_460,
    ACTOR_OBJ_BANK_461,
    ACTOR_OBJ_BANK_462,
    ACTOR_OBJ_BANK_463,
    ACTOR_OBJ_BANK_464,
    ACTOR_OBJ_BANK_465,
    ACTOR_OBJ_BANK_466,
    ACTOR_OBJ_BANK_467,
    ACTOR_OBJ_BANK_468,
    ACTOR_OBJ_BANK_469,
    ACTOR_OBJ_BANK_470,
    ACTOR_OBJ_BANK_471,
    ACTOR_OBJ_BANK_472,
    ACTOR_OBJ_BANK_473,
    ACTOR_OBJ_BANK_474,
    ACTOR_OBJ_BANK_475,
    ACTOR_OBJ_BANK_476,
    ACTOR_OBJ_BANK_477,
    ACTOR_OBJ_BANK_478,
    ACTOR_OBJ_BANK_479,
    ACTOR_OBJ_BANK_480,
    ACTOR_OBJ_BANK_481,
    ACTOR_OBJ_BANK_482,
    ACTOR_OBJ_BANK_483,
    ACTOR_OBJ_BANK_484,
    ACTOR_OBJ_BANK_485,
    ACTOR_OBJ_BANK_486,
    ACTOR_OBJ_BANK_487,
    ACTOR_OBJ_BANK_488,
    ACTOR_OBJ_BANK_489,
    ACTOR_OBJ_BANK_490,
    ACTOR_OBJ_BANK_491,
    ACTOR_OBJ_BANK_492,
    ACTOR_OBJ_BANK_493,
    ACTOR_OBJ_BANK_494,
    ACTOR_OBJ_BANK_495,
    ACTOR_OBJ_BANK_496,
    ACTOR_OBJ_BANK_497,
    ACTOR_OBJ_BANK_498,
    ACTOR_OBJ_BANK_499,
    ACTOR_OBJ_BANK_500,
    ACTOR_OBJ_BANK_501,
    ACTOR_OBJ_BANK_502,
    ACTOR_OBJ_BANK_503,
    ACTOR_OBJ_BANK_504,
    ACTOR_OBJ_BANK_505,
    ACTOR_OBJ_BANK_506,
    ACTOR_OBJ_BANK_507,
    ACTOR_OBJ_BANK_508,
    ACTOR_OBJ_BANK_509,
    ACTOR_OBJ_BANK_510,
    ACTOR_OBJ_BANK_511,
    ACTOR_OBJ_BANK_512,
    ACTOR_OBJ_BANK_513,
    ACTOR_OBJ_BANK_514,
    ACTOR_OBJ_BANK_515,
    ACTOR_OBJ_BANK_516,
    ACTOR_OBJ_BANK_517,
    ACTOR_OBJ_BANK_518,
    ACTOR_OBJ_BANK_519,
    ACTOR_OBJ_BANK_520,
    ACTOR_OBJ_BANK_521,
    ACTOR_OBJ_BANK_522,
    ACTOR_OBJ_BANK_523,
    ACTOR_OBJ_BANK_524,
    ACTOR_OBJ_BANK_525,
    ACTOR_OBJ_BANK_526,
    ACTOR_OBJ_BANK_527,
    ACTOR_OBJ_BANK_528,
    ACTOR_OBJ_BANK_529,
    ACTOR_OBJ_BANK_530,
    ACTOR_OBJ_BANK_531,
    ACTOR_OBJ_BANK_532,
    ACTOR_OBJ_BANK_533,
    ACTOR_OBJ_BANK_534,
    ACTOR_OBJ_BANK_535,
    ACTOR_OBJ_BANK_536,
    ACTOR_OBJ_BANK_537,
    ACTOR_OBJ_BANK_538,
    ACTOR_OBJ_BANK_539,
    ACTOR_OBJ_BANK_540,
    ACTOR_OBJ_BANK_541,
    ACTOR_OBJ_BANK_542,
    ACTOR_OBJ_BANK_543,
    ACTOR_OBJ_BANK_544,
    ACTOR_OBJ_BANK_545,
    ACTOR_OBJ_BANK_546,
    ACTOR_OBJ_BANK_547,
    ACTOR_OBJ_BANK_548,
    ACTOR_OBJ_BANK_549,
    ACTOR_OBJ_BANK_550,
    ACTOR_OBJ_BANK_551,
    ACTOR_OBJ_BANK_552,
    ACTOR_OBJ_BANK_553,
    ACTOR_OBJ_BANK_554,
    ACTOR_OBJ_BANK_555,
    ACTOR_OBJ_BANK_556,
    ACTOR_OBJ_BANK_557,
    ACTOR_OBJ_BANK_558,
    ACTOR_OBJ_BANK_559,
    ACTOR_OBJ_BANK_560,
    ACTOR_OBJ_BANK_561,
    ACTOR_OBJ_BANK_562,
    ACTOR_OBJ_BANK_563,
    ACTOR_OBJ_BANK_564,
    ACTOR_OBJ_BANK_565,
    ACTOR_OBJ_BANK_566,
    ACTOR_OBJ_BANK_567,
    ACTOR_OBJ_BANK_568,
    ACTOR_OBJ_BANK_569,
    ACTOR_OBJ_BANK_570,
    ACTOR_OBJ_BANK_571,
    ACTOR_OBJ_BANK_572,
    ACTOR_OBJ_BANK_573,
    ACTOR_OBJ_BANK_574,
    ACTOR_OBJ_BANK_575,
    ACTOR_OBJ_BANK_576,
    ACTOR_OBJ_BANK_577,
    ACTOR_OBJ_BANK_578,
    ACTOR_OBJ_BANK_579,
    ACTOR_OBJ_BANK_580,
    ACTOR_OBJ_BANK_581,
    ACTOR_OBJ_BANK_582,
    ACTOR_OBJ_BANK_583,
    ACTOR_OBJ_BANK_584,
    ACTOR_OBJ_BANK_585,
    ACTOR_OBJ_BANK_586,
    ACTOR_OBJ_BANK_587,
    ACTOR_OBJ_BANK_588,
    ACTOR_OBJ_BANK_589,
    ACTOR_OBJ_BANK_590,
    ACTOR_OBJ_BANK_591,
    ACTOR_OBJ_BANK_592,
    ACTOR_OBJ_BANK_593,
    ACTOR_OBJ_BANK_594,
    ACTOR_OBJ_BANK_595,
    ACTOR_OBJ_BANK_596,
    ACTOR_OBJ_BANK_597,
    ACTOR_OBJ_BANK_598,
    ACTOR_OBJ_BANK_599,
    ACTOR_OBJ_BANK_600,
    ACTOR_OBJ_BANK_601,
    ACTOR_OBJ_BANK_602,
    ACTOR_OBJ_BANK_603,
    ACTOR_OBJ_BANK_604,
    ACTOR_OBJ_BANK_605,
    ACTOR_OBJ_BANK_606,
    ACTOR_OBJ_BANK_607,
    ACTOR_OBJ_BANK_608,
    ACTOR_OBJ_BANK_609,
    ACTOR_OBJ_BANK_610,
    ACTOR_OBJ_BANK_611,
    ACTOR_OBJ_BANK_612,
    ACTOR_OBJ_BANK_613,
    ACTOR_OBJ_BANK_614,
    ACTOR_OBJ_BANK_615,
    ACTOR_OBJ_BANK_616,
    ACTOR_OBJ_BANK_617,
    ACTOR_OBJ_BANK_618,
    ACTOR_OBJ_BANK_619,
    ACTOR_OBJ_BANK_620,
    ACTOR_OBJ_BANK_621,
    ACTOR_OBJ_BANK_622,
    ACTOR_OBJ_BANK_623,
    ACTOR_OBJ_BANK_624,
    ACTOR_OBJ_BANK_625,
    ACTOR_OBJ_BANK_626,
    ACTOR_OBJ_BANK_627,
    ACTOR_OBJ_BANK_628,
    ACTOR_OBJ_BANK_629,
    ACTOR_OBJ_BANK_630,
    ACTOR_OBJ_BANK_631,
    ACTOR_OBJ_BANK_632,
    ACTOR_OBJ_BANK_633,
    ACTOR_OBJ_BANK_634,
    ACTOR_OBJ_BANK_635,
    ACTOR_OBJ_BANK_636,
    ACTOR_OBJ_BANK_637,
    ACTOR_OBJ_BANK_638,
    ACTOR_OBJ_BANK_639,
    ACTOR_OBJ_BANK_640,
    ACTOR_OBJ_BANK_641,
    ACTOR_OBJ_BANK_642,
    ACTOR_OBJ_BANK_643,
    ACTOR_OBJ_BANK_644,
    ACTOR_OBJ_BANK_645,
    ACTOR_OBJ_BANK_646,
    ACTOR_OBJ_BANK_647,
    ACTOR_OBJ_BANK_648,
    ACTOR_OBJ_BANK_649,
    ACTOR_OBJ_BANK_650,
    ACTOR_OBJ_BANK_651,
    ACTOR_OBJ_BANK_652,
    ACTOR_OBJ_BANK_653,
    ACTOR_OBJ_BANK_654,
    ACTOR_OBJ_BANK_655,
    ACTOR_OBJ_BANK_656,
    ACTOR_OBJ_BANK_657,
    ACTOR_OBJ_BANK_658,
    ACTOR_OBJ_BANK_659,
    ACTOR_OBJ_BANK_660,
    ACTOR_OBJ_BANK_661,
    ACTOR_OBJ_BANK_662,
    ACTOR_OBJ_BANK_663,
    ACTOR_OBJ_BANK_664,
    ACTOR_OBJ_BANK_665,
    ACTOR_OBJ_BANK_666,
    ACTOR_OBJ_BANK_667,
    ACTOR_OBJ_BANK_668,
    ACTOR_OBJ_BANK_669,
    ACTOR_OBJ_BANK_670,
    ACTOR_OBJ_BANK_671,
    ACTOR_OBJ_BANK_672,
    ACTOR_OBJ_BANK_673,
    ACTOR_OBJ_BANK_674,
    ACTOR_OBJ_BANK_675,
    ACTOR_OBJ_BANK_676,
    ACTOR_OBJ_BANK_677,
    ACTOR_OBJ_BANK_678,
    ACTOR_OBJ_BANK_679,
    ACTOR_OBJ_BANK_680,
    ACTOR_OBJ_BANK_681,
    ACTOR_OBJ_BANK_682,
    ACTOR_OBJ_BANK_683,
    ACTOR_OBJ_BANK_684,
    ACTOR_OBJ_BANK_685,
    ACTOR_OBJ_BANK_686,
    ACTOR_OBJ_BANK_687,
    ACTOR_OBJ_BANK_688,
    ACTOR_OBJ_BANK_689,
    ACTOR_OBJ_BANK_690,
    ACTOR_OBJ_BANK_691,
    ACTOR_OBJ_BANK_692,
    ACTOR_OBJ_BANK_693,
    ACTOR_OBJ_BANK_694,
    ACTOR_OBJ_BANK_695,
    ACTOR_OBJ_BANK_696,
    ACTOR_OBJ_BANK_697,
    ACTOR_OBJ_BANK_698,
    ACTOR_OBJ_BANK_699,
    ACTOR_OBJ_BANK_700,
    ACTOR_OBJ_BANK_701,
    ACTOR_OBJ_BANK_702,
    ACTOR_OBJ_BANK_703,
    ACTOR_OBJ_BANK_704,
    ACTOR_OBJ_BANK_705,
    ACTOR_OBJ_BANK_706,
    ACTOR_OBJ_BANK_707,
    ACTOR_OBJ_BANK_708,
    ACTOR_OBJ_BANK_709,
    ACTOR_OBJ_BANK_710,
    ACTOR_OBJ_BANK_711,
    ACTOR_OBJ_BANK_712,
    ACTOR_OBJ_BANK_713,
    ACTOR_OBJ_BANK_714,
    ACTOR_OBJ_BANK_715,
    ACTOR_OBJ_BANK_716,
    ACTOR_OBJ_BANK_717,
    ACTOR_OBJ_BANK_718,
    ACTOR_OBJ_BANK_719,
    ACTOR_OBJ_BANK_720,
    ACTOR_OBJ_BANK_721,
    ACTOR_OBJ_BANK_722,
    ACTOR_OBJ_BANK_723,
    ACTOR_OBJ_BANK_724,
    ACTOR_OBJ_BANK_725,
    ACTOR_OBJ_BANK_726,
    ACTOR_OBJ_BANK_727,
    ACTOR_OBJ_BANK_728,
    ACTOR_OBJ_BANK_729,
    ACTOR_OBJ_BANK_730,
    ACTOR_OBJ_BANK_731,
};

enum actor_part {
    ACTOR_PART_FG,
    ACTOR_PART_ITEM,
    ACTOR_PART_UNUSED,
    ACTOR_PART_PLAYER,
    ACTOR_PART_NPC,
    ACTOR_PART_BG,
    ACTOR_PART_EFFECT,
    ACTOR_PART_CONTROL,

    ACTOR_PART_NUM
};

enum actor_profile_table {
    mAc_PROFILE_PLAYER,
    mAc_PROFILE_BGITEM,
    mAc_PROFILE_SAMPLE,
    mAc_PROFILE_FIELDM_DRAW,
    mAc_PROFILE_FIELD_DRAW,
    mAc_PROFILE_AIRPLANE,
    mAc_PROFILE_ROOM_SUNSHINE,
    mAc_PROFILE_LAMP_LIGHT,
    mAc_PROFILE_EV_ANGLER,
    mAc_PROFILE_BALL,
    mAc_PROFILE_HANIWA,
    mAc_PROFILE_MY_ROOM,
    mAc_PROFILE_MBG,
    mAc_PROFILE_T_TAMA,
    mAc_PROFILE_BOXMANAGER,
    mAc_PROFILE_BOXMOVE,
    mAc_PROFILE_BOXTRICK01,
    mAc_PROFILE_ARRANGE_ROOM,
    mAc_PROFILE_ARRANGE_FURNITURE,
    mAc_PROFILE_TRAINDOOR,
    mAc_PROFILE_T_KEITAI,
    mAc_PROFILE_HALLOWEEN_NPC,
    mAc_PROFILE_EV_PUMPKIN,
    mAc_PROFILE_RIDE_OFF_DEMO,
    mAc_PROFILE_NPC_MAMEDANUKI,
    mAc_PROFILE_HANABI_NPC0,
    mAc_PROFILE_HANABI_NPC1,
    mAc_PROFILE_SNOWMAN,
    mAc_PROFILE_NPC_POST_GIRL,
    mAc_PROFILE_NPC_ENGINEER,
    mAc_PROFILE_NPC_MAJIN3,
    mAc_PROFILE_NPC_SLEEP_OBABA,
    mAc_PROFILE_NPC,
    mAc_PROFILE_EFFECT_CONTROL,
    mAc_PROFILE_NPC2,
    mAc_PROFILE_KAMAKURA_NPC0,
    mAc_PROFILE_NPC_POST_MAN,
    mAc_PROFILE_SHOP_DESIGN,
    mAc_PROFILE_QUEST_MANAGER,
    mAc_PROFILE_MAILBOX,
    mAc_PROFILE_HOUSE,
    mAc_PROFILE_SHOP_LEVEL,
    mAc_PROFILE_SHOP,
    mAc_PROFILE_MYHOUSE,
    mAc_PROFILE_EV_ARTIST,
    mAc_PROFILE_EV_BROKER,
    mAc_PROFILE_EV_DESIGNER,
    mAc_PROFILE_T_UMBRELLA,
    mAc_PROFILE_NPC_SHOP_MASTER,
    mAc_PROFILE_BIRTH_CONTROL,
    mAc_PROFILE_SHOP_MANEKIN,
    mAc_PROFILE_SHOP_INDOOR,
    mAc_PROFILE_EVENT_MANAGER,
    mAc_PROFILE_SHOP_GOODS,
    mAc_PROFILE_BRSHOP,
    mAc_PROFILE_WEATHER,
    mAc_PROFILE_POST_OFFICE,
    mAc_PROFILE_NPC_GUIDE,
    mAc_PROFILE_NPC_GUIDE2,
    mAc_PROFILE_INSECT,
    mAc_PROFILE_STATION,
    mAc_PROFILE_EV_CARPETPEDDLER,
    mAc_PROFILE_EV_KABUPEDDLER,
    mAc_PROFILE_RESERVE,
    mAc_PROFILE_HANDOVERITEM,
    mAc_PROFILE_NPC_CONV_MASTER,
    mAc_PROFILE_NPC_SUPER_MASTER,
    mAc_PROFILE_NPC_DEPART_MASTER,
    mAc_PROFILE_TOOLS,
    mAc_PROFILE_STRUCTURE,
    mAc_PROFILE_EV_GYPSY,
    mAc_PROFILE_NPC_POLICE,
    mAc_PROFILE_TRAIN0,
    mAc_PROFILE_TRAIN1,
    mAc_PROFILE_NPC_STATION_MASTER,
    mAc_PROFILE_EV_SANTA,
    mAc_PROFILE_NPC_POLICE2,
    mAc_PROFILE_POLICE_BOX,
    mAc_PROFILE_BGPOLICEITEM,
    mAc_PROFILE_BGCHERRYITEM,
    mAc_PROFILE_BGWINTERITEM,
    mAc_PROFILE_BGXMASITEM,
    mAc_PROFILE_BGPOSTITEM,
    mAc_PROFILE_FALLS,
    mAc_PROFILE_FALLSESW,
    mAc_PROFILE_EV_BROKER2,
    mAc_PROFILE_BROKER_DESIGN,
    mAc_PROFILE_T_UTIWA,
    mAc_PROFILE_PSNOWMAN,
    mAc_PROFILE_MY_INDOOR,
    mAc_PROFILE_NPC_RCN_GUIDE,
    mAc_PROFILE_INTRO_DEMO,
    mAc_PROFILE_SHRINE,
    mAc_PROFILE_BUGGY,
    mAc_PROFILE_T_HANABI,
    mAc_PROFILE_CONVENI,
    mAc_PROFILE_SUPER,
    mAc_PROFILE_DEPART,
    mAc_PROFILE_HANAMI_NPC0,
    mAc_PROFILE_S_CAR,
    mAc_PROFILE_HANAMI_NPC1,
    mAc_PROFILE_NPC_P_SEL,
    mAc_PROFILE_NPC_P_SEL2,
    mAc_PROFILE_NPC_RCN_GUIDE2,
    mAc_PROFILE_TRAIN_WINDOW,
    mAc_PROFILE_NPC_MAJIN4,
    mAc_PROFILE_KAMAKURA,
    mAc_PROFILE_GYOEI,
    mAc_PROFILE_NPC_MAJIN,
    mAc_PROFILE_T_NPCSAO,
    mAc_PROFILE_EV_SONCHO,
    mAc_PROFILE_UKI,
    mAc_PROFILE_NPC_MAJIN2,
    mAc_PROFILE_NORMAL_NPC,
    mAc_PROFILE_SET_MANAGER,
    mAc_PROFILE_SET_NPC_MANAGER,
    mAc_PROFILE_NPC_SHOP_MASTERSP,
    mAc_PROFILE_ROOM_SUNSHINE_POSTHOUSE,
    mAc_PROFILE_ROOM_SUNSHINE_POLICE,
    mAc_PROFILE_EFFECTBG,
    mAc_PROFILE_EV_CHERRY_MANAGER,
    mAc_PROFILE_EV_YOMISE,
    mAc_PROFILE_TOKYOSO_NPC0,
    mAc_PROFILE_TOKYOSO_NPC1,
    mAc_PROFILE_GOZA,
    mAc_PROFILE_RADIO,
    mAc_PROFILE_YATAI,
    mAc_PROFILE_TOKYOSO_CONTROL,
    mAc_PROFILE_SHOP_UMBRELLA,
    mAc_PROFILE_GYO_RELEASE,
    mAc_PROFILE_TUKIMI,
    mAc_PROFILE_KAMAKURA_INDOOR,
    mAc_PROFILE_EV_MIKO,
    mAc_PROFILE_GYO_KAGE,
    mAc_PROFILE_MIKUJI,
    mAc_PROFILE_HOUSE_GOKI,
    mAc_PROFILE_T_CRACKER,
    mAc_PROFILE_NPC_NEEDLEWORK,
    mAc_PROFILE_T_PISTOL,
    mAc_PROFILE_T_FLAG,
    mAc_PROFILE_T_TUMBLER,
    mAc_PROFILE_TUKIMI_NPC0,
    mAc_PROFILE_TUKIMI_NPC1,
    mAc_PROFILE_NEEDLEWORK_SHOP,
    mAc_PROFILE_COUNTDOWN_NPC0,
    mAc_PROFILE_COUNTDOWN_NPC1,
    mAc_PROFILE_TURI_NPC0,
    mAc_PROFILE_TAISOU_NPC0,
    mAc_PROFILE_COUNT,
    mAc_PROFILE_GARAGARA,
    mAc_PROFILE_TAMAIRE_NPC0,
    mAc_PROFILE_TAMAIRE_NPC1,
    mAc_PROFILE_HATUMODE_NPC0,
    mAc_PROFILE_NPC_TOTAKEKE,
    mAc_PROFILE_COUNT02,
    mAc_PROFILE_HATUMODE_CONTROL,
    mAc_PROFILE_TAMA,
    mAc_PROFILE_KAGO,
    mAc_PROFILE_TURI,
    mAc_PROFILE_HOUSE_CLOCK,
    mAc_PROFILE_TUNAHIKI_CONTROL,
    mAc_PROFILE_TUNAHIKI_NPC0,
    mAc_PROFILE_TUNAHIKI_NPC1,
    mAc_PROFILE_KOINOBORI,
    mAc_PROFILE_BEE,
    mAc_PROFILE_NAMEPLATE,
    mAc_PROFILE_DUMP,
    mAc_PROFILE_ROPE,
    mAc_PROFILE_EV_DOZAEMON,
    mAc_PROFILE_WINDMILL,
    mAc_PROFILE_LOTUS,
    mAc_PROFILE_ANIMAL_LOGO,
    mAc_PROFILE_MIKANBOX,
    mAc_PROFILE_DOUZOU,
    mAc_PROFILE_NPC_RTC,
    mAc_PROFILE_TOUDAI,
    mAc_PROFILE_NPC_RESTART,
    mAc_PROFILE_NPC_MAJIN5,
    mAc_PROFILE_FUUSEN,
    mAc_PROFILE_EV_DOKUTU,
    mAc_PROFILE_DUMMY,
    mAc_PROFILE_NPC_CURATOR,
    mAc_PROFILE_MUSEUM,
    mAc_PROFILE_EV_GHOST,
    mAc_PROFILE_MUSEUM_PICTURE,
    mAc_PROFILE_185,
    mAc_PROFILE_MUSEUM_FISH,
    mAc_PROFILE_MUSEUM_INSECT,
    mAc_PROFILE_BRIDGE_A,
    mAc_PROFILE_ROOM_SUNSHINE_MUSEUM,
    mAc_PROFILE_NEEDLEWORK_INDOOR,
    mAc_PROFILE_ROOM_SUNSHINE_MINSECT,
    mAc_PROFILE_MUSEUM_FOSSIL,
    mAc_PROFILE_MURAL,
    mAc_PROFILE_AC_SIGN,
    mAc_PROFILE_ANT,
    mAc_PROFILE_NPC_SENDO,
    mAc_PROFILE_FLAG,
    mAc_PROFILE_PRESENT_DEMO,
    mAc_PROFILE_PRESENT_NPC,
    mAc_PROFILE_BOAT,
    mAc_PROFILE_BOAT_DEMO,
    mAc_PROFILE_COTTAGE_MY,
    mAc_PROFILE_COTTAGE_NPC,
    mAc_PROFILE_EV_SONCHO2,
    mAc_PROFILE_NPC_MASK_CAT,
    mAc_PROFILE_NPC_MASK_CAT2,
    mAc_PROFILE_RESET_DEMO,
    mAc_PROFILE_GO_HOME_NPC,
    mAc_PROFILE_MISIN,
    mAc_PROFILE_LIGHTHOUSE_SWITCH,
    mAc_PROFILE_MUSEUM_INDOOR,
    mAc_PROFILE_T_ANRIUM1,
    mAc_PROFILE_T_BISCUS1,
    mAc_PROFILE_T_BISCUS2,
    mAc_PROFILE_T_HASU1,
    mAc_PROFILE_T_HAT1,
    mAc_PROFILE_T_ZINNIA1,
    mAc_PROFILE_T_BISCUS3,
    mAc_PROFILE_T_BISCUS4,
    mAc_PROFILE_T_ZINNIA2,
    mAc_PROFILE_T_HAT2,
    mAc_PROFILE_T_HAT3,
    mAc_PROFILE_T_REI1,
    mAc_PROFILE_T_REI2,
    mAc_PROFILE_NPC_SHASHO,
    mAc_PROFILE_T_BAG1,
    mAc_PROFILE_T_BAG2,
    mAc_PROFILE_EV_CASTAWAY,
    mAc_PROFILE_T_COBRA1,
    mAc_PROFILE_BALLOON,
    mAc_PROFILE_NPC_SONCHO,
    mAc_PROFILE_APRILFOOL_CONTROL,
    mAc_PROFILE_EV_MAJIN,
    mAc_PROFILE_HARVEST_NPC0,
    mAc_PROFILE_HARVEST_NPC1,
    mAc_PROFILE_GROUNDHOG_CONTROL,
    mAc_PROFILE_EV_SPEECH_SONCHO,
    mAc_PROFILE_GROUNDHOG_NPC0,
    mAc_PROFILE_EV_TURKEY,
    mAc_PROFILE_GHOG,
    mAc_PROFILE_HTABLE,
    mAc_PROFILE_NPC_HEM,
    mAc_PROFILE_TENT,
    mAc_PROFILE_PTERMINAL,
    mAc_PROFILE_MSCORE_CONTROL,

    mAc_PROFILE_NUM
};

enum {
    mAc_HILITE_OPAQUE,
    mAc_HILITE_TRANSLUCENT,

    mAc_HILITE_NUM
};

/* sizeof(ACTOR_PROFILE) == 0x24 */
struct actor_profile_s {
    /* 0x00 */ s16 id;                  /* unique actor type ID */
    /* 0x02 */ u8 part;                 /* actor type, seemingly called 'part' */
    /* 0x04 */ u32 initial_flags_state; /* initial actor flag state */
    /* 0x08 */ mActor_name_t npc_id;    /* "world" npc id/name */
    /* 0x0A */ s16 obj_bank_id;         /* used with object exchange */
    /* 0x0C */ size_t class_size;       /* sizeof(ZZZ_ACTOR) */
    /* 0x10 */ mActor_proc ct_proc;     /* constructor */
    /* 0x14 */ mActor_proc dt_proc;     /* destructor */
    /* 0x18 */ mActor_proc mv_proc;     /* move */
    /* 0x1C */ mActor_proc dw_proc;     /* draw */
    /* 0x20 */ mActor_proc sv_proc;     /* save */
};

typedef void (*mActor_shadow_proc)(ACTOR*, LightsN*, GAME_PLAY*);

/* sizeof(Shape_Info) == 0x48 */
typedef struct actor_shape_info_s {
    /* 0x00 */ s_xyz rotation;
    /* 0x06 */ s16 unk_6;
    /* 0x08 */ f32 ofs_y;
    /* 0x0C */ mActor_shadow_proc shadow_proc;
    /* 0x10 */ f32 shadow_size_x;
    /* 0x14 */ f32 shadow_size_z;
    /* 0x18 */ f32 shadow_size_change_rate;
    /* 0x1C */ f32 shadow_alpha_change_rate;
    /* 0x20 */ int unk_20;
    /* 0x24 */ xyz_t* shadow_position;
    /* 0x28 */ int unk_28;
    /* 0x2C */ u8 draw_shadow; /* TRUE = shadow is drawn, FALSE = shadow is not drawn */
    /* 0x2D */ u8 unk_2D;
    /* 0x2E */ u8
        force_shadow_position; /* TRUE = shadow's position is forcefully updated, FALSE = non-forcefully updated */
    /* 0x2F */ u8 unused_2F[0x48 - 0x2F];
} Shape_Info;

typedef struct actor_shadow_s {
    /* 0x00 */ xyz_t position;
    /* 0x0C */ f32 groundY;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ char pad28[0xC];
    /* 0x34 */ int unk34;
    /* 0x38 */ int kind;
} Shadow_Info;

/* sizeof(struct actor_s) == 0x174 */
struct actor_s {
    /* 0x000 */ s16 id; /* unique actor type ID */
    /* 0x002 */ u8 part;
    /* 0x003 */ u8 restore_fg; /* restores 'fgdata' according to restore_fgdata_all */
    /* 0x004 */ s16 scene_id;
    /* 0x006 */ mActor_name_t npc_id;
    /* 0x008 */ s8 block_x;
    /* 0x009 */ s8 block_z;
    /* 0x00A */ s16 move_actor_list_idx;          /* used in aBC_setupCommonMvActor */
    /* 0x00C */ PositionAngle home;               /* Home position & rotation */
    /* 0x020 */ u32 state_bitfield;               /* bitfield of current actor state */
    /* 0x024 */ s16 actor_specific;               /* actor specific temp data */
    /* 0x026 */ s16 data_bank_id;                 /* data bank id actor is in */
    /* 0x028 */ PositionAngle world;              /* World position & rotation */
    /* 0x03C */ xyz_t last_world_position;        /* previous actor world position */
    /* 0x048 */ PositionAngle eye;                /* actor "eyes" (head/lookat) world position & rotation */
    /* 0x05C */ xyz_t scale;                      /* actor size */
    /* 0x068 */ xyz_t position_speed;             /* actor movement velocity (see Actor_position_speed_set) */
    /* 0x074 */ f32 speed;                        /* movement speed */
    /* 0x078 */ f32 gravity;                      /* gravity acting on actor */
    /* 0x07C */ f32 max_velocity_y;               /* maximum y velocity possible due to gravity, usually -20.0f */
    /* 0x080 */ f32 ground_y;                     /* vertical position of ground underneath actor */
    /* 0x084 */ mCoBG_Check_c bg_collision_check; /* background object collision info with actor */
    /* 0x0B4 */ u8 unknown_b4;                    /* some sort of flag */
    /* 0x0B5 */ u8 drawn;               /* was drawn flag, TRUE = actor was drawn, FALSE = actor was not drawn */
    /* 0x0B6 */ s16 player_angle_y;     /* Y angle (yaw) between actor and player actor */
    /* 0x0B8 */ f32 player_distance;    /* distance between actor and player actor (squared magnitude) */
    /* 0x0BC */ f32 player_distance_xz; /* distance between actor and player actor on XZ plane (magnitude) */
    /* 0x0C0 */ f32 player_distance_y;  /* distance between actor and player actor on Y plane */
    /* 0x0C4 */ Status_c status_data;   /* collider info, lots of leftover stuff from OoT */
    /* 0x0DC */ Shape_Info shape_info;
    /* 0x124 */ xyz_t camera_position; /* camera position relative to actor position */
    /* 0x130 */ f32 camera_w;          /* camera projection W value */
    /* 0x134 */ f32 cull_width;
    /* 0x138 */ f32 cull_height;
    /* 0x13C */ f32 cull_distance;
    /* 0x140 */ f32 cull_radius;
    /* 0x144 */ f32 talk_distance;     /* maximum distance for talking to be triggered, default seems to be 55.0f */
    /* 0x148 */ u8 cull_while_talking; /* flag to disable actor drawing while talking */
    /* 0x149 */ u8 skip_drawing;       /* manual "do not draw" override flag only used by player umbrella actor */
    /* 0x14C */ ACTOR* parent_actor;
    /* 0x150 */ ACTOR* child_actor;
    /* 0x154 */ ACTOR* prev_actor;
    /* 0x158 */ ACTOR* next_actor;
    /* 0x15C */ mActor_proc ct_proc;  /* constructor */
    /* 0x160 */ mActor_proc dt_proc;  /* destructor */
    /* 0x164 */ mActor_proc mv_proc;  /* move */
    /* 0x168 */ mActor_proc dw_proc;  /* draw */
    /* 0x16C */ mActor_proc sv_proc;  /* save */
    /* 0x170 */ ACTOR_DLFTBL* dlftbl; /* display list function table */
};

#define mActor_NONE_PROC1 ((mActor_proc)none_proc1)

typedef struct actor_list_s {
    /* 0x00 */ int num_actors;
    /* 0x04 */ ACTOR* actor;
} Actor_list;

typedef struct actor_info_s {
    /* 0x00 */ int total_num;
    /* 0x04 */ Actor_list list[ACTOR_PART_NUM];
} Actor_info;

typedef struct actor_data_s {
    /* 0x00 */ s16 profile;
    /* 0x02 */ s_xyz position;
    /* 0x08 */ s_xyz rotation;
    /* 0x0E */ s16 arg;
} Actor_data;

extern void Actor_world_to_eye(ACTOR* actor, f32 eye_height);
extern void Actor_position_move(ACTOR* actor);
extern void Actor_position_speed_set(ACTOR* actor);
extern void Actor_position_moveF(ACTOR* actor);
extern int Actor_player_look_direction_check(ACTOR* actor, s16 angle, GAME_PLAY* play);
extern void Shape_Info_init(ACTOR* actor, f32 ofs_y, mActor_shadow_proc shadow_proc, f32 shadow_size_x,
                            f32 shadow_size_z);
extern void Actor_delete(ACTOR* actor);
extern int Actor_draw_actor_no_culling_check(ACTOR* actor);
extern int Actor_draw_actor_no_culling_check2(ACTOR* actor, xyz_t* camera_pos, f32 camera_w);
extern void Actor_info_ct(GAME* game, Actor_info* actor_info, Actor_data* player_data);
extern void Actor_info_dt(Actor_info* actor_info, GAME_PLAY* play);
extern void Actor_info_call_actor(GAME_PLAY* play, Actor_info* actor_info);
extern void Actor_info_draw_actor(GAME_PLAY* play, Actor_info* actor_info);
extern void Actor_free_overlay_area(ACTOR_DLFTBL* dlftbl);
extern void Actor_get_overlay_area(ACTOR_DLFTBL* dlftbl, int unused, size_t alloc_size);
extern void Actor_init_actor_class(ACTOR* actor, ACTOR_PROFILE* profile, ACTOR_DLFTBL* dlftbl, GAME_PLAY* play,
                                   int bank_idx, f32 x, f32 y, f32 z, s16 rot_x, s16 rot_y, s16 rot_z, s8 block_x,
                                   s8 block_z, s16 move_actor_list_idx, mActor_name_t name_id, s16 arg);
extern ACTOR* Actor_info_make_actor(Actor_info* actor_info, GAME* game, s16 profile_no, f32 x, f32 y, f32 z, s16 rot_x,
                                    s16 rot_y, s16 rot_z, s8 block_x, s8 block_z, s16 move_actor_list_idx,
                                    mActor_name_t name_id, s16 arg, s8 npc_info_idx, int data_bank_idx);
extern ACTOR* Actor_info_make_child_actor(Actor_info* actor_info, ACTOR* parent_actor, GAME* game, s16 profile, f32 x,
                                          f32 y, f32 z, s16 rot_x, s16 rot_y, s16 rot_z, s16 move_actor_list_idx,
                                          mActor_name_t name_id, s16 arg, int data_bank_idx);
extern void restore_fgdata_all(GAME_PLAY* play);
extern void Actor_info_save_actor(GAME_PLAY* play);
extern ACTOR* Actor_info_delete(Actor_info* actor_info, ACTOR* actor, GAME* game);
extern ACTOR* Actor_info_name_search_sub(ACTOR* actor, s16 name);
extern ACTOR* Actor_info_name_search(Actor_info* actor_info, s16 name, int part);
extern ACTOR* Actor_info_fgName_search_sub(ACTOR* actor, mActor_name_t fgName);
extern ACTOR* Actor_info_fgName_search(Actor_info* actor_info, mActor_name_t fgName, int part);
extern Gfx* HiliteReflect_new(xyz_t* pos, xyz_t* eye, xyz_t* light_direction, GRAPH* graph, Gfx* gfx, Hilite** hilite);
extern Hilite* HiliteReflect_init(xyz_t* pos, xyz_t* eye, xyz_t* light_direction, GRAPH* graph);
extern Hilite* HiliteReflect_xlu_init(xyz_t* pos, xyz_t* eye, xyz_t* light_direction, GRAPH* graph);
extern void Setpos_HiliteReflect_init(xyz_t* pos, GAME_PLAY* play);
extern void Setpos_HiliteReflect_xlu_init(xyz_t* pos, GAME_PLAY* play);

#ifdef __cplusplus
}
#endif

#endif
