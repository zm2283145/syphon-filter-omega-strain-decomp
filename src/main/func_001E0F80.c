/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Address of element index of a 16-byte element array. */
FlagElem16* cArray_cEdgeGroup_opIndex(Vec16Array* v, int index) {
    return v->data + index;
}

int cArray_cEdgeGroup_Size(Vec16Array* v) {
    return v->count;
}

int cArray_cCollisionEdge_ConstIterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Advance an iterator over 0x60-byte records. */
Elem60Iter* cArray_cCollisionEdge_ConstIterator_opInc(Elem60Iter* it) {
    it->p = it->p + 1;
    return it;
}
