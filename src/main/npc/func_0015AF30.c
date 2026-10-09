/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0015AF30(int a0, int a1) {
    *(int*)((char*)a0) = *(int*)(char*)a1;
}

Word* func_0015AF40(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
