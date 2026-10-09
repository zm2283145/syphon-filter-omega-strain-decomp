/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00139200(int, int, int, int);

int* func_00290940(PtrVec* v) {
    return v->data + v->count;
}

void func_00290960(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_00290970(char* self) {
    return *(int*)(self + 8);
}

void* func_00290980(char* self) {
    return self + 8;
}

void* func_00290990(char* self) {
    return self + 11856;
}

int func_002909A0(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return func_00139200(a0, (tmp1 + (tmp0 << 2)), 1, a1);
}
