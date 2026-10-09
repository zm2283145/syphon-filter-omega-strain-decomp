/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001E0EA0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return (tmp1 + (tmp0 * 96));
}

void func_001E0EC0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_001E0ED0(char* self) {
    return *(int*)(self + 8);
}
