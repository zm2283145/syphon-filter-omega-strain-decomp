/*
 * SFOGame/Source/humanIk: 3 files, 001DD0C0-001DD1C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001DD0C0 */
#pragma push /* merge_units */
/* Bounded push of a SegPair into a 6-entry list; member-wise copies (pointer-temp placement steers mw38 coloring). */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct Seg { V4 p; V4 q; signed char f; } Seg;
typedef struct SegPair { Seg a; Seg b; } SegPair;
typedef struct SegList { unsigned int n; SegPair e[6]; } SegList;
#pragma peephole off
#pragma opt_propagation off
void cArray_FixedCapacity_cIkTarget_LeftRight_6_PushBackActual(SegList* l, const SegPair* s)
{
    if (l->n < 6) {
        SegPair* e;
        V4* dbq;
        const V4* sbq;
        V4* daq;
        const V4* saq;
        V4* dbp;
        const V4* sbp;
        e = &l->e[l->n];
        asm { .set reorder } /* scheduling barrier */
        e->a.p = s->a.p;
        daq = &e->a.q;
        saq = &s->a.q;
        *daq = *saq;
        dbp = &e->b.p;
        sbp = &s->b.p;
        e->a.f = s->a.f;
        dbq = &e->b.q;
        sbq = &s->b.q;
        *dbp = *sbp;
        *dbq = *sbq;
        e->b.f = s->b.f;
        l->n++;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001DD0C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001DD0C0 */

/* merge_units: begin func_001DD140 */
#pragma push /* merge_units */
#pragma peephole off
#pragma opt_propagation off
SegList* cDrawAndHolsterWeapon_ActionManager_cWeaponSlotIkTargetTable_PushBack_WithIndexCheck(SegList* l, int unused, const SegPair* s)
{
    if (l->n < 6) {
        SegPair* e;
        V4* dbq;
        const V4* sbq;
        V4* daq;
        const V4* saq;
        V4* dbp;
        const V4* sbp;
        e = &l->e[l->n];
        asm { .set reorder } /* scheduling barrier */
        e->a.p = s->a.p;
        daq = &e->a.q;
        saq = &s->a.q;
        *daq = *saq;
        dbp = &e->b.p;
        sbp = &s->b.p;
        e->a.f = s->a.f;
        dbq = &e->b.q;
        sbq = &s->b.q;
        *dbp = *sbp;
        *dbq = *sbq;
        e->b.f = s->b.f;
        l->n++;
    }
    return l;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001DD140(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001DD140 */

/* merge_units: begin func_001DD1C0 */
#pragma push /* merge_units */
/* 001DD1C0 nHumanIk::cAimComponent::CalculateTargetRotation_WorldSpace(const cMatrix&, const cSkeleton&) const (humanIk.cc)
   Prototype counterpart 0x1D2CA0 (lines 207-233, locals worldUpVector_SkelSpace, aimFromPosition_WorldSpace,
   result_WorldSpace); retail replaces the prototype's Cross/Set block with the LookAt inline (same body as in
   UpperBody_HandRotation, humanIk_48.c). The transposed-rotation idiom follows cParticleSpray_UpdateGravityVector.
   Inline asm is used only for EE/VU0 instructions C cannot express: 128-bit lq/sq quadword copies, VU0 macro-mode
   transforms (lqc2/sqc2/vmula...), cfc2 flag tests and the MtxToQuat sequence. No register pinning. */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "vslot_pad.h"

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V(const V& o, int) { const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(this) } }
    V& Rot(struct cMatrix m);
} __attribute__((aligned(16)));
struct cMatrix {
    float m[4][4];
    cMatrix() {}
    cMatrix(const cMatrix& o) { __int128 qa, qb; asm volatile { lq qa, 0x0(&o); lq qb, 0x10(&o); sq qa, 0x0(this); lq qa, 0x20(&o); sq qb, 0x10(this); lq qb, 0x30(&o); sq qa, 0x20(this); sq qb, 0x30(this) } }
    const V& GetTranslation() const { return *(const V*)m[3]; }
} __attribute__((aligned(16)));

extern "C" {
cMatrix* cMatrix_ctor_void(cMatrix*);
cMatrix* cMatrix_ctor_cMatrixR(cMatrix*, const cMatrix*);
V cVector_GetNormalized_void(const V*);
float cVector_Dot(const V*, const V*);
float Math_Fabs(float);
void cMatrix_MakeLookAtMatrix_cVectorR_cVectorR(cMatrix*, const V*, const V*);
const V* func_001D3AC0(const cMatrix*);
const V* cMatrix_GetXAxis(const cMatrix*);
V* cVector_ctor_void(V*);
void func_001D3A90(const cMatrix*, V*, V*, V*);
V func_001D3A60(const V*);
void cMatrix_SetAxes(cMatrix*, const V*, const V*, const V*);
extern cMatrix g_IdentityMatrix;
}
static inline void MtxToQuat(const cMatrix* m, V* out) {
    const cMatrix* mp = m;
    V* op = out;
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(mp)
        lqc2 vf2, 0x10(mp)
        lqc2 vf3, 0x20(mp)
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
        sqc2 vf9, 0x0(op)
        .set reorder
    }
}

/* VU0 macro-mode transforms (COP2), not expressible in C */
inline V& V::Rot(cMatrix m) { V* p = this; __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(%0)" : : "r"(p), "r"(&m) : "memory"); return *p; }
static inline void XformM(V* v, const cMatrix* m) { asm volatile { lqc2 vf8, 0x0(v); lqc2 vf4, 0x0(m); lqc2 vf5, 0x10(m); lqc2 vf6, 0x20(m); lqc2 vf7, 0x30(m); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(v) } }
static inline void SubT(V* d, const V* p, const V* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline V operator-(const V& a, const V& b) { V r; SubT(&r, &a, &b); return r; }
static inline V operator*(const cMatrix& m, const V& v) { V r(v, 0); V* p = &r; XformM(p, &m); return *p; }
static inline cMatrix Transposed(const cMatrix& a)
{
    cMatrix r(a);
    cMatrix& s = r;
    float t;
    t = s.m[0][1]; s.m[0][1] = s.m[1][0]; s.m[1][0] = t;
    t = s.m[0][2]; s.m[0][2] = s.m[2][0]; s.m[2][0] = t;
    t = s.m[1][2]; s.m[1][2] = s.m[2][1]; s.m[2][1] = t;
    return s;
}

struct cMatrixC : cMatrix {
    cMatrixC() { cMatrix_ctor_void(this); }
    cMatrixC(const cMatrixC& o) { cMatrix_ctor_cMatrixR(this, &o); }
};
static inline cMatrixC LookAt(const V& aimDir, const V& up)
{
    cMatrixC m;
    V n = cVector_GetNormalized_void(&aimDir);
    if (Math_Fabs(cVector_Dot(&n, &up)) < 0.9999985f) {
        cMatrix_MakeLookAtMatrix_cVectorR_cVectorR(&m, &aimDir, &up);
    } else {
        const V* z = func_001D3AC0(&g_IdentityMatrix);
        if (Math_Fabs(cVector_Dot(&n, z)) < 0.9999985f) {
            cMatrix_MakeLookAtMatrix_cVectorR_cVectorR(&m, &n, z);
        } else {
            cMatrix_MakeLookAtMatrix_cVectorR_cVectorR(&m, &n, cMatrix_GetXAxis(&g_IdentityMatrix));
            V ax, ay, az;
            cVector_ctor_void(&ax);
            cVector_ctor_void(&ay);
            cVector_ctor_void(&az);
            func_001D3A90(&m, &ax, &ay, &az);
            V nx = func_001D3A60(&ax);
            cMatrix_SetAxes(&m, &az, &ay, &nx);
        }
    }
    return m;
}

struct cXform { VPAD16(a) VPAD4(b) virtual void UpdateTreeNode() const; int pad4[3]; cMatrix localToWorldMatrix; unsigned char needsUpdate;
    const cMatrix& GetMatrix() const { if (needsUpdate) UpdateTreeNode(); return localToWorldMatrix; } };
struct cBone;
struct cBoneArray { int pad[4]; };
struct cSkeleton { char pad0[0x14]; unsigned char hasBones; char pad15[3]; cBoneArray bones; cXform* xform; };
extern "C" {
cBone* cArray_cBone_opIndex_int(const cBoneArray*, int);
cXform* cBone_Xform(const cBone*);
const cMatrix* cXform_GetMatrix(const cXform*);
}

/* the reference to the temporary is taken before the transposed copy is built (retail sets up its address first) */
static inline V& RotR(const V& v, const cMatrix& m) { V& w = (V&)v; return w.Rot(Transposed(m)); }
struct Q : V { Q(const cMatrix& m) { MtxToQuat(&m, this); } };
struct cAimComponent { signed char boneIdx; char pad1[0xF]; V target; };
static inline const cMatrix& BoneMatrix(const cSkeleton& s, int i) { if (s.hasBones) return *cXform_GetMatrix(cBone_Xform(cArray_cBone_opIndex_int(&s.bones, i))); return *cXform_GetMatrix(s.xform); }

extern "C" V UpperBodyLook_TargetQuat(const cAimComponent* self, const cMatrix& skelSpaceToWorldSpaceTransform, const cSkeleton& skeleton)
{
    V worldUpVector_SkelSpace = RotR(V(0.0f, 0.0f, 1.0f, 0.0f), skeleton.xform->GetMatrix());

    V aimFromPosition_WorldSpace = skelSpaceToWorldSpaceTransform * BoneMatrix(skeleton, self->boneIdx).GetTranslation();
    V result_WorldSpace = Q(LookAt(self->target - aimFromPosition_WorldSpace, worldUpVector_SkelSpace));
    return result_WorldSpace;
}
static inline void merge_flush_func_001DD1C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001DD1C0 */
