/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001AF130(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void func_001AF150(Iter* out, Tree* t) {
    out->p = &t->header;
}
