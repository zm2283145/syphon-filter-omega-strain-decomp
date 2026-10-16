#pragma cplusplus on
#include "types.h"

struct VC_32CA00 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); };
struct W_32CA00;
struct Stack_32CA00 { char p0[0x20]; W_32CA00* focus; char p24[0x44]; unsigned int flags; };
struct Vec_32CA00 { int p0; int p4; W_32CA00** data; };
struct Menu_32CA00 { char p0[0x78]; char* slider; };
struct Self_32CA00 {
    char p0[0x20];
    W_32CA00* focus;
    char p24[0x28];
    Menu_32CA00* menu;
    char p50[0xC];
    int sel;
    Vec_32CA00 vec;
    char p6C[0x75];
    unsigned char bE1;
    char pE2[6];
    unsigned int mods;
};

extern "C" {
void func_0041EFA0(Self_32CA00* self);
void func_0032B5F0(Self_32CA00* self, unsigned int flags);
Stack_32CA00* Gui_GetScreenStack(void);
W_32CA00*** func_00171EC0(Vec_32CA00* v);
VC_32CA00* func_0032C110(W_32CA00* w);
int GuiKeyboard_IsSpecialKey(Self_32CA00* self, W_32CA00* w);
}

static inline float clamp01(float x) { float lo = 0.0f; float hi = 1.0f; asm { max.s lo, x, lo; min.s lo, lo, hi } return lo; }

static inline W_32CA00* At(Vec_32CA00* v, int i) { return (*func_00171EC0(v))[i]; }

static inline void Focus(Self_32CA00* self, W_32CA00* w)
{
    Stack_32CA00* ss = Gui_GetScreenStack();
    if (w != ss->focus) {
        if (ss->focus) func_0032C110(ss->focus)->v8();
        ss->focus = w;
        if (w) {
            if (!GuiKeyboard_IsSpecialKey(self, w)) func_0032C110(w)->v7();
        }
    }
}

extern "C" void GuiKeyboard_Wake(Self_32CA00* self)
{
    func_0041EFA0(self);
    self->sel = 0;
    self->bE1 = 0;
    self->mods = 0;
    func_0032B5F0(self, 0);
    Gui_GetScreenStack();
    Focus(self, At(&self->vec, self->sel));
    self->focus = self->vec.data[self->sel];
    Gui_GetScreenStack()->flags |= 0x40;
    {
        char* s = self->menu->slider;
        if (s) *(float*)(s + 0x54) = clamp01(0.2f);
    }
}
