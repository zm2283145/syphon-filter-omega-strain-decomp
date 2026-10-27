/* ActorPhys_AuxiliaryProbe: two short downward sphere probes (at the given
 * point and at a point offset from the root by its orientation); each flag
 * pair is (enabled, hit within the step height of the reference height). */
#pragma cplusplus on
#pragma inline_depth(8)
#pragma always_inline on
#include "types.h"
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
