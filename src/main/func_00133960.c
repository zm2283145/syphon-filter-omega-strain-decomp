/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00133960(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* func_00133980(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00133990(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_001339A0(char* self) {
    return self + 4;
}
