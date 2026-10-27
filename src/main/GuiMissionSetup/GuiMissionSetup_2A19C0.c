/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern char GuiMissionSetup_vtable[];   /* GuiMissionSetup vtable */
extern GameMachine* D_004FFC04;
extern GuiScreen* GuiLobbyScreen_ctor(GuiScreen* self);
extern GuiSlot* SFOLobbyList_ctor(GuiSlot* slot);

/* GuiMissionSetup constructor. */
GuiMissionSetup* GuiMissionSetup_ctor(GuiMissionSetup* self) {
    GuiLobbyScreen_ctor(&self->base);
    self->base.base.base.vtable = GuiMissionSetup_vtable;
    SFOLobbyList_ctor(&self->slots[0]);
    SFOLobbyList_ctor(&self->slots[1]);
    SFOLobbyList_ctor(&self->slots[2]);
    self->base.screenId = 6;
    self->unkDC = 0;
    self->unkE0 = 0;
    self->unkE4 = 0;
    self->unkE8 = 0;
    self->unkEC = 0;
    self->machine = 0;
    self->machineData = 0;
    self->unkF8 = 0;
    self->machine = D_004FFC04;
    self->machineData = self->machine->data140;
    return self;
}
