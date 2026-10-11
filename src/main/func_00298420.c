#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_001692D0(int);                             
int strncpy(signed char *, int, int);                            
extern signed char D_0048B7A0;
extern int D_0048B7A4;

void func_00298420(char * arg0) {
    int var_s2;
    int temp_v1;
    char * var_s1;
    signed char *var_s0;

    var_s2 = 0;
    var_s1 = arg0;
    var_s0 = &D_0048B7A0;
    D_0048B7A0 = F_(arg0, 0x1D4, signed char);
    D_0048B7A4 = F_(arg0, 0x1CC, int);
    do {
        temp_v1 = F_(var_s1, 0x2D0, int);
        if (temp_v1 != 0) {
            strncpy(var_s0 + 8, func_001692D0(temp_v1 + 4), 0x1F);
            F_(var_s0, 0x28, signed char) = 0;
        } else {
            F_(var_s0, 0x8, signed char) = 0;
        }
        var_s2 += 1;
        var_s1 += 4;
        var_s0 += 0x20;
    } while (var_s2 < 6);
}
