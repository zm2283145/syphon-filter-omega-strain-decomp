/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* func_001E5220(PtrVec* v) {
    return v->data + v->count;
}

void func_001E5240(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_001E5250(char* self) {
    return *(int*)(self + 8);
}

float func_001E5260(char* self) {
    return *(float*)(self + 12);
}

void AnimScalar_RestartTimer(int a0) {
    *(float*)((char*)a0 + 4) = *(float*)((char*)*(int*)(char*)a0 + 16);
}
