#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
#pragma inline_depth(8)
#pragma opt_propagation off

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
    V& operator=(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    V operator-(const V& o) const { V r; V* rp = &r; const V* tp = this; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "=f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));

struct M { V r[4]; };

static inline void Xform(V* v, const M* m)
{
    __asm__ volatile("lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory");
}

static inline const V& XformR(const V& v, const M& m) { V* p = (V*)&v; Xform(p, &m); return *p; }

static inline float FMax(float a, float b) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct Ctl {
    VPAD16(a) VPAD4(b) VPAD2(c)
    virtual void SetTarget(struct Obj* o, int held, int sub);
    char pad4[0x1C];
    float f20;
    float f24;
};

struct Inv {
    struct Slot { int a; int b; int id; int c; };
    char pad[0x84];
    unsigned char cur;
};

struct Obj {
    VPAD32(a) VPAD16(b) VPAD2(c)
    virtual int SubCount();
    VPAD4(d)
    virtual V GetPos();
    VPAD2(e) VPAD1(f)
    virtual M GetMtx();
    char pad4[8];
    int serial;
    int f10;
    char pad14[0x18];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x29];
    Ctl* ctl;
    char pad5C[0x3524 - 0x5C];
    char* inv;
};

struct H { Obj* p; union { float fs; int serial; }; };

struct Input {
    char pad0[0x38];
    int mode;
    int flags;
    int top;
    int bits[1];
    char pad48[0xA8 - 0x48];
    unsigned char prevR1;
    char padA9[0xBC - 0xA9];
    unsigned char latch;
    char padBD[3];
    H lock;
    H pick;
    char aim[0x14];
    int sub;
    float lockTimer;
    char recent[0x2D];
    unsigned char noTarget;
    char pad11A[2];
    float raise;
};

struct Msg30 { void* vt; char base[0x1C]; unsigned char b20; char p21[3]; int type; unsigned char kind; char p29[3]; int f2C; };
struct Msg40 { void* vt; char base[0x1C]; unsigned char b20; char p21[3]; int type; unsigned char kind; char p29[7]; V pt; };
struct Msg60 { void* vt; char base[0x1C]; unsigned char b20; char p21[3]; int type; unsigned char kind; char p29[7]; int id; int sub; unsigned char b38; char p39[7]; V v; float f50; char p54[0xC]; };

extern "C" {
extern char* g_Hud;
extern char g_Game[];
extern char g_TargetVisMgr[];
extern int D_0048AED0;
extern float D_0048AED8;
extern float D_0048AEE0;
extern unsigned char D_0048AEE8;
extern float D_004A7550;
extern float D_004A7558;
extern float D_004A7590;
extern unsigned char g_IsMultiplayer;
extern char g_CameraObject[];
extern Obj* D_004FFC10;
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern char D_004E01A0[];
extern char D_004E0200[];
extern char D_004E0140[];
extern char D_004D9320[];
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void Targeting_LockTimer(Input* s, float dt);
void Hud_SetLockMeter(char* hud, float f);
unsigned char WeaponInv_GetHeldClass(char* inv);
void Player_AimViewThrownPoint(void* aim, void* cam, Obj* actor);
Obj* PlayerInput_AimViewLock(Input* s, void* cam, Obj* actor);
void PlayerInput_AimViewPointAction(Input* s, void* cam, Obj* actor);
void PlayerInput_LookAtLockAction(Input* s, Obj* o, Obj* actor);
Obj* Targeting_LockPick(Obj* actor, Obj* cur, void* recent);
int TargetVis_Test(void* v, Obj* a, Obj* b, int delay, bool force);
char* Agent_GetSelected(void* list, int idx);
int AgentData_HasUnlock(char* agent, unsigned char bit);
Obj* Targeting_AutoPick(Obj* actor, Obj* prev);
void func_002494E0(Input* s, Obj* actor, int a2, int* a3, int t0);
void func_00249420(Input* s, Obj* actor, int* a2, char a3);
void func_00249490(Input* s, Obj* actor, V* v);
int Inventory_GetEquipMode(char* inv);
int Actor_IsFlashlightOn(Obj* actor);
int func_00159570(void* p);
Obj** List_Front(void* p);
void Hud_OnTargetChanged(char* hud);
void Hud_ShowTargetLock(char* hud, int* id, int sub);
void Hud_ClearTargetLock(char* hud);
void Hud_SetLockProgress(char* hud, float f);
}

extern "C" { extern signed char D_004E1D88; extern int D_004E1D90; extern int D_004E1D94; extern int D_004E1D98; extern int D_004E1D9C; }
struct MsgB {
    void* vt; char base[0x1C]; unsigned char b20; char p21[3]; int type; unsigned char kind; char p29[3];
    MsgB() {}
    MsgB(int t, unsigned char k) { MsgB* p = this; p->Init(t, k); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgB() { vt = D_004E0840; cMessage_dtor(this, 0); }
    void Send(Obj* to) { b20 = 1; Event_Send(this, to, 1); }
    void Init(int t, unsigned char k) { Event_Construct(this, g_ActorActionMsgClass); vt = D_004E0840; type = t; kind = k; }
};
struct MsgId : MsgB { int id; MsgId(const int& i) { MsgId* p = this; p->Init(0x3E, 5); p->vt = D_004E01A0; p->id = i; } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgId() {} };
struct MsgFlag : MsgB { unsigned char f; MsgFlag(const unsigned char& b) { MsgFlag* p = this; p->Init(0x39, 1); p->vt = D_004D9320; p->f = b; } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgFlag() {} };
struct MsgPt : MsgB { char p2C[4]; V pt; MsgPt(const V& v) { MsgPt* p = this; p->Init(0x39, 4); p->vt = D_004E0140; p->pt = v; } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgPt() {} };
struct MsgAim : MsgB {
    char p2C[4]; int id; int sub; unsigned char b38; char p39[7]; V v; float f50; char p54[0xC];
    MsgAim(const int& i, int s) { MsgAim* p = this; p->Init(0x39, 0xB); p->vt = D_004E0200; { if (D_004E1D88 == 0) { D_004E1D88 = 1; D_004E1D90 = 0; D_004E1D94 = 0; D_004E1D98 = 0; D_004E1D9C = 0; } const V* zp = (const V*)&D_004E1D90; p->id = i; p->sub = s; p->b38 = 0; p->v = *zp; p->f50 = 0.0f; } }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgAim() {}
};
static inline bool IEq(int a, int b) { return a == b; }
static inline bool INe(const int& a, const int& b) { return a != b; }
static inline bool HValid(H* h) { Obj* t = h->p; bool ok = true; if (((t != 0) ^ 1) == 0) if (IEq(t->serial, h->serial) == false) ok = false; return ok; }
static inline Obj* HGet(H* h) { return HValid(h) ? h->p : 0; }
static inline H* NullH(H* t);
static inline void HSet(H* h, Obj* o)
{
    int none;
    h->p = o;
    h->serial = *(o ? &o->serial : (none = -1, &none));
}

static inline int HeldId(char* inv)
{
    struct I2 { Inv::Slot s[6]; char p[0x24]; unsigned char cur; }* p = (I2*)inv;
    return p->cur != 6 ? p->s[p->cur].id : -1;
}

static inline int BitGet(Input* s, int i) { return (s->bits[i / 32] >> (i & 31)) & 1; }
static inline bool BitTest(Input* s, int i) { bool r = BitGet(s, i); return r; }
static inline void BitScan(Input* s)
{
    int i;
    for (i = 11; i >= 0 && !BitTest(s, i); i--) {}
    if (!BitTest(s, i)) s->top = -1;
    else s->top = i;
}

static inline bool IsAlive(Obj* o) { return o->b2D && o->b2C; }
static inline bool IsTargetable(Obj* o) { bool r = false; if (IsAlive(o) && ((o->b2E != 0) ^ 1)) r = true; return r; }
static inline bool CanSee(Obj* a, Obj* b, int delay) { return !TargetVis_Test(g_TargetVisMgr, a, b, delay, 0); }

static inline H* NullH(H* t) { t->p = 0; t->serial = -1; HSet(t, 0); return t; }

extern "C" void Player_RunTargeting(Input* self, void* cam, Obj* actor, bool r1, float dt, bool l1)
{
    int id;
    struct { int v; } none;
    bool autoLock = false;
    Obj* prev = HGet(&self->lock);
    char* hud = g_Hud;
    self->noTarget = 0;
    if (self->mode == 8) {
        Targeting_LockTimer(self, dt);
        if (HeldId(actor->inv) < 0) {
            HSet(&self->lock, 0);
            Hud_SetLockMeter(hud, 0.0f);
        } else {
            if (WeaponInv_GetHeldClass(actor->inv) == 1) {
                Player_AimViewThrownPoint(self->aim, cam, actor);
                HSet(&self->lock, 0);
            } else {
                HSet(&self->lock, PlayerInput_AimViewLock(self, cam, actor));
            }
            PlayerInput_AimViewPointAction(self, cam, actor);
        }
        PlayerInput_LookAtLockAction(self, HGet(&self->lock), actor);
        self->bits[0] &= ~0x20;
        BitScan(self);
        goto tail;
    }
    HGet(&self->pick);
    if (r1 && !self->latch) {
        if (!self->prevR1 || !HGet(&self->pick)) {
            HSet(&self->pick, Targeting_LockPick(actor, HGet(&self->pick), self->recent));
            self->sub = -1;
        } else if (HGet(&self->pick) && (!IsTargetable(HGet(&self->pick)) || !CanSee(actor, HGet(&self->pick), D_0048AED0))) {
            HSet(&self->pick, 0);
            self->latch = 1;
        } else if (HGet(&self->pick)) {
            V d = actor->GetPos() - HGet(&self->pick)->GetPos();
            float lim = D_0048AED8; float l2 = lim * lim;
            if (!(d.LenSq() <= l2) || !CanSee(actor, HGet(&self->pick), 0)) self->sub = -1;
        }
        self->lockTimer = D_004A7550;
    } else {
        if (!r1) self->latch = 0;
        Targeting_LockTimer(self, dt);
    }
    if (HGet(&self->pick) && l1 && AgentData_HasUnlock(Agent_GetSelected(g_Game, -1), 2) && CanSee(actor, HGet(&self->pick), 0)) {
        V d = actor->GetPos() - HGet(&self->pick)->GetPos();
        float lim = D_0048AED8; float l2 = lim * lim;
        if (d.LenSq() < l2) {
            if (++self->sub == HGet(&self->pick)->SubCount()) self->sub = -1;
        }
    }
    self->lock = self->pick;
    if (HGet(&self->pick) && self->lockTimer > D_004A7550 - D_004A7558) {
        self->bits[0] |= 0x20;
        BitScan(self);
    } else {
        self->bits[0] &= ~0x20;
        BitScan(self);
    }
    if (!HGet(&self->lock)) {
        HSet(&self->lock, Targeting_AutoPick(actor, prev));
        autoLock = HGet(&self->lock) != 0;
    }
    id = -1;
    if (autoLock || (HGet(&self->pick) && ((self->flags >> 5) & 1))) {
        id = HGet(&self->lock)->serial;
        MsgId(id).Send(actor);
        MsgAim(id, self->sub).Send(actor);
        if (g_IsMultiplayer) {
            func_002494E0(self, actor, HGet(&self->lock)->f10, &id, self->sub);
            func_00249420(self, actor, &id, 1);
        }
    } else {
        bool mode5;
        self->noTarget = 1;
        mode5 = (unsigned char)Inventory_GetEquipMode(actor->inv) == 5;
        if (mode5 || Actor_IsFlashlightOn(actor) || self->raise > 0.0f) {
            float z = (mode5 || self->raise > 0.0f) ? 0.0f : -D_0048AEE0;
            V pt;
            pt = XformR(V(0.0f, 5000.0f, z, 0.0f), actor->GetMtx());
            MsgB(0x3F, 0).Send(actor);
            MsgPt(pt).Send(actor);
            if (g_IsMultiplayer) func_00249490(self, actor, &pt);
        } else {
            MsgB(0x3F, 0).Send(actor);
            MsgFlag(D_0048AEE8).Send(actor);
            if (g_IsMultiplayer) func_00249420(self, actor, &id, 0);
        }
    }
    {
        Obj* cur = func_00159570(g_CameraObject) ? *List_Front(g_CameraObject) : 0;
        if (D_004FFC10 != cur) {
            Hud_OnTargetChanged(hud);
        } else {
            if (!autoLock && (none.v = -1, id != none.v)) Hud_ShowTargetLock(hud, &id, self->sub);
            else Hud_ClearTargetLock(hud);
        }
    }
tail:
    {
        Ctl* ctl;
        H tmp;
        self->prevR1 = r1;
        ctl = actor->ctl;
        {
            H* h = (autoLock || r1) ? &self->lock : NullH(&tmp);
            ctl->SetTarget(HGet(h), HeldId(actor->inv), self->sub);
        }
        if (!autoLock && HGet(&self->lock) && self->mode != 8) { float b = ctl->f24; float a = ctl->f20; Hud_SetLockProgress(hud, a * b); }
        if (self->noTarget) {
            if (self->mode == 5) self->raise = D_004A7590;
            else { self->raise -= dt; self->raise = FMax(0.0f, self->raise); }
        } else {
            self->raise = D_004A7590;
        }
    }
}



