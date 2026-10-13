#pragma cplusplus on
#include "types.h"
struct W28A5C0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* type);
    char pad[0x80];
    int f84;
};
struct Mgr_28A5C0 { char pad[0x265]; unsigned char b265; };
struct S_28A5C0 {
    char pad0[0x20]; W28A5C0* p20; char pad24[0x88 - 0x24];
    W28A5C0* p88; W28A5C0* p8C; W28A5C0* p90; W28A5C0* p94; W28A5C0* p98; int f9C; W28A5C0* pA0;
    char padA4[4]; int fA8; unsigned char bAC; unsigned char bAD;
};
extern "C" {
extern Mgr_28A5C0* D_004FFC04;
extern char D_004FFB50[];
extern char D_004A96F8[];
extern char D_004A9718[];
extern char D_004A9880[];
extern char D_004A9870[];
extern char D_004A7520[];
extern int D_0048B400;
extern int D_0048B408;
extern int D_0048B410;
extern int D_0048B418;
extern int D_0048B420;
extern int D_0048B428;
void func_0033D3F0(void);
int Agent_GetSelected(void* a, int b);
W28A5C0* func_0041DB80(S_28A5C0* a, int b);
char* Loc_LookupText(char* key);
void func_0041BEB0(void* w, char* s, int a);
}
extern "C" void func_0028A5C0(S_28A5C0* self)
{
    W28A5C0* p;
    func_0033D3F0();
    self->f9C = Agent_GetSelected(D_004FFB50, -1);
    self->p88 = func_0041DB80(self, D_0048B400);
    p = func_0041DB80(self, D_0048B408);
    p = (p && p->IsA(D_004A9880)) ? p : 0;
    self->p8C = p;
    if (self->p8C)
        self->p8C->f84 = 15;
    self->p90 = func_0041DB80(self, D_0048B410);
    p = func_0041DB80(self, D_0048B418);
    p = (p && p->IsA(D_004A9880)) ? p : 0;
    self->p94 = p;
    if (self->p94)
        self->p94->f84 = 15;
    p = func_0041DB80(self, D_0048B420);
    p = (p && p->IsA(D_004A9870)) ? p : 0;
    self->p98 = p;
    p = func_0041DB80(self, D_0048B428);
    p = (p && p->IsA(D_004A7520)) ? p : 0;
    self->pA0 = p;
    if (self->pA0)
        func_0041BEB0(self->pA0, Loc_LookupText(D_004A96F8), 0);
    if (self->p98)
        func_0041BEB0(self->p98, Loc_LookupText(D_004A9718), 0);
    self->bAD = 0;
    if (!D_004FFC04->b265)
        self->p20 = self->p98;
    self->fA8 = -1;
}
