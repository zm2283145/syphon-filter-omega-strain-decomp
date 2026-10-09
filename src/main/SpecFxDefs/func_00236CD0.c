/*
 * Matched functions (byte-identical with the retail executable).
 * Per-frame update of an emitter-driven effect.
 */

#include "types.h"
#include "SpecFxDefs_types.h"

extern int func_003A2400(SpecEmitter* emitter, float* pos, int c, float dt);

/* Updates the emitter at the effect position; marks the effect done once the
 * emitter is no longer active. */
void func_00236CD0(SpecEmitterFx* fx, float dt) {
    if (fx->emitter != 0) {
        func_003A2400(fx->emitter, fx->pos, 0, dt);
        if (fx->emitter->active == 0) {
            fx->done = 1;
        }
    }
}
