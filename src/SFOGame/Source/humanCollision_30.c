/*
 * SFOGame/Source/humanCollision: 6 files, 001EC1C0-001EC850
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

/* merge_units: begin func_001EC850 */
#pragma push /* merge_units */
/* 001EC850 cHumanCollisionRoutine_cFinalLedgeSearchInfo_RecordResults -- cHumanCollisionRoutine::cFinalLedgeSearchInfo::RecordResults (humanCollision.cc). l5 match. */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

static inline void QS(const void* s, void* d) { Q16(d, s); }

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; Q16(d, &o); }
    V& operator=(const V& o) { Q16(this, &o); return *this; }
} __attribute__((aligned(16)));

struct M { float m[16]; M() {} M& Look(V* nd, V* axis); } __attribute__((aligned(16)));

struct Plc_001EC850 {
    V rot, pos;
    Plc_001EC850() {}
    Plc_001EC850(const V& p) : pos(p) {}
    Plc_001EC850(const V& p, int) { pos = p; }
    Plc_001EC850& operator=(const Plc_001EC850& o) { V* d = &rot; Q16(d, &o.rot); Q16(&pos, &o.pos); return *this; }
};

struct K { unsigned char v; };

struct Bits {
    int w[1];
    Bits& operator=(const Bits& o) { for (int i = 0; i < 1; i++) w[i] = o.w[i]; return *this; }
};

struct VA {
    float x, y, z, w;
    VA& operator=(const VA& o) { V* d = (V*)this; Q16(d, &o); return *this; }
} __attribute__((aligned(16)));

struct Desc {
    VA a;
    V b, c;
    K k;
    float f;
    V d, e;

};

struct Src {
    char pad0[0x32];
    unsigned char active;
    char pad33[0xD];
    Desc desc;
    Bits flags;
    char padA4[0xC];
    V dir;
    V tgt;
    V pos;
    char padE0[4];
    float fE4;
};

struct Pre {
    unsigned char enabled;
    char b1;
    unsigned char published;
    char pad3[0xD];
    Desc desc;
    Bits flags;
    float f74;
    char pad78[8];
    Plc_001EC850 plc;
};

struct PIt { int* p; };

extern "C" {
extern float D_004A0320;
void cArray_cEdgeGroup_Begin_void_2(PIt* out, void* c);
void cArray_cEdgeGroup_End_void_2(PIt* out, void* c);
int cArray_cEdgeGroup_ConstIterator_opNe(PIt* a, PIt* b);
void* cArray_cEdgeGroup_ConstIterator_opMul(PIt* it);
PIt* cArray_cEdgeGroup_ConstIterator_opInc(PIt* it);
int cEdgeGroup_IsEdgeInsideGroup(void* e, Desc* d);
int* std_vector_imp_cCollisionEdgePtr_1_begin(void* v);
int* std_vector_imp_cCollisionEdgePtr_1_end(void* v);

void cVector_opSub(V* out, V* a, V* b);
float cVector_Dot(V* a, V* b);
void cVector_Cross(V* out, V* a, V* b);
int cVector_IsZeroXYZ(V* v);
void cVector_GetNormalized_void(V* out, V* v);
V* cVector_Normalize_void(V* v);
V* cVector_ctor_cVectorR(V* d, V* s);
V* cVector_ctor_float_float_float_float(V* v, float x, float y, float z, float w);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M* m, V* a, V* b, V* c, V* t);
M* cMatrix_MakeLookAtMatrix_cVectorR(M* m, V* axis);
void cMatrix_SetUnit(M* m);
void cHumanCollisionRoutine_cFinalLedgeSearchInfo_RecordResults(Pre* o, Src* s, void* c);
}

static inline V Cross(const V& aa, const V& bb)
{
    V r;
    V* pr = &r;
    const V* a = &aa;
    const V* b = &bb;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf3, vf2, vf1
        vsubw.w vf3, vf0, vf0w
        sqc2 vf3, 0x0(pr)
    }
    return r;
}

static inline V Sub(const V& aa, const V& bb)
{
    V r;
    V* pr = &r;
    const V* a = &aa;
    const V* b = &bb;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(pr)
    }
    return r;
}

static inline V Add(const V& aa, const V& bb)
{
    V r;
    V* pr = &r;
    const V* a = &aa;
    const V* b = &bb;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(pr)
    }
    return r;
}

static inline V Mul(const V& aa, float k)
{
    V r;
    const V* a = &aa;
    V* pr = &r;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(a)
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(pr)
        .set reorder
    }
    return r;
}

static inline V Neg(const V& aa)
{
    V r;
    V* pr = &r;
    const V* a = &aa;
    asm {
        lqc2 vf1, 0x0(a)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0x0(pr)
    }
    return r;
}

static inline void NegTo(V* d, const V* a)
{
    asm {
        lqc2 vf1, 0x0(a)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0x0(d)
    }
}

static inline float Dot3(V* a, V* b)
{
    int rv0;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}

static inline void ToQuat(V* out, M* m)
{
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(m)
        lqc2 vf2, 0x10(m)
        lqc2 vf3, 0x20(m)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(out)
        .set reorder
    }
}

struct PI;
extern "C" PI std_vector_cCollisionEdgePtr_pointer2iterator(void* self, int* const& src);
struct PI {
    int* p;
    PI() {}
    PI(const PI& o) { p = o.p; }
    bool operator==(const PI& o) const { int* b = o.p; return p == b; }
    bool operator!=(const PI& o) const { return !(*this == o); }
};

static inline PI Begin(void* e)
{
    return std_vector_cCollisionEdgePtr_pointer2iterator(e, std_vector_imp_cCollisionEdgePtr_1_begin(e));
}

static inline PI End(void* e)
{
    return std_vector_cCollisionEdgePtr_pointer2iterator(e, std_vector_imp_cCollisionEdgePtr_1_end(e));
}

static inline void* Find(void* c, Desc* d)
{
    PIt it;
    PIt end;
    cArray_cEdgeGroup_Begin_void_2(&it, c);
    cArray_cEdgeGroup_End_void_2(&end, c);
    for (; cArray_cEdgeGroup_ConstIterator_opNe(&it, &end); cArray_cEdgeGroup_ConstIterator_opInc(&it)) {
        void* e = cArray_cEdgeGroup_ConstIterator_opMul(&it);
        if (cEdgeGroup_IsEdgeInsideGroup(e, d))
            return e;
    }
    return 0;
}

static inline M* Frame(M* mt, V* nd, V* axis)
{
    V cr;
    cVector_Cross(&cr, nd, axis);
    if (!cVector_IsZeroXYZ(&cr)) {
        V f;
        V r;
        V u;
        V w;
        cVector_GetNormalized_void(&f, nd);
        cVector_ctor_cVectorR(&r, cVector_Normalize_void(&cr));
        cVector_Cross(&u, &r, &f);
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(mt, &r, &f, &u, cVector_ctor_float_float_float_float(&w, 0.0f, 0.0f, 0.0f, 1.0f));
        return mt;
    } else if (!cVector_IsZeroXYZ(nd)) {
        return cMatrix_MakeLookAtMatrix_cVectorR(mt, nd);
    } else {
        cMatrix_SetUnit(mt);
        return mt;
    }
}

inline M& M::Look(V* nd, V* axis)
{
    V cr;
    cVector_Cross(&cr, nd, axis);
    if (!cVector_IsZeroXYZ(&cr)) {
        V f;
        V r;
        V u;
        V w;
        cVector_GetNormalized_void(&f, nd);
        cVector_ctor_cVectorR(&r, cVector_Normalize_void(&cr));
        cVector_Cross(&u, &r, &f);
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(this, &r, &f, &u, cVector_ctor_float_float_float_float(&w, 0.0f, 0.0f, 0.0f, 1.0f));
        return *this;
    } else if (!cVector_IsZeroXYZ(nd)) {
        return *cMatrix_MakeLookAtMatrix_cVectorR(this, nd);
    } else {
        cMatrix_SetUnit(this);
        return *this;
    }
}
#undef nd

static inline M* Frame8(M* mt, V* nd, V* axis)
{
    return Frame(mt, nd, axis);
}

static inline V MulI(V* tri, float k)
{
    return Mul(tri[4], k);
}

static inline void Orient8(V* q, const M& mt, V nd, V* axis)
{
    ToQuat(q, Frame8((M*)&mt, &nd, axis));
}

static inline V MulII(V* tri, float k)
{
    return MulI(tri, k);
}

static inline V NegW(const V& v)
{
    return Neg(v);
}

static inline int SJ(const V* p, V* t1, V* t0, V* n)
{
    V ea;
    V eb;
    cVector_opSub(&ea, t1, t0);
    cVector_opSub(&eb, (V*)p, t0);
    float d1 = cVector_Dot(&ea, n);
    float d2 = cVector_Dot(&eb, n);
    if (d1 < 0.0f) {
        d1 = -d1;
        d2 = -d2;
    }
    bool r; if (d2 >= 0.0f && d2 <= d1 && d1 != 0.0f) r = true; else r = false; return r;
}

static inline int SJR(const V& p, V* t1, V* t0, V* n)
{
    return SJ(&p, t1, t0, n);
}

static inline int SJR2(const V& p, V* t1, V* t0, V* n)
{
    return SJR(p, t1, t0, n);
}

static inline int SJd(V p, V* const& t1, V* t0, V* n)
{
    return SJR2(p, t1, t0, n);
}

static inline float DotD(V* aa, V* bb)
{
    V* a = aa;
    V* b = bb;
    int rv0;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}

static inline void SIb(Pre* o, V* n, V* d)
{
    float dt = DotD(n, d);
    o->flags.w[(signed char)(dt < 0.0f ? 0x11 : 0x10) / 32] |= 1 << ((signed char)(dt < 0.0f ? 0x11 : 0x10) & 31);
}

struct VB {
    float x, y, z, w;
    VB() {}
    VB(const VB& o) { V* d = (V*)this; __int128 q; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(q) : "r"(&o) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(q), "r"(d) : "memory"); }
} __attribute__((aligned(16)));

static inline VB SubB(const V& aa, const V& bb)
{
    VB r;
    VB* pr = &r;
    const V* a = &aa;
    const V* b = &bb;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(pr)
    }
    return r;
}

static inline void SetBitX(Pre* o, V* n, VB d)
{
    SIb(o, n, (V*)&d);
}

void cHumanCollisionRoutine_cFinalLedgeSearchInfo_RecordResults(Pre* o, Src* s, void* c)
{
    if (s->active) {
        if (o->enabled && !o->published) {
            V axis(0.0f, 0.0f, 1.0f, 0.0f);
            o->published = 1;
            o->desc = s->desc;
            o->flags = s->flags;
            o->f74 = s->fE4;
            V n = Cross(axis, s->dir);
            if ((o->flags.w[15 / 32] >> (15 & 31)) & 1) {
                SetBitX(o, &n, SubB(s->tgt, s->pos));
            }
            if ((o->flags.w[8 / 32] >> (8 & 31)) & 1) {
                void* e = Find(c, &s->desc);
                if (e) {
                    PI i, last;
                    for (i = Begin(e), last = End(e); i != last; i.p++) {
                        V* tri = (V*)*i.p;
                        V m = MulII(tri, D_004A0320);
                        if (Dot3(&m, &n) < 0.0f)
                            NegTo(&m, &m);
                        if (SJd(Sub(s->pos, m), &tri[1], tri, &n))
                            o->flags.w[0] |= 0x400;
                        if (SJd(Add(s->pos, m), &tri[1], tri, &n))
                            o->flags.w[0] |= 0x800;
                    }
                }
            }
            Plc_001EC850 pl(s->pos);
            Orient8(&pl.rot, M(), NegW(s->dir), &axis);
            o->plc = pl;
        }
    } else {
        o->published = 0;
    }
}
static inline void merge_flush_func_001EC850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EC850 */
