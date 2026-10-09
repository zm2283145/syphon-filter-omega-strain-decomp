/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "loose05_types.h"

extern Rel* func_00460F20(Rel* r);

/* Constructor: clears the triple and sets the enabled flag. */
FlaggedRel* func_00460E90(FlaggedRel* self) {
    func_00460F20(&self->rel);
    self->enabled = 1;
    return self;
}
