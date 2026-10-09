/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* 16-byte copy. */
Quad* func_001BEAA0(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}

/* Build begin/end/capacity-end pointers from a counted int array. */
void func_001BEAD0(IntSpan* out, IntArray* arr) {
    out->end = arr->data + arr->size;
    out->begin = arr->data;
    out->end2 = out->begin + arr->size;
    out->capEnd = out->begin + arr->capacity;
}
