#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int func_00138B70();                         
int func_00412CF0();                          
int func_00416A00();                         
int func_00418240();                         
int operator_delete();                          
extern char D_004E09F0;
extern char D_00571DC0;

char * func_00417AE0(char * arg0, long long arg1) {
    int temp_a1;
    char * temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&D_004E09F0);
        temp_a1 = F_(arg0, 0x20, int);
        if (temp_a1 != -1) {
            func_00412CF0(&D_00571DC0, temp_a1);
        }
        temp_a0 = arg0 + 0x70;
        if ((temp_a0 != NULL) && (temp_a0 != NULL) && (temp_a0 != NULL)) {
            func_00418240(temp_a0, 0);
        }
        temp_a0_2 = arg0 + 0x14;
        if (temp_a0_2 != NULL) {
            func_00138B70(temp_a0_2, 0);
        }
        temp_a0_3 = arg0 + 8;
        if (temp_a0_3 != NULL) {
            func_00138B70(temp_a0_3, 0);
        }
        func_00416A00(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
