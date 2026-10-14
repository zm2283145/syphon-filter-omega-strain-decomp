/*
 * main/gameFrontEnd: range (2 files, 002C8E80-002C8E90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002C8E80 */
#pragma push /* merge_units */
/* Returns 2048.0f. */
float func_002C8E80(void) { return 2048.0f; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C8E80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C8E80 */

/* merge_units: begin func_002C8E90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Quad* func_002C8E90(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C8E90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C8E90 */
