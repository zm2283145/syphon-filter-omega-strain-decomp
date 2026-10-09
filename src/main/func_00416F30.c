/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

void func_00416F30(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* end() of the element vector. */
L4Elem18* func_00416F40(L4Elem18Vec* v) {
    return v->data + v->count;
}

void* func_00416F60(char* self) {
    return self + 8;
}
