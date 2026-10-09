/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0032F820(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return (tmp1 + (tmp0 * 24));
}

void func_0032F840(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_0032F850(char* self) {
    return *(int*)(self + 8);
}
