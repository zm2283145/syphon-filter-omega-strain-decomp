/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_0013A2A0(int);

int func_0013F100(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void func_0013F120(Iter* out, Tree* t) {
    out->p = &t->header;
}

int func_0013F130(int a0) {
    func_0013A2A0(a0);
    return a0;
}

int func_0013F160(int a0) {
    return (*(int*)(char*)a0 + 16);
}

void func_0013F170(Iter* out, Tree* t) {
    out->p = t->leftmost;
}

int func_0013F180(int a0, int a1, int a2) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    *(int*)((char*)a0 + 4) = *(int*)(char*)a2;
    return a0;
}
