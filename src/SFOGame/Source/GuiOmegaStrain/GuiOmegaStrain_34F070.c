/*
 * Matched functions (byte-identical with the retail executable).
 * GuiOmegaStrain constructor (vtable D_004DEDE0); derives from GuiPersonnelScreen.
 */

#include "loose03_types.h"

extern char D_004DEDE0[];       /* vtable */
extern int GuiPersonnelScreen_ctor(GuiPersonnelScreen*);

/* GuiPersonnelScreen subclass constructor (unk64 = 8). */
GuiPersonnelScreen* GuiOmegaStrain_ctor(GuiPersonnelScreen* self) {
    GuiPersonnelScreen_ctor(self);
    self->base.vtable = D_004DEDE0;
    self->unk64 = 8;
    return self;
}
