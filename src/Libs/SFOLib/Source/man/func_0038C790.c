/*
 * Matched functions (byte-identical with the retail executable).
 * Equipment slot swap and clear; both refresh via cMan_UpdateHandMorphs.
 */

#include "types.h"
#include "man_types.h"

extern void cMan_UpdateHandMorphs(ManEquipOwner* self);

void cMan_ChangeGunPlacement(ManEquipOwner* self, int a, int b) {
    int itemA = self->slots[a];
    int itemB = self->slots[b];
    self->slots[a] = itemB;
    self->slots[b] = itemA;
    cMan_UpdateHandMorphs(self);
}

void cMan_RemoveGun(ManEquipOwner* self, int slot) {
    self->slots[slot] = 0;
    cMan_UpdateHandMorphs(self);
}
