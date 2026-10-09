/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0013BCB0(int, int);

void func_00408DF0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_00408E00(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return (tmp1 + (tmp0 * 292));
}

int func_00408E30(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = func_0013BCB0(a0, a1);
    *(int*)((char*)a0 + 12) = a2;
    return tmp0;
}

Word* func_00408E70(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00408E80(Iter* out, Tree* t) {
    out->p = &t->header;
}

void* func_00408E90(char* self) {
    return self + 8;
}
