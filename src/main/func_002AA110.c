/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern char D_004DDAF0[];   /* GuiOnlineOptions vtable */
extern GuiScreen* GuiScreen_ctor(GuiScreen* self);
extern GuiSlot* func_0044FA00(GuiSlot* slot);

/* GuiOnlineOptions constructor. */
GuiOnlineOptions* GuiOnlineOptions_ctor(GuiOnlineOptions* self) {
    GuiScreen_ctor(&self->base);
    self->base.base.base.vtable = D_004DDAF0;
    func_0044FA00(&self->slot);
    self->base.screenId = 5;
    self->unk88 = 0;
    self->unk90 = 0;
    self->unk8C = 0;
    self->unk94 = 0;
    self->unk9C = -1;
    self->unk98 = -1;
    self->base.unk78 = 0;
    return self;
}
