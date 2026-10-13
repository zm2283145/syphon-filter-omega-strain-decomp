#pragma cplusplus on
#include "vslot_pad.h"
struct Obj2426 { char pad[0x6A4]; void* snd; unsigned char b6A8; unsigned char b6A9; unsigned char b6AA; };
class Mgr2427 {
public:
    VPAD16(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual void s23(void* x, int y); virtual void s24(void* x);
};
extern "C" {
void* Gui_GetScreenList(void);
Mgr2427* Gui_GetScreenStack(void);
void* GuiManager_FindByName(void* a, void* b);
void* GuiManager_FindOrLoad(void* a, void* b, void* c);
extern char D_004A7230[];
}extern "C" void func_00242870(Obj2426* s) {
    if (s->b6A9 || s->b6A8) return;
    {
        void* x = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A7230, "MAPSCRN");
        Gui_GetScreenStack()->s23(x, 0);
        s->b6A9 = 1;
    }
}

