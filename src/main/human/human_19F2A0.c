/*
 * main/human: range (2 files, 0019F2A0-0019F350)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "pp_quad_copy.h"
#include "vu0_ops.h"

/* merge_units: begin func_0019F2A0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
V4* cVector_InverseRotate_cMatrixR(V4* v, PPMtx* m)
{
    PPMtx t;
    PPMtx tmp;
    PPMtx* pm = &t;
    PPMtx* sw = &tmp;
    PPMtx* pd = &t;
    PPMtx* c1 = &tmp;
    float x;
    PP_COPY4(c1, m)
    x = sw->f[1]; sw->f[1] = sw->f[4]; sw->f[4] = x;
    x = sw->f[2]; sw->f[2] = sw->f[8]; sw->f[8] = x;
    x = sw->f[6]; sw->f[6] = sw->f[9]; sw->f[9] = x;
    PP_COPY4(pd, sw)
    VU0_ApplyMtx33(v, pm);
    return v;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019F2A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019F2A0 */

/* merge_units: begin func_0019F350 */
#pragma push /* merge_units */
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void cMatrix_GetTransformed(PPMtx* out, PPMtx* in, PPMtx* m) {
    PPMtx t;
    PPMtx* ps = &t;
    PPMtx* pd = &t;
    PP_COPY4(pd, in)
    VU0_MulRows44(ps, m);
    PP_COPY4(out, ps)
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019F350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019F350 */
