/*
 * SFOGame/Source/GuiEquipmentModify: 1 file, 002C3840
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiEquipmentModify_2C3840 */
#pragma push /* merge_units */
#include "types.h"
extern void cSplinedMotion_Scalar0To1_opAssign(void* p, int a);
void func_002C3840(char* p, int n, int a)
{
    while (n != 0) {
        cSplinedMotion_Scalar0To1_opAssign(p, a);
        n--;
        p += 0x3C;
    }
}
static inline void merge_flush_GuiEquipmentModify_2C3840(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiEquipmentModify_2C3840 */
