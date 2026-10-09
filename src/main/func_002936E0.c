/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern char D_004DD460[];   /* GuiSaveAgentWidget vtable */
extern char D_004E1220[];   /* GuiItem vtable */
extern int func_00292E80(GuiSaveAgentWidget* self);
extern int func_0041EFA0(GuiWidget* self);
extern void GuiWidget_ctor(GuiWidget* self);

/* GuiSaveAgentWidget vtable slot 5: own update, then the base widget's. */
int func_002936E0(GuiSaveAgentWidget* self) {
    func_00292E80(self);
    return func_0041EFA0(&self->base.base);
}

/* GuiSaveAgentWidget constructor (GuiItem constructor inlined). */
GuiSaveAgentWidget* GuiSaveAgentWidget_ctor(GuiSaveAgentWidget* self, unsigned char arg) {
    GuiWidget_ctor(&self->base.base);
    self->base.base.vtable = D_004E1220;
    self->base.unk48 = -2;
    self->base.base.vtable = D_004DD460;
    self->unk78 = 10.0f;
    self->unk7C = arg;
    return self;
}
