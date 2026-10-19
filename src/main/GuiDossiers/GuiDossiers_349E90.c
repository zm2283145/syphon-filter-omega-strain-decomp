/*
 * main/GuiDossiers: 2 files, 00349E90-00349EA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00349E90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiDossiers class-name getter (vtable D_004DEC30 slot 19).
 */

#include "loose03_types.h"

char D_004BA650[] = "GuiDossiers";       /* "GuiDossiers" */

/* Returns the class name string "GuiDossiers". */
const char* GuiDossiers_GetClassName(void) {
    return D_004BA650;
}
#pragma pop /* merge_units */
/* merge_units: end func_00349E90 */

/* merge_units: begin func_00349EA0 */
#pragma push /* merge_units */
#include "types.h"
extern int strcmp(void* p);
/* Returns whether the test on the global object fails. */
int GuiDossiers_IsType(void) { return strcmp("GuiDossiers") == 0; }
#pragma pop /* merge_units */
/* merge_units: end func_00349EA0 */
