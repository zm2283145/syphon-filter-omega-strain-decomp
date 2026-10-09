/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001E1580(char* self) {
    return *(int*)(self + 0);
}

int func_001E1590(char* self) {
    return *(int*)(self + 0);
}

void func_001E15A0(int a0, int a1) {
    *(int*)((char*)a0) = (*(int*)((char*)a1 + 8) + (*(int*)((char*)a1 + 4) << 4));
}

void func_001E15C0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
