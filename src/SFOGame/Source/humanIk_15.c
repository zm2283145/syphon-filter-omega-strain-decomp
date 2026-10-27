/*
 * SFOGame/Source/humanIk: 1 file, 001D0C80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D0C80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int cHumanIkRoutine_OrientFoot_AfterPositionLeg(int self, int a1, int a2, int a3);
extern int cHumanIkRoutine_PositionLeg(int self, int a1, int a2, int a3);

/* Run cHumanIkRoutine_PositionLeg with the first argument, then cHumanIkRoutine_OrientFoot_AfterPositionLeg with the second. */
int cHumanIkRoutine_PositionLegAndOrientFoot(int self, int first, int second, int a3, int t0) {
    int result;

    cHumanIkRoutine_PositionLeg(self, first, a3, t0);
    result = cHumanIkRoutine_OrientFoot_AfterPositionLeg(self, second, a3, t0);
    return result;
}
static inline void merge_flush_func_001D0C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D0C80 */
