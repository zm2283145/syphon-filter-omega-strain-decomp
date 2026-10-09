/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_001AF6B0(char* self) {
    return self + 16;
}

float func_001AF6C0(char* self) {
    return *(float*)(self + 8);
}

int func_001AF6D0(char* self) {
    return *(int*)(self + 0);
}

int func_001AF6E0(char* self) {
    return *(int*)(self + 0);
}

void func_001AF6F0(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_001AF710(Iter* out, PtrVec* v) {
    out->p = v->data;
}
