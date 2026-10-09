/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DA330[];

Rel* func_0017F9B0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_0017F9D0(int a0) {
    *(int*)((char*)a0) = (int)D_004DA330;
    return a0;
}
