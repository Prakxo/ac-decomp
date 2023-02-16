#include "zurumode.h"
#include "libultra/libultra.h"
s32 zurumode_update() {
    s32 flag_now;
    s32 zurumode_now;
    
    flag_now = zurumode_flag;
    zurumode_now = osAppNMIBuffer[15];
    
    if (zurumode_now & 1) {
        zurumode_now = (zurumode_now >> 3) & 1;
        zurumode_now = (int)(zurumode_now + 1);
    }    
    else {
        zurumode_now = 0;
    }
    zurumode_flag = zurumode_now;
    
    if (flag_now != zurumode_now) {
        OSReport("zurumode_flag が %d から %d に変更されました\n", flag_now, zurumode_now);
        if (zurumode_flag != 0) {
            if ((osAppNMIBuffer[15] & 0x40) || (osAppNMIBuffer[15] & 1)) {
                JC_JUTAssertion_changeDevice(3);
                JC_JUTDbPrint_setVisible(JC_JUTDbPrint_getManager(), 1);
            }
        } else {
            JC_JUTAssertion_changeDevice(2);
            JC_JUTDbPrint_setVisible(JC_JUTDbPrint_getManager(), 0);
        }
    }
    return zurumode_flag;