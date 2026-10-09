/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003D0E40(int, int, int, int, float, float);

void func_003D0D70(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_003D0D80(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003D0D90(Iter* out, PtrVec* v) {
    out->p = v->data;
}

int func_003D0DA0(int a0, int a1) {
    *(int*)((char*)a0) = a1;
    return a0;
}

int func_003D0DB0(int a0, int a1) {
    *(int*)((char*)a0) = a1;
    return a0;
}

void* func_003D0DC0(char* self) {
    return self + 4;
}

int func_003D0DD0(int a0, int a1, int a2, float f12, float f13) {
    int tmp0;

    tmp0 = *(int*)(char*)a0;
    return func_003D0E40(a0, a1, tmp0, a2, f12, f13);
}
