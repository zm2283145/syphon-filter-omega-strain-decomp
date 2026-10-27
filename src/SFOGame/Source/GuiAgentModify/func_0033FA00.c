#include "types.h"

extern int g_AgentPartCache;
extern void Monster_RestoreLockedPartsTex(void*);
extern void cMotionManager_FlushUpdateList(void);
extern void* Gui_Manager(void);
extern void* GuiManager_OpenGui(void*, void*, void*);
extern void* Gui_Canvas(void);
extern void GuiCanvas_Transition(void*, int, void*);

/* Resets state, looks up a named entry and hands it to GuiCanvas_Transition with the argument. */
void GuiAgentModify_SaveDone(int arg) {
    void* entry;
    Monster_RestoreLockedPartsTex(&g_AgentPartCache);
    cMotionManager_FlushUpdateList();
    entry = GuiManager_OpenGui(Gui_Manager(), ((int*)"GuiCommandCenter"), ((int*)"CMDCENTR"));
    GuiCanvas_Transition(Gui_Canvas(), arg, entry);
}
