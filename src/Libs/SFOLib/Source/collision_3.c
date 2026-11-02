/*
 * Libs/SFOLib/Source/collision: 9 files, 003BF250-003BF760
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BF250 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cCollisionFace_UnitNormal(char* self) {
    return self + 48;
}
static inline void merge_flush_func_003BF250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF250 */

/* merge_units: begin func_003BF260 */
#pragma push /* merge_units */
#pragma cplusplus on

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
} __attribute__((aligned(16)));
static inline void AddV(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline V operator+(const V& a, const V& b) { V r; AddV(&r, &a, &b); return r; }
static inline float Dot3(const V* a, const V* b)
{
    int t;
    float r = 0.0f;
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}
static inline unsigned char IsZero(const V* v)
{
    int k, f, r;
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
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return (unsigned char)r;
}
static inline void Normalize(V* v)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(v) : "memory");
}
struct W { const V* p; W(const V* q) : p(q) {} };
struct CIt {
    const V* p;
    CIt(const W& w) : p(w.p) {}
    const V& operator*() const { return *p; }
    CIt& operator++() { p++; return *this; }
};
static inline bool operator==(const CIt& a, const CIt& b) { const V* bp = b.p; return a.p == bp; }
static inline bool operator!=(const CIt& a, const CIt& b) { return !(a == b); }
struct ArrV { int p0; int count; int p8; unsigned char canExpand; };
extern "C" V** std_vector_deleter_cVector_data(const ArrV* a);
static inline CIt Begin(const ArrV& a) { return CIt(W(*std_vector_deleter_cVector_data(&a))); }
static inline CIt End(const ArrV& a) { return CIt(W(*std_vector_deleter_cVector_data(&a) + a.count)); }

extern "C" unsigned char CheckPotentiallyStoppedByTaperingSpace(const V& moveDir, const V& faceNormal, const ArrV& prev)
{
    CIt curr = Begin(prev);
    CIt end = End(prev);
    for (; curr != end; ++curr) {
        const V& currNormal = *curr;
        if (Dot3(&faceNormal, &currNormal) < 0.0f) {
            V combinedNormal = faceNormal + currNormal;
            if (Dot3(&moveDir, &combinedNormal) < 0.0f) {
                if (!IsZero(&combinedNormal)) {
                    Normalize(&combinedNormal);
                    if (Dot3(&moveDir, &combinedNormal) < -0.866f) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
static inline void merge_flush_func_003BF260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF260 */

/* merge_units: begin func_003BF460 */
#pragma push /* merge_units */
extern int cCollisionProbe_SphereSweptRay_DetectForCollision_uchar_uchar(int);

int ColQuery_ExecuteThunk(int a0) {
    return cCollisionProbe_SphereSweptRay_DetectForCollision_uchar_uchar(a0);
}
static inline void merge_flush_func_003BF460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF460 */

/* merge_units: begin func_003BF470 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
static inline void QF470(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
typedef struct { signed char hit; char pad[0xF]; V4 a; V4 b; V4 c; V4 d; V4 e; V4 f; } LosResult;
typedef struct { signed char hit; char pad[0xF]; V4 p; V4 n; V4 t; V4 r; V4 q; } LosHit;
extern void cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(LosResult* r, void* x, V4* a, V4* b, int k, float f0, float f1, float f2, float f3, float f4);
void Los_CombineResult(LosResult* r, LosHit* h, void* x)
{
    cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(r, x, &h->q, &h->r, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    r->hit = h->hit;
    QF470(&r->a, &h->p);
    { void* xx = &r->b; }
    QF470(&r->b, &h->p);
    { void* xx = &r->c; }
    QF470(&r->c, &h->p);
    { void* xx = &r->d; }
    QF470(&r->d, &h->n);
    { void* xx = &r->e; }
    QF470(&r->e, &h->n);
    QF470(&r->f, &h->t);
}
static inline void merge_flush_func_003BF470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF470 */

/* merge_units: begin func_003BF540 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq quad copies as GCC-style volatile asm; the unused xx keeps retail's dead addiu; local decl order picks the copy registers */
struct V_003BF540 {
    float x, y, z, w;
    V_003BF540() {}
    V_003BF540& operator=(const V_003BF540& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct CQ {
    signed char b0; char pad1[0xF];
    V_003BF540 v10; char pad20[0x20];
    V_003BF540 v40; char pad50[0x20];
    V_003BF540 v70; char pad80[0x10];
    V_003BF540 v90;
    float fA0; char padA4[0xC];
    char boxB0[0x20];
    int xD0; float fD4; float fD8; char padDC[4];
    V_003BF540 vE0; char padF0[0x10];
    float f100, f104, f108, f10C;
    unsigned char b110; char pad111[3]; float f114; unsigned char b118; unsigned char b119;
};
extern "C" {
extern signed char D_004E1D88;
extern V_003BF540 D_004E1D90;
extern void* D_00542D00;
#if 0 /* merge_units */
void cVector_opAssign(V_003BF540* d, const V_003BF540* s);
#endif /* merge_units */
void* cVector_opAssign(void*, void*); /* merge_units */
#define cVector_opAssign(a0, a1) ((void)cVector_opAssign((void *)(a0), (void *)(a1))) /* merge_units */

int cVector_IsZero(V_003BF540* v);
void cVector_GetNormalized_void(V_003BF540* out, V_003BF540* v);
V_003BF540* cVector_GetZero(void);
#if 0 /* merge_units */
V_003BF540* cVector_ctor_cVectorR(V_003BF540* d, V_003BF540* s);
#endif /* merge_units */
void* cVector_ctor_cVectorR(void*, void*); /* merge_units */
#define cVector_ctor_cVectorR(a0, a1) ((V_003BF540 *)cVector_ctor_cVectorR((void *)(a0), (void *)(a1))) /* merge_units */

float cVector_Dot(V_003BF540* a, V_003BF540* b);
void cBox_Empty(void* b);
void cBox_Include(void* b, V_003BF540* v);
void cVector_opAdd(V_003BF540* out, V_003BF540* a, V_003BF540* b);
void cBox_Grow(void* b, float r);
void std_vector_deleter_cVector_clear(void* l);
}
static inline const V_003BF540& Zero()
{
    if (!D_004E1D88) {
        D_004E1D88 = 1;
        D_004E1D90.x = 0.0f;
        D_004E1D90.y = 0.0f;
        D_004E1D90.z = 0.0f;
        D_004E1D90.w = 0.0f;
    }
    return D_004E1D90;
}
extern "C" void cCollisionProbe_SphereSweptRay_Reset_CommonCode(CQ* q, int a1, V_003BF540* org, V_003BF540* dir, unsigned char k, float r, float f0, float f1, float f2, float f3)
{
    q->xD0 = a1;
    q->fD4 = r;
    q->fD8 = r * r;
    { void* d = &q->vE0; __int128 t; const void* s = org; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    cVector_opAssign(&q->v70, dir);
    {
        V_003BF540 a, b;
        cVector_opAssign(&q->v90, !(cVector_IsZero(&q->v70) != 0) ? (cVector_GetNormalized_void(&a, dir), &a) : cVector_ctor_cVectorR(&b, cVector_GetZero()));
    }
    q->fA0 = cVector_Dot(dir, dir);
    q->f100 = f0;
    q->f104 = f1;
    q->f108 = f2;
    q->f10C = f3;
    q->b0 = 0;
    q->v10 = Zero();
    q->v40 = Zero();
    q->b110 = 0;
    q->f114 = 1.0f;
    q->b118 = 1;
    q->b119 = k;
    cBox_Empty(q->boxB0);
    cBox_Include(q->boxB0, &q->vE0);
    {
        V_003BF540 t;
        cVector_opAdd(&t, &q->vE0, &q->v70);
        cBox_Include(q->boxB0, &t);
    }
    cBox_Grow(q->boxB0, q->fD4);
    std_vector_deleter_cVector_clear(D_00542D00);
}
#undef cVector_opAssign /* merge_units */
#undef cVector_ctor_cVectorR /* merge_units */
static inline void merge_flush_func_003BF540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF540 */

/* merge_units: begin func_003BF750 */
#pragma push /* merge_units */
extern void cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc_2(void* q, float a, float b, float c, float d, float e, float f, float g);
/* Calls cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc_2 with the last two parameters zeroed. */
void ColQuery_InitTransformedThunk(void* q, float a, float b, float c, float d, float e)
{
    cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc_2(q, a, b, c, d, e, 0.0f, 0.0f);
}
static inline void merge_flush_func_003BF750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF750 */

/* merge_units: begin func_003BF760 */
#pragma push /* merge_units */
#include "vc_copy.h"

typedef struct { V4 r[4]; } Mtx;
typedef struct { int cap; int n; } VecE;
extern void* func_003C0200(VecE* v, int index);
extern void* cVector_ctor_void(void* p);
extern V4* cCollisionFace_Vertex(void* base, int i);
#if 0 /* merge_units */
extern V4* cVector_opAssign(V4* d, V4* s);
#endif /* merge_units */
#define cVector_opAssign(a0, a1) ((V4 *)cVector_opAssign((void *)(a0), (void *)(a1))) /* merge_units */

extern V4 cVector_GetTransformed(V4* vp, Mtx* m);
extern int func_003C01E0(V4* p, float x);
extern void func_003BFAB0(void* e, VecE* v, int i, float f, V4* t);
#if 0 /* merge_units */
extern void func_003BF900(void* e, V4* t);
#endif /* merge_units */
void func_003BF900(); /* merge_units */


#pragma opt_rotateloops off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_propagation off
void func_003BF760(VecE* v, Mtx* mtx, float f) {
    int i;
    for (i = v->n - 1; i >= 0; i--) {
        Mtx m;
        void* e;
        V4 t[3];
        V4 r0;
        V4 r1;
        V4 r2;
        Mtx* pm;
        Mtx* d;
        __int128 qa;
        __int128 qb;
        d = &m;
        asm { .set reorder; lq qa, 0x0(mtx); lq qb, 0x10(mtx); sq qa, 0x0(d); lq qa, 0x20(mtx); sq qb, 0x10(d); lq qb, 0x30(mtx); sq qa, 0x20(d); sq qb, 0x30(d) }
        pm = &m;
        e = func_003C0200(v, i);
        cVector_ctor_void(&t[0]);
        cVector_ctor_void(&t[1]);
        cVector_ctor_void(&t[2]);
        r0 = cVector_GetTransformed(cCollisionFace_Vertex(e, 0), pm);
        cVector_opAssign(&t[0], &r0);
        r1 = cVector_GetTransformed(cCollisionFace_Vertex(e, 1), pm);
        cVector_opAssign(&t[1], &r1);
        r2 = cVector_GetTransformed(cCollisionFace_Vertex(e, 2), pm);
        cVector_opAssign(&t[2], &r2);
        if (func_003C01E0(&t[0], f) || func_003C01E0(&t[1], f) || func_003C01E0(&t[2], f)) {
            func_003BFAB0(e, v, i, f, t);
        } else {
            func_003BF900(e, t);
        }
    }
}
#undef cVector_opAssign /* merge_units */
static inline void merge_flush_func_003BF760(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF760 */

/* merge_units: begin func_003BF900 */
#pragma push /* merge_units */
extern void cVector_opSub(V4* out, V4* a, V4* b);
extern void cVector_Cross(V4* out, V4* a, V4* b);
#if 0 /* merge_units */
extern float func_003BF9E0(V4* p);
#endif /* merge_units */
float func_003BF9E0(); /* merge_units */


extern void cVector_opMul(V4* out, V4* v, float s);
extern V4* cVector_Normalize_void(V4* v);
#if 0 /* merge_units */
extern V4* cVector_ctor_cVectorR(V4* d, V4* s);
#endif /* merge_units */
#define cVector_ctor_cVectorR(a0, a1) ((V4 *)cVector_ctor_cVectorR((void *)(a0), (void *)(a1))) /* merge_units */

extern void cCollisionFace_SetUnitNormal(V4* p, V4* v);
#pragma push
#pragma opt_unroll_loops off
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
void func_003BF900(V4* dst, V4* src) {
    V4 a;
    V4 b;
    V4 e;
    V4 d;
    V4 c;
    int i;
    for (i = 0; i < 3; i++) {
        float inv = 1.0f / src[i].y;
        src[i].x = src[i].x * inv;
        src[i].z = src[i].z * inv;
        /* asm quad copy: keeps the i++ scheduled between lq and sq */
        VCopyF(&dst[i], &src[i]);
    }
    cVector_opSub(&a, &dst[1], &dst[0]);
    cVector_opSub(&b, &dst[2], &dst[0]);
    cVector_Cross(&c, &a, &b);
    cVector_opMul(&d, &c, func_003BF9E0(dst));
    cVector_ctor_cVectorR(&e, cVector_Normalize_void(&d));
    cCollisionFace_SetUnitNormal(dst, &e);
}
#pragma pop
#undef cVector_ctor_cVectorR /* merge_units */
static inline void merge_flush_func_003BF900(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF900 */

/* merge_units: begin func_003BF9E0 */
#pragma push /* merge_units */
typedef struct { char pad[3]; unsigned char type; char pad2[0x14]; int f18; } B4Track;
typedef struct { int f0; B4Track** tracks; } B4Anim;
typedef struct { char pad[0x60]; int idx; B4Anim* anim; } B4Obj5;
extern char* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(B4Track*, int*);
float func_003BF9E0(B4Obj5* p) {
    int idx = p->idx;
    B4Track* t = p->anim->tracks[0];
    float* v;
    if (t->type < 4) {
        int k[1];
        k[0] = t->f18;
        v = (float*)(cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(t, k) + idx * 64);
    } else if (t->type < 5) {
        int k[1];
        k[0] = t->f18;
        v = (float*)(cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(t, k) + idx * 32);
    } else {
        int k[1];
        k[0] = t->f18;
        v = (float*)(cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(t, k) + idx * 16);
    }
    if (*v > 0.0f) return 1.0f;
    return -1.0f;
}
static inline void merge_flush_func_003BF9E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF9E0 */
