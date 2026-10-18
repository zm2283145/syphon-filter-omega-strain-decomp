#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class M2A7C20 { public: VPAD16(a) VPAD8(b) virtual void Remove(void* o); };
struct E2A7C20 { int f0; int f4; void* item; void* btnA; void* btnB; };
struct O2A7C20 { char p0[0x10]; int sel; char p14[0x34]; int mode; int cur; int f50; int idx; E2A7C20 entries[1]; };
extern "C" {
extern void* D_004FFC04;
int GuiMessageBox_ValidateTarget(int v);
void GuiWidget_SendEvent(O2A7C20* o, int a, int b, int c, int d);
int FrontEnd_ClosePopup(void* g, int sel);
int String_CStr(void* p);
int GuiWidget_OnEvent(O2A7C20* o, void* sender, unsigned short msg);
M2A7C20* Gui_GetScreenStack(void);
}

extern "C" int GuiMessageBox_HandleEvent(O2A7C20* o, void* sender, unsigned short msg)
{
    if (msg == 2) {
        E2A7C20* e; int old; old = o->sel; e = &o->entries[o->idx];
        o->cur = GuiMessageBox_ValidateTarget(o->cur);
        if (o->mode == 6) {
            if (sender == e->btnA || sender == e->item) {
                int v = 0;
                if (e->item != 0) {
                    v = String_CStr((char*)e->item + 0x48);
                }
                GuiWidget_SendEvent(o, o->cur, 0x1A, o->f50, v);
            } else if (sender == e->btnB) {
                GuiWidget_SendEvent(o, o->cur, 0x1B, o->f50, 0);
            }
        } else {
            if (sender == e->btnA) {
                GuiWidget_SendEvent(o, o->cur, 0x1A, o->f50, 0);
            } else if (sender == e->btnB) {
                GuiWidget_SendEvent(o, o->cur, 0x1B, o->f50, 0);
            }
        }
        if (!FrontEnd_ClosePopup(D_004FFC04, old) && old == o->sel) {
            o->sel = -1;
            Gui_GetScreenStack()->Remove(o);
        }
        return 1;
    }
    return GuiWidget_OnEvent(o, sender, msg);
}

