#pragma cplusplus on
#include "types.h"
struct V2998B0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); };
typedef struct { V2998B0 v; char pad[0x10]; unsigned short flags; } E2998B0;
typedef struct {
    char pad0[0x20];
    int x20;
    char pad24[0x8C - 0x24];
    E2998B0* items[4];
    void* objs[4];
    E2998B0* xAC;
    int padB0;
    int idx;
} S2998B0;
extern "C" {
void* func_004147A0(void);
void func_00414B30(void* a, int b);
void func_0041E0F0(void* a, void* b, int c, int d, int e);
void func_002999B0(S2998B0* s);
}
extern "C" void func_002998B0(S2998B0* s)
{
    if (s->items[s->idx]) {
        int r;
        s->items[s->idx]->flags |= 4;
        r = s->items[s->idx]->v.v15();
        func_00414B30(func_004147A0(), r);
        s->x20 = r;
    }
    if (s->xAC)
        s->xAC->flags &= ~4;
    if (s->objs[s->idx]) {
        func_0041E0F0(s, s->objs[s->idx], 10, 10, 0);
        func_0041E0F0(s->objs[s->idx], func_004147A0(), 0x10, 0, 0);
    }
    func_002999B0(s);
}