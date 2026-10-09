/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_004097A0(int, int, int);

int func_00409480(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 8);
    return (tmp0 + (a1 * 292));
}

int func_004094A0(int a0) {
    return (*(int*)(char*)a0 + 24);
}

int func_004094B0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void func_004094D0(Iter* out, Tree* t) {
    out->p = &t->header;
}

void func_004094E0(int a0) {
    int loc[1];
    int a1, a2, s0, v1;

    s0 = a0;
    a0 = (int)loc;
    func_004097A0(a0, a1, a2);
    v1 = *(int*)(char*)loc;
    *(int*)(char*)s0 = v1;
    goto ret;
ret:;
}

int func_00409510(int a0, int a1) {
    *(int*)((char*)a0) = a1;
    return a0;
}
