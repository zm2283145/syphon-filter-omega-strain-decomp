#pragma cplusplus on
#include "types.h"
struct V4561 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual void v23(void*, int); virtual void v24(void*); };
typedef struct { char pad[0x10]; int f10; unsigned short flags; short h16; } W4561;
extern "C" {
extern int Gui_GetScreenList(void);
extern W4561* func_00418A80(int, char*, char*);
extern void* func_00418980(int, char*);
extern W4561* func_0041DB80(void*, char*);
extern V4561* Gui_GetScreenStack(void);
extern char D_004C1AD8[];
extern char D_004C1B00[];
extern char D_004C1B18[];
extern char D_004C1B20[];
extern char D_004C1B28[];
extern char D_004C1B38[];
}
extern "C" void func_00456160(W4561* g) {
    W4561* w = func_00418A80(Gui_GetScreenList(), D_004C1AD8, "INGAMENU");
    void* p;
    if (!w) return;
    w->f10 = g->f10;
    {
        int z = g->h16;
        Gui_GetScreenStack()->v24(g);
        Gui_GetScreenStack()->v23(w, z);
    }
    p = func_00418980(Gui_GetScreenList(), D_004C1B00);
    if (p) {
        W4561* a = func_0041DB80(p, D_004C1B18);
        W4561* b = func_0041DB80(p, D_004C1B20);
        if (a) a->flags |= 2;
        if (b) b->flags |= 2;
    }
    p = func_00418980(Gui_GetScreenList(), D_004C1B00);
    if (p) {
        W4561* a = func_0041DB80(p, D_004C1B28);
        W4561* b = func_0041DB80(p, D_004C1B38);
        if (a) a->flags |= 2;
        if (b) b->flags |= 2;
    }
}
