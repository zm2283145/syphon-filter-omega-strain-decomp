/*
 * main/Generator: range (7 files, 002204C0-002212D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"
#include "net_local_id.h"

/* merge_units: begin func_002204C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    void SubEq(const V& b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(this), "r"(&b) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    void AddEq(V b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(this), "r"(&b) : "memory"); }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
    void Normalize() { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory"); }
    float Dot(const V& b) const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&b) : "memory");
        return r;
    }
    V operator*(float s) const { V r; int t; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(&r), "r"(this), "f"(s) : "memory"); return r; }
} __attribute__((aligned(16)));
struct Mtx { V r0, r1, r2, t; const V& T() const { return t; } void SubT(V& d) const { d.SubEq(T()); } };
static inline const V& MTrans(const Mtx& m) { return m.t; }
struct Sub {
    VPAD16(a) VPAD4(b)
    virtual void Sync();
    char pad4[0xC];
    Mtx m;
    unsigned char f50;
};
static inline const V& SubPos(Sub* o) { if (o->f50) o->Sync(); return o->m.t; }
static inline const Mtx& SubMtx(Sub* o) { if (o->f50) o->Sync(); return o->m; }
struct Obj { char pad[0x50]; Sub* sub; };
struct Tgt {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) virtual void e0();
    virtual Mtx GetMtx();
    VPAD4(f)
    virtual unsigned char State();
    int pad4[2]; int id;
};
struct Hnd { Tgt* p; int id; };
struct LNode { LNode* prev; LNode* next; Hnd h; };
struct It { LNode* n; };
struct Gen { char pad[0x90]; int list90; char pad94[0xB8 - 0x94]; float radius; char padBC[0xD0 - 0xBC]; signed char busy; };
struct Svc { virtual void v0(); virtual void Send(void* m); };
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct HitSub { VP v[3]; char pad30[0x10]; unsigned char b40; char b41; unsigned char b42; char pad43[0x1D]; int f60; int f64; void Init() { HitSub* q = this; VP* i = q->v; VP* e = q->v + 3; do { i++; } while (i != e); q->b40 = 0; q->b42 = 0; q->f60 = 0; q->f64 = 0; } };
struct HitRes { unsigned char hit; char pad1[0x1F]; HitSub s; char pad88[0x10]; HitRes() { HitRes* p = this; p->s.Init(); } };
struct RayMsg { void* vt; char base[0x20]; int f24; int f28; HitRes* res; V start; V end; Obj* pl; Obj* cl; int f58; unsigned char b5C; };
struct Plr { char pad[0x30]; Obj* obj; };
extern "C" {
extern unsigned char D_005721C8;
extern Plr* D_004FFC0C;
extern char D_004FFC14[];
extern char D_004FFB50[];
extern char D_004EA0B0[];
extern char D_005435A0[];
extern char D_004D9180[];
LNode* func_0021E000(void* l);
LNode** func_0021DFE0(It* it, LNode* n);
LNode** func_0021DFF0(It* it, LNode* n);
void Node_GetTranslation(V* out, void* node);
Obj* PlayerSlots_Get(int i);
Obj** func_00159560(void* v);
float Math_Cos(float a);
Obj* Object_ClosestPlayerDistSq(void* node, int a);
Svc* Service_Lookup(void* a, void* b);
int Event_Construct(void* m, void* type);
int cMessage_dtor(void* m, int flags);
}
static inline bool IdEq(Tgt* p, Hnd* h) { return p->id == h->id; }
static inline Tgt* HGet(Hnd* h) {
    bool ok = !h->p || IdEq(h->p, h);
    return ok ? h->p : 0;
}
static inline void Begin(It* o, Gen* g) { It t; func_0021DFF0(&t, func_0021E000(&g->list90)->next); *o = t; }
static inline void End(It* o, Gen* g) { It t; func_0021DFE0(&t, func_0021E000(&g->list90)); *o = t; }
static inline void DoRay(Svc* svc, HitRes* res, const V& start, const V& end, Obj* pl, Obj* cl) {
    RayMsg msg;
    RayMsg* m = &msg;
    Event_Construct(m, D_005435A0);
    m->vt = D_004D9180;
    m->f24 = 0;
    m->f28 = 0;
    m->res = res;
    m->start = start;
    m->end = end;
    m->pl = pl;
    m->cl = cl;
    m->f58 = 0;
    m->b5C = 0;
    m->start.w = 1.0f;
    m->end.w = 0.0f;
    svc->Send(&msg);
    msg.vt = D_004D9180;
    cMessage_dtor(m, 0);
}
extern "C" int Generator_SpawnTest(Gen* self, void* node)
{
    int r = self->busy;
    if (!(unsigned char)r) {
        It it;
        It b;
        It e;
        bool found = false;
        Begin(&b, self);
        for (it = b; End(&e, self), it.n != e.n; it.n = it.n->next) {
            Tgt* t = HGet(&it.n->h);
            if (t->State() != 3) {
                V d;
                Node_GetTranslation(&d, node);
                t->GetMtx().SubT(d);
                if (d.LenSq() < 9.0f) found = true;
            }
        }
        if (found) goto done;
        r = 1;
        if (D_005721C8) {
            for (int i = 0; i < 4; i++) {
                Obj* p = PlayerSlots_Get(i);
                if (p) {
                    V d;
                    Node_GetTranslation(&d, node);
                    d.SubEq(SubPos(p->sub));
                    if (d.LenSq() < self->radius) {
                        r = 0;
                        break;
                    }
                }
            }
        } else {
            Obj* p = D_004FFC0C->obj;
            V d;
            Node_GetTranslation(&d, node);
            d.SubEq(SubPos(p->sub));
            if (d.LenSq() < self->radius) r = 0;
        }
        if ((unsigned char)r == 1) {
            float ang = 0.87266463f;
            V d;
            Node_GetTranslation(&d, node);
            d.SubEq(SubPos((*func_00159560(D_004FFC14))->sub));
            d.z = 0.0f;
            d.Normalize();
            V f = SubMtx((*func_00159560(D_004FFC14))->sub).r1;
            f.z = 0.0f;
            float dot = f.Dot(d);
            if (dot + (1.0f - Math_Cos(ang)) < 1.0f) {
                r = 1;
            } else {
                Obj* pl = D_004FFC0C->obj;
                Obj* cl = 0;
                if (D_005721C8) cl = Object_ClosestPlayerDistSq(node, 0);
                Svc* svc = Service_Lookup(D_004FFB50, D_004EA0B0);
                V end;
                V start;
                Node_GetTranslation(&start, node);
                start.z += 6.0f;
                end = SubPos((*func_00159560(D_004FFC14))->sub);
                end.AddEq(SubMtx((*func_00159560(D_004FFC14))->sub).r1 * 1.5f);
                end.SubEq(start);
                HitRes res;
                DoRay(svc, &res, start, end, pl, cl);
                r = res.hit ? 1 : 0;
            }
        }
    }
done:
    if ((unsigned char)r == 1) self->busy = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002204C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002204C0 */

/* merge_units: begin func_00220BB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#define V5(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4();
struct Tgt_00220BB0 {
    V5(a) V5(b) V5(c) V5(d) virtual void e0(); virtual void e1();
    virtual void Deactivate(int);
    int pad4[2]; int id;
};
struct Hnd_00220BB0 { Tgt_00220BB0* p; int id; };
struct LNode_00220BB0 { LNode_00220BB0* prev; LNode_00220BB0* next; Hnd_00220BB0 h; };
struct Gen_00220BB0;
struct Ev {
    char* vt; char p4[0x1C]; signed char f20; char p21[3]; Tgt_00220BB0* f24;
};
extern "C" {
#if 0 /* merge_units */
LNode_00220BB0* func_0021E000(void* l);
#endif /* merge_units */
#define func_0021E000(a0) ((LNode_00220BB0 *)func_0021E000((a0))) /* merge_units */

#if 0 /* merge_units */
LNode_00220BB0** func_0021DFE0(LNode_00220BB0** it, LNode_00220BB0* n);
#endif /* merge_units */
#define func_0021DFE0(a0, a1) ((LNode_00220BB0 * *)func_0021DFE0((It *)(a0), (LNode *)(a1))) /* merge_units */

#if 0 /* merge_units */
LNode_00220BB0** func_0021DFF0(LNode_00220BB0** it, LNode_00220BB0* n);
#endif /* merge_units */
#define func_0021DFF0(a0, a1) ((LNode_00220BB0 * *)func_0021DFF0((It *)(a0), (LNode *)(a1))) /* merge_units */

#if 0 /* merge_units */
int Event_Construct(void*, char*);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((a0), (void *)(a1))) /* merge_units */

int Event_Send(void*, void*, int);
#if 0 /* merge_units */
int cMessage_dtor(void*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((a0), (a1))) /* merge_units */

void Object_Deactivate(Gen_00220BB0*, int);
extern char D_004A4A88[];
extern char D_004DB620[];
extern char D_004DB660[];
}
struct Gen_00220BB0 {
    char pad[0x90]; int list90;
};
static inline Tgt_00220BB0* HGet_00220BB0(Hnd_00220BB0* h) {
    unsigned char valid = 1;
    Tgt_00220BB0* p = h->p;
    int n = (p != 0) ^ 1;
    if (!n && p->id != h->id)
        valid = 0;
    return valid ? p : 0;
}
extern "C" void Generator_DeactivateSpawned(Gen_00220BB0* self)
{
    Tgt_00220BB0* t;
    LNode_00220BB0* it;
    LNode_00220BB0* end;
    LNode_00220BB0* n;
    func_0021DFF0(&it, func_0021E000(&self->list90)->next);
    for (n = it; func_0021DFE0(&end, func_0021E000(&self->list90)), n != end; n = n->next) {
        Hnd_00220BB0* h = &n->h;
        t = HGet_00220BB0(h);
        t->Deactivate(1);
        Ev ev;
        Event_Construct(&ev, D_004A4A88);
        ev.f24 = t;
        ev.vt = D_004DB620;
        ev.f20 = 2;
        Event_Send(&ev, self, 0);
        ev.vt = D_004DB660;
        cMessage_dtor(&ev, 0);
    }
    Object_Deactivate(self, 1);
}
#undef func_0021E000 /* merge_units */
#undef func_0021DFE0 /* merge_units */
#undef func_0021DFF0 /* merge_units */
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00220BB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00220BB0 */

/* merge_units: begin func_00220D00 */
#pragma push /* merge_units */
typedef struct cGen00220D00 {
    char pad0[0xC];
    char f0C[0x20];
    char b2C;
    char pad2D[0xCC - 0x2D];
    unsigned int mask;
} cGen00220D00;
extern void func_0043B190(void* msg);
extern void func_0043A030(void* msg, void* target);
void cGenerator_v09(cGen00220D00* self, int bit)
{
    if (bit >= 0)
        self->mask &= ~(1 << bit);
    else
        self->mask = 0;
    if (self->mask == 0) {
        int msg[1];
        self->b2C = 0;
        func_0043B190(msg);
        func_0043A030(msg, self->f0C);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00220D00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00220D00 */

/* merge_units: begin func_00220D70 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad04[0x18]; int size; signed char kind; char pad21[3]; int target; } Msg_220D70;
typedef struct { char pad[0xC]; char sub[4]; int id; char pad14[0x18]; unsigned char state; char pad2d[0xCC - 0x2D]; int mask; } G_220D70;
#if 0 /* merge_units */
int Event_Construct(Msg_220D70* msg, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int cMessage_dtor(Msg_220D70* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

extern char g_cDisableMsgClass[];
extern char D_004E0860[];
void func_003FF650(Msg_220D70* msg, int id, int x);
#if 0 /* merge_units */
void func_0043B190(void* t);
#endif /* merge_units */
#define func_0043B190(a0) (func_0043B190((a0))) /* merge_units */

#if 0 /* merge_units */
void func_0043A030(void* t, void* p);
#endif /* merge_units */
#define func_0043A030(a0, a1) (func_0043A030((a0), (a1))) /* merge_units */

void cGenerator_v18(G_220D70* g, int bit)
{
    if (D_005721C8) {
        int t[1];
        Msg_220D70 msg;
        if (bit >= 0)
            g->mask &= ~(1 << bit);
        if (g->mask == 0) {
            func_0043B190(t);
            func_0043A030(t, g->sub);
            g->state = 0;
        }
        Event_Construct(&msg, g_cDisableMsgClass);
        msg.target = bit;
        msg.vtable = D_004E0860;
        msg.size = 0x40;
        msg.kind = 4;
        func_003FF650(&msg, g->id, -1);
        msg.vtable = D_004E0860;
        cMessage_dtor(&msg, 0);
    } else {
        g->state = 0;
    }
}
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef func_0043B190 /* merge_units */
#undef func_0043A030 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00220D70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00220D70 */

/* merge_units: begin func_00220E60 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {}
typedef struct { char pad[0xC]; char key[0x20]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x9D]; unsigned int maskCC; } Gen_12D0;
extern "C" {
void func_003CE810(void);
#if 0 /* merge_units */
void func_0043B190(void* ctx);
#endif /* merge_units */
#define func_0043B190(a0) (func_0043B190((a0))) /* merge_units */

int func_0043AB20(void* ctx, void* key);
void func_00439D00(void* ctx, void* key, int id);
void func_0043A420(void* ctx, void* key);
}
extern "C" void cGenerator_v08(Gen_12D0* g, int who)
{
    char ctx[4];
    g->b2C = 1;
    int ok = g->b2D != 0;
    ok = ok ? g->b2C != 0 : ok;
    ok = ok ? (g->b2E != 0) ^ 1 : ok;
    if (ok) {
        func_0043B190(ctx);
        if (who == NetLocalId() && g->maskCC == 0) {
            void* key = g->key;
            func_00439D00(ctx, key, NetLocalId());
        }
        func_0043A420(ctx, g->key);
    }
    if (who >= 0) g->maskCC |= 1 << who; else g->maskCC = 0xFF;
}
#undef func_0043B190 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00220E60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00220E60 */

/* merge_units: begin func_00220FD0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {}
typedef struct { char pad[0xC]; unsigned int h; } Own_0FD0;
typedef struct { char pad[0xC]; char key[4]; int id10; char pad14[0x18]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x9D]; unsigned int maskCC; } Gen_0FD0;
typedef struct { char* vt; char pad[0x18]; int f1C; signed char f20; char pad21[3]; int f24; } Msg_0FD0;
extern "C" {
extern char D_004E0880[];
extern char g_cEnableMsgClass[];
#if 0 /* merge_units */
void func_0043B190(void* ctx);
#endif /* merge_units */
#define func_0043B190(a0) (func_0043B190((a0))) /* merge_units */

#if 0 /* merge_units */
Own_0FD0* Object_ClosestPlayerDistSq(Gen_0FD0* g, int i);
#endif /* merge_units */
#define Object_ClosestPlayerDistSq(a0, a1) ((Own_0FD0 *)Object_ClosestPlayerDistSq((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int Event_Construct(Msg_0FD0* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

void func_003FF930(Msg_0FD0* m, int id);
#if 0 /* merge_units */
int cMessage_dtor(Msg_0FD0* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

}
static inline int Owner_0FD0(Own_0FD0* o) { return ((o->h & 0x7F000000) >> 24) - 1; }
extern "C" void cGenerator_v17(Gen_0FD0* g, int who)
{
    char ctx[4];
    char ctx2[4];
    Msg_0FD0 msg;
    g->b2C = 1;
    if (D_005721C8) {
        int ok = g->b2D != 0;
        ok = ok ? g->b2C != 0 : ok;
        ok = ok ? (g->b2E != 0) ^ 1 : ok;
        if (ok) {
            func_0043B190(ctx);
            if (who < 0) {
                Own_0FD0* o = Object_ClosestPlayerDistSq(g, 0);
                func_00439D00(ctx, g->key, o ? Owner_0FD0(o) : NetLocalId());
            } else {
                if (who == NetLocalId() && g->maskCC == 0) {
                    void* key = g->key;
                    func_00439D00(ctx, key, NetLocalId());
                }
            }
            func_0043A420(ctx, g->key);
        } else if (who < 0) {
            int own = -1;
            Own_0FD0* o = Object_ClosestPlayerDistSq(g, 0);
            if (o) own = Owner_0FD0(o);
            if (own != NetLocalId()) {
                func_0043B190(ctx2);
                func_00439D00(ctx2, g->key, own);
            }
        }
        if (who >= 0) g->maskCC |= 1 << who; else g->maskCC = 0xFF;
        Event_Construct(&msg, g_cEnableMsgClass);
        msg.f24 = who;
        msg.vt = D_004E0880;
        msg.f1C = 0x40;
        msg.f20 = 4;
        func_003FF930(&msg, g->id10);
        msg.vt = D_004E0880;
        cMessage_dtor(&msg, 0);
    }
}
#undef func_0043B190 /* merge_units */
#undef Object_ClosestPlayerDistSq /* merge_units */
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00220FD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00220FD0 */

/* merge_units: begin func_002212D0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {}
extern "C" {
#if 0 /* merge_units */
void func_0043B190(void* ctx);
#endif /* merge_units */
#define func_0043B190(a0) (func_0043B190((a0))) /* merge_units */

}
extern "C" void cGenerator_v06(Gen_12D0* g)
{
    char ctx[4];
    func_003CE810();
    int ok = g->b2D != 0;
    ok = ok ? g->b2C != 0 : ok;
    ok = ok ? (g->b2E != 0) ^ 1 : ok;
    if (ok) {
        func_0043B190(ctx);
        if ((g->maskCC & (1 << NetLocalId())) && func_0043AB20(ctx, g->key) == 0) {
            void* key = g->key;
            func_00439D00(ctx, key, NetLocalId());
        }
        func_0043A420(ctx, g->key);
    }
}
#undef func_0043B190 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002212D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002212D0 */
