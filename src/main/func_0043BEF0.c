/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GenInfoObject.cc (ends 0x0043BA00); gui widget code.
 */

#include "loose05_types.h"

extern char D_004E0F40[]; /* vtable */
extern void GuiWidget_ctor(void* self);

/* Constructor: base widget plus zeroed fields. */
GuiWidget43BEF0* func_0043BEF0(GuiWidget43BEF0* self) {
    GuiWidget_ctor(self);
    self->base.vtable = D_004E0F40;
    self->unk54 = 0;
    self->unk58 = 0;
    self->unk5C = 0;
    self->unk60 = 10;
    self->unk48 = 0;
    self->unk4C = 0;
    self->unk50 = 0;
    return self;
}
