/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_vector_cGOBJPtr_end(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Iter* cArray_cGOBJPtr_ConstIterator_ctor_wrapiteratorR(Iter* d, Iter* s) {
    d->p = s->p;
    return d;
}

void std_vector_cGOBJPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cTerrain_GetBBox(char* self) {
    return self + 560;
}
