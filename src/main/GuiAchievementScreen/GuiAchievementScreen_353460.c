/*
 * main/GuiAchievementScreen: 2 files, 00353460-00353470
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00353460 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAchievementScreen class-name getter (vtable D_004DEF90 slot 19).
 */

#include "loose03_types.h"

char D_004BB050[] = "GuiAchievementScreen";       /* "GuiAchievementScreen" */

/* Returns the class name string "GuiAchievementScreen". */
const char* GuiAchievementScreen_GetClassName(void) {
    return D_004BB050;
}
#pragma pop /* merge_units */
/* merge_units: end func_00353460 */

/* merge_units: begin func_00353470 */
#pragma push /* merge_units */
#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiAchievementScreen" yields null. */
int func_00353470(void) {
    return strcmp("GuiAchievementScreen") == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00353470 */
