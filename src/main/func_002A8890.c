/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Iterator inequality. */
int opNe_cLListIteratorR_cLListIteratorR_6(Iter* a, Iter* b) {
    return a->p != b->p;
}

void cLList_GuiWidgetPtr_End(Iter* out, Tree* t) {
    out->p = &t->header;
}
