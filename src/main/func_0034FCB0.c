/*
 * Matched functions (byte-identical with the retail executable).
 * GuiMissionStatistics constructor (vtable D_004DEE70).
 */

#include "loose03_types.h"

extern char D_004DEE70[];       /* GuiMissionStatistics vtable */
extern int func_0034FE40(Member34FE40*);
extern int GuiPersonnelScreen_ctor(GuiMissionStatistics*);

/* GuiMissionStatistics constructor. */
GuiMissionStatistics* GuiMissionStatistics_ctor(GuiMissionStatistics* self) {
    Member34FE40* member;

    GuiPersonnelScreen_ctor(self);
    member = &self->unk70;
    self->base.base.vtable = D_004DEE70;
    func_0034FE40(member);
    member->unk0C = 1;
    self->unk6C = 0;
    return self;
}
