/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cArray_cSkaAnimAnchorListEntry_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Iterator ++ over 384-byte elements. */
Iter16* cArray_cSkaAnimAnchorListEntry_Iterator_opInc(Iter16* it) {
    it->p = it->p + 384;
    return it;
}
