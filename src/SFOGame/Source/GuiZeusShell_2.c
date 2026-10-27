/*
 * SFOGame/Source/GuiZeusShell: 2 files, 002B0C10-002B0C20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B0C10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004ABE98[] = "GuiZeusShell";   /* "GuiZeusShell" */

/* Class name getter: "GuiZeusShell". */
char* GuiZeusShell_GetClassName(void) {
    return D_004ABE98;
}
static inline void merge_flush_func_002B0C10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B0C10 */

/* merge_units: begin func_002B0C20 */
#pragma push /* merge_units */
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiZeusShell". */
int GuiZeusShell_IsClass(void)
{
    return strcmp("GuiZeusShell") == 0;
}
static inline void merge_flush_func_002B0C20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B0C20 */
