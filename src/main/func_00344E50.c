/*
 * Matched functions (byte-identical with the retail executable).
 * Pointer-vector helpers (end(), begin(), push_back).
 */

#include "loose03_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int count, int* value);

/* end() */
int* func_00344E50(PtrVec* v) {
    return v->data + v->count;
}

void func_00344E70(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* begin() */
int* func_00344E80(PtrVec* v) {
    return v->data;
}

int** func_00344E90(PtrVec* v) {
    return &v->data;
}

/* push_back */
int func_00344EA0(PtrVec* v, int* value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
