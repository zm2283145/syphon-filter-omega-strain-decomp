/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int PtrVec_Insert(int, int, int, int);

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

int func_00344EA0(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return PtrVec_Insert(a0, (tmp1 + (tmp0 << 2)), 1, a1);
}
