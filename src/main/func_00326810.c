/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern char D_004DE670[];   /* GuiCharacterDisplay vtable */
extern int func_0041E470(GuiWidget* self);
extern int func_0041EFA0(GuiWidget* self);
extern void GuiWidget_ctor(GuiWidget* self);

/* GuiCharacterDisplay vtable slot 10: base call, then the optional callback. */
void func_00326810(GuiCharacterDisplay* self) {
    func_0041E470(&self->base);
    if (self->onDestroy != 0) {
        self->onDestroy();
    }
}

/* GuiCharacterDisplay vtable slot 5: forwards to the base widget. */
int func_00326850(GuiWidget* self) {
    return func_0041EFA0(self);
}

/* GuiCharacterDisplay constructor. */
GuiCharacterDisplay* GuiCharacterDisplay_ctor(GuiCharacterDisplay* self) {
    GuiWidget_ctor(&self->base);
    self->base.vtable = D_004DE670;
    self->onDestroy = 0;
    return self;
}
