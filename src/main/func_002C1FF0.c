/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* Vector end(). */
int* func_002C1FF0(PtrVec* v) {
    return v->data + v->count;
}

void func_002C2010(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* Vector data pointer. */
int* func_002C2020(PtrVec* v) {
    return v->data;
}

int** func_002C2030(PtrVec* v) {
    return &v->data;
}

/* Vector push_back. */
int func_002C2040(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
