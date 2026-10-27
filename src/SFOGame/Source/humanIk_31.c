/*
 * SFOGame/Source/humanIk: 1 file, 001D8500
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D8500 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct V {
    float x, y, z, w;
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct VP { V a; V b; };
struct Curve8500 { void* vt; char pad4[0xBC]; unsigned char bC0; char padC1[0xD0 - 0xC1]; };
struct VCurve8500 { void* vt; char pad4[0xB8 - 4]; };
struct O8500 { V p0; V p10; signed char b20; char pad21[0xF]; Curve8500 curve; VCurve8500 vc; };
extern "C" {
extern signed char D_004E1D80;
extern VP D_00497F00;
extern char D_004DA440[];
extern char D_004DA410[];
void cQuaternion_GetIdentity(V* q);
void cVector_Get0001(V* v);
void cQuatVec_ctor_cQuaternionR_cVectorR(VP* p, V* q, V* v);
void cQuatVec_ctor_cQuatVecR(VP* d, VP* s);
void cQuaternion_GetZero(V* v);
void cSplinedMotion_cQuaternion_ctor(Curve8500* c, V* q, V* v);
V* cVector_GetZero(void);
void cSplinedMotion_cVector_ctor(VCurve8500* c, V* a, V* b);
O8500* cIkTargetWithSplinedTransition_ctor(O8500* o);
}
static inline const VP& IdentPl() { if (!D_004E1D80) { V q; V p; cQuaternion_GetIdentity(&q); cVector_Get0001(&p); cQuatVec_ctor_cQuaternionR_cVectorR(&D_00497F00, &q, &p); D_004E1D80 = 1; } return D_00497F00; }
#pragma opt_propagation off
static inline void CurveCtor(Curve8500* c)
{
    V q;
    V v;
    cQuaternion_GetIdentity(&q);
    cQuaternion_GetZero(&v);
    cSplinedMotion_cQuaternion_ctor(c, &q, &v);
    c->vt = D_004DA440;
    c->bC0 = 0;
}
static inline void VCurveCtor(VCurve8500* c)
{
    V z;
    cVector_Get0001(&z);
    cSplinedMotion_cVector_ctor(c, &z, cVector_GetZero());
    c->vt = D_004DA410;
}
static inline void CC(O8500* o) { Curve8500* c = &o->curve; CurveCtor(c); }
static inline void VC(O8500* o) { VCurve8500* vc = &o->vc; VCurveCtor(vc); }
O8500* cIkTargetWithSplinedTransition_ctor(O8500* o_)
{
    O8500* o; VP t;
    o = o_;
    IdentPl();
    cQuatVec_ctor_cQuatVecR(&t, &D_00497F00);
    o->p0 = t.a;
    o->p10 = t.b;
    o->b20 = -1;
    CC(o);
    VC(o);
    return o;
}
static inline void merge_flush_func_001D8500(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D8500 */
