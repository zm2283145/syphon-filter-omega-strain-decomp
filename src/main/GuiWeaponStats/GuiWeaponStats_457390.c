/*
 * main/GuiWeaponStats: 2 files, 00457390-004573C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00457390 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the string "GuiBriefingPane". */
int GuiBriefingPane_IsType(void* self, const char* name)
{
    return strcmp("GuiBriefingPane", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00457390 */

/* merge_units: begin func_004573C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(GuiStartMenu_dtor, D_004E1430, D_004DF5C0, GuiWidget_Destroy)
#pragma pop /* merge_units */
/* merge_units: end func_004573C0 */
