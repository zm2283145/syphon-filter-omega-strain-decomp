/*
 * main/GuiSaveAgentWidget: 2 files, 002927E0-002927F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002927E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004A9E30[] = "GuiAgentSave";   /* "GuiAgentSave" */

/* Class name getter: "GuiAgentSave". */
char* GuiAgentSave_GetClassName(void) {
    return D_004A9E30;
}
#pragma pop /* merge_units */
/* merge_units: end func_002927E0 */

/* merge_units: begin func_002927F0 */
#pragma push /* merge_units */
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiAgentSave". */
int GuiAgentSave_IsClass(void)
{
    return strcmp("GuiAgentSave") == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002927F0 */
