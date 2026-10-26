#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"

static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
  V(const V& o) { V* d = this; Q16(d, &o); } V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
struct M { V r[4]; V& T() { return r[3]; } V& R(int i) { return r[i]; } } __attribute__((aligned(16)));

struct Obj { VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d) virtual V Pos(int); VPAD8(e) VPAD1(f) virtual M Mtx(); VPAD2(g) virtual M Mtx2();
    char pad4[8]; int serial; char pad10[0x3C]; int cls; const int& Ser() { return serial; } };
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int DiffNV(int a, int b) { return a ^ b; }
static inline int SameNV(int a, int b) { return (unsigned)DiffNV(a, b) < 1; }
struct Hdl { Obj* obj; int serial;
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(obj) && !SameNV(obj->serial, serial)) ok = 0; return ok; }
    Obj* Get() { return IsValid() ? obj : 0; } };
struct Ai { V pos; char pad10[0x10]; unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1; unsigned char b4 : 1; char pad21[0x1F]; Obj* obj; int serial;
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(obj) && !SameNV(obj->serial, serial)) ok = 0; return ok; }
    Obj* Get() { return IsValid() ? obj : 0; } };
struct Inv { char pad[0x84]; unsigned char state; };
struct Owner {
    VPAD32(a) VPAD16(b) VPAD8(c) virtual M Mtx(); VPAD2(d) virtual M Mtx2();
    char pad4[0x3520];
    Inv* inv;               /* 0x3524 */
    char pad3528[0x5C];
    char* stats;            /* 0x3584 */
};
struct Npc {
    VPAD32(a) VPAD8(b) virtual int Busy(int); VPAD2(c) virtual unsigned char Stance();
    char pad4[0x2C];
    Owner* owner;           /* 0x30 */
    char pad34[0x44];
    float range;            /* 0x78 */
    char pad7C[0x98];
    int state;              /* 0x114 */
    char pad118[4];
    int team;               /* 0x11C */
    char pad120[0x10];
    int forced;             /* 0x130 */
    char pad134[8];
    unsigned char alert;    /* 0x13C */
    unsigned char mode;     /* 0x13D */
    char pad13E[0x42];
    Hdl h180;               /* 0x180 */
    char pad188[8];
    unsigned char hasH;     /* 0x190 */
    char pad191[0x1B];
    Ai* ai;                 /* 0x1AC */
};

struct SRec { char pad[0x24]; float dist; };

extern "C" {
extern float WorthShootingThreshold;
extern int g_HumanActorClassKey;
extern int D_004EA770;
extern char g_ActorActionMsgClass[], D_004E0840[], D_004E0140[], D_004E01A0[];
extern unsigned char g_IsMultiplayer;
SRec* NpcPerception_SensedRecord(Ai*, Obj*);
V* cMatrix_GetAxis(M*, int);
void Event_Construct(void*, void*);
void Event_Send(void*, void*, int);
void cMessage_dtor(void*, int);
unsigned char NpcAttack_WeaponPosture(Npc* self);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX

struct MsgB {
    void* vtable; void* type; int pad8[6]; unsigned char kind; char pad21[3];
    MsgB(void* t) { Event_Construct(this, t); }
    void Send(void* to, int f) { kind = 1; Event_Send(this, to, f); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct MsgI : MsgB {
    int id; unsigned char sub; char pad29[3];
    MsgI(int i, unsigned char s) : MsgB(g_ActorActionMsgClass) { vtable = D_004E0840; id = i; sub = s; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgI() { vtable = D_004E0840; }
};
struct MsgPos : MsgI {
    V pos;
    MsgPos(const V& p) : MsgI(0x39, 4) { vtable = D_004E0140; V* d = &pos; Q16(d, &p); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgPos() {}
} __attribute__((aligned(16)));
struct MsgSer : MsgI {
    int ser;
    MsgSer(const int& s) : MsgI(0x3E, 5) { vtable = D_004E01A0; ser = s; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgSer() {}
};

static inline int Ld(int* p) { return *p; }
static inline int Ld2(const int& p) { return p; }
static inline int Key0() { int* p = &g_HumanActorClassKey; return *p; }
static inline int Key1() { int* p = &D_004EA770; return *p; }
static inline float Range(Npc* self) {
    float r = self->range;
    if (r < 0.0f) r = WorthShootingThreshold;
    return r;
}
static inline unsigned char Engaged(Ai* ai) { unsigned char f = 0; if (ai->b0) { unsigned char b = ai->b2; if (b) f = 1; } return f; }
static inline Hdl* H180(Npc* self) { return self->hasH ? &self->h180 : 0; }
static inline void Sub(V* r, V* a, V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline void Add(V* r, V* a, V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline void Scale2(V* r, V* a, float k) { int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(r), "r"(a), "f"(k) : "memory"); }
static inline float Len(V* a) { float r = 0.0f; int t; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
static inline float Len2(const V& v) { float r = 0.0f; int t; const V* a = &v; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
static inline void AddTo(V& d, const V& b) { Add(&d, &d, (V*)&b); }
/* Diff's return copy uses its own 16-byte copy (this/&o operands directly) to get retail's register choice. */
struct VD : V { VD() {} VD(const VD& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); } } __attribute__((aligned(16)));
static inline VD Diff(const V& a, const V& b) { VD t; Sub(&t, (V*)&a, (V*)&b); return t; }
static inline V Scaled(const V& a, float k) { V t; Scale2(&t, (V*)&a, k); return t; }
static inline V Sum(const V& a, const V& b) { V t; Add(&t, (V*)&a, (V*)&b); return t; }

unsigned char NpcAttack_WeaponPosture(Npc* p)
{
    Obj* tgt;
    Npc* self = p;
    unsigned char ok = 1;
    unsigned char idle = 1;
    unsigned char aim = 1;
    Inv* inv = self->owner->inv;
    tgt = self->ai->Get();
    V pos;

    if (self->mode) {
        if (inv->state == 6 || (self->alert && (self->state == 4 || self->state == 11 || self->state == 3 || self->state == 9))) {
            ok = 0;
        } else if (self->forced > 0) {
            ok = 1;
        } else if (self->mode == 1) {
            if (!self->ai->b3 && !self->ai->b2) {
                ok = 0;
            } else {
                if (!Engaged(self->ai)) {
                    if (!self->ai->b3 || !self->ai->b1) {
                        if (!(Range(self) < 0.01f)) {
                            SRec* r = NpcPerception_SensedRecord(self->ai, tgt);
                            if (!r || !(r->dist < 5.0f)) ok = 0;
                        }
                    }
                }
            }
        }
        if (self->Busy(1)) {
            { Hdl* h = 0; if (self->hasH) h = &self->h180; pos = h->Get()->Pos(-1); }
            { int* k = &D_004EA770; Hdl* h = 0; if (self->hasH) h = &self->h180; if (h->Get()->cls == Ld(k)) pos.z += 4.5f; }
            MsgPos(pos).Send(self->owner, 0);
            MsgI(0x3F, 0).Send(self->owner, 0);
            idle = 0;
        } else if (ok) {
            idle = 0;
            if (tgt && Engaged(self->ai)) {
                MsgPos(tgt->Pos(self->team)).Send(self->owner, 0);
                MsgSer(tgt->Ser()).Send(self->owner, 0);
                aim = 0;
            } else if (self->ai->b4) {
                pos = self->ai->pos;
                if (!(Len2(Diff(pos, self->owner->Mtx().T())) <= 3.0f)) {
                    if (tgt) { int c = tgt->cls; if (c == Key0() || c == Key1()) pos.z += 4.5f; }
                } else {
                    AddTo(pos, Scaled(self->owner->Mtx2().R(1), 20.0f));
                }
                if (!idle) {
                    MsgPos(pos).Send(self->owner, 0);
                    MsgI(0x3F, 0).Send(self->owner, 0);
                }
            } else {
                pos = Sum(self->owner->Mtx2().T(), Scaled(*cMatrix_GetAxis(&self->owner->Mtx2(), 1), 20.0f));


                pos.z += 4.5f;
                MsgPos(pos).Send(self->owner, 0);
                MsgI(0x3F, 0).Send(self->owner, 0);
            }
        }
    }
    if (idle) {
        MsgI(0x3A, 0).Send(self->owner, 0);
        MsgI(0x3F, 0).Send(self->owner, 0);
    }
    if (g_IsMultiplayer) {
        unsigned char st = self->Stance();
        char* s = self->owner->stats;
        if (s) s += 0x1C;
        if (s) { s[5] = !idle; s[4] = st; }
        char* q = self->owner->stats;
        if (q) {
            q[0] = aim;
            *(float*)(q + 0x10) = pos.x;
            *(float*)(q + 0x14) = pos.y;
            *(float*)(q + 0x18) = pos.z;
        }
    }
    return ok;
}

