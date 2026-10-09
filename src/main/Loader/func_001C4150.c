/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc: pointer-vector helpers.
 */

#include "types.h"

/* End pointer. */
int* func_001C4150(PtrVec* v) {
    return v->data + v->count;
}

/* Copy an iterator. */
void func_001C4170(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* Data pointer. */
int* func_001C4180(PtrVec* v) {
    return v->data;
}
