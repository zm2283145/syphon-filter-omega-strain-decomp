/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Rel* func_001E1300(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_001E1320(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter16* func_001E1340(Iter16* it) {
    it->p += 16;
    return it;
}
