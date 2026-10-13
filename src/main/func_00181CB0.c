/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* PtrArray_End(PtrVec* v) {
    return v->data + v->count;
}

void func_00181CD0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* PtrArray_Begin(PtrVec* v) {
    return v->data;
}
