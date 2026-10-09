/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001A6D00(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* func_001A6D20(Iter* it) {
    it->p++;
    return it;
}
