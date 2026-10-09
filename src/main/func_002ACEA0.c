/*
 * Matched functions (byte-identical with the retail executable).
 * Probably GuiMissionList.cc: this constructor installs the GuiMissionList vtable
 * and sits just past that unit's known address range (0x002AAC60-0x002ACCF0).
 */

#include "types.h"
#include "loose02_types.h"

extern char D_004DDB80[];   /* GuiMissionList vtable */
extern Rel* func_002AD080(Rel* r);
extern GuiWidget* func_00424C50(GuiWidget* self);

/* GuiMissionList constructor. */
GuiMissionListObj* GuiMissionList_ctor(GuiMissionListObj* self) {
    OwnedRel* items;

    func_00424C50(&self->base);
    items = &self->items;
    self->base.vtable = D_004DDB80;
    func_002AD080(&items->vec);
    items->owned = 1;
    self->unkA8 = 0;
    self->unkAC = 1;
    self->unkAD = 1;
    self->unkB0 = 0;
    self->unkB4 = 0;
    self->unkB5 = 0;
    self->unkB8 = -1;
    self->unk58 = 2;
    self->unk11C = 0;
    self->unkBC = 0;
    self->unkCC = -1;
    self->unkC4 = -1;
    self->unkC0 = -1;
    return self;
}
