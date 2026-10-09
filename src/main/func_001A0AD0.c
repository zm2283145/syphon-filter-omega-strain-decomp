/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_001A0AD0(char* self) {
    return self + 16;
}

int func_001A0AE0(char* self) {
    return *(int*)(self + 0);
}

void func_001A0AF0(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a1 + 4);
    tmp1 = *(int*)((char*)a1 + 8);
    *(int*)((char*)a0) = (tmp1 + (tmp0 * 384));
}

void func_001A0B10(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_001A0B20(char* self) {
    return self + 160;
}
