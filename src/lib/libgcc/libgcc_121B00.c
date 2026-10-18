/*
 * lib/libgcc: 4 files, 00121B00-00121B48
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00121B00 */
#include "types.h"

extern int func_0011DDA8(float);

int func_00121B00(float f12) {
    return func_0011DDA8(f12);
}
/* merge_units: end func_00121B00 */

/* merge_units: begin func_00121B18 */
extern int func_0011E088(float);

int func_00121B18(float f12) {
    return func_0011E088(f12);
}
/* merge_units: end func_00121B18 */

/* merge_units: begin func_00121B30 */
extern int Math_PowfKernel(float, float);

int Math_Powf(float f12, float f13) {
    return Math_PowfKernel(f12, f13);
}
/* merge_units: end func_00121B30 */

/* merge_units: begin func_00121B48 */
extern int Math_Sqrtf(float);

int func_00121B48(float f12) {
    return Math_Sqrtf(f12);
}
/* merge_units: end func_00121B48 */
