/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0013F100(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void func_0013F120(Iter* out, Tree* t) {
    out->p = &t->header;
}
