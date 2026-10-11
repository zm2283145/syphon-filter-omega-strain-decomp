#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_004505C0();                                
int func_00451B00(char * , int, char *, int);                 
extern char D_004C0D10;
extern char * D_00585E60;

#pragma push
#pragma opt_common_subs off
void func_00447E30(int d0, int d1, int d2, signed char *arg3) {
    signed char *temp_a3;
    int temp_a0;
    signed char *var_a2;
    signed char *var_a1;
    int var_a0;

    if (func_004505C0() == 0) {
        F_(D_00585E60, 0x1F0, int) = 1;
        temp_a0 = F_(arg3, 0x18, int);
        switch (temp_a0) {                          
        case 0:
            break;
        default:
        case -991:
        case -989:
        case -988:
            func_00451B00(D_00585E60, 1, &D_004C0D10, 0x9CC);
            break;
        }
        var_a0 = 0x15;
        var_a2 = arg3;
        temp_a3 = D_00585E60 + 0x1CEC;
        var_a1 = temp_a3;
        do {
            var_a0 -= 1;
            *var_a1 = *var_a2;
            var_a2 += 1;
            var_a1 += 1;
        } while (var_a0 > 0);
        F_(temp_a3, 0x18, int) = F_(arg3, 0x18, int);
    }
}
#pragma pop
