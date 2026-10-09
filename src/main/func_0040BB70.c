/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

int func_0040BB70(PtrVec* v) {
    return (int)v->data;
}

/* Address of the previous word (reverse-iterator dereference). */
int* func_0040BB80(Iter* it) {
    return it->p - 1;
}

/* Steps the pointer back one word. */
Iter* func_0040BB90(Iter* it) {
    it->p = it->p - 1;
    return it;
}

int func_0040BBB0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}
