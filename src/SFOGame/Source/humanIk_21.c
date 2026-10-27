/*
 * SFOGame/Source/humanIk: 2 files, 001D2BA0-001D2C00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D2BA0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
/* VU0 hand-scheduled block (MAC-flag test with branch-likely), emitted as written */
void nIk_NegateIfDotProductNegative(V4* a, V4* b) {
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf5, vf1, vf0w
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf3w
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni t, vi17
        andi t, t, 0x10
        beql t, zero, done
        nop
        sqc2 vf5, 0x0(a)
        nop
    done:
        .set reorder
    }
}
static inline void merge_flush_func_001D2BA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D2BA0 */

/* merge_units: begin func_001D2C00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cJointInfo_BoneSpaceToJointSpaceTransform(char* self) {
    return self + 32;
}
static inline void merge_flush_func_001D2C00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D2C00 */
