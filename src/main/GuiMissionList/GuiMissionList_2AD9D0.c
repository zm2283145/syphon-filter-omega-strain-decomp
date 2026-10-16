/*
 * main/GuiMissionList: 2 files, 002AD9D0-002AD9E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002AD9D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004ABBD8[] = "GuiNetContacts";   /* "GuiNetContacts" */

/* Class name getter: "GuiNetContacts". */
char* func_002AD9D0(void) {
    return D_004ABBD8;
}
#pragma pop /* merge_units */
/* merge_units: end func_002AD9D0 */

/* merge_units: begin func_002AD9E0 */
#pragma push /* merge_units */
extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiNetContacts". */
int func_002AD9E0(void* self, const char* name)
{
    return strcmp("GuiNetContacts", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002AD9E0 */
