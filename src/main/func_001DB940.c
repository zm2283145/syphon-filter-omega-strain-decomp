/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001DB940(int a0, int a1) {
    return ((unsigned int)((*(int*)(char*)a0 ^ *(int*)(char*)a1)) < (unsigned int)(1));
}

void func_001DB960(Iter* out, Tree* t) {
    out->p = &t->header;
}
