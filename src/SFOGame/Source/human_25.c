/*
 * SFOGame/Source/human: 8 files, 001A7370-001A77E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001A7370 */
#pragma push /* merge_units */
#include "types.h"
#include "vc_copy.h"
#include "vu0_quat_rot.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* cVector_Rotate_cQuaternionR(V4* a, V4* b) {
    asm {
        lqc2 vf1, 0x0(a)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(b)
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
        sqc2 vf6, 0x0(a)
    }
    return a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7370(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7370 */

/* merge_units: begin func_001A73C0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_73C0;
typedef struct { char pad[0xB0]; void* root; } Obj_73C0;
extern int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void* r);
extern void cSkaAnimAnchor_TreeNode_UpdateTransform(void* r);
extern char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void* r);
#pragma push
#pragma opt_propagation off
V4_73C0* cSkaAnimAnchor_TreeNode_GetParentInverseRotation(Obj_73C0* o, V4_73C0* out)
{
    void* r = o->root;
    V4_73C0* v;
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(r);
        v = (V4_73C0*)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r);
        asm { .set reorder } /* empty barrier keeps the then-arm separate (known trick) */
    } else {
        v = (V4_73C0*)(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x50);
    }
    VCopyFF(out, v);
    asm {
        lqc2 vf1, 0x0(out)
        vsub.xyz vf1, vf0, vf1
        sqc2 vf1, 0x0(out)
    }
    return out;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A73C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A73C0 */

/* merge_units: begin func_001A7440 */
#pragma push /* merge_units */
typedef struct { V4 rot; V4 pos; } P;
typedef struct { char pad[0xB0]; void* root; } Obj;
static inline V4* CopyVec(V4* d, V4* s) { *d = *s; return d; }
static inline P* PCopy(P* d, P* s) { CopyVec(&d->rot, &s->rot); CopyVec(&d->pos, &s->pos); return d; }
static inline P* PInvert(P* p) {
    VU0_NEG3(p, p)
    { V4* b; V4* a; a = &p->pos; b = &p->pos; VU0_NEG3(a, b) }
    /* empty barrier: changes block scheduling so the then-arm's call arg lands in the jal delay slot */
    { V4* v; asm { .set reorder } v = &p->pos; VU0_QROT(v, p, v) }
    return p;
}
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
/* Copies the parent's world placement into out and inverts it in place. */
P* cSkaAnimAnchor_TreeNode_GetParentInverseTransform(Obj* o, P* out)
{
    void* r = o->root;
    P* v;
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(r);
        v = (P*)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r);
        asm { .set reorder }
    } else {
        v = (P*)(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x50);
    }
    PCopy(out, v);
    PInvert(out);
    return out;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7440(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7440 */

/* merge_units: begin func_001A7530 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "human_types.h"

extern int std_vector_pod_int_insert(PtrVec*, int*, int, int);

void* cQuatVec_ctor_void(void* self) {
    return self;
}

/* push_back: insert one value at end(). */
int cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_PushBackActual(PtrVec* v, int value) {
    int count = v->count;
    int* data = v->data;

    return std_vector_pod_int_insert(v, data + count, 1, value);
}
static inline void merge_flush_func_001A7530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A7530 */

/* merge_units: begin func_001A7560 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

/* Recomputes a root's cached world pose (w at 0x30) from its local placement
 * (p at 0x80) and the parent's world placement when the dirty flag is set. */

/* 16-byte quad copy (lq/sq have no C equivalent). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct V {
    float x, y, z, w;
    /* The unused xx keeps retail's dead source-address addiu. */
    V& operator=(const V& o) { void* xx = (void*)&o; Q16(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Plc { V rot, pos; };

extern "C" {
#if 0 /* merge_units */
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void*);
#endif /* merge_units */
#define cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(a0) ((void *)cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void((a0))) /* merge_units */


void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void*);
void cQuatVec_opAssign(Plc*, void*);
void cQuatVec_InvertAssumingUnitQuat(Plc*);
void cQuaternion_ctor_void(V*);
void cQuaternion_VU0Multiply(V*, V*, V*);
void cQuaternion_ctor_cQuaternionR(V*, V*);
void cSkaAnimAnchor_TreeNode_UpdateSkeletonTarget(struct S* s);
#if 0 /* merge_units */
void cSkaAnimAnchor_TreeNode_UpdateTransform(void*);
#endif /* merge_units */
#define cSkaAnimAnchor_TreeNode_UpdateTransform(a0) (cSkaAnimAnchor_TreeNode_UpdateTransform((a0))) /* merge_units */


#if 0 /* merge_units */
char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void*);
#endif /* merge_units */
#define cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(a0) (cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void((a0))) /* merge_units */


}

struct S {
    char pad00[0x30];
    Plc w;              /* 0x30 */
    char pad50[0x30];
    Plc p;              /* 0x80 */
    char padA0[2];
    unsigned char ba2;  /* 0xA2 */
    char padA3[0xD];
    void* ib0;          /* 0xB0 */
};

static inline void QRot(V* v, V* q) {
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
static inline void VAdd3(V* s, V* d) {
    asm {
        lqc2 vf1, 0x0(d)
        lqc2 vf2, 0x0(s)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}

static inline Plc* WorldPlc(void* r)
{
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(r);
        return (Plc*)cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r);
    }
    return (Plc*)(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x50);
}

void cSkaAnimAnchor_TreeNode_UpdateSkeletonTarget(S* s)
{
    if (s->ba2) {
        Plc* pi = WorldPlc(s->ib0);
        {
            Plc* o = &s->p;
            Plc* d = &s->w;
            Q16(&d->rot, &o->rot);
            Q16(&d->pos, &o->pos);
        }
        Plc* p = &s->w;
        V r;
        V q;
        cQuaternion_ctor_void(&q);
        cQuaternion_VU0Multiply(&q, &pi->rot, &p->rot);
        cQuaternion_ctor_cQuaternionR(&r, &q);
        p->rot = r;
        QRot(&p->pos, &pi->rot);
        VAdd3(&pi->pos, &p->pos);
        s->ba2 = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7560(void) {}
#undef cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void /* merge_units */
#undef cSkaAnimAnchor_TreeNode_UpdateTransform /* merge_units */
#undef cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A7560 */

/* merge_units: begin func_001A76A0 */
#pragma push /* merge_units */
typedef struct { V4 r[4]; } M4;
typedef struct { char pad[0x20]; V4 v20; char pad30[0x40]; V4 v70; char pad80[0x21]; unsigned char dirty; char padA2[0xE]; void* root; } Obj_001A76A0;

extern V4* cQuatVec_Rotation(void* p);
extern M4* cMatrix_ctor_cQuaternionR(M4* m, V4* q);
extern V4* cQuatVec_Translation(void* p);
extern M4* cMatrix_Set_cMatrixR_cVectorR(M4* m, M4* b, V4* p);
#pragma opt_common_subs off
static inline char* GetWorld(void* r) {
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(r);
        return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r);
    }
    return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x50;
}
void cSkaAnimAnchor_TreeNode_UpdateDeltaPos(Obj_001A76A0* o)
{
    if (o->dirty) {
        char* v = GetWorld(o->root);
        VCopyF(&o->v20, &o->v70);
        {
            M4 m; M4 rot; M4* b; V4* d;
            b = cMatrix_ctor_cQuaternionR(&rot, cQuatVec_Rotation(v));
            cMatrix_Set_cMatrixR_cVectorR(&m, b, cQuatVec_Translation(v));
            d = &o->v20;
            {
                M4* mp = &m;
                asm {
                    lqc2 vf8, 0x0(d)
                    lqc2 vf4, 0x0(mp)
                    lqc2 vf5, 0x10(mp)
                    lqc2 vf6, 0x20(mp)
                    vmulax.xyz ACC, vf4, vf8x
                    vmadday.xyz ACC, vf5, vf8y
                    vmaddz.xyz vf8, vf6, vf8z
                    sqc2 vf8, 0x0(d)
                }
            }
        }
        o->dirty = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A76A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A76A0 */

/* merge_units: begin func_001A7780 */
#pragma push /* merge_units */
void* cTreeNode_cSkaSystemPtr_Data(void* self) {
    return self;
}

int cArray_cTreeNode_cSkaSystemPtrPtr_Iterator_opMul(char* self) {
    return *(int*)(self + 0);
}

void cArray_cTreeNode_cSkaSystemPtrPtr_End_void(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_cTreeNode_cSkaSystemPtrPtr_Begin_void(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cMatrix_GetYAxis(char* self) {
    return self + 8;
}
static inline void merge_flush_func_001A7780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A7780 */

/* merge_units: begin func_001A77E0 */
#pragma push /* merge_units */
/* cSkaAnim_GetLastFrameRootTransform: placement (rotation, position) at the end of a clip - the clip's stored
   end placement for a full clip, otherwise the root sample at the clip's end time. */
#pragma cplusplus on

/* 16-byte vector; copies are lq/sq quad moves (no C equivalent) */
struct V_001A77E0 {
    float x, y, z, w;
    V_001A77E0() {}
    V_001A77E0(const V_001A77E0& o) { V_001A77E0* pd = this; const V_001A77E0* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    void Set(const V_001A77E0& o) { const V_001A77E0* ps = &o; V_001A77E0* pd = this; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V_001A77E0& operator=(const V_001A77E0& o) { const V_001A77E0* ps = &o; V_001A77E0* pd = this; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));

struct Placement {
    V_001A77E0 q;
    V_001A77E0 p;
    Placement(const V_001A77E0& a, const V_001A77E0& b) : q(a), p(b) {}
};

struct ClipData {
    char pad[0x50];
    Placement end;
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
    V_001A77E0 v10;
    V_001A77E0 v20;
    V_001A77E0 v30;
    V_001A77E0 v40;
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
V_001A77E0* cVector_ctor_float_float_float_float(V_001A77E0* v, float x, float y, float z, float w);
V_001A77E0* cSkaAnimDataSample_DeltaTranslation(Sample* s);
V_001A77E0* cSkaAnimDataSample_Translation(Sample* s);
V_001A77E0* cSkaAnimDataSample_DeltaRotation(Sample* s);
V_001A77E0* cSkaAnimDataSample_Rotation(Sample* s);
V_001A77E0 LerpXYZ(V_001A77E0* a, V_001A77E0* b, float s);
V_001A77E0 LerpAndNormalize(V_001A77E0* a, V_001A77E0* b, float s);
void cVector_opAssign(V_001A77E0* d, const V_001A77E0& s);
V_001A77E0* cAxisAngle_ctor_eCoordinateAxis_float(V_001A77E0* v, unsigned char axis, float w);
V_001A77E0* cQuaternion_ctor_cAxisAngleR(V_001A77E0* q, V_001A77E0* axisAngle);
V_001A77E0* cQuaternion_opAssign(V_001A77E0* d, const V_001A77E0& s);
V_001A77E0* cQuaternion_ctor_floatP(V_001A77E0* d, float* s);
static inline void SetApproach(V_001A77E0* dst, V_001A77E0* a, V_001A77E0* b, Cursor& c)
{
    cQuaternion_opAssign(dst, LerpAndNormalize(a, b, c.frac));
}

static inline void SetYaw(V_001A77E0* dst, float ang)
{
    V_001A77E0 q;
    V_001A77E0 axis;
    cQuaternion_opAssign(dst, *cQuaternion_ctor_cAxisAngleR(&q, cAxisAngle_ctor_eCoordinateAxis_float(&axis, 2, ang)));
}

/* sample position as a point (w = 1) */
static inline V_001A77E0& SamplePoint(const Sample& r, V_001A77E0& p)
{
    V_001A77E0* pp;
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
                V_001A77E0 a0, a1, b0, b1;
                cVector_ctor_float_float_float_float(&a0, cur.a[0], cur.a[1], 0.0f, 0.0f);
                cVector_ctor_float_float_float_float(&a1, 0.0f, 0.0f, cur.a[2], 0.0f);
                cVector_ctor_float_float_float_float(&b0, cur.b[0], cur.b[1], 0.0f, 0.0f);
                cVector_ctor_float_float_float_float(&b1, 0.0f, 0.0f, cur.b[2], 0.0f);
                cVector_opAssign(cSkaAnimDataSample_DeltaTranslation(&s), LerpXYZ(&a0, &b0, cur.frac));
                cVector_opAssign(cSkaAnimDataSample_Translation(&s), LerpXYZ(&a1, &b1, cur.frac));
            } else {
                V_001A77E0 a, b;
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
                V_001A77E0 qa, qb;
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

int cSkaAnim_GetLastFrameRootTransform(Placement* res_out, Clip* clip, int* out)
{
    int r; /* the early path returns without setting v0, as retail does */
    if (clip->pos == 0.0f) {
        bool full = false;
        if (clip->from == 0.0f && clip->to == 1.0f) {
            full = true;
        }
        if (full) {
            *res_out = clip->d->end;
            return r;
        }
    }
    Cursor cur(clip->d, out);
    float t = clip->pos;
    t = t != 0.0f ? t : (clip->reverse ? clip->from : clip->to);
    cSkaAnimDataIterator_GotoAnimFrame(&cur, t * cSkaAnimData_GetFrameCount(cPointer_cSkaAnimData_opArrow(&cur)));
    Sample res = SampleNext(cur);
    V_001A77E0 ret;
    V_001A77E0 p;
    {
        const V_001A77E0* pq = &res.v30;
        V_001A77E0* pb = &res_out->p;
        const V_001A77E0* pr = &ret;
        ret = SamplePoint(res, p);
        res_out->q = *pq;
        *pb = *pr;
    }
    r = 0;
    return r;
}
}
static inline void merge_flush_func_001A77E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A77E0 */
