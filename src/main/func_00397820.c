/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Address 8 bytes past the iterator position (payload of a tree node). */
void* func_00397820(Iter* it) {
    return it->p + 2;
}

/* begin() */
void func_00397830(Iter* out, PtrVec* v) {
    out->p = v->data;
}
