/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cConstLListIterator_tCalloutPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
