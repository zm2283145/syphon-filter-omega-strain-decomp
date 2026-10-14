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
    V operator-() const { V t; const V* sp = this; V* tp = &t; __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(tp), "r"(sp) : "memory"); return t; }
    V operator*(float s) const { V r; int t; const V* tp = this; V* rp = &r; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(rp), "r"(tp), "f"(s) : "memory"); return r; }
} __attribute__((aligned(16)));
struct M {
    V r0, r1, r2, t;
    M() {}
    M(const M& o) { const M* s = &o; M* d = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
};
static inline void MulV(V* v, M* m) { V* o = v; __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
struct Sub {
    VPAD16(a) VPAD4(b)
    virtual void Sync();
    char pad4[0xC];
    M m;
    unsigned char f50;
};
static inline const M& SubMtx(Sub* o) { if (o->f50) o->Sync(); return o->m; }
struct Obj { char pad[0x50]; Sub* sub; };
struct Svc { virtual void v0(); virtual void Send(void* m); };
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct HitSub { VP v[3]; V n; unsigned char b40; char b41; unsigned char b42; char pad43[0x1D]; int f60; int f64; void Init() { HitSub* q = this; VP* i = q->v; VP* e = q->v + 3; do { i++; } while (i != e); q->b40 = 0; q->b42 = 0; q->f60 = 0; q->f64 = 0; } };
struct HitRes { unsigned char hit; char pad1[0xF]; V pos; HitSub s; char pad88[0x10]; HitRes() { HitRes* p = this; p->s.Init(); } V Normal() const { const V* q = &s.n; return *q; } };
struct Item { char pad[0x3C]; int range; };
struct Plr { char pad[0x3524]; int inv; };
struct RayMsg { void* vt; char base[0x20]; int f24; int f28; HitRes* res; V start; V end; Plr* pl; void* cl; int f58; unsigned char b5C; };
extern "C" {
extern char* D_004FFC2C;
extern char D_004FFB50[];
extern char D_004EA0B0[];
extern char D_005435A0[];
extern char D_004D9180[];
Svc* Service_Lookup(void* a, void* b);
void Event_Construct(void* m, void* type);
void cMessage_dtor(void* m, int flags);
void func_00244960(char* h, float f);
void func_00244580(char* h, V* a, V* b);
Item* WeaponInv_GetHeldItem(int inv);
}
extern "C" unsigned char func_002497C0(V* out, Obj* obj, Plr* p)
{
    M m = SubMtx(obj->sub);
    char* hud = D_004FFC2C;
    func_00244960(hud, 0.0f);
    V a;
    unsigned char r = 0;
    a.y = 1.5f; a.w = 1.0f; a.x = 0.0f; a.z = 0.0f;
    MulV(&a, &m);
    m.t = a;
    float range = (float)WeaponInv_GetHeldItem(p->inv)->range;
    HitRes res;
    RayMsg msg;
    V b;
    V d;
    V dir = m.r1 * range;
    RayMsg* mp = &msg;
    V* st = &m.t;
    Event_Construct(mp, D_005435A0);
    mp->vt = D_004D9180;
    mp->f24 = 0;
    mp->f28 = 0;
    mp->res = &res;
    mp->start = *st;
    mp->end = dir;
    mp->pl = p;
    mp->cl = 0;
    mp->f58 = 0x10;
    mp->b5C = 0;
    mp->start.w = 1.0f;
    mp->end.w = 0.0f;
    Service_Lookup(D_004FFB50, D_004EA0B0)->Send(&msg);
    b.x = 0.0f; b.y = range; b.z = 0.0f; b.w = 1.0f;
    MulV(&b, &m);
    if (res.hit) {
        *out = res.pos;
        d = res.Normal();
        r = 1;
    } else {
        *out = b;
        d = -m.r1;
    }
    func_00244580(hud, out, &d);
    msg.vt = D_004D9180;
    cMessage_dtor(&msg, 0);
    return r;
}
