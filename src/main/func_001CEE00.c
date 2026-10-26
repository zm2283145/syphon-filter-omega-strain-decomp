/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_cWeaponSlotPair_cIkTarget_LeftRight_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
