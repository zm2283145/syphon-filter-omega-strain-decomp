/*
 * SFOGame/Source/GuiWeaponDisplay: 1 file, 00440550
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00440550 */
#pragma push /* merge_units */
#include "types.h"

int D_004C0420 = 0x57697547;
extern int strcmp(void*);

/* Returns whether strcmp(&D_004C0420) returned 0. */
int GuiWeaponDisplay_IsClass(void) {
    return strcmp(&D_004C0420) == 0;
}
static inline void merge_flush_func_00440550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00440550 */
