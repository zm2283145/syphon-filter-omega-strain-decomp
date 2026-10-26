/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* PtrArray_End(PtrVec* v) {
    return v->data + v->count;
}

void std_vector_cGOBJPtr_pointer2iterator_cGOBJPPR(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* PtrArray_Begin(PtrVec* v) {
    return v->data;
}
