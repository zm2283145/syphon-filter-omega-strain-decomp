/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

float func_001AF320(char* self) {
    return *(float*)(self + 4);
}

int func_001AF330(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 8);
    return (tmp0 + (a1 * 464));
}

int func_001AF350(char* self) {
    return *(int*)(self + 0);
}

int func_001AF360(char* self) {
    return *(int*)(self + 0);
}

void func_001AF370(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_001AF390(Iter* out, PtrVec* v) {
    out->p = v->data;
}

int func_001AF3A0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

int func_001AF3C0(int a0) {
    *(int*)((char*)a0) = (*(int*)(char*)a0 + 464);
    return a0;
}
