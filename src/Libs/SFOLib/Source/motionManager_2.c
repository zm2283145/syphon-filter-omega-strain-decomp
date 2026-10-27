/*
 * Libs/SFOLib/Source/motionManager: 1 file, 0040F520
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040F520 */
#pragma push /* merge_units */
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
void cMotionManager_FlushUpdateList(void) {
    Tree* t = g_MotionManager;

    if (t != 0) {
        World_ClearPending(t);
    }
}
static inline void merge_flush_func_0040F520(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040F520 */
