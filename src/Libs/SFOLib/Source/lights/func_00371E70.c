#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { void* xx = this; const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
};
struct M { float m[4][4]; } __attribute__((aligned(16)));
static inline void XformInPlace(V* v, const M* m)
{
    __asm__ volatile(
        "lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory");
}
static inline V Xform(V v, const M& m) { XformInPlace(&v, &m); return v; }
static inline void QMoveA(void* s, int n, void* d) {
    __int128 t; int nn = n; void* dd = d; void* ss = s; 
    asm {
        .set noreorder
    lp:
        lq t, 0(ss)
        addiu dd, dd, 0x10
        addi nn, nn, -1
        addiu ss, ss, 0x10
        bgtz nn, lp
        sq t, -0x10(dd)
        .set reorder
    }
}
static inline void QMoveB(void* d, int n, void* s) {
    int nn = n; __int128 t; void* ss = s; void* dd = d;
    asm {
        .set noreorder
    lp:
        lq t, 0(ss)
        addiu dd, dd, 0x10
        addi nn, nn, -1
        addiu ss, ss, 0x10
        bgtz nn, lp
        sq t, -0x10(dd)
        .set reorder
    }
}
struct LData { char pad[0x2800]; V lights[4]; V x2840[4]; };
struct LMgr {
    char pad0[0x54];
    LData* data;
    char pad58[0x2070 - 0x58];
    V x2070[4];
    float x20B0[4][4];
    V x20F0[4];
};
extern "C" {
M* cMatrix_ctor_cMatrixR(M* d, const M* s);
M* cMatrix_InvertRotTrans(M* m);
}
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
static inline M* InvCopy(M* b, M* m) { M a; return cMatrix_ctor_cMatrixR(b, cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&a, m))); }
extern "C" void cLightMan_VU1PrepareParallel(LMgr* self, M* m)
{
    V rows[4];
    if (m) {
        M b;
        InvCopy(&b, m);
        for (int i = 0; i < 4; i++) {
            rows[i] = Xform(self->data->lights[i], b);
        }
    } else {
        for (int i = 0; i < 4; i++) {
            rows[i] = self->data->lights[i];
        }
    }
    QMoveA(self->data->lights, 4, self->x2070);
    QMoveB(self->x20B0, 4, rows);
    {
        float (*t)[4] = self->x20B0;
        float f;
        f = t[0][1]; t[0][1] = t[1][0]; t[1][0] = f;
        f = t[0][2]; t[0][2] = t[2][0]; t[2][0] = f;
        f = t[1][2]; t[1][2] = t[2][1]; t[2][1] = f;
        f = t[0][3]; t[0][3] = t[3][0]; t[3][0] = f;
        f = t[1][3]; t[1][3] = t[3][1]; t[3][1] = f;
        f = t[2][3]; t[2][3] = t[3][2]; t[3][2] = f;
    }
    QMoveA(self->data->x2840, 4, self->x20F0);
    self->x20F0[0].x *= 128.0f; self->x20F0[0].y *= 128.0f; self->x20F0[0].z *= 128.0f;
    self->x20F0[1].x *= 128.0f; self->x20F0[1].y *= 128.0f; self->x20F0[1].z *= 128.0f;
    self->x20F0[2].x *= 128.0f; self->x20F0[2].y *= 128.0f; self->x20F0[2].z *= 128.0f;
    self->x20F0[3].x *= 128.0f; self->x20F0[3].y *= 128.0f; self->x20F0[3].z *= 128.0f;
}
#pragma pop