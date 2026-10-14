/*
 * main/particle: range (2 files, 003A2650-003A2670)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "particle_types.h"

/* merge_units: begin func_003A2650 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; Q q; char pad2[0x28]; signed char value; } Obj;

/* Optionally copies the vector at +0x30 out and returns the byte at +0x68. */
#pragma peephole off
signed char func_003A2650(Obj* self, Q* out)
{
    if (out) {
        *out = self->q;
    }
    return self->value;
}
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A2650(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A2650 */

/* merge_units: begin func_003A2670 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Particle emitter helpers.
 */


/* Returns 1 if the emitter has a pending flag set. */
int func_003A2670(ParticleEmitter* e) {
    return e->pending != 0;
}

/* Sets the rate to base scaled by (1 + rateScale). */
void ParticleEmitter_SetRate(ParticleEmitter* e, float base) {
    e->rate = base + base * e->rateScale;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A2670(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A2670 */
