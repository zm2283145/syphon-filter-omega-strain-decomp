/*
 * main/human: 3 files, 001BED50-001BEDC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001BED50 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int a[4]; float f; } T_001BED50;
typedef struct { T_001BED50* t; float v; } D_001BED50;
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Reset(D_001BED50* d, T_001BED50* t, float v) {
    d->t = t;
    if (v < 0.0f) v = t->f;
    d->v = v;
}
#pragma pop /* merge_units */
/* merge_units: end func_001BED50 */

/* merge_units: begin func_001BED70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose00_types.h"

float cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_GetTimeLeft(FloatPair* self) {
    return self->b;
}

/* Copy six floats. */
Float6* cHermiteSplineWithScaledDuration_float_opAssign(Float6* d, Float6* s) {
    d->f[0] = s->f[0];
    d->f[1] = s->f[1];
    d->f[2] = s->f[2];
    d->f[3] = s->f[3];
    d->f[4] = s->f[4];
    d->f[5] = s->f[5];
    return d;
}
#pragma pop /* merge_units */
/* merge_units: end func_001BED70 */

/* merge_units: begin func_001BEDC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_obj.h"

extern "C" { char D_0049ECF8[] = "allocator.hh"; }
DEFINE_VECTOR_INSERT_FILL_OBJ(AnimChannelVec_Grow, 0x3C, 0x199999, 0xCCCCC, D_0049E980, D_0049ECF8, 0x5C, Mem_PlacementNew, AnimChannel_CopyCtor, std_copy_backward_cSkaSliderValue_copy_backward, std_fill_n_cSkaSliderValue_int_fill_n, std_swap_vectordeleterR_vectordeleterR_9, std_vector_deleter_cSkaSliderValue_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001BEDC0 */
