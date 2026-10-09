/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

int* func_002596A0(PtrVec* v) {
    return v->data + v->count;
}

void func_002596C0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* func_002596D0(PtrVec* v) {
    return v->data;
}
