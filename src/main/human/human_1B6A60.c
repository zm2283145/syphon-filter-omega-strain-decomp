/*
 * main/human: range (2 files, 001B6A60-001B6A90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001B6A60 */
#pragma push /* merge_units */
Rel* ItemList_Reset(Rel* r); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern Rel* ItemList_Reset(Rel*);
#endif /* merge_units */
#define ItemList_Reset(a0) (ItemList_Reset((a0))) /* merge_units */


/* Clear the three words and set the byte at +0x0C. */
Rel* cArray_tItem_ctor(Rel* r) {
    ItemList_Reset(r);
    *((char*)r + 12) = 1;
    return r;
}
#undef ItemList_Reset /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B6A60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B6A60 */

/* merge_units: begin func_001B6A90 */
#pragma push /* merge_units */
Rel* ItemList_Reset(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B6A90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B6A90 */
