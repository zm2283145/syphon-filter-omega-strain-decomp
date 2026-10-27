/*
 * SFOGame/Source/human: 2 files, 00190100-001901C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00190100 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 rot; V4 pos; } Plc;
static inline V4 QMul_(V4* a, V4* b) {
    V4 r; V4* p = &r;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(a)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(p)
    }
    return r;
}
static inline void QRot_(V4* v, V4* q) {
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}
static inline void VAdd3_(V4* s, V4* d) {
    asm {
        lqc2 vf1, 0x0(d)
        lqc2 vf2, 0x0(s)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
Plc* cQuatVec_Transform(Plc* a, Plc* b) {
    V4* v;
    { V4 t; V4* tp; t = QMul_(&a->rot, &b->rot); tp = &t; a->rot = *tp; }
    v = &a->pos;
    QRot_(v, &b->rot);
    VAdd3_(&b->pos, &a->pos);
    return a;
}
#pragma pop
static inline void merge_flush_func_00190100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00190100 */

/* merge_units: begin func_001901C0 */
#pragma push /* merge_units */
/* cSkaAnim_GetFirstFrameRootTransform: placement (rotation, position) at the start of a clip - the clip's stored
   start placement for a full forward clip, otherwise the root sample at the clip's start time. */
#pragma cplusplus on

/* 16-byte vector; copies are lq/sq quad moves (no C equivalent) */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    void Set(const V& o) { const V* ps = &o; V* pd = this; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { const V* ps = &o; V* pd = this; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));

struct Placement {
    V q;
    V p;
    Placement(const V& a, const V& b) : q(a), p(b) {}
};

struct ClipData {
    char pad[0x30];
    Placement start;
};

struct Clip {
    char pad[0x24];
    ClipData* d;
    unsigned char reverse;
    float from;
    float to;
    float pos;
};

struct Sample;
extern "C" Sample* cSkaAnimDataSample_ctor_cSkaAnimDataSampleR(Sample* d, Sample* s);
struct Sample {
    Sample() {}
    Sample(const Sample& o) { cSkaAnimDataSample_ctor_cSkaAnimDataSampleR(this, (Sample*)&o); }
    signed char active;
    V v10;
    V v20;
    V v30;
    V v40;
};

struct Cursor;
extern "C" {
ClipData** cPointer_cSkaAnimData_ctor(Cursor* c, ClipData* d);
ClipData* cPointer_cSkaAnimData_opArrow(Cursor* c);
int cSkaAnimData_GetFrameCount(ClipData* d);
float cSkaAnimData_GetDuration(ClipData* d);
void cSkaAnimDataIterator_GotoStartAnimFrame(Cursor* c);
}
struct Cursor {
    Cursor(ClipData* dd, int* o) {
        Cursor* c = this;
        cPointer_cSkaAnimData_ctor(c, dd);
        c->out = o;
        c->speed = 0.0f;
        c->t = 0;
        c->i = 0;
        c->frac = 0;
        c->a = 0;
        c->b = 0;
        c->done = 0;
        c->speed = cSkaAnimData_GetFrameCount(cPointer_cSkaAnimData_opArrow(c)) / cSkaAnimData_GetDuration(cPointer_cSkaAnimData_opArrow(c));
        cSkaAnimDataIterator_GotoStartAnimFrame(c);
    }
    ClipData* d;
    int* out;
    float speed;
    float t;
    unsigned int i;
    float frac;
    float* a;
    float* b;
    unsigned char done;
};

extern "C" {
void cSkaAnimDataIterator_GotoAnimFrame(Cursor* c, float t);
Sample* cSkaAnimDataSample_ctor_void(Sample* s);
signed char* cSkaAnimDataSample_IsEndOfData(Sample* s);
unsigned int cSkeletonData_GetBoneCount(int* out);
char* cSkeletonData_GetBoneData(int* out, int i);
int cSkaAnimData_BoneHasTranslation(ClipData* d, int i);
int cSkaAnimData_RootHasDeltaTranslation(ClipData* d);
int cSkaAnimData_BoneHasRotation(ClipData* d, int i);
int cSkaAnimData_RootHasDeltaRotation(ClipData* d);
V* cVector_ctor_float_float_float_float(V* v, float x, float y, float z, float w);
V* cSkaAnimDataSample_DeltaTranslation(Sample* s);
V* cSkaAnimDataSample_Translation(Sample* s);
V* cSkaAnimDataSample_DeltaRotation(Sample* s);
V* cSkaAnimDataSample_Rotation(Sample* s);
V LerpXYZ(V* a, V* b, float s);
V LerpAndNormalize(V* a, V* b, float s);
void cVector_opAssign(V* d, const V& s);
V* cAxisAngle_ctor_eCoordinateAxis_float(V* v, unsigned char axis, float w);
V* cQuaternion_ctor_cAxisAngleR(V* q, V* axisAngle);
V* cQuaternion_opAssign(V* d, const V& s);
V* cQuaternion_ctor_floatP(V* d, float* s);
static inline void SetApproach(V* dst, V* a, V* b, Cursor& c)
{
    cQuaternion_opAssign(dst, LerpAndNormalize(a, b, c.frac));
}

static inline void SetYaw(V* dst, float ang)
{
    V q;
    V axis;
    cQuaternion_opAssign(dst, *cQuaternion_ctor_cAxisAngleR(&q, cAxisAngle_ctor_eCoordinateAxis_float(&axis, 2, ang)));
}

/* sample position as a point (w = 1) */
static inline V& SamplePoint(const Sample& r, V& p)
{
    V* pp;
    const Sample* rr = &r; /* unused: reproduces retail's dead load of the sample address */
    p.Set(r.v10);
    pp = &p;
    pp->w = 1.0f;
    return *pp;
}

static inline Sample SampleNext(Cursor& cur)
{
    Sample s;
    cSkaAnimDataSample_ctor_void(&s);
    *cSkaAnimDataSample_IsEndOfData(&s) = 1;
    if (cur.i < cSkeletonData_GetBoneCount(cur.out)) {
        cSkeletonData_GetBoneData(cur.out, cur.i);
        if (cSkaAnimData_BoneHasTranslation(cPointer_cSkaAnimData_opArrow(&cur), cur.i)) {
            if (cur.i == 0 && cSkaAnimData_RootHasDeltaTranslation(cPointer_cSkaAnimData_opArrow(&cur))) {
                V a0, a1, b0, b1;
                cVector_ctor_float_float_float_float(&a0, cur.a[0], cur.a[1], 0.0f, 0.0f);
                cVector_ctor_float_float_float_float(&a1, 0.0f, 0.0f, cur.a[2], 0.0f);
                cVector_ctor_float_float_float_float(&b0, cur.b[0], cur.b[1], 0.0f, 0.0f);
                cVector_ctor_float_float_float_float(&b1, 0.0f, 0.0f, cur.b[2], 0.0f);
                cVector_opAssign(cSkaAnimDataSample_DeltaTranslation(&s), LerpXYZ(&a0, &b0, cur.frac));
                cVector_opAssign(cSkaAnimDataSample_Translation(&s), LerpXYZ(&a1, &b1, cur.frac));
            } else {
                V a, b;
                cVector_ctor_float_float_float_float(&a, cur.a[0], cur.a[1], cur.a[2], 0.0f);
                cVector_ctor_float_float_float_float(&b, cur.b[0], cur.b[1], cur.b[2], 0.0f);
                cVector_opAssign(cSkaAnimDataSample_Translation(&s), LerpXYZ(&a, &b, cur.frac));
            }
            cur.a += 4;
            cur.b += 4;
        }
        if (cSkaAnimData_BoneHasRotation(cPointer_cSkaAnimData_opArrow(&cur), cur.i)) {
            if (cur.i == 0 && cSkaAnimData_RootHasDeltaRotation(cPointer_cSkaAnimData_opArrow(&cur))) {
                float f = cur.frac;
                SetYaw(cSkaAnimDataSample_DeltaRotation(&s), (1.0f - f) * cur.a[0] + f * cur.b[0]);
                cur.a += 4;
                cur.b += 4;
            }
            {
                V qa, qb;
                cQuaternion_ctor_floatP(&qa, cur.a);
                cQuaternion_ctor_floatP(&qb, cur.b);
                SetApproach(cSkaAnimDataSample_Rotation(&s), &qa, &qb, cur);
                cur.a += 4;
                cur.b += 4;
            }
        }
        cur.i++;
        *cSkaAnimDataSample_IsEndOfData(&s) = 0;
    }
    return s;
}

int cSkaAnim_GetFirstFrameRootTransform(Placement* res_out, Clip* clip, int* out)
{
    int r; /* the early path returns without setting v0, as retail does */
    if (clip->pos == 0.0f) {
        bool full = false;
        if (clip->from == 0.0f && clip->to == 1.0f) {
            full = true;
        }
        if (full) {
            *res_out = clip->d->start;
            return r;
        }
    }
    Cursor cur(clip->d, out);
    float t = clip->pos;
    t = t != 0.0f ? t : (clip->reverse ? clip->to : clip->from);
    cSkaAnimDataIterator_GotoAnimFrame(&cur, t * cSkaAnimData_GetFrameCount(cPointer_cSkaAnimData_opArrow(&cur)));
    Sample res = SampleNext(cur);
    V ret;
    V p;
    {
        const V* pq = &res.v30;
        V* pb = &res_out->p;
        const V* pr = &ret;
        ret = SamplePoint(res, p);
        res_out->q = *pq;
        *pb = *pr;
    }
    r = 0;
    return r;
}
}
static inline void merge_flush_func_001901C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001901C0 */
