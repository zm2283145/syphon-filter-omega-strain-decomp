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
void Quat_SetIdentity(V* q);
void Vec4_SetOrigin(V* v);
void Placement_GetIdentity(VP* p, V* q, V* v);
void VecPair_Copy(VP* d, VP* s);
void cQuaternion_GetZero(V* v);
void CameraCurve_MakeQuaternion(Curve8500* c, V* q, V* v);
V* Vec4_GetZero(void);
void VecCurve_InitState(VCurve8500* c, V* a, V* b);
O8500* cIkTargetWithSplinedTransition_ctor(O8500* o);
}
static inline const VP& IdentPl() { if (!D_004E1D80) { V q; V p; Quat_SetIdentity(&q); Vec4_SetOrigin(&p); Placement_GetIdentity(&D_00497F00, &q, &p); D_004E1D80 = 1; } return D_00497F00; }
#pragma opt_propagation off
static inline void CurveCtor(Curve8500* c)
{
    V q;
    V v;
    Quat_SetIdentity(&q);
    cQuaternion_GetZero(&v);
    CameraCurve_MakeQuaternion(c, &q, &v);
    c->vt = D_004DA440;
    c->bC0 = 0;
}
static inline void VCurveCtor(VCurve8500* c)
{
    V z;
    Vec4_SetOrigin(&z);
    VecCurve_InitState(c, &z, Vec4_GetZero());
    c->vt = D_004DA410;
}
static inline void CC(O8500* o) { Curve8500* c = &o->curve; CurveCtor(c); }
static inline void VC(O8500* o) { VCurve8500* vc = &o->vc; VCurveCtor(vc); }
O8500* cIkTargetWithSplinedTransition_ctor(O8500* o_)
{
    O8500* o; VP t;
    o = o_;
    IdentPl();
    VecPair_Copy(&t, &D_00497F00);
    o->p0 = t.a;
    o->p10 = t.b;
    o->b20 = -1;
    CC(o);
    VC(o);
    return o;
}
