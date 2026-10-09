/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_002203B0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_002203C0(int a0, int a1) {
    return ((unsigned int)(0) < (unsigned int)((*(int*)(char*)a0 ^ *(int*)(char*)a1)));
}

void func_002203E0(Iter* out, Tree* t) {
    out->p = &t->header;
}

int func_002203F0(int a0) {
    *(int*)((char*)a0) = *(int*)((char*)*(int*)(char*)a0 + 4);
    return a0;
}
