#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { char pad[0x10]; unsigned char b10; char pad2[0x47]; unsigned char b58; } C458;
typedef struct { char pad[0x3C]; float f3c; float f40; char pad2[4]; C458* f48; int f4c; char pad3[0x28]; int f78; } W458;
extern "C" {
extern void func_0041EFA0(W458*);
extern int func_00414790(void);
extern int func_00418420(int, char*);
extern void* Mem_Alloc(int, int, char*, int);
extern char D_004C1EB0[];
extern char D_00587D70[];
extern C458* func_003D0940(void*, int, int, int, int, int, char*);
extern int func_0036A2F0(int);
}
extern "C" void func_00458140(W458* w) {
    C458* obj;
    func_0041EFA0(w);
    w->f4c = func_00418420(func_00414790(), "callout");
    {
        AllocGuard g;
        obj = (C458*)Mem_Alloc(0, 0x60, D_004C1EB0, 0x154);
    }
    if (obj) obj = func_003D0940(obj, 0, 0, (int)w->f3c, (int)w->f40, w->f4c, D_00587D70);
    w->f48 = obj;
    w->f48->b10 = 0;
    w->f48->b58 = 1;
    w->f78 = (int)(w->f40 / (float)func_0036A2F0(w->f4c));
}
