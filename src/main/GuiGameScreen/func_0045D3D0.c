/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiGameScreen_types.h"

extern int func_0041EF10(GuiGameScreen* self, void* sender, int msg);
extern int func_0045BDF0(GuiGameScreen* self);

/* Message handler: message 19 from the choice list is handled here,
 * everything else goes to the base widget handler. */
int func_0045D3D0(GuiGameScreen* self, void* sender, int msg) {
    if ((msg & 0xFFFF) == 19 && sender == self->choices) {
        func_0045BDF0(self);
        return 1;
    }
    return func_0041EF10(self, sender, msg);
}
