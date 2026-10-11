#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002EC878(int, int);                        
extern int D_00497550;
extern int D_00497558;
extern signed char D_00582D00;

#pragma push
#pragma opt_propagation off
unsigned char func_00438A10(void) {
    unsigned char var_s0;
    int b; int a;

    var_s0 = 0;
    b = D_00497558; a = D_00497550;
    if (func_002EC878(a, b) == 0) {
        var_s0 = 1;
    }
    D_00582D00 = 0;
    D_00497550 = -1;
    D_00497558 = -1;
    return var_s0;
}
#pragma pop
