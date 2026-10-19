#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
#pragma always_inline on
#pragma inline_depth(8)
#pragma opt_rebuildconditionals off
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    V r0, r1, r2, t;
    M() {}
    V* T() { return &t; }
};
static inline void VSub(V* o, V* a, V* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
}
static inline float AbsN(float x) { float r; asm { abs.s r, x } return r; }
static inline float AbsZ(float x) { float r = 0.0f; asm { abs.s r, x } return r; }

struct Obj;
struct Npc;
struct HObj { char pad[0xC]; int id; };
struct H { Obj* p; int serial; };
struct LNode { int unk0; LNode* next; H* h; };
struct RecR { int f0; int f4; int f8; char bC; };
struct WEnt { int a; int b; int c; int d; };
struct Wpn { WEnt e[8]; char p80[4]; unsigned char b84; };
struct Y { char pad[0x2C8]; float f2C8; };
struct X { char pad[0x310]; unsigned char b310; unsigned char b311; };
struct Tab { char pad[0x4C]; unsigned char b4C; char pad2[3]; };
struct G {
    VPAD16(a) VPAD4(b)
    virtual void V58();
    char pad4[0xC];
    M m;
    unsigned char b50;
    M* GetMtx() { if (b50) V58(); return &m; }
};
struct Obj {
    VPAD16(a) VPAD4(b) VPAD2(c)
    virtual void V60(int);
    VPAD32(d) VPAD4(e)
    virtual M VF4();
    VPAD4(f)
    virtual unsigned char GetMode();
    bool IsDead() { bool r; unsigned char m = GetMode(); r = true; if (m != 3 && m != 2) r = false; return r; }
    char pad4[8];
    int id;
    int f10;
    unsigned char b14;
    char pad15[0x17];
    bool b2C;
    bool b2D;
    bool b2E;
    char pad2F[0x15];
    int f44;
    char pad48[8];
    G* f50;
    char pad54[4];
    Npc* npc58;
    char pad5C[0x320C - 0x5C];
    int f320C;
    char p3210[0x3310 - 0x3210];
    Y* f3310;
    X* f3314;
    char p3318[0x33A5 - 0x3318];
    unsigned char b33A5;
    char p33A6[0x3524 - 0x33A6];
    Wpn* f3524;
    char p3528[0x3584 - 0x3528];
    RecR* f3584;
};
static inline bool U8(unsigned char v) { return v; }
struct PFlags { unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1; unsigned char rest : 4; };
struct Perc { char pad[0x20]; PFlags f20; char pad21[0x1F]; H h40; bool B2() { return U8(f20.b2); } };
struct Sensed { char pad[0x20]; unsigned char b20; char p21[3]; float f24; char p28[0x11]; unsigned char b39; };
struct Path { V v0; V v10; char pad20[0x30]; int f50; };
struct F1B4 {
    VPAD32(a) VPAD32(b) VPAD2(c)
    virtual int V110(V*);
    char pad4[0x8C];
    int f90;
};
struct Npc {
    VPAD8(a) VPAD4(b) VPAD2(c) VPAD1(d)
    virtual int V44();
    VPAD4(e) VPAD2(f)
    virtual void V60(Obj*, int, int);
    VPAD8(g) VPAD1(h)
    virtual unsigned char V88();
    VPAD8(i) VPAD2(j)
    virtual int VB4();
    VPAD32(k) VPAD8(l)
    virtual void V158();
    VPAD8(m) VPAD4(n) VPAD2(o) VPAD1(p)
    virtual void V198(float, int, int);
    char pad4[0x2C];
    Obj* actor;
    char pad34[0x2C];
    float f60;
    char pad64[0x18];
    float f7C;
    char pad80[0x24];
    int fA4;
    char padA8[0x40];
    int fE8;
    char padEC[0x30];
    int f11C;
    char pad120[4];
    int f124;
    float f128;
    char pad12C[4];
    int f130;
    char pad134[8];
    unsigned char b13C;
    char pad13D[4];
    PFlags f141;
    char pad142[0x12];
    float f154;
    unsigned char b158;
    char pad159[0x53];
    Perc* perc;
    Path* path;
    F1B4* f1B4;
    char pad1B8[4];
    float f1BC;
    float f1C0;
    float f1C4;
};
struct MBase { void* vtable; };
struct Msg : MBase { char pad[0x1C]; unsigned char kind; char pad2[3]; unsigned char b24; char pad3[0xB]; char data[0x40]; };
extern "C" {
extern char D_0055D4E0[], D_004D9360[], D_004EE550[], D_004D9340[], D_004EE698[], D_004D9940[];
void Event_Construct(void* m, void* type);
void cMessage_dtor(void* m, int flags);
}
struct MsgA : MBase {
    char pad[0x20]; unsigned char b24; char pad2[3]; int f28;
    MsgA(unsigned char m) { MsgA* p = this; Event_Construct(p, D_004EE550); p->vtable = D_004D9340; p->b24 = m; p->f28 = -1; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgA() { vtable = D_004D9340; cMessage_dtor(this, 0); }
};
struct MsgB : MBase {
    char pad[0x20]; int f24; int f28; int f2C; Obj* f30;
    MsgB(int a, int b, Obj* c) { MsgB* p = this; Event_Construct(p, D_004EE698); p->vtable = D_004D9940; p->f24 = a; p->f28 = b; p->f30 = c; p->f2C = 0; }
    MsgB(int a, F1B4* s, Obj* c);
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgB() { vtable = D_004D9940; cMessage_dtor(this, 0); }
};

extern "C" {
extern Tree D_004EA190;
extern int D_005383C8;
extern int D_004EA3A0;
extern Npc* D_004EA358;
extern unsigned char D_005721C8;
extern unsigned char D_005721D0;
extern Tab D_0049F790[];
void func_0014FC10(Iter* out, Tree* t);
Word* func_0014AB70(Word* dst, Word* src);
void func_0014AB80(Iter* out, Tree* t);
void cAI_v0E(Npc* self, float dt);
void NpcAi_RequestAction(Npc* self, unsigned char type, int prio, float f);
void NpcAi_RunLocomotion(Npc* self);
void NpcPerception_Think(Perc* p, float dt);
Sensed* NpcPerception_SensedRecord(Perc* p, Obj* o);
int NpcPerception_SightTest(Perc* p, Perc* q, int a, int b);
void* NpcPath_GetNode(int id);
void NpcPath_RelocateStuck(Path* p, int id);
V* Vec4_Set(V* v, float x, float y, float z, float w);
void Vec4_NormalizeXYZ_132060(V* out, V* v);
void Vec4_Cross(V* out, V* a, V* b);
int Vec4_IsZeroXYZ(V* v);
V* Vec4_NormalizeXYZInPlace(V* v);
V* Vec4_Assign(V* d, V* s);
void Mtx_FromRowsAndTranslation(M* m, V* a, V* b, V* c, V* t);
void Mtx_FrameFromAxis(M* m, V* a);
void Mtx_SetIdentity(M* m);
V Node_GetTranslation(void* node);
void Event_Construct(void* m, void* type);
int TeleportMsg_IsMode3(void* m);
V* func_00133EC0(M* m);
void func_0015A400(V* out, V* v);
void Vec4_CopyAsPoint(V* out, V* v);
void Mtx_SetRotationTranslation(void* data, M* obj, V* v);
void Event_Send(const MBase& m, void* target, int immediate);
void NpcAttack_SelectLookAt(Npc* self, float dt);
void NpcAttack_WeaponPosture(Npc* self);
void NpcAttack_FiringGate(Npc* self, float dt);
unsigned char NpcAi_DispatchMode(Npc* self, const MsgA& m);
int Npc_IsDeadRemovalAllowed(Npc* self);
void cNPC_v0E(Npc* self, float dt);
}

static inline void FCopy(float* d, float* s) { float* ss = s; float* dd = d; *dd = *ss; }

static inline bool Valid(H* h)
{
    Obj* t = h->p;
    int isNull = (t != 0) ^ 1;
    bool ok = true;
    if (!isNull)
        if ((t->id == h->serial) == false)
            ok = false;
    return ok != false;
}
static inline Obj* Get(H* h)
{
    Obj* r; if (Valid(h)) r = *(Obj* volatile*)&h->p; else r = 0; return r;
}
static inline bool ValidP(Perc* p)
{
    Obj* t = p->h40.p;
    int isNull = (t != 0) ^ 1;
    bool ok = true;
    if (!isNull)
        if ((t->id == p->h40.serial) == false)
            ok = false;
    return ok != false;
}
static inline Obj* GetP(Perc* p)
{
    Obj* r; if (ValidP(p)) r = *(Obj* volatile*)&p->h40.p; else r = 0; return r;
}
static inline int PathId(Npc* s) { return s->path->f50; }
static inline bool NotE(Obj* o) { return !(o->b2E != 0); }
static inline bool Active(Obj* o)
{
    bool b = 0;
    bool a = 0;
    if (o->b2D && o->b2C) a = 1;
    if (a && NotE(o)) b = 1;
    return b;
}
static inline bool Dead(Obj* o)
{
    unsigned char m = o->GetMode();
    return m == 3 || m == 2;
}
static inline bool TabOk(Tab* t) { return t->b4C; }
static inline bool PairOk(X* x)
{
    bool r = 0;
    if (TabOk(&D_0049F790[x->b310]) && TabOk(&D_0049F790[x->b311])) r = 1;
    return r;
}
static inline int SightSelf(Perc* p, int b) { Perc* q = p; return NpcPerception_SightTest(q, p, 1, b); }
static inline bool Ready(Y* y) { return y->f2C8 >= 0.5f; }
static inline void LookFrame(M* m, V* dir, const V& up)
{
    V c;
    Vec4_Cross(&c, dir, (V*)&up);
    if (!Vec4_IsZeroXYZ(&c)) {
        V f;
        V r;
        V u;
        V w;
        Vec4_NormalizeXYZ_132060(&f, dir);
        Vec4_Assign(&r, Vec4_NormalizeXYZInPlace(&c));
        Vec4_Cross(&u, &r, &f);
        Mtx_FromRowsAndTranslation(m, &r, &f, &u, Vec4_Set(&w, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!Vec4_IsZeroXYZ(dir)) {
        Mtx_FrameFromAxis(m, dir);
    } else {
        Mtx_SetIdentity(m);
    }
}
static inline void TeleInit(Msg* m, M* mtx)
{
    V a2;
    V b2;
    V* v;
    if (TeleportMsg_IsMode3(m)) {
        func_0015A400(&a2, func_00133EC0(mtx));
        v = &a2;
    } else {
        Vec4_CopyAsPoint(&b2, func_00133EC0(mtx));
        v = &b2;
    }
    Mtx_SetRotationTranslation(m->data, mtx, v);
}

inline MsgB::MsgB(int a, F1B4* s, Obj* c) { MsgB* p = this; int b = s->f90; Event_Construct(p, D_004EE698); p->vtable = D_004D9940; p->f24 = a; p->f28 = b; p->f30 = c; p->f2C = 0; }
extern "C" void cNPC_v0E(Npc* self, float dt)
{
    LNode* it;
    int tmp;
    Word w;
    int tmp2;
    Word w2;
    Iter b;
    Iter e;
    V d;
    M mtx;
    V fwd;
    Msg msg;
    bool leader = 0;
    Obj* actor = self->actor;
    int fr = D_005383C8;
    if (D_004EA3A0 == fr) {} else {
        float best = -1.0f;
        func_0014FC10(&b, &D_004EA190);
        func_0014AB70(&w, (Word*)&b);
        { int v = w.value; tmp = v; }
        FCopy((float*)&it, (float*)&tmp);
        while (func_0014AB80(&e, &D_004EA190), func_0014AB70(&w2, (Word*)&e), *(volatile int*)&tmp2 = w2.value, *(int*)&it != *(volatile int*)&tmp2) {
            Obj* o = Get(it->h);
            if (o && Active(o)) {
                Npc* n = o->npc58;
                if (n && n->V44() && n->V88() == 1) {
                    float f = n->f1BC;
                    if (!(f <= best)) {
                        D_004EA358 = n;
                        best = f;
                    }
                }
            }
            it = it->next;
        }
        D_004EA3A0 = D_005383C8;
    }
    if (D_004EA358 == self) leader = 1;
    if (!(self->f7C <= 0.0f)) {
        self->f7C -= dt;
        if (self->f7C <= 0.0f) self->V158();
    }
    cAI_v0E(self, dt);
    if (!(self->f128 <= 0.0f)) {
        self->f128 -= dt;
        if (self->f128 <= 0.0f && (self->f124 & 8)) NpcAi_RequestAction(self, 0xB, 0x64, 0.0f);
    }
    NpcAi_RunLocomotion(self);
    {
        Obj* tgt = GetP(self->perc);
        RecR* rec;
        Obj* a;
        if (D_005721C8 && (a = self->actor)) {
            rec = 0;
            if (D_005721D0) rec = a->f3584;
            if (rec) {
                if (tgt) {
                    rec->f8 = tgt->id;
                    rec->f4 = tgt->f10;
                    rec->bC = self->f11C;
                } else {
                    rec->f8 = -1;
                    rec->f4 = -1;
                    rec->bC = -1;
                }
            }
        }
        {
            bool c = 0;
            if (self->perc->f20.b0 && self->perc->B2()) c = 1;
            if (!c || (tgt && !Active(tgt)) || self->actor->IsDead()) tgt = 0;
        }
        {
            Wpn* wp = actor->f3524;
            unsigned char k = wp->b84;
            int arg;
            if (k != 6) arg = wp->e[k].c;
            else arg = -1;
            self->V60(tgt, arg, self->f11C);
        }
    }
    if (!self->actor->IsDead()) {
        if (leader) {
            NpcPerception_Think(self->perc, self->f1BC);
            if (GetP(self->perc) && !self->VB4() && !self->f130 && self->perc->f20.b3) {
                if (self->actor->f3314 ? PairOk(self->actor->f3314) : 0) {
                    Sensed* r = NpcPerception_SensedRecord(self->perc, GetP(self->perc));
                    if (r && r->b39 && r->f24 < 1.0f && (r->b20 == 3 || r->b20 == 4)) {
                        if (SightSelf(self->perc, GetP(self->perc)->f44 >> 1))
                            self->V198(0.0f, self->fA4, -1);
                    }
                }
            }
            if (!D_005721C8 || self->actor->b14) {
                Y* y;
                if ((!self->b158 || ((y = self->actor->f3310) ? Ready(y) : 0)) && self->b13C == 1 && !(self->f60 <= 0.0001f) && !self->actor->b33A5 && self->actor->f320C != 0x1A && self->actor->f320C != 0x10) {
                    V* dp = &d;
                    Path* p = self->path;
                    float ax = AbsN(p->v10.x);
                    float ay = AbsN(p->v10.y);
                    float az = AbsN(p->v10.z);
                    float c;
                    *dp = p->v0;
                    VSub(&d, &d, self->actor->VF4().T());
                    if (!(ax <= ay)) {
                        if (!(ax <= az)) c = AbsZ(d.x);
                        else c = AbsZ(d.z);
                    } else {
                        if (!(ay <= az)) c = AbsZ(d.y);
                        else c = AbsZ(d.z);
                    }
                    if (!(self->f1C0 <= c)) {
                        self->f1C0 = c;
                        self->f1C4 = 0.0f;
                    } else {
                        if (!(self->f1C4 <= 2.0f) && self->path->f50 >= 0) {
                            void* node = NpcPath_GetNode(PathId(self));
                            NpcPath_RelocateStuck(*(Path* volatile*)&self->path, PathId(self));
                            fwd = self->path->v10;
                            fwd.z = 0.0f;
                            LookFrame(&mtx, &fwd, V(0.0f, 0.0f, 1.0f, 0.0f));
                            mtx.t = Node_GetTranslation(node);
                            {
                                Msg* m = &msg;
                                Event_Construct(m, D_0055D4E0);
                                m->vtable = D_004D9360;
                                m->b24 = 2;
                                TeleInit(m, &mtx);
                                msg.kind = 1;
                                Event_Send(msg, self->actor, 1);
                                self->f1C4 = 0.0f;
                                self->f1C0 = 999999.0f;
                                msg.vtable = D_004D9360;
                                cMessage_dtor(&msg, 0);
                            }
                        }
                        self->f1C4 += self->f1BC;
                    }
                } else {
                    self->f1C4 = 0.0f;
                    self->f1C0 = 999999.0f;
                }
            }
        }
        NpcAttack_SelectLookAt(self, dt);
        NpcAttack_WeaponPosture(self);
        NpcAttack_FiringGate(self, dt);
        if (self->fE8 > 0) {
            self->fE8--;
            if (self->fE8 == 0) Event_Send(MsgA(3), self, 0);
        }
        NpcAi_DispatchMode(self, MsgA(2));
        if (leader && self->f1B4) {
            G* g = actor->f50;
            if (self->f1B4->V110(g->GetMtx()->T())) {
                if (!self->f141.b3) {
                    Event_Send(MsgB(0, self->f1B4->f90, actor), self->f1B4, 0);
                    self->f141.b3 = 1;
                }
            } else if (self->f141.b3) {
                Event_Send(MsgB(2, self->f1B4, actor), self->f1B4, 0);
                self->f141.b3 = 0;
            }
        }
    } else if (Npc_IsDeadRemovalAllowed(self)) {
        self->actor->V60(1);
    } else {
        NpcAttack_FiringGate(self, dt);
    }
    if (leader) self->f1BC = 0.0f;
    self->f1BC += dt;
    if (!(self->f154 <= 0.0f)) self->f154 -= dt;
}
