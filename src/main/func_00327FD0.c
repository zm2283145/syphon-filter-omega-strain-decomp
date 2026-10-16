#pragma cplusplus on
#include "types.h"
struct W327FD0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* type);
};
struct F327FD0 { char p0[0x14]; unsigned short flags; };
struct S327FD0 { char p0[0x5C]; W327FD0* w5C; W327FD0* w60; W327FD0* w64; W327FD0* w68; };
extern "C" {
extern char* D_00491548;
extern char* D_00491540;
extern char* D_00491550;
extern char* D_00491558;
extern char D_004B88F0[];
extern char D_004A7520[];
void GuiWidget_Init(S327FD0* self);
W327FD0* GuiWidget_FindChildByName(S327FD0* a, char* b);
void func_0041C0F0(W327FD0* w, int a);
}
extern "C" void func_00327FD0(S327FD0* self)
{
    W327FD0* p;
    GuiWidget_Init(self);
    p = GuiWidget_FindChildByName(self, D_00491548);
    self->w5C = (p && p->IsA(D_004B88F0)) ? p : 0;
    if (self->w5C)
        ((F327FD0*)self->w5C)->flags &= ~2;
    p = GuiWidget_FindChildByName(self, D_00491540);
    self->w60 = (p && p->IsA(D_004A7520)) ? p : 0;
    if (self->w60)
        func_0041C0F0(self->w60, 1);
    p = GuiWidget_FindChildByName(self, D_00491550);
    self->w64 = (p && p->IsA(D_004A7520)) ? p : 0;
    p = GuiWidget_FindChildByName(self, D_00491558);
    self->w68 = (p && p->IsA(D_004A7520)) ? p : 0;
}
