/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Sets the screen id of the referenced screen, if any. */
void func_002A7DD0(ScreenRefHolder* self, int screenId) {
    GuiScreen* screen = self->screen;

    if (screen != 0) {
        screen->screenId = screenId;
    }
}
