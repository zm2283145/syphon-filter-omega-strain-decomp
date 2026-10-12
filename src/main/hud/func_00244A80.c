#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_003F44E0(float, int);                          
int func_003F45A0(float, int);                          

#pragma opt_common_subs off
void Hud_SetFlashlightIcon(int arg0, int arg1, int arg2) {
    int temp_a0;
    int temp_s1;

    temp_a0 = F_(arg0, 0x74, int);
    if (temp_a0 != 0) {
        temp_s1 = ((arg1 & 0xFF) * 0x1E) + 0xD2;
        if (arg2 == 0) {
            func_003F45A0((float) (temp_s1 + 0xA), temp_a0);
            func_003F44E0((float) temp_s1, F_(arg0, 0x74, int));
            return;
        }
        func_003F45A0((float) temp_s1, temp_a0);
        func_003F44E0((float) (temp_s1 + 0xA), F_(arg0, 0x74, int));
    }
}
