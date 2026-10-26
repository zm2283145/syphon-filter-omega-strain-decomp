/*
 * Matched functions (byte-identical with the retail executable).
 * Trivial accessors.
 */

#include "types.h"
#include "particle_types.h"

int cParticleBox_Done(void) {
    return 0;
}

int cParticleBox_Definition(ParticleObj* self) {
    return self->unk100;
}

int cParticleShatter_Definition(ParticleObj* self) {
    return self->unk120;
}
