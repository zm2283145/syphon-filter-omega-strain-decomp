#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int func_0041DB80(int , signed char *);                    
int func_0041DC70(int , signed char *);                    
extern signed char D_0048B7A0;
extern int D_0048B7A4;

#pragma opt_common_subs off
void func_00298360(int arg0) {
    int var_s2;
    signed char *var_s1;
    int var_s0;

    var_s2 = 0;
    var_s1 = &D_0048B7A0;
    var_s0 = arg0;
    F_(arg0, 0x1D4, signed char) = (signed char) D_0048B7A0;
    F_(arg0, 0x1CC, int) = (int) D_0048B7A4;
    do {
        if (F_(var_s1, 0x8, signed char) != 0) {
            F_(var_s0, 0x2D0, int) = func_0041DB80(arg0, var_s1 + 8);
            if (F_(var_s0, 0x2D0, int) == 0) {
                F_(var_s0, 0x2D0, int) = func_0041DC70(arg0, var_s1 + 8);
            }
        } else {
            F_(var_s0, 0x2D0, int) = 0;
        }
        var_s2 += 1;
        var_s1 += 0x20;
        var_s0 += 4;
    } while (var_s2 < 6);
}
