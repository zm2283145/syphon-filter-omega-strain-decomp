/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* func_001CF090(PtrVec* v) {
    return v->data + v->count;
}

void func_001CF0B0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_001CF0C0(char* self) {
    return *(int*)(self + 8);
}

int func_001CF0D0(char* self) {
    return *(int*)(self + 0);
}

void func_001CF0E0(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_001CF100(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void func_001CF110(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a1 + 4);
    tmp1 = *(int*)((char*)a1 + 8);
    *(int*)((char*)a0) = (tmp1 + (tmp0 * 464));
}

Word* func_001CF140(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_001CF150(Iter* out, PtrVec* v) {
    out->p = v->data;
}
