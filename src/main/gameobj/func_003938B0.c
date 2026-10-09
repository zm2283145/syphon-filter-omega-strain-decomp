/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

/* Iterator inequality. */
int func_003938B0(Iter* a, Iter* b) {
    return a->p != b->p;
}

void func_003938D0(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Advances a linked-list iterator to the node's next pointer (+4). */
Iter* func_003938E0(Iter* it) {
    it->p = (int*)it->p[1];
    return it;
}
