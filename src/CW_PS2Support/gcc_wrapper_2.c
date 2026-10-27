/*
 * CW_PS2Support/gcc_wrapper: 1 file, 00100218
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00100218 */
#pragma push /* merge_units */
#include "types.h"

extern void Exit_2(int);

void Newlib_SysExit_Thunk(int a0) {
    Exit_2(a0);
}
static inline void merge_flush_func_00100218(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00100218 */
