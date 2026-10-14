/*
 * main/human: range (3 files, 001906B0-00190750)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#include "types.h"

/* merge_units: begin func_001906B0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_001906B0)
#pragma pop /* merge_units */
/* merge_units: end func_001906B0 */

/* merge_units: begin func_00190700 */
#pragma push /* merge_units */
/* Animation sample assignment: implicit member-wise operator= (byte id + four lq/sq quad copies). */
#pragma cplusplus on
struct V {
    float x, y, z, w;
    V() {}
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct Sample {
    unsigned char id;
    V v[4];
};
extern "C" Sample* Anim_CopySample(Sample* d, const Sample* s)
{
    *d = *s; return d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190700(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190700 */

/* merge_units: begin func_00190750 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma opt_common_subs off
V4 Anim_ApproachTarget(V4* b, V4* c, float s) {
    V4 l0;
    V4* q1 = &l0;
    int rv1;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        mfc1 rv1, s
        qmtc2.ni rv1, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddax.xyzw ACC, vf2, vf3x
        vmsubx.xyzw vf4, vf1, vf3x
        vmul.xyzw vf5, vf4, vf4
        vmulax.w ACC, vf0, vf5x
        vmadday.w ACC, vf0, vf5y
        vmaddaz.w ACC, vf0, vf5z
        vmaddw.w vf6, vf0, vf5w
        vrsqrt Q, vf0w, vf6w
        vwaitq 
        vmulq.xyzw vf7, vf4, Q
        sqc2 vf7, 0x0(q1)
    }
    return l0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190750(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190750 */
