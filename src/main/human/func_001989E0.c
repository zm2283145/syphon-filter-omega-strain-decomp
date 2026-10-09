/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001989E0(Iter* a, Iter* b) {
    return a->p != b->p;
}

/* List iterator ++: follow the next link at node +0x04. */
Iter* func_00198A00(Iter* it) {
    it->p = (int*)it->p[1];
    return it;
}
