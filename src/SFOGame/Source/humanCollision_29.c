/*
 * SFOGame/Source/humanCollision: 5 files, 001EC1C0-001EC580
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EC1C0 */
#pragma push /* merge_units */
/* cHumanCollisionRoutine_cFinalLedgeSearchInfo_ctor: ctor; function-local static identity placement D_00497F00 (guard D_004E1D80) copied via cQuatVec_ctor_cQuatVecR then lq/sq into place. */
#pragma cplusplus on
#pragma exceptions off
struct V4c {
    float x, y, z, w;
    V4c& operator=(const V4c& o) { const V4c* s = &o; V4c* d = this; __int128 t; asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Pair { V4c a; V4c b; Pair() {} Pair(const Pair& o); };
struct T {
    unsigned char b0, b1, b2;
    char p3[0x3D];
    unsigned char b40;
    char p41[0x1F];
    int i60;
    int i64;
    int i68;
    char p6C[4];
    int a70[1];
    int i74;
    char p78[8];
    Pair place;
};
extern "C" {
extern signed char D_004E1D80;
extern Pair D_00497F00;
Pair* cQuatVec_ctor_cQuaternionR_cVectorR(Pair* p, const V4c* a, const V4c* b);
Pair* cQuatVec_ctor_cQuatVecR(Pair* d, const Pair* s);
V4c cVector_Get0001(void);
V4c cQuaternion_GetIdentity(void);
}
static inline const Pair& IdentPl(void)
{
    if (!D_004E1D80) {
        cQuatVec_ctor_cQuaternionR_cVectorR(&D_00497F00, &cQuaternion_GetIdentity(), &cVector_Get0001());
        D_004E1D80 = 1;
    }
    return D_00497F00;
}
extern "C" T* cHumanCollisionRoutine_cFinalLedgeSearchInfo_ctor(T* p)
{
    int i;
    p->b0 = 0;
    p->b1 = 0;
    p->b2 = 0;
    p->b40 = 0;
    p->i60 = -1;
    p->i64 = -1;
    p->i68 = 0;
    for (i = 0; i < 1; i++) p->a70[i] = 0;
    p->i74 = 0;
    {
        Pair pl;
        IdentPl();
        cQuatVec_ctor_cQuatVecR(&pl, &D_00497F00);
        p->place.a = pl.a;
        p->place.b = pl.b;
    }
    return p;
}
static inline void merge_flush_func_001EC1C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EC1C0 */

/* merge_units: begin func_001EC2A0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float mass; float invMass; } PhysMass_b6;
void cPointMass_SetMass(PhysMass_b6* p, float m)
{
    if (m == -1.0f || m > 0.0f) {
        float inv;
        p->mass = m;
        if (m == -1.0f) {
            inv = 0.0f;
        } else {
            inv = 1.0f / m;
        }
        p->invMass = inv;
    }
}
static inline void merge_flush_func_001EC2A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EC2A0 */

/* merge_units: begin func_001EC310 */
#pragma push /* merge_units */
int func_001EC310(int a0, int a1) {
    int v0, v1;
    int cond;

    v1 = a1 & 255;
    v0 = 0 + 1;
    cond = v1 != v0;
    v0 = 0 + -1;
    if (cond) goto L001EC328;
    *(int*)(char*)a0 = v0;
    goto L001EC330;
L001EC328:;
    *(int*)(char*)a0 = 0;
L001EC330:;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_001EC310(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EC310 */

/* merge_units: begin func_001EC340 */
#pragma push /* merge_units */
#include "prio_bitset.h"
PB_DEFINE(PS_1EC340, 1)
#pragma opt_rotateloops off
PS_1EC340* cModeSwitch_12_ctor_uint(PS_1EC340* p, int v)
{
    int i;
    p->w[0] = 0;
    PS_1EC340_Set(p, 0);
    for (i = 1; i < 13; i++) PS_1EC340_Clr(p, i);
    PS_1EC340_Set(p, v);
    PB_FIND_TOP(PS_1EC340, p, i, 13)
    return p;
}
#pragma opt_rotateloops reset
static inline void merge_flush_func_001EC340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EC340 */

/* merge_units: begin func_001EC580 */
#pragma push /* merge_units */
/* ActorPhys_AuxiliaryProbe: two short downward sphere probes (at the given
 * point and at a point offset from the root by its orientation); each flag
 * pair is (enabled, hit within the step height of the reference height). */
#pragma cplusplus on
#pragma inline_depth(8)
#pragma always_inline on
/* lq/sq and VU0 ops: no C equivalent (asm). */
static inline void Add_(void* d, const void* o) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(d), "r"(o) : "memory"); }
static inline void Add2_(void* d, const void* o) { Add_(d, o); }
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4(const V4& o) { const V4* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(this) } }
    V4& Rotate(const V4& q) { __asm__ volatile("lqc2 vf1, 0x0(%0); vmove.w vf6, vf1; vmr32.w vf1, vf0; lqc2 vf2, 0x0(%1); vmove.w vf3, vf2; vsub.xyz vf3, vf0, vf2; vmul.xyzw vf4, vf2, vf1; vopmula.xyz ACC, vf2, vf1; vmaddaw.xyz ACC, vf1, vf2w; vopmsub.xyz vf5, vf1, vf2; vsubaz.w ACC, vf4, vf4z; vmsubay.w ACC, vf0, vf4y; vmsubx.w vf5, vf0, vf4x; vopmula.xyz ACC, vf5, vf3; vmaddaw.xyz ACC, vf5, vf3w; vmaddaw.xyz ACC, vf3, vf5w; vopmsub.xyz vf6, vf3, vf5; sqc2 vf6, 0x0(%0)" : : "r"(this), "r"(&q) : "memory"); return *this; }
    void Add3(const V4& o) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(this), "r"(&o) : "memory"); }
    V4 operator*(float k) const;
    void AddP(V4 o) { const void* po = &o; Add2_(this, po); float* pw = &w; *pw = o.w; }
} __attribute__((aligned(16)));
static inline void ScaleTo(V4* d, const V4* s, float k) { int r; V4* dd = d; asm {
        .set noreorder
        lqc2 vf1, 0x0(s)
        mfc1 r, k
        qmtc2.ni r, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(dd)
        .set reorder
    } }
inline V4 V4::operator*(float k) const { V4 t; ScaleTo(&t, this, k); return t; }
static inline V4* TransformPoint(V4* pp, const V4* q, const V4* pos)
{
    V4& p = *pp;
    p.Rotate(*q);
    float* w = &p.w;
    float wv = *w;
    if (wv == 1.0f) {
        p.Add3(*pos);
    } else {
        p.AddP(*pos * wv);
    }
    return pp;
}
struct Res { unsigned char hit; char p1[0x57]; float f58; char p5C[0x110 - 0x5C]; unsigned char b110; char p111[0x1E0 - 0x111]; };
struct Probe { unsigned char on; unsigned char hit; void Run(void* filter, V4* pos, float z); };
struct Probes { Probe a; Probe b; };
struct Plc { V4 quat; V4 pos; V4* Transform(V4* v); };
extern "C" {
extern float D_004A0358;
void cCollisionProbe_SphereSweptRay_ctor(Res*);
void cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(Res*, void*, V4*, V4*, float, float, float, float, float, int);
int ColQuery_ExecuteThunk(Res*, int, int);
Plc* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* r);
V4* cQuatVec_Translation(Plc* p);
/* wrappers: the local pointer copies keep the probe/position addresses in registers as retail */
static inline void RunB(Probe* p, void* f, V4* pos, float z) { Probe* q = p; q->Run(f, pos, z); }
void ActorPhys_AuxiliaryProbe(Probes* self, void* filter, V4* pos, void* root, float z);
}
static inline V4* XformP(V4* v, Plc* pl) { const V4* pos = &pl->pos; return TransformPoint(v, &pl->quat, pos); }
inline void Probe::Run(void* filter, V4* pos, float z)
{
    hit = 0;
    if (on) {
        Res r;
        cCollisionProbe_SphereSweptRay_ctor(&r);
        cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(&r, filter, pos, &V4(0.0f, 0.0f, D_004A0358, 0.0f), 0.1f, 0.05f, 0.05f, 0.0f, 0.1f, 0);
        r.b110 = 0;
        ColQuery_ExecuteThunk(&r, 0, 128);
        if (r.hit && r.f58 - z <= D_004A0358)
            hit = 1;
    }
    on = 0;
}

void ActorPhys_AuxiliaryProbe(Probes* self, void* filter, V4* pos, void* root, float z)
{
    RunB(&self->a, filter, pos, z);
    {
        V4 p2 = *XformP(&V4(0.0f, 0.35f, 0.7f, 1.0f), cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(root));
        RunB(&self->b, filter, &p2, cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(root))->z);
    }
}
static inline void merge_flush_func_001EC580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EC580 */
