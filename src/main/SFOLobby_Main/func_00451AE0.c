#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma opt_common_subs off
void func_00451AE0(int arg0) {
    if (F_(arg0, 0x2564, unsigned char) != 5) {
        F_(arg0, 0x2564, unsigned char) = 0U;
    }
}
