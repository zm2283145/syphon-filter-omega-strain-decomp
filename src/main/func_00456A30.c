/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies before GuiSubTitleDisplay.cc (starts 0x00457AA0).
 */

#include "loose05_types.h"

extern int func_0041EBF0(void* self);

/* Shutdown: base shutdown, then clears the handle at +0x10. */
int func_00456A30(GuiWidget* self) {
    int ret;

    ret = func_0041EBF0(self);
    self->unk10 = -1;
    return ret;
}
