/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_00268950(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_00268960(int a0, int a1) {
    return ((unsigned int)(0) < (unsigned int)((*(int*)(char*)a0 ^ *(int*)(char*)a1)));
}

void func_00268980(Iter* out, Tree* t) {
    out->p = &t->header;
}

int func_00268990(int a0) {
    *(int*)((char*)a0) = *(int*)((char*)*(int*)(char*)a0 + 4);
    return a0;
}

int func_002689B0(int a0) {
    return (*(int*)(char*)a0 + 8);
}

int func_002689C0(int a0, int a1) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    return a0;
}

void func_002689D0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_002689E0(void* self) {
    return self;
}
