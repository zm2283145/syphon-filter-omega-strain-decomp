/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after NetMsgThrottle.cc (ends 0x00472370).
 */

#include "loose05_types.h"

extern int AnimChannel_SetTarget(void* channel, int anim, int arg, float weight, float blend, float start);

/* Clears flag bits 25 and 26, then retargets the animation channel to anim 21. */
int func_00475BB0(Char475BB0* self) {
    unsigned int flags;

    flags = self->flags;
    self->flags = flags & 0xfdffffff;
    flags = self->flags;
    self->flags = flags & 0xfbffffff;
    return AnimChannel_SetTarget(self->animChannel, 21, 0, 1.0f, 0.5f, 0.0f);
}
