/*
 * main/GuiOnlineOfflineSelect: 2 files, 002A0D80-002A0D90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A0D80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004AB070[] = "GuiMissionSetup";   /* "GuiMissionSetup" */

/* Class name getter: "GuiMissionSetup". */
char* GuiMissionSetup_GetClassName(void) {
    return D_004AB070;
}
#pragma pop /* merge_units */
/* merge_units: end func_002A0D80 */

/* merge_units: begin func_002A0D90 */
#pragma push /* merge_units */
int D_004AB080 = 0x4D697547;
extern int strcmp(void*);

/* Returns whether strcmp(&D_004AB080) returned 0. */
int GuiMissionSetup_IsClass(void) {
    return strcmp(&D_004AB080) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002A0D90 */
