/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

Word* func_003C5BB0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_003C5BC0(int* table, int index) {
    return table[index];
}
