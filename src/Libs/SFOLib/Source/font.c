/*
 * Libs/SFOLib/Source/font: 2 files, 0036A2F0-0036A300
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036A2F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Return the resource's byte-sized row-height metric through the integer ABI. */
unsigned int cFont_GetCharH(unsigned char* self) {
    return self[153];
}
static inline void merge_flush_func_0036A2F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036A2F0 */

/* merge_units: begin func_0036A300 */
#pragma push /* merge_units */
extern void cFont_Display_charP_tRGBAR_float_float_etc(int a0, int a1, int a2, float x, float y, float z, float p, float q, float r);
void cFont_Display_charP_tRGBAR_int_int_etc(int a0, int a1, int a2, int ix, int iy, float z) {
    cFont_Display_charP_tRGBAR_float_float_etc(a0, a1, a2, (float)ix, (float)iy, z, 0.0f, 0.0f, 0.0f);
}
static inline void merge_flush_func_0036A300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036A300 */
