#include "types.h"

extern int g_AgentPartCache;
extern void AgentPartCache_Unlock(void*);
extern void World_ClearPendingIfLoaded(void);
extern void* Gui_GetScreenList(void);
extern void* GuiManager_FindOrLoad(void*, void*, void*);
extern void* Gui_GetScreenStack(void);
extern void GuiStack_SwapScreens(void*, int, void*);

/* Resets state, looks up a named entry and hands it to GuiStack_SwapScreens with the argument. */
void GuiAgentModify_ReturnToCommandCenter(int arg) {
    void* entry;
    AgentPartCache_Unlock(&g_AgentPartCache);
    World_ClearPendingIfLoaded();
    entry = GuiManager_FindOrLoad(Gui_GetScreenList(), ((int*)"GuiCommandCenter"), ((int*)"CMDCENTR"));
    GuiStack_SwapScreens(Gui_GetScreenStack(), arg, entry);
}
