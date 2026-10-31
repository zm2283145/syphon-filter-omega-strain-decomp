#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(&o)); asm { sq t, 0(this) } }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    static void VU0Subtract(V& vecOut, const V& vecIn0, const V& vecIn1) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&vecOut), "r"(&vecIn0), "r"(&vecIn1) : "memory"); }
    V operator-(const V& vector) const { V result; VU0Subtract(result, *this, vector); return result; }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
    void Normalize() { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory"); }
    void Scale(float k) { V* d = this; const V* s = this; __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(d), "r"(s), "f"(k) : "memory"); }
} __attribute__((aligned(16)));

struct Entry { int time; int interval; int result; unsigned char c; unsigned char pending; };
struct Ctl {
    VPAD16(a) VPAD2(b) virtual void c18();
    virtual int Active();
};
struct Obj {
    VPAD32(a) VPAD8(b) VPAD4(c) virtual void o44();
    virtual V GetPos();
    char pad4[0x10]; unsigned char b14; char pad15[0x37]; int f4C; char pad50[8]; Ctl* ctl;
};
struct Svc { virtual void s0(); virtual void Send(void* m); };
struct Vis {
    virtual void v0(); virtual void Send(void* m);
    char pad4[0x1C]; Entry* rows[0x3C]; char map[4]; char end[4];
};
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct HitSub { VP v[3]; V n; unsigned char b40; char b41; unsigned char b42; char pad43[0x1D]; int f60; int f64; void Init() { HitSub* q = this; VP* i = q->v; VP* e = q->v + 3; do { i++; } while (i != e); q->b40 = 0; q->b42 = 0; q->f60 = 0; q->f64 = 0; } HitSub* InitR() { HitSub* q = this; VP* i = q->v; VP* e = q->v + 3; do { i++; } while (i != e); q->b40 = 0; q->b42 = 0; q->f60 = 0; q->f64 = 0; return q; } };
struct HitRes { unsigned char hit; char pad1[0xF]; V pos; HitSub s; int res; char pad94[0xC]; HitSub* Init() { HitRes* p = this; return p->s.InitR(); } };
struct RayMsg { void* vt; char base[0x20]; void* f24; int* f28; HitRes* res; V start; V end; Obj* pl; Obj* cl; int f58; unsigned char b5C; RayMsg() {} RayMsg(void* o, int* r, HitRes* h, const V& s, const V& en, Obj* p, Obj* c, int f, unsigned char bb); };
struct HS2 { char pad[0x70]; void Touch() { HS2* q = this; if (q) q = 0; } };
struct HR2 { char pad[0x20]; HS2 s; char tail[0x10]; };
struct ResMsg { void* vt; char base[0x20]; char pad24[0xC]; HR2 res; };
struct Key { Entry* e; int result; int lo; int hi; Key(Entry* a, int b, int c, int d) { e = a; result = b; lo = c; hi = d; } };

extern "C" {
extern int g_FrameCounter;
extern int g_HumanActorClassKey;
extern char g_Game[]; extern char g_LosCheckService[];
extern char g_LosRequestMsgClass[]; extern char g_LosResultMsgClass[];
extern char D_004D9180[]; extern char D_004D91C0[];
int cTargetManager_FindGobj(Vis* v, Obj* o);
Svc* cSystemContainer_GetSystem(void* a, void* b);
int func_0014D460(Obj* o);
int func_0014D450(int x);
int func_0014D410(int x);
int func_001AE360(Svc* s);
void LosProvider_SeedRegion(int a, int b);
int cAreaEffect_LOS_Obscured(V* a, V* b, HitSub* s);
void cLosResult_ctor_cLosResultR(void* d, HitRes* r);
void std_list_deleter_LosReqElem_insert(void* out, void* map, void* it, const Key* k);
void cMessage_ctor_cMessageNameR(void* m, void* type);
void cMessage_dtor(void* m, int flags);
}

inline RayMsg::RayMsg(void* o, int* r, HitRes* h, const V& s, const V& en, Obj* p, Obj* c, int f, unsigned char bb) { char b2 = bb; RayMsg* m = this; cMessage_ctor_cMessageNameR(m, g_LosRequestMsgClass); m->vt = D_004D9180; m->f24 = o; m->f28 = r; m->res = h; m->start = s; m->end = en; m->pl = p; m->cl = c; m->f58 = f; m->b5C = b2; m->start.w = 1.0f; m->end.w = 0.0f; }
static inline bool IsActive(Obj* o)
{
    bool r = 0;
    if (o->ctl && o->ctl->Active()) r = 1;
    return r;
}
static inline void Insert(void* it, void* map, void* end, const Key& k) { std_list_deleter_LosReqElem_insert(it, map, end, &k); }

extern "C" int cTargetManager_IsLosBlocked(Vis* self, Obj* a, Obj* b, int delay, bool force)
{
    int out;
    char it1[4];
    void* end1;
    char it2[4];
    void* end2;
    int lo;
    int hi;
    int ret;
    Entry* e;
    int now;
    Svc* svc;

    lo = cTargetManager_FindGobj(self, a);
    hi = cTargetManager_FindGobj(self, b);
    ret = 0;
    if (lo < 0 || hi < 0) return ret;
    if (lo == hi) return ret;
    if (IsActive(a) && IsActive(b)) return ret;
    if (hi < lo) { int t = lo; lo = hi; hi = t; }
    e = &self->rows[lo][hi - lo - 1];
    now = g_FrameCounter;
    if (force || (!e->pending && e->time - 20 < now)) {
        if ((IsActive(b) && b->b14) || (IsActive(a) && !a->b14)) {
            Obj* t = a; a = b; b = t;
        }
        V posB = b->GetPos();
        V posA = a->GetPos();
        V dir = posB - posA;
        svc = cSystemContainer_GetSystem(g_Game, g_LosCheckService);
        int* gp = &g_HumanActorClassKey;
        int id = *gp;
        if (a->f4C == id) {
            int h = func_0014D410(func_0014D450(func_0014D460(a)));
            if (h) LosProvider_SeedRegion(func_001AE360(svc), h);
        }
        force = 1;
        if (!force) {
            RayMsg ma(self, &out, 0, posA, dir, a, b, 4, 2);
            RayMsg* m = &ma;
            e->pending = 1;
            svc->Send(&ma);
            Insert(it1, self->map, (end1 = self->end, &end1), Key(e, out, lo, hi));
            ma.vt = D_004D9180;
            cMessage_dtor(m, 0);
        } else if (now - delay >= e->interval) {
            HitRes r;
            int hit = cAreaEffect_LOS_Obscured(&posA, &posB, r.Init());
            if (hit) {
                e->result = hit;
                e->c = 0;
                e->pending = 0;
                e->time = g_FrameCounter + 40;
            } else {
                dir.Normalize();
                dir.Scale(250.0f);
                RayMsg mb;
                RayMsg* m = &mb;
                cMessage_ctor_cMessageNameR(m, g_LosRequestMsgClass);
                m->vt = D_004D9180;
                m->f24 = 0;
                m->f28 = 0;
                m->res = &r;
                m->start = posA;
                m->end = dir;
                m->pl = a;
                m->cl = b;
                m->f58 = 4;
                m->b5C = 0;
                m->start.w = 1.0f;
                m->end.w = 0.0f;
                svc->Send(&mb);
                out = 0;
                r.res = out;
                if (r.hit) {
                    float l1 = (r.pos - posA).LenSq();
                    if (!(l1 <= (posB - posA).LenSq())) r.hit = 0;
                }
                ResMsg mr;
                ResMsg* q = &mr;
                cMessage_ctor_cMessageNameR(q, g_LosResultMsgClass);
                q->vt = D_004D91C0;
                cLosResult_ctor_cLosResultR(&q->res, &r);
                { void* en = self->end; e->pending = 1; Insert(it2, self->map, (end2 = en, &end2), Key(e, out, lo, hi)); }
                self->Send(q);
                { void* vt = D_004D91C0; HS2* hs = &mr.res.s; mr.vt = vt; hs->Touch(); }
                cMessage_dtor(q, 0);
                mb.vt = D_004D9180;
                cMessage_dtor(&mb, 0);
            }
        }
    }
    if (now - delay < e->interval) ret = 0;
    else if (now < e->time) ret = e->result;
    return ret;
}


