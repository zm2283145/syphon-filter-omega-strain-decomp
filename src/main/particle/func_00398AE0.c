/*
 * Matched functions (byte-identical with the retail executable).
 * Indexed slot accessors.
 */

#include "types.h"
#include "particle_types.h"

/* Address of the slot for a byte index. */
int* func_00398AE0(ParticleSlotTable* t, int index) {
    return &t->slots[index & 255];
}

/* Element index of a pointer vector. */
int func_00398B00(PtrVec* v, int index) {
    return v->data[index];
}
