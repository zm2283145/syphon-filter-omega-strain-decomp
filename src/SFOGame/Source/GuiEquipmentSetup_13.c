/*
 * SFOGame/Source/GuiEquipmentSetup: 1 file, 002A6400
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A6400 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x3C]; } E2A64;
extern void cSplinedMotion_Scalar0To1_opAssign(E2A64* e, int a);
void func_002A6400(E2A64* p, int n, int a)
{
    while (n != 0) {
        cSplinedMotion_Scalar0To1_opAssign(p, a);
        n--;
        p++;
    }
}
static inline void merge_flush_func_002A6400(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A6400 */
