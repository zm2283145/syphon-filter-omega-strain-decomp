/*
 * SFOGame/Source/GuiStartMenu: 1 file, 00457250
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00457250 */
#pragma push /* merge_units */
#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiEquipmentPane" yields null. */
int GuiEquipmentPane_IsClass(void) {
    return strcmp("GuiEquipmentPane") == 0;
}
static inline void merge_flush_func_00457250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00457250 */
