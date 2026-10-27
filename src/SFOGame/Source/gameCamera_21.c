/*
 * SFOGame/Source/gameCamera: 1 file, 0017F860
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017F860 */
#pragma push /* merge_units */
#include "types.h"
unsigned int D_004A3FD8[2] = { 0x0, 0x0 };
extern float Libc_Atanf(float);
/* Returns 2 * f(1 / (x * scale)). */
float func_0017F860(float x) { return 2.0f * Libc_Atanf(1.0f / (x * (*(float*)D_004A3FD8))); }
static inline void merge_flush_func_0017F860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017F860 */
