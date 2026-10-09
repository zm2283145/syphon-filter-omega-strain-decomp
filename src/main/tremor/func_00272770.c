/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_00272770(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00272780(Iter* out, Tree* t) {
    out->p = &t->header;
}

void func_00272790(int a0, int a1) {
    *(int*)((char*)a0) = *(int*)(char*)a1;
}

Word* func_002727A0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
