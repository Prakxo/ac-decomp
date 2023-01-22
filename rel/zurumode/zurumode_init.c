#include "zurumode.h"

void zurumode_init(void){
    zurumode_flag = 0;
    zerucheck_init(&zuruKeyCheck);
    zuruKeyCheck.zurumode_enabled = osAppNMIBuffer[OS_APP_NMI_ZURUMODE_IDX] & 1;
    padmgr_class.callback2 = zurumode_callback;
    padmgr_class.callback2_param = &padmgr_class;
    zurumode_update();
}