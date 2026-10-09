/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00287910(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_00287930(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_00287940(char* self) {
    return self + 4;
}
