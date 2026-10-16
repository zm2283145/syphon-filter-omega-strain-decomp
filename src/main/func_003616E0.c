/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAgentInfo virtual (vtable D_004DF350 slot 12); extends the base handler
 * GuiScreen_Update.
 */

#include "loose03_types.h"

extern void GuiScreen_Update(GuiAgentInfo*);
extern Obj4147A0* Gui_GetScreenStack(void);

/* Calls the base handler, then clears target->unk4E0 unless this screen is the current one. */
void func_003616E0(GuiAgentInfo* self) {
    GuiScreen_Update(self);
    if (self->unk120 != 0 && Gui_GetScreenStack()->unk2C->unk08 != self) {
        self->unk120->unk4E0 = 0;
    }
}
