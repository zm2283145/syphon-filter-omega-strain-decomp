#pragma cplusplus on
#include "types.h"
struct V29B { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual char* v19(); };
typedef struct { int a; unsigned char b4, b5, b6, b7; float f8, fc, f10; int f14; unsigned char b18, b19; char p1a[2]; float f1c; int f20; } C29B;
typedef struct { char pad[0x14]; unsigned short flags; } W29B;
typedef struct { char pad[0xA8]; W29B* fa8; char pad2[0xC]; C29B cfg; char pad3[0x324]; unsigned char b400; char pad4[0x2B]; W29B* f42c; } G29B;
extern "C" {
extern void func_0041EFA0(G29B*);
extern C29B* D_004FFD2C;
extern void func_0029AA50(G29B*, int);
extern V29B* Gui_GetScreenStack(void);
extern int String_CompareNoCase(char*, char*);
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern int func_0029BDB0(void);
extern void func_0036B250(int);
extern void func_0036B3B0(int, int, int);
}
static inline int ok29B(void) { return D_005721C8 ? D_005721C0 : 1; }
extern "C" void func_0029B1E0(G29B* g) {
    C29B* c;
    func_0041EFA0(g);
    c = D_004FFD2C;
    g->cfg.a = c->a;
    g->cfg.b4 = c->b4;
    g->cfg.b5 = c->b5;
    g->cfg.b6 = c->b6;
    g->cfg.b7 = c->b7;
    g->cfg.f8 = c->f8;
    g->cfg.fc = c->fc;
    g->cfg.f10 = c->f10;
    g->cfg.f14 = c->f14;
    g->cfg.b18 = c->b18;
    g->cfg.b19 = c->b19;
    g->cfg.f1c = c->f1c;
    g->cfg.f20 = c->f20;
    func_0029AA50(g, -1);
    g->b400 = String_CompareNoCase(Gui_GetScreenStack()->v19(), "GuiGameCanvas") == 0;
    if (g->b400) {
        if (g->f42c) g->f42c->flags &= ~4;
        if (!D_005721C8 || !ok29B() || func_0029BDB0() < 2) {
            if (g->fa8) g->fa8->flags &= ~4;
        }
    } else {
        func_0036B250(1);
        func_0036B3B0(1, 0x100000, 0x800);
    }
}
