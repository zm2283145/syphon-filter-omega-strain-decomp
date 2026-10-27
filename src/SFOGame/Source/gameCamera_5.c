/*
 * main/gameCamera: range (2 files, 0017D070-0017D0A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "curve_count_down.h"

/* merge_units: begin func_0017D070 */
#pragma push /* merge_units */
typedef struct { char pad[0xB4]; float fB4; } S17D070;
int cSplinedMotion_cVector_IsTransitionInProgress(S17D070* s) {
    return !(s->fB4 == 0.0f);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017D070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017D070 */

/* merge_units: begin func_0017D0A0 */
#pragma push /* merge_units */
/* Count a curve's remaining time down to zero. */
DEFINE_CURVE_COUNT_DOWN(cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_NextFrame)
#pragma pop /* merge_units */
/* merge_units: end func_0017D0A0 */
