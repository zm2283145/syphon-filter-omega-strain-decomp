/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003939B0(int a0) {
    return (*(int*)(char*)a0 + 8);
}

void func_003939C0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
