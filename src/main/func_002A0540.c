#include "types.h"

typedef struct { char pad[0x10]; int flag; } Widget;

extern char D_004AAEB0[];
extern char D_004AAEC8[];
extern void* Gui_GetScreenList(void);
extern Widget* func_00418A80(void* factory, const char* a, const char* b);
extern void* Gui_GetScreenStack(void);
extern void GuiStack_SwapScreens(void* mgr, void* self, Widget* w);

/* Creates a widget from two names, flags it and registers it for self. */
void func_002A0540(void* self)
{
    Widget* w = func_00418A80(Gui_GetScreenList(), D_004AAEB0, D_004AAEC8);
    w->flag = 1;
    GuiStack_SwapScreens(Gui_GetScreenStack(), self, w);
}
