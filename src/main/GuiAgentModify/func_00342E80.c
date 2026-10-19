/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentModify.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiAgentModify_types.h"

extern char g_AgentPartCache[];
extern int AgentPartCache_Unlock(void* p);
extern void World_ClearPendingIfLoaded(void);
extern GuiManagerState* Gui_GetScreenStack(void);
extern int GuiWidget_BaseSleep(void* self);
extern int GuiWidget_Deinit(void* self);

int GuiAgentModify_Deinit(void* self) {
    AgentPartCache_Unlock(g_AgentPartCache);
    World_ClearPendingIfLoaded();
    return GuiWidget_Deinit(self);
}

/* Calls the base handler, then clears bits 2-3 of the gui manager flags. */
GuiManagerState* GuiAgentModify_Sleep(void* self) {
    GuiManagerState* gui;

    GuiWidget_BaseSleep(self);
    gui = Gui_GetScreenStack();
    gui->flags &= ~12;
    return gui;
}
