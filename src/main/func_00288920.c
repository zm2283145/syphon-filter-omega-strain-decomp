#pragma cplusplus on
#include "types.h"
struct W_00288920 { char pad[0x14]; unsigned short flags; };
struct Scr_00288920 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void* GetFocus();
    char pad[0x10];
    unsigned short flags;
};
extern "C" {
extern char* D_0048B3E8;
extern char* D_0048B3F0;
extern char* D_0048B3F8;
W_00288920* GuiWidget_FindChildByName(Scr_00288920* s, char* name);
void* Gui_GetScreenStack(void);
void GuiScreen_SetFocus(void* stack, void* w);
}
extern "C" void func_00288920(Scr_00288920* self, int on)
{
    char* names[3] = { D_0048B3E8, D_0048B3F0, D_0048B3F8 };
    unsigned int i;
    for (i = 0; i < 3; i++) {
        W_00288920* w = GuiWidget_FindChildByName(self, names[i]);
        if (w) {
            if (on)
                w->flags |= 4;
            else
                w->flags &= ~4;
        }
    }
    if (self->flags & 8)
        GuiScreen_SetFocus(Gui_GetScreenStack(), self->GetFocus());
}

