#include "types.h"

extern void func_0041EBF0(void* self);
extern int Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(void* self, int a, int b, int c, int d);

/* Runs the base setup, then calls GuiWidget_SendEvent with Gui_GetScreenStack's result and constants 0x10, 3, 0. */
void GuiMessageBox_Sleep(void* self)
{
    func_0041EBF0(self);
    GuiWidget_SendEvent(self, Gui_GetScreenStack(), 0x10, 3, 0);
}
