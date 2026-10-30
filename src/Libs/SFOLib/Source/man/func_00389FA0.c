#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#pragma bool on
#define PA A0
#define CA A0
#define VA A0
#include "types.h"
static inline void RQ(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { const V* s = &o; void* xx = this; RQ(this, s); }
    void A0(const V& o) { const V* s = &o; void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(s) : "memory"); }
    void A1(const V& o) { void* xx = this; RQ(this, &o); }
    void A2(const V& o) { RQ(this, &o); }
    void A3(const V& o) { V* d = this; RQ(d, &o); }
    void A4(const V& o) { const V* s = &o; RQ(this, s); }
    void A5(const V& o) { void* xx = this; const V* s = &o; RQ(this, s); }
    V& operator=(const V& o) { const V* s = &o; void* xx = this; RQ(this, s); return *this; }
    V& operator+=(const V& o) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(this), "r"(&o) : "memory"); return *this; }
    int IsZero() const { const V* me = this;int r = 0;int f;int k; asm { .set noreorder
            lqc2 vf1, 0(this)
            vaddx.xyz vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xE
            vnop
            vnop
            vnop
            vnop
            cfc2.ni f, vi17
            bne k, f, done
            nop
            ori r, zero, 1
        nop
        done:
            .set reorder
        }
        return (unsigned char)r;
    }
} __attribute__((aligned(16)));
static inline int VZ(const V* v) { int k;int f;int r = 0; asm { .set noreorder
            lqc2 vf1, 0(v)
            vaddx.xyz vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xE
            vnop
            vnop
            vnop
            vnop
            cfc2.ni f, vi17
            bne k, f, done
            nop
            ori r, zero, 1
        nop
            .set reorder
        }
        done:
        return (unsigned char)r;
}
static inline int VZr(const V& c) { const V* p = &c; return VZ(&c); }
static inline int VZv(V c) { return VZ(&c); }
static inline void MCopy(void* d, const void* s) { __int128 q1, q0; __asm__ volatile("lq %0, 0x0(%3)\n lq %1, 0x10(%3)\n sq %0, 0x0(%2)\n lq %0, 0x20(%3)\n sq %1, 0x10(%2)\n lq %1, 0x30(%3)\n sq %0, 0x20(%2)\n sq %1, 0x30(%2)" : "=&r"(q0), "=&r"(q1) : "r"(d), "r"(s) : "memory"); }
struct M { float m[4][4]; M() {} M(const M& o) { M* me = this; const M* s = &o; __int128 q0, q1; __asm__ volatile("lq %0, 0x0(%3)\n lq %1, 0x10(%3)\n sq %0, 0x0(%2)\n lq %0, 0x20(%3)\n sq %1, 0x10(%2)\n lq %1, 0x30(%3)\n sq %0, 0x20(%2)\n sq %1, 0x30(%2)" : "=&r"(q0), "=&r"(q1) : "r"(me), "r"(s) : "memory"); } V& Pos() { return *(V*)m[3]; } M& operator=(const M& o) { M* me = this; const M* s = &o; __int128 q0, q1; __asm__ volatile("lq %0, 0x0(%3)\n lq %1, 0x10(%3)\n sq %0, 0x0(%2)\n lq %0, 0x20(%3)\n sq %1, 0x10(%2)\n lq %1, 0x30(%3)\n sq %0, 0x20(%2)\n sq %1, 0x30(%2)" : "=&r"(q0), "=&r"(q1) : "r"(me), "r"(s) : "memory"); return *this; } } __attribute__((aligned(16)));
struct Box { __int128 mn; __int128 mx; Box() {} inline Box(const Box& o);
    Box& operator=(const Box& o) { __int128 q0, q1; __asm__ volatile("lq %0, 0x0(%3)\n lq %1, 0x10(%3)\n sq %0, 0x0(%2)\n sq %1, 0x10(%2)" : "=&r"(q0), "=r"(q1) : "r"(this), "r"(&o) : "memory"); return *this; } };
struct Sphere { int node; unsigned char zero; char pad5[3]; float r; int wC; V c; };
struct Skel { char pad0[0x14]; unsigned char b14; char pad15[3]; char nodes[0x10]; void* xf; char pad2C[4]; Box box; };
struct Part { V pos; V q; V vel; float fall; float floor; char pad38[6]; unsigned short age; };
struct Gz { char pad0[0xC]; int serial; };
struct Actor {
    Box box;
    char pad20[0x2410 - 0x20];
    char* hand[2];
    char pad2418[0x2450 - 0x2418];
    unsigned char handNode[2];
    char pad2452[0x2780 - 0x2452];
    V prev[2];
    V cur[2];
    Part parts[16];
    unsigned char b2BC0;
    unsigned char b2BC1;
    char pad2BC2[0x2BDA - 0x2BC2];
    signed char b2BDA;
    char pad2BDB[0x2C04 - 0x2BDB];
    Skel* skel;
    int timer;
    char pad2C0C[0x2C12 - 0x2C0C];
    unsigned char count;
    char pad2C13[0x2D68 - 0x2C13];
    void* lpd;
    char pad2D6C[4];
    Gz* gaze;
    int gazeSerial;
    char pad2D78[0x2D8C - 0x2D78];
    float f2D8C;
    unsigned char b2D90;
    unsigned char b2D91;
};
struct Box;
extern "C" {
void cBox_ctor_cBoxR(Box* d, const Box* s);
extern int g_VideoFrameCounter;
extern float D_00493348;
extern float D_00493350;
V* cVector_ctor_cVectorR(V* d, const V* s);
V* cVector_SetW(V* v, float w);
int cSkeletonBBoxContribution_BoneIndex(Sphere* s);
void* cArray_cBone_opIndex_int(void* nodes, int i);
M* cBone_GetMatrix(void* n);
void cSkeletonBBoxContribution_ContributeToBBox(Sphere* s, Box* b, M* m);
void cMan_Bloodlost(Actor* a);
void cMan_LipSyncUpdate(Actor* a);
void cMan_UpdateMorphs(Actor* a);
void cMan_EyeTracking(Actor* a);
void* cBone_Xform(void* n);
M* cXform_GetMatrix(void* t);
void cMatrix_GetTransformed(M* out, M* a, M* b);
void cMatrix_ctor_cMatrixR(M* d, M* s);
}
inline Box::Box(const Box& o) { cBox_ctor_cBoxR(this, &o); }
static inline M* QuatToMtx(M* a, const V& qq) { M* aa = a; const V* b = &qq;
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
    return a;
}
static inline V Scale(const V& v0, float k) {
    __int128 z = 0; V r; V* p = &r; const V* v = &v0; 
    asm {
        .set noreorder
        lqc2 vf1, 0x0(v)
        mfc1 z, k
        qmtc2.ni z, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(p)
        .set reorder
    }
    return r;
}
static inline void Add(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline void MulM(V* v, M* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
static inline V XformPt(const V& v, M& m) { V p(v); MulM(&p, &m); return p; }
static inline Box Bounds(Skel* sk, Sphere* s) {
    if (sk->b14) {
        Box b(sk->box);
        cSkeletonBBoxContribution_ContributeToBBox(s, &b, cBone_GetMatrix(cArray_cBone_opIndex_int(sk->nodes, cSkeletonBBoxContribution_BoneIndex(s))));
        return b;
    }
    return sk->box;
}
static inline Box Bounds2(Skel* sk, Sphere* s) { return Bounds(sk, s); }
static inline V Hom(const V* c) { V t; return *cVector_SetW(cVector_ctor_cVectorR(&t, c), 1.0f); }
static inline void InitSphere(Sphere* s, int node, V c) {  s->node = node;
    s->zero = VZr(c);
    s->r = 0.3f;
    s->c.A1(Hom(&c));
}
static inline M Q2M(const V& q) { M m; QuatToMtx(&m, q); return m; }
static inline bool Same(Actor* a) { return a->gaze->serial == a->gazeSerial; }
static inline int GazeValid(Actor* a) { return !a->gaze || Same(a); }
static inline Gz* Gaze(Actor* a) { if ((unsigned char)GazeValid(a)) return a->gaze; return 0; }
static inline void Tick(unsigned char& c) {
    if (c) {
        c++;
        if (c > 8) c = 0;
    }
}
static inline void UpdateHand(Actor* a, int i) {
    if (a->hand[i]) {
        Skel* sk = a->skel;
        M m;
        int n = a->handNode[i];
        if (sk->b14)
            cMatrix_GetTransformed(&m, cXform_GetMatrix(cBone_Xform(cArray_cBone_opIndex_int(sk->nodes, n))), cXform_GetMatrix(sk->xf));
        else
            cMatrix_ctor_cMatrixR(&m, cXform_GetMatrix(sk->xf));
        a->prev[i] = a->cur[i];
        a->cur[i] = m.Pos();
    }
}
#define OR ||
static inline float Z0() { return 0.0f; }
static inline bool EQB(float z, float f) { return f == z; }
static inline bool NEB(float z, float f) { return !(f == z); }
static inline bool EQB2(float f) { return f == Z0(); }
static const float ZR = 0.0f;
extern "C" void cMan_ManNextFrame(Actor* a, float dt)
{
    int paused = g_VideoFrameCounter & 1;
    if (a->hand[0]) {
        Sphere s;
        InitSphere(&s, a->handNode[0], *(V*)(a->hand[0] + 0x130));
        Skel* sk = a->skel;
        a->box = Bounds2(sk, &s);
    } else {
        a->box = a->skel->box;
    }
    if (a->timer > 0) {
        if (a->b2BDA) {
            if (!paused) {
                a->timer = a->timer + 1;
                if (a->timer >= 90) {
                    a->timer = -1;
                    cMan_Bloodlost(a);
                }
            }
        } else {
            cMan_Bloodlost(a);
            a->timer = -1;
        }
    }
    a->b2BC1 = a->b2BC0;
    if (a->lpd) cMan_LipSyncUpdate(a);
    if (a->b2BDA) {
        cMan_UpdateMorphs(a);
        if (Gaze(a) OR !(a->f2D8C == Z0())) cMan_EyeTracking(a);
    }
    Tick(a->b2D90);
    Tick(a->b2D91);
    if (a->hand[0]) {
        Skel* sk = a->skel;
        M m0;
        int n = a->handNode[0];
        if (sk->b14)
            cMatrix_GetTransformed(&m0, cXform_GetMatrix(cBone_Xform(cArray_cBone_opIndex_int(sk->nodes, n))), cXform_GetMatrix(sk->xf));
        else
            cMatrix_ctor_cMatrixR(&m0, cXform_GetMatrix(sk->xf));
        a->prev[0].PA(a->cur[0]);
        a->cur[0].CA(m0.Pos());
    }
    if (a->hand[1]) {
        Skel* sk = a->skel;
        M m1;
        int n = a->handNode[1];
        if (sk->b14)
            cMatrix_GetTransformed(&m1, cXform_GetMatrix(cBone_Xform(cArray_cBone_opIndex_int(sk->nodes, n))), cXform_GetMatrix(sk->xf));
        else
            cMatrix_ctor_cMatrixR(&m1, cXform_GetMatrix(sk->xf));
        a->prev[1].PA(a->cur[1]);
        a->cur[1].CA(m1.Pos());
    }
    {
        int n = 0;
        float k = dt / 0.033333335f;
        float damp = 1.0f - (1.0f - D_00493348) * k;
        M rm;
        int i;
        for (i = 0; i < 16; i++) {
            if (a->parts[i].age) {
                M* pr; M* pt = &M(); pr = &rm; *pr = *QuatToMtx(pt, a->parts[i].q);
                V nv = Scale(a->parts[i].vel, damp);
                V d = XformPt(nv, rm); V* pn = &nv; 
                a->parts[i].vel.VA(*pn);
                Add(&a->parts[i].pos, &a->parts[i].pos, &d);
                a->parts[i].pos.z -= a->parts[i].fall;
                a->parts[i].fall += D_00493350 * k;
                n++;
                a->parts[i].age++;
                if (a->parts[i].age > 60000) {
                    a->parts[i].age = 0;
                    n--;
                }
                if (a->parts[i].pos.z < a->parts[i].floor) {
                    a->parts[i].age = 0;
                    n--;
                }
            }
        }
        a->count = n;
    }
}



















