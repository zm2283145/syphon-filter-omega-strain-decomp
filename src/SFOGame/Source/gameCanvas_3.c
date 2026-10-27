/*
 * SFOGame/Source/gameCanvas: 1 file, 00464CF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiGameScreen_464CF0 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiGameCanvas". */
int GuiGameCanvas_IsClass(void* self, const char* name)
{
    return strcmp("GuiGameCanvas", name) == 0;
}
static inline void merge_flush_GuiGameScreen_464CF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiGameScreen_464CF0 */
