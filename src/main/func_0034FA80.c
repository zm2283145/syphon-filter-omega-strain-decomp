#include "types.h"
#pragma cplusplus on
typedef struct { unsigned short a0; unsigned short a2; short pad4; unsigned short a6; unsigned short a8; } E34FA80;
extern "C" {
void* Gui_GetScreenList(void);
void* Gui_GetScreenStack(void);
int func_00418A80(void* mgr, char* a, char* b);
void GuiStack_SwapScreens(void* mgr, void* self, int snd);
bool func_00356BE0(void* self, E34FA80* e);
bool func_0034FA80(void* self, E34FA80* e);
}
bool func_0034FA80(void* self, E34FA80* e)
{
    bool b = e->a0 == 1 && e->a2 == 0 && e->a8 == 0x10 && e->a6 == 0;
    if (b) {
        int s = func_00418A80(Gui_GetScreenList(), "GuiCommandCenter", "cmdcentr");
        GuiStack_SwapScreens(Gui_GetScreenStack(), self, s);
        return 1;
    }
    return func_00356BE0(self, e);
}