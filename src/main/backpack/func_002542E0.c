#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    V operator-(const V& b) const { V r; const V* tp = this; V* rp = &r; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(&b) : "memory"); return r; }
} __attribute__((aligned(16)));
struct Mtx { V r0, r1, r2, t; };
struct Sub {
    VPAD16(a) VPAD4(b)
    virtual void Sync();
    char pad4[0xC];
    Mtx m;
    unsigned char f50;
};
static inline const V& SubPos(Sub* o) { if (o->f50) o->Sync(); return o->m.t; }
struct Tgt { char pad[0xC]; int id; char pad10[0x1C]; unsigned char b2C; unsigned char b2D; unsigned char b2E; };
struct Hnd { Tgt* p; int id; };
struct Svc { virtual void v0(); virtual void Send(void* m); };
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct HitSub { VP v[3]; char pad30[0x10]; unsigned char b40; char b41; unsigned char b42; char pad43[0x1D]; int f60; int f64; void Init() { HitSub* q = this; VP* i = q->v; VP* e = q->v + 3; do { i++; } while (i != e); q->b40 = 0; q->b42 = 0; q->f60 = 0; q->f64 = 0; } };
struct HitRes { unsigned char hit; char pad1[0xF]; VP pos; HitSub s; char pad88[0x10]; HitRes() { HitRes* p = this; p->s.Init(); } };
struct Bp;
struct RayMsg { void* vt; char base[0x20]; int f24; int f28; HitRes* res; V start; V end; Bp* pl; void* cl; int f58; unsigned char b5C; };
struct Bp {
    VPAD32(a) VPAD8(b)
    virtual void OnHit(const V& d);
    char pad4[0x4C];
    Sub* sub;
    char pad54[0x2F4 - 0x54];
    unsigned char b2F4;
    Tgt* t2F8;
    int pad2FC;
    Hnd h;
};
extern "C" {
extern char D_004FFB50[];
extern char D_004EA0B0[];
extern char D_005435A0[];
extern char D_004D9180[];
Svc* Service_Lookup(void* a, void* b);
void Event_Construct(void* m, void* type);
void cMessage_dtor(void* m, int flags);
}
static inline bool IdEq(Tgt* p, Hnd* h) { return p->id == h->id; }
static inline Tgt* HGet(Hnd* h) {
    bool ok = !h->p || IdEq(h->p, h);
    return ok ? h->p : 0;
}
static inline bool Not(unsigned char x) { return !x; }
static inline bool Ready(Tgt* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }
extern "C" void cBackpack_v10(Bp* self)
{
    if (self->b2F4) {
        Tgt* t = self->t2F8;
        if (t && Ready(t)) {
            if (!HGet(&self->h) || !Ready(HGet(&self->h))) {
                HitRes res;
                V start = SubPos(self->sub);
                V dir(0.0f, 0.0f, -5.0f, 1.0f);
                RayMsg msg;
                RayMsg* m = &msg;
                Event_Construct(m, D_005435A0);
                m->vt = D_004D9180;
                m->f24 = 0;
                m->f28 = 0;
                m->res = &res;
                m->start = start;
                m->end = dir;
                m->pl = self;
                m->cl = 0;
                m->f58 = 0;
                m->b5C = 0;
                m->start.w = 1.0f;
                m->end.w = 0.0f;
                Service_Lookup(D_004FFB50, D_004EA0B0)->Send(&msg);
                if (res.hit) {
                    V d = *(V*)&res.pos - start;
                    self->OnHit(d);
                }
                self->b2F4 = 0;
                msg.vt = D_004D9180;
                cMessage_dtor(&msg, 0);
            }
        }
    }
}

