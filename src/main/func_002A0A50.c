/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern char D_004DD6B0[];   /* GuiOnlineOfflineSelect vtable */
extern void GuiWidget_ctor(GuiWidget* self);

/* GuiOnlineOfflineSelect constructor. */
GuiOnlineOfflineSelect* GuiOnlineOfflineSelect_ctor(GuiOnlineOfflineSelect* self) {
    GuiWidget_ctor(&self->base);
    self->base.vtable = D_004DD6B0;
    self->unk48 = 0;
    return self;
}
