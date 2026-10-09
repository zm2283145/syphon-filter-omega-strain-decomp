/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

void* func_003B2630(char* self) {
    return self + 8;
}

/* Clip root-motion axis Z flag set. */
int ClipHeader_HasAxisZ(SkaClipFlags* clip) {
    return 0U < clip->axisZ;
}

void* func_003B2650(char* self) {
    return self + 4;
}

/* Clip root-motion axis Y flag set. */
int ClipHeader_HasAxisY(SkaClipFlags* clip) {
    return 0U < clip->axisY;
}

/* Clip root-motion axis X flag set. */
int ClipHeader_HasAxisX(SkaClipFlags* clip) {
    return 0U < clip->axisX;
}

void* func_003B2680(void* self) {
    return self;
}

Iter16* SkaClip_AdvanceFrame16(Iter16* it) {
    it->p += 16;
    return it;
}
