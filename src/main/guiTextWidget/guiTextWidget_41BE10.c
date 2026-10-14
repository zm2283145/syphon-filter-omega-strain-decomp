/*
 * main/guiTextWidget: range (2 files, 0041BE10-0041BE20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int strcmp(const void *, const void *);

/* merge_units: begin func_0041BE10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiTextWidget.cc. Functions are named by address
 * until real names are known.
 */



int func_0041BE10(void) {
    return (int)"GuiTextWidget";
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0041BE10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0041BE10 */

/* merge_units: begin func_0041BE20 */
#pragma push /* merge_units */
char D_004BF3A8[] = "GuiTextWidget"; /* "GuiTextWidget" */

/* GuiTextWidget type check: true when name equals the class name "GuiTextWidget". */
int GuiTextWidget_IsType(void* self, const char* name) {
    return strcmp(D_004BF3A8, name) == 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0041BE20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0041BE20 */
