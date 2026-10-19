#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { __int128 q[4];
    M& operator=(const M& o) { const void* s = &o; __int128 qa; __int128 qb; void* d = this; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
};
struct Flag { int v; };
extern "C" {
void Camera_ConstructFov(void*, int*, int, float);
Flag* func_00281070(Flag*, int);
V* Vec4_GetZero(void);
void Vec4_Assign(V*, V*);
extern char D_004DCDE0[];
extern float D_004A9328;
extern M g_IdentityMatrix;
}
struct R { int a, b, c, d; };
static inline const int* Id(const R* p) {
    int t;
    const int* r;
    if (p) r = &p->d;
    else { t = -1; r = &t; }
    return r;
}
struct Flags { Flag f[3]; void Init() { Flags* t = this; func_00281070(&t->f[0], 0); func_00281070(&t->f[1], 0); func_00281070(&t->f[2], 0); } };
struct Handle { int a; int id; void Init() { id = -1; a = 0; id = *Id(0); } };
static inline V VZero() { V t; __asm__ volatile("sqc2 $vf0, 0x0(%0)" : : "r"(&t) : "memory"); return t; }
struct PlayerCamera {
    char* vtbl;
    char pad04[0x2C];
    int f30;
    char pad34[0xCF0 - 0x34];
    Flags flags;
    Handle h0;
    Handle h1;
    char padD0C[0x8];
    int fD14, fD18, fD1C, fD20;
    char padD24[0x1C];
    V vD40, vD50, vD60;
    float fD70;
    int fD74, fD78;
    char padD7C[4];
    unsigned char bD80, bD81;
    int fD84, fD88;
    char padD8C[4];
    V vD90;
    M mDA0;
};
extern "C" PlayerCamera* PlayerCamera_Construct(PlayerCamera* self, int* k, float fov)
{
    Camera_ConstructFov(self, k, 0, fov);
    self->vtbl = D_004DCDE0;
    self->flags.Init();
    self->h0.Init();
    self->h1.Init();
    self->fD14 = 0;
    self->fD18 = 0;
    self->fD1C = 0;
    self->fD20 = 0;
    Vec4_Assign(&self->vD40, Vec4_GetZero());
    Vec4_Assign(&self->vD50, Vec4_GetZero());
    Vec4_Assign(&self->vD60, Vec4_GetZero());
    self->fD70 = D_004A9328;
    self->fD74 = 0;
    self->fD78 = 0;
    self->bD80 = 0;
    self->bD81 = 0;
    self->fD84 = 0;
    self->fD88 = 0;
    self->vD90 = VZero();
    self->mDA0 = g_IdentityMatrix;
    self->f30 = 2;
    return self;
}
