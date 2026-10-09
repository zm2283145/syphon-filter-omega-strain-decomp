/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00159570(char* self) {
    return *(int*)(self + 0);
}

void func_00159580(Iter* out, PtrVec* v) {
    out->p = v->data;
}
