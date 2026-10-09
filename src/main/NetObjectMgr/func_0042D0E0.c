/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Iterator copy-assignment. */
Word* func_0042D0E0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* end(): iterator at the tree header. */
void func_0042D0F0(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* begin(): iterator at the leftmost node. */
void func_0042D100(Iter* out, Tree* t) {
    out->p = t->leftmost;
}
