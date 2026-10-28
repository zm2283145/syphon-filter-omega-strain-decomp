#pragma cplusplus on
#include "types.h"
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