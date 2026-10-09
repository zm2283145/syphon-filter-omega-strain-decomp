/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int PtrVec_Insert(int, int, int, int);

Word* func_0032D040(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0032D050(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

int func_0032D070(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return PtrVec_Insert(a0, (tmp1 + (tmp0 << 2)), 1, a1);
}

void func_0032D090(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_0032D0A0(char* self) {
    return *(int*)(self + 8);
}

int func_0032D0B0(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return PtrVec_Insert(a0, (tmp1 + (tmp0 << 2)), 1, a1);
}
