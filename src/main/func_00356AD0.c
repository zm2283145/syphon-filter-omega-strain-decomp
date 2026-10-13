#include "types.h"

extern void* Gui_GetScreenList(void);
extern void* func_00418A80(void* manager, const char* a, const char* b);
extern void* Gui_GetScreenStack(void);
extern void GuiStack_SwapScreens(void* target, void* self, void* handle);

/* Creates a handle from the two name strings and registers it for self. */
void func_00356AD0(void* self)
{
    void* handle = func_00418A80(Gui_GetScreenList(), "GuiCommandCenter", "cmdcentr");
    GuiStack_SwapScreens(Gui_GetScreenStack(), self, handle);
}
