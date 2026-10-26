#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
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
void Secondary_MotionRecordCtor(void);
void Secondary_MotionRecordDtor(void);
void cIkTargetWithSplinedTransition_ctor(void);
void cIkTargetWithSplinedTransition_dtor(void);
void Quat_SetIdentity(V* q);
void cQuaternion_GetZero(V* v);
void CameraCurve_MakeQuaternion(CurveR* c, V* q, V* v);
void Event_Construct(void* e, void* type);
void UpperBodyLook_ClearRecords(LookR* l);
ActorS* ActorSecondary_Ctor(ActorS* self);
}
static inline void CurveCtor(CurveR* c0)
{
    CurveR* c = c0;
    V q;
    V v;
    Quat_SetIdentity(&q);
    cQuaternion_GetZero(&v);
    CameraCurve_MakeQuaternion(c, &q, &v);
    c->vt = D_004DA440;
    c->bC0 = 0;
}
static inline void EvCtor(EvR* e)
{
    Event_Construct(e, D_00542B60);
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
    __construct_array(self->recs, (void*)Secondary_MotionRecordCtor, (void*)Secondary_MotionRecordDtor, 0x30, 2);
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
    UpperBodyLook_ClearRecords(self->looks);
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
ActorS* ActorSecondary_Ctor(ActorS* self)
{
    return self->Init();
}
