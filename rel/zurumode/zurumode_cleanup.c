#include "zurumode.h"

typedef struct {
    u8 pad_pattern;
    void (*callback)(void*);
    void* callback_param;
    void (*callback2)(void*);
    void* callback2_param;
} padmgr;

extern padmgr padmgr_class;
extern void zurumode_callback(void*);
extern s32 zurumode_flag;

extern void zurumode_cleanup(void) {
    if ((padmgr_class.callback2 == &zurumode_callback) && (padmgr_class.callback2_param == &padmgr_class)) {
        padmgr_class.callback2 = NULL;
        padmgr_class.callback2_param = NULL;
    }
    zurumode_flag = 0;
}
