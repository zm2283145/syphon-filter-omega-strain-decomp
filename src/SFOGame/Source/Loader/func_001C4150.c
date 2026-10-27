/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc: pointer-vector helpers.
 */

#include "types.h"

/* End pointer. */
int* std_vector_imp_cTerrainPtr_1_end(PtrVec* v) {
    return v->data + v->count;
}

/* Copy an iterator. */
void std_vector_cTerrainPtr_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* Data pointer. */
int* std_vector_imp_cTerrainPtr_1_begin(PtrVec* v) {
    return v->data;
}
