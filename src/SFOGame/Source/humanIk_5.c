/*
 * SFOGame/Source/humanIk: 1 file, 001CEA20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001CEA20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* True when byte +0x380 is clear and byte +0x381 is set. */
int cHandIkTargetList_HasTransitionJustEndedForBothHands(Unk001CEA20* self) {
    int v0;

    v0 = (self->unk380 != 0) ^ 1;
    if (v0 != 0) {
        v0 = self->unk381 != 0;
    }
    return v0;
}

/* Store a byte and whether it is non-zero. */
void cDrawAndHolsterWeapon_ActionManager_SwitchStage(ByteBool* self, int value) {
    self->value = value;
    self->nonZero = (value & 255) != 0;
}
static inline void merge_flush_func_001CEA20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CEA20 */
