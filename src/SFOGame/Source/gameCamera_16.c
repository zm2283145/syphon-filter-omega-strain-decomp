/*
 * SFOGame/Source/gameCamera: 3 files, 0017F3D0-0017F460
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017F3D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

typedef struct CurveBinding {
    int curve;
    int unk4;
} CurveBinding;

/* Binds a curve and clears the second word. */
CurveBinding* cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_ctor(CurveBinding* b, int curve) {
    b->curve = curve;
    b->unk4 = 0;
    return b;
}
static inline void merge_flush_func_0017F3D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017F3D0 */

/* merge_units: begin func_0017F3E0 */
#pragma push /* merge_units */
#pragma cplusplus on
inline void* operator new(unsigned int, void* p) { return p; }
struct Key_F3E0 { float v; float s; Key_F3E0() {} };
struct Crv_F3E0 { Key_F3E0 k[2]; float dur; float inv; };
/* constant curve: both keys = (*a, *b * dur), store duration and its inverse */
#pragma push
#pragma opt_unroll_loops off
extern "C" Crv_F3E0* cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_float(Crv_F3E0* c, float* a, float* b, float dur)
{
    float va = *a; float vs = *b * dur;
    { Key_F3E0* e = c->k; do { new (e) Key_F3E0; } while (++e != c->k + 2); }
    c->k[0].v = va;
    c->k[0].s = vs;
    c->k[1].v = va;
    c->k[1].s = vs;
    c->dur = dur;
    c->inv = (dur != 0.0f) ? 1.0f / dur : 0.0f;
    return c;
}
#pragma pop
static inline void merge_flush_func_0017F3E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017F3E0 */

/* merge_units: begin func_0017F460 */
#pragma push /* merge_units */
typedef struct { Vec4 a; Vec4 b; } VecPair;
/* Builds a vector pair from two vectors. */
#pragma peephole off
VecPair* cQuatVec_ctor_cQuaternionR_cVectorR(VecPair* p, Vec4* a, Vec4* b) { p->a = *a; p->b = *b; return p; }
#pragma peephole reset
static inline void merge_flush_func_0017F460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017F460 */
