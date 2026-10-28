#include "types.h"
#include "vslot_pad.h"

#pragma cplusplus on
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { QC(this, &o); }
} __attribute__((aligned(16)));
static inline V Sub(const V& a0, const V& b0) {
    V r;
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(&r), "r"(&a0), "r"(&b0) : "memory");
    return r;
}
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float Len(V* p) {
    float len;
    len = 0.0f;
    { __asm__ volatile("lqc2 vf1, 0x0(%1); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni %0, vf4" : "=r"(len) : "r"(p) : "memory"); }
    return len;
}
struct E { float x, y, z; unsigned int pad; } __attribute__((aligned(16)));
class Ctrl {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int Test();
};
struct Mv { char pad[0x310]; V vel; };
class Actor {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual V GetPos();
    VPAD4(f) VPAD2(h)
    virtual void Hurt();
    VPAD1(g)
    virtual unsigned char State();
    char pad04[0x8];
    int id;
    char pad10[0x3C];
    int w4C;
    char pad50[8];
    Ctrl* ctrl;
    char pad5C[0x3310 - 0x5C];
    Mv* mv;
};
struct Hnd { Actor* p; int id; };
static inline bool IdEq(Actor* p, Hnd* h) { return p->id == h->id; }
static inline Actor* HGet(Hnd* h) {
    bool ok = !h->p || IdEq(h->p, h);
    return ok ? h->p : 0;
}
struct WNode { WNode* prev; WNode* next; Hnd h; };
struct WIt2 {
    WNode* volatile n;
    WIt2() {}
    WIt2(WNode* a) { n = a; }
    Hnd& operator*() { return n->h; }
    WIt2& operator++() { n = n->next; return *this; }
    bool operator!=(const WIt2& o) const { return n != o.n; }
};
struct WList { int x0; int list; int x8; };
struct Self { char pad[0x88]; Actor* actor; };
extern "C" {
extern WList D_004F78DC;
extern int g_HumanActorClassKey[];
extern float D_00489D80;
extern float D_00489D88;
extern float D_00489D90;
extern float D_00489D98;
extern signed char D_004E1D88;
extern V D_004E1D90;
WNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(void* l);
int cHuman_IsInvulnerable(Actor* a);
void GetTargetAngle_cHumanP_cGOBJP_cEulerAngleTP(Actor* a, Actor* b, E* out);
}
static inline WIt2 WBegin(WList& l) { WIt2 r(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(&l.list)->next); return r; }
static inline WIt2 WEnd(WList& l) { WIt2 r(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(&l.list)); return r; }
static inline int Team() { int* p = g_HumanActorClassKey; return *p; }
static inline bool CtrlBusy(Actor* a) { bool r = false; if (a->ctrl && a->ctrl->Test()) r = true; return r; }
static inline bool Downed(Actor* a) { bool r; unsigned char s = a->State(); r = true; if (s != 3 && s != 2) r = false; return r; }
static inline const V& Zero()
{
    if (!D_004E1D88) {
        D_004E1D90.x = 0.0f;
        D_004E1D88 = 1;
        D_004E1D90.y = 0.0f;
        D_004E1D90.z = 0.0f;
        D_004E1D90.w = 0.0f;
    }
    return D_004E1D90;
}
static inline const V& Vel(Actor* a) { return *(a->mv ? &a->mv->vel : &Zero()); }
static inline float Sq(float x) { return x * x; }

extern "C" Actor* cWeapon_GetStabTarget(Self* self, unsigned char* isSlash)
{
    WList& gobjs = D_004F78DC;
    WIt2 g = WBegin(gobjs);
    WIt2 end = WEnd(gobjs);
    V mLoc = self->actor->GetPos();
    float bestDistSquared = Sq(D_00489D90);
    Actor* bestHuman = 0;
    for (; g != end; ++g) {
        Actor* gobj = HGet(&*g);
        if (!gobj) continue;
        if (gobj == self->actor) continue;
        if (CtrlBusy(gobj)) continue;
        if (Downed(gobj)) continue;
        if (gobj->w4C != Team()) continue;
        V loc = gobj->GetPos();
        V diff = Sub(loc, mLoc);
        float distSquared = diff.x * diff.x + Sq(diff.y);
        if (distSquared < bestDistSquared) {
            if (Abs(diff.z) < D_00489D88) {
                E dir;
                GetTargetAngle_cHumanP_cGOBJP_cEulerAngleTP(self->actor, gobj, &dir);
                if (Abs(dir.z) < D_00489D80) {
                    bestDistSquared = distSquared;
                    bestHuman = gobj;
                }
            }
        }
    }
    *isSlash = 0;
    if (bestHuman && !cHuman_IsInvulnerable(bestHuman)) {
        E dir;
        GetTargetAngle_cHumanP_cGOBJP_cEulerAngleTP(bestHuman, self->actor, &dir);
        if (!(Abs(dir.z) <= D_00489D98)) {
            const V* src = bestHuman->mv ? &bestHuman->mv->vel : &Zero(); V velVec; V* d4 = &velVec; __int128 t4 = *(__int128*)src; *(__int128*)d4 = t4;
            float vel = Len(&velVec);
            if (vel < 1.0f)
                *isSlash = 1;
        }
    }
    return bestHuman;
}
