/*
 * main/GuiOnlineConnect: 3 files, 0029CB50-0029CB90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0029CB50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004AADC0[] = "GuiOnlineConnect";   /* "GuiOnlineConnect" */

/* Class name getter: "GuiOnlineConnect". */
char* GuiOnlineConnect_GetClassName(void) {
    return D_004AADC0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0029CB50 */

/* merge_units: begin func_0029CB60 */
#pragma push /* merge_units */
extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiOnlineConnect". */
int func_0029CB60(void* self, const char* name)
{
    return strcmp("GuiOnlineConnect", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0029CB60 */

/* merge_units: begin func_0029CB90 */
#pragma push /* merge_units */
void func_0029CB90(void) {
}

void func_0029CBA0(void) {
}
#pragma pop /* merge_units */
/* merge_units: end func_0029CB90 */
