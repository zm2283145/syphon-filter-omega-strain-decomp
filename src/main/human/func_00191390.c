/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00191390(char* self) {
    return *(int*)(self + 0);
}

void func_001913A0(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_001913C0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_001913D0(char* self) {
    return self + 180;
}
