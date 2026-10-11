#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0033C320(int, int);                                 
extern int D_00532FD0;

int func_0033CEF0(int arg0, int arg1) {
    int var_v0;

    if (F_(arg0, 0x78, unsigned char) != 0) {
        var_v0 = F_(arg1, 0x0, unsigned short) == 1;
        var_v0 = var_v0 ? F_(arg1, 0x2, unsigned short) == 0 : var_v0;
        if (var_v0 != 0) {
            var_v0 = F_(arg1, 0x8, unsigned short) == 0x800;
        }
        var_v0 = var_v0 ? F_(arg1, 0x6, unsigned short) == 0 : var_v0;
        if (var_v0 != 0) {
            D_00532FD0 = F_(arg0, 0x84, int);
            func_0033C320(arg0, 9);
            return 1;
        }
        goto block_9;
    }
block_9:
    return 0;
}
