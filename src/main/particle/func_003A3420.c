/*
 * Matched functions (byte-identical with the retail executable).
 * Forwarder to the wrapped particle system.
 */

#include "types.h"
#include "particle_types.h"

extern int ShatterEmitter_BuildShards(void* system, int a1, int a2, int a3, int t0, int t1, float f);

int ParticleInst_SetupShatter(ParticleHandle* h, int a1, int a2, int a3, int t0, int t1, float f) {
    return ShatterEmitter_BuildShards(h->system, a1, a2, a3, t0, t1, f);
}
