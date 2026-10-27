/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentModify.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiAgentModify_types.h"

extern char g_AgentPartCache[];
extern int Monster_RestoreLockedPartsTex(void* p);
extern void cMotionManager_FlushUpdateList(void);
extern GuiManagerState* Gui_Canvas(void);
extern int GuiWidget_onSleep(void* self);
extern int GuiWidget_onRemove(void* self);

int GuiAgentModify_onRemove(void* self) {
    Monster_RestoreLockedPartsTex(g_AgentPartCache);
    cMotionManager_FlushUpdateList();
    return GuiWidget_onRemove(self);
}

/* Calls the base handler, then clears bits 2-3 of the gui manager flags. */
GuiManagerState* GuiAgentModify_onSleep(void* self) {
    GuiManagerState* gui;

    GuiWidget_onSleep(self);
    gui = Gui_Canvas();
    gui->flags &= ~12;
    return gui;
}
