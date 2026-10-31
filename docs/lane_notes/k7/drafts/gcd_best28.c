#pragma cplusplus on
#pragma inline_depth(8)
#include "vslot_pad.h"
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { Q16(this, &o); }
    V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; }
} __attribute__((aligned(16)));
static inline V operator*(const V& a, float s)
{
    V r; V* rp = &r; const V* ap = &a; int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(ap)
        mfc1 t, s
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(rp)
        .set reorder
    }
    return r;
}
static inline V operator-(const V& a, const V& b)
{
    V r; V* rp = &r; const V* ap = &a; const V* bp = &b;
    asm {
        lqc2 vf1, 0x0(ap)
        lqc2 vf2, 0x0(bp)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(rp)
    }
    return r;
}
static inline float Length(const V& v)
{
    int rv0; float ret = 0.0f; const V* a = &v;
    asm {
        lqc2 vf1, 0x0(a)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni rv0, vf4
        mtc1 rv0, ret
    }
    return ret;
}
struct M { V r[4]; };
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct cCollisionFace {
    VP v[3]; char pad30[0x10]; unsigned char b40; char pad41; unsigned char b42; char pad43[0x1D]; int i60; int i64; char pad68[0x8];
    cCollisionFace* Init() { cCollisionFace* t = this; VP* q = t->v; do { q++; } while (q != t->v + 3); t->b40 = 0; t->b42 = 0; t->i60 = 0; t->i64 = 0; return t; }
};
struct cLosResult { unsigned char mIsLosBlocked; char pad1[0xF]; V mIntersectionPoint; cCollisionFace face; int mHandle; cLosResult() { cLosResult* t = this; t->face.Init(); } } __attribute__((aligned(16)));
struct cHuman { char pad[0x3524]; int mWeapon; };
struct tBulletCollisionInfo { cHuman* attacker; M* bulMat; char pad8[0xC]; float travelDist; int wpnEntry; char pad1C[4]; unsigned char noDamage; char pad21[0xF]; int hitLocation; float hitDist; };
struct cSystem { VPAD1(a) virtual void Post(void*); };
extern "C" {
extern char D_004D9180[], g_Game[], g_LosRequestMsgClass[], g_LosCheckService[];
void cMessage_ctor_cMessageNameR(void*, void*);
void cMessage_dtor(void*, int);
cSystem* cSystemContainer_GetSystem(void*, void*);
void* func_0014D460(cHuman* a);
void* func_0014D450(void* a);
void* func_0014D410(void* a);
void* func_001AE360(void* a);
void LosProvider_SeedRegion(void* p, void* r);
int cWeapon_GetWeaponEntry(int);
void CheckBulletCollisions(tBulletCollisionInfo*);
float GetCollisionDist(cHuman* attacker, tBulletCollisionInfo* inf, int collisionMask);
}
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct cLosRequestMessage : MsgB {
    int mRequester; int mReturnHandle; cLosResult* mResult; V pos; V dir; cHuman* src; void* tgt; int mask; unsigned char b5C;
    cLosRequestMessage(cLosResult* i, const V& p, V d, cHuman* s, void* t, int m) : MsgB(g_LosRequestMsgClass) {
        vtable = D_004D9180; mRequester = 0; mReturnHandle = 0; mResult = i; V* dp = &pos; Q16(dp, &p); dir = d; src = s; tgt = t; mask = m; b5C = 0; pos.w = 1.0f; dir.w = 0.0f; }
    __declspec(weak) __declspec(MSG_DTOR) ~cLosRequestMessage() { vtable = D_004D9180; }
} __attribute__((aligned(16)));

float GetCollisionDist(cHuman* attacker, tBulletCollisionInfo* inf, int collisionMask)
{
    {
        cLosResult result;
        cLosRequestMessage msg(&result, inf->bulMat->r[3], inf->bulMat->r[1] * inf->travelDist, attacker, 0, collisionMask);
        cSystem* losManager = cSystemContainer_GetSystem(g_Game, g_LosCheckService);
        void* where = func_0014D410(func_0014D450(func_0014D460(attacker)));
        if (where) LosProvider_SeedRegion(func_001AE360(losManager), where);
        losManager->Post(&msg);
        if (result.mIsLosBlocked) {
            V& pt = result.mIntersectionPoint;
            inf->travelDist = Length(pt - inf->bulMat->r[3]);
        }
    }
    inf->attacker = attacker;
    inf->wpnEntry = cWeapon_GetWeaponEntry(attacker->mWeapon);
    inf->noDamage = 1;
    CheckBulletCollisions(inf);
    if (inf->hitLocation) inf->travelDist = inf->hitDist;
    return inf->travelDist;
}
