/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Address of element index of a 16-byte element array. */
FlagElem16* func_001E0F80(Vec16Array* v, int index) {
    return v->data + index;
}

int func_001E0F90(Vec16Array* v) {
    return v->count;
}

int func_001E0FA0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Advance an iterator over 0x60-byte records. */
Elem60Iter* func_001E0FC0(Elem60Iter* it) {
    it->p = it->p + 1;
    return it;
}
