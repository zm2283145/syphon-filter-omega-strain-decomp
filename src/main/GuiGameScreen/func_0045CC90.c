#include "types.h"
typedef struct { float x, y; } Vec2_45CC90;
typedef struct {
    char pad0[0x14];
    unsigned short flags;
    char pad16[0x34 - 0x16];
    Vec2_45CC90 pos;
    Vec2_45CC90 size;
    char pad44[0xA4 - 0x44];
    unsigned char fA4;
} W_45CC90;
typedef struct {
    char pad0[0x6C];
    W_45CC90* root;
    char pad70[0x90 - 0x70];
    int f90;
    int f94;
    int f98;
    unsigned char f9C;
    char pad9D[0xA8 - 0x9D];
    W_45CC90* items[5];
    char padBC[0xD0 - 0xBC];
    int fD0;
    int fD4;
    char fD8[4];
    int fDC;
} S_45CC90;
extern char D_004C2210[];
extern char D_004C2228[];
extern void* D_004FFD30;
extern void* D_00497AC0;
extern W_45CC90* func_0041F960(char*);
extern int sprintf(char*, const char*, ...);
extern W_45CC90* func_0041DB80(W_45CC90*, char*);
extern void func_0041EBA0(W_45CC90*, float, float);
extern void GuiWidget_AddChild(W_45CC90*, W_45CC90*);
extern void WeaponDb_LoadModel(void* m, void* a, void* b, int c, int d, int e, int f);

static inline void SetSize(W_45CC90* w, float x, float y)
{
    w->size.x = x;
    w->size.y = y;
}

void func_0045CC90(S_45CC90* self)
{
    int i;
    char buf[16];
    if (self->root == 0) {
        return;
    }
    self->f90 = -1;
    self->fDC = 0;
    self->f94 = -1;
    self->f9C = 0;
    self->f98 = 0;
    self->fD0 = 0;
    self->fD4 = 0;
    self->root->flags &= ~2;
    self->root->flags &= ~4;
    for (i = 0; i < 5; i++) {
        W_45CC90* ref;
        Vec2_45CC90 p;
        Vec2_45CC90 s;
        self->items[i] = func_0041F960(D_004C2210);
        sprintf(buf, D_004C2228, i + 1);
        ref = func_0041DB80(self->root, buf);
        p = ref->pos;
        func_0041EBA0(self->items[i], p.x, p.y);
        s = ref->size;
        SetSize(self->items[i], s.x, s.y);
        GuiWidget_AddChild(self->root, self->items[i]);
        self->items[i]->fA4 = 0;
    }
    WeaponDb_LoadModel(D_004FFD30, D_00497AC0, self->fD8, -1, 0, 0, 0);
}


