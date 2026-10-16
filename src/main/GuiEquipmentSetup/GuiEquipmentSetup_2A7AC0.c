/*
 * main/GuiEquipmentSetup: 2 files, 002A7AC0-002A7AD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A7AC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004AB618[] = "GuiMessageBox";   /* "GuiMessageBox" */

/* Class name getter: "GuiMessageBox". */
char* func_002A7AC0(void) {
    return D_004AB618;
}
#pragma pop /* merge_units */
/* merge_units: end func_002A7AC0 */

/* merge_units: begin func_002A7AD0 */
#pragma push /* merge_units */
extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiMessageBox" yields null. */
int func_002A7AD0(void) {
    return strcmp("GuiMessageBox") == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002A7AD0 */
