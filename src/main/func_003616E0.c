/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAgentInfo virtual (vtable D_004DF350 slot 12); extends the base handler
 * func_0033D310.
 */

#include "loose03_types.h"

extern void func_0033D310(GuiAgentInfo*);
extern Obj4147A0* func_004147A0(void);

/* Calls the base handler, then clears target->unk4E0 unless this screen is the current one. */
void func_003616E0(GuiAgentInfo* self) {
    func_0033D310(self);
    if (self->unk120 != 0 && func_004147A0()->unk2C->unk08 != self) {
        self->unk120->unk4E0 = 0;
    }
}
