#pragma opt_rebuildconditionals off
#pragma cplusplus on

#include "types.h"

typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;
typedef struct Child { int x, y, w, h; } Child;
typedef struct Self {
    char pad0[0x14];
    unsigned short flags;
    char pad16[0x34 - 0x16];
    float x, y, w, h;
    char pad44[0x60 - 0x44];
    float color[4];
    char pad70[0x78 - 0x70];
    Child* child;
} Self;

extern "C" {
extern char D_005381F0[];
extern int D_00538C64;
extern char D_00538C68;
void func_0041E470(Self* self);
void func_003D0810(Child* c, float* color);
void func_003CFAB0(Child* c);
}

static inline void SetPos(Child* c, int x, int y) { c->x = x; c->y = y; }
static inline void SetSize(Child* c, int w, int h) { c->w = w; c->h = h; }
static inline Mtx* MtxAt(int i) { return &((Render*)D_005381F0)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

extern "C" void func_0041C150(Self* self)
{
    float c[4];
    Mtx saved;
    func_0041E470(self);
    if (self->child == 0) return;
    c[0] = self->color[0];
    c[1] = self->color[1];
    c[2] = self->color[2];
    c[3] = self->color[3];
    if (!(self->flags & 4)) {
        c[0] *= 0.5f;
        c[1] *= 0.5f;
        c[2] *= 0.5f;
    }
    func_003D0810(self->child, c);
    { Mtx* s = MtxAt(D_00538C64); Mtx* d = &saved; GQR(d, s); }
    UM(MtxAt(D_00538C64));
    D_00538C68 = 1;
    SetPos(self->child, (int)self->x, (int)self->y);
    SetSize(self->child, (int)self->w, (int)self->h);
    func_003CFAB0(self->child);
    GQR(MtxAt(D_00538C64), &saved);
    D_00538C68 = 1;
}
