/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003308A0(char* self) {
    return *(int*)(self + 0);
}

void func_003308B0(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a1 + 4);
    tmp1 = *(int*)((char*)a1 + 8);
    *(int*)((char*)a0) = (tmp1 + (tmp0 * 24));
}

void func_003308D0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
