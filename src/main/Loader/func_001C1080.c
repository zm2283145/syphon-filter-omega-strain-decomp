/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* v.push_back(value): insert one copy at end(). */
int PtrVec_PushBack_1C1080(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

/* Zero-initialise a three-word vector. */
Rel* func_001C10A0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
