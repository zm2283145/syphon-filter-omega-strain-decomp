/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiGameScreen_types.h"

extern int GuiWidget_OnEvent(GuiGameScreen* self, void* sender, int msg);
extern int GuiGameScreen_ChooseConfirm(GuiGameScreen* self);

/* Message handler: message 19 from the choice list is handled here,
 * everything else goes to the base widget handler. */
int GuiGameScreen_OnEvent(GuiGameScreen* self, void* sender, int msg) {
    if ((msg & 0xFFFF) == 19 && sender == self->choices) {
        GuiGameScreen_ChooseConfirm(self);
        return 1;
    }
    return GuiWidget_OnEvent(self, sender, msg);
}
