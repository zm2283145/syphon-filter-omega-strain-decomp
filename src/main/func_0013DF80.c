/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0013DF80(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Iter* func_0013DFA0(Iter* d, Iter* s) {
    d->p = s->p;
    return d;
}

void func_0013DFB0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_0013DFC0(char* self) {
    return self + 560;
}
