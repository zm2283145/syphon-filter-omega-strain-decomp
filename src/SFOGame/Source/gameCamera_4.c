/*
 * SFOGame/Source/gameCamera: 8 files, 0017CB70-0017CC60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017CB70 */
#pragma push /* merge_units */
/* cHermiteSplineWithScaledDuration<cVector>(p0, v0, p1, v1, duration): base cHermiteSpline(p0, v0*duration, p1, v1*duration), then duration and its inverse. */
#pragma cplusplus on
#pragma exceptions off
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; __int128 t; const V* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    V operator*(float k) const;
} __attribute__((aligned(16)));
static inline void ScaleTo(V* d, const V* s, float k) { __int128 r = 0; V* dd = d; asm {
        .set noreorder
        lqc2 vf1, 0x0(s)
        mfc1 r, k
        qmtc2.ni r, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(dd)
        .set reorder
    } }
inline V V::operator*(float k) const { V t; ScaleTo(&t, this, k); return t; }
struct CP {
    V position;
    V tangent;
    CP() {}
};
struct Arr { CP d[2]; CP& operator[](int i) { return d[i]; } };
struct HSD {
    Arr mPoints;
    float mDuration;
    float mOneOverDuration;
};
static inline void HS_ctor(HSD* p, const V& p0, V v0, const V& p1, V v1)
{
    {
        CP* q = p->mPoints.d;
        do { q++; } while (q != p->mPoints.d + 2);
    }
    p->mPoints[0].position = p0;
    p->mPoints[0].tangent = v0;
    p->mPoints[1].position = p1;
    p->mPoints[1].tangent = v1;
}
extern "C" HSD* cHermiteSplineWithScaledDuration_cVector_ctor_cVectorR_cVectorR_cVectorR_cVectorR_etc(HSD* p, const V* p0, const V* v0, const V* p1, const V* v1, float duration)
{
    HS_ctor(p, *p0, *v0 * duration, *p1, *v1 * duration);
    p->mDuration = duration;
    p->mOneOverDuration = (duration != 0.0f) ? 1.0f / duration : 0.0f;
    return p;
}
static inline void merge_flush_func_0017CB70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017CB70 */

/* merge_units: begin func_0017CC60 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cHermiteSplineWithScaledDuration_cVector_dtor)
static inline void merge_flush_func_0017CC60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017CC60 */

/* merge_units: begin func_0017CCB0 */
#pragma push /* merge_units */
#include "types.h"
#include "vu0_quat_rot.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 rot; V4 pos; } P_CCB0;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
P_CCB0* cQuatVec_Invert(P_CCB0* p) {
    float d;
    int t;
    asm {
        lqc2 vf1, 0x0(p)
        lqc2 vf2, 0x0(p)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf3w
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, d
    }
    if (d != 0.0f) {
        VU0_NEG3(p, p)
        {
        float inv;
        __int128 q = 0; /* dead init kept by opt_dead_assignments off: retail's paddub v0,zero,zero */
        inv = 1.0f / d;
        asm {
            .set noreorder
            lqc2 vf1, 0x0(p)
            mfc1 q, inv
            qmtc2.ni q, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0x0(p)
            .set reorder
        }
        }
    }
    { V4* a; a = &p->pos; VU0_NEG3(a, a) }
    { V4* v; v = &p->pos; VU0_QROT(v, p, v) }
    return p;
}
#pragma pop
static inline void merge_flush_func_0017CCB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017CCB0 */

/* merge_units: begin func_0017CD90 */
#pragma push /* merge_units */
/* Retail computes each quadword address separately (peephole pass off). */
#pragma peephole off

typedef struct { Vec4 a; Vec4 b; } VecPair;

static inline Vec4* CopyVec(Vec4* d, Vec4* s)
{
    *d = *s;
    return d;
}

/* Copies a pair of 16-byte vectors; returns the destination. */
VecPair* cQuatVec_ctor_cQuatVecR(VecPair* dst, VecPair* src)
{
    CopyVec(&dst->a, &src->a);
    CopyVec(&dst->b, &src->b);
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017CD90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017CD90 */

/* merge_units: begin func_0017CDB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Vector of 16-byte records: +4 count, +8 data. */
typedef struct VecRecordList {
    int unk0;
    int count;
    char* data;
} VecRecordList;

extern int std_vector_imp_cVector_insert(VecRecordList* list, char* pos, int n, int value);

/* Appends one record at the end of the list. */
int cArray_cVector_PushBackActual(VecRecordList* list, int value) {
    return std_vector_imp_cVector_insert(list, list->data + (list->count << 4), 1, value);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017CDB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017CDB0 */

/* merge_units: begin func_0017CDD0 */
#pragma push /* merge_units */
/* cSplinedMotion_cVector_UpdateVelocity: rate = (b - a) * k; rate *= max(0, 1 - damp * dt). Hand-matched (auto1 family seed).
 * The empty `.set noreorder/.set reorder` asm blocks are scheduling barriers that reproduce retail instruction order. */

typedef struct { char pad[0x10]; V4 a; V4 b; V4 rate; char pad40[0x10]; float damp; } CR_t;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
static inline float CR_Max(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
void cSplinedMotion_cVector_UpdateVelocity(CR_t* c, float dt, float k) {
    V4 u; V4 t; V4 s; V4 d; V4* q;
    {
        V4* q = &d; V4* x = &c->b; V4* y;
        asm { .set noreorder; .set reorder }
        y = &c->a;
        asm { lqc2 vf1, 0x0(x); lqc2 vf2, 0x0(y); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(q) }
    }
    {
        __int128 tt = 0; V4* p; V4* ss = &d; V4* dd = &t;
        *dd = *ss; p = &t; q = &s;
        asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 tt, k; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(q); .set reorder }
    }
    {
        V4* d2; V4* ss; V4* d1 = &u;
        asm { .set noreorder; .set reorder }
        *d1 = *q; ss = &u; d2 = &c->rate; *d2 = *ss;
    }
    {
        float f = CR_Max(0.0f, 1.0f - c->damp * dt); __int128 tt = 0; V4* q = &c->rate; V4* p = &c->rate;
        asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 tt, f; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(q); .set reorder }
    }
}
#pragma pop
static inline void merge_flush_func_0017CDD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017CDD0 */

/* merge_units: begin func_0017CE90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void cSplinedMotion_cVector_FixUpResultOfSplineEvaluation(void) {
}
static inline void merge_flush_func_0017CE90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017CE90 */

/* merge_units: begin func_0017CEA0 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; float f40; float f44; } A1_X;
typedef struct { A1_X* x; float t; } A1_P;
extern void cHermiteSpline_cVector_Evaluate(void* a, A1_X* x, float r);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_Evaluate(void* a, A1_P* p) {
    A1_X* x = p->x;
    float d = x->f40 - p->t;
    float r;
    if (x->f40 != 0.0f) r = d * x->f44;
    else r = 1.0f;
    cHermiteSpline_cVector_Evaluate(a, x, r);
}
static inline void merge_flush_func_0017CEA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017CEA0 */
