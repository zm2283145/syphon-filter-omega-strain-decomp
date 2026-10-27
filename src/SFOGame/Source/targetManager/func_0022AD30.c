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
extern float D_0048AC24;
extern float D_0048AC28;
extern float D_0048AC2C;
extern float D_0048AC34;
extern float D_0048AC38;
extern float D_0048AC3C;
extern float D_0048AC40;
extern float D_0048AC44;
extern char g_TargetVisMgr;
WNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(void* l);
int func_00159570(void* p);
Cam** cLList_cCAMERA_GOBJPtr_Front(void* p);
Item* cWeapon_GetWeaponEntry(Inv* inv);
int cGOBJ_Enemy(Tgt* a, Tgt* b);
void GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(Mtx3* m, V4* v, V4* out);
Tgt* cGobjController_GetTarget(Ctl* c);
WNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(void* n);
WNode* std_list_deleter_cSafePtr_cGOBJ_tail(void* l);
WNode** std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(WIt* it, WNode* n);
WNode** std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(WIt* it, WNode* n);
int cTargetManager_IsLosBlocked(void* mgr, Tgt* a, Tgt* b, int c, int d);
void std_list_imp_cSafePtr_cGOBJ_remove_if(RList* l, Pred p);
WIt std_list_deleter_cSafePtr_cGOBJ_insert(RList* list, const WIt& pos, HndT* h);
Tgt* ChooseTarget(Tgt* self, Tgt* cur, RList* recent);
}

static inline float Sq(float x) { return x * x; }
static inline bool NotVis(Tgt* a, Tgt* b) { return !cTargetManager_IsLosBlocked(&g_TargetVisMgr, a, b, 0, 1); }
static inline WIt Next(WIt& i) { return i++; }
static inline WIt2 WBegin(WList& l) { WIt2 r(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(&l.list)->next); return r; }
static inline WIt2 WEnd(WList& l) { WIt2 r(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(&l.list)); return r; }
static inline WIt RHead(RList* l) { WIt r(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(&l->head)->next); return r; }
static inline WIt RBegin(RList* l) { WIt t; std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(&t, std_list_deleter_cSafePtr_cGOBJ_tail(l)->next); return t; }
static inline WIt REnd(RList* l) { WIt t; std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&t, std_list_deleter_cSafePtr_cGOBJ_tail(l)); return t; }
static inline void RPush(RList* l, const HndT& h) { WNode* hd = (WNode*)&l->head; std_list_deleter_cSafePtr_cGOBJ_insert(l, WIt(hd), (HndT*)&h); }

static inline V4 Xform(const Mtx& m, const V4& in) {
    V4 v;
    V4* d = &v;
    const V4* s = &in;
    __int128 t;
    __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory");
    V4* p = &v;
    __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(p), "r"(&m), "r"(p) : "memory");
    return *p;
}
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
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }

static inline void Leave2(RList* l, const HndT& h) { Eq eq; std_list_imp_cSafePtr_cGOBJ_remove_if(l, Pred(eq, (HndT&)h)); }
static inline void Leave3(RList* l, Tgt* t) { Leave2(l, HndT(t)); }
static inline void Push2(RList* l, Tgt* t) { RPush(l, HndT(t)); }
Tgt* ChooseTarget(Tgt* self, Tgt* cur, RList* recent)
{
    WList& wl = g_Hud->S()->objs;
    WIt2 it = WBegin(wl);
    WIt2 end = WEnd(wl);
    V4 off(0.0f, 0.0f, 5.0f, 1.0f);
    Mtx sm = self->GetMtx();
    V4 aim = Xform(sm, off);
    Cam* cam = func_00159570(&g_CameraObject) ? *cLList_cCAMERA_GOBJPtr_Front(&g_CameraObject) : 0;
    V4 aim2;
    Mtx3 cm = cam->GetMtx();
    aim2 = aim;
    int cnt = recent->count;
    bool sawCur = false;
    Item* item = cWeapon_GetWeaponEntry(self->inv);
    Tgt* tgts[16];
    float scores[16];
    int n;
    int best;
    if (!item || item->kind == 1 || item->kind == 3 || item->kind == 4 || item->kind == 10)
        return 0;
    float maxSq = (float)(item ? item->x3C * item->x3C : 0);
    float closeSq = Sq(D_0048AC38);
    n = 0;
    for (; it != end; it++) {
        Tgt* t = HGet(&*it);
        if (!t) continue;
        if (!t->Targetable()) continue;
        if (t == self || !cGOBJ_Enemy(self, t)) continue;
        if (t->Kind() != 2) continue;
        int cover = t->x44;
        {
            int* pd = &g_HumanActorClassKey;
            int ty = *pd;
            if (t->x4C == ty && t->x346C) continue;
        }
        if (self->x33A8 > 0.0f) cover = 100;
        else if (self->x3470 == 1) cover = 0;
        if (cover >= 100) continue;
        V4 pos = t->GetPos(-1);
        V4 diff = Sub(pos, aim);
        float dsq = LenSq(&diff);
        float wd;
        float lvlScore, yaw, dist, rec, pitch, score;
        lvlScore = 0.0f; yaw = 0.0f; pitch = 0.0f; rec = 0.0f; dist = 0.0f; score = 0.0f;
        wd = dsq;
        if (cover) {
            float k = 100.0f / (float)(100 - cover);
            wd = dsq * (k * k);
        }
        if (wd < maxSq) {
            V4 hd;
            V4 dir = t->GetDir();
            GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(&cm, &dir, &hd);
            dist = D_0048AC24 * (maxSq - wd);
            pitch = 1.0f - Abs(hd.u.f.z) / 3.1415927f;
            yaw = 1.0f - Abs(hd.u.f.x) / 3.1415927f;
            dist = dist / maxSq;
            int lvl;
            Ctl* c = t->x58;
            lvl = 4;
            if (pitch > D_0048AC3C || wd < closeSq) lvl = 1;
            else if (pitch > D_0048AC40) lvl = 2;
            else if (pitch > D_0048AC44) lvl = 3;
            if (c && cGobjController_GetTarget(c) == self && dsq < 200.0f && c->x20 > 0.75f) lvl = 1;
            lvlScore = (4.0f - (float)lvl) / 3.0f * D_0048AC34;
            pitch = pitch * D_0048AC2C;
            int found = -1;
            {
                WIt i = RHead(recent);
                int idx = 0;
                for (i = RBegin(recent); i != REnd(recent) && found < 0; ) {
                    if (HGet(&*Next(i)) == t) found = idx;
                    idx++;
                }
            }
            rec = (float)(5 - found) / 6.0f * D_0048AC28;
            score = pitch + (rec + (dist + lvlScore));
        }
        if (score <= 0.0f) continue;
        if (t == cur) {
            sawCur = true;
            continue;
        }
        tgts[n] = t;
        scores[n] = score;
        n++;
    }
    do {
        best = -1;
        float z = 0.0f;
        for (int i = 0; i < n; i++) {
            bool better;
            if (best < 0) better = scores[i] > z;
            else better = scores[i] > scores[best];
            if (better) best = i;
        }
        if (best >= 0) {
            scores[best] = -1.0f;
            if (NotVis(self, tgts[best])) {
                Leave3(recent, tgts[best]);
                Push2(recent, tgts[best]);
                return tgts[best];
            }
        }
    } while (best >= 0);
    return sawCur ? cur : 0;
}
