/*
 * SFOGame/Source/human: 23 files, 001906B0-00190E50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001906B0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#include "types.h"

#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cSkaAnimDataIterator_dtor)
static inline void merge_flush_func_001906B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001906B0 */

/* merge_units: begin func_00190700 */
#pragma push /* merge_units */
/* Animation sample assignment: implicit member-wise operator= (byte id + four lq/sq quad copies). */
#pragma cplusplus on
struct V {
    float x, y, z, w;
    V() {}
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct Sample {
    unsigned char id;
    V v[4];
};
extern "C" Sample* cSkaAnimDataSample_ctor_cSkaAnimDataSampleR(Sample* d, const Sample* s)
{
    *d = *s; return d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190700(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190700 */

/* merge_units: begin func_00190750 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma opt_common_subs off
V4 LerpAndNormalize(V4* b, V4* c, float s) {
    V4 l0;
    V4* q1 = &l0;
    int rv1;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        mfc1 rv1, s
        qmtc2.ni rv1, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddax.xyzw ACC, vf2, vf3x
        vmsubx.xyzw vf4, vf1, vf3x
        vmul.xyzw vf5, vf4, vf4
        vmulax.w ACC, vf0, vf5x
        vmadday.w ACC, vf0, vf5y
        vmaddaz.w ACC, vf0, vf5z
        vmaddw.w vf6, vf0, vf5w
        vrsqrt Q, vf0w, vf6w
        vwaitq 
        vmulq.xyzw vf7, vf4, Q
        sqc2 vf7, 0x0(q1)
    }
    return l0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190750(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190750 */

/* merge_units: begin func_001907B0 */
#pragma push /* merge_units */
#include "human_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cSkaAnimDataSample_Rotation(char* self) {
    return self + 48;
}

Vec4* cQuaternion_ctor_floatP(Vec4* dst, Vec4* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = src->w;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001907B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001907B0 */

/* merge_units: begin func_001907F0 */
#pragma push /* merge_units */
typedef struct Quat {
    float x, y, z, w;
} Quat;

extern float Libc_Cosf(float); /* Libc_Cosf */
extern float Libc_Sinf(float); /* Libc_Sinf */

/* Builds a quaternion from an axis (xyz) and angle (w). */
Quat* cQuaternion_ctor_cAxisAngleR(Quat* q, Quat* axisAngle) {
    float half = 0.5f * axisAngle->w;
    float c;
    float s;
    c = Libc_Cosf(half); /* cos */
    s = Libc_Sinf(half); /* sin */
    q->w = c;
    q->x = s * axisAngle->x;
    q->y = s * axisAngle->y;
    q->z = s * axisAngle->z;
    return q;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001907F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001907F0 */

/* merge_units: begin func_00190880 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } V_190880;
V_190880* cAxisAngle_ctor_eCoordinateAxis_float(V_190880* v, unsigned char axis, float w)
{
    v->w = w;
    switch (axis) {
    case 0: v->x = 1.0f; v->y = 0.0f; v->z = 0.0f; break;
    case 1: v->x = 0.0f; v->y = 1.0f; v->z = 0.0f; break;
    case 2: v->x = 0.0f; v->y = 0.0f; v->z = 1.0f; break;
    }
    return v;
}
static inline void merge_flush_func_00190880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00190880 */

/* merge_units: begin func_00190900 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cSkaAnimDataSample_DeltaRotation(char* self) {
    return self + 64;
}

int cSkaAnimData_RootHasDeltaRotation(G18* s) {
    return s->v != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190900(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190900 */

/* merge_units: begin func_00190920 */
#pragma push /* merge_units */
typedef struct FlagObj {
    char pad00[0x20];
    int flags; /* 0x20 */
} FlagObj;

/* Returns whether bit `bit` is set in the object's flag word. */
int cSkaAnimData_BoneHasRotation(FlagObj* obj, int bit) {
    return (obj->flags & (1 << bit)) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190920(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190920 */

/* merge_units: begin func_00190940 */
#pragma push /* merge_units */
void* cSkaAnimDataSample_Translation(char* self) {
    return self + 16;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190940 */

/* merge_units: begin func_00190950 */
#pragma push /* merge_units */
#pragma push
#pragma opt_common_subs off
V4 LerpXYZ(V4* b, V4* c, float s) {
    V4 l0;
    V4* q1 = &l0;
    int rv1;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        mfc1 rv1, s
        qmtc2.ni rv1, vf3
        vaddax.xyz ACC, vf1, vf0x
        vmaddax.xyz ACC, vf2, vf3x
        vmsubx.xyz vf1, vf1, vf3x
        sqc2 vf1, 0x0(q1)
    }
    return l0;
}
#pragma pop
static inline void merge_flush_func_00190950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00190950 */

/* merge_units: begin func_00190990 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cSkaAnimDataSample_DeltaTranslation(char* self) {
    return self + 32;
}

int cSkaAnimData_RootHasDeltaTranslation(G14* s) {
    return s->v != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190990 */

/* merge_units: begin func_001909B0 */
#pragma push /* merge_units */
typedef struct { char pad[0x1C]; unsigned int mask; } BitObj;

/* Returns 1 if bit n of the mask at +0x1C is set. */
int cSkaAnimData_BoneHasTranslation(BitObj* self, int n)
{
    return (self->mask & (1 << n)) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001909B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001909B0 */

/* merge_units: begin func_001909D0 */
#pragma push /* merge_units */
/* Address of field +0x10 in 32-byte element i. */
char* cSkeletonData_GetBoneData(char* base, int i) {
    return base + (i << 5) + 16;
}

int cSkeletonData_GetBoneCount(char* self) {
    return *(int*)(self + 0);
}

void* cSkaAnimDataSample_IsEndOfData(void* self) {
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001909D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001909D0 */

/* merge_units: begin func_00190A00 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V_00190A00 {
    float x, y, z, w;
    V_00190A00() {}
    V_00190A00(const V_00190A00& o) { V_00190A00* pd = this; const V_00190A00* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V_00190A00& operator=(const V_00190A00& o) { V_00190A00* pd = this; const V_00190A00* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct S {
    signed char a;
    V_00190A00 v10;
    V_00190A00 v20;
    V_00190A00 v30;
    V_00190A00 v40;
};
extern "C" { extern signed char D_004E1D88; extern V_00190A00 D_004E1D90; }
static inline const V_00190A00& Zero() { if (!D_004E1D88) { D_004E1D90.x = 0.0f; D_004E1D88 = 1; D_004E1D90.y = 0.0f; D_004E1D90.z = 0.0f; D_004E1D90.w = 0.0f; } return D_004E1D90; }
static inline V_00190A00 Unit() { V_00190A00 l0; V_00190A00* q1 = &l0; asm { sqc2 vf0, 0x0(q1) } return l0; }
extern "C" S* cSkaAnimDataSample_ctor_void(S* p)
{
    p->a = 0;
    p->v10 = Zero();
    p->v20 = Zero();
    { V_00190A00 u = Unit(); p->v30 = u; }
    p->v40 = Unit();
    return p;
}
static inline void merge_flush_func_00190A00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00190A00 */

/* merge_units: begin func_00190B00 */
#pragma push /* merge_units */
typedef struct {
    unsigned int type;
    unsigned int frames;
    int stride;
    int pad0C;
    int loop;
} ClipData;
typedef struct {
    ClipData* d;
    int pad04;
    int pad08;
    float t;
    int i10;
    float frac;
    float* a;
    float* b;
    unsigned char done;
} ClipCursor;
void cSkaAnimDataIterator_GotoAnimFrame(ClipCursor* c, float t) {
    float len;
    unsigned int frames;
    int stride;
    ClipData* d;
    unsigned int type;
    unsigned int idx;
    int i0;
    float* base;
    int i1;
    c->t = t;
    c->done = 0;
    len = (int)c->d->frames;
    if (c->d->loop) {
        while (c->t >= len) {
            c->t -= len;
        }
    } else if (c->t >= len) {
        c->t = len;
        c->done = 1;
    }
    frames = c->d->frames;
    stride = c->d->stride;
    c->i10 = 0;
    d = c->d;
    type = d->type;
    if (type >= 3) {
        base = (float*)((char*)d + 0x70);
    } else if (type == 2) {
        base = (float*)((char*)d + 0x40);
    } else {
        base = (float*)((char*)d + 0x30);
    }
    idx = (int)c->t;
    i0 = idx * d->stride;
    if (d->loop) {
        i1 = (idx < frames - 1) ? i0 + stride : 0;
    } else {
        i1 = (idx < frames) ? i0 + stride : i0;
    }
    c->frac = c->t - idx;
    c->a = base + i0;
    c->b = base + i1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190B00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190B00 */

/* merge_units: begin func_00190C70 */
#pragma push /* merge_units */
typedef struct {
    void* d;
    int pad04;
    int pad08;
    float t;
    int i10;
    float frac;
    float* a;
    float* b;
    unsigned char done;
} ClipCursor_00190C70;
#if 0 /* merge_units */
extern unsigned int nSFO_Macros_FTOI(float);
#endif /* merge_units */
int nSFO_Macros_FTOI(float x); /* merge_units */
#define nSFO_Macros_FTOI(a0) ((unsigned int)nSFO_Macros_FTOI((a0))) /* merge_units */

#if 0 /* merge_units */
extern float* cSkaAnimData_DataStart(void*);
#endif /* merge_units */
void * cSkaAnimData_DataStart(); /* merge_units */

#if 0 /* merge_units */
extern int cSkaAnimData_GetFrameSize(void*);
#endif /* merge_units */
int cSkaAnimData_GetFrameSize(); /* merge_units */

#if 0 /* merge_units */
extern int cSkaAnimData_IsLooping(void*);
#endif /* merge_units */
int cSkaAnimData_IsLooping(); /* merge_units */

#if 0 /* merge_units */
extern int cSkaAnimData_GetFrameCount(void*);
#endif /* merge_units */
int cSkaAnimData_GetFrameCount(); /* merge_units */

#if 0 /* merge_units */
extern void* cPointer_cSkaAnimData_opArrow(ClipCursor_00190C70*);
#endif /* merge_units */
int cPointer_cSkaAnimData_opArrow(); /* merge_units */

void cSkaAnimDataIterator_GotoStartAnimFrame(ClipCursor_00190C70* c) {
    float len;
    unsigned int frames;
    int stride;
    unsigned int idx;
    int i0;
    float* base;
    int i1;
    c->t = 0.0f;
    c->done = 0;
    len = cSkaAnimData_GetFrameCount(cPointer_cSkaAnimData_opArrow(c));
    if (cSkaAnimData_IsLooping(cPointer_cSkaAnimData_opArrow(c))) {
        while (c->t >= len) {
            c->t -= len;
        }
    } else if (c->t >= len) {
        c->t = len;
        c->done = 1;
    }
    frames = cSkaAnimData_GetFrameCount(cPointer_cSkaAnimData_opArrow(c));
    stride = cSkaAnimData_GetFrameSize(cPointer_cSkaAnimData_opArrow(c));
    c->i10 = 0;
    base = cSkaAnimData_DataStart(cPointer_cSkaAnimData_opArrow(c));
    idx = nSFO_Macros_FTOI(c->t);
    i0 = idx * cSkaAnimData_GetFrameSize(cPointer_cSkaAnimData_opArrow(c));
    if (cSkaAnimData_IsLooping(cPointer_cSkaAnimData_opArrow(c))) {
        i1 = (idx < frames - 1) ? i0 + stride : 0;
    } else {
        i1 = (idx < frames) ? i0 + stride : i0;
    }
    c->frac = c->t - idx;
    c->a = base + i0;
    c->b = base + i1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190C70(void) {}
#undef nSFO_Macros_FTOI /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00190C70 */

/* merge_units: begin func_00190E50 */
#pragma push /* merge_units */
#include "float_to_int.h"

/* Convert a float to int. */
DEFINE_FLOAT_TO_INT(nSFO_Macros_FTOI)
static inline void merge_flush_func_00190E50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00190E50 */

/* merge_units: begin func_00190E60 */
#pragma push /* merge_units */
typedef struct { unsigned int kind; char pad[0x2C]; char a[0x10]; char b[0x30]; char c[1]; } O_190E60;
void* cSkaAnimData_DataStart(O_190E60* o)
{
    if (o->kind >= 3) return o->c;
    if (o->kind == 2) return o->b;
    return o->a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190E60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190E60 */

/* merge_units: begin func_00190EA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int cSkaAnimData_GetFrameSize(char* self) {
    return *(int*)(self + 8);
}

int cSkaAnimData_IsLooping(char* self) {
    return *(unsigned int*)(self + 16) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190EA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190EA0 */

/* merge_units: begin func_00190EC0 */
#pragma push /* merge_units */
typedef struct { int unk0; unsigned int count; int unk8; float scale; } ScaledCount;

/* Returns count (unsigned) * scale. */
float cSkaAnimData_GetDuration(ScaledCount* self)
{
    return (float)self->count * self->scale;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190EC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190EC0 */

/* merge_units: begin func_00190F00 */
#pragma push /* merge_units */
int cSkaAnimData_GetFrameCount(char* self) {
    return *(int*)(self + 4);
}

int cPointer_cSkaAnimData_opArrow(char* self) {
    return *(int*)(self + 0);
}

int* cPointer_cSkaAnimData_ctor(int* self, int value) {
    *self = value;
    return self;
}

int cSkeleton_GetSkeletonData(char* self) {
    return *(int*)(self + 0);
}

int cSkaParams_Skeleton(char* self) {
    return *(int*)(self + 32);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190F00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190F00 */

/* merge_units: begin func_00190F50 */
#pragma push /* merge_units */
typedef struct { int unk0; unsigned char disabled; } Item;
typedef struct { void* owner; } Holder;
extern int cSkaAnimationSet_GetNodeId(void* owner);
extern Item** cArray_cSkaNodePtr_opIndex(void* table, int key);

/* Looks up the owner's item; returns it unless it is disabled (then 0). */
Item* cSkaSystem_GetAnimation(Holder* self)
{
    char* owner = self->owner;
    Item* item = *cArray_cSkaNodePtr_opIndex(owner + 0x34, cSkaAnimationSet_GetNodeId(owner));
    return item->disabled == 0 ? item : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190F50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190F50 */

/* merge_units: begin func_00190F90 */
#pragma push /* merge_units */
typedef struct Rec14 {
    char b[0x14];
} Rec14;

typedef struct Tmp20 {
    char b[0x14];
} Tmp20;

typedef struct Holder_00190F90 {
    char pad[0x3C];
    char vec[4];
    int count;
    Rec14* data;
} Holder_00190F90;

extern void func_00191040(Tmp20*, int, int*);
extern void std_vector_imp_cTimedEvent_insert(void*, Rec14*, int, Tmp20*);

/* Builds a record from (a1, {a2, a3}) and appends it to the vector at +0x3C. */
Holder_00190F90* cSkaAnimCheckpoints_ScheduleEvent(Holder_00190F90* self, int a1, int a2, int a3) {
    Tmp20 rec;
    int pair[2];
    pair[0] = a2;
    pair[1] = a3;
    func_00191040(&rec, a1, pair);
    std_vector_imp_cTimedEvent_insert(self->vec, self->data + self->count, 1, &rec);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190F90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190F90 */
