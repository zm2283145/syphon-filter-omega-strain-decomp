#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#pragma opt_rebuildconditionals off

#pragma opt_dead_assignments off
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
#include "types.h"

struct V4 {
    union { struct { float x, y, z, w; } f; __int128 q; } u;
    V4() {}
    V4(const V4& o) { V4* d = this; const V4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    V4(float a, float b, float c, float d) { u.f.x = a; u.f.y = b; u.f.z = c; u.f.w = d; }
    void Set(const V4& o) { u.q = o.u.q; }
};
struct Mtx { V4 r[4]; };
struct Mtx3 { V4 r[3]; };
struct Cam {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual Mtx3 GetMtx();
};
struct Ctl { char p[0x20]; float x20; };
struct Inv;
struct Item { char p[0x3C]; int x3C; char p40[0xF0 - 0x40]; unsigned char kind; };
struct Tgt {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D();
    virtual V4 GetPos(int a); /* 0xC0 */
    virtual unsigned char Kind(); /* 0xC4 */
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual Mtx GetMtx(); /* 0xD8 */
    virtual void v35(); virtual void v36();
    virtual V4 GetDir(); /* 0xE4 */
    virtual void v3A(); virtual void v3B(); virtual void v3C();
    virtual Mtx3 GetViewMtx(); /* 0xF4 */
    int pad4[2];
    int id;
    char p10[0x2C - 0x10];
    bool x2C; bool x2D; bool x2E; char p2F;
    char p30[0x44 - 0x30];
    int x44;
    char p48[0x4C - 0x48];
    int x4C;
    char p50[0x58 - 0x50];
    Ctl* x58;
    char p5C[0x33A8 - 0x5C];
    float x33A8;
    char p33AC[0x346C - 0x33AC];
    unsigned char x346C;
    char p346D[0x3470 - 0x346D];
    unsigned char x3470;
    char p3471[0x3524 - 0x3471];
    Inv* inv;
    bool Alive() { bool r = 0; if (x2D && x2C) r = 1; return r; }
    bool Live() { return !x2E; }
    bool Targetable() { bool r = 0; if (Alive() && Live()) r = 1; return r; }
};
struct Hnd { Tgt* p; int id; };
static inline bool IdEq(Tgt* p, Hnd* h) { return p->id == h->id; }
static inline Tgt* HGet(Hnd* h) {
    bool ok = !h->p || IdEq(h->p, h);
    return ok ? h->p : 0;
}
struct HndT {
    Tgt* p; int id;
    HndT(Tgt* a) { id = -1; p = a; int none; id = *(a ? &a->id : (none = -1, &none)); }
};
struct WNode { WNode* prev; WNode* next; Hnd h; };
struct WIt {
    WNode* volatile n;
    WIt() {}
    WIt(WNode* a) { n = a; }
    Hnd& operator*() { return n->h; }
    WIt Post() { WIt old = *this; n = n->next; return old; }
    WIt operator++(int) { WIt r = Post(); return r; }
    bool operator!=(const WIt& o) const { return n != o.n; }
    bool operator==(const WIt& o) const { return n == o.n; }
};
struct WIt2 {
    WNode* volatile n;
    WIt2() {}
    WIt2(WNode* a) { n = a; }
    Hnd& operator*() { return n->h; }
    WIt2 Post1() { WNode* c = n; WIt2 old(c); n = c->next; return old; }
    WIt2 Post() { return Post1(); }
    WIt2 operator++(int) { WIt2 r = Post(); return r; }
    bool operator!=(const WIt2& o) const { return n != o.n; }
    bool operator==(const WIt2& o) const { return n == o.n; }
};
struct Eq {};
struct Pred { Eq op; HndT* value; Pred(const Eq& o, HndT& v) : op(o) { value = &v; } };
struct RList { volatile int count; WNode* head; };
struct WList { int x0; int list; };
struct Sys { char p[0x18]; WList objs; };
struct World { char p[0x90]; Sys sys; Sys* S() { return &sys; } };

extern "C" {
extern World* g_Hud;
extern char g_CameraObject;
extern int g_HumanActorClassKey;
extern float D_0048AC4C;
extern float D_0048AC54;
extern float D_0048AC24;
extern float D_0048AC28;
extern float D_0048AC2C;
extern float D_0048AC34;
extern float D_0048AC38;
extern float D_0048AC3C;
extern float D_0048AC40;
extern float D_0048AC44;
extern char g_TargetVisMgr;
WNode* WorldObjList_Get(void* l);
int func_00159570(void* p);
Cam** List_Front(void* p);
Item* WeaponInv_GetHeldItem(Inv* inv);
int TeamTable_AreEnemies(Tgt* a, Tgt* b);
void Combat_HitDirection(Mtx3* m, V4* v, V4* out);
Tgt* Controller_GetAimTarget(Ctl* c);
WNode* func_0021EDE0(void* n);
WNode* func_0021E000(void* l);
WNode** func_0021DFE0(WIt* it, WNode* n);
WNode** func_0021DFF0(WIt* it, WNode* n);
int TargetVis_Test(void* mgr, Tgt* a, Tgt* b, int c, int d);
void TargetVis_LeaveRecent(RList* l, Pred p);
WIt WeakHandleList_Append(RList* list, const WIt& pos, HndT* h);
Tgt* Targeting_AutoPick(Tgt* self, Tgt* cur);
}

static inline WIt2 WBegin(WList& l) { WIt2 r(WorldObjList_Get(&l.list)->next); return r; }
static inline WIt2 WEnd(WList& l) { WIt2 r(WorldObjList_Get(&l.list)); return r; }
static inline V4 Sub(const V4& a, const V4& b) {
    V4 r;
    V4* pr = &r; const V4* pa = &a; const V4* pb = &b;
    asm {
        lqc2 vf1, 0x0(pa)
        lqc2 vf2, 0x0(pb)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(pr)
    }
    return r;
}
static inline float LenSq(V4* v) {
    float r = 0.0f; int t;
    asm {
        lqc2 vf1, 0x0(v)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
static inline void QCp(V4* d, const V4* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
/* sqrt.s: no C equivalent */
static inline float SqrtZ(float x) { float r = 0.0f; asm { sqrt.s r, x } return r; }
static inline float Sq(float x) { return x * x; }
static inline bool Vis(Tgt* a, Tgt* b) { return TargetVis_Test(&g_TargetVisMgr, a, b, 0, 0); }

/* Targeting_AutoPick: nearest visible enemy within the held weapon's range,
 * weighted by its cover level and by how far off the aim direction it is. */
Tgt* Targeting_AutoPick(Tgt* self, Tgt* cur)
{
    WList& wl = g_Hud->S()->objs;
    WIt2 it = WBegin(wl);
    WIt2 end = WEnd(wl);
    V4 dir = self->GetDir();
    V4 org;
    Mtx3 cm = self->GetViewMtx();
    QCp(&org, &dir);
    Tgt* best = 0;
    Item* item = WeaponInv_GetHeldItem(self->inv);
    if (!item || item->kind == 1 || item->kind == 3 || item->kind == 4 || item->kind == 10)
        return 0;
    float bestSq = (float)(item ? item->x3C * item->x3C : 0);
    for (; it != end; it++) {
        Tgt* t = HGet(&*it);
        if (!t) continue;
        if (!t->Targetable()) continue;
        if (t == self || !TeamTable_AreEnemies(self, t)) continue;
        if (t->Kind() != 2) continue;
        if (Vis(self, t)) continue;
        V4 pos = t->GetPos(-1);
        V4 diff = Sub(pos, dir);
        V4 hd;
        V4 tdir = t->GetDir();
        Combat_HitDirection(&cm, &tdir, &hd);
        float aim = SqrtZ(Sq(hd.u.f.x) + Sq(hd.u.f.z));
        aim = 1.0f - aim / 3.1415927f;
        if (t == cur) aim += D_0048AC54;
        if (aim <= D_0048AC4C) continue;
        float dsq = LenSq(&diff);
        int cover = t->x44;
        if (self->x33A8 > 0.0f) cover = 100;
        else if (self->x3470 == 1) cover = 0;
        if (cover >= 100) continue;
        if (cover) {
            float k = 100.0f / (float)(100 - cover);
            dsq = dsq * (k * k);
        }
        if (dsq < bestSq) {
            bestSq = dsq;
            best = t;
        }
    }
    return best;
}
