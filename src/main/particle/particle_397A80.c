/*
 * main/particle: range (2 files, 00397A80-00397A90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "particle_types.h"

/* merge_units: begin func_00397A80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Trivial accessor.
 */


int func_00397A80(ParticleObj* self) {
    return self->unk120;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00397A80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00397A80 */

/* merge_units: begin func_00397A90 */
#pragma push /* merge_units */
typedef struct { char pad[0xE0]; char sub[0x48]; unsigned char enabled; } Obj128;

/* Returns the sub-block at +0xE0 when the flag at +0x128 is set, else NULL. */
void* func_00397A90(Obj128* o)
{
    if (o->enabled)
        return o->sub;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00397A90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00397A90 */
