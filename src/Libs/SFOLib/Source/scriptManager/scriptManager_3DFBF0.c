/*
 * main/scriptManager: range (2 files, 003DFBF0-003DFC00)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003DFBF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void std_tree_pair_int_value_compare_begin_void(Iter* out, Tree* t) {
    out->p = t->leftmost;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DFBF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DFBF0 */

/* merge_units: begin func_003DFC00 */
#pragma push /* merge_units */
extern void Script_Reschedule_3DFC40(int target, float delay);

typedef union { int i; void* p; float f; } ScriptArg;

/* Script native: reschedules target args[0] after args[1] seconds. */
int Script_Reschedule(ScriptArg* args)
{
    volatile int delay = args[1].i;
    volatile int target = args[0].i;
    Script_Reschedule_3DFC40(target, *(float*)&delay);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DFC00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DFC00 */
