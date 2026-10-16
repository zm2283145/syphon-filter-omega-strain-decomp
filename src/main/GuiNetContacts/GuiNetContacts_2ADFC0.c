/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern char D_004DDC20[];   /* GuiNetContacts vtable */
extern GuiMenuScreen* GuiMenuScreen_ctor(GuiMenuScreen* self);

/* GuiNetContacts constructor. */
GuiNetListScreen* GuiNetContacts_ctor(GuiNetListScreen* self) {
    GuiMenuScreen_ctor(&self->base);
    self->base.base.base.base.vtable = D_004DDC20;
    self->base.base.screenId = 4;
    self->unk160 = 0;
    self->unk164 = 0;
    return self;
}
