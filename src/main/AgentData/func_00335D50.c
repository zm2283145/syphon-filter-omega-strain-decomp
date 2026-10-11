#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int awards_SetAwardsAndBonuses(char * , int, int);         
int func_00335D40();                                

void func_00335D50(char * arg0, int arg1) {
    int var_a0;
    int var_s2;
    char * var_s1;
    char * var_v1;

    var_a0 = 0x12;
    var_v1 = arg0 + 0x48;
    do {
        F_(var_v1, 0x8, int) = 0;
        F_(var_v1, 0xC, int) = 0;
        var_a0 += 6;
        F_(var_v1, 0x10, int) = 0;
        F_(var_v1, 0x14, int) = 0;
        F_(var_v1, 0x18, int) = 0;
        F_(var_v1, 0x1C, int) = 0;
        var_v1 += 0x18;
    } while (var_a0 < 0x19);
    F_(((char *)(var_a0 * 4) + (int)(arg0)), 0x8, int) = 0;
    awards_SetAwardsAndBonuses(arg0, 1, arg1);
    F_(arg0, 0xA4, int) = 0;
    var_s2 = 0;
    F_(arg0, 0xA8, int) = 0;
    F_(arg0, 0xAC, int) = 0;
    F_(arg0, 0xB0, int) = 0;
    F_(arg0, 0xB4, int) = 0;
    F_(arg0, 0xB8, int) = 0;
    F_(arg0, 0xBC, int) = 0;
    F_(arg0, 0xC0, int) = 0;
    for (var_s2 = 0; var_s2 < func_00335D40(); var_s2++) F_(arg0 + var_s2 * 4, 0xB2C, int) = F_(arg0 + var_s2 * 4, 0xB08, int);
    F_(arg0, 0xB70, signed char) = 1;
    F_(arg0, 0xB71, signed char) = 0;
    F_(arg0, 0xB54, int) = F_(arg0, 0xB50, int);
    F_(arg0, 0xD4, int) = 0xBF800000;
}
