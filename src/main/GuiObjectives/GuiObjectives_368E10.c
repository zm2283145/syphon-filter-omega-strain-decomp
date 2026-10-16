/*
 * Matched functions (byte-identical with the retail executable).
 * GuiObjectives constructor (vtable D_004DF5C0).
 */

#include "loose03_types.h"

extern char D_004DF5C0[];       /* GuiObjectives vtable */
extern void GuiWidget_ctor(GuiObjectives*);

/* GuiObjectives constructor. */
GuiObjectives* GuiObjectives_ctor(GuiObjectives* self, int a1, int a2) {
    GuiWidget_ctor(self);
    self->base.vtable = D_004DF5C0;
    self->unk5C = -1;
    self->unk58 = 0;
    self->unk78 = 0;
    self->unk7C = 0;
    self->unk84 = 0;
    self->unk88 = a1;
    self->unk89 = a2;
    return self;
}
