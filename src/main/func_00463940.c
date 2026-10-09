/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "loose05_types.h"

extern GuiWidget* func_0041D8C0(GuiWidget* self);

/* Hides the widget returned by func_0041D8C0 unless it is this widget. */
GuiWidget* func_00463940(GuiWidget* self) {
    GuiWidget* other;

    other = func_0041D8C0(self);
    if (other != self) {
        other->flags &= ~0x2;
    }
    return self;
}
