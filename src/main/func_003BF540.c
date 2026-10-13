#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq quad copies as GCC-style volatile asm; the unused xx keeps retail's dead addiu; local decl order picks the copy registers */
struct V {
    float x, y, z, w;
    V() {}
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct CQ {
    signed char b0; char pad1[0xF];
    V v10; char pad20[0x20];
    V v40; char pad50[0x20];
    V v70; char pad80[0x10];
    V v90;
    float fA0; char padA4[0xC];
    char boxB0[0x20];
    int xD0; float fD4; float fD8; char padDC[4];
    V vE0; char padF0[0x10];
    float f100, f104, f108, f10C;
    unsigned char b110; char pad111[3]; float f114; unsigned char b118; unsigned char b119;
};
extern "C" {
extern signed char D_004E1D88;
extern V D_004E1D90;
extern void* D_00542D00;
void Vec4_Copy(V* d, const V* s);
int Vec4_IsZero(V* v);
void Vec4_NormalizeXYZ_132060(V* out, V* v);
V* Vec4_GetZero(void);
V* Vec4_Assign(V* d, V* s);
float Vec4_Dot3(V* a, V* b);
void Mtx_Multiply4b(void* b);
void Box_ExtendXYZ(void* b, V* v);
void Vec4_Add(V* out, V* a, V* b);
void Bounds_ExpandByRadius(void* b, float r);
void List_Clear(void* l);
}
static inline const V& Zero()
{
    if (!D_004E1D88) {
        D_004E1D88 = 1;
        D_004E1D90.x = 0.0f;
        D_004E1D90.y = 0.0f;
        D_004E1D90.z = 0.0f;
        D_004E1D90.w = 0.0f;
    }
    return D_004E1D90;
}
extern "C" void ColQuery_InitBase(CQ* q, int a1, V* org, V* dir, unsigned char k, float r, float f0, float f1, float f2, float f3)
{
    q->xD0 = a1;
    q->fD4 = r;
    q->fD8 = r * r;
    { void* d = &q->vE0; __int128 t; const void* s = org; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    Vec4_Copy(&q->v70, dir);
    {
        V a, b;
        Vec4_Copy(&q->v90, !(Vec4_IsZero(&q->v70) != 0) ? (Vec4_NormalizeXYZ_132060(&a, dir), &a) : Vec4_Assign(&b, Vec4_GetZero()));
    }
    q->fA0 = Vec4_Dot3(dir, dir);
    q->f100 = f0;
    q->f104 = f1;
    q->f108 = f2;
    q->f10C = f3;
    q->b0 = 0;
    q->v10 = Zero();
    q->v40 = Zero();
    q->b110 = 0;
    q->f114 = 1.0f;
    q->b118 = 1;
    q->b119 = k;
    Mtx_Multiply4b(q->boxB0);
    Box_ExtendXYZ(q->boxB0, &q->vE0);
    {
        V t;
        Vec4_Add(&t, &q->vE0, &q->v70);
        Box_ExtendXYZ(q->boxB0, &t);
    }
    Bounds_ExpandByRadius(q->boxB0, q->fD4);
    List_Clear(D_00542D00);
}


