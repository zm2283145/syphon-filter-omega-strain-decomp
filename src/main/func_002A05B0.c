#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct Ctl_002A05B0;
struct Hnd_002A05B0 {
    VPAD16(a) VPAD1(b)
    virtual void* Make(Ctl_002A05B0* w, int a);
};
struct Ctl_002A05B0 { char pad[0x14]; unsigned short flags; char pad16[0xE]; Hnd_002A05B0* h; };
struct Self_002A05B0 { char pad[0x20]; Ctl_002A05B0* p20; };
struct Mgr_002A05B0 { char pad[0x31]; unsigned char b31; };
struct G_002A05B0 { char pad[0x59D]; unsigned char b59D; };
struct Ui_002A05B0 { char pad[0x20]; Ctl_002A05B0* p20; };

extern "C" {
extern char* D_0048BA28;
extern Mgr_002A05B0* D_004FFC04;
extern unsigned char D_0051EEA0;
extern G_002A05B0* D_0055A830;
void func_0041E3B0(Self_002A05B0* self);
Ctl_002A05B0* GuiWidget_FindChildByName(Self_002A05B0* self, char* name);
Ui_002A05B0* Gui_GetScreenStack(void);
void GuiScreen_SetFocus(Ui_002A05B0* ui, void* w);
}

static inline void SetHidden_002A05B0(Ctl_002A05B0* w, bool h)
{
    if (h)
        w->flags |= 4;
    else
        w->flags &= ~4;
}
extern "C" void func_002A05B0(Self_002A05B0* self)
{
    Ctl_002A05B0* w;
    func_0041E3B0(self);
    w = GuiWidget_FindChildByName(self, D_0048BA28);
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
        SetHidden_002A05B0(w, hide);
    }
}
