/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiTextArrayWidget.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "guiTextArrayWidget_types.h"

extern char D_004E0DC0[];   /* guiTextArrayWidget vtable */
extern void* func_00424C50(void* self);
extern Rel* func_00427000(Rel* r);

/* guiTextArrayWidget constructor. */
guiTextArrayWidget* guiTextArrayWidget_ctor(guiTextArrayWidget* self) {
    TextArrayStore* store;

    func_00424C50(self);
    store = &self->store;
    self->vtable = D_004E0DC0;
    func_00427000((Rel*)store);
    store->unk0C = 1;
    self->unk90 = 0;
    self->count = 0;
    self->unk98 = 2;
    self->color[0] = 1.0f;
    self->color[1] = 1.0f;
    self->color[2] = 1.0f;
    self->color[3] = 1.0f;
    return self;
}
