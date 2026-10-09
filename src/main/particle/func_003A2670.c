/*
 * Matched functions (byte-identical with the retail executable).
 * Particle emitter helpers.
 */

#include "types.h"
#include "particle_types.h"

/* Returns 1 if the emitter has a pending flag set. */
int func_003A2670(ParticleEmitter* e) {
    return e->pending != 0;
}

/* Sets the rate to base scaled by (1 + rateScale). */
void ParticleEmitter_SetRate(ParticleEmitter* e, float base) {
    e->rate = base + base * e->rateScale;
}
