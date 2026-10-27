/*
 * Libs/SFOLib/Source/gui: 1 file, 00414A50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00414A50 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the class name string "GuiCanvas". */
int GuiCanvas_IsType(void* self, const char* name)
{
    return strcmp("GuiCanvas", name) == 0;
}
static inline void merge_flush_func_00414A50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00414A50 */
