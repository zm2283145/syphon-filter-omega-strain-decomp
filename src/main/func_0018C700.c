/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_001BACB0(int, int, int);

int func_0018C700(int a0) {
    return (*(int*)(char*)a0 + 64);
}

int func_0018C710(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void func_0018C730(Iter* out, Tree* t) {
    out->p = &t->header;
}

void func_0018C740(int a0) {
    int loc[1];
    int a1, a2, s0, v1;

    s0 = a0;
    a0 = (int)loc;
    func_001BACB0(a0, a1, a2);
    v1 = *(int*)(char*)loc;
    *(int*)(char*)s0 = v1;
    goto ret;
ret:;
}
