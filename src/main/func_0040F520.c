/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern Tree* D_00571CD0;
extern void World_ClearPending(Tree*);

void Tree_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

void Tree_Begin(Iter* out, Tree* t) {
    out->p = t->leftmost;
}

/* Clears the global tree D_00571CD0 if it exists. */
void func_0040F540(void) {
    Tree* t = D_00571CD0;

    if (t != 0) {
        World_ClearPending(t);
    }
}
