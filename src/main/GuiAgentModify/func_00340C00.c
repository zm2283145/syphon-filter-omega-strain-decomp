#include "types.h"
extern char g_AgentPartCache[];
extern char D_004B9ED0[];
extern char D_004B9EE8[];
extern void Monster_RestoreLockedPartsTex(void* a);
extern void cMotionManager_FlushUpdateList(void);
extern void* Gui_Manager(void);
extern int GuiManager_OpenGui(void* a, const char* b, const char* c);
extern void* Gui_Canvas(void);
extern void GuiCanvas_Transition(void* a, int b, int c);
/* Look up an entry and register it with `arg`. */
void GuiAgentModify_NextScreen(int arg)
{
    int entry;
    Monster_RestoreLockedPartsTex(g_AgentPartCache);
    cMotionManager_FlushUpdateList();
    entry = GuiManager_OpenGui(Gui_Manager(), D_004B9ED0, D_004B9EE8);
    GuiCanvas_Transition(Gui_Canvas(), arg, entry);
}
