/*
 * main/GuiBatch: 2 files, 0025F220-0025F230
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0025F220 */
#pragma push /* merge_units */
#include "types.h"

/* Returns 2048.0f. */
float tVifFloatToInt_short_4_Bias(void)
{
    return 2048.0f;
}
#pragma pop /* merge_units */
/* merge_units: end func_0025F220 */

/* merge_units: begin func_0025F230 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern int cVisionFxMan_DrawLightGlows(int*, int, int);

/* Calls cVisionFxMan_DrawLightGlows(self, a1, 1) when the state is 1 or 2. */
void cVisionFxMan_DrawLightSfx(int* self, int a1) {
    int state = *self;

    if (state == 1 || state == 2) {
        cVisionFxMan_DrawLightGlows(self, a1, 1);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0025F230 */
