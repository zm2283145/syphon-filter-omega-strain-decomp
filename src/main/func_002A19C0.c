/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern char D_004DD730[];   /* GuiMissionSetup vtable */
extern GameMachine* D_004FFC04;
extern GuiScreen* GuiScreen_ctor(GuiScreen* self);
extern GuiSlot* func_0044FA00(GuiSlot* slot);

/* GuiMissionSetup constructor. */
GuiMissionSetup* GuiMissionSetup_ctor(GuiMissionSetup* self) {
    GuiScreen_ctor(&self->base);
    self->base.base.base.vtable = D_004DD730;
    func_0044FA00(&self->slots[0]);
    func_0044FA00(&self->slots[1]);
    func_0044FA00(&self->slots[2]);
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
