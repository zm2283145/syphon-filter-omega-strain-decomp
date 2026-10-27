/*
 * main/GuiPersonnelMenu: 2 files, 00354980-00354990
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00354980 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiPersonnelMenu class-name getter (vtable D_004DF020 slot 19).
 */

#include "loose03_types.h"

char D_004BB200[] = "GuiPersonnelMenu";       /* "GuiPersonnelMenu" */

/* Returns the class name string "GuiPersonnelMenu". */
const char* GuiPersonnelMenu_GetClassName(void) {
    return D_004BB200;
}
#pragma pop /* merge_units */
/* merge_units: end func_00354980 */

/* merge_units: begin func_00354990 */
#pragma push /* merge_units */
#include "types.h"

/* "GuiPersonnelMenu" */
/* strcmp */
extern int strcmp(const char* a, const char* b);

/* GuiPersonnelMenu::IsA: returns 1 if the given class name is "GuiPersonnelMenu". */
int GuiPersonnelMenu_IsClass(void* self, const char* name)
{
    return strcmp("GuiPersonnelMenu", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00354990 */
