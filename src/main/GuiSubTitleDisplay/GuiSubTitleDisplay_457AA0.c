/*
 * main/GuiSubTitleDisplay: range (2 files, 00457AA0-00457AB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int strcmp(const void *, const void *);

/* merge_units: begin func_00457AA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiSubTitleDisplay.cc. Functions are named by address
 * until real names are known.
 */



int func_00457AA0(void) {
    return (int)"GuiSubTitleDisplay";
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00457AA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00457AA0 */

/* merge_units: begin func_00457AB0 */
#pragma push /* merge_units */
char D_004C1FB0[] = "GuiSubTitleDisplay"; /* "GuiSubTitleDisplay" */

/* GuiSubTitleDisplay type check: true when name equals the class name "GuiSubTitleDisplay". */
int GuiSubTitleDisplay_IsType(void* self, const char* name) {
    return strcmp(D_004C1FB0, name) == 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00457AB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00457AB0 */
