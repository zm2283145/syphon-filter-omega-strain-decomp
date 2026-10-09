/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0040C0E0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void func_0040C100(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}
