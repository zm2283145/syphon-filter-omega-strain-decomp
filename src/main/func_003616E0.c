/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAgentInfo virtual (vtable GuiAgentInfo_vtable slot 12); extends the base handler
 * GuiLobbyScreen_onAdvanceTime.
 */

#include "loose03_types.h"

extern void GuiLobbyScreen_onAdvanceTime(GuiAgentInfo*);
extern Obj4147A0* Gui_Canvas(void);

/* Calls the base handler, then clears target->unk4E0 unless this screen is the current one. */
void GuiAgentInfo_Update(GuiAgentInfo* self) {
    GuiLobbyScreen_onAdvanceTime(self);
    if (self->unk120 != 0 && Gui_Canvas()->unk2C->unk08 != self) {
        self->unk120->unk4E0 = 0;
    }
}
