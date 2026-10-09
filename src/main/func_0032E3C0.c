/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0032E3C0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return (tmp1 + (tmp0 * 24));
}

void func_0032E3E0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_0032E3F0(char* self) {
    return *(int*)(self + 8);
}
