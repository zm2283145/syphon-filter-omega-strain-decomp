/*
 * SFOGame/Source/gameCamera: 4 files, 0017EFC0-0017F0E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017EFC0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "nested_null_dtor.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable_chain_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

#pragma cplusplus on

DEFINE_NESTED_NULL_DTOR3(cArray_cVector_dtor, std_vector_deleter_cVector_dtor)
static inline void merge_flush_func_0017EFC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017EFC0 */

/* merge_units: begin func_0017F030 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR1(cCollisionRoutine_cBox_dtor_void_2, D_004DA330)
static inline void merge_flush_func_0017F030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017F030 */

/* merge_units: begin func_0017F080 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Derived destructor: restore vtable, run cGOBJ base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(cCAMERA_GOBJ_dtor, D_004DA470, cGOBJ_dtor)
static inline void merge_flush_func_0017F080(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017F080 */

/* merge_units: begin func_0017F0E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma peephole off
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
} __attribute__((aligned(16)));
struct VI_ { int x, y, z, w; } __attribute__((aligned(16)));
struct Curve_F0E0 {
    void* vt;
    char pad04[0xC];
    V v10;
    V v20;
    V v30;
    V v40;
    int f50;
    char pad54[0x60 - 0x54];
    char seg[0xB0 - 0x60];
    char bind[0x10];
};
extern "C" {
extern signed char D_004E1D88;
extern struct VI_ D_004E1D90;
extern void* const D_004DA3B0[];
extern char D_004DA410[];
void cVector_ctor_cVectorR(V* d, const V* s);
void cHermiteSplineWithScaledDuration_cVector_ctor_cVectorR_cVectorR_float(void* p, const V* a, const V* b, float f);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_ctor(void* b, void* target);
}

static inline const V& Zero() { if (!D_004E1D88) { D_004E1D90.x = 0; D_004E1D88 = 1; D_004E1D90.y = 0; D_004E1D90.z = 0; D_004E1D90.w = 0; } return *(const V*)&D_004E1D90; }
static inline V Unit() { V l0; V* q1 = &l0; asm { sqc2 vf0, 0x0(q1) } return l0; }
extern "C" Curve_F0E0* cSplinedMotion_Vector_ctor(Curve_F0E0* p)
{
    V u = Unit();
    const V* rr = &u; /* unused; reproduces retail dead addiu a0,&u */
    const V& z = Zero();
    p->vt = (void*)D_004DA3B0;
    cVector_ctor_cVectorR(&p->v10, &u);
    cVector_ctor_cVectorR(&p->v20, &u);
    cVector_ctor_cVectorR(&p->v30, &z);
    cVector_ctor_cVectorR(&p->v40, &u);
    p->f50 = 0;
    cHermiteSplineWithScaledDuration_cVector_ctor_cVectorR_cVectorR_float(p->seg, &u, &z, 0.0f);
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_ctor(p->bind, p->seg);
    p->vt = D_004DA410;
    return p;
}
static inline void merge_flush_func_0017F0E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017F0E0 */
