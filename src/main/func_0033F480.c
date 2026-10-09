/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet (screen derived from the
 * GuiLobbyScreen.cc base built by GuiScreen_ctor).
 */

#include "loose03_types.h"

extern char D_004DE8A0[];       /* L3GuiMenuScreen vtable */
extern int GuiScreen_ctor(L3GuiMenuScreen*);
extern int func_0044FA00(Member44FA00*);

/* L3GuiMenuScreen constructor. */
L3GuiMenuScreen* GuiMenuScreen_ctor(L3GuiMenuScreen* self) {
    GuiScreen_ctor(self);
    self->base.vtable = D_004DE8A0;
    func_0044FA00(&self->unkAC);
    func_0044FA00(&self->unkC8);
    func_0044FA00(&self->unkE4);
    self->unk104 = 0;
    self->unk108 = 0;
    self->unk10C = 0;
    self->unk88 = 0;
    self->unk8C = 0;
    self->unk98 = 0;
    self->unk9C = 0;
    self->unkA0 = 0;
    self->unkA4 = 0;
    self->unk94 = 1;
    self->unkA8 = 0;
    self->unk100 = -1;
    return self;
}
