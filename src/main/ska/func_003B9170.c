/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern void func_003B91B0(SkaQuadWords* self, int a1, int a2);

/* Zero the four header words, then initialise from (a1, a2). */
SkaQuadWords* func_003B9170(SkaQuadWords* self, int a1, int a2) {
    self->w[0] = 0;
    self->w[1] = 0;
    self->w[2] = 0;
    self->w[3] = 0;
    func_003B91B0(self, a1, a2);
    return self;
}
