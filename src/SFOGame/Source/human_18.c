/*
 * SFOGame/Source/human: 6 files, 00188070-00188760
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00188070 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cAIUnconsciousMsg_dtor, D_004DCC30, D_004DCD70, cMessage_dtor)
static inline void merge_flush_func_00188070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00188070 */

/* merge_units: begin func_001880E0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cDamageMsg_dtor, D_004E08A0, cMessage_dtor)
static inline void merge_flush_func_001880E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001880E0 */

/* merge_units: begin func_00188140 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#pragma always_inline on
#pragma inline_depth(8)
static inline void RQ(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void RQn(void* d, const void* s) { __int128 t; __asm__("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void RQ4(void* d, const void* s) { __int128 a, b; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b) : "r"(d), "r"(s) : "memory"); }
static inline void RQ4X(void* d, const void* s) { __int128 b, a; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; RQn(d, &o); }
    V& operator=(const V& o) { V* d = this; RQ(d, &o); return *this; }
    inline V(const V& a, const V& b, int);
    V(const V& v, long) { V* d = this; RQ(d, &v); }
    V(const V& v, short) { V* d = this; RQ(d, &v); }
    V& SetW(float f) { w = f; return *this; }
    V& NormalizeN() {
        __asm__("lqc2 vf1, 0x0(%0); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(%0)" : : "r"(this) : "memory");
        return *this;
    }
    V& Normalize() {
        __asm__ volatile("lqc2 vf1, 0x0(%0); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(%0)" : : "r"(this) : "memory");
        return *this;
    }
    V operator-() const { V r; __asm__ volatile("lqc2 vf1, 0x0(%1); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(&r), "r"(this) : "memory"); return r; }
} __attribute__((aligned(16)));
static inline void CrossTo(V& r, const V& a, const V& b) {
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0w; sqc2 vf3, 0x0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
}
static inline V Cross1(const V& a, const V& b) { V r; CrossTo(r, a, b); return r; }
static inline V Cross(const V& a, const V& b) { return Cross1(a, b); }
static inline const V* CrossP(const V& a, const V& b) { V r; CrossTo(r, a, b); return &r; }
static inline const V* CrossP2(const V& a, const V& b) { return CrossP(a, b); }
inline V::V(const V& a, const V& b, int) { const V* r = CrossP2(a, b); V* d = this; RQn(d, r); }
struct Mtx {
    float r[4][4];
    Mtx() {}
    Mtx(const Mtx& o) { Mtx* d = this; RQ4(d, &o); } Mtx(const Mtx* o, char) { Mtx* d = this; RQ4X(d, o); }
    inline Mtx(const Mtx& m, int);
} __attribute__((aligned(16)));
static inline void Mul(void* d, void* a, void* b) {
    __asm__ volatile(
        "lqc2 $vf4, 0x0(%2)\n"
        "lqc2 $vf5, 0x10(%2)\n"
        "lqc2 $vf6, 0x20(%2)\n"
        "lqc2 $vf7, 0x30(%2)\n"
        "lqc2 $vf8, 0x0(%1)\n"
        "lqc2 $vf9, 0x10(%1)\n"
        "lqc2 $vf10, 0x20(%1)\n"
        "lqc2 $vf11, 0x30(%1)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x\n"
        "vmadday.xyzw $ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw $ACC, $vf4, $vf9x\n"
        "vmadday.xyzw $ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw $ACC, $vf4, $vf10x\n"
        "vmadday.xyzw $ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw $ACC, $vf4, $vf11x\n"
        "vmadday.xyzw $ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2 $vf12, 0x0(%0)\n"
        "sqc2 $vf13, 0x10(%0)\n"
        "sqc2 $vf14, 0x20(%0)\n"
        "sqc2 $vf15, 0x30(%0)\n"
        : : "r"(d), "r"(b), "r"(a) : "memory");
}
static inline void Xform(V* d, const Mtx* m, const V* v) {
    __asm__ volatile(
        "lqc2 $vf8, 0x0(%2)\n"
        "lqc2 $vf4, 0x0(%1)\n"
        "lqc2 $vf5, 0x10(%1)\n"
        "lqc2 $vf6, 0x20(%1)\n"
        "lqc2 $vf7, 0x30(%1)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x\n"
        "vmadday.xyzw $ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2 $vf12, 0x0(%0)\n"
        : : "r"(d), "r"(m), "r"(v) : "memory");
}
struct Hit {
    char pad[0x2D92];
    unsigned char b2D92;
    void Spawn(int kind, const V& d, const V& p);
};
extern "C" {
extern int WoundEffectTable[];
void SfxParticleEffect_int_cVectorR_cVectorR(int kind, V* p, const V* d);
int cMan_GetBloodEffect(int);
Mtx* cMatrix_ctor_cMatrixR(Mtx* d, const Mtx* s);
Mtx* cMatrix_InvertRotTrans(Mtx* m);
void cMatrix_SetAxes(Mtx* m, V* a, V* b, V* c);
void cMatrix_SetTranslation(Mtx* m, V* t);
}
inline void Hit::Spawn(int kind, const V& d, const V& p) { void* xx = this; SfxParticleEffect_int_cVectorR_cVectorR(kind, (V*)&p, &d); }
struct HNode {
    VPAD16(a) VPAD4(b)
    virtual void Refresh(); /* +0x58 */
    int pad4[3];
    Mtx m10;
    unsigned char b50;
};
struct HVQ { char pad[0x24]; float f24; int i28; char pad2C[0xC]; float f38; int i3C; };
struct NodeMats { int x; };
class Actor {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual V GetPos();
    VPAD4(f) VPAD2(h)
    virtual void Hurt();
    VPAD1(g)
    virtual unsigned char State(); /* +0x108 */
    char pad04[0x5C];
    Hit hit;                 /* 0x60 */
    char pad2DF3[0x2E50 - 0x2DF3];
    NodeMats nm;             /* 0x2E50 */
    char pad2E54[0x2E78 - 0x2E54];
    HNode* HNode;              /* 0x2E78 */
};
extern "C" {
void cSkeleton_GetMeshToSkeletonSpaceMatrices(NodeMats* nm, void* spr, const Mtx& m);
void cMan_BloodUpdate(Hit* h);
int cMan_BloodHit(Hit* h, HVQ* e, int d);
}
static inline Mtx* InvCopy(Mtx* b, Mtx* m) { Mtx a; return cMatrix_ctor_cMatrixR(b, cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&a, m))); }
static inline Mtx* InvCopy3(Mtx* b, Mtx* m) { return InvCopy(b, m); }
static inline Mtx* InvCopy2(Mtx* b, Mtx* m) { return InvCopy3(b, m); }
inline Mtx::Mtx(const Mtx& m, int) { InvCopy2(this, (Mtx*)&m); }

static inline V Normalized(const V& v) { V r(v); r.Normalize(); return r; }
static inline V Normalized2(const V& v) { V r(v, 0L); V* n = &r; n->Normalize(); return *n; }
static inline const Mtx& Refd(HNode* n) { if (n->b50) n->Refresh(); return n->m10; }
static inline const Mtx* RefdP(HNode* n) { if (n->b50) n->Refresh(); return &n->m10; }
static inline Mtx MulBy(Mtx t, const Mtx& inv) { Mtx* p = &t; Mul(p, (Mtx*)&inv, p); return *p; }
static inline Mtx MulByP(const Mtx* s, const Mtx& inv) { Mtx t(s, (char)0); Mtx* p = &t; Mul(p, (Mtx*)&inv, p); return *p; }
static inline Mtx MulByR(const Mtx& s, const Mtx& inv) { Mtx t(&s, (char)0); Mtx* p = &t; Mul(p, (Mtx*)&inv, p); return *p; }
static inline void NM(NodeMats* nm, void* spr, HNode* n, const Mtx& m) { cSkeleton_GetMeshToSkeletonSpaceMatrices(nm, spr, MulBy(Refd(n), Mtx(m, 0))); }
static inline void NMi(NodeMats* nm, void* spr, HNode* n, const Mtx& inv) { cSkeleton_GetMeshToSkeletonSpaceMatrices(nm, spr, MulBy(Refd(n), inv)); }
static inline Mtx RefdV(HNode* n) { if (n->b50) n->Refresh(); return n->m10; }
static inline Mtx MulByI(HNode* n, const Mtx& inv) { return MulBy(Refd(n), inv); }
static inline Mtx World(HNode* n, const Mtx& inv) { if (n->b50) n->Refresh(); Mtx* s = &n->m10; Mtx t(s, (char)0); Mtx* p = &t; Mul(p, (Mtx*)&inv, p); return *p; }
static inline bool Downed(Actor* a) { bool r; unsigned char s = a->State(); r = true; if (s != 3 && s != 2) r = false; return r; }
extern "C" int cHuman_BulletBlood(Actor* a, V* pos, V* dir, int d, HVQ* e)
{
    void* spr = (void*)0x70000000;
    Mtx m;
    V fwd(Normalized2(*dir));
    V side;
    V up;
    if (fwd.z < 0.707f) {
        V zv(0.0f, 0.0f, 1.0f, 0.0f);
        side = V(fwd, zv, 0).Normalize();
        up = Cross(side, fwd);
    } else {
        V xv(1.0f, 0.0f, 0.0f, 0.0f);
        up = V(xv, fwd, 0).Normalize();
        side = Cross(fwd, up);
    }
    const V& p = V(*pos).SetW(1.0f);
    cMatrix_SetAxes(&m, &side, &fwd, &up);
    cMatrix_SetTranslation(&m, (V*)&p);
    NodeMats* nm = &a->nm;
    cSkeleton_GetMeshToSkeletonSpaceMatrices(nm, spr, MulByI(a->HNode, Mtx(m, 0)));
    cMan_BloodUpdate(&a->hit);
    if (cMan_BloodHit(&a->hit, e, d)) {
        int flags = 0x100;
        int idx = 1;
        if (e->i28 == 0xC) { idx = 2; flags |= 0x80; }
        if (e->i28 == 0x10) { idx = 3; flags |= 0x40; }
        if (e->i28 == 4) flags |= 0x40;
        if (e->i28 == 0x14) flags |= 0x20;
        if (d > 0) {
            V lp(0.0f, e->f24, 0.0f, 1.0f);
            V at;
            Xform(&lp, &m, &lp);
            Hit* h = &a->hit;
            at = lp;
            h->Spawn(WoundEffectTable[idx], -fwd, at);
            if (d == 2 || (e->i3C < 0xC && e->i28 < 0xC)) {
                V lp2(0.0f, e->f38, 0.0f, 1.0f);
                Xform(&lp2, &m, &lp2);
                Hit* h2 = &a->hit;
                at = lp2;
                h2->Spawn(((int (*)(int))cMan_GetBloodEffect)(0), fwd, at);
                if (!Downed(a)) {
                    Hit* h = &a->hit;
                    if (!((unsigned char*)a)[0x2DF2]) h->b2D92 = 1;
                }
            }
        }
        return flags;
    }
    return 0;
}
static inline void merge_flush_func_00188140(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00188140 */

/* merge_units: begin func_00188760 */
#pragma push /* merge_units */
/* Return entry `index` of a global int table. */
int cMan_GetBloodEffect(int index)
{
    return WoundEffectTable[index];
}
static inline void merge_flush_func_00188760(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00188760 */

/* merge_units: begin func_00188780 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cHuman_CheckBullet: resolve a bullet hit on this actor - which body region it struck (hit volumes,
   or the aimed part for a player's own target), friendly-fire/miss chance, kill stats, then the
   combat event; records the region and node code back into the hit record. */
struct V_188780 { float x, y, z, w; } __attribute__((aligned(16)));
struct Ray_188780 { char pad0[0x10]; V_188780 dir; char pad20[0x10]; V_188780 from; };
struct HV_188780 { char pad0[0x24]; float f24; char pad28[0x18]; signed char ids[8]; signed char count; char pad49[3]; float f4C; } __attribute__((aligned(16)));
struct Ctrl_188780 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsHuman(); };
struct Wpn_188780 { char pad0[0xBC]; signed char type; };
struct Actor_188780;
struct Hit_188780 {
    Actor_188780* src;      /* 0x0 */
    Ray_188780* ray;        /* 0x4 */
    Actor_188780* tgt;      /* 0x8 */
    char padC;
    unsigned char b0D;      /* 0xD */
    char padE[2];
    int part;               /* 0x10 */
    char pad14[4];
    Wpn_188780* wpn;        /* 0x18 */
    char pad1C[4];
    unsigned char b20;      /* 0x20 */
    char pad21[3];
    int armor;              /* 0x24 */
    float f28;              /* 0x28 */
    unsigned char b2C;      /* 0x2C */
    char pad2D[3];
    int loc;                /* 0x30 */
    float f34;              /* 0x34 */
    Actor_188780* victim;   /* 0x38 */
    int node;               /* 0x3C */
    float dmg;              /* 0x40 */
};
struct Actor_188780 {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD4(d) VPAD2(e)
    virtual int HandleCombatEvent(float dmg, Actor_188780* src, int loc, int type, int* armor, int flag, V_188780* hitPos);
    VPAD1(f)
    virtual unsigned char Stance();
    char pad4[0x10];
    unsigned char alive;    /* 0x14 */
    char pad15[0x58 - 0x15];
    Ctrl_188780* ctrl;      /* 0x58 */
    char pad5C[0x33A0 - 0x5C];
    int armorHP;            /* 0x33A0 */
    unsigned char dead;     /* 0x33A4 */
};
extern "C" {
extern float D_0048A2B8[];
extern signed char ActorNodeCodeTable[];
extern char g_Game[];
int Libc_Rand(void);
Actor_188780* cGobjController_GetTarget(Ctrl_188780* c);
void* cGameSystem_GetAgentData(void* a, int b);
void cAgentData_AddScore(void* a, int b, int c);
#if 0 /* merge_units */
int cHuman_BulletBlood(Actor_188780* a, V_188780* from, V_188780* dir, int mode, HV_188780* out);
#endif /* merge_units */
#define cHuman_BulletBlood(a0, a1, a2, a3, a4) (cHuman_BulletBlood((Actor *)(a0), (V *)(a1), (V *)(a2), (a3), (HVQ *)(a4))) /* merge_units */

int cHuman_CheckBullet(Actor_188780* self, Hit_188780* h);
}

static inline bool IsHuman(Actor_188780* a) { bool r = 0; if (a->ctrl && a->ctrl->IsHuman()) r = 1; return r; }
static inline bool Dying(Actor_188780* a) { bool r; unsigned char s = a->Stance(); r = 1; if ((unsigned int)(s - 2) > 1) r = 0; return r; }
static inline int IsNullNV(int x) { return (x != 0) ^ 1; }
static inline void SetNode(Hit_188780* h, int id) { int j; for (j = 0; j < 21; j++) { if (ActorNodeCodeTable[j] == id) { h->node = j; break; } } }
/* damage types that count toward the shooter's hit stats: 0, 1, 7, 9, 10, 13 */
static inline bool Counts(unsigned char t)
{
    bool r = 0;
    if ((unsigned int)t < 14 && ((1 << t) & 0x2683))
        r = 1;
    return r;
}

int cHuman_CheckBullet(Actor_188780* self, Hit_188780* h)
{
    HV_188780 hv;
    bool miss;
    int part;
    bool a;
    /* loc/type/mode are int (tested as unsigned char) - the retail code assigns them with li and
       passes them to the int parameters below without re-masking */
    /* declaration order chosen for the retail register assignment */
    int type;
    int flags;
    unsigned char own;
    bool both;
    Ray_188780* ray;
    unsigned char aimed;
    int loc;
    Actor_188780* src;
    int mode;
    Ctrl_188780* sc;
    int dmg;
    int ne;
    ne = self != h->tgt;
    own = IsNullNV(ne);
    if (own)
        part = h->part;
    else
        part = -1;
    if (h->wpn)
        type = h->wpn->type;
    else
        type = 8;
    dmg = (int)h->dmg;
    ray = h->ray;
    sc = h->src ? h->src->ctrl : 0;
    mode = (unsigned char)ne;
    both = 0;
    a = 0;
    if (IsHuman(self) && sc)
        a = 1;
    if (a && sc->IsHuman())
        both = 1;
    if (!(unsigned short)dmg || self->dead || both || (unsigned char)type == 7)
        mode = 0;
    else if (self->armorHP <= 0)
        mode = 2;
    /* an NPC shooting at something other than its aim target misses by chance (HitInnocentNpcChance) */
    miss = 0;
    if (sc && !sc->IsHuman() && cGobjController_GetTarget(sc) != self) {
        if ((float)Libc_Rand() / 2147483648.0f > D_0048A2B8[0])
            miss = 1;
    }
    hv.f4C = h->f28;
    if (miss)
        flags = 0;
    else
        flags = cHuman_BulletBlood(self, &ray->from, &ray->dir, mode, &hv);
    loc = 0;
    if (flags & 0x40)
        loc = 2;
    else if (flags & 0x20)
        loc = 4;
    else if (flags & 0x80)
        loc = 3;
    else if (flags)
        loc = 1;
    aimed = sc && cGobjController_GetTarget(sc) == self && own;
    if (aimed) {
        int k = part & 3;
        if (k == 0)
            loc = 2;
        else if (k == 3)
            loc = 3;
        else
            loc = 1;
    }
    src = h->src;
    if ((unsigned char)loc && src && src->alive && !h->b20) {
        if (IsHuman(self)) {
            if (both) {
                dmg = 0;
                if ((unsigned char)type == 7)
                    type = 0;
            }
            if (!aimed)
                loc = 3;
        }
        {
            int t = (unsigned char)type;
            bool cnt = Counts(t);
            if (!Dying(self) && cnt) {
                if (IsHuman(src) && src->alive && !both && h->b2C) {
                    cAgentData_AddScore(cGameSystem_GetAgentData(g_Game, -1), 10, 1);
                    if (h->b0D)
                        cAgentData_AddScore(cGameSystem_GetAgentData(g_Game, -1), 12, 1);
                    if (t == 7 && (unsigned char)loc != 2)
                        cAgentData_AddScore(cGameSystem_GetAgentData(g_Game, -1), 6, 1);
                }
            }
        }
        self->HandleCombatEvent((float)dmg, src, loc, type, &h->armor, 0, 0);
    }
    if (flags && h->armor <= 0) {
        int i;
        h->node = -1;
        h->f34 = hv.f24;
        h->loc = (unsigned char)loc;
        h->victim = self;
        for (i = hv.count - 1; i >= 0; i--) {
            if (hv.ids[i] >= 0) {
                SetNode(h, hv.ids[i]);
                break;
            }
        }
    }
    return loc;
}
#undef cHuman_BulletBlood /* merge_units */
static inline void merge_flush_func_00188780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00188780 */

/* merge_units: begin func_00188D30 */
#pragma push /* merge_units */
const float D_0048A2A8[2] = { 0.3f, 0.0f };
const float D_0048A2B0[2] = { 0.5f, 0.0f };
float cHuman_GetSubTargetAimAdjust(void* self, int n)
{
    int k = n & 3;
    if (k == 0) return (*(float*)D_0048A2A8);
    if (k == 1 || k == 2) return (*(float*)D_0048A2B0);
    return 1.0f;
}
static inline void merge_flush_func_00188D30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00188D30 */
