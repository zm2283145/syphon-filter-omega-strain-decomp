/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern void _cdeque_deleter_int_1_init(SkaQuadWords* self, int a1, int a2);

/* Zero the four header words, then initialise from (a1, a2). */
SkaQuadWords* _cdeque_imp_cSkaSystem_RequestPtr_1_ctor(SkaQuadWords* self, int a1, int a2) {
    self->w[0] = 0;
    self->w[1] = 0;
    self->w[2] = 0;
    self->w[3] = 0;
    _cdeque_deleter_int_1_init(self, a1, a2);
    return self;
}
