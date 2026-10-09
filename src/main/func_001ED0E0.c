/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001ED0E0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter16* func_001ED100(Iter16* it) {
    it->p += 16;
    return it;
}
