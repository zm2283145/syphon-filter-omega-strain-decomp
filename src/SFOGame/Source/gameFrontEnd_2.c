/*
 * SFOGame/Source/gameFrontEnd: 1 file, 002C9020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C9020 */
#pragma push /* merge_units */
#include "types.h"
static const unsigned int dat_0048C290[8] = { 0x1, 0x3, 0x5, 0x8, 0xB, 0x0, 0x0, 0x0 };
int cGameFrontEnd_GetConvertedWeaponFireRate(int x)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (x > ((int*)dat_0048C290)[i]) continue;
        return i + 1;
    }
    return 5;
}
static inline void merge_flush_func_002C9020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C9020 */
