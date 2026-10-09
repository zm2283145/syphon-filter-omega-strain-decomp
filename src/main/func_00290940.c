/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* func_00290940(PtrVec* v) {
    return v->data + v->count;
}

void func_00290960(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_00290970(char* self) {
    return *(int*)(self + 8);
}

void* func_00290980(char* self) {
    return self + 8;
}

void* func_00290990(char* self) {
    return self + 11856;
}
