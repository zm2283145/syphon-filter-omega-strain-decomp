#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_003E8EB0(int);                               
int func_003E9770(int);                               

#pragma opt_common_subs off
void func_00244280(int arg0) {
    int temp_a0;
    int temp_a0_2;

    temp_a0 = F_(arg0, 0x68, int);
    if (temp_a0 != 0) {
        if (F_(arg0, 0x64, int) == 0) {
            func_003E8EB0(temp_a0);
        }
        F_(arg0, 0x68, int) = 0;
    }
    temp_a0_2 = F_(arg0, 0x64, int);
    if (temp_a0_2 != 0) {
        func_003E9770(temp_a0_2);
        F_(arg0, 0x64, int) = 0;
    }
}
