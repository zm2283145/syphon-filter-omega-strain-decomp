/*
 * Matched functions (byte-identical with the retail executable).
 * Tree iterator helpers.
 */

#include "loose03_types.h"

/* Iterator inequality. */
int func_003975A0(Iter* a, Iter* b) {
    return a->p != b->p;
}

void func_003975C0(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Advance: follow the link at +4 of the current node. */
Iter* func_003975D0(Iter* it) {
    it->p = (int*)it->p[1];
    return it;
}
