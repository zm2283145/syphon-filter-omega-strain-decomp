#pragma cplusplus on
#include "vslot_pad.h"
struct Obj2426 { char pad[0x6A4]; void* snd; unsigned char b6A8; unsigned char b6A9; unsigned char b6AA; };
class Mgr2427 {
public:
    VPAD16(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual void s23(void* x, int y); virtual void s24(void* x);
};
extern "C" {
void* Gui_Manager(void);
Mgr2427* Gui_Canvas(void);
void* GuiManager_FindOpenGui(void* a, void* b);
void* GuiManager_OpenGui(void* a, void* b, void* c);
extern char D_004A7230[];
}extern "C" void cHud_ActivateMap(Obj2426* s) {
    if (s->b6A9 || s->b6A8) return;
    {
        void* x = GuiManager_OpenGui(Gui_Manager(), D_004A7230, "MAPSCRN");
        Gui_Canvas()->s23(x, 0);
        s->b6A9 = 1;
    }
}

