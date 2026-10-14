/*
 * main/GuiSaveAgentWidget: 3 files, 00293920-00293960
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00293920 */
#pragma push /* merge_units */
#include "types.h"

/* "GuiSaveAgentWidget" */
/* strcmp */
extern int strcmp(const char* a, const char* b);

/* GuiSaveAgentWidget::IsA: returns 1 if the given class name is "GuiSaveAgentWidget". */
int GuiSaveAgentWidget_IsType(void* self, const char* name)
{
    return strcmp("GuiSaveAgentWidget", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00293920 */

/* merge_units: begin func_00293950 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int func_00293950(void) {
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00293950 */

/* merge_units: begin func_00293960 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_resize.h"

/* Resize a vector of 4-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem4, 4)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_00293960, Elem4, PtrVec_Insert, PtrVector_Erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_00293960 */
