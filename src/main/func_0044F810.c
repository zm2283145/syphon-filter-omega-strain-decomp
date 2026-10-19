#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int SFOLobby_Free(int);                               
extern int D_00585E58;

#pragma opt_common_subs off
void func_0044F810(int arg0) {
    int temp_a0;

    temp_a0 = F_(arg0, 0x14, int);
    if (temp_a0 != 0) {
        SFOLobby_Free(temp_a0);
        D_00585E58 -= F_(arg0, 0x0, int) * F_(arg0, 0x10, int);
    }
    F_(arg0, 0x0, int) = 0;
    F_(arg0, 0x4, int) = 0;
    F_(arg0, 0x14, int) = 0;
    F_(arg0, 0x18, signed char) = 1;
}
