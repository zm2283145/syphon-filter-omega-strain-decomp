/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00362940(char* self) {
    return *(int*)(self + 0);
}

void func_00362950(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_00362970(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_00362980(char* self) {
    return self + 180;
}
