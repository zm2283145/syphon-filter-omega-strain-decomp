/*
 * main/GuiAgentInfo: 2 files, 003604D0-003604E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003604D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAgentInfo class-name getter (vtable GuiAgentInfo_vtable slot 19).
 */

#include "loose03_types.h"

char D_004BBC18[] = "GuiAgentInfo";       /* "GuiAgentInfo" */

/* Returns the class name string "GuiAgentInfo". */
const char* GuiAgentInfo_GetClassName(void) {
    return D_004BBC18;
}
#pragma pop /* merge_units */
/* merge_units: end func_003604D0 */

/* merge_units: begin func_003604E0 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiAgentInfo". */
int func_003604E0(void* self, const char* name)
{
    return strcmp("GuiAgentInfo", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003604E0 */
