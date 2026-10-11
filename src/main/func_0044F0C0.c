#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int *func_0044F290(char * , int);                    

int *func_0044F0C0(char * arg0, int arg1) {
    int *temp_v0;
    int temp_s1;
    int var_s0;

    if (arg1 == 0) {
        return NULL;
    }
    temp_s1 = F_(arg0, 0x11C, int);
    for (var_s0 = 0; var_s0 < temp_s1; var_s0++) {
        temp_v0 = func_0044F290(arg0 + 0x118, var_s0);
        if (arg1 == *temp_v0) {
            return temp_v0;
        }
    }
    return NULL;
}