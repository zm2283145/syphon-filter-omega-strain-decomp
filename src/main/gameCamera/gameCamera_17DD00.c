/*
 * main/gameCamera: range (2 files, 0017DD00-0017DD10)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0017DD00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


float func_0017DD00(float f12) {
    return f12;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017DD00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017DD00 */

/* merge_units: begin func_0017DD10 */
#pragma push /* merge_units */
#pragma peephole off
typedef struct { char pad[0x40]; Vec4 v; } S;
/* Sets the curve's target vector (+0x40). */
void VecCurve_SetTarget(S* dst, Vec4* src) { dst->v = *src; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017DD10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017DD10 */
