/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

/* Iterator inequality. */
int cArray_cSkaPlaybackItem_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Advance an iterator over 32-byte elements. */
Iter16* cArray_cSkaPlaybackItem_Iterator_opInc(Iter16* it) {
    it->p = it->p + 32;
    return it;
}
