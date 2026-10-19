#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int String_AssignString();                    

int func_004093E0(int arg0, int arg1) {
    char * var_s2;
    char * var_s1;

    String_AssignString();
    var_s1 = (char *)(arg1 + 0xC);
    var_s2 = (char *)(arg0 + 0xC);
    do {
        String_AssignString(var_s2, var_s1);
        F_(var_s2, 0xC, int) = F_(var_s1, 0xC, int);
        F_(var_s2, 0x10, int) = F_(var_s1, 0x10, int);
        String_AssignString(var_s2 + 0x14, var_s1 + 0x14);
        String_AssignString(var_s2 + 0x20, var_s1 + 0x20);
        F_(var_s2, 0x2C, int) = F_(var_s1, 0x2C, int);
        F_(var_s2, 0x30, float) = F_(var_s1, 0x30, float);
        F_(var_s2, 0x34, signed char) = F_(var_s1, 0x34, signed char);
        var_s2 += 0x38;
        var_s1 += 0x38;
    } while ((void *)(var_s2) != (void *)((arg0 + 0x124)));
    return arg0;
}
