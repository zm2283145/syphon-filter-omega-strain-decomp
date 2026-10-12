#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; } W_45CA20;
typedef struct {
    char pad[0x6C]; W_45CA20* w; char pad70[0x20]; int f90; int f94; int f98; unsigned char f9C;
    char pad9D[3]; void* fA0; void* fA4; char padA8[0x28]; int fD0; int fD4; char padD8[4]; int fDC;
} S_45CA20;
typedef struct { char pad[0x6A8]; unsigned char busy; } G_45CA20;
extern G_45CA20* D_004FFC2C;
extern int D_00497ACC[];
extern int D_00497AEC[];
void func_0045C760(S_45CA20* o);
long long func_003698B0(void);
void func_0045C5E0(S_45CA20* o);
void func_0041E0F0(void* a, void* b, int kind, int v, int f);
void* func_004147A0(void);
void func_00414B30(void* mgr, void* w);
static inline float fmin_45CA20(float a, float b) { float r; asm { min.s r, a, b } return r; }

static inline unsigned char Has_45CA20(unsigned short* p, int m) { return (*p & m) != 0; }
static inline void Set_45CA20(unsigned short* p, int m) { *p |= m; }
void func_0045CA20(S_45CA20* o, int on)
{
    W_45CA20* w = o->w;
    unsigned short* pf;
    if (w == 0) return;
    pf = &w->flags;
    if ((unsigned char)on == Has_45CA20(pf, 4)) return;
    if (on) {
        if (D_004FFC2C->busy) return;
        Set_45CA20(pf, 2);
        o->w->flags |= 4;
        func_0045C760(o);
        o->f94 = o->f90;
        o->f98 = func_003698B0();
        o->f9C = 0;
        func_0045C5E0(o);
        if (o->fD4 == 0 && o->fD0 == 0) func_0041E0F0(o, o->fA4, 0xA, D_00497ACC[o->fDC], 0);
        o->fD4 = 1;
        o->fD0 = 2;
        func_0041E0F0(o, o->fA4, 0xB, D_00497AEC[o->fDC], 0);
        func_0041E0F0(o, o->fA0, 6, (int)"onWake", 0);
        o->w->flags |= 0x80;
        func_00414B30(func_004147A0(), o->w);
        func_0041E0F0(o->w, func_004147A0(), 0x10, 2, 0);
    } else {
        float v;
        o->fD4 = 0;
        o->fD0 = 2;
        v = 0;
        func_0041E0F0(o, o->fA4, 9, (int)&v, 0);
        v = fmin_45CA20((float)D_00497AEC[o->fDC], v);
        func_0041E0F0(o, o->fA4, 0xC, (int)v, D_00497ACC[o->fDC]);
        o->w->flags &= ~4;
        func_0041E0F0(o, o->fA0, 6, (int)"onSleep", 0);
        o->w->flags &= ~0x80;
        func_00414B30(func_004147A0(), o);
        func_0041E0F0(o->w, func_004147A0(), 0x10, 3, 0);
    }
}