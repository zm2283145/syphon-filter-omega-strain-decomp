/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

/* Clears GuiWidget flag bit 2. */
void func_0041F070(GuiWidget* self) {
    unsigned int flags;

    flags = self->flags; /* zero-extended load keeps the match */
    self->flags = flags & 65531;
}

/* Sets GuiWidget flag bit 2. */
void func_0041F080(GuiWidget* self) {
    unsigned int flags;

    flags = self->flags;
    self->flags = flags | 4;
}
