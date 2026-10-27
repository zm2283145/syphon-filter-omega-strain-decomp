/*
 * SFOGame/Source/GuiStartMenu: 1 file, 004574E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiWeaponStats_4574E0 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiStartMenuBackdrop". */
int GuiStartMenuBackdrop_IsClass(void* self, const char* name)
{
    return strcmp("GuiStartMenuBackdrop", name) == 0;
}
static inline void merge_flush_GuiWeaponStats_4574E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiWeaponStats_4574E0 */
