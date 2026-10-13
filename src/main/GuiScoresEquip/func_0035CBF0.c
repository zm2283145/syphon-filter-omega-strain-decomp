#include "types.h"
#pragma cplusplus on
#include "vslot_pad.h"
class W35CBF0 {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
    char pad[0x10]; unsigned short a14;
};
struct S35CBF0 { char pad[0x224]; int a224; char pad228[4]; unsigned char a22C; };
extern "C" {
extern char D_004BB4D8[];
extern char D_004BB4E8[];
extern char D_004BB500[];
extern char D_004BB520[];
extern char D_004BB530[];
extern char D_004A9870[];
void func_0041EFA0(S35CBF0* o);
W35CBF0* GuiWidget_FindChildByName(void* self, char* name);
char* Loc_LookupText(char* key);
void func_0041BEB0(W35CBF0* w, char* text, int flags);
void func_0035CBF0(S35CBF0* o);
}
static inline W35CBF0* cast35CBF0(W35CBF0* w)
{
    return (w && w->IsA(D_004A9870)) ? w : 0;
}
void func_0035CBF0(S35CBF0* o)
{
    W35CBF0* a;
    W35CBF0* b;
    W35CBF0* c;
    func_0041EFA0(o);
    o->a224 = 0;
    a = GuiWidget_FindChildByName(o, D_004BB4D8);
    b = GuiWidget_FindChildByName(o, D_004BB4E8);
    if (a) a->a14 |= 2;
    if (b) b->a14 &= ~2;
    c = cast35CBF0(GuiWidget_FindChildByName(o, D_004BB500));
    if (c) {
        char* t = Loc_LookupText(D_004BB520);
        func_0041BEB0(c, t ? t : D_004BB530, 0);
    }
    o->a22C = 1;
}
