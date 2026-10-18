#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002EBC48(int *);                           
int func_002EBCE0(int *);                           

int Net_GetClock(int arg0) {
    int sp1C;
    int var_v0;

    if (arg0 != 0) {
        var_v0 = func_002EBC48(&sp1C);
        asm { .set reorder } /* barrier: keeps the b; nop + aligned else label */
    } else {
        var_v0 = func_002EBCE0(&sp1C);
    }
    if (var_v0 == 0) {
        return sp1C;
    }
    return -1;
}
