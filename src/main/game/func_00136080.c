#include "types.h"

extern char D_004E1D88[];
extern char D_004E1D90[];
extern char D_004E1D94[];
extern char D_004E1D98[];
extern char D_004E1D9C[];

int Vec4_GetZero(void) {
    int v0;
    int cond;

    v0 = *(signed char*)(char*)D_004E1D88;
    cond = v0 != 0;
    if (cond) goto L001360B8;
    v0 = 0 + 1;
    *(int*)(char*)D_004E1D90 = 0;
    *(char*)(char*)D_004E1D88 = v0;
    *(int*)(char*)D_004E1D94 = 0;
    *(int*)(char*)D_004E1D98 = 0;
    *(int*)(char*)D_004E1D9C = 0;
L001360B8:;
    v0 = (int)D_004E1D90;
    goto ret;
ret:
    return v0;
}
