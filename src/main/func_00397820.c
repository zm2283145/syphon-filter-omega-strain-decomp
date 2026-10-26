/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Address 8 bytes past the iterator position (payload of a tree node). */
void* cLListIterator_cSkaPlaybackGroupPtr_opMul(Iter* it) {
    return it->p + 2;
}

/* begin() */
void cLList_cSkaPlaybackGroupPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
