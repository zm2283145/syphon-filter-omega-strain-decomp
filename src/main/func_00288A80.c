/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004DD0A0;
extern void GuiWidget_ctor(Unk288A80*);

Unk288A80* func_00288A80(Unk288A80* self) {
    GuiWidget_ctor(self);
    self->vtable = &D_004DD0A0;
    self->unk48 = 0;
    self->unk4C = 0;
    self->unk50 = -2;
    return self;
}
