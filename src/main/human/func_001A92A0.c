#pragma cplusplus on
#pragma always_inline on
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs on
#pragma opt_propagation off
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct VR { float x, y, z, w; VR() {} VR(const VR& o) { x = o.x; y = o.y; z = o.z; w = o.w; } } __attribute__((aligned(16)));
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Key30;
typedef struct { char c[0x40]; } __attribute__((aligned(16))) Ev40;
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Ev30;
typedef struct { char c[0x50]; } __attribute__((aligned(16))) Ev50;
typedef struct { char c[0x60]; } __attribute__((aligned(16))) Ev60;
typedef struct { char c[0x70]; } __attribute__((aligned(16))) Ev70;
typedef struct { char c[0xA0]; } __attribute__((aligned(16))) Buf_A0;
typedef struct { char c[0xC0]; } __attribute__((aligned(16))) Buf_C0;
typedef struct { char c[0x20]; } __attribute__((aligned(16))) Buf_20;
typedef struct { char c[0x100]; } __attribute__((aligned(16))) Buf_100;
typedef struct { char c[0x200]; } __attribute__((aligned(16))) Buf_200;
typedef struct { char c[0x400]; } __attribute__((aligned(16))) Buf_400;
typedef struct { int a, b; } Y2;
typedef struct { float x, y, z; } V4u;

class Ctl_L { public: VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsLocal(); };

#define AI(o) (*(int*)(a + (o)))
#define AU(o) (*(unsigned int*)(a + (o)))
#define AB(o) (*(unsigned char*)(a + (o)))
#define AF(o) (*(float*)(a + (o)))
#define AP(o) (*(char**)(a + (o)))
#define MI(o) (*(int*)(m + (o)))
#define MU(o) (*(unsigned int*)(m + (o)))
#define MB(o) (*(unsigned char*)(m + (o)))
#define MSB(o) (*(signed char*)(m + (o)))
#define MF(o) (*(float*)(m + (o)))
#define MP(o) (*(char**)(m + (o)))
#define PI(p, o) (*(int*)((char*)(p) + (o)))
#define PB(p, o) (*(unsigned char*)((char*)(p) + (o)))
#define PF(p, o) (*(float*)((char*)(p) + (o)))
#define PP(p, o) (*(char**)((char*)(p) + (o)))
#define VF(o, off, T) (*(T*)(*(char**)(o) + (off)))
struct VO {
    virtual void x00();
    virtual void f01(void*);
    virtual void x02();
    virtual void x03();
    virtual void x04();
    virtual void x05();
    virtual void f06();
    virtual void x07();
    virtual void x08();
    virtual void x09();
    virtual void x10();
    virtual void x11();
    virtual void x12();
    virtual void x13();
    virtual void x14();
    virtual void x15();
    virtual void x16();
    virtual void x17();
    virtual void x18();
    virtual void x19();
    virtual void f20();
    virtual void f21(int);
    virtual void x22();
    virtual void x23();
    virtual void x24();
    virtual void x25();
    virtual void x26();
    virtual void x27();
    virtual void x28();
    virtual void x29();
    virtual void x30();
    virtual void x31();
    virtual void x32();
    virtual void x33();
    virtual void x34();
    virtual void x35();
    virtual void x36();
    virtual void x37();
    virtual void x38();
    virtual void x39();
    virtual void x40();
    virtual void x41();
    virtual void x42();
    virtual void x43();
    virtual void x44();
    virtual void x45();
    virtual VR f46(int);
    virtual void x47();
    virtual void x48();
    virtual void x49();
    virtual void x50();
    virtual void x51();
    virtual void x52();
    virtual void x53();
    virtual VR f54();
    virtual void x55();
    virtual void x56();
    virtual void x57();
    virtual void x58();
    virtual void x59();
    virtual void x60();
    virtual void x61();
    virtual void x62();
    virtual void x63();
    virtual int f64();
};
#define VO_(o) ((VO*)(o))

extern "C" {
extern unsigned char D_005721C8;
extern int D_0049D010;
extern float D_0049D038;
extern char D_0049D048[], D_0049DBC0[], D_0049E080[], D_0049E4A0[], D_0049E4D0[], D_0049E500[], D_0049E520[];
extern char D_0049E540[], D_0049E558[], D_0049E570[], D_0049E590[], D_0049E5B0[], D_0049E5C8[], D_0049E5E0[];
extern char D_0049E600[], D_0049E620[], D_0049E640[];
extern char D_004D9180[], D_004D9360[], D_004DA930[], D_004DA950[], D_004DCC70[], D_004E00E0[], D_004E01A0[];
extern char D_004E0840[], D_004EA0B0[], D_004FF2B0[], D_004FFB50[], D_00542B60[], D_005435A0[], D_0055A1D8[];
extern char D_0055D480[], D_0055D4E0[];
extern signed char D_004EED58;
extern char D_004EED60[];

void Actor_ApplyBlind(char* a, int f, float t);
void Actor_ApplyFlash(char* a, int f, float t);
void Actor_ApplyControlInput(char* p, char* v, int f, float x, float y);
void Actor_ChooseSecondaryMode(char* a, int mode);
void Actor_FlashbangHide(char* a, char* m);
char* Actor_GetFloorRoot2(char* a);
void Actor_HandleDeathAction(char* a, char* m);
void Actor_HandleFire(char* a, void* b);
void Actor_HandleLedgeAction(char* a, char* m);
void Actor_HandleObjectAction(char* a, char* m);
int Actor_HangSlotClimbable(char* a);
void Actor_Ignite(char* a, int f, char* o, int x, int y, float t);
void Actor_JumpForGrab(char* a, char* m);
void Actor_ReleaseSecondary(char* a, char* m);
void Actor_RequestRunningJump(char* a, char* m);
void Actor_ResolveMotionSelection(void* sel, int* out, void* y, void* model);
void Actor_SetLookTarget(char* l, char* o);
void Actor_StartFall(char* a);
float AnimChannel_GetCurrent(void* c, int i);
void AnimCtl_InstallMotion(void* ctl, int id, int mode, void* range, void* pair, void* m1, void* m2, void* x, float f0, float f1);
void AnimEvent_Construct(void* e);
void AnimEvent_Copy(void* d, void* s);
void AnimPriority_Helper0(void* p, int index, unsigned char on);
void AnimPriority_Helper1(void* p);
void AnimPriority_Helper2(void* p, int index, int v);
unsigned char AnimPriority_Helper3(void* bits, int index);
V4* AnimRate_Init(void* p, float f);
void BitArray_Assign(void* p, int i, int v);
unsigned char BitSet_Test(void* p, int i);
void CanonicalKey_Construct(void* k, char* s);
void Event_Construct(void* e, char* t);
void Event_Send(void* e, char* t, int f);
unsigned char Inventory_GetEquipMode(char* w);
void Ladder_HandleExitAction(char* a, char* m);
void LookCtl_ClearSlot(char* l, int s, int f);
void LookCtl_SetSlotPoint(char* l, int s, void* p);
float Math_Atan2f(float y, float x);
float Math_Cos(float x);
float Math_CosThunk(float x);
float Math_Sin(float x);
float Math_SinThunk(float x);
float Model_GetFirstFloat(void* m);
void MotionRequest_Construct(void* d, void* n);
void MotionRequest_Copy(void* d, void* s);
void MotionRequest_ResolveName(void* d, char* lib);
int Motion_Lookup(char* lib, char* name);
void* Mtx_GetIdentity(void);
char* Object_LookupById(void* id);
void Physical_ClearModeBit(char* p, int b);
char* Physical_GetLatchSlot(char* p, int i);
void Physical_LatchEdgeRequest(char* s, int v);
void Physical_SetModeBit(char* p, int b);
void* Placement_GetIdentity(void* d, void* a, void* b);
float* Placement_GetPosition(void* p);
void Ptr_Identity(void* p);
char** Ptr_IdentityCast(char* p);
void Root_Attach(char* r, char* c, int f);
float* Root_GetWorldBasePlacement(char* r);
void* Root_GetWorldPlacement(char* r);
void Root_SetWorldPlacement(char* r, void* p);
unsigned char Secondary_RequestOneShot(char* s, void* k, int f, void* e);
char* Service_Lookup(char* a, char* b);
V4* Vec4_Assign(void* d, void* s);
void Vec4_Copy(void* d, void* s, void* t);
void Vec4_CopyAsPoint(void* d, void* s);
V4* Vec4_Copy_18A350(void* d, void* s);
void Vec4_SetXYZ_W(void* d, void* s, float f);
void Vec4_Subtract(void* d, void* a, void* b);
char* WeakRef_Get(void* r);
int WeaponInv_AllowsAction(char* w);
void WeaponInv_HolsterCurrent(char* w);
void Weapon_StartReload(char* w);
void cAIGOBJMsg_ctor(void* e, char* t, char* o);
void cAIGOBJMsg_dtor(void* e, int f);
void cMessage_ctor(void* e, char* m);
void cMessage_ctor3(void* e, char* m);
void cMessage_dtor(void* e, int f);
int printf(const char* f, ...);
void func_00131B70(void* p, int f);
void func_0013AAE0(void* p);
void func_00140D40(void* p, int f);
void func_0014B160(void* d, void* m, void* p);
int func_0014D410(int v);
int func_0014D450(int v);
int func_0014D460(char* a);
void func_0016F7E0(void* d, void* s);
void func_00189F40(void* p, int f);
void func_00189FD0(void* p, int f);
void func_0018A040(void* p, int f);
void func_0018A260(void* p, int f);
int MotionRequest_GetMode(void* s);
void* func_0018A2E0(void* s);
float func_0018A2D0(void* s);
float func_0018A2C0(void* s);
void func_0018A700(void* p, int v);
void func_0018A710(void* d, void* s);
void func_0018A890(void* p);
void func_0018A8C0(void* p);
void MotionTokens_Init(void* p);
void func_0018C620(void* y, int m);
void* func_0018C6A0(void* s);
void* func_00190F90(void* x, void* r, int a, char* b);
void* func_00192750(void* r, float a, float b, int k);
char* func_001A02B0(char* r, char* n);
void func_001A1500(void* p);
int func_001A6D00(void* a, void* b);
void func_001A6D20(void* a);
char** func_001A7790(void* a);
void func_001A77A0(void* d, int v);
void func_001A77C0(void* d, int v);
int func_001A77D0(char* p);
int func_001A9210(char* a);
void func_001AD710(void* d, char* s);
void func_001AD750(void* d, float f, float g);
char* func_001AD8B0(char* p);
void ActorRelation_AddChild(char* a, char* b);
void RootAttachments_Attach(char* r, void* p);
void func_001ADA90(void* d, void* s);
void Actor_LinkBody(char* a, char* b);
void func_001ADB90(void* p, int f);
void func_001ADBE0(void* p, int f);
void* func_001ADC50(void* p);
void* func_001ADC60(void* p);
void* func_001ADC70(void* p);
void func_001ADC80(void* d, void* s);
void* func_001ADD40(void* p);
int func_001ADD50(int v);
int func_001ADD60(void* p);
void* func_001ADD70(void* p);
int func_001ADD80(void* p);
void func_001ADFE0(void* p, int v);
void* Actor_SetMotionOverride(void* d, void* s);
void* func_001AE020(void* d, int k, float f);
void* func_001AE050(void* x, int i, int id, char* a);
int func_001AE0B0(char* p, int v);
int func_001AE0D0(char* a, int v);
char* func_001AE140(char* a);
void func_001AE170(void* d, void* s, int n);
int func_001AE190(void* k);
void* func_001AE260(int v);
int func_001AE270(int v);
void func_001AE280(void* k, int n);
void LosProvider_SeedRegion(int s, int v);
int func_001AE360(char* s);
void func_001AE370(void* e);
void func_001AE3B0(char* p, char* v, float x, float y);
void Backpack_Hide(char* p);
int Net_GetClock(int v);
}

static inline unsigned char IsLoc(char* a)
{
    unsigned char r = 0;
    Ctl_L* c = *(Ctl_L**)(a + 0x58);
    if (c && c->IsLocal()) r = 1;
    return r;
}
static inline void QCp(void* d, const void* s) { const void* ss = s; void* dd = d; __int128 q; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(dd), "r"(ss) : "memory"); }
#define NETFLAG(bit, on) \
    if (D_005721C8) { unsigned char* np = (unsigned char*)AP(0x3584); if (np && AB(0x14)) { if (on) np[0x50] |= (bit); else np[0x50] &= ~(bit); } }
/* NAME_COPY_N: the empty asm in the else arm is a scheduling barrier that keeps the zero store unhoisted. */
#define NAME_COPY_N(dst, src) \
    { \
        unsigned char ckc_end = 0; \
        int ckc_i; \
        for (ckc_i = 0; ckc_i < 0x2F; ckc_i++) { \
            if ((src)[ckc_i] == 0) ckc_end = 1; \
            { char ckc_c = 0; if (ckc_end) asm { .set reorder } else ckc_c = (src)[ckc_i]; (dst)[ckc_i] = ckc_c; } \
        } \
        (dst)[ckc_i] = 0; \
    }
typedef struct { unsigned char kind; char pad[3]; char pairs[0x38]; char tail[0x10]; } XS;
static inline void XInit(XS* x) { x->kind = 0; MotionTokens_Init(x->pairs); func_0018A8C0(x->tail); }
static inline void XDtor(XS* x) { func_00189FD0(x->tail, -1); func_0018A040(x->pairs, -1); }
#define FwdMsg(a, m, f) { \
    Ev30 c; \
    char* ep = c.c; \
    cMessage_ctor(ep, m); \
    PP(ep, 0) = D_004E0840; \
    PI(ep, 0x24) = MI(0x24); \
    *(signed char*)(ep + 0x28) = *(signed char*)(m + 0x28); \
    PB(&c, 0x20) = 4; \
    PI(&c, 0x1C) = 0x40; \
    Event_Send(ep, a, f); \
    PP(&c, 0) = D_004E0840; \
    cMessage_dtor(ep, 0); \
}
typedef void (*FnPV)(char*, void*);
typedef void (*FnP)(char*);
typedef void (*FnPI)(char*, int);
typedef int (*FnRP)(char*);
typedef void (*FnSR)(void*, char*);
typedef void (*FnSRF)(void*, char*, float);
typedef unsigned char (*FnRB)(char*);
typedef void (*FnOut)(void*, char*, int);
typedef void (*FnOut0)(void*, char*);

static inline void APri(char* a, int k, int on)
{
    char* p = a + 0x320C;
    unsigned char o = AnimPriority_Helper3(p + 0xC, k);
    AnimPriority_Helper2(p + 4, k, on);
    AnimPriority_Helper1(p);
    AnimPriority_Helper0(p, k, o);
}
static inline void PlaySlotI(char* a, XS* xp, V4* rp, int mode)
{
    int s;
    char* c;
    int id;
    Ev40 e1, e2;
    s = AI(0x326C);
    a = a + 0x2EC0;
    AnimEvent_Construct(&e1);
    AnimEvent_Construct(&e2);
    c = (char*)func_0018C6A0(a);
    id = func_001AE270(s);
    AnimCtl_InstallMotion(c, id, mode, rp, func_001AE260(s), &e1, &e2, xp, -1.0f, 0.0f);
    func_0018A260(&e2, -1);
    func_0018A260(&e1, -1);
}
#define PlaySlot(a, mode) PST(a, RT(D_0049D038), XT(), mode)
static inline void PlayNamed(char* a, void* x, void* name, V4* r, int mode)
{
    int id;
    char* c = a + 0x2EC0;
    id = Motion_Lookup(AP(0x2EC0), (char*)name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        c = (char*)func_0018C6A0(c);
        func_0018C620(&y, id);
        AnimCtl_InstallMotion(c, id, mode, r, &y, &e1, &e2, x, -1.0f, 0.0f);
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
}
static inline void PlayNamedL(char* a, void* x, void* name, V4* r, int mode)
{
    char* c = a + 0x2EC0;
    int id;
    id = Motion_Lookup(AP(0x2EC0), (char*)name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        a = (char*)func_0018C6A0(c);
        func_0018C620(&y, id);
        AnimCtl_InstallMotion(a, id, mode, r, &y, &e1, &e2, x, -1.0f, 0.0f);
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
}
static inline unsigned char IsDown(char* a)
{
    unsigned char k = VO_(a)->f64();
    return k == 3 || k == 2;
}
static inline void FailInit(char* p)
{
    Event_Construct(p, D_0055A1D8);
    PP(p, 0) = D_004DA950;
    PI(p, 0x24) = 9;
    PI(p, 0x28) = -1;
    PI(p, 0x2C) = 0;
}
static inline void EvInit(char* p, int id, unsigned char b)
{
    Event_Construct(p, D_0055D480);
    PP(p, 0) = D_004E0840;
    PI(p, 0x24) = id;
    PB(p, 0x28) = b;
}
struct FailEv {
    char c[0x40];
    FailEv() {
        Event_Construct(this, D_0055A1D8);
        PP(this, 0) = D_004DA950;
        PI(this, 0x24) = 9;
        PI(this, 0x28) = -1;
        PI(this, 0x2C) = 0;
    }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~FailEv() {
        PP(this, 0) = D_004DA950;
        cMessage_dtor(this, 0);
    }
};
#define FailMsg(a) { \
    Ev40 e; \
    char* p = e.c; \
    FailInit(p); \
    Event_Send(p, AP(0x58), 1); \
    PP(&e, 0) = D_004DA950; \
    cMessage_dtor(p, 0); \
}
struct CtlS { void Sel(Buf_A0* selp, V4* rtp); void Sel2(Buf_A0* rsel, Buf_A0* selp, V4* rtp); void Lnk(CtlS* o) { char* oc = (char*)o; char* ctl = (char*)this; ActorRelation_AddChild(oc + 0x100, ctl + 0x100); } float Cur(int ch) { char* ctl = (char*)this; return AnimChannel_GetCurrent(ctl + 0x10, ch); } };
#define LATCH(i) Physical_LatchEdgeRequest(Physical_GetLatchSlot(AP(0x3310) + 0x3E0, (i)), 0)
#define KEYFILL(k, s) \
    { Key30 kf; CanonicalKey_Construct(&kf, (s)); if (!func_001AE190(&(k)) || !func_001AE190(&kf)) func_001AE170(&(k), &kf, 3); }

static inline void PlaySlotBI(char* a, XS* xp, V4* rp, int mode)
{
    int s;
    char* c;
    int id;
    Ev40 e1, e2;
    s = AI(0x326C);
    a = a + 0x2EC0;
    AnimEvent_Construct(&e1);
    AnimEvent_Construct(&e2);
    c = (char*)func_0018C6A0(a);
    id = func_001AE270(s);
    AnimCtl_InstallMotion(c, id, mode, rp, func_001AE260(s), &e1, &e2, xp, -1.0f, 0.0f);
    func_0018A260(&e2, -1);
    func_0018A260(&e1, -1);
}
#define PlaySlotB(a, mode) PSBT(a, RT2(D_0049D038), XT(), mode)
static inline void SelCtor(char* p, int id, unsigned char f, void* xp)
{
    PB(p, 0) = 2;
    func_0018A890(p + 0x10);
    PI(p, 0x44) = id;
    PB(p, 0x48) = f;
    func_0018A710(p + 0x4C, xp);
    PF(p, 0x98) = -1.0f;
    PI(p, 0x9C) = 0;
}
inline void CtlS::Sel(Buf_A0* selp, V4* rtp)
{
    char* ctl = (char*)this;
    unsigned char* s;
    int out;
    Y2 y;
    char* q = ctl + 0x34;
    s = (unsigned char*)Actor_SetMotionOverride(q, AnimRate_Init(rtp, D_0049D038));
    func_0018A700(&y, -1);
    Actor_ResolveMotionSelection(selp, &out, &y, *(void**)s);
    if (out) {
        V4 t, rr;
        Ev40 e1, e2;
        int md;
        void* pp;
        float g0;
        V4* rp = s[5] ? (V4*)(s + 8) : AnimRate_Init(&t, Model_GetFirstFloat(*(void**)s));
        Vec4_Copy_18A350(&rr, rp);
        s[5] = 0;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        md = MotionRequest_GetMode(selp);
        pp = func_0018A2E0(selp);
        g0 = func_0018A2D0(selp);
        AnimCtl_InstallMotion(s, out, md, &rr, &y, &e1, &e2, pp, g0, func_0018A2C0(selp));
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
}
inline void CtlS::Sel2(Buf_A0* rsel, Buf_A0* selp, V4* rtp)
{
    char* ctl = (char*)this;
    unsigned char* s;
    int out;
    Y2 y;
    char* q = ctl + 0x34;
    s = (unsigned char*)Actor_SetMotionOverride(q, AnimRate_Init(rtp, D_0049D038));
    func_0018A700(&y, -1);
    Actor_ResolveMotionSelection(rsel, &out, &y, *(void**)s);
    if (out) {
        V4 t, rr;
        Ev40 e1, e2;
        int md;
        void* pp;
        float g0;
        V4* rp = s[5] ? (V4*)(s + 8) : AnimRate_Init(&t, Model_GetFirstFloat(*(void**)s));
        Vec4_Copy_18A350(&rr, rp);
        s[5] = 0;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        md = MotionRequest_GetMode(selp);
        pp = func_0018A2E0(selp);
        g0 = func_0018A2D0(selp);
        AnimCtl_InstallMotion(s, out, md, &rr, &y, &e1, &e2, pp, g0, func_0018A2C0(selp));
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
}
struct SelT {
    char c[0xA0];
    SelT(int id, unsigned char fl, void* xp) {
        char* p = c;
        PB(p, 0) = 2;
        func_0018A890(p + 0x10);
        PI(p, 0x44) = id;
        PB(p, 0x48) = fl;
        func_0018A710(p + 0x4C, xp);
        PF(p, 0x98) = -1.0f;
        PI(p, 0x9C) = 0;
    }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~SelT() { func_00189F40(c + 0x4C, -1); }
} __attribute__((aligned(16)));
#define PlaySel(a, xp, id, fl) { \
    V4 rt; \
    Buf_A0 sel; \
    int idv = (id); \
    char* p = sel.c; \
    PB(p, 0) = 2; \
    func_0018A890(p + 0x10); \
    PI(p, 0x44) = idv; \
    PB(p, 0x48) = (fl); \
    func_0018A710(p + 0x4C, (xp)); \
    PF(p, 0x98) = -1.0f; \
    PI(p, 0x9C) = 0; \
    ((CtlS*)(a + 0x2EC0))->Sel(&sel, &rt); \
    func_00189F40(sel.c + 0x4C, -1); \
}
#define PlaySelP(a, xp, id, fl) { \
    V4 rt; \
    Buf_A0 sel; \
    int idv = (id); \
    char* p = sel.c; \
    PB(p, 0) = 2; \
    func_0018A890(p + 0x10); \
    PI(p, 0x44) = idv; \
    PB(p, 0x48) = (fl); \
    func_0018A710(p + 0x4C, (xp)); \
    PF(p, 0x98) = -1.0f; \
    PI(p, 0x9C) = 0; \
    ((CtlS*)(a + 0x2EC0))->Sel((Buf_A0*)p, &rt); \
    func_00189F40(sel.c + 0x4C, -1); \
}
#define PlaySelP2(a, xp, id, fl) { \
    V4 rt; \
    Buf_A0 sel; \
    int idv = (id); \
    char* p = sel.c; \
    PB(p, 0) = 2; \
    func_0018A890(p + 0x10); \
    PI(p, 0x44) = idv; \
    PB(p, 0x48) = (fl); \
    func_0018A710(p + 0x4C, (xp)); \
    PF(p, 0x98) = -1.0f; \
    PI(p, 0x9C) = 0; \
    ((CtlS*)(a + 0x2EC0))->Sel2((Buf_A0*)p, &sel, &rt); \
    func_00189F40(sel.c + 0x4C, -1); \
}
static inline void AttachAll(char* a)
{
    char* b = a + 0x2EC0;
    int it, end;
    char* r;
    func_001A77C0(&it, func_001A77D0(b + 0x100));
    func_001A77A0(&end, func_001A77D0(b + 0x100));
    r = func_001A02B0(b, D_0049D048);
    while (func_001A6D00(&it, &end)) {
        Root_Attach(r, func_001A02B0(*Ptr_IdentityCast(*func_001A7790(&it)), D_0049D048), 1);
        func_001A6D20(&it);
    }
}
inline bool BTn(void* p, int i) { return !(BitSet_Test(p, i) != 0); }
inline bool BIs(unsigned char v) { return v != 0; }
inline bool NB2(char* o, int off) { return !(PB(o, off) != 0); }
struct MRT;
static inline void PlayMR(char* a, const MRT& mr)
{
    Buf_A0 mc;
    char* s5;
    int s4;
    s4 = AI(0x326C);
    s5 = a + 0x2EC0;
    MotionRequest_Copy(&mc, (void*)&mr);
    MotionRequest_ResolveName(&mc, *(char**)s5);
    if (func_001ADD80(&mc)) {
        Ev40 e1;
        Ev50 e2;
        void* c;
        int id;
        void* rg;
        Y2 y;
        AnimEvent_Construct(&e1);
        func_001A1500(&e2);
        c = func_001ADD70(s5 + 0x10);
        id = func_001ADD50(func_001ADD60(&mc));
        rg = func_001ADD40(&mc);
        func_001ADC80(&y, &mc);
        AnimCtl_InstallMotion(c, id, 1, rg, &y, func_001ADC70(&mc), &e1, &e2, -1.0f, 0.0f);
        func_00189F40(&e2, -1);
        func_0018A260(&e1, -1);
    }
    {
        Ev40 e3, e5;
        Ev50 e4;
        int got;
        void* m2;
        void* rg;
        int md;
        void* c;
        int id;
        AnimEvent_Construct(&e3);
        got = 0;
        func_001A1500(&e4);
        if (func_001ADD80(&mc)) {
            AnimEvent_Construct(&e5);
            got = 1;
            m2 = &e5;
        } else {
            m2 = func_001ADC70(&mc);
        }
        if (func_001ADD80(&mc)) rg = func_001ADC60(&mc); else rg = func_001ADC50(&mc);
        if (func_001ADD80(&mc)) md = 0; else md = 1;
        s5 = (char*)func_001ADD70(s5 + 0x10);
        id = func_001AE270(s4);
        AnimCtl_InstallMotion(s5, id, md, rg, func_001AE260(s4), &e3, m2, &e4, -1.0f, 0.0f);
        func_00189F40(&e4, -1);
        if (got) func_0018A260(&e5, -1);
        func_0018A260(&e3, -1);
    }
    func_001ADBE0(&mc, -1);
}
static inline void SubTo(V4* d, V4* x, V4* y)
{
    V4 t;
    Ptr_Identity(&t);
    Vec4_Subtract(&t, x, y);
    Vec4_Assign(d, &t);
}
static inline void SetPt(char* p, void* mx, char* src)
{
    V4 cp;
    Vec4_CopyAsPoint(&cp, src);
    {
        char* d = p;
        // Empty scheduling barrier: keep the destination address before the matrix argument.
        asm { .set noat }
        func_0014B160(d, mx, &cp);
    }
}
static inline void SetLook(char* a, int slot, void* src)
{
    V4 v;
    LookCtl_SetSlotPoint(AP(0x3314), slot, Vec4_Assign(&v, src));
}

struct XT {
    unsigned char kind; char pad[3]; char pairs[0x38]; char tail[0x10];
    XT() { XT* q = this; q->kind = 0; MotionTokens_Init(q->pairs); func_0018A8C0(q->tail); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~XT() { func_00189FD0(tail, -1); func_0018A040(pairs, -1); }
    XT* p() { return this; }
};
struct RT { float x, y, z, w; RT(float f) { AnimRate_Init(this, f); } } __attribute__((aligned(16)));
struct RT2 { float x, y, z, w; RT2(float f) { func_001AD750(this, f, 0.0f); } } __attribute__((aligned(16)));
struct KT { char c[0x30]; KT(char* s) { CanonicalKey_Construct(this, s); } } __attribute__((aligned(16)));
static inline void PNT(char* a, const KT& name, const RT& r, void* x, int mode)
{
    int id;
    char* c = a + 0x2EC0;
    id = Motion_Lookup(AP(0x2EC0), (char*)&name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        c = (char*)func_0018C6A0(c);
        func_0018C620(&y, id);
        AnimCtl_InstallMotion(c, id, mode, (V4*)&r, &y, &e1, &e2, x, -1.0f, 0.0f);
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
}
static inline void PNLT(char* a, const KT& name, const RT& r, void* x, int mode)
{
    char* c = a + 0x2EC0;
    int id;
    id = Motion_Lookup(AP(0x2EC0), (char*)&name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        a = (char*)func_0018C6A0(c);
        func_0018C620(&y, id);
        AnimCtl_InstallMotion(a, id, mode, (V4*)&r, &y, &e1, &e2, x, -1.0f, 0.0f);
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
}
static inline void PNLTr(char* a, char*& c, const KT& name, const RT& r, void* x, int mode)
{
    int id;
    c = a + 0x2EC0;
    id = Motion_Lookup(AP(0x2EC0), (char*)&name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        a = (char*)func_0018C6A0(c);
        func_0018C620(&y, id);
        AnimCtl_InstallMotion(a, id, mode, (V4*)&r, &y, &e1, &e2, x, -1.0f, 0.0f);
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
}
static inline void PNLT2(char* a, const KT& name, const RT2& r, void* x, int mode)
{
    char* c = a + 0x2EC0;
    int id;
    id = Motion_Lookup(AP(0x2EC0), (char*)&name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        a = (char*)func_0018C6A0(c);
        func_0018C620(&y, id);
        AnimCtl_InstallMotion(a, id, mode, (V4*)&r, &y, &e1, &e2, x, -1.0f, 0.0f);
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
}
static inline void PNLT3(char* a, const KT& name, const RT& r, const XT& x, int mode)
{
    char* c = a + 0x2EC0;
    int id;
    id = Motion_Lookup(AP(0x2EC0), (char*)&name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        a = (char*)func_0018C6A0(c);
        func_0018C620(&y, id);
        AnimCtl_InstallMotion(a, id, mode, (V4*)&r, &y, &e1, &e2, (void*)&x, -1.0f, 0.0f);
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
}
static inline void PNLT4(char* a, const KT& name, const RT2& r, const XT& x, int mode)
{
    char* c = a + 0x2EC0;
    int id;
    id = Motion_Lookup(AP(0x2EC0), (char*)&name);
    if (id) {
        Ev40 e1, e2;
        Y2 y;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        a = (char*)func_0018C6A0(c);
        func_0018C620(&y, id);
        AnimCtl_InstallMotion(a, id, mode, (V4*)&r, &y, &e1, &e2, (void*)&x, -1.0f, 0.0f);
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
}
static inline void PST(char* a, const RT& r, const XT& x, int mode)
{
    int s;
    char* c;
    int id;
    Ev40 e1, e2;
    s = AI(0x326C);
    a = a + 0x2EC0;
    AnimEvent_Construct(&e1);
    AnimEvent_Construct(&e2);
    c = (char*)func_0018C6A0(a);
    id = func_001AE270(s);
    AnimCtl_InstallMotion(c, id, mode, (V4*)&r, func_001AE260(s), &e1, &e2, (void*)&x, -1.0f, 0.0f);
    func_0018A260(&e2, -1);
    func_0018A260(&e1, -1);
}
static inline void PSBT(char* a, const RT2& r, const XT& x, int mode)
{
    int s;
    char* c;
    int id;
    Ev40 e1, e2;
    s = AI(0x326C);
    a = a + 0x2EC0;
    AnimEvent_Construct(&e1);
    AnimEvent_Construct(&e2);
    c = (char*)func_0018C6A0(a);
    id = func_001AE270(s);
    AnimCtl_InstallMotion(c, id, mode, (V4*)&r, func_001AE260(s), &e1, &e2, (void*)&x, -1.0f, 0.0f);
    func_0018A260(&e2, -1);
    func_0018A260(&e1, -1);
}
struct RTU { float x, y, z, w; RTU() {} } __attribute__((aligned(16)));
struct ST {
    char c[0xA0];
    ST(char*& p, int id, unsigned char fl, void* xp) {
        p = c;
        PB(p, 0) = 2;
        func_0018A890(p + 0x10);
        PI(p, 0x44) = id;
        PB(p, 0x48) = fl;
        func_0018A710(p + 0x4C, xp);
        PF(p, 0x98) = -1.0f;
        PI(p, 0x9C) = 0;
    }
    ST(int id, unsigned char fl, void* xp) {
        char* p = c;
        PB(p, 0) = 2;
        func_0018A890(p + 0x10);
        PI(p, 0x44) = id;
        PB(p, 0x48) = fl;
        func_0018A710(p + 0x4C, xp);
        PF(p, 0x98) = -1.0f;
        PI(p, 0x9C) = 0;
    }
    ST(int id, unsigned char fl, const XT& x) {
        char* p = c;
        PB(p, 0) = 2;
        func_0018A890(p + 0x10);
        PI(p, 0x44) = id;
        PB(p, 0x48) = fl;
        func_0018A710(p + 0x4C, (void*)&x);
        PF(p, 0x98) = -1.0f;
        PI(p, 0x9C) = 0;
    }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ST() { func_00189F40(c + 0x4C, -1); }
} __attribute__((aligned(16)));
struct CtlT { void SelX(const RTU& rtr, const ST& sr); void SelX2(const RTU& rtr, const ST& sr); };
#define PlaySelT(a, x, id, fl) ((CtlT*)((a) + 0x2EC0))->SelX(RTU(), ST((id), (fl), x))
#define PlaySelT2(a, x, id, fl) ((CtlT*)((a) + 0x2EC0))->SelX2(RTU(), ST((id), (fl), x))
#define PlaySelT2R(a, x, id, fl, pv) ((CtlT*)((a) + 0x2EC0))->SelX2(RTU(), ST(pv, (id), (fl), x))
inline void CtlT::SelX(const RTU& rtr, const ST& sr)
{
#define selp ((Buf_A0*)&sr)
#define rtp ((V4*)&rtr)
    char* ctl = (char*)this;
    unsigned char* s;
    int out;
    Y2 y;
    char* q = ctl + 0x34;
    s = (unsigned char*)Actor_SetMotionOverride(q, AnimRate_Init(rtp, D_0049D038));
    func_0018A700(&y, -1);
    Actor_ResolveMotionSelection(selp, &out, &y, *(void**)s);
    if (out) {
        V4 rr, t;
        Ev40 e1, e2;
        int md;
        void* pp;
        float g0;
        V4* rp = s[5] ? (V4*)(s + 8) : AnimRate_Init(&t, Model_GetFirstFloat(*(void**)s));
        Vec4_Copy_18A350(&rr, rp);
        s[5] = 0;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        md = MotionRequest_GetMode(selp);
        pp = func_0018A2E0(selp);
        g0 = func_0018A2D0(selp);
        AnimCtl_InstallMotion(s, out, md, &rr, &y, &e1, &e2, pp, g0, func_0018A2C0(selp));
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
}
inline void CtlT::SelX2(const RTU& rtr, const ST& sr)
{
#define rsel ((Buf_A0*)&sr)
#define selp ((Buf_A0*)&sr)
#define rtp ((V4*)&rtr)
    char* ctl = (char*)this;
    unsigned char* s;
    int out;
    Y2 y;
    char* q = ctl + 0x34;
    s = (unsigned char*)Actor_SetMotionOverride(q, AnimRate_Init(rtp, D_0049D038));
    func_0018A700(&y, -1);
    Actor_ResolveMotionSelection(rsel, &out, &y, *(void**)s);
    if (out) {
        V4 rr, t;
        Ev40 e1, e2;
        int md;
        void* pp;
        float g0;
        V4* rp = s[5] ? (V4*)(s + 8) : AnimRate_Init(&t, Model_GetFirstFloat(*(void**)s));
        Vec4_Copy_18A350(&rr, rp);
        s[5] = 0;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        md = MotionRequest_GetMode(selp);
        pp = func_0018A2E0(selp);
        g0 = func_0018A2D0(selp);
        AnimCtl_InstallMotion(s, out, md, &rr, &y, &e1, &e2, pp, g0, func_0018A2C0(selp));
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
}
#undef selp
#undef rtp
#undef rsel
struct OSE0 { char c[0x40];
    OSE0(char* a) { char* ep = c; Event_Construct(ep, D_00542B60); PP(ep, 0) = D_004DA930; PI(ep, 0x24) = 0; PB(ep, 0x28) = 0; PP(ep, 0x2C) = a; PB(ep, 0x30) = 0; PI(ep, 0x34) = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~OSE0() { PP(this, 0) = D_004DA930; cMessage_dtor(this, 0); } } __attribute__((aligned(16)));
struct MRT { char c[0xA0];
    MRT(Key30* k, const RT& r2, const RT& r1, const OSE0& ev) { char* mp = c; MotionRequest_Construct(mp, k); func_001ADFE0(mp + 0x30, 0); func_0018A700(mp + 0x34, -1); Vec4_Copy_18A350(mp + 0x3C, (void*)&r2); Vec4_Copy_18A350(mp + 0x4C, (void*)&r1); AnimEvent_Copy(mp + 0x5C, (void*)&ev); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MRT() { func_0018A260(c + 0x5C, -1); func_001ADB90(c + 0x30, -1); }
    char* q() { return c; } } __attribute__((aligned(16)));
struct V4T { float x, y, z, w; V4T(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } } __attribute__((aligned(16)));
static inline void QCpT(void* d, const V4T& s) { QCp(d, (void*)&s); }
struct VP { float x, y, z, w; VP(const float* s) { Vec4_Assign(this, (void*)s); } } __attribute__((aligned(16)));
struct VC { float x, y, z, w; VC() { Ptr_Identity(this); } VC(const VC& o) { Vec4_Assign(this, (void*)&o); } } __attribute__((aligned(16)));
static inline VC DirOf(V4* v) { VC t; func_001ADA90(&t, v); return t; }
static inline float Yaw(const VC& d) { return Math_Atan2f(-d.x, d.y); }
struct AA { float x, y, z, w; AA(V4* ax, float f) { Vec4_SetXYZ_W(this, ax, f); } } __attribute__((aligned(16)));
static inline void QAA(V4* q, const AA& w) { float hf = 0.5f * w.w; float c = Math_CosThunk(hf); float sn = Math_SinThunk(hf); q->w = c; q->x = sn * w.x; q->y = sn * w.y; q->z = sn * w.z; }
static inline void* PlId(V4* q, V4* p) { Buf_20 pl; return Placement_GetIdentity(&pl, q, p); }
struct FT { char c[0x30];
    FT() { char* p = c; FailInit(p); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~FT() { PP(this, 0) = D_004DA950; cMessage_dtor(this, 0); }
    char* q() { return c; } } __attribute__((aligned(16)));
static inline void ESend(const FT& e, char* d, int f) { Event_Send((char*)&e, d, f); }
struct OSE { char c[0x40];
    OSE(char* a) { char* ep = c; Event_Construct(ep, D_00542B60); PP(ep, 0) = D_004DA930; PI(ep, 0x24) = 1; PB(ep, 0x28) = 0; PP(ep, 0x2C) = a; PB(ep, 0x30) = 0; PI(ep, 0x34) = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~OSE() { PP(this, 0) = D_004DA930; cMessage_dtor(this, 0); }
    void* p() { return this; } } __attribute__((aligned(16)));
static inline unsigned char ROS(char* s, Key30* k, int f, const OSE& e) { return Secondary_RequestOneShot(s, k, f, (void*)&e); }
struct FireT { char c[0x30]; FireT(char* p) { func_0016F7E0(this, p); PI(this, 4) = PI(p, 4); PB(this, 8) = PB(p, 8); Vec4_Assign(c + 0x10, p + 0x10); PF(this, 0x20) = PF(p, 0x20); } } __attribute__((aligned(16)));
static inline void HFire(char* a, const FireT& f) { Actor_HandleFire(a, (void*)&f); }
#undef KEYFILL
static inline void KF(Key30* k, const KT& kf) { if (!func_001AE190(k) || !func_001AE190((void*)&kf)) func_001AE170(k, (void*)&kf, 3); }
#define KEYFILL(k, s) KF(&(k), KT(s));


#define DirTail(a, m) { QCp(a + 0x30B0, m + 0x30); AF(0x30C0) = MF(0x50); QCpT(a + 0x30D0, V4T(-Math_Sin(AF(0x30C0)), Math_Cos(AF(0x30C0)), 0.0f, 0.0f)); }

static inline void DirTailP(char* a, char* m, V4* d, char* dp)
{
    float c;
    QCp(a + 0x30B0, m + 0x30);
    AF(0x30C0) = MF(0x50);
    c = Math_Cos(AF(0x30C0));
    d->x = -Math_Sin(AF(0x30C0));
    d->y = c;
    d->z = 0.0f;
    d->w = 0.0f;
    QCp(dp, d);
}

#define NETFP(bit, src) \
    { unsigned char* op = (unsigned char*)(src); if (D_005721C8) { unsigned char* np = (unsigned char*)AP(0x3584); if (np && AB(0x14)) { if (*op) np[0x50] |= (bit); else np[0x50] &= ~(bit); } } }
static inline void SetA0(char* w, unsigned char v) { w[0xA0] = v; }
static inline void LnkF(char* x, char* y) { char* xc = x; char* yc = y; ActorRelation_AddChild(xc + 0x100, yc + 0x100); }
static inline void QCp2(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%0)" : "=r"(q) : "0"(s) : "memory"); void* dd = d; __asm__ volatile("sq %0, 0x0(%1)" : : "r"(q), "r"(dd) : "memory"); }
static inline void LnkH(char* y, char* x) { char* xc; char* yc; yc = y; xc = x; ActorRelation_AddChild(xc + 0x100, yc + 0x100); }
static inline bool IsCls2(char* p) { int d = D_0049D010; int k = PI(p, 0x4C); return k == d; }
static inline bool NotB(unsigned char v) { return !v; }
static inline VC FlPos(char* a) { return *(const VC*)Root_GetWorldBasePlacement(Actor_GetFloorRoot2(a)); }
static inline unsigned char AtFlY(char* m, const VC& fl) { V4* mp; unsigned char e, e2; mp = (V4*)(m + 0x30); e = 0; e2 = 0; if (MF(0x30) == fl.x && mp->y == fl.y) e2 = 1; if (e2 && mp->z == fl.z) e = 1; return e; }
static inline unsigned char AtFlX(char* m, const V4& fl) { V4* mp; unsigned char e, e2; mp = (V4*)(m + 0x30); e = 0; e2 = 0; if (MF(0x30) == fl.x && mp->y == fl.y) e2 = 1; if (e2 && mp->z == fl.z) e = 1; return e; }
extern "C" unsigned char Actor_HandleActionMessage(char* a, char* m)
{
    unsigned char r = 1;
    switch (MI(0x24)) {
    case 0x0:
        switch (MB(0x28)) {
        case 12:
            if (MB(0x48) != 2) {
                { float y = MF(0x44); unsigned char b = MB(0x48) == 1; float x = MF(0x40); Actor_ApplyControlInput(a + 0x3030, m + 0x30, b, x, y); }
            } else {
                { char* v = m + 0x30; float y = MF(0x44); float x = MF(0x40); func_001AE3B0(a + 0x3030, v, x, y); }
            }
            AB(0x30AC) = 0;
            AB(0x30AD) = 0;
            break;
        case 13:
            if (D_005721C8) {
                if (!AB(0x14) && IsLoc(a)) {
                    if (MU(0xC) < AU(0x3594)) {
                        printf(D_0049E4A0, MU(0xC), AU(0x3594));
                    } else {
                        int t = Net_GetClock(0);
                        if (t - AI(0x3580) >= 150 && func_001A9210(a) && IsLoc(a)) {
                            if (!AtFlY(m, FlPos(a))) {
                                V4 p1, p2, f1, f2, d1, d2;
                                Buf_A0 h1, h2;
                                Ev60 ev1, ev2;
                                Ev70 ev3;
                                char* svc;
                                int v;
                                QCp(&p1, m + 0x30);
                                QCp(&p2, m + 0x30);
                                p1.z += 4.5f;
                                p2.z += 2.5f;
                                Vec4_Assign(&f1, Root_GetWorldBasePlacement(Actor_GetFloorRoot2(a)));
                                Vec4_Assign(&f2, Root_GetWorldBasePlacement(Actor_GetFloorRoot2(a)));
                                f1.z += 4.5f; f2.z += 2.5f; f1.w = 1.0f; f2.w = 1.0f;
                                SubTo(&d1, &p1, &f1);
                                SubTo(&d2, &p2, &f2);
                                d1.w = 0.0f;
                                d2.w = 0.0f;
                                { char* hp = h1.c; Ptr_Identity(hp + 0x10); func_0013AAE0(hp + 0x20); }
                                { char* hp = h2.c; Ptr_Identity(hp + 0x10); func_0013AAE0(hp + 0x20); }
                                {
                                char* ep = ev1.c;
                                Event_Construct(ep, D_005435A0);
                                PP(ep, 0) = D_004D9180;
                                PI(ep, 0x24) = 0;
                                PI(ep, 0x28) = 0;
                                PP(ep, 0x2C) = h1.c;
                                Vec4_Assign(ep + 0x30, &f1);
                                Vec4_Assign(ep + 0x40, &d1);
                                PP(ep, 0x50) = a;
                                PI(ep, 0x54) = 0;
                                PI(ep, 0x58) = 4;
                                PB(ep, 0x5C) = 0;
                                func_001AE370(ep);
                                }
                                {
                                char* ep = ev2.c;
                                Event_Construct(ep, D_005435A0);
                                PP(ep, 0) = D_004D9180;
                                PI(ep, 0x24) = 0;
                                PI(ep, 0x28) = 0;
                                PP(ep, 0x2C) = h2.c;
                                Vec4_Assign(ep + 0x30, &f2);
                                Vec4_Assign(ep + 0x40, &d2);
                                PP(ep, 0x50) = a;
                                PI(ep, 0x54) = 0;
                                PI(ep, 0x58) = 4;
                                PB(ep, 0x5C) = 0;
                                func_001AE370(ep);
                                }
                                svc = Service_Lookup(D_004FFB50, D_004EA0B0);
                                v = func_0014D410(func_0014D450(func_0014D460(a)));
                                if (v) LosProvider_SeedRegion(func_001AE360(svc), v);
                                VO_(svc)->f01(&ev1);
                                VO_(svc)->f01(&ev2);
                                if ((*(unsigned char*)h1.c || *(unsigned char*)h2.c) && IsLoc(a)) {
                                    char* ep; char* src; void* mx;
                                    ep = ev3.c; src = m + 0x30;
                                    Event_Construct(ep, D_0055D4E0);
                                    PP(ep, 0) = D_004D9360;
                                    PB(ep, 0x24) = 0;
                                    mx = Mtx_GetIdentity();
                                    SetPt(ep + 0x30, mx, src);
                                    PB(&ev3, 0x20) = 1;
                                    Event_Send(ep, a, 1);
                                    PP(&ev3, 0) = D_004D9360;
                                    cMessage_dtor(ep, 0);
                                }
                                AI(0x3580) = t;
                                PP(&ev2, 0) = D_004D9180;
                                cMessage_dtor(&ev2, 0);
                                PP(&ev1, 0) = D_004D9180;
                                cMessage_dtor(&ev1, 0);
                                func_00131B70(h2.c + 0x20, -1);
                                func_00131B70(h1.c + 0x20, -1);
                            }
                        }
                        {
                            char* dp;
                            { QCp(a + 0x30B0, m + 0x30); AF(0x30C0) = MF(0x50); QCpT(dp = a + 0x30D0, V4T(-Math_Sin(AF(0x30C0)), Math_Cos(AF(0x30C0)), 0.0f, 0.0f)); }
                            AF(0x30E0) = 1.0f;
                            Vec4_Copy(a + 0x3570, m + 0x40, dp);
                            if (!AB(0x14)) AB(0x30AC) = 1;
                        }
                    }
                } else {
                    char* p;
                    DirTail(a, m);
                    AF(0x30E0) = MF(0x54);
                    AB(0x30AC) = 1;
                    if (IsLoc(a)) { float f = MF(0x54); p = AP(0x3584); if (p) PF(p, 0x3C) = f; }
                    if (AB(0x14)) { float f = MF(0x50); p = AP(0x3584); if (p) PF(p, 0x40) = f; }
                }
            } else {
                DirTail(a, m);
                AF(0x30E0) = MF(0x54);
                AB(0x30AC) = 1;
            }
            break;
        }
        break;
    case 0x1:
    {
        char* p = AP(0x3310);
        unsigned char ok = 0;
        if (p && PB(p, 0xDD)) ok = 1;
        if (ok) {
            BitArray_Assign(a + 0x3248, 0, 1);
            NETFLAG(1, 1)
        }
        break;
    }
    case 0x2:
        BitArray_Assign(a + 0x3248, 0, 0);
        NETFLAG(1, 0)
        break;
    case 0x9:
        BitArray_Assign(a + 0x3248, 1, 1);
        break;
    case 0xA:
        BitArray_Assign(a + 0x3248, 1, 0);
        break;
    case 0x3:
        AB(0x31B3) = MB(0x2C);
        NETFP(4, m + 0x2C)
        break;
    case 0x4:
        AB(0x31B4) = MB(0x2C);
        NETFP(8, m + 0x2C)
        break;
    case 0x6:
        AB(0x3539) = 1;
        break;
    case 0x7:
    {
        int on = MI(0x2C);
        char* pr = a + 0x320C;
        if (!((AI(0x3210) >> 27) & 1) && !((AI(0x3210) >> 31) & 1)) {
            if (on) {
                unsigned char o = AnimPriority_Helper3(pr + 0xC, 0x1A);
                AnimPriority_Helper2(pr + 4, 0x1A, 1);
                AnimPriority_Helper1(pr);
                AnimPriority_Helper0(pr, 0x1A, o);
                if (!D_004EED58) {
                    NAME_COPY_N(D_004EED60, D_0049E080)
                    D_004EED58 = 1;
                }
                {
                    PNLT3(a, *(KT*)D_004EED60, RT(0.1f), XT(), 1);
                }
            } else if (AI(0x320C) == 0x1A) {
                unsigned char o = AnimPriority_Helper3(pr + 0xC, 0x1A);
                AnimPriority_Helper2(pr + 4, 0x1A, 0);
                AnimPriority_Helper1(pr);
                AnimPriority_Helper0(pr, 0x1A, o);
                PlaySlot(a, 0);
            }
        }
        break;
    }
    case 0x39:
        switch (MB(0x28)) {
        case 1:
            Actor_ChooseSecondaryMode(a, MB(0x2C));
            break;
        case 4:
        {
            char* q = m + 0x30;
            if (AP(0x3314)) {
                Actor_ChooseSecondaryMode(a, 1);
                SetLook(a, 0, q);
            }
            break;
        }
        case 11:
        {
            char* o = Object_LookupById(m + 0x30);
            if (o) {
                VR t = VO_(o)->f46(MI(0x34));
                if (AP(0x3314)) {
                    Actor_ChooseSecondaryMode(a, 1);
                    SetLook(a, 0, &t);
                }
            }
            break;
        }
        case 5:
        {
            char* o = Object_LookupById(m + 0x2C);
            if (o) {
                VR t = VO_(o)->f54();
                if (AP(0x3314)) {
                    Actor_ChooseSecondaryMode(a, 1);
                    SetLook(a, 0, &t);
                }
            }
            break;
        }
        }
        break;
    case 0x3A:
        Actor_ChooseSecondaryMode(a, 0);
        break;
    case 0x3B:
    {
        char* p = m + 0x30;
        HFire(a, FireT(p));
        break;
    }
    case 0x3C:
        if (AI(0x320C) != 0x14 && AI(0x320C) != 0x1B && AI(0x320C) != 0x1A && AI(0x320C) != 0x1F &&
            !((AI(0x3210) >> 4) & 1) && !((AI(0x3210) >> 5) & 1) && !((AI(0x3210) >> 8) & 1) &&
            !((AI(0x3210) >> 7) & 1) && !((AI(0x3210) >> 16) & 1) && WeaponInv_AllowsAction(AP(0x3524))) {
            Key30 k;
            unsigned char ok = 1;
            func_001AE280(&k, 3);
            if (Inventory_GetEquipMode(AP(0x3524)) == 1 || Inventory_GetEquipMode(AP(0x3524)) == 3) {
                KEYFILL(k, D_0049E4D0)
            } else if (Inventory_GetEquipMode(AP(0x3524)) == 2 || Inventory_GetEquipMode(AP(0x3524)) == 4) {
                KEYFILL(k, D_0049E4D0)
            } else if (Inventory_GetEquipMode(AP(0x3524)) == 5 || Inventory_GetEquipMode(AP(0x3524)) == 6) {
                KEYFILL(k, D_0049E4D0)
            } else {
                ok = 0;
            }
            if (AP(0x3314) && ok) {
                unsigned char s;
                s = ROS(AP(0x3314), &k, 1, OSE(a));
                if (s) {
                    SetA0(AP(0x3524), 1);
                    Weapon_StartReload(AP(0x3524));
                }
            }
        }
        break;
    case 0x3D:
        switch (MB(0x28)) {
        case 1:
            if (!MB(0x2C)) {
                char* l = AP(0x3314);
                if (l) LookCtl_ClearSlot(l, 1, 1);
            }
            break;
        case 4:
            if (AP(0x3314)) {
                SetLook(a, 1, m + 0x30);
            }
            break;
        case 11:
        {
            char* o = Object_LookupById(m + 0x30);
            VR t = VO_(o)->f46(MI(0x34));
            if (AP(0x3314)) {
                SetLook(a, 1, &t);
            }
            break;
        }
        case 5:
        {
            char* o = Object_LookupById(m + 0x2C);
            if (o) {
                VR t = VO_(o)->f54();
                if (AP(0x3314)) {
                    SetLook(a, 1, &t);
                }
            }
            break;
        }
        }
        break;
    case 0x3E:
        { char* o = Object_LookupById(m + 0x2C); Actor_SetLookTarget(func_001AE140(a), o); }
        break;
    case 0x3F:
        Actor_SetLookTarget(func_001AE140(a), 0);
        break;
    case 0x8:
        if (AI(0x320C) == 0) {
            unsigned char ok = 0;
            if (AI(0x3234) == 0 && AI(0x3220) == 0) ok = 1;
            if (ok) {
                unsigned char h = 0;
                unsigned char g = 0;
                if (func_001AE0D0(a, 4) && AP(0x3310)) g = 1;
                if (g && func_001AE0B0(AP(0x3310), 0)) h = 1;
                if (!h) {
                    float cur = ((CtlS*)(a + 0x2EC0))->Cur(0xF);
                    unsigned char f3 = 0;
                    unsigned char f2 = 0;
                    int kind;
                    unsigned char b3;
                    float f21, f20;
                    if (!(AF(0x309C) < 1.0f) && BTn(a + 0x3200, 3)) f2 = 1;
                    if (f2 && BTn(a + 0x3200, 4)) f3 = 1;
                    b3 = f3;
                    if (cur < 0.125f) {
                        if (b3) kind = 2; else kind = 6;
                    } else if (cur < 0.3f) {
                        kind = 4;
                    } else if (cur < 0.7f) {
                        kind = 1;
                    } else if (cur < 0.875f) {
                        kind = 5;
                    } else {
                        if (b3) kind = 3; else kind = 6;
                    }
                    switch ((unsigned char)kind) {
                    case 1: f21 = 0.325f; f20 = 0.55f; break;
                    case 2: f21 = 0.325f; f20 = 0.55f; break;
                    case 3: f21 = 0.325f; f20 = 0.55f; break;
                    case 4: f21 = 0.325f; f20 = 0.55f; break;
                    case 5: f21 = 0.325f; f20 = 0.55f; break;
                    case 6: f21 = 0.425f; f20 = 0.55f; break;
                    }
                    {
                        V4u b1, b2;
                        char* pv;
                        PlaySelT2R(a, func_00190F90(func_00190F90(func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 1, a), 1, 2, a), 3, 5, a), 5, 6, a), 6, 7, a), func_001AE020(&b1, 0, f21), 3, a), func_001AE020(&b2, 0, f20), 4, a), ((int*)(a + 0x326C))[(unsigned char)kind], 1, pv);
                    }
                    {
                        PlaySelT(a, XT(), AI(0x326C), 0);
                    }
                }
            }
        }
        break;
    case 0xB:
        if (AI(0x320C) == 0 && !((AI(0x3248) >> 30) & 1)) {
            BitArray_Assign(a + 0x3248, 0x1F, 0);
            BitArray_Assign(a + 0x3248, 0x1E, 1);
            if (D_005721C8) { char* np = AP(0x3584); if (np && AB(0x14)) np[0x51] = 0xB; }
        }
        break;
    case 0xC:
        if (AI(0x320C) == 0 && !((AI(0x3248) >> 31) & 1)) {
            BitArray_Assign(a + 0x3248, 0x1E, 0);
            BitArray_Assign(a + 0x3248, 0x1F, 1);
            if (D_005721C8) { char* np = AP(0x3584); if (np && AB(0x14)) np[0x51] = 0xC; }
        }
        break;
    case 0xD:
        BitArray_Assign(a + 0x3248, 0x1E, 0);
        BitArray_Assign(a + 0x3248, 0x1F, 0);
        if (D_005721C8) { char* np = AP(0x3584); if (np && AB(0x14)) np[0x51] = 0xD; }
        break;
    case 0xE:
        if (AI(0x320C) == 0) {
            Key30 k;
            float f21, f20;
            func_001AE280(&k, 3);
            if (BitSet_Test(a + 0x3200, 4)) {
                KEYFILL(k, D_0049E500)
                f21 = 0.2f;
                f20 = 0.2f;
            } else if (BitSet_Test(a + 0x3200, 3)) {
                KEYFILL(k, D_0049E500)
                f21 = 0.2f;
                f20 = 0.4f;
            } else {
                KEYFILL(k, D_0049E520)
                f21 = 0.2f;
                f20 = f21;
            }
            PlayMR(a, MRT(&k, RT(f21), RT(f20), OSE0(a)));
            APri(a, 3, 1);
        }
        break;
    case 0xF:
        if (AP(0x3310) && AI(0x320C) == 0) {
            if (!AB(0x14) || !IsLoc(a) || !PB(AP(0x3524), 0xA0)) {
                LATCH(2);
                LATCH(3);
                LATCH(8);
                if (AB(0x31B1)) LATCH(4);
            }
        }
        break;
    case 0x10:
        if (!((AI(0x3248) >> 4) & 1) && AP(0x3310) && AI(0x320C) == 0) {
            if (AB(0x14) || !IsLoc(a)) LATCH(1);
        }
        break;
    case 0x11:
        if (AP(0x3310) && !IsDown(a) &&
            (((AI(0x320C) == 7 || AI(0x320C) == 8) && Actor_HangSlotClimbable(AP(0x3310))) || (!AB(0x14) && IsLoc(a)))) {
            if (D_005721C8 && AB(0x14) && IsLoc(a)) FwdMsg(a, m, 0);
            {
                PNT(a, KT(D_0049E540), RT(D_0049D038), func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 0x2E, a), 1, 0x2F, a), 3, 0x30, a), 5, 0x31, a), 6, 0x32, a), 1);
            }
            PlaySlot(a, 0);
            APri(a, 1, 1);
            Physical_SetModeBit(AP(0x3310) + 0x18, 5);
            Physical_SetModeBit(AP(0x3310) + 0x18, 3);
        } else {
            Event_Send(FT().q(), AP(0x58), 1);
        }
        break;
    case 0x13:
        if (!IsDown(a)) {
            if (((AI(0x3210) >> 7) & 1) || ((AI(0x3210) >> 8) & 1) || (!AB(0x14) && IsLoc(a))) {
                if (D_005721C8 && AB(0x14) && IsLoc(a)) FwdMsg(a, m, 0);
                BitArray_Assign(a + 0x3248, 0xA, 0);
                BitArray_Assign(a + 0x3248, 0xB, 0);
                BitArray_Assign(a + 0x3248, 0xC, 0);
                BitArray_Assign(a + 0x3248, 0xD, 0);
                Actor_StartFall(a);
            }
        }
        break;
    case 0x14:
    case 0x15:
    case 0x16:
        Actor_JumpForGrab(a, m);
        break;
    case 0x17:
        Actor_RequestRunningJump(a, m);
        break;
    case 0x1A:
        if (!((AI(0x3210) >> 16) & 1) && AP(0x3310)) {
            if (AB(0x14) || !IsLoc(a)) {
                LATCH(7);
                LATCH(8);
            }
        }
        break;
    case 0x1B:
        if (!((AI(0x3210) >> 16) & 1) && AP(0x3310)) {
            if (AB(0x14) || !IsLoc(a)) LATCH(7);
        }
        break;
    case 0x1C:
    {
        char* p = AP(0x3310);
        if (p && PB(p, 0x9A5)) {
            AB(0x31B5) = 1;
            NETFLAG(0x20, 1)
        }
        break;
    }
    case 0x1D:
        AB(0x31B5) = 0;
        NETFLAG(0x20, 0)
        break;
    case 0x1E:
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
        Ladder_HandleExitAction(a, m);
        break;
    case 0x24:
        int* st = (int*)(a + 0x320C);
        if ((st[1] >> 16) & 1) {
            if (st[0] == 0x10) PlaySlot(a, 1);
            APri(a, 0xC, 0);
            APri(a, 0xD, 0);
            APri(a, 0xE, 0);
            APri(a, 0xF, 0);
            APri(a, 0x10, 0);
            if (AP(0x3310)) {
                Physical_ClearModeBit(AP(0x3310) + 0x18, 6);
                Physical_ClearModeBit(AP(0x3310) + 0x18, 7);
                Physical_ClearModeBit(AP(0x3310) + 0x18, 8);
                Physical_ClearModeBit(AP(0x3310) + 0x18, 9);
            }
        }
        break;


    case 0x2B:
        if (!IsDown(a) && !((AI(0x324C) >> 1) & 1) && (!AB(0x14) || AI(0x320C) == 0) &&
            !WeakRef_Get(a + 0x3478) && MB(0x28) == 5) {
            char* o;
            char* t;
            if ((t = Object_LookupById(m + 0x2C)) && IsCls2(t)) { o = t; if (!AB(0x14) || PI(o, 0x320C) == 0x1F) {
                V4 ax, pos, v, q;
                char* s3;
                char* pa;
                Actor_LinkBody(a + 0x3478, o);
                unsigned char g = 0;
                unsigned char h = 0;
                if (PB(o, 0x2D) && PB(o, 0x2C)) h = 1;
                if (h && NB2(o, 0x2E)) g = 1;
                if (!g) {
                    if (PB(o, 0x14)) VO_(o)->f21(1);
                    else VO_(o)->f06();
                }
                WeaponInv_HolsterCurrent(AP(0x3524));
                if (PP(o, 0x3464)) Backpack_Hide(PP(o, 0x3464));
                ax.x = 0.0f;
                ax.y = 0.0f;
                ax.z = 1.0f;
                ax.w = 0.0f;
                QCp2(&pos, Placement_GetPosition(Root_GetWorldPlacement(PP(o, 0x3290))));
                s3 = PP(o, 0x50);
                if (PB(s3, 0x50)) VO_(s3)->f20();
                { char* sub = s3 + 0x10; QCp(&v, sub + 0x20); }
                {
                    float ang = Yaw(DirOf(&v));
                    QAA(&q, AA(&ax, ang - 1.5707964f));
                }
                pa = AP(0x3294);
                RootAttachments_Attach(pa, PlId(&q, &pos));
                LnkH(o + 0x2EC0, a + 0x2EC0);
                AttachAll(a);
                {
                    Ev30 e;
                    char* ep = e.c;
                    EvInit(ep, 0x2E, 0);
                    PB(&e, 0x20) = 1;
                    Event_Send(ep, o, 1);
                    PP(&e, 0) = D_004E0840;
                    cMessage_dtor(ep, 0);
                }
                if (IsLoc(a) && AB(0x14)) {
                    Ev30 e;
                    char* ep = e.c;
                    cAIGOBJMsg_ctor(ep, D_004FF2B0, func_001AD8B0(AP(0x58)));
                    PP(ep, 0) = D_004DCC70;
                    PB(ep, 0x28) = 1;
                    PB(&e, 0x20) = 2;
                    Event_Send(ep, o, 0);
                    PP(&e, 0) = D_004DCC70;
                    cAIGOBJMsg_dtor(ep, 0);
                }
                {
                    V4u rr;
                    PNT(a, KT(D_0049E558), RT(D_0049D038), func_00190F90(func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 0x71, a), 1, 0x72, a), 3, 0x74, a), 5, 0x75, a), 6, 0x76, a), func_00192750(&rr, 0.12f, 0.12f, 0), 0x73, a), 1);
                }
                {
                    PNT(a, KT(D_0049E570), RT(D_0049D038), func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 0x77, a), 1, 0x78, a), 3, 0x79, a), 5, 0x7A, a), 6, 0x7B, a), 0);
                }
                if (D_005721C8 && AB(0x14)) {
                    Ev30 c;
                    char* ep = c.c;
                    cMessage_ctor3(ep, m);
                    PP(ep, 0) = D_004E01A0;
                    func_0016F7E0(ep + 0x2C, m + 0x2C);
                    PB(&c, 0x20) = 4;
                    PI(&c, 0x1C) = 0x40;
                    Event_Send(ep, a, 1);
                    PP(&c, 0) = D_004E01A0;
                    func_00140D40(ep, 0);
                }
            } }
        }
        break;
    case 0x2C:
    case 0x2D:
        if (!IsDown(a) && !((AI(0x324C) >> 4) & 1) && (!AB(0x14) || !((AI(0x324C) >> 2) & 1))) {
            if (AB(0x14)) {
                unsigned char dc = 0;
                char* p = AP(0x3310);
                if (p && PB(p, 0xDC)) dc = 1;
                if (dc) break;
            }
            {
                unsigned char done = 0;
                if ((!AB(0x14) || ((AI(0x324C) >> 3) & 1)) && WeakRef_Get(a + 0x3478) &&
                    (!AB(0x14) || ((PI(WeakRef_Get(a + 0x3478), 0x324C) >> 6) & 1))) {
                    Key30 k;
                    signed char ev;
                    if (PF(AP(0x3294), 0xD0) == 0.0f) {
                        void* w = Root_GetWorldPlacement(AP(0x3290));
                        char* r = AP(0x3294);
                        Root_SetWorldPlacement(r, w);
                        PI(r, 0x160) = 0;
                    }
                    AttachAll(a);
                    func_001AE280(&k, 3);
                    switch (MI(0x24)) {
                    case 0x2C:
                        ev = 0x2F;
                        KEYFILL(k, D_0049E590)
                        break;
                    case 0x2D:
                        ev = 0x30;
                        KEYFILL(k, D_0049E5B0)
                        break;
                    }
                    {
                        Ev30 e;
                        char* ep = e.c;
                    EvInit(ep, ev, 0);
                        PB(&e, 0x20) = 1;
                        Event_Send(ep, WeakRef_Get(a + 0x3478), 1);
                        PP(&e, 0) = D_004E0840;
                        cMessage_dtor(ep, 0);
                    }
                    {
                        PNT(a, *(KT*)&k, RT(D_0049D038), func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 0x7C, a), 1, 0x7D, a), 3, 0x7E, a), 5, 0x7F, a), 6, 0x80, a), 1);
                    }
                    PlaySlotB(a, 0);
                    done = 1;
                    if (D_005721C8 && AB(0x14)) FwdMsg(a, m, 1);
                }
                if (!done && WeakRef_Get(a + 0x3478)) {
                    PlaySelT(a, XT(), AI(0x326C), 1);
                    if (D_005721C8 && AB(0x14)) FwdMsg(a, m, 1);
                }
            }
        }
        break;
    case 0x2E:
        if (!((AI(0x324C) >> 5) & 1)) {
            {
                PNT(a, KT(D_0049E5C8), RT(D_0049D038), func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 0x81, a), 1, 0x82, a), 3, 0x83, a), 5, 0x84, a), 6, 0x85, a), 1);
            }
            {
                char* c;
                PNLTr(a, c, KT(D_0049E5E0), RT(D_0049D038), func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 0x86, a), 1, 0x87, a), 3, 0x89, a), 5, 0x88, a), 6, 0x8A, a), 0);
            }
        }
        break;
    case 0x2F:
    case 0x30:
        if (!((AI(0x324C) >> 7) & 1)) {
            Key30 k1, k2;
            func_001AE280(&k1, 3);
            func_001AE280(&k2, 3);
            switch (MI(0x24)) {
            case 0x2F:
                KEYFILL(k1, D_0049E600)
                KEYFILL(k2, D_0049E620)
                break;
            case 0x30:
                KEYFILL(k1, D_0049E640)
                KEYFILL(k2, D_0049DBC0)
                break;
            }
            {
                PNT(a, *(KT*)&k1, RT(D_0049D038), func_001AE050(func_001AE050(func_001AE050(func_001AE050(func_001AE050(XT().p(), 0, 0x8B, a), 1, 0x8C, a), 3, 0x8D, a), 5, 0x8E, a), 6, 0x8F, a), 1);
            }
            {
                PNLT4(a, *(KT*)&k2, RT2(D_0049D038), XT(), 0);
            }
        }
        break;
    case 0x28:
        { int t = AI(0x320C); if (t == 0x14 || t == 0x11 || t == 0x12 || t == 0x13)
        {
            unsigned char v = 1;
            if (MB(0x28) == 1) v = MB(0x2C);
            else if (MB(0x28) == 2) v = MI(0x2C) != 0;
            if (v || (AI(0x324C) & 1)) {
                Ev30 e;
                char* ep = e.c;
                    EvInit(ep, 0x29, 0);
                PB(&e, 0x20) = 5;
                PI(&e, 0x1C) = 0x40;
                Event_Send(ep, a, 0);
                PP(&e, 0) = D_004E0840;
                cMessage_dtor(ep, 0);
            }
        }
        }
        break;
    case 0x29:
        if (!IsDown(a)) {
            PlaySelT(a, XT(), AI(0x326C), 1);
        }
        break;
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x31:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x37:
    case 0x38:
        Actor_HandleObjectAction(a, m);
        break;
    case 0x32:
    case 0x36:
        if (!((AI(0x3210) >> 27) & 1) && !((AI(0x3210) >> 31) & 1)) PlaySlot(a, 1);
        break;
    case 0x2A:
        if (!IsDown(a) && PF(AP(0x3294), 0xD0) == 0.0f && MB(0x28) == 0xE) {
            if (D_005721C8 && AB(0x14) && IsLoc(a)) {
                struct { char c[0x60]; } __attribute__((aligned(16))) c;
                char* ep = c.c;
                cMessage_ctor3(ep, m);
                func_001AD710(ep + 0x30, m + 0x30);
                PP(ep, 0) = D_004E00E0;
                PB(&c, 0x20) = 4;
                PI(&c, 0x1C) = 0x40;
                Event_Send(ep, a, 0);
                PP(&c, 0) = D_004E00E0;
                func_00140D40(ep, 0);
            }
            Actor_HandleLedgeAction(a, m);
        }
        break;
    case 0x40:
        Actor_FlashbangHide(a, m);
        break;
    case 0x41:
        Actor_ReleaseSecondary(a, m);
        break;
    case 0x42:
        Actor_HandleDeathAction(a, m);
        break;
    case 0x43:
    {
        unsigned char v = MB(0x2C);
        if (AP(0x3310)) {
            PB(AP(0x3310), 0x12) = v;
            PB(AP(0x3310), 0x13) = v;
        }
        NETFLAG(0x40, NotB(v))
        break;
    }
    case 0x44:
        if (MU(0xC) > AU(0x3594)) { char* ip = m + 0x2C; int f = MI(0x30); Actor_Ignite(a, f != 0, Object_LookupById(ip), 0, 1, -1.0f); }
        break;
    case 0x45:
        Actor_ApplyBlind(a, 1, MF(0x2C));
        break;
    case 0x46:
        Actor_ApplyFlash(a, 1, MF(0x2C));
        break;

    default:
        r = 0;
        break;
    }
    return r;
}
