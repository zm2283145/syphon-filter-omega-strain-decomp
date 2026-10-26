#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"

/* Weapon_MuzzleFlash picks a free (or the oldest) flash slot, places it at the muzzle with
 * ShellEject_Place and gives it a random upward speed plus half the barrel direction.
 * ShellEject_Place composes the attach point with the muzzle's rest rotation (quaternion -> matrix
 * -> product -> quaternion) and moves the muzzle offset into world space.
 * VU0 math and quad copies are inline asm (C cannot express the VU0 ops); QuatToMtx / MtxToQuat are
 * the shared VU0 quaternion routines (PlayerCamera_Follow.c / GuiAgentInfo/GuiAgentDisplay_Draw.c). */
struct M;
struct V {
    float x, y, z, w;
    V() {}
    V(M m);
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { void* xx = this; __int128 q; const V* ps = &o; V* pd = this; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose */ V* pd = this; const V* ps = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(pd), "r"(ps) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    struct { float x, y, z, w; } __attribute__((aligned(16))) r[4];
    M() {}
    M(const M& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 qa, qb; M* d = this; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
} __attribute__((aligned(16)));
struct Muzzle {
    char pad0[0x170];
    V pos;          /* 0x170 */
    char pad180[0x220 - 0x180];
    V rot;          /* 0x220 */
    V off;          /* 0x230 */
    char pad240[0x404 - 0x240];
    int flashTex;   /* 0x404 */
    unsigned short flashId; /* 0x408 */
};
struct Flash {
    V pos;          /* 0x00 */
    V rot;          /* 0x10 */
    V vel;          /* 0x20 */
    float f30;
    float f34;
    int tex;        /* 0x38 */
    unsigned short id;   /* 0x3C */
    unsigned short life; /* 0x3E */
};
struct Skel {
    char pad0[0x14];
    unsigned char shot;
    char pad15[3];
    char nodes[0x10];
    void* xform;    /* 0x28 */
};
struct Weapon {
    char pad0[0x2410];
    Muzzle* muzzle[4];      /* 0x2410 */
    char pad2420[0x2780 - 0x2420];
    V base[2];              /* 0x2780 */
    V tip[2];               /* 0x27A0 */
    Flash flash[16];        /* 0x27C0 */
    char pad2BC0[0x2C04 - 0x2BC0];
    Skel* skel;             /* 0x2C04 */
};
extern "C" {
extern float D_00493340;
void ActorRender_GetAttachPoint(Weapon* w, M* out, int i);
void* Skeleton_NodeAt(void* nodes, int i);
void* func_0019F420(void* n);
M* Transform_GetUpdated(void* x);
void Actor_ShotFrameNodeWorld(M* out, M* a, M* b);
void Mtx_Copy(M* d, M* s);
int Random_Next(void);
int ShellEject_Place(Weapon* w, int i, V* pos, V* rot);
void Weapon_MuzzleFlash(Weapon* w, int i);
}
static inline void QuatToMtx(void* a_, void* b) {
    void* a = a_;
    asm {
        lqc2 vf1, 0x0(b)
        vadd.xyzw vf2, vf1, vf1
        vaddw.xyz vf3, vf0, vf0w
        vmulx.w vf8, vf0, vf0x
        vmulx.w vf9, vf0, vf0x
        vmuly.xyzw vf5, vf1, vf2y
        vmulz.xyzw vf6, vf1, vf2z
        vmulx.xyzw vf4, vf1, vf2x
        vmulx.w vf10, vf0, vf0x
        vsubay.x ACC, vf3, vf5y
        vmsubz.x vf8, vf3, vf6z
        vsubw.x vf9, vf5, vf6w
        vaddw.x vf10, vf6, vf5w
        vaddw.y vf8, vf4, vf6w
        vsubax.y ACC, vf3, vf4x
        vmsubz.y vf9, vf3, vf6z
        vsubw.y vf10, vf6, vf4w
        vsubw.z vf8, vf4, vf5w
        vaddw.z vf9, vf5, vf4w
        vsubax.z ACC, vf3, vf4x
        vmsuby.z vf10, vf3, vf5y
        sqc2 vf0, 0x30(a)
        sqc2 vf8, 0x0(a)
        sqc2 vf9, 0x10(a)
        sqc2 vf10, 0x20(a)
    }
}
static inline void MtxToQuat(void* m, void* out) {
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(m)
        lqc2 vf2, 0x10(m)
        lqc2 vf3, 0x20(m)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(out)
        .set reorder
    }
}


static inline void MM(void* d, void* a, void* b)
{
    __asm__ volatile("lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf11, 0x30(%2); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void MulV(V* d, const M* m, const V* v) { __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(d), "r"(m), "r"(v) : "memory"); }
static inline void AddV(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void SubV(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
/* quadword copy as an MW `asm volatile` block: MW schedules it with the surrounding code, and after
 * it the compiler keeps float constants in FPRs (mtc1 zero + swc1) instead of storing them with sw,
 * which is what retail does in both functions */
static inline void QCopy(void* d, const void* s) { __int128 q; asm volatile { lq q, 0(s); sq q, 0(d) } }
static inline void Copy(V* d, const V* s) { __int128* pd = (__int128*)d; const __int128* ps = (const __int128*)s; *pd = *ps; }

static inline V Sub(const V& a, const V& b) { V r; SubV(&r, &a, &b); return r; }
static inline V Half(V v)
{
    __int128 tt = 0; /* dead: retail's paddub zero */
    V r;
    V* q;
    V* p;
    float h;
    p = &v;
    q = &r;
    h = 0.5f;
    asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 tt, h; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(q); .set reorder }
    return *q;
}
static inline void operator+=(V& a, const V& b) { AddV(&a, &a, &b); }

extern "C" void Weapon_MuzzleFlash(Weapon* w, int i)
{
    int best;
    int most;
    int j;
    Muzzle* mz = w->muzzle[i];
    if (!mz) return;
    if (!mz->flashTex) return;
    best = 0;
    most = 0;
    for (j = 0; j < 16; j++) {
        int life = w->flash[j].life;
        if (life == 0) { best = j; break; }
        if (most < life) { most = life; best = j; }
    }
    ShellEject_Place(w, i, &w->flash[best].pos, &w->flash[best].rot);
    {
        Skel* s = w->skel;
        M m;
        V up;
        V vel;
        if (s->shot) {
            M* t = Transform_GetUpdated(func_0019F420(Skeleton_NodeAt(s->nodes, 0)));
            Actor_ShotFrameNodeWorld(&m, t, Transform_GetUpdated(s->xform));
        } else {
            Mtx_Copy(&m, Transform_GetUpdated(s->xform));
        }
        QCopy(&up, &m.r[3]);
        {
            float k = (float)(Random_Next() & 0xF) * 0.002f + D_00493340;
            vel.z = k;
            vel.y = -k;
            vel.x = 0.0f;
            vel.w = 0.0f;
        }
        w->flash[best].vel = vel;
        w->flash[best].vel += Half(Sub(w->tip[i], w->base[i]));
        w->flash[best].f34 = up.z - 4.0f;
        w->flash[best].f30 = 0.0f;
        w->flash[best].tex = w->muzzle[i]->flashTex;
        w->flash[best].id = w->muzzle[i]->flashId;
        w->flash[best].life = 1;
    }
}

static inline void MulMM(M* d, const M* a, const M* b) { M* pd = d; const M* pb = b; const M* pa = a; MM(pd, (void*)pa, (void*)pb); }
static inline M Compose(const M& a, V* q) { M qm; M prod; QuatToMtx(&qm, q); MulMM(&prod, &a, &qm); return prod; }
inline V::V(M m) { void* xx = this; V* o = this; MtxToQuat(&m, o); }

extern "C" int ShellEject_Place(Weapon* w, int i, V* pos, V* rot)
{
    V p;
    M att;
    if (w->muzzle[i]) {
        ActorRender_GetAttachPoint(w, &att, i);
        QCopy(rot, &w->muzzle[i]->rot);
        V q(Compose(att, rot));
        QCopy(rot, &q);
        p = w->muzzle[i]->pos;
        AddV(&p, &p, &w->muzzle[i]->off);
        p.w = 1.0f;
        MulV(&p, &att, &p);
        Copy(pos, &p);
        return 1;
    }
    return 0;
}
