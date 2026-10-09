/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hudTargets.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hudTargets_types.h"

void func_00273EE0(int* dst, int* src) {
    *dst = *src;
}

Word* func_00273EF0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
