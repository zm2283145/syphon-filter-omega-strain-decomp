#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_004505C0();                                
extern char * D_00585E60;

typedef struct { char c[21]; } SCc21;
void func_00448E30(int d0, int d1, int d2, signed char *arg3) {
    signed char *temp_a3;
    signed char *var_a1;
    signed char *var_a2;
    int var_a0;

    if (func_004505C0() == 0) {
        var_a0 = 0x15;
        var_a2 = arg3;
        F_(D_00585E60, 0x1D4, int) = 1;
        temp_a3 = D_00585E60 + 0xC0C;
        var_a1 = temp_a3;
        *(SCc21 *)(temp_a3) = *(SCc21 *)(arg3);
        F_(temp_a3, 0x18, int) = F_(arg3, 0x18, int);
    }
}
