#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_00138B70(int, int);                            
int operator_delete(int);                             

int func_00267740(int arg0, long long arg1) {
    int temp_a0;
    int temp_a0_2;

    if (arg0 != 0) {
        temp_a0 = arg0 + 0x20;
        if (temp_a0 != 0) {
            func_00138B70(temp_a0, 0);
        }
        temp_a0_2 = arg0 + 0x14;
        if (temp_a0_2 != 0) {
            func_00138B70(temp_a0_2, 0);
        }
        if (arg0 != 0) {
            func_00138B70(arg0, 0);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
