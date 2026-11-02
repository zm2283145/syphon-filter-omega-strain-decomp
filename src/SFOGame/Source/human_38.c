/*
 * SFOGame/Source/human: 11 files, 001B5560-001B5E20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B5560 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
class Vis {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsOn();
};
struct Phys {
    char pad0[4];
    void* w4;
    void* w8;
    void* wC;
    char pad10;
    unsigned char b11;
    char pad12[2];
    unsigned char b14;
    char pad15[0x9E0 - 0x15];
    char a9E0[0x20];
    char aA00[0x30];
};
struct Sec {
    char pad0[4];
    void* w4;
    unsigned char b8;
    char pad9[3];
    void* wC;
    void* w10;
};
struct Found { char pad[0x164]; void* w164; };
struct Root { char pad[0xB0]; char coll[4]; };
struct Opt { char pad[0xA0]; unsigned char bA0; };
struct Act {
    char pad0[0x14];
    unsigned char b14;
    char pad15[0x58 - 0x15];
    Vis* p58;
    char pad5C[0x2E50 - 0x5C];
    char a2E50[0x2EC0 - 0x2E50];
    Root r2EC0;
    char pad2F74[0x2FE0 - 0x2EC0 - sizeof(Root)];
    void* w2FE0;
    char pad2FE4[0x3010 - 0x2FE4];
    void* w3010;
    void* w3014;
    char pad3018[0x3020 - 0x3018];
    void* w3020;
    void* w3024;
    char pad3028[0x32A0 - 0x3028];
    char a32A0[0x3310 - 0x32A0];
    Phys* p3310;
    Sec* p3314;
    char pad3318[0x3524 - 0x3318];
    Opt* p3524;
};
extern "C" {
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_0049D8D0[];
extern char D_004A03C8[];
extern char D_004A03D0[];
#if 0 /* merge_units */
void Alloc_Lock(int);
#endif /* merge_units */
#define Alloc_Lock(a0) (Alloc_Lock((a0))) /* merge_units */

#if 0 /* merge_units */
void EnableIntc(int);
#endif /* merge_units */
#define EnableIntc(a0) (EnableIntc((a0))) /* merge_units */

void* cMemMan_Allocate(int, int, char*, int);
Phys* cHumanCollisionRoutine_ctor(void*);
Sec* cHumanIkRoutine_ctor(void*);
Found* RootCollection_FindByKey(void*, char*);
void cHuman_AimWeapon(Act*, int);
void cHumanCollisionRoutine_InitializePosition(Phys*);
}
static inline Found* FindC(char* c, char* key)
{
    return RootCollection_FindByKey(c, key);
}
static inline Found* Find(Root* r, char* key)
{
    return RootCollection_FindByKey(r->coll, key);
}
static inline void Link(Sec* s, Root* r, Phys* p)
{
    s->wC = r;
    s->w10 = p;
}
static inline void Set3(Act* a, void* x, void* p)
{
    a->w2FE0 = x;
    a->w3014 = p;
    a->w3010 = 0;
}
extern "C" void cHuman_InitializationToDoUponActivation(Act* a)
{
    Phys* p;
    Sec* s;
    {
        AllocGuard g;
        p = (Phys*)cMemMan_Allocate(0, 0xA30, D_0049D8D0, 0x424);
    }
    if (p) p = cHumanCollisionRoutine_ctor(p);
    a->p3310 = p;
    {
        AllocGuard g;
        s = (Sec*)cMemMan_Allocate(0, 0x840, D_0049D8D0, 0x425);
    }
    if (s) s = cHumanIkRoutine_ctor(s);
    a->p3314 = s;
    {
        Root* r = &a->r2EC0;
        Phys* q = a->p3310;
        char* c;
        q->w4 = a;
        q->w8 = a->a2E50;
        q->wC = r;
        c = r->coll;
        FindC(c, D_004A03C8)->w164 = q->a9E0;
        FindC(c, D_004A03D0)->w164 = q->aA00;
    }
    Set3(a, a->a32A0, a->p3310);
    Link(a->p3314, &a->r2EC0, a->p3310);
    s = a->p3314;
    a->w3024 = s;
    s->w4 = a->w3020;
    cHuman_AimWeapon(a, 0);
    if (a->p3524) a->p3524->bA0 = 0;
    a->p3310->b11 = 1;
    cHumanCollisionRoutine_InitializePosition(a->p3310);
    if (a->b14) {
        bool on = 0;
        if (a->p58 && a->p58->IsOn()) on = 1;
        if (on) {
            a->p3314->b8 = 2;
            a->p3310->b14 = 3;
        }
    }
}
#undef Alloc_Lock /* merge_units */
#undef EnableIntc /* merge_units */
static inline void merge_flush_func_001B5560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B5560 */

/* merge_units: begin func_001B57C0 */
#pragma push /* merge_units */
#pragma cplusplus on

class VObj { public: virtual ~VObj(); };
struct Net { char pad[0x24]; int w24; };
struct Msg {
    void* vt;
    char pad4[0x20 - 0x4];
    unsigned char b20;
    char pad21[0x78 - 0x21];
    char sub78[0x114 - 0x78];
    char sub114[0x1D4 - 0x114];
};

struct Npc {
    void* vt;
    char pad4[0xC - 0x4];
    char aC[0x10 - 0xC];
    int w10;
    char pad14[0x2C - 0x14];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x58 - 0x2F];
    Vis* p58;
    char pad5C[0x3030 - 0x5C];
    char m3030[0x3050 - 0x3030];
    char m3050[0x3088 - 0x3050];
    char m3088[0x30F0 - 0x3088];
    char m30F0[0x31FC - 0x30F0];
    unsigned char b31FC;
    char pad31FD[0x320C - 0x31FD];
    char m320C[0x3220 - 0x320C];
    char m3220[0x3234 - 0x3220];
    char m3234[0x3248 - 0x3234];
    char m3248[0x3250 - 0x3248];
    char m3250[0x3258 - 0x3250];
    char m3258[0x3264 - 0x3258];
    void* p3264;
    char pad3268[0x32A0 - 0x3268];
    void* vt32A0;
    char pad32A4[0x32E0 - 0x32A4];
    char m32E0[0x3310 - 0x32E0];
    VObj* w3310;
    VObj* w3314;
    char pad3318[0x33BC - 0x3318];
    float f33BC;
    char pad33C0[0x33EC - 0x33C0];
    void* p33EC;
    char m33F0[0x3524 - 0x33F0];
    void* p3524;
    void* p3528;
    char pad352C[0x3584 - 0x352C];
    Net* p3584;
};

extern "C" {
extern char D_004DA690[];
extern char D_004DA2F0[];
extern char D_004DADF0[];
extern char D_0049EDB8[];
extern char D_0055C7A0[];
extern char D_004F12D0[];
extern char g_Game[];
extern unsigned char g_IsMultiplayer;
void cMemMan_Deallocate(int, void*, char*, int);
void cWeapon_dtor(void*, int);
void cGOBJ_DeleteController(Npc*);
void cHuman_SetParticleEffect(Npc*, unsigned char, int, float);
int func_002D2210(Net*);
void NetFreeObject(int);
void cAssocArray_int_netSystemField_End(Iter*, char*);
void cAssocArray_int_netSystemField_Find(Iter*, char*, int*);
int cAssocArray_int_netSystemField_Iterator_opNe(Iter*, Iter*);
int cAssocArray_int_netSystemField_Erase(char*, Iter*);
void cNPCInfoObject_ctor(int*);
void cNPCInfoObject_Deactivate(int*, void*);
void cNPCInfoObject_dtor(int*, int);
void cNetObj_RemovePlayer_cGOBJP(Npc*);
void cFlashlight_dtor(void*, int);
void std_vector_deleter_tItem_dtor(void*, int);
void cStopSoundMsg_ctor_cSndFxR_cGOBJP(Msg*, char*, Npc*);
void QueueMessage_cMessageR_cSystemP_int(Msg*, char*, int);
void cFileMan_dtor(void*, int);
void cMessage_dtor(Msg*, int);
void Actor_UnlinkAll(Npc*);
void cCheckpoint_dtor(void*, int);
void cActivationTracker_dtor(void*, int);
void cCollisionModelList_dtor(void*, int);
#if 0 /* merge_units */
void cAimComponentList_dtor(void*, int);
#endif /* merge_units */
void* cAimComponentList_dtor(void* self, short deleteFlag); /* merge_units */
#define cAimComponentList_dtor(a0, a1) ((void)cAimComponentList_dtor((a0), (short)(a1))) /* merge_units */

#if 0 /* merge_units */
void cArray_FixedSize_bool_10_dtor(void*, int);
#endif /* merge_units */
void* cArray_FixedSize_bool_10_dtor(void* self, short deleteFlag); /* merge_units */
#define cArray_FixedSize_bool_10_dtor(a0, a1) ((void)cArray_FixedSize_bool_10_dtor((a0), (short)(a1))) /* merge_units */

void func_0017ED20(void*, int);
#if 0 /* merge_units */
void cHumanMotionParams_cTargetZRotationStack_dtor(void*, int);
#endif /* merge_units */
void* cHumanMotionParams_cTargetZRotationStack_dtor(void* self, short deleteFlag); /* merge_units */
#define cHumanMotionParams_cTargetZRotationStack_dtor(a0, a1) ((void)cHumanMotionParams_cTargetZRotationStack_dtor((a0), (short)(a1))) /* merge_units */

#if 0 /* merge_units */
void cSplinedMotion_Angle_dtor(void*, int);
#endif /* merge_units */
struct VtableChainObject; /* merge_units */
VtableChainObject* cSplinedMotion_Angle_dtor(VtableChainObject* self, short deleteFlag); /* merge_units */
#define cSplinedMotion_Angle_dtor(a0, a1) ((void)cSplinedMotion_Angle_dtor((VtableChainObject *)(a0), (short)(a1))) /* merge_units */

#if 0 /* merge_units */
void cStatesWithHistory_1_dtor(void*, int);
#endif /* merge_units */
void* cStatesWithHistory_1_dtor(void* self, short deleteFlag); /* merge_units */
#define cStatesWithHistory_1_dtor(a0, a1) ((void)cStatesWithHistory_1_dtor((a0), (short)(a1))) /* merge_units */

void cSKM_GOBJ_dtor(Npc*, int);
void operator_delete(void*);
}

static inline void Unreg(int key)
{
    Iter e, f;
    cAssocArray_int_netSystemField_End(&e, D_0055C7A0);
    cAssocArray_int_netSystemField_Find(&f, D_0055C7A0, &key);
    if (cAssocArray_int_netSystemField_Iterator_opNe(&e, &f)) {
        Iter g;
        cAssocArray_int_netSystemField_Find(&g, D_0055C7A0, &key);
        cAssocArray_int_netSystemField_Erase(D_0055C7A0, &g);
    }
}
static inline void SendDeath(Npc* a)
{
    Msg m;
    cStopSoundMsg_ctor_cSndFxR_cGOBJP(&m, D_004F12D0, a);
    m.b20 = 1;
    QueueMessage_cMessageR_cSystemP_int(&m, g_Game, 1);
    m.vt = D_004DADF0;
    cFileMan_dtor(m.sub114, -1);
    cFileMan_dtor(m.sub78, -1);
    cMessage_dtor(&m, 0);
}
static inline bool IsOn(Npc* a)
{
    bool on = 0;
    if (a->p58 && a->p58->IsOn()) on = 1;
    return on;
}

extern "C" Npc* cHuman_dtor(Npc* a, short flag)
{
    int loc;
    if (a) {
        int i;
        a->vt = D_004DA690;
        {
            void* p = a->p3264;
            if (p) {
                {
                    AllocGuard g;
                    cMemMan_Deallocate(0, p, D_0049EDB8, 0x39A);
                }
                a->p3264 = 0;
            }
        }
        {
            void* p = a->p3524;
            AllocGuard g;
            cWeapon_dtor(p, -1);
            cMemMan_Deallocate(0, p, D_0049D8D0, 0x3E9);
        }
        if (a->b31FC) {
            cGOBJ_DeleteController(a);
            a->b31FC = 0;
        }
        for (i = 0; i < 3; i++) cHuman_SetParticleEffect(a, i, 0, 1.0f);
        if (g_IsMultiplayer) {
            Net* n = a->p3584;
            if (n) {
                if (func_002D2210(n)) NetFreeObject(n->w24);
                a->p3584 = 0;
            }
            Unreg(a->w10);
            cNPCInfoObject_ctor(&loc);
            cNPCInfoObject_Deactivate(&loc, a->aC);
            cNPCInfoObject_dtor(&loc, -1);
        }
        if (IsOn(a)) cNetObj_RemovePlayer_cGOBJP(a);
        {
            void* p = a->p33EC;
            if (p) {
                AllocGuard g;
                cFlashlight_dtor(p, -1);
                cMemMan_Deallocate(0, p, D_0049D8D0, 0x402);
            }
        }
        int v = a->b2D != 0;
        if (v) v = a->b2C != 0;
        v = v ? (a->b2E != 0) ^ 1 : v; /* ternary: no pad nop before the join label */
        if (v) {
            VObj* o = a->w3310;
            if (o) {
                {
                    AllocGuard g;
                    o->~VObj();
                    cMemMan_Deallocate(0, o, D_0049D8D0, 0x408);
                }
                a->w3310 = 0;
            }
            o = a->w3314;
            if (o) {
                {
                    AllocGuard g;
                    o->~VObj();
                    cMemMan_Deallocate(0, o, D_0049D8D0, 0x40D);
                }
                a->w3314 = 0;
            }
        }
        {
            void* p = a->p3528;
            AllocGuard g;
            if (p) if (p) if (p) if (p) std_vector_deleter_tItem_dtor(p, 0);
            cMemMan_Deallocate(0, p, D_0049D8D0, 0x412);
        }
        if (!(a->f33BC < 0.0f)) SendDeath(a);
        Actor_UnlinkAll(a);
        cCheckpoint_dtor(a->m33F0, -1);
        if (&a->vt32A0) {
            a->vt32A0 = D_004DA2F0;
            cActivationTracker_dtor(a->m32E0, -1);
            cCollisionModelList_dtor(&a->vt32A0, 0);
        }
        if (a->m320C) {
            cAimComponentList_dtor(a->m3258, -1);
            cAimComponentList_dtor(a->m3250, -1);
            cAimComponentList_dtor(a->m3248, -1);
            cArray_FixedSize_bool_10_dtor(a->m3234, -1);
            cArray_FixedSize_bool_10_dtor(a->m3220, -1);
            cArray_FixedSize_bool_10_dtor(a->m320C, -1);
        }
        if (a->m3030) {
            func_0017ED20(a->m30F0, -1);
            cHumanMotionParams_cTargetZRotationStack_dtor(a->m3088, -1);
            cSplinedMotion_Angle_dtor(a->m3050, -1);
            cStatesWithHistory_1_dtor(a->m3030, -1);
        }
        cSKM_GOBJ_dtor(a, 0);
        if (flag > 0) operator_delete(a);
    }
    return a;
}
#undef cAimComponentList_dtor /* merge_units */
#undef cArray_FixedSize_bool_10_dtor /* merge_units */
#undef cHumanMotionParams_cTargetZRotationStack_dtor /* merge_units */
#undef cSplinedMotion_Angle_dtor /* merge_units */
#undef cStatesWithHistory_1_dtor /* merge_units */
static inline void merge_flush_func_001B57C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B57C0 */

/* merge_units: begin func_001B5E20 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vtable_chain_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int sprintf(void *, const void *, ...);
int strlen(const char *);
char *strncpy(void *, const void *, int);

#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cStatesWithHistory_1_dtor)
static inline void merge_flush_func_001B5E20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B5E20 */

/* merge_units: begin func_001B5E70 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" void cSplinedMotion_Angle_UpdateSplinePoints();
extern "C" void cSplinedMotion_Angle_UpdateVelocity();
extern "C" void cSplinedMotion_Angle_TeleportByDelta();
extern "C" void cSplinedMotion_Angle_InitPos();
extern "C" void cSplinedMotion_Angle_ZeroVel();
extern "C" void cSplinedMotion_Angle_FixUpResultOfSplineEvaluation();
extern void * const D_004DA7D0[];
extern "C" char D_004DA380[];
extern "C" VtableChainObject* cSplinedMotion_Angle_dtor(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DA7D0);
        if (self)
            self->vtable = D_004DA380;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DA7D0[12] = { (void*)0x0, (void*)0x0, (void*)cSplinedMotion_Angle_dtor, (void*)cSplinedMotion_Angle_TeleportByDelta, (void*)cSplinedMotion_Angle_InitPos, (void*)cSplinedMotion_Angle_ZeroVel, (void*)cSplinedMotion_Angle_UpdateSplinePoints, (void*)cSplinedMotion_Angle_FixUpResultOfSplineEvaluation, (void*)cSplinedMotion_Angle_UpdateVelocity, (void*)0x0, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B5E70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B5E70 */

/* merge_units: begin func_001B5ED0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */



void func_001BE690(void* p, int f);
}
static inline void D3_1B5ED0(void* p) { if (p) func_001BE690(p, 0); }
static inline void D2_1B5ED0(void* p) { if (p) D3_1B5ED0(p); }
static inline void D1_1B5ED0(void* p) { if (p) D2_1B5ED0(p); }
extern "C" void* cHumanMotionParams_cTargetZRotationStack_dtor(void* self, short deleteFlag)
{
    if (self) {
        D1_1B5ED0(self);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B5ED0(void) {}
#undef operator_delete /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B5ED0 */

/* merge_units: begin func_001B5F40 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cArray_FixedSize_bool_10_dtor)
static inline void merge_flush_func_001B5F40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B5F40 */

/* merge_units: begin func_001B5F90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cAimComponentList_dtor)
static inline void merge_flush_func_001B5F90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B5F90 */

/* merge_units: begin func_001B5FE0 */
#pragma push /* merge_units */
/* cHuman_InitHuman (0x001B5FE0), mw38 MATCH.
 * Keys: AllocGuard (alloc_guard.h) in the Alloc inline supplies the 3 extra 4-byte stack slots;
 * the Mtx copy is an explicit lq/sq asm block (asm in the function also keeps the null-handle
 * Clear() unfolded = retail b + dead 'li 0xC'); LocalId as 'r = 0; if (net) {...; return id;} return r;';
 * opt_unroll_loops/opt_strength_reduction off. UNDEF __dl__FPv is the usual benign one. */
#pragma cplusplus on
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
typedef int Q128 __attribute__((mode(TI)));
static inline void QCopy(void* d, const void* s) { Q128 q; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct Mtx { Q128 q[4]; };
struct HObj { int q[3]; int id; };
struct Hd {
    HObj* hp;
    int hid;
    void Set(HObj* o) { hp = o; int d; hid = *(o ? &o->id : (d = -1, &d)); }
    void Clear() { Set(0); }
};
struct Desc { char* name; void* skl; int x8; };
class Sub {
public:
    VPAD32(a) VPAD2(b)
    virtual void Apply(Mtx* m, int f);
};
class Act_001B5FE0 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c)
    virtual void SetMtx(Mtx* m);
    virtual void SetDesc(Desc* d);
    char p4[0xC - 0x4];
    int wC;
    char p10[0x40 - 0x10];
    float x40;
    char p44[0x58 - 0x44];
    Vis* p58;
    char p5C[0x31F0 - 0x5C];
    int x31F0;
    char p31F4[0x3264 - 0x31F4];
    char* x3264;
    char p3268[0x326B - 0x3268];
    unsigned char b326B;
    char p326C[0x3318 - 0x326C];
    char x3318[0x80];
    int x3398;
    int x339C;
    int x33A0;
    char p33A4[0x33B8 - 0x33A4];
    unsigned char b33B8;
    unsigned char b33B9;
    char p33BA[0x33BC - 0x33BA];
    float x33BC;
    char p33C0[0x33E7 - 0x33C0];
    unsigned char b33E7;
    void* x33E8;
    void* x33EC;
    Sub x33F0;
    char p33F4[0x3450 - 0x33F4];
    int x3450;
    char p3454[0x3458 - 0x3454];
    int x3458;
    char p345C[0x3469 - 0x345C];
    unsigned char b3469;
    unsigned char b346A;
    unsigned char b346B;
    unsigned char b346C;
    unsigned char b346D;
    unsigned char b346E;
    unsigned char b346F;
    unsigned char b3470;
    char p3471[0x3480 - 0x3471];
    Hd h3480;
    unsigned char b3488;
    char p3489[0x34E0 - 0x3489];
    int x34E0;
    int x34E4[12];
    void* x3514[4];
    void* x3524;
    void* x3528;
    int x352C;
    char p3530[0x3538 - 0x3530];
    unsigned char b3538;
    char p3539[0x354C - 0x3539];
    Hd h354C[3];
    char p3564[0x3588 - 0x3564];
    int x3588[2];
};
struct ItemList { char p[0x10]; Act_001B5FE0* owner; };
struct Hog { char p[0xA0]; };
struct Skl { char p[0x440]; };
extern "C" {
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern Desc* D_004FFBD8;
extern char D_0049E8F0[];
extern char D_0048B2F8[];
extern char D_0049E908[];
extern char D_0049E918[];
extern char D_0049E928[];
extern char D_0049E940[];
extern char D_0055D4F8;
extern char D_004FFB8C;
#if 0 /* merge_units */
extern char g_Game;
#endif /* merge_units */
#define g_Game (*(char*)&g_Game) /* merge_units */

extern float D_0048A1C8;
extern float D_0048A1D0;
#if 0 /* merge_units */
void Alloc_Lock(int);
#endif /* merge_units */
#define Alloc_Lock(a0) (Alloc_Lock((a0))) /* merge_units */



#if 0 /* merge_units */
void EnableIntc(int);
#endif /* merge_units */
#define EnableIntc(a0) (EnableIntc((a0))) /* merge_units */

#if 0 /* merge_units */
void cArray_tItem_ctor(void*);
#endif /* merge_units */
Rel* cArray_tItem_ctor(Rel* r); /* merge_units */
#define cArray_tItem_ctor(a0) ((void)cArray_tItem_ctor((Rel *)(a0))) /* merge_units */


void* cFlashlight_ctor(void*, Act_001B5FE0*);
void cFileMan_ctor_void(Hog*);
#if 0 /* merge_units */
void cFileMan_dtor(Hog*, int);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) (cFileMan_dtor((void *)(a0), (a1))) /* merge_units */

void cGOBJ_SetHitpoints(Act_001B5FE0*, int, int);
void NetGetMyClientIndex(int*, int);
Skl* SKLHog_FindSKL(char*, char*);
int cHogList_Open(char*, char*, int, int);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(Hog*, char*, int, int);
int cFileMan_Open(Hog*);
int cFileMan_GetSize(Hog*);
void SKL_ReadSKL(Skl*, Hog*, int);
void cWeapon_Add(void*, int, int, int, int, int);
void cWeapon_DrawWeapon_void(void*);
void cHuman_CreateGobjController(Act_001B5FE0*, unsigned char, int, void*);
void cNPCInfoObject_Add(int*, int*, int);
void cNPCInfoObject_SetOwner_cObjectIdR_int(int*, int*, int);
int cGameSystem_GetAgentData(char*, int);
int cAgentData_HasSpecialBonus(int, int);
}
struct HogH {
    Hog h;
    HogH() { cFileMan_ctor_void(&h); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~HogH() { cFileMan_dtor(&h, -1); }
};
static inline void* Alloc(int size, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, D_0049D8D0, line);
}
static inline int LocalId()
{
    int a = D_005721A8;
    int r = 0;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGetMyClientIndex(&D_00494178, a);
        return D_00494178;
    }
    return r;
}
static inline int LocalId2()
{
    int a = D_005721A8;
    int r = 0;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGetMyClientIndex(&D_00494178, a);
        r = D_00494178;
    }
    return r;
}
static inline bool On(Act_001B5FE0* a)
{
    bool on = 0;
    if (a->p58 && a->p58->IsOn()) on = 1;
    return on;
}
extern "C" bool cHuman_InitHuman(Act_001B5FE0* a, Mtx* mtx, char* name, int health, int maxh, int* weap, int s2, unsigned char type, char* label)
{
    Desc* desc = D_004FFBD8;
    char path[0x80];
    HogH hog;
    Mtx m;
    HogH hog2;
    Skl skl;
    Skl* sk;
    {
        ItemList* l = (ItemList*)Alloc(0x14, 0x31A);
        if (l) {
            cArray_tItem_ctor(l);
            l->owner = a;
        }
        a->x3528 = l;
    }
    a->b326B = 0;
    if (type == 1 || type == 3) {
        void* f = Alloc(0x1C, 0x31E);
        if (f) f = cFlashlight_ctor(f, a);
        a->x33EC = f;
    } else {
        a->x33EC = 0;
    }
    {
        int i;
        for (i = 0; i < 12; i++) a->x34E4[i] = -1;
    }
    a->x34E0 = 0;
    a->b33E7 = 0;
    a->x352C = 0;
    a->b33B8 = 0;
    a->b3470 = 0;
    a->b346F = 0;
    a->b346E = 0;
    a->b3538 = 0;
    a->x33BC = -1.0f;
    a->b33B9 = 0;
    a->b3469 = 0;
    a->b346B = 0;
    a->b346A = 0;
    a->b346C = 0;
    a->h3480.Clear();
    a->b3488 = 0;
    a->b346D = 0;
    {
        int i;
        for (i = 0; i < 3; i++) a->h354C[i].Clear();
    }
    sprintf(path, D_0049E8F0, D_0048B2F8, 1);
    a->x3398 = health;
    cGOBJ_SetHitpoints(a, health, 0);
    a->x339C = maxh;
    a->x33A0 = maxh;
    {
        int len = label ? strlen(label) : 0;
        if (len) {
            a->x3264 = (char*)Alloc(len + 1, 0x33F);
            Libc_Strcpy(a->x3264, label);
        } else {
            a->x3264 = 0;
        }
    }
    if (name) {
        if (g_IsMultiplayer) {
            if (type == 1 && !(g_IsMultiplayer ? D_005721C0 : (unsigned char)1)) {
                switch (LocalId()) {
                case 1: strncpy(a->x3318, D_0049E908, 0x80); break;
                case 2: strncpy(a->x3318, D_0049E918, 0x80); break;
                case 3: strncpy(a->x3318, D_0049E928, 0x80); break;
                default: strncpy(a->x3318, D_0049E918, 0x80); break;
                }
            } else {
                strncpy(a->x3318, name, 0x80);
            }
            sk = SKLHog_FindSKL(&D_0055D4F8, a->x3318);
            if (!sk) {
                cFileMan_EncodeFilename_charP_cHogFileR_bool(&hog.h, a->x3318, cHogList_Open(&D_004FFB8C, path, 0, 0), 0);
                if ((unsigned char)cFileMan_Open(&hog.h)) {
                    char err[0x40];
                    sprintf(err, D_0049E940, name);
                    return 0;
                }
                SKL_ReadSKL(&skl, &hog.h, cFileMan_GetSize(&hog.h));
                sk = &skl;
            }
        } else {
            strncpy(a->x3318, name, 0x80);
            sk = SKLHog_FindSKL(&D_0055D4F8, name);
            if (!sk) {
                cFileMan_EncodeFilename_charP_cHogFileR_bool(&hog.h, name, cHogList_Open(&D_004FFB8C, path, 0, 0), 0);
                if ((unsigned char)cFileMan_Open(&hog.h)) {
                    char err[0x40];
                    sprintf(err, D_0049E940, name);
                    return 0;
                }
                SKL_ReadSKL(&skl, &hog.h, cFileMan_GetSize(&hog.h));
                sk = &skl;
            }
        }
    } else {
        sk = 0;
    }
    desc->name = name;
    desc->skl = sk;
    desc->x8 = a->x31F0;
    { Mtx* pm = &m; Q128 a0, a1, a2, a3; __asm__ volatile("lq %0, 0x0(%4)\n lq %1, 0x10(%4)\n sq %0, 0x0(%5)\n lq %0, 0x20(%4)\n sq %1, 0x10(%5)\n lq %1, 0x30(%4)\n sq %0, 0x20(%5)\n sq %1, 0x30(%5)" : "=&r"(a0), "=&r"(a1), "=&r"(a2), "=&r"(a3) : "r"(mtx), "r"(pm) : "memory"); }
    a->SetMtx(&m);
    a->SetDesc(desc);
    {
        int i;
        for (i = 0; i < 2; i++) {
            a->x3588[i] = weap[i];
            if (weap[i] != -1) {
                if (g_IsMultiplayer) {
                    if (!s2)
                        cWeapon_Add(a->x3524, weap[i], 1, 0, 0, 0);
                    else
                        cWeapon_Add(a->x3524, weap[i], 1, 0, 0, 1);
                } else {
                    cWeapon_Add(a->x3524, weap[i], 1, 0, 0, 0);
                }
            }
        }
    }
    cWeapon_DrawWeapon_void(a->x3524);
    if (!g_IsMultiplayer) {
        cHuman_CreateGobjController(a, type, s2, 0);
    } else {
        if (type != 4) cHuman_CreateGobjController(a, type, s2, 0);
        if (type != 4 && type != 3 && !s2) {
            int loc;
            cNPCInfoObject_ctor(&loc);
            { int* w = &a->wC; cNPCInfoObject_Add(&loc, w, LocalId()); }
            if (type == 1) { int* w = &a->wC; cNPCInfoObject_SetOwner_cObjectIdR_int(&loc, w, LocalId()); }
            cNPCInfoObject_dtor(&loc, -1);
        }
    }
    if (On(a)) {
        int idx;
        int ag;
        if (g_IsMultiplayer) {
            if (On(a))
                idx = ((unsigned)(a->wC & 0x7F000000) >> 24) - 1;
            else
                idx = -1;
        } else {
            idx = 0;
        }
        {
            Vis* p = a->p58;
            int x = p != 0;
            if (x) x = (unsigned char)p->IsOn();
            x = (unsigned char)x;
            ag = x ? cGameSystem_GetAgentData(&g_Game, idx) : 0;
        }
        if (ag) {
            if (cAgentData_HasSpecialBonus(ag, 3)) {
                int v = (int)((float)a->x33A0 * D_0048A1C8);
                a->x339C = v;
                a->x33A0 = v;
            }
            if (cAgentData_HasSpecialBonus(ag, 4)) {
                int h = (int)(a->x40 * D_0048A1D0);
                a->x3398 = h;
                cGOBJ_SetHitpoints(a, h, 0);
            }
        }
    }
    a->x33F0.Apply(mtx, 0);
    a->x3450 = (int)a->x40;
    a->x3458 = a->x33A0;
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B5FE0(void) {}
#undef g_Game /* merge_units */
#undef Alloc_Lock /* merge_units */
#undef EnableIntc /* merge_units */
#undef cArray_tItem_ctor /* merge_units */
#undef cFileMan_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B5FE0 */

/* merge_units: begin func_001B6A60 */
#pragma push /* merge_units */
#if 0 /* merge_units */
Rel* ItemList_Reset(Rel* r); /* gsynth: defined below */
#endif /* merge_units */
Rel * ItemList_Reset(); /* merge_units */


/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern Rel* ItemList_Reset(Rel*);
#endif /* merge_units */
Rel * ItemList_Reset(); /* merge_units */




/* Clear the three words and set the byte at +0x0C. */
Rel* cArray_tItem_ctor(Rel* r) {
    ItemList_Reset(r);
    *((char*)r + 12) = 1;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B6A60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B6A60 */

/* merge_units: begin func_001B6A90 */
#pragma push /* merge_units */
Rel* ItemList_Reset(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B6A90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B6A90 */

/* merge_units: begin func_001B6AB0 */
#pragma push /* merge_units */
/* cHuman_ctor_cPopulationR_eCharacterType_SKLP_cGeneratorParamsP (0x001B6AB0), mw38/mw50 MATCH.
 * From c150lg's 13-diff draft. Fix: the three NormTo sites bind the source via a const V4& local,
 * the tail copy uses the QS asm helper, and the middle site (m.r[1]) copies out into a const local
 * before the final QS, which flips vreg colouring of r/t across sites 2-3. UNDEF __dl__FPv is the usual benign one. */
#pragma cplusplus on
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
#pragma inline_depth(10)

struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
struct V : V4 {
    V() {}
    V& operator=(const V& o) { float fy, fz, fw, fx; fw = o.w; fz = o.z; fy = o.y; fx = o.x; w = fw; z = fz; y = fy; x = fx; return *this; }
    V(const V& o) { *(Q128*)this = *(const Q128*)&o; }
    void Normalize() {
        __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory");
    }
    float DotX(const V4& b) const {
        int t; float r = 0.0f; const V* pa = this; __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(pa), "r"(&b) : "memory");
        return r;
    }
    float Dot(const V4& b) const {
        int t; float r = 0.0f; const V4* pb = &b; const V* pa = this;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(pa), "r"(pb) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
static inline void NormP(V* p) { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(p) : "memory"); }
static inline void QS(void* d0, const void* s0) { const void* s = s0; void* d = d0; Q128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
static inline V Normalized(const V4& v) { V t; QS(&t, &v); V* const p = &t; NormP(p); return *p; }
static inline void NormTo(V* out, const V4& v) { V t; QS(&t, &v); V* const p = &t; NormP(p); QS(out, p); }
static inline void NormTo_1(V* out, const V4& v) { V t; QS(&t, &v); V* const p = &t; NormP(p); QS(out, p); }
static inline void NormTo_2(V* out, const V4& v) { V t; QS(&t, &v); V* const p = &t; NormP(p); Q128 q = *(const Q128*)p; V* d = out; *(Q128*)d = q; }
static inline void NormTo_3(V* out, const V4& v) { V t; QS(&t, &v); V* const p = &t; NormP(p); Q128 q; V* d = out; q = *(const Q128*)p; *(Q128*)d = q; }
static inline void NormTo_5(V* out, const V4& v) { V t; V* const p = &t; QS(p, &v); NormP(p); QS(out, p); }
static inline void NormTo_6(V* out, const V4& v) { V t; QS(&t, &v); V* p; p = &t; NormP(p); QS(out, p); }
static inline void NormTo_7(V* out, const V4& v) { V t; const V4* s = &v; QS(&t, s); V* const p = &t; NormP(p); QS(out, p); }
static inline void NormTo_8(V* out, const V4& v) { V t; QS(&t, &v); V* const p = &t; NormP(p); V* const o = out; QS(o, p); }
static inline void NormTo_4(V* out, const V4& v) { V t; QS(&t, &v); NormP(&t); QS(out, &t); }
static inline void NormToP(V* out, const V4* v) { NormTo(out, *v); }
#define SITE(k,n) { V r; const V4& s = m.r[k]; NormTo_##n(&r, s); *(V*)&m.r[k] = r; }
static inline V Origin() { V r; __asm__ volatile("sqc2 $vf0, 0x0(%0)" : : "r"(&r) : "memory"); return r; }
struct Mtx_001B6AB0 {
    V4 r[4];
    void Init() { r[0].w = 0.0f; r[1].w = 0.0f; r[2].w = 0.0f; r[3].w = 1.0f; }
};
inline void* operator new(unsigned int, void* p) { return p; }
struct Skl_001B6AB0 { Q128 q[0x44]; };
struct VecPair; struct V;
extern "C" void cVector_Get0001(V*);
extern "C" void cVector_ctor_cVectorR(void*, void*);
extern "C" void cQuatVec_GetUnit(VecPair*);
extern "C" void cQuatVec_ctor_cQuatVecR(void*, VecPair*);
struct VecPair { V a; V b; VecPair() { cQuatVec_GetUnit(this); } };
static inline void SetQ(V4* d0, const V& s0) { V* d = (V*)d0; const V* s = &s0; Q128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void OriginTo(V* d0) { V* d; V r; const V* s = &r; Q128 q; __asm__ volatile(".set noreorder; sqc2 $vf0, 0x0(%0); .set reorder" : : "r"(s) : "memory"); d = d0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
struct VO : V { VO() { cVector_Get0001(this); } };
struct VA { char p[0x10]; void operator=(const V& o) { cVector_ctor_cVectorR(this, (void*)&o); } };
static inline void InitPair0(void* d) { VecPair b; cQuatVec_ctor_cQuatVecR(d, &b); }
static inline void InitOrg0(void* d) { VO o; cVector_ctor_cVectorR(d, &o); }
static inline void InitPair(void* d) { InitPair0(d); }
static inline void InitOrg(void* d) { InitOrg0(d); }
static inline void InitPair1(void* d) { InitPair(d); }
static inline void InitOrg1(void* d) { InitOrg(d); }
struct VPS { char p[0x20]; void operator=(const VecPair& o) { cQuatVec_ctor_cQuatVecR(this, (VecPair*)&o); } };
struct A60 {
    char p[0x40];
    Skl_001B6AB0 skl;
    void SetSkl(Skl_001B6AB0* s0) {
        Skl_001B6AB0* s = s0; A60* p = this; Skl_001B6AB0* d; int n; Q128 t;
        asm {
            .set noreorder
            addiu n, zero, 0x44
            addiu d, p, 0x40
            nop
        lp:
            lq t, 0(s)
            addiu d, d, 0x10
            addi n, n, -1
            addiu s, s, 0x10
            bgtz n, lp
            sq t, -0x10(d)
            .set reorder
        }
    }
};
struct Reader { int version; int a, b; char* cur; };
struct H { int v; H() : v(-1) {} };
struct VP {
    HObj* a; H b;
    VP() { Clear(); }
    void Set(HObj* o) { a = o; int d; b.v = *(o ? &o->id : (d = -1, &d)); }
    void Clear() { Set(0); }
};
struct Hd_001B6AB0 { HObj* hp; int hid; Hd_001B6AB0() : hp(0), hid(-2) {} };
struct Plane {
    float x, y, z, d;
    void Set(const V4& n, const V& p) { float dd = ((const V&)n).DotX(p); float nx, ny, nz; nz = n.z; ny = n.y; nx = n.x; x = nx; y = ny; z = nz; d = -dd; }
};

extern "C" {
extern char g_HumanActorClassKey[];
extern int g_NoneWord;
extern char D_004DA7A8[];
extern char D_004DA7B8[];
extern int g_ActorSerialCounter;
extern void* D_004FFBE0;
void cSKM_GOBJ_ctor_cObjectIdR_cSubclassIdR(void*, int*, void*);
void cStatesWithHistory_1_ctor(void*);
void* cVector_GetZero(void);
void cVector_ctor_cVectorR(void*, void*);
void cSplinedMotion_Angle_ctor(void*);
void cHumanMotionParams_cTargetZRotationStack_ctor(void*);
void cSplinedMotion_Vector_ctor(void*);
int cHumanMotionParams_PushTargetZRotationOnStack(void*, float, float);
void cSplinedMotion_float_SetDamp(void*, float);
void cSplinedMotion_cVector_SetDamp(void*, float);
void cBitArray_8_ctor(void*, int);
void func_001B75B0(void*, int);
void func_001B7580(void*, int);
void cCollisionModelList_ctor(void*, int*, int*);
void cActivationTracker_ctor(void*);
void cCheckpoint_ctor(void*);
void cQuatVec_GetUnit(VecPair*);
void cQuatVec_ctor_cQuatVecR(void*, VecPair*);
void* cWeapon_ctor(void*, void*, int);
int* std_vector_cNodePtr_opIndex(void*, int);
V cNode_GetLoc(int);
}

struct S3030 {
    char p0[0xC];
    unsigned char bC;
    char pD[0x10 - 0xD];
    char x10[0x10];
    char x20[0x38];
    char x58[0x10];
    int x68;
    int x6C;
    int x70;
    float x74;
    int x78;
    unsigned char b7C;
    unsigned char b7D;
    char p7E[0x80 - 0x7E];
    char x80[0x10];
    int x90;
    char p94[0xA0 - 0x94];
    char xA0[0x10];
    int xB0;
    char pB4[0xC0 - 0xB4];
    char xC0[0xC0];
    unsigned char b180[8];
    char p188[0x190 - 0x188];
    char x190[0x10];
    int x1A0;
    int x1A4;
    int x1A8;
    unsigned char b1AC;
    unsigned char b1AD;
    char p1AE[0x1B0 - 0x1AE];
    int x1B0;
    void Init();
};
inline void S3030::Init()
{
    S3030* s = this;
    cStatesWithHistory_1_ctor(s);
    s->bC = 1;
    cVector_ctor_cVectorR(s->x10, cVector_GetZero());
    cSplinedMotion_Angle_ctor(s->x20);
    cHumanMotionParams_cTargetZRotationStack_ctor(s->x58);
    s->x6C = 0;
    s->x70 = 0;
    s->x74 = -3.4028235e38f;
    s->x78 = 0;
    s->b7C = 0;
    s->b7D = 0;
    cVector_ctor_cVectorR(s->x80, cVector_GetZero());
    s->x90 = 0;
    cVector_ctor_cVectorR(s->xA0, cVector_GetZero());
    s->xB0 = 0;
    cSplinedMotion_Vector_ctor(s->xC0);
    s->b180[0] = 0;
    s->b180[1] = 0;
    s->b180[2] = 0;
    s->b180[3] = 0;
    s->b180[4] = 0;
    s->b180[5] = 0;
    s->b180[6] = 0;
    s->b180[7] = 0;
    cVector_ctor_cVectorR(s->x190, cVector_GetZero());
    s->x1A0 = 0;
    s->x1A4 = 0;
    s->x1A8 = 0;
    s->b1AC = 1;
    s->b1AD = 0;
    s->x1B0 = 0;
    s->x68 = cHumanMotionParams_PushTargetZRotationOnStack(s, 0.0f, -1.0f);
    cSplinedMotion_float_SetDamp(s->x20, 15.0f);
    cSplinedMotion_cVector_SetDamp(s->xC0, 10.0f);
}
struct S3200 { int e[3]; };
struct S320C { char a[3][0x14]; char b[3][8]; };
struct S32A0 {
    void* vt;
    char p4[0x20 - 4];
    int x20;
    char p24[0x30 - 0x24];
    char x30[0x10];
    char x40[0x20];
    int x60;
};
struct S3530 {
    void* vt;
    int x4;
    char p8;
    unsigned char b9;
    unsigned char bA;
    char pB;
    int xC;
    float x10;
    int x14;
};

struct Act_001B6AB0 {
    void* vt;
    char p4[0xC - 4];
    int wC;
    char p10[0x30 - 0x10];
    int x30;
    char p34[0x60 - 0x34];
    A60 x60;
    char p4E0[0x3030 - 0x4E0];
    S3030 x3030;
    char p31E4[0x31F0 - 0x31E4];
    int x31F0;
    float x31F4;
    float x31F8;
    unsigned char b31FC;
    char p31FD[0x3200 - 0x31FD];
    S3200 x3200;
    S320C x320C;
    unsigned char b3260;
    char p3261[0x3268 - 0x3261];
    unsigned char b3268;
    unsigned char b3269;
    unsigned char b326A;
    char p326B[0x32A0 - 0x326B];
    S32A0 x32A0;
    char p3304[0x3310 - 0x3304];
    int x3310;
    int x3314;
    char p3318[0x33A0 - 0x3318];
    int x33A0;
    unsigned char b33A4;
    unsigned char b33A5;
    char p33A6[0x33A8 - 0x33A6];
    int x33A8;
    int x33AC;
    int x33B0;
    int x33B4;
    char p33B8[0x33CC - 0x33B8];
    int x33CC;
    int x33D0;
    int x33D4;
    int x33D8;
    int x33DC;
    int x33E0;
    unsigned char b33E4;
    unsigned char b33E5;
    unsigned char b33E6;
    char p33E7;
    unsigned char b33E8;
    char p33E9[0x33F0 - 0x33E9];
    char x33F0[0x3464 - 0x33F0];
    int x3464;
    unsigned char b3468;
    char p3469[0x3474 - 0x3469];
    int x3474;
    VP h3478;
    Hd_001B6AB0 h3480;
    char p3488[0x3490 - 0x3488];
    unsigned char b3490;
    char p3491[0x34A0 - 0x3491];
    char x34A0[0x20];
    char x34C0[0x10];
    char x34D0[0x10];
    char p34E0[0x3514 - 0x34E0];
    int x3514;
    signed char b3518;
    char p3519[0x351C - 0x3519];
    int x351C;
    int x3520;
    void* x3524;
    char p3528[0x3530 - 0x3528];
    S3530 x3530;
    int x3548;
    Hd_001B6AB0 h354C[3];
    char p3564[0x3570 - 0x3564];
    Plane pl;
    int x3580;
    int x3584;
    char p3588[0x3594 - 0x3588];
    int x3594;
    bool b3598;
};

#if 0 /* merge_units */
extern "C" bool cHuman_InitHuman(Act_001B6AB0* a, Mtx_001B6AB0* mtx, char* name, int health, int maxh, int* weap, int s2, unsigned char type, char* label);
#endif /* merge_units */
#define cHuman_InitHuman(a0, a1, a2, a3, a4, a5, a6, a7, a8) (cHuman_InitHuman((Act_001B5FE0 *)(a0), (Mtx *)(a1), (a2), (a3), (a4), (a5), (a6), (a7), (a8))) /* merge_units */


static inline int RdI(Reader* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void RdF(Reader* r, float* o) { *o = *(float*)r->cur; r->cur += 4; }
static inline void RdI2(Reader* r, int* o) { *o = *(int*)r->cur; r->cur += 4; }
static inline void RdV(Reader* r, V4* v0) { V4* v = v0; RdF(r, &v->x); RdF(r, &v->y); RdF(r, &v->z); }
static inline char* RdS(Reader* r)
{
    char* s = r->cur;
    while (*r->cur++) {}
    int mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
    return s;
}

extern "C" Act_001B6AB0* cHuman_ctor_cPopulationR_eCharacterType_SKLP_cGeneratorParamsP(Act_001B6AB0* a, Reader* rd, unsigned char type, Skl_001B6AB0* src, int flag)
{
    volatile int nid1;
    volatile int nid2;
    int weap[2];
    Mtx_001B6AB0 m;
    V o;
    {
        int id = -1;
        cSKM_GOBJ_ctor_cObjectIdR_cSubclassIdR(a, &id, g_HumanActorClassKey);
    }
    a->x3030.Init();
    a->vt = D_004DA690;
    a->x31F0 = -1;
    a->x31F4 = -1.0f;
    a->x31F8 = 36.69f;
    a->b31FC = 0;
    {
        S3200* p = &a->x3200;
        cBitArray_8_ctor(&p->e[0], 0);
        cBitArray_8_ctor(&p->e[1], 0);
        cBitArray_8_ctor(&p->e[2], 0);
    }
    {
        S320C* p = &a->x320C;
        func_001B75B0(p->a[0], 0);
        func_001B75B0(p->a[1], 0);
        func_001B75B0(p->a[2], 0);
        func_001B7580(p->b[0], 0);
        func_001B7580(p->b[1], 0);
        func_001B7580(p->b[2], 0);
    }
    a->b3260 = 0;
    a->b3268 = 0;
    a->b3269 = 0;
    a->b326A = 0;
    {
        S32A0* p = &a->x32A0;
        int z1, z0; z0 = 0; z1 = 0;
        cCollisionModelList_ctor(p, &z1, &z0);
        p->vt = D_004DA2F0;
        p->x20 = 0;
        cVector_ctor_cVectorR(p->x30, cVector_GetZero());
        cActivationTracker_ctor(p->x40);
        p->x60 = 0;
    }
    a->x3310 = 0;
    a->x3314 = 0;
    a->x33A0 = 0;
    a->b33A4 = 0;
    a->b33A5 = 0;
    a->x33A8 = 0;
    a->x33AC = 0;
    a->x33B0 = 0;
    a->x33B4 = 0;
    a->x33CC = g_NoneWord;
    a->x33D0 = 0;
    a->x33D4 = 0;
    a->x33D8 = 0;
    a->x33DC = 0;
    a->x33E0 = 0;
    a->b33E4 = 0;
    a->b33E5 = 0;
    a->b33E6 = 0;
    a->b33E8 = 0;
    cCheckpoint_ctor(a->x33F0);
    a->x3464 = 0;
    a->b3468 = 0;
    a->x3474 = 0;
    a->h3478.b.v = -1;
    a->h3478.Clear();
    a->h3480.hid = -2;
    a->h3480.hp = 0;
    a->b3490 = 0;
    {
        InitPair1(a->x34A0);
    }
    InitOrg1(a->x34C0);
    cVector_ctor_cVectorR(a->x34D0, cVector_GetZero());
    a->x3514 = -1;
    a->b3518 = -1;
    a->x351C = 0;
    a->x3520 = 0;
    {
        S3530* p = &a->x3530;
        p->vt = D_004DA7B8;
        p->vt = D_004DA7A8;
        p->x4 = 0;
        p->b9 = 0;
        p->bA = 0;
        p->xC = 0;
        p->x10 = 1.0f;
        p->x14 = 0;
    }
    {
        Hd_001B6AB0* h;
        h = a->h354C;
        do { h->hid = -2; h->hp = 0; h++; } while (h != a->h354C + 3);
    }
    {
        V4 n;
        n.x = 0.0f; n.y = 0.0f; n.z = 1.0f; n.w = 0.0f;
        OriginTo(&o);
        a->pl.Set(n, o);
    }
    a->x3580 = 0;
    a->x3584 = 0;
    a->x3594 = 0;
    a->b3598 = flag ? true : false;
    {
        void* w = Alloc(0xF8, 0x267);
        if (w) { int h = type == 1; if (!h) h = type == 3; w = cWeapon_ctor(w, a, h); }
        a->x3524 = w;
    }
    a->x3530.x4 = (int)a->x3524;
    if (type == 2 || type == 4) {
        a->x31F0 = g_ActorSerialCounter;
        g_ActorSerialCounter++;
    }
    m.Init();
    int hi = RdI(rd);
    int lo = RdI(rd);
    if (!g_IsMultiplayer) {
        nid1 = lo | (hi << 16);
        a->wC = nid1;
    } else {
        int slot = (type == 1) ? LocalId() : -1;
        if (type == 1) {
            if (slot < 0 || slot >= 4) slot = 0;
        }
        nid2 = lo | (((slot + 1) << 24) | (hi << 16));
        a->wC = nid2;
    }
    char* name = RdS(rd);
    if (src) {
        a->x60.SetSkl(src);
        name = 0;
    }
    char* label = 0;
    if (rd->version >= 0x3C) label = RdS(rd);
    int health = RdI(rd);
    int maxh = RdI(rd);
    {
        V4* v;
        v = &m.r[3]; RdV(rd, v);
        v = &m.r[0]; RdV(rd, v);
        v = &m.r[1]; RdV(rd, v);
        v = &m.r[2]; RdV(rd, v);
    }
    SITE(0, 1)
    SITE(1, 8)
    SITE(2, 1)
    {
        int i;
        for (i = 0; i < 2; i++) RdI2(rd, &weap[i]);
    }
    if (rd->version >= 0x34) {
        RdI2(rd, &a->x3548);
        if (a->x3548 >= 0) {
            SetQ(&m.r[3], cNode_GetLoc(*std_vector_cNodePtr_opIndex(D_004FFBE0, a->x3548)));
        }
    } else {
        a->x3548 = -1;
    }
    cHuman_InitHuman(a, &m, name, health, maxh, weap, flag, type, label);
    a->x30 = 1;
    return a;
}
#undef cHuman_InitHuman /* merge_units */
static inline void merge_flush_func_001B6AB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B6AB0 */
