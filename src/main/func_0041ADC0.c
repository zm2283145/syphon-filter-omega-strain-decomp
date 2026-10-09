/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_004E0A40[];         /* Unk41ADC0 vtable */
extern Unk41ADC0* func_0041C7D0(Unk41ADC0*);

/* Constructor: runs the parent constructor, then sets flag bit 7. */
Unk41ADC0* func_0041ADC0(Unk41ADC0* self) {
    unsigned int flags;

    func_0041C7D0(self);
    self->vtable = D_004E0A40;
    flags = self->flags; /* zero-extended load keeps the match */
    self->flags = flags | 128;
    self->unk80 = 0;
    self->unk84 = 100;
    self->unk8C = 0;
    self->unk88 = 0;
    return self;
}
