#include "zurumode.h"
#include "libultra/libultra.h"
int zerucheck_init(zuru_keycheck* key_check) {
  key_check->zurumode_enabled = FALSE;
  key_check->state = ZURUMODE_STAGE_BEGIN_e;
  key_check->progressing = ZURUMODE_RESET;
  key_check->last_controller = 0;
}
