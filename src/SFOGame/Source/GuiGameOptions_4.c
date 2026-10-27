/*
 * SFOGame/Source/GuiGameOptions: 1 file, 002996A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002996A0 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the class name string "GuiGameOptions". */
int GuiGameOptions_IsClass(void* self, const char* name)
{
    return strcmp("GuiGameOptions", name) == 0;
}
static inline void merge_flush_func_002996A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002996A0 */
