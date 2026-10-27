/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

FlagElem16* cArray_cCollisionEdge_ConstIterator_opMul(FlagElem16Iter* it) {
    return it->p;
}

Elem60* cArray_cEdgeGroup_Iterator_opMul(Elem60Iter* it) {
    return it->p;
}

/* End iterator of an array of 16-byte elements. */
void cArray_cEdgeGroup_End_void(FlagElem16Iter* out, Vec16Array* v) {
    out->p = v->data + v->count;
}

void cArray_cEdgeGroup_Begin_void(Iter* out, PtrVec* v) {
    out->p = v->data;
}

/* End iterator of an array of 0x60-byte records. */
void cArray_cCollisionEdge_End(Elem60Iter* out, Vec60Array* v) {
    int count;
    Elem60* data;

    count = v->count;
    data = v->data;
    out->p = data + count;
}

void cArray_cCollisionEdge_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
