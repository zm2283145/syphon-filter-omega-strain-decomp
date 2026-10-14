/*
 * main/gameCamera: range (2 files, 001800A0-001800C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001800A0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4 func_001800A0(void) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        sqc2 vf0, 0x0(q1)
    }
    return l0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001800A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001800A0 */

/* merge_units: begin func_001800C0 */
#pragma push /* merge_units */
extern char D_004E1D88;
extern Vec4 D_004E1D90;
void VecCurve_ZeroDerivative(Vec4* out) {
    if (!D_004E1D88) {
        D_004E1D90.x = 0.0f;
        D_004E1D88 = 1;
        D_004E1D90.y = 0.0f;
        D_004E1D90.z = 0.0f;
        D_004E1D90.w = 0.0f;
    }
    *out = D_004E1D90;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001800C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001800C0 */
