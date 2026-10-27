/*
 * SFOGame/Source/humanIk: 3 files, 001D3A60-001D3AC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D3A60 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma opt_common_subs off
V4 func_001D3A60(V4* b) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        lqc2 vf1, 0x0(b)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0x0(q1)
    }
    return l0;
}
#pragma pop
static inline void merge_flush_func_001D3A60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D3A60 */

/* merge_units: begin func_001D3A90 */
#pragma push /* merge_units */
/* Retail computes each quadword address separately (peephole pass off). */
#pragma peephole off

typedef struct { Vec4 a; Vec4 b; Vec4 c; } Vec4x3;

/* Copies three consecutive vectors out to three destinations. */
void func_001D3A90(Vec4x3* src, Vec4* a, Vec4* b, Vec4* c)
{
    *a = src->a;
    *b = src->b;
    *c = src->c;
}
static inline void merge_flush_func_001D3A90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D3A90 */

/* merge_units: begin func_001D3AC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* func_001D3AC0(char* self) {
    return self + 32;
}
static inline void merge_flush_func_001D3AC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D3AC0 */
