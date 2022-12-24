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

extern void zurumode_cleanup(void) { // Hm, this looks like PADMGR_UNSET_RETRACE_CALLBACK macro lol
    if ((padmgr_class.callback2 == &zurumode_callback) && (padmgr_class.callback2_param == &padmgr_class)) {
        padmgr_class.callback2 = NULL;
        padmgr_class.callback2_param = NULL;
    }
    zurumode_flag = 0;
}
