#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int NpcAi_RequestMode(int , int, int);

int func_001584B0(int arg0) {
    int var_a0;
    int var_a1;
    int var_v1;

    var_a0 = 0;
    var_v1 = arg0;
    do {
        F_(var_v1, 0x5C, int) = 0;
        F_(var_v1, 0x60, int) = 0;
        var_a0 += 3;
        F_(var_v1, 0x64, int) = 0;
        var_v1 += 0xC;
    } while (var_a0 < 9);
    F_(arg0, 0xF0, int) = 0;
    F_(arg0, 0xF8, int) = 0;
    NpcAi_RequestMode(arg0 + 0xF0, 0, 0);
    var_a1 = arg0 + 0x1E0;
    F_(arg0, 0x1D0, int) = -1;
    do {
        F_(var_a1, 0x4, int) = -2;
        F_(var_a1, 0x0, int) = 0;
        F_(var_a1, 0x8, int) = -1;
        var_a1 += 0x40;
    } while (var_a1 != (arg0 + 0x2E0));
    return arg0;
}
