#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_001164C0(int *arg0, int *arg1, unsigned int arg2) {
    unsigned int var_a3;
    int *var_a1;
    unsigned int temp_a2;
    int temp_v1;
    int *var_a0;

    var_a0 = arg0;
    var_a1 = arg1;
    temp_a2 = arg2 >> 2;
    var_a3 = 0;
    if (temp_a2 != 0) {
        do {
            temp_v1 = *var_a1;
            var_a3 += 1;
            var_a1 += 1;
            *var_a0 = temp_v1;
            var_a0 += 1;
        } while (var_a3 < temp_a2);
    }
    return 0;
}
