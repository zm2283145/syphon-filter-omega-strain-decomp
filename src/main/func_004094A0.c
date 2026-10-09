/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_004094A0(int a0) {
    return (*(int*)(char*)a0 + 24);
}

int func_004094B0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void func_004094D0(Iter* out, Tree* t) {
    out->p = &t->header;
}
