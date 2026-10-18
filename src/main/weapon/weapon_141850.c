/*
 * main/weapon: range (2 files, 00141850-00141870)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00141850 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; float f40; } FObj;

/* Returns 3 if the float at +0x40 truncates to 0, else 0. */
int GObj_GetLifeState(FObj* self)
{
    return (int)self->f40 ? 0 : 3;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00141850(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00141850 */

/* merge_units: begin func_00141870 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* WorldObjList_Get(void* self) {
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00141870(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00141870 */
