/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern void func_00298420(GuiCommandCenter* self);
extern GuiManager* Gui_GetScreenStack(void);

/* Deactivates the screen: clears manager flags 0x0C and resets the selection. */
void func_00297350(GuiCommandCenter* self) {
    GuiManager* mgr;

    if (self->active != 0) {
        mgr = Gui_GetScreenStack();
        mgr->flags &= ~0xC;
        func_00298420(self);
        self->selection = -1;
        self->unk1D0 = 0;
        self->active = 0;
    }
}
