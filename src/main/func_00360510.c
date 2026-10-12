#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_CtorCStr_13B480(char *, char *);                 
int func_00138B70(char *, int);                            
int func_0013D680(char * , char *);                       
const unsigned int D_004BB868[2] = { 0x0, 0x0 };

void func_00360510(char * arg0) {
    int sp30[4];
    int sp20[4];
    int var_a0;
    int var_a1;
    char * var_a0_2;
    char * var_v1;

    var_a0 = 0;
    var_v1 = arg0;
    do {
        F_(var_v1, 0x0, int) = 0;
        F_(var_v1, 0x4, int) = 0;
        var_a0 += 6;
        F_(var_v1, 0x8, int) = 0;
        F_(var_v1, 0xC, int) = 0;
        F_(var_v1, 0x10, int) = 0;
        F_(var_v1, 0x14, int) = 0;
        var_v1 += 0x18;
    } while (var_a0 < 0xC);
    String_CtorCStr_13B480(sp30, &(*(char*)D_004BB868));
    func_0013D680(arg0 + 0x30, sp30);
    func_00138B70(sp30, 0);
    String_CtorCStr_13B480(sp20, &(*(char*)D_004BB868));
    func_0013D680(arg0 + 0x3C, sp20);
    func_00138B70(sp20, 0);
    F_(arg0, 0x48, int) = 0;
    var_a1 = 0;
    var_a0_2 = arg0;
    do {
        F_(var_a0_2, 0x4C, signed char) = 0;
        F_(var_a0_2, 0x4D, signed char) = 0;
        var_a1 += 1;
        F_(var_a0_2, 0x4E, signed char) = 0;
        F_(var_a0_2, 0x4F, signed char) = 0;
        var_a0_2 += 4;
    } while (var_a1 < 6);
    F_(arg0, 0x64, signed char) = 0;
    F_(arg0, 0x65, signed char) = 0;
    F_(arg0, 0x66, signed char) = 0;
    F_(arg0, 0x67, signed char) = 0;
    F_(arg0, 0x68, signed char) = 0;
    F_(arg0, 0x69, signed char) = 0;
    F_(arg0, 0x6A, signed char) = 0;
    F_(arg0, 0x6B, signed char) = 0;
    F_(arg0, 0x6C, signed char) = 0;
    F_(arg0, 0x70, int) = -1;
}
