/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern Rel* func_003BA290(Rel* r);

/* Construct: zero the three words and set the flag byte. */
SkaRelFlag* func_003BA260(SkaRelFlag* self) {
    func_003BA290(&self->rel);
    self->flag = 1;
    return self;
}
