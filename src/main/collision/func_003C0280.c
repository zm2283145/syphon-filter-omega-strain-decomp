#pragma cplusplus on
#include "types.h"
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(&o), "r"(this) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    V r[4];
    M& operator=(const M& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%2); lq %1, 0x10(%2); sq %0, 0x0(%3); lq %0, 0x20(%2); sq %1, 0x10(%3); lq %1, 0x30(%2); sq %0, 0x20(%3); sq %1, 0x30(%3)" : "=&r"(qa), "=&r"(qb) : "r"(&o), "r"(this) : "memory"); return *this; }
};
static inline void SetU(V* p) { __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(p) : "memory"); }
static inline V Unit() { V l0; SetU(&l0); return l0; }
extern "C" {
extern signed char D_004E1D88;
extern V D_004E1D90;
extern M g_IdentityMatrix;
}
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
struct ColResult {
    unsigned char b0;
    V v10, v20, v30;
    V v40, v50;
    int f60, f64;
    V v70, v80, v90;
    float fA0;
    V mn;
    V mx;
    int fD0;
    float fD4, fD8;
    V vE0, vF0;
    float f100, f104, f108, f10C;
    unsigned char b110;
    float f114;
    unsigned char b118, b119, b11A;
    M m120, m160, m1A0;
};
extern "C" ColResult* ColResult_Construct(ColResult* r);
ColResult* ColResult_Construct(ColResult* r)
{
    r->b0 = 0;
    r->v10 = Zero();
    r->v20 = Zero();
    r->v30 = Zero();
    r->v40 = Unit();
    r->v50 = Unit();
    r->f60 = 0;
    r->f64 = 0;
    r->v70 = Zero();
    r->v80 = Zero();
    r->v90 = Zero();
    r->fA0 = 0.0f;
    r->mn.x = 3.4028235e38f;
    r->mn.y = 3.4028235e38f;
    r->mn.z = 3.4028235e38f;
    r->mn.w = 1.0f;
    r->mx.x = -3.4028235e38f;
    r->mx.y = -3.4028235e38f;
    r->mx.z = -3.4028235e38f;
    r->mx.w = 1.0f;
    r->fD0 = 0;
    r->fD4 = 0.0f;
    r->fD8 = 0.0f;
    r->vE0 = Unit();
    r->vF0 = Unit();
    r->f100 = 0.0f;
    r->f104 = 0.0f;
    r->f108 = 0.0f;
    r->f10C = 0.0f;
    r->b110 = 0;
    r->f114 = 1.0f;
    r->b118 = 1;
    r->b119 = 0;
    r->b11A = 0;
    r->m120 = g_IdentityMatrix;
    r->m160 = g_IdentityMatrix;
    r->m1A0 = g_IdentityMatrix;
    return r;
}
