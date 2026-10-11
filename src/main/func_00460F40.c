#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0036E220(char * , int);                         
int func_0041F370(char **, int);                           
int func_00461DC0(char * , int);                         
int operator_delete(char **);                            
extern char D_004E1730;

#pragma push
#pragma opt_common_subs off
char **func_00460F40(char **arg0, short arg1) {
    char * temp_a0;

    if (arg0 != NULL) {
        *arg0 = &D_004E1730;
        if (((char *)arg0 + 0x350) != 0) {
            if (((char *)arg0 + 0x370) != NULL) {
                func_0036E220((char *)arg0 + 0x454, -1);
                func_0036E220((char *)arg0 + 0x3B8, -1);
            }
            temp_a0 = (char *)arg0 + 0x350;
            if ((temp_a0 != NULL) && (temp_a0 != NULL) && (temp_a0 != NULL)) {
                func_00461DC0(temp_a0, 0);
            }
        }
        if (((char *)arg0 + 0x1C0) != NULL) {
            func_0036E220((char *)arg0 + 0x2A4, -1);
            func_0036E220((char *)arg0 + 0x208, -1);
        }
        func_0041F370(arg0, 0);
        if (arg1 > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
#pragma pop
