/*
 * main/GuiSaveAgentWidget: 5 files, 00293850-00293910
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00293850 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004A9E50[] = "GuiAgentLoad";   /* "GuiAgentLoad" */

/* Class name getter: "GuiAgentLoad". */
char* GuiAgentLoad_GetClassName(void) {
    return D_004A9E50;
}
#pragma pop /* merge_units */
/* merge_units: end func_00293850 */

/* merge_units: begin func_00293860 */
#pragma push /* merge_units */
extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiAgentLoad" yields null. */
int GuiAgentLoad_IsType(void) {
    return strcmp("GuiAgentLoad") == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00293860 */

/* merge_units: begin func_00293890 */
#pragma push /* merge_units */
void GuiSaveAgentWidget_SaveDone(void) {
}
#pragma pop /* merge_units */
/* merge_units: end func_00293890 */

/* merge_units: begin func_002938A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(GuiAgentDirectoryWidget_dtor, D_004DD460, D_004E1220, GuiWidget_Destroy)
#pragma pop /* merge_units */
/* merge_units: end func_002938A0 */

/* merge_units: begin func_00293910 */
#pragma push /* merge_units */
char D_004A9E70[] = "GuiSaveAgentWidget";   /* "GuiSaveAgentWidget" */

/* Class name getter: "GuiSaveAgentWidget". */
char* GuiSaveAgentWidget_GetClassName(void) {
    return D_004A9E70;
}
#pragma pop /* merge_units */
/* merge_units: end func_00293910 */
