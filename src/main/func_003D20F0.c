/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003D20F0(int a0, int a1) {
    return ((unsigned int)(0) < (unsigned int)((*(int*)(char*)a0 ^ *(int*)(char*)a1)));
}

void func_003D2110(Iter* out, Tree* t) {
    out->p = &t->header;
}

int func_003D2120(int a0) {
    *(int*)((char*)a0) = *(int*)((char*)*(int*)(char*)a0 + 4);
    return a0;
}

void* func_003D2140(void* self) {
    return self;
}

int func_003D2150(char* self) {
    return *(int*)(self + 0);
}

int func_003D2160(int a0) {
    return (*(int*)(char*)a0 + 8);
}

Word* func_003D2170(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003D2180(Iter* out, PtrVec* v) {
    out->p = v->data;
}
