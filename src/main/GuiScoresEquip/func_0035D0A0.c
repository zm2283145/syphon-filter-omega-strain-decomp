#include "types.h"
#pragma cplusplus on
#include "vslot_pad.h"
class W35D0A0 {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
    char pad[0x10]; unsigned short a14;
};
struct S35D0A0 { char pad[0x224]; int a224; };
extern "C" {
extern char D_004BB4D8[];
extern char D_004BB4E8[];
extern char D_004BB500[];
extern char D_004BB520[];
extern char D_004BB530[];
extern char D_004BB540[];
extern char D_004A9870[];
W35D0A0* GuiWidget_FindChildByName(void* self, char* name);
char* Loc_LookupText(char* key);
void func_0041BEB0(W35D0A0* w, char* text, int flags);
void func_0035D0A0(S35D0A0* o, int mode);
}
static inline W35D0A0* cast35D0A0(W35D0A0* w)
{
    return (w && w->IsA(D_004A9870)) ? w : 0;
}
/* Switches the screen between its two modes: toggles two widgets and relabels a third. */
void func_0035D0A0(S35D0A0* o, int mode)
{
    W35D0A0* a;
    W35D0A0* b;
    W35D0A0* c;
    o->a224 = mode;
    a = GuiWidget_FindChildByName(o, D_004BB4D8);
    b = GuiWidget_FindChildByName(o, D_004BB4E8);
    if (a) {
        if (!mode) a->a14 |= 2;
        else a->a14 &= ~2;
    }
    if (b) {
        if (mode) b->a14 |= 2;
        else b->a14 &= ~2;
    }
    c = cast35D0A0(GuiWidget_FindChildByName(o, D_004BB500));
    if (c) {
        char* t = Loc_LookupText(mode == 0 ? D_004BB520 : D_004BB540);
        func_0041BEB0(c, t ? t : D_004BB530, 0);
    }
}
