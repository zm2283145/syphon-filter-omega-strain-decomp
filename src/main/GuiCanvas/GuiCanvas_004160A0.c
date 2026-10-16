/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_004E08D0[];         /* GuiWidget4160A0 vtable */
extern int ScalarCollection_Init(L4ScalarCollection*);
extern GuiWidget* GuiWidget_ctor(GuiWidget*);

/* Constructor of a GuiWidget subclass; clears flag bit 2 of the base. */
GuiWidget4160A0* func_004160A0(GuiWidget4160A0* self) {
    unsigned int flags;

    GuiWidget_ctor(&self->base);
    self->base.vtable = D_004E08D0;
    ScalarCollection_Init(&self->unk54);
    self->unk50 = 0;
    self->unk48 = 0;
    self->unk4C = 0;
    self->unk60 = 0;
    self->unk64 = 0;
    flags = self->base.flags; /* zero-extended load keeps the match */
    self->base.flags = flags & 0xFFFB;
    self->unk51 = 1;
    self->unk52 = 1;
    self->unk68 = 0xF000;
    return self;
}
