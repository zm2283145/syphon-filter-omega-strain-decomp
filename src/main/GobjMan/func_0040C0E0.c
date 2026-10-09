/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc: pointer-vector iterator helpers.
 */

#include "types.h"

/* Iterator inequality. */
int func_0040C0E0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* end() iterator of a pointer vector. */
void func_0040C100(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}
