/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00397820(int a0) {
    return (*(int*)(char*)a0 + 8);
}

void func_00397830(Iter* out, PtrVec* v) {
    out->p = v->data;
}
