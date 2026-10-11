#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
extern int D_004DA380;

int func_003462A0(int arg0, int arg1) {
    int temp_a2;
    int var_v1;

    temp_a2 = arg0 + 0x18;
    var_v1 = temp_a2;
    F_(arg0, 0x0, int) = (int)(&D_004DA380);
    F_(arg0, 0x4, float) = F_(arg1, 0x4, float);
    F_(arg0, 0x8, float) = F_(arg1, 0x8, float);
    F_(arg0, 0xC, float) = F_(arg1, 0xC, float);
    F_(arg0, 0x10, float) = F_(arg1, 0x10, float);
    F_(arg0, 0x14, float) = F_(arg1, 0x14, float);
    do {
        var_v1 += 8;
    } while (var_v1 != (temp_a2 + 0x10));
    F_(temp_a2, 0x0, float) = F_(arg1, 0x18, float);
    F_(temp_a2, 0x4, float) = F_(arg1, 0x1C, float);
    F_(temp_a2, 0x8, float) = F_(arg1, 0x20, float);
    F_(temp_a2, 0xC, float) = F_(arg1, 0x24, float);
    F_(temp_a2, 0x10, float) = F_(arg1, 0x28, float);
    F_(temp_a2, 0x14, float) = F_(arg1, 0x2C, float);
    F_(arg0, 0x30, int) = (int ) (arg0 + 0x18);
    F_(arg0, 0x34, int) = 0;
    return arg0;
}
