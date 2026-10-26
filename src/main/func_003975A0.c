/*
 * Matched functions (byte-identical with the retail executable).
 * Tree iterator helpers.
 */

#include "loose03_types.h"

/* Iterator inequality. */
int opNe_cLListIteratorR_cLListIteratorR_9(Iter* a, Iter* b) {
    return a->p != b->p;
}

void cLList_cSkaPlaybackGroupPtr_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Advance: follow the link at +4 of the current node. */
Iter* cLListIterator_cSkaPlaybackGroupPtr_opInc(Iter* it) {
    it->p = (int*)it->p[1];
    return it;
}
