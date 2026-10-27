/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Iterator copy-assignment. */
Word* cAssocArray_int_cSafePtr_cGOBJ_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* end(): iterator at the tree header. */
void std_map_int_cSafePtr_cGOBJ_cAllocator_pair_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
