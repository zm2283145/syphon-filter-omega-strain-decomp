/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

float func_003ADEB0(char* self) {
    return *(float*)(self + 4);
}

int func_003ADEC0(char* self) {
    return *(int*)(self + 0);
}

void func_003ADED0(int a0, int a1) {
    *(int*)((char*)a0) = (*(int*)((char*)a1 + 8) + (*(int*)((char*)a1 + 4) << 5));
}

void func_003ADEF0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
