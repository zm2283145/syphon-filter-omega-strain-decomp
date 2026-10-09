/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* end() of a vector of 24-byte elements. */
Elem24* func_0032E3C0(Vec24* v) {
    return v->data + v->count;
}

void func_0032E3E0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* begin() */
Elem24* func_0032E3F0(Vec24* v) {
    return v->data;
}
