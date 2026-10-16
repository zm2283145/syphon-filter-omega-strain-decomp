/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern char D_004DDDE0[];   /* GuiZeusShell vtable */
extern int func_0041EFA0(GuiWidget* self);
extern void GuiWidget_ctor(GuiWidget* self);

/* GuiZeusShell vtable slot 5: forwards to the base widget. */
int func_002B0D10(GuiWidget* self) {
    return func_0041EFA0(self);
}

/* GuiZeusShell constructor. */
GuiWidget* GuiZeusShell_ctor(GuiWidget* self) {
    GuiWidget_ctor(self);
    self->vtable = D_004DDDE0;
    return self;
}
