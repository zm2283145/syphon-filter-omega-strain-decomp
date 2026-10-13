#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct Ctl_002A0860;
struct Hnd_002A0860 {
    VPAD16(a) VPAD1(b)
    virtual void* Make(Ctl_002A0860* w, int a);
};
struct Ctl_002A0860 { char pad[0x14]; unsigned short flags; char pad16[0xE]; Hnd_002A0860* h; };
struct Self_002A0860 { char pad[0x20]; Ctl_002A0860* p20; };
struct Mgr_002A0860 { char pad[0x31]; unsigned char b31; };
struct G_002A0860 { char pad[0x59D]; unsigned char b59D; };
struct Ui_002A0860 { char pad[0x20]; Ctl_002A0860* p20; };

extern "C" {
extern char* D_0048BA28;
extern Mgr_002A0860* D_004FFC04;
extern unsigned char D_0051EEA0;
extern G_002A0860* D_0055A830;
void func_0041E3B0(Self_002A0860* self);
Ctl_002A0860* func_0041DB80(Self_002A0860* self, char* name);
Ui_002A0860* Gui_GetScreenStack(void);
void GuiScreen_SetFocus(Ui_002A0860* ui, void* w);
}

static inline void SetHidden_002A0860(Ctl_002A0860* w, bool h)
{
    if (h)
        w->flags |= 4;
    else
        w->flags &= ~4;
}
extern "C" void func_002A0860(Self_002A0860* self)
{
    Ctl_002A0860* w;
    
    w = func_0041DB80(self, D_0048BA28);
    if (w) {
        bool hide;
        if (D_004FFC04->b31) {
            w->flags &= ~4;
            return;
        }
        hide = D_0055A830->b59D && !D_0051EEA0;
        if (!hide && Gui_GetScreenStack()->p20 == w) {
            GuiScreen_SetFocus(Gui_GetScreenStack(), w->h->Make(w, 1));
        }
        SetHidden_002A0860(w, hide);
    }
}
