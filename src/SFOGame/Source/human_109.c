/*
 * SFOGame/Source/human: 2 files, 001B16C0-001B16E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B16C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

int cHuman_IsHoldingGun(Actor* actor) {
    return actor->unk3524->state != 6;
}
static inline void merge_flush_func_001B16C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B16C0 */

/* merge_units: begin func_001B16E0 */
#pragma push /* merge_units */
extern int cSKM_GOBJ_Render(int);

void cHuman_Render(int a0) {
    int v0, v1;
    int cond;

    v1 = *(int*)((char*)a0 + 13236);
    cond = v1 != 0;
    if (cond) goto L001B1700;
    v0 = cSKM_GOBJ_Render(a0);
L001B1700:;
    goto ret;
ret:;
}
static inline void merge_flush_func_001B16E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B16E0 */
