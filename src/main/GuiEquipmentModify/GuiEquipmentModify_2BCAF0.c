/*
 * main/GuiEquipmentModify: 2 files, 002BCAF0-002BCB20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002BCAF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004AC7F0[] = "GuiEquipmentModify";   /* "GuiEquipmentModify" */
extern int func_0027C4D8(void);

int func_002BCAF0(void) {
    func_0027C4D8();
    return 0;
}

/* Class name getter: "GuiEquipmentModify". */
char* GuiEquipmentModify_GetClassName(void) {
    return D_004AC7F0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002BCAF0 */

/* merge_units: begin func_002BCB20 */
#pragma push /* merge_units */
/* "GuiEquipmentModify" */
/* strcmp */
extern int strcmp(const char* a, const char* b);

/* GuiEquipmentModify::IsA: returns 1 if the given class name is "GuiEquipmentModify". */
int GuiEquipmentModify_IsType(void* self, const char* name)
{
    return strcmp("GuiEquipmentModify", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002BCB20 */
