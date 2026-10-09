/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiGameScreen_types.h"

/* True when the screen's menu child exists and has flag bit 1 set. */
int func_0045BD00(GuiGameScreen* self) {
    GuiGameChild* menu = self->menu;

    if (menu != 0) {
        return (menu->flags & 2) != 0;
    }
    return 0;
}
