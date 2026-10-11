#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_00443EA0(int);                               
int func_00443F40(int);                             
extern int D_00585E58;

#pragma opt_common_subs off
void func_0044F880(int arg0, int arg1, int arg2, int arg3) {
    int temp_a0;

    temp_a0 = F_(arg0, 0x14, int);
    if (temp_a0 != 0) {
        func_00443EA0(temp_a0);
        D_00585E58 -= F_(arg0, 0x0, int) * F_(arg0, 0x10, int);
    }
    F_(arg0, 0x0, int) = 0;
    F_(arg0, 0x4, int) = 0;
    F_(arg0, 0x14, int) = 0;
    F_(arg0, 0x18, signed char) = 1;
    F_(arg0, 0x4, int) = 0;
    F_(arg0, 0x0, int) = arg1;
    F_(arg0, 0xC, int) = arg2;
    F_(arg0, 0x10, int) = arg3;
    if (F_(arg0, 0x0, int) < 5) {
        F_(arg0, 0x0, int) = 5;
    }
    F_(arg0, 0x8, int) = F_(arg0, 0x0, int);
    F_(arg0, 0x18, signed char) = 1;
    F_(arg0, 0x14, int) = func_00443F40(F_(arg0, 0x0, int) * F_(arg0, 0x10, int));
    D_00585E58 += F_(arg0, 0x0, int) * F_(arg0, 0x10, int);
}
