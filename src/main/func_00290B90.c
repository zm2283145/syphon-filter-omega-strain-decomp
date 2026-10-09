/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Rel* func_00290B90(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_00290BB0(int a0, int a1) {
    *(int*)((char*)a0) = a1;
    return a0;
}
