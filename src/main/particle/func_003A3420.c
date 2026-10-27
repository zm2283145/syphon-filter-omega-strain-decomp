/*
 * Matched functions (byte-identical with the retail executable).
 * Forwarder to the wrapped particle system.
 */

#include "types.h"
#include "particle_types.h"

extern int cParticleShatter_SetShatterData(void* system, int a1, int a2, int a3, int t0, int t1, float f);

int cParticle_SetShatterData(ParticleHandle* h, int a1, int a2, int a3, int t0, int t1, float f) {
    return cParticleShatter_SetShatterData(h->system, a1, a2, a3, t0, t1, f);
}
