/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* func_00344E50(PtrVec* v) {
    return v->data + v->count;
}

void func_00344E70(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_00344E80(char* self) {
    return *(int*)(self + 8);
}

void* func_00344E90(char* self) {
    return self + 8;
}
