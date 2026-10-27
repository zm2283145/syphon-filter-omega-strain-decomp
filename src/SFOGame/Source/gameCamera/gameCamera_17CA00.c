/*
 * main/gameCamera: range (2 files, 0017CA00-0017CA90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop

/* merge_units: begin func_0017CA00 */
#pragma push /* merge_units */
#pragma cplusplus on
inline void* operator new(unsigned int, void* p) { return p; }
struct Key_CA00 { float v; float s; Key_CA00() {} };
struct Crv_CA00 { Key_CA00 k[2]; float dur; float inv; };
/* two-key curve: keys (*v0, *s0 * dur) and (*v1, *s1 * dur), duration and inverse */
#pragma push
#pragma opt_unroll_loops off
extern "C" Crv_CA00* cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(Crv_CA00* c, float* v0, float* s0, float* v1, float* s1, float dur)
{
    float vs0; float vs1;
    vs1 = *s1 * dur; vs0 = *s0 * dur;
    { Key_CA00* e = c->k; do { new (e) Key_CA00; } while (++e != c->k + 2); }
    c->k[0].v = *v0;
    c->k[0].s = vs0;
    c->k[1].v = *v1;
    c->k[1].s = vs1;
    c->dur = dur;
    c->inv = (dur != 0.0f) ? 1.0f / dur : 0.0f;
    return c;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017CA00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017CA00 */

/* merge_units: begin func_0017CA90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_0017CA90)
#pragma pop /* merge_units */
/* merge_units: end func_0017CA90 */
