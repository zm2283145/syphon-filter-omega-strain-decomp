/*
 * SFOGame/Source/SpecFxDefs: 1 file, 00232120
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00232120 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int x0; unsigned char x4; } FxEnt232120;
extern FxEnt232120 SpecFxTable[];
extern int SfxParticleEffect_int_cMatrixR(int);
static inline FxEnt232120* GetFx232120(int id) {
    if (!SpecFxTable[id].x4) return 0;
    if ((unsigned int)id < 41) return &SpecFxTable[id];
    return 0;
}
int SfxParticleEffect_eEffectName_cMatrixR(signed char id) {
    return SfxParticleEffect_int_cMatrixR(GetFx232120(id)->x0);
}
static inline void merge_flush_func_00232120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00232120 */
