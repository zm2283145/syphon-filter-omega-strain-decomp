#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_003813A0(int, int, int);                       
extern int D_00539248;

#pragma opt_common_subs off
void func_0043C6E0(int arg0) {
    int temp_a1;

    temp_a1 = F_(arg0, 0x48, int);
    if (temp_a1 != -1) {
        func_003813A0(D_00539248, temp_a1, 0);
        F_(arg0, 0x48, int) = -1;
    }
}
