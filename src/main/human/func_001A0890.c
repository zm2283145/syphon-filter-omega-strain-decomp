/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* func_001A0890(PtrVec* v) {
    return v->data + v->count;
}

void func_001A08B0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_001A08C0(char* self) {
    return *(int*)(self + 8);
}
