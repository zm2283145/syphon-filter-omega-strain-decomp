/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001912A0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* func_001912C0(Iter* it) {
    it->p++;
    return it;
}
