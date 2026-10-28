#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"
#include "vslot_pad.h"

static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(const V& o) { V* d = this; Q16(d, &o); } } __attribute__((aligned(16)));
struct M { V r[4]; } __attribute__((aligned(16)));

static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int DiffNV(int a, int b) { return a ^ b; }
static inline int SameNV(int a, int b) { return (unsigned)DiffNV(a, b) < 1; }

struct Sub58 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char Big(); };
struct Actor;
struct Hdl { Actor* obj; int serial;
    int IsValid();
    Actor* Get() { return IsValid() ? obj : 0; } };
struct Actor {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(c2) VPAD1(c3) virtual V GetPos(); VPAD2(d) VPAD1(d2) virtual M GetMtx(); VPAD2(e)
    virtual void Damage(Actor* src, int a, int kind, int b, int c, int d, float amt); VPAD1(f) virtual unsigned char Cls();
    char pad4[8];
    int serial;             /* 0x0C */
    char pad10[4];
    unsigned char b14;      /* 0x14 */
    char pad15[0x2F];
    int m44;                /* 0x44 */
    char pad48[4];
    int m4C;                /* 0x4C */
    char pad50[8];
    Sub58* s58;             /* 0x58 */
    char pad5C[0x320E];
    unsigned char b326A;    /* 0x326A */
    char pad326B[0x13A];
    unsigned char b33A5;    /* 0x33A5 */
    char pad33A6[0x12];
    unsigned char b33B8;    /* 0x33B8 */
    char pad33B9[0xB7];
    unsigned char b3470;    /* 0x3470 */
};
inline int Hdl::IsValid() { unsigned char ok = 1; if (!IsNullNV(obj) && !SameNV(obj->serial, serial)) ok = 0; return ok; }

struct WNode { WNode* prev; WNode* next; Hdl h; };
struct It { WNode* n; It() {} It(const It& o) : n(o.n) {} Hdl& operator*() { return n->h; } void Next() { n = n->next; } };
struct WList { WNode* prev; WNode* next;
    It begin() { It i; i.n = next; return i; }
    It end() { It i; i.n = (WNode*)this; return i; } };

struct Def { char pad[0xBC]; unsigned char kind; char padBD[0xB]; float radius; char padCC[4]; float life; };
struct Eff {
    char pad[0x60];
    float t;                /* 0x60 */
    char pad64[0xC];
    V pos;                  /* 0x70 */
    Def* def;               /* 0x80 */
    Hdl owner;              /* 0x84 */
    char pad8C[0x48];
    unsigned char doneD4;   /* 0xD4 */
    unsigned char bD5;      /* 0xD5 */
};

extern "C" {
struct WList;
WList* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(WList*);
extern float D_0048AFE8, D_0048AFE0, D_0048B000, D_0048B008, BlindDuration, BlindNVFactor;
extern struct G78DC { int a; WList list; WList* L() { return details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(&list); } } D_004F78DC;
extern int g_HumanActorClassKey[];
extern char g_ActorActionMsgClass[], D_004E0840[], g_Game[];
WList* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(WList*);
int cHuman_IsInvulnerable(Actor*);
void Actor_Ignite(Actor*, unsigned char, Actor*, unsigned char, int, float);
void cHuman_SetDeaf(Actor*, int, float);
void cHuman_SetBlinded(Actor*, int, float);
void cMatrix_InvertRot(M*);
int cMatrix_IsZeroTranslation(M*);
V* func_00133EC0(M*);
V* cVector_ctor_cVectorR(V*, const V*);
void cVector_NegateXYZ(V*);
void cVector_Rotate_cMatrixR(V*, M*);
void cMatrix_SetTranslation(M*, V*);
float Libc_Atanf(float);
bool cAreaEffect_GasCheck(Eff*, Actor*);
void* cGameSystem_GetAgentData(void*, int);
void cAgentData_AddScore(void*, int, int);
void cMessage_ctor_cMessageNameR(void*, void*);
void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
void cMessage_dtor(void*, int);
void nGobjManager_RemoveGOBJ(Eff*);
void cSystem_ActualScheduleDelete(Eff*, float);
extern "C" void cAreaEffect_NextFrame(Eff* self, float dt);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[7]; int id; unsigned char sub; char pad29[7];
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct Msg6 : MsgB {
    Msg6() : MsgB(g_ActorActionMsgClass) { vtable = D_004E0840; id = 6; sub = 0; }
    __declspec(weak) __declspec(MSG_DTOR) ~Msg6() { vtable = D_004E0840; }
};

static inline V Sub(const V& a0, const V& b0) {
    V r; V* p = &r; const V* a = &a0; const V* b = &b0;
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(p), "r"(a), "r"(b) : "memory");
    return r;
}
static inline void Xform(V* v, M* m) {
    V* d = v; M* mm = m; V* p = v;
    __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(d), "r"(mm), "r"(p) : "memory");
}
static inline void FixTrans(M* m) {
    if (!cMatrix_IsZeroTranslation(m)) {
        V t;
        cVector_ctor_cVectorR(&t, func_00133EC0(m));
        cVector_NegateXYZ(&t);
        cVector_Rotate_cMatrixR(&t, m);
        cMatrix_SetTranslation(m, &t);
    }
}
static inline void Xf0(V* v, M* m) { Xform(v, m); }
static inline void Dmg(Actor* a, Actor* o, int t, int k, float amt) { a->Damage(o, t, k, 0, 0, 0, amt); }
static inline float Fabs(float x) { float r = 0.0f; __asm__ volatile("abs.s %0, %1" : "+f"(r) : "f"(x)); return r; }
static inline unsigned char IsPlayer(Actor* a) { unsigned char r = 0; if (a->s58 && a->s58->Big()) r = 1; return r; }
static inline int Cur() { int* p = g_HumanActorClassKey; return *p; }
struct ActorI { VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(c2) VPAD1(c3) virtual V GetPos(); VPAD2(d) VPAD1(d2) virtual M GetMtx(); VPAD2(e)
    virtual void Damage(Actor* src, int a, int kind, int b, int c, int d, float amt); VPAD1(f) virtual int Cls(); };

static inline bool IsDown(unsigned char c) { return c == 3 || c == 2; }

extern "C" void cAreaEffect_NextFrame(Eff* self, float dt)
{
    float k = 1.0f;
    if (!self->bD5 && self->t < D_0048AFE8 && self->def->kind != 4)
        k = self->t / D_0048AFE8;
    float r = self->def->radius * k;
    float hz = D_0048AFE0 * (1.0f + k) / 2.0f;
    float r2 = r * r;
    G78DC* g = &D_004F78DC;
    It it = g->L()->begin();
    It e = g->L()->end();
    Actor* owner = self->owner.Get();
    for (; it.n != e.n; it.Next()) {
        Actor* a = (*it).Get();
        if (!a) continue;
        if (a->Cls() == 3 && self->def->kind != 4) continue;
        {
            unsigned char sel = 1;
            unsigned char pl = IsPlayer(a);
            if (!pl && !IsNullNV(owner)) sel = 0;
            if (!(sel ? a->b14 : owner->b14)) continue;
        }
        if (a->m4C != Cur()) continue;
        V p = a->GetPos();
        V dd(Sub(p, self->pos));
        float dy = dd.y; float y2 = dy * dy; float x2 = dd.x * dd.x; float dsq = x2 + y2;
        if (!(dsq < r2)) continue;
        if (!(Fabs(dd.z) < hz)) continue;
        switch (self->def->kind) {
        case 4:
            if (a->b33B8) break;
            if (cHuman_IsInvulnerable(a)) break;
            if (a->b326A) break;
            Actor_Ignite(a, 1, owner, 1, 0, -1.0f);
            break;
        case 3: {
            float f = (r2 - dsq) / r2;
            cHuman_SetDeaf(a, 0, D_0048B000 * f);
            M m = a->GetMtx();
            cMatrix_InvertRot(&m);
            FixTrans(&m);
            V lp(self->pos);
            Xf0(&lp, &m);
            if (lp.y <= 0.0f) break;
            float yaw = Libc_Atanf(lp.x / lp.y);
            float pitch = Libc_Atanf(lp.z / lp.y);
            if (Fabs(yaw) < D_0048B008 && Fabs(pitch) < D_0048B008) {
                float b = BlindDuration * f;
                if (a->b3470 == 1) b *= BlindNVFactor;
                { float q = b / 200.0f; int lv = 100 - a->m44; b -= q * lv; }
                cHuman_SetBlinded(a, 0, b);
            }
            break;
        }
        case 7:
            if (cHuman_IsInvulnerable(a)) break;
            if (a->b33A5) break;
            if (!cAreaEffect_GasCheck(self, a)) break;
            if (owner && IsPlayer(owner) && owner->b14 && !IsPlayer(a))
                cAgentData_AddScore(cGameSystem_GetAgentData(g_Game, -1), 6, 1);
            a->Damage(owner, 1, 7, 0, 0, 0, 0.0f);
            break;
        case 5:
            if (cHuman_IsInvulnerable(a)) break;
            if (IsDown(((ActorI*)a)->Cls())) break;
            if (!cAreaEffect_GasCheck(self, a)) break;
            if (owner && IsPlayer(owner) && owner->b14 && !IsPlayer(a))
                cAgentData_AddScore(cGameSystem_GetAgentData(g_Game, -1), 4, 1);
            { float one = 1.0f; Dmg(a, owner, 2, (signed char)self->def->kind, one); }
            break;
        case 6:
            if (cAreaEffect_GasCheck(self, a)) {
                Msg6 msg;
                QueueMessage_cMessageR_cSystemP_int(&msg, a, 0);
            }
            break;
        }
    }
    if (self->def->kind == 3) self->t = self->def->life;
    self->t += dt;
    if (!(self->t <= self->def->life) && !self->doneD4) {
        self->doneD4 = 1;
        nGobjManager_RemoveGOBJ(self);
        cSystem_ActualScheduleDelete(self, 0.1f);
    }
}


