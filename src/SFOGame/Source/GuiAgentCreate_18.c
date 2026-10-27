/*
 * SFOGame/Source/GuiAgentCreate: 1 file, 00291C30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiSaveAgentWidget_291C30 */
#pragma push /* merge_units */
#include "types.h"
extern void cSplinedMotion_Scalar0To1_opAssign(void* p, int x);
void func_00291C30(char* p, int n, int x)
{
    for (; n != 0; n--) {
        cSplinedMotion_Scalar0To1_opAssign(p, x);
        p += 0x3C;
    }
}
static inline void merge_flush_GuiSaveAgentWidget_291C30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiSaveAgentWidget_291C30 */
