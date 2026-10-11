#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0035D1F0(char **, int);                           
int func_0036E220(char * , int);                         
int func_00461DC0(char * , int);                         
int operator_delete(char **);                            
extern char D_004E1840;

#pragma push
#pragma opt_common_subs off
char **func_00463060(char **arg0, long long arg1) {
    char * temp_a0;

    if (arg0 != NULL) {
        *arg0 = &D_004E1840;
        if (((char *)arg0 + 0x260) != 0) {
            if (((char *)arg0 + 0x280) != NULL) {
                func_0036E220((char *)arg0 + 0x364, -1);
                func_0036E220((char *)arg0 + 0x2C8, -1);
            }
            temp_a0 = (char *)arg0 + 0x260;
            if ((temp_a0 != NULL) && (temp_a0 != NULL) && (temp_a0 != NULL)) {
                func_00461DC0(temp_a0, 0);
            }
        }
        func_0035D1F0(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}

#pragma pop
