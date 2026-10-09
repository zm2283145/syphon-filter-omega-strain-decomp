/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00273EE0(int a0, int a1) {
    *(int*)((char*)a0) = *(int*)(char*)a1;
}

Word* func_00273EF0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
