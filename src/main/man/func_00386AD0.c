#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
typedef unsigned long long U64;
static inline void RQ(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void RQ4(void* d, const void* s) { __int128 a, b; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b) : "r"(d), "r"(s) : "memory"); }
static inline void RQ4s(void* d, const void* s) { __int128 a, b; __asm__ volatile("lq %0, 0x0(%2); lq %1, 0x10(%2); sq %0, 0x0(%3); lq %0, 0x20(%2); sq %1, 0x10(%3); lq %1, 0x30(%2); sq %0, 0x20(%3); sq %1, 0x30(%3)" : "=&r"(a), "=&r"(b) : "r"(s), "r"(d) : "memory"); }
static inline void QZero(void* d0, int n0) { int n = n0; void* d = d0;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(int a, int b, int c, int d) { *(int*)&w = d; *(int*)&x = a; *(int*)&y = b; *(int*)&z = c; }
    V(const V& o) { void* xx = this; RQ(this, &o); }
    V& operator=(const V& o) { void* xx = this; RQ(this, &o); return *this; }
    void Set(const V& o) { const V* q = &o; void* xx = this; RQ(this, q); }
    void Set2(const V& o) { void* xx = this; const V* q = &o; RQ(this, q); }
    V& operator*=(float s) { __int128 t = 0; V* me = this; float ss = s;  __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(this), "r"(this), "f"(s) : "memory"); return *this; }
    V& operator+=(const V& b) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(this), "r"(&b) : "memory"); return *this; }
    V operator+(const V& b) const { V r; __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%1)" : : "r"(this), "r"(&r), "r"(&b) : "memory"); return r; }
} __attribute__((aligned(16)));
struct VI { int x, y, z, w; } __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M& operator=(const M& o) { void* xx = this; RQ4(this, &o); return *this; }
    void Set(const M& o) { const M* q = &o; void* xx = this; RQ4(this, q); }
    void Scale(float f) { m[0][0] *= f; m[0][1] *= f; m[0][2] *= f; m[0][3] *= f; m[1][0] *= f; m[1][1] *= f; m[1][2] *= f; m[1][3] *= f; m[2][0] *= f; m[2][1] *= f; m[2][2] *= f; m[2][3] *= f; m[3][0] *= f; m[3][1] *= f; m[3][2] *= f; m[3][3] *= f; }
} __attribute__((aligned(16)));
struct Pkt {
    U64 tag;
    U64 gif;
    U64 d10;
    int i18; float f1C;
    U64 d20;
    int i28; float f2C;
    U64 d30;
    int i38; float f3C;
    char pad40[0x30];
    int i70;
    float f74;
    int i78;
    int i7C;
    M m;
    V v;
    int r[8];
    int q[8];
    char pal[0xA40 - 0x110];
    int z[4];
};
struct Skm {
    char pad0[0x2BD4];
    int flags;
    short h2BD8;
    signed char c2BDA;
    char pad2BDB[0x2C04 - 0x2BDB];
    void* hv;
    int i2C08;
    char pad2C0C[0x2C11 - 0x2C0C];
    signed char c2C11;
    char pad2C12[0x2D96 - 0x2C12];
    short h2D96;
};
extern "C" {
extern int D_004933F0;
extern float D_004933F8;
extern int D_00493400;
extern int D_00493408;
extern int g_VisionThermal;
extern M D_0055DEC0;
extern M D_00537E10;
extern V D_00537D80;
void cSkeleton_GetMeshToSkeletonSpaceMatrices_WithScale(void* hv, void* out, void* m);
}
extern "C" void cMan_ManDMAHeader(Skm* s, Pkt* p, void* unused, void* pal, U64 t0, int s2, int s1, int s0, int a8)
{
    p->tag = 0x100000A4;
    p->gif = 0x6CA3007501000404ULL;
    p->d10 = 0;
    p->i18 = D_004933F0;
    p->f1C = D_004933F8;
    p->d20 = 0;
    p->i28 = D_004933F0;
    p->f2C = D_004933F8;
    p->d30 = t0;
    p->i38 = D_004933F0;
    p->f3C = D_004933F8;
    float f = s->i2C08;
    if (f < 0.0f) f = 0.0f;
    if (s1) f = -1.0f;
    p->i70 = a8 + 0x47000000;
    p->f74 = f;
    p->i78 = s->c2BDA - 1;
    p->i7C = s->h2BD8 << 4;
    if (s1 || g_VisionThermal) {
        QZero(&p->m, 4);
        float g = s1;
        p->v.x = g;
        p->v.y = g;
        p->v.z = g;
        p->v.w = 128.0f;
    } else if (s->c2C11) {
        p->m = D_0055DEC0;
        p->v = V(8388608.0f, 8388608.0f, 8388608.0f, 128.0f);
    } else {
        p->m.Set(D_00537E10);
        V off;
        if (s->h2D96 == 0) {
            off = D_00537D80 + V(8388608.0f, 8388608.0f, 8388608.0f, 0.0f);
        } else {
            if (s->h2D96 >= D_00493400) s->h2D96 = D_00493400;
            float k = 1.0f - (float)s->h2D96 / (float)D_00493408;
            p->m.Scale(k);
            { const V* q = &D_00537D80; RQ(&off, q); }
            off *= k;
            off += V(0x4B000000, 0x4B000000, 0x4B000000, 0);
        }
        p->v = off;
    }
    cSkeleton_GetMeshToSkeletonSpaceMatrices_WithScale(s->hv, p->pal, pal);
    if (s1) {
        p->r[0] = 0x8000;
        p->r[1] = 0x10424000;
        p->r[2] = 4;
        p->r[3] = 0x10224000;
        p->r[4] = 0x8000;
        p->r[5] = 0x10424000;
        p->r[6] = 4;
        p->r[7] = 0x10224000;
        s->h2BD8 = 0xFF;
    } else if (s->flags & 0x80) {
        p->r[0] = 0x8000;
        p->r[1] = 0x303E4000;
        p->r[2] = 0x412;
        p->r[3] = 0x303E4000;
        p->r[4] = 0x8000;
        if (!s2) p->r[5] = 0x307E4000; else p->r[5] = 0x303E4000;
        p->r[6] = 0x412;
        p->r[7] = 0x303E4000;
    } else if (a8 < 0x80 || s0) {
        p->r[0] = 0x8000;
        p->r[1] = 0x302E4000;
        p->r[2] = 0x412;
        p->r[3] = 0x302E4000;
        p->r[4] = 0x8000;
        p->r[5] = 0x302E4000;
        p->r[6] = 0x412;
        p->r[7] = 0x302E4000;
        s->h2BD8 = 0xFF;
    } else {
        p->r[0] = 0x8000;
        p->r[1] = 0x302E4000;
        p->r[2] = 0x412;
        p->r[3] = 0x302E4000;
        p->r[4] = 0x8000;
        if (!s2) p->r[5] = 0x306E4000; else p->r[5] = 0x302E4000;
        p->r[6] = 0x412;
        p->r[7] = 0x302E4000;
        s->h2BD8 = 0xFF;
    }
    p->q[0] = 1;
    p->q[1] = 0x10000000;
    p->q[2] = 6;
    p->q[3] = 0;
    p->q[4] = 1;
    p->q[5] = 0x10000000;
    p->q[6] = 6;
    p->q[7] = 0;
    p->z[0] = 0x15000000;
    p->z[1] = 0;
    p->z[2] = 0;
    p->z[3] = 0;
}


