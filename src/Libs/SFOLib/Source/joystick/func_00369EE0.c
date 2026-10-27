#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
void cJoyPad_Clear(char * arg0, int arg1) {
    int var_a2;
    char * var_a0;
    int temp_a1;

    var_a0 = arg0;
    F_(var_a0, 0x12C, int) = 0;
    temp_a1 = ~arg1;
    F_(var_a0, 0x130, int) = 0;
    var_a2 = 0;
    F_(var_a0, 0x134, int) = 0;
    F_(var_a0, 0x138, int) = 0;
    F_(var_a0, 0x13C, int) = 0;
    F_(var_a0, 0x140, int) = 0;
    F_(var_a0, 0x144, int) = 0;
    F_(var_a0, 0x148, int) = 0;
    F_(var_a0, 0x10C, int) = (int) (F_(var_a0, 0x10C, int) & temp_a1);
    F_(var_a0, 0x110, int) = (int) (F_(var_a0, 0x110, int) & temp_a1);
    F_(var_a0, 0x114, int) = (int) (F_(var_a0, 0x114, int) & temp_a1);
    F_(var_a0, 0x118, int) = (int) (F_(var_a0, 0x118, int) & temp_a1);
    F_(var_a0, 0x104, int) = (int) (F_(var_a0, 0x104, int) & temp_a1);
    do {
        F_(var_a0, 0x17C, int) = 0;
        F_(var_a0, 0x14C, int) = 0;
        var_a2 += 6;
        F_(var_a0, 0x180, int) = 0;
        F_(var_a0, 0x150, int) = 0;
        F_(var_a0, 0x184, int) = 0;
        F_(var_a0, 0x154, int) = 0;
        F_(var_a0, 0x188, int) = 0;
        F_(var_a0, 0x158, int) = 0;
        F_(var_a0, 0x18C, int) = 0;
        F_(var_a0, 0x15C, int) = 0;
        F_(var_a0, 0x190, int) = 0;
        F_(var_a0, 0x160, int) = 0;
        var_a0 += 0x18;
    } while (var_a2 < 0xC);
}
