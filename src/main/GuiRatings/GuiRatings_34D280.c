/*
 * main/GuiRatings: range (2 files, 0034D280-0034D2B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int strcmp(const void *, const void *);

/* merge_units: begin func_0034D280 */
#pragma push /* merge_units */
/* Returns whether name equals the string "GuiRatings". */
int GuiRatings_IsType(void* self, const char* name)
{
    return strcmp("GuiRatings", name) == 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0034D280(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0034D280 */

/* merge_units: begin func_0034D2B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiRatings.cc. Functions are named by address
 * until real names are known.
 */


void func_0034D2B0(void) {
}

void func_0034D2C0(void) {
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0034D2B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0034D2B0 */
