/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "loose05_types.h"

extern GuiWidget* GuiWidget_FocusFirst(GuiWidget* self);

/* Hides the widget returned by GuiWidget_FocusFirst unless it is this widget. */
GuiWidget* func_00463940(GuiWidget* self) {
    GuiWidget* other;

    other = GuiWidget_FocusFirst(self);
    if (other != self) {
        other->flags &= ~0x2;
    }
    return self;
}
