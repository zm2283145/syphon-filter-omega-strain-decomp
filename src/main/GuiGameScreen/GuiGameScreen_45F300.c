/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "loose05_types.h"

char D_004C2460[] = "GuiAutoSaver"; /* resource name */
extern int Gui_Manager(void);
extern int Gui_Canvas(void);
extern void GuiCanvas_Transition(int mgr, void* owner, int res);
extern int GuiManager_Add(int a0, int res);
extern int GuiWidget_onWake(void* self);
extern int AbstractWidgetClassRep_Create(char* name);
extern int GuiSaveAgentWidget_HandleEvent(void* self);

void GuiAutoSaver_SaveDone(void* self) {
    GuiCanvas_Transition(Gui_Canvas(), self, 0);
}

int GuiAutoSaver_Wake(GuiWidget45F340* self) {
    GuiWidget_onWake(self);
    self->unk4C = 2;
    return GuiSaveAgentWidget_HandleEvent(self);
}

/* Looks up the named resource and, if found, registers it for this owner. */
void GuiEndGameAwards_Done(void* self) {
    int res;

    res = AbstractWidgetClassRep_Create(D_004C2460);
    if (res != 0) {
        GuiManager_Add(Gui_Manager(), res);
        GuiCanvas_Transition(Gui_Canvas(), self, res);
    }
}
