#pragma opt_rebuildconditionals off
#pragma cplusplus on

#include "types.h"

typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;
typedef struct Child { int x, y, w, h; char f10; char pad11[0x20 - 0x11]; int f20; } Child;
typedef struct Item { char str[0xC]; int flags; char f10; char pad11[3]; int f14; char pad18[8]; char f20[0x10]; } Item;
typedef struct Self { char pad[0x90]; Child* child; int f94; char f98; char pad99[0xA0 - 0x99]; char fA0[0x10]; } Self;

extern "C" {
extern char D_005381F0[];
extern int D_00538C64;
extern char D_00538C68;
void func_00423600(Self* self, int a, int b, float* r);
Item* func_00426590(Self* self, int a, int b);
void func_003D0810(Child* c, void* p);
char* String_CStr(void* s);
void func_003D08B0(Child* c, char* text);
void func_003CFAB0(Child* c);
}

static inline void SetPos(Child* c, int x, int y) { c->x = x; c->y = y; }
static inline void SetSize(Child* c, int w, int h) { c->w = w; c->h = h; }
static inline void SetF10(Child* c, char v) { c->f10 = v; }
static inline void SetF20(Child* c, int v) { c->f20 = v; }
static inline Mtx* MtxAt(int i) { return &((Render*)D_005381F0)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

extern "C" void func_00425EA0(Self* self, int a, int b, float* r)
{
    Item* it;
    func_00423600(self, a, b, r);
    if (self->child == 0) return;
    it = func_00426590(self, a, b);
    if (it == 0) return;
    if (it->flags & 1) SetF10(self->child, it->f10);
    if (it->flags & 2) SetF20(self->child, it->f14);
    if (it->flags & 4) func_003D0810(self->child, it->f20);
    { int i = D_00538C64; GQR(MtxAt(i + 1), MtxAt(i)); }
    D_00538C64++;
    UM(MtxAt(D_00538C64));
    D_00538C68 = 1;
    SetPos(self->child, (int)r[0], (int)r[1]);
    SetSize(self->child, (int)r[2], (int)r[3]);
    func_003D08B0(self->child, String_CStr(it));
    func_003CFAB0(self->child);
    D_00538C64--;
    D_00538C68 = 1;
    if (it->flags & 1) SetF10(self->child, self->f98);
    if (it->flags & 2) SetF20(self->child, self->f94);
    if (it->flags & 4) func_003D0810(self->child, self->fA0);
}

