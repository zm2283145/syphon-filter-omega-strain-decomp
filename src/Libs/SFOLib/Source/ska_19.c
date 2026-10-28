/*
 * Libs/SFOLib/Source/ska: 11 files, 003B1420-003B1710
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B1420 */
#pragma push /* merge_units */
#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma opt_common_subs off
V4 cQuaternion_opAdd_cQuaternionR(V4* b, V4* c) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(q1)
    }
    return l0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B1420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B1420 */

/* merge_units: begin func_003B1450 */
#pragma push /* merge_units */
typedef struct { int f0; float s; unsigned char on; char pad[7]; V4 v; } S_3B1450;
static inline V4 Scale_(V4* v, float s) {
    V4 r;
    V4* q = &r;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(v)
        mfc1 t, s
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(q)
        
    }
    return *q;
}
#pragma push
#pragma peephole off

V4 cSkaPlaybackItem_GetSummedOffsetRootRotation(S_3B1450* p) {
    if (p->on) return Scale_(&p->v, p->s);
    return p->v;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B1450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B1450 */

/* merge_units: begin func_003B14A0 */
#pragma push /* merge_units */
typedef struct { int id; float weight; unsigned char active; char pad[7]; Vec4 v; } AC_3B14A0;
AC_3B14A0* cSkaPlaybackItem_opAssign(AC_3B14A0* self, AC_3B14A0* o) {
    self->id = o->id;
    self->weight = o->weight;
    self->active = o->active;
    { typedef char uf_chk_[sizeof(self->v) == 16 ? 1 : -1]; VCopyF(&(self->v), &(o->v)); }
    return self;
}
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B14A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B14A0 */

/* merge_units: begin func_003B14D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


void* std_vector_deleter_cSkaPlaybackItem_data(char* self) {
    return self + 8;
}
static inline void merge_flush_func_003B14D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B14D0 */

/* merge_units: begin func_003B14E0 */
#pragma push /* merge_units */
typedef struct { float a; float b; unsigned char c; } S_3B14E0;
static inline float clamp_3B14E0(float x, float lo, float hi) { asm { max.s lo, x, lo
 min.s lo, lo, hi } return lo; }
S_3B14E0* cSkaPlaybackGroup_cPlaybackPosWithHistory_ctor(S_3B14E0* s, float x)
{
    float v;
    s->c = 1;
    v = clamp_3B14E0(x, 0.0f, 1.0f);
    s->b = v;
    s->a = v;
    return s;
}
static inline void merge_flush_func_003B14E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B14E0 */

/* merge_units: begin func_003B1510 */
#pragma push /* merge_units */
#include "ska_types.h"

#if 0 /* merge_units */
Rel* std_vector_imp_cSkaPlaybackItem_ctor(Rel* r); /* gsynth: defined below */
#endif /* merge_units */
Rel * std_vector_imp_cSkaPlaybackItem_ctor(); /* merge_units */
typedef struct { char pad[0xC]; unsigned char flag; } S;
#if 0 /* merge_units */
extern void std_vector_imp_cSkaPlaybackItem_ctor(S*);
#endif /* merge_units */
Rel * std_vector_imp_cSkaPlaybackItem_ctor(); /* merge_units */



extern void std_vector_imp_cSkaPlaybackItem_reserve(S*, int);
/* Constructor: base init, sets value from *v, stores flag. */
S* cArray_cSkaPlaybackItem_ctor(S* s, int* v, unsigned char flag) { std_vector_imp_cSkaPlaybackItem_ctor(s); std_vector_imp_cSkaPlaybackItem_reserve(s, *v); s->flag = flag; return s; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B1510(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B1510 */

/* merge_units: begin func_003B1560 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


extern int std_vector_imp_cSkaPlaybackItem_insert(SkaVec* v, char* pos, int n, int value);

Rel* std_vector_imp_cSkaPlaybackItem_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

unsigned char cSkaAnim_IsLooping(unsigned char* self) {
    return self[69];
}

/* Append one 32-byte element at the end of the array. */
int cArray_cSkaPlaybackItem_PushBackActual(SkaVec* v, int value) {
    int count = v->count;
    char* data = v->data;
    return std_vector_imp_cSkaPlaybackItem_insert(v, data + (count << 5), 1, value);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B1560(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B1560 */

/* merge_units: begin func_003B15B0 */
#pragma push /* merge_units */
/* cSkaPlaybackItem::Accumulate: first contribution is copied; otherwise summed root rotations (weighted when still unweighted) and weights. Dead 'xx = this' locals keep retail's dead addius. */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#pragma peephole off
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V& operator=(const V& o) { void* xx = this; V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
    V operator*(float k) const;
    V operator+(const V& o) const;
} __attribute__((aligned(16)));
static inline void ScaleTo(V* d, const V* s, float k) { int r; const V* ss = s; asm {
        .set noreorder
        lqc2 vf1, 0x0(ss)
        mfc1 r, k
        qmtc2.ni r, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(d)
        .set reorder
    } }
static inline void AddTo(V* d, const V* a, const V* b) { asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    } }
inline V V::operator*(float k) const { V t; ScaleTo(&t, this, k); return t; }
inline V V::operator+(const V& o) const { V t; AddTo(&t, this, &o); return t; }
struct cSkaPlaybackItem {
    void* mAnimation;
    float mSummedWeight;
    unsigned char mIsSummedOffsetRootRotationUnweightedAndNormalized;
    V mSummedOffsetRootRotation;
    V GetWeighted() const {
        if (mIsSummedOffsetRootRotationUnweightedAndNormalized)
            return mSummedOffsetRootRotation * mSummedWeight;
        return mSummedOffsetRootRotation;
    }
};
extern "C" void cSkaPlaybackItem_Accumulate(cSkaPlaybackItem* self, const cSkaPlaybackItem* contribution)
{
    if (self->mSummedWeight == 0.0f) {
        *self = *contribution;
    } else {
        self->mSummedOffsetRootRotation = self->GetWeighted() + contribution->GetWeighted();
        self->mSummedWeight += contribution->mSummedWeight;
        self->mIsSummedOffsetRootRotationUnweightedAndNormalized = 0;
    }
}
static inline void merge_flush_func_003B15B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B15B0 */

/* merge_units: begin func_003B1710 */
#pragma push /* merge_units */
/* Iterator equality. */
int cSkaPlaybackItem_HasSameAnimation(Iter* a, Iter* b) {
    return a->p == b->p;
}

void* AnimBlend_GetGroupCollection(char* self) {
    return self + 232;
}
static inline void merge_flush_func_003B1710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B1710 */

/* merge_units: begin func_003B1740 */
#pragma push /* merge_units */
typedef struct AC_3B1740 { int id; float weight; unsigned char active; char pad[7]; Vec4 v; } AC_3B1740;
/* Initialises an animation contribution record and returns it. */
#pragma peephole off
AC_3B1740* cSkaPlaybackItem_ctor(AC_3B1740* self, int id, float weight, Vec4* v) {
    self->id = id;
    self->weight = weight;
    self->active = 1;
    self->v = *v;
    return self;
}
#pragma peephole reset
static inline void merge_flush_func_003B1740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B1740 */

/* merge_units: begin func_003B1770 */
#pragma push /* merge_units */
void** PtrStack_Top(PtrStack* s) {
    return &s->items[s->count - 1];
}

int AnimContext_GetCount(char* self) {
    return *(int*)(self + 0);
}

float cSkaSliderValue_opCast_float(char* self) {
    return *(float*)(self + 8);
}

/* Address of element i in an array of 60-byte elements. */
char* cArray_cSkaSliderValue_opIndex(SkaVec* v, int i) {
    return v->data + i * 60;
}
static inline void merge_flush_func_003B1770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B1770 */
