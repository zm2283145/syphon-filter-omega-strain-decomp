/*
 * Matched functions (byte-identical with the retail executable).
 * GuiRanks constructor (vtable D_004DED50); derives from GuiPersonnelScreen.
 */

#include "loose03_types.h"

extern char D_004DED50[];       /* vtable */
extern int GuiPersonnelScreen_ctor(GuiPersonnelScreen*);

/* GuiPersonnelScreen subclass constructor (unk64 = 6). */
GuiPersonnelScreen* GuiRanks_ctor(GuiPersonnelScreen* self) {
    GuiPersonnelScreen_ctor(self);
    self->base.vtable = D_004DED50;
    self->unk64 = 6;
    return self;
}
