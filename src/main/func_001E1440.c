/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_vector_imp_cCollisionEdgePtr_1_end(PtrVec* v) {
    return v->data + v->count;
}

void std_vector_cCollisionEdgePtr_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* std_vector_imp_cCollisionEdgePtr_1_begin(PtrVec* v) {
    return v->data;
}
