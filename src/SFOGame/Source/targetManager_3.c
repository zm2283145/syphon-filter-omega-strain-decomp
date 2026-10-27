/*
 * SFOGame/Source/targetManager: 3 files, 0022ABC0-0022B660
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022ABC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); return *this; }
    V operator-(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(this), "r"(&c), "r"(&b) : "memory");
        return c;
    }
} __attribute__((aligned(16)));
struct M {
    V r0, r1, r2, t;
    M() {}
    M& operator=(const M& o) { M* d = this; const M* s = &o; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
    M(const M& o) { const M* s = &o; M* d = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
};
static inline void MulV(V* v, M* m) { __asm__ volatile("lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
extern "C" {
V* cVector_ctor_cVectorR(V* d, V* s);
void cMatrix_InvertRot(M* m);
int cMatrix_IsZeroTranslation(M* m);
V* func_00133EC0(M* m);
void cVector_NegateXYZ(V* v);
void cVector_Rotate_cMatrixR(V* v, M* m);
void cMatrix_SetTranslation(M* m, V* v);
float Libc_Atan2f(float y, float x);
float GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(M* m, V* p, V* out);
}
static inline void InvertRigid(M* m)
{
    cMatrix_InvertRot(m);
    if (!cMatrix_IsZeroTranslation(m)) {
        V t;
        cVector_ctor_cVectorR(&t, func_00133EC0(m));
        cVector_NegateXYZ(&t);
        cVector_Rotate_cMatrixR(&t, m);
        cMatrix_SetTranslation(m, &t);
    }
}
static inline void CP1(V* d, const V* s) { __int128 t; asm volatile { lq t, 0(s); sq t, 0(d) } }
static inline void MulVO(V* o, V* v, M* m) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
static inline float Len(V* v) {
    float r = 0.0f;
    int t;
    asm {
        lqc2 vf1, 0x0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2 t, vf4
        mtc1 t, r
    }
    return r;
}
/* GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP: hit point in the target frame; yaw/pitch of it into out, returns the horizontal distance */
float GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(M* m, V* p, V* out)
{
    M inv = *m;
    InvertRigid(&inv);
    V l;
    CP1(&l, p);
    MulVO(&l, &l, &inv);
    V h(l.x, l.y, 0.0f, 0.0f);
    float d = Len(&h);
    out->x = Libc_Atan2f(l.z, d);
    out->y = 0.0f;
    out->z = Libc_Atan2f(-l.x, l.y);
    return d;
}
static inline void merge_flush_func_0022ABC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022ABC0 */

/* merge_units: begin func_0022AD30 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#pragma opt_rebuildconditionals off

#pragma opt_dead_assignments off
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off

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
#if 0 /* merge_units */
void GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(Mtx3* m, V4* v, V4* out);
#endif /* merge_units */
#define GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(a0, a1, a2) ((void)GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP((M *)(a0), (V *)(a1), (V *)(a2))) /* merge_units */

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
#undef GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP /* merge_units */
static inline void merge_flush_func_0022AD30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022AD30 */

/* merge_units: begin func_0022B660 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#pragma opt_rebuildconditionals off

#pragma opt_dead_assignments off
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off

struct V4_0022B660 {
    union { struct { float x, y, z, w; } f; __int128 q; } u;
    V4_0022B660() {}
    V4_0022B660(const V4_0022B660& o) { V4_0022B660* d = this; const V4_0022B660* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    V4_0022B660(float a, float b, float c, float d) { u.f.x = a; u.f.y = b; u.f.z = c; u.f.w = d; }
    void Set(const V4_0022B660& o) { u.q = o.u.q; }
};
struct Mtx_0022B660 { V4_0022B660 r[4]; };
struct Mtx3_0022B660 { V4_0022B660 r[3]; };
struct Cam_0022B660 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual Mtx3_0022B660 GetMtx();
};
struct Inv;
struct Tgt_0022B660 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D();
    virtual V4_0022B660 GetPos(int a); /* 0xC0 */
    virtual unsigned char Kind(); /* 0xC4 */
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual Mtx_0022B660 GetMtx(); /* 0xD8 */
    virtual void v35(); virtual void v36();
    virtual V4_0022B660 GetDir(); /* 0xE4 */
    virtual void v3A(); virtual void v3B(); virtual void v3C();
    virtual Mtx3_0022B660 GetViewMtx(); /* 0xF4 */
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
struct Hnd_0022B660 { Tgt_0022B660* p; int id; };
static inline bool IdEq_0022B660(Tgt_0022B660* p, Hnd_0022B660* h) { return p->id == h->id; }
static inline Tgt_0022B660* HGet_0022B660(Hnd_0022B660* h) {
    bool ok = !h->p || IdEq_0022B660(h->p, h);
    return ok ? h->p : 0;
}
struct HndT_0022B660 {
    Tgt_0022B660* p; int id;
    HndT_0022B660(Tgt_0022B660* a) { id = -1; p = a; int none; id = *(a ? &a->id : (none = -1, &none)); }
};
struct WNode_0022B660 { WNode_0022B660* prev; WNode_0022B660* next; Hnd_0022B660 h; };
struct WIt_0022B660 {
    WNode_0022B660* volatile n;
    WIt_0022B660() {}
    WIt_0022B660(WNode_0022B660* a) { n = a; }
    Hnd_0022B660& operator*() { return n->h; }
    WIt_0022B660 Post() { WIt_0022B660 old = *this; n = n->next; return old; }
    WIt_0022B660 operator++(int) { WIt_0022B660 r = Post(); return r; }
    bool operator!=(const WIt_0022B660& o) const { return n != o.n; }
    bool operator==(const WIt_0022B660& o) const { return n == o.n; }
};
struct WIt2_0022B660 {
    WNode_0022B660* volatile n;
    WIt2_0022B660() {}
    WIt2_0022B660(WNode_0022B660* a) { n = a; }
    Hnd_0022B660& operator*() { return n->h; }
    WIt2_0022B660 Post1() { WNode_0022B660* c = n; WIt2_0022B660 old(c); n = c->next; return old; }
    WIt2_0022B660 Post() { return Post1(); }
    WIt2_0022B660 operator++(int) { WIt2_0022B660 r = Post(); return r; }
    bool operator!=(const WIt2_0022B660& o) const { return n != o.n; }
    bool operator==(const WIt2_0022B660& o) const { return n == o.n; }
};
struct Pred_0022B660 { Eq op; HndT_0022B660* value; Pred_0022B660(const Eq& o, HndT_0022B660& v) : op(o) { value = &v; } };
struct RList_0022B660 { volatile int count; WNode_0022B660* head; };

extern "C" {
extern float D_0048AC4C;
extern float D_0048AC54;
#if 0 /* merge_units */
WNode_0022B660* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(void* l);
#endif /* merge_units */
#define details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(a0) ((WNode_0022B660 *)details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2((a0))) /* merge_units */

#if 0 /* merge_units */
Cam_0022B660** cLList_cCAMERA_GOBJPtr_Front(void* p);
#endif /* merge_units */
#define cLList_cCAMERA_GOBJPtr_Front(a0) ((Cam_0022B660 * *)cLList_cCAMERA_GOBJPtr_Front((a0))) /* merge_units */

#if 0 /* merge_units */
int cGOBJ_Enemy(Tgt_0022B660* a, Tgt_0022B660* b);
#endif /* merge_units */
#define cGOBJ_Enemy(a0, a1) (cGOBJ_Enemy((Tgt *)(a0), (Tgt *)(a1))) /* merge_units */

#if 0 /* merge_units */
void GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(Mtx3_0022B660* m, V4_0022B660* v, V4_0022B660* out);
#endif /* merge_units */
#define GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(a0, a1, a2) ((void)GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP((M *)(a0), (V *)(a1), (V *)(a2))) /* merge_units */

#if 0 /* merge_units */
Tgt_0022B660* cGobjController_GetTarget(Ctl* c);
#endif /* merge_units */
#define cGobjController_GetTarget(a0) ((Tgt_0022B660 *)cGobjController_GetTarget((a0))) /* merge_units */

#if 0 /* merge_units */
WNode_0022B660* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(void* n);
#endif /* merge_units */
#define details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(a0) ((WNode_0022B660 *)details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4((a0))) /* merge_units */

#if 0 /* merge_units */
WNode_0022B660* std_list_deleter_cSafePtr_cGOBJ_tail(void* l);
#endif /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_tail(a0) ((WNode_0022B660 *)std_list_deleter_cSafePtr_cGOBJ_tail((a0))) /* merge_units */

#if 0 /* merge_units */
WNode_0022B660** std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(WIt_0022B660* it, WNode_0022B660* n);
#endif /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(a0, a1) ((WNode_0022B660 * *)std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP((WIt *)(a0), (WNode *)(a1))) /* merge_units */

#if 0 /* merge_units */
WNode_0022B660** std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(WIt_0022B660* it, WNode_0022B660* n);
#endif /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(a0, a1) ((WNode_0022B660 * *)std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP((WIt *)(a0), (WNode *)(a1))) /* merge_units */

#if 0 /* merge_units */
int cTargetManager_IsLosBlocked(void* mgr, Tgt_0022B660* a, Tgt_0022B660* b, int c, int d);
#endif /* merge_units */
#define cTargetManager_IsLosBlocked(a0, a1, a2, a3, a4) (cTargetManager_IsLosBlocked((a0), (Tgt *)(a1), (Tgt *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
void std_list_imp_cSafePtr_cGOBJ_remove_if(RList_0022B660* l, Pred_0022B660 p);
#endif /* merge_units */
#define std_list_imp_cSafePtr_cGOBJ_remove_if(a0, a1) (std_list_imp_cSafePtr_cGOBJ_remove_if((RList *)(a0), (Pred)(a1))) /* merge_units */

#if 0 /* merge_units */
WIt_0022B660 std_list_deleter_cSafePtr_cGOBJ_insert(RList_0022B660* list, const WIt_0022B660& pos, HndT_0022B660* h);
#endif /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_insert(a0, a1, a2) ((WIt_0022B660)std_list_deleter_cSafePtr_cGOBJ_insert((RList *)(a0), (const WIt &)(a1), (HndT *)(a2))) /* merge_units */

Tgt_0022B660* ChooseAutoTarget(Tgt_0022B660* self, Tgt_0022B660* cur);
}

static inline WIt2_0022B660 WBegin_0022B660(WList& l) { WIt2_0022B660 r(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(&l.list)->next); return r; }
static inline WIt2_0022B660 WEnd_0022B660(WList& l) { WIt2_0022B660 r(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(&l.list)); return r; }
static inline V4_0022B660 Sub_0022B660(const V4_0022B660& a, const V4_0022B660& b) {
    V4_0022B660 r;
    V4_0022B660* pr = &r; const V4_0022B660* pa = &a; const V4_0022B660* pb = &b;
    asm {
        lqc2 vf1, 0x0(pa)
        lqc2 vf2, 0x0(pb)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(pr)
    }
    return r;
}
static inline float LenSq_0022B660(V4_0022B660* v) {
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
static inline void QCp(V4_0022B660* d, const V4_0022B660* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
/* sqrt.s: no C equivalent */
static inline float SqrtZ(float x) { float r = 0.0f; asm { sqrt.s r, x } return r; }
static inline bool Vis(Tgt_0022B660* a, Tgt_0022B660* b) { return cTargetManager_IsLosBlocked(&g_TargetVisMgr, a, b, 0, 0); }

/* ChooseAutoTarget: nearest visible enemy within the held weapon's range,
 * weighted by its cover level and by how far off the aim direction it is. */
Tgt_0022B660* ChooseAutoTarget(Tgt_0022B660* self, Tgt_0022B660* cur)
{
    WList& wl = g_Hud->S()->objs;
    WIt2_0022B660 it = WBegin_0022B660(wl);
    WIt2_0022B660 end = WEnd_0022B660(wl);
    V4_0022B660 dir = self->GetDir();
    V4_0022B660 org;
    Mtx3_0022B660 cm = self->GetViewMtx();
    QCp(&org, &dir);
    Tgt_0022B660* best = 0;
    Item* item = cWeapon_GetWeaponEntry(self->inv);
    if (!item || item->kind == 1 || item->kind == 3 || item->kind == 4 || item->kind == 10)
        return 0;
    float bestSq = (float)(item ? item->x3C * item->x3C : 0);
    for (; it != end; it++) {
        Tgt_0022B660* t = HGet_0022B660(&*it);
        if (!t) continue;
        if (!t->Targetable()) continue;
        if (t == self || !cGOBJ_Enemy(self, t)) continue;
        if (t->Kind() != 2) continue;
        if (Vis(self, t)) continue;
        V4_0022B660 pos = t->GetPos(-1);
        V4_0022B660 diff = Sub_0022B660(pos, dir);
        V4_0022B660 hd;
        V4_0022B660 tdir = t->GetDir();
        GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(&cm, &tdir, &hd);
        float aim = SqrtZ(Sq(hd.u.f.x) + Sq(hd.u.f.z));
        aim = 1.0f - aim / 3.1415927f;
        if (t == cur) aim += D_0048AC54;
        if (aim <= D_0048AC4C) continue;
        float dsq = LenSq_0022B660(&diff);
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
#undef details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2 /* merge_units */
#undef cLList_cCAMERA_GOBJPtr_Front /* merge_units */
#undef cGOBJ_Enemy /* merge_units */
#undef GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP /* merge_units */
#undef cGobjController_GetTarget /* merge_units */
#undef details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4 /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_tail /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP /* merge_units */
#undef cTargetManager_IsLosBlocked /* merge_units */
#undef std_list_imp_cSafePtr_cGOBJ_remove_if /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_insert /* merge_units */
static inline void merge_flush_func_0022B660(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022B660 */
