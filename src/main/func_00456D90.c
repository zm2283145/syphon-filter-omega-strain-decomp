/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies before GuiSubTitleDisplay.cc (starts 0x00457AA0); gui widget code.
 */

#include "loose05_types.h"

extern char D_004E1430[]; /* vtable */
extern int GuiObjectives_ctor(void* self, int a1, int a2);

/* Constructor: base built by GuiObjectives_ctor, fields cleared, flag bit 5 cleared. */
GuiWidget456D90* func_00456D90(GuiWidget456D90* self) {
    GuiObjectives_ctor(self, 1, 1);
    self->vtable = D_004E1430;
    self->unk90 = 0;
    self->unk94 = 0;
    self->unk98 = 0;
    self->unk9C = 0;
    self->unkA0 = 0;
    self->unkA4 = 0;
    self->unkA8 = 0;
    self->flags &= ~0x20;
    return self;
}
