/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

int* func_00363DB0(PtrVec* v) {
    return v->data + v->count;
}

void func_00363DD0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_00363DE0(char* self) {
    return *(int*)(self + 8);
}

void* func_00363DF0(char* self) {
    return self + 8;
}

void* func_00363E00(char* self) {
    return self + 11856;
}
