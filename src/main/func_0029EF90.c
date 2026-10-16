#pragma cplusplus on
#include "types.h"
struct W_0029EF90 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
    char pad4[0x5C]; int f60; char pad64[0x18]; W_0029EF90* f7C; char pad80[8]; void* f88;
};
struct Page_0029EF90 { char pad[0x14]; unsigned short flags; };
struct Self_0029EF90 {
    char pad0[0xEC]; W_0029EF90* fEC; W_0029EF90* fF0; W_0029EF90* fF4; void* fF8; void* fFC; W_0029EF90* f100; void* f104;
    Page_0029EF90* f108; void* f10C; void* f110; void* f114;
};
extern "C" {
extern char* D_0048B920;
extern char* D_0048B928;
extern char* D_0048B930;
extern char* D_0048B938;
extern char* D_0048B940;
extern char* D_0048B948;
extern char* D_0048B950;
extern char* D_0048B958;
extern char* D_0048B960;
extern char* D_0048B968;
extern char* D_0048B970;
extern char* D_0048B978;
extern char* D_0048B980;
extern char D_004AA640[];
extern char D_004A7520[];
extern char D_004AAE20[];
extern char D_004AAE00[];
void GuiScreen_Init(Self_0029EF90* self);
void* GuiWidget_FindChildByName(Self_0029EF90* self, char* name);
void func_004235B0(W_0029EF90* w, int a, int b);
void func_00421650(W_0029EF90* w, int a);
void MLTextWidget_SetFont(W_0029EF90* w, char* s);
void* Gui_GetScreenList(void);
Page_0029EF90* GuiManager_FindOrLoad(void* a, char* b, char* c);
}
static inline W_0029EF90* FindAs_0029EF90(Self_0029EF90* self, char* name, char* type)
{
    W_0029EF90* w = (W_0029EF90*)GuiWidget_FindChildByName(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" void func_0029EF90(Self_0029EF90* self)
{
    GuiScreen_Init(self);
    self->f10C = GuiWidget_FindChildByName(self, D_0048B920);
    self->f110 = GuiWidget_FindChildByName(self, D_0048B938);
    self->f114 = GuiWidget_FindChildByName(self, D_0048B968);
    self->fEC = FindAs_0029EF90(self, D_0048B928, D_004AA640);
    if (self->fEC) {
        func_004235B0(self->fEC, 1, 10);
        self->fEC->f88 = GuiWidget_FindChildByName(self, D_0048B930);
        func_00421650(self->fEC, 1);
    }
    self->fF0 = FindAs_0029EF90(self, D_0048B940, D_004A7520);
    self->fF4 = FindAs_0029EF90(self, D_0048B948, D_004AAE20);
    self->fF8 = GuiWidget_FindChildByName(self, D_0048B950);
    self->fFC = GuiWidget_FindChildByName(self, D_0048B958);
    self->f100 = FindAs_0029EF90(self, D_0048B970, D_004AAE20);
    self->f104 = GuiWidget_FindChildByName(self, D_0048B978);
    if (self->fF4) {
        self->fF4->f7C = FindAs_0029EF90(self, D_0048B960, D_004AAE00);
        MLTextWidget_SetFont(self->fF4, "callout");
        self->fF4->f60 = 0;
    }
    if (self->f100) {
        self->f100->f7C = FindAs_0029EF90(self, D_0048B980, D_004AAE00);
        MLTextWidget_SetFont(self->f100, "callout");
        self->f100->f60 = 0;
    }
    self->f108 = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiWidget", "DNASLOGO");
    self->f108->flags &= ~0x20;
}