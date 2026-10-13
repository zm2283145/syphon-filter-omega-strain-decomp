#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct Ctl_002A06C0;
struct Hnd_002A06C0 {
    VPAD16(a) VPAD1(b)
    virtual void* Make(Ctl_002A06C0* w, int a);
};
struct Ctl_002A06C0 { char pad[0x14]; unsigned short flags; char pad16[0xE]; Hnd_002A06C0* h; };
struct Self_002A06C0 { char pad[0x20]; Ctl_002A06C0* p20; char pad24[0x24]; unsigned char b48; };
struct Mgr_002A06C0 { char pad[0x31]; unsigned char b31; };
struct G_002A06C0 { char pad[0x59D]; unsigned char b59D; };
struct Ui_002A06C0 { char pad[0x20]; Ctl_002A06C0* p20; };

extern "C" {
extern char* D_0048BA28;
extern char* D_0048BA30;
extern char* D_0048BA38;
extern Mgr_002A06C0* D_004FFC04;
extern unsigned char D_0051EEA0;
extern unsigned char D_0051EEA8;
extern G_002A06C0* D_0055A830;
void func_0041EFA0(Self_002A06C0* self);
void func_002C9AF0(Mgr_002A06C0* m, int a);
Ctl_002A06C0* func_0041DB80(Self_002A06C0* self, char* name);
Ui_002A06C0* Gui_GetScreenStack(void);
void GuiScreen_SetFocus(Ui_002A06C0* ui, void* w);
}

static inline void SetHidden_002A06C0(Ctl_002A06C0* w, bool h)
{
    if (h)
        w->flags |= 4;
    else
        w->flags &= ~4;
}

extern "C" void func_002A06C0(Self_002A06C0* self)
{
    Ctl_002A06C0* w;
    func_0041EFA0(self);
    func_002C9AF0(D_004FFC04, 0);
    self->p20 = func_0041DB80(self, self->b48 ? D_0048BA28 : D_0048BA30);
    w = func_0041DB80(self, D_0048BA38);
    if (w)
        SetHidden_002A06C0(w, !D_0051EEA8);
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
        SetHidden_002A06C0(w, hide);
    }
}