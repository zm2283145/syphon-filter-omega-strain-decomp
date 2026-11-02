/*
 * Libs/SFOLib/Source/ska: 14 files, 003B2540-003B36C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B2540 */
#pragma push /* merge_units */
#include "types.h"
typedef struct SkV4 { __int128 q; } SkV4;
typedef struct SkClip { unsigned int type; char p4[0x10]; unsigned char ux, uy, uz; char p17[0x11]; int has; char p2c[4]; SkV4 base; float off[4]; } SkClip;
extern signed char D_004E1D88;
extern SkV4 D_004E1D90;
#pragma peephole off
#pragma opt_propagation off
SkV4 cSkaAnimData_RootOffsetFromFirstFrameTranslation(SkClip* c) {
    if (c->type < 2) {
        if (!D_004E1D88) {
            ((int*)&D_004E1D90)[0] = 0;
            D_004E1D88 = 1;
            ((int*)&D_004E1D90)[1] = 0;
            ((int*)&D_004E1D90)[2] = 0;
            ((int*)&D_004E1D90)[3] = 0;
        }
        return D_004E1D90;
    }
    if (c->type == 2) return c->base;
    {
        SkV4 r; __int128* zp = &r.q; *zp = 0;
        if (c->has) {
            if (c->ux) ((float*)&r)[0] = c->off[0];
            if (c->uy) ((float*)&r)[1] = c->off[1];
            if (c->uz) ((float*)&r)[2] = c->off[2];
        }
        return r;
    }
}
#pragma opt_propagation reset
#pragma peephole reset
static inline void merge_flush_func_003B2540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B2540 */

/* merge_units: begin func_003B2630 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

void* cVector_Z_void_2(char* self) {
    return self + 8;
}

/* Clip root-motion axis Z flag set. */
int cSkaAnimData_RootHasDeltaTranslationZ(SkaClipFlags* clip) {
    return 0U < clip->axisZ;
}

void* cVector_Y_void_2(char* self) {
    return self + 4;
}

/* Clip root-motion axis Y flag set. */
int cSkaAnimData_RootHasDeltaTranslationY(SkaClipFlags* clip) {
    return 0U < clip->axisY;
}

/* Clip root-motion axis X flag set. */
int cSkaAnimData_RootHasDeltaTranslationX(SkaClipFlags* clip) {
    return 0U < clip->axisX;
}

void* cVector_X_void_2(void* self) {
    return self;
}

Iter16* cSkaAnimDataFrame_ConstIterator_opInc(Iter16* it) {
    it->p += 16;
    return it;
}
static inline void merge_flush_func_003B2630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B2630 */

/* merge_units: begin func_003B26B0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void cSkaAnim_LerpXYZ(V4* a, V4* b, V4* c, V4* d, V4* e) {
    asm {
        lqc2 vf1, 0x0(c)
        lqc2 vf2, 0x0(d)
        lqc2 vf3, 0x0(e)
        vmulax.xyz ACC, vf2, vf3x
        vmaddy.xyz vf4, vf1, vf3y
        vaddx.w vf4, vf1, vf0x
        sqc2 vf4, 0x0(b)
    }
}
static inline void merge_flush_func_003B26B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B26B0 */

/* merge_units: begin func_003B26D0 */
#pragma push /* merge_units */
int cSkaAnimDataFrame_ConstIterator_Vector(char* self) {
    return *(int*)(self + 0);
}
static inline void merge_flush_func_003B26D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B26D0 */

/* merge_units: begin func_003B26E0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
typedef __int128 Q128;
Q128 *cVector_SetZero(Q128 *arg0) {
    *arg0 = 0;
    return arg0;
}
static inline void merge_flush_func_003B26E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B26E0 */

/* merge_units: begin func_003B26F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


int cPointer_cSkaAnimData_opCast_constcSkaAnimDataPtr(char* self) {
    return *(int*)(self + 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B26F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B26F0 */

/* merge_units: begin func_003B2700 */
#pragma push /* merge_units */
typedef struct SkaClip {
    char pad[0x40];
    int grouping;
} SkaClip;

typedef struct GroupingPair {
    SkaClip* clip;
    int grouping;
} GroupingPair;

/* Fills (clip, grouping); clip is NULL unless the clip's grouping is -1. */
void cSkaAnim_PlaybackGroupId(GroupingPair* out, SkaClip* clip) {
    out->clip = clip->grouping == -1 ? clip : 0;
    out->grouping = clip->grouping;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B2700(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B2700 */

/* merge_units: begin func_003B2730 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#include "alloc_guard.h"
extern "C" char D_004DFC50[];
extern void * const D_004DFC30[];
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline V Unit() { V l0; __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(&l0) : "memory"); return l0; }
struct F2 { float a, b; F2() {} };
struct ClipBase {
    void* vt;
    signed char b4;
    V v10;
    ClipBase() {}
    ~ClipBase() { vt = D_004DFC50; }
    ClipBase& operator=(const ClipBase& o) { b4 = o.b4; v10 = o.v10; return *this; }
};
struct SkaClip_003B2730 : ClipBase {
    int f20;
    void* clip;
    unsigned char b28, b29;
    F2 r2c;
    float f34, f38, f3c;
    int f40;
    signed char b44;
    unsigned char b45, b46;
    SkaClip_003B2730() {}
    ~SkaClip_003B2730() { vt = (void*)D_004DFC30; }
};
static inline V QMulR(const V* a, const V* b) {
    V r;
    __asm__ volatile("lqc2 vf1, 0x0(%0)\nlqc2 vf2, 0x0(%1)\nvmul.xyzw vf3, vf1, vf2\nvopmula.xyz ACC, vf1, vf2\nvmaddaw.xyz ACC, vf1, vf2w\nvmaddaw.xyz ACC, vf2, vf1w\nvopmsub.xyz vf4, vf2, vf1\nvsubaz.w ACC, vf3, vf3z\nvmsubay.w ACC, vf0, vf3y\nvmsubx.w vf4, vf0, vf3x\nsqc2 vf4, 0x0(%2)" : : "r"(a), "r"(b), "r"(&r) : "memory");
    return r;
}

static inline bool IsUnit(const V& v) { return 1.0f == v.w; }
static inline bool NotUnit(const V& v) { return !IsUnit(v); }
struct AnimContribution { char pad[0x20]; };
struct Ctx { char pad[0x14]; char stack[4]; };
extern "C" float D_004BCD68;
extern "C" void cSkaPlaybackItem_ctor(AnimContribution* c, SkaClip_003B2730* clip, const V* q, float w);
extern "C" int AnimContext_GetCount(void* s);
extern "C" void** PtrStack_Top(void* s);
extern "C" void* AnimBlend_GetGroupCollection(void* b);
extern "C" void cSkaPlaybackList_Add(void* g, AnimContribution* c, int id, float w);
extern "C" void cSkaPlaybackItem_dtor(AnimContribution* c, int f);
static inline void Submit(SkaClip_003B2730* self, const V* r, Ctx* ctx, float w)
{
    int id = self->f40;
    float wt = self->f3c;
    if (AnimContext_GetCount(ctx->stack)) {
        void* blend = *PtrStack_Top(ctx->stack);
        if (blend) {
            AnimContribution c;
            cSkaPlaybackItem_ctor(&c, self, r, w);
            cSkaPlaybackList_Add(AnimBlend_GetGroupCollection(blend), &c, id, wt);
            cSkaPlaybackItem_dtor(&c, -1);
        }
    }
}
static inline void Submit2(SkaClip_003B2730* self, const V* r, Ctx* ctx, float w) { Submit(self, r, ctx, w); }
static inline const V* In1(const V* a, const V* b) { if (NotUnit(*a)) { V x(QMulR(a, b)); V t(x); return &t; } return b; }
extern "C" void cSkaAnim_UpdateNodes(SkaClip_003B2730* self, const V* q, Ctx* ctx, float w)
{
    if (w < D_004BCD68)
        return;
    bool b = !IsUnit(self->v10);
    q = b ? In1(q, &self->v10) : q;
    { const V* r = q; Submit2(self, r, ctx, w); }
}
static inline void merge_flush_func_003B2730(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B2730 */

/* merge_units: begin func_003B28F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
#if 0 /* merge_units */
extern "C" void cSkaAnim_PlaybackGroupId();
#endif /* merge_units */

#if 0 /* merge_units */
extern "C" void cSkaAnim_UpdateNodes();
#endif /* merge_units */

extern "C" VtableChainObject* cSkaAnim_dtor(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DFC30);
        if (self)
            self->vtable = D_004DFC50;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DFC30[8] = { (void*)0x0, (void*)0x0, (void*)cSkaAnim_dtor, (void*)cSkaAnim_UpdateNodes, (void*)cSkaAnim_PlaybackGroupId, (void*)0x0, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_003B28F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B28F0 */

/* merge_units: begin func_003B2950 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
struct Qt {
    float x, y, z, w;
    Qt() {}
    Qt(const Qt& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(&o), "r"(this) : "memory"); }
    Qt operator*(const Qt& b) const {
        Qt c; Qt* d = &c; const Qt* l = this; const Qt* r = &b;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
    Qt& operator=(const Qt& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline Qt Ident() { Qt a; __asm__ volatile("sqc2 $vf0, 0x0(%0)" : : "r"(&a) : "memory"); return a; }
#if 0 /* merge_units */
extern "C" char D_004DFC30[];
#endif /* merge_units */
#define D_004DFC30 ((char*)&D_004DFC30) /* merge_units */

struct T {
    void* vt; unsigned char b4; char pad5[11]; Qt q;
    int f20, f24; unsigned char f28, f29; char pad2a[2];
    float f2c, f30, f34, f38, f3c; int f40; unsigned char f44, f45, f46;
};
extern "C" T* cSkaAnim_ctor_eType_cSkaAnimR_eAxisOfMotion_bool(T* d, unsigned char a1, T* s, unsigned char a3, unsigned char t0);
T* cSkaAnim_ctor_eType_cSkaAnimR_eAxisOfMotion_bool(T* d, unsigned char a1, T* s, unsigned char a3, unsigned char t0)
{
    Qt b(Ident());
    d->vt = D_004DFC50;
    d->b4 = a1;
    d->q = b * s->q;
    d->vt = D_004DFC30;
    d->f20 = s->f20; d->f24 = s->f24; d->f28 = s->f28; d->f29 = s->f29;
    d->f2c = s->f2c; d->f30 = s->f30; d->f34 = s->f34; d->f38 = s->f38; d->f3c = s->f3c;
    d->f40 = s->f40; d->f44 = a3; d->f45 = s->f45; d->f46 = t0;
    return d;
}
#undef D_004DFC30 /* merge_units */
static inline void merge_flush_func_003B2950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B2950 */

/* merge_units: begin func_003B2A60 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on


struct V_003B2A60 {
    float x, y, z, w;
    V_003B2A60() {}
    V_003B2A60(const V_003B2A60& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V_003B2A60 operator*(const V_003B2A60& b) const {
        V_003B2A60 c; V_003B2A60* d = &c; const V_003B2A60* l = this; const V_003B2A60* r = &b;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
    V_003B2A60& operator=(const V_003B2A60& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct ClipBase_003B2A60 {
    void* vt;
    signed char b4;
    V_003B2A60 v10;
    ClipBase_003B2A60() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ClipBase_003B2A60() { vt = D_004DFC50; }
    ClipBase_003B2A60& operator=(const ClipBase_003B2A60& o) { b4 = o.b4; v10 = o.v10; return *this; }
};
struct SkaClip_003B2A60 : ClipBase_003B2A60 {
    int f20;
    void* clip;
    unsigned char b28, b29;
    F2 r2c;
    float f34, f38, f3c;
    int f40;
    signed char b44;
    unsigned char b45, b46;
    SkaClip_003B2A60() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~SkaClip_003B2A60() { vt = (void*)D_004DFC30; }
};
extern "C" float Libc_Sinf(float);
extern "C" float Libc_Cosf(float);
extern "C" SkaClip_003B2A60* cSkaAnim_ctor_cSkaAnimR_eModifier_cEulerAngleTR_eAxisOfMotion(SkaClip_003B2A60* self, SkaClip_003B2A60* src, int a, const float* ang, signed char s)
{
    float hx = 0.5f * ang[0];
    float hy = 0.5f * ang[1];
    float hz = 0.5f * ang[2];
    float cx = Libc_Cosf(hx);
    float cy = Libc_Cosf(hy);
    float cz = Libc_Cosf(hz);
    float sx = Libc_Sinf(hx);
    float sy = Libc_Sinf(hy);
    float sz = Libc_Sinf(hz);
    V_003B2A60 q;
    q.w = cx * (cy * cz) - sx * (sy * sz);
    q.x = sx * (cy * cz) - cx * (sy * sz);
    q.y = cx * (sy * cz) + sx * (cy * sz);
    q.z = cx * (cy * sz) + sx * (sy * cz);
    self->vt = D_004DFC50;
    self->b4 = src->b4;
    self->v10 = q * src->v10;
    self->vt = (void*)D_004DFC30;
    self->f20 = src->f20;
    self->clip = src->clip;
    self->b28 = src->b28;
    self->b29 = src->b29;
    self->r2c.a = src->r2c.a;
    self->r2c.b = src->r2c.b;
    self->f34 = src->f34;
    self->f38 = src->f38;
    self->f3c = src->f3c;
    self->f40 = src->f40;
    self->b44 = s;
    self->b45 = src->b45;
    self->b46 = src->b46;
    return self;
}
static inline void merge_flush_func_003B2A60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B2A60 */

/* merge_units: begin func_003B2C50 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on

struct V_003B2C50 {
    float x, y, z, w;
    V_003B2C50() {}
    V_003B2C50(const V_003B2C50& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(&o), "r"(this) : "memory"); }
    V_003B2C50 operator*(const V_003B2C50& b) const {
        V_003B2C50 c; V_003B2C50* d = &c; const V_003B2C50* l = this; const V_003B2C50* r = &b;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
    V_003B2C50& operator=(const V_003B2C50& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline V_003B2C50 Unit_003B2C50() { V_003B2C50 l0; __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(&l0) : "memory"); return l0; }
struct ClipBase_003B2C50 {
    void* vt;
    signed char b4;
    V_003B2C50 v10;
    ClipBase_003B2C50() {}
    ~ClipBase_003B2C50() { vt = D_004DFC50; }
    ClipBase_003B2C50& operator=(const ClipBase_003B2C50& o) { b4 = o.b4; v10 = o.v10; return *this; }
};
struct SkaClip_003B2C50 : ClipBase_003B2C50 {
    int f20;
    void* clip;
    unsigned char b28, b29;
    F2 r2c;
    float f34, f38, f3c;
    int f40;
    signed char b44;
    unsigned char b45, b46;
    SkaClip_003B2C50() {}
    ~SkaClip_003B2C50() { vt = (void*)D_004DFC30; }
};
extern "C" float Libc_Fmodf(float x, float y);
extern "C" SkaClip_003B2C50* cSkaAnim_ctor_cSkaAnimR_eModifier(SkaClip_003B2C50* self, const SkaClip_003B2C50* o, unsigned char mode)
{
    V_003B2C50 u(Unit_003B2C50());
    self->vt = D_004DFC50;
    self->b4 = o->b4;
    self->v10 = u * o->v10;
    self->vt = (void*)D_004DFC30;
    self->f20 = o->f20;
    self->clip = o->clip;
    self->b28 = o->b28;
    self->b29 = o->b29;
    self->r2c.a = o->r2c.a;
    self->r2c.b = o->r2c.b;
    self->f34 = o->f34;
    self->f38 = o->f38;
    self->f3c = o->f3c;
    self->f40 = o->f40;
    self->b44 = o->b44;
    self->b45 = o->b45;
    self->b46 = o->b46;
    switch (mode) {
    case 0:
        break;
    case 1:
        self->b28 = !o->b28;
        break;
    case 2:
        self->b29 = !o->b29;
        break;
    case 3:
        self->b29 = !o->b29;
        self->f34 = Libc_Fmodf(0.5f + o->f34, 1.0f);
        break;
    }
    return self;
}
static inline void merge_flush_func_003B2C50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B2C50 */

/* merge_units: begin func_003B2E10 */
#pragma push /* merge_units */
#pragma cplusplus on

/* ska clip copies (siblings of cSkaAnim_ctor_cSkaAnimR_bool_bool_float_etc): rotate the source clip's quaternion by the euler
 * angles, flip the direction flags and set the playback sub-range - cSkaAnim_ctor_cSkaAnimR_bool_bool_cSkaAnimPlaybackRangeR_etc from a frame range
 * normalised by the animation length, cSkaAnim_ctor_cSkaAnimR_bool_bool_cSkaAnimPlaybackRangeNormalizedR_etc as a sub-range of the source clip's range
 * (mirrored when the clip runs backwards). */
#pragma always_inline on

struct V_003B2E10 {
    float x, y, z, w;
    V_003B2E10() {}
    V_003B2E10(const V_003B2E10& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V_003B2E10 operator*(const V_003B2E10& b) const {
        V_003B2E10 c; V_003B2E10* d = &c; const V_003B2E10* l = this; const V_003B2E10* r = &b;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
    V_003B2E10& operator=(const V_003B2E10& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline float Clamp01(float x) { float r = 0.0f; float hi = 1.0f; float lo = 0.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline float ClampLo(float x, float lo) { float r = 0.0f; float hi = 1.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }
/* same clamps with the bounds declared in the other order (cSkaAnim_ctor_cSkaAnimR_bool_bool_cSkaAnimPlaybackRangeNormalizedR_etc's register choice) */
static inline float Sat01(float x) { float r = 0.0f; float lo = 0.0f; float hi = 1.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline float SatLo(float x, float lo) { float r = 0.0f; float hi = 1.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }

struct F2_003B2E10 {
    float a, b;
    F2_003B2E10() {}
    float Span() const { return b - a; }
    void Mirror() { F2_003B2E10 o = *this; a = 1.0f - o.b; b = 1.0f - o.a; }
    void Lerp(const F2_003B2E10& p) { float a0 = a; float s = b - a; a = a0 + s * p.a; b = a0 + s * p.b; }
    void Fix2() { a = Sat01(a); b = SatLo(b, a); }
    void Fix() { a = Clamp01(a); b = ClampLo(b, a); }
};
struct SkaAnim { int pad0; unsigned int count; int pad8; float dur; };
static inline float Length(SkaAnim* c) { return (float)c->count * c->dur; }
struct ClipBase_003B2E10 {
    void* vt;
    signed char b4;
    V_003B2E10 v10;
    ClipBase_003B2E10() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ClipBase_003B2E10() { vt = D_004DFC50; }
    ClipBase_003B2E10& operator=(const ClipBase_003B2E10& o) { b4 = o.b4; v10 = o.v10; return *this; }
};
struct SkaClip_003B2E10 : ClipBase_003B2E10 {
    int f20;
    SkaAnim* clip;
    unsigned char b28, b29;
    F2_003B2E10 r2c;
    float f34, f38, f3c;
    int f40;
    signed char b44;
    unsigned char b45, b46;
    SkaClip_003B2E10() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~SkaClip_003B2E10() { vt = (void*)D_004DFC30; }
};
extern "C" SkaClip_003B2E10* cSkaAnim_ctor_cSkaAnimR_bool_bool_cSkaAnimPlaybackRangeR_etc(SkaClip_003B2E10* self, SkaClip_003B2E10* src, bool a, bool b, float g, const float* range, const float* ang, int id, signed char s, unsigned char mode)
{
    float hx = 0.5f * ang[0];
    float hy = 0.5f * ang[1];
    float hz = 0.5f * ang[2];
    float cx = Libc_Cosf(hx);
    float cy = Libc_Cosf(hy);
    float cz = Libc_Cosf(hz);
    float sx = Libc_Sinf(hx);
    float sy = Libc_Sinf(hy);
    float sz = Libc_Sinf(hz);
    V_003B2E10 q;
    q.w = cx * (cy * cz) - sx * (sy * sz);
    q.x = sx * (cy * cz) - cx * (sy * sz);
    q.y = cx * (sy * cz) + sx * (cy * sz);
    q.z = cx * (cy * sz) + sx * (sy * cz);
    self->vt = D_004DFC50;
    self->b4 = src->b4;
    {
        V_003B2E10 t = q * src->v10;
        self->v10 = t;
    }
    self->vt = (void*)D_004DFC30;
    self->f20 = src->f20;
    self->clip = src->clip;
    self->b28 = (src->b28 && !a) || (!src->b28 && a);
    self->b29 = (src->b29 && !b) || (!src->b29 && b);
    {
        F2_003B2E10 r;
        float n = Length(src->clip);
        if (n != 0.0f) {
            float lo = range[0];
            float inv = 1.0f / n;
            r.a = inv * lo;
            r.b = inv * range[1];
            r.Fix();
        } else {
            r.a = 0.0f;
            r.b = 1.0f;
        }
        self->r2c.a = r.a;
        self->r2c.b = r.b;
    }
    self->f34 = src->f34;
    self->f38 = src->f38 * g;
    self->f3c = self->f38 * Length(src->clip) * self->r2c.Span();
    self->f40 = id;
    self->b44 = s;
    self->b45 = src->b45;
    self->b46 = src->b46;
    switch (mode) {
    case 0:
        break;
    case 1:
        self->b45 = 1;
        break;
    default:
        break;
    }
    return self;
}

extern "C" SkaClip_003B2E10* cSkaAnim_ctor_cSkaAnimR_bool_bool_cSkaAnimPlaybackRangeNormalizedR_etc(SkaClip_003B2E10* self, SkaClip_003B2E10* src, bool a, bool b, float g, const float* range, const float* ang, int id, signed char s, unsigned char mode)
{
    float hx = 0.5f * ang[0];
    float hy = 0.5f * ang[1];
    float hz = 0.5f * ang[2];
    float cx = Libc_Cosf(hx);
    float cy = Libc_Cosf(hy);
    float cz = Libc_Cosf(hz);
    float sx = Libc_Sinf(hx);
    float sy = Libc_Sinf(hy);
    float sz = Libc_Sinf(hz);
    V_003B2E10 q;
    q.w = cx * (cy * cz) - sx * (sy * sz);
    q.x = sx * (cy * cz) - cx * (sy * sz);
    q.y = cx * (sy * cz) + sx * (cy * sz);
    q.z = cx * (cy * sz) + sx * (sy * cz);
    self->vt = D_004DFC50;
    self->b4 = src->b4;
    {
        V_003B2E10 t = q * src->v10;
        self->v10 = t;
    }
    self->vt = (void*)D_004DFC30;
    self->f20 = src->f20;
    self->clip = src->clip;
    self->b28 = (src->b28 && !a) || (!src->b28 && a);
    self->b29 = (src->b29 && !b) || (!src->b29 && b);
    {
        F2_003B2E10 res;
        F2_003B2E10 t;
        F2_003B2E10 cur;
        const F2_003B2E10* pr;
        if (src->b28) {
            F2_003B2E10 x = *(const F2_003B2E10*)range;
            x.Mirror();
            x.Fix2();
            t = x;
            pr = &t;
        } else {
            pr = (const F2_003B2E10*)range;
        }
        cur = src->r2c;
        cur.Lerp(*pr);
        cur.Fix2();
        {
            const F2_003B2E10& c = cur; /* through a reference: retail copies cur via a pointer register */
            res = c;
            self->r2c.a = res.a;
            self->r2c.b = res.b;
        }
    }
    self->f34 = src->f34;
    self->f38 = src->f38 * g;
    self->f3c = src->f3c * g * ((const F2_003B2E10*)range)->Span();
    self->f40 = id;
    self->b44 = s;
    self->b45 = src->b45;
    self->b46 = src->b46;
    switch (mode) {
    case 0:
        break;
    case 1:
        self->b45 = 1;
        break;
    default:
        break;
    }
    return self;
}
static inline void merge_flush_func_003B2E10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B2E10 */

/* merge_units: begin func_003B36C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on

struct V_003B36C0 {
    float x, y, z, w;
    V_003B36C0() {}
    V_003B36C0(const V_003B36C0& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V_003B36C0 operator*(const V_003B36C0& b) const {
        V_003B36C0 c; V_003B36C0* d = &c; const V_003B36C0* l = this; const V_003B36C0* r = &b;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
    V_003B36C0& operator=(const V_003B36C0& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct ClipBase_003B36C0 {
    void* vt;
    signed char b4;
    V_003B36C0 v10;
    ClipBase_003B36C0() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ClipBase_003B36C0() { vt = D_004DFC50; }
    ClipBase_003B36C0& operator=(const ClipBase_003B36C0& o) { b4 = o.b4; v10 = o.v10; return *this; }
};
struct SkaClip_003B36C0 : ClipBase_003B36C0 {
    int f20;
    void* clip;
    unsigned char b28, b29;
    F2 r2c;
    float f34, f38, f3c;
    int f40;
    signed char b44;
    unsigned char b45, b46;
    SkaClip_003B36C0() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~SkaClip_003B36C0() { vt = (void*)D_004DFC30; }
};
#if 0 /* merge_units */
extern "C" float Libc_Fmodf(float, float);
#endif /* merge_units */
#define Libc_Fmodf(a0, a1) (Libc_Fmodf((a0), (a1))) /* merge_units */

extern "C" SkaClip_003B36C0* cSkaAnim_ctor_cSkaAnimR_bool_bool_float_etc(SkaClip_003B36C0* self, SkaClip_003B36C0* src, bool a, bool b, float f, float g, const float* ang, int id, signed char s, unsigned char mode)
{
    float hx = 0.5f * ang[0];
    float hy = 0.5f * ang[1];
    float hz = 0.5f * ang[2];
    float cx = Libc_Cosf(hx);
    float cy = Libc_Cosf(hy);
    float cz = Libc_Cosf(hz);
    float sx = Libc_Sinf(hx);
    float sy = Libc_Sinf(hy);
    float sz = Libc_Sinf(hz);
    V_003B36C0 q;
    q.w = cx * (cy * cz) - sx * (sy * sz);
    q.x = sx * (cy * cz) - cx * (sy * sz);
    q.y = cx * (sy * cz) + sx * (cy * sz);
    q.z = cx * (cy * sz) + sx * (sy * cz);
    self->vt = D_004DFC50;
    self->b4 = src->b4;
    {
        V_003B36C0 t = q * src->v10;
        self->v10 = t;
    }
    self->vt = (void*)D_004DFC30;
    self->f20 = src->f20;
    self->clip = src->clip;
    self->b28 = (src->b28 && !a) || (!src->b28 && a);
    self->b29 = (src->b29 && !b) || (!src->b29 && b);
    self->r2c.a = src->r2c.a;
    self->r2c.b = src->r2c.b;
    self->f34 = Libc_Fmodf(src->f34 + (src->b28 ? 1.0f - f : f), 1.0f);
    self->f38 = src->f38 * g;
    self->f3c = src->f3c * g * (src->r2c.b - src->r2c.a);
    self->f40 = id;
    self->b44 = s;
    self->b45 = src->b45;
    self->b46 = src->b46;
    switch (mode) {
    case 0:
        break;
    case 1:
        self->b45 = 1;
        break;
    default:
        break;
    }
    return self;
}
#undef Libc_Fmodf /* merge_units */
static inline void merge_flush_func_003B36C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B36C0 */
