/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_vector_imp_cGOBJPtr_1_end_void(PtrVec* v) {
    return v->data + v->count;
}

void std_vector_cGOBJPtr_pointer2iterator_cGOBJPPR(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* std_vector_imp_cGOBJPtr_1_begin(PtrVec* v) {
    return v->data;
}
