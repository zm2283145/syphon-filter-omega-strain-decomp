/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hudTargets.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hudTargets_types.h"

void std_list_cHudTargetInfoPtr_generic_iterator_opCast(int* dst, int* src) {
    *dst = *src;
}

Word* std_list_cHudTargetInfoPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
