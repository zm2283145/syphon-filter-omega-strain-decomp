#pragma cplusplus on
#include "types.h"
#include "gui_widget_vslots.h"
struct W_455610 : GuiWidgetV { char pad4[0x10]; unsigned short f14; char pad16[0x4A]; int f60; char pad64[0x18]; GuiWidgetV* f7C; };
struct S_455610 { char pad0[0x48]; GuiWidgetV* f48; W_455610* f4C; GuiWidgetV* f50; GuiWidgetV* f54; };
extern "C" {
extern char* D_00497998;
extern char D_004C1A60[];
extern char D_004C19C0[];
extern char D_004C1A78[];
extern char D_004C19B0[];
extern char D_004BB3D0[];
extern char D_004A7520[];
extern char D_004C1D88[];
extern char D_004AAE20[];
extern char D_004AAE00[];
void func_0041F150(S_455610* s);
}
extern "C" void func_00455610(S_455610* s)
{
    func_0041F150(s);
    s->f48 = GuiFindAs(s, D_00497998, D_004BB3D0);
    s->f50 = GuiFindAs(s, D_004C1A60, D_004A7520);
    s->f54 = GuiFindAs(s, D_004C19C0, D_004C1D88);
    s->f4C = (W_455610*)GuiFindAs(s, D_004C1A78, D_004AAE20);
    if (s->f4C) {
        s->f4C->f60 = 0;
        s->f4C->f7C = GuiFindAs(s, D_004C19B0, D_004AAE00);
        s->f4C->f14 |= 0x80;
    }
}
