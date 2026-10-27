/*
 * SFOGame/Source/SpecFxDefs: 1 file, 00232BF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00232BF0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_00232BF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00232BF0 */
