/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

/* Iterator inequality. */
int opNe_cLListIteratorR_cLListIteratorR_8(Iter* a, Iter* b) {
    return a->p != b->p;
}

void cLList_cSkaTransPlaybackPtr_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Advances a linked-list iterator to the node's next pointer (+4). */
Iter* cLListIterator_cSkaTransPlaybackPtr_opInc(Iter* it) {
    it->p = (int*)it->p[1];
    return it;
}
