/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_00494150[];
extern char D_004E0D20[];         /* GuiWidget424C50 vtable */
extern int PtrVec_PushBack_1C1080(L4OwnedVec*, void*);
extern int func_001C10A0(L4OwnedVec*);
extern GuiWidget* GuiWidget_ctor(GuiWidget*);

/* Constructor of a GuiWidget subclass holding a vector seeded with one entry. */
GuiWidget424C50* func_00424C50(GuiWidget424C50* self) {
    L4OwnedVec* vec;

    GuiWidget_ctor(&self->base);
    vec = &self->unk60;
    self->base.vtable = D_004E0D20;
    func_001C10A0(vec);
    vec->owned = 1;
    self->unk58 = 0;
    self->unk48 = 1;
    self->unk4C = 1;
    self->unk50 = 0;
    self->unk54 = 0;
    self->unk5C = 24;
    PtrVec_PushBack_1C1080(vec, D_00494150);
    self->unk70 = self->unk48;
    self->unk74 = self->unk4C;
    self->unk78 = self->unk50;
    self->unk7C = self->unk54;
    self->unk82 = 0;
    self->unk84 = 0;
    self->unk81 = 0;
    self->unk80 = 0;
    self->unk88 = 0;
    self->unk8C = 0;
    return self;
}
