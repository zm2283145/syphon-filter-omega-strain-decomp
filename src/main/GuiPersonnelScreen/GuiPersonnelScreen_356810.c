/*
 * main/GuiPersonnelScreen: 2 files, 00356810-00356820
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00356810 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiPersonnelScreen class-name getter (vtable D_004DF0B0 slot 19).
 */

#include "loose03_types.h"

char D_004BB430[] = "GuiPersonnelScreen";       /* "GuiPersonnelScreen" */

/* Returns the class name string "GuiPersonnelScreen". */
const char* GuiPersonnelScreen_GetClassName(void) {
    return D_004BB430;
}
#pragma pop /* merge_units */
/* merge_units: end func_00356810 */

/* merge_units: begin func_00356820 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the class name string "GuiPersonnelScreen". */
int GuiPersonnelScreen_IsType(void* self, const char* name)
{
    return strcmp("GuiPersonnelScreen", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00356820 */
