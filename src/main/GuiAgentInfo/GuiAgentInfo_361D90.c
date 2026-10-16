/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAgentInfo constructor (vtable D_004DF350); derives from the screen base
 * built by GuiScreen_ctor (GuiLobbyScreen.cc range).
 */

#include "loose03_types.h"

extern char D_004DF350[];       /* GuiAgentInfo vtable */
extern int func_00298690(void*);
extern int GuiScreen_ctor(GuiAgentInfo*);

/* GuiAgentInfo constructor. */
GuiAgentInfo* GuiAgentInfo_ctor(GuiAgentInfo* self) {
    GuiAgentInfoMember88* member;

    GuiScreen_ctor(self);
    member = &self->unk88;
    self->base.vtable = D_004DF350;
    func_00298690(member->unk30);
    func_00298690(member->unk3C);
    self->base.screenId = 8;
    self->unkFC = 0;
    return self;
}
