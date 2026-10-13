#pragma cplusplus on
#include "types.h"
struct W2A0970 { char pad[0x14]; unsigned short flags; };
struct S2A0970 { char pad[0x48]; unsigned char b48; };
extern "C" {
extern unsigned char D_00506488;
extern unsigned char D_00506490;
extern const char* D_0048BA38;
extern const char* D_0048BA30;
void func_0041F150(S2A0970* s);
W2A0970* GuiWidget_FindChildByName(S2A0970* s, const char* name);
}

static inline int Nz2A0970(unsigned char v) { return v != 0; }
/* Screen init: copies the global mode flag and shows/hides two widgets accordingly. */
extern "C" void func_002A0970(S2A0970* s)
{
    W2A0970* w;
    func_0041F150(s);
    s->b48 = D_00506488;
    w = GuiWidget_FindChildByName(s, D_0048BA38);
    if (w) {
        bool c = !s->b48 && D_00506490;
        if (c) w->flags |= 2;
        else w->flags &= ~2;
    }
    w = GuiWidget_FindChildByName(s, D_0048BA30);
    if (w) {
        if (Nz2A0970(s->b48) ^ 1) w->flags |= 4;
        else w->flags &= ~4;
    }
}
