/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet (address lies just after
 * guiWidget.cc's known range); functions are named by address until real
 * names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_004E09B0[];         /* base widget vtable */
extern char D_004E0B40[];         /* GuiWidget vtable */
extern int D_00572130;            /* widget instance counter */
extern int ScalarCollection_Init(L4ScalarCollection*);

/* GuiWidget constructor. */
GuiWidget* GuiWidget_ctor(GuiWidget* self) {
    self->vtable = D_004E09B0;
    D_00572130 = D_00572130 + 1;
    self->vtable = D_004E0B40;
    self->unk04 = 0;
    self->unk08 = 0;
    self->unk0C = 0;
    ScalarCollection_Init(&self->children);
    self->unk34 = 0;
    self->unk38 = 0;
    self->unk3C = 0;
    self->unk40 = 0;
    self->flags = 38;
    self->unk10 = -1;
    self->parent = 0;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk34 = 0;
    self->unk38 = 0;
    self->unk3C = 0;
    self->unk40 = 0;
    self->self = self;
    self->unk16 = 0;
    self->unk18 = 0;
    return self;
}
