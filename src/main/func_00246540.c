/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00138EA0(int, int, int, int);

int func_00246540(int a0, int a1) {
    int loc[2];
    int a2, a3, v0;

    a3 = a1;
    v0 = a0 + 4;
    a1 = a0;
    *(int*)(char*)loc = v0;
    a0 = (int)((char*)loc + 4);
    a2 = (int)loc;
    v0 = func_00138EA0(a0, a1, a2, a3);
    goto ret;
ret:
    return v0;
}

Rel* func_00246570(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Rel* func_00246590(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
