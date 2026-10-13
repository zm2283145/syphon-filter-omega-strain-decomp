#include "types.h"

extern void func_0041EBF0(void* self);
extern int Gui_GetScreenStack(void);
extern void func_0041E0F0(void* self, int a, int b, int c, int d);

/* Runs the base setup, then calls func_0041E0F0 with Gui_GetScreenStack's result and constants 0x10, 3, 0. */
void func_002A86A0(void* self)
{
    func_0041EBF0(self);
    func_0041E0F0(self, Gui_GetScreenStack(), 0x10, 3, 0);
}
