#include "types.h"

extern int D_0055DDA0;
extern void AgentPartCache_Unlock(void*);
extern void World_ClearPendingIfLoaded(void);
extern void* Gui_GetScreenList(void);
extern void* GuiManager_FindOrLoad(void*, void*, void*);
extern void* Gui_GetScreenStack(void);
extern void GuiStack_SwapScreens(void*, int, void*);

/* Resets state, looks up a named entry and hands it to GuiStack_SwapScreens with the argument. */
void func_0033FA00(int arg) {
    void* entry;
    AgentPartCache_Unlock(&D_0055DDA0);
    World_ClearPendingIfLoaded();
    entry = GuiManager_FindOrLoad(Gui_GetScreenList(), ((int*)"GuiCommandCenter"), ((int*)"CMDCENTR"));
    GuiStack_SwapScreens(Gui_GetScreenStack(), arg, entry);
}
