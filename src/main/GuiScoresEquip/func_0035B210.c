#pragma cplusplus on
#include "types.h"
struct W_0035B210 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
};
struct B_0035B210 { char pad0[0x14]; unsigned short flags; };
struct S_0035B210 { char pad0[0x224]; int f224; };
extern "C" {
extern char D_004BB4D8[];
extern char D_004BB4E8[];
extern char D_004BB500[];
extern char D_004BB520[];
extern char D_004BB530[];
extern char D_004BB540[];
extern char D_004A9870[];
void* GuiWidget_FindChildByName(void* self, char* name);
char* Loc_LookupText(char* key);
void func_0041BEB0(W_0035B210* w, char* s, int a);
int func_0041EF10(void* self, int a, unsigned short b);
}
static inline W_0035B210* FindAs_0035B210(void* self, char* name, char* type)
{
    W_0035B210* w = (W_0035B210*)GuiWidget_FindChildByName(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" int func_0035B210(S_0035B210* self, int a, unsigned short b)
{
    if (b == 2) {
        int on = self->f224 == 0;
        B_0035B210* b1;
        B_0035B210* b2;
        W_0035B210* w;
        self->f224 = on;
        b1 = (B_0035B210*)GuiWidget_FindChildByName(self, D_004BB4D8);
        b2 = (B_0035B210*)GuiWidget_FindChildByName(self, D_004BB4E8);
        if (b1) {
            if (!on)
                b1->flags |= 2;
            else
                b1->flags &= ~2;
        }
        if (b2) {
            if (on)
                b2->flags |= 2;
            else
                b2->flags &= ~2;
        }
        w = FindAs_0035B210(self, D_004BB500, D_004A9870);
        if (w) {
            char* t = Loc_LookupText(on == 0 ? D_004BB520 : D_004BB540);
            func_0041BEB0(w, t ? t : D_004BB530, 0);
        }
        return 1;
    }
    return func_0041EF10(self, a, b);
}

