#include "ef_effect_control.h"

static void eBushHappa_init(xyz_t pos, int prio, s16 angle, GAME* game, u16 item_name, s16 arg0, s16 arg1) {
    // TODO
}

static void eBushHappa_ct(eEC_Effect_c* effect, GAME* game, void* ct_arg) {
    // TODO
}

static void eBushHappa_mv(eEC_Effect_c* effect, GAME* game) {
    // TODO
}

static void eBushHappa_dw(eEC_Effect_c* effect, GAME* game) {
    // TODO
}

eEC_PROFILE_c iam_ef_bush_happa = {
    // clang-format off
    &eBushHappa_init,
    &eBushHappa_ct,
    &eBushHappa_mv,
    &eBushHappa_dw,
    eEC_IGNORE_DEATH,
    eEC_NO_CHILD_ID,
    eEC_DEFAULT_DEATH_DIST,
    // clang-format on
};