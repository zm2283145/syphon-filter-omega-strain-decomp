/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* End pointer of an array of 0x1D0-byte records. */
Elem1D0* func_001D7AD0(Vec1D0Array* v) {
    int count;
    Elem1D0* data;

    count = v->count;
    data = v->data;
    return data + count;
}

void func_001D7B00(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

Elem1D0* func_001D7B10(Vec1D0Array* v) {
    return v->data;
}
