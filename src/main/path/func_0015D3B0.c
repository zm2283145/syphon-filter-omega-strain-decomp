/*
 * Matched functions (byte-identical with the retail executable).
 * Accessors for a vector of 8-byte elements.
 */

#include "types.h"
#include "path_types.h"

/* end(): one past the last element. */
PathPair* func_0015D3B0(PathPairVec* v) {
    return v->data + v->count;
}

void func_0015D3D0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* begin() */
PathPair* func_0015D3E0(PathPairVec* v) {
    return v->data;
}
