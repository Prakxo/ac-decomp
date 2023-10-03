#ifndef M_CLIP_H
#define M_CLIP_H

#include "types.h"
#include "ac_gyoei_h.h"
#include "ac_insect_h.h"
#include "ac_structure.h"
#include "ac_animal_logo.h"
#include "ef_effect_control.h"
#include "m_demo.h"
#include "bg_item_h.h"
#include "ac_npc.h"
#include "ac_tools.h"
#include "ac_aprilfool_control.h"
#include "ac_groundhog_control.h"
#include "ac_event_manager.h"

#ifdef __cplusplus
extern "C" {
#endif

/* sizeof(Clip_c) == 0x104 */
typedef struct clip_s {
  /* 0x000 */ void* _000[(0x040 - 0x000) / sizeof(void*)];
  /* 0x040 */ aNPC_Clip_c* npc_clip;
  /* 0x044 */ void* _044[(0x074 - 0x044) / sizeof(void*)];
  /* 0x074 */ bIT_Clip_c* bg_item_clip;
  /* 0x078 */ void* _078;
  /* 0x07C */ aINS_Clip_c* insect_clip;
  /* 0x080 */ void* _080[(0x08C - 0x080) / sizeof(void*)];
  /* 0x08C */ aSTR_Clip_c* structure_clip;
  /* 0x090 */ eEC_EffectControl_Clip_c* effect_clip;
  /* 0x094 */ aTOL_Clip_c* tools_clip;
  /* 0x098 */ void* _094[(0x0A0 - 0x098) / sizeof(void*)];
  /* 0x0A0 */ mDemo_Clip_c* demo_clip; /* can be multiple clip classes */
  /* 0x0A4 */ void* demo_clip2; /* can be multiple clip classes */
  /* 0x0A8 */ void* _0A8;
  /* 0x0AC */ aGYO_Clip_c* gyo_clip;
  /* 0x0B0 */ void* _0B0[(0x0DC - 0x0B0) / sizeof(void*)];
  /* 0x0DC */ aAL_Clip_c* animal_logo_clip;
  /* 0x0E0 */ void* _0E0[(0x0EC - 0x0E0) / sizeof(void*)];
  /* 0x0EC */ aAPC_Clip_c* aprilfool_control_clip;
  /* 0x0F0 */ aEvMgr_Clip_c* event_manager_clip;
  /* 0x0F4 */ aGHC_Clip_c* groundhog_control_clip;
  /* 0x0F8 */ void* _0F8;
  /* 0x0FC */ void* _0FC;
  /* 0x100 */ void* _100;
} Clip_c;

extern void clip_clear();

#ifdef __cplusplus
}
#endif

#endif
