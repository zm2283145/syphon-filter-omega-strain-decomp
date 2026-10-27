/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Sets the screen id of the referenced screen, if any. */
void GuiMessageBox_SetEditBufferSize(ScreenRefHolder* self, int screenId) {
    GuiScreen* screen = self->screen;

    if (screen != 0) {
        screen->screenId = screenId;
    }
}
