/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_0027AA80(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_0027AA90(int a0) {
    return (*(int*)((char*)a0 + 8) + 8);
}
