#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "vslot_pad.h"
typedef struct { char pad[0x10]; unsigned char b10; unsigned char b11; unsigned char b12; char pad2[0x45]; unsigned char b58; } C48B90;
typedef struct { char pad[0x90]; C48B90* f90; } B48B90;
typedef struct { int f0; int f4; } L48B90;
class W48B90 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void SetCount(int kind, int n); /* +0x5C */
    char pad4[0x38]; float f3c; float f40; char p44[8]; unsigned int f4C; char p50[4]; int f54; char p58[0x38];
    B48B90* f90; char p94[0xC]; C48B90* fa0; L48B90* fa4;
};
extern "C" {
extern void func_00424A90(W48B90*);
extern void* Mem_Alloc(int, int, char*, int);
extern char D_004BA3D0[];
extern char D_004BA3E8[];
extern char D_00587C20[];
extern int func_00414790(void);
extern int func_00418420(int, char*);
extern C48B90* func_003D0940(void*, int, int, int, int, int, char*);
extern char* func_004294C0(void);
extern void func_00424410(W48B90*, int*, unsigned int*);
extern void func_00424430(W48B90*, int, unsigned int);
}
/* List screen init: creates the callout, binds the lobby list and clamps the restored selection. */
extern "C" void func_00348B90(W48B90* w) {
    C48B90* c;
    func_00424A90(w);
    {
        AllocGuard g;
        c = (C48B90*)Mem_Alloc(0, 0x60, D_004BA3D0, 0x89);
    }
    if (c) {
        int x = (int)w->f3c;
        int y = (int)w->f40;
        c = func_003D0940(c, 0, 0, x, y, func_00418420(func_00414790(), D_004BA3E8), D_00587C20);
    }
    w->fa0 = c;
    w->fa0->b12 = 1;
    w->fa0->b10 = 2;
    if (func_004294C0()) w->fa4 = (L48B90*)(func_004294C0() + 0x1C);
    w->f54 = 0;
    if (w->fa4) w->SetCount(4, w->fa4->f4);
    {
        int top[1];
unsigned int sel[1];
        func_00424410(w, top, sel);
        if (sel[0] >= w->f4C && w->f4C != 0) sel[0] = w->f4C - 1;
        else if (sel[0] >= w->f4C) sel[0] = 0;
        w->f54 = 100000;
        func_00424430(w, top[0], sel[0]);
    }
    if (w->f90 && w->f90->f90) {
        C48B90* x = w->f90->f90;
        x->b11 = 1;
        x->b58 = 1;
    }
}
