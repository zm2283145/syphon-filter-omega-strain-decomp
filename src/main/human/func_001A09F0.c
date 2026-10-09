/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001A09F0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Iterator ++ over 384-byte elements. */
Iter16* func_001A0A10(Iter16* it) {
    it->p = it->p + 384;
    return it;
}
