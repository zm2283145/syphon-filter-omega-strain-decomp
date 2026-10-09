/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00380D20(int a0) {
    return (*(int*)(char*)a0 + 8);
}

void func_00380D30(Iter* out, PtrVec* v) {
    out->p = v->data;
}
