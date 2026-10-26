/*
 * Matched functions (byte-identical with the retail executable).
 * Indexed slot accessors.
 */

#include "types.h"
#include "particle_types.h"

/* Address of the slot for a byte index. */
int* ParticleRandom_QwordAt(ParticleSlotTable* t, int index) {
    return &t->slots[index & 255];
}

/* Element index of a pointer vector. */
int cTexMan_GetHalTexture(PtrVec* v, int index) {
    return v->data[index];
}
