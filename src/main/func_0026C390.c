/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

Word* std_list_cHudTargetInfoPtr_generic_iterator_1_ctor(Word* dst, int value) {
    volatile int tmp = value; /* stored to the stack and reloaded */

    dst->value = tmp;
    return dst;
}
