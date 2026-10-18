/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern Tree* g_MotionManager;
extern void World_ClearPending(Tree*);

void Tree_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

void Tree_Begin(Iter* out, Tree* t) {
    out->p = t->leftmost;
}

/* Clears the global tree g_MotionManager if it exists. */
void World_ClearPendingIfLoaded(void) {
    Tree* t = g_MotionManager;

    if (t != 0) {
        World_ClearPending(t);
    }
}
