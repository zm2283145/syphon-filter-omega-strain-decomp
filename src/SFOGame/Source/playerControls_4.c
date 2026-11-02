/*
 * SFOGame/Source/playerControls: 4 files, 002477B0-00247D50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002477B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */

#include "types.h"
#include "playerControls_types.h"

extern int std_vector_imp_cTargetZRotationStackSlot_insert(Pair8Vec* v, Pair8* pos, int n, Pair8* value);

int cHumanMotionParams_GetTargetZRotation_TopOfStackId(ControlsUnk5C* self) {
    return self->unk5C + -1;
}

/* push_back on a vector of 8-byte elements. */
int cArray_cTargetZRotationStackSlot_PushBackActual(Pair8Vec* v, Pair8* value) {
    return std_vector_imp_cTargetZRotationStackSlot_insert(v, v->data + v->count, 1, value);
}

OptFloat* cHumanMotionParams_cTargetZRotationStackSlot_ctor(OptFloat* self, float value) {
    self->set = 1;
    self->value = value;
    return self;
}
static inline void merge_flush_func_002477B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002477B0 */

/* merge_units: begin func_00247800 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Q7 { __int128 Q7; };
static inline void QM(void* d, const void* s) { __int128 t; asm { .set noat
 lq t, 0(s)
 sq t, 0(d) } }

struct Id_7800 { int v; };
struct Obj_7800 { char pad[0xC]; int id; };
static inline Id_7800* ObjId(Obj_7800* o) { return (Id_7800*)&o->id; }
static inline Id_7800* MakeId(Id_7800* t, int v) { t->v = v; return t; }
struct Handle_7800 {
    Obj_7800* obj;
    int id;
    Handle_7800(Obj_7800* o) : obj(o), id(-1) { Id_7800 t; id = (o ? ObjId(o) : MakeId(&t, -1))->v; }
};
struct Veh_7800 { char pad[0x3D2]; unsigned char b3D2; unsigned char b3D3; unsigned char b3D4; };
struct Player_7800 {
    char pad[0x3204];
    int f3204;
    char pad3208[8];
    int f3210;
    char pad3214[0x34];
    int f3248;
    char pad324C[0xC4];
    Veh_7800* veh;
    int f3314;
    char pad3318[0x20C];
    int f3524;
};
struct Cam_7800 {
    char pad0[8];
    Obj_7800* obj;
    char padC[4];
    float f10, f14, f18, f1C;
    char pad20[4];
    unsigned char b24;
    char pad25[0x13];
    int f38;
    int f3C;
    char pad40[0x10];
    int f50;
    char pad54[0x6C];
    Handle_7800 h;
    char padC8[0x1C];
    int fE4;
};
struct Flags_7800 { int w[1]; };
struct Out_7800 {
    char pad0[0xCF8];
    Flags_7800 flags;
    Obj_7800* obj;
    int id;
    Obj_7800* tgt;
    int tgtId;
    int fD0C;
    float fD10;
    float fD14, fD18, fD1C, fD20;
    char padD24[0xC];
    Q7 vD30;
    Q7 vD40;
    Q7 vD50;
    Q7 vD60;
    char padD70[0x20];
    Q7 vD90;
};
extern "C" {
extern float D_004A9330;
unsigned char cWeapon_GetEquipmentType(int);
Id_7800* cObjectId_ctor_uint(Id_7800*, int);
#if 0 /* merge_units */
Id_7800* cSystem_GetObjectID_void_2(Obj_7800*);
#endif /* merge_units */
void* cSystem_GetObjectID_void_2(char* self); /* merge_units */
#define cSystem_GetObjectID_void_2(a0) ((Id_7800 *)cSystem_GetObjectID_void_2((char *)(a0))) /* merge_units */

void cHumanIkRoutine_GetCurrentGunRecoilAnimation(Q7*, int);
void cPlayerControls_UpdateCamera(Cam_7800* cam, Out_7800* out, Player_7800* pl, Q7* a3, Q7* t0, Q7* t1, Q7* t2);
}
struct HS_7800 { Obj_7800* obj; int id; };
static inline void SetH(HS_7800* h, Obj_7800* o) { Id_7800 t; h->obj = o; h->id = (o ? cSystem_GetObjectID_void_2(o) : cObjectId_ctor_uint(&t, -1))->v; }
static inline void SetF(Out_7800* o, float a, float b, float c, float d) { o->fD14 = a; o->fD18 = b; o->fD1C = c; o->fD20 = d; }
static inline bool Eq(int a, int b) { return a == b; }
static inline bool HandleValid(Handle_7800* h) { return !h->obj || Eq(h->obj->id, h->id); }
static inline bool Bit(int v, int b) { return (v >> b) & 1; }
static inline bool CamBit8(Cam_7800* c) { return Bit(c->f3C, 8); }
static inline bool InVeh(Player_7800* p) { return Bit(p->f3204, 4) && p->veh; }
static inline bool VehB3D2(Player_7800* p) { bool r = false; if (InVeh(p) && p->veh->b3D2) r = true; return r; }
static inline bool VehB3D4(Player_7800* p) { return p->veh && p->veh->b3D4; }
void cPlayerControls_UpdateCamera(Cam_7800* cam, Out_7800* out, Player_7800* pl, Q7* a3, Q7* t0, Q7* t1, Q7* t2)
{
    Obj_7800* tgt;
    int tid;
    Q7 v;
    {
        Handle_7800* h;
        if (CamBit8(cam) != 0) {
            Handle_7800 n(0);
            h = &n;
        } else {
            h = &cam->h;
        }
        tgt = HandleValid(h) ? h->obj : 0;
    }
    tid = CamBit8(cam) ? -1 : cam->fE4;
    SetH((HS_7800*)&out->obj, cam->obj);
    if (tgt) {
        SetH((HS_7800*)&out->tgt, tgt);
        out->fD10 = D_004A9330;
    }
    out->fD0C = tid;
    SetF(out, cam->f14, cam->f10, cam->f18, cam->f1C);
    Q7* p0 = &out->vD30; Q7* p1 = &out->vD40; Q7* p2 = &out->vD50; Q7* p3 = &out->vD60;
    int i = 0;
    QM(p0, t2);
    QM(p1, a3);
    QM(p2, t0);
    QM(p3, t1);
    for (; i <= 0; i++)
        out->flags.w[i] = 0;
    if (cam->f50 == 1)
        out->flags.w[0] |= 1;
    if (cam->f38 == 4) {
        if (!VehB3D2(pl) && cam->b24)
            out->flags.w[0] |= 0x400;
    }
    if (cam->f38 == 4) {
        if (VehB3D2(pl))
            out->flags.w[0] |= 0x800;
    }
    if ((cam->f3C >> 8) & 1) {
        out->flags.w[0] |= 4;
        if (cWeapon_GetEquipmentType(pl->f3524) != 1)
            out->flags.w[0] |= 8;
    }
    if ((cam->f3C >> 5) & 1)
        out->flags.w[0] |= 2;
    if ((cam->f3C >> 7) & 1) {
        out->flags.w[0] |= 0x40;
        if ((pl->f3248 >> 8) & 1)
            out->flags.w[0] |= 0x80;
        if ((pl->f3248 >> 9) & 1)
            out->flags.w[0] |= 0x100;
    }
    if ((cam->f3C >> 6) & 1)
        out->flags.w[0] |= 0x200;
    if ((cam->f3C >> 10) & 1)
        out->flags.w[0] |= 0x10;
    if (((cam->f3C >> 10) & 1) || ((pl->f3248 >> 4) & 1)) {
        int f = pl->f3248;
        if (!((f >> 6) & 1) && !((f >> 7) & 1) && !((pl->f3210 >> 7) & 1)) {
            if (pl->veh)
                pl->veh->b3D3 = 1;
            if (VehB3D4(pl))
                out->flags.w[0] |= 0x20;
        }
    }
    if (pl->f3314) {
        cHumanIkRoutine_GetCurrentGunRecoilAnimation(&v, pl->f3314);
    } else {
        ((int*)&v)[0] = 0; ((int*)&v)[1] = 0; ((int*)&v)[2] = 0; ((int*)&v)[3] = 0;
    }
    {
        Q7* s = &v;
        Q7* d;
        __int128 x;
        __asm__ volatile("lq %0, 0x0(%1)" : "=r"(x) : "r"(s));
        d = &out->vD90;
        __asm__ volatile("sq %0, 0x0(%1)" : : "r"(x), "r"(d) : "memory");
    }
}
#undef cSystem_GetObjectID_void_2 /* merge_units */
static inline void merge_flush_func_00247800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00247800 */

/* merge_units: begin func_00247D50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cSystem_GetObjectID_void_2(char* self) {
    return self + 12;
}
static inline void merge_flush_func_00247D50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00247D50 */

/* merge_units: begin func_00247D60 */
#pragma push /* merge_units */
#pragma cplusplus on
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
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void cPlayerControls_DecrementTargetFrameTimer_AndClearStickyTargetedObjectIfNecessary(Input* s, float dt);
void cHud_SetAimCursorColor(char* hud, float f);
#if 0 /* merge_units */
unsigned char cWeapon_GetEquipmentType(char* inv);
#endif /* merge_units */
#define cWeapon_GetEquipmentType(a0) (cWeapon_GetEquipmentType((int)(a0))) /* merge_units */

void GetGrenadeManualAimTarget(void* aim, void* cam, Obj* actor);
Obj* cPlayerControls_GetManualAimTarget(Input* s, void* cam, Obj* actor);
void cPlayerControls_SetManualAimWeaponTargetInHuman(Input* s, void* cam, Obj* actor);
void cPlayerControls_SetManualAimEyesTargetInHuman(Input* s, Obj* o, Obj* actor);
Obj* ChooseTarget(Obj* actor, Obj* cur, void* recent);
int cTargetManager_IsLosBlocked(void* v, Obj* a, Obj* b, int delay, bool force);
char* cGameSystem_GetAgentData(void* list, int idx);
int cAgentData_HasSpecialBonus(char* agent, unsigned char bit);
Obj* ChooseAutoTarget(Obj* actor, Obj* prev);
void cPlayerControls_NetSetTarget(Input* s, Obj* actor, int a2, int* a3, int t0);
void cPlayerControls_NetAimWeapon(Input* s, Obj* actor, int* a2, char a3);
void cPlayerControls_NetSetManualTarget(Input* s, Obj* actor, V* v);
int cWeapon_GetPoseType(char* inv);
int cHuman_FlashlightIsOn(Obj* actor);
int func_00159570(void* p);
Obj** cLList_cCAMERA_GOBJPtr_Front(void* p);
void cHud_ClearTargetNow(char* hud);
void cHud_SetTarget(char* hud, int* id, int sub);
void cHud_ClearTarget(char* hud);
void cHud_SetToHit(char* hud, float f);
}

extern "C" { extern signed char D_004E1D88; extern int D_004E1D90; extern int D_004E1D94; extern int D_004E1D98; extern int D_004E1D9C; }
struct MsgB {
    void* vt; char base[0x1C]; unsigned char b20; char p21[3]; int type; unsigned char kind; char p29[3];
    MsgB() {}
    MsgB(int t, unsigned char k) { MsgB* p = this; p->Init(t, k); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgB() { vt = D_004E0840; cMessage_dtor(this, 0); }
    void Send(Obj* to) { b20 = 1; QueueMessage_cMessageR_cSystemP_int(this, to, 1); }
    void Init(int t, unsigned char k) { cMessage_ctor_cMessageNameR(this, g_ActorActionMsgClass); vt = D_004E0840; type = t; kind = k; }
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
static inline bool CanSee(Obj* a, Obj* b, int delay) { return !cTargetManager_IsLosBlocked(g_TargetVisMgr, a, b, delay, 0); }

static inline H* NullH(H* t) { t->p = 0; t->serial = -1; HSet(t, 0); return t; }

extern "C" void cPlayerControls_UpdateTarget(Input* self, void* cam, Obj* actor, bool r1, float dt, bool l1)
{
    int id;
    struct { int v; } none;
    bool autoLock = false;
    Obj* prev = HGet(&self->lock);
    char* hud = g_Hud;
    self->noTarget = 0;
    if (self->mode == 8) {
        cPlayerControls_DecrementTargetFrameTimer_AndClearStickyTargetedObjectIfNecessary(self, dt);
        if (HeldId(actor->inv) < 0) {
            HSet(&self->lock, 0);
            cHud_SetAimCursorColor(hud, 0.0f);
        } else {
            if (cWeapon_GetEquipmentType(actor->inv) == 1) {
                GetGrenadeManualAimTarget(self->aim, cam, actor);
                HSet(&self->lock, 0);
            } else {
                HSet(&self->lock, cPlayerControls_GetManualAimTarget(self, cam, actor));
            }
            cPlayerControls_SetManualAimWeaponTargetInHuman(self, cam, actor);
        }
        cPlayerControls_SetManualAimEyesTargetInHuman(self, HGet(&self->lock), actor);
        self->bits[0] &= ~0x20;
        BitScan(self);
        goto tail;
    }
    HGet(&self->pick);
    if (r1 && !self->latch) {
        if (!self->prevR1 || !HGet(&self->pick)) {
            HSet(&self->pick, ChooseTarget(actor, HGet(&self->pick), self->recent));
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
        cPlayerControls_DecrementTargetFrameTimer_AndClearStickyTargetedObjectIfNecessary(self, dt);
    }
    if (HGet(&self->pick) && l1 && cAgentData_HasSpecialBonus(cGameSystem_GetAgentData(g_Game, -1), 2) && CanSee(actor, HGet(&self->pick), 0)) {
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
        HSet(&self->lock, ChooseAutoTarget(actor, prev));
        autoLock = HGet(&self->lock) != 0;
    }
    id = -1;
    if (autoLock || (HGet(&self->pick) && ((self->flags >> 5) & 1))) {
        id = HGet(&self->lock)->serial;
        MsgId(id).Send(actor);
        MsgAim(id, self->sub).Send(actor);
        if (g_IsMultiplayer) {
            cPlayerControls_NetSetTarget(self, actor, HGet(&self->lock)->f10, &id, self->sub);
            cPlayerControls_NetAimWeapon(self, actor, &id, 1);
        }
    } else {
        bool mode5;
        self->noTarget = 1;
        mode5 = (unsigned char)cWeapon_GetPoseType(actor->inv) == 5;
        if (mode5 || cHuman_FlashlightIsOn(actor) || self->raise > 0.0f) {
            float z = (mode5 || self->raise > 0.0f) ? 0.0f : -D_0048AEE0;
            V pt;
            pt = XformR(V(0.0f, 5000.0f, z, 0.0f), actor->GetMtx());
            MsgB(0x3F, 0).Send(actor);
            MsgPt(pt).Send(actor);
            if (g_IsMultiplayer) cPlayerControls_NetSetManualTarget(self, actor, &pt);
        } else {
            MsgB(0x3F, 0).Send(actor);
            MsgFlag(D_0048AEE8).Send(actor);
            if (g_IsMultiplayer) cPlayerControls_NetAimWeapon(self, actor, &id, 0);
        }
    }
    {
        Obj* cur = func_00159570(g_CameraObject) ? *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject) : 0;
        if (D_004FFC10 != cur) {
            cHud_ClearTargetNow(hud);
        } else {
            if (!autoLock && (none.v = -1, id != none.v)) cHud_SetTarget(hud, &id, self->sub);
            else cHud_ClearTarget(hud);
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
        if (!autoLock && HGet(&self->lock) && self->mode != 8) { float b = ctl->f24; float a = ctl->f20; cHud_SetToHit(hud, a * b); }
        if (self->noTarget) {
            if (self->mode == 5) self->raise = D_004A7590;
            else { self->raise -= dt; self->raise = FMax(0.0f, self->raise); }
        } else {
            self->raise = D_004A7590;
        }
    }
}
#undef cWeapon_GetEquipmentType /* merge_units */
static inline void merge_flush_func_00247D60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00247D60 */
