/*
 * Matched functions (byte-identical with the retail executable).
 * GuiPersonnelScreen constructor (vtable D_004DF0B0).
 */

#include "loose03_types.h"

extern char D_004DF0B0[];       /* GuiPersonnelScreen vtable */
extern void GuiWidget_ctor(GuiPersonnelScreen*);

/* GuiPersonnelScreen constructor. */
GuiPersonnelScreen* GuiPersonnelScreen_ctor(GuiPersonnelScreen* self) {
    GuiWidget_ctor(self);
    self->base.vtable = D_004DF0B0;
    self->unk48 = 0;
    self->unk4C = 0;
    self->unk50 = 0;
    self->unk5C = 0;
    self->unk60 = 0;
    self->unk54 = 0;
    self->unk58 = 0;
    self->unk68 = 1;
    return self;
}
