/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern char D_004DDD40[];   /* GuiNetAgencyCell vtable */
extern GuiMenuScreen* GuiMenuScreen_ctor(GuiMenuScreen* self);

/* GuiNetAgencyCell constructor. */
GuiNetAgencyCell* GuiNetAgencyCell_ctor(GuiNetAgencyCell* self) {
    GuiMenuScreen_ctor(&self->base);
    self->base.base.base.base.vtable = D_004DDD40;
    self->unk174 = 0;
    self->unk178 = 0;
    self->unk17C = 0;
    self->base.base.screenId = 3;
    self->unk164 = 0;
    self->unk168 = 0;
    self->unk16C = 0;
    self->unk170 = 0;
    return self;
}
