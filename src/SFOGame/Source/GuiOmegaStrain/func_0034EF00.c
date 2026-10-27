/*
 * Matched functions (byte-identical with the retail executable).
 * GuiOmegaStrain message handler (vtable D_004DEDE0 slot 13).
 */

#include "loose03_types.h"

extern int GuiPersonnelScreen_onMessage(GuiPersonnelScreen* self, int a1, int msg, int value, int t0);

/* Forwards to the GuiPersonnelScreen handler. */
int GuiOmegaStrain_onMessage(GuiPersonnelScreen* self, int a1, int msg, int value, int t0) {
    return GuiPersonnelScreen_onMessage(self, a1, msg, value, t0);
}
