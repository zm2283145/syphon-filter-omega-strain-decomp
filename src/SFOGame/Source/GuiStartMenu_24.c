/*
 * SFOGame/Source/GuiStartMenu: 2 files, 004572E0-004572F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004572E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after SFOLobby_Main.cc (ends 0x004534A0),
 * before GuiSubTitleDisplay.cc (starts 0x00457AA0).
 */

#include "types.h"


char* GuiWeaponStats_GetClassName(void) {
    return "GuiWeaponStats";
}
static inline void merge_flush_func_004572E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004572E0 */

/* merge_units: begin GuiWeaponStats_4572F0 */
#pragma push /* merge_units */
char D_004C1D78[] = "GuiWeaponStats"; /* "GuiWeaponStats" */
extern int strcmp(const char* a, const char* b); /* strcmp */

/* GuiWeaponStats::IsA: returns 1 if the given class name is "GuiWeaponStats". */
int GuiWeaponStats_IsClass(void* self, const char* name)
{
    return strcmp(D_004C1D78, name) == 0;
}
static inline void merge_flush_GuiWeaponStats_4572F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiWeaponStats_4572F0 */
