/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameScreen.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiGameScreen_types.h"

extern int func_00424430(GuiChoiceList* list, int a1, int index);

void func_0045BEB0(GuiGameScreen* self, int value) {
    self->unkEC = value;
}

/* Forwards a valid choice index (0 < index < count) to the choice list. */
void func_0045BEC0(GuiGameScreen* self, int index) {
    if (self->menu != 0 && index > 0 && index < self->choices->count) {
        func_00424430(self->choices, 0, index);
    }
}
