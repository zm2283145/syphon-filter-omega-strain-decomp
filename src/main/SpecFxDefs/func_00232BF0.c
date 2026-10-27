/*
 * Matched functions (byte-identical with the retail executable).
 * Float-argument forwarder.
 */

#include "types.h"

extern int SfxAtmosphericParticleEffect_eEffectName_float_float_float_etc(int, int, float, float, float, float);

/* Forwards to SfxAtmosphericParticleEffect_eEffectName_float_float_float_etc unchanged. */
int World_StartAtmosphereEffect_Thunk(int a0, int a1, float f0, float f1, float f2, float f3) {
    return SfxAtmosphericParticleEffect_eEffectName_float_float_float_etc(a0, a1, f0, f1, f2, f3);
}
