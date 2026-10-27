/*
 * Libs/SFOLib/Source/particle: 3 files, 003A6070-003A6110
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A6070 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_003A6070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A6070 */

/* merge_units: begin func_003A60A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR3(cParticleSpline_dtor, D_004DFB30, D_004DFB50, D_004DFAD8)
static inline void merge_flush_func_003A60A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A60A0 */

/* merge_units: begin func_003A6110 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Trivial accessor.
 */


int cParticleSpline_Definition(ParticleObj* self) {
    return self->unk100;
}
static inline void merge_flush_func_003A6110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A6110 */
