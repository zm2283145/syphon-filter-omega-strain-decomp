#include "types.h"
typedef struct { int a; unsigned char b4, b5, b6, b7; float f8, fc, f10; int f14; unsigned char b18, b19; char p1a[2]; float f1c; int f20; } C_AD10;
typedef struct { char pad[0x4C]; unsigned char b4c; char pad4d[0xB8 - 0x4D]; C_AD10 cfg; char pad3[0x401 - 0xDC]; unsigned char b401; } G_AD10;
extern C_AD10* D_004FFD2C;
extern void* D_004FFC04;
extern int func_0045A600(C_AD10*, C_AD10*);
extern void func_0045A3A0(C_AD10*, int);
extern void func_00441A10(G_AD10*);
extern void func_002C9860(void*, int);
extern void func_002C9510(void*);
extern void* Gui_GetScreenStack(void);
extern void func_0041E0F0(G_AD10*, void*, int, int, int);

void func_0029AD10(G_AD10* g, int apply) {
    int diff;
    int m;
    C_AD10* c;
    diff = func_0045A600(&g->cfg, D_004FFD2C);
    if (diff != 0 || !g->b401) {
        if (apply) {
            c = D_004FFD2C;
            c->a = g->cfg.a;
            c->b4 = g->cfg.b4;
            c->b5 = g->cfg.b5;
            c->b6 = g->cfg.b6;
            c->b7 = g->cfg.b7;
            c->f8 = g->cfg.f8;
            c->fc = g->cfg.fc;
            c->f10 = g->cfg.f10;
            c->f14 = g->cfg.f14;
            c->b18 = g->cfg.b18;
            c->b19 = g->cfg.b19;
            c->f1c = g->cfg.f1c;
            c->f20 = g->cfg.f20;
            g->b401 = 0;
            g->b4c = 4;
            func_00441A10(g);
        } else {
            m = diff & 0x800;
            if (m) func_002C9860(D_004FFC04, 1);
            func_0045A3A0(D_004FFD2C, diff);
            if (m) func_002C9510(D_004FFC04);
        }
    } else {
        func_0041E0F0(g, Gui_GetScreenStack(), 0x10, 4, 0);
    }
}