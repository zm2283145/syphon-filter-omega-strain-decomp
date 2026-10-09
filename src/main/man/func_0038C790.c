/*
 * Matched functions (byte-identical with the retail executable).
 * Equipment slot swap and clear; both refresh via Equip_Init.
 */

#include "types.h"
#include "man_types.h"

extern void Equip_Init(ManEquipOwner* self);

void Equip_SwapSlots(ManEquipOwner* self, int a, int b) {
    int itemA = self->slots[a];
    int itemB = self->slots[b];
    self->slots[a] = itemB;
    self->slots[b] = itemA;
    Equip_Init(self);
}

void Equip_ClearSlot(ManEquipOwner* self, int slot) {
    self->slots[slot] = 0;
    Equip_Init(self);
}
