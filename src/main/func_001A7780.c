/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* Ptr_IdentityCast(void* self) {
    return self;
}

int func_001A7790(char* self) {
    return *(int*)(self + 0);
}

void func_001A77A0(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_001A77C0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_001A77D0(char* self) {
    return self + 8;
}
