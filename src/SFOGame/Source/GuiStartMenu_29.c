/*
 * SFOGame/Source/GuiStartMenu: 1 file, 00457440
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiWeaponStats_457440 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the class name string "GuiStartMenu". */
int GuiStartMenu_IsClass(void* self, const char* name)
{
    return strcmp("GuiStartMenu", name) == 0;
}
static inline void merge_flush_GuiWeaponStats_457440(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiWeaponStats_457440 */
