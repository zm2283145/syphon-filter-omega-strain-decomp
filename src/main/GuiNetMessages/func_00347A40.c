/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiNetMessages.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiNetMessages_types.h"

extern char D_004DEB10[];   /* GuiNetMessages vtable */
extern void* func_0033D580(void* self);

/* Constructor. */
GuiNetMessages* func_00347A40(GuiNetMessages* self) {
    func_0033D580(self);
    self->vtable = D_004DEB10;
    self->unk84 = 9;
    self->unk88 = 0;
    self->unk9C = -1;
    return self;
}
