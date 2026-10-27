/*
 * Libs/SFOLib/Source/MemCard: 1 file, 0040D5D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040D5D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_002B5F48(int* a, int* b);

/* Polls func_002B5F48 until it returns non-zero. */
void cMemCard_WaitUntilNotBusy(void) {
    int loc[2];

    while (func_002B5F48(&loc[1], &loc[0]) == 0) {
    }
}
static inline void merge_flush_func_0040D5D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040D5D0 */
