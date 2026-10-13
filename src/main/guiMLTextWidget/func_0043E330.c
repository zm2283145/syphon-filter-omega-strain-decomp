#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)
struct W_43E330 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
};
typedef struct { char pad[0x10]; unsigned char b10; char pad11[0x47]; unsigned char b58; } T_43E330;
typedef struct {
    char pad[0x3C]; float f3C; float f40; char pad44[4]; T_43E330* f48; void* f4C; char pad50[0x10];
    int f60; int f64; char pad68[0x14]; W_43E330* f7C;
} O_43E330;
extern "C" {
extern char D_004C0110[]; extern char D_004C0100[]; extern char D_004AAE00[];
extern int D_004976B8;
void func_0041F150(O_43E330* o);
void* Mem_Alloc(int pool, int size, char* file, int line);
void* Gui_GetScreenList(void);
void* func_00418420(void* mgr, int name);
T_43E330* func_003D0940(void* p, int a, int b, int c, int d, void* e, char* f);
W_43E330* func_0041DC70(void* o, int id);
int func_0036A2F0(void* p);
void func_0043E330(O_43E330* o);
}
static inline void* Alloc_43E330(int n, int line) { AllocGuard g; return Mem_Alloc(0, n, D_004C0110, line); }
static inline W_43E330* Cast_43E330(W_43E330* w, void* t) { return w && w->IsA(t) ? w : 0; }

void func_0043E330(O_43E330* o)
{
    T_43E330* t;
    func_0041F150(o);
    o->f4C = func_00418420(Gui_GetScreenList(), 0);
    t = (T_43E330*)Alloc_43E330(0x60, 0x33);
    if (t) t = func_003D0940(t, 0, 0, (int)o->f3C, (int)o->f40, o->f4C, D_004C0100);
    o->f48 = t;
    o->f48->b10 = 0;
    o->f48->b58 = 1;
    o->f60 = (int)o->f40 / func_0036A2F0(o->f4C);
    o->f64 = o->f60;
    o->f7C = Cast_43E330(func_0041DC70(o, D_004976B8), D_004AAE00);
}

