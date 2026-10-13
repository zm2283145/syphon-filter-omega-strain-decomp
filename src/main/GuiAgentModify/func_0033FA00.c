#include "types.h"

extern int D_0055DDA0;
extern void func_00403310(void*);
extern void func_0040F540(void);
extern void* Gui_GetScreenList(void);
extern void* func_00418A80(void*, void*, void*);
extern void* Gui_GetScreenStack(void);
extern void GuiStack_SwapScreens(void*, int, void*);

/* Resets state, looks up a named entry and hands it to GuiStack_SwapScreens with the argument. */
void func_0033FA00(int arg) {
    void* entry;
    func_00403310(&D_0055DDA0);
    func_0040F540();
    entry = func_00418A80(Gui_GetScreenList(), ((int*)"GuiCommandCenter"), ((int*)"CMDCENTR"));
    GuiStack_SwapScreens(Gui_GetScreenStack(), arg, entry);
}
