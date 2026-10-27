/*
 * SFOGame/Source/gameCamera: 3 files, 0017CA00-0017CAE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017CA00 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop

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
static inline void merge_flush_func_0017CA90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017CA90 */

/* merge_units: begin func_0017CAE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma peephole off
#pragma opt_propagation off
typedef Vec4 V4c;
class CamCAE0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual V4c GetTangent();
    char pad04[0x1C];
    V4c p20;
    V4c p30;
    V4c p40;
    char pad50[0x10];
    char sp60[0x40];
    float fA0;
};
extern "C" void cHermiteSplineWithScaledDuration_cVector_dtor(void*, int);
extern "C" void* opNew_uint_voidP(int, void*);
extern "C" void cHermiteSplineWithScaledDuration_cVector_ctor_cVectorR_cVectorR_cVectorR_cVectorR_etc(void*, V4c*, V4c*, V4c*, V4c*, float);
extern "C" void cSplinedMotion_cVector_ResetCurrValAndResetCurrVelocity(CamCAE0* c, V4c* a, V4c* b)
{
    V4c t;
    void* n;
    /* empty asm: emits nothing, only a scheduling barrier keeping the lq after addiu d */
    { V4c* d = &c->p20; asm { .set noreorder; .set reorder } *d = *a; }
    c->p30 = *b;
    t = c->GetTangent();
    cHermiteSplineWithScaledDuration_cVector_dtor(c->sp60, -1);
    n = opNew_uint_voidP(0x50, c->sp60);
    if (n) cHermiteSplineWithScaledDuration_cVector_ctor_cVectorR_cVectorR_cVectorR_cVectorR_etc(n, &c->p20, &c->p30, &c->p40, &t, c->fA0);
}
static inline void merge_flush_func_0017CAE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017CAE0 */
