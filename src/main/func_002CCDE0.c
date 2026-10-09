/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00138EA0(int, int, int, int);

Word* func_002CCDE0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_002CCDF0(int a0) {
    *(int*)((char*)a0) = *(int*)((char*)*(int*)(char*)a0 + 4);
    return a0;
}

int func_002CCE10(int a0) {
    return (*(int*)(char*)a0 + 8);
}

int func_002CCE20(int a0, int a1) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    return a0;
}

void func_002CCE30(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_002CCE40(void* self) {
    return self;
}

int func_002CCE50(int a0, int a1) {
    int loc[2];
    int a2, a3, v0;

    a3 = a1;
    v0 = a0 + 4;
    a1 = a0;
    *(int*)(char*)loc = v0;
    a0 = (int)((char*)loc + 4);
    a2 = (int)loc;
    v0 = func_00138EA0(a0, a1, a2, a3);
    goto ret;
ret:
    return v0;
}
