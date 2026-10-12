#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { char pad[0x10]; unsigned char b10; unsigned char b11; unsigned char b12; char pad2[0x45]; unsigned char b58; } C2AB;
typedef struct { char pad[0x90]; C2AB* f90; } B2AB;
typedef struct { char pad[0x2480]; int f2480; } L2AB;
typedef struct { char pad[0x3C]; float f3c; float f40; char pad2[0x64]; C2AB* fa8; char p[4]; B2AB* fb0; char p2[8]; unsigned char bbc; char p3[3]; int fc0; int fc4; char p4[4]; int fcc; char p5[0x50]; int f120; } W2AB;
extern "C" {
extern void func_00424A90(W2AB*);
extern void* Mem_Alloc(int, int, char*, int);
extern char D_004AB9B0[];
extern char D_00587C40[];
extern int func_00414790(void);
extern int func_00418420(int, char*);
extern C2AB* func_003D0940(void*, int, int, int, int, int, char*);
extern void* memset(void*, int, int);
extern void func_003D08B0(C2AB*, char*);
extern L2AB* func_004294C0(void);
extern int func_0044FA40(L2AB*);
}
extern "C" void func_002ABD50(W2AB* w) {
    char buf[0x50];
    C2AB* c;
    L2AB* l;
    func_00424A90(w);
    {
        AllocGuard g;
        c = (C2AB*)Mem_Alloc(0, 0x60, D_004AB9B0, 0x2C5);
    }
    if (c) {
        int x = (int)w->f3c;
        int y = (int)w->f40;
        c = func_003D0940(c, 0, 0, x, y, func_00418420(func_00414790(), "callout"), D_00587C40);
    }
    w->fa8 = c;
    w->fa8->b12 = 1;
    w->fa8->b10 = 2;
    memset(buf, 0x2A, 0x50);
    buf[0x4F] = 0;
    func_003D08B0(w->fa8, buf);
    w->fcc = -1;
    w->fc4 = -1;
    w->fc0 = -1;
    l = func_004294C0();
    w->f120 = l ? l->f2480 : -1;
    {
        C2AB* x = w->fb0->f90;
        if (x) {
            x->b11 = 1;
            x->b58 = 1;
        }
    }
    w->bbc = l != 0 && func_0044FA40(l) != 0;
}
