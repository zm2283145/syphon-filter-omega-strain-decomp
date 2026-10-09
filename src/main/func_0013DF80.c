/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0013DF80(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Iter* Iter_Assign(Iter* d, Iter* s) {
    d->p = s->p;
    return d;
}

void Iter_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_0013DFC0(char* self) {
    return self + 560;
}
