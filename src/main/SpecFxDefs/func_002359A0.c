/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int List_InsertBefore(int, int, int, int);

int func_002359A0(int a0, int a1) {
    int loc[2];
    int a2, a3, v0;

    a3 = a1;
    v0 = a0 + 4;
    a1 = a0;
    *(int*)(char*)loc = v0;
    a0 = (int)((char*)loc + 4);
    a2 = (int)loc;
    v0 = List_InsertBefore(a0, a1, a2, a3);
    goto ret;
ret:
    return v0;
}

void func_002359D0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_002359E0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_002359F0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
