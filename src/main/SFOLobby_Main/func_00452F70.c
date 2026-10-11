#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
#pragma push
#pragma opt_common_subs off
void func_00452F70(char * arg0, int arg1, int arg2) {
    int (*temp_v1)(int, int);

    F_(arg0, 0x2409, signed char) = 1;
    temp_v1 = (int (*)(int, int))(F_(arg0, 0x2550, int));
    if (temp_v1 != NULL) {
        temp_v1(arg1, arg2);
    }
    F_(arg0, 0x2409, signed char) = 0;
}
#pragma pop
