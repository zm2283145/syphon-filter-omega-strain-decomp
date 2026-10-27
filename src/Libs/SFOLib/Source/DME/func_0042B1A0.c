#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetGetLocalTime(int *);                           
int NetGetTime(int *);                           

int cDME_GetTime(int arg0) {
    int sp1C;
    int var_v0;

    if (arg0 != 0) {
        var_v0 = NetGetLocalTime(&sp1C);
        asm { .set reorder } /* barrier: keeps the b; nop + aligned else label */
    } else {
        var_v0 = NetGetTime(&sp1C);
    }
    if (var_v0 == 0) {
        return sp1C;
    }
    return -1;
}
