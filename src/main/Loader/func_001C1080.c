/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* v.push_back(value): insert one copy at end(). */
int std_vector_int_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

/* Zero-initialise a three-word vector. */
Rel* std_vector_int_ctor_void(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
