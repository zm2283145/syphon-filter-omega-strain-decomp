#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0045A600(char * arg0, char * arg1) {
    int var_v0;

    var_v0 = 0;
    if (F_(arg1, 0x4, unsigned char) != F_(arg0, 0x4, unsigned char)) {
        var_v0 |= 1;
    }
    if (F_(arg1, 0x5, unsigned char) != F_(arg0, 0x5, unsigned char)) {
        var_v0 |= 2;
    }
    if (F_(arg1, 0x6, unsigned char) != F_(arg0, 0x6, unsigned char)) {
        var_v0 |= 4;
    }
    if (F_(arg1, 0x7, unsigned char) != F_(arg0, 0x7, unsigned char)) {
        var_v0 |= 8;
    }
    if (F_(arg1, 0x8, float) != F_(arg0, 0x8, float)) {
        var_v0 |= 0x10;
    }
    if (F_(arg1, 0xC, float) != F_(arg0, 0xC, float)) {
        var_v0 |= 0x20;
    }
    if (F_(arg1, 0x10, float) != F_(arg0, 0x10, float)) {
        var_v0 |= 0x40;
    }
    if (F_(arg1, 0x14, int) != F_(arg0, 0x14, int)) {
        var_v0 |= 0x80;
    }
    if (F_(arg1, 0x1C, float) != F_(arg0, 0x1C, float)) {
        var_v0 |= 0x400;
    }
    if (F_(arg1, 0x20, int) != F_(arg0, 0x20, int)) {
        var_v0 |= 0x800;
    }
    return var_v0;
}
