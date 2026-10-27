/*
 * Matched functions (byte-identical with the retail executable).
 * Accessors for a vector of 8-byte elements.
 */

#include "types.h"
#include "path_types.h"

/* end(): one past the last element. */
PathPair* std_vector_imp_tNodeLink_end_void_2(PathPairVec* v) {
    return v->data + v->count;
}

void std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* begin() */
PathPair* std_vector_imp_tNodeLink_begin_void_2(PathPairVec* v) {
    return v->data;
}
