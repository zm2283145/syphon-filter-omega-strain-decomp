/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern char D_004DD620[];   /* GuiOnlineConnect vtable */
extern GuiScreen* GuiScreen_ctor(GuiScreen* self);
extern GuiSlot* LobbyArray_ctor(GuiSlot* slot);

/* GuiOnlineConnect constructor. */
GuiOnlineConnect* GuiOnlineConnect_ctor(GuiOnlineConnect* self) {
    GuiScreen_ctor(&self->base);
    self->base.base.base.vtable = D_004DD620;
    LobbyArray_ctor(&self->slots[0]);
    LobbyArray_ctor(&self->slots[1]);
    LobbyArray_ctor(&self->slots[2]);
    self->base.screenId = 0;
    self->unk94 = 0;
    self->unk88 = 0;
    self->unk8C = 0;
    self->unk90 = 0;
    self->unkEC = 0;
    self->unkF4 = 0;
    self->unkF8 = 0;
    self->unkFC = 0;
    self->unk100 = 0;
    self->unk104 = 0;
    self->unk10C = 0;
    self->unk110 = 0;
    self->unk114 = 0;
    self->unk118 = 4;
    self->unk11C = -2;
    self->unk120 = -2;
    return self;
}
