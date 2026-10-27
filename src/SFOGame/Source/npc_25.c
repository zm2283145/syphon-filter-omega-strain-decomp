/*
 * SFOGame/Source/npc: 4 files, 0014DE90-0014E0C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0014DE90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x4A (no-op). */
void cNPC_RequestLookAt_cVector_float_int(void) {
}
static inline void merge_flush_func_0014DE90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014DE90 */

/* merge_units: begin func_0014DEA0 */
#pragma push /* merge_units */
#include "types.h"
#include "vslot_pad.h"

#pragma cplusplus on
#define AND &&
struct Act_DEA0 { char pad[0xC]; int serial; };
struct Mode_DEA0 { int prio; unsigned char active; char pad[0xF]; };
struct Npc_DEA0 { VPAD32(a) VPAD8(b) virtual int CanLeave(signed char mode); char pad4[0x160]; unsigned char mode; char pad165[0x13]; Mode_DEA0 modes[1]; char pad18c[0x8]; Act_DEA0* target; int targetSerial; float x19C; int prio; unsigned char x1A4; unsigned char x1A5; };
#pragma push



extern "C" void cNPC_RequestFacial(Npc_DEA0* self, Act_DEA0* a, int prio, float f)
{
    if (prio >= self->prio AND prio >= self->modes[self->mode].prio) {
        if (self->CanLeave(*(signed char*)&self->mode)) {
            { int off;
Mode_DEA0* m;
char* b; off = self->mode * 20; b = (char*)(off + (int)self); m = (Mode_DEA0*)(b + 0x178); if (prio >= *(int*)(b + 0x178)) { b[0x17C] = 0; m->prio = 0; } }
        }
        self->mode = 2;
        self->target = a;
        { int none; self->targetSerial = *(a ? &a->serial : (none = -1, &none)); }
        self->x1A4 = 1;
        self->x1A5 = 1;
        self->x19C = f;
        self->prio = prio;
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014DEA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014DEA0 */

/* merge_units: begin func_0014DFB0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Act_DFB0 { char pad[0xC]; int serial; };
struct Mode_DFB0 { int prio; unsigned char active; unsigned char b; char pad[0xE]; };
struct Npc_DFB0 { VPAD32(a) VPAD8(b) virtual int CanLeave(signed char mode); char pad4[0x7C]; int x80; char pad84[0xE0]; unsigned char mode; char pad165[7]; Act_DFB0* target; int serial; float f; Mode_DFB0 modes[1]; };
struct Rec_DFB0 { Act_DFB0* target; int serial; float f; int prio; unsigned char a; unsigned char b; };
#pragma push



#define R(s) ((Rec_DFB0*)((char*)(s) + 0x16C))
extern "C" void cNPC_RequestLookAt_cGOBJP_float_int(Npc_DFB0* self, Act_DFB0* a, int prio, float f)
{
    if (prio >= self->modes[0].prio) {
        if (prio >= self->modes[self->mode].prio) {
        if (self->CanLeave(*(signed char*)&self->mode)) {
            { int off;
Mode_DFB0* m;
char* b; off = self->mode * 20; b = (char*)(off + (int)self); m = (Mode_DFB0*)(b + 0x178); if (prio >= *(int*)(b + 0x178)) { b[0x17C] = 0; m->prio = 0; } }
        }
        self->mode = 0;
        self->target = a;
        { int none; self->serial = *(a ? &a->serial : (none = -1, &none)); }
        self->modes[0].active = 1;
        self->modes[0].b = 1;
        self->f = f;
        self->modes[0].prio = prio;
        }
        self->x80 = 0;
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014DFB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014DFB0 */

/* merge_units: begin func_0014E0C0 */
#pragma push /* merge_units */
/* cNPC_UpdateLookAt 0014E0C0 mw38 - matched by c150lg (slot-loop IsValid2 with SameNV2(Obj*,Hdl*) helper) */
#pragma cplusplus on

static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(const V& o) { V* d = this; Q16(d, &o); } V& operator=(const V& o) { Q16(this, &o); return *this; } } __attribute__((aligned(16)));

struct Obj { VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d) virtual V GetPos(int); char pad4[8]; int serial; char pad10[0x1C]; unsigned char f2C, f2D, f2E; char pad2F[0x1D]; int f4C; };
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int DiffNV(int a, int b) { return a ^ b; }
static inline int SameNV(int a, int b) { return (unsigned)(a ^ b) < 1; }
struct Hdl; static inline int IsNullNV2(struct Obj* p);
static inline int SameNV2(struct Obj* o, struct Hdl* h);
struct Hdl { Obj* obj; int serial;
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(obj) && !SameNV(obj->serial, serial)) ok = 0; return ok; }
    Obj* Get() { return IsValid() ? obj : 0; }
    int IsValid2() { unsigned char ok = 1; if (!IsNullNV(obj) && !SameNV2(obj, this)) ok = 0; return ok; }
    Obj* Get2() { return IsValid2() ? obj : 0; } };
static inline int IsNullNV2(Obj* p) { return (p != 0) ^ 1; }
static inline int SameNV2(Obj* o, Hdl* h) { return (unsigned)(o->serial ^ h->serial) < 1; }
struct Dat { Hdl h; float dist; int cnt; unsigned char used; };
struct LNode { LNode* prev; LNode* next; Dat d; };
struct It { bool operator!=(It o) { return p != o.p; } LNode* p; It() {} It(LNode* n) : p(n) {} It(const It& o) : p(o.p) {} It& operator=(const It& o) { p = o.p; return *this; } };

struct Gun { char pad[0x415]; unsigned char b415; };
struct Owner : Obj { char padO[0x3314 - 0x50]; Gun* gun; };
struct Slot { Hdl h; float t; int prio; unsigned char on; unsigned char f17D; char pad[2]; };
struct Npc {
    VPAD32(a) VPAD8(b) virtual int SlotBusy(int);
    VPAD32(d) VPAD8(e) VPAD2(f) VPAD1(g) virtual void Lost();
    char pad4[0x2C];
    Owner* owner;           /* 0x30 */
    char pad34[0x4C];
    float f80;              /* 0x80 */
    char pad84[0xD8];
    float timer;            /* 0x15C */
    int prio;               /* 0x160 */
    signed char cur;        /* 0x164 */
    unsigned char closest;  /* 0x165 */
    unsigned char active;   /* 0x166 */
    unsigned char found;    /* 0x167 */
    unsigned char f168;     /* 0x168 */
    char pad169[3];
    Slot slots[3];          /* 0x16C */
    unsigned char f1A8;     /* 0x1A8 */
    char pad1A9[3];
    void* ai;               /* 0x1AC */
    char pad1B0[8];
    char* list;             /* 0x1B8 */
};

extern "C" {
extern char g_ActorActionMsgClass[], D_004E0840[], D_004E0140[], D_004E01A0[], D_004D9320[];
extern unsigned char g_IsMultiplayer;
extern unsigned char D_00489DE0, D_00489DE8;
extern int g_HumanActorClassKey, D_004EA770;
LNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_3(void*);
LNode* std_list_deleter_cLookAtListItem_tail(void*);
void std_list_deleter_cLookAtListItem_generic_iterator_ctor_nodeP(It*, LNode*);
void std_list_deleter_cLookAtListItem_generic_iterator_ctor_nodebaseP(It*, LNode*);
int cAITarget_TestPointInViewCone(void*, V*, int, int);
void cMessage_ctor_cMessageNameR(void*, void*);
void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
void cMessage_dtor(void*, int);
void cNetNPCMsgs_SendMessage(void*, int, int, int, int, int, int);
void cNPC_UpdateLookAt(Npc* self, float dt);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX

struct MsgB {
    void* vtable; void* type; int pad8[7]; int id; unsigned char kind; char pad29[3];
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct Msg3D : MsgB {
    Msg3D(unsigned char k) : MsgB(g_ActorActionMsgClass) { vtable = D_004E0840; id = 0x3D; kind = k; }
    __declspec(weak) __declspec(MSG_DTOR) ~Msg3D() { vtable = D_004E0840; }
};
struct PosMsg : Msg3D {
    int pad2C; V pos;
    PosMsg(const V& p) : Msg3D(4) { vtable = D_004E0140; pos = p; }
    __declspec(weak) __declspec(MSG_DTOR) ~PosMsg() {}
} __attribute__((aligned(16)));
struct SerMsg : Msg3D {
    int serial;
    SerMsg(int* s) : Msg3D(5) { vtable = D_004E01A0; serial = *s; }
    __declspec(weak) __declspec(MSG_DTOR) ~SerMsg() {}
};
struct ByteMsg : Msg3D {
    unsigned char b;
    ByteMsg(const unsigned char& v) : Msg3D(1) { vtable = D_004D9320; b = v; }
    __declspec(weak) __declspec(MSG_DTOR) ~ByteMsg() {}
};

static inline void Send(const MsgB& m, Owner* o) { QueueMessage_cMessageR_cSystemP_int((void*)&m, o, 0); }
static inline void Sub(V* r, V* a, V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline unsigned char IsZero3(V* v) {
    int k, f; int r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline void Normalize(V* v, float* len) {
    int t;
    __asm__ volatile("lqc2 vf1, 0x0(%1); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; vdiv Q, vf0w, vf4x; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(%1); qmfc2.ni %0, vf4; sw %0, 0x0(%2)" : "=&r"(t) : "r"(v), "r"(len) : "memory");
}

static inline It First(char* l) { It t(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_3(l + 4)); return t; }
static inline It Begin0(LNode* n) { It t; std_list_deleter_cLookAtListItem_generic_iterator_ctor_nodeP(&t, n); return t; }
static inline It Begin(char* l) { It t; std_list_deleter_cLookAtListItem_generic_iterator_ctor_nodeP(&t, std_list_deleter_cLookAtListItem_tail(l)->next); return t; }
static inline It End(char* l) { It t; std_list_deleter_cLookAtListItem_generic_iterator_ctor_nodebaseP(&t, std_list_deleter_cLookAtListItem_tail(l)); return t; }
static inline void SubEq(V* a, const V& b) { Sub(a, a, (V*)&b); }
static inline int Sight(void* ai, const V& p) { return cAITarget_TestPointInViewCone(ai, (V*)&p, 1, 0); }
static inline Slot* CurSlot(Npc* self) { unsigned char i = self->cur; Slot* r = 0; if (self->slots[i].on) r = &self->slots[i]; return r; }
static inline void ClearSlot(Npc* self, unsigned char i, int prio) {
    if (prio >= self->slots[i].prio) { self->slots[i].on = 0; self->slots[i].prio = 0; }
}
static inline int SerOf(Obj* o) { int tmp; return *(o ? &o->serial : (tmp = -1, &tmp)); }
static inline int* SerP(Obj* o, int* t) { return o ? &o->serial : (*t = -1, t); }
static inline int SerOf2(Obj* o) { int tmp; return *SerP(o, &tmp); }
static inline void SetLook(Npc* self, Obj* o, float t, signed char idx, int prio) {
    if (prio >= self->slots[*(unsigned char*)&self->cur].prio) {

        if (self->SlotBusy(self->cur)) ClearSlot(self, (unsigned char)self->cur, prio);
        self->cur = idx;
        self->slots[(unsigned char)idx].h.obj = o;
        self->slots[(unsigned char)idx].h.serial = SerOf(o);
        self->slots[(unsigned char)idx].on = 1;
        self->slots[(unsigned char)idx].f17D = 1;
        self->slots[(unsigned char)idx].t = t;
        self->slots[(unsigned char)idx].prio = prio;
    }
}
static inline int Key0(void) { int* p = &g_HumanActorClassKey; return *p; }
static inline int Key1(void) { int* p = &D_004EA770; return *p; }
static inline int Ld(int* p) { return *p; }
static inline bool IsKey(Obj* o, int* k) { return o->f4C == *k; }
static inline bool IsKey2(Obj* o, int* k) { int v = *k; return o->f4C == v; }
static inline unsigned char Alive(Obj* o) {
    unsigned char r = 0;
    unsigned char a = 0;
    if (o->f2D && o->f2C) a = 1;
    if (a && ((o->f2E != 0) ^ 1)) r = 1;
    return r;
}

void cNPC_UpdateLookAt(Npc* self, float dt)
{
    int i;
    self->found = 0;
    if (self->active) {
        if ((self->timer -= dt) <= 0.0f || !CurSlot(self) || self->slots[(unsigned char)self->cur].prio < self->prio) {
            Dat* best = 0;
            float bestD = 1000000.0f;
            It x = First(self->list);
            It it; for (it = Begin(self->list); it != End(self->list); it.p = it.p->next) {
                Dat* d = &it.p->d;
                if (!d->used) {
                    float len;
                    len = 0.0f;
                    V a = self->owner->GetPos(-1);
                    SubEq(&a, d->h.Get()->GetPos(-1));
                    if (!IsZero3(&a)) Normalize(&a, &len);
                    if (len > 3.0f && a.z < 0.9f) {
                        if (!Sight(self->ai, d->h.Get()->GetPos(-1))) {
                            if (self->closest) {
                                if (len < bestD) { bestD = len; best = d; }
                                continue;
                            }
                            best = d;
                            break;
                        }
                    }
                    d->used = 1;
                    if (best) best->cnt++;
                }
            }
            if (best) {
                SetLook(self, best->h.Get(), best->dist, self->cur, self->prio);
                best->used = 1;
                self->timer = best->dist;
                self->found = 1;
            } else if (self->prio >= self->slots[*(unsigned char*)&self->cur].prio) {
                ClearSlot(self, (unsigned char)self->cur, self->prio);
                self->active = 0;
                self->prio = 0;
                if (self->f168) self->Lost();
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (self->slots[i].on) {
            if (self->slots[i].t > 0.0f && self->slots[i].h.Get2() &&
                (self->slots[i].h.Get2()->f4C != Key0() || Alive(self->slots[i].h.Get2())))
                self->slots[i].t -= dt;
            else
                ClearSlot(self, (unsigned char)i, self->slots[i].prio);
        }
    }
    if (self->slots[0].on && self->slots[0].h.Get()) {
        if (self->slots[0].f17D) {
            int* k = &D_004EA770; if (self->slots[0].h.Get()->f4C == Ld(k)) {
                V p = self->slots[0].h.Get()->GetPos(-1);
                p.z += 4.5f;
                Send(PosMsg(p), self->owner);
                if (g_IsMultiplayer) cNetNPCMsgs_SendMessage(self->owner, 0xE, 4, *(int*)&p.x, *(int*)&p.y, *(int*)&p.z, 0);
            } else {
                Send(SerMsg(&self->slots[0].h.Get()->serial), self->owner);
                if (g_IsMultiplayer) cNetNPCMsgs_SendMessage(self->owner, 0xE, 4, self->slots[0].h.Get()->serial, 0, 0, 0);
            }
            self->f1A8 = 1;
            self->slots[0].f17D = 0;
        }
    } else if (self->f1A8) {
        Send(ByteMsg(D_00489DE0), self->owner);
        if (g_IsMultiplayer) cNetNPCMsgs_SendMessage(self->owner, 0xE, 4, 0, 0, 0, 0);
        self->f1A8 = 0;
    } else {
        unsigned char g = 0;
        Gun* gun = self->owner->gun;
        if (gun && gun->b415) g = 1;
        if (g) Send(ByteMsg(D_00489DE8), self->owner);
    }
    self->f80 += dt;
}
static inline void merge_flush_func_0014E0C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014E0C0 */
