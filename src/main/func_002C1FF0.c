/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* func_002C1FF0(PtrVec* v) {
    return v->data + v->count;
}

void func_002C2010(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_002C2020(char* self) {
    return *(int*)(self + 8);
}

void* func_002C2030(char* self) {
    return self + 8;
}
