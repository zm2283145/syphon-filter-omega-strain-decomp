#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
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
void Event_Construct(void* m, void* type);
void cMessage_dtor(void* m, int flags);
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
