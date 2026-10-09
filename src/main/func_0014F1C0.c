/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0014F1C0(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* func_0014F1E0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0014F1F0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

int func_0014F200(int a0) {
    return (*(int*)((char*)a0 + 8) + (*(int*)((char*)a0 + 4) << 3));
}

void func_0014F220(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_0014F230(char* self) {
    return *(int*)(self + 8);
}
