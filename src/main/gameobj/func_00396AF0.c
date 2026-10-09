/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_00396AF0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00396B00(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_00396B10(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_00396B20(int a0, int a1, int a2) {
    *(int*)((char*)a0) = a2;
    *(int*)((char*)a0 + 4) = *(int*)((char*)a1 + 12);
    *(int*)((char*)a0 + 8) = (*(int*)((char*)a0 + 4) + (*(int*)((char*)a1 + 8) << 2));
    *(int*)((char*)a0 + 12) = (*(int*)((char*)a0 + 4) + (*(int*)(char*)a1 << 2));
    return a0;
}

void* func_00396B60(void* self) {
    return self;
}

void func_00396B70(char* self) {
    *(int*)(self + 4) = 0;
}
