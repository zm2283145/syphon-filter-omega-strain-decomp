/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* End pointer of an array of 0x1D0-byte records. */
Elem1D0* std_vector_imp_cBone_end(Vec1D0Array* v) {
    int count;
    Elem1D0* data;

    count = v->count;
    data = v->data;
    return data + count;
}

void std_vector_cBone_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

Elem1D0* std_vector_imp_cBone_begin(Vec1D0Array* v) {
    return v->data;
}
