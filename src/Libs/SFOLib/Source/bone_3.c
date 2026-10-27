/*
 * Libs/SFOLib/Source/bone: 6 files, 003BA2B0-003BA5F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BA2B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
/* cBone_AnimationSetWeightedRotation: push the accumulated rotation (normalised, as a matrix) and keep it,
 * or restore the bind rotation (the conjugate of the bone matrix's quaternion) */
struct V {
    float x, y, z, w;
    V() {}
    /* quad copy (lq/sq; C has no 128-bit move); xx is dead on purpose: retail keeps the extra addiu */
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { float f[4][4]; } __attribute__((aligned(16)));
struct BoneBR {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void SetRot(M* m);
    char pad[0xCC];
    M mtx;
    char pad110[0x190 - 0x110];
    V accumR;
    V rot;
};
static inline void VCx(void* d, const void* s) { void* xx = d; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
/* VU0 vector compare / quaternion helpers: no C equivalent */
static inline int IsZero(const V* v)
{
    int k, fl;
    unsigned char r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline M* QuatToMtx(M* a, V* b)
{
    __asm__ volatile("lqc2 vf1, 0x0(%1); vadd.xyzw vf2, vf1, vf1; vaddw.xyz vf3, vf0, vf0w; vmulx.w vf8, vf0, vf0x; vmulx.w vf9, vf0, vf0x; vmuly.xyzw vf5, vf1, vf2y; vmulz.xyzw vf6, vf1, vf2z; vmulx.xyzw vf4, vf1, vf2x; vmulx.w vf10, vf0, vf0x; vsubay.x ACC, vf3, vf5y; vmsubz.x vf8, vf3, vf6z; vsubw.x vf9, vf5, vf6w; vaddw.x vf10, vf6, vf5w; vaddw.y vf8, vf4, vf6w; vsubax.y ACC, vf3, vf4x; vmsubz.y vf9, vf3, vf6z; vsubw.y vf10, vf6, vf4w; vsubw.z vf8, vf4, vf5w; vaddw.z vf9, vf5, vf4w; vsubax.z ACC, vf3, vf4x; vmsuby.z vf10, vf3, vf5y; sqc2 vf0, 0x30(%0); sqc2 vf8, 0x0(%0); sqc2 vf9, 0x10(%0); sqc2 vf10, 0x20(%0)" : : "r"(a), "r"(b) : "memory");
    return a;
}
static inline V* MtxToQuatR(const M* m, V* out)
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

    return out;
}
static inline void NormQg(V* a) { __asm__ volatile("lqc2 vf1, 0x0(%0); vmul.xyzw vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddaz.w ACC, vf0, vf2z; vmaddw.w vf3, vf0, vf2w; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyzw vf4, vf1, Q; sqc2 vf4, 0x0(%0)" : : "r"(a) : "memory"); }
static inline void Conjg(V* p) { __asm__ volatile("lqc2 vf1, 0x0(%0); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0x0(%0)" : : "r"(p) : "memory"); }
extern "C" void cBone_AnimationSetWeightedRotation(BoneBR* b)
{
    if (!IsZero(&b->accumR)) {
        NormQg(&b->accumR);
        {
            M m;
            QuatToMtx(&m, &b->accumR);
            b->SetRot(&m);
        }
        VCx(&b->rot, &b->accumR);
    } else if (IsZero(&b->rot)) {
        V q;
        MtxToQuatR(&b->mtx, &q);
        V* p = &q;
        Conjg(p);
        b->rot = *p;
    }
}
static inline void merge_flush_func_003BA2B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BA2B0 */

/* merge_units: begin func_003BA5F0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cBone_AnimationSetWeightedOffset: push the accumulated translation, or restore the bind position */
typedef struct Vec3BT { float x, y, z; } Vec3BT;
struct Vec4BT {
    float x, y, z, w;
    Vec4BT() {}
    Vec4BT(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 0; }
} __attribute__((aligned(16)));
typedef struct XfBT { int a, b; Vec3BT pos; } XfBT;
struct BoneBT {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void SetName(void* n);
    virtual void SetPos(Vec4BT* p);
    char pad[0xBC];
    XfBT* xf;
    char padC4[0x180 - 0xC4];
    Vec4BT accumT;
    Vec4BT accumR;
    char pad1A0[0x10];
    Vec4BT pos;
};
static inline void VC(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline int IsZero_003BA5F0(const Vec4BT* v)
{
    int k, fl;
    unsigned char r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
extern "C" void cBone_AnimationSetWeightedOffset(BoneBT* b)
{
    if (!IsZero_003BA5F0(&b->accumT)) {
        b->accumT.w = 1.0f;
        b->SetPos(&b->accumT);
        VC(&b->pos, &b->accumT);
    } else if (IsZero_003BA5F0(&b->pos)) {
        XfBT* xf = b->xf;
        Vec4BT* q;
        Vec4BT v(xf->pos.x, xf->pos.y, xf->pos.z);
        Vec4BT* p = &b->pos;
        VC(p, &v);
        q = &b->pos; q->w = 1.0f;
    }
}
static inline void merge_flush_func_003BA5F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BA5F0 */

/* merge_units: begin func_003BA710 */
#pragma push /* merge_units */
/* Zero the bone's translation and rotation accumulators. */
typedef struct { __int128 q; } Q_3BA710;
typedef struct { unsigned char pad[0x180]; Q_3BA710 accumT; Q_3BA710 accumR; } Bone_3BA710;

#pragma peephole off
#pragma opt_propagation off
void cBone_AnimationClearAccumulation(Bone_3BA710* b)
{
    __int128* p;
    p = &b->accumT.q; *p = 0;
    p = &b->accumR.q; *p = 0;
}
#pragma opt_propagation reset
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA710(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA710 */

/* merge_units: begin func_003BA730 */
#pragma push /* merge_units */
typedef struct { __int128 q[4]; } MBA730_;
typedef struct { char pad[0xD0]; MBA730_ m; } SBA730_;
#pragma peephole off
void cBone_SetMeshSpaceToBoneSpaceMatrix(SBA730_* dst, MBA730_* src)
{
    MBA730_* d = &dst->m;
    __int128 qa, qb;
    qa = src->q[0]; qb = src->q[1];
    d->q[0] = qa; qa = src->q[2];
    d->q[1] = qb; qb = src->q[3];
    d->q[2] = qa;
    d->q[3] = qb;
}
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA730(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA730 */

/* merge_units: begin func_003BA760 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct Vec3SA { float x, y, z; } Vec3SA;
struct Vec4SA { float x, y, z, w; Vec4SA() {} Vec4SA(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 0; } };
typedef struct XfSA { int a, b; Vec3SA pos; } XfSA;
struct SkelSA {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void SetName(void* n);
    virtual void SetPos(Vec4SA* p);
    virtual void v0E(); virtual void v0F();
    virtual void Attach(void* parent, int f);
    char pad[0xBC];
    XfSA* xf;
};
extern "C" char g_IdentityMatrix[];
extern "C" void cBone_SetParent(SkelSA* n, void* parent)
{
    XfSA* xf;
    if (parent) {
        n->Attach(parent, 1);
    }
    xf = n->xf;
    Vec4SA v(xf->pos.x, xf->pos.y, xf->pos.z);
    v.w = 1.0f;
    n->SetPos(&v);
    n->SetName(g_IdentityMatrix);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA760(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA760 */

/* merge_units: begin func_003BA7F0 */
#pragma push /* merge_units */
typedef struct { char data[0x1D0]; } SkelInit; /* temporary built from the record */
typedef struct { char pad[0xC0]; void* record; } SkelNode;
extern void cBone_ctor_void(SkelInit* init, void* record);
extern void cBone_opAssign(SkelNode* node, SkelInit* init);
extern void cBone_dtor(SkelInit* init, int flags);

/* Initializes the node from a record via a temporary init block, then remembers the record. */
void cBone_Init(SkelNode* self, void* record)
{
    SkelInit init;
    cBone_ctor_void(&init, record);
    cBone_opAssign(self, &init);
    self->record = record;
    cBone_dtor(&init, -1);
}
static inline void merge_flush_func_003BA7F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BA7F0 */
