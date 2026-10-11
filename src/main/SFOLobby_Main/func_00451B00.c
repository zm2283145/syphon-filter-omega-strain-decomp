#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma opt_common_subs off
void func_00451B00(int arg0, unsigned char arg1, int arg2, int arg3) {
    if (F_(arg0, 0x2564, unsigned char) != 5) {
        F_(arg0, 0x2564, unsigned char) = arg1;
        F_(arg0, 0x2568, int) = arg2;
        F_(arg0, 0x256C, int) = arg3;
    }
}
