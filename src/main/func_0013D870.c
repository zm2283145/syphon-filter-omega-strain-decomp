/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0013D870(int a0, int a1) {
    int loc[1];
    int v0, v1;

    v0 = a0;
    *(int*)(char*)loc = a1;
    v1 = *(int*)(char*)loc;
    *(int*)(char*)a0 = v1;
    goto ret;
ret:
    return v0;
}

void func_0013D890(Iter* out, Tree* t) {
    out->p = &t->header;
}
