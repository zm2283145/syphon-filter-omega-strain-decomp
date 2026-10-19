#pragma cplusplus on
#include "types.h"
/* LevelLight_InitPoint: point-light variant of LevelLight_CreateDirectional (LevelLight_CreateDirectional.c) */
struct V4c { float x, y, z, w; };
// VU0 macro-mode squared length (COP2), not expressible in C
static inline float LenSqP(const V4c* a) { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
// 128-bit lq/sq quadword copy
static inline void Q16(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
struct DirLight {
    unsigned char f0;
    unsigned char f1;
    char pad2[2];
    void* vt;
    char pad8[4];
    int fC;
    char pad10[8];
    float f18;
    unsigned char f1C;
    unsigned char f1D;
    unsigned char f1E;
    char pad1F;
    V4c color;
    V4c dir;
};
extern "C" {
extern char D_004D9240[];
extern char D_004D9280[];
extern signed char D_0048A150;
extern unsigned char D_00535D62;
}
extern "C" DirLight* LevelLight_InitPoint(DirLight* l, unsigned char a, V4c* c, V4c* pos, unsigned char b)
{
    V4c v;
    float x, y, z, w;
    l->vt = D_004D9280;
    l->f0 = D_0048A150;
    l->f1 = 0;
    l->vt = D_004D9240;
    l->fC = 0;
    l->f1C = 0;
    l->f1D = b;
    l->f1E = a;
    l->color = *c;
    Q16(&l->dir, pos);
    D_00535D62 = 1;
    w = c->w; z = c->z; y = c->y; x = c->x;
    v.x = x; v.y = y; v.z = z; v.w = w;
    l->f18 = 1.0f / LenSqP(&v);
    return l;
}
