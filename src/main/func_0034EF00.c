/*
 * Matched functions (byte-identical with the retail executable).
 * GuiOmegaStrain message handler (vtable D_004DEDE0 slot 13).
 */

#include "loose03_types.h"

extern int func_00356B30(GuiPersonnelScreen* self, int a1, int msg, int value, int t0);

/* Forwards to the GuiPersonnelScreen handler. */
int func_0034EF00(GuiPersonnelScreen* self, int a1, int msg, int value, int t0) {
    return func_00356B30(self, a1, msg, value, t0);
}
