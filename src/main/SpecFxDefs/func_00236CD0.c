/*
 * Matched functions (byte-identical with the retail executable).
 * Per-frame update of an emitter-driven effect.
 */

#include "types.h"
#include "SpecFxDefs_types.h"

extern int cParticle_NextFrame(SpecEmitter* emitter, float* pos, int c, float dt);

/* Updates the emitter at the effect position; marks the effect done once the
 * emitter is no longer active. */
void cParticleFx_SfxUpdate(SpecEmitterFx* fx, float dt) {
    if (fx->emitter != 0) {
        cParticle_NextFrame(fx->emitter, fx->pos, 0, dt);
        if (fx->emitter->active == 0) {
            fx->done = 1;
        }
    }
}
