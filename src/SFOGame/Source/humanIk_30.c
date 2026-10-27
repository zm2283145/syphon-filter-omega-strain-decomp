/*
 * SFOGame/Source/humanIk: 6 files, 001D7C90-001D81A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D7C90 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cJointInfo_dtor)
static inline void merge_flush_func_001D7C90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7C90 */

/* merge_units: begin func_001D7CE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

/* 16-byte member with an inline lq/sq assignment (gcc-style asm keeps the copy unfolded). */
struct QV7 {
    float x, y, z, w;
    QV7& operator=(const QV7& o)
    {
        const QV7* src = &o;
        QV7* dst = this;
        __int128 t;
        __asm__ volatile("lq %0,0(%1)" : "=r"(t) : "r"(src));
        __asm__ volatile("sq %0,0(%1)" : : "r"(t), "r"(dst) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct SB7 { float x, y, z; int pad; QV7 c; QV7 e; };

extern "C" SB7* cJointInfo_opAssign(SB7* d, const SB7* s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
    d->c = s->c;
    d->e = s->e;
    return d;
}
static inline void merge_flush_func_001D7CE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7CE0 */

/* merge_units: begin func_001D7D20 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_7D20;
typedef struct { float x, y, z; float pad; V4_7D20 q10; V4_7D20 q20; } T_7D20;
static inline V4_7D20 Neg_(V4_7D20* q) {
    V4_7D20 r = *q; V4_7D20* p = &r;
    asm {
        lqc2 vf1, 0x0(p)
        vsub.xyz vf1, vf0, vf1
        sqc2 vf1, 0x0(p)
    }
    return *p;
}
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
T_7D20* cJointInfo_ctor(T_7D20* d, T_7D20* s, V4_7D20* q) {
    d->x = s->x; d->y = s->y; d->z = s->z;
    { V4_7D20* t = &d->q10; *t = *q; }
    { V4_7D20 t; V4_7D20* tp; V4_7D20* dp; t = Neg_(q); dp = &d->q20; tp = &t; *dp = *tp; }
    return d;
}
#pragma pop
static inline void merge_flush_func_001D7D20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7D20 */

/* merge_units: begin func_001D7D90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cJointLimits_dtor)
static inline void merge_flush_func_001D7D90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7D90 */

/* merge_units: begin func_001D7DE0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
extern unsigned char D_004F47B8;
extern V4 D_004F2D90[];
extern char D_004F3030[], D_0048A3A0[], D_0048A400[], D_0048A460[], D_0048A4C0[], D_0048A520[], D_0048A580[], D_004F3180[], D_0048A5E0[], D_004F31E0[], D_0048A640[];
extern char D_0048A6A0[], D_0048A6C0[];
extern char D_0048A6E0[], D_0048A700[], D_0048A720[], D_0048A740[], D_0048A760[], D_0048A780[], D_0048A7A0[], D_0048A7C0[], D_0048A7E0[], D_0048A800[];
extern char D_0048A820[], D_0048A840[], D_0048A860[], D_0048A880[], D_0048A8A0[], D_0048A8C0[], D_0048A8E0[], D_0048A900[], D_0048A920[], D_0048A940[];
extern unsigned int D_0049F730[];
void ReorderList_uint_cQuaternionP_uintP(unsigned int, void*, unsigned int*);
void ReorderList_uint_cJointLimitsP_uintP(unsigned int, void*, unsigned int*);
void ReorderList_uint_floatP_uintP(unsigned int, void*, unsigned int*);
void ReorderList_uint_boolP_uintP(unsigned int, void*, unsigned int*);
void ReorderList_uint_eAnimSourceP_uintP(unsigned int, void*, unsigned int*);
void ReorderList_uint_eAnimSourceP_uintP_2(unsigned int, void*, unsigned int*);
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
void InitializeStaticDataIfNotInitialized(void) {
    int i;
    if (D_004F47B8) return;
    D_004F47B8 = 1;
    ReorderList_uint_cQuaternionP_uintP(21, D_004F2D90, D_0049F730);
    ReorderList_uint_cJointLimitsP_uintP(21, D_004F3030, D_0049F730);
    ReorderList_uint_floatP_uintP(21, D_0048A3A0, D_0049F730);
    ReorderList_uint_floatP_uintP(21, D_0048A400, D_0049F730);
    ReorderList_uint_floatP_uintP(21, D_0048A460, D_0049F730);
    ReorderList_uint_floatP_uintP(21, D_0048A4C0, D_0049F730);
    ReorderList_uint_floatP_uintP(21, D_0048A520, D_0049F730);
    ReorderList_uint_floatP_uintP(21, D_0048A580, D_0049F730);
    ReorderList_uint_floatP_uintP(21, D_004F3180, D_0049F730);
    ReorderList_uint_floatP_uintP(21, D_0048A5E0, D_0049F730);
    ReorderList_uint_floatP_uintP(21, D_004F31E0, D_0049F730);
    ReorderList_uint_floatP_uintP(21, D_0048A640, D_0049F730);
    ReorderList_uint_boolP_uintP(21, D_0048A6A0, D_0049F730);
    ReorderList_uint_boolP_uintP(21, D_0048A6C0, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP(21, D_0048A6E0, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP(21, D_0048A700, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP(21, D_0048A720, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP(21, D_0048A740, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP(21, D_0048A760, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP(21, D_0048A780, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP(21, D_0048A7A0, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP(21, D_0048A7C0, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP(21, D_0048A7E0, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP(21, D_0048A800, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP_2(21, D_0048A820, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP_2(21, D_0048A840, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP_2(21, D_0048A860, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP_2(21, D_0048A880, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP_2(21, D_0048A8A0, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP_2(21, D_0048A8C0, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP_2(21, D_0048A8E0, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP_2(21, D_0048A900, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP_2(21, D_0048A920, D_0049F730);
    ReorderList_uint_eAnimSourceP_uintP_2(21, D_0048A940, D_0049F730);
    for (i = 0; i < 21; i++) {
        if (D_004F2D90[i].w < 0.0f) {
            V4* p = &D_004F2D90[i];
            asm {
                lqc2 vf1, 0x0(p)
                vmulax.xyzw ACC, vf0, vf0x
                vmsubw.xyzw vf1, vf1, vf0w
                sqc2 vf1, 0x0(p)
            }
        }
    }
}
#pragma pop
static inline void merge_flush_func_001D7DE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7DE0 */

/* merge_units: begin func_001D81A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline void SetU(V* p) { __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(p) : "memory"); }
static inline V Unit() { V l0; SetU(&l0); return l0; }
struct CurveR { void* vt; char pad4[0xBC]; unsigned char bC0; char padC1[0xD0 - 0xC1]; };
struct EvR { void* vt; char pad4[0x20]; int f24; signed char b28; int f2c; signed char b30; int f34; };
struct SlotR { void* p; int pad; };
struct EntR;
struct SlotArr { SlotR e[25]; };
struct MRec { char pad[0x30]; };
struct LookR { signed char b0, b1, b2, b3; unsigned char b4; char pad5[0x6B]; };
struct SubR { char pad[0x1C0]; };
struct SubArr { SubR e[2]; unsigned char a, b; } __attribute__((aligned(16)));
struct ActorS {
    void* vt;
    int f4;
    unsigned char b8;
    int fc;
    int f10;
    SlotArr slots;
    int fdc;
    MRec recs[2];
    V v140;
    V v150;
    CurveR c160;
    CurveR c230;
    float f300, f304, f308, f30c;
    unsigned char b310, b311, b312, b313, b314;
    int f318, f31c;
    float f320;
    int f324, f328;
    EvR e32c;
    EvR e364;
    int f39c;
    LookR looks[2];
    V v480;
    V v490;
    SubArr subs;
    unsigned char b830, b831, b832, b833;
    signed char b834, b835;
    int f838;
    ActorS* Init();
};
struct EntR { char pad[0x50]; };
extern "C" {
extern char D_004DA830[];
extern char D_004DACF0[];
extern char D_004DA440[];
extern char D_004DA930[];
extern char D_00542B60[];
extern EntR SecondaryStateTable[];
extern signed char D_004E1D88;
extern V D_004E1D90;
void* __construct_array(void* a, void* ctor, void* dtor, unsigned int size, unsigned int n);
void func_001D8700(void);
void func_001B4C70(void);
void cSkaAnimDataIterator_ctor_void(void);
void cSkaAnimDataIterator_dtor(void);
void cIkTargetWithSplinedTransition_ctor(void);
void cIkTargetWithSplinedTransition_dtor(void);
void cQuaternion_GetIdentity(V* q);
void cQuaternion_GetZero(V* v);
void cSplinedMotion_cQuaternion_ctor(CurveR* c, V* q, V* v);
void cMessage_ctor_cMessageNameR(void* e, void* type);
void cArray_FixedSize_cAimComponent_2_ctor(LookR* l);
ActorS* cHumanIkRoutine_ctor(ActorS* self);
}
static inline void CurveCtor(CurveR* c0)
{
    CurveR* c = c0;
    V q;
    V v;
    cQuaternion_GetIdentity(&q);
    cQuaternion_GetZero(&v);
    cSplinedMotion_cQuaternion_ctor(c, &q, &v);
    c->vt = D_004DA440;
    c->bC0 = 0;
}
static inline void EvCtor(EvR* e)
{
    cMessage_ctor_cMessageNameR(e, D_00542B60);
    e->vt = D_004DA930;
    e->f24 = 0;
    e->b28 = 0;
    e->f2c = 0;
    e->b30 = 0;
    e->f34 = 0;
}
static inline void CC(ActorS* self)
{
    CurveCtor(&self->c160);
    CurveCtor(&self->c230);
}
static inline void CCW(ActorS* self) { CC(self); }
static inline const V& Zero()
{
    if (!D_004E1D88) {
        D_004E1D90.x = 0.0f;
        D_004E1D88 = 1;
        D_004E1D90.y = 0.0f;
        D_004E1D90.z = 0.0f;
        D_004E1D90.w = 0.0f;
    }
    return D_004E1D90;
}
#pragma opt_propagation off
static inline void SetS(SlotR* s, EntR* p) { s->p = p; }
static inline void SlotCtor(SlotArr* a)
{
    int i;
    SlotR* e = a->e;
    __construct_array(e, (void*)func_001D8700, (void*)func_001B4C70, 8, 25);
    for (i = 0; i < 25; i++) {
        if ((unsigned int)i >= 25)
            break;
        SetS(&e[i], &SecondaryStateTable[i]);
    }
}
static inline void SubCtor(SubArr* s)
{
    __construct_array(s->e, (void*)cIkTargetWithSplinedTransition_ctor, (void*)cIkTargetWithSplinedTransition_dtor, 0x1C0, 2);
    s->a = 0;
    s->b = 0;
}
inline ActorS* ActorS::Init()
{
    ActorS* self = this;
    self->vt = D_004DA830;
    self->f4 = 0;
    self->vt = D_004DACF0;
    self->b8 = 1;
    self->f10 = 0;
    SlotCtor(&self->slots);
    __construct_array(self->recs, (void*)cSkaAnimDataIterator_ctor_void, (void*)cSkaAnimDataIterator_dtor, 0x30, 2);
    self->v140 = Unit();
    self->v150 = Unit();
    CCW(self);
    self->f300 = 0.0f;
    self->f304 = 1.0f;
    self->f308 = 1.0f;
    self->f30c = 1.0f;
    self->b310 = 0;
    self->b311 = 0;
    self->b312 = 0;
    self->b313 = 0;
    self->b314 = 0;
    self->f318 = 0;
    self->f31c = 0;
    self->f320 = 0.4f;
    self->f324 = 0;
    self->f328 = 0;
    { EvR* e = &self->e32c; EvCtor(e); }
    { EvR* e = &self->e364; EvCtor(e); }
    cArray_FixedSize_cAimComponent_2_ctor(self->looks);
    self->v480 = Unit();
    self->v490 = Zero();
    { SubArr* p = &self->subs; SubCtor(p); }
    self->b830 = 0;
    self->b831 = 0;
    self->b832 = 6;
    self->b833 = 6;
    self->b834 = -1;
    self->b835 = -1;
    self->f838 = 0;
    self->looks[0].b0 = 14;
    self->looks[0].b1 = 0;
    self->looks[0].b2 = -1;
    self->looks[0].b3 = -1;
    self->looks[0].b4 = 0;
    self->looks[1].b0 = 14;
    self->looks[1].b1 = 9;
    self->looks[1].b2 = 5;
    self->looks[1].b3 = 14;
    self->looks[1].b4 = 1;
    return this;
}
ActorS* cHumanIkRoutine_ctor(ActorS* self)
{
    return self->Init();
}
static inline void merge_flush_func_001D81A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D81A0 */
