/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "loose05_types.h"

char D_004C2460[] = "GuiAutoSaver"; /* resource name */
extern int Gui_GetScreenList(void);
extern int Gui_GetScreenStack(void);
extern void GuiStack_SwapScreens(int mgr, void* owner, int res);
extern int GuiManager_AddWidget(int a0, int res);
extern int func_0041EFA0(void* self);
extern int GuiFactory_CreateWidget(char* name);
extern int GuiSaveAgentWidget_HandleEvent(void* self);

void func_0045F300(void* self) {
    GuiStack_SwapScreens(Gui_GetScreenStack(), self, 0);
}

int func_0045F340(GuiWidget45F340* self) {
    func_0041EFA0(self);
    self->unk4C = 2;
    return GuiSaveAgentWidget_HandleEvent(self);
}

/* Looks up the named resource and, if found, registers it for this owner. */
void func_0045F380(void* self) {
    int res;

    res = GuiFactory_CreateWidget(D_004C2460);
    if (res != 0) {
        GuiManager_AddWidget(Gui_GetScreenList(), res);
        GuiStack_SwapScreens(Gui_GetScreenStack(), self, res);
    }
}
