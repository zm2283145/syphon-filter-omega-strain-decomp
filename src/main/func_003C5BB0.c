/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

Word* cCollisionModel_Address_int_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int cVU0Man_GetProgAddr(int* table, int index) {
    return table[index];
}
