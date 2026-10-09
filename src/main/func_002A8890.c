/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Iterator inequality. */
int func_002A8890(Iter* a, Iter* b) {
    return a->p != b->p;
}

void func_002A88B0(Iter* out, Tree* t) {
    out->p = &t->header;
}
