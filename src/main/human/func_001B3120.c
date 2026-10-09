/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_001BB080(int, int, int);
extern int func_001BE870(int, int);

int ReceiverMap_Erase(int a0, int a1) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a1;
    *(int*)(char*)loc = v0;
    a1 = (int)loc;
    v0 = func_001BE870(a0, a1);
    goto ret;
ret:
    return v0;
}

int func_001B3150(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void func_001B3170(int a0) {
    int loc[1];
    int a1, a2, s0, v1;

    s0 = a0;
    a0 = (int)loc;
    func_001BB080(a0, a1, a2);
    v1 = *(int*)(char*)loc;
    *(int*)(char*)s0 = v1;
    goto ret;
ret:;
}

void func_001B31A0(Iter* out, Tree* t) {
    out->p = &t->header;
}
