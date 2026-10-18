#include "types.h"
extern char D_0055DDA0[];
extern char D_004B9ED0[];
extern char D_004B9EE8[];
extern void AgentPartCache_Unlock(void* a);
extern void World_ClearPendingIfLoaded(void);
extern void* Gui_GetScreenList(void);
extern int GuiManager_FindOrLoad(void* a, const char* b, const char* c);
extern void* Gui_GetScreenStack(void);
extern void GuiStack_SwapScreens(void* a, int b, int c);
/* Look up an entry and register it with `arg`. */
void func_00340C00(int arg)
{
    int entry;
    AgentPartCache_Unlock(D_0055DDA0);
    World_ClearPendingIfLoaded();
    entry = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004B9ED0, D_004B9EE8);
    GuiStack_SwapScreens(Gui_GetScreenStack(), arg, entry);
}
