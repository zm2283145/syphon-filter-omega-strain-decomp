/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "types.h"

Word* cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_cString16N_2_cSkaAnimationBlendPtr_cAllocator_pair_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
