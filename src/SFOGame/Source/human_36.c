/*
 * SFOGame/Source/human: 13 files, 001906B0-00190990
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
