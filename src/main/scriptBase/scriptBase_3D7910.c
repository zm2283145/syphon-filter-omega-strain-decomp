/*
 * main/scriptBase: range (2 files, 003D7910-003D7930)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptBase_types.h"

/* merge_units: begin func_003D7910 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* push_back: inserts one value at the end. */
int func_003D7910(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D7910(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D7910 */

/* merge_units: begin func_003D7930 */
#pragma push /* merge_units */
/* Variadic no-op (debug print stub). */
void Script_PrintWarning(int fmt, ...) {
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D7930(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D7930 */
