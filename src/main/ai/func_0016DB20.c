/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_0016DB20(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0016DB30(int a0, int a1) {
    *(int*)((char*)a0) = *(int*)(char*)a1;
}
