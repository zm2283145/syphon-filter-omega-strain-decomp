/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern char D_004DDA50[];   /* GuiNetJoinMission vtable */
extern GuiMenuScreen* GuiMenuScreen_ctor(GuiMenuScreen* self);

/* GuiNetJoinMission constructor. */
GuiNetListScreen* GuiNetJoinMission_ctor(GuiNetListScreen* self) {
    GuiMenuScreen_ctor(&self->base);
    self->base.base.base.base.vtable = D_004DDA50;
    self->base.base.screenId = 2;
    self->unk160 = 0;
    self->unk164 = 0;
    return self;
}
