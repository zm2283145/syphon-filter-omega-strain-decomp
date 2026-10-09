/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern SkaTransitionReq* ScalarCollection_Init(SkaTransitionReq* self);

/* True when both requests carry the same key. */
int TransitionReq_SameKey(SkaTransitionReq* a, SkaTransitionReq* b) {
    return a->key == b->key;
}

SkaTransitionReq* TransitionReq_Construct(SkaTransitionReq* self, float time) {
    ScalarCollection_Init(self);
    self->unk0C = time;
    return self;
}

/* Reset: zero words, both limits to FLT_MAX. */
SkaTransitionReq* TransitionReq_Reset(SkaTransitionReq* self) {
    self->unk00 = 0;
    self->unk04 = 0;
    self->unk08 = 3.4028235e38f;
    self->unk0C = 3.4028235e38f;
    self->key = 0;
    return self;
}
