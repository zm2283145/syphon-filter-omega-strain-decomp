/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cAssocArray_cString_cSkaAnimationSetPtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_cString_cSkaAnimationSetPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

void std_tree_pair_cString_value_compare_begin(Iter* out, Tree* t) {
    out->p = t->leftmost;
}
