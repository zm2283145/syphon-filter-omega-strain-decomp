/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after guiMLTextWidget.cc (ends 0x0043E330); gui widget code.
 */

#include "loose05_types.h"

extern char D_004E10C0[]; /* vtable */
extern GuiWidget* GuiWidget_ctor(void* self);

/* Constructor: base widget, then defaults for this widget type. */
GuiWidget43F910* func_0043F910(GuiWidget43F910* self) {
    GuiWidget_ctor(self);
    self->base.vtable = D_004E10C0;
    self->base.flags |= 0x80;
    self->unk60 = 0;
    self->unk64 = 0;
    self->unk68 = 0;
    self->unk6C = 100;
    self->unk70 = 10;
    self->unk4C = 0;
    self->unk50 = 0;
    self->unk58 = 0;
    self->unk4D = 0;
    self->unk54 = 0;
    self->unk58 = 0;
    self->unk48 = 1;
    return self;
}
