/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiGameScreen_types.h"

extern int GuiWidget_onMessage(GuiGameScreen* self, void* sender, int msg);
extern int GuiGameScreen_AcceptChooseMenu(GuiGameScreen* self);

/* Message handler: message 19 from the choice list is handled here,
 * everything else goes to the base widget handler. */
int GuiGameScreen_onMessage(GuiGameScreen* self, void* sender, int msg) {
    if ((msg & 0xFFFF) == 19 && sender == self->choices) {
        GuiGameScreen_AcceptChooseMenu(self);
        return 1;
    }
    return GuiWidget_onMessage(self, sender, msg);
}
